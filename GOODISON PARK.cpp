#include <windows.h>
#include <stdlib.h>
#include <glut.h>
#include <math.h>

void init(void);
void tampil(void);
void mouse ( int button , int state , int x , int y);
void ukuran (int , int);
void mouseMotion(int x , int y);
void keyboard(unsigned char key , int x, int y);
int kubus (float n);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
int X = 0;
int Y = 0;
int Z = 0;
int balok (float n) {
	glBegin(GL_QUADS);
    glVertex3f(-n, n/2, n/2);
    glVertex3f(n, n/2, n/2);
    glVertex3f(n, -n/2, n/2);
    glVertex3f(-n, -n/2, n/2);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-n, n/2, -n/2);
    glVertex3f(n, n/2, -n/2);
    glVertex3f(n, -n/2, -n/2);
    glVertex3f(-n, -n/2, -n/2);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-n, n/2, -n/2);
    glVertex3f(-n, n/2, n/2);
    glVertex3f(-n, -n/2, n/2);
    glVertex3f(-n, -n/2, -n/2);
    glEnd();
 
    glBegin(GL_QUADS);
    glVertex3f(n, n/2, -n/2);
    glVertex3f(n, n/2, n/2);
    glVertex3f(n, -n/2, n/2);
    glVertex3f(n, -n/2, -n/2);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-n, n/2, n/2);
    glVertex3f(n, n/2, n/2);
    glVertex3f(n, n/2, -n/2);
    glVertex3f(-n, n/2, -n/2);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-n, -n/2, n/2);
    glVertex3f(n, -n/2, n/2);
    glVertex3f(n, -n/2, -n/2);
    glVertex3f(-n, -n/2, -n/2);
    glEnd();
	
}
void broadcaster(){
glPushMatrix();

	glColor3f(1.0, 1.0, 1.0);
glRotatef(220,0,1,0);
glTranslatef(-9,41,130);

balok(12);

	glColor3f(0.15, 0.15, 0.15);
glBegin(GL_QUADS);
    glVertex3f(-12-0.01, 12/2, -12/2);
    glVertex3f(-12-0.01, 12/2, 12/2);
    glVertex3f(-12-0.01, -12/2, 12/2);
    glVertex3f(-12-0.01, -12/2, -12/2);
    glEnd();
 
    glBegin(GL_QUADS);
    glVertex3f(12+0.01, 12/2, -12/2);
    glVertex3f(12+0.01, 12/2, 12/2);
    glVertex3f(12+0.01, -12/2, 12/2);
    glVertex3f(12+0.01, -12/2, -12/2);
    glEnd();
glPopMatrix(); 

glPushMatrix();
glRotatef(220,0,1,0);
glTranslatef(-9,37,130);
glColor3f(0.15, 0.15, 0.15);
    glBegin(GL_QUADS);
    glVertex3f(-12-0.01, 12/6, -12/2-0.01);
    glVertex3f(12+0.01, 12/6, -12/2-0.01);
    glVertex3f(12+0.01, -12/6, -12/2-0.01);
    glVertex3f(-12-0.01, -12/6, -12/2-0.01);
    glEnd();
glPopMatrix();

glPushMatrix();
glRotatef(220,0,1,0);
glTranslatef(-9,37,130);
glColor3f(0.15, 0.15, 0.15);
    glBegin(GL_QUADS);
    glVertex3f(-12.012, 10.01, 12/2);
    glVertex3f(12.012, 10.01, 12/2);
    glVertex3f(12.012, 10.01, -12/2);
    glVertex3f(-12.012, 10.01, -12/2);
    glEnd();
    
glPopMatrix();

}

void DrawCircle(float cx, float cz, float cy ,  float r, int num_segments) 
{ 
	float theta = 2 * 3.1415926 / float(num_segments); 
	float tangetial_factor = tanf(theta);//calculate the tangential factor 

	float radial_factor = cosf(theta);//calculate the radial factor 
	
	float x = r;//we start at angle = 0 

	float y = 0; 
    
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		glVertex3f(x + cx, cz ,y + cy);//output vertex 
        
		//calculate the tangential vector 
		//remember, the radial vector is (x, y) 
		//to get the tangential vector we flip those coordinates and negate one of them 

		float tx = -y; 
		float ty = x; 
        
		//add the tangential vector 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 
        
		//correct using the radial factor 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
}

void SetengahCircle(float cx, float cz, float cy ,  float r, int num_segments) 
{ 
	float theta = 1 * 3.1415926 / float(num_segments); 
	float tangetial_factor = tanf(theta);//calculate the tangential factor 

	float radial_factor = cosf(theta);//calculate the radial factor 
	
	float x = r;//we start at angle = 0 

	float y = 0; 
    
	glBegin(GL_LINE_STRIP); 
	for(int ii = 0; ii <  num_segments; ii++) 
	{  
		glVertex3f(y + cx, cz ,x + cy);//output vertex 
        
		//calculate the tangential vector 
		//remember, the radial vector is (x, y) 
		//to get the tangential vector we flip those coordinates and negate one of them 

		float tx = y; 
		float ty = -x; 
        
		//add the tangential vector 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 
        
		//correct using the radial factor 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
}
void SetengahCircleNormal(float cx, float cz, float cy ,  float r, int num_segments) 
{ 
	float theta = -1 * 3.1415926 / float(num_segments); 
	float tangetial_factor = tanf(theta);//calculate the tangential factor 

	float radial_factor = cosf(theta);//calculate the radial factor 
	
	float x = r;//we start at angle = 0 

	float y = 0; 
    
	glBegin(GL_LINE_STRIP); 
	for(int ii = 0; ii <  num_segments; ii++) 
	{  
		glVertex3f(y + cx, cz ,x + cy);//output vertex 
        
		//calculate the tangential vector 
		//remember, the radial vector is (x, y) 
		//to get the tangential vector we flip those coordinates and negate one of them 

		float tx = y; 
		float ty = -x; 
        
		//add the tangential vector 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 
        
		//correct using the radial factor 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
}

void seperempatCircle(float cx, float cz, float cy ,  float r, int num_segments) 
{ 
	float theta = -1 * 3.1415926 / float(num_segments); 
	float tangetial_factor = tanf(theta);//calculate the tangential factor 

	float radial_factor = cosf(theta);//calculate the radial factor 
	
	float x = r;//we start at angle = 0 

	float y = 0; 
    
	glBegin(GL_LINE_STRIP); 
	for(int ii = 0; ii < 0.5 * num_segments; ii++) 
	{ 
		glVertex3f(x + cx, cz ,y + cy);//output vertex 
        
		//calculate the tangential vector 
		//remember, the radial vector is (x, y) 
		//to get the tangential vector we flip those coordinates and negate one of them 

		float tx = -y; 
		float ty = x; 
        
		//add the tangential vector 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 
        
		//correct using the radial factor 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
}void seperempatCircleNormal(float cx, float cz, float cy ,  float r, int num_segments) 
{ 
	float theta = 1 * 3.1415926 / float(num_segments); 
	float tangetial_factor = tanf(theta);//calculate the tangential factor 

	float radial_factor = cosf(theta);//calculate the radial factor 
	
	float x = r;//we start at angle = 0 

	float y = 0; 
    
	glBegin(GL_LINE_STRIP); 
	for(int ii = 0; ii < 0.5 * num_segments; ii++) 
	{ 
		glVertex3f(x + cx, cz ,y + cy);//output vertex 
        
		//calculate the tangential vector 
		//remember, the radial vector is (x, y) 
		//to get the tangential vector we flip those coordinates and negate one of them 

		float tx = -y; 
		float ty = x; 
        
		//add the tangential vector 

		x += tx * tangetial_factor; 
		y += ty * tangetial_factor; 
        
		//correct using the radial factor 

		x *= radial_factor; 
		y *= radial_factor; 
	} 
	glEnd(); 
}

void dinding()
{
	//belakang
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0,30,-132);
	glScalef(125,62.0,4);
	kubus(1);
	glPopMatrix();
	
	//belakang 1 kiri
	glBegin(GL_TRIANGLES);
	glVertex3f(-62.5,21,-134);
	glVertex3f(-62.5,-4.75,-134);
	glVertex3f(-62.5,-4.75,-90);
	glEnd();
	
	//belakang 1 kanan
	glBegin(GL_TRIANGLES);
	glVertex3f(62.5,21,-134);
	glVertex3f(62.5,-4.75,-134);
	glVertex3f(62.5,-4.75,-90);
	glEnd();
	
	//depan 1 kanan
	glBegin(GL_TRIANGLES);
	glVertex3f(62.5,21,62);
	glVertex3f(62.5,-4.75,62);
	glVertex3f(62.5,-4.75,15);
	glEnd();
	
	//depan 1 kiri
	glBegin(GL_TRIANGLES);
	glVertex3f(-62.5,21,62);
	glVertex3f(-62.5,-4.75,62);
	glVertex3f(-62.5,-4.75,15);
	glEnd();
	
	//bawah
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0,-2.5,-36);
	glScalef(125,4.5,196);
	kubus(1);
	glPopMatrix();
	
	//tutupkiriatas
	glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-105.5, -4.75, 15 );
    glVertex3f(-62.5 , -4.75 , 15);
    glVertex3f(-62.5, -4.75 , 62);
     glEnd();
     
     //tutupkiribawah
     glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-105.5, -4.75, -90 );
    glVertex3f(-62.5 , -4.75 , -90);
    glVertex3f(-62.5, -4.75 ,-134);
     glEnd();
     
	//bawah 2
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0,-2.5,-37.5);
	glScalef(211,4.5,105);
	kubus(1);
	glPopMatrix();
	
	//kanan
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(104,26.5,-37.5);
	glScalef(3,55,105);
	kubus(1);
	glPopMatrix();
	
	//belakangkanankubus
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(84.5,28.125,-90);
	glScalef(42,65.75,2);
	kubus(1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(63.5,28.125,-112);
	glScalef(2,65.75,44);
	kubus(1);
	glPopMatrix();
	
	//depankanankubus
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(63.5,28.125,38.5);
	glScalef(2,65.75,47);
	kubus(1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(84.5,28.125,15);
	glScalef(42,65.75,2);
	kubus(1);
	glPopMatrix();
	
	//depan kanan
	glBegin(GL_TRIANGLES);
	glVertex3f(-105,21,15);
	glVertex3f(-62,-4.75,15);
	glVertex3f(-105,-4.75,15);
	glEnd();
	
	//belakangan kanan
	glBegin(GL_TRIANGLES);
	glVertex3f(105,21,-90);
	glVertex3f(62,-4.75,-90);
	glVertex3f(105,-4.75,-90);
	glEnd();
	
	//kiri
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(-104,30,-37.5);
	glScalef(3,62,105);
	kubus(1);
	glPopMatrix();
	
	//depan kiri
	glBegin(GL_TRIANGLES);
	glVertex3f(105,21,15);
	glVertex3f(62,-4.75,15);
	glVertex3f(105,-4.75,15);
	glEnd();
	
	//belakang kiri
	glBegin(GL_TRIANGLES);
	glVertex3f(-105,21,-90);
	glVertex3f(-62,-4.75,-90);
	glVertex3f(-105,-4.75,-90);
	glEnd();
	
	//depan
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0,30,60.5);
	glScalef(125,62.0,3);
	kubus(1);
	glPopMatrix();
	
	//tutup depankiri
	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.5);
	glVertex3f(-105.5,61,15);
	glVertex3f(-105.5,-4.75,15);
	glVertex3f(-62.5,-4.75,62);
	glVertex3f(-62.5,61,62);
	glEnd();
	
	//tutupbelakangkiri
	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.5);
	glVertex3f(-105.5,61,-90);
	glVertex3f(-105.5,-4.75,-90);
	glVertex3f(-62.5,-4.75,-134);
	glVertex3f(-62.5,61,-134);
	glEnd();
	
	/*glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.5);
	glVertex3f(-102.5,61,15);
	glVertex3f(-102.5,-4.75,15);
	glVertex3f(-62.5,-4.75,58);
	glVertex3f(-62.5,61,58);
	glEnd();*/
	
/*	glBegin(GL_QUADS);
	glColor3f(0.5,0.5,0.5);
	glVertex3f(-102.5,61,15);
	glVertex3f(-102.5,-4.75,15);
	glVertex3f(-62.5,-4.75,58);
	glVertex3f(-62.5,61,58);
	glEnd();
*/	


}
void lingkaran()
{
	//garis tengah lapangan
	glLineWidth(6.0);
    DrawCircle(-0.5, 0.13, -37.5 , 10, 360);
    
    seperempatCircle(-40, 0.13, -2.5 , 5, 50);
    seperempatCircleNormal(-40, 0.13, -72.5 , 5, 50);
    seperempatCircleNormal(40, 0.13, -2.5 , -5, 50);
    seperempatCircle(40, 0.13, -72.5 , -5, 50);
    SetengahCircle(24,0.13,-37,2,100);
    SetengahCircleNormal(-24,0.13,-37,2,100);
    glLineWidth(1.0);
    //corner
}


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
//	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);

}

int kubus (float n) {
	glBegin(GL_QUADS);
    glVertex3f(-n/2, n/2, n/2);
    glVertex3f(n/2, n/2, n/2);
    glVertex3f(n/2, -n/2, n/2);
    glVertex3f(-n/2, -n/2, n/2);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-n/2, n/2, -n/2);
    glVertex3f(n/2, n/2, -n/2);
    glVertex3f(n/2, -n/2, -n/2);
    glVertex3f(-n/2, -n/2, -n/2);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-n/2, n/2, -n/2);
    glVertex3f(-n/2, n/2, n/2);
    glVertex3f(-n/2, -n/2, n/2);
    glVertex3f(-n/2, -n/2, -n/2);
    glEnd();
 
    glBegin(GL_QUADS);
    glVertex3f(n/2, n/2, -n/2);
    glVertex3f(n/2, n/2, n/2);
    glVertex3f(n/2, -n/2, n/2);
    glVertex3f(n/2, -n/2, -n/2);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-n/2, n/2, n/2);
    glVertex3f(n/2, n/2, n/2);
    glVertex3f(n/2, n/2, -n/2);
    glVertex3f(-n/2, n/2, -n/2);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-n/2, -n/2, n/2);
    glVertex3f(n/2, -n/2, n/2);
    glVertex3f(n/2, -n/2, -n/2);
    glVertex3f(-n/2, -n/2, -n/2);
    glEnd();
	
}

void layoutkursi()
{
    
    //kanan
    
    glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(60+2.5+40, 20 , -85-5);
    glVertex3f(60+2.5+40,20 ,10.0+5);
    glVertex3f(60+2.5, -0.133 , 10.0+5);
    glVertex3f(60+2.5, -0.133, -85-5); 
    glEnd();
    
    //kiri
    glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5-40, 20 , -85-5);
    glVertex3f(-60-2.5-40,20 ,10.0+5);
    glVertex3f(-60-2.5, -0.133 , 10.0+5);
    glVertex3f(-60-2.5, -0.133, -85-5); 
    glEnd();
    
    //depan
    glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 20 , 10.0+2.5+40+5);
    glVertex3f(60+2.5,20 ,10.0+2.5+40+5);
    glVertex3f(60+2.5, -0.133 , 10.0+5);
    glVertex3f(-60-2.5, -0.133, 10.0+5); 
    glEnd();
    
    //belakang
    glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 20 , -85-2.5-40);
    glVertex3f(60+2.5,20 ,-85-2.5-40);
    glVertex3f(60+2.5, -0.133 , -85-5);
    glVertex3f(-60-2.5, -0.133,-85-5); 
    glEnd();
    
    /*//belakang kanan
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(60, 20,-85-5-40);
    glVertex3f(60+40+2.5, 20 , -85-5);
    glVertex3f(60+2.5, -0.133 , -85-5);
     glEnd();*/
     
     
     //belakang kiri 
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60, 20,-85-5-40);
    glVertex3f(-60-40-2.5, 20 , -85-5);
    glVertex3f(-60-2.5, -0.133 , -85-5);
     glEnd();
     


    /*  //depan kanan
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(60, 20,10.0+2.5+40+5);
    glVertex3f(60+40+2.5, 20 , 5.0+5);
    glVertex3f(60+2.5, -0.133 , 5.0+5);
     glEnd();*/
     
     //depan kiri
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60, 20,10.0+2.5+40+5);
    glVertex3f(-60-40-2.5, 20 , 5.0+5);
    glVertex3f(-60-2.5, -0.133 , 5.0+5);
     glEnd();
}

void tangga(){
float n = 1.5;
float k = -93-2;
int i;
float j=1.5;
float l=17.75+2.5;
float b = 1.5;
float a = 67.2;
float c = 1.5;
float d = -67.2;

//belakang
for (i=1; i<=9; i++){

glPushMatrix();
glColor3f(0.5, 0.5, 0.5);
glTranslatef(0,n,k);
glScalef(30,1.0,1.0);
kubus(4);
glPopMatrix();
n+=2;
k-=3.7;

}

//depan
for (i=1; i<=9; i++){

glPushMatrix();
glColor3f(0.5, 0.5, 0.5);
glTranslatef(0,j,l);
glScalef(30.0,1.0,1.0);
kubus(4);
glPopMatrix();
j+=2;
l+=3.7;
}

//kanan
for (i=1; i<=9; i++){

glPushMatrix();
glColor3f(0.5, 0.5, 0.5);
glTranslatef(a,b,-37);
glScalef(1.0,1.0,25);
kubus(4);
glPopMatrix();
b+=2;
a+=3.7;
}

//kiri
for (i=1; i<=9; i++){

glPushMatrix();
glColor3f(0.5, 0.5, 0.5);
glTranslatef(d,c,-37);
glScalef(1.0,1.0,25);
kubus(4);
glPopMatrix();
c+=2;
d-=3.7;
}

}

void kursi()
{


int i;
int j;
float n = 5;
float k = -93.5-2.5;
int p=58;

float c = 5;
float b = 17.5+2.5;
int a=58;

float x = 68;
float y = 5;
int z=11;
//belakang

for(j=1; j<=40; j++){	

if(j%5==0){
p-=3;	
}

else if (j<=26 && j>=20) 
{
	for (i=7; i>=1; i--){

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(p,n+4,k-7.4);
	glScalef(2,3,0.5);
	kubus(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(p,n-1+4,k+1-7.4);
	glScalef(2,0.5,1.5);
	kubus(1);
	glPopMatrix();
	n+=2;
	k-=3.7;
			if(i==1){
			n-=14;
			k+=25.9;
				}
					}
	p-=3;
}

else if (j<=19 && j>=14) 
{
	for (i=7; i>=1; i--){

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(p,n+4,k-7.4);
	glScalef(2,3,0.5);
	kubus(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(p,n-1+4,k+1-7.4);
	glScalef(2,0.5,1.5);
	kubus(1);
	glPopMatrix();
	n+=2;
	k-=3.7;
			if(i==1){
			n-=14;
			k+=25.9;
				}
					}
	p-=3;
}


else{

	for (i=1; i<=9; i++){

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(p,n,k);
	glScalef(2,3,0.5);
	kubus(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(p,n-1,k+1);
	glScalef(2,0.5,1.5);
	kubus(1);
	glPopMatrix();
	n+=2;
	k-=3.7;
			if(i==9){
			n-=18;
			k+=33.3;
				}
					}
p-=3;
}
}

//depan
for(j=1; j<=40; j++){
	if(j%5==0){
a-=3;	
}


else{
	for (i=1; i<=9; i++){

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(a,c,b);
	glScalef(2,3,0.5);
	kubus(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(a,c-1,b-1);
	glScalef(2,0.5,1.5);
	kubus(1);
	glPopMatrix();
	c+=2;
	b+=3.7;
			if(i==9){
			c-=18;
			b-=33.3;
				}
					}
a-=3;
}
}


//kiri
for(j=1; j<=33; j++){
if(j%5==0){
z-=3;	
}
else{	
	for (i=1; i<=9; i++){

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(x,y,z);
	glScalef(0.5,3,2);
	kubus(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(x-1,y-1,z);
	glScalef(1.5,0.5,2);
	kubus(1);
	glPopMatrix();
	y+=2;
	x+=3.7;
			if(i==9){
			y-=18;
			x-=33.3;
				}
					}
z-=3;
}
}

//kanan
float q = -68;
float w = 5;
int e=11;	
for(j=1; j<=33; j++){
if(j%5==0){
e-=3;	
}
else{	
	for (i=1; i<=9; i++){

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(q,w,e);
	glScalef(0.5,3,2);
	kubus(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(q+1,w-1,e);
	glScalef(1.5,0.5,2);
	kubus(1);
	glPopMatrix();
	w+=2;
	q-=3.7;
			if(i==9){
			w-=18;
			q+=33.3;
				}
					}
e-=3;
}
}
}

void tunnel ()
{
//tunnel	
glPushMatrix();
glColor3f(0.0, 0.0, 0.0);
glTranslatef(1,4,-93);
glScalef(8,9.9,1.0);
kubus(1);
glPopMatrix();

//dinding
glPushMatrix();
glColor3f(0.0, 0.0, 0.2);
glTranslatef(-2.75,4,-90);
glScalef(0.5,9.9,0.5);
kubus(1);
glPopMatrix();

//dinding
glPushMatrix();
glColor3f(0.0, 0.0, 0.2);
glTranslatef(4.75,4,-90);
glScalef(0.5,9.9,0.5);
kubus(1);
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 0.3);
glVertex3f(-3.01,9,-90);
glVertex3f(-3.01,0,-90);
glVertex3f(-3.01,0,-98);
glVertex3f(-3.01,9,-94);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 0.3);
glVertex3f(5.01,9,-90);
glVertex3f(5.01,0,-90);
glVertex3f(5.01,0,-98);
glVertex3f(5.01,9,-94);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 0.3);
glVertex3f(-3.01,9,-90);
glVertex3f(-3.01,9,-94);
glVertex3f(5.01,9,-94);
glVertex3f(5.01,9,-90);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0, 0.0, 0.3);
glVertex3f(-3.01,9,-94);
glVertex3f(-3.01,0,-98);
glVertex3f(5.01,0,-98);
glVertex3f(5.01,9,-94);
glEnd();



}

void pemisah()
{
//pagar
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(-3.75,2,-90-0.5);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();

//pagar
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(-3.75,2+2,-90-3.7-0.5);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();

//pagar
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(-3.75,2+2+2,-90-3.7-3.7-0.5);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();

//pagar
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(-9.75,2+2+2,-90-3.7-3.7-0.5);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();

//pagar
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(-16.75,2+2+2,-90-3.7-3.7-0.5);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();

//pagar
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(-16.75,2+2,-90-3.7-0.5);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();


glPushMatrix();
glLineWidth(2.0);
glBegin(GL_LINES);
glColor3f(0.2, 0.2, 0.2);
glVertex3f(-3.75,9,-90-3.7-0.5-3.7);
glVertex3f(-3.75,5,-90-0.5);
glEnd();
glPopMatrix();

glPushMatrix();
glLineWidth(2.0);
glBegin(GL_LINES);
glColor3f(0.2, 0.2, 0.2);
glVertex3f(-3.75,9,-90-3.7-0.5-3.7);
glVertex3f(-16.75,9,-90-3.7-0.5-3.7);
glEnd();
glPopMatrix();

glPushMatrix();
glLineWidth(2.0);
glBegin(GL_LINES);
glColor3f(0.2, 0.2, 0.2);
glVertex3f(-16.75,9,-90-3.7-0.5-3.7);
glVertex3f(-16.75,7,-90-3.7-0.5);
glEnd();
glPopMatrix();

//pagar2
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(5.75,2,-90-0.5);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();

//pagar2
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(5.75,2+2,-90-3.7-0.5);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();

//pagar2
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(5.75,2+2+2,-90-3.7-0.5-3.7);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();

//pagar 2
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(12.75,2+2+2,-90-3.7-3.7-0.5);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();

//pagar
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(18.75,2+2+2,-90-3.7-3.7-0.5);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();

//pagar2
glPushMatrix();
glColor3f(0.1, 0.1, 0.1);
glTranslatef(18.75,2+2,-90-3.7-0.5);
glScalef(0.5,7,0.5);
kubus(1);
glPopMatrix();

glPushMatrix();
glLineWidth(2.0);
glBegin(GL_LINES);
glColor3f(0.2, 0.2, 0.2);
glVertex3f(5.75,9,-90-3.7-0.5-3.7);
glVertex3f(5.75,5,-90-0.5);
glEnd();
glPopMatrix();

glPushMatrix();
glLineWidth(2.0);
glBegin(GL_LINES);
glColor3f(0.2, 0.2, 0.2);
glVertex3f(5.75,9,-90-3.7-0.5-3.7);
glVertex3f(18.75,9,-90-3.7-0.5-3.7);
glEnd();
glPopMatrix();

glPushMatrix();
glLineWidth(2.0);
glBegin(GL_LINES);
glColor3f(0.2, 0.2, 0.2);
glVertex3f(18.75,9,-90-3.7-0.5-3.7);
glVertex3f(18.75,7,-90-3.7-0.5);
glEnd();
glPopMatrix();


	
}

void tingkatbelakang(){
float a = 26;
float b = -100-2.5;
int i,j;

float n = 29.5;
float k = -100.5-2.5;
int p=58;
 //belakang
    glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 45-5 , -85-2.5-40-2.5);
    glVertex3f(60+2.5,45-5 ,-85-2.5-40-2.5);
    glVertex3f(60+2.5, 25.133 , -85-2.5-10-2.5);
    glVertex3f(-60-2.5, 25.133,-85-2.5-10-2.5); 
    glEnd();
    
    glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 25.133 , -85-2.5-10-2.5);
    glVertex3f(60+2.5,25.133 ,-85-2.5-10-2.5);
    glVertex3f(60+2.5, 25.133-4, -85-2.5-10-2.5);
    glVertex3f(-60-2.5, 25.133-4,-85-2.5-10-2.5); 
    glEnd();
    
     glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(60+2.5, 45-5 , -85-2.5-40-2.5);
    glVertex3f(60+2.5, 25.133 ,-85-2.5-10-2.5);
    glVertex3f(60+2.5, 25.133-4, -85-2.5-10-2.5);
    glVertex3f(60+2.5, 45-5-4, -85-2.5-40-2.5); 
    glEnd();
    
     glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 45-5 , -85-2.5-40-2.5);
    glVertex3f(-60-2.5, 25.133 ,-85-2.5-10-2.5);
    glVertex3f(-60-2.5, 25.133-4, -85-2.5-10-2.5);
    glVertex3f(-60-2.5, 45-5-4, -85-2.5-40-2.5); 
    glEnd();
    
    glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 45-5-4 , -85-2.5-40-2.5);
    glVertex3f(60+2.5,45-5-4 ,-85-2.5-40-2.5);
    glVertex3f(60+2.5, 25.133-4 , -85-2.5-10-2.5);
    glVertex3f(-60-2.5, 25.133-4,-85-2.5-10-2.5); 
    glEnd();
   
//tangga
for (i=1; i<=7; i++){

glPushMatrix();
glColor3f(0.5, 0.5, 0.5);
glTranslatef(0,a,b);
glScalef(30,1.0,1.0);
kubus(4);
glPopMatrix();
a+=2;
b-=3.7;
}
//kursi

for(j=1; j<=40; j++){
if(j%5==0){
p-=3;	
}
else{	
	for (i=1; i<=7; i++){

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(p,n,k);
	glScalef(2,3,0.5);
	kubus(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(p,n-1,k+1);
	glScalef(2,0.5,1.5);
	kubus(1);
	glPopMatrix();
	n+=2;
	k-=3.7;
			if(i==7){
			n-=14;
			k+=25.9;
				}
					}
p-=3;
}	
}
}

void pilar(){
	//belakang	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(46,30,-110);
	glScalef(1.0,50.0,1.0);
	kubus(1);
	glPopMatrix();	
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(16,30,-110);
	glScalef(1.0,50.0,1.0);
	kubus(1);
	glPopMatrix();	
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(-14,30,-110);
	glScalef(1.0,50.0,1.0);
	kubus(1);
	glPopMatrix();	
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(-44,30,-110);
	glScalef(1.0,50.0,1.0);
	kubus(1);
	glPopMatrix();	
	
	//depan
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(46,30,35);
	glScalef(1.0,50.0,1.0);
	kubus(1);
	glPopMatrix();	
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(16,30,35);
	glScalef(1.0,50.0,1.0);
	kubus(1);
	glPopMatrix();	
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(-14,30,35);
	glScalef(1.0,50.0,1.0);
	kubus(1);
	glPopMatrix();	
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(-44,30,35);
	glScalef(1.0,50.0,1.0);
	kubus(1);
	glPopMatrix();	
	
	//kiri
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(-82,30,-16);
	glScalef(1.0,50.0,1.0);
	kubus(1);
	glPopMatrix();	
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(-82,30,-61);
	glScalef(1.0,50.0,1.0);
	kubus(1);
	glPopMatrix();	
	
	//kanan
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(82,23.75,-16);
	glScalef(1.0,47.5,1.0);
	kubus(1);
	glPopMatrix();	
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(82,23.75,-61);
	glScalef(1.0,47.5,1.0);
	kubus(1);
	glPopMatrix();	
}

void bola(){
glPushMatrix();
glColor3f(0.5, 0.0, 0.0);
glTranslatef(0,1.5,-38);
glutSolidSphere(1.5,50,10);
glPopMatrix();	

}

void tingkatdepan(){
int i;	
int k;
float j=25;
float l=25.75+2.5;	
float c = 28.5;
float b = 25.5+2.5;
int a=58;

    glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 45-5 , 10.0+2.5+40+2.5);
    glVertex3f(60+2.5,45-5 ,10.0+2.5+40+2.5);
    glVertex3f(60+2.5, 20.133+4 , 10.0+2.5+10+2.5);
    glVertex3f(-60-2.5, 20.133+4, 10.0+2.5+10+2.5); 
    glEnd();
    
     glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 20.133+4 , 10.0+2.5+10+2.5);
    glVertex3f(60+2.5,20.133+4,10.0+2.5+10+2.5);
    glVertex3f(60+2.5, 20.133, 10.0+2.5+10+2.5);
    glVertex3f(-60-2.5, 20.133,10.0+2.5+10+2.5); 
    glEnd();
    
     glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(60+2.5, 45-5 , 10.0+2.5+40+2.5);
    glVertex3f(60+2.5, 24.133 ,10.0+2.5+10+2.5);
    glVertex3f(60+2.5, 20.133, 10.0+2.5+10+2.5);
    glVertex3f(60+2.5, 45-5-4, 10.0+2.5+40+2.5); 
    glEnd();
    
     glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 45-5 , 10.0+2.5+40+2.5);
    glVertex3f(-60-2.5, 24.133 ,10.0+2.5+10+2.5);
    glVertex3f(-60-2.5, 20.133, 10.0+2.5+10+2.5);
    glVertex3f(-60-2.5, 45-5-4, 10.0+2.5+40+2.5); 
    glEnd();
    
    glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 45-5-4 , 10.0+2.5+40+2.5);
    glVertex3f(60+2.5,45-5-4 ,10.0+2.5+40+2.5);
    glVertex3f(60+2.5, 20.133 , 10.0+2.5+10+2.5);
    glVertex3f(-60-2.5, 20.133,10.0+2.5+10+2.5); 
    glEnd();
    
//depan
for (i=1; i<=7; i++){

glPushMatrix();
glColor3f(0.5, 0.5, 0.5);
glTranslatef(0,j,l);
glScalef(30.0,1.0,1.0);
kubus(4);
glPopMatrix();
j+=2;
l+=3.7;
}    

//depan
for(k=1; k<=40; k++){
if(k%5==0){
a-=3;	
}
else{
	for (i=1; i<=7; i++){

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(a,c,b);
	glScalef(2,3,0.5);
	kubus(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(a,c-1,b-1);
	glScalef(2,0.5,1.5);
	kubus(1);
	glPopMatrix();
	c+=2;
	b+=3.7;
			if(i==7){
			c-=14;
			b-=25.9;
				}
					}
a-=3;
}	
}
}

void tingkatkiri(){
float c = 25.5;
float d = -75.7;
int i,j;	
glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5-40, 45-5 , -85-5);
    glVertex3f(-60-2.5-40,45-5 ,10.0+5);
    glVertex3f(-60-2.5-10, 22.133+2 , 10.0+5);
    glVertex3f(-60-2.5-10, 22.133+2, -85-5); 
    glEnd();	
    
glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5-40, 45-5-4 , -85-5);
    glVertex3f(-60-2.5-40,45-5-4 ,10.0+5);
    glVertex3f(-60-2.5-10, 22.133+2-4 , 10.0+5);
    glVertex3f(-60-2.5-10, 22.133+2-4, -85-5); 
    glEnd();    
    
 glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5-10, 22.133+2 , -85-5);
    glVertex3f(-60-2.5-10,22.133+2 ,10.0+5);
    glVertex3f(-60-2.5-10, 22.133+2-4 , 10.0+5);
    glVertex3f(-60-2.5-10, 22.133+2-4, -85-5); 
    glEnd();      
	
   glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5-10,22.133+2  , 10.0+5);
    glVertex3f(-60-2.5-10,22.133+2-4 ,10.0+5);
    glVertex3f(-60-2.5-40, 45-5-4 , 10.0+5);
    glVertex3f(-60-2.5-40, 45-5, 10.0+5); 
    glEnd();	 
    
     glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5-10,22.133+2  , -85-5);
    glVertex3f(-60-2.5-10,22.133+2-4 ,-85-5);
    glVertex3f(-60-2.5-40, 45-5-4 , -85-5);
    glVertex3f(-60-2.5-40, 45-5, -85-5); 
    glEnd();
    
    //kiri
for (i=1; i<=7; i++){

glPushMatrix();
glColor3f(0.5, 0.5, 0.5);
glTranslatef(d,c,-37);
glScalef(1.0,1.0,25);
kubus(4);
glPopMatrix();
c+=2;
d-=3.7;
}


//kanan
float q = -76;
float w = 29;
int e=11;	
for(j=1; j<=33; j++){
	if(j%5==0){
e-=3;	
}
else{
	for (i=1; i<=7; i++){

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(q,w,e);
	glScalef(0.5,3,2);
	kubus(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(q+1,w-1,e);
	glScalef(1.5,0.5,2);
	kubus(1);
	glPopMatrix();
	w+=2;
	q-=3.7;
			if(i==7){
			w-=14;
			q+=25.9;
				}
					}
e-=3;



}
}
}

void tingkatbelakangkiri(){
	
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 45-5 , -85-2.5-40-2.5);
    glVertex3f(-60-2.5, 24.133,-85-2.5-10-2.5); 
     glVertex3f(-60-2.5-10, 22.133+2, -85-5);
   glVertex3f(-60-2.5-40, 45-5 , -85-5);
    glEnd();
    
   	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 45-5-4 , -85-2.5-40-2.5);
    glVertex3f(-60-2.5, 23.133+2-4,-85-2.5-10-2.5); 
    glVertex3f(-60-2.5-10, 22.133+2-4, -85-5);
     glVertex3f(-60-2.5-40, 45-5-4 , -85-5);
     glEnd();
     
    glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 24.133,-85-2.5-10-2.5);
    glVertex3f(-60-2.5, 22.133+2-4,-85-2.5-10-2.5); 
    glVertex3f(-60-2.5-10, 22.133+2-4, -85-5);
    glVertex3f(-60-2.5-10, 22.133+2, -85-5);

    glEnd();
}

tingkatdepankiri(){
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 45-5 , 10.0+2.5+40+2.5);
    glVertex3f(-60-2.5-40,45-5 ,10.0+5); 
    glVertex3f(-60-2.5-10, 22.133+2 , 10.0+5);
   glVertex3f(-60-2.5, 20.133+4, 10.0+2.5+10+2.5);
    glEnd();
    
  glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5, 45-5-4 , 10.0+2.5+40+2.5);
    glVertex3f(-60-2.5-40,45-5-4 ,10.0+5); 
     glVertex3f(-60-2.5-10, 22.133+2-4 , 10.0+5);
   glVertex3f(-60-2.5, 20.133+4-4, 10.0+2.5+10+2.5);
    glEnd();
     
    glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-60-2.5-10, 22.133+2 , 10.0+5);
    glVertex3f(-60-2.5-10, 22.133+2-4 , 10.0+5); 
    glVertex3f(-60-2.5, 20.133+4-4, 10.0+2.5+10+2.5);
    glVertex3f(-60-2.5, 20.133+4, 10.0+2.5+10+2.5);
     glEnd();
}

void pinggirlapangan()
{
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.0, 0.0);
    glVertex3f(-60-5, -0.133, -85-5);
    glVertex3f(60+5, -0.133, -85-5);
    glVertex3f(60+5, -0.133, 10.0+5);
    glVertex3f(-60-5, -0.133, 10.0+5);
    glEnd();
    
    glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
    glVertex3f(60+2.5, -0.133+2, -85-5+1);
    glVertex3f(60+2.5, -0.133, -85-5+1);
    glVertex3f(60+2.5, -0.133, 10.0+5-1);
    glVertex3f(60+2.5, -0.133+2, 10.0+5-1);
    
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(60+2.7, -0.133+2, -85-5+1);
    glVertex3f(60+2.7, -0.133, -85-5+1);
    glVertex3f(60+2.7, -0.133, 10.0+5-1);
    glVertex3f(60+2.7, -0.133+2, 10.0+5-1);
    
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(60+2.5, -0.133+2, -85-5+1);
    glVertex3f(60+2.7, -0.133+2, -85-5+1);
    glVertex3f(60+2.7, -0.133+2, 10.0+5-1);
    glVertex3f(60+2.5, -0.133+2, 10.0+5-1);
    
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(60+2.7, -0.133+2, 10.0+5-1);
    glVertex3f(60+2.7, -0.133, 10.0+5-1);
    glVertex3f(60+2.5, -0.133, 10.0+5-1);
    glVertex3f(60+2.5, -0.133+2, 10.0+5-1);
    
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(60+2.7, -0.133+2, -85-5+1);
    glVertex3f(60+2.7, -0.133, -85-5+1);
    glVertex3f(60+2.5, -0.133, -85-5+1);
    glVertex3f(60+2.5, -0.133+2, -85-5+1);
    
    // pinggir lapangan kedua kanan
    
    glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-60-2.5, -0.133+2, -85-5+1);
    glVertex3f(-60-2.5, -0.133, -85-5+1);
    glVertex3f(-60-2.5, -0.133, 10.0+5-1);
    glVertex3f(-60-2.5, -0.133+2, 10.0+5-1);
    
    glEnd();
    
    //pinggir lapangan kedua belakang
    
    glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-60-2.5, -0.133+2, -85-2.5);
    glVertex3f(60+2.5, -0.133+2, -85-2.5);
    glVertex3f(60+2.5, -0.133, -85-2.5);
    glVertex3f(-60-2.5, -0.133, -85-2.5);
    glEnd();
    
}
void lapangan()
{	
int n;
int i = -50;
int j = -40;	
	//lapangan alas
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-50, -0.122, -75);
    glVertex3f(50, -0.122, -75);
    glVertex3f(50, -0.122, 0.0);
    glVertex3f(-50, -0.122, 0.0);
    glEnd();
    
    //garis"
    for(n=1; n<=10; n++){   
	if (n%2==0){
    	glColor3f(0.0, 0.7, 0.0);
	}
	else if (n%2!=0){
		glColor3f(0.0, 0.5, 0.0);
	}
		
    glBegin(GL_QUADS);
    glVertex3f(i, 0.01, -75);
    glVertex3f(i+10, 0.01, -75);
    glVertex3f(i+10, 0.01, 0.0);
    glVertex3f(i, 0.01, 0.0);
    glEnd();   
    i+=10;
	}	
	
		//garis penalty bawah
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(40, 0.12, -17);
    glVertex3f(25, 0.12, -17);
    glVertex3f(25, 0.12, -16);
    glVertex3f(40, 0.12, -16);
    glEnd();
    
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(40, 0.12, -22);
    glVertex3f(32, 0.12, -22);
    glVertex3f(32, 0.12, -23);
    glVertex3f(40, 0.12, -23);
    glEnd();
    
    //garis penalty atas   
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(40, 0.12, -58);
    glVertex3f(25, 0.12, -58);
    glVertex3f(25, 0.12, -57);
    glVertex3f(40, 0.12, -57);
    glEnd();
    
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(40, 0.12, -53);
    glVertex3f(32, 0.12, -53);
    glVertex3f(32, 0.12, -52);
    glVertex3f(40, 0.12, -52);
    glEnd();
    
    //garis penalty kanan
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(25, 0.12, -58);
    glVertex3f(24, 0.12, -58);
    glVertex3f(24, 0.12, -16);
    glVertex3f(25, 0.12, -16);
    glEnd();
    
     glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(32, 0.12, -53);
    glVertex3f(33, 0.12, -53);
    glVertex3f(33, 0.12, -22);
    glVertex3f(32, 0.12, -22);
    glEnd();
    
    
    
    //kanan

	//garis penalty bawah
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40, 0.12, -17);
    glVertex3f(-25, 0.12, -17);
    glVertex3f(-25, 0.12, -16);
    glVertex3f(-40, 0.12, -16);
    glEnd();
    
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40, 0.12, -22);
    glVertex3f(-32, 0.12, -22);
    glVertex3f(-32, 0.12, -23);
    glVertex3f(-40, 0.12, -23);
    glEnd();
    
    //garis penalty atas
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40, 0.12, -58);
    glVertex3f(-25, 0.12, -58);
    glVertex3f(-25, 0.12, -57);
    glVertex3f(-40, 0.12, -57);
    glEnd();
    
     glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40, 0.12, -53);
    glVertex3f(-32, 0.12, -53);
    glVertex3f(-32, 0.12, -52);
    glVertex3f(-40, 0.12, -52);
    glEnd();
    
    //garis penalty kanan
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-25, 0.12, -58);
    glVertex3f(-24, 0.12, -58);
    glVertex3f(-24, 0.12, -16);
    glVertex3f(-25, 0.12, -16);
    glEnd();
    
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-32, 0.12, -53);
    glVertex3f(-33, 0.12, -53);
    glVertex3f(-33, 0.12, -22);
    glVertex3f(-32, 0.12, -22);
    glEnd();
    
	//garis lapangan atas
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40, 0.12, -73);
    glVertex3f(40, 0.12, -73);
    glVertex3f(40, 0.12, -72);
    glVertex3f(-40, 0.12, -72);
    glEnd();
    
    //kanan
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(39, 0.12, -73);
    glVertex3f(40, 0.12, -73);
    glVertex3f(40, 0.12, -2.0);
    glVertex3f(39, 0.12, -2.0);
    glEnd();
    
    //tengah
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.5, 0.12, -73);
    glVertex3f(0.5, 0.12, -73);
    glVertex3f(0.5, 0.12, -2.0);
    glVertex3f(-0.5, 0.12, -2.0);
    glEnd();
    
    //kiri
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-39, 0.12, -73);
    glVertex3f(-40, 0.12, -73);
    glVertex3f(-40, 0.12, -2.0);
    glVertex3f(-39, 0.12, -2.0);
    glEnd();
    
    //bawah
    glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40, 0.12, -3);
    glVertex3f(40, 0.12, -3);
    glVertex3f(40, 0.12, -2);
    glVertex3f(-40, 0.12, -2);
    glEnd();
    
   
}

void gawang ()
{
int i;
float n = -52.5;
int j = -41;
float k = -52.5;
int m = 12;
int p= 12;
int o = -46;
	
	//kiri
glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-39.5,6,-22);
glScalef(1.0,12.0,1.0);
kubus(1);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-39.5,6,-52);
glScalef(1.0,12.0,1.0);
kubus(1);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(-39.5,11.5,-37);
glScalef(1.0,1.0,30.0);
kubus(1);
glPopMatrix();

//knan
glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(39.5,6,-22);
glScalef(1.0,12.0,1.0);
kubus(1);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(39.5,6,-52);
glScalef(1.0,12.0,1.0);
kubus(1);
glPopMatrix();

glPushMatrix();
glColor3f(1.0, 1.0, 1.0);
glTranslatef(39.5,11.5,-37);
glScalef(1.0,1.0,30.0);
kubus(1);
glPopMatrix();


//jaring

//atas
for (i=1; i<=32; i++){

glPushMatrix();
glLineWidth(1.0);
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(-40,12,n);
glVertex3f(-46,12,n);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(40,12,n);
glVertex3f(46,12,n);
glEnd();
glPopMatrix();
n+=1;
}

for (i=1; i<=6; i++){

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(j,12,-52.5);
glVertex3f(j,12,-21.5);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(-j,12,-52.5);
glVertex3f(-j,12,-21.5);
glEnd();
glPopMatrix();
j-=1;
}

//belakang
for (i=1; i<=32; i++){

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(-46,12,k);
glVertex3f(-46,0,k);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(46,12,k);
glVertex3f(46,0,k);
glEnd();
glPopMatrix();

k+=1;
}

for (i=1; i<=12; i++){

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(-46,m,-52.5);
glVertex3f(-46,m,-21.5);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(46,m,-52.5);
glVertex3f(46,m,-21.5);
glEnd();
glPopMatrix();

m-=1;
}


//kanan
for (i=1; i<=12; i++){

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(-40,p,-21.5);
glVertex3f(-46,p,-21.5);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(40,p,-21.5);
glVertex3f(46,p,-21.5);
glEnd();
glPopMatrix();
p-=1;
}

for (i=1; i<=6; i++){

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(o,12,-21.5);
glVertex3f(o,0,-21.5);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(-o,12,-21.5);
glVertex3f(-o,0,-21.5);
glEnd();
glPopMatrix();

o+=1;
}

//kiri
int y = 12;
for (i=1; i<=12; i++){

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(-40,y,-52.5);
glVertex3f(-46,y,-52.5);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(40,y,-52.5);
glVertex3f(46,y,-52.5);
glEnd();
glPopMatrix();

y-=1;
}

int u = -46;
for (i=1; i<=6; i++){

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(u,12,-52.5);
glVertex3f(u,0,-52.5);
glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex3f(-u,12,-52.5);
glVertex3f(-u,0,-52.5);
glEnd();
glPopMatrix();
u+=1;
}

}

void papanscore()
{
glPushMatrix();
glColor3f(0, 0, 0);
glTranslatef(60.5,39.5,-37);
glScalef(1.0,14.0,24.0);
kubus(1);
glPopMatrix();

glPushMatrix();
glColor3f(0.4, 0.4, 0.4);
glTranslatef(61.5,39.5,-37);
glScalef(1.0,16.0,25.0);
kubus(1);
glPopMatrix();

glPushMatrix();
glColor3f(0.4, 0.4, 0.4);
glTranslatef(60.5,47,-37);
glScalef(1.0,1.0,25.0);
kubus(1);
glPopMatrix();

glPushMatrix();
glColor3f(0.4, 0.4, 0.4);
glTranslatef(60.5,32,-37);
glScalef(1.0,1.0,25.0);
kubus(1);
glPopMatrix();

glPushMatrix();
glColor3f(0.4, 0.4, 0.4);
glTranslatef(60.5,39.5,-24.5);
glScalef(1.0,16.0,1.0);
kubus(1);
glPopMatrix();

glPushMatrix();
glColor3f(0.4, 0.4, 0.4);
glTranslatef(60.5,39.5,-49.5);
glScalef(1.0,16.0,1.0);
kubus(1);
glPopMatrix();
}

void bench(){
	int i;
int j;
float n = 5-2;
float k = -93.5+2;
int p=58-3.5;
for(j=1; j<=40; j++){	

if(j%5==0){
p-=3;	
}

else if (j<=25 && j>=20) 
{
	for (i=2; i>=1; i--){

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(p,n-0.5,k);
	glScalef(2,3+0.5,0.5);
	kubus(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(p,n-1,k+1);
	glScalef(2,0.5,1.5);
	kubus(1);
	glPopMatrix();
	n+=2;
	k-=3.7;
			if(i==1){
			n-=4;
			k+=7.4;
				}
					}
	p-=3;
}

else if (j<=19 && j>=15) 
{
	for (i=2; i>=1; i--){

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(p+8,n-0.5,k);
	glScalef(2,3.5,0.5);
	kubus(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.7);
	glTranslatef(p+8,n-1,k+1);
	glScalef(2,0.5,1.5);
	kubus(1);
	glPopMatrix();
	n+=2;
	k-=3.7;
			if(i==1){
			n-=4;
			k+=7.4;
				}
					}
	p-=3;
}	
else {
	p-=3;
}
}
}

void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f ); 
	glRotatef(xrot , 1.0f ,0.0f ,0.0f);
	glRotatef(yrot , 0.0f , 1.0f , 0.0f);
	glTranslatef(X,Y,Z);
	lapangan();
	lingkaran();
	gawang();
	pinggirlapangan();
	layoutkursi();
//	glPopMatrix();	
	tangga();
	gawang();
	kursi();
	tingkatbelakang(); tingkatdepan(); tingkatkiri();
	tingkatbelakangkiri(); tingkatdepankiri();
    tunnel();
    pemisah();
    bench();
	papanscore();
	pilar();
	bola();
	dinding();
	broadcaster();
	
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
	gluPerspective(120.0 , lebar/tinggi , 5.0 , 5000.0);
	glTranslatef(0.0 , -5.0 , -150.0);
	glMatrixMode(GL_MODELVIEW);
}
