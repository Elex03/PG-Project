#include <Window.h>
#include <Shader.h>
#include <Arrays.h>

int main(void)
{
	Window window(800, 600, "Mi Ventana GLFW");
	int Longitud_Array = sizeof(simpleTriangle) / sizeof(*simpleTriangle);
	unsigned int buffer;

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, Longitud_Array * sizeof(float), simpleTriangle, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	Shader Shader(Colors[0]);

	while (!glfwWindowShouldClose(window.getWindow())) {
		glClearColor(0.145, 0.157, 0.314, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, Longitud_Array / 2);
		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
	}
	window.~Window();
	return 0;
}