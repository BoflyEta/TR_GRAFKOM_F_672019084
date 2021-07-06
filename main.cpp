//Anggota Kelompok : 
//672019084	Carens Kurniawan Wijaya
//672019149	Theodore Noveiota 
//672019284	Hafid Ahsani
//672019315	Bofly Ebenhaezer Eta

#include <windows.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#define DEG2RAD 3.14159/180.0
int is_depth;
int i,j,a,b,c;

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

void objekDalam (){

    for (b=0;b<5;b++){
    for (c=0;c<3;c++){
    //Meja
    for (i=0;i<2;i++){ //horizontal
    glBegin(GL_QUADS);
    glColor3f(1.0,0.4,0.0);
    glVertex3f(0 - 500 + (b*170), -50 + (i*10), 220.0 + (c*120) - 500);
    glVertex3f(140 - 500 + (b*170), -50 + (i*10), 220.0 + (c*120) - 500);
    glVertex3f(140 - 500 + (b*170), -50 + (i*10), 250.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (b*170), -50 + (i*10), 250.0 + (c*120) - 500);
    glEnd();
    }

    for (i=0;i<2;i++){ //vertikal depan
    glBegin(GL_QUADS);
    glColor3f(1.0,0.4,0.0);
    glVertex3f(0 - 500 + (b*170), -50, 250.0 - (i*30) + (c*120) - 500);
    glVertex3f(140 - 500 + (b*170), -50, 250.0 - (i*30) + (c*120) - 500);
    glVertex3f(140 - 500 + (b*170), -40, 250.0 - (i*30) + (c*120) - 500);
    glVertex3f(0 - 500 + (b*170), -40, 250.0 - (i*30) + (c*120) - 500);
    glEnd();
    }

    for (i=0;i<2;i++){ //vertikal samping
    glBegin(GL_QUADS);
    glColor3f(1.0,0.4,0.0);
    glVertex3f(0 - 500 + (b*170), -50, 250.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (b*170), -50, 220.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (b*170), -40, 220.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (b*170), -40, 250.0 + (c*120) - 500);
    glEnd();
    }

    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
        glBegin(GL_QUADS); //kaki samping kiri
        glColor3f(1.0,0.4,0.0);
        glVertex3f(0 - 500+ (i*135) + (b*170), -50, 225.0 + (j*25) + (c*120) - 500);
        glVertex3f(0 - 500 + (i*135) + (b*170), -50, 220.0 + (j*25) + (c*120) - 500);
        glVertex3f(0 - 500 + (i*135) + (b*170), -70, 220.0 + (j*25) + (c*120) - 500);
        glVertex3f(0 - 500 + (i*135) + (b*170), -70, 225.0 + (j*25) + (c*120) - 500);
        glEnd();
        }
    }

    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
        glBegin(GL_QUADS); //kaki samping kanan
        glColor3f(1.0,0.4,0.0);
        glVertex3f(5 - 500 + (i*135) + (b*170), -50, 225.0 + (j*25) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*135) + (b*170), -50, 220.0 + (j*25) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*135) + (b*170), -70, 220.0 + (j*25) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*135) + (b*170), -70, 225.0 + (j*25) + (c*120)- 500);
        glEnd();
        }
    }

    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
        glBegin(GL_QUADS); //kaki depan
        glColor3f(1.0,0.4,0.0);
        glVertex3f(0 - 500 + (i*135) + (b*170), -50, 250.0 - (j*25) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*135) + (b*170), -50, 250.0 - (j*25) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*135) + (b*170), -70, 250.0 - (j*25) + (c*120) - 500);
        glVertex3f(0 - 500 + (i*135) + (b*170), -70, 250.0 - (j*25) + (c*120) - 500);
        glEnd();
        }
    }

    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
        glBegin(GL_QUADS); //kaki belakang
        glColor3f(1.0,0.4,0.0);
        glVertex3f(0 - 500 + (i*135) + (b*170), -50, 245.0 - (j*25) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*135) + (b*170), -50, 245.0 - (j*25) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*135) + (b*170), -70, 245.0 - (j*25) + (c*120) - 500);
        glVertex3f(0 - 500 + (i*135) + (b*170), -70, 245.0 - (j*25) + (c*120) - 500);
        glEnd();
        }
    }

    //Kursi
    for (a=0;a<5;a++){
    for (i=0;i<2;i++){ //horizontal
    glBegin(GL_QUADS);
    glColor3f(1.0,0.4,0.0);
    glVertex3f(0 - 500 + (a*30) + (b*170), -50 + (i*5), 180.0 + (c*120) - 500);
    glVertex3f(20 - 500 + (a*30) + (b*170), -50 + (i*5), 180.0 + (c*120) - 500);
    glVertex3f(20 - 500 + (a*30) + (b*170), -50 + (i*5), 200.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (a*30) + (b*170), -50 + (i*5), 200.0 + (c*120) - 500);
    glEnd();
    }

    for (i=0;i<2;i++){ //vertikal depan
    glBegin(GL_QUADS);
    glColor3f(1.0,0.4,0.0);
    glVertex3f(0 - 500 + (a*30) + (b*170), -50, 200.0 - (i*20) + (c*120) - 500);
    glVertex3f(20 - 500 + (a*30) + (b*170), -50, 200.0 - (i*20) + (c*120) - 500);
    glVertex3f(20 - 500 + (a*30) + (b*170), -45, 200.0 - (i*20) + (c*120) - 500);
    glVertex3f(0 - 500 + (a*30) + (b*170), -45, 200.0 - (i*20) + (c*120) - 500);
    glEnd();
    }

    for (i=0;i<2;i++){ //vertikal samping
    glBegin(GL_QUADS);
    glColor3f(1.0,0.4,0.0);
    glVertex3f(0 - 500 + (a*30) + (b*170), -50, 200.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (a*30) + (b*170), -50, 180.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (a*30) + (b*170), -45, 180.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (a*30) + (b*170), -45, 200.0 + (c*120) - 500);
    glEnd();
    }

    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
        glBegin(GL_QUADS); //kaki samping kiri
        glColor3f(1.0,0.4,0.0);
        glVertex3f(0 - 500 + (i*15) + (a*30) + (b*170), -50, 185.0 + (j*15) + (c*120) - 500);
        glVertex3f(0 - 500 + (i*15) + (a*30) + (b*170), -50, 180.0 + (j*15) + (c*120) - 500);
        glVertex3f(0 - 500 + (i*15) + (a*30) + (b*170), -70, 180.0 + (j*15) + (c*120) - 500);
        glVertex3f(0 - 500 + (i*15) + (a*30) + (b*170), -70, 185.0 + (j*15) + (c*120) - 500);
        glEnd();
        }
    }

    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
        glBegin(GL_QUADS); //kaki samping kanan
        glColor3f(1.0,0.4,0.0);
        glVertex3f(5 - 500 + (i*15) + (a*30) + (b*170), -50, 185.0 + (j*15) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*15) + (a*30) + (b*170), -50, 180.0 + (j*15) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*15) + (a*30) + (b*170), -70, 180.0 + (j*15) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*15) + (a*30) + (b*170), -70, 185.0 + (j*15) + (c*120) - 500);
        glEnd();
        }
    }

    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
        glBegin(GL_QUADS); //kaki depan
        glColor3f(1.0,0.4,0.0);
        glVertex3f(0 - 500 + (i*15) + (a*30) + (b*170), -50, 200.0 - (j*15) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*15) + (a*30) + (b*170), -50, 200.0 - (j*15) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*15) + (a*30) + (b*170), -70, 200.0 - (j*15) + (c*120) - 500);
        glVertex3f(0 - 500 + (i*15) + (a*30) + (b*170), -70, 200.0 - (j*15) + (c*120) - 500);
        glEnd();
        }
    }

    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
        glBegin(GL_QUADS); //kaki belakang
        glColor3f(1.0,0.4,0.0);
        glVertex3f(0 - 500 + (i*15) + (a*30) + (b*170), -50, 195.0 - (j*15) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*15) + (a*30) + (b*170), -50, 195.0 - (j*15) + (c*120) - 500);
        glVertex3f(5 - 500 + (i*15) + (a*30) + (b*170), -70, 195.0 - (j*15) + (c*120) - 500);
        glVertex3f(0 - 500 + (i*15) + (a*30) + (b*170), -70, 195.0 - (j*15) + (c*120) - 500);
        glEnd();
        }
    }

    for (i=0;i<2;i++){ //bagian atas vertikal depan
    glBegin(GL_QUADS);
    glColor3f(1.0,0.4,0.0);
    glVertex3f(0 - 500 + (a*30) + (b*170), -25, 180.0 + (i*5) + (c*120) - 500);
    glVertex3f(20 - 500 + (a*30) + (b*170), -25, 180.0 + (i*5) + (c*120) - 500);
    glVertex3f(20 - 500 + (a*30) + (b*170), -45, 180.0 + (i*5) + (c*120) - 500);
    glVertex3f(0 - 500 + (a*30) + (b*170), -45, 180.0 + (i*5) + (c*120) - 500);
    glEnd();
    }

    glBegin(GL_QUADS); //bagian atas horizontal
    glColor3f(1.0,0.4,0.0);
    glVertex3f(20 - 500 + (a*30) + (b*170), -25, 185.0 + (c*120) - 500);
    glVertex3f(20 - 500 + (a*30) + (b*170), -25, 180.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (a*30) + (b*170), -25, 180.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (a*30) + (b*170), -25, 185.0 + (c*120) - 500);
    glEnd();

    for (i=0;i<2;i++){ //bagian atas vertikal samping
    glBegin(GL_QUADS);
    glColor3f(1.0,0.4,0.0);
    glVertex3f(0 - 500 + (i*20) + (a*30) + (b*170), -25, 180.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (i*20) + (a*30) + (b*170), -25, 185.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (i*20) + (a*30) + (b*170), -45, 185.0 + (c*120) - 500);
    glVertex3f(0 - 500 + (i*20) + (a*30) + (b*170), -45, 180.0 + (c*120) - 500);
    glEnd();
    }
    }
    }
    }

}

void gedungBelakang1( int x = 860 ){
    glBegin(GL_POLYGON);
    glColor3f (0.81, 0.81, 0.81);
    glVertex3f(500, -70, -250.0);
    glVertex3f(500, 440, -250.0);
    glVertex3f(500, 440, 10.0);
    glVertex3f(500, -70, 10.0);
    glEnd();

    //BELAKANG
    glBegin(GL_QUADS);
    for (i=0 ; i<3 ; i++){
	//--------------depan kiri nya jendela pertama dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-448.0 + x, 95.0 + (i*115), 90 - 340); //kiri bawah
	glVertex3f(-448.0 + x, 210.0 + (i*115), 90 - 340);//kiri atas
	glVertex3f(-345.0 + x, 210.0 + (i*115), 90 - 340);//kanan atas
	glVertex3f(-345.0 + x, 95.0 + (i*115), 90 - 340);//kanan bawah
	glEnd();


	//--------------tengah kiri jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-320.0  + x, 95.0 + (i*115), 90 - 340); //kiri bawah
	glVertex3f(-320.0  + x, 210.0 + (i*115), 90 - 340);//kiri atas
	glVertex3f(-315.0  + x, 210.0 + (i*115), 90 - 340);//kanan atas
	glVertex3f(-315.0  + x, 95.0 + (i*115), 90 - 340);//kanan bawah
	glEnd();


	//--------------tengah kanan jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-275.0 + x, 95.0 + (i*115), 90 - 340); //kiri bawah
	glVertex3f(-275.0 + x, 210.0 + (i*115), 90 - 340);//kiri atas
	glVertex3f(-265.0 + x, 210.0 + (i*115), 90 - 340);//kanan atas
	glVertex3f(-270.0 + x, 95.0 + (i*115), 90 - 340);//kanan bawah
	glEnd();


	//--------------atas nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-345.0 + x, 195.0 + (i*115), 90 - 340); //kiri bawah
	glVertex3f(-345.0 + x, 210.0 + (i*115), 90 - 340);//kiri atas
	glVertex3f(-220.0 + x, 210.0 + (i*115), 90 - 340);//kanan atas
	glVertex3f(-220.0 + x, 195.0 + (i*115), 90 - 340);//kanan bawah
	glEnd();

	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-345.0 + x, 87.0 + (i*115), 90 - 340); //kiri bawah
	glVertex3f(-345.0 + x, 110.0 + (i*115), 90 - 340);//kiri atas
	glVertex3f(-220.0 + x, 110.0 + (i*115), 90 - 340);//kanan atas
	glVertex3f(-220.0 + x, 87.0 + (i*115), 90 - 340);//kanan bawah
	glEnd();

	//--------------paling kanan terakhir setelah jendela ketiga dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-245.0 + x, 95.0 + (i*115), 90 - 325); //kiri bawah
	glVertex3f(-245.0 + x, 210.0 + (i*115), 90 - 325);//kiri atas
	glVertex3f(-220.0 + x, 210.0 + (i*115), 90 - 325);//kanan atas
	glVertex3f(-220.0 + x, 95.0 + (i*115), 90 - 325);//kanan bawah
	glEnd();
	}
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS); //TAMBAHAN MUNGIL
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-448.0 + x, 80.0, 90 - 325); //kiri bawah
	glVertex3f(-448.0 + x, 95.0, 90 - 325);//kiri atas
	glVertex3f(-220.0 + x, 95.0, 90 - 325);//kanan atas
	glVertex3f(-220.0 + x, 80.0, 90 - 325);//kanan bawah
	glEnd();

    glBegin(GL_QUADS);
    glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667); //atas
    glVertex3f(500.0 , 440.0 , 9.9); //kiri bawah
    glVertex3f(500.0 , 440.0 , -255);//kiri atas
    glVertex3f(640.0 , 440.0 , -255);//kanan atas
    glVertex3f(640.0 , 440.0 , 9.9);//kanan bawah
    glEnd();

    glBegin(GL_QUADS);
    glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667); //bawah
    glVertex3f(500.0 , 80.0 , 9.9); //kiri bawah
    glVertex3f(500.0 , 80.0 , -250);//kiri atas
    glVertex3f(640.0 , 80.0 , -250);//kanan atas
    glVertex3f(640.0 , 80.0 , 9.9);//kanan bawah
    glEnd();

    glBegin(GL_QUADS);
    glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667); //bawah
    glVertex3f(640.0 , 80.0 , 9.9); //kiri bawah
    glVertex3f(640.0 , 80.0 , -250);//kiri atas
    glVertex3f(640.0 , 445.0 , -250);//kanan atas
    glVertex3f(640.0 , 445.0 , 9.9);//kanan bawah
    glEnd();


    // TEMBOK PUTIH
    glBegin(GL_QUADS); //kiri
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-661.0 + ( i * 100) + x, 50.0, 80.0 - 250);//kiri bawah
		glVertex3f(-661.0 + ( i * 100) + x, -70.0, 80.0 - 250);//kiri atas
		glVertex3f(-661.0 + ( i * 100) + x, -70.0, 4.0 - 250);//kanan atas
		glVertex3f(-661.0 + ( i * 100) + x, 50.0, 4.0 - 250);//kanan bawah
		glEnd();

    for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS); //kiri
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 80.0 - 250);//kiri bawah
		glVertex3f(-344.0 + ( i * 100) + x, -70.0, 80.0 - 250);//kiri atas
		glVertex3f(-344.0 + ( i * 100) + x, -70.0, 20.0 - 250);//kanan atas
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 20.0 - 250);//kanan bawah
		glEnd();

		glBegin(GL_QUADS); //kanan
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 30.0);//kiri bawah
		glVertex3f(-344.0 + ( i * 100) + x, -70.0, 30.0);//kiri atas
		glVertex3f(-344.0 + ( i * 100) + x, -70.0, 10.0 - 250);//kanan atas
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 10.0 - 250);//kanan bawah
		glEnd();

		glBegin(GL_QUADS); //atas
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 80.0 - 250);//kiri bawah
		glVertex3f(-344.0 + ( i * 100) + x, 25.0, 80.0 - 250);//kiri atas
		glVertex3f(-344.0 + ( i * 100) + x, 25.0, 10.0 - 250);//kanan atas
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 10.0 - 250);//kanan bawah
		glEnd();

		}

		glBegin(GL_QUADS);//tengah atap
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 + x, 49.9, 10 - 250); //kiri bawah
		glVertex3f(-244.0 + x, 49.9, 10 - 250);//kanan atas
		glVertex3f(-244.0 + x, 49.9, 80 - 250);//kanan bawah
		glVertex3f(-344.0 + x, 49.9, 80 - 250);//kiri atas
		glEnd();

		// ATAP GARDU
		glBegin(GL_QUADS);//atap gardu (alas)
			glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-365.0 + x, 50.0, 10 - 250); //kiri bawah
		glVertex3f(-218.0 + x, 50.0, 10 - 250);//kanan atas
		glVertex3f(-218.0 + x, 50.0, 95 - 250);//kanan bawah
		glVertex3f(-365.0 + x, 50.0, 95 - 250);//kiri atas
		glEnd();

		glBegin(GL_QUADS);//atap gardu (atas)
			glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0 + x, 80.0, 10 - 250); //kiri bawah
		glVertex3f(-218.0 + x, 80.0, 10 - 250);//kanan atas
		glVertex3f(-218.0 + x, 80.0, 95 - 250);//kanan bawah
		glVertex3f(-370.0 + x, 80.0, 95 - 250);//kiri atas
		glEnd();

		glBegin(GL_QUADS);//atap gardu (depan)
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0 + x, 50.0, 95 - 250); //kiri bawah
		glVertex3f(-370.0 + x, 80.0, 95 - 250);//kiri atas
		glVertex3f(-218.0 + x, 80.0, 95 - 250);//kanan atas
		glVertex3f(-218.0 + x, 50.0, 95 - 250);//kanan bawah
		glEnd();

		glBegin(GL_QUADS);//atap gardu (belakang)
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0 + x, 50.0, 10 - 250); //kiri bawah
		glVertex3f(-370.0 + x, 80.0, 10 - 250);//kiri atas
		glVertex3f(-218.0 + x, 80.0, 10 - 250);//kanan atas
		glVertex3f(-218.0 + x, 50.0, 10 - 250);//kanan bawah
		glEnd();

		for (i=0;i<2;i++){
		glBegin(GL_QUADS); //atap gardu (kiri kanan)
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0 + ( i * 152) + x, 50.0, 95.0);//kiri bawah
		glVertex3f(-370.0 + ( i * 152) + x, 80.0, 95.0);//kiri atas
		glVertex3f(-370.0 + ( i * 152) + x, 80.0, 10.0 - 250);//kanan atas
		glVertex3f(-370.0 + ( i * 152) + x, 50.0, 10.0 - 250);//kanan bawah
		glEnd();
		}

		//GARDU
		for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS); //kiri
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-358.0 + ( i * 100) + x, -50.0, 110.0 - 325);//kiri bawah
		glVertex3f(-358.0 + ( i * 100) + x, 50.0, 110.0 - 325);//kiri atas
		glVertex3f(-358.0 + ( i * 100) + x, 50.0, 80.0 - 325);//kanan atas
		glVertex3f(-358.0 + ( i * 100) + x, -50.0, 80.0 - 325);//kanan bawah
		glEnd();

		glBegin(GL_QUADS); //kanan
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 110.0 - 325);//kiri bawah
		glVertex3f(-330.0 + ( i * 100) + x, 50.0, 110.0 - 325);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, 50.0, 80.0 - 325);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 80.0 - 325);//kanan bawah
		glEnd();

		glBegin(GL_QUADS);//depan
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-358.0 + ( i * 100) + x, -50.0, 110 - 325); //kiri bawah
		glVertex3f(-358.0 + ( i * 100) + x, 50.0, 110 - 325);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, 50.0, 110 - 325);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 110 - 325);//kanan bawah
		glEnd();

		glBegin(GL_QUADS);//belakang
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-358.0 + ( i * 100) + x, -50.0, 80 - 325); //kiri bawah
		glVertex3f(-358.0 + ( i * 100) + x, 50.0, 80 - 325);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, 50.0, 80 - 325);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 80 - 325);//kanan bawah
		glEnd();
		}

		//ABU - ABU
		for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS); //kiri
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) + x, -70.0, 110.0 - 325);//kiri bawah
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 110.0 - 325);//kiri atas
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 80.0 - 325);//kanan atas
		glVertex3f(-360.0 + ( i * 100) + x, -70.0, 80.0 - 325);//kanan bawah
		glEnd();

		glBegin(GL_QUADS); //kanan
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-330.0 + ( i * 100) + x, -70.0, 110.0 - 325);//kiri bawah
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 110.0 - 325);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 80.0 - 325);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -70.0, 80.0 - 325);//kanan bawah
		glEnd();

		glBegin(GL_QUADS);//depan
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) + x, -70.0, 110 - 325); //kiri bawah
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 110 - 325);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 110 - 325);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -70.0, 110 - 325);//kanan bawah
		glEnd();

		glBegin(GL_QUADS);//belakang
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) + x, -70.0, 80 - 325); //kiri bawah
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 80 - 325);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 80 - 325);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -70.0, 80 - 325);//kanan bawah
		glEnd();

		glBegin(GL_QUADS);//atas
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 80 - 325);//kiri bawah
		glVertex3f(-330.0 + ( i * 100) + x , -50.0, 80 - 325);//kanan bawah
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 110 - 325);//kanan atas
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 110 - 325);//kiri atas
		glEnd();
		}

		// ATAS GARDU
		for (i=0;i<2;i++){
		glBegin(GL_QUADS);//bawah
		glColor3f(0.81, 0.81, 0.81);
		glVertex3f(-361.0 - (i*5) + x, 50.1 + (i*10), 95 - 365); //kiri bawah
		glVertex3f(-227.0 + (i*5) + x, 50.1 + (i*10), 95 - 365);//kanan atas
		glVertex3f(-227.0 + (i*5) + x, 50.1 + (i*10), 120 + (i*5) - 365);//kanan bawah
		glVertex3f(-361.0 - (i*5) + x, 50.1 + (i*10), 120 + (i*5) - 365);//kiri atas
		glEnd();

		glBegin(GL_QUADS);//atas
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-361.0 - (i*5) + x, 60.0 + (i*10), 95 - 375); //kiri bawah
		glVertex3f(-227.0 + (i*5) + x, 60.0 + (i*10), 95 - 375);//kanan atas
		glVertex3f(-227.0 + (i*5) + x, 60.0 + (i*10), 120 + (i*5) - 365);//kanan bawah
		glVertex3f(-361.0 - (i*5) + x, 60.0 + (i*10), 120 + (i*5) - 365);//kiri atas
		glEnd();

		glBegin(GL_QUADS);//kiri
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-361.0 - (i*5) + x, 60.0 + (i*10), 120.0 - (i*5) - 365);//kiri bawah
		glVertex3f(-361.0 - (i*5) + x, 50.0 + (i*10), 120.0 - (i*5) - 365);//kiri atas
		glVertex3f(-361.0 - (i*5) + x, 50.0 + (i*10), 95.0 - 365);//kanan atas
		glVertex3f(-361.0 - (i*5) + x, 60.0 + (i*10), 95.0 - 365);//kanan bawah
		glEnd();

		glBegin(GL_QUADS);//kanan
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-227 + (i*5) + x, 60.0 + (i*10), 120.0 + (i*5) - 365);//kiri bawah
		glVertex3f(-227 + (i*5) + x, 50.0 + (i*10), 120.0 + (i*5) - 365);//kiri atas
		glVertex3f(-227 + (i*5) + x, 50.0 + (i*10), 95.0 - 365);//kanan atas
		glVertex3f(-227 + (i*5) + x, 60.0 + (i*10), 95.0 - 365);//kanan bawah
		glEnd();


		glBegin(GL_QUADS);//depan
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-361.0 - (i*5) + x, 50.0 + (i*10), 120 + (i*5) - 390); //kiri bawah
		glVertex3f(-361.0 - (i*5) + x, 60.0 + (i*10), 120 + (i*5) - 390);//kiri atas
		glVertex3f(-227.0 + (i*5) + x, 60.0 + (i*10), 120 + (i*5) - 390);//kanan atas
		glVertex3f(-227.0 + (i*5) + x, 50.0 + (i*10), 120 + (i*5) - 390);//kanan bawah
		glEnd();
		}
}

void gedungBelakang2(){
    int i,j,k,l;
    //batas belakang
    glBegin(GL_POLYGON);
    glColor3f (0.81, 0.81, 0.81);
    glVertex3f(500, -70, -150.0);
    glVertex3f(500, 440, -150.0);
    glVertex3f(220, 440, -550.0);
	glVertex3f(220, -70, -550.0);
    glEnd();

    //jendela horizontal
    for (i=0;i<3;i++){
    glBegin(GL_POLYGON);
    glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
    glVertex3f(500, 440 - (i*90), -250.0);
    glVertex3f(500, 420 - (i*90), -250.0);
    glVertex3f(220, 420 - (i*90), -637.5);
	glVertex3f(220, 440 - (i*90), -637.5);
    glEnd();
    }

    //batas dengan gedung kiri
    for (i=0;i<4;i++){
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(175, 440 - (i*90), -617.5);
    glVertex3f(220, 440 - (i*90), -637.5);
    glVertex3f(220, 440 - (i*90), -550.0);
    glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(175, 80, -617.5);
    glVertex3f(220, 80, -637.5);
    glVertex3f(220, 80, -550.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
    glVertex3f(175, 80, -617.5);
    glVertex3f(220, 80, -637.5);
    glVertex3f(220, 440, -637.5);
    glVertex3f(175, 440, -617.5);
    glEnd();

    //jendela vertikal
    for(i = 0; i < 4; i++){
		glBegin(GL_QUADS);
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(500 - (i*81.84), 170, -250.0 - (i*112.4));//kanan bawah
		glVertex3f(465 - (i*81.84), 170, -300.0 - (i*112.4));//kiri bawah
		glVertex3f(465 - (i*81.84), 440, -300.0 - (i*112.4));//kiri atas
		glVertex3f(500 - (i*81.84), 440, -250.0 - (i*112.4));//kanan atas
		glEnd();
	}

    //atas
    for(i=0;i<3;i++){
    glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0); //depan
	glVertex3f(500, 440 - (i*90), -250.0);
	glVertex3f(500, 440 - (i*90), -150.0);
	glVertex3f(220, 440 - (i*90), -550.0);
	glVertex3f(220, 440 - (i*90), -637.5);
	glEnd();
    }

    //bawah
    for(i=0;i<3;i++){
    glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0); //depan
	glVertex3f(500, 420 - (i*90), -250.0);
	glVertex3f(500, 420 - (i*90), -150.0);
	glVertex3f(220, 420 - (i*90), -550.0);
	glVertex3f(220, 420 - (i*90), -637.5);
	glEnd();
    }

    //paling bawah
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(500, 170, -250.0);
	glVertex3f(500, 80, -250);
	glVertex3f(220, 80, -637.5);
	glVertex3f(220, 170, -637.5);
	glEnd();

    glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0); //atas
	glVertex3f(500, 170, -250.0);
	glVertex3f(500, 170, -150.0);
	glVertex3f(220, 170, -550.0);
	glVertex3f(220, 170, -637.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0); //bawah
	glVertex3f(500, 80, -250.0);
	glVertex3f(500, 80, -150.0);
	glVertex3f(220, 80, -550.0);
	glVertex3f(220, 80, -637.5);
	glEnd();
}

void gedungBelakang(){
    gedungBelakang1();
    gedungBelakang2();
}

void gedungDepan(){
	//LANTAI 1 start
	//tembok pintu kiri
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-730.0, -45.0, -160);//kiri bawah
	glVertex3f(-750.0, -45.0, -100.0);//kanan bawah
	glVertex3f(-750.0, 70.0, -100.0);//kanan atas
	glVertex3f(-730.0, 70.0, -160);//kiri atas
	glEnd();
	
	//pintu kiri
	glBegin(GL_POLYGON);
	glColor3f (0.36 , 0.25 , 0.2);
	glVertex3f(-740.0, -45.0, -143);//kiri bawah
	glVertex3f(-750.0, -45.0, -105.0);//kanan bawah
	glVertex3f(-750.0, 67.0, -105.0);//kanan atas
	glVertex3f(-740.0, 67.0, -143);//kiri atas
	glEnd();
	
	//tembok pintu tengah
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-750.0, -45.0, -100);//kiri bawah
	glVertex3f(-750.0, -45.0, -20.0);//kanan bawah
	glVertex3f(-750.0, 70.0, -20.0);//kanan atas
	glVertex3f(-750.0, 70.0, -100);//kiri atas
	glEnd();
	
	//pintu tengah
	glBegin(GL_POLYGON);
	glColor3f (0.36 , 0.25 , 0.2);
	glVertex3f(-751.0, -45.0, -85);//kiri bawah
	glVertex3f(-751.0, -45.0, -35.0);//kanan bawah
	glVertex3f(-751.0, 67.0, -35.0);//kanan atas
	glVertex3f(-751.0, 67.0, -85);//kiri atas
	glEnd();
	
	//tembok pintu kanan
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-750.0, -45.0, -20);//kiri bawah
	glVertex3f(-707.0, -45.0, 40.0);//kanan bawah
	glVertex3f(-707.0, 70.0, 40.0);//kanan atas
	glVertex3f(-750.0, 70.0, -20);//kiri atas
	glEnd();
	//pintu kanan
	glBegin(GL_POLYGON);
	glColor3f (0.36 , 0.25 , 0.2);;
	glVertex3f(-745.0, -45.0, -10);//kiri bawah
	glVertex3f(-717.0, -45.0, 30.0);//kanan bawah
	glVertex3f(-717.0, 67.0, 30.0);//kanan atas
	glVertex3f(-745.0, 67.0, -10);//kiri atas
	glEnd();
	
	//tembok kanan samping pintu
	glBegin(GL_POLYGON);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-707.0, -35.0, 40);//kiri bawah
	glVertex3f(-707.0, -35.0, 105.0);//kanan bawah
	glVertex3f(-707.0, 80.0, 105.0);//kanan atas
	glVertex3f(-707.0, 80.0, 40);//kiri atas
	glEnd();

	//tembok kiri samping pintu
	glBegin(GL_POLYGON);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-750.0, -35.0, -230.0);//kiri bawah
	glVertex3f(-730.0, -35.0, -160);//kanan bawah
	glVertex3f(-730.0, 80.0, -160);//kanan atas
	glVertex3f(-750.0, 80.0, -230.0);//kiri atas
	glEnd();
		
	//LANTAI 1 end
	//-----batas lantai 1-2 start
	//---------atap teras
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.8666666666666667);
	glVertex3f(-707.0, 70.0, 20.0);
	glVertex3f(-707.0, 70.0, 85.0);
	glVertex3f(-765.0, 70.0, 30.0);
	glVertex3f(-780.0, 70.0, 10.0);
	glVertex3f(-790.0, 70.0, -35.0);
	glVertex3f(-790.0, 70.0, -65.0);
	glVertex3f(-780.0, 70.0, -100.0);
	glVertex3f(-765.0, 70.0, -160);
	glVertex3f(-750.0, 70.0, -200.0);
	glVertex3f(-730.0, 70.0, -160);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.8666666666666667);
	glVertex3f(-707.0, 75.0, 20.0);
	glVertex3f(-707.0, 75.0, 85.0);
	glVertex3f(-765.0, 75.0, 30.0);
	glVertex3f(-780.0, 75.0, 10.0);
	glVertex3f(-790.0, 75.0, -35.0);
	glVertex3f(-790.0, 75.0, -65.0);
	glVertex3f(-780.0, 75.0, -100.0);
	glVertex3f(-765.0, 75.0, -160);
	glVertex3f(-750.0, 75.0, -200.0);
	glVertex3f(-730.0, 75.0, -160);
	glEnd();
	
	//--------atap teras end
	//--------teralis atap start
	glBegin(GL_POLYGON);
	glColor3f (0.2 , 0.2 , 0.2);
	glVertex3f(-765.0, 75.0, -160);
	glVertex3f(-750.0, 75.0, -200.0);
	glVertex3f(-750.0, 70.0, -200.0);
	glVertex3f(-765.0, 70.0, -160);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f (0.2 , 0.2 , 0.2);
	glVertex3f(-780.0, 75.0, -100.0);
	glVertex3f(-765.0, 75.0, -160);
	glVertex3f(-765.0, 70.0, -160);
	glVertex3f(-780.0, 70.0, -100.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f (0.2 , 0.2 , 0.2);
	glVertex3f(-790.0, 75.0, -65.0);
	glVertex3f(-780.0, 75.0, -100.0);
	glVertex3f(-780.0, 70.0, -100.0);
	glVertex3f(-790.0, 70.0, -65.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f (0.2 , 0.2 , 0.2);
	glVertex3f(-790.0, 75.0, -35.0);
	glVertex3f(-790.0, 75.0, -65.0);
	glVertex3f(-790.0, 70.0, -65.0);
	glVertex3f(-790.0, 70.0, -35.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f (0.2 , 0.2 , 0.2);
	glVertex3f(-780.0, 75.0, 10.0);
	glVertex3f(-790.0, 75.0, -35.0);
	glVertex3f(-790.0, 70.0, -35.0);
	glVertex3f(-780.0, 70.0, 10.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f (0.2 , 0.2 , 0.2);
	glVertex3f(-765.0, 75.0, 30.0);
	glVertex3f(-780.0, 75.0, 10.0);
	glVertex3f(-780.0, 70.0, 10.0);
	glVertex3f(-765.0, 70.0, 30.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f (0.2 , 0.2 , 0.2);
	glVertex3f(-707.0, 75.0, 85.0);
	glVertex3f(-765.0, 75.0, 30.0);
	glVertex3f(-765.0, 70.0, 30.0);
	glVertex3f(-707.0, 70.0, 85.0);
	glEnd();
	//tiang teralis tengah 1
	glBegin(GL_POLYGON);
	glColor3f (0.2 , 0.2 , 0.2);
	glVertex3f(-751.0, 15.0, -25);//kiri bawah
	glVertex3f(-751.0, 70.0, -25);//kiri atas
	glVertex3f(-785.0, 70.0, -10);//kiri atas
	glEnd();
	//tiang teralis tengah 2
	glBegin(GL_POLYGON);
	glColor3f (0.2 , 0.2 , 0.2);
	glVertex3f(-751.0, 15.0, -92.0);//kanan bawah
	glVertex3f(-751.0, 70.0, -92.0);//kanan atas
	glVertex3f(-780.0, 70.0, -107);//kiri atas
	glEnd();
	//tiang teralis kanan
	glBegin(GL_POLYGON);
	glColor3f (0.2 , 0.2 , 0.2);
	glVertex3f(-717.0, 15.0, 35);//kiri bawah
	glVertex3f(-717.0, 70.0, 35);//kiri atas
	glVertex3f(-730.0, 70.0, 60);//kiri atas
	glEnd();
	//tiang teralis kiri
	glBegin(GL_POLYGON);
	glColor3f (0.2 , 0.2 , 0.2);
	glVertex3f(-737.0, 15.0, -150.0);//kanan bawah
	glVertex3f(-737.0, 70.0, -150.0);//kanan atas
	glVertex3f(-760.0, 70.0, -170.0);//kanan atas
	glEnd();
	//--------teralis atap end
	//-----batas lantai 1-2 end
	
	//LANTAI 2 start
	//tembok kanan
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-750.0, 70.0, 10);//kiri bawah
	glVertex3f(-707.0, 70.0, 40.0);//kanan bawah
	glVertex3f(-707.0, 225.0, 40.0);//kanan atas
	glVertex3f(-750.0, 225.0, 10);//kiri atas
	glEnd();
	//tembok kiri
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-720.0, 70.0, -160);//kiri bawah
	glVertex3f(-750.0, 70.0, -120.0);//kanan bawah
	glVertex3f(-750.0, 225.0, -120.0);//kanan atas
	glVertex3f(-720.0, 225.0, -160);//kiri atas
	glEnd();
	//tembok tengah
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-750.0, 225.0, -120.0);
	glVertex3f(-765.0, 225.0, -95.0);
	glVertex3f(-765.0, 75.0, -95.0);
	glVertex3f(-750.0, 75.0, -120.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-765.0, 225.0, -95.0);
	glVertex3f(-765.0, 225.0, -10.0);
	glVertex3f(-765.0, 75.0, -10.0);
	glVertex3f(-765.0, 75.0, -95.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-750.0, 225.0, 10.0);
	glVertex3f(-765.0, 225.0, -10.0);
	glVertex3f(-765.0, 75.0, -10.0);
	glVertex3f(-750.0, 75.0, 10.0);
	glEnd();
	
	//jendela
	glBegin(GL_POLYGON);
	glColor3f (0.81 , 0.81 , 0.81);
	glVertex3f(-751.0, 205.0, -120.0);
	glVertex3f(-764.0, 205.0, -95.0);
	glVertex3f(-764.0, 80.0, -95.0);
	glVertex3f(-751.0, 80.0, -120.0);
	glEnd();
	for(int i=0;i<3;i++){
		glBegin(GL_POLYGON);
		glColor3f (0.81 , 0.81 , 0.81);
		glVertex3f(-766.0, 205.0, -95.0+(i*25));
		glVertex3f(-766.0, 205.0, -75.0+(i*25));
		glVertex3f(-766.0, 80.0, -75.0+(i*25));
		glVertex3f(-766.0, 80.0, -95.0+(i*25));
		glEnd();
	}
	glBegin(GL_POLYGON);
	glColor3f (0.81 , 0.81 , 0.81);
	glVertex3f(-760.0, 205.0, 0.0);
	glVertex3f(-769.0, 205.0, -15.0);
	glVertex3f(-769.0, 80.0, -15.0);
	glVertex3f(-760.0, 80.0, 0.0);
	glEnd();
	//LANTAI 2 end
	//batas lantai 2-3
	for(int i=0;i<3;i++){
		glBegin(GL_POLYGON);
		glColor3f (1 , 1 , 1);
		glVertex3f(-780.0+(i*5), 225.0-(i*5), -95.0);
		glVertex3f(-780.0+(i*5), 225.0-(i*5), -10.0);
		glVertex3f(-780.0+(i*5), 220.0-(i*5), -10.0);
		glVertex3f(-780.0+(i*5), 220.0-(i*5), -95.0);
		glEnd();
	}
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-780.0, 225.0, -95.0);
	glVertex3f(-780.0, 225.0, -10.0);
	glVertex3f(-765.0, 225.0, -10.0);
	glVertex3f(-765.0, 225.0, -95.0);
	glEnd();
	for(int i=0;i<3;i++){
		glBegin(GL_POLYGON);
		glColor3f(0.81, 0.81, 0.81);
		glVertex3f(-780.0+(i*5), 220.0-(i*5), -95.0);
		glVertex3f(-780.0+(i*5), 220.0-(i*5), -10.0);
		glVertex3f(-765.0, 220.0-(i*5), -10.0);
		glVertex3f(-765.0, 220.0-(i*5), -95.0);
		glEnd();
	}
	for(int i=0;i<3;i++){
		glBegin(GL_POLYGON);
		glColor3f (1 , 1 , 1);
		glVertex3f(-765.0+(i*5), 225.0-(i*5), -120.0);
		glVertex3f(-780.0+(i*5), 225.0-(i*5), -95.0);
		glVertex3f(-780.0+(i*5), 220.0-(i*5), -95.0);
		glVertex3f(-765.0+(i*5), 220.0-(i*5), -120.0);
		glEnd();
	}
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-750.0, 225.0, -120.0);
	glVertex3f(-765.0, 225.0, -95.0);
	glVertex3f(-780.0, 225.0, -95.0);
	glVertex3f(-765.0, 225.0, -120.0);
	glEnd();
	for(int i=0;i<3;i++){
		glBegin(GL_POLYGON);
		glColor3f(0.81, 0.81, 0.81);
		glVertex3f(-750.0, 220.0-(i*5), -120.0);
		glVertex3f(-765.0, 220.0-(i*5), -95.0);
		glVertex3f(-780.0+(i*5), 220.0-(i*5), -95.0);
		glVertex3f(-765.0+(i*5), 220.0-(i*5), -120.0);
		glEnd();
	}
	for(int i=0;i<3;i++){
		glBegin(GL_POLYGON);
		glColor3f (1 , 1 , 1);
		glVertex3f(-765.0+(i*5), 225.0-(i*5), 10.0);
		glVertex3f(-780.0+(i*5), 225.0-(i*5), -10.0);
		glVertex3f(-780.0+(i*5), 220.0-(i*5), -10.0);
		glVertex3f(-765.0+(i*5), 220.0-(i*5), 10.0);
		glEnd();
	}
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-780.0, 225.0, -10.0);
	glVertex3f(-765.0, 225.0, 10.0);
	glVertex3f(-750.0, 225.0, 10.0);
	glVertex3f(-765.0, 225.0, -10.0);
	glEnd();
	for(int i=0;i<3;i++){
		glBegin(GL_POLYGON);
		glColor3f(0.81, 0.81, 0.81);
		glVertex3f(-780.0+(i*5), 220.0-(i*5), -10.0);
		glVertex3f(-765.0+(i*5), 220.0-(i*5), 10.0);
		glVertex3f(-750.0, 220.0-(i*5), 10.0);
		glVertex3f(-765.0, 220.0-(i*5), -10.0);
		glEnd();
	}
	for(int i=0;i<3;i++){
		glBegin(GL_POLYGON);
		glColor3f (1 , 1 , 1);
		glVertex3f(-765.0+(i*5), 220.0-(i*5), 10);//kiri bawah
		glVertex3f(-720.0+(i*5), 220.0-(i*5), 45.0);//kanan bawah
		glVertex3f(-720.0+(i*5), 225.0-(i*5), 45.0);//kanan atas
		glVertex3f(-765.0+(i*5), 225.0-(i*5), 10);//kiri atas
		glEnd();
	}
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-750.0, 225.0, 10);//kiri atas
	glVertex3f(-765.0, 225.0, 10);//kiri bawah
	glVertex3f(-720.0, 225.0, 45.0);//kanan bawah
	glVertex3f(-707.0, 225.0, 45.0);//kanan atas
	glEnd();
	for(int i=0;i<3;i++){
		glBegin(GL_POLYGON);
		glColor3f(0.81, 0.81, 0.81);
		glVertex3f(-750.0, 220.0-(i*5), 10);//kiri atas
		glVertex3f(-765.0+(i*5), 220.0-(i*5), 10);//kiri bawah
		glVertex3f(-720.0+(i*5), 220.0-(i*5), 45.0);//kanan bawah
		glVertex3f(-707.0, 220.0-(i*5), 45.0);//kanan atas
		glEnd();
	}
	for(int i=0;i<3;i++){
		glBegin(GL_POLYGON);
		glColor3f (1,1,1);
		glVertex3f(-740.0+(i*5), 220.0-(i*5), -160);//kiri bawah
		glVertex3f(-765.0+(i*5), 220.0-(i*5), -120.0);//kanan bawah
		glVertex3f(-765.0+(i*5), 225.0-(i*5), -120.0);//kanan atas
		glVertex3f(-740.0+(i*5), 225.0-(i*5), -160);//kiri atas
		glEnd();
	}
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-720.0, 225.0, -160);
	glVertex3f(-750.0, 225.0, -120.0);
	glVertex3f(-765.0, 225.0, -120.0);
	glVertex3f(-740.0, 225.0, -160);
	glEnd();
	for(int i=0;i<3;i++){
		glBegin(GL_POLYGON);
		glColor3f(0.81, 0.81, 0.81);
		glVertex3f(-720.0, 220.0-(i*5), -160);
		glVertex3f(-750.0, 220.0-(i*5), -120.0);
		glVertex3f(-765.0+(i*5), 220.0-(i*5), -120.0);
		glVertex3f(-740.0+(i*5), 220.0-(i*5), -160);
		glEnd();
	}
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-705, 455, -150.0);
	glVertex3f(-690, 455, 10.0);
	glVertex3f(-690, -70, 10.0);
	glVertex3f(-705, -70, -150.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-705, 226, -150.0);
	glVertex3f(-690, 226, 45.0);
	glVertex3f(-750.0+20, 226.0, 37);
	glVertex3f(-800.0+20, 226.0, -10);
	glVertex3f(-800.0+20, 226.0, -95);
	glVertex3f(-780.0+20, 226.0, -110);
	glVertex3f(-705, 226.0, -180);
	glEnd();
	

	//lantai teras
	glBegin(GL_POLYGON);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-730.0, -45.0, -160);
	glVertex3f(-765.0, -45.0, -100);
	glVertex3f(-765.0, -45.0, -20.0);
	glVertex3f(-707.0, -45.0, 40.0);
	glVertex3f(-707.0, -45.0, 105.0);
	glVertex3f(-790.0, -45.0, 30.0);
	glVertex3f(-800.0, -45.0, -100.0);
	glVertex3f(-750.0, -45.0, -230.0);
	glEnd();
	
	
	//tembok tangga kanan
	glBegin(GL_POLYGON);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-707.0, -70.0, 105.0);
	glVertex3f(-790.0, -70.0, 30.0);
	glVertex3f(-790.0, -45.0, 30.0);
	glVertex3f(-707.0, -45.0, 105.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-707.0, -70.0, 105.0);
	glVertex3f(-830.0, -70.0, 90.0);
	glVertex3f(-830.0, -60.0, 90.0);
	glVertex3f(-707.0, -60.0, 105.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-707.0, -60.0, 105.0);
	glVertex3f(-830.0, -60.0, 90.0);
	glVertex3f(-790.0, -60.0, 30.0);
	glEnd();
	
	//tembok tangga kiri
	glBegin(GL_POLYGON);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-800.0, -45.0, -100.0);
	glVertex3f(-750.0, -45.0, -230.0);
	glVertex3f(-750.0, -70.0, -230.0);
	glVertex3f(-800.0, -70.0, -100.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-850.0, -60.0, -90.0);
	glVertex3f(-750.0, -60.0, -230.0);
	glVertex3f(-750.0, -70.0, -230.0);
	glVertex3f(-850.0, -70.0, -90.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-850.0, -60.0, -90.0);
	glVertex3f(-750.0, -60.0, -230.0);
	glVertex3f(-800.0, -60.0, -100.0);
	glEnd();
	//tembok tengah tangga
	glBegin(GL_POLYGON);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-800.0, -45.0, -100.0);
	glVertex3f(-790.0, -45.0, 30.0);
	glVertex3f(-790.0, -70.0, 30.0);
	glVertex3f(-800.0, -70.0, -100.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-850.0, -60.0, -90.0);
	glVertex3f(-830.0, -60.0, 90.0);
	glVertex3f(-830.0, -70.0, 90.0);
	glVertex3f(-850.0, -70.0, -90.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-850.0, -60.0, -90.0);
	glVertex3f(-830.0, -60.0, 90.0);
	glVertex3f(-790.0, -60.0, 30.0);
	glVertex3f(-800.0, -60.0, -100.0);
	glEnd();
	
	//tangga
}



void gedungKiri1(){
	
	//--------------------------------------GEDUNG 1--------------------------------------//
	//batas belakang
	glBegin(GL_QUADS);
	glColor3f (0.81, 0.81, 0.81);
	glVertex3f(-300, -70, -350.0);
	glVertex3f(220, -70, -550.0);
	glVertex3f(220, 440, -550.0);
	glVertex3f(-300, 440, -350.0);
	glEnd();
	
	//sekat jendela vertikal
	for(i = 0; i < 7; i++){
		glBegin(GL_QUADS);
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-345 + (i*80.84), 80, -410.0 - (i*33.3));//kanan bawah
		glVertex3f(-310 + (i*80.84), 80, -417.5 - (i*33.3));//kiri bawah
		glVertex3f(-310 + (i*80.84), 440, -417.5 - (i*33.3));//kiri atas
		glVertex3f(-345 + (i*80.84), 440, -410.0 - (i*33.3));//kanan atas
		glEnd();
	}
	
	//sekat bawah jendela horizontal
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-345, 80, -410.0);
	glVertex3f(175, 80, -617.5);
	glVertex3f(175, 170, -617.5);
	glVertex3f(-345, 170, -410.0);
	glEnd();
	
	//sekat jendela horizontal
	for(i = 0; i<3; i++){
		glBegin(GL_QUADS);
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-345, 240 + (i * 90), -410.0);
		glVertex3f(175, 240 + (i * 90), -617.5);
		glVertex3f(175, 260 + (i * 90), -617.5);
		glVertex3f(-345, 260 + (i * 90), -410.0);
		glEnd();
	}
	
	//tembok kiri
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(220, 440, -550.0);
	glVertex3f(175, 440, -617.5);
	glVertex3f(175, -70, -617.5);
	glVertex3f(220, -70, -550.0);
	glEnd();
	
	//tembok kanan
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-344.9, 440, -410.0);
	glVertex3f(-300, 440, -350.0);
	glVertex3f(-300, -70, -350.0);
	glVertex3f(-344.9, -70, -410.0);
	glEnd();
	
	//sekat per lantai
	for(i = 0; i < 5; i++){
		glBegin(GL_QUADS);
		glColor3f (1, 1, 1);
		glVertex3f(220, 80 + (i*90), -550.0);
		glVertex3f(175, 80 + (i*90), -617.5);
		glVertex3f(-345, 80 + (i*90), -410.0);
		glVertex3f(-300, 80 + (i*90), -350.0);
		glEnd();
	}
	//--------------------------------------GEDUNG 1 (END)--------------------------------------//
}





void gedungKiri2(){
	//batas belakang
	glBegin(GL_QUADS);//kiri
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-300, -70, -350.0);
	glVertex3f(-450, -70, -550.0);
	glVertex3f(-450, 440, -550.0);
	glVertex3f(-300, 440, -350.0);
	glEnd();
	
	//--------------------------------------GEDUNG SEGITIGA--------------------------------------//
	
	//batas kanan gedung segitiga
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-345, 440, -520.0);
	glVertex3f(-350, 440, -635.0);
	glVertex3f(-350, -70, -635.0);
	glVertex3f(-345, -70, -520.0);
	glEnd();
	
	//batas depan gedung segitiga
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-350, 440, -635.0);
	glVertex3f(-350, -70, -635.0);
	glVertex3f(-300, -70, -660.0);
	glVertex3f(-300, 440, -660.0);
	glEnd();
	
	//batas kiri gedung segitiga
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-300, 100, -660.0);
	glVertex3f(-300, 440, -660.0);
	glVertex3f(-200, 440, -580.0);
	glVertex3f(-200, 100, -580.0);
	glEnd();
	
	//batas belakang gedung segitiga
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-200, 440, -580.0);
	glVertex3f(-200, -70, -580.0);
	glVertex3f(-345, -70, -520.0);
	glVertex3f(-345, 440, -520.0);
	glEnd();
	
	//batas atas gedung segitiga
	glBegin(GL_POLYGON);
	glColor3f (0.7215686274509804, 0.6431372549019608, 0.6431372549019608);
	glVertex3f(-300, 440, -660.0);
	glVertex3f(-200, 440, -580.0);
	glVertex3f(-345, 440, -520.0);//
	glVertex3f(-350, 440, -635.0);
	glEnd();
	
	//--------------------------------------GEDUNG KOTAK--------------------------------------//
	
	//batas belakang
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-450, -70, -550.0);
	glVertex3f(-450, 220, -550.0);
	glVertex3f(-270, 220, -645.0);
	glVertex3f(-270, -70, -645.0);
	glEnd();
	
	//batas kiri
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-270, 220, -645.0);
	glVertex3f(-270, -70, -645.0);
	glVertex3f(-340, -70, -780.0);
	glVertex3f(-340, 220, -780.0);
	glEnd();
	
	//batas depan
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-340, -70, -780.0);
	glVertex3f(-340, 220, -780.0);
	glVertex3f(-505, 220, -620.0);
	glVertex3f(-505, -70, -620.0);
	glEnd();
	
	//batas kanan
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-450, -70, -550.0);
	glVertex3f(-450, 220, -550.0);
	glVertex3f(-505, 220, -620.0);
	glVertex3f(-505, -70, -620.0);
	glEnd();
	
	//atap gedung kotak
	glBegin(GL_POLYGON);
	glColor3f (1 , 1 , 1);
	glVertex3f(-270, 220, -645.0);//1
	glVertex3f(-340, 220, -780.0);//2
	glVertex3f(-505, 220, -620.0);//3
	glVertex3f(-450, 220, -550.0);//4
	glEnd();
}




void gedungKiri3(){
	//batas belakang
	glBegin(GL_QUADS);//kiri
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-450, -70, -550.0);
	glVertex3f(-705, -70, -150.0);
	glVertex3f(-705, 440+15, -150.0);
	glVertex3f(-450, 440+15, -550.0);
	glEnd();
	
	//--------------sebelah kirinya pintu masuk--------------
	glBegin(GL_QUADS);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-750.0, -70.0, 110.0-340);//kiri bawah
	glVertex3f(-750.0, -40.0, 110.0-340);//kiri atas
	glVertex3f(-730.0, -40.0, -160.0);//kanan atas
	glVertex3f(-730.0, -70.0, -160.0);//kanan bawah
	glEnd();
	
	//--------------tembok alas--------------
	glBegin(GL_QUADS);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-750.0, -70.0, 110.0-340);//kiri bawah
	glVertex3f(-750.0, -40.0, 110.0-340);//kiri atas
	glVertex3f(-660.0, -40.0, -370.0);//kanan atas
	glVertex3f(-660.0, -70.0, -370.0);//kanan bawah
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (kanan)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-753.0, -40.0, 110.0-340);//kiri bawah
	glVertex3f(-753.0, -35.0, 110.0-340);//kiri atas
	glVertex3f(-733.0, -35.0, -157.0);//kanan atas
	glVertex3f(-733.0, -40.0, -157.0);//kanan bawah
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (atas)
	glBegin(GL_POLYGON);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-733.0, -35.0, -157.0);//kanan atas
	glVertex3f(-753.0, -35.0, 110.0-340);//kanan bawah
	glVertex3f(-660.0, -35, -373.0);//kiri bawah
	glVertex3f(-615.0, -35, -335.0);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (depan)
	glBegin(GL_POLYGON);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-753.0, -40.0, 110.0-340);//kanan bawah
	glVertex3f(-753.0, -35.0, 110.0-340);//kanan atas
	glVertex3f(-660.0, -35.0, -373.0);//kiri atas
	glVertex3f(-660.0, -40.0, -373.0);//kiri bawah
	glEnd();
	
	//dinding oren sebelah lekukan
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-750.0, 80.0, 110.0-340);//kiri bawah
	glVertex3f(-750.0, -35.0, 110.0-340);//kiri atas
	glVertex3f(-730.0, -35.0, -160.0);//kanan atas
	glVertex3f(-730.0, 80.0, -160.0);//kanan bawah
	glEnd();
	
	//depan oren
	glBegin(GL_POLYGON);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-750.0, 80.0, 110.0-340);//kanan bawah
	glVertex3f(-750.0, -35.0, 110.0-340);//kanan atas
	glVertex3f(-660.0, -35.0, -370.0);//kiri atas
	glVertex3f(-660.0, 80.0, -370.0);//kiri bawah
	glEnd();
	
	//--------------LIS DINDING OREN PUTIH----------------
	//--------------pengantara alas & dinding-------------- (atas1)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-733.0, 80, -157.0);//kanan atas
	glVertex3f(-753.0, 80, 110.0-340);//kanan bawah
	glVertex3f(-440.0-70, 80, -673.0+70);//kiri bawah
	glVertex3f(-400.0-65, 80, -635.0+70);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (atas2)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-733.0-5, 85, -157.0+5);//kanan atas
	glVertex3f(-753.0-5, 85, 110.0-340-5);//kanan bawah
	glVertex3f(-440.0-70-5, 85, -673.0+70-5);//kiri bawah
	glVertex3f(-400.0-65, 85, -635.0+70);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (atas3)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-733.0-10, 90, -157.0+10);//kanan atas
	glVertex3f(-753.0-10, 90, 110.0-340-10);//kanan bawah
	glVertex3f(-440.0-70-10, 90, -673.0+70-10);//kiri bawah
	glVertex3f(-400.0-65, 90, -635.0+70);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (atas4)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-733.0-10, 95, -157.0+10);//kanan atas
	glVertex3f(-753.0-10, 95, 110.0-340-10);//kanan bawah
	glVertex3f(-440.0-70-10, 95, -673.0+70-10);//kiri bawah
	glVertex3f(-400.0-65, 95, -635.0+70);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (kanan1)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-733.0, 80, -157.0);//kanan bawah
	glVertex3f(-753.0, 80, 110.0-340);//kiri bawah
	glVertex3f(-753.0, 85, 110.0-340);//kiri atas
	glVertex3f(-733.0, 85, -157.0);//kanan atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (kanan2)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-733.0-5, 85, -157.0+5);//kanan bawah
	glVertex3f(-753.0-5, 85, 110.0-340-5);//kiri bawah
	glVertex3f(-753.0-5, 90, 110.0-340-5);//kiri atas
	glVertex3f(-733.0-5, 90, -157.0+5);//kanan atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (kanan3)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-733.0-10, 90, -157.0+10);//kanan bawah
	glVertex3f(-753.0-10, 90, 110.0-340-10);//kiri bawah
	glVertex3f(-753.0-10, 95, 110.0-340-10);//kiri atas
	glVertex3f(-733.0-10, 95, -157.0+10);//kanan atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (depan1)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-753.0, 85, 110.0-340);//kanan atas = kiri atas 'kanan'
	glVertex3f(-753.0, 80, 110.0-340);//kanan bawah = kiri bawah 'kanan'
	glVertex3f(-440.0-70, 80, -673.0+70);//kiri bawah = kiri bawah 'atas'
	glVertex3f(-440.0-70, 85, -673.0+70);//kiri atas = kiri bawah 'atas' + 5y
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (depan2)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-753.0-5, 90, 110.0-340-5);//kanan atas = kiri atas 'kanan'
	glVertex3f(-753.0-5, 85, 110.0-340-5);//kanan bawah = kiri bawah 'kanan'
	glVertex3f(-440.0-70-5, 85, -673.0+70-5);//kiri bawah = kiri bawah 'atas'
	glVertex3f(-440.0-70-5, 90, -673.0+70-5);//kiri atas = kiri bawah 'atas' + 5y
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (depan3)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-753.0-10, 95, 110.0-340-10);//kanan atas = kiri atas 'kanan'
	glVertex3f(-753.0-10, 90, 110.0-340-10);//kanan bawah = kiri bawah 'kanan'
	glVertex3f(-440.0-70-10, 90, -673.0+70-10);//kiri bawah = kiri bawah 'atas'
	glVertex3f(-440.0-70-10, 95, -673.0+70-10);//kiri atas = kiri bawah 'atas' + 5y
	glEnd();
	
	//--------------LIS LEVEL 1----------------
	//--------------pengantara alas & dinding-------------- (atas1)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-733.0, 80+130, -157.0);//kanan atas
	glVertex3f(-753.0, 80+130, 110.0-340);//kanan bawah
	glVertex3f(-670.0, 80+130, -370.0-13+25);//kiri bawah
	glVertex3f(-630.0, 80+130, -285.0-27);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (atas2)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-733.0-5, 85+130, -157.0+5);//kanan atas
	glVertex3f(-753.0-5, 85+130, 110.0-340-5);//kanan bawah
	glVertex3f(-670.0-10, 85+130, -370.0-13+25-10+13);//kiri bawah
	glVertex3f(-630.0, 85+130, -285.0-27);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (atas3)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-733.0-10, 90+130, -157.0+10);//kanan atas
	glVertex3f(-753.0-10, 90+130, 110.0-340-10);//kanan bawah
	glVertex3f(-670.0-10, 90+130, -370.0-13+25-10);//kiri bawah
	glVertex3f(-630.0, 90+130, -285.0-27);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (atas4)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-733.0-10, 95+130, -157.0+10);//kanan atas
	glVertex3f(-753.0-10, 95+130, 110.0-340-10);//kanan bawah
	glVertex3f(-670.0-10, 95+130, -370.0-13+25-10);//kiri bawah
	glVertex3f(-630.0, 95+130, -285.0-27);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (kanan1)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-733.0, 80+130, -157.0);//kanan bawah
	glVertex3f(-753.0, 80+130, 110.0-340);//kiri bawah
	glVertex3f(-753.0, 85+130, 110.0-340);//kiri atas
	glVertex3f(-733.0, 85+130, -157.0);//kanan atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (kanan2)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-733.0-5, 85+130, -157.0+5);//kanan bawah
	glVertex3f(-753.0-5, 85+130, 110.0-340-5);//kiri bawah
	glVertex3f(-753.0-5, 90+130, 110.0-340-5);//kiri atas
	glVertex3f(-733.0-5, 90+130, -157.0+5);//kanan atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (kanan3)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-733.0-10, 90+130, -157.0+10);//kanan bawah
	glVertex3f(-753.0-10, 90+130, 110.0-340-10);//kiri bawah
	glVertex3f(-753.0-10, 95+130, 110.0-340-10);//kiri atas
	glVertex3f(-733.0-10, 95+130, -157.0+10);//kanan atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (depan1)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-753.0, 85+130, 110.0-340);//kanan atas = kiri atas 'kanan'
	glVertex3f(-753.0, 80+130, 110.0-340);//kanan bawah = kiri bawah 'kanan'
	glVertex3f(-670.0, 80+130, -370.0-13+25);//kiri bawah = kiri bawah 'atas'
	glVertex3f(-670.0, 85+130, -370.0-13+25);//kiri atas = kiri bawah 'atas' + 5y
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (depan2)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-753.0-5, 90+130, 110.0-340-5);//kanan atas = kiri atas 'kanan'
	glVertex3f(-753.0-5, 85+130, 110.0-340-5);//kanan bawah = kiri bawah 'kanan'
	glVertex3f(-670.0-5, 85+130, -370.0-13+25-5);//kiri bawah = kiri bawah 'atas'
	glVertex3f(-670.0-5, 90+130, -370.0-13+25-5);//kiri atas = kiri bawah 'atas' + 5y
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (depan3)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-753.0-10, 95+130, 110.0-340-10);//kanan atas = kiri atas 'kanan'
	glVertex3f(-753.0-10, 90+130, 110.0-340-10);//kanan bawah = kiri bawah 'kanan'
	glVertex3f(-670.0-10, 90+130, -370.0-13+25-10);//kiri bawah = kiri bawah 'atas'
	glVertex3f(-670.0-10, 95+130, -370.0-13+25-10);//kiri atas = kiri bawah 'atas' + 5y
	glEnd();
	
	//tembok kiri oren
	glBegin(GL_POLYGON);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-400.0-70, 80, -635.0+70);//kiri atas
	glVertex3f(-440.0-70, 80, -673.0+70);//kanan atas
	glVertex3f(-440.0-70, -35, -673.0+70);//kanan bawah
	glVertex3f(-400.0-70, -35, -635.0+70);//kiri bawah
	glEnd();
	
	//tembok kiri abu2
	glBegin(GL_POLYGON);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-400.0-70, -35, -635.0+70);//kiri atas
	glVertex3f(-440.0-70, -35, -673.0+70);//kanan atas
	glVertex3f(-440.0-70, -70, -673.0+70);//kanan bawah
	glVertex3f(-400.0-70, -70, -635.0+70);//kiri bawah
	glEnd();
	
	//tembok pembatas oren
	for(i = 0; i < 3; i++){
		//tembok pembatas oren
		glBegin(GL_POLYGON);
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-460.0-70 - (i * 50), 80, -635.0+62+ (i * 80));//kanan atas
		glVertex3f(-440.0-70- (i * 50), 80, -673.0+70+ (i * 80));//kiri atas
		glVertex3f(-440.0-70- (i * 50), -35, -673.0+70+ (i * 80));//kiri bawah
		glVertex3f(-460.0-70- (i * 50), -35, -635.0+62+ (i * 80));//kanan bawah
		glEnd();
		
		//tembok pembatas abu2
		glBegin(GL_POLYGON);
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-460.0-70 - (i * 50), -35, -635.0+62+ (i * 80));//kanan atas
		glVertex3f(-440.0-70- (i * 50), -35, -673.0+70+ (i * 80));//kiri atas
		glVertex3f(-440.0-70- (i * 50), -70, -673.0+70+ (i * 80));//kiri bawah
		glVertex3f(-460.0-70- (i * 50), -70, -635.0+62+ (i * 80));//kanan bawah
		glEnd();
		
		//tembok pembatas oren dan alas (depan)
		glBegin(GL_POLYGON);
		glColor3f(0.41, 0.41, 0.41);
		glVertex3f(-460.0-75- (i * 50)+1, -35, -635.0+67+ (i * 80)-3);//kanan atas
		glVertex3f(-440.0-71- (i * 50)+1, -35, -673.0+70+ (i * 80)-3);//kiri atas
		glVertex3f(-440.0-71- (i * 50)+1, -40, -673.0+70+ (i * 80)-3);//kiri bawah
		glVertex3f(-460.0-75- (i * 50)+1, -40, -635.0+67+ (i * 80)-3);//kanan bawah
		glEnd();
		
		//tembok pembatas oren dan alas (depan)
		glBegin(GL_POLYGON);
		glColor3f(0.41, 0.41, 0.41);
		glVertex3f(-460.0-75- (i * 50)+1, -35, -635.0+67+ (i * 80)-3);//kanan depan = kanan atas
		glVertex3f(-440.0-71- (i * 50)+1, -35, -673.0+70+ (i * 80)-3);//kiri depan = kiri atas
		glVertex3f(-440.0-71- (i * 50)+40, -35, -673.0+70+ (i * 80)+30);//kiri belakang
		glVertex3f(-460.0-75- (i * 50)+40, -35, -635.0+67+ (i * 80)+30);//kanan belakang
		glEnd();
		
		//garasi
		glBegin(GL_POLYGON);
		glColor3f (0.36 , 0.25 , 0.2);
		glVertex3f(-460.0-70- (i * 50), 30, -635.0+62+ (i * 80));//kiri atas
		glVertex3f(-440.0-72- ((i+1) * 50), 30.0, -673.0+70+ ((i+1) * 80));//kanan atas
		glVertex3f(-440.0-72- ((i+1) * 50), -70.0, -673.0+70+ ((i+1) * 80));//kanan bawah
		glVertex3f(-460.0-70- (i * 50), -70, -635.0+62+ (i * 80));//kiri bawah
		glEnd();
	}
	
	//tembok atasnya pembatas
	glBegin(GL_POLYGON);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-440.0-70, 80, -673.0+70);//kiri atas
	glVertex3f(-660.0, 80.0, -370.0);//kanan atas
	glVertex3f(-660.0, 30.0, -370.0);//kanan bawah
	glVertex3f(-440.0-70, 30, -673.0+70);//kiri bawah
	glEnd();
	
	//depan putih - kanan
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-750.0, 95.0, 110.0-340);//kanan bawah
	glVertex3f(-750.0, 210.0, 110.0-340);//kanan atas
	glVertex3f(-660.0, 210.0, -370.0);//kiri atas
	glVertex3f(-660.0, 95.0, -370.0);//kiri bawah
	glEnd();
	
	//depan putih - kiri
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-440.0-70, 95, -673.0+70);//kiri bawah
	glVertex3f(-660.0-7, 95.0, -370.0+12.5);//kanan bawah
	glVertex3f(-660.0-7, 440.0+15, -370.0+12.5);//kanan atas
	glVertex3f(-440.0-70, 440+15, -673.0+70);//kiri atas
	glEnd();
	
	//tembok kanan dinding putih
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-750.0, 95.0, 110.0-340);//kiri bawah
	glVertex3f(-750.0, 210.0, 110.0-340);//kiri atas
	glVertex3f(-730.0, 210.0, -160.0);//kanan atas
	glVertex3f(-730.0, 95.0, -160.0);//kanan bawah
	glEnd();
	
	//tembok kiri dinding putih
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-450, 95, -550.0);//kiri atas
	glVertex3f(-440.0-70, 95, -673.0+70);//kanan atas
	glVertex3f(-440.0-70, 440+15, -673.0+70);//kanan bawah
	glVertex3f(-450, 440+15, -550.0);//kiri bawah
	glEnd();
	
	//tembok tengah
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-660.0-7, 440.0+15, -370.0+12.5);//kanan atas
	glVertex3f(-620.0, 440.0+15, -285.0);//kiri atas
	glVertex3f(-620.0, 95.0, -285.0);//kiri bawah
	glVertex3f(-660.0-7, 95.0, -370.0+12.5);//kanan bawah
	glEnd();
	
	//--------------LIS LEVEL 2----------------
	//--------------pengantara alas & dinding-------------- (atas1)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-620.0-20, 80+345+15, -285.0-20);//kanan atas
	glVertex3f(-660.0-7-5, 80+345+15, -370.0+12.5);//kanan bawah
	glVertex3f(-440.0-70, 80+345+15, -673.0+70);//kiri bawah
	glVertex3f(-400.0-65, 80+345+15, -635.0+70);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (atas2)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-620.0-20-5, 85+345+15, -285.0-20+5);//kanan atas
	glVertex3f(-660.0-7-5-5, 85+345+15, -370.0+12.5-5);//kanan bawah
	glVertex3f(-440.0-70-5, 85+345+15, -673.0+70-5);//kiri bawah
	glVertex3f(-400.0-65, 85+345+15, -635.0+70);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (atas3)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-620.0-20-10, 90+345+15, -285.0-20+10);//kanan atas
	glVertex3f(-660.0-7-5-10, 90+345+15, -370.0+12.5-10);//kanan bawah
	glVertex3f(-440.0-70-10, 90+345+15, -673.0+70-10);//kiri bawah
	glVertex3f(-400.0-65, 90+345+15, -635.0+70);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (atas4)
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-620.0-20-10, 95+345+15, -285.0-20+10);//kanan atas
	glVertex3f(-660.0-7-5-10, 95+345+15, -370.0+12.5-10);//kanan bawah
	glVertex3f(-440.0-70-10, 95+345+15, -673.0+70-10);//kiri bawah
	glVertex3f(-400.0-65, 95+345+15, -635.0+70);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (kanan1)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-620.0-20, 80+345+15, -285.0-20);//kanan bawah
	glVertex3f(-660.0-7-5, 80+345+15, -370.0+12.5);//kiri bawah
	glVertex3f(-660.0-7-5, 85+345+15, -370.0+12.5);//kiri atas
	glVertex3f(-620.0-20, 85+345+15, -285.0-20);//kanan atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (kanan2)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-620.0-20-5, 85+345+15, -285.0-20+5);//kanan bawah
	glVertex3f(-660.0-7-5-5, 85+345+15, -370.0+12.5-5);//kiri bawah
	glVertex3f(-660.0-7-5-5, 90+345+15, -370.0+12.5-5);//kiri atas
	glVertex3f(-620.0-20-5, 90+345+15, -285.0-20+5);//kanan atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (kanan3)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-620.0-20-10, 90+345+15, -285.0-20+10);//kanan bawah
	glVertex3f(-660.0-7-5-10, 90+345+15, -370.0+12.5-10);//kiri bawah
	glVertex3f(-660.0-7-5-10, 95+345+15, -370.0+12.5-10);//kiri atas
	glVertex3f(-620.0-20-10, 95+345+15, -285.0-20+10);//kanan atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (depan1)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-660.0-7-5, 85+345+15, -370.0+12.5);//kanan atas = kiri atas 'kanan'
	glVertex3f(-660.0-7-5, 80+345+15, -370.0+12.5);//kanan bawah = kiri bawah 'kanan'
	glVertex3f(-440.0-70, 80+345+15, -673.0+70);//kiri bawah = kiri bawah 'atas'
	glVertex3f(-440.0-70, 85+345+15, -673.0+70);//kiri atas = kiri bawah 'atas' + 5y
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (depan2)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-660.0-7-5-5, 90+345+15, -370.0+12.5-5);//kanan atas = kiri atas 'kanan'
	glVertex3f(-660.0-7-5-5, 85+345+15, -370.0+12.5-5);//kanan bawah = kiri bawah 'kanan'
	glVertex3f(-440.0-70-5, 85+345+15, -673.0+70-5);//kiri bawah = kiri bawah 'atas'
	glVertex3f(-440.0-70-5, 90+345+15, -673.0+70-5);//kiri atas = kiri bawah 'atas' + 5y
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (depan3)
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(-660.0-7-5-10, 95+345+15, -370.0+12.5-10);//kanan atas = kiri atas 'kanan'
	glVertex3f(-660.0-7-5-10, 90+345+15, -370.0+12.5-10);//kanan bawah = kiri bawah 'kanan'
	glVertex3f(-440.0-70-10, 90+345+15, -673.0+70-10);//kiri bawah = kiri bawah 'atas'
	glVertex3f(-440.0-70-10, 95+345+15, -673.0+70-10);//kiri atas = kiri bawah 'atas' + 5y
	glEnd();
	
	//COVER
	//--------------sebelah kirinya pintu masuk--------------
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-730.0, -70.0, -160.0);//kiri bawah
	glVertex3f(-705, -70, -150.0);//kanan bawah
	glVertex3f(-705, 230, -150.0);//kanan atas
	glVertex3f(-730.0, 230.0, -160.0);//kiri atas
	glEnd();
	
	//atasnya level 1
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-705, 225, -150.0);//kanan atas
	glVertex3f(-730.0-5, 225.0, -160.0-5);//kanan bawah
	glVertex3f(-630.0, 225, -285.0-27);//kiri bawah
	glVertex3f(-620.0, 225.0, -285.0);//kiri atas
	glEnd();
	
	//atasnya level 2
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	glVertex3f(-620.0, 440.0+15, -285.0);//kanan atas
	glVertex3f(-620.0-20-10, 440+15, -285.0-20+10);//kanan bawah
	glVertex3f(-400.0-65, 440+15, -635.0+70);//kiri bawah
	glVertex3f(-450, 440+15, -550.0);//kiri atas
	glEnd();
}


void jendelaGedungKiri2(){
	a=0, b=0;
	//depan GEDUNG KOTAK
	for(j = 0; j < 2; j++){
		for(i = 0; i < 4; i++){
			glBegin(GL_QUADS);
			glColor3f (0.81, 0.81, 0.81);
			glVertex3f(-465 + (i*35) + a, 140 - (j*80), -660.0 - (i*34) - b);
			glVertex3f(-465 + (i*35) + a, 200 - (j*80), -660.0 - (i*34) - b);
			glVertex3f(-490 + (i*35) + a, 200 - (j*80), -635.0 - (i*34) - b);
			glVertex3f(-490 + (i*35) + a, 140 - (j*80), -635.0 - (i*34) - b);
			glEnd();
		}
	}
	for(j = 2; j < 3; j++){
		for(i = 0; i < 4; i++){
			glBegin(GL_QUADS);
			if(i == 0){
				glColor3f (0.36 , 0.25 , 0.2);
				glVertex3f(-465 + (i*35) + a, 90 - (j*80), -660.0 - (i*34) - b);
				glVertex3f(-465 + (i*35) + a, 190 - (j*80), -660.0 - (i*34) - b);
				glVertex3f(-490 + (i*35) + a, 190 - (j*80), -635.0 - (i*34) - b);
				glVertex3f(-490 + (i*35) + a, 90 - (j*80), -635.0 - (i*34) - b);
				glEnd();
			}else{
				glColor3f (0.81, 0.81, 0.81);
				glVertex3f(-465 + (i*35) + a, 140 - (j*80), -660.0 - (i*34) - b);
				glVertex3f(-465 + (i*35) + a, 200 - (j*80), -660.0 - (i*34) - b);
				glVertex3f(-490 + (i*35) + a, 200 - (j*80), -635.0 - (i*34) - b);
				glVertex3f(-490 + (i*35) + a, 140 - (j*80), -635.0 - (i*34) - b);
				glEnd();
			}

		}
	}
	
	//kiri GEDUND KOTAK
	for(j = 0; j < 3; j++){
		for(i = 0; i < 3; i++){
			glBegin(GL_POLYGON);
			glColor3f (0.81, 0.81, 0.81);
			glVertex3f(-321 + (i*18), 200 - (j*80), -745.0+ (i*34));
			glVertex3f(-321 + (i*18), 140 - (j*80), -745.0+ (i*34));
			glVertex3f(-334 + (i*18), 140 - (j*80), -770.0+ (i*34));
			glVertex3f(-334 + (i*18), 200 - (j*80), -770.0+ (i*34));
			glEnd();
		}
	}
	
	//kiri GEDUNG SEGITIGA
	for(j = 0; j < 2; j++){
		for(i = 0; i < 2; i++){
			glBegin(GL_QUADS);
			glColor3f (0.81, 0.81, 0.81);
			glVertex3f(-287 + (i*45), 360- (j*80), -650.0+ (i*35));
			glVertex3f(-287 + (i*45), 420- (j*80), -650.0+ (i*35));
			glVertex3f(-261 + (i*45), 420- (j*80), -630.0+ (i*35));
			glVertex3f(-261 + (i*45), 360- (j*80), -630.0+ (i*35));
			glEnd();
		}
	}
	
	//depan GEDUNG SEGITIGA
	for(j = 0; j < 2; j++){
		glBegin(GL_POLYGON);
		glColor3f (0.81, 0.81, 0.81);
		glVertex3f(-345, 420- (j*80), -638.0);
		glVertex3f(-345, 360- (j*80), -638.0);
		glVertex3f(-308, 360- (j*80), -656.0);
		glVertex3f(-308, 420- (j*80), -656.0);
		glEnd();
	}
	
}

void jendelaGedungKiri3(){
	//jendela depan putih
	a = 0, b = 0;
	for(i = 0; i < 3; i++){
		glBegin(GL_POLYGON);
		glColor3f (0.81, 0.81, 0.81);
		glVertex3f(-724.0 + (i*27) + a, 110.0, -275 - (i*40) - b);//kiri bawah
		glVertex3f(-724.0 + (i*27) + a, 200.0, -275 - (i*40) - b);//kiri atas
		glVertex3f(-749.0 + (i*27) + a, 200.0, -237 - (i*40) - b);//kanan atas
		glVertex3f(-749.0 + (i*27) + a, 110.0, -237 - (i*40) - b);//kanan bawah
		glEnd();	
	}
	
	a = 15;
	b = 30;
	for(j = 0; j < 3; j++){
		for(i = 3; i < 5; i++){
			glBegin(GL_POLYGON);
			glColor3f (0.81, 0.81, 0.81);
			glVertex3f(-724.0 + (i*27) + a, 110.0+(j*110), -275 - (i*40) - b);//kiri bawah
			glVertex3f(-724.0 + (i*27) + a, 200.0+(j*110), -275 - (i*40) - b);//kiri atas
			glVertex3f(-749.0 + (i*27) + a, 200.0+(j*110), -237 - (i*40) - b);//kanan atas
			glVertex3f(-749.0 + (i*27) + a, 110.0+(j*110), -237 - (i*40) - b);//kanan bawah
			glEnd();
		}
	}
	
	a = 80;
	b = 130;
	for(j = 0; j < 3; j++){
		for(i = 3; i < 5; i++){
			glBegin(GL_POLYGON);
			glColor3f (0.81, 0.81, 0.81);
			glVertex3f(-724.0 + (i*27) + a, 110.0+(j*110), -275 - (i*40) - b);//kiri bawah
			glVertex3f(-724.0 + (i*27) + a, 200.0+(j*110), -275 - (i*40) - b);//kiri atas
			glVertex3f(-749.0 + (i*27) + a, 200.0+(j*110), -237 - (i*40) - b);//kanan atas
			glVertex3f(-749.0 + (i*27) + a, 110.0+(j*110), -237 - (i*40) - b);//kanan bawah
			glEnd();
		}
	}
	
	
	//jendela depan oren
	a = 15;
	b = 18;
	glBegin(GL_POLYGON);
	glColor3f (0.81, 0.81, 0.81);
	glVertex3f(-700.0+ a, 60.0, -275 - 40 - b);//kiri bawah
	glVertex3f(-700.0+ a, -35.0, -275 - 40 - b);//kiri atas
	glVertex3f(-749.0+ a, -35.0, -237 - b);//kanan atas
	glVertex3f(-749.0+ a, 60.0, -237 - b);//kanan bawah
	glEnd();
}

void gedungKiri(){
	gedungKiri1();
	gedungKiri2();
	jendelaGedungKiri2();
	gedungKiri3();
	jendelaGedungKiri3();
}


void BatasBangunan(void){
	
	
	glBegin(GL_POLYGON);
	glColor3f(0.81, 0.81, 0.81);
	
	glVertex3f(500, 440, -150.0);
	glVertex3f(220, 440, -550.0);
	glVertex3f(-300, 440, -350.0);
	glVertex3f(-450, 440, -550.0);
	
	glVertex3f(-705, 440, -150.0);
	glVertex3f(-690, 440, 10.0);
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



void sambungandindingalasdandindingoren(){
	//--------------pengantara alas & dinding-------------- (kiri)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-710.0, -40.0, 115.0);//kiri bawah
	glVertex3f(-710.0, -35.0, 115.0);//kiri atas
	glVertex3f(-710.0, -35.0, 40.0);//kanan atas
	glVertex3f(-710.0, -40.0, 40.0);//kanan bawah
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
	glVertex3f(-710.0, -35.0, 40);//kiri bawah
	glVertex3f(-390.0, -35, 40);//kanan bawah
	glVertex3f(-390.0, -35.0, 115);//kanan atas
	glVertex3f(-710.0, -35.0, 115);//kiri atas
	glEnd();
	
	///--------------pengantara alas & dinding-------------- (bawah)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-707.0, -40.0, 40);//kiri bawah
	glVertex3f(-390.0, -40, 40);//kanan bawah
	glVertex3f(-390.0, -40.0, 115);//kanan atas
	glVertex3f(-707.0, -40.0, 115);//kiri atas
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
	glVertex3f(-360.0, -35.0, 95);//kanan atas
	glVertex3f(-360.0, -40.0, 95);//kanan bawah
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (Kanan Akhir Atas)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-370.0, -35.0, 90);//kiri bawah
	glVertex3f(-360.0, -35, 90);//kanan bawah
	glVertex3f(-360.0, -35.0, 95);//kanan atas
	glVertex3f(-370.0, -35.0, 95);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (Kanan Akhir bawah)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-370.0, -40.0, 90);//kiri bawah
	glVertex3f(-360.0, -40, 90);//kanan bawah
	glVertex3f(-360.0, -40.0, 95);//kanan atas
	glVertex3f(-370.0, -40.0, 95);//kiri atas
	glEnd();
	
	
}

void DindingAlas(){

	
	//--------------sebelah kanannya pintu masuk--------------
	glBegin(GL_QUADS);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-707.0, -70.0, 110.0);//kiri bawah
	glVertex3f(-707.0, -40.0, 110.0);//kiri atas
	glVertex3f(-707.0, -40.0, 40.0);//kanan atas
	glVertex3f(-707.0, -70.0, 40.0);//kanan bawah
	glEnd();
	
	//--------------tembok alas--------------
	glBegin(GL_QUADS);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-707.0, -70.0, 110.0);//kiri bawah
	glVertex3f(-707.0, -40.0, 110.0);//kiri atas
	glVertex3f(-390, -40.0, 110.0);//kanan atas
	glVertex3f(-390, -70.0, 110.0);//kanan bawah
	glEnd();
	
	
	
	//--------------lengkungan pintu--------------
	glBegin(GL_QUADS); //utama kanan
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-390, -70.0, 110.0);//kiri bawah
	glVertex3f(-390, -35.0, 110.0);//kiri atas
	glVertex3f(-370, -35.0, 90.0);//kanan atas
	glVertex3f(-370, -70.0, 90.0);//kanan bawah
	glEnd();
	
	for (i=0;i<2;i++){
	glBegin(GL_QUADS); //utama kanan akhir
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-370, -70.0, 90.0);//kiri bawah
	glVertex3f(-370, -40.0, 90.0);//kiri atas
	glVertex3f(-358, -40.0, 90.0);//kanan atas
	glVertex3f(-358, -70.0, 90.0);//kanan bawah
	glEnd();
	}
	
	//DindingPembatas(posisi x, posisi y, banyak pembatas, banyak pembatasTengah) --- z nya bakalan sama jadi ga usah masuk parameter
	DindingPembatasSisiKanan(-700, -70, 5, 4);
	DindingPembatasSisiKanan(-200, -70, 2, 1);
	DindingPembatasSisiKanan(300, -70, 2, 1);
	//=========================================================================================================================================================================	

}




void dindingorensebelahKANAN(){
	//--------------sebelah kanannya pintu masuk tapi yang orennya--------------
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-705.0, -35.0, 105.0);//kiri bawah
	glVertex3f(-705.0, 80.0, 105.0);//kiri atas
	glVertex3f(-705.0, 80.0, 40.0);//kanan atas
	glVertex3f(-705.0, -35.0, 40.0);//kanan bawah
	glEnd();
	
	//--------------depan kiri nya jendela pertama dinding oren--------------
	for (i=0 ; i<4 ;i++){
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-705.0 + ( i * 70),-40.0, 105); //kiri bawah
	glVertex3f(-705.0 + ( i * 70), 80.0, 105);//kiri atas
	glVertex3f(-675.0 + ( i * 70), 80.0, 105);//kanan atas
	glVertex3f(-675.0 + ( i * 70), -40.0, 105);//kanan bawah
	glEnd();
	}

	for (i=0 ; i<3 ;i++){
	//--------------depan kanan nya jendela pertama dinding oren--------------
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-635.0 + ( i * 70),-40.0, 105); //kiri bawah
	glVertex3f(-635.0 + ( i * 70), 80.0, 105);//kiri atas
	glVertex3f(-615.0 + ( i * 70), 80.0, 105);//kanan atas
	glVertex3f(-615.0 + ( i * 70), -40.0, 105);//kanan bawah
	glEnd();
	}	
	
	//--------------paling kanan jendela terakhir dinding oren sebelum lengkungan--------------
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-425.0 ,-40.0, 105); //kiri bawah
	glVertex3f(-425.0 , 80.0, 105);//kiri atas
	glVertex3f(-390.0 , 80.0, 105);//kanan atas
	glVertex3f(-390.0 , -40.0, 105);//kanan bawah
	glEnd();
	
	//--------------paling kanan jendela terakhir dinding oren lengkungan--------------
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-390.0 ,-40.0, 105); //kiri bawah
	glVertex3f(-390.0 , 80.0, 105);//kiri atas
	glVertex3f(-370.0 , 80.0, 90);//kanan atas
	glVertex3f(-370.0 , -40.0, 90);//kanan bawah
	glEnd();
	
	//--------------paling kanan jendela terakhir dinding oren setelah lengkungan--------------
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-370.0 , -40.0, 90); //kiri bawah
	glVertex3f(-370.0 , 80.0, 90);//kiri atas
	glVertex3f(-365.0 , 80.0, 90);//kanan atas
	glVertex3f(-365.0 , -40.0, 90);//kanan bawah
	glEnd();
	
	
//-----------------atas nya jendela dinding oren-----------------------------------------------
	for (i=0 ; i<4 ;i++){
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
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
			glVertex3f(-710.0 - (i*5), 80.0 + (i*5), 40);//kiri bawah
			glVertex3f(-375.0 + (i*5), 80.0 + (i*5), 40);//kanan bawah
			glVertex3f(-375.0 + (i*5), 80.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-710.0 - (i*5), 80.0 + (i*5), 115 + (i*5));//kiri atas
			glEnd();
		
			glBegin(GL_QUADS);//atas
			glColor3f(0.81, 0.81, 0.81);
			glVertex3f(-710.0 - (i*5), 85.0 + (i*5), 40);//kiri bawah
			glVertex3f(-375.0 + (i*5), 85.0 + (i*5), 40);//kanan bawah
			glVertex3f(-375.0 + (i*5), 85.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-710.0 - (i*5), 85.0 + (i*5), 115 + (i*5));//kiri atas
			glEnd();
		
			glBegin(GL_QUADS);//kiri
			glColor3f(1,1,1);
			glVertex3f(-710.0 - (i*5), 80.0 + (i*5), 40); //kiri bawah
			glVertex3f(-710.0 - (i*5), 85.0 + (i*5), 40);//kiri atas
			glVertex3f(-710.0 - (i*5), 85.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-710.0 - (i*5), 80.0 + (i*5), 115 + (i*5));//kanan bawah
			glEnd();
		
			glBegin(GL_QUADS);//kanan
			glColor3f(1,1,1);
			glVertex3f(-375.0 + (i*5), 80.0 + (i*5), 40); //kiri bawah
			glVertex3f(-375.0 + (i*5), 85.0 + (i*5), 40);//kiri atas
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
	glVertex3f(-705.0 + (i*80), 210.0, 40.0);//kanan atas
	glVertex3f(-705.0 + (i*80), 95.0, 40.0);//kanan bawah
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
	glVertex3f(-625.0 , 210.0 + (i*115), 40.0);//kanan atas
	glVertex3f(-625.0 , 95.0 + (i*115), 40.0);//kanan bawah
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
	glVertex3f(-545.0 , 210.0 + (i*115), 40.0);//kanan atas
	glVertex3f(-545.0 , 95.0 + (i*115), 40.0);//kanan bawah
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
	glVertex3f(-470.0 , 210.0 + (i*115), 40.0);//kanan atas
	glVertex3f(-470.0 , 95.0 + (i*115), 40.0);//kanan bawah
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
	glVertex3f(-390.0 , 80.0 + (i*115), 105); //kiri bawah
	glVertex3f(-390.0 , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-370.0 , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-370.0 , 80.0 + (i*115), 90);//kanan bawah
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
	
	//kiri & kanan sebelum penyangga ada dinding kecil banget
		for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS);
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-358.0 + ( i * 135) , -40.0, 90); //kiri bawah
		glVertex3f(-358.0 + ( i * 135) , 50.0, 90);//kiri atas
		glVertex3f(-365.0 + ( i * 135) , 50.0, 90);//kanan atas
		glVertex3f(-365.0 + ( i * 135) , -40.0, 90);//kanan bawah
		glEnd();
		}
		
	//--------------KAKI ABU ABU -------------- 
		
		for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS); //kiri
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) , -70.0, 110.0);//kiri bawah
		glVertex3f(-360.0 + ( i * 100) , -50.0, 110.0);//kiri atas
		glVertex3f(-360.0 + ( i * 100) , -50.0, 80.0);//kanan atas
		glVertex3f(-360.0 + ( i * 100) , -70.0, 80.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS); //kanan
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-330.0 + ( i * 100) , -70.0, 110.0);//kiri bawah
		glVertex3f(-330.0 + ( i * 100) , -50.0, 110.0);//kiri atas
		glVertex3f(-330.0 + ( i * 100) , -50.0, 80.0);//kanan atas
		glVertex3f(-330.0 + ( i * 100) , -70.0, 80.0);//kanan bawah
		glEnd();
	
		glBegin(GL_QUADS);//depan
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) , -70.0, 110); //kiri bawah
		glVertex3f(-360.0 + ( i * 100) , -50.0, 110);//kiri atas
		glVertex3f(-330.0 + ( i * 100) , -50.0, 110);//kanan atas
		glVertex3f(-330.0 + ( i * 100) , -70.0, 110);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) , -70.0, 80); //kiri bawah
		glVertex3f(-360.0 + ( i * 100) , -50.0, 80);//kiri atas
		glVertex3f(-330.0 + ( i * 100) , -50.0, 80);//kanan atas
		glVertex3f(-330.0 + ( i * 100) , -70.0, 80);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) , -50.0, 80);//kiri bawah
		glVertex3f(-330.0 + ( i * 100) , -50.0, 80);//kanan bawah
		glVertex3f(-330.0 + ( i * 100) , -50.0, 110);//kanan atas
		glVertex3f(-360.0 + ( i * 100) , -50.0, 110);//kiri atas
		glEnd();
		}
		
	//--------------Gardu-------------- 
		for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS); //kiri
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-358.0 + ( i * 100) , -50.0, 110.0);//kiri bawah
		glVertex3f(-358.0 + ( i * 100) , 50.0, 110.0);//kiri atas
		glVertex3f(-358.0 + ( i * 100) , 50.0, 80.0);//kanan atas
		glVertex3f(-358.0 + ( i * 100) , -50.0, 80.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS); //kanan
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-330.0 + ( i * 100) , -50.0, 110.0);//kiri bawah
		glVertex3f(-330.0 + ( i * 100) , 50.0, 110.0);//kiri atas
		glVertex3f(-330.0 + ( i * 100) , 50.0, 80.0);//kanan atas
		glVertex3f(-330.0 + ( i * 100) , -50.0, 80.0);//kanan bawah
		glEnd();
	
		glBegin(GL_QUADS);//depan
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-358.0 + ( i * 100) , -50.0, 110); //kiri bawah
		glVertex3f(-358.0 + ( i * 100) , 50.0, 110);//kiri atas
		glVertex3f(-330.0 + ( i * 100) , 50.0, 110);//kanan atas
		glVertex3f(-330.0 + ( i * 100) , -50.0, 110);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-358.0 + ( i * 100) , -50.0, 80); //kiri bawah
		glVertex3f(-358.0 + ( i * 100) , 50.0, 80);//kiri atas
		glVertex3f(-330.0 + ( i * 100) , 50.0, 80);//kanan atas
		glVertex3f(-330.0 + ( i * 100) , -50.0, 80);//kanan bawah
		glEnd();
		}
		
	//--------------Atap Gardu-------------- 
		glBegin(GL_QUADS);//atap gardu (alas)
			glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-365.0 , 50.0, 10); //kiri bawah
		glVertex3f(-218.0 , 50.0, 10);//kanan atas
		glVertex3f(-218.0 , 50.0, 95);//kanan bawah
		glVertex3f(-365.0 , 50.0, 95);//kiri atas
		glEnd();
	
		glBegin(GL_QUADS);//atap gardu (atas)
			glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0 , 80.0, 10); //kiri bawah
		glVertex3f(-218.0 , 80.0, 10);//kanan atas
		glVertex3f(-218.0 , 80.0, 95);//kanan bawah
		glVertex3f(-370.0 , 80.0, 95);//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//atap gardu (depan)
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0, 50.0, 95); //kiri bawah
		glVertex3f(-370.0, 80.0, 95);//kiri atas
		glVertex3f(-218.0, 80.0, 95);//kanan atas
		glVertex3f(-218.0, 50.0, 95);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atap gardu (belakang)
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0, 50.0, 10); //kiri bawah
		glVertex3f(-370.0, 80.0, 10);//kiri atas
		glVertex3f(-218.0, 80.0, 10);//kanan atas
		glVertex3f(-218.0, 50.0, 10);//kanan bawah
		glEnd();
		
		
		for (i=0;i<2;i++){
		glBegin(GL_QUADS); //atap gardu (kiri kanan)
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0 + ( i * 152) , 50.0, 95.0);//kiri bawah
		glVertex3f(-370.0 + ( i * 152) , 80.0, 95.0);//kiri atas
		glVertex3f(-370.0 + ( i * 152) , 80.0, 10.0);//kanan atas
		glVertex3f(-370.0 + ( i * 152) , 50.0, 10.0);//kanan bawah
		glEnd();
		}
	
	//--------------Atasnya Atap Gardu--------------
	
		for (i=0;i<2;i++){
		glBegin(GL_QUADS);//bawah
		glColor3f(0.81, 0.81, 0.81);
		glVertex3f(-361.0 - (i*5) , 50.1 + (i*10), 95); //kiri bawah
		glVertex3f(-227.0 + (i*5) , 50.1 + (i*10), 95);//kanan atas
		glVertex3f(-227.0 + (i*5) , 50.1 + (i*10), 120 + (i*5));//kanan bawah
		glVertex3f(-361.0 - (i*5) , 50.1 + (i*10), 120 + (i*5));//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-361.0 - (i*5) , 60.0 + (i*10), 95); //kiri bawah
		glVertex3f(-227.0 + (i*5) , 60.0 + (i*10), 95);//kanan atas
		glVertex3f(-227.0 + (i*5) , 60.0 + (i*10), 120 + (i*5));//kanan bawah
		glVertex3f(-361.0 - (i*5) , 60.0 + (i*10), 120 + (i*5));//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//kiri
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-361.0 - (i*5) , 60.0 + (i*10), 120.0 + (i*5));//kiri bawah
		glVertex3f(-361.0 - (i*5) , 50.0 + (i*10), 120.0 + (i*5));//kiri atas
		glVertex3f(-361.0 - (i*5) , 50.0 + (i*10), 95.0);//kanan atas
		glVertex3f(-361.0 - (i*5) , 60.0 + (i*10), 95.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kanan
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-227 + (i*5) , 60.0 + (i*10), 120.0 + (i*5));//kiri bawah
		glVertex3f(-227 + (i*5) , 50.0 + (i*10), 120.0 + (i*5));//kiri atas
		glVertex3f(-227 + (i*5) , 50.0 + (i*10), 95.0);//kanan atas
		glVertex3f(-227 + (i*5) , 60.0 + (i*10), 95.0);//kanan bawah
		glEnd();
		
		
		glBegin(GL_QUADS);//depan
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-361.0 - (i*5) , 50.0 + (i*10), 120 + (i*5)); //kiri bawah
		glVertex3f(-361.0 - (i*5) , 60.0 + (i*10), 120 + (i*5));//kiri atas
		glVertex3f(-227.0 + (i*5) , 60.0 + (i*10), 120 + (i*5));//kanan atas
		glVertex3f(-227.0 + (i*5) , 50.0 + (i*10), 120 + (i*5));//kanan bawah
		glEnd();
		}
	
		
	//--------------tembok bagian dalem pintu masuk kanan kiri-------------- 		
		for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS); //kiri
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 + ( i * 100) , 50.0, 80.0);//kiri bawah
		glVertex3f(-344.0 + ( i * 100) , -70.0, 80.0);//kiri atas
		glVertex3f(-344.0 + ( i * 100) , -70.0, 60.0);//kanan atas
		glVertex3f(-344.0 + ( i * 100) , 50.0, 60.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS); //kanan
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 + ( i * 100) , 50.0, 30.0);//kiri bawah
		glVertex3f(-344.0 + ( i * 100) , -70.0, 30.0);//kiri atas
		glVertex3f(-344.0 + ( i * 100) , -70.0, 10.0);//kanan atas
		glVertex3f(-344.0 + ( i * 100) , 50.0, 10.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS); //atas
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 + ( i * 100) , 50.0, 80.0);//kiri bawah
		glVertex3f(-344.0 + ( i * 100) , 25.0, 80.0);//kiri atas
		glVertex3f(-344.0 + ( i * 100) , 25.0, 10.0);//kanan atas
		glVertex3f(-344.0 + ( i * 100) , 50.0, 10.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS); //pintu
		glColor3f (0.0 , 0.0 , 0.0);
		glVertex3f(-344.0 + ( i * 100) , 25.0, 60.0);//kiri bawah
		glVertex3f(-344.0 + ( i * 100) , -70.0, 60.0);//kiri atas
		glVertex3f(-344.0 + ( i * 100) , -70.0, 30.0);//kanan atas
		glVertex3f(-344.0 + ( i * 100) , 25.0, 30.0);//kanan bawah
		glEnd();
		}
		
		glBegin(GL_QUADS);//tengah kiri
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 , -70.0, 10); //kiri bawah
		glVertex3f(-344.0 , 50.0, 10);//kiri atas
		glVertex3f(-319.0 , 50.0, 10);//kanan atas
		glVertex3f(-319.0 , -70.0, 10);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//tengah atas
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 , 25.0, 10); //kiri bawah
		glVertex3f(-344.0 , 50.0, 10);//kiri atas
		glVertex3f(-244.0 , 50.0, 10);//kanan atas
		glVertex3f(-244.0 , 25.0, 10);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//tengah atap
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 , 49.9, 10); //kiri bawah
		glVertex3f(-244.0 , 49.9, 10);//kanan atas
		glVertex3f(-244.0 , 49.9, 80);//kanan bawah
		glVertex3f(-344.0 , 49.9, 80);//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//pintu kiri
		glColor3f (0.0 ,0.0 , 0.0);
		glVertex3f(-319.0 , -70.0, 10); //kiri bawah
		glVertex3f(-319.0 , 25.0, 10);//kiri atas
		glVertex3f(-294.0 , 25.0, 10);//kanan atas
		glVertex3f(-294.0 , -70.0, 10);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//pintu kanan
		glColor3f (0.0 ,0.0 , 0.0);		
		glVertex3f(-294.0 , -70.0, 10); //kiri bawah
		glVertex3f(-294.0 , 25.0, 10);//kiri atas
		glVertex3f(-269.0 , 25.0, 10);//kanan atas
		glVertex3f(-269.0 , -70.0, 10);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//tengah kanan
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-269.0 , -70.0, 10); //kiri bawah
		glVertex3f(-269.0 , 50.0, 10);//kiri atas
		glVertex3f(-244.0 , 50.0, 10);//kanan atas
		glVertex3f(-244.0 , -70.0, 10);//kanan bawah
		glEnd();
		
		
//--------------tembok putih atas pintu masuk samping-------------- 
	for (i=0 ; i<3 ; i++){
	//--------------depan kiri nya jendela pertama dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-370.0 , 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-370.0 , 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-345.0 , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-345.0 , 95.0 + (i*115), 90);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kiri jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-320.0  , 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-320.0  , 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-315.0  , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-315.0  , 95.0 + (i*115), 90);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kanan jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-275.0 , 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-275.0 , 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-265.0 , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-270.0 , 95.0 + (i*115), 90);//kanan bawah
	glEnd();
		
		
	//--------------atas nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-345.0 , 195.0 + (i*115), 90); //kiri bawah
	glVertex3f(-345.0 , 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-220.0 , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-220.0 , 195.0 + (i*115), 90);//kanan bawah
	glEnd();
		
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-345.0 , 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-345.0 , 110.0 + (i*115), 90);//kiri atas
	glVertex3f(-220.0 , 110.0 + (i*115), 90);//kanan atas
	glVertex3f(-220.0 , 95.0 + (i*115), 90);//kanan bawah
	glEnd();	
	
	//--------------paling kanan terakhir setelah jendela ketiga dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-245.0 , 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-245.0 , 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-220.0 , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-220.0 , 95.0 + (i*115), 90);//kanan bawah
	glEnd();
	}
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS); //TAMBAHAN MUNGIL
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-370.0 , 50.0, 90); //kiri bawah
	glVertex3f(-370.0 , 95.0, 90);//kiri atas
	glVertex3f(-220.0 , 95.0, 90);//kanan atas
	glVertex3f(-220.0 , 50.0, 90);//kanan bawah
	glEnd();
}






void setelahpintusampingkanan(int x , int Y){
	
	//dinding oren setelah gardu kanannya
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-230.0 + x , -40.0, 90); //kiri bawah
	glVertex3f(-230.0 + x , 50.0, 90);//kiri atas
	glVertex3f(-220.0 + x , 50.0, 90);//kanan atas
	glVertex3f(-220.0 + x , -40.0, 90);//kanan bawah
	glEnd();
	
	for (i=0 ; i<3 ; i++){
	//--------------------------lengkungan dinding putih samping pintusamping---------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-220.0 + x , 80.0 +(i*115), 90); //kiri bawah
	glVertex3f(-220.0 + x , 210.0 +(i*115), 90);//kiri atas
	glVertex3f(-200.0 + x , 210.0 +(i*115), 105);//kanan atas
	glVertex3f(-200.0 + x , 80.0 +(i*115), 105);//kanan bawah
	glEnd();
	
	//--------------lengkungan pintu--------------
	glBegin(GL_QUADS); //utama kiri
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-220 + x , -70.0, 90.0);//kiri bawah
	glVertex3f(-220 + x , -35.0, 90.0);//kiri atas
	glVertex3f(-200 + x , -35.0, 110.0);//kanan atas
	glVertex3f(-200 + x , -70.0, 110.0);//kanan bawah
	glEnd();
	
	glBegin(GL_QUADS); //alas kiri abu abu tengah
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-243 + x , -70.0, 90.0);//kiri bawah
	glVertex3f(-243 + x , -40.0, 90.0);//kiri atas
	glVertex3f(-220 + x , -40.0, 90.0);//kanan atas
	glVertex3f(-220 + x , -70.0, 90.0);//kanan bawah
	glEnd();
	
	//--------------lengkungan dinding oren yang samping nya pintu samping--------------
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-220.0 + x , -35.0, 90); //kiri bawah
	glVertex3f(-220.0 + x , 80.0, 90);//kiri atas
	glVertex3f(-200.0 + x , 80.0, 105);//kanan atas
	glVertex3f(-200.0 + x , -35.0, 105);//kanan bawah
	glEnd();
	}
	
//---------------------------------------------------------------------------------------------	
	
	
	//--------------pengantara alas & dinding-------------- (lengkungan Depan)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-220.0 + x , -40.0, 95); //kiri bawah
	glVertex3f(-220.0 + x , -35.0, 95);//kiri atas
	glVertex3f(-200.0 + x , -35.0, 115);//kanan atas
	glVertex3f(-200.0 + x , -40.0, 115);//kanan bawah
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (lengkungan Atas)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-220.0 + x , -35.0, 90);//kiri bawah
	glVertex3f(-200.0 + x , -35.0, 90);//kanan bawah
	glVertex3f(-200.0 + x , -35.0, 115);//kanan atas
	glVertex3f(-220.0 + x , -35.0, 95);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (Kiri Akhir depan)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-240.0 + x , -40.0, 95); //kiri bawah
	glVertex3f(-240.0 + x , -35.0, 95);//kiri atas
	glVertex3f(-220.0 + x , -35.0, 95);//kanan atas
	glVertex3f(-220.0 + x , -40.0, 95);//kanan bawah
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (Kiri Akhir Atas)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-240.0 + x , -35.0, 90);//kiri bawah
	glVertex3f(-220.0 + x , -35, 90);//kanan bawah
	glVertex3f(-220.0 + x , -35.0, 95);//kanan atas
	glVertex3f(-240.0 + x , -35.0, 95);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (Kiri Akhir bawah)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-240.0 + x , -40.0, 90);//kiri bawah
	glVertex3f(-220.0 + x , -40, 90);//kanan bawah
	glVertex3f(-220.0 + x , -40.0, 95);//kanan atas
	glVertex3f(-240.0 + x , -40.0, 95);//kiri atas
	glEnd();
	
	//--------------tembok alas----------------------------- (panjang antar pembatas alas 90)
	glBegin(GL_QUADS);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-200.0 + x , -70.0, 110.0);//kiri bawah
	glVertex3f(-200.0 + x , -40.0, 110.0);//kiri atas
	glVertex3f(-97 + x , -40.0, 110.0);//kanan atas
	glVertex3f(-97 + x , -70.0, 110.0);//kanan bawah
	glEnd();
	

	//--------------pengantara alas & dinding-------------- (depan)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-200.0 + x , -40.0, 115); //kiri bawah
	glVertex3f(-200.0 + x , -35.0, 115);//kiri atas
	glVertex3f(-100.0 + x , -35.0, 115);//kanan atas
	glVertex3f(-100.0 + x , -40.0, 115);//kanan bawah
	glEnd();
	
	///--------------pengantara alas & dinding-------------- (atas)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-200.0 + x , -35.0, 90);//kiri bawah
	glVertex3f(-100.0 + x , -35, 90);//kanan bawah
	glVertex3f(-100.0 + x , -35.0, 115);//kanan atas
	glVertex3f(-200.0 + x , -35.0, 115);//kiri atas
	glEnd();
	
	//--------------Bagian Atas  dinding alas-------------
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-200.0 + x , -40.0, 90);//kiri bawah
	glVertex3f(-100.0 + x , -40, 90);//kanan bawah
	glVertex3f(-100.0 + x , -40.0, 115);//kanan atas
	glVertex3f(-200.0 + x , -40.0, 115);//kiri atas
	glEnd();
	
	//---------------lengkungan samping pintu yang kanan
	glBegin(GL_QUADS);
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-110.0 + x , -70.0, 115); //kiri bawah
	glVertex3f(-110.0 + x , -40.0, 115);//kiri atas
	glVertex3f(-90.0 + x , -40.0, 90);//kanan atas
	glVertex3f(-90.0 + x , -70.0, 90);//kanan bawah
	glEnd();
	
	
	
//--------------------------------------------------------------------------------------------	
	
	//--------------pengantara alas & dinding-------------- (lengkungan Depan)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-100.0 + x , -40.0, 115); //kiri bawah
	glVertex3f(-100.0 + x , -35.0, 115);//kiri atas
	glVertex3f(-80.0 + x , -35.0, 95);//kanan atas
	glVertex3f(-80.0 + x , -40.0, 95);//kanan bawah
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (lengkungan Atas)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-100.0 + x , -35.0, 90);//kiri bawah
	glVertex3f(-80.0 + x , -35, 90);//kanan bawah
	glVertex3f(-80.0 + x , -35.0, 95);//kanan atas
	glVertex3f(-100.0 + x , -35.0, 115);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (Kanan Akhir depan)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-90.0 + x , -40.0, 95); //kiri bawah
	glVertex3f(-90.0 + x , -35.0, 95);//kiri atas
	glVertex3f(-80.0 + x + Y, -35.0, 95);//kanan atas
	glVertex3f(-80.0 + x + Y, -40.0, 95);//kanan bawah
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (Kanan Akhir Atas)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-90.0 + x , -35.0, 90);//kiri bawah
	glVertex3f(-80.0 + x + Y, -35, 90);//kanan bawah
	glVertex3f(-80.0 + x + Y, -35.0, 95);//kanan atas
	glVertex3f(-90.0 + x , -35.0, 95);//kiri atas
	glEnd();
	
	//--------------pengantara alas & dinding-------------- (Kanan Akhir bawah)
	glBegin(GL_QUADS);
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-90.0 + x , -40.0, 90);//kiri bawah
	glVertex3f(-80.0 + x + Y, -40, 90);//kanan bawah
	glVertex3f(-80.0 + x + Y, -40.0, 95);//kanan atas
	glVertex3f(-90.0 + x , -40.0, 95);//kiri atas
	glEnd();
	
//==========================Jendela Dinding oren--------------------

	//--------------depan kiri nya jendela pertama dinding oren--------------
	for (i=0 ; i<2 ;i++){
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-200.0 + ( i * 70) + x ,-40.0, 105); //kiri bawah
	glVertex3f(-200.0 + ( i * 70) + x , 80.0, 105);//kiri atas
	glVertex3f(-175.0 + ( i * 70) + x , 80.0, 105);//kanan atas
	glVertex3f(-175.0 + ( i * 70) + x , -40.0, 105);//kanan bawah
	glEnd();
	}
	
	//--------------lengkungan pintu--------------
	glBegin(GL_QUADS); //utama kanan
	glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
	glVertex3f(-220 + x , -70.0, 90.0);//kiri bawah
	glVertex3f(-220 + x , -35.0, 90.0);//kiri atas
	glVertex3f(-200 + x , -35.0, 110.0);//kanan atas
	glVertex3f(-200 + x , -70.0, 110.0);//kanan bawah
	glEnd();
	
	glBegin(GL_QUADS); //atasnya jendela
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-175.0 + x , 50.0, 105); //kiri bawah
	glVertex3f(-175.0 + x , 80.0, 105);//kiri atas
	glVertex3f(-105.0 + x , 80.0, 105);//kanan atas
	glVertex3f(-105.0 + x , 50.0, 105);//kanan bawah
	glEnd();

	glBegin(GL_QUADS); //kanannya utama kanan
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-105.0 + x , -35.0, 105); //kiri bawah
	glVertex3f(-105.0 + x , 80.0, 105);//kiri atas
	glVertex3f(-90.0 + x , 80.0, 90);//kanan atas
	glVertex3f(-90.0 + x , -35.0, 90);//kanan bawah
	glEnd();
	
	
//==========================sambungan dinding oren sama putih--------------------	
	for (i=0;i<3;i++){
			glBegin(GL_QUADS);//bawah
			glColor3f(0.81, 0.81, 0.81);
			glVertex3f(-210.0 - (i*5) + x , 80.0 + (i*5), 90);//kiri bawah
			glVertex3f(-100.0 + (i*5) + x , 80.0 + (i*5), 90);//kanan bawah
			glVertex3f(-100.0 + (i*5) + x , 80.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-210.0 - (i*5) + x , 80.0 + (i*5), 115 + (i*5));//kiri atas
			glEnd();
		
			glBegin(GL_QUADS);//atas
			glColor3f(0.81, 0.81, 0.81);
			glVertex3f(-210.0 - (i*5) + x , 85.0 + (i*5), 90);//kiri bawah
			glVertex3f(-100.0 + (i*5) + x , 85.0 + (i*5), 90);//kanan bawah
			glVertex3f(-100.0 + (i*5) + x , 85.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-210.0 - (i*5) + x , 85.0 + (i*5), 115 + (i*5));//kiri atas
			glEnd();
		
			glBegin(GL_QUADS);//kiri
			glColor3f(1,1,1);
			glVertex3f(-210.0 - (i*5) + x , 80.0 + (i*5), 90); //kiri bawah
			glVertex3f(-210.0 - (i*5) + x , 85.0 + (i*5), 90);//kiri atas
			glVertex3f(-210.0 - (i*5) + x , 85.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-210.0 - (i*5) + x , 80.0 + (i*5), 115 + (i*5));//kanan bawah
			glEnd();
		
			glBegin(GL_QUADS);//kanan
			glColor3f(1,1,1);
			glVertex3f(-100.0 + (i*5) + x , 80.0 + (i*5), 90); //kiri bawah
			glVertex3f(-100.0 + (i*5) + x , 85.0 + (i*5), 90);//kiri atas
			glVertex3f(-100.0 + (i*5) + x , 85.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-100.0 + (i*5) + x , 80.0 + (i*5), 115 + (i*5));//kanan bawah
			glEnd();
		
			glBegin(GL_QUADS);
			glColor3f(1,1,1); //depan
			glVertex3f(-210.0 - (i*5) + x , 80.0 + (i*5), 115 + (i*5)); //kiri bawah
			glVertex3f(-210.0 - (i*5) + x , 85.0 + (i*5), 115 + (i*5));//kiri atas
			glVertex3f(-100.0 + (i*5) + x , 85.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-100.0 + (i*5) + x , 80.0 + (i*5), 115 + (i*5));//kanan bawah
			glEnd();
			}
			
//------------------------------------- DINDING PUTIH ----------------------------
	for (i=0 ; i<3 ; i++){

	//--------------depan kiri nya jendela pertama dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-200.0 + x , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-200.0 + x , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-185.0 + x , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-185.0 + x , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kiri jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-163.0  + x , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-163.0  + x , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-161.0  + x , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-161.0  + x , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kanan jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-134.0 + x , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-134.0 + x , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-132.0 + x , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-132.0 + x , 95.0 + (i*115), 105);//kanan bawah
	glEnd();
	
		
	//--------------atas nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-185.0 + x , 195.0 + (i*115), 105); //kiri bawah
	glVertex3f(-185.0 + x , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-185.0 + 90 + x , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-185.0 + 90 + x , 195.0 + (i*115), 105);//kanan bawah
	glEnd();
		
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-185.0  + x , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-185.0  + x , 110.0 + (i*115), 105);//kiri atas
	glVertex3f(-185.0 + 90 + x , 110.0 + (i*115), 105);//kanan atas
	glVertex3f(-185.0 + 90 + x , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	
	
	//--------------depan kiri nya jendela pertama dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-200.0  + 90 + x , 95.0 + (i*115), 105); //kiri bawah
	glVertex3f(-200.0  + 90 + x , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-185.0  + 90 + x , 210.0 + (i*115), 105);//kanan atas
	glVertex3f(-185.0  + 90 + x , 95.0 + (i*115), 105);//kanan bawah
	glEnd();	
	
	//--------------depan kanan nya jendela ketiga dinding putih--------------
	
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-105.0 + x , 80.0 + (i*115), 105); //kiri bawah
	glVertex3f(-105.0 + x , 210.0 + (i*115), 105);//kiri atas
	glVertex3f(-90.0 + x , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-90.0 + x , 80.0 + (i*115), 90);//kanan bawah
	glEnd();
	}
	
	//-----------------------dinding oren lengkungan kanan 
	glBegin(GL_QUADS);
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-90.0 + x , -40.0, 90); //kiri bawah
	glVertex3f(-90.0 + x , 80.0, 90);//kiri atas
	glVertex3f(-80.0 + x , 80.0, 90);//kanan atas
	glVertex3f(-80.0 + x , -40.0, 90);//kanan bawah
	glEnd();
			
	//-----------------------dinding alas kanan setelah lengkungan	
	glBegin(GL_QUADS);
	glColor3f(0.48, 0.48, 0.48);
	glVertex3f(-90.0 + x , -70.0, 90); //kiri bawah
	glVertex3f(-90.0 + x , -40.0, 90);//kiri atas
	glVertex3f(-80.0 + x + Y , -40.0, 90);//kanan atas
	glVertex3f(-80.0 + x + Y , -70.0, 90);//kanan bawah
	glEnd();
	
	//-----------------------dinding alas kanan setelah lengkungan	
	for (i=0;i<3;i++){
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-90.0 + x , 80.0 + (i*115), 90); //kiri bawah
	glVertex3f(-90.0 + x , 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-80.0 + x , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-80.0 + x , 80.0 + (i*115), 90);//kanan bawah
	glEnd();
	
	
	}
}






void tengahnyasisikananbangunan(int x , int y , int z){
	
	//-------------------Pintu--------------------
	for (i=0;i<2;i++){
	glBegin(GL_QUADS);//tembok dalem kanan
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-80.0 + x , -35.0, 105.0 - y);//kiri bawah
	glVertex3f(-80.0 + x , 80.0, 105.0 - y);//kiri atas
	glVertex3f(-80.0 + x , 80.0, 50.0);//kanan atas
	glVertex3f(-80.0 + x , -35.0, 50.0);//kanan bawah
	glEnd();
	}
	
	for (i=0;i<2;i++){
	glBegin(GL_QUADS);//tembok dalem kanan
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(40.0 + x , -35.0, 50.0);//kiri bawah
	glVertex3f(40.0 + x , 80.0, 50.0);//kiri atas
	glVertex3f(40.0 + x , 80.0, 50.0 + z);//kanan atas
	glVertex3f(40.0 + x , -35.0, 50.0 + z);//kanan bawah
	glEnd();
	}
	
	for (i=0;i<2;i++){
	glBegin(GL_QUADS);//kiri kanan sebelum pintu
	glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
	glVertex3f(-80.0 + (i*110) + x , -35.0, 50); //kiri bawah
	glVertex3f(-80.0 + (i*110) + x , 80.0, 50);//kiri atas
	glVertex3f(-70.0 + (i*110) + x , 80.0, 50);//kanan atas
	glVertex3f(-70.0 + (i*110) + x , -35.0, 50);//kanan bawah
	glEnd();
	}
	
	for (i=0;i<2;i++){
	glBegin(GL_QUADS);//kiri atau kanan nya pintu kiri dan pintu kanan
	glColor3f (0.8235294117647059 , 0.4117647058823529 , 0.1176470588235294);
	glVertex3f(-70.0 + (i*90) + x , -35.0, 50); //kiri bawah
	glVertex3f(-70.0 + (i*90) + x , 80.0, 50);//kiri atas
	glVertex3f(-60.0 + (i*90) + x , 80.0, 50);//kanan atas
	glVertex3f(-60.0 + (i*90) + x , -35.0, 50);//kanan bawah
	glEnd();
	}
	
	for (i=0;i<2;i++){
	glBegin(GL_QUADS);//atas
	glColor3f (0.8235294117647059 , 0.4117647058823529 , 0.1176470588235294);
	glVertex3f(-60.0 + (i*43) + x , 60.0, 50 - (i*15)); //kiri bawah
	glVertex3f(-60.0 + (i*43) + x , 80.0, 50 - (i*15));//kiri atas
	glVertex3f(-20.0 + (i*40) + x , 80.0, 50);//kanan atas
	glVertex3f(-20.0 + (i*40) + x , 60.0, 50);//kanan bawah
	glEnd();
	}
	
	for (i=0;i<2;i++){
	glBegin(GL_QUADS);//bawah
	glColor3f (0.8235294117647059 , 0.4117647058823529 , 0.1176470588235294);
	glVertex3f(-60.0 + (i*43) + x , -35.0, 50 - (i*15)); //kiri bawah
	glVertex3f(-60.0 + (i*43) + x , 0.0, 50 - (i*15));//kiri atas
	glVertex3f(-20.0 + (i*40) + x , 0.0, 50);//kanan atas
	glVertex3f(-20.0 + (i*40) + x , -35.0, 50);//kanan bawah
	glEnd();
	}
	
	for (i=0;i<2;i++){
	glBegin(GL_QUADS);//kanan atau kiri
	glColor3f (0.8235294117647059 , 0.4117647058823529 , 0.1176470588235294);
	glVertex3f(-30.0 + (i*13) + x , 0.0, 50 - (i*16)); //kiri bawah
	glVertex3f(-30.0 + (i*13) + x , 60.0, 50 - (i*16));//kiri atas
	glVertex3f(-20.0 + (i*11) + x , 60.0, 50 - (i*11));//kanan atas
	glVertex3f(-20.0 + (i*11) + x , 0.0, 50 - (i*11));//kanan bawah
	glEnd();
	}
	
	//-----------------atapnya-----------------------
	
	glBegin(GL_QUADS);//atas
	glColor3f(1,1,1);
	glVertex3f(-80.1 + x , 80.0, 50);//kiri bawah
	glVertex3f(39.9 + x , 80.0, 50);//kanan bawah
	glVertex3f(39.9 + x , 80.0 , 105);//kanan atas
	glVertex3f(-80.1 + x , 80.0 , 105);//kiri atas
	glEnd();
	glBegin(GL_QUADS); //depan
	glColor3f(1,1,1);
	glVertex3f(-80.0  + x , 80.0, 105); //kiri bawah
	glVertex3f(-80.0  + x , 60.0, 105);//kiri atas
	glVertex3f(40.0  + x , 60, 105);//kanan atas
	glVertex3f(40.0  + x , 80.0, 105);//kanan bawah
	glEnd();
	
	
	//--------------------------tangga
	
	for (i=0;i<4;i++){
	glBegin(GL_QUADS); //depan
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-80.0  + x , -70.0 + (i*10), 130  - (i*10)); //kiri bawah
	glVertex3f(-80.0  + x , -60.0 + (i*10), 130  - (i*10));//kiri atas
	glVertex3f(40.0  + x , -60 + (i*10), 130 - (i*10));//kanan atas
	glVertex3f(40.0  + x , -70.0 + (i*10), 130 - (i*10));//kanan bawah
	glEnd();
	}
	
	for (i=0;i<4;i++){
	glBegin(GL_QUADS);//kiri
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(-80.1 + x , -70.0 + (i*10), 50); //kiri bawah
	glVertex3f(-80.1 + x , -60.0 + (i*10), 50);//kiri atas
	glVertex3f(-80.1 + x , -60.0 + (i*10), 130 - (i*10));//kanan atas
	glVertex3f(-80.1 + x , -70.0 + (i*10), 130 - (i*10));//kanan bawah
	glEnd();
	}
	
	for (i=0;i<4;i++){
	glBegin(GL_QUADS);//kanan
	glColor3f(0.41, 0.41, 0.41);
	glVertex3f(39.9 + x , -70.0 + (i*10), 50); //kiri bawah
	glVertex3f(39.9 + x , -60.0 + (i*10), 50);//kiri atas
	glVertex3f(39.9 + x , -60.0 + (i*10), 130 - (i*10));//kanan atas
	glVertex3f(39.9 + x , -70.0 + (i*10), 130 - (i*10));//kanan bawah
	glEnd();
	}
	
	for (i=0;i<4;i++){
	glBegin(GL_QUADS);//atas
	glColor3f(0.61, 0.61, 0.61);
	glVertex3f(-80.1 + x , -60.0 + (i*10), 50);//kiri bawah
	glVertex3f(39.9 + x , -60.0 + (i*10), 50);//kanan bawah
	glVertex3f(39.9 + x , -60.0 + (i*10), 130 - (i*10));//kanan atas
	glVertex3f(-80.1 + x , -60.0 + (i*10), 130 - (i*10));//kiri atas
	glEnd();
	}
	
	
	//--------------------------tembok putih 	
	
	for (i=0 ; i<3 ; i++){
	//--------------depan kiri nya jendela pertama dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-80.0  + x , 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-80.0  + x , 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-65.0  + x , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-65.0  + x , 95.0 + (i*115), 90);//kanan bawah
	glEnd();		
 	
	//--------------atas nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-65.0  + x , 195.0 + (i*115), 90); //kiri bawah
	glVertex3f(-65.0  + x , 210.0 + (i*115), 90);//kiri atas
	glVertex3f(40.0  + x , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(40.0  + x , 195.0 + (i*115), 90);//kanan bawah
	glEnd();	
		
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-65.0  + x , 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-65.0  + x , 110.0 + (i*115), 90);//kiri atas
	glVertex3f(40.0  + x , 110.0 + (i*115), 90);//kanan atas
	glVertex3f(40.0  + x , 95.0 + (i*115), 90);//kanan bawah
	glEnd();	
	
	//--------------paling kanan terakhir setelah jendela ketiga dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(25.0  + x , 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(25.0  + x , 210.0 + (i*115), 90);//kiri atas
	glVertex3f(40.0  + x , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(40.0  + x , 95.0 + (i*115), 90);//kanan bawah
	glEnd();
	}
	
	for (i=0;i<2;i++){	
	//--------------pemisah jendela--------------	
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-25.0  + x , 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-25.0  + x , 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-15.0  + x , 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-15.0  + x , 95.0 + (i*115), 90);//kanan bawah
	glEnd();
	}
	
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS); //TAMBAHAN MUNGIL
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-90.0  + x , 80.0, 90); //kiri bawah
	glVertex3f(-90.0  + x , 95.0, 90);//kiri atas
	glVertex3f(40.0  + x , 95.0, 90);//kanan atas
	glVertex3f(40.0  + x , 80.0, 90);//kanan bawah
	glEnd();
	
}


void sisikananPALINGAKHIRYUHUUUU(){
	tengahnyasisikananbangunan(120 , 55 , 0);
}

void tengahkananyangkedua(){
	tengahnyasisikananbangunan(240 , 55 , 55);
}

void benerbeneryangterakhir(){
	setelahpintusampingkanan(500 , 90);
}

void pintuparkirankanan(int x = 860){
		//kiri & kanan sebelum penyangga ada dinding kecil banget
		
		glBegin(GL_QUADS);
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(408.0 , -40.0, 90); //kiri bawah
		glVertex3f(408.0 , 80.0, 90);//kiri atas
		glVertex3f(-345.0 + x, 80.0, 90);//kanan atas
		glVertex3f(-345.0 + x, -40.0, 90);//kanan bawah
		glEnd();
		
		
	//--------------KAKI ABU ABU -------------- 
		
		for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS); //kiri
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) + x, -70.0, 110.0);//kiri bawah
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 110.0);//kiri atas
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 80.0);//kanan atas
		glVertex3f(-360.0 + ( i * 100) + x, -70.0, 80.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS); //kanan
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-330.0 + ( i * 100) + x, -70.0, 110.0);//kiri bawah
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 110.0);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 80.0);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -70.0, 80.0);//kanan bawah
		glEnd();
	
		glBegin(GL_QUADS);//depan
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) + x, -70.0, 110); //kiri bawah
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 110);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 110);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -70.0, 110);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) + x, -70.0, 80); //kiri bawah
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 80);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 80);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -70.0, 80);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (0.4929411764705882 , 0.4929411764705882 , 0.4929411764705882);
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 80);//kiri bawah
		glVertex3f(-330.0 + ( i * 100) + x , -50.0, 80);//kanan bawah
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 110);//kanan atas
		glVertex3f(-360.0 + ( i * 100) + x, -50.0, 110);//kiri atas
		glEnd();
		}
		
	//--------------Gardu-------------- 
		for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS); //kiri
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-358.0 + ( i * 100) + x, -50.0, 110.0);//kiri bawah
		glVertex3f(-358.0 + ( i * 100) + x, 50.0, 110.0);//kiri atas
		glVertex3f(-358.0 + ( i * 100) + x, 50.0, 80.0);//kanan atas
		glVertex3f(-358.0 + ( i * 100) + x, -50.0, 80.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS); //kanan
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 110.0);//kiri bawah
		glVertex3f(-330.0 + ( i * 100) + x, 50.0, 110.0);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, 50.0, 80.0);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 80.0);//kanan bawah
		glEnd();
	
		glBegin(GL_QUADS);//depan
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-358.0 + ( i * 100) + x, -50.0, 110); //kiri bawah
		glVertex3f(-358.0 + ( i * 100) + x, 50.0, 110);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, 50.0, 110);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 110);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//belakang
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-358.0 + ( i * 100) + x, -50.0, 80); //kiri bawah
		glVertex3f(-358.0 + ( i * 100) + x, 50.0, 80);//kiri atas
		glVertex3f(-330.0 + ( i * 100) + x, 50.0, 80);//kanan atas
		glVertex3f(-330.0 + ( i * 100) + x, -50.0, 80);//kanan bawah
		glEnd();
		}
		
	//--------------Atap Gardu-------------- 
		glBegin(GL_QUADS);//atap gardu (alas)
			glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-365.0 + x, 50.0, 10); //kiri bawah
		glVertex3f(-218.0 + x, 50.0, 10);//kanan atas
		glVertex3f(-218.0 + x, 50.0, 95);//kanan bawah
		glVertex3f(-365.0 + x, 50.0, 95);//kiri atas
		glEnd();
	
		glBegin(GL_QUADS);//atap gardu (atas)
			glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0 + x, 80.0, 10); //kiri bawah
		glVertex3f(-218.0 + x, 80.0, 10);//kanan atas
		glVertex3f(-218.0 + x, 80.0, 95);//kanan bawah
		glVertex3f(-370.0 + x, 80.0, 95);//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//atap gardu (depan)
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0 + x, 50.0, 95); //kiri bawah
		glVertex3f(-370.0 + x, 80.0, 95);//kiri atas
		glVertex3f(-218.0 + x, 80.0, 95);//kanan atas
		glVertex3f(-218.0 + x, 50.0, 95);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//atap gardu (belakang)
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0 + x, 50.0, 10); //kiri bawah
		glVertex3f(-370.0 + x, 80.0, 10);//kiri atas
		glVertex3f(-218.0 + x, 80.0, 10);//kanan atas
		glVertex3f(-218.0 + x, 50.0, 10);//kanan bawah
		glEnd();
		
		for (i=0;i<2;i++){
		glBegin(GL_QUADS); //atap gardu (kiri kanan)
		glColor3f (0.9137254901960784 , 0.5882352941176471 , 0.4784313725490196);
		glVertex3f(-370.0 + ( i * 152) + x, 50.0, 95.0);//kiri bawah
		glVertex3f(-370.0 + ( i * 152) + x, 80.0, 95.0);//kiri atas
		glVertex3f(-370.0 + ( i * 152) + x, 80.0, 10.0);//kanan atas
		glVertex3f(-370.0 + ( i * 152) + x, 50.0, 10.0);//kanan bawah
		glEnd();
		}
	
	//--------------Atasnya Atap Gardu--------------
	
		for (i=0;i<2;i++){
		glBegin(GL_QUADS);//bawah
		glColor3f(0.81, 0.81, 0.81);
		glVertex3f(-361.0 - (i*5) + x, 50.1 + (i*10), 95); //kiri bawah
		glVertex3f(-227.0 + (i*5) + x, 50.1 + (i*10), 95);//kanan atas
		glVertex3f(-227.0 + (i*5) + x, 50.1 + (i*10), 120 + (i*5));//kanan bawah
		glVertex3f(-361.0 - (i*5) + x, 50.1 + (i*10), 120 + (i*5));//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//atas
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-361.0 - (i*5) + x, 60.0 + (i*10), 95); //kiri bawah
		glVertex3f(-227.0 + (i*5) + x, 60.0 + (i*10), 95);//kanan atas
		glVertex3f(-227.0 + (i*5) + x, 60.0 + (i*10), 120 + (i*5));//kanan bawah
		glVertex3f(-361.0 - (i*5) + x, 60.0 + (i*10), 120 + (i*5));//kiri atas
		glEnd();
		
		glBegin(GL_QUADS);//kiri
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-361.0 - (i*5) + x, 60.0 + (i*10), 120.0 + (i*5));//kiri bawah
		glVertex3f(-361.0 - (i*5) + x, 50.0 + (i*10), 120.0 + (i*5));//kiri atas
		glVertex3f(-361.0 - (i*5) + x, 50.0 + (i*10), 95.0);//kanan atas
		glVertex3f(-361.0 - (i*5) + x, 60.0 + (i*10), 95.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kanan
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-227 + (i*5) + x, 60.0 + (i*10), 120.0 + (i*5));//kiri bawah
		glVertex3f(-227 + (i*5) + x, 50.0 + (i*10), 120.0 + (i*5));//kiri atas
		glVertex3f(-227 + (i*5) + x, 50.0 + (i*10), 95.0);//kanan atas
		glVertex3f(-227 + (i*5) + x, 60.0 + (i*10), 95.0);//kanan bawah
		glEnd();
		
		
		glBegin(GL_QUADS);//depan
		glColor3f (1.0,1.0,1.0);
		glVertex3f(-361.0 - (i*5) + x, 50.0 + (i*10), 120 + (i*5)); //kiri bawah
		glVertex3f(-361.0 - (i*5) + x, 60.0 + (i*10), 120 + (i*5));//kiri atas
		glVertex3f(-227.0 + (i*5) + x, 60.0 + (i*10), 120 + (i*5));//kanan atas
		glVertex3f(-227.0 + (i*5) + x, 50.0 + (i*10), 120 + (i*5));//kanan bawah
		glEnd();
		}
	
		
	//--------------tembok bagian dalem pintu masuk kanan kiri-------------- 		
		for (i=0 ; i<2 ; i++){
		glBegin(GL_QUADS); //kiri
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 80.0);//kiri bawah
		glVertex3f(-344.0 + ( i * 100) + x, -70.0, 80.0);//kiri atas
		glVertex3f(-344.0 + ( i * 100) + x, -70.0, 20.0);//kanan atas
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 20.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS); //kanan
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 30.0);//kiri bawah
		glVertex3f(-344.0 + ( i * 100) + x, -70.0, 30.0);//kiri atas
		glVertex3f(-344.0 + ( i * 100) + x, -70.0, 10.0);//kanan atas
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 10.0);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS); //atas
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 80.0);//kiri bawah
		glVertex3f(-344.0 + ( i * 100) + x, 25.0, 80.0);//kiri atas
		glVertex3f(-344.0 + ( i * 100) + x, 25.0, 10.0);//kanan atas
		glVertex3f(-344.0 + ( i * 100) + x, 50.0, 10.0);//kanan bawah
		glEnd();
		
		}
		
	
		
		glBegin(GL_QUADS);//tengah atap
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(-344.0 + x, 49.9, 10); //kiri bawah
		glVertex3f(-244.0 + x, 49.9, 10);//kanan atas
		glVertex3f(-244.0 + x, 49.9, 80);//kanan bawah
		glVertex3f(-344.0 + x, 49.9, 80);//kiri atas
		glEnd();
		
	
		
		
//--------------tembok putih atas pintu masuk samping-------------- 
	for (i=0 ; i<3 ; i++){
	//--------------depan kiri nya jendela pertama dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-448.0 + x, 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-448.0 + x, 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-345.0 + x, 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-345.0 + x, 95.0 + (i*115), 90);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kiri jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-320.0  + x, 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-320.0  + x, 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-315.0  + x, 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-315.0  + x, 95.0 + (i*115), 90);//kanan bawah
	glEnd();	
	
	
	//--------------tengah kanan jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-275.0 + x, 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-275.0 + x, 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-265.0 + x, 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-270.0 + x, 95.0 + (i*115), 90);//kanan bawah
	glEnd();
		
		
	//--------------atas nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-345.0 + x, 195.0 + (i*115), 90); //kiri bawah
	glVertex3f(-345.0 + x, 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-220.0 + x, 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-220.0 + x, 195.0 + (i*115), 90);//kanan bawah
	glEnd();
		
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-345.0 + x, 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-345.0 + x, 110.0 + (i*115), 90);//kiri atas
	glVertex3f(-220.0 + x, 110.0 + (i*115), 90);//kanan atas
	glVertex3f(-220.0 + x, 95.0 + (i*115), 90);//kanan bawah
	glEnd();	
	
	//--------------paling kanan terakhir setelah jendela ketiga dinding putih--------------
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-245.0 + x, 95.0 + (i*115), 90); //kiri bawah
	glVertex3f(-245.0 + x, 210.0 + (i*115), 90);//kiri atas
	glVertex3f(-220.0 + x, 210.0 + (i*115), 90);//kanan atas
	glVertex3f(-220.0 + x, 95.0 + (i*115), 90);//kanan bawah
	glEnd();
	}
	//--------------bawah nya jendela dinding putih--------------
	glBegin(GL_QUADS); //TAMBAHAN MUNGIL
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-448.0 + x, 80.0, 90); //kiri bawah
	glVertex3f(-448.0 + x, 95.0, 90);//kiri atas
	glVertex3f(-220.0 + x, 95.0, 90);//kanan atas
	glVertex3f(-220.0 + x, 80.0, 90);//kanan bawah
	glEnd();
}

void atapnyasisikanan(){
	for (i=0;i<3;i++){
			glBegin(GL_QUADS);//bawah
			glColor3f(0.81, 0.81, 0.81);
			glVertex3f(-710.0 - (i*5), 210.0 + (i*5), 40);//kiri bawah
			glVertex3f(-620.0 + (i*3.5), 210.0 + (i*5), 40);//kanan bawah
			glVertex3f(-620.0 + (i*3.5), 210.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-710.0 - (i*5), 210.0 + (i*5), 115 + (i*5));//kiri atas
			glEnd();
		
			glBegin(GL_QUADS);//atas
			glColor3f(0.81, 0.81, 0.81);
			glVertex3f(-710.0 - (i*5), 215.0 + (i*5), 40);//kiri bawah
			glVertex3f(-620.0 + (i*3.5), 215.0 + (i*5), 40);//kanan bawah
			glVertex3f(-620.0 + (i*3.5), 215.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-710.0 - (i*5), 215.0 + (i*5), 115 + (i*5));//kiri atas
			glEnd();
		
			glBegin(GL_QUADS);//kiri
			glColor3f(1,1,1);
			glVertex3f(-710.0 - (i*5), 210.0 + (i*5), 40); //kiri bawah
			glVertex3f(-710.0 - (i*5), 215.0 + (i*5), 40);//kiri atas
			glVertex3f(-710.0 - (i*5), 215.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-710.0 - (i*5), 210.0 + (i*5), 115 + (i*5));//kanan bawah
			glEnd();
		
			glBegin(GL_QUADS);//kanan
			glColor3f(1,1,1);
			glVertex3f(-620.0 + (i*3.5), 210.0 + (i*5), 40); //kiri bawah
			glVertex3f(-620.0 + (i*3.5), 215.0 + (i*5), 40);//kiri atas
			glVertex3f(-620.0 + (i*3.5), 215.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-620.0 + (i*3.5), 210.0 + (i*5), 115 + (i*5));//kanan bawah
			glEnd();
		
			glBegin(GL_QUADS);
			glColor3f(1,1,1); //depan
			glVertex3f(-710.0 - (i*5), 210.0 + (i*5), 115 + (i*5)); //kiri bawah
			glVertex3f(-710.0 - (i*5), 215.0 + (i*5), 115 + (i*5));//kiri atas
			glVertex3f(-620.0 + (i*3.5), 215.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-620.0 + (i*3.5), 210.0 + (i*5), 115 + (i*5));//kanan bawah
			glEnd();
			}
			
	//-------------------------------------------------------------------------------------------------------
			
			for (i=0;i<3;i++){
			glBegin(GL_QUADS);//bawah
			glColor3f(0.81, 0.81, 0.81);
			glVertex3f(-630.0 - (i*5), 440.0 + (i*5), 10);//kiri bawah
			glVertex3f(640.0 + (i*5), 440.0 + (i*5), 10);//kanan bawah
			glVertex3f(640.0 + (i*5), 440.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-630.0 - (i*5), 440.0 + (i*5), 115 + (i*5));//kiri atas
			glEnd();
		
			glBegin(GL_QUADS);//atas
			glColor3f(0.81, 0.81, 0.81);
			glVertex3f(-630.0 - (i*5), 445.0 + (i*5), 10);//kiri bawah
			glVertex3f(640.0 + (i*5), 445.0 + (i*5), 10);//kanan bawah
			glVertex3f(640.0 + (i*5), 445.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-630.0 - (i*5), 445.0 + (i*5), 115 + (i*5));//kiri atas
			glEnd();
		
			glBegin(GL_QUADS);//kiri
			glColor3f(1,1,1);
			glVertex3f(-630.0 - (i*5), 440.0 + (i*5), 10); //kiri bawah
			glVertex3f(-630.0 - (i*5), 445.0 + (i*5), 10);//kiri atas
			glVertex3f(-630.0 - (i*5), 445.0 + (i*5), 115 + (i*5));//kanan atas
			glVertex3f(-630.0 - (i*5), 440.0 + (i*5), 115 + (i*5));//kanan bawah
			glEnd();
		
			glBegin(GL_QUADS);//kanan
			glColor3f(1,1,1);
			glVertex3f(640.0 + (i*5), 440.0 + (i*5), 10); //kiri bawah
			glVertex3f(640.0 + (i*5), 445.0 + (i*5) , 10);//kiri atas
			glVertex3f(640.0 + (i*5), 445.0 + (i*5) , 115 + (i*5));//kanan atas
			glVertex3f(640.0 + (i*5), 440.0 + (i*5) , 115 + (i*5));//kanan bawah
			glEnd();
		
			glBegin(GL_QUADS);
			glColor3f(1,1,1); //depan
			glVertex3f(-630.0 - (i*5), 440.0 + (i*5) , 115 + (i*5)); //kiri bawah
			glVertex3f(-630.0 - (i*5), 445.0 + (i*5) , 115 + (i*5));//kiri atas
			glVertex3f(640.0 + (i*5), 445.0 + (i*5) , 115 + (i*5));//kanan atas
			glVertex3f(640.0 + (i*5), 440.0 + (i*5) , 115 + (i*5));//kanan bawah
			glEnd();
			}
}

void backgroundsisikanan(){
	//--------------------tengah
		glBegin(GL_QUADS);
		glColor3f(0.81,0.81,0.81); //depan
		glVertex3f(-625.0 , -70.0  , 9.9); //kiri bawah
		glVertex3f(-625.0 , 445.0 , 9.9);//kiri atas
		glVertex3f(517.0 , 445.0  , 9.9);//kanan atas
		glVertex3f(517.0 , -70.0  , 9.9);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kiri
		glColor3f(0.81, 0.81, 0.81);
		glVertex3f(-625.0, -70.0, 9.9); //kiri bawah
		glVertex3f(-625.0, 445.0, 9.9);//kiri atas
		glVertex3f(-625.0, 445.0, 40);//kanan atas
		glVertex3f(-625.0, -70.0, 40);//kanan bawah
		glEnd();
		
		
		
	//--------------------kiri		
		glBegin(GL_QUADS);
		glColor3f(0.81,0.81,0.81); //depan
		glVertex3f(-705.0 , -70.0  , 39.9); //kiri bawah
		glVertex3f(-705.0 , 225.0 , 39.9);//kiri atas
		glVertex3f(-625.0 , 225.0  , 39.9);//kanan atas
		glVertex3f(-625.0 , -70.0  , 39.9);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);//kiri
		glColor3f(0.81, 0.81, 0.81);
		glVertex3f(-705.0, -70.0, 39.9); //kiri bawah
		glVertex3f(-705.0, 225.0, 39.9);//kiri atas
		glVertex3f(-705.0, 225.0, 40);//kanan atas
		glVertex3f(-705.0, -70.0, 40);//kanan bawah
		glEnd();
		
		glBegin(GL_QUADS);
		glColor3f(0.81, 0.81, 0.81);//atas
		glVertex3f(-705.0, 225.0, 39.9);//kiri bawah
		glVertex3f(-625.0, 225.0, 39.9);//kanan bawah
		glVertex3f(-625.0, 225.0, 40);//kanan atas
		glVertex3f(-705.0, 225.0, 40);//kiri atas
		glEnd();
		
	//--------------------kanan		
		glBegin(GL_QUADS);
		glColor3f(0.81,0.81,0.81); //depan
		glVertex3f(500.0 , 80.0  , 9.9); //kiri bawah
		glVertex3f(500.0 , 445.0 , 9.9);//kiri atas
		glVertex3f(640.0 , 445.0  , 9.9);//kanan atas
		glVertex3f(640.0 , 80.0  , 9.9);//kanan bawah
		glEnd();
	
		glBegin(GL_QUADS);//kanan
		glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
		glVertex3f(640.0, 80.0, 9.9); //kiri bawah
		glVertex3f(640.0, 445.0, 9.9);//kiri atas
		glVertex3f(640.0, 445.0, 90);//kanan atas
		glVertex3f(640.0, 80.0, 90);//kanan bawah
		glEnd();
	
	//-----------------------bawah keseluruhan
		glBegin(GL_QUADS);
		glColor3f(0.81, 0.81, 0.81);//atas
		glVertex3f(-625.0, 100, 10);//kiri bawah
		glVertex3f(640.0, 100, 10);//kanan bawah
		glVertex3f(640.0, 100, 90);//kanan atas
		glVertex3f(-625.0, 100, 90);//kiri atas
		glEnd();
		
		//-----------------------bawah keseluruhan
		glBegin(GL_QUADS);
		glColor3f(0.81, 0.81, 0.81);//atas
		glVertex3f(-220.0, -35, 10);//kiri bawah
		glVertex3f(500.0, -35, 10);//kanan bawah
		glVertex3f(500.0, -35, 90);//kanan atas
		glVertex3f(-220.0, -35, 90);//kiri atas
		glEnd();
}

void covergerbang(){
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-707.0, -70.0, 40.0);
	glVertex3f(-690, -70, 10.0);
	glVertex3f(-690, 225, 10.0);
	glVertex3f(-707.0, 225.0, 40.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-690, 225, 10.0);
	glVertex3f(-707.0, 225.0, 40.0);
	glVertex3f(-625.0 , 225.0, 40);
	glVertex3f(-625.0 , 225.0, 10);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f (0.9333333333333333 , 0.9098039215686275 , 0.6666666666666667);
	glVertex3f(-690.0 , -70.0  , 10);
	glVertex3f(-690.0 , 440.0+15 , 10);
	glVertex3f(-625.0 , 440.0+15  , 10);
	glVertex3f(-625.0 , -70.0  , 10);
	glEnd();
}

void gedungKanan(){
	DindingAlas();
	dindingorensebelahKANAN();
	sambungandindingorendanputih();
	dindingkananputih();
	pintumasuksamping();
    setelahpintusampingkanan(0 , 0);
	sambungandindingalasdandindingoren();
	tengahnyasisikananbangunan(0,0,0);
	sisikananPALINGAKHIRYUHUUUU();
	tengahkananyangkedua();
	benerbeneryangterakhir();
	pintuparkirankanan();
	atapnyasisikanan();
	backgroundsisikanan();
	covergerbang();
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
	
	//alas
	glBegin(GL_POLYGON);
	glColor3f(0.91,0.91,0.91);
	glVertex3f(-850, -70, 200);//kiri bawwah
	glVertex3f(-900, -70, -100);//kiri atas
	glVertex3f(-600, -70, -600);//pertengahan kiri
	glVertex3f(-300, -70, -1000);//pertengahan kanan
	glVertex3f(800, -70, -500);//kanan atas
	glVertex3f(800, -70, 200);//kanan bawah
	glEnd();

	BatasBangunan();
	gedungKiri();
	gedungKanan();
	gedungDepan();
	gedungBelakang();
	objekDalam();
	
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
	glTranslatef(0.0, 0.0, -1500.0);
	glMatrixMode(GL_MODELVIEW);
}





int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1920,1080);
	glutInitWindowPosition(0,0);
	glutCreateWindow("HSE University Rusia");
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
