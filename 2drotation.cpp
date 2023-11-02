#include <GL/glut.h>
#include <iostream>
#include <cmath>

// Variables to store transformation parameters
float translationX = 0.0f;
float translationY = 0.0f;
float rotationAngle = 0.0f;
float scaleFactor = 1.0f;

void drawShape()
{
    glPushMatrix();

    // Apply transformations
    glTranslatef(translationX, translationY, 0.0);
    glRotatef(rotationAngle, 0.0, 0.0, 1.0);
    glScalef(scaleFactor, scaleFactor, 1.0);

    // Draw your 2D shape here (e.g., a rectangle)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.2f); // Orange color
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawShape();

    glFlush();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0 * width / height, 1.0 * width / height, -1.0, 1.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        translationY += 0.1f; // Translate up
        break;
    case 's':
        translationY -= 0.1f; // Translate down
        break;
    case 'a':
        translationX -= 0.1f; // Translate left
        break;
    case 'd':
        translationX += 0.1f; // Translate right
        break;
    case 'r':
        rotationAngle += 10.0f; // Rotate clockwise
        break;
    case 'R':
        rotationAngle -= 10.0f; // Rotate counterclockwise
        break;
    case '+':
        scaleFactor += 0.1f; // Scale up
        break;
    case '-':
        scaleFactor -= 0.1f; // Scale down
        break;
    }
    glutPostRedisplay(); // Trigger a redraw
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("2D Transformations using GLUT");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}