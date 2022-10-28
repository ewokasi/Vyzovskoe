#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <GL/glut.h>
#include <cstdio>
#include <math.h>
#include "Header.h"
//#include "stb_image.h"


char title[] = "BOX";


GLfloat mousepos[] = { 0, 0 };

GLfloat angle_y = -70.0f;
GLfloat angle_x = 0.0f;
GLfloat pos_x = -2.5f;
GLfloat pos_y = 1.0f;
GLfloat zoom = -14.0f;
int refreshMills = 20;

//для света
GLfloat pos0[4] = { 0, 0, 0, 1 };
GLfloat pos1[4] = { 0, 0, 0, 1 };
GLfloat pos2[4] = { 0, 0, 0, 1 };

GLfloat angle1 = 0;
GLfloat angle2 = 120;
GLfloat angle3 = 240;


GLfloat diffuseColor0[] = { 1, 0.2, 0, 1.0 };
GLfloat diffuseColor1[] = { 0, 0.8,0, 0.4 };
GLfloat diffuseColor2[] = { 0.3, 0.5, 0.9, 1.0 };

GLfloat ambientColor2[] = { 0.6, 0.8, 0.8, 1.0 };
GLfloat ambientColor0[] = { 0.2, 0.2, 0.2, 0.4 };
int light = 0;

void display() {



    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
   
   
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseColor0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, pos0);
    glTranslated(pos0[0], pos0[1], pos0[2]);
    glutSolidSphere(0.3, 10, 10);
    glTranslated(-pos0[0], -pos0[1], -pos0[2]);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, pos1);
    glTranslated(pos1[0], pos1[1], pos1[2]);
    glutSolidSphere(0.3, 10, 10);
    glTranslated(-pos1[0], -pos1[1], -pos1[2]);

    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseColor2);
    glLightfv(GL_LIGHT2, GL_AMBIENT, ambientColor2);
    glLightfv(GL_LIGHT2, GL_POSITION, pos2);
    glTranslated(pos2[0], pos2[1], pos2[2]);
    glutSolidSphere(0.3, 10, 10);
    glTranslated(-pos2[0], -pos2[1], -pos2[2]);


    angle1 += 10;
    pos0[0] = 10 * cos(angle1 / 180);
    pos0[1] = 10 * sin(angle1 / 180);


    angle2 += 10;
    pos1[2] = 10 * cos(angle2 / 180);
    pos1[1] = 10 * sin(angle2 / 180);


    angle3 += 10;
    pos2[0] = 10 * sin(angle3 / 180);
    pos2[1] = 10 * cos(angle3 / 180);

 
    GLfloat miror[] = { 0.6, 0.0, 1.0, 3.0 }; 
    GLfloat dif[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat AMB[] = { 0.0, 0.04, 0.2, 0.5 };
    GLfloat EMIS[] = { 0.1, 0.1, 0.1, 0.6 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AMB); 
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, miror); 
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif);   
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, EMIS); 
    glTranslatef(0.0f, 0.0f, -8.0f);
    glTranslatef(1.0f, 0.0f, 4.0f);
    glTranslatef(0.0f, 0.0f, 8.0f);
    glTranslatef(-1.0f, 0.0f, -4.0f);
    glutSolidCone(1,2 ,100, 100);
   

    GLfloat miror2[] = { 0.3, 0.2, 0.4, 1.0 };   
    GLfloat dif2[] = { 0.0, 1.0, 0.88, 1.0 }; 
    GLfloat AMB2[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat EMIS2[] = { 0.0, 0.0, 0.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AMB2); 
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, miror2); 
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif2);    
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,EMIS);         
    glTranslatef(3, 5, 0);
    glutSolidOctahedron();
    glTranslatef(-3, -5, 0);
    glTranslatef(0, -5, 0);

    GLfloat miror3[] = { 0.1, 0.2, 0.4, 0.0 };
    GLfloat dif3[] = { 0.2, 0.2, 0.2, 0.4 };
    GLfloat AMB3[] = { 0.93, 1.0, 0.3, 1.0 };
    GLfloat EMIS3[] = { 0.3, 0.3, 0.3, 0.1 };


    glTranslatef(3, 0, 0);
    
    glutSolidIcosahedron();
    glTranslatef(-3, 0, 0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AMB3); 
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, miror3);   
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif3);  
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, EMIS3);
    glFlush();
    glDisable(GL_TEXTURE_2D);


    glLoadIdentity();
    glTranslatef(pos_x, pos_y, zoom);
    glRotatef(angle_x, 0.0f, 1.0f, 0.0f);
    glRotatef(angle_y, 1.0f, 0.0f, 0.0f);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    
    glPopMatrix();
    glutSwapBuffers();
}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // цвет фона
    glClearDepth(1.0f);                   // глубина фона
    glEnable(GL_DEPTH_TEST);   // врубаем depth test
    glDepthFunc(GL_LEQUAL);    // тип depth test
    glShadeModel(GL_SMOOTH);   
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}

void process_Normal_Keys(unsigned char key, int x, int y) {

    switch (key) {

        // rot_x
    case '6':
        angle_x -= 5;
        break;

    case '4':
        angle_x += 5;
        break;

        // rot_y
    case '2':
        angle_y -= 5;
        break;

    case '8':
        angle_y += 5;
        break;

        // zoom
    case ('w'):
        zoom += 0.5;
        break;

    case ('s'):
        zoom -= 0.5;
        break;

    default:
        break;

        // pos_x
    case ('d'):
        pos_x -= 0.5;
        break;

    case 'a':
        pos_x += 0.5;
        break;

        // pos_y
    case ('9'):
        pos_y += 0.1;
        break;

    case('3'):
        pos_y += -0.5;
        break;
    case ('f'):
  
        angle1 += 10;
        pos0[0] = 10* cos(angle1 / 180);
        pos0[1] = 10* sin(angle1 / 180);


        angle2 += 10;
        pos1[2] = 10 * cos(angle2 / 180);
        pos1[1] = 10 * sin(angle2 / 180);

   
        angle3 += 10;
        pos2[0] = 10 * sin(angle3 / 180);
        pos2[1] = 10 * cos(angle3 / 180);
        break;

    }
}


void reshape(GLsizei width, GLsizei height) {

    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;


    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(refreshMills, timer, 0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480); // размеры окна
    glutInitWindowPosition(50, 50); // позиция окна на экране
    glutCreateWindow(title); // создаём окно
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    initGL();



    glutDisplayFunc(display);
    glutReshapeFunc(reshape);


    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(process_Normal_Keys);

    glutMainLoop();

    return 0;
}
