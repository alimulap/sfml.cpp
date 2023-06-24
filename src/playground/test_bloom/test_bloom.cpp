#include <SFML/Graphics.hpp>

namespace bloom {

const std::string bloom1_frag = R"(
uniform sampler2D texSampler;
uniform vec2 texResolution;

vec3 makeBloom(float lod, vec2 offset, vec2 bCoord){
    vec2 pixelSize = 1.0 / texResolution;

    offset += pixelSize;

    float lodFactor = exp2(lod);

    vec3 bloom = vec3(0.0);
    vec2 scale = lodFactor * pixelSize;

    vec2 coord = (bCoord.xy - offset) * lodFactor;
    float totalWeight = 0.0;

    if (any(greaterThanEqual(abs(coord - 0.5), scale + 0.5)))
        return vec3(0.0);

    for (int i = -5; i < 5; i++) {
        for (int j = -5; j < 5; j++) {

            float wg = pow(1.0-length(vec2(i,j)) * 0.125,6.0);

            bloom = pow(texture2D(texSampler,vec2(i,j) * scale + lodFactor * pixelSize + coord, lod).rgb,vec3(2.2))*wg + bloom;
            totalWeight += wg;

        }
    }

    bloom /= totalWeight;

    return bloom;
}

void main()
{
    vec2 uv = gl_FragCoord / texResolution;
    
	vec3 blur  = makeBloom(2.,vec2(0.0,0.0), uv);
	 	 blur += makeBloom(3.,vec2(0.3,0.0), uv);
	 	 blur += makeBloom(4.,vec2(0.0,0.3), uv);
	 	 blur += makeBloom(5.,vec2(0.1,0.3), uv);
	 	 //blur += makeBloom(6.,vec2(0.2,0.3), uv);

    gl_FragColor = vec4(pow(blur, vec3(1.0 / 2.2)),1.0);
}
)";

const std::string bloom2_frag = R"(
uniform sampler2D texSampler;
uniform sampler2D texSamplerRaw;
uniform vec2 texResolution;

vec3 jodieReinhardTonemap(vec3 c){
    float l = dot(c, vec3(0.2126, 0.7152, 0.0722));
    vec3 tc = c / (c + 1.0);

    return mix(c / (l + 1.0), tc, tc);
}

vec3 bloomTile(float lod, vec2 offset, vec2 uv){
    return texture2D(texSampler, uv * exp2(-lod) + offset).rgb;
}

vec3 getBloom(vec2 uv){

    vec3 blur = vec3(0.0);

    blur = pow(bloomTile(2., vec2(0.0,0.0), uv),vec3(2.2))       	   	+ blur;
    blur = pow(bloomTile(3., vec2(0.3,0.0), uv),vec3(2.2)) * 0.4        + blur;
    blur = pow(bloomTile(4., vec2(0.0,0.3), uv),vec3(2.2)) * 0.7        + blur;
    blur = pow(bloomTile(5., vec2(0.1,0.3), uv),vec3(2.2)) * 1.0 	   	+ blur;
    //blur = pow(bloomTile(6., vec2(0.2,0.3), uv),vec3(2.2)) * 1.3 	   	+ blur;

    return blur;
}

void main()
{
	vec2 uv = gl_FragCoord / texResolution;
    
    vec3 color  = pow(texture2D(texSamplerRaw, uv).rgb, vec3(2.2));
         color  = pow(color, vec3(2.2));
         color += pow(getBloom(uv), vec3(2.2));
         color  = pow(color, vec3(1.0 / 2.2));
    
    color = jodieReinhardTonemap(color);
    
	gl_FragColor = vec4(color,1.0);
}
)";

const sf::Vector2i WINDOW_SIZE = sf::Vector2i(720, 480);

int main() {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 3.0;
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Playground", sf::Style::Close | sf::Style::Titlebar, settings);

    sf::RectangleShape rect(sf::Vector2f(160., 160.));
    rect.setPosition(60., 160.);

    sf::ConvexShape triangle(3);
    triangle.setPoint(0, {360., 160.});
    triangle.setPoint(1, {280., 320.});
    triangle.setPoint(2, {440., 320.});

    sf::CircleShape circle(80.);
    circle.setPosition({500., 160.});

    sf::RenderTexture texture1;
    texture1.create(720, 480, settings);
    texture1.setSmooth(true);

    sf::RenderTexture texture2;
    texture2.create(720, 480, settings);
    texture2.setSmooth(true);

    sf::RenderTexture texture3;
    texture3.create(720, 480, settings);
    texture3.setSmooth(true);

    sf::Shader bloom1;
    if (!bloom1.loadFromMemory(bloom1_frag, sf::Shader::Type::Fragment))
        return 1;
    bloom1.setUniform("texSampler", sf::Shader::CurrentTexture);
    bloom1.setUniform("texResolution", static_cast<sf::Vector2f>(WINDOW_SIZE));

    sf::Shader bloom2;
    if (!bloom2.loadFromMemory(bloom2_frag, sf::Shader::Type::Fragment))
        return 1;
    bloom2.setUniform("texSampler", sf::Shader::CurrentTexture);
    bloom2.setUniform("texSamplerRaw", texture1.getTexture());
    bloom2.setUniform("texResolution", static_cast<sf::Vector2f>(WINDOW_SIZE));

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            window.close();
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        rect.setFillColor(sf::Color(100, 185, 255));
        triangle.setFillColor(sf::Color(100, 255, 100));
        circle.setFillColor(sf::Color(255, 100, 100));

        texture1.clear(sf::Color::Transparent);
        texture1.draw(rect);
        texture1.draw(triangle);
        texture1.draw(circle);
        texture1.display();

        texture2.clear(sf::Color::Transparent);
        texture2.draw(sf::Sprite(texture1.getTexture()), &bloom1);
        texture2.display();

        texture3.clear(sf::Color::Transparent);
        texture3.draw(sf::Sprite(texture2.getTexture()), &bloom2);
        texture3.display();

        rect.setFillColor(sf::Color(100, 255, 255));
        triangle.setFillColor(sf::Color(180, 255, 180));
        circle.setFillColor(sf::Color(255, 180, 180));

        window.clear(sf::Color::Transparent);
        window.draw(sf::Sprite(texture3.getTexture()));
        window.draw(rect);
        window.draw(triangle);
        window.draw(circle);
        window.display();
    }

    return 0;
}

}
