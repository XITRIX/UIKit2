//
// Created by Даниил Виноградов on 06.09.2023.
//

#include <Application.hpp>
#include <cstdio>

#include <SDL2/SDL.h>

//#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <SDL_syswm.h>

//class ExampleHelloWorld : public entry::AppI {
//public:
//}

static void* sdlNativeWindowHandle(SDL_Window* _window)
{
    SDL_SysWMinfo wmi;
    SDL_VERSION(&wmi.version);
    if (!SDL_GetWindowWMInfo(_window, &wmi) )
    {
        return NULL;
    }
    return wmi.info.cocoa.window;

#	if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
    #		if ENTRY_CONFIG_USE_WAYLAND
			if (wmi.subsystem == SDL_SYSWM_WAYLAND)
				{
					wl_egl_window *win_impl = (wl_egl_window*)SDL_GetWindowData(_window, "wl_egl_window");
					if(!win_impl)
					{
						int width, height;
						SDL_GetWindowSize(_window, &width, &height);
						struct wl_surface* surface = wmi.info.wl.surface;
						if(!surface)
							return nullptr;
						win_impl = wl_egl_window_create(surface, width, height);
						SDL_SetWindowData(_window, "wl_egl_window", win_impl);
					}
					return (void*)(uintptr_t)win_impl;
				}
			else
#		endif // ENTRY_CONFIG_USE_WAYLAND
				return (void*)wmi.info.x11.window;
#	elif BX_PLATFORM_OSX || BX_PLATFORM_IOS
    return wmi.info.cocoa.window;
#	elif BX_PLATFORM_WINDOWS
    return wmi.info.win.window;
#   elif BX_PLATFORM_ANDROID
    return wmi.info.android.window;
#	endif // BX_PLATFORM_
}

void Application::test() {
    SDL_Init(SDL_INIT_GAMECONTROLLER);


    auto window = SDL_CreateWindow("bgfx"
            , SDL_WINDOWPOS_UNDEFINED
            , SDL_WINDOWPOS_UNDEFINED
            , 1280
            , 720
            , SDL_WINDOW_SHOWN
              | SDL_WINDOW_RESIZABLE
    );

//    auto renderer = SDL_CreateRenderer(window, 0, 0);

//    bgfx::PlatformData pd;
//    pd.nwh = sdlNativeWindowHandle(window);
//    bgfx::setPlatformData(pd);

    bgfx::Init bgfxInit;
    bgfxInit.platformData.nwh = sdlNativeWindowHandle(window);
    bgfxInit.type = bgfx::RendererType::Count; // Automatically choose a renderer.
    bgfxInit.resolution.width = 1280;
    bgfxInit.resolution.height = 720;
    bgfxInit.resolution.reset = BGFX_RESET_VSYNC | BGFX_RESET_HIDPI;

    bgfx::renderFrame();
    bgfx::init(bgfxInit);
//    bgfx::init();



//    int width, height;
//    SDL_GetWindowSize(window, &width, &height);
//    bgfx::setViewRect(0, 0, 0, width, height);

    bool needToStop = false;
    while (!needToStop) {
//        bgfx::renderFrame();

        bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
        bgfx::setViewRect(0, 0, 0, 1280, 720);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    needToStop = true;
                    break;
            }
        }


        bgfx::frame();

//        SDL_RenderClear(renderer);
//
//        SDL_Rect rect;
//        rect.x = 250;
//        rect.y = 150;
//        rect.w = 200;
//        rect.h = 200;
//
//        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//        SDL_RenderFillRect(renderer, &rect);
//
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//
////        SDL_RenderFlush(renderer);
//        SDL_RenderPresent(renderer);
    }

//    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
