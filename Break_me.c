#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<stdio.h>
#include <stdlib.h>
#include<cstdlib>

float X=0.0;
float v=-1.0;
float a=0.0;
float b=0.0;
float k=0.0;
float l=0.7;
int up=1,right=1,left=0,down=0,i;
int start=0;
int A[30];

void DrawBlock()
{
	glBegin(GL_QUADS);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(-0.25+X,-0.9,0.0);
	glVertex3f(0.25+X,-0.9,0.0);
	glVertex3f(0.25+X,-1.0,0.0);
	glVertex3f(-0.25+X,-1.0,0.0);
	glEnd();
}


void CheckBlock()
{
	l=0.7;
	for(int j=0;j<3;j++)
	{
		if(j%2==0)
			 k=-1.0;
		else
			 k=-0.9;
		for(int i=0;i<7;i++)
		{
			if(A[j*7+i]==0)
			{
				k=k+0.3;
				continue;
			}
			if(i>0)
				k=k+0.3;
			int ran=rand()%3;
			if(ran==0)
				glColor3f(1.0,1.0,0.0);
			else if(ran==1)
				glColor3f(0.0,1.0,1.0);
			else if(ran==2)
				glColor3f(1.0,0.0,1.0);
			glBegin(GL_QUADS);
			glVertex3f(k,l,0.0);
			glVertex3f(k+0.2,l,0.0);
			glVertex3f(k+0.2,l+0.1,0.0);
			glVertex3f(k,l+0.1,0.0);
			glEnd();
		}
		l=l+0.1;
	}
}



void DrawBall()
{
	glBegin(GL_QUADS);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(0.05+a,0.05+b,0.0);
	glVertex3f(0.05+a,-0.05+b,0.0);
	glVertex3f(-0.05+a,-0.05+b,0.0);
	glVertex3f(-0.05+a,0.05+b,0.0);
	glEnd();
}

void CheckBlockNumber(int num)
{	
	if(num%2==0)
		v=-1.05;
	else
		v=-0.95;
	for(int i=0;i<7;i++)
	{
		if(a>v&&a<=v+0.3)
		{
			if(A[num*7+i]==0)
			break;
			if(A[num*7+i]==1);
			{
				up=0;
				down=1;
				A[num*7+i]=0;
				//printf("yes1 %d %f %f %f\n",i,a,b,v);
				break;
			}
		}
		v=v+0.3;
		/*if(a-v==0);
		{
			if(A[num*7+i]==1||A[num*7+i+1]==1)
			{
				A[num*7+i]=0;
				A[num*7+i+1]=0;
				printf("yes2 %d %f %f %f\n",i,a,b,v);
				up=0;
				down=1;
			}
			break;
		}*/
	}
}

void CheckColison()
{
	if(b>0.84&&b<0.86)
	{
		CheckBlockNumber(2);
	}
	else if(b>0.74&&b<0.76)
	{
		CheckBlockNumber(1);
	}
	
	else if(b>0.64&&b<0.66)
	{
		CheckBlockNumber(0);
	}
	
	if(b>=0.95)
	{
		up=0;
		down=1;
	}
	if(a>=0.95)
	{
		left=1;
		right=0;
	}
	if(a<=-0.95)
	{
		right=1;
		left=0;
	}
	if(b<=-0.85)
	{
		if(X-0.25<=a&&X+0.25>=a)
		{
			down=0;
			up=1;
		}
		else
		   exit(0);
	}
}

void Display()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	DrawBlock();
	CheckBlock();
	DrawBall();
	glutSwapBuffers();
}

void keypress(int key,int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_LEFT:
		{
			if(X>-0.75)
			{
				
				X=X-0.04;
				
			}
			break;
		}
		case GLUT_KEY_RIGHT:
		{
			if(X<0.75)
			{
				X=X+0.04;
			}
			break;
		}
	}
	glutPostRedisplay();
}

void Time(int value)
{
	CheckColison();
	
	if(up==1)
	b=b+0.015;
	if(right==1)
	a=a+0.01;
	if(left==1)
	a=a-0.01;
	if(down==1)
	b=b-0.015;
	//printf("%f %f\n",a,b);
	glutPostRedisplay();
	glutTimerFunc(10,Time,0);
}

int main(int argc,char **argv)
{
	if(start==0)
	{
		for(int i=0;i<21;i++)
		A[i]=1;
		start=1;
	}
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(750,500);
    glutInitWindowPosition(200,50);
    glutCreateWindow("Breakout");
    glutSpecialFunc(keypress);
    glutTimerFunc(1000,Time,0);
    glutDisplayFunc(Display);
    glutMainLoop();
}
	
