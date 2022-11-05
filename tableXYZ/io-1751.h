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

// Pour g�n�rer la DLL #define _MR_IO_EXPORTS dans project settings

// Pour version DEBUG = sorties physiques <--> affichages 
// ajouter _MR_NOCARTE dans les settings pour reg�n�rer IOD

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
// Module Circuit PIO 1751 �quivalent INTEL8255
// h�rite de la classe Port du noyau Temps R�el
// un circuit comporte:
//      3 ports A B C (BASE +0 +1 +2
//      un port de configuration BASE +3
// Seul le mode 0 est g�r�
///////////////////////////////////////////////////////////////////////////////

class CPio1751 :protected CAdamPort {
public:
protected:						// impossible de cr�er un objet
	CPio1751 ( string Trace, UINT AdrBase=CAdamPort::ADR_BASE);                                 	
	CPio1751 ( string Trace,char *szDevNum, UINT AdrBase=CAdamPort::ADR_BASE );	// Cha�ne num�ro du p�riph�rique
	void InitCircuit ( int Offset,char * szMode );         						// configuration du circuit
	void EcrireReg ( int NumPort,char Val );                 					// Ecrire sur port NumPort(1.6)
	int LireReg ( int NumPort );                                    			// Lire sur port NumPort(1.6)

private:
	char iTabModes[8];															// mode 0: S/modes possibles
    	char TraceMsg[256];
	void Tracer(LPSTR Txt);

};

///////////////////////////////////////////////////////////////////////////////
// Module carte E/S parall�le 6 ports organis�s en 2 circuits de 3 ports A,B,C
// A1   port 1
// B1   port 2
// .
// C2   port 6
// h�rite de la classe Pio8255 circuit de type INTEL8255
///////////////////////////////////////////////////////////////////////////////

// Configuration par d�faut de la carte: tout en entr�e
#define DEFAUTMODE "EEEEEE"

// pilote de port utilis� par la carte
// Note: pourrait �tre lu dans un fichier de configuration (conf par d�faut)
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
