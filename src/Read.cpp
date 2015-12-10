/*************************************************************************
                      Read  -  classe de lecture de log
                             -------------------
    début                : 1 dec. 2015
    copyright            : (C) 2015 par Ulysse et Adrien
*************************************************************************/

///---------- Réalisation de la classe <Read> (fichier Read.cpp) --

///---------------------------------------------------------------- INCLUDE

///-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

///------------------------------------------------------ Include personnel
#include "Read.h"

///----------------------------------------------------------------- PUBLIC
///-------------------------------------------------------- Fonctions amies

///----------------------------------------------------- Méthodes publiques

bool Read::hasNextLog ( )
{
#ifdef MAP
    cout << "Appel à la methode Read::hasNextLog" << endl;
#endif

	if ( !file.eof() )
	{
		char c;
		file.get(c);
		if ( (int)c == 1 && file.eof() )
		{
			file.unget();
#ifdef MAP
	cout << "Read::hasNextLog = true" << endl;
#endif
			return true;
		}
	}
#ifdef MAP
	cout << "Read::hasNextLog = false" << endl;
#endif
	return false;
} //----- Fin de hasNextLog

Log Read::readNextLog ( )
{
#ifdef MAP
    cout << "Appel à la methode Read::readNextLog" << endl;
#endif
    string line;
    getline(file, line);
    //----- recherche de la racine
    string rootFinder ( "\"GET " );
    int rootBegin  ( line.find ( rootFinder ) + rootFinder.size ( ) );
    int rootEnd    ( line.find ( " HTTP", rootBegin ) );
    int rootLength ( rootEnd - rootBegin );
    string root ( line.substr ( rootBegin, rootLength ) );
    //----- recherche de la cible
    int targetBegin  ( line.find ( '"', rootEnd + 15) + 1 );
    int targetEnd    ( line.find ( "\" \"", targetBegin) );
    int targetLength ( targetEnd - targetBegin );
    string target ( line.substr ( targetBegin, targetLength ) );
    //----- recherche de la date
    Date date;
    int dateBegin ( line.find ( '[' ) + 1);
    line = line.substr ( dateBegin, line.find( ']') - dateBegin );
    line.replace ( line.find ( '/' ) , 1, 1, ' ' );
    line.replace ( line.find ( '/' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    //istringstream streamDate ( line );
    /*streamDate >>*/ date.day = 0;
    /*streamDate >>*/ date.month = "0";
    /*streamDate >>*/ date.year = 0;
    /*streamDate >>*/ date.hour = 0;
    /*streamDate >>*/ date.minute = 0;
    /*streamDate >>*/ date.second = 0;
    if (/*streamDate.get() == 32*/true) // 32 correspond à +
    {
        /*streamDate >>*/ date.timeZone = 0;
    }
    else
    {
        /*streamDate >>*/ date.timeZone = 0;
        date.timeZone = - date.timeZone;
    }
    date.timeZone /= 100;

    return *(new Log(date, root, target));
} //----- Fin de readNextLog

///------------------------------------------------- Surcharge d'opérateurs
Read & Read::operator = ( const Read & aRead )
// Algorithme :
//
{
    if (this != &aRead)
    {
        cerr << "impossible de copier le flux" << endl;
    }
	return *this;
} //----- Fin de operator =


///-------------------------------------------- Constructeurs - destructeur
Read::Read ( const Read & unRead )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Read>" << endl;
#endif

    if (this != &unRead)
    {
    	*this = unRead;
    }
} //----- Fin de Read (constructeur de copie)


Read::Read ( const string & aFile )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Read>" << endl;
#endif

    if (aFile.rfind(".log\0") != string::npos)
    {
    	cerr << "Le fichier selectionné n’est pas un fichier .log"<< endl;
    	return;
    }

    ifstream file(aFile.c_str(), ios::in);

    if (!file)
    {
		cerr << "Impossible d'ouvrir le fichier " << aFile << '.' <<endl;
	}

} //----- Fin de Read


Read::~Read ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Read>" << endl;
#endif
} //----- Fin de ~Read


///------------------------------------------------------------------ PRIVE

///----------------------------------------------------- Méthodes protégées

///------------------------------------------------------- Méthodes privées
