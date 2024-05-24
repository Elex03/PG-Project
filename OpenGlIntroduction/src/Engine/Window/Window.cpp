#include "window.h"
Window::Window(int width, int height, const char* title) {
	
    // Initialize GLFW
    glfwInit();
    // Tell GLFW what version of OpenGL we are using
    // In this case we are using OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Tell GLFW we are using the CORE profile
    // So that means we only have the modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Create a GLFWwindow object of 800 by 800 pixels
    m_window = glfwCreateWindow(width, height, title, NULL, NULL);
    // Error check if the window fails to create
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);

}
Window::~Window() {
	// Termina GLFW
	glfwDestroyWindow(m_window);
	glfwTerminate();
}



