#include<Windows.h>\
#include<math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

void setPixel(GLint x,GLint y);
int round(float a);
/* GLUT callback Handlers */

void lineDDA(int x0,int y0,int xEnd,int yEnd)
{
    glClear(GL_COLOR_BUFFER_BIT);// �����ʾ����
    glColor3f(0.0, 0.4, 0.2);// ָ��ǰ��ɫ����ǰ������ɫ��Ϊ��ɫ

    int dx=xEnd-x0,dy=yEnd-y0,steps,k;
    float xIncrement,yIncrement,x=x0,y=y0;

    if(abs(dx)>abs(dy))
        steps = abs(dy);
    else
        steps = abs(dx);
    xIncrement = float(dx)/float(steps);
    yIncrement = float (dy)/float(steps);

    setPixel(round(x),round(y));
    for (k=0;k<steps;k++)
    {
        x+=xIncrement;
        y+=yIncrement;
        setPixel(round(x),round(y));
    }
}
void setPixel(GLint x,GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
int round(float a)
{
    return int(a+0.5);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);// �����ʾ����

	lineDDA(0, 0, 200000, 200000);
	glFlush();// ʹ����������ӳ����Ļ��
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);// ָ�������ɫ������ɫ��Ϊ��ɫ
    glColor3f(1.0, 0.0, 0.0); /* draw in red */
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0); //ָ����ά����ϵ�б���ʾ������
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);// ��ʼ GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//�趨��ʾģʽ
	glutInitWindowPosition(50, 100);// �趨����λ��
	glutInitWindowSize(400, 300);// �趨���ڴ�С
	glutCreateWindow("DDA");// ��ǰ��ָ�������������ڣ������崰������
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);//ָ����ά����ϵ�б���ʾ������

	init(); // ����һЩ��ʼ������
	glutDisplayFunc(myDisplay);// ָ�����ƵĻص�����
	glutMainLoop();// ��������ѭ�����ȴ��¼�����

    return 0;
}
