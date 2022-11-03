#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <GL/glut.h>
#include <cstdio>
#include <math.h>




char title[] = "КАЧАЛКА";

GLfloat ligtht_radius = 5;
GLfloat angle_y =0.0f;
GLfloat angle_x = 0.0f;
GLfloat pos_x = 0;
GLfloat pos_y = 0.0f;
GLfloat zoom = -4.0f;
int refreshMills = 20;

//для света
GLfloat pos0[4] = { 0, 0, 0, 1 };
GLfloat pos1[4] = { 0, 0, 0, 1 };
GLfloat pos2[4] = { 0, 0, 0, 1 };

GLfloat angle1 = 0;
GLfloat angle2 = 120;
GLfloat angle3 = 240;


GLfloat diffuseColor0[] = { 1, 0.2, 0, 1.0 };
GLfloat diffuseColor1[] = { 0, 0.8,0, 1 };
GLfloat diffuseColor2[] = { 0.3, 0.5, 0.9, 1.0 };

GLfloat ambientColor2[] = { 0.6, 0.8, 0.8, 1.0 };
GLfloat ambientColor0[] = { 0.2, 0.2, 0.2, 1 };

GLfloat con_pos[3] = { 1, 0 , -1 };
GLfloat miror_cone[] = { 0.6, 0.0, 1.0, 1.0 };
GLfloat dif_cone[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat AMB_cone[] = { 0.0, 0.04, 0.2, 1.0 };
GLfloat EMIS_cone[] = { 0.1, 0.1, 0.1, 1.0 };


GLfloat pot_pos[3] = { 0, 0 , 0 };
GLfloat miror_pot[] = { 0.3, 0.2, 0.4, 1.0 };
GLfloat dif_pot[] = { 0.0, 1.0, 0.88, 0.3 };
GLfloat AMB_pot[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat EMIS_pot[] = { 0.0, 0.0, 0.0, 1.0 };

GLfloat miror_ico[] = { 0.1, 0.2, 0.4, 1.0 };
GLfloat dif_ico[] = { 0.2, 0.2, 0.2, 0.8 };
GLfloat AMB_ico[] = { 0.4, 1.0, 0.3, 0.2 };
GLfloat EMIS_ico[] = { 0.3, 0.3, 0.3, 0.3 };
GLfloat ico_pos[3] = { -1, 0, 0 };


void display() {
    //прозрачность
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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


 
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AMB_cone); 
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, miror_cone); 
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif_cone);   
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, EMIS_cone); 
    glTranslatef(con_pos[0], con_pos[1], con_pos[2]);
    glutSolidCone(1,2 ,100, 100);
    glTranslatef(-con_pos[0], -con_pos[1], -con_pos[2]);
   

    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AMB_pot);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, miror_pot);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif_pot);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,EMIS_pot);
    glTranslatef(pot_pos[0], pot_pos[1], pot_pos[2]);
    glutSolidTeapot(1);
    glTranslatef(-pot_pos[0], -pot_pos[1], -pot_pos[2]);


 
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AMB_ico);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, miror_ico);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif_ico);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, EMIS_ico);
    glTranslatef(ico_pos[0], ico_pos[1], ico_pos[2]);
    glutSolidIcosahedron();
    glTranslatef(-ico_pos[0], -ico_pos[1], -ico_pos[2]);
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
    glClearColor(0.1f, 0.1f, 0.2f, 1.0f); // цвет фона
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

    case ('+'):
        ligtht_radius += 0.5;
        break;

    case ('-'):
        ligtht_radius -= 0.5;
        break;
    case ('f'):
  
        angle1 += 10;
        pos0[0] = ligtht_radius * cos(angle1 / 180);
        pos0[1] = ligtht_radius * sin(angle1 / 180);
        break;
   
        /**/
    
    case ('F'):

        angle1 -= 10;
        pos0[0] = ligtht_radius * cos(angle1 / 180);
        pos0[1] = ligtht_radius * sin(angle1 / 180);
        break;

    case ('g'):

        angle2 += 10;
        pos1[2] = ligtht_radius * cos(angle2 / 180);
        pos1[1] = ligtht_radius * sin(angle2 / 180);
        break;

    case ('G'):

        angle2 -= 10;
        pos1[2] = ligtht_radius * cos(angle2 / 180);
        pos1[1] = ligtht_radius * sin(angle2 / 180);
        break;

    case ('h'):

        angle3 += 10;
        pos2[0] = ligtht_radius * sin(angle3 / 180);
        pos2[1] = ligtht_radius * cos(angle3 / 180);
        break;

    case ('H'):

        angle3 -= 10;
        pos2[0] = ligtht_radius * sin(angle3 / 180);
        pos2[1] = ligtht_radius * cos(angle3 / 180);
        break;

    case ('.'):
        pot_pos[1] += 0.1;
        break;

    case (','):
        pot_pos[1] -= 0.1;
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
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
