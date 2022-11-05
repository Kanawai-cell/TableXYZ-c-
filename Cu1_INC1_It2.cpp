// CU1_INC1_IT2.cpp : définit le point d'entrée pour l'application console.
// EFFECTUER UN DEPLACEMENT EN X AVEC CAXEBASE

#include "stdafx.h"

#include "..\CAxeBase\CAxeBase.h"

int _tmain(int argc, _TCHAR* argv[])
{
  // créer un traceur graphique
  CTraceur* lpTraceur = new CTraceur(-1);
  // le fichier de trace des sorties matérielles
  string Trace("TraceCU1_INC1_IT2.txt");
  // créer la carte d'accès au matériel
  CCarte6P* pCarte;
  pCarte = new CCarte6P(Trace,"SSESSE","1",0xe400);
  // céer l'objet axe en le reliant au câblage : port de cmd=1 port de led=2.
  // 2 pour le numéro de l'axe ici Y
  CAxeBase* pAxeY = new CAxeBase(pCarte,4,5,2);
  // pour le traçage graphique
  CTraceur::InitVoies(&(pAxeY->uPosCourante),V);
  // piloter un déplacement en X
  cout << "Deplacement en Y : pos=200pas Vit=40pas/s" << endl;
  // Aller.
  pAxeY->SetPosFinale(200);		// fixer la position à atteindre
  pAxeY->SetVitesse(40);		// fixer la vitesse du déplacement
  //pAxeY->FaireUnDep();			// Effectuer le déplacement
  // Retour origine.
  pAxeY->SetPosFinale(0);		// fixer la position à atteindre
  pAxeY->SetVitesse(40);		// fixer la vitesse du déplacement
  pAxeY->FaireUnDep();			// Effectuer le déplacement

  // affichage de la position atteinte
  cout << "Position finale Y= "<< pAxeY->uPosCourante << endl;
  // attendre "Q" pour quitter
  cout << "Entrer q pour quitter.." << endl;
  char cFin;
  do {
    cin >> cFin;
  }while ( cFin != 'q' && cFin != 'Q' );
	// détruire les objets créés dynamiquement dans l'ordre inverse de leur création
  delete pAxeY;			
  delete pCarte;
  return 0;
}

