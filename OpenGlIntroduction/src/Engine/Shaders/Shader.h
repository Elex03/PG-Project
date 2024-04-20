#pragma once
#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Shader {
public:
    Shader(std::string fragmentShader);

    unsigned int getprogram() const { return program; };
    static unsigned int CompileShader(unsigned int type, const std::string& source);
	

private:
    unsigned int program = glCreateProgram();

};