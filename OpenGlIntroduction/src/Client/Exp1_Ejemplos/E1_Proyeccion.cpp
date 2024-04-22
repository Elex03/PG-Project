// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.
/*
#include <GL/freeglut.h> // we use glut here as window manager
#define _USE_MATH_DEFINES
#include <math.h>

class Renderer {

public:
    float t;

public:
    Renderer() : t(0.0) {}

public:

    void resize(int w, int h) {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(30.0, (float)w / (float)h, 2.0, 20.0);
    }

    void display() {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // camera orbits in the y=10 plane
        // and looks at origin
        double rad = M_PI / 180.0f * t;
        gluLookAt(10.0 * cos(rad), 10.0, 10.0 * sin(rad), // eye
            0.0, 0.0, 0.0, // look at
            0.0, 1.0, 0.0); // up

        //draw cube at origin
        drawCube();

        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(2.5f, 0.0f, 0.0f);
        glScalef(0.5f, 0.5f, 0.5f);

        drawCube(); //draw transformed cube
    }

    void init() {
        glEnable(GL_DEPTH_TEST);
    }
private:
    void drawCube() {
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glEnd();
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glEnd();
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glEnd();
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glEnd();
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glEnd();
        glColor3f(0.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glEnd();
    }
};

//this is a static pointer to a Renderer used in the glut callback functions
static Renderer* renderer;

//glut static callbacks start
static void glutResize(int w, int h)
{
    renderer->resize(w, h);
}

static void glutDisplay()
{
    renderer->display();
    glutSwapBuffers();
}

static void timer(int v)
{
    float offset = 1.0f;
    renderer->t += offset;
    glutDisplay();
    glutTimerFunc(unsigned(20), timer, ++v);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);

    glutCreateWindow("Demo for gluLookAt");

    glutDisplayFunc(glutDisplay);
    //glutIdleFunc(glutDisplay);
    glutReshapeFunc(glutResize);

    renderer = new Renderer;
    renderer->init();

    glutTimerFunc(unsigned(20), timer, 0);

    glutMainLoop();
}
*/