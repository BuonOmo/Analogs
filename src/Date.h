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
// Date permet de génerer des dates, d’acceder aux differents élements de
// celles-ci et de les afficher. 
//-------------------------------------------------------------------------

class Date
{
//------------------------------------------------------------------ PUBLIC

public:
//------------------------------------------------------ Méthodes publiques
    int getHour () const;
    // Contrat :
    // Renvoi l’attribut hour.

//-------------------------------------------------- Surcharge d'opérateurs
    Date & operator = ( const Date & aDate );
    // Contrat :
    // Copier tous les attributs un à un.

    friend ostream & operator << ( ostream & os, const Date & aDate);
    // Contrat :
    // Format -> [DD/Mon/YYYY:HH:MM:SS ±TTTT], T réfère à timeZone

//--------------------------------------------- Constructeurs - destructeur
    Date ( const Date & aDate );
    // Contrat :
    // Voir operator =.

    Date ( 	int aHour     = 0,
            int aMinute   = 0,
            int aSecond   = 0,
            int aTimeZone = 0,
            int aDay      = 1,
            int aYear     = 2000,
            const string & aMonth = "Jan"
         );
    // Mode d'emploi :
    // Entrer les valeurs correspondant au nom des attributs. Pour le mois
    // il s’agit des trois premières lettres en anglais.
    //
    // Contrat :
    // Les paramètres doivent être entré dans des formats valide
    // (60 minutes / 24 heures / Jan, Feb, Mar..).
    // Les GTM comprenant des demi-heures ne sont pas pris en compte et
    // sont automatiquement tronqués.

    virtual ~Date ( );
    // Contrat :
    // Rien à detruire

//------------------------------------------------------------------- PRIVE

private:
//-------------------------------------------------------- Attributs privés
    int hour;
    int minute;
    int second;
    int timeZone;
    int day;
    int year;
    string month;
};

#endif // DATE_H
