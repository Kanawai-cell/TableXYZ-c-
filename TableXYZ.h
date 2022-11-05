#pragma once
#include "x:\mtr86w32\noyauobj\mtrobj.h"

class CTableXYZ : public Tache
{
private:
	CCarte6P* pCarte;
	CAxe* pAxeX;
	CAxe* pAxeY;
	RendezVous* Rdv;

public:
	CTableXYZ(void);
	~CTableXYZ(void);
};
