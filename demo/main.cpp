#include <Application.hpp>
#include <SDL_main.h>
#ifdef __SWITCH__
#include <stdio.h>
#include <switch.h>
#endif

int main(int argc, char *argv[]) {
#ifdef __SWITCH__
    socketInitializeDefault();              // Initialize sockets
    nxlinkStdio();                          // Redirect stdout and stderr over the network to nxlink
    printf("Hello Switch\n");
#endif

    auto result = Application::run();

#ifdef __SWITCH__
    socketExit();                           // Cleanup
#endif

    return result;
}
