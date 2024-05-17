#include <iostream>
#include <Window.h>

int main() {


	Window window(600, 800, "Primitivas graficas");
	
	//Cargamos GLAD para configurar OpenGL
	gladLoadGL();

	//Especificamos el puerto de vision de OpenGL en la ventana. En este caso tiene las coordenadas desde x = 0, y = 0, hasta x = 800, y = 800
	glViewport(0, 0, 800, 800);

	//Especificamos el color de fondo
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f); //Podemos jugar con los parametros del color para obtener diferentes tonos del fondo en la ventana.

	//Limpiamos el buffer de memoria con el valor que tiene y asignamos un nuevo color si acaso es necesario
	glClear(GL_COLOR_BUFFER_BIT);

	//Realizamos un intercambio entre el buffer trasero con el buffer delantero, es decir, entre el registro viejo de memoria con el nuevo registro de memoria
	glfwSwapBuffers(window.getWindow());

	while (!glfwWindowShouldClose(window.getWindow()))
	{
		//Tomamos en consideracion todos los eventos que le puedan ser indicados a GLFW
		glfwPollEvents();
	}

	//Eliminamos la ventana antes de que termine el programa
	glfwDestroyWindow(window.getWindow());

	//Terminamos de ejecutar GLFW antes de que termine el programa
	glfwTerminate();

	return 0;

}
