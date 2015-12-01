/*************************************************************************
                      Read  -  classe de lecture de log
                             -------------------
    d�but                : 1 dec. 2015
    copyright            : (C) 2015 par Ulysse et Adrien
*************************************************************************/

//---------- Interface de la classe <Read> (fichier Read.h) ------
#if ndef ( READ_H )
#define READ_H

//--------------------------------------------------- Interfaces utilis�es
#include "Log.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Read>
//
//
//------------------------------------------------------------------------ 

class Read
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool hasNextLog ( );

    Log readNextLog ( );


//------------------------------------------------- Surcharge d'op�rateurs
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

    Read ( string aFile );
    // Mode d'emploi :
    // Appel le constructeur  avec  un  nom de fichier (� la racine) ou un
    // chemin.  Un mauvais adressage peut �tre detect� si un autre fichier
    // n�est pas cibl�.
    // 
    // Contrat :
    // Le fichier cibl� par aFile doit �tre un fichier log.

    virtual ~Read ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
    ifstream file;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Read>

#endif // READ_H
