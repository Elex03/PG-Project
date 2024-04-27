#include <Window.h>
#include <Shader.h>
#include <Arrays.h>
#include <vector>


void changePositions(GLFWwindow* window, double xpos, double ypos) {
	int width, height;

	glfwGetWindowSize(window, &width, &height);

	double x_position = (xpos * width + width) / 2;

}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	int width, height;

	glfwGetWindowSize(window, &width, &height);

	double x_normalized = (2.0 * xpos) / width - 1.0;

	double x_nonormalized = (x_normalized * width + width) / 2;
	double y_normalized = 1.0 - (2.0 * ypos) / height;
	double y_nonormalized = (y_normalized * height + height) / 2;

	std::cout << "Coordenadas en openGl: (" << x_nonormalized << ", " << y_nonormalized << ")" << std::endl;
}


int main(void)
{
	Window window(800, 600, "Mi Ventana GLFW");
	int Longitud_Array = sizeof(positions) / sizeof(*positions);
	std::vector<unsigned int> buffers(Longitud_Array);

	// Establecer la funci?n de devoluci?n de llamada para la posici?n del cursor
	glfwSetCursorPosCallback(window.getWindow(), cursor_position_callback);
	glGenBuffers((Longitud_Array / 2), buffers.data());

	bool estado = true;
	while (!glfwWindowShouldClose(window.getWindow())) {
		glClearColor(0.145, 0.157, 0.314, 1);

		while (estado)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			for (int i = 1, j = 0; i < Longitud_Array && !glfwWindowShouldClose(window.getWindow()); i += 2, j++)
			{
				Shader Shader(Colors[j]);
				glUseProgram(Shader.getprogram());
				glBindBuffer(GL_ARRAY_BUFFER, buffers[j]);
				glBufferData(GL_ARRAY_BUFFER, positions[(i - 1)][0] * sizeof(float), positions[i], GL_STATIC_DRAW);
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
				glDrawArrays(GL_TRIANGLE_STRIP, 0, (positions[(i - 1)][0]) / 2);
			}
			glfwSwapBuffers(window.getWindow());
			estado = false;
		}
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}