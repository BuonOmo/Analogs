/*************************************************************************
                           Date  -  description
                             -------------------
    début                : 10/12/2015
    copyright            : (C) 2015 par ulysse
*************************************************************************/

//------------------- Interface de la classe <Date> (fichier Date.h) ------
#ifndef DATE_H
#define DATE_H

//---------------------------------------------------- Interfaces utilisées
#include <string>
//-------------------------------------------------------------- Constantes

//------------------------------------------------------------------- Types

//-------------------------------------------------------------------------
// Rôle de la classe <Date>
//
//
//-------------------------------------------------------------------------

class Date
{
//------------------------------------------------------------------ PUBLIC

public:
//------------------------------------------------------ Méthodes publiques
    int getHour () const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------------- Surcharge d'opérateurs
    Date & operator = ( const Date & aDate );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend ostream & operator << ( ostream & os, const Date & aDate);

//--------------------------------------------- Constructeurs - destructeur
    Date ( const Date & aDate );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Date ( 	int aHour     = 0,
            int aMinute   = 0,
            int aSecond   = 0,
            int aTimeZone = 0, //__ ne prends pas en compte les demi heures
            int aDay      = 1,
            int aYear     = 2000,
            const string & aMonth = "Jan"
         );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Date ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------- PRIVE

protected:
//------------------------------------------------------ Méthodes protégées

private:
//-------------------------------------------------------- Méthodes privées

protected:
//------------------------------------------------------ Attributs protégés

private:
//-------------------------------------------------------- Attributs privés
int hour;
int minute;
int second;
int timeZone; //_______________ ne prends pas en compte les demi heures
int day;
string month;
int year;
//----------------------------------------------------------- Classes amies

//--------------------------------------------------------- Classes privées

//------------------------------------------------------------ Types privés

};

//------------------------------------------ Types dépendants de <Date>

#endif // DATE_H
