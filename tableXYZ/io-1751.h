/////////////////// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! /////////////////////
// POUR LA COMPILATION ET L'UTILISATION  DE LA LIBRAIRIES DYNAMIQUE
// POUR LA COMPILATION DE LA LIBRAIRIES STATIQUE
// POUR L'UTILISATION DE LA LIBRAIRIE STATIQUE --> UTILISER CARTE6P.H
/////////////////// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! /////////////////////

///////////////////////////////////////////////////////////////////////////////
// interface pour l'API IO.DLL (E/S sur un port //)
///////////////////////////////////////////////////////////////////////////////
#ifndef _MR_IO_1751_H
 #define _MR_IO_1751_H

// Pour générer la DLL #define _MR_IO_EXPORTS dans project settings

// Pour version DEBUG = sorties physiques <--> affichages 
// ajouter _MR_NOCARTE dans les settings pour regénérer IOD

#include "conio.h"
#include <iostream>
#include <cstring>

using namespace std;

#ifdef _LIB
 #define IO_API
#else
#ifdef _MR_IO_EXPORTS
 #define IO_API __declspec(dllexport)
#else
 #define IO_API __declspec(dllimport)
#endif
#endif

#pragma comment(linker, "/nodefaultlib:LIBCMT") // n'utiliser que LIBCMT
#include "X:\Mtr86W32\NoyauObj\mtrObj.h"

class CAdamPort;

///////////////////////////////////////////////////////////////////////////////
// Module Circuit PIO 1751 équivalent INTEL8255
// hérite de la classe Port du noyau Temps Réel
// un circuit comporte:
//      3 ports A B C (BASE +0 +1 +2
//      un port de configuration BASE +3
// Seul le mode 0 est géré
///////////////////////////////////////////////////////////////////////////////

class CPio1751 :protected CAdamPort {
public:
protected:						// impossible de créer un objet
	CPio1751 ( string Trace, UINT AdrBase=CAdamPort::ADR_BASE);                                 	
	CPio1751 ( string Trace,char *szDevNum, UINT AdrBase=CAdamPort::ADR_BASE );	// Chaîne numéro du périphérique
	void InitCircuit ( int Offset,char * szMode );         						// configuration du circuit
	void EcrireReg ( int NumPort,char Val );                 					// Ecrire sur port NumPort(1.6)
	int LireReg ( int NumPort );                                    			// Lire sur port NumPort(1.6)

private:
	char iTabModes[8];															// mode 0: S/modes possibles
    	char TraceMsg[256];
	void Tracer(LPSTR Txt);

};

///////////////////////////////////////////////////////////////////////////////
// Module carte E/S parallèle 6 ports organisés en 2 circuits de 3 ports A,B,C
// A1   port 1
// B1   port 2
// .
// C2   port 6
// hérite de la classe Pio8255 circuit de type INTEL8255
///////////////////////////////////////////////////////////////////////////////

// Configuration par défaut de la carte: tout en entrée
#define DEFAUTMODE "EEEEEE"

// pilote de port utilisé par la carte
// Note: pourrait être lu dans un fichier de configuration (conf par défaut)
#define DEFAUTPORT "0"

class CCarte6P : protected CPio1751 {
public:
  IO_API CCarte6P ( string Trace, UINT AdrBase=CAdamPort::ADR_BASE );
  IO_API CCarte6P ( string Trace,char* szMode,char* szPort=DEFAUTPORT, UINT AdrBase=CAdamPort::ADR_BASE );
  IO_API ~CCarte6P ( );
  IO_API void InitCarte ( char* szMode );
  IO_API void EcrirePort ( unsigned int uNumPort, int iVal );
  IO_API void LirePort ( unsigned int uNumPort, char* lpValeur );
  IO_API void OuvrirPort ( char * szName );
  IO_API void FermerPort ( );

private:
  LONG hPort;                                 // handle du port ouvert
  char szModeCirc1[4];                    // s/mode du circuit 1
  char szModeCirc2[4];                    // s/mode du circuit 2
  char szPortName[80];                    // nom du port (driver NT)
  char szMode[7];                           // mode de configuration
  char TraceMsg[256];	
  string 	Trace;
  void Tracer(LPSTR Txt);
};
#endif
