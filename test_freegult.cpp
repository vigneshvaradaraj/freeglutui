#include "statemachine.h"

Button button_idle(BUTTON_IDLE_X, BUTTON_IDLE_Y, 100, 50);
Button button_settings(BUTTON_SETTINGS_X, BUTTON_SETTINGS_Y, 100, 50);

void drawText(const char* text, int x, int y) {
    glColor3f(0, 0, 0); // Set text color (black)
    glRasterPos2i(x, y); // Position from bottom-left (OpenGL coordinates)

    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    post_event(DISPLAY_EVENT);
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    y = 300 - y;  // Convert from window to OpenGL coordinates

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (button_idle.isInside(x, y)) {
            printf("idle pressed!\n");
            post_event(IDLE_BUTTON_EVENT);
        } else if (button_settings.isInside(x, y)) {
            
            printf("settings pressed!\n");
            post_event(SETTINGS_BUTTON_EVENT);
        }
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(1, 1, 1, 1); // white background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 300);  // Set coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutCreateWindow("BOOT AND CONFIG");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
