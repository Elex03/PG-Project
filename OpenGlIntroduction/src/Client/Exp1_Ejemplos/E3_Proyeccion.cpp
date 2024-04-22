/*
// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.

#include <GL/freeglut.h> // we use glut here as window manager

#include <math.h>

class Renderer {

public:
  float t;

public:
  Renderer() : t(0.0), width(0), height(0) {}

public:
  void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // top right viewport (look from front)
    glViewport(width/2, height/2, width/2, height/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawFrame();
    // set camera (look from positive x-direction)
    gluLookAt(10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    // draw scene
    drawSceneGrid();
    drawRotatingPyramid();

    // bottom left viewport (look from left)
    glViewport(0, 0, width/2, height/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawFrame();
     // set camera (look from negative y-direction)
    gluLookAt(0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    // draw scene
    drawSceneGrid();
    drawRotatingPyramid();

    // top left viewport (look from top)
    glViewport(0, height/2, width/2, height/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawFrame();
    // set camera (look from positive z-direction)
     gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0);
    // draw scene
    drawSceneGrid();
    drawRotatingPyramid();

    // bottom right viewport (perspective)
    glViewport(width/2, 0, width/2, height/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawFrame();
    // set camera
    gluLookAt(8.0, -2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    // draw scene
    drawSceneGrid();
    drawRotatingPyramid();
  }

  void init() {
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
  }

  void resize(int w, int h) {
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (30.0, (float)width/(float)height, 2.0, 20.0);

  }

private:
  int width;
  int height;

private:
  void drawFrame() {
      glLineWidth(2.0f);
      glMatrixMode(GL_PROJECTION);
      glPushMatrix();
      glLoadIdentity();
      glColor3f(1.0f, 1.0f, 1.0f);
      glBegin(GL_LINE_LOOP);
      glVertex3f(-1.0f, 1.0f, 0.0f);
      glVertex3f( 1.0f, 1.0f, 0.0f);
      glVertex3f( 1.0f,-1.0f, 0.0f);
      glVertex3f(-1.0f,-1.0f, 0.0f);
      glEnd();
      glPopMatrix();
      glMatrixMode(GL_MODELVIEW);
      glLineWidth(1.0f);
  }

  void drawSceneGrid() {
      glColor3f(0.3f, 0.3f, 0.3f);
      glBegin(GL_LINES);
      for(unsigned i=0; i<=10; i++) {
        glVertex3f(-5.0f+i, -5.0f,   0.0f);
        glVertex3f(-5.0f+i,  5.0f,   0.0f);
        glVertex3f(-5.0f,   -5.0f+i, 0.0f);
        glVertex3f( 5.0f,   -5.0f+i, 0.0f);
      }
      glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    drawCoordinateAxisZ();
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCoordinateAxisY();
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCoordinateAxisX();
  }

  void drawCoordinateAxisZ() {
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f); // z-axis
    glVertex3f(0.0f, 0.0f, 2.0f);
    glEnd();
    glLineWidth(1.0f);

    // z-axis tip
    glBegin(GL_TRIANGLES);
    glVertex3f( 0.0f, 0.0f, 2.0f);
    glVertex3f(-0.05f, 0.05f, 1.9f);
    glVertex3f( 0.05f, 0.05f, 1.9f);
    glVertex3f( 0.0f,  0.0f, 2.0f);
    glVertex3f( 0.05f, -0.05f, 1.9f);
    glVertex3f(-0.05f, -0.05f, 1.9f);
    glVertex3f( 0.0f,  0.0f, 2.0f);
    glVertex3f( 0.05f,  0.05f, 1.9f);
    glVertex3f( 0.05f, -0.05f, 1.9f);
    glVertex3f( 0.0f,  0.0f, 2.0f);
    glVertex3f(-0.05f, -0.05f, 1.9f);
    glVertex3f(-0.05f,  0.05f, 1.9f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f( 0.05f, -0.05f, 1.9f);
    glVertex3f( 0.05f,  0.05f, 1.9f);
    glVertex3f(-0.05f,  0.05f, 1.9f);
    glVertex3f(-0.05f, -0.05f, 1.9f);
    glEnd();
  }

  void drawCoordinateAxisX() {
      glPushMatrix();
      glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
      drawCoordinateAxisZ();
      glPopMatrix();
  }

  void drawCoordinateAxisY() {
      glPushMatrix();
      glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
      drawCoordinateAxisZ();
      glPopMatrix();
  }

  void drawRotatingPyramid() {
    glRotatef(t, 0.0f, 0.0f, 1.0f);
    drawPyramid();
  }

  void drawPyramid() {
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f( 0.0f, 0.0f, 1.5f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, 1.0f, 0.0f);
    glEnd();
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f( 0.0f,  0.0f, 1.5f);
    glVertex3f( 1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f( 0.0f,  0.0f, 1.5f);
    glVertex3f( 1.0f,  1.0f, 0.0f);
    glVertex3f( 1.0f, -1.0f, 0.0f);
    glEnd();
    glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f( 0.0f,  0.0f, 1.5f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f,  1.0f, 0.0f);
    glEnd();
    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_POLYGON);
    glVertex3f( 1.0f, -1.0f, 0.0f);
    glVertex3f( 1.0f,  1.0f, 0.0f);
    glVertex3f(-1.0f,  1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();
  }
};

//this is a static pointer to a Renderer used in the glut callback functions
static Renderer *renderer;

//glut static callbacks start
static void glutResize(int w, int h)
{
  renderer->resize(w,h);
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

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(320, 320);

  glutCreateWindow("glViewport Demo");

  glutDisplayFunc(glutDisplay);
  //glutIdleFunc(glutDisplay);
  glutReshapeFunc(glutResize);

  renderer = new Renderer;
  renderer->init();

  glutTimerFunc(unsigned(20), timer, 0);

  glutMainLoop();
}

*/