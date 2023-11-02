#include <GL/glut.h>
#include <string>

float angleX = 0.0f;
float angleY = 0.0f;
float rotationStep = 2.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    glColor4f(1.0f, 1.0f, 1.0f, 0.5f); // Transparent white

    // Draw the wireframe cube
    glutWireCube(1.0);

    glDisable(GL_BLEND);

    // Draw labels for the vertices
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f(-0.8f, -0.8f, -0.8f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
    glRasterPos3f(0.8f, -0.8f, -0.8f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');
    glRasterPos3f(0.8f, 0.8f, -0.8f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'C');
    glRasterPos3f(-0.8f, 0.8f, -0.8f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'D');
    glRasterPos3f(-0.8f, -0.8f, 0.8f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
    glRasterPos3f(0.8f, -0.8f, 0.8f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'F');
    glRasterPos3f(0.8f, 0.8f, 0.8f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');
    glRasterPos3f(-0.8f, 0.8f, 0.8f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'H');

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        angleX += rotationStep;
        break;
    case GLUT_KEY_DOWN:
        angleX -= rotationStep;
        break;
    case GLUT_KEY_LEFT:
        angleY -= rotationStep;
        break;
    case GLUT_KEY_RIGHT:
        angleY += rotationStep;
        break;
    }
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Transparent Wireframe Cube");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
