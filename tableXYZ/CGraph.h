//////////////////////////// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! /////////////////////////////////
// A UTILISER POUR LA COMPILATION DES LIBRAIRIES DLLOU LIB
//////////////////////////// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! /////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// classe CTraceur: Classe UTILITAIRE: les méthodes peuvent être utilisées 
//                  sans référence sur un objet.
//                  traceur 2 voies. Mode F(t) ou XY.
//                  trace suivant X ou Y avec 1 pas/s = 1 pixel/s
//                  trace des segments de droite du point courant vers le
//                  point à atteindre.
//                  Pour utiliser cette classe, il faut appeler la méthode
//                  InitVoies(adresse var, voie utilisée)
//                       adresse var = adresse variable à suivre
//                       voie 1: déplacement selon les X
//                       voie 2: déplacement selon les Y

///////////////////////////////////////////////////////////////////////////////
#ifndef _MR_CGRAPH_H
 #define _MR_CGRAPH_H

#ifdef _LIB
 #define IO_API
#else
#ifdef _MR_IO_EXPORTS
 #define IO_API __declspec(dllexport)
#else
 #define IO_API __declspec(dllimport)
#endif
#endif

// Le noyau Temps Réel Objet
#pragma comment(linker, "/nodefaultlib:LIBCMT") // n'utiliser que LIBCMT
#include "x:\mtr86w32\noyauobj\Mtrobj.h"

class CTraceur;

class CGraph : public Tache {
public:
  IO_API CGraph ( CTraceur* const lpTraceur, int Prior,HWND hWnd, int uMd );// constructeur 2
  IO_API virtual ~CGraph ( );
  IO_API static void ModeGraph ( );             // choisir un mode Y(t) ou XY

protected:
  HWND hWnd;
  HDC hDc;
  void virtual Tracer ( );                      // selon le mode y(t) ou XY
  CTraceur* lpTraceur;

private:
  static int Etat;
  void main ( void* );                          // code de la tâche
                                                // procédure de fenêtre graph
  UINT uOrg;                                    // Origine des axes en 0,0
  UINT uMode;
  LOGBRUSH logbrush;

};

class CTraceurPlume;

class CGraphPlume : public CGraph {
public:
  IO_API CGraphPlume (CTraceurPlume* const lpTraceur, int Prior,HWND hWnd, bool *_uEtatPlume, int uMd );// constructeur 2
  IO_API virtual ~CGraphPlume ( );

protected:
  void virtual Tracer ( );                      // selon le mode y(t) ou XY

private:
  HPEN hPen;                                    // stylo courant
  bool *uEtatPlume;   // état de la plume
};
#endif
