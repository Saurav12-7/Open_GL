#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); // Set color to purple
    glLoadIdentity();

    // Set the camera position and orientation
    gluLookAt(9.0, 6.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Draw the cube wireframe manually
    glBegin(GL_LINES);

    // Front face
    glVertex3f(-0.9f, -0.9f, 0.9f);
    glVertex3f(0.9f, -0.9f, 0.9f);

    glVertex3f(0.9f, -0.9f, 0.9f);
    glVertex3f(0.9f, 0.9f, 0.9f);

    glVertex3f(0.9f, 0.9f, 0.9f);
    glVertex3f(-0.9f, 0.9f, 0.9f);

    glVertex3f(-0.9f, 0.9f, 0.9f);
    glVertex3f(-0.9f, -0.9f, 0.9f);

    // Back face
    glVertex3f(-0.9f, -0.9f, -0.9f);
    glVertex3f(0.9f, -0.9f, -0.9f);

    glVertex3f(0.9f, -0.9f, -0.9f);
    glVertex3f(0.9f, 0.9f, -0.9f);

    glVertex3f(0.9f, 0.9f, -0.9f);
    glVertex3f(-0.9f, 0.9f, -0.9f);

    glVertex3f(-0.9f, 0.9f, -0.9f);
    glVertex3f(-0.9f, -0.9f, -0.9f);

    // Connecting lines
    glVertex3f(-0.9f, -0.9f, 0.9f);
    glVertex3f(-0.9f, -0.9f, -0.9f);

    glVertex3f(0.9f, -0.9f, 0.9f);
    glVertex3f(0.9f, -0.9f, -0.9f);

    glVertex3f(0.9f, 0.9f, 0.9f);
    glVertex3f(0.9f, 0.9f, -0.9f);

    glVertex3f(-0.9f, 0.9f, 0.9f);
    glVertex3f(-0.9f, 0.9f, -0.9f);

    glEnd();

    glutSwapBuffers();
}

// The reshape and main functions remain the same.

void reshape(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Cube Wireframe");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
