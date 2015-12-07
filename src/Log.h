/*************************************************************************
                           Log  -  structure d’un log
                             -------------------
    début                : 1 déc. 2015
    copyright            : (C) 2015 par Adrien et Ulysse
*************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ------
#ifndef LOG_H
#define LOG_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
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

//------------------------------------------------------------------------
// Rôle de la classe <Log>
//
//
//------------------------------------------------------------------------

class Log
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    // ----------------------------------------------------------- GETTERS
    // Mode d'emploi :
    //
    // Contrat :
    // renvoi la valeur de la variable annoncée

    Date getDate();

    string getRoot();

    string getTarget();


//------------------------------------------------- Surcharge d'opérateurs
    Log & operator = ( const Log & unLog );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend ostream & operator << ( ostream & os, const Log & unLog);

//-------------------------------------------- Constructeurs - destructeur
    Log ( const Log & unLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Log ( const Date &aDate, const string &aRoot, const string &aTarget );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    Date date;
    string root;
    string target;

};

//----------------------------------------- Types dépendants de <Log>

#endif // LOG_H
