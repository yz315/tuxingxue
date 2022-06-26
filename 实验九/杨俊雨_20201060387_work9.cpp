#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

GLsizei winWidth=500,winHeight=500;

void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,0,100);
    //��һ������Ϊfov�ǣ��ڶ��������ǿ�߱�
    //�����������ֱ���������Ӿ������Զ���Ӿ���
}

void Move(){
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-1, 0, -10);//��xyzƽ�Ƶķ���
	glColor3f(1, 0, 0);
	glutWireCube(1);

	glTranslatef(3, 0, 0);
	glColor3f(0, 1, 0);
	glutWireCube(1);
}

void Scale(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-1, 0, -10);
	glColor3f(1, 0, 0);
	glutWireCube(1);

	glScalef(1.5, 1.5, 1.5);
	glColor3f(0, 1, 0);
	glutWireCube(1);
}

void RotateV(){
	//opengl��ά��ת(��ƽ���������������ת)
	//����Ϊԭ���ƾ���(0,0,-5)��ֱ��xzƽ�����ת�������ת
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//Ϊ�˷���鿴Ч������������z�Ḻ��ƽ��10����λ
	glTranslatef(0, -2, -10);
	glColor3f(0.0,0.0,1);
	glBegin(GL_LINES);
	//���Ƴ���ת��
	glVertex3f(0, -10, -5);
	glVertex3f(0, 10, -5);
	glEnd();
	glFlush();
	for (int i = 0; i < 18; i++)
	{
		//������ƽ��
		glTranslatef(0, 0, -5);
		//�����������ת
		glRotatef(20, 0, 1, 0);
		//��������ƽ������y���غ�
		glTranslatef(0, 0, 5);
		glColor3f(1, 0, 0);
		glutWireCube(1);
	}
	glTranslatef(0, 4, 0);
	for (int i = 0; i < 18; i++)
	{
		//������ƽ��
		glTranslatef(0, 0, -5);
		//�����������ת
		glRotatef(20, 0, 1, 0);
		//��������ƽ������y���غ�
		glTranslatef(0, 0, 5);
		glColor3f(0, 1, 0);
		glutWireCube(1);
	}
}

void RotateAny(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-1, 4, -20);
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	//���Ƴ���ת��
	glVertex3f(-25, -30, -25);
	glVertex3f(20, 15, 20);
	glEnd();
	glColor3f(1, 0, 0);
	for (int i = 0; i < 36; i++)
	{
		//��任
		glTranslatef(5, 0, 5);
		glRotatef(-45, 0, 0, 1);
		glRotatef(45, 1, 0, 0);
		glRotatef(10, 0, 1, 0);
		//����x��˳ʱ����ת45��ʹ��ת����y���غ�
		glRotatef(-45, 1, 0, 0);
		//����z����ʱ����ת45��ʹ��ת��λ��yzƽ����
		glRotatef(45, 0, 0, 1);
		//�Ƚ���ת��ƽ��������ԭ��
		glTranslatef(-5, 0, -5);
		glutWireCube(1);
	}
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //Move();
    //Scale();
    //RotateV();
    RotateAny();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(winWidth,winHeight);
    glutInitWindowPosition(400,100);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    glutCreateWindow("��ά���α任");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
