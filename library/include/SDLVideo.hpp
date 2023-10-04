#include <Video.hpp>
#include <SDL.h>
#include <bgfx/bgfx.h>

class SDLVideo: public Video {
public:
    SDLVideo();

    void runMainLoop() override;
    void update() override;
    void draw(int width, int height, float scale) override;

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    const bgfx::ViewId kClearView = 0;
    int width = 0, height = 0;
    bool s_showStats = false;
    bool isInitialized = false;

    static SDLVideo* shared;
    static int resizingEventWatcher(void* data, SDL_Event* event);
    const int fpsCap = 120;
//    static void framebuffer_size_callback(SDLVideo* window, int width, int height);
};