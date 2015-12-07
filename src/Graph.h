/*************************************************************************
                      Read  -  classe de lecture de log
                             -------------------
    début                : 1 dec. 2015
    copyright            : (C) 2015 par Ulysse et Adrien
*************************************************************************/

//---------- Interface de la classe <Read> (fichier Read.h) ------
#ifndef GRAPH_H
#define GRAPH_H

//--------------------------------------------------- Interfaces utilisées
#include "Read.h"
#include <string>
#include <map>
#include <list>


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Link{
	string root;
	string target;
	int flux;
}Link;

//------------------------------------------------------------------------
// Rôle de la classe <Read>
//
//
//------------------------------------------------------------------------

class Graph
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

void insertData();

void insertOption (bool aOptVisual,  bool aOptExclude,  bool aOptHour, int aHourInOpt);

void insertDataSources (const Read & aData );

list<string [3]> allLinks();

//------------------------------------------------- Surcharge d'opérateurs
	Graph & operator = (  Graph & aGraph );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
	Graph (  Graph & aGraph );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

	Graph (const Read & aData, bool aOptVisual,  bool aOptExclude,  bool aOptHour, int aHourInOpt);
    // Mode d'emploi :
    //
    // Contrat :
    //

	Graph (  );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graph ( );
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
	map<string,map<string,int>* > graph ;
	bool optVisual;
	bool optExclude;
	bool optHour;
	int hourInOpt;
	Read * data;


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Read>

#endif // READ_H

