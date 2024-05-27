#include<iostream>
#include<irrKlang/irrKlang.h>
#include<GLFW/glfw3.h>

using namespace irrklang;
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

// Inicializa IrrKlang
ISoundEngine* engine = createIrrKlangDevice();

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Verifica si la tecla 'E' fue presionada
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
    {
        // Reproduce el sonido
        if (engine)
        {
            engine->play2D("test1.wav", false);
        }
    }
}

int main()
{
    // Inicializa GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Crea una ventana
    GLFWwindow* window = glfwCreateWindow(800, 600, "Mi primer sonido con teclado", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Hace que el contexto de OpenGL sea actual
    glfwMakeContextCurrent(window);

    // Configura el callback de teclado
    glfwSetKeyCallback(window, key_callback);

    // Bucle principal
    while (!glfwWindowShouldClose(window))
    {
        // Renderiza aquí

        // Intercambia los buffers de pantalla
        glfwSwapBuffers(window);

        // Procesa eventos
        glfwPollEvents();
    }

    // Limpieza
    glfwDestroyWindow(window);
    glfwTerminate();

    // Detiene el motor de sonido
    if (engine)
    {
        engine->drop();
    }

    return 0;
}




