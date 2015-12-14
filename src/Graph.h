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
	// Mode d'emploi :
	//incert les dones du fichier cible de dataFile dans la map.
	// Contrat :
	//


void insertOption (bool aOptVisual,  bool aOptExclude,  bool aOptHour, int aHourInOpt);
	// Mode d'emploi :
	// icertion des options
	// Contrat :
	//

void insertDataSources (const string & aDataFile );
	// Mode d'emploi :
	// icertion des incertion du cible de fichier.
	// Contrat :
	//Le fichier ciblé par aDataFile doit être un fichier log.

list<string > allLinks();
	// Mode d'emploi :
	// revoie une list string remprésante l'ensemble des lien entre les pages
	// la permière string coorespond a la page rassine
	// la 2ème coorespond a la page cible
	// et la 3ème au nombre de hite
	// Contrat :
	//

void print(ostream &flux) const;
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
friend ostream& operator <<( ostream &flux, const Graph & aGrpah);
   // Mode d'emploi :
    //
    // Contrat :
    //

	Graph & operator = (  Graph & aGraph );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
	Graph ( const Graph & aGraph );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

	Graph (const string & aDataFile, bool aOptVisual,  bool aOptExclude,  bool aOptHour, int aHourInOpt);
    // Mode d'emploi :
    //inscrti les option donné en paramétre incert les donnés de du fichier (addrésse aDataFile)
    // Contrat :
    //Le fichier ciblé par aDataFile doit être un fichier log.

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
	string dataFile;
	bool optVisual;
	bool optExclude;
	bool optHour;
	int hourInOpt;


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Graph>

#endif // GRAPH_H
