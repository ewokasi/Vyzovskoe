#include <iostream>
#include <math.h>
#include <gl/glut.h>

int Angle = 10.0;
//координаты поверхности
GLfloat ctrlpoints[4][4][3] = {

{{-3.5, 1.0, -4.5}, {-0.5, 1.0,-4.5 }, {0.5, 1.0, -4.5 }, {3.5, 1.0,-4.5}},

{{-3.5, 0.5, -0.5}, {-0.5, 0.5, -0.5 }, {0.5, 0.5, -0.5}, {3.5, 0.5,-0.5}},

{{-3.5, 0.0, 0.5}, {-0.5, 0.0, 0.5 }, {0.5, 0.0, 0.5 }, {3.5, 0.0, 0.5}},

{{-3.5, -0.5, 4.5}, {-0.5, -0.5, 4.5 }, {0.5, -0.5, 4.5 }, {3.5, -0.5, 4.5}}

};

GLfloat m[] = { -15, -30, -20, -10 };

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

//для работы с поверхностью
void initMap(void)
{
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);
	glMapGrid2f(2, 0.0, 2.0, 2, 0.0, 2.0);
}

void init(void)
{
	glClearColor(0.3, 0.2, 0.2, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
	initMap();
}

void changeSize(int w, int h)
{
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(4.5f, ratio, 0.1f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
}

void Keyboard(unsigned char key, int x, int y) {

	if (key == 48)
	{
		exit(0);
	}
	else if (key == 119)
	{
		Angle += 3;
	}
	else if (key == 115)
	{
		Angle -= 3;
	}
}

void Reshape(GLint w, GLint h)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);

}
float ambient[] = { 0.4, 0.4, 0.4, 1.0 };
float spec[] = { 1.0, 1.0, 1.0, 1.0 };
float specref[] = { 0.4, 0.4, 1.0, 1.0 };
float lpos0[] = { -4, -4, -5, 0 };
float black[] = { 0.0, 0.0, 0.0, 1.0 };
void renderScene(void) {
	glScalef(1.5, 1.5, 1.5);
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST); //фигуры не просвечиваются
	glPushMatrix();
	glRotatef(50.0, 0.5, 1.0, 0.0);
	for (j = 0; j <= 500; j++)
	{
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 500; i++)
			glEvalCoord2f((GLfloat)i / 500.0, (GLfloat)j / 500.0);
		glEnd();
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 500; i++)
			glEvalCoord2f((GLfloat)j / 500.0, (GLfloat)i / 500.0);
		glEnd();
	}
	glPopMatrix();
	glLoadIdentity();
	gluLookAt(-0.9f, -0.1f, -1.5f,
		0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f);
	glPushMatrix();
	GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_diffuse);
	GLfloat light5_diffuse[] = { 1, 1, 1 }; //цвет источника света
	glEnable(GL_LIGHT5);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
	glLightfv(GL_LIGHT5, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, light5_diffuse);
	glLightfv(GL_LIGHT5, GL_POSITION, lpos0);
	glLightfv(GL_LIGHT5, GL_SPECULAR, spec);
	GLfloat matrix[4][4];
	shadowmatrix(matrix, m, lpos0); //подключаем ф-ю матрицы для тени
	glDisable(GL_LIGHTING);
	glColor4f(0.0, 0.0, 0.0, 0.5);
	glPushMatrix();
	// Проецируем тень 
	glMultMatrixf(*matrix);
	glRotatef(Angle, 1.0, 1.0, 1.0);
	glTranslatef(0.0, -1.0, -4.0);
	glutSolidSphere(1.0, 100, 100);
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glRotatef(Angle, 1.0, 1.0, 1.0);
	glTranslatef(0.0, -1.0, -4.0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthMask(GL_FALSE);
	glColor4f(1.0, 0.5, 1.0, 0.5);
	const GLfloat paramsA[] = { 0.0215,	0.1745,	0.0215, 1.0 };
	const GLfloat paramsD[] = { 0.07568, 0.61424, 0.07568, 1.0 };
	const GLfloat paramsS[] = { 0.633, 0.727811, 0.633, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, paramsA);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, paramsD);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, paramsS);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128);
	glutSolidSphere(1.0, 100, 100);
	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
	glColor4f(0.0, 0.5, 1.0, 0.5);

	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("lab6");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutReshapeFunc(Reshape);
	init();
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 1;
}