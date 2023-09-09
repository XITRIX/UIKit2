#include <Video.hpp>
#include <SDL.h>
#include <bgfx/bgfx.h>

class SDLVideo: public Video {
public:
    SDLVideo();
    void draw() override;

private:
    SDL_Window *window = nullptr;
    const bgfx::ViewId kClearView = 0;
    int width = 0, height = 0;
    bool s_showStats = false;

    static SDLVideo* shared;
    static int resizingEventWatcher(void* data, SDL_Event* event);
//    static void framebuffer_size_callback(SDLVideo* window, int width, int height);
};