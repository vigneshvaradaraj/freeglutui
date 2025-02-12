#include "GL/glut.h"

float pos = -1.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(pos, 0.0, 0.0);
    
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(0.1, 20, 20);

    glFlush();
}

void timer(int) {
    pos += 0.01;
    if (pos > 1.0) pos = -1.0;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("GLUT Animation");
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
