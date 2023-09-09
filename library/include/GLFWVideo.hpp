//#include <Video.hpp>
//#include <GLFW/glfw3.h>
//#include <bgfx/bgfx.h>
//
//class GLFWVideo: public Video {
//public:
//    GLFWVideo();
//    void draw() override;
//
//private:
//    GLFWwindow *window = nullptr;
//    const bgfx::ViewId kClearView = 0;
//    int width = 0, height = 0;
//    int oldWidth = 0, oldHeight = 0;
//
//    static GLFWVideo* shared;
//    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//};