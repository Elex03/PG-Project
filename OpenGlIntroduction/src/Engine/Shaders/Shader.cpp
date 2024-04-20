#include "Shader.h"

std::string vertexShader =
"#version 330 core\n"
"\n"
"layout(location = 0) in vec4 position;\n"
"\n"
"void main()\n"
"{\n"
" gl_Position = position;\n"
"}\n";

static std::string putColor(std::string color) {
	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		" color = vec4(" + color + ");\n"/*Establecimiento del color*/
		"}\n";
	return fragmentShader;
}

Shader::Shader(std::string fragmentShader)
{
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, putColor(fragmentShader));

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program); /*Realizando la union*/
	glValidateProgram(program); /*Validando el resultado final*/

	glDeleteShader(vs);
	glDeleteShader(fs);
}

void Shader::ChangeColor(std::string fragmentShader)
{
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, putColor(fragmentShader));

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program); /*Realizando la union*/
	glValidateProgram(program); /*Validando el resultado final*/

	glDeleteShader(vs);
	glDeleteShader(fs);
}
unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {

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