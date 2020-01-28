#include <windows.h>

#include "XIniLib.h"

namespace XLib {

  bool INI::Load( const char* fileName )
  {
    _fileName = new char[strlen(fileName) + 1];
    strcpy( _fileName, fileName );
    //_fileName = fileName;
    _dict = iniparser_load( fileName );

    if( NULL != _dict )
      return true;

    _dict = dictionary_new(0) ;
    return false;
  }

int writeLog(const char *file, const char *content) {
    if (file && content)     {
      FILE* fd = fopen(file, "a+b");
      if (!fd)
        return 1;
      else {
        SYSTEMTIME st;
        GetLocalTime(&st);
        fprintf( fd, "%04d.%02d.%02d %02d:%02d:%02d.%03d > Content:\r\n%s\r\n", 
          st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds, content );

        fclose(fd);
      }
    }
    return 0;
  }


  void INI::Save()
  {
    FILE *file;

    if (( file = fopen(_fileName, "w")) != NULL) {
      iniparser_dump_ini(_dict, file);
      fclose( file );
      return;
    }    

  }

  void INI::SaveAs( const char* fileName )
  {
    FILE *file;

    if (( file = fopen(fileName, "w")) != NULL) {
      iniparser_dump_ini(_dict, file);
      fclose( file );
    }
  }

  char* INI::GetVal( const char* key, char* def )
  {
    return iniparser_getstring( _dict, key, def );
  }

  double INI::GetVal( const char* key, double def )
  {
    return iniparser_getdouble( _dict, key, def );
  }

  int INI::GetVal( const char* key, int def )
  {
    return iniparser_getint( _dict, key, def );
  }

  int INI::SetSection( const char* name ) {
    return iniparser_setstring(_dict, name, NULL );
  }

  int INI::GetNumberOfSections() {
    return iniparser_getnsec( _dict );
  }

  char* INI::GetSectionByIndex( int index ) {
    return iniparser_getsecname( _dict, index );
  }

  int INI::SetVal( const char* key, const char* val ) {
    return iniparser_setstring(_dict, key, val );
  }

  void INI::Free()
  {
    iniparser_freedict(_dict);
  }
}
