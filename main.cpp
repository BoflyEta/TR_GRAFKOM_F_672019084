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
	
//-----------tangga depan kampus-----------//
	

//-----------SISI KANAN BANGUNAN-----------//
	
	//---------alas tembok bangunan---------//
	
	
/*			//sambungan alas tembok dengan tembok oren
			
				glBegin(GL_QUADS);//kiri
				glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
				glVertex3f(80.0, -70.0, 15.0);//kiri bawah
				glVertex3f(80.0, -40.0, 15.0);//kiri atas
				glVertex3f(80.0, -40.0, 20.0);//kanan atas
				glVertex3f(80.0, -70.0, 20.0);//kanan bawah
				glEnd();
							
				glBegin(GL_QUADS);//atas
				glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
				glVertex3f(80.0, -40.0, 15);//kiri bawah
				glVertex3f(90.0, -40.0, 15);//kanan bawah
				glVertex3f(90.0, -40.0, 20);//kanan atas
				glVertex3f(80.0, -40.0, 20);//kiri atas
				glEnd();
							
				glBegin(GL_QUADS);//kanan
				glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
				glVertex3f(90.0, -70.0, 15.0);//kiri bawah
				glVertex3f(90.0, -40.0, 15.0);//kiri atas
				glVertex3f(90.0, -40.0, 20.0);//kanan atas
				glVertex3f(90.0, -70.0, 20.0);//kanan bawah
				glEnd();
							
				glBegin(GL_QUADS); //depan
				glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
				glVertex3f(80.0, -70.0, 20.0);//kiri bawah
				glVertex3f(80.0, -40.0, 20.0);//kiri atas
				glVertex3f(90.0, -40.0, 20.0);//kanan atas
				glVertex3f(90.0, -70.0, 20.0);//kanan bawah
				glEnd();
*/			
			//sambungan alas tembok dengan tembok oren
	
			glBegin(GL_QUADS);//sebelah kanannya pintu masuk
			glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
			glVertex3f(-205.0, -70.0, 10.0);//kiri bawah
			glVertex3f(-205.0, -40.0, 10.0);//kiri atas
			glVertex3f(-205.0, -40.0, -10.0);//kanan atas
			glVertex3f(-205.0, -70.0, -10.0);//kanan bawah
			glEnd();
	
			glBegin(GL_QUADS); //utama kiri - tengah
			glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
			glVertex3f(-205.0, -70.0, 10.0);//kiri bawah
			glVertex3f(-205.0, -40.0, 10.0);//kiri atas
			glVertex3f(105.0, -40.0, 10.0);//kanan atas
			glVertex3f(105.0, -70.0, 10.0);//kanan bawah
			glEnd();
			
					//hiasan kecil
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
						glEnd();
			
					//hiasan kecil 
			
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
							
				//DINDING PEMBATAS
					for (i=0 ; i<5 ; i++){
						
						glBegin(GL_QUADS);//kiri
						glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
						glVertex3f(-195.0 + (i*70), -70.0, 10.0);//kiri bawah
						glVertex3f(-195.0 + (i*70), -40.0, 10.0);//kiri atas
						glVertex3f(-195.0 + (i*70), -40.0, 15.0);//kanan atas
						glVertex3f(-195.0 + (i*70), -70.0, 15.0);//kanan bawah
						glEnd();
						
						glBegin(GL_QUADS);//atas
						glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
						glVertex3f(-195.0 + (i*70), -40.0, 10);//kiri bawah
						glVertex3f(-175.0 + (i*70), -40.0, 10);//kanan bawah
						glVertex3f(-175.0 + (i*70), -40.0, 15);//kanan atas
						glVertex3f(-195.0 + (i*70), -40.0, 15);//kiri atas
						glEnd();
			
						glBegin(GL_QUADS); //depan
						glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
						glVertex3f(-195.0 + (i*70), -70.0, 15.0);//kiri bawah
						glVertex3f(-195.0 + (i*70), -40.0, 15.0);//kiri atas
						glVertex3f(-175.0 + (i*70), -40.0, 15.0);//kanan atas
						glVertex3f(-175.0 + (i*70), -70.0, 15.0);//kanan bawah
						glEnd();
						
						glBegin(GL_QUADS);//kanan
						glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
						glVertex3f(-175.0 + (i*70), -70.0, 10.0);//kiri bawah
						glVertex3f(-175.0 + (i*70), -40.0, 10.0);//kiri atas
						glVertex3f(-175.0 + (i*70), -40.0, 15.0);//kanan atas
						glVertex3f(-175.0 + (i*70), -70.0, 15.0);//kanan bawah
						glEnd();
						
						// tambahan moncong
							glBegin(GL_QUADS);//kiri
							glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
							glVertex3f(-190.0 + (i*70), -70.0, 15.0);//kiri bawah
							glVertex3f(-190.0 + (i*70), -40.0, 15.0);//kiri atas
							glVertex3f(-190.0 + (i*70), -40.0, 20.0);//kanan atas
							glVertex3f(-190.0 + (i*70), -70.0, 20.0);//kanan bawah
							glEnd();
							
							glBegin(GL_QUADS);//atas
							glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
							glVertex3f(-190.0 + (i*70), -40.0, 15);//kiri bawah
							glVertex3f(-180.0 + (i*70), -40.0, 15);//kanan bawah
							glVertex3f(-180.0 + (i*70), -40.0, 20);//kanan atas
							glVertex3f(-190.0 + (i*70), -40.0, 20);//kiri atas
							glEnd();
							
							glBegin(GL_QUADS);//kanan
							glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
							glVertex3f(-180.0 + (i*70), -70.0, 15.0);//kiri bawah
							glVertex3f(-180.0 + (i*70), -40.0, 15.0);//kiri atas
							glVertex3f(-180.0 + (i*70), -40.0, 20.0);//kanan atas
							glVertex3f(-180.0 + (i*70), -70.0, 20.0);//kanan bawah
							glEnd();
							
							
							
							glBegin(GL_QUADS); //depan
							glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
							glVertex3f(-190.0 + (i*70), -70.0, 20.0);//kiri bawah
							glVertex3f(-190.0 + (i*70), -40.0, 20.0);//kiri atas
							glVertex3f(-180.0 + (i*70), -40.0, 20.0);//kanan atas
							glVertex3f(-180.0 + (i*70), -70.0, 20.0);//kanan bawah
							glEnd();
						// tambahan moncong
					}
					//DINDING PEMBATAS
					
			
									
					//Pertengahan antar pembatas
						for (i=0 ; i<4 ; i++){
						
							//kiri PERTENGAHAN
								glBegin(GL_QUADS);//kiri
								glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
								glVertex3f(-165.0 + (i*70), -50.0, 10.0);//kiri bawah
								glVertex3f(-165.0 + (i*70), -40.0, 10.0);//kiri atas
								glVertex3f(-165.0 + (i*70), -40.0, 15.0);//kanan atas
								glVertex3f(-165.0 + (i*70), -50.0, 15.0);//kanan bawah
								glEnd();
								
								glBegin(GL_QUADS);//atas
								glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
								glVertex3f(-165.0 + (i*70), -40.0, 10);//kiri bawah
								glVertex3f(-157.0 + (i*70), -40.0, 10);//kanan bawah
								glVertex3f(-157.0 + (i*70), -40.0, 15);//kanan atas
								glVertex3f(-165.0 + (i*70), -40.0, 15);//kiri atas
								glEnd();
								
								glBegin(GL_QUADS);//belakang
								glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
								glVertex3f(-165.0 + (i*70), -50.0, 10);//kiri bawah
								glVertex3f(-157.0 + (i*70), -50.0, 10);//kanan bawah
								glVertex3f(-157.0 + (i*70), -50.0, 15);//kanan atas
								glVertex3f(-165.0 + (i*70), -50.0, 15);//kiri atas
								glEnd();
					
								glBegin(GL_QUADS); //depan
								glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
								glVertex3f(-165.0 + (i*70), -50.0, 15.0);//kiri bawah
								glVertex3f(-165.0 + (i*70), -40.0, 15.0);//kiri atas
								glVertex3f(-157.0 + (i*70), -40.0, 15.0);//kanan atas
								glVertex3f(-157.0 + (i*70), -50.0, 15.0);//kanan bawah
								glEnd();
								
								glBegin(GL_QUADS);//kanan
								glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
								glVertex3f(-157.0 + (i*70), -50.0, 10.0);//kiri bawah
								glVertex3f(-157.0 + (i*70), -40.0, 10.0);//kiri atas
								glVertex3f(-157.0 + (i*70), -40.0, 15.0);//kanan atas
								glVertex3f(-157.0 + (i*70), -50.0, 15.0);//kanan bawah
								glEnd();
					
							//kiri PERTENGAHAN
					
							//tengah PERTENGAHAN
							
								glBegin(GL_QUADS);//kiri
								glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
								glVertex3f(-157.0 + (i*70), -55.0, 10.0);//kiri bawah
								glVertex3f(-157.0 + (i*70), -40.0, 10.0);//kiri atas
								glVertex3f(-157.0 + (i*70), -40.0, 17.0);//kanan atas
								glVertex3f(-157.0 + (i*70), -55.0, 17.0);//kanan bawah
								glEnd();
								
								glBegin(GL_QUADS);//atas
								glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
								glVertex3f(-157.0 + (i*70), -40.0, 10);//kiri bawah
								glVertex3f(-143.0 + (i*70), -40.0, 10);//kanan bawah
								glVertex3f(-143.0 + (i*70), -40.0, 17);//kanan atas
								glVertex3f(-157.0 + (i*70), -40.0, 17);//kiri atas
								glEnd();
								
								glBegin(GL_QUADS);//belakang
								glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
								glVertex3f(-157.0 + (i*70), -55.0, 10);//kiri bawah
								glVertex3f(-143.0 + (i*70), -55.0, 10);//kanan bawah
								glVertex3f(-143.0 + (i*70), -55.0, 17);//kanan atas
								glVertex3f(-157.0 + (i*70), -55.0, 17);//kiri atas
								glEnd();
					
								glBegin(GL_QUADS); //depan
								glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
								glVertex3f(-157.0 + (i*70), -55.0, 17.0);//kiri bawah
								glVertex3f(-157.0 + (i*70), -40.0, 17.0);//kiri atas
								glVertex3f(-143.0 + (i*70), -40.0, 17.0);//kanan atas
								glVertex3f(-143.0 + (i*70), -55.0, 17.0);//kanan bawah
								glEnd();
								
								glBegin(GL_QUADS);//kanan
								glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
								glVertex3f(-143.0 + (i*70), -55.0, 10.0);//kiri bawah
								glVertex3f(-143.0 + (i*70), -40.0, 10.0);//kiri atas
								glVertex3f(-143.0 + (i*70), -40.0, 17.0);//kanan atas
								glVertex3f(-143.0 + (i*70), -55.0, 17.0);//kanan bawah
								glEnd();
							
							//tengah PERTENGAHAN
							
							//kanan PERTENGAHAN
								glBegin(GL_QUADS);//kiri
								glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
								glVertex3f(-143.0 + (i*70), -50.0, 10.0);//kiri bawah
								glVertex3f(-143.0 + (i*70), -40.0, 10.0);//kiri atas
								glVertex3f(-143.0 + (i*70), -40.0, 15.0);//kanan atas
								glVertex3f(-143.0 + (i*70), -50.0, 15.0);//kanan bawah
								glEnd();
								
								glBegin(GL_QUADS);//atas
								glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
								glVertex3f(-143.0 + (i*70), -40.0, 10);//kiri bawah
								glVertex3f(-135.0 + (i*70), -40.0, 10);//kanan bawah
								glVertex3f(-135.0 + (i*70), -40.0, 15);//kanan atas
								glVertex3f(-143.0 + (i*70), -40.0, 15);//kiri atas
								glEnd();
								
								glBegin(GL_QUADS);//belakang
								glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
								glVertex3f(-143.0 + (i*70), -50.0, 10);//kiri bawah
								glVertex3f(-135.0 + (i*70), -50.0, 10);//kanan bawah
								glVertex3f(-135.0 + (i*70), -50.0, 15);//kanan atas
								glVertex3f(-143.0 + (i*70), -50.0, 15);//kiri atas
								glEnd();
					
								glBegin(GL_QUADS); //depan
								glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
								glVertex3f(-143.0 + (i*70), -50.0, 15.0);//kiri bawah
								glVertex3f(-143.0 + (i*70), -40.0, 15.0);//kiri atas
								glVertex3f(-135.0 + (i*70), -40.0, 15.0);//kanan atas
								glVertex3f(-135.0 + (i*70), -50.0, 15.0);//kanan bawah
								glEnd();
								
								glBegin(GL_QUADS);//kanan
								glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
								glVertex3f(-135.0 + (i*70), -50.0, 10.0);//kiri bawah
								glVertex3f(-135.0 + (i*70), -40.0, 10.0);//kiri atas
								glVertex3f(-135.0 + (i*70), -40.0, 15.0);//kanan atas
								glVertex3f(-135.0 + (i*70), -50.0, 15.0);//kanan bawah
								glEnd();
					
							//kanan PERTENGAHAN
						}
					//Pertengahan antar pembatas
				
				

					
					
					
	//---------alas tembok bangunan---------//
	
	//---------atas nya alas tembok---------//
	
	//---------atas nya alas tembok---------//
	
//-----------SISI KANAN BANGUNAN-----------//	


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

/*void keyboard(unsigned char key, int x, int y){
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
}*/

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
	gluPerspective(100.0, lebar/tinggi, 10.0, 5000.0);
	glTranslatef(0.0, 0.0, -250.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(250,80);
	glutCreateWindow("3D");
	myInit();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
	
//glutKeyboardFunc(keyboard);
	
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}
