///////////////////////////////////////////////////////////////////////////////
// CAxe.h: interface de la classe CAxe
// Un axe utilise Trois ports d'une carte E/S 6 ports
//    un port pour les commandes
//    un port pour les voyants ( ici un seul voyant)
//    un port pour les inter ( ici Dcy Axe) 
// est en association par référence avec une carte 6 ports.
// (les ports diponibles peuvent être utilisés par un autre objet)
///////////////////////////////////////////////////////////////////////////////

#ifndef _MR_CAXEBASE_H
 #define _MR_CAXEBASE_H

#ifdef _MR_IO_EXPORTS
#define IO_API __declspec(dllexport)
#else
#define IO_API __declspec(dllimport)
#endif

#include "M:\TP\iris2\TableXYZ\1751.h"					// Pour la carte ADAM
#include "M:\TP\iris2\TableXYZ\io-1751.h"       // Pour les IO par carte 6P 
#include "M:\TP\iris2\TableXYZ\Ctraceur.h"      // Pour le traceur graphique 

#define HORSTENSION 0
#define NBPHASES  4
#define ALLUMERLED 0x01
#define ETEINDRELED 0xFE

class CAxeBase {
public:
  IO_API CAxeBase ( CCarte6P *lpCarte,UINT uPortCmd, UINT uPortLed,UINT uNumAxe);
  IO_API ~CAxeBase ( );
  IO_API void MettreSousTension ( );
  IO_API void MettreHorsTension ( );
  IO_API void FaireUnDep ( );
  UINT uPosCourante;										// position courante de l'axe
																				// public --> fixer la donnée à afficher dans le traceur
  IO_API void SetPosFinale(UINT uVal);	// affecter la position à atteindre
  IO_API void SetVitesse(UINT Vit);			// affecter la vitesse souhaitée

  UINT uMonNum;							// numéro de l'axe pour identification

protected:

private:
  void AllumerLed ( );
  void EteindreLed ( );
  CCarte6P* lpCarte;				// La carte parallèle 6 ports par agrégation
  UINT uPosFinale;					// position finale de l'axe
  UINT uVitesse;						// Vitesse de l'axe;     
  UINT iDelai;							// délai pour régler la vitesse
  static const char TabCmd[4];		// Tableau des commandes des phases d'un MPAP
  UINT uIndiceCourant;			// numéro de la phase actuellement alimentée
  int iSens;								// indique le sens du déplacement
  UINT uNumPortCmd;					// port des commandes de phases
  UINT uNumPortLed;					// port de commande du voyant
};

#endif
