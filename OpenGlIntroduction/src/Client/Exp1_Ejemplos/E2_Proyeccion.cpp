// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.
/*
#include <GL/freeglut.h> // we use glut here as window manager

#include <math.h>
#ifndef M_PI 
#define M_PI 3.1415926535897932385f 
#endif

#include <sstream>
#include <vector>
using namespace std;

class Renderer {

public:
    float t; //time
    const float d0; // initial distance

public:
    Renderer() : t(1.0), d0(3.0), width(0), height(0) {}

public:
    void display() {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(dollyZoomFovy(), (float)width / (float)height, 0.1, 50.0);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        // translate camera by 3 units
        glTranslatef(0.0f, 0.0f, -t * d0);

        // draw a cube in the local coordinate system
        drawCube();
        // draw random lines
        drawRandomLines();
    }

    void init() {
        glEnable(GL_DEPTH_TEST);
        // create random values between -1.0 and 1.0
        for (unsigned r = 0; r < 1000; r++) {
            int rval = rand();
            randVals.push_back(2.0f * float(rval) / float(RAND_MAX) - 1.0f);
        }
    }

    void resize(int w, int h) {
        // ignore this for now
        glViewport(0, 0, w, h);
        width = w;
        height = h;
    }

    float dollyZoomFovy() {
        float fovyInit = 60.0f; // initial field of view
        float theta = fovyInit / 180.0f * M_PI; // degree to rad
        float f = 1.0f / tan(theta / 2.0f);
        float fNew = f * (d0 * t - 1) / (d0 - 1);
        float thetaNew = atan(1.0f / fNew) * 2.0f;
        float val = 180.0f * thetaNew / M_PI; //rad to degree
        return val;
    }

private:
    int width;
    int height;
    std::vector<float> randVals;

private:
    void drawCube() {

        glColor3f(1.0f, 1.0f, 1.0f);
        glLineWidth(3.0f);
        glBegin(GL_LINE_LOOP);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glEnd();
        glLineWidth(1.0);
    }

    void drawRandomLines() {
        if (randVals.size() % 5) return;
        unsigned i = 0;
        while (i < randVals.size()) {
            glColor3f(fabs(randVals[i++]), fabs(randVals[i++]), fabs(randVals[i++]));
            float x = randVals[i++];
            float y = randVals[i++];
            glBegin(GL_LINES);
            glVertex3f(x, y, -1.0f);
            glVertex3f(x, y, 1.0f);
            glEnd();
        }
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

static void glutKeyboard(unsigned char key, int x, int y) {
    bool redraw = false;
    float offset = 0.02f;

    if (glutGetModifiers() & GLUT_ACTIVE_ALT) {
        offset = -offset;
    }
    switch (key) {
    case '1':
        renderer->t += offset;
        if (renderer->t < 1.0f) renderer->t = 4.0f;
        if (renderer->t > 4.0f) renderer->t = 1.0f;
        redraw = true;
        break;
    case '0':
        renderer->t = 1.0f;
        redraw = true;
        break;
    }
    if (redraw) {
        float distance = renderer->t * renderer->d0;
        float fovy = renderer->dollyZoomFovy();

        std::stringstream ss;
        ss << "Distance: " << int(distance * 10.0f) / 10.0f << " FieldofView: " << int(fovy * 10.0f) / 10.0f;
        glutSetWindowTitle(ss.str().c_str());
        glutDisplay();
    }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);

    glutCreateWindow("Use the 1 key to perform a dolly zoom");

    glutDisplayFunc(glutDisplay);
    //glutIdleFunc(glutDisplay);
    glutReshapeFunc(glutResize);
    glutKeyboardFunc(glutKeyboard);

    renderer = new Renderer;
    renderer->init();

    glutMainLoop();
}
*/