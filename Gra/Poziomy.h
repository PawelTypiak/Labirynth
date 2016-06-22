#pragma once

#include "Podstawa.h"
#include "Sciany.h"
#include "Bonus.h"
#include "Kulka.h"

class CPoziomy
{
public:
	CPoziomy(void);
	~CPoziomy(void);

	virtual void Rysuj(void)=0;

	int gr;
	int wys;
	int sz;
	int os_y;
	CPodstawa * podstawa;
	CSciany * sciana[20];
	CBonus * bonus[10];
	CKulka * kulka;
};

