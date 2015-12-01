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
// type Read::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


///------------------------------------------------- Surcharge d'opérateurs
Read & Read::operator = ( const Read & unRead )
// Algorithme :
//
{
} //----- Fin de operator =


///-------------------------------------------- Constructeurs - destructeur
Read::Read ( const Read & unRead )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Read>" << endl;
#endif
} //----- Fin de Read (constructeur de copie)


Read::Read ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Read>" << endl;
#endif

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
