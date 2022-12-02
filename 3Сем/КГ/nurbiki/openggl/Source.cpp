#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <GL/glut.h>
#include <cstdio>
#include <math.h>
#define STB_IMAGE_IMPLEMENTATON
#include <gl/stb_image.h>

#ifdef GL_GLEXT_PROTOTYPES
...
...
GLAPI void APIENTRY glGenerateMipmap(GLenum);
...
#endif /* GL_GLEXT_PROTOTYPES */

char title[] = "КАЧАЛКА";
//туман
bool fog = 1;
bool   gp;                              // G Нажата? ( Новое )
GLuint filter;                          // Используемый фильтр для текстур
GLuint fogMode[] = { GL_EXP, GL_EXP2, GL_LINEAR }; // Хранит три типа тумана
GLuint fogfilter = 0;                    // Тип используемого тумана
GLfloat fogColor[4] = { 0.5f, 0.5f, 0.5f, 1.0f }; // Цвет тумана


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

//нурбы
const int size_numb_x = 4;
const int size_numb_y = 4;

GLfloat ctlpoints[size_numb_x][size_numb_y][3];
GLfloat knots[size_numb_x + size_numb_y] = {
  0.0, 0.0, 0.0, 0.0,
  1.0, 1.0, 1.0, 1.0
};
int showPoints = 0;

GLUnurbsObj* theNurb;

GLuint shtanga;
GLuint	texture;




void compile_lists() {
    shtanga = glGenLists(1);
   
    glNewList(shtanga, GL_COMPILE);

    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 1.0);
    glEnd;
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, 1.0, -1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, -1.0);
    glEnd;
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, -1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, 1.0, 1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, -1.0);
    glEnd();
    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0, -1.0, -1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);
    glEnd();
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 1.0);
    glEnd();
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, 1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, -1.0);
    glEnd();


    glEndList();

    glShadeModel(GL_FLAT);
   
}


void fog_on() 
{
   
        glEnable(GL_FOG);                       // Включает туман (GL_FOG)
        glFogi(GL_FOG_MODE, fogMode[fogfilter]);// Выбираем тип тумана
        glFogfv(GL_FOG_COLOR, fogColor);        // Устанавливаем цвет тумана
        glFogf(GL_FOG_DENSITY, 0.35f);          // Насколько густым будет туман
        glHint(GL_FOG_HINT, GL_DONT_CARE);      // Вспомогательная установка тумана
        glFogf(GL_FOG_START, 1.0f);             // Глубина, с которой начинается туман
        glFogf(GL_FOG_END, 5.0f);               // Глубина, где туман заканчивается.
   
   
}
void lightmove() {
    angle3 += 10;
    pos2[0] = ligtht_radius * sin(angle3 / 180);
    pos2[1] = ligtht_radius * cos(angle3 / 180);

    angle1 += 10;
    pos0[0] = ligtht_radius * cos(angle1 / 180);
    pos0[1] = ligtht_radius * sin(angle1 / 180);

    angle2 += 10;
    pos1[2] = ligtht_radius * cos(angle2 / 180);
    pos1[1] = ligtht_radius * sin(angle2 / 180);
}
void init_surface(void) {
    int u, v;
    int m = 2; // 2
    for (u = 0; u < size_numb_y; u++) {
        for (v = 0; v < size_numb_x; v++) {
            ctlpoints[u][v][0] = m * ((GLfloat)u - 1.5);
            ctlpoints[u][v][1] = m * ((GLfloat)v - 1.5);

            if ((u == 1 || u == 2) && (v == 1 || v == 2))
                ctlpoints[u][v][2] = 1.0;
            // else
            //     ctlpoints[u][v][2] = -1.0;
        }
    }
}



void display() {

   
   
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


    lightmove();

   

    gluBeginSurface(theNurb);
    glRotatef(90, 1, 0, 0);
    gluNurbsSurface(theNurb,
        size_numb_x + size_numb_y, knots, size_numb_x + size_numb_y, knots,
        size_numb_x * 3, 3, &ctlpoints[0][0][0],
        size_numb_x, size_numb_y, GL_MAP2_VERTEX_3);

    gluEndSurface(theNurb);


    glCallList(shtanga);

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
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClearDepth(1.0f);                   // глубина фона
    glEnable(GL_DEPTH_TEST);   // врубаем depth test
    glDepthFunc(GL_LEQUAL);    // тип depth test
    glShadeModel(GL_SMOOTH);   
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
    compile_lists();
    fog_on();
  
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
}



void process_Normal_Keys(unsigned char key, int x, int y) {

    switch (key) {

    case 'q': 
        angle_x += 1;
        break;

    case 'e':
        angle_x -= 1;
        break;

    case 'n':
        gp = 1;                         // gp устанавливаем в TRUE
        fogfilter += 1;                    // Увеличиние fogfilter на 1
        if (fogfilter > 2)                 // fogfilter больше 2 ... ?
        {
            fogfilter = 0;              // Если так, установить fogfilter в ноль
        }
        glFogi(GL_FOG_MODE, fogMode[fogfilter]); // Режим тумана

    case 'm':
        glDisable(GL_FOG);
        break;
    case 'M':
        glEnable(GL_FOG);
        break;

       
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
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    initGL();
    glEnable(GL_TEXTURE_2D);
 
    init_surface();

    theNurb = gluNewNurbsRenderer();
    gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 25.0);
    gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);


    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(process_Normal_Keys);
 
    glutMainLoop();

    return 0;
}
