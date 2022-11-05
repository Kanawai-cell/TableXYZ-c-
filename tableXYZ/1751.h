#pragma once

#include "M:\tp\iris2\TableXYZ\include-Adam\driver.h"
#include "M:\tp\iris2\TableXYZ\include-Adam\os.h"
#include <cstring>
#include <iostream>

using namespace std;
//--------------------------------------------------------------------------------------------
// Classe Port : accès aux ports E/S
//--------------------------------------------------------------------------------------------
class CAdamPort {
  public :
    CAdamPort ( string Trace, UINT AdrBase=ADR_BASE );
    CAdamPort ( string Trace,char* szNumDev, UINT AdrBase=ADR_BASE );
    void open ( char* szNumDev );
    void close ( );
    ~CAdamPort( );
    BYTE   InPortb  ( DWORD dwOffset );
    USHORT InPortw  ( DWORD dwOffset );
//    DWORD  InPortdw ( DWORD dwOffset );
    void   OutPortb ( DWORD dwOffset, DWORD dwData );
    void   OutPortw ( DWORD dwOffset, DWORD dwData );
//    void   OutPortdw( DWORD dwOffset, DWORD dwData );
    LONG handle   ( );
  private :
//   Port           ( const Port& );
//   Port& operator=( const Port& );

  private :
    void Tracer(LPSTR Txt);
//\/\/\/\/\/\/\ NE PAS MODIFIER !!! \/\/\/\/\/\/\/\//
   LONG IOstatus;
  USHORT Base;
  LONG DriverHandle;
  char szNumDev[80+80];
  PT_DioReadPortByte ptDioReadPortByte;
  PT_DioWritePortByte ptDioWritePortByte;
  PT_ReadPortByte ptReadPortByte;
  PT_WritePortByte ptWritePortByte;
  PT_ReadPortWord ptReadPortWord;
  PT_WritePortWord ptWritePortWord;
//  PT_ReadPortDword ptReadPortDword;
//  PT_WritePortDword ptWritePortDword;
  char TraceMsg[256];
//\/\/\/\/\/\/\ NE PAS MODIFIER !!! \/\/\/\/\/\/\/\//
protected:
  HANDLE hTrace;
  static const UINT ADR_BASE = 0xD400	;
};
