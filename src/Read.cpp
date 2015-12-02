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
#include <fstream>

///------------------------------------------------------ Include personnel
#include "Read.h"

///------------------------------------------------------------- Constantes

///---------------------------------------------------- Variables de classe

///----------------------------------------------------------- Types privés


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
    int rootBegin  ( find ( rootFinder ) + rootFinder.size ( ) );
    int rootEnd    ( find ( '"', rootBegin ) );
    int rootLength ( rootEnd - rootBegin );
    string root ( line.substr ( rootBegin, rootLength ) );
    //----- recherche de la cible
    int targetBegin  ( find ( '"', rootEnd + 1 );
    int targetEnd    ( find ( '"', targetBegin + 1 ) );
    int targetLength ( targetEnd - targetBegin );
    string target ( line.substr ( targetBegin, targetEnd ) );
    //----- recherche de la date ________________________________________________________TODO
    Date date;
    root = line.substr())
    return new Log(date, root, target);
} //----- Fin de readNextLog

///------------------------------------------------- Surcharge d'opérateurs
Read & Read::operator = ( const Read & unRead )
// Algorithme :
//
{
	this.file = unRead.file;
} //----- Fin de operator =


///-------------------------------------------- Constructeurs - destructeur
Read::Read ( const Read & unRead )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Read>" << endl;
#endif

    if (&this != &unRead)
    {
    	this = unRead;
    }
} //----- Fin de Read (constructeur de copie)


Read::Read ( string aFile )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Read>" << endl;
#endif

    if (aFile.rfind(".log\0") != string::npos)
    {
    	cerr << "Le fichier selectionné n’est pas un fichier .log"<< endl;
    	return 1;
    }

    file(aFile, ios::in);

    if (!file)
    {
		cerr << "Impossible d'ouvrir le fichier " << aFile << '.' <<endl;
		return 1;
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
