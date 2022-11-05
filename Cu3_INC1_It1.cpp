// CU3_INC1_IT1.cpp�: d�finit le point d'entr�e pour l'application console.
// EFFECTUER UN DEPLACEMENT EN X AVEC CAXEBASE

#include "stdafx.h"

#include "..\CAxeBase\CAxeBase.h"
#include "Axe.h"

int _tmain(int argc, _TCHAR* argv[])
{
  // cr�er un traceur graphique
  CTraceur* lpTraceur = new CTraceur(-1);
  // le fichier de trace des sorties mat�rielles
  string Trace("TraceCU3_INC1_IT1.txt");
  // cr�er la carte d'acc�s au mat�riel
  CCarte6P* pCarte;
  pCarte = new CCarte6P(Trace,"SSESSE","1",0xe400);
  // c�er l'objet axe en le reliant au c�blage : port de cmd=1 port de led=2.
  // 2 pour le num�ro de l'axe ici Y
  CAxe* pAxeX = new CAxe(pCarte,1,2,1);
  CAxe* pAxeY = new CAxe(pCarte,4,5,2);
  // pour le tra�age graphique
  CTraceur::InitVoies(&(pAxeX->uPosCourante),H);
  CTraceur::InitVoies(&(pAxeY->uPosCourante),V);

  cout << "Ceci n'est pas la version demand�. A modifier en cons�quence !!" << endl;
  // ------- Premier d�placement ------- //
  // piloter un d�placement en X et en Y
  cout << "Deplacement en X : pos=200pas Vit=20pas/s" << endl;
  cout << "Deplacement en Y : pos=200pas Vit=20pas/s" << endl;
  // Aller.
  pAxeX->SetPosFinale(200);		// fixer la position � atteindre
  pAxeX->SetVitesse(20);		// fixer la vitesse du d�placement

  pAxeY->SetPosFinale(200);		// fixer la position � atteindre
  pAxeY->SetVitesse(20);		// fixer la vitesse du d�placement

  pAxeY->active();				// Effectuer le d�placement
  pAxeX->active();				// Effectuer le d�placement

  pAxeX->Tache::wait_for_terminate();
  pAxeY->Tache::wait_for_terminate();
  
  // affichage de la position atteinte
  cout << "Position finale X= "<< pAxeX->uPosCourante << endl;
  cout << "Position finale Y= "<< pAxeY->uPosCourante << endl;

  // ------- Deuxi�me d�placement ------- //
  // piloter un d�placement en X et en Y
  cout << "Deplacement en X : pos=400pas Vit=20pas/s" << endl;
  cout << "Deplacement en Y : pos=0pas Vit=20pas/s" << endl;
  // Aller.
  pAxeX->SetPosFinale(400);		// fixer la position � atteindre
  pAxeX->SetVitesse(20);		// fixer la vitesse du d�placement

  pAxeY->SetPosFinale(0);		// fixer la position � atteindre
  pAxeY->SetVitesse(20);		// fixer la vitesse du d�placement

  pAxeY->active();				// Effectuer le d�placement
  pAxeX->active();				// Effectuer le d�placement

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
	// d�truire les objets cr��s dynamiquement dans l'ordre inverse de leur cr�ation
  delete pAxeX;	
  delete pAxeY;
  delete pCarte;
  return 0;
}

