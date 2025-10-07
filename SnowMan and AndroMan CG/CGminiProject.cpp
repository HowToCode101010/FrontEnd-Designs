#include <windows.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <GL/glut.h>

static double x = 0.0, a = 0.0;
bool change = true;
static double r1 = 1.0;
bool rot = false, play = false;
static float y1 = 0;

void stroke_output(GLfloat x, GLfloat y, char *format, ...) {
    va_list args;
    char buffer[200], *p;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    glPushMatrix();
    glTranslatef(-2.5, y, 0);
    glScaled(0.003, 0.005, 0.005);
    for (p = buffer; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}

void tree() {
    glPushMatrix();
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(-.5, 0.5);
    glVertex2f(0, 0.7);
    glVertex2f(-0.3, 1);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.8, 2);
    glVertex2f(0.8, 0.9);
    glVertex2f(1.2, 1);
    glVertex2f(0.8, 0.8);
    glVertex2f(1.2, 0.5);
    glVertex2f(0.5, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, -0.4, 0);
    glScaled(0.2, 1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawSnowman() {
    glPushMatrix();
    glColor3f(1, 1, 1);

    // Top sphere (head)
    glPushMatrix();
    glScaled(0.8, 1.0, 0.8);
    glTranslatef(0.0, 1.2, 0.0);
    glutSolidSphere(0.4, 80, 120);
    glPopMatrix();

    // Eyes
    glPushMatrix();
    glScaled(0.8, 1.0, 0.8);
    glTranslatef(0.2, 1.4, 0.25);
    glutSolidSphere(0.06, 80, 120);
    glPopMatrix();

    glPushMatrix();
    glScaled(0.8, 1.0, 0.8);
    glTranslatef(-0.2, 1.4, 0.25);
    glutSolidSphere(0.06, 80, 120);
    glPopMatrix();

    // Nose
    glPushMatrix();
    glScaled(0.8, 1.0, 0.8);
    glTranslatef(0.0, 1.3, 0.0);
    glutSolidCone(0.1, 0.9, 80, 120);
    glPopMatrix();

    // Hat
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(0.0, 1.5, 0.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(0.2, 0.6, 10, 10);
    glPopMatrix();

    // Body
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScaled(0.8, 0.8, 0.8);
    glTranslatef(0.0, 0.2, 0.0);
    glutSolidSphere(0.9, 80, 120);
    glPopMatrix();

    // Buttons
    for (float i = 0.0; i <= 0.5; i += 0.25) {
        glPushMatrix();
        glColor3f(1, 0, 0);
        glTranslatef(0.0, i, 1.0);
        glScaled(0.2, 0.2, 0.2);
        glutSolidSphere(0.5, 80, 120);
        glPopMatrix();
    }

    glPopMatrix();
}

void andro() {
    glPushMatrix();
    glTranslatef(a, y1, 0.0);

    // Body
    glPushMatrix();
    glScaled(0.3, 1.5, 0.3);
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(0.5, 1, 30, 30);
    glPopMatrix();

    // Arms
    float dirs[2] = { 0.5, -0.5 };
    for (int i = 0; i < 2; i++) {
        glPushMatrix();
        glTranslatef(dirs[i], 0, 0);
        glScaled(0.1, 1, 0.1);
        glRotatef(90, 1, 0, 0);
        glutSolidTorus(0.4, 0.8, 30, 30);
        glPopMatrix();
    }

    // Head
    glPushMatrix();
    glTranslatef(0, 0.8, 0);
    glutSolidSphere(0.4, 30, 30);
    glPopMatrix();

    // Eyes
    glPushMatrix();
    glTranslatef(0.15, 0.85, 0.3);
    glutSolidSphere(0.1, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.15, 0.85, 0.3);
    glutSolidSphere(0.1, 30, 30);
    glPopMatrix();

    // Ears
    glPushMatrix();
    glTranslatef(-0.15, 1, 0);
    glScaled(0.5, 2, 0);
    glutSolidSphere(0.2, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, 1, 0);
    glScaled(0.5, 2, 0);
    glutSolidSphere(0.2, 30, 30);
    glPopMatrix();

    // Legs
    for (float i = -0.15; i <= 0.15; i += 0.3) {
        glPushMatrix();
        glTranslatef(i, -0.8, 0);
        glRotatef(r1, 1, 0, 0);
        glScaled(0.1, 1, 0.1);
        glRotatef(90, 1, 0, 0);
        glutSolidTorus(0.4, 0.8, 30, 30);
        glPopMatrix();
    }

    glPopMatrix();
}

void snowMan(double rang, double ad) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -13.0f);

    if (rot) {
        glRotatef(30, 0, 1, 0);
    }

    // Ground
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glScaled(1.0, 0.03, 100.8);
    glTranslatef(0.0, -30.2, 0.0);
    glutSolidCube(7.0);
    glPopMatrix();

    // Trees and Rings
    glPushMatrix();
    glTranslatef(0.0, 0.0, rang);
    glColor3f(1, 1, 0);

    for (int i = 0; i < 500; i += 13) {
        for (float j : { 2.5f, -2.5f }) {
            glPushMatrix();
            glTranslatef(j, -0.5, 7.0 + i);
            tree();
            glPopMatrix();
        }

        glPushMatrix();
        glTranslatef(0.0, 0.0, i + 40);
        glutSolidTorus(0.2, 3.0, 10, 15);
        glPopMatrix();
    }

    glPopMatrix();

    glPushMatrix();
    glTranslatef(ad, 0, 0);
    change ? drawSnowman() : andro();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void w() {
    r1 += 10;
    x -= 0.08;
    snowMan(x, a);
}

void s() {
    snowMan(x, a);
}

void skiLeft() {
    x -= 0.08;
    a -= 0.03;
    snowMan(x, a);
}

void skiRight() {
    x -= 0.08;
    a += 0.03;
    snowMan(x, a);
}

void doInit() {
    glColor3f(.0, 1.0, 1.0);
    glViewport(0, 0, 640, 480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f, 640.0f/480.0f, 0.1f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearDepth(2.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void menu(int id) {
    switch (id) {
        case 1: glutIdleFunc(w); break;
        case 2: glutIdleFunc(s); break;
        case 3: exit(0); break;
    }
    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
}

void mykey(unsigned char key, int x, int y) {
    switch (key) {
        case 'c': case 'C': change = !change; break;
        case 'r': case 'R': rot = !rot; break;
        case 'w': case 'W': y1 += 0.2; break;
        case 's': case 'S': y1 -= 0.2; break;
        case 'a': case 'A': a -= 0.3; snowMan(x, a); break;
        case 'd': case 'D': a += 0.3; snowMan(x, a); break;
        case ' ': play = !play; glutIdleFunc(play ? w : s); break;
        case 'q': case 'Q': exit(0); break;
    }
}

void doDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.8, 0.8, 0.8, 0);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -13.0f);

    glColor3f(0, 0, 0);
    stroke_output(-2.0, 2.2, "Interactive SnowMan by:");
    stroke_output(-2.0, 0.9, "Candidate 1 name");
    stroke_output(-2.0, 0.0, "Candidate 2 name");

    GLfloat mat_ambient[] = {0.0f, 1.0f, 2.0f, 1.0f};
    GLfloat mat_diffuse[] = {0.0f, 1.5f, 0.5f, 1.0f};
    GLfloat mat_specular[] = {5.0f, 1.0f, 1.0f, 1.0f};
    GLfloat shininess[] = {50.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    GLfloat lightIntensity[] = {10.7f, 0.7f, 100.7f, 1.0f};
    GLfloat light_position[] = {0.0f, 5.0f, 10.0f, 0.0f};

    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_COLOR_MATERIAL);

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(30, 0);
    glutCreateWindow("Snow/Man");

    glutDisplayFunc(doDisplay);
    glutKeyboardFunc(mykey);
    glutCreateMenu(menu);
    glutAddMenuEntry("Ski     's'", 1);
    glutAddMenuEntry("Stop Ski 'S'", 2);
    glutAddMenuEntry("Exit     'q'", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    doInit();
    glutMainLoop();
    return 0;
}
