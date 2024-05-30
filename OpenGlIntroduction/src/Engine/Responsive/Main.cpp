#include <windows.h>   
#include <GL/glut.h>   

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.8f, 0.1f);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(-0.2f, 0.7f);
    glVertex2f(-0.8f, 0.7f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.7f, -0.6f);
    glVertex2f(-0.1f, -0.6f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.7f, 0.0f);

    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.9f, -0.7f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, -0.7f);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.5f, -0.3f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.9f, -0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.1f, -0.6f);
    glVertex2f(0.7f, -0.6f);
    glVertex2f(0.4f, -0.1f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, -0.4f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.9f, -0.4f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.6f, -0.9f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.6f, 0.2f);
    glVertex2f(0.7f, 0.4f);
    glVertex2f(0.6f, 0.6f);
    glVertex2f(0.4f, 0.6f);
    glVertex2f(0.3f, 0.4f);
    glEnd();

    glFlush();   // renderizar 
}
void reshape(GLsizei ancho, GLsizei alto) {
    // Calcula la relación de aspecto de la nueva ventana 
    if (alto == 0) alto = 1;
    GLfloat aspecto = (GLfloat)ancho / (GLfloat)alto;

    // Configura la ventana gráfica para cubrir la nueva ventana
    glViewport(0, 0, ancho, alto);

    // Establece la relación de aspecto del área de recorte para que coincida con la ventana gráfica 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (ancho >= alto) {
        gluOrtho2D(-1.0 * aspecto, 1.0 * aspecto, -1.0, 1.0);
    }
    else {
        gluOrtho2D(-1.0, 1.0, -1.0 / aspecto, 1.0 / aspecto);
    }
}

int Main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Viewport Transform");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutMainLoop();
    return 0;
}