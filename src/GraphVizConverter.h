/*************************************************************************
						   GraphVizConverter
							 -------------------
	début				: 29 nov. 2015
	copyright			: (C) 2015 par ulysse
*************************************************************************/

//----------------------------- Interface de la classe <GraphVizConverter>
//------------------------------------------ (fichier GraphVizConverter.h)
#ifndef GRAPHVIZCONVERTER_H
#define GRAPHVIZCONVERTER_H

//--------------------------------------------------- Interfaces utilisées
#include <list>


//------------------------------------------------------------- Constantes
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <GraphVizConverter>
//
//
//------------------------------------------------------------------------

class GraphVizConverter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

	void convert (list<string[3]> & graph,
				  const string & nameBase = "graph",
				  const string & path     = "");
    // Mode d'emploi :
    // lancer la conversion d’un graph après avoir vérifié les parametres
    // de conversion
    // Contrat :
    //

//------------------------------------------------- Surcharge d'op�rateurs
	GraphVizConverter & operator =
		( const GraphVizConverter & unGraphVizConverter );
	// Contrat :
	// utilise les constructeurs de copie de chaque attribut un à un.


//-------------------------------------------- Constructeurs - destructeur
	GraphVizConverter ( const GraphVizConverter & unGraphVizConverter );
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	GraphVizConverter ( bool  aPrintPNG	           = true,
						const string & aTitle      = "",
						const string & aShapeArrow = "normal",
						const string & aColorLink  = "lightblue",
						const string & aColorNode  = "lightblue",
						const string & aShapeNode  = "note",
						const string & aShapeTail  = ""
						);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~GraphVizConverter ( );
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
	string colorNode, colorLink;
	string shapeNode, shapeArrow, shapeTail;
	string title;
	bool printPNG;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};






#endif // GRAPHVIZCONVERTER_H
