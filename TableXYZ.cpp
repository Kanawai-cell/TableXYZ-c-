#include "StdAfx.h"
#include "TableXYZ.h"
#include "..\CAxeBase\CAxeBase.h"
#include "Axe.h"

CTableXYZ::CTableXYZ(void)
{
}

CTableXYZ::~CTableXYZ(void)
{
	delete pAxeX;			
	delete pAxeY;	
	delete pCarte;
	delete Rdv;
}
