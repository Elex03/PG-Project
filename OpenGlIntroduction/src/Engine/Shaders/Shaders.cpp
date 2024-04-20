#include "Shaders.h"

unsigned int Shaders::CompileShader(unsigned int type, const std::string& source) {

    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Fallo al compilar el sombreado de la figura" <<
            (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "Shader!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;

    }
    return id;
}
unsigned int Shaders::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    /*Combinando vertexShader con fragmentShader*/
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program); /*Realizando la union*/
    glValidateProgram(program); /*Validando el resultado final*/

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}
