#include "handler/window_handler.hpp"

namespace Handler
{
    void enableBlurBehindWindow(HWND hwnd)
    {
        // Create the blur-behind structure
        DWM_BLURBEHIND bb = {0};
        bb.dwFlags = DWM_BB_ENABLE;
        bb.fEnable = TRUE;
        bb.hRgnBlur = NULL;

        // Enable the blur-behind effect
        DwmEnableBlurBehindWindow(hwnd, &bb);
    }

    void makeWindowTransparent(std::shared_ptr<sf::RenderWindow>& window)
    {
        HWND hwnd = window->getSystemHandle();
        SetWindowLongPtr(hwnd, GWL_EXSTYLE, GetWindowLongPtr(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    }

    void makeWindowOpaque(std::shared_ptr<sf::RenderWindow>& window)
    {
        HWND hwnd = window->getSystemHandle();
        SetWindowLongPtr(hwnd, GWL_EXSTYLE, GetWindowLongPtr(hwnd, GWL_EXSTYLE) & ~WS_EX_LAYERED);
        RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_FRAME | RDW_ALLCHILDREN);
    }

    inline void setWindowAlpha(const std::shared_ptr<sf::RenderWindow>& window, sf::Uint8 alpha = 255)
    {
        SetLayeredWindowAttributes(window->getSystemHandle(), 0, alpha, LWA_ALPHA);
    }
}

