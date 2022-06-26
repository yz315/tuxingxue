#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>
float theta=0.0;
void drawPyramid() //�ý���������ԭ��Ϊ���ģ��߳�Ϊ2�������巶Χ��
{
	glBegin(GL_TRIANGLES);
	  glColor3f(1.0f,0.0f,0.0f);	  //ǰ��Ϊ��ɫ
	  glVertex3f( 0.0f, 1.0f, 0.0f);	//ǰ���������϶���
	  glVertex3f(-1.0f,-1.0f, 1.0f);  //ǰ���������󶥵�
	  glVertex3f( 1.0f,-1.0f, 1.0f);	//ǰ���������Ҷ���

	  glColor3f(0.0f,1.0f,0.0f);		//����Ϊ��ɫ
	  glVertex3f( 0.0f, 1.0f, 0.0f);	//�����������϶���
	  glVertex3f( 1.0f,-1.0f, 1.0f);	//�����������󶥵�
	  glVertex3f( 1.0f,-1.0f, -1.0f);	 //�����������Ҷ���

	  glColor3f(0.0f,0.0f,1.0f);		//����Ϊ��ɫ
	  glVertex3f( 0.0f, 1.0f, 0.0f);  //�����������϶���
	  glVertex3f( 1.0f,-1.0f, -1.0f);	 //�����������󶥵�
	  glVertex3f(-1.0f,-1.0f, -1.0f);	//�����������Ҷ���

	  glColor3f(1.0f,1.0f,0.0f);		//����Ϊ��ɫ
	  glVertex3f( 0.0f, 1.0f, 0.0f);	//�����������϶���
	  glVertex3f(-1.0f,-1.0f,-1.0f);	//�����������󶥵�
	  glVertex3f(-1.0f,-1.0f, 1.0f);	//�����������Ҷ���
	glEnd();
	glBegin(GL_POLYGON);  //����������������
      glColor3f(0.5f,0.5f,0.5f);  //����Ϊ��ɫ
	  glVertex3f(-1.0f,-1.0f, 1.0f);
	  glVertex3f(1.0f,-1.0f, 1.0f);
	  glVertex3f(1.0f,-1.0f, -1.0f);
	  glVertex3f(-1.0f,-1.0f, -1.0f);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //�����ɫ����Ȼ���
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0f,0.0f,-5.0f);
	glRotatef(theta,0.0f,1.0f,0.0f);
	drawPyramid();

	glutSwapBuffers();

}

void reshape(int w, int h) //�ػ�ص��������ڴ����״δ������û��ı䴰�ڳߴ�ʱ������
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 3.1, 10.0);
	//gluPerspective(45,1,0.1,10.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, 2.0, 10.0);
}

void init()
{
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);     //������Ȳ���ģʽ
}

void myKeyboard(unsigned char key,  int x, int y)
{
	if(key == 'a' || key == 'A')
		theta += 5.0;
	if(key == 's' || key == 'S')
		theta -= 5.0;
    if(key == 'c' || key == 'C')
		exit(0);
	if (theta>360) theta -=360;
	if (theta<0) theta +=360;
	glutPostRedisplay(); //���µ��û��ƺ���
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DEPTH |GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("������---A��:˳ʱ����ת,S��:��ʱ����ת,C��:�˳�");
	glutReshapeFunc(reshape); //ָ���ػ�ص�����
	glutDisplayFunc(display);
	glutKeyboardFunc( myKeyboard);   //ָ�����̻ص�����
	init();
	glutMainLoop();
    return 0;
}

