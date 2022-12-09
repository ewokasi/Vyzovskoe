#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "gl/glut.h"

#include "scene.h"

void DrawScene(float angle)
{
	static GLuint figures = 0, scene2 = 0;
	if (!figures)
	{
		figures = glGenLists(1);
		glNewList(figures, GL_COMPILE);
		{
			glPushMatrix();
			glColor3f(0.0f, 1.39f, 2.55f);
			glTranslatef(-0.55f, 1.4f, 0.45f);
			glutWireTeapot(0.3);
			glPopMatrix();
			glPushMatrix();
			glColor3f(2.55f, 0.0f, 0.0f);
			glTranslatef(0.45f, 2.0f, -0.45f);
			glutSolidCube(0.55);
			glPopMatrix();
		}
		glEndList();
	}
	if (!scene2)
	{
		scene2 = glGenLists(1);
		glNewList(scene2, GL_COMPILE);
		{
			glColor3f(0.76f, 0.88f, 0.00f);
			glPushMatrix();
			glTranslatef(0.0f, -0.5f, 0.45f);
			glutSolidSphere(1, 50, 50);
			glPopMatrix();
		}
		glEndList();
	}
	glCallList(scene2);
	glPushMatrix();
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glCallList(figures);
	glPopMatrix();
}
