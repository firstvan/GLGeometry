#include <GL/glut.h>
#include <math.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406
GLdouble winW = 800.0, winH = 800.0;
GLdouble center[2] = { winW / 2, winH / 2 };
GLdouble r = 300;
GLdouble nagyNo = 0;
GLdouble kicsiNo = 0;
GLdouble noX, noY, noKisX, noKisY;
GLdouble mForgat;
GLint resz = 10;
bool enabled= true;


typedef struct POINT2D{
	GLdouble x;
	GLdouble y;
} Point2D;

typedef struct LINE{
	GLdouble x1, x2;
	GLdouble y1, y2;
} Line;

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,winW, 0.0, winH);
	glShadeModel(GL_FLAT);
	glPointSize(5.0);
	glEnable(GL_POINT_SMOOTH);
	
}

GLdouble degToRad(GLint deg){

	return deg * (PI / 180);

}

void kor(){

	GLdouble lepeskoz = degToRad(1);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++){
		GLdouble x = center[0] + r * cos(i * lepeskoz);
		GLdouble y = center[1] + r * sin(i * lepeskoz);
		glVertex2d(x, y);
	}

	glEnd();
}

void display(){

	glClear(GL_COLOR_BUFFER_BIT);
	
	kor();
	
	Point2D pontok[12];
	GLdouble pontKoz = degToRad(360 / (double)12);

	glColor3f(1.0, 0.0, 0.0);
	
	glBegin(GL_POINTS);
		for (int i = 0; i < 12; i++){
			pontok[i].x = center[0] + r * cos(i * pontKoz);
			pontok[i].y = center[1] + r * sin(i * pontKoz);
			glVertex2d(pontok[i].x, pontok[i].y);
		}
	glEnd();

	GLdouble mutatolep = degToRad(1);
	mForgat = degToRad(90);
	Line nagyMutato;
	nagyMutato.x1 = center[0];
	nagyMutato.y1 = center[1];
	nagyMutato.x2 = center[0] + r * cos(noX * mutatolep + mForgat);
	nagyMutato.y2 = center[1] + r * sin(noY * mutatolep + mForgat);
	
	Line kisMutato;
	kisMutato.x1 = center[0];
	kisMutato.y1 = center[1];
	kisMutato.x2 = center[0] + (3 / (double)4) * r * cos(noKisX * mutatolep);
	kisMutato.y2 = center[1] + (3 / (double)4) * r * sin(noKisY * mutatolep);


	glColor3f(0.0, 1.0, 0.0);
	
	glBegin(GL_LINES);
		glVertex2d(nagyMutato.x1, nagyMutato.y1);
		glVertex2d(nagyMutato.x2, nagyMutato.y2);
		glVertex2d(kisMutato.x1, kisMutato.y1);
		glVertex2d(kisMutato.x2, kisMutato.y2);

		for (int i = 0; i < resz; i++){
			GLdouble tempX = kisMutato.x1 + i * ((3 / (double)4) * r / (double)resz) * cos(noKisX * mutatolep);
			GLdouble tempY = kisMutato.y1 + i * ((3 / (double)4) * r / (double)resz) * sin(noKisY * mutatolep);
			glVertex2d(tempX, tempY);

			GLdouble temp1X = nagyMutato.x2 - i * (r / (double)resz) * cos(noX * mutatolep + mForgat);
			GLdouble temp1Y = nagyMutato.y2 - i * (r / (double)resz) * sin(noY * mutatolep + mForgat);
			glVertex2d(temp1X, temp1Y);
		}
	glEnd();

	
	
	glutSwapBuffers();
}

void update(int n){
	if (enabled){
		noX--;
		noY--;
		noKisX = noX / (double)12;
		noKisY = noX / (double)12;
	}
	glutPostRedisplay();

	glutTimerFunc(30, update, 0);
}

void keyboard(unsigned char key, int x, int y){

	switch (key){
		case 's':
			enabled = false;
			break;
		case 'p':
			enabled = true;
			break;
	}

}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winW, winH);
	glutInitWindowPosition(50, 10);
	glutCreateWindow("Óra");

	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(30, update, 0);
	glutMainLoop();
	return 0;
}