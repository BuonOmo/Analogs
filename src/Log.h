/*************************************************************************
                           Log  -  structure d’un log
                             -------------------
    début                : 1 déc. 2015
    copyright            : (C) 2015 par Adrien et Ulysse
*************************************************************************/

//--------------------- Interface de la classe <Log> (fichier Log.h) ------
#ifndef LOG_H
#define LOG_H

//---------------------------------------------------- Interfaces utilisées
#include "Date.h"
#include <string>

//-------------------------------------------------------------------------
// Log permet de gerer des attributs contenant les élements principaux
// d’une ligne d’un fichier log. Et de les afficher.
//-------------------------------------------------------------------------

class Log
{
//------------------------------------------------------------------ PUBLIC

public:
//------------------------------------------------------ Méthodes publiques

    //------------------------------------------------------------- GETTERS
    // Contrat :
    // Renvoi la valeur de la variable annoncée.

    Date getDate() const;

    string getRoot() const;

    string getTarget() const;


//-------------------------------------------------- Surcharge d'opérateurs
    Log & operator = ( const Log & unLog );
    // Contrat :
    // Copie un à un les elements d’un Log.

    friend ostream & operator << ( ostream & os, const Log & unLog);
	// Contrat :
	// Affiche un log au format (Racine ; Cible ; Date).

//--------------------------------------------- Constructeurs - destructeur
    Log ( const Log & unLog );
    // Contrat :
    // Voir operator =.

    Log ( const Date   & aDate   = *(new Date ()),
		  const string & aRoot   = "root",
		  const string & aTarget = "target"
		  );
    // Mode d'emploi :
    // Entrer les valeurs des parametres.
    // Contrat :
    // -

    virtual ~Log ( );
    // Contrat :
    // Rien à detruire.

//------------------------------------------------------------------- PRIVE

private:
//-------------------------------------------------------- Attributs privés
    Date date;
    string root;
    string target;
};

#endif // LOG_H
