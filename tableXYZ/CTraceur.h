//////////////////////////// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! /////////////////////////////////
// A UTILISER POUR LA COMPILATION DES LIBRAIRIES DLLOU LIB
//////////////////////////// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! /////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// classe CTraceur: Classe UTILITAIRE: les m�thodes peuvent �tre utilis�es 
//                  sans r�f�rence sur un objet.
//                  traceur 2 voies. Mode F(t) ou XY.
//                  trace suivant X ou Y avec 1 pas/s = 1 pixel/s
//                  trace des segments de droite du point courant vers le
//                  point � atteindre.
//                  Pour utiliser cette classe, il faut appeler la m�thode
//                  InitVoies(adresse var, voie utilis�e)
//                       adresse var = adresse variable � suivre
//                       voie 1: d�placement selon les X
//                       voie 2: d�placement selon les Y
///////////////////////////////////////////////////////////////////////////////
#ifndef _MR_CTRACEUR_H
 #define _MR_CTRACEUR_H

#ifdef _LIB
 #define IO_API
#else
#ifdef _MR_IO_EXPORTS
 #define IO_API __declspec(dllexport)
#else
 #define IO_API __declspec(dllimport)
#endif
#endif

#define MODE_YT 0               // pour les deux modes du traceur
#define MODE_XY 1               

 // Le noyau Temps R�el Objet
#pragma comment(linker, "/nodefaultlib:LIBCMT") // n'utiliser que LIBCMT
#include "x:\mtr86w32\noyauobj\Mtrobj.h"

// voie Horizontale et Verticale
enum VOIES {H,V};

class CGraph;

class CTraceur : public Tache {
public:
//  IO_API CTraceur ( ){}                         // constructeur par d�faut
  IO_API CTraceur ( int Prior,int uMd=MODE_XY );// constructeur 2
  IO_API ~CTraceur ( );
  IO_API static void ModeTraceur ( );           // choisir un mode Y(t) ou XY
                                                // fixer donn�e � afficher 
  IO_API static void InitVoies ( UINT *iVoie,enum VOIES Voie ); 
  static UINT uMode;
  static int EtatVoies;
  static UINT *ix;
  static UINT *iy;
protected:
  CGraph *lpGraph;
  int Prior;
  void virtual main ( void* );                          // code de la t�che
                                                // proc�dure de fen�tre graph
  static LRESULT WINAPI CTraceur_WndProc ( HWND hWnd, UINT uMessage,
                                           WPARAM wParam,LPARAM lParam );
  HWND hWndTraceur;
private:

};

class CGraphPlume;

class CTraceurPlume : public CTraceur {
public:
  IO_API CTraceurPlume (int Prior, int uMd=MODE_XY );   // constructeur 2
  IO_API ~CTraceurPlume ( );
  static bool *lpuEtatPlume;
  IO_API static void InitPlume ( bool *lpuEtatPlume); 
  static int EtatPlume;
protected:
  void virtual main ( void* );                          // code de la t�che
};
#endif
