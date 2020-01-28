#include "stdafx.h"
#include <wtypes.h>

typedef int  (__stdcall *loadType)(const char*);

int main( int argc, char *argv[] ) {   
  HMODULE h = ::LoadLibrary( L"./XIniLib.dll" );
  if (h)
  {
    loadType l = (loadType)::GetProcAddress(h, "Load");	

    if (l)
    {

      l("c://test.ini");

      ::FreeLibrary(h);
    }
  }

  getchar();
}  
