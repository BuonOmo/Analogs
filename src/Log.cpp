/*************************************************************************
                           Log  -  structure d’un log
                             -------------------
    début                : 1 déc. 2015
    copyright            : (C) 2015 par Adrien et Ulysse
*************************************************************************/

//----------- Réalisation de la classe <Log> (fichier Log.cpp) --

//----------------------------------------------------------------- INCLUDE

//--------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------- Include personnel
#include "Log.h"

//------------------------------------------------------------------ PUBLIC

//------------------------------------------------------ Méthodes publiques
Date Log::getDate() const
{
	return date;
} //----- Fin de getDate

string Log::getRoot() const
{
	return root;
} //----- Fin de getRoot

string Log::getTarget() const
{
	return target;
} //----- Fin de getTarget


//-------------------------------------------------- Surcharge d'opérateurs
Log & Log::operator = ( const Log & aLog )
{
	if (this != &aLog)
	{
		date = aLog.date;
		root = aLog.root;
		target = aLog.target;
	}
	return *this;
} //----- Fin de operator =

ostream & operator << ( ostream & os, const Log & aLog)
{
    os << "( " << aLog.root << " ; " << aLog.target << " ; ";
    os << aLog.date.day << " ; ";
    os << aLog.date.month << " ; ";
    os << aLog.date.year << " ; ";
    os << aLog.date.hour << " ; ";
    os << aLog.date.minute << " ; ";
    os << aLog.date.second << " ; ";
    os <<  (( aLog.date.timeZone >= 0 ) ? '+' : '-' );
    os << aLog.date.timeZone << " )" << endl;
	return os;
} //----- Fin de operator <<


//--------------------------------------------- Constructeurs - destructeur
Log::Log ( const Log & aLog )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Log>" << endl;
#endif
	*this = aLog;
} //----- Fin de Log (constructeur de copie)


Log::Log ( const Date & aDate,
		   const string & aRoot,
		   const string & aTarget ) :
	date (aDate), root (aRoot), target (aTarget)
{
#ifdef MAP
    cout << "Appel au constructeur de <Log>" << endl;
#endif

} //----- Fin de Log

Log::~Log ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Log>" << endl;
#endif
} //----- Fin de ~Log
