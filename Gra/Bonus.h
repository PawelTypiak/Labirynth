#pragma once

#include "Stozek.h"
class CBonus
{
public:
	CBonus(void);
	CBonus(int x, int y, int z, float r, float g, float b);
	~CBonus(void);
	void CBonus::Przesun(int dx, int dy, int dz);
	void CBonus::Obroc(double alfa, double beta, double gamma);
	void Rysuj(void);

	CStozek * gora; //górny sto¿ek
	CStozek * dol; //dolny sto¿ek
	int step;
	int pozycja[3];
	int obrot[3];
};

