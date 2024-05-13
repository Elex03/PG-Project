#include "window.h"

Window::Window(int width, int height, const char* title) {
    glfwInit();
    
    m_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!m_window) {
        glfwTerminate();
        throw "Error al crear la ventana GLFW";
    }

    glfwMakeContextCurrent(m_window);


    std::cout << glGetString(GL_VERSION) << std::endl;

}
Window::~Window() {
    // Termina GLFW
    glfwDestroyWindow(m_window);
    glfwTerminate();
}
