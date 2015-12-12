/*************************************************************************
                    	Graph  -  gestion de graphs
                             -------------------
    début                : 1 dec. 2015
    copyright            : (C) 2015 par Ulysse et Adrien
*************************************************************************/

//---------- Interface de la classe <Graph> (fichier Graph.h) ------
#ifndef GRAPH_H
#define GRAPH_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
//class Graph;
#include <string>
#include "Read.h"
#include <map>
#include <list>
#include "Log.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Link{
	string root;
	string target;
	int flux;
}Link;

//------------------------------------------------------------------------
// Rôle de la classe <Graph>
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

list<string*> allLinks();

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

//----------------------------------------- Types dépendants de <Graph>

#endif // GRAPH_H
