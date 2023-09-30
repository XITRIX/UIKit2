//
// Created by Даниил Виноградов on 09.09.2023.
//

#include <SDLVideo.hpp>

#include <stdio.h>
#include <bx/bx.h>
#include <bgfx/platform.h>
#include <SDL_syswm.h>
#include "logo.h"

#include <nanovg.h>
#include <CoreGraphics/CGContext.hpp>

#define USE_GL BX_PLATFORM_SWITCH || BX_PLATFORM_ANDROID

uint32_t flags = BGFX_RESET_VSYNC | BGFX_RESET_HIDPI;

SDLVideo* SDLVideo::shared = nullptr;

int SDLVideo::resizingEventWatcher(void* data, SDL_Event* event) {
    if (event->type == SDL_WINDOWEVENT &&
        event->window.event == SDL_WINDOWEVENT_RESIZED) {
        SDL_Window* win = SDL_GetWindowFromID(event->window.windowID);
        if (win == (SDL_Window*)data) {
            printf("resizing.....\n");
            shared->update();
        }
    }
    return 0;
}


SDLVideo::SDLVideo() {
// Create a GLFW window without an OpenGL context.
    shared = this;
//    glfwSetErrorCallback(glfw_errorCallback);
    SDL_Init(SDL_INIT_EVERYTHING);
//    SDL_InitSubSystem(SDL_INIT_VIDEO);

    //Screen dimensions
    SDL_Rect gScreenRect = { 0, 0, 1280, 720 };

#if BX_PLATFORM_OS_CONSOLE
    //Get device display mode
    SDL_DisplayMode displayMode;
    if( SDL_GetCurrentDisplayMode( 0, &displayMode ) == 0 )
    {
        gScreenRect.w = displayMode.w;
        gScreenRect.h = displayMode.h;
    }
#endif

    Uint32 windowFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;

#if USE_GL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 0);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
    SDL_GL_SetAttribute(SDL_GL_RETAINED_BACKING, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    windowFlags |= SDL_WINDOW_OPENGL;
#endif

    printf("Init size %d | %d\n ", gScreenRect.w, gScreenRect.h);
    window = SDL_CreateWindow("Angle Test",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              gScreenRect.w, gScreenRect.h,
                              windowFlags);

//    window = glfwCreateWindow(1024, 768, "helloworld", nullptr, nullptr);
    if (!window)
        return;

    SDL_RegisterEvents(7);
    SDL_AddEventWatch(resizingEventWatcher, window);
//    printf("Window is presented - %d\n", window);

#if USE_GL
    // Configure window
    SDL_GLContext context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);
#endif

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
#elif BX_PLATFORM_IOS
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    init.platformData.nwh = SDL_RenderGetMetalLayer(renderer);
    //    init.platformData.nwh = wmi.info.uikit.window;
#elif BX_PLATFORM_WINDOWS
    init.platformData.nwh = glfwGetWin32Window(window);
#elif USE_GL
    init.platformData.context = context;
#endif

    SDL_GetWindowSize(window, &width, &height);
//    glfwGetWindowSize(window, &width, &height);

    init.resolution.width = (uint32_t)width;
    init.resolution.height = (uint32_t)height;
    init.resolution.reset = flags;

    if (!bgfx::init(init)) {
        return;
    }

    // Set view 0 to the same dimensions as the window and to clear the color buffer.
    bgfx::setViewClear(kClearView, BGFX_CLEAR_COLOR);
    bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);
    
    isInitialized = true;

    nvgContext = nvgCreate(1, 0);
    bgfx::setViewMode(0, bgfx::ViewMode::Sequential);
}

void SDLVideo::runMainLoop() {
    auto controller = SDL_GameControllerOpen(0);

    bool closeRequired = false;
    while (!closeRequired) {
//        bgfx::renderFrame();

        SDL_Event event;
        SDL_PumpEvents();
//        printf("Frame\n");
        while (SDL_PollEvent(&event)) {
            printf("Event\n");
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
                case SDL_CONTROLLERBUTTONDOWN:
                    switch (event.cbutton.button) {
                        case SDL_CONTROLLER_BUTTON_START:
                            closeRequired = true;
                            break;
                        case SDL_CONTROLLER_BUTTON_A:
                            s_showStats = !s_showStats;
                            break;
                    }
                    break;
            }
        }


//        SDL_SetRenderDrawColor( render, 0x00, 0xFF, 0xFF, 0xFF );
//        SDL_RenderClear( render );
//
//        SDL_RenderPresent( render );

        // Handle window resize.
        update();
    }

    nvgDelete(nvgContext);
    bgfx::shutdown();
    SDL_GameControllerClose(controller);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLVideo::update() {
    if (!isInitialized) return;

    int dw, dh;
    SDL_GetWindowSize(window, &dw, &dh);

    int oldWidth = width, oldHeight = height;
#if BX_PLATFORM_OSX || BX_PLATFORM_IOS
    SDL_Metal_GetDrawableSize(window, &width, &height);
#elif USE_GL
    SDL_GL_GetDrawableSize(window, &width, &height);
#else
    width = dw;
    height = dh;
#endif

    if (width != oldWidth || height != oldHeight) {
        bgfx::reset((uint32_t)width, (uint32_t)height, flags);
        bgfx::setViewRect(kClearView, 0, 0, bgfx::BackbufferRatio::Equal);
    }

    // This dummy draw call is here to make sure that view 0 is cleared if no other draw calls are submitted to view 0.
    bgfx::touch(kClearView);

//    bgfx::tex
    float scale = (float) width / (float) dw;
    draw(width, height, scale);

#if USE_GL
    SDL_GL_SwapWindow(window);
#endif
}

void SDLVideo::draw(int width, int height, float scale) {
    nvgBeginFrame(nvgContext, (float) width, (float) height, 1);
    nvgScale(nvgContext, scale, scale);

    auto context = new CGContext();
    context->nvgContext = nvgContext;
    CGContext::current = context;

    rootLayer->position = CGPoint::zero;
    rootLayer->bounds.size.width = width;
    rootLayer->bounds.size.height = height;
    rootLayer->draw();

    CGContext::current = nullptr;
    delete context;

    nvgEndFrame(nvgContext);

    // Use debug font to print information about this example.
//    bgfx::dbgTextClear();
//    bgfx::dbgTextImage(bx::max<uint16_t>(uint16_t(width / 2 / 8), 20) - 20, bx::max<uint16_t>(uint16_t(height / 2 / 16), 6) - 6, 40, 12, s_logo, 160);
//    bgfx::dbgTextPrintf(0, 0, 0x0f, "Press F1 to toggle stats.");
//    bgfx::dbgTextPrintf(0, 1, 0x0f, "Color can be changed with ANSI \x1b[9;me\x1b[10;ms\x1b[11;mc\x1b[12;ma\x1b[13;mp\x1b[14;me\x1b[0m code too.");
//    bgfx::dbgTextPrintf(80, 1, 0x0f, "\x1b[;0m    \x1b[;1m    \x1b[; 2m    \x1b[; 3m    \x1b[; 4m    \x1b[; 5m    \x1b[; 6m    \x1b[; 7m    \x1b[0m");
//    bgfx::dbgTextPrintf(80, 2, 0x0f, "\x1b[;8m    \x1b[;9m    \x1b[;10m    \x1b[;11m    \x1b[;12m    \x1b[;13m    \x1b[;14m    \x1b[;15m    \x1b[0m");
//    const bgfx::Stats* stats = bgfx::getStats();
//    bgfx::dbgTextPrintf(0, 2, 0x0f, "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters.", stats->width, stats->height, stats->textWidth, stats->textHeight);
    // Enable stats or debug text.
//    bgfx::setDebug(s_showStats ? BGFX_DEBUG_STATS : BGFX_DEBUG_TEXT);
//    bgfx::setDebug(BGFX_DEBUG_IFH);

    // Advance to next frame. Process submitted rendering primitives.
    bgfx::frame();
}
