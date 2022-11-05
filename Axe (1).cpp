#include "StdAfx.h"
#include "Axe.h"

CAxe::CAxe(CCarte6P *lpCarte,UINT uPortCmd, UINT uPortLed,UINT uNumAxe):CAxeBase(lpCarte , uPortCmd , uPortLed , uNumAxe)
{
}

void CAxe::main(void*)
{
	this->FaireUnDep() ;
	mtr86exit(0); 
}

CAxe::~CAxe(void)
{
}
