#include "statemachine.h"

Button button_idle(50, 100, 100, 50);
Button button_settings(200, 100, 100, 50);

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    post_event(DISPLAY_EVENT);
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    y = 300 - y;  // Convert from window to OpenGL coordinates

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (button_idle.isInside(x, y)) {
            button_idle.pressed = !button_idle.pressed;
            printf("idle pressed!\n");
            post_event(IDLE_BUTTON_EVENT);
        } else if (button_settings.isInside(x, y)) {
            button_settings.pressed = !button_settings.pressed;
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
    glutCreateWindow("Two Button Demo");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
