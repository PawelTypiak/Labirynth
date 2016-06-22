#pragma once
#include "Figura.h"
#include "Podloga.h"
class CPodstawa : public CFigura //klasa odpowiedzialna za tworzenie scian
{
public:
	CPodstawa(void);
	CPodstawa(double dl,double sz, double wys, double x, double y, double z,float r, float g, float b);
	~CPodstawa(void);

	void Rysuj(void);

	void loadTextureFromFile(char *filename);
	CPodloga * podloga[6];
};

