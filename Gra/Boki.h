#pragma once
#include "Figura.h"
class CBoki :
	public CFigura
{
public:
	CBoki(void);
	CBoki(double dl,double sz, double x, double y, double z, double alfa, double beta, double gamma, float r, float g,float b);
	~CBoki(void);
	
	void loadTextureFromFile(char *filename);
	GLuint textures;
	void Rysuj(void); // funkcja rysuj¹ca figurê
	double dlugosc;
	double szerokosc;
};

