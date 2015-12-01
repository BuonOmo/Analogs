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
