#include <GL/glut.h>
#include <math.h>

GLfloat Y=100.0;
GLfloat X=0.0;
GLfloat Z=-100.0;
GLfloat k=0.0;
GLfloat rot=0;
GLfloat C1[3];
GLfloat C2[3];

void Cuboid(float b,float l,float h)
{
   glColor3fv(C1);

   glBegin(GL_POLYGON);            //bottom
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,0,+b/2);
   glEnd();


   glBegin(GL_POLYGON);                 //front
   glVertex3f(l/2,h,-b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glEnd();

   
   glBegin(GL_POLYGON);                  //left
  glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glVertex3f(-l/2,0,b/2);
   glVertex3f(-l/2,0,-b/2);
   glEnd();

   
   glBegin(GL_POLYGON);                //back
   glVertex3f(-l/2,h,b/2);
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(-l/2,0,b/2);
   glEnd();

   
   glBegin(GL_POLYGON);             //right
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(l/2,h,-b/2);
   glEnd();

   glColor3fv(C2);
   glBegin(GL_POLYGON);         //top
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,h,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glEnd();

  

}


void RECT(float l,float b)
{
  glBegin(GL_POLYGON);
  glVertex3f(-b,0,l);
  glVertex3f(b,0,l);
  glVertex3f(b,0,-l);
  glVertex3f(-b,0,-l);
  glEnd();
}

void SetC1(float x,float y,float z)
{
   C1[0]=x;
   C1[1]=y;
   C1[2]=z;
}

void SetC2(float x,float y,float z)
{
   C2[0]=x;
   C2[1]=y;
   C2[2]=z;
}

void makeRoadSlab()
{
    float L=20;
    float B=20;
    float b=0.5;
    float l=4;
    float fh=0.7;

    glColor3f(0,0,0);             //Concrete
    RECT(L,B+6);

    glPushMatrix();
    glTranslatef(0,0.5,0);
    glColor3f(1,1,0);          //Middle Yellow Strip
    RECT(L,b);
    glPopMatrix();

    glColor3f(1,1,1);       //WhiteStrips

    glPushMatrix();
    glTranslatef(-B/2,0.5,0);
    RECT(l,b);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(B/2,0.5,0);
    RECT(l,b);
    glPopMatrix();

    SetC2(0.871,0.722,0.529);
     SetC1(0.804,0.522,0.247);     //Footpath1
   
    glPushMatrix();
    glTranslatef(-(5*B/4),0,L/2);
   Cuboid(L,B/3,fh);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((5*B/4),0,L/2);
    Cuboid(L,B/3,fh);
    glPopMatrix();
    
    SetC2(0.957,0.643,0.376); 
    SetC1(0.804,0.522,0.247);         //Footpath2

    glPushMatrix();
    glTranslatef(-(5*B/4),0,-L/2);
    Cuboid(L,B/3,fh);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((5*B/4),0,-L/2);
    Cuboid(L,B/3,fh);
    glPopMatrix();
}



void Display()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(X,Y,Z,0,0,0,0,1,0);

	glRotatef(rot,0,1,0);
	
	for(int j=0;j<2;j++)
	{
		int pos=0;
		glPushMatrix();
		glTranslatef(0,0,0);
		if(j==1)
			glRotatef(180,0,1,0);
		
		for(int i=0;i<5;i++)
		{
			glPushMatrix();
			glTranslatef(pos,0,0);
			glRotatef(90,0,1,0);
			makeRoadSlab();
			glColor3f(0.165,0.42,0.42);
			glPushMatrix();
			glTranslatef(25,0,0);
			Cuboid(10,10,pos+20);
			glTranslatef(-50,0,0);
			Cuboid(10,10,pos+20);
			glTranslatef(-5,pos+25,0);
			glRotatef(90,0,0,-1);
			Cuboid(10,10,60);
			glPopMatrix();

			glPopMatrix();
			pos+=40;

		}
		glPushMatrix();
		glTranslatef(pos,0,0);
		glRotatef(90,0,1,0);
		makeRoadSlab();
		glPopMatrix();
		
		int A[20]={10,20,30,40,45,50,55,60,55,45,40,30,20,10,0};
		float posx=pos;
		float posy=0;
		for(int i=0;i<16;i++)
		{
			posx=posx+38*cos(A[i]*3.141/180);
			posy=posy-19*sin(A[i]*3.141/180);
			glPushMatrix();
			glTranslatef(posx,posy,0);
			glRotatef(90,0,1,0);
			glRotatef(A[i],1,0,0);
			makeRoadSlab();
			glPopMatrix();
			posy=posy-19*sin(A[i]*3.141/180);	
		}
	glPopMatrix();

}
	glutSwapBuffers();
}

void Enable()
{
	glEnable(GL_DEPTH_TEST);
}

void Resize(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,w/h,1,5000);
}

void Keypress(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 'W':
		{
			Z=Z+5;
			break;
		}
		case 'S':
			Z=Z-5;
			break;
		case 'A':
			X=X-5;
			break;
		case 'D':
			X=X+5;
			break;
		case 'K':
			Y=Y+5;
			break;
		case 'L':
			Y=Y-5;
			break;
		case 'G':
			rot+=5;
			break;
		case 'H':
			rot-=5;
			break;
	}
	glutPostRedisplay();
}


int main(int argv,char **argc)
{
	glutInit(&argv,argc);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(1366,768);
	glutCreateWindow("BRIDGE");
	Enable();
	glutReshapeFunc(Resize);
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keypress);
	glutMainLoop();
	return 0;
}
