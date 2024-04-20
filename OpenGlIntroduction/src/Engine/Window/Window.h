#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    GLFWwindow* getWindow() const { return m_window; };
    static unsigned int CompileShader(unsigned int type, const std::string& source);
    static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);


private:
    GLFWwindow* m_window;
};