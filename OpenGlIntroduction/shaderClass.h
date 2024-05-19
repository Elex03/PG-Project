#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H
#include<glad/glad.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
std::string get_file_contents(const char* filename);
class Shader {
public:
	GLuint ID;
	Shader(const char* vertexFile, const char* fragmentFile);
	void Activate();
	void Delete();
};
#endif