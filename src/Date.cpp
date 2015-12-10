/*************************************************************************
                           Date  -  description
                             -------------------
    début                : 10/12/2015
    copyright            : (C) 2015 par ulysse
*************************************************************************/

//------------------- Réalisation de la classe <Date> (fichier Date.cpp) --

//----------------------------------------------------------------- INCLUDE

//--------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>

//------------------------------------------------------- Include personnel
#include "Date.h"

//------------------------------------------------------------------ PUBLIC

//------------------------------------------------------ Méthodes publiques
int Date::getHour () const
{
#ifdef MAP
    cout << "Appel à la méthode getHour de <Date>" << endl;
#endif
    return hour;
} //----- Fin de getHour


//-------------------------------------------------- Surcharge d'opérateurs
Date & Date::operator = ( const Date & aDate )
{
    if (this != &aDate) {
        hour = aDate.hour;
        minute = aDate.minute;
        second = aDate.second;
        timeZone = aDate.timeZone;
        day = aDate.day;
        year = aDate.year;
        month = aDate.month;
    }
    return *this;
} //----- Fin de operator =

ostream & operator << ( ostream & os, const Date & aDate)
{
    string zero = (day < 10) ? "0" : "";
    os << '[' << zero << day;
    os << '/' << month;
    os << '/' << year;
    zero = (hour < 10) ? "0" : "";
    os << ':' << zero << hour;
    zero = (minute < 10) ? "0" : "";
    os << ':' << zero << minute;
    zero = (second < 10) ? "0" : "";
    os << ':' << zero << second;
    char plus = (timeZone < 0) ? '-' : '+';
    zero = (timeZone < 10) ? "0" : "";
    os << ' ' << plus << zero << timeZone;
    os << "00]";
    return os;
} //----- Fin de operator <<

//--------------------------------------------- Constructeurs - destructeur
Date::Date ( const Date & aDate )
// Algorithme :
// Utilisation de la surcharge
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Date>" << endl;
#endif
    *this = aDate;
} //----- Fin de Date (constructeur de copie)


Date::Date ( 	int aHour,
                int aMinute,
                int aSecond,
                int aTimeZone,
                int aDay,
                int aYear,
                const string & aMonth
            ) :
            hour ( aHour ),
            minute ( aMinute ),
            second ( aSecond ),
            timeZone ( aTimeZone ),
            day ( aDay ),
            year ( aYear ),
            month ( aMonth )
{
#ifdef MAP
    cout << "Appel au constructeur de <Date>" << endl;
#endif
} //----- Fin de Date


Date::~Date ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Date>" << endl;
#endif
} //----- Fin de ~Date
