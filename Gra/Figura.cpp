#include "StdAfx.h"
#include "Figura.h"


CFigura::CFigura(void)
{
}


CFigura::~CFigura(void)
{
}
void CFigura::Przesun(int dx, int dy, int dz)
{ //przesuniecie figury
	translacja[0]+=dx;
	translacja[1]+=dy;
	translacja[2]+=dz;
}
void CFigura::Obroc(double alfa, double beta, double gamma)
{ // obrot figury
	rotacja[0]+=alfa;
	rotacja[1]+=beta;
	rotacja[2]+=gamma;
}
