#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

GLsizei winWidth = 500,winHeight = 500;
	char sixel;
	float thera=0;
	float x=0,y=0,z=0;
void init(void){
	glClearColor(1.0,1.0,1.0,0.0);
}


void displayWirePolyhedra(float x,float y,float z,float thera){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	gluLookAt(5.0,5.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
	glScalef(1.0,1.0,1.0);
	glTranslatef(1.0,2.0,0.0);//��һ��ͼ������
	glutSolidTeapot(1.5);
	//glutWireTeapot(1.5);//�Ŵ���
	glScalef(1.0,1.0,1.0);//���ű�
	glTranslatef(-1.0,-5.0,0.0);//��һ��ͼ������

	glRotatef(thera,x,y,z);
	glutWireTeapot(1.5);
	//glutSolidTeapot(2.0);
	glFlush();
}

void display(){

	displayWirePolyhedra(x,y,z,thera);
}

void winReshapeFcn(GLint newWidth,GLint newHeight){
	glViewport(0,0,newWidth,newHeight);
	glMatrixMode(GL_PROJECTION);
	glFrustum(-1.0,1.0,-1.0,1.0,2.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(winWidth,winHeight);
	glutCreateWindow("teapot");
	init();
		printf("��ѡ������һ������תx,y,z \n");
	scanf("%c",&sixel);
	getchar();
	if(sixel=='x'){
		x=1.0;
		y=0.0;
		z=0.0;
		printf("��������ת�ĽǶ�\n");
		scanf("%f",&thera);
	}else if(sixel=='y'){
		x=0.0;
		y=1.0;
		z=0.0;
		printf("��������ת�ĽǶ�\n");
		scanf("%f",&thera);
	}else if(sixel=='z'){
		x=0.0;
		y=0.0;
		z=1.0;
		printf("��������ת�ĽǶ�\n");
		scanf("%f",&thera);
	}else{
	printf("��������\n");
	}
	glutDisplayFunc(display);
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
	return 0;
}
