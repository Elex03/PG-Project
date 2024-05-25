#pragma once
#include<GLFW/glfw3.h>

GLfloat vertices[] = {
    // Coordenadas       // Colores          // Coordenadas de Textura
    // Cara frontal
    -0.5f, -0.5f,  0.5f,  0.83f, 0.70f, 0.44f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.83f, 0.70f, 0.44f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.83f, 0.70f, 0.44f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.83f, 0.70f, 0.44f,  0.0f, 1.0f,
    // Cara trasera
    -0.5f, -0.5f, -0.5f,  0.83f, 0.70f, 0.44f,  1.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.83f, 0.70f, 0.44f,  0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.83f, 0.70f, 0.44f,  0.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.83f, 0.70f, 0.44f,  1.0f, 1.0f
};

GLuint indices[] = {
    // Cara frontal
    0, 1, 2,
    2, 3, 0,
    // Cara trasera
    4, 5, 6,
    6, 7, 4,
    // Cara izquierda
    4, 0, 3,
    3, 7, 4,
    // Cara derecha
    1, 5, 6,
    6, 2, 1,
    // Cara superior
    3, 2, 6,
    6, 7, 3,
    // Cara inferior
    4, 5, 1,
    1, 0, 4
};