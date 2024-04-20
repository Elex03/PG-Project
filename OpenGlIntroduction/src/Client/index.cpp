#include <Window.h>

std::string shaders(std:: string color) {
	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		" color = vec4("+color+");\n"/*Establecimiento del color*/
		"}\n";
	return fragmentShader;
}
int main(void)
{
	Window window(800, 600, "Mi Ventana GLFW");


	float positions[] = {
		 0.0f, 0.9f,
		 0.9f, 0.0f,
		 0.0f,-0.9f,
		 -0.9f, 0.0f,
		 0.0f, 0.9f,
	};


	int Longitud_Array = sizeof(positions) / sizeof(*positions);
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, Longitud_Array * sizeof(float), positions, GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	std::string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main()\n"
		"{\n"
		" gl_Position = position;\n"
		"}\n";

	unsigned int shader = window.CreateShader(vertexShader, shaders("0.494,0.518,0.969, 0"));
	glUseProgram(shader);

	while (!glfwWindowShouldClose(window.getWindow())) {

		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLE_STRIP, 0, (Longitud_Array / 2));

		glfwSwapBuffers(window.getWindow());

		glfwPollEvents();

	}
	glfwTerminate();
	return 0;

}