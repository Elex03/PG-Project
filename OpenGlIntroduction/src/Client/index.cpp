#include <Window.h>
#include <Shader.h>
#include <Arrays.h>
#include <vector>


void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	int width, height;

	glfwGetWindowSize(window, &width, &height);

	double x_normalized = (2.0 * xpos) / width - 1.0;
	double y_normalized = 1.0 - (2.0 * ypos) / height;

	std::cout << "Posición del mouse en OpenGL: (" << x_normalized << ", " << y_normalized << ")" << std::endl;
}

int main(void)
{
	Window window(800, 600, "Mi Ventana GLFW");
	int Longitud_Array = sizeof(positions) / sizeof(*positions);
	std::vector<unsigned int> buffers(Longitud_Array);

	// Establecer la función de devolución de llamada para la posición del cursor
	glfwSetCursorPosCallback(window.getWindow(), cursor_position_callback);

	glGenBuffers((Longitud_Array / 2), buffers.data());

	while (!glfwWindowShouldClose(window.getWindow())) {

		glClear(GL_COLOR_BUFFER_BIT);

		for (int i = 1, j = 0; i < Longitud_Array && !glfwWindowShouldClose(window.getWindow()); i += 2, j++)
		{
			Shader Shader;
			Shader.ChangeColor(Colors[j]);
			glUseProgram(Shader.getprogram());
			glBindBuffer(GL_ARRAY_BUFFER, buffers[j]);
			glBufferData(GL_ARRAY_BUFFER, positions[(i - 1)][0] * sizeof(float), positions[i], GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, (positions[(i - 1)][0]) / 2);
		}

		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}