//
// Created by Даниил Виноградов on 09.09.2023.
//

#include <SDLVideo.hpp>

#include <bx/bx.h>
#include <bgfx/platform.h>
#include <SDL2/SDL_syswm.h>
#include "logo.h"

uint32_t flags = BGFX_RESET_VSYNC | BGFX_RESET_HIDPI;

SDLVideo* SDLVideo::shared = nullptr;

int SDLVideo::resizingEventWatcher(void* data, SDL_Event* event) {
    if (event->type == SDL_WINDOWEVENT &&
        event->window.event == SDL_WINDOWEVENT_RESIZED) {
        SDL_Window* win = SDL_GetWindowFromID(event->window.windowID);
        if (win == (SDL_Window*)data) {
            printf("resizing.....\n");
            shared->draw();
        }
    }
    return 0;
}


SDLVideo::SDLVideo() {
// Create a GLFW window without an OpenGL context.
    shared = this;
//    glfwSetErrorCallback(glfw_errorCallback);
    SDL_Init(0 | SDL_INIT_GAMECONTROLLER);

    window = SDL_CreateWindow("Angle Test",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          1024, 768, SDL_WINDOW_SHOWN
                                                     | SDL_WINDOW_RESIZABLE);
//    window = glfwCreateWindow(1024, 768, "helloworld", nullptr, nullptr);
    if (!window)
        return;

    SDL_RegisterEvents(7);
    SDL_AddEventWatch(resizingEventWatcher, window);

//    glfwSetKeyCallback(window, glfw_keyCallback);
//SDL_SetSize
//    glfwSetFramebufferSizeCallback(window, &GLFWVideo::framebuffer_size_callback);
    // Call bgfx::renderFrame before bgfx::init to signal to bgfx not to create a render thread.
    // Most graphics APIs must be used on the same thread that created the window.
    bgfx::renderFrame();
    // Initialize bgfx using the native window handle and window resolution.
    bgfx::Init init;

    SDL_SysWMinfo wmi;
    SDL_VERSION(&wmi.version);
    SDL_GetWindowWMInfo(window, &wmi);

#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
    init.platformData.ndt = glfwGetX11Display();
	init.platformData.nwh = (void*)(uintptr_t)glfwGetX11Window(window);
#elif BX_PLATFORM_OSX
    init.platformData.nwh = wmi.info.cocoa.window;
#elif BX_PLATFORM_WINDOWS
    init.platformData.nwh = glfwGetWin32Window(window);
#endif
    SDL_GetWindowSize(window, &width, &height);
//    glfwGetWindowSize(window, &width, &height);

    init.resolution.width = (uint32_t)width;
    init.resolution.height = (uint32_t)height;
    init.resolution.reset = flags;
    if (!bgfx::init(init))
        return;
    // Set view 0 to the same dimensions as the window and to clear the color buffer.
    bgfx::setViewClear(kClearView, BGFX_CLEAR_COLOR);
    bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);

    bool closeRequired = false;
    while (!closeRequired) {
        bgfx::renderFrame();

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    // handling of close button
                    closeRequired = true;
                    break;
                case SDL_KEYUP:
                    if (event.key.keysym.sym == SDLK_F1) {
                        s_showStats = !s_showStats;
                    }
                    break;
            }
        }

        // Handle window resize.
        draw();
    }
    bgfx::shutdown();
    SDL_Quit();
}

void SDLVideo::draw() {
    int oldWidth = width, oldHeight = height;
    SDL_GetWindowSize(window, &width, &height);
//    glfwGetWindowSize(window, &width, &height);
    if (width != oldWidth || height != oldHeight) {
        bgfx::reset((uint32_t)width, (uint32_t)height, flags);
        bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);
    }
    // This dummy draw call is here to make sure that view 0 is cleared if no other draw calls are submitted to view 0.
    bgfx::touch(kClearView);
    // Use debug font to print information about this example.
    bgfx::dbgTextClear();
    bgfx::dbgTextImage(bx::max<uint16_t>(uint16_t(width / 2 / 8), 20) - 20, bx::max<uint16_t>(uint16_t(height / 2 / 16), 6) - 6, 40, 12, s_logo, 160);
    bgfx::dbgTextPrintf(0, 0, 0x0f, "Press F1 to toggle stats.");
    bgfx::dbgTextPrintf(0, 1, 0x0f, "Color can be changed with ANSI \x1b[9;me\x1b[10;ms\x1b[11;mc\x1b[12;ma\x1b[13;mp\x1b[14;me\x1b[0m code too.");
    bgfx::dbgTextPrintf(80, 1, 0x0f, "\x1b[;0m    \x1b[;1m    \x1b[; 2m    \x1b[; 3m    \x1b[; 4m    \x1b[; 5m    \x1b[; 6m    \x1b[; 7m    \x1b[0m");
    bgfx::dbgTextPrintf(80, 2, 0x0f, "\x1b[;8m    \x1b[;9m    \x1b[;10m    \x1b[;11m    \x1b[;12m    \x1b[;13m    \x1b[;14m    \x1b[;15m    \x1b[0m");
    const bgfx::Stats* stats = bgfx::getStats();
    bgfx::dbgTextPrintf(0, 2, 0x0f, "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters.", stats->width, stats->height, stats->textWidth, stats->textHeight);
    // Enable stats or debug text.
    bgfx::setDebug(s_showStats ? BGFX_DEBUG_STATS : BGFX_DEBUG_TEXT);
    // Advance to next frame. Process submitted rendering primitives.
    bgfx::frame();
}