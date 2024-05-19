#include"shaderClass.h"
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}
//Procedemos a contruir el constructor de sombras
Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();
	//Create Vertex Shader Object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	//Compile the Vertex Shader into machine code
	glCompileShader(vertexShader);
	//Create Fragment Shader Object and get its reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//Attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	//Compile the Vertex Shader into machine code
	glCompileShader(fragmentShader);
	//Create Shader Program Object and get its reference
	ID = glCreateProgram();
	//Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	//Link all the shaders together into the Shader Program
	glLinkProgram(ID);
	//Delete the now useless Vertex and Fragment Shader Objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
void Shader::Activate()
{
	glUseProgram(ID);
}
void Shader::Delete()
{
	glUseProgram(ID);
}