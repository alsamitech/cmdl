/*
 *	(c) Alsami Technologies, 2020
 *
 *	This is a simple 3D Modeling Program which uses GLUT to model whatever the user inputs
 *
 * */

#include <stdio.h>
#include <GL/glut.h>

// Defines
#define HLEN 800
#define VLEN 600

	int cx=0,cy=0,cz=0;
	int cn;


struct Quads{
	int x1,y1,z1, x2,y2,z2 , x3, y3,z3 ,x4,y4,y5;
	float r,g,b;
	int state;
	int total

}; Quads Q[100];
void addQuad(){
	/*This function is called whenever we press our spacebar*/
	Q[0].state++;		// So let's increase our state by 1, so lets
	int st=Q[0].state;
	if(st==1){Q[0].total++;cn=Q[0].total;}
	if(st==1||st==2){Q[cn].x1=cx; Q[cn].1.cy;Q[cn].z1.cz}
	if(st==1||st==2||st==3){Q[cn].x1=cx; Q[cn].1.cy;Q[cn].z1.cz}
	if(st==1||st==2||st==3||st==4){Q[cn].x1=cx; Q[cn].1.cy;Q[cn].z1.cz}
}

void drawQuads(){}


void T_CB() {
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(cx,cy,cs);
	glutSolidCube(0.4);
}

void drawGrid() {

	int i;
	for(i=0;i<40;i++) {
		glPushMatrix();
		if(i<20) {glTranslatef(0,0,i);}
		if(i>=20){glTranslatef(i-20,0,0); glRotatef(-90.0,1,0);}

		glBegin(GL_LINES);
  		glColor3f(1,1,1); glLineWidth(1);
		glVertex3f(0,-0.1,0); glVertex3f(19,-0.1,0);
		glEnd();
		glPopMatrix();
	}
}

void display() {
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-13,0,45);
	glRotatef(40,1,1,10);
	

	T_CB();
	glutSwapBuffers();
}

void init() {

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(35,1.0f,0.1f,1000);
		glMatrixMode(GL_MODELVIEW);
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.1,0.1,0.1,1); 
}

void keyboard(unsigned char key, int x, int y) {

	if(key=='w'){cz=1;} if(key=='s'){cx+=1;}	// FORWARD
	if(key=='a'){cx-=1;} if(key=='d'){cx+=1;}	// LEFT
	if(key=='q'){cy+=1;} if(key=='z'){cy-=1;}	// UP
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(HLEN, VLEN);		// Sets the Window size (NOT LOOSE so  you can just change it in the defines category)
	glutCreateWindow("Alsami Modler");	// Creates window and title
	glutDisplayFunc(display);		// Sets the void display function as the function that handles the displaying
	glutKeyboardFunc(keyboard);		// Sets the void keyboard function as the function that handles keyboard Input
	glutMainLoop();				 // The main loop of the window
	return 0;				// Returns 0 if the everything went sucsessfully
}

