/*************************************************************************
                      Read  -  classe de lecture de log
                             -------------------
    début                : 1 dec. 2015
    copyright            : (C) 2015 par Ulysse et Adrien
*************************************************************************/

//---------- Interface de la classe <Read> (fichier Read.h) ------
#if ndef ( READ_H )
#define READ_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Read>
//
//
//------------------------------------------------------------------------ 

class Read
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


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

    Read ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Read ( );
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
    ifstream file;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Read>

#endif // READ_H
