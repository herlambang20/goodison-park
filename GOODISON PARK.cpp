#include <windows.h>
#include <stdlib.h>
#include <glut.h>

void init(void);
void tampil(void);
void mouse ( int button , int state , int x , int y);
void ukuran (int , int);
void mouseMotion(int x , int y);
void keyboard(unsigned char key , int x, int y);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
int X = 0;
int Y = 0;
int Z = 0;

 

int main (int argc , char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000,800);
	glutInitWindowPosition(250,80);
	glutCreateWindow("GOODISON PARK");
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
	
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	
	glutKeyboardFunc(keyboard);
	
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0 ;
}

void init (void)
{
	glClearColor (0.0 , 0.0 , 0.0 ,1.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f ); 
	glRotatef(xrot , 1.0f ,0.0f ,0.0f);
	glRotatef(yrot , 0.0f , 1.0f , 0.0f);
	glTranslatef(X,Y,Z);
	glPushMatrix();
	
glPushMatrix();
	glPopMatrix();
	
	glutSwapBuffers();
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button , int state , int x , int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot ;
		ydiff = -y + xrot ;
	}
	else
	mouseDown = false ;
}

void mouseMotion (int x , int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff ; 
		xrot = y + ydiff ;
		
		glutPostRedisplay();
	}
}

void keyboard(unsigned char key , int x, int y)
{
	switch(key)
	{
		case'w':
		case'W':
		    Z+=3;
			break;
		case'd':
		case'D':
			X+=3;
			break;
		case's':
		case'S':
			Z-=3;
			break;
		case'a':
		case'A':
			X-=3;
			break;
		case'7':
			Y+=3;
			break;
		case'9':
			Y-=3;
			break;
		case'2':
			X+=2;
			Y+=1;
			break;
		case'8':
			X-=2;
			Y+=1;
			break;
		case'6':
			X+=2;
			Z+=1;
			break;
		case'4':
			X-=2;
			Z+=1;
			break;
		case'5':
			if (is_depth)
			{
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			}
			else
			{
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}	
	}
	tampil();
}

void ukuran (int lebar , int tinggi)
{
	if (tinggi == 0 ) tinggi = 1  ;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0 , lebar/tinggi , 5.0 , 500.0);
	glTranslatef(0.0 , -5.0 , -150.0);
	glMatrixMode(GL_MODELVIEW);
}

