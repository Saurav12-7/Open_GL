#include <GL/freeglut.h>
#include <cmath>

void drawSquare() {
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();
}

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glEnd();
}

void drawCircle(float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Center of the circle

    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(segments);
        float x = radius * std::cos(angle);
        float y = radius * std::sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(2.0f, 0.0f, 1.0f); // Red color

    glLoadIdentity();
    glTranslatef(0.5f, 0.5f, 0.0f);
    drawSquare();

    glLoadIdentity();
    glTranslatef(0.5f, -0.5f, 0.3f);
    drawTriangle();

    glLoadIdentity();
    glTranslatef(-0.5f, -0.5f, 0.8f);
    drawCircle(0.2f, 36); // 36 segments for a smooth circle

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Basic Shapes");

    glClearColor(2.0f, 2.0f, 2.0f, 2.0f); // White background

    glutDisplayFunc(display);

    glutMainLoop();


    return 0;
}