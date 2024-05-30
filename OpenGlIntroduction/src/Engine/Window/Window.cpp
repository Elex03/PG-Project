#include "window.h"
Window::Window(int width, int height, const char* title) {
	
	glfwInit();

	//Le indicamos a GLFW con que version de OpenGL queremos trabajar. En este caso estamos usando OpenGL 3.7
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Le indicamos GLFW que estamos usando solo funciones modernas
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Establecemos el nombre que deseamos aparezca en pantalla
	m_window = glfwCreateWindow(width, height, title, NULL, NULL);

	//En caso que la ventana no se pueda crear entonces enviamos un error.
	if (m_window == NULL) {

		std::cout << "Fallo al tratar de crear la ventana usando GLFW" << std::endl;
		glfwTerminate();
	}

	//Ponemos la ventana en el contexto actual de lo que queremos presentar en pantalla
	glfwMakeContextCurrent(m_window);

}
Window::~Window() {
	// Termina GLFW
	glfwDestroyWindow(m_window);
	glfwTerminate();
}



