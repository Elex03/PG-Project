#include "Window.h"

Window::Window(int width, int height, const char* title) {
    
    glfwInit();

    m_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!m_window) {
        glfwTerminate();
        throw "Error al crear la ventana GLFW";
    }
    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;


    const char* renderer = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
    std::cout << "Tarjeta gráfica: " << renderer << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;
    glfwMakeContextCurrent(m_window);
}

Window::~Window() {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}
