#pragma once
#include "Figura.h"
class CPodloga :
	public CFigura
{
public:
	CPodloga(void);
	CPodloga(double dl,double sz, double x, double y, double z, double alfa, double beta, double gamma, float r, float g,float b);
	~CPodloga(void);
	
	void loadTextureFromFile(char *filename);
	GLuint textures;
	void Rysuj(void); // funkcja rysuj¹ca figurê
	double dlugosc;
	double szerokosc;
};

