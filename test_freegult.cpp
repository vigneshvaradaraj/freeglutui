#include "GL/glut.h"
#include <math.h>
#include <stdio.h>

class KM
{
    //kalman members
    int x,y,vx,vy;
    //member functions
    public:
    KM(int a,int b,int c,int d):x(a),y(b),vx(c),vy(d)
    {
        
    }
    void update(void);
    void meassure(void);
    void display(void);
};

KM km_ob(0,0,0,0);

void KM::update(void)
{
    //nothing
}
void KM::meassure(void)
{
    //nothing
}
void KM::display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen
    glLoadIdentity();              // Reset transformations

    glColor3f(1.0, 0.0, 0.0);  // Set color to Red
    //glBegin(GL_LINES);
        glVertex2f(-1.0, -1.0);  // Start at bottom-left (-1, -1)
        glVertex2f(1.0, 1.0);    // End at top-right (1, 1)
    //glEnd();

    glColor3f(0.0, 0.0, 1.0);  // Set color to Blue
    //glBegin(GL_LINES);
        glVertex2f(-1.0, 1.0);  // Start at top-left (-1, 1)
        glVertex2f(1.0, -1.0);  // End at bottom-right (1, -1)
    //glEnd();
    printf("howmany\n");
    glFlush();  // Render the drawing
}

void display() 
{
    km_ob.display();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background to white
    glColor3f(1.0, 1.0, 1.0); // Set default drawing color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3.5, 3.5, -1.5, 1.5); // Set coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 500);  // Set window size to 800x600 pixels
    glutInitWindowPosition(100, 0);  // Set window position on the screen
    glutCreateWindow("Graph");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
