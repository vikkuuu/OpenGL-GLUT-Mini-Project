#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

float LR=0.0;
float a=0.0;
float UD=0.0;
int n1=0,i=0,m=0,n=0;
int start=0;
float posx[12];
float posy[12];
int score=0;

void drawcar()
{
	glBegin(GL_QUADS);

	glColor3f(0.0,0.0,0.0);
	glVertex3f(-0.30+LR,-2.3+UD,0.0);
	glVertex3f(0.30+LR,-2.3+UD,0.0);
	glVertex3f(0.25+LR,-2.7+UD,0.0);
	glVertex3f(-0.25+LR,-2.7+UD,0.0);
     
    glVertex3f(-0.25+LR,-2.8+UD,0.0);
    glVertex3f(-0.25+LR,-3.0+UD,0.0);
    glVertex3f(0.25+LR,-3.0+UD,0.0);
    glVertex3f(0.25+LR,-2.8+UD,0.0);

    glVertex3f(-0.30+LR,-3.5+UD,0.0);
    glVertex3f(0.30+LR,-3.5+UD,0.0);
    glVertex3f(0.25+LR,-3.2+UD,0.0);
    glVertex3f(-0.25+LR,-3.2+UD,0.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(-0.33+LR,-2.4+UD,0.0);
	glVertex3f(-0.37+LR,-2.4+UD,0.0);
	glVertex3f(-0.37+LR,-3.4+UD,0.0);
	glVertex3f(-0.33+LR,-3.4+UD,0.0);
	glVertex3f(-0.28+LR,-3.2+UD,0.0);
	glVertex3f(-0.28+LR,-2.7+UD,0.0);

	glEnd();
	glColor3f(1.0,0.0,0.0);

	glBegin(GL_QUADS);

	
	glVertex3f(-0.37+LR,-2.7+UD,0.0);
	glVertex3f(-0.2+LR,-2.7+UD,0.0);
	glVertex3f(-0.28+LR,-2.75+UD,0.0);
	glVertex3f(-0.37+LR,-2.75+UD,0.0);

	glVertex3f(-0.28+LR,-3.2+UD,0.0);
	glVertex3f(-0.37+LR,-3.2+UD,0.0);
	glVertex3f(-0.37+LR,-3.15+UD,0.0);
	glVertex3f(-0.28+LR,-3.15+UD,0.0);

	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(0.30+LR,-2.0+UD,0.0);
	glVertex3f(-0.30+LR,-2.0+UD,0.0);
	glVertex3f(-0.40+LR,-2.1+UD,0.0);
	glVertex3f(-0.45+LR,-2.2+UD,0.0);
	glVertex3f(-0.45+LR,-3.5+UD,0.0);
	glVertex3f(-0.35+LR,-3.6+UD,0.0);
	glVertex3f(0.35+LR,-3.6+UD,0.0);
	glVertex3f(0.45+LR,-3.5+UD,0.0);
	glVertex3f(0.45+LR,-2.2+UD,0.0);
	glVertex3f(0.40+LR,-2.1+UD,0.0);
	glEnd();
	

}

void DrawCars()
{
	for(i=0;i<12;i++)
	{
		if(posy[i]-0.3<=-2.0+UD&&posy[i]-0.3>=-3.6+UD)
		{
			if(posx[i]+0.3>=-0.45+LR&&posx[i]-0.3<=0.45+LR)
			{
				score=score-100;
				if(score<0)
					exit(0);
				else
					posy[i]=-3.9;
			}
		}
		if(posy[i]<=-3.9)
		{
			score=score+5;
			printf("score=%d\n",score);
			
			n1=rand()%6;
			if(n1==0)
				posx[i]=-2.4;
			if(n1==1)
				posx[i]=-1.5;
			if(n1==2)
				posx[i]=-0.5;
			if(n1==3)
				posx[i]=0.5;
			if(n1==4)
				posx[i]=1.5;
			if(n1==5)
				posx[i]=2.4;
			posy[i]=8.0;
		}
		
		m=rand()%3;
		if(m==0)
			glColor3f(1.0,1.0,0.0);
		else if(m==1)
			glColor3f(0.0,1.0,1.0);
		else if(m==2)
			glColor3f(1.0,0.0,1.0);
		glBegin(GL_QUADS);
		glVertex3f(posx[i]+0.3,posy[i]+0.2,0.0);
		glVertex3f(posx[i]+0.2,posy[i]+0.3,0.0);
		glVertex3f(posx[i]-0.2,posy[i]+0.3,0.0);
		glVertex3f(posx[i]-0.3,posy[i]+0.2,0.0);
		glEnd();
		m=rand()%3;
		if(m==0)
			glColor3f(1.0,1.0,0.0);
		else if(m==1)
			glColor3f(0.0,1.0,1.0);
		else if(m==2)
			glColor3f(1.0,0.0,1.0);
		glBegin(GL_QUADS);
		glVertex3f(posx[i]+0.3,posy[i]+0.2,0.0);
		glVertex3f(posx[i]+0.3,posy[i]-0.2,0.0);
		glVertex3f(posx[i]-0.3,posy[i]-0.2,0.0);
		glVertex3f(posx[i]-0.3,posy[i]+0.2,0.0);
		glEnd();
		m=rand()%3;
		if(m==0)
			glColor3f(1.0,1.0,0.0);
		else if(m==1)
			glColor3f(0.0,1.0,1.0);
		else if(m==2)
			glColor3f(1.0,0.0,1.0);
		glBegin(GL_QUADS);
		glVertex3f(posx[i]+0.3,posy[i]-0.2,0.0);
		glVertex3f(posx[i]+0.2,posy[i]-0.3,0.0);
		glVertex3f(posx[i]-0.2,posy[i]-0.3,0.0);
		glVertex3f(posx[i]-0.3,posy[i]-0.2,0.0);
		glEnd();
	}
}
		

void Display()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-10.0);
	drawcar();
	DrawCars();
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
	gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
}

void keypress(int key,int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_LEFT:
			if(LR>-2.4)
				LR=LR-0.2;
			break;
		case GLUT_KEY_RIGHT:
			if(LR<2.4)
				LR=LR+0.2;
			break;
		case GLUT_KEY_UP:
			if(UD<6.1)
				UD=UD+0.3;
			break;
		case GLUT_KEY_DOWN:
			if(UD>-0.5)
				UD=UD-0.3;
			break;
	}
	glutPostRedisplay();
}

void IntialCars()
{
	for(i=0;i<12;i++)
	{
		n=rand()%6;
		if(n==0)
			posx[i]=-2.4;
		if(n==1)
			posx[i]=-1.5;
		if(n==2)
			posx[i]=-0.5;
		if(n==3)
			posx[i]=0.5;
		if(n==4)
			posx[i]=1.5;
		if(n==5)
			posx[i]=2.4;
		posy[i]=3.6+a;
		a=a+1.5;
	}
}

void Time(int value)
{
	for(i=0;i<12;i++)
	{
		posy[i]=posy[i]-0.2;
	}
	glutPostRedisplay();
	glutTimerFunc(100,Time,0);
}			
			
int main(int argc,char **argv)
{
	if(start==0)
	{
		IntialCars();
		start=1;
	}
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1366,768);
	glutCreateWindow("RACE");
	Enable();
	glutReshapeFunc(Resize);
	glutSpecialFunc(keypress);
	glutTimerFunc(1000,Time,0);
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
