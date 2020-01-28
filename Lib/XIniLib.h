#ifndef _INILIB_H_
#define _INILIB_H_

#include "iniparser.h"

namespace XLib {

	class INI {
	public:
    
    INI() {
      _dict = dictionary_new(0);
    }
    ~INI() {
      if( _dict != NULL )
        iniparser_freedict(_dict);
    }

    bool Load( const char* fileName );
    void Save();
    void SaveAs( const char* fileName );
    char* GetVal( const char* key, char* def );
    double GetVal( const char* key, double def );
    int GetVal( const char* key, int def );
    int SetSection( const char* name );
    int GetNumberOfSections();
    char* GetSectionByIndex( int index );
    int SetVal( const char* key, const char* val );
    void Free();

  private: 

  private: 
    dictionary* _dict;
    char* _fileName;
	};

  static INI Ini;
}

#endif