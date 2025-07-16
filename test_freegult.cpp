#include "GL/freeglut.h"
#include "statemachine.h"


class Button {
public:
    int x, y, width, height;
    bool pressed;

    Button(int x_, int y_, int w, int h)
        : x(x_), y(y_), width(w), height(h), pressed(false) {}

    void draw() const {
        if (pressed)
            glColor3f(0.0f, 1.0f, 0.0f);  // Green if pressed
        else
            glColor3f(1.0f, 0.0f, 0.0f);  // Red if not pressed

        glBegin(GL_QUADS);
        glVertex2i(x, y);
        glVertex2i(x + width, y);
        glVertex2i(x + width, y + height);
        glVertex2i(x, y + height);
        glEnd();
    }

    bool isInside(int mx, int my) const {
        return (mx >= x && mx <= x + width && my >= y && my <= y + height);
    }
};

Button button_idle(50, 100, 100, 50);
Button button_settings(200, 100, 100, 50);

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    switch(current_state)
    {
        case IDLE_STATE:
        {
            button_idle.draw();
            break;
        }
        case SETTINGS_STATE:
        {
            button_settings.draw();
            break;
        }

    }

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    y = 300 - y;  // Convert from window to OpenGL coordinates

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (button_idle.isInside(x, y)) {
            button_idle.pressed = !button_idle.pressed;
            printf("idle pressed!");
            post_event(IDLE_BUTTON_EVENT);
        } else if (button_settings.isInside(x, y)) {
            button_settings.pressed = !button_settings.pressed;
            printf("settings pressed!");
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
