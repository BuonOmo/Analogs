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
    os << "( ";
	os << aLog.root << " ; ";
	os << aLog.target << " ; ";
    os << aLog.date << " )";
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
		   const string & aTarget,
	       bool removeLocalAddress) :
	date (aDate), root (aRoot), target (aTarget)
{
#ifdef MAP
    cout << "Appel au constructeur de <Log> avec les parametres :" << endl;
	cout << "\t" << aDate << "\n\t" << aRoot << "\n\t" << aTarget << "\n\t";
	cout << removeLocalAddress << endl;
#endif
	if (aTarget == "-")
	{
		target = "";
	}
	if (removeLocalAddress)
	{
		string localAddress = "http://intranet-if.insa-lyon.fr";
		int position = root.find(localAddress);
		cout << localAddress.size() << " + " << position << endl;
		if (position != string::npos)
		{
			root =
			  aRoot.substr(position + localAddress.size(), aRoot.size()-1);
		}
	}
#ifdef MAP
	cout << *this << endl;
#endif
} //----- Fin de Log

Log::~Log ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Log>" << endl;
#endif
} //----- Fin de ~Log
