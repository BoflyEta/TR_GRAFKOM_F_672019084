#include <windows.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#define DEG2RAD 3.14159/180.0
int is_depth;
int i;

int kbmouse = 0;

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


void gedungKiri1(){
	//batas belakang
	glBegin(GL_QUADS);
	glColor3f (0, 0, 0);
	glVertex3f(-300, -70, -350.0);
	glVertex3f(220, -70, -550.0);
	glVertex3f(220, 440, -550.0);
	glVertex3f(-300, 440, -350.0);
	glEnd();
	
	//sekat jendela vertikal
	for(i = 0; i < 7; i++){
		glBegin(GL_QUADS);
		glColor3f (1, 1, 1);
		glVertex3f(-345 + (i*80.84), 80, -410.0 - (i*33.3));//kanan bawah
		glVertex3f(-310 + (i*80.84), 80, -417.5 - (i*33.3));//kiri bawah
		glVertex3f(-310 + (i*80.84), 440, -417.5 - (i*33.3));//kiri atas
		glVertex3f(-345 + (i*80.84), 440, -410.0 - (i*33.3));//kanan atas
		glEnd();
	}
	
	//sekat bawah jendela horizontal
	glBegin(GL_QUADS);
	glColor3f (1, 1, 1);
	glVertex3f(-345, 80, -410.0);
	glVertex3f(175, 80, -617.5);
	glVertex3f(175, 170, -617.5);
	glVertex3f(-345, 170, -410.0);
	glEnd();
	
	//sekat jendela horizontal
	for(i = 0; i<3; i++){
		glBegin(GL_QUADS);
		glColor3f (1, 1, 1);
		glVertex3f(-345, 240 + (i * 90), -410.0);
		glVertex3f(175, 240 + (i * 90), -617.5);
		glVertex3f(175, 260 + (i * 90), -617.5);
		glVertex3f(-345, 260 + (i * 90), -410.0);
		glEnd();
	}
	
	//tembok kiri
	glBegin(GL_QUADS);
	glColor3f (1, 1, 1);
	glVertex3f(220, 440, -550.0);
	glVertex3f(175, 440, -617.5);
	glVertex3f(175, -70, -617.5);
	glVertex3f(220, -70, -550.0);
	glEnd();
	
	//tembok atas
	glBegin(GL_QUADS);
	glColor3f (1, 1, 1);
	glVertex3f(220, 440, -550.0);
	glVertex3f(175, 440, -617.5);
	glVertex3f(-345, 440, -410.0);
	glVertex3f(-300, 440, -350.0);
	glEnd();
	
	//tembok bawah
	glBegin(GL_QUADS);
	glColor3f (1, 1, 1);
	glVertex3f(220, 80, -550.0);
	glVertex3f(175, 80, -617.5);
	glVertex3f(-345, 80, -410.0);
	glVertex3f(-300, 80, -350.0);
	glEnd();
}

void gedungKiri2(){
	//batas belakang
	glBegin(GL_QUADS);//kiri
	glColor3f (0, 0, 0);
	glVertex3f(-300, -70, -350.0);
	glVertex3f(-450, -70, -550.0);
	glVertex3f(-450, 440, -550.0);
	glVertex3f(-300, 440, -350.0);
	glEnd();
}

void gedungKiri(){
	gedungKiri1();
	gedungKiri2();
}


void BatasBangunan(void){
	glBegin(GL_LINE_LOOP);
	glColor3f (1 , 0 , 0);
	
	glVertex3f(500, -70, -150.0);
	glVertex3f(220, -70, -550.0);
	glVertex3f(-300, -70, -350.0);
	glVertex3f(-450, -70, -550.0);
	
	glVertex3f(-705, -70, -150.0);
	glVertex3f(-700, -70, 10.0);
	glVertex3f(500, -70, 10.0);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f (1 , 0 , 0);
	
	glVertex3f(500, 440, -150.0);
	glVertex3f(220, 440, -550.0);
	glVertex3f(-300, 440, -350.0);
	glVertex3f(-450, 440, -550.0);
	
	glVertex3f(-705, 440, -150.0);
	glVertex3f(-700, 440, 10.0);
	glVertex3f(500, 440, 10.0);
	glEnd();
}





void DindingPembatasSisiKanan(int x, int y, int pembatas, int pembatasTengah){
	//--------------dinding pembatas--------------
	for (i=0 ; i<pembatas ; i++){
		glBegin(GL_QUADS);//kiri
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + (i*70), y, 110.0);//kiri bawah
		glVertex3f(x + (i*70), y + 30, 110.0);//kiri atas
		glVertex3f(x + (i*70), y + 30, 115.0);//kanan atas
		glVertex3f(x + (i*70), y, 115.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + (i*70), y + 30, 110);//kiri bawah
		glVertex3f(x + 20 + (i*70), y + 30, 110);//kanan bawah
		glVertex3f(x + 20 + (i*70), y + 30, 115);//kanan atas
		glVertex3f(x + (i*70), y + 30, 115);//kiri atas
		glEnd();
		glBegin(GL_QUADS); //depan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + (i*70), y, 115.0);//kiri bawah
		glVertex3f(x + (i*70), y + 30, 115.0);//kiri atas
		glVertex3f(x + 20 + (i*70), y + 30, 115.0);//kanan atas
		glVertex3f(x + 20 + (i*70), y, 115.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kanan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 20 + (i*70), y, 110.0);//kiri bawah
		glVertex3f(x + 20 + (i*70), y + 30, 110.0);//kiri atas
		glVertex3f(x + 20 + (i*70), y + 30, 115.0);//kanan atas
		glVertex3f(x + 20 + (i*70), y, 115.0);//kanan bawah
		glEnd();
		
		// tambahan moncong
			glBegin(GL_QUADS);//kiri
			glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
			glVertex3f(x + 5 + (i*70), y, 115.0);//kiri bawah
			glVertex3f(x + 5 + (i*70), y + 30, 115.0);//kiri atas
			glVertex3f(x + 5 + (i*70), y + 30, 120.0);//kanan atas
			glVertex3f(x + 5 + (i*70), y, 120.0);//kanan bawah
			glEnd();
			
			glBegin(GL_QUADS);//atas
			glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
			glVertex3f(x + 5 + (i*70), y + 30, 115);//kiri bawah
			glVertex3f(x + 15 + (i*70), y + 30, 115);//kanan bawah
			glVertex3f(x + 15 + (i*70), y + 30, 120);//kanan atas
			glVertex3f(x + 5 + (i*70), y + 30, 120);//kiri atas
			glEnd();
			
			glBegin(GL_QUADS);//kanan
			glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
			glVertex3f(x + 15 + (i*70), y, 115.0);//kiri bawah
			glVertex3f(x + 15 + (i*70), y + 30, 115.0);//kiri atas
			glVertex3f(x + 15 + (i*70), y + 30, 120.0);//kanan atas
			glVertex3f(x + 15 + (i*70), y, 120.0);//kanan bawah
			glEnd();
			
			glBegin(GL_QUADS); //depan
			glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
			glVertex3f(x + 5 + (i*70), y, 120.0);//kiri bawah
			glVertex3f(x + 5 + (i*70), y + 30, 120.0);//kiri atas
			glVertex3f(x + 15 + (i*70), y + 30, 120.0);//kanan atas
			glVertex3f(x + 15 + (i*70), y, 120.0);//kanan bawah
			glEnd();
		// tambahan moncong
	}
	
	//--------------pertengahan antar pembatas--------------
	for (i=0 ; i<pembatasTengah ; i++){
	//kiri PERTENGAHAN
		glBegin(GL_QUADS);//kiri
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 30 + (i*70), y + 20, 110.0);//kiri bawah
		glVertex3f(x + 30 + (i*70), y + 30, 110.0);//kiri atas
		glVertex3f(x + 30 + (i*70), y + 30, 115.0);//kanan atas
		glVertex3f(x + 30 + (i*70), y + 20, 115.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 30 + (i*70), y + 30, 110);//kiri bawah
		glVertex3f(x + 38 + (i*70), y + 30, 110);//kanan bawah
		glVertex3f(x + 38 + (i*70), y + 30, 115);//kanan atas
		glVertex3f(x + 30 + (i*70), y + 30, 115);//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 30 + (i*70), y + 20, 110);//kiri bawah
		glVertex3f(x + 38 + (i*70), y + 20, 110);//kanan bawah
		glVertex3f(x + 38 + (i*70), y + 20, 115);//kanan atas
		glVertex3f(x + 30 + (i*70), y + 20, 115);//kiri atas
		glEnd();
		glBegin(GL_QUADS); //depan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 30 + (i*70), y + 20, 115.0);//kiri bawah
		glVertex3f(x + 30 + (i*70), y + 30, 115.0);//kiri atas
		glVertex3f(x + 38 + (i*70), y + 30, 115.0);//kanan atas
		glVertex3f(x + 38 + (i*70), y + 20, 115.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kanan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 38 + (i*70), y + 20, 110.0);//kiri bawah
		glVertex3f(x + 38 + (i*70), y + 30, 110.0);//kiri atas
		glVertex3f(x + 38 + (i*70), y + 30, 115.0);//kanan atas
		glVertex3f(x + 38 + (i*70), y + 20, 115.0);//kanan bawah
		glEnd();
	//kiri PERTENGAHAN
	//tengah PERTENGAHAN
		glBegin(GL_QUADS);//kiri
		glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
		glVertex3f(x + 38 + (i*70), y + 15, 110.0);//kiri bawah
		glVertex3f(x + 38 + (i*70), y + 30, 110.0);//kiri atas
		glVertex3f(x + 38 + (i*70), y + 30, 117.0);//kanan atas
		glVertex3f(x + 38 + (i*70), y + 15, 117.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
		glVertex3f(x + 38 + (i*70), y + 30, 110);//kiri bawah
		glVertex3f(x + 52 + (i*70), y + 30, 110);//kanan bawah
		glVertex3f(x + 52 + (i*70), y + 30, 117);//kanan atas
		glVertex3f(x + 38 + (i*70), y + 30, 117);//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
		glVertex3f(x + 38 + (i*70), y + 15, 110);//kiri bawah
		glVertex3f(x + 52 + (i*70), y + 15, 110);//kanan bawah
		glVertex3f(x + 52 + (i*70), y + 15, 117);//kanan atas
		glVertex3f(x + 38 + (i*70), y + 15, 117);//kiri atas
		glEnd();
		glBegin(GL_QUADS); //depan
		glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
		glVertex3f(x + 38 + (i*70), y + 15, 117.0);//kiri bawah
		glVertex3f(x + 38 + (i*70), y + 30, 117.0);//kiri atas
		glVertex3f(x + 52 + (i*70), y + 30, 117.0);//kanan atas
		glVertex3f(x + 52 + (i*70), y + 15, 117.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kanan
		glColor3f (0.4319607843137255 , 0.4319607843137255 , 0.4319607843137255);
		glVertex3f(x + 52 + (i*70), y + 15, 110.0);//kiri bawah
		glVertex3f(x + 52 + (i*70), y + 30, 110.0);//kiri atas
		glVertex3f(x + 52 + (i*70), y + 30, 117.0);//kanan atas
		glVertex3f(x + 52 + (i*70), y + 15, 117.0);//kanan bawah
		glEnd();
	//tengah PERTENGAHAN
	
	//kanan PERTENGAHAN
		glBegin(GL_QUADS);//kiri
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 52 + (i*70), y + 20, 110.0);//kiri bawah
		glVertex3f(x + 52 + (i*70), y + 30, 110.0);//kiri atas
		glVertex3f(x + 52 + (i*70), y + 30, 115.0);//kanan atas
		glVertex3f(x + 52 + (i*70), y + 20, 115.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 52 + (i*70), y + 30, 110);//kiri bawah
		glVertex3f(x + 60 + (i*70), y + 30, 110);//kanan bawah
		glVertex3f(x + 60 + (i*70), y + 30, 115);//kanan atas
		glVertex3f(x + 52 + (i*70), y + 30, 115);//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 60 + (i*70), y + 20, 110);//kiri bawah
		glVertex3f(x + 60 + (i*70), y + 20, 110);//kanan bawah
		glVertex3f(x + 60 + (i*70), y + 20, 115);//kanan atas
		glVertex3f(x + 60 + (i*70), y + 20, 115);//kiri atas
		glEnd();
		glBegin(GL_QUADS); //depan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 52 + (i*70), y + 20, 115.0);//kiri bawah
		glVertex3f(x + 52 + (i*70), y + 30, 115.0);//kiri atas
		glVertex3f(x + 60 + (i*70), y + 30, 115.0);//kanan atas
		glVertex3f(x + 60 + (i*70), y + 20, 115.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kanan
		glColor3f (0.4519607843137255 , 0.4519607843137255 , 0.4519607843137255);
		glVertex3f(x + 60 + (i*70), y + 20, 110.0);//kiri bawah
		glVertex3f(x + 60 + (i*70), y + 30, 110.0);//kiri atas
		glVertex3f(x + 60 + (i*70), y + 30, 115.0);//kanan atas
		glVertex3f(x + 60 + (i*70), y + 20, 115.0);//kanan bawah
		glEnd();
	//kanan PERTENGAHAN
	}
}





void DindingSisiKanan(){
	//--------------pengantara alas & dinding-------------- (kiri)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-710.0, -40.0, 115.0);//kiri bawah
	glVertex3f(-710.0, -35.0, 115.0);//kiri atas
	glVertex3f(-710.0, -35.0, 90.0);//kanan atas
	glVertex3f(-710.0, -40.0, 90.0);//kanan bawah
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (depan)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-710.0, -40.0, 115); //kiri bawah
	glVertex3f(-710.0, -35.0, 115);//kiri atas
	glVertex3f(-390.0, -35.0, 115);//kanan atas
	glVertex3f(-390.0, -40.0, 115);//kanan bawah
	glEnd();
	
	///--------------pengantara alas & dinding-------------- (atas)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-710.0, -35.0, 90);//kiri bawah
	glVertex3f(-390.0, -35, 90);//kanan bawah
	glVertex3f(-390.0, -35.0, 115);//kanan atas
	glVertex3f(-710.0, -35.0, 115);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (lengkungan Depan)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-390.0, -40.0, 115); //kiri bawah
	glVertex3f(-390.0, -35.0, 115);//kiri atas
	glVertex3f(-370.0, -35.0, 95);//kanan atas
	glVertex3f(-370.0, -40.0, 95);//kanan bawah
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (lengkungan Atas)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-390.0, -35.0, 90);//kiri bawah
	glVertex3f(-370.0, -35, 90);//kanan bawah
	glVertex3f(-370.0, -35.0, 95);//kanan atas
	glVertex3f(-390.0, -35.0, 115);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (Kanan Akhir depan)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-370.0, -40.0, 95); //kiri bawah
	glVertex3f(-370.0, -35.0, 95);//kiri atas
	glVertex3f(-365.0, -35.0, 95);//kanan atas
	glVertex3f(-365.0, -40.0, 95);//kanan bawah
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (Kanan Akhir Atas)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-370.0, -35.0, 90);//kiri bawah
	glVertex3f(-365.0, -35, 90);//kanan bawah
	glVertex3f(-365.0, -35.0, 95);//kanan atas
	glVertex3f(-370.0, -35.0, 95);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (Kanan Akhir Atas)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-370.0, -40.0, 90);//kiri bawah
	glVertex3f(-365.0, -40, 90);//kanan bawah
	glVertex3f(-365.0, -40.0, 95);//kanan atas
	glVertex3f(-370.0, -40.0, 95);//kiri atas
	glEnd();
	
	//--------------sebelah kanannya pintu masuk--------------
	glBegin(GL_QUADS);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-707.0, -70.0, 110.0);//kiri bawah
	glVertex3f(-707.0, -40.0, 110.0);//kiri atas
	glVertex3f(-707.0, -40.0, 90.0);//kanan atas
	glVertex3f(-707.0, -70.0, 90.0);//kanan bawah
	glEnd();
	
	//--------------tembok alas--------------
	glBegin(GL_QUADS);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-707.0, -70.0, 110.0);//kiri bawah
	glVertex3f(-707.0, -40.0, 110.0);//kiri atas
	glVertex3f(-390, -40.0, 110.0);//kanan atas
	glVertex3f(-390, -70.0, 110.0);//kanan bawah
	glEnd();
	
	//--------------Bagian Atas  dinding alas-------------
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-707.0, -40.0, 90);//kiri bawah
	glVertex3f(-390.0, -40, 90);//kanan bawah
	glVertex3f(-390.0, -40.0, 115);//kanan atas
	glVertex3f(-707.0, -40.0, 115);//kiri atas
	glEnd();
	
	//--------------lengkungan pintu--------------
	glBegin(GL_QUADS); //utama kanan
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-390, -70.0, 110.0);//kiri bawah
	glVertex3f(-390, -40.0, 110.0);//kiri atas
	glVertex3f(-370, -40.0, 90.0);//kanan atas
	glVertex3f(-370, -70.0, 90.0);//kanan bawah
	glEnd();
	
	glBegin(GL_QUADS); //utama kanan akhir
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-370, -70.0, 90.0);//kiri bawah
	glVertex3f(-370, -40.0, 90.0);//kiri atas
	glVertex3f(-365, -40.0, 90.0);//kanan atas
	glVertex3f(-365, -70.0, 90.0);//kanan bawah
	glEnd();
	
	//DindingPembatas(posisi x, posisi y, banyak pembatas, banyak pembatasTengah) --- z nya bakalan sama jadi ga usah masuk parameter
	DindingPembatasSisiKanan(-700, -70, 5, 4);
	//DindingPembatasSisiKanan(160, -70, 2, 1);
	//=========================================================================================================================================================================	

}




void dindingorensebelahKANAN(){
	//--------------sebelah kanannya pintu masuk tapi yang orennya--------------
	glBegin(GL_QUADS);
	glColor3f (1.0 , 0.5490196078431373 , 0.0);
	glVertex3f(-705.0, -35.0, 105.0);//kiri bawah
	glVertex3f(-705.0, 80.0, 105.0);//kiri atas
	glVertex3f(-705.0, 80.0, 90.0);//kanan atas
	glVertex3f(-705.0, -35.0, 90.0);//kanan bawah
	glEnd();
	
	//--------------depan kiri nya jendela pertama dinding oren--------------
	for (i=0 ; i<4 ;i++){
	glBegin(GL_QUADS);
	glColor3f (1.0 , 0.5490196078431373 , 0.0);
	glVertex3f(-705.0 + ( i * 70),-40.0, 105); //kiri bawah
	glVertex3f(-705.0 + ( i * 70), 80.0, 105);//kiri atas
	glVertex3f(-675.0 + ( i * 70), 80.0, 105);//kanan atas
	glVertex3f(-675.0 + ( i * 70), -40.0, 105);//kanan bawah
	glEnd();
	}

	for (i=0 ; i<3 ;i++){
	//--------------depan kanan nya jendela pertama dinding oren--------------
	glBegin(GL_QUADS);
	glColor3f (1.0 , 0.5490196078431373 , 0.0);
	glVertex3f(-635.0 + ( i * 70),-40.0, 105); //kiri bawah
	glVertex3f(-635.0 + ( i * 70), 80.0, 105);//kiri atas
	glVertex3f(-615.0 + ( i * 70), 80.0, 105);//kanan atas
	glVertex3f(-615.0 + ( i * 70), -40.0, 105);//kanan bawah
	glEnd();
	}	
	
	//--------------paling kanan jendela terakhir dinding oren sebelum lengkungan--------------
	glBegin(GL_QUADS);
	glColor3f (1.0 , 0.5490196078431373 , 0.0);
	glVertex3f(-425.0 ,-40.0, 105); //kiri bawah
	glVertex3f(-425.0 , 80.0, 105);//kiri atas
	glVertex3f(-390.0 , 80.0, 105);//kanan atas
	glVertex3f(-390.0 , -40.0, 105);//kanan bawah
	glEnd();
	
	//--------------paling kanan jendela terakhir dinding oren lengkungan--------------
	glBegin(GL_QUADS);
	glColor3f (1.0 , 0.5490196078431373 , 0.0);
	glVertex3f(-390.0 ,-40.0, 105); //kiri bawah
	glVertex3f(-390.0 , 80.0, 105);//kiri atas
	glVertex3f(-370.0 , 80.0, 90);//kanan atas
	glVertex3f(-370.0 , -40.0, 90);//kanan bawah
	glEnd();
	
	//--------------paling kanan jendela terakhir dinding oren setelah lengkungan--------------
	glBegin(GL_QUADS);
	glColor3f (1.0 , 0.5490196078431373 , 0.0);
	glVertex3f(-370.0 , -40.0, 90); //kiri bawah
	glVertex3f(-370.0 , 80.0, 90);//kiri atas
	glVertex3f(-365.0 , 80.0, 90);//kanan atas
	glVertex3f(-365.0 , -40.0, 90);//kanan bawah
	glEnd();
	
	
//-----------------atas nya jendela dinding oren-----------------------------------------------
	for (i=0 ; i<4 ;i++){
	glBegin(GL_QUADS);
	glColor3f (1.0 , 0.5490196078431373 , 0.0);
	glVertex3f(-675.0 + ( i * 70), 50.0, 105); //kiri bawah
	glVertex3f(-675.0 + ( i * 70), 80.0, 105);//kiri atas
	glVertex3f(-635.0 + ( i * 70), 80.0, 105);//kanan atas
	glVertex3f(-635.0 + ( i * 70), 50.0, 105);//kanan bawah
	glEnd();
	}
	
}





void sambungandindingorendanputih(){
	//--------------level1-------------	
		for (i=0;i<3;i++){
			glBegin(GL_QUADS);//bawah
			glColor3f(0.81, 0.81, 0.81);
			glVertex3f(-710.0 - (i*5), 80.0 + (i*5), 90);//kiri bawah
			glVertex3f(-375.0 + (i*5), 80.0 + (i*5), 90);//kanan bawah
			glVertex3f(-375.0 + (i*5), 80.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-710.0 - (i*5), 80.0 + (i*5), 115 + (i*5));//kiri atas
			glEnd();
		
			glBegin(GL_QUADS);//atas
			glColor3f(0.81, 0.81, 0.81);
			glVertex3f(-710.0 - (i*5), 85.0 + (i*5), 90);//kiri bawah
			glVertex3f(-375.0 + (i*5), 85.0 + (i*5), 90);//kanan bawah
			glVertex3f(-375.0 + (i*5), 85.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-710.0 - (i*5), 85.0 + (i*5), 115 + (i*5));//kiri atas
			glEnd();
		
			glBegin(GL_QUADS);//kiri
			glColor3f(1,1,1);
			glVertex3f(-710.0 - (i*5), 80.0 + (i*5), 90); //kiri bawah
			glVertex3f(-710.0 - (i*5), 85.0 + (i*5), 90);//kiri atas
			glVertex3f(-710.0 - (i*5), 85.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-710.0 - (i*5), 80.0 + (i*5), 115 + (i*5));//kanan bawah
			glEnd();
		
			glBegin(GL_QUADS);//kanan
			glColor3f(1,1,1);
			glVertex3f(-375.0 + (i*5), 80.0 + (i*5), 90); //kiri bawah
			glVertex3f(-375.0 + (i*5), 85.0 + (i*5), 90);//kiri atas
			glVertex3f(-375.0 + (i*5), 85.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-375.0 + (i*5), 80.0 + (i*5), 115 + (i*5));//kanan bawah
			glEnd();
		
			glBegin(GL_QUADS);
			glColor3f(1,1,1); //depan
			glVertex3f(-710.0 - (i*5), 80.0 + (i*5), 115 + (i*5)); //kiri bawah
			glVertex3f(-710.0 - (i*5), 85.0 + (i*5), 115 + (i*5));//kiri atas
			glVertex3f(-375.0 + (i*5), 85.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-375.0 + (i*5), 80.0 + (i*5), 115 + (i*5));//kanan bawah
			glEnd();
			}
}





void dindingkananputih(){
	
	for (i=0 ; i<4 ; i++){
	//--------------sebelah kanannya pintu masuk tapi yang Putihnya--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-705.0 + (i*80), 95.0, 105.0);//kiri bawah
	glVertex3f(-705.0 + (i*80), 210.0, 105.0);//kiri atas
	glVertex3f(-705.0 + (i*80), 210.0, 90.0);//kanan atas
	glVertex3f(-705.0 + (i*80), 95.0, 90.0);//kanan bawah
	glEnd();

	//--------------depan kiri nya jendela pertama dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-705.0 + (i*80), 95.0, 105); //kiri bawah
	glVertex3f(-705.0 + (i*80), 210.0, 105);//kiri atas
	glVertex3f(-690.0 + (i*80), 210.0, 105);//kanan atas
	glVertex3f(-690.0 + (i*80), 95.0, 105);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kiri jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-673.0 + (i*80) , 95.0, 105); //kiri bawah
	glVertex3f(-673.0 + (i*80) , 210.0, 105);//kiri atas
	glVertex3f(-671.0 + (i*80) , 210.0, 105);//kanan atas
	glVertex3f(-671.0 + (i*80) , 95.0, 105);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kanan jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-649.0 + (i*80) , 95.0, 105); //kiri bawah
	glVertex3f(-649.0 + (i*80) , 210.0, 105);//kiri atas
	glVertex3f(-647.0 + (i*80) , 210.0, 105);//kanan atas
	glVertex3f(-647.0 + (i*80) , 95.0, 105);//kanan bawah
	glEnd();
		
	//--------------atas nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-690.0 + (i*80) , 195.0, 105); //kiri bawah
	glVertex3f(-690.0 + (i*80) , 210.0, 105);//kiri atas
	glVertex3f(-630.0 + (i*80) , 210.0, 105);//kanan atas
	glVertex3f(-630.0 + (i*80) , 195.0, 105);//kanan bawah
	glEnd();
		
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-690.0 + (i*80) , 95.0, 105); //kiri bawah
	glVertex3f(-690.0 + (i*80) , 110.0, 105);//kiri atas
	glVertex3f(-630.0 + (i*80) , 110.0, 105);//kanan atas
	glVertex3f(-630.0 + (i*80) , 95.0, 105);//kanan bawah
	glEnd();	
	}
	
	//--------------depan kanan nya jendela ketiga dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-630.0 , 95.0, 105); //kiri bawah
	glVertex3f(-630.0 , 210.0, 105);//kiri atas
	glVertex3f(-610.0 , 210.0, 105);//kanan atas
	glVertex3f(-610.0 , 95.0, 105);//kanan bawah
	glEnd();
	
//-------------------------------------------------------------------------------------------------------	
	
	for (i=0 ; i<3 ; i++){
	//--------------sebelah kanannya pintu masuk tapi yang Putihnya--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-625.0 , 95.0 + (i*115), 105.0);//kiri bawah
	glVertex3f(-625.0 , 210.0 + (i*115), 105.0);//kiri atas
	glVertex3f(-625.0 , 210.0 + (i*115), 90.0);//kanan atas
	glVertex3f(-625.0 , 95.0 + (i*115), 90.0);//kanan bawah
	glEnd();

	//--------------depan kiri nya jendela pertama dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-625.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-625.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-610.0 , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-610.0 , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kiri jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-593.0  , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-593.0  , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-591.0  , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-591.0  , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kanan jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-569.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-569.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-567.0 , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-567.0 , 95.0 + (i*115), 105);//kanan bawah
	glEnd();
		
	
	//--------------depan kanan nya jendela ketiga dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-550.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-550.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-530.0 , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-530.0 , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
		
		
	//--------------atas nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-610.0 , 195.0 + (i*115), 105); //kiri bawah
	glVertex3f(-610.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-550.0 , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-550.0 , 195.0 + (i*115), 105);//kanan bawah
	glEnd();
		
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-610.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-610.0 , 110.0 + (i*115), 105);//kiri atas
	glVertex3f(-550.0 , 110.0 + (i*115), 105);//kanan atas
	glVertex3f(-550.0 , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	}
	
	
//-------------------------------------------------------------------------------------------------------	
	
	for (i=0 ; i<3 ; i++){
	//--------------sebelah kanannya pintu masuk tapi yang Putihnya--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-545.0 , 95.0 + (i*115), 105.0);//kiri bawah
	glVertex3f(-545.0 , 210.0 + (i*115), 105.0);//kiri atas
	glVertex3f(-545.0 , 210.0 + (i*115), 90.0);//kanan atas
	glVertex3f(-545.0 , 95.0 + (i*115), 90.0);//kanan bawah
	glEnd();

	//--------------depan kiri nya jendela pertama dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-545.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-545.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-530.0 , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-530.0 , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kiri jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-513.0  , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-513.0  , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-511.0  , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-511.0  , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kanan jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-489.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-489.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-487.0 , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-487.0 , 95.0 + (i*115), 105);//kanan bawah
	glEnd();
		
	
	//--------------depan kanan nya jendela ketiga dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-470.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-470.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-470.0 , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-470.0 , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
		
		
	//--------------atas nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-530.0 , 195.0 + (i*115), 105); //kiri bawah
	glVertex3f(-530.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-470.0 , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-470.0 , 195.0 + (i*115), 105);//kanan bawah
	glEnd();
		
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-530.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-530.0 , 110.0 + (i*115), 105);//kiri atas
	glVertex3f(-470.0 , 110.0 + (i*115), 105);//kanan atas
	glVertex3f(-470.0 , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	}
	
//-------------------------------------------------------------------------------------------------------	
	
	for (i=0 ; i<3 ; i++){
	//--------------sebelah kanannya pintu masuk tapi yang Putihnya--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-470.0 , 95.0 + (i*115), 105.0);//kiri bawah
	glVertex3f(-470.0 , 210.0 + (i*115), 105.0);//kiri atas
	glVertex3f(-470.0 , 210.0 + (i*115), 90.0);//kanan atas
	glVertex3f(-470.0 , 95.0 + (i*115), 90.0);//kanan bawah
	glEnd();

	//--------------depan kiri nya jendela pertama dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-470.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-470.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-450.0 , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-450.0 , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kiri jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-433.0  , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-433.0  , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-431.0  , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-431.0  , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kanan jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-409.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-409.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-407.0 , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-407.0 , 95.0 + (i*115), 105);//kanan bawah
	glEnd();
		
	
	//--------------depan kanan nya jendela ketiga dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-390.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-390.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-370.0 , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-370.0 , 95.0 + (i*115), 90);//kanan bawah
	glEnd();	
		
		
	//--------------atas nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-450.0 , 195.0 + (i*115), 105); //kiri bawah
	glVertex3f(-450.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-390.0 , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-390.0 , 195.0 + (i*115), 105);//kanan bawah
	glEnd();
		
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-450.0 , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-450.0 , 110.0 + (i*115), 105);//kiri atas
	glVertex3f(-390.0 , 110.0 + (i*115), 105);//kanan atas
	glVertex3f(-390.0 , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	}
}





void pintumasuksamping(){
	glBegin(GL_QUADS);//depan
		glColor3f (1.0 , 0.5490196078431373 , 0.0);
		glVertex3f(-363.0, -50.0, 110); //kiri bawah
		glVertex3f(-363.0, 50.0, 110);//kiri atas
		glVertex3f(-335.0, 50.0, 110);//kanan atas
		glVertex3f(-335.0 , -50.0, 110);//kanan bawah
		glEnd();
	//--------------KAKI ABU ABU kiri-------------- 
		
		for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS); //kiri
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-365.0 + ( i * 100) , -70.0, 110.0);//kiri bawah
		glVertex3f(-365.0 + ( i * 100) , -50.0, 110.0);//kiri atas
		glVertex3f(-365.0 + ( i * 100) , -50.0, 80.0);//kanan atas
		glVertex3f(-365.0 + ( i * 100) , -70.0, 80.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS); //kanan
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-335.0 + ( i * 100) , -70.0, 110.0);//kiri bawah
		glVertex3f(-335.0 + ( i * 100) , -50.0, 110.0);//kiri atas
		glVertex3f(-335.0 + ( i * 100) , -50.0, 80.0);//kanan atas
		glVertex3f(-335.0 + ( i * 100) , -70.0, 80.0);//kanan bawah
		glEnd();
	
		glBegin(GL_QUADS);//depan
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-365.0 + ( i * 100) , -70.0, 110); //kiri bawah
		glVertex3f(-365.0 + ( i * 100) , -50.0, 110);//kiri atas
		glVertex3f(-335.0 + ( i * 100) , -50.0, 110);//kanan atas
		glVertex3f(-335.0 + ( i * 100) , -70.0, 110);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-365.0 + ( i * 100) , -70.0, 80); //kiri bawah
		glVertex3f(-365.0 + ( i * 100) , -50.0, 80);//kiri atas
		glVertex3f(-335.0 + ( i * 100) , -50.0, 80);//kanan atas
		glVertex3f(-335.0 + ( i * 100) , -70.0, 80);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-365.0 + ( i * 100) , -50.0, 80);//kiri bawah
		glVertex3f(-335.0 + ( i * 100) , -50.0, 80);//kanan bawah
		glVertex3f(-335.0 + ( i * 100) , -50.0, 110);//kanan atas
		glVertex3f(-365.0 + ( i * 100) , -50.0, 110);//kiri atas
		glEnd();
		}
		
	//--------------Gardu kiri-------------- 
		for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS); //kiri
		glColor3f (1.0 , 0.5490196078431373 , 0.0);
		glVertex3f(-363.0 + ( i * 100) , -50.0, 110.0);//kiri bawah
		glVertex3f(-363.0 + ( i * 100) , 50.0, 110.0);//kiri atas
		glVertex3f(-363.0 + ( i * 100) , 50.0, 80.0);//kanan atas
		glVertex3f(-363.0 + ( i * 100) , -50.0, 80.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS); //kanan
		glColor3f (1.0 , 0.5490196078431373 , 0.0);
		glVertex3f(-335.0 + ( i * 100) , -50.0, 110.0);//kiri bawah
		glVertex3f(-335.0 + ( i * 100) , 50.0, 110.0);//kiri atas
		glVertex3f(-335.0 + ( i * 100) , 50.0, 80.0);//kanan atas
		glVertex3f(-335.0 + ( i * 100) , -50.0, 80.0);//kanan bawah
		glEnd();
	
		glBegin(GL_QUADS);//depan
		glColor3f (1.0 , 0.5490196078431373 , 0.0);
		glVertex3f(-363.0 + ( i * 100) , -50.0, 110); //kiri bawah
		glVertex3f(-363.0 + ( i * 100) , 50.0, 110);//kiri atas
		glVertex3f(-335.0 + ( i * 100) , 50.0, 110);//kanan atas
		glVertex3f(-335.0 + ( i * 100) , -50.0, 110);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (1.0 , 0.5490196078431373 , 0.0);
		glVertex3f(-363.0 + ( i * 100) , -50.0, 80); //kiri bawah
		glVertex3f(-363.0 + ( i * 100) , 50.0, 80);//kiri atas
		glVertex3f(-335.0 + ( i * 100) , 50.0, 80);//kanan atas
		glVertex3f(-335.0 + ( i * 100) , -50.0, 80);//kanan bawah
		glEnd();
	
		}
		
}






void tampil(void){
	//keyboard
	if(kbmouse){
		if(is_depth) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		else glClear(GL_COLOR_BUFFER_BIT);
	}
	
	//mouse
	else{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
		glRotatef(xrot, 1.0f, 0.0f, 0.0f);
		glRotatef(yrot, 0.0f, 1.0f, 0.0f);
		glPushMatrix();
	}

	gedungKiri();
	BatasBangunan();
	DindingSisiKanan();
	dindingorensebelahKANAN();
	sambungandindingorendanputih();
	dindingkananputih();
	pintumasuksamping();

	
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
		//zoom_in
		case 'w':
		case 'W':
			glTranslatef(0.0,0.0,3.0);
			break;
		
		//geser kiri
		case 'a':
		case 'A':
			glTranslatef(-3.0,0.0,0.0);
			break;
			
		//zoom_out
		case 's':
		case 'S':
			glTranslatef(0.0,0.0,-3.0);
			break;
			
		//geser kanan
		case 'd':
		case 'D':
			glTranslatef(3.0,0.0,0.0);
			break;
		
		//naik
		case'7':
			glTranslatef(0.0,3.0,0.0);
			break;
		
		//turun
		case'9':
			glTranslatef(0.0,-3.0,0.0);
			break;
		
		//miring depan
		case'2':
			glRotatef(2.0, 1.0, 0.0, 0.0);
			break;
		
		//miring belakang
		case'8':
			glRotatef(-2.0, 1.0, 0.0, 0.0);
			break;
		
		//miring depan kanan
		case'6':
			glRotatef(2.0, 0.0, 1.0, 0.0);
			break;
		
		//miring depan kiri
		case'4':
			glRotatef(-2.0, 0.0, 1.0, 0.0);
			break;
			
		//miring kiri
		case'1':
			glRotatef(2.0, 0.0, 0.0, 1.0);
			break;
			
		//miring kanan
		case'3':
			glRotatef(-2.0, 0.0, 0.0, 1.0);
			break;
			
		//on off gl depth
		case'5':
			if(is_depth){
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			}else{
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
			break;
		
		//switch keyboard - mouse
		case'-':
			if(kbmouse){
				kbmouse = 0;
			}else{
				kbmouse = 1;
			}
			break;
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
	glTranslatef(0.0, 0.0, -1000.0);
	//glTranslatef(500.0, 500.0, -1000.0);
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
