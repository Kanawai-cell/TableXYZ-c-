// CU1_INC1_IT2.cpp�: d�finit le point d'entr�e pour l'application console.
// EFFECTUER UN DEPLACEMENT EN X AVEC CAXEBASE

#include "stdafx.h"

#include "..\CAxeBase\CAxeBase.h"

int _tmain(int argc, _TCHAR* argv[])
{
  // cr�er un traceur graphique
  CTraceur* lpTraceur = new CTraceur(-1);
  // le fichier de trace des sorties mat�rielles
  string Trace("TraceCU1_INC1_IT2.txt");
  // cr�er la carte d'acc�s au mat�riel
  CCarte6P* pCarte;
  pCarte = new CCarte6P(Trace,"SSESSE","1",0xe400);
  // c�er l'objet axe en le reliant au c�blage : port de cmd=1 port de led=2.
  // 2 pour le num�ro de l'axe ici Y
  CAxeBase* pAxeY = new CAxeBase(pCarte,4,5,2);
  // pour le tra�age graphique
  CTraceur::InitVoies(&(pAxeY->uPosCourante),V);
  // piloter un d�placement en X
  cout << "Deplacement en Y : pos=200pas Vit=40pas/s" << endl;
  // Aller.
  pAxeY->SetPosFinale(200);		// fixer la position � atteindre
  pAxeY->SetVitesse(40);		// fixer la vitesse du d�placement
  //pAxeY->FaireUnDep();			// Effectuer le d�placement
  // Retour origine.
  pAxeY->SetPosFinale(0);		// fixer la position � atteindre
  pAxeY->SetVitesse(40);		// fixer la vitesse du d�placement
  pAxeY->FaireUnDep();			// Effectuer le d�placement

  // affichage de la position atteinte
  cout << "Position finale Y= "<< pAxeY->uPosCourante << endl;
  // attendre "Q" pour quitter
  cout << "Entrer q pour quitter.." << endl;
  char cFin;
  do {
    cin >> cFin;
  }while ( cFin != 'q' && cFin != 'Q' );
	// d�truire les objets cr��s dynamiquement dans l'ordre inverse de leur cr�ation
  delete pAxeY;			
  delete pCarte;
  return 0;
}

