#include <nanovg.h>
#include <CoreAnimation/CALayer.hpp>

class Video {
public:
    virtual void runMainLoop() = 0;

    virtual void update() = 0;
    virtual void draw(int width, int height, float scale) = 0;

    CALayer* rootLayer = nullptr;
};