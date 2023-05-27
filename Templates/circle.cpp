// #include <windows.h>

#include <GL/gl.h>

#include <GL/glu.h>

#include <GL/glaux.h>

#include <math.h>

#define PI 3.14159

#define MaxIter 8000

#define CALLBACK

void CALLBACK myReshape(GLint w, GLint h)
{

  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluOrtho2D(-8, 8, -3, 13);

  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
}

void CALLBACK display(void)

{

  GLfloat x = 0, y = 0;

  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.4f, 0.8f, 0.4f);

  glBegin(GL_POINTS);

  for (int i = 1; i <= MaxIter; i++)

  {

    int n = (int)100 * rand() / (RAND_MAX + 1);

    GLfloat x1, y1;

    if (n < 1)

    {

      x1 = 0;

      y1 = 0.16 * y;

    }

    else if (n < 8)

    {

      x1 = 0.2 * x - 0.26 * y;

      y1 = 0.23 * x + 0.22 * y + 1.6;

    }

    else if (n < 16)

    {

      x1 = -0.15 * x + 0.28 * y;

      y1 = 0.26 * x + 0.24 * y + 0.44;

    }

    else

    {

      x1 = 0.85 * x + 0.04 * y;

      y1 = -0.04 * x + 0.85 * y + 1.6;
    }

    //按概率随机选取一个仿射变换      

    glVertex2f(x1, y1);

    x = x1;
    y = y1;

    glFlush();
  }

  glEnd();

  glFlush();
}

int main(int argc, char *argv[])

{

  auxInitDisplayMode(AUX_SINGLE | AUX_RGBA);

  auxInitPosition(0, 0, 300, 300);

  auxInitWindow("分形图案");

  glClearColor(0.0, 0.0, 0.0, 0.0);

  auxReshapeFunc(myReshape);

  auxMainLoop(display);
}