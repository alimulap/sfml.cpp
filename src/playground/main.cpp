#include "SFML/Graphics.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Shape.hpp"
#include "SFML/Graphics/VertexArray.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include <imgui.h>
#include <imgui-SFML.h>

#include "playground/test_bloom.hpp"

const std::string vertexShader = R"(
uniform vec2 middle;

void main()
{
    vec4 vertex = gl_ModelViewMatrix * gl_Vertex;
    vec2 offset = vertex.xy - middle;
    float len = length(offset);

    float angle = atan(offset.y, offset.x);
    float newAngle = angle + 0.00003 * len * len;
    //float newAngle = angle + 0.02 * len;
    vec2 newPosition = middle + vec2(cos(newAngle), sin(newAngle)) * len;
    vertex.xy = newPosition;

    gl_Position = gl_ProjectionMatrix * vertex;
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
    gl_FrontColor = gl_Color;
}
)";

const std::string blackHoleFragmentShader = R"(
uniform sampler2D textureSampler;
uniform vec2 iResolution;
uniform vec2 middle;

void main() {
    vec2 uv = gl_FragCoord.xy / iResolution;
    vec2 md = middle / iResolution;
    vec2 delta = abs(uv - md);
    float distance = sqrt(delta.x * delta.x + delta.y * delta.y);

    float radius = 0.3;  // Desired radius for the effect
    float eventHorizon = 0.05;
    
    if (distance < radius) {
        distance = distance - eventHorizon;
        float darkness = 1.0;
        if (distance > 0.0) {
            darkness = 1.0 - distance / (radius - eventHorizon);
        }
        gl_FragColor = texture2D(textureSampler, uv) * vec4(1.0, 1.0, 1.0 ,1.0 - darkness);
    } else {
        gl_FragColor = texture2D(textureSampler, uv);
    }
}
)";

const std::string glowFragmentShader = R"(
    uniform sampler2D textureSampler;
    uniform vec2 resolution;
    uniform float glowStrength;
    
    vec4 blur(sampler2D texture, vec2 uv, vec2 direction)
    {
        vec4 color = vec4(0.0);
        vec2 offset = direction / resolution;

        // Blur using a 9-tap Gaussian kernel
        for (int i = -4; i <= 4; ++i)
        {
            float weight = exp(-float(i * i) / 70.0);
            color += texture2D(texture, uv + offset * float(i)) * weight;
        }

        return color;
    }

    void main()
    {
        vec2 uv = gl_FragCoord.xy / resolution;
        vec4 originalColor = texture2D(textureSampler, uv);
        
        // Apply horizontal and vertical blur passes
        vec4 blurredColor = blur(textureSampler, uv, vec2(1.0, 0.0)) + blur(textureSampler, uv, vec2(0.0, 1.0));
        
        // Combine original and blurred image with glow strength
        vec4 finalColor = originalColor + blurredColor * glowStrength;
        
        gl_FragColor = finalColor;
    }
)";

const sf::Vector2i WINDOW_SIZE(720, 480);
const sf::Vector2f PORTAL_CENTER(WINDOW_SIZE.x / 2., WINDOW_SIZE.y / 2.);
const float PORTAL_RADIUS = 250.f;

float SPAWN_INTERVAL = 0.3f;

int PARTICLES_PER_SPAWN = 10;
float PARTICLE_SPEED = 0.5f;

const float MINIMUM_RADIUS = 0.f;
const float MAXIMUM_RADIUS = 15.f;

class PColor {
    public:
        const char* name;
        sf::Color value;
        PColor(const char* name, const sf::Color& value)
            : name(name), value(value) {} 
};


std::vector<PColor> paletteColors = {
    PColor("Cyan", sf::Color::Cyan), 
    PColor("Magenta", sf::Color::Magenta), 
    PColor("Yellow", sf::Color::Yellow)
};

std::vector<PColor> colorPresets = { 
    PColor("Black", sf::Color::Black), 
    PColor("White", sf::Color::White), 
    PColor("Red", sf::Color::Red), 
    PColor("Green", sf::Color::Green), 
    PColor("Blue", sf::Color::Blue), 
    PColor("Magenta", sf::Color::Magenta), 
    PColor("Yellow", sf::Color::Yellow), 
    PColor("Cyan", sf::Color::Cyan)
};

int main() {
    bloom::main();
    return 0;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 3.0;
    // settings.sRgbCapable = true;
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Playground", sf::Style::Close | sf::Style::Titlebar, settings);

    auto _ = ImGui::SFML::Init(window);
    //ImGuiWindowFlags controlPanel_flags = 0;
    //controlPanel_flags |= ImGuiWindowFlags_NoMove;

    std::vector<sf::CircleShape> smallCircles;
    
    std::srand(std::time(0));

    sf::Clock timer;
    sf::Clock deltaTime;

    sf::Shader spiralShader;
    if (!spiralShader.loadFromMemory(vertexShader, sf::Shader::Type::Vertex))
        return 1;
    spiralShader.setUniform("middle", PORTAL_CENTER);

    sf::Shader glowShader;
    if (!glowShader.loadFromMemory(glowFragmentShader, sf::Shader::Type::Fragment))
        return 1;
    glowShader.setUniform("resolution", static_cast<sf::Vector2f>(WINDOW_SIZE));
    glowShader.setUniform("glowStrength", 0.1f);

    sf::Shader blackHoleShader;
    if (!blackHoleShader.loadFromMemory(blackHoleFragmentShader, sf::Shader::Type::Fragment))
        return 1;
    blackHoleShader.setUniform("middle", PORTAL_CENTER);
    blackHoleShader.setUniform("iResolution", static_cast<sf::Vector2f>(WINDOW_SIZE));

    sf::RenderTexture sceneTex;
    sceneTex.create(WINDOW_SIZE.x, WINDOW_SIZE.y, settings);
    sf::Sprite sceneSprite(sceneTex.getTexture());
    glowShader.setUniform("textureSampler", sceneTex.getTexture());

    sf::RenderTexture glowTex;
    glowTex.create(WINDOW_SIZE.x, WINDOW_SIZE.y, settings);
    sf::Sprite glowSprite(glowTex.getTexture());
    blackHoleShader.setUniform("textureSampler", glowTex.getTexture());

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            ImGui::SFML::ProcessEvent(window, event);

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                        window.close();
                    break;
                default:
                    break;
            }
        }

        if (timer.getElapsedTime().asSeconds() > SPAWN_INTERVAL && paletteColors.size() > 0) {
            for (int i = 0; i < PARTICLES_PER_SPAWN; ++i) {
                sf::CircleShape smallCircle(MINIMUM_RADIUS);
                auto ikan = sf::VertexArray();

                int rand = std::rand();
                smallCircle.setFillColor(paletteColors[rand % paletteColors.size()].value);
                smallCircle.setOrigin(5., 5.);
                int posAngle = rand % 360;
                sf::Vector2f pos(
                    PORTAL_CENTER.x + std::cos(posAngle * (3.14 / 180)) * PORTAL_RADIUS,
                    PORTAL_CENTER.y + std::sin(posAngle * (3.14 / 180)) * PORTAL_RADIUS
                );
                smallCircle.setPosition(pos);

                sf::Vector2f diff = PORTAL_CENTER - pos;
                float rotation = std::atan2(diff.y, diff.x) * (180.f / 3.14f);
                smallCircle.setRotation(rotation);

                smallCircle.setScale(1.f, 0.4f);

                smallCircles.emplace_back(smallCircle);
            }

            timer.restart();
        }

        for (int i = smallCircles.size() - 1; i >= 0; --i) {
            float newRadius = MINIMUM_RADIUS;
            float deltax = abs(smallCircles[i].getPosition().x - PORTAL_CENTER.x);
            float deltay = abs(smallCircles[i].getPosition().y - PORTAL_CENTER.y);
            float distance = sqrt(deltax * deltax + deltay * deltay);
            // the radius get bigger the closer to the middle using easeOutCubic (from ChatGPT)
            if (distance < PORTAL_RADIUS) {
                float t = (1. - distance / PORTAL_RADIUS) - 1.;
                newRadius += (t * t * t + 1.) * MAXIMUM_RADIUS;
            }
            smallCircles[i].setRadius(newRadius);

            sf::Vector2f cirPos = smallCircles[i].getPosition();
            float angle = std::atan2(PORTAL_CENTER.y - cirPos.y, PORTAL_CENTER.x - cirPos.x);// + (3.14 / 4);// <-- do this if you want to move the circle in spiral without shaders
            smallCircles[i].move(
                std::cos(angle) * PARTICLE_SPEED,
                std::sin(angle) * PARTICLE_SPEED
            );
            if (smallCircles[i].getGlobalBounds().contains(PORTAL_CENTER)) 
                smallCircles.erase(smallCircles.begin() + i);
        }

        ImGui::SFML::Update(window, deltaTime.restart());

        ImGui::ShowDemoWindow();

        ImGui::Begin("Control Panel",0, ImGuiWindowFlags_NoMove);

        ImGui::InputFloat("Spawn interval", &SPAWN_INTERVAL, 0.01f, 0.1f, "%.3f");
        SPAWN_INTERVAL = std::clamp(SPAWN_INTERVAL, 0.0f, INFINITY);

        ImGui::InputInt("Particles per spawn", &PARTICLES_PER_SPAWN);
        PARTICLES_PER_SPAWN = std::clamp(PARTICLES_PER_SPAWN, 0, INT_MAX);

        ImGui::InputFloat("Particle speed", &PARTICLE_SPEED, 0.1f, 0.01f, "%.3f");
        PARTICLE_SPEED = std::clamp(PARTICLE_SPEED, 0.001f, INFINITY);

        if (ImGui::CollapsingHeader("Colors", ImGuiTreeNodeFlags_None)) {
            static int currentPaletteColor = 0;
            static const char* currentPaletteColorName;
            sf::Color currPV;
            if (paletteColors.size() > 0) {
                currentPaletteColorName = paletteColors[currentPaletteColor].name;
                currPV = paletteColors[currentPaletteColor].value;
            } else {
                currentPaletteColorName = "##";
                currPV = ImVec4(0,0,0,0);
            }

            ImGui::ColorButton(currentPaletteColorName, ImVec4(currPV.r, currPV.g, currPV.b, currPV.a)); ImGui::SameLine();
            if (ImGui::BeginCombo("Palette", currentPaletteColorName)) {
                for (int n = 0; n < paletteColors.size(); ++n) {
                    ImGui::PushID(n);
                    bool isSelected = currentPaletteColor == n;
                    if (ImGui::Selectable(paletteColors[n].name, isSelected))
                        currentPaletteColor = n;
                    if (isSelected)
                        ImGui::SetItemDefaultFocus();
                    ImGui::PopID();
                }
                ImGui::EndCombo();
            }
            if (ImGui::Button("Delete color")) {
                if (currentPaletteColor == paletteColors.size() - 1 && paletteColors.size() > 1)
                    paletteColors.erase(paletteColors.begin() + (currentPaletteColor--));
                else 
                    paletteColors.erase(paletteColors.begin() + currentPaletteColor);
            }

            static int currentColorPreset = 0;
            sf::Color currPCV = colorPresets[currentColorPreset].value;
            ImGui::ColorButton(colorPresets[currentColorPreset].name, ImVec4(currPCV.r, currPCV.g, currPCV.b, currPCV.a)); ImGui::SameLine();
            if (ImGui::BeginCombo("Preset", colorPresets[currentColorPreset].name)) {
                for (int n = 0; n < colorPresets.size(); ++n) {
                    bool isSelected = currentColorPreset == n;
                    if (ImGui::Selectable(colorPresets[n].name, isSelected))
                        currentColorPreset = n;
                    if (isSelected)
                        ImGui::SetItemDefaultFocus();
                }
                ImGui::EndCombo();
            }
            if (ImGui::Button("Add to palette"))
                paletteColors.push_back(colorPresets[currentColorPreset]);
            //ImGui::TreePop();
        }

        ImGui::End();

        auto shape = sf::CircleShape();

        sceneTex.clear(sf::Color::Transparent);
        for (auto& circle : smallCircles)
            sceneTex.draw(circle, &spiralShader);
        sceneTex.display();

        glowTex.clear(sf::Color::Transparent);
        glowTex.draw(sceneSprite, &glowShader);
        glowTex.display();

        window.clear(sf::Color::Black);
        window.draw(glowSprite, &blackHoleShader);
        ImGui::SFML::Render(window);

        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
