/*************************************************************************
                      Read  -  classe de lecture de log
                             -------------------
    d�but                : 1 dec. 2015
    copyright            : (C) 2015 par Ulysse et Adrien
*************************************************************************/

///---------- R�alisation de la classe <Read> (fichier Read.cpp) --

///---------------------------------------------------------------- INCLUDE

///-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>
#include <fstream>

///------------------------------------------------------ Include personnel
#include "Read.h"

///------------------------------------------------------------- Constantes

///---------------------------------------------------- Variables de classe

///----------------------------------------------------------- Types priv�s


///----------------------------------------------------------------- PUBLIC
///-------------------------------------------------------- Fonctions amies

///----------------------------------------------------- M�thodes publiques

bool Read::hasNextLog ( )
{

} //----- Fin de hasNextLog

bool Read::readNextLog ( )
{

} //----- Fin de readNextLog

///------------------------------------------------- Surcharge d'op�rateurs
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
    	cerr << "Le fichier selectionn� n�est pas un fichier .log"<< endl;
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

///----------------------------------------------------- M�thodes prot�g�es

///------------------------------------------------------- M�thodes priv�es
