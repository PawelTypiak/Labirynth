#pragma once
#include "Figura.h"
#include "Boki.h"
class CSciany : public CFigura //klasa odpowiedzialna za tworzenie scian
{
public:
	CSciany(void);
	CSciany(double dl,double sz, double wys, double x, double y, double z,float r, float g, float b);
	~CSciany(void);

	void Rysuj(void);

	void loadTextureFromFile(char *filename);
	CBoki * boki[6];
};

