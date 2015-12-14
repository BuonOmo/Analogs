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
    file -> get();
	if ( !(file -> eof() || file -> peek() == EOF/*char_traits<wchar_t>::eof()*/ ))
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

Log & Read::readNextLog ( )
{
#ifdef MAP
    cout << "Appel à la methode Read::readNextLog" << endl;
#endif
    string line;
    getline(*file, line);
    //----- recherche de la racine
    string rootFinder ( "\"GET " );
    if (line.find (rootFinder) == string::npos)
    {
        rootFinder = "\"POST ";
    }
    int rootBegin  ( line.find ( rootFinder ) + rootFinder.size ( ) );
#ifdef MAP
	cout << "\trootBegin : " << rootBegin << endl;
#endif
    int rootEnd    ( line.find ( " HTTP", rootBegin ) );
#ifdef MAP
	cout << "\trootEnd : " << rootEnd << endl;
#endif
    int rootLength ( rootEnd - rootBegin );
#ifdef MAP
	cout << "\trootLength : " << rootLength << endl;
#endif
    string root ( line.substr ( rootBegin, rootLength ) );
#ifdef MAP
	cout << "\troot : " << root << endl;
#endif
    //----- recherche de la cible
    int targetBegin  ( line.find ( '"', rootEnd + 15) + 1 );
#ifdef MAP
	cout << "\ttargetBegin : " << targetBegin << endl;
#endif
    int targetEnd    ( line.find ( "\" \"", targetBegin) );
#ifdef MAP
	cout << "\ttargetEnd : " << targetEnd << endl;
#endif
    int targetLength ( targetEnd - targetBegin );
#ifdef MAP
	cout << "\ttargetLength : " << targetLength << endl;
#endif
    string target ( line.substr ( targetBegin, targetLength ) );
#ifdef MAP
	cout << "\ttarget : " << target << endl;
#endif
    //----- recherche de la date
    int dateBegin ( line.find ( '[' ) + 1);
#ifdef MAP
	cout << "\tdateBegin : " << dateBegin << endl;
#endif
    line = line.substr ( dateBegin, line.find( ']') - dateBegin );
    line.replace ( line.find ( '/' ) , 1, 1, ' ' );
    line.replace ( line.find ( '/' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    line.replace ( line.find ( ':' ) , 1, 1, ' ' );
    istringstream streamDate ( line );
    int day;
	streamDate >> day;
#ifdef MAP
	cout << "\tday : " << day << endl;
#endif
    string month;
	streamDate >> month;
#ifdef MAP
	cout << "\tmonth : " << month << endl;
#endif
    int year;
	streamDate >> year;
#ifdef MAP
	cout << "\tyear : " << year << endl;
#endif
    int hour;
	streamDate >> hour;
#ifdef MAP
	cout << "\thour : " << hour << endl;
#endif
    int minute;
    streamDate >> minute;
   #ifdef MAP
	cout << "\tminute : " << minute << endl;
#endif
    int second;
	streamDate >> second;
#ifdef MAP
	cout << "\tsecond : " << second << endl;
#endif
    int gtm;
    if (streamDate.get() == 32) // 32 correspond à +
    {
        streamDate >> gtm;
    }
    else
    {
        streamDate >> gtm;
        gtm = - gtm;
    }
    gtm /= 100;
#ifdef MAP
	cout << "\tgtm : " << gtm << endl;
#endif
    Date date ( hour,
                minute,
                second,
                gtm,
                day,
                year,
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
