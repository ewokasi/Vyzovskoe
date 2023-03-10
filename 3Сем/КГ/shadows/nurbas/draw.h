#pragma once
/*
  ����� ����������� ������� ��� ����������
*/

#include <iostream>
#include <GL/glut.h>

#include <cmath>
#include "move.h"
#include "models.h"

namespace global {
    extern float cam_xz_rotate;
    extern float cam_y_rotate;
    extern float cam_zoom;
    extern float light_xy_rotate;
    extern float light_y_rotate;
    extern float obj_pos[3];
}

// ��������� ��������
float mat_dif_grass[] = { 0.7f, 0.7f, 0.7f, 1.0f };
float mat_spec_grass[] = { 0.7f, 0.7f, 0.7f };
float mat_amb_grass[] = { 0.7f, 0.7f, 0.7f };
float mat_shininess_grass = 0.1f * 128;

float mat_dif_Sphere[] = { 0.7f, 0.7f, 0.7f ,1.0f };
float mat_spec_Sphere[] = { 0.7f, 0.7f, 0.7f };
float mat_amb_Sphere[] = { 0.7f, 0.7f, 0.7f };
float mat_shininess_Sphere = 0.1f * 128;

float mat_dif_shadow[] = { 0.0f, 0.0f, 0.0f, 0.8f };
float mat_spec_shadow[] = { 0.0f, 0.0f, 0.0f };
float mat_amb_shadow[] = { 0.0f, 0.0f, 0.0f };
float mat_shininess_shadow = 0.1f * 128;

// ��������� �����
// �������� ������� ��� ������������ ���������
float mat_dif_light[] = { 0.9f, 0.9f, 0.0f, 1.0f };
float mat_spec_light[] = { 0.9f, 0.9f, 0.0f };
float mat_amb_light[] = { 0.9f, 0.9f, 0.0f };
float mat_shininess_light = 0.1f * 128;

// �������� �����
float matl_dif_light[] = { 0.9f, 0.9f, 0.9f, 1.0f };

// ����������� �����
float light_position_fraction = 0.02;
float light_position_radius = 10;
float light_tick = 0;
// ����� �������� XYZ � W (���� ��������� �� 0, �� ����� �������� �������� �����)
float light_position[4] = { 0.0, 4.0, 0.0, 0.0 };

// ������� ��� ����������� � ��������� �����
void set_light(GLenum name, GLfloat* light_position) {
    // �������� �����
    glLightfv(name, GL_DIFFUSE, matl_dif_light);
    glLightfv(name, GL_POSITION, light_position);
    glLightf(name, GL_SPOT_CUTOFF, 360);

    // �������� ������� ������� ������������� �������� �����
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_light);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_light);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_light);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_light);

    glTranslatef(light_position[0], light_position[1], light_position[2]);
    glutSolidSphere(0.2, 32, 32);
    glTranslatef(-light_position[0], -light_position[1], -light_position[2]);

    // �������� ����
    glEnable(name);
}

void Display(void) {
    glLoadIdentity();

    // ������������ ������������ ��� ������
    move();
    glRotated(90, 0, 0, 1);
    // ����� ��������� ������
    gluLookAt(
        cos(global::cam_y_rotate) * sin(global::cam_xz_rotate) * global::cam_zoom,
        sin(global::cam_y_rotate) * global::cam_zoom,
        cos(global::cam_y_rotate) * cos(global::cam_xz_rotate) * global::cam_zoom,
        0, 0, 0,
        0.0f, 1.0f, 0.0f
    );

    // ���
    glClearColor(0, 0.3, 0.3, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // ��� ����� ��������� ��� �������� ���������� 3D (����� ������ �������)
    glEnable(GL_DEPTH_TEST);

    // �������� ���������� ����� (��� ������������)
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /* �������� ��������� */
    glEnable(GL_LIGHTING);

    /* ���������� ��������� ����� */
    set_light(GL_LIGHT0, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_grass);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_grass);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_grass);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_grass);

    glEnable(GL_AUTO_NORMAL);
    draw_nurb();

    // �������� ����
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_Sphere);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_Sphere);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_Sphere);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_Sphere);

    // ���
    glTranslatef(global::obj_pos[0], 2, global::obj_pos[2]);
    glutSolidCube(1);

    // �������� ����
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_shadow);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_shadow);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_shadow);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_shadow);

    // ���������� ������� ����
    glTranslatef((global::obj_pos[0] - light_position[0]) / light_position[1], -1.9, (global::obj_pos[2] - light_position[2]) / light_position[1]);
    // �������������� ���� � ����������� �� ��������� ��������� �� ������
    glScalef(1 + abs(global::obj_pos[0] - light_position[0]) / (light_position[1] * 5), 0.02, 1 + abs(global::obj_pos[2] - light_position[2]) / (light_position[1] * 5));
    // ��������� ����
    glRotated(90, 0, 0, 1);
    glutSolidCube(1);

    // ��� ���� ����� ����������� ��������� ����������� �� ����
    glEnable(GL_AUTO_NORMAL);

    glPopMatrix();
    glFlush();
}

void Reshape(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLfloat)w / h, 1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}
