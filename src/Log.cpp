/*************************************************************************
                           Log  -  structure d’un log
                             -------------------
    début                : 1 déc. 2015
    copyright            : (C) 2015 par Adrien et Ulysse
*************************************************************************/

///---------- Réalisation de la classe <Log> (fichier Log.cpp) --

///---------------------------------------------------------------- INCLUDE

///-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

///------------------------------------------------------ Include personnel
#include "Log.h"

///------------------------------------------------------------- Constantes

///---------------------------------------------------- Variables de classe
struct Date
{
	int hour;
	int minute;
	int second;
	int timeZone;
	int day;
	int month;
	int year
};
typedef Date struct date;

///----------------------------------------------------------- Types privés

///----------------------------------------------------------------- PUBLIC
///-------------------------------------------------------- Fonctions amies

///----------------------------------------------------- Méthodes publiques

Date getDate()
{
	return date;
}

string getRoot()
{
	return root;
}

string getTarget()
{
	return target;
}


///------------------------------------------------- Surcharge d'opérateurs
Log & Log::operator = ( const Log & unLog )
{
	date = unLog.date;
	root = unLog.root;
	target = unLog.target;
} //----- Fin de operator =


///-------------------------------------------- Constructeurs - destructeur
Log::Log ( const Log & unLog ) :
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Log>" << endl;
#endif
    if (&this != &unLog)
    {
    	this = unLog;
    }
} //----- Fin de Log (constructeur de copie)


Log::Log ( Date aDate, string aRoot, string aTarget ) :
	date (aDate), root (aRoot), target (aTarget)
{
#ifdef MAP
    cout << "Appel au constructeur de <Log>" << endl;
#endif

} //----- Fin de Log

Log::~Log ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Log>" << endl;
#endif
} //----- Fin de ~Log


///------------------------------------------------------------------ PRIVE

///----------------------------------------------------- Méthodes protégées

///------------------------------------------------------- Méthodes privées
