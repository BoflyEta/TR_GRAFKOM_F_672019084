#include <windows.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#define DEG2RAD 3.14159/180.0
int is_depth;
int i;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
void myInit(void){
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_COLOR_MATERIAL);
	//glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
	glLineWidth(1.0f);
}

void BatasBangunan(void){
	glBegin(GL_LINE_LOOP);//kiri
	glColor3f (1 , 0 , 0);
	glVertex3f(1000, -40, -150.0);
	glVertex3f(700, -40, -550.0);
	glVertex3f(200, -40, -350.0);
	glVertex3f(50, -40, -550.0);

	glVertex3f(-205, -40, -150.0);
	glVertex3f(-155, -40, 10.0);
	glVertex3f(1000, -40, 10.0);
	glEnd();
}

void DindingPembatasSisiKanan(int x, int y, int pembatas, int pembatasTengah){
	//--------------dinding pembatas--------------
	for (i=0 ; i<pembatas ; i++){
		glBegin(GL_QUADS);//kiri
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + (i*70), y, 10.0);//kiri bawah
		glVertex3f(x + (i*70), y + 30, 10.0);//kiri atas
		glVertex3f(x + (i*70), y + 30, 15.0);//kanan atas
		glVertex3f(x + (i*70), y, 15.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + (i*70), y + 30, 10);//kiri bawah
		glVertex3f(x + 20 + (i*70), y + 30, 10);//kanan bawah
		glVertex3f(x + 20 + (i*70), y + 30, 15);//kanan atas
		glVertex3f(x + (i*70), y + 30, 15);//kiri atas
		glEnd();
		glBegin(GL_QUADS); //depan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + (i*70), y, 15.0);//kiri bawah
		glVertex3f(x + (i*70), y + 30, 15.0);//kiri atas
		glVertex3f(x + 20 + (i*70), y + 30, 15.0);//kanan atas
		glVertex3f(x + 20 + (i*70), y, 15.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kanan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 20 + (i*70), y, 10.0);//kiri bawah
		glVertex3f(x + 20 + (i*70), y + 30, 10.0);//kiri atas
		glVertex3f(x + 20 + (i*70), y + 30, 15.0);//kanan atas
		glVertex3f(x + 20 + (i*70), y, 15.0);//kanan bawah
		glEnd();
		
		// tambahan moncong
			glBegin(GL_QUADS);//kiri
			glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
			glVertex3f(x + 5 + (i*70), y, 15.0);//kiri bawah
			glVertex3f(x + 5 + (i*70), y + 30, 15.0);//kiri atas
			glVertex3f(x + 5 + (i*70), y + 30, 20.0);//kanan atas
			glVertex3f(x + 5 + (i*70), y, 20.0);//kanan bawah
			glEnd();
			
			glBegin(GL_QUADS);//atas
			glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
			glVertex3f(x + 5 + (i*70), y + 30, 15);//kiri bawah
			glVertex3f(x + 15 + (i*70), y + 30, 15);//kanan bawah
			glVertex3f(x + 15 + (i*70), y + 30, 20);//kanan atas
			glVertex3f(x + 5 + (i*70), y + 30, 20);//kiri atas
			glEnd();
			
			glBegin(GL_QUADS);//kanan
			glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
			glVertex3f(x + 15 + (i*70), y, 15.0);//kiri bawah
			glVertex3f(x + 15 + (i*70), y + 30, 15.0);//kiri atas
			glVertex3f(x + 15 + (i*70), y + 30, 20.0);//kanan atas
			glVertex3f(x + 15 + (i*70), y, 20.0);//kanan bawah
			glEnd();
			
			glBegin(GL_QUADS); //depan
			glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
			glVertex3f(x + 5 + (i*70), y, 20.0);//kiri bawah
			glVertex3f(x + 5 + (i*70), y + 30, 20.0);//kiri atas
			glVertex3f(x + 15 + (i*70), y + 30, 20.0);//kanan atas
			glVertex3f(x + 15 + (i*70), y, 20.0);//kanan bawah
			glEnd();
		// tambahan moncong
	}
	
	//--------------pertengahan antar pembatas--------------
	for (i=0 ; i<pembatasTengah ; i++){
	//kiri PERTENGAHAN
		glBegin(GL_QUADS);//kiri
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 30 + (i*70), y + 20, 10.0);//kiri bawah
		glVertex3f(x + 30 + (i*70), y + 30, 10.0);//kiri atas
		glVertex3f(x + 30 + (i*70), y + 30, 15.0);//kanan atas
		glVertex3f(x + 30 + (i*70), y + 20, 15.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 30 + (i*70), y + 30, 10);//kiri bawah
		glVertex3f(x + 38 + (i*70), y + 30, 10);//kanan bawah
		glVertex3f(x + 38 + (i*70), y + 30, 15);//kanan atas
		glVertex3f(x + 30 + (i*70), y + 30, 15);//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 30 + (i*70), y + 20, 10);//kiri bawah
		glVertex3f(x + 38 + (i*70), y + 20, 10);//kanan bawah
		glVertex3f(x + 38 + (i*70), y + 20, 15);//kanan atas
		glVertex3f(x + 30 + (i*70), y + 20, 15);//kiri atas
		glEnd();
		glBegin(GL_QUADS); //depan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 30 + (i*70), y + 20, 15.0);//kiri bawah
		glVertex3f(x + 30 + (i*70), y + 30, 15.0);//kiri atas
		glVertex3f(x + 38 + (i*70), y + 30, 15.0);//kanan atas
		glVertex3f(x + 38 + (i*70), y + 20, 15.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kanan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 38 + (i*70), y + 20, 10.0);//kiri bawah
		glVertex3f(x + 38 + (i*70), y + 30, 10.0);//kiri atas
		glVertex3f(x + 38 + (i*70), y + 30, 15.0);//kanan atas
		glVertex3f(x + 38 + (i*70), y + 20, 15.0);//kanan bawah
		glEnd();
	//kiri PERTENGAHAN
	//tengah PERTENGAHAN
		glBegin(GL_QUADS);//kiri
		glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
		glVertex3f(x + 38 + (i*70), y + 15, 10.0);//kiri bawah
		glVertex3f(x + 38 + (i*70), y + 30, 10.0);//kiri atas
		glVertex3f(x + 38 + (i*70), y + 30, 17.0);//kanan atas
		glVertex3f(x + 38 + (i*70), y + 15, 17.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
		glVertex3f(x + 38 + (i*70), y + 30, 10);//kiri bawah
		glVertex3f(x + 52 + (i*70), y + 30, 10);//kanan bawah
		glVertex3f(x + 52 + (i*70), y + 30, 17);//kanan atas
		glVertex3f(x + 38 + (i*70), y + 30, 17);//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
		glVertex3f(x + 38 + (i*70), y + 15, 10);//kiri bawah
		glVertex3f(x + 52 + (i*70), y + 15, 10);//kanan bawah
		glVertex3f(x + 52 + (i*70), y + 15, 17);//kanan atas
		glVertex3f(x + 38 + (i*70), y + 15, 17);//kiri atas
		glEnd();
		glBegin(GL_QUADS); //depan
		glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
		glVertex3f(x + 38 + (i*70), y + 15, 17.0);//kiri bawah
		glVertex3f(x + 38 + (i*70), y + 30, 17.0);//kiri atas
		glVertex3f(x + 52 + (i*70), y + 30, 17.0);//kanan atas
		glVertex3f(x + 52 + (i*70), y + 15, 17.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kanan
		glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
		glVertex3f(x + 52 + (i*70), y + 15, 10.0);//kiri bawah
		glVertex3f(x + 52 + (i*70), y + 30, 10.0);//kiri atas
		glVertex3f(x + 52 + (i*70), y + 30, 17.0);//kanan atas
		glVertex3f(x + 52 + (i*70), y + 15, 17.0);//kanan bawah
		glEnd();
	//tengah PERTENGAHAN
	
	//kanan PERTENGAHAN
		glBegin(GL_QUADS);//kiri
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 52 + (i*70), y + 20, 10.0);//kiri bawah
		glVertex3f(x + 52 + (i*70), y + 30, 10.0);//kiri atas
		glVertex3f(x + 52 + (i*70), y + 30, 15.0);//kanan atas
		glVertex3f(x + 52 + (i*70), y + 20, 15.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 52 + (i*70), y + 30, 10);//kiri bawah
		glVertex3f(x + 60 + (i*70), y + 30, 10);//kanan bawah
		glVertex3f(x + 60 + (i*70), y + 30, 15);//kanan atas
		glVertex3f(x + 52 + (i*70), y + 30, 15);//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 60 + (i*70), y + 20, 10);//kiri bawah
		glVertex3f(x + 60 + (i*70), y + 20, 10);//kanan bawah
		glVertex3f(x + 60 + (i*70), y + 20, 15);//kanan atas
		glVertex3f(x + 60 + (i*70), y + 20, 15);//kiri atas
		glEnd();
		glBegin(GL_QUADS); //depan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 52 + (i*70), y + 20, 15.0);//kiri bawah
		glVertex3f(x + 52 + (i*70), y + 30, 15.0);//kiri atas
		glVertex3f(x + 60 + (i*70), y + 30, 15.0);//kanan atas
		glVertex3f(x + 60 + (i*70), y + 20, 15.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kanan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 60 + (i*70), y + 20, 10.0);//kiri bawah
		glVertex3f(x + 60 + (i*70), y + 30, 10.0);//kiri atas
		glVertex3f(x + 60 + (i*70), y + 30, 15.0);//kanan atas
		glVertex3f(x + 60 + (i*70), y + 20, 15.0);//kanan bawah
		glEnd();
	//kanan PERTENGAHAN
	}
}
void DindingSisiKanan(){
	//--------------sebelah kanannya pintu masuk--------------
	glBegin(GL_QUADS);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-205.0, -70.0, 10.0);//kiri bawah
	glVertex3f(-205.0, -40.0, 10.0);//kiri atas
	glVertex3f(-205.0, -40.0, -10.0);//kanan atas
	glVertex3f(-205.0, -70.0, -10.0);//kanan bawah
	glEnd();
	
	//--------------tembok alas--------------
	glBegin(GL_QUADS);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-205.0, -70.0, 10.0);//kiri bawah
	glVertex3f(-205.0, -40.0, 10.0);//kiri atas
	glVertex3f(105.0, -40.0, 10.0);//kanan atas
	glVertex3f(105.0, -70.0, 10.0);//kanan bawah
	glEnd();
	
	//--------------lengkungan pintu--------------
	glBegin(GL_QUADS); //utama kanan
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(105.0, -70.0, 10.0);//kiri bawah
	glVertex3f(105.0, -40.0, 10.0);//kiri atas
	glVertex3f(125.0, -40.0, -10.0);//kanan atas
	glVertex3f(125.0, -70.0, -10.0);//kanan bawah
	glEnd();
	
	glBegin(GL_QUADS); //utama kanan akhir
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(125.0, -70.0, -10.0);//kiri bawah
	glVertex3f(125.0, -40.0, -10.0);//kiri atas
	glVertex3f(130.0, -40.0, -10.0);//kanan atas
	glVertex3f(130.0, -70.0, -10.0);//kanan bawah
	glEnd();
	
	//DindingPembatas(posisi x, posisi y, banyak pembatas, banyak pembatasTengah) --- z nya bakalan sama jadi ga usah masuk parameter
	DindingPembatasSisiKanan(-195, -70, 5, 4);
	//DindingPembatasSisiKanan(160, -70, 2, 1);
	
	//=========================================================================================================================================================================
	
	
}
void tampil(void){
	//keyboard
	//if(is_depth) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//else glClear(GL_COLOR_BUFFER_BIT);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glPushMatrix();

	BatasBangunan();
	DindingSisiKanan();

	/*//--------------hiasan kecil--------------
	glBegin(GL_QUADS);//kiri
	glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
	glVertex3f(-205.0, -55.0, 10.0);//kiri bawah
	glVertex3f(-205.0, -40.0, 10.0);//kiri atas
	glVertex3f(-205.0, -40.0, 15.0);//kanan atas
	glVertex3f(-205.0, -55.0, 15.0);//kanan bawah
	glEnd();
	
	glBegin(GL_QUADS);//atas
	glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
	glVertex3f(-205.0, -40.0, 10);//kiri bawah
	glVertex3f(-200.0, -40.0, 10);//kanan bawah
	glVertex3f(-200.0, -40.0, 15);//kanan atas
	glVertex3f(-205.0, -40.0, 15);//kiri atas
	glEnd();
	glBegin(GL_QUADS); //depan
	glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
	glVertex3f(-205.0, -55.0, 15.0);//kiri bawah
	glVertex3f(-205.0, -40.0, 15.0);//kiri atas
	glVertex3f(-200.0, -40.0, 15.0);//kanan atas
	glVertex3f(-200.0, -55.0, 15.0);//kanan bawah
	glEnd();
	
	glBegin(GL_QUADS);//kanan
	glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
	glVertex3f(-200.0, -55, 10.0);//kiri bawah
	glVertex3f(-200.0, -40.0, 10.0);//kiri atas
	glVertex3f(-200.0, -40.0, 15.0);//kanan atas
	glVertex3f(-200.0, -55.0, 15.0);//kanan bawah
	glEnd();*/
	
	glPushMatrix();
	glPopMatrix();
	
	glutSwapBuffers();
}
void idle(){
	if(!mouseDown){
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'w':
		case 'W':
			glTranslatef(0.0,0.0,3.0);
			break;
		case 'd':
		case 'D':
			glTranslatef(3.0,0.0,3.0);
			break;
		case 's':
		case 'S':
			glTranslatef(0.0,0.0,-3.0);
			break;
		case 'a':
		case 'A':
			glTranslatef(-3.0,0.0,0.0);
			break;
		case'7':
			glTranslatef(0.0,3.0,0.0);
			break;
		case'9':
			glTranslatef(0.0,-3.0,0.0);
			break;
		case'2':
			glRotatef(2.0, 1.0, 0.0, 0.0);
			break;
		case'8':
			glRotatef(-2.0, 1.0, 0.0, 0.0);
			break;
		case'6':
			glRotatef(2.0, 0.0, 1.0, 0.0);
			break;
		case'4':
			glRotatef(-2.0, 0.0, 1.0, 0.0);
			break;
		case'1':
			glRotatef(2.0, 0.0, 0.0, 1.0);
			break;
		case'3':
			glRotatef(-2.0, 0.0, 0.0, 1.0);
			break;
		case'5':
			if(is_depth){
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			}else{
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
	}
	tampil();
}
void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}else{
		mouseDown = false;
	}
}
void mouseMotion(int x, int y){
	if(!mouseDown){
		xrot = y + ydiff;
		yrot = x - xdiff;
		glutPostRedisplay();
	}	
}
void ukuran(int lebar, int tinggi){
	if(tinggi == 0) tinggi = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, lebar/tinggi, 10.0, 1500.0);
	glTranslatef(0.0, 0.0, -250.0);
	glTranslatef(500.0, 500.0, -1000.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowSize(1500,600);
	glutInitWindowPosition(250,80);
	glutCreateWindow("3D");
	myInit();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
	
	glutKeyboardFunc(keyboard);
	
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}
