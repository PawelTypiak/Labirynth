#pragma once
#include "Figura.h"
class CSfera :
	public CFigura
{
public:
	CSfera(void);
	CSfera(int x, int y, int z, double radius, double r, double g, double b);
	~CSfera(void);

	void loadTextureFromFile(char *filename);
	void Rysuj(void);
	double promien;
};

