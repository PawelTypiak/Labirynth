#pragma once
#include "Figura.h"
#include "Sfera.h"
class CKulka :
	public CFigura
{
public:
	CKulka(void);
	CKulka(int x, int y, int z, double r, double g, double b);
	~CKulka(void);

	void Rysuj(void);
	void loadTextureFromFile(char *filename);
	int spr( int poziom );

	
	int step;
	CSfera * sfera[5];
};

