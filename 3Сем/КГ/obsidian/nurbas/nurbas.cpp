#include <iostream>
#include <cmath>

#include <GL/glut.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define W_WIDTH 1280
#define W_HEIGHT 720

// camera

double angle_x = 0.0;
double angle_y = -5000.0;
float lx = -3.0f, ly = 0.0f, lz = -1.0f;
float x = -3.0f, y = 0.0f, z = 10.0f;

int refreshMills = 60;

float fraction = -0.5f;
float fraction_angle = 0.1f;

float light_fraction = -0.5f;

bool use_mouse = true;

bool forward = false;
bool back = false;
bool left = false;
bool right = false;


GLuint theTorus;
GLuint texture;

void move() {
    // camera
    if (forward) {
        z -= lz * fraction;
        x -= lx * fraction;
        y -= ly * fraction;
    }

    if (back) {
        z += lz * fraction;
        x += lx * fraction;
        y += ly * fraction;
    }

    if (left) {
        z += lx * fraction;
        x -= lz * fraction;
    }

    if (right) {
        z -= lx * fraction;
        x += lz * fraction;
    }

}

void keyUp(unsigned char key, int xx, int yy) {
    switch (key) {
        // camera
    case ('w'):
        forward = false;
        break;

    case ('s'):
        back = false;
        break;

    case ('a'):
        left = false;
        break;

    case ('d'):
        right = false;
        break;

        // fog
   
    case ('g'):
        use_mouse = !use_mouse;
        break;

        // выход
    case 27:
        //glutDestroyWindow ( Win.id );
        exit(0);
        break;

    }
}

void keyDown(unsigned char key, int xx, int yy) {
    switch (key) {

        // camera
    case ('w'):
        forward = true;
        break;

    case ('s'):
        back = true;
        break;

    case ('a'):
        left = true;
        break;

    case ('d'):
        right = true;
        break;

    }
}

double sensivity = 0.001;

void gen(int size) {
    theTorus = glGenLists(1);
    
  
    glNewList(theTorus, GL_COMPILE);
    glRotatef(90.0, 1.0, 0.0, 0.0);
   
        // glRotatef(i * 50, 0.0, 1.0, 0.0);
      

        glEnable(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glBindTexture(GL_TEXTURE_2D, texture);

            glTranslatef(-2.0f, 0.0f, 0.0f);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);
            glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
            glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);
            glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
            glEnd();


  
 
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glEndList();
}


void shadowmatrix(GLfloat matrix[4][4], GLfloat m[4], GLfloat lpos0[4])
{
    GLfloat dot;
    dot = m[0] * lpos0[0] +
        m[1] * lpos0[1] +
        m[2] * lpos0[2] +
        m[3] * lpos0[3];
    matrix[0][0] = dot - lpos0[0] * m[0];
    matrix[1][0] = 0.f - lpos0[0] * m[1];
    matrix[2][0] = 0.f - lpos0[0] * m[2];
    matrix[3][0] = 0.f - lpos0[0] * m[3];
    matrix[0][1] = 0.f - lpos0[1] * m[0];
    matrix[1][1] = dot - lpos0[1] * m[1];
    matrix[2][1] = 0.f - lpos0[1] * m[2];
    matrix[3][1] = 0.f - lpos0[1] * m[3];
    matrix[0][2] = 0.f - lpos0[2] * m[0];
    matrix[1][2] = 0.f - lpos0[2] * m[1];
    matrix[2][2] = dot - lpos0[2] * m[2];
    matrix[3][2] = 0.f - lpos0[2] * m[3];
    matrix[0][3] = 0.f - lpos0[3] * m[0];
    matrix[1][3] = 0.f - lpos0[3] * m[1];
    matrix[2][3] = 0.f - lpos0[3] * m[2];
    matrix[3][3] = dot - lpos0[3] * m[3];
}

void mouseMove(int xx, int yy) {
    if (use_mouse) {
        angle_x -= (W_WIDTH / 2 - xx) * sensivity;
        if ((angle_y + (W_HEIGHT / 2 - yy) * sensivity < -4998.3) && (angle_y + (W_HEIGHT / 2 - yy) * sensivity > -5001.3)) {
            angle_y += (W_HEIGHT / 2 - yy) * sensivity;
        }

        lx = sin(angle_y) * sin(angle_x);
        ly = -cos(angle_y);
        lz = -sin(angle_y) * cos(angle_x);
        glutWarpPointer(
            W_WIDTH / 2,
            W_HEIGHT / 2
        );
    }
}
float ambient[] = { 0.4, 0.4, 0.4, 1.0 };
float spec[] = { 1.0, 1.0, 1.0, 1.0 };
float specref[] = { 0.4, 0.4, 1.0, 1.0 };
float lpos0[] = { 5, 5, 0, 1 };
float black[] = { 0.0, 0.0, 0.0, 1.0 };

void display(void) {
    glLoadIdentity();
    move();
    gluLookAt(x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f);
    glPushMatrix();
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.5, 0.5, 0.5, 1);
    glPushMatrix();
    glEnable(GL_DEPTH_TEST);

    GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
    GLfloat light5_diffuse[] = { 1, 1, 1 }; //цвет источника света
    glEnable(GL_LIGHT5);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
    glLightfv(GL_LIGHT5, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, light5_diffuse);
    glLightfv(GL_LIGHT5, GL_POSITION, lpos0);
    glTranslated(lpos0[0], lpos0[1], lpos0[2]);
    
    GLfloat m[] = { -15, -30, -20, -10 };

    GLfloat matrix[4][4];
    shadowmatrix(matrix, m, lpos0); //подключаем ф-ю матрицы для тени
    glDisable(GL_LIGHTING);
    glColor4f(0.0, 0.0, 0.0, 0.5);
    glPushMatrix();
    // Проецируем тень 
    glMultMatrixf(*matrix);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_FALSE);
   
    glPopMatrix();


    glutSolidCube(1);
  
    glTranslated(-lpos0[0], -lpos0[1], -lpos0[2]);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);

    glVertex3f(10.0f, 10.0f, -10.0f);
    glVertex3f(10.0f, 0.0f, -10.0f);
    glVertex3f(0.0f, 0.0f, -10.0f);
    glVertex3f(0.0f, 10.0f, -10.0f);


    glEnd();


    glBindTexture(GL_TEXTURE_2D, texture);
    glTranslated(6, 5, -5);
 
    glCallList(theTorus);

  
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
    glFlush();
    
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_MAP2_VERTEX_3);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
}

void reshape(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(40.0, (GLfloat)w / h, 1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(1000 / refreshMills, timer, 0);
}

int main(int argc, char** argv) {

    glEnable(GL_DEPTH_TEST);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(150, 50);
    glutInitWindowSize(W_WIDTH, W_HEIGHT);
    glutCreateWindow("nurbs");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

    int width, height, nrChannels;
    unsigned char* data = stbi_load("side.png", &width, &height, &nrChannels, 0);

    glGenTextures(1, &texture);
    std::cout << texture << std::endl;
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    // stbi_image_free(data);

    init();

    gen(1);



    GLfloat mat_diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
    GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat mat_emission[] = { 0.5, 0.5, 0.5, 1.0 };
    // GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 128.0 };

    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);

    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);

    glutPassiveMotionFunc(mouseMove);

    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}
