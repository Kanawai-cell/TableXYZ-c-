#pragma once
#include "d:\tp05 - tablexyz\tablexyz_cu1_inc1_it1\caxebase\caxebase.h"

class CAxe : public CAxeBase, public Tache
{
virtual public void main (void*);
public:
	CAxe(CCarte6P *lpCarte,UINT uPortCmd, UINT uPortLed,UINT uNumAxe);
	~CAxe(void);
};
