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
#include <sstream>

///------------------------------------------------------ Include personnel
#include "Read.h"

///----------------------------------------------------------------- PUBLIC

///----------------------------------------------------- Méthodes publiques

bool Read::hasNextLog ( )
{
#ifdef MAP
    cout << "Appel à la methode Read::hasNextLog" << endl;
#endif
<<<<<<< HEAD
    char c = file -> get();
	if ( !(file -> eof() || file -> peek() == EOF/*char_traits<wchar_t>::eof()*/ ))
=======
    file -> get();
	if ( !(file -> eof() || file -> peek() == char_traits<wchar_t>::eof() ))
>>>>>>> e81e57a65b89a31bcd24d11b18383a48a2eb8fb1
	{
        file -> unget();
#ifdef MAP
	cout << "Read::hasNextLog = true" << endl;
#endif
		return true;
	}
    file -> unget();
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
    getline(*file, line);
    //----- recherche de la racine
    string rootFinder ( "\"GET " );
    int rootBegin  ( line.find ( rootFinder ) + rootFinder.size ( ) );
    cout << rootBegin << endl;
    int rootEnd    ( line.find ( " HTTP", rootBegin ) );
    int rootLength ( rootEnd - rootBegin );
    if (rootLength == 0)
    {
        cout << "La taille de la racine n’est pas bonne :" << endl;
        cout << line << endl;
        cout << "____________________________________________________" << endl;
    }
    string root ( line.substr ( rootBegin, rootLength ) );
    //----- recherche de la cible
    int targetBegin  ( line.find ( '"', rootEnd + 15) + 1 );
    int targetEnd    ( line.find ( "\" \"", targetBegin) );
    int targetLength ( targetEnd - targetBegin );
    string target ( line.substr ( targetBegin, targetLength ) );
    //----- recherche de la date
    string month;
    int newDate[6];
    int dateBegin ( line.find ( '[' ) + 1);
    line = line.substr ( dateBegin, line.find( ']') - dateBegin );
    line.replace ( line.find ( '/' ) , 1, 1, ' ' );
    line.replace ( line.find ( '/' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    istringstream streamDate ( line );
    streamDate >> newDate[4];
    streamDate >> month;
    streamDate >> newDate[5];
    streamDate >> newDate[0];
    streamDate >> newDate[1];
    streamDate >> newDate[2];
    if (streamDate.get() == 32) // 32 correspond à +
    {
        streamDate >> newDate[3];
    }
    else
    {
        streamDate >> newDate[3];
        newDate[3] = - newDate[3];
    }
    newDate[3] /= 100;
    Date date ( newDate[0],
                newDate[1],
                newDate[2],
                newDate[3],
                newDate[4],
                newDate[5],
                month);
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
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Read>" << endl;
#endif
    *this = unRead;
} //----- Fin de Read (constructeur de copie)


Read::Read ( const string & aFile ) : fileName(aFile)
{
#ifdef MAP
    cout << "Appel au constructeur de <Read>" << endl;
#endif

    if (aFile.find(".log\0") == string::npos)
    {
    	cerr << "Le fichier selectionné n’est pas un fichier .log"<< endl;
    	return;
    }

    file = new ifstream (aFile.c_str(), fstream::in);

    if (!*(file))
    {
		cerr << "Impossible d'ouvrir le fichier " << aFile << '.' <<endl;
	}
} //----- Fin de Read


Read::~Read ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Read>" << endl;
#endif
} //----- Fin de ~Read
