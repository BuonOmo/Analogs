/*************************************************************************
                      Read  -  classe de lecture de log
                             -------------------
    début                : 1 dec. 2015
    copyright            : (C) 2015 par Ulysse et Adrien
*************************************************************************/

//---------- Interface de la classe <Read> (fichier Read.h) ------
#ifndef READ_H
#define READ_H

//--------------------------------------------------- Interfaces utilisées
#include "Log.h"
#include <fstream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Read permet de lire un fichier log et d’en dégager les élements clés
// pour faciliter le traitement ulterieur par un utilisateur.
//
//------------------------------------------------------------------------

class Read
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool hasNextLog ( );
    // Mode d'emploi :
    // Verifie s’il reste encore un log dans le fichier.
    //
    // Contrat :
    // -

    Log readNextLog ( );
    // Mode d'emploi :
    // Lis la ligne suivant et renvoi un objet Log correspondant.
    //
    // Contrat :
    // -


//------------------------------------------------- Surcharge d'opérateurs
    Read & operator = ( const Read & aRead );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Read ( const Read & aRead );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Read ( const string & aFile );
    // Mode d'emploi :
    // Appel le constructeur  avec  un  nom de fichier (à la racine) ou un
    // chemin.  Un mauvais adressage peut être detecté si un autre fichier
    // n’est pas ciblé.
    //
    // Contrat :
    // Le fichier ciblé par aFile doit être un fichier log.

    virtual ~Read ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    ifstream file;

};

#endif // READ_H
