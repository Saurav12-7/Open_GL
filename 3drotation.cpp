#include <GL/freeglut.h>
#include <iostream> 


// Define cube vertices and indices
GLfloat vertices[] = {
    -0.2f, -0.2f, -0.2f,
     0.2f, -0.2f, -0.2f,
     0.2f,  0.2f, -0.2f,
    -0.2f,  0.2f, -0.2f,
    -0.2f, -0.2f,  0.2f,
     0.2f, -0.2f,  0.2f,
     0.2f,  0.2f,  0.2f,
    -0.2f,  0.2f,  0.2f
};

GLuint indices[] = {
    0, 1, 2,
    2, 3, 0,
    4, 5, 6,
    6, 7, 4,
    0, 4, 7,
    7, 3, 0,
    1, 5, 6,
    6, 2, 1,
    3, 2, 6,
    6, 7, 3,
    0, 1, 5,
    5, 4, 0
};
GLfloat colors[] = {
    1.0f, 0.5f, 0.0f, // YELLOW
    1.0f, 0.5f, 0.0f, // YELLOW
    1.0f, 0.5f, 0.0f, // YELLOW
    1.0f, 0.5f, 0.0f, // YELLOW
    1.0f, 0.5f, 0.0f, // YELLOW
    1.0f, 0.5f, 0.0f, // YELLOW
    1.0f, 0.5f, 0.0f, // YELLOW
    1.0f, 0.5f, 0.0f  // YELLOW
};

// Rotation angles

GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;
GLfloat angleZ = 0.0f;

GLfloat rotationSpeed = 12.0f; // Adjust the rotation speed as needed

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -2.0f);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

    // Draw cube
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, indices);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);
}

//rotation direction flags
bool rotateclockwiseX = false;
bool rotateclockwiseY = false;
bool rotateclockwiseZ = false;



void keyboard(unsigned char key, int x, int y) {
    if (key == 'x' || key == 'X') {
        rotateclockwiseX = !rotateclockwiseX;
    }
    if (key == 'y' || key == 'Y') {
        rotateclockwiseY = !rotateclockwiseY;
    }
    if (key == 'z' || key == 'Z') {
        rotateclockwiseZ = !rotateclockwiseZ;
    }
}
void idle()
{
    static int previousTime = glutGet(GLUT_ELAPSED_TIME);
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    float deltaTime = (currentTime - previousTime) / 1000.0f; // Convert to seconds
    previousTime = currentTime;
    if (rotateclockwiseX) {
        angleX += rotationSpeed * deltaTime;

    }

    if (rotateclockwiseY) {
        angleY += rotationSpeed * deltaTime;

    }
    if (rotateclockwiseZ) {
        float rotationspeedZ = 15.0f;
        angleZ += rotationspeedZ * deltaTime;

    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL 3D Cube");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}