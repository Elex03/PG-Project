/*void changePositions(GLFWwindow* window, double xpos, double ypos) {
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
*/