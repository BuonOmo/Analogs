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
typedef struct Date
{
	int hour;
	int minute;
	int second;
	int timeZone; //_______________ ne prends pas en compte les demi heures
	int day;
	string month;
	int year;
} Date;

///----------------------------------------------------------- Types privés

///----------------------------------------------------------------- PUBLIC
///-------------------------------------------------------- Fonctions amies

///----------------------------------------------------- Méthodes publiques

Date Log::getDate()
{
	return date;
} //----- Fin de getDate

string Log::getRoot()
{
	return root;
} //----- Fin de getRoot

string Log::getTarget()
{
	return target;
} //----- Fin de getTarget


///------------------------------------------------- Surcharge d'opérateurs
Log & Log::operator = ( const Log & unLog )
{
	date = unLog.date;
	root = unLog.root;
	target = unLog.target;
} //----- Fin de operator =

ostream & Log::operator << ( ostream & os, const Log & unLog)
{
    os << "( " << root << " ; " << target << " ; ";
    os << date.day << " ; ";
    os << date.month << " ; ";
    os << date.year << " ; ";
    os << date.hour << " ; ";
    os << date.minute << " ; ";
    os << date.second << " ; ";
    os <<  (( date.timeZone >= 0 ) ? '+' : '-' );
    os << date.timeZone << " )" << endl;
	return os;
}


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
