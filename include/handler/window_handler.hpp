#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include <Windows.h>
#include <dwmapi.h>
#include <memory>

namespace Handler
{
    void enableBlurBehindWindow(HWND hwnd);
    void makeWindowTransparent(std::shared_ptr<sf::RenderWindow>& window);
    void makeWindowOpaque(std::shared_ptr<sf::RenderWindow>& window);
    inline void setWindowAlpha(const std::shared_ptr<sf::RenderWindow>& window, sf::Uint8 alpha);
}

