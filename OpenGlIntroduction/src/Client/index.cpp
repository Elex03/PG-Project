#include <Window.h>
int main(void)
{
    Window window(800, 600, "Mi Ventana GLFW");

    while (!glfwWindowShouldClose(window.getWindow())) {
        
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        //Renderizamos

        glfwSwapBuffers(window.getWindow());

    }
    glfwTerminate();
    return 0;
}
