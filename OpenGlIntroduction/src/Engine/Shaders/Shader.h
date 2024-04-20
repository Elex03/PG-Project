#pragma once
#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Shader {
public:
    unsigned int getprogram() const { return program; };
    static unsigned int CompileShader(unsigned int type, const std::string& source);
    void ChangeColor(std::string fragmentShader);

private:
    unsigned int program = glCreateProgram();

};