#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    GLFWwindow* getWindow() const { return m_window; };


private:
    GLFWwindow* m_window;
};