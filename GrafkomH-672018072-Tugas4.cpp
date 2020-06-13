#include <iostream>
#include <GL/freeglut.h>

float x_pos = 0.0f;
float y_pos = 0.0f;

float x_pos_acak = 0.0f;
float y_pos_acak = 0.0f;

float deltax = 0.05f;
float deltay = 0.03f;

float deltax_acak = 0.08f;
float deltay_acak = 0.06f;

bool toRight = true;
bool toUp = true;

bool toRight_acak = true;
bool toUp_acak = true;

bool anim = true;
bool segitiga = false;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	//ATAS BAWAH
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(0, y_pos);
	glEnd();

	//KIRI KANAN
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(x_pos, 0);
	glEnd();

	//ACAK
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(x_pos_acak, y_pos_acak);
	glEnd();

	//SEGITIGA
	if (segitiga) {
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, y_pos);
		glVertex2f(x_pos, 0);
		glVertex2f(x_pos_acak, y_pos_acak);
		glEnd();
	}

	glutSwapBuffers();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glPointSize(15.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
	if (anim) {
		if (x_pos < 1.0f && toRight) {
			x_pos += deltax;
		}
		else {
			toRight = false;
		}
		if (x_pos > -1.0f && !toRight) {
			x_pos -= deltax;
		}
		else {
			toRight = true;
		}
		if (y_pos < 0.955f && toUp) {
			y_pos += deltay;
		}
		else {
			toUp = false;
		}
		if (y_pos > -0.955f && !toUp) {
			y_pos -= deltay;
		}
		else {
			toUp = true;
		}
		//////////////////////////////////////////////////////////////////////////
		if (x_pos_acak < 0.95f && toRight_acak) {
			x_pos_acak += deltax_acak;
		}
		else {
			toRight_acak = false;
		}
		if (x_pos_acak > -0.95f && !toRight_acak) {
			x_pos_acak -= deltax_acak;
		}
		else {
			toRight_acak = true;
		}
		if (y_pos_acak < 0.95f && toUp_acak) {
			y_pos_acak += deltay_acak;
		}
		else {
			toUp_acak = false;
		}
		if (y_pos_acak > -0.95f && !toUp_acak) {
			y_pos_acak -= deltay_acak;
		}
		else {
			toUp_acak = true;
		}
	}
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'p') {
		anim = !anim;
	}
	/////////////////////////////////////////
	if (key == 's') {
		segitiga = !segitiga;
	}
	printf("%c Pressed\n", key);
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GrafkomH-672018072-Tugas4");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	myinit();
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}