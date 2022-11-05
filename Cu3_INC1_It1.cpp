// CU3_INC1_IT1.cpp : définit le point d'entrée pour l'application console.
// EFFECTUER UN DEPLACEMENT EN X AVEC CAXEBASE

#include "stdafx.h"

#include "..\CAxeBase\CAxeBase.h"
#include "Axe.h"

int _tmain(int argc, _TCHAR* argv[])
{
  // créer un traceur graphique
  CTraceur* lpTraceur = new CTraceur(-1);
  // le fichier de trace des sorties matérielles
  string Trace("TraceCU3_INC1_IT1.txt");
  // créer la carte d'accès au matériel
  CCarte6P* pCarte;
  pCarte = new CCarte6P(Trace,"SSESSE","1",0xe400);
  // céer l'objet axe en le reliant au câblage : port de cmd=1 port de led=2.
  // 2 pour le numéro de l'axe ici Y
  CAxe* pAxeX = new CAxe(pCarte,1,2,1);
  CAxe* pAxeY = new CAxe(pCarte,4,5,2);
  // pour le traçage graphique
  CTraceur::InitVoies(&(pAxeX->uPosCourante),H);
  CTraceur::InitVoies(&(pAxeY->uPosCourante),V);

  cout << "Ceci n'est pas la version demandé. A modifier en conséquence !!" << endl;
  // ------- Premier déplacement ------- //
  // piloter un déplacement en X et en Y
  cout << "Deplacement en X : pos=200pas Vit=20pas/s" << endl;
  cout << "Deplacement en Y : pos=200pas Vit=20pas/s" << endl;
  // Aller.
  pAxeX->SetPosFinale(200);		// fixer la position à atteindre
  pAxeX->SetVitesse(20);		// fixer la vitesse du déplacement

  pAxeY->SetPosFinale(200);		// fixer la position à atteindre
  pAxeY->SetVitesse(20);		// fixer la vitesse du déplacement

  pAxeY->active();				// Effectuer le déplacement
  pAxeX->active();				// Effectuer le déplacement

  pAxeX->Tache::wait_for_terminate();
  pAxeY->Tache::wait_for_terminate();
  
  // affichage de la position atteinte
  cout << "Position finale X= "<< pAxeX->uPosCourante << endl;
  cout << "Position finale Y= "<< pAxeY->uPosCourante << endl;

  // ------- Deuxième déplacement ------- //
  // piloter un déplacement en X et en Y
  cout << "Deplacement en X : pos=400pas Vit=20pas/s" << endl;
  cout << "Deplacement en Y : pos=0pas Vit=20pas/s" << endl;
  // Aller.
  pAxeX->SetPosFinale(400);		// fixer la position à atteindre
  pAxeX->SetVitesse(20);		// fixer la vitesse du déplacement

  pAxeY->SetPosFinale(0);		// fixer la position à atteindre
  pAxeY->SetVitesse(20);		// fixer la vitesse du déplacement

  pAxeY->active();				// Effectuer le déplacement
  pAxeX->active();				// Effectuer le déplacement

  Tache::wait_for_terminate();

  // affichage de la position atteinte
  cout << "Position finale X= "<< pAxeX->uPosCourante << endl;
  cout << "Position finale Y= "<< pAxeY->uPosCourante << endl;

  // attendre "Q" pour quitter
  cout << "Entrer q pour quitter.." << endl;
  char cFin;
  do {
    cin >> cFin;
  }while ( cFin != 'q' && cFin != 'Q' );
	// détruire les objets créés dynamiquement dans l'ordre inverse de leur création
  delete pAxeX;	
  delete pAxeY;
  delete pCarte;
  return 0;
}

