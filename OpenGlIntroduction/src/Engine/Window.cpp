#include "Window.h"

Window::Window(int width, int height, const char* title) {
    // Inicializa GLFW
    glfwInit();

    // Configura la ventana
    m_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!m_window) {
        glfwTerminate();
        throw "Error al crear la ventana GLFW";
    }

    // Hacer que la ventana sea el contexto principal
    glfwMakeContextCurrent(m_window);
}

Window::~Window() {
    // Termina GLFW
    glfwDestroyWindow(m_window);
    glfwTerminate();
}
