/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <windows.h>
#include <math.h>

static GLfloat x = 0.0f;
static GLfloat y = 0.0f;

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //清除后保存初始
    glPushMatrix();
   	glRotatef(x, 1.0f, 0.0f, 0.0f);  //绕x轴旋转
	glRotatef(y, 0.0f, 1.0f, 0.0f);  //绕y轴旋转
	//车子正面
	glBegin(GL_POLYGON);
		glColor3f(0.1, 0.1, 0.8);
		glVertex3f(-40.0f,0.0f,15.0f);
		glVertex3f(40.0f,0.0f,15.0f);
		glColor3f(0.1, 0.9, 0.8);
		glVertex3f(40.0f,-15.0f,15.0f);
		glVertex3f(-40.0f,-15.0f,15.0f);
	glEnd();
	//车子侧面
	glBegin(GL_POLYGON);
		glColor3f(0, 0.3, 0.3);
		glVertex3f(40.0f,0.0f,-15.0f);
		glVertex3f(40.0f,0.0f,15.0f);
		glVertex3f(40.0f,-15.0f,15.0f);
		glVertex3f(40.0f,-15.0f,-15.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0, 0.3, 0.3);
		glVertex3f(-40.0f,0.0f,-15.0f);
		glVertex3f(-40.0f,0.0f,15.0f);
		glVertex3f(-40.0f,-15.0f,15.0f);
		glVertex3f(-40.0f,-15.0f,-15.0f);
	glEnd();
	//车子反面和上下面
    glBegin(GL_POLYGON);
		glColor3f(0.1, 0.1, 0.8);
		glVertex3f(-40.0f,0.0f,-15.0f);
		glVertex3f(40.0f,0.0f,-15.0f);
		glColor3f(1, 0.5, 0.8);
		glVertex3f(40.0f,-15.0f,-15.0f);
		glVertex3f(-40.0f,-15.0f,-15.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0, 0, 1);
		glVertex3f(-40.0f,0.0f,15.0f);
		glVertex3f(-40.0f,0.0f,-15.0f);
		glVertex3f(40.0f,0.0f,-15.0f);
		glVertex3f(40.0f,0.0f,15.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.8, 0.5, 0.2);
		glVertex3f(-40.0f,-15.0f,15.0f);
		glVertex3f(-40.0f,-15.0f,-15.0f);
		glVertex3f(40.0f,-15.0f,-15.0f);
		glVertex3f(40.0f,-15.0f,15.0f);
	glEnd();
	//车上半部
	glBegin(GL_POLYGON);
		glColor3f(0, 0, 1);
		glVertex3f(-20.0f,0.0f,15.0f);
		glVertex3f(-10.0f,10.0f,15.0f);
		glVertex3f(20.0f,10.0f,15.0f);
		glVertex3f(25.0f,0.0f,15.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0, 0, 1);
		glVertex3f(-20.0f,0.0f,-15.0f);
		glVertex3f(-10.0f,10.0f,-15.0f);
		glVertex3f(20.0f,10.0f,-15.0f);
		glVertex3f(25.0f,0.0f,-15.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0, 1, 1);
    	glVertex3f(-10.0f,10.0f,15.0f);
    	glVertex3f(-10.0f,10.0f,-15.0f);
		glVertex3f(20.0f,10.0f,-15.0f);
		glVertex3f(20.0f,10.0f,15.0f);
	glEnd();
    glBegin(GL_POLYGON);
		glColor3f(0.5, 0.8, 0.8);
    	glVertex3f(-10.0f,10.0f,15.0f);
		glVertex3f(-20.0f,0.0f,15.0f);
		glVertex3f(-20.0f,0.0f,-15.0f);
    	glVertex3f(-10.0f,10.0f,-15.0f);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0, 0.5, 0.5);
		glVertex3f(20.0f,10.0f,15.0f);
		glVertex3f(20.0f,10.0f,-15.0f);
		glVertex3f(25.0f,0.0f,-15.0f);
		glVertex3f(25.0f,0.0f,15.0f);
	glEnd();
	//车轮
	glColor3f(1, 0, 0);
	glTranslated(-20.0f,-15.0f,15.0f);
    glutSolidTorus(2,5,5,100);
	glTranslated(0.0f,0.0f,-30.0f);
    glutSolidTorus(2,5,5,100);
	glTranslated(45.0f,0.0f,0.0f);
    glutSolidTorus(2,5,5,100);
	glTranslated(0.0f,0.0f,30.0f);
    glutSolidTorus(2,5,5,100);
    //增加光照
    GLfloat ambient[] = { 0.5, 0.8, 0.1, 0.1 };
    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat position[] = { 80.0, 50.0, -50.0, 1.0 };
    GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat local_view[] = { 0.0 };
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

    glPopMatrix();       //回到初始，防止键盘控制后位置不一样
	glutSwapBuffers();   //交换缓冲
}

//定义键盘控制函数
void SpecialKeys(int key, int a, int b)
{
    if(key == GLUT_KEY_UP)		x -= 5.0f;
	if(key == GLUT_KEY_DOWN)	x += 5.0f;
	if(key == GLUT_KEY_LEFT)	y -= 5.0f;
	if(key == GLUT_KEY_RIGHT)	y += 5.0f;

	glutPostRedisplay(); // 刷新窗口
}

//定义光照菜单
void MenuProc(int id){
    if(id==1){
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
    }
    if(id==2){
        glDisable(GL_LIGHTING);
    }

    glutPostRedisplay(); // 刷新窗口
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("car and light");
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glLoadIdentity();
	glOrtho (-100, 100, -100, 100,-100, 100);

	glutDisplayFunc(Display);
	glutCreateMenu(MenuProc);//设置右键选择光照
	glutAddMenuEntry("enlight",1);
	glutAddMenuEntry("dislight",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutSpecialFunc(SpecialKeys);  //注册功能键回调函数
	glutMainLoop();

	return 0;
}
