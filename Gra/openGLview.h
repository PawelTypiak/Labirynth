#pragma once
#include <gl\glut.h> // dodajemy bibliotekê glut do projekt
#include "Figura.h"
#include "Bonus.h"
#include "Poziom1.h"
#include "Poziom2.h"
#include "Poziom3.h"
#include "Poziom4.h"
#include "Kulka.h"
class openGLview
{
public:
	openGLview(void);
	~openGLview(void);

	void animacja(void);
	void display(void); 
	void resize(int width, int height);
	void rysuj_figury(void);
	void keyboard(unsigned char key, int x, int y);
	void drawText(int x, int y, int z,char *string);
	void zapisRekord ( int czas, int level );
	int odczytRekord (int level );
	int odczytPoziom (int opcja);
	void zapisPoziom(int level, int time1, int time2, int time3);

	char napis[50];
	CKulka * kulka;
	CPoziomy * poziom[4];
	int v;
	int los;
	int poz;
	int odp;
	int tmp;
	int czasGL, czas1, czas2, czas3, czas4;
	time_t startGL, stopGL, stop1, stop2, stop3, stop4, start1, start2, start3, start4;
};
