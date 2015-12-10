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
// GraphVizConverter permet de parametrer et utiliser un outil capable de
// convertir un graphe au format %.dot et d’afficher son rendu.
// On peut ainsi avec un convertisseur travailler sur plusieurs graphes à
// la suite en conservant nos parametres.
// Les graphes sont envoyés sous forme de tableaux de type
// {Nœud racine, Nœud cible, Pondération}.
//------------------------------------------------------------------------

class GraphVizConverter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void showParameters () const;
    // Contrat :
    // Voir operator <<

    void modifyParameter ( int param, const string & value );
    // Mode d’Emploi :
    // Modifie un paramètre de la manière suivante :
    //      valeur de param :
    //      0 -> modification de printPNG (value = "true" | "false" )
    //      1 -> modification de title (*)
    //      2 -> modification de shapeArrow (*)
    //      3 -> modification de colorLink (*)
    //      4 -> modification de colorNode (*)
    //      5 -> modification de shapeNode (*)
    //      6 -> modification de shapeTail (*)
    // *La valeure du parametre en question devient value
    //
    // Contrat :
    // Les cohérances avec le langage graphViz sont à verifier par
    // l’utilisateur.

	void convert (list<string[3]> & graph,
				  const string & nameBase = "graph",
				  const string & path     = "") const;
    // Mode d'emploi :
    // Lance la conversion d’un graph après avoir vérifié les parametres
    // de conversion.
    //
    // Contrat :
    // Récupère un graph au format (racine, cible, label)

//------------------------------------------------- Surcharge d'opérateurs
	GraphVizConverter & operator =
		( const GraphVizConverter & aGraphVizConverter );
	// Contrat :
	// Utilise les constructeurs de copie de chaque attribut un à un.

    friend ostream & operator <<
        ( ostream & os, const GraphVizConverter & aGraphVizConverter );
    // Contrat :
    // Affiche les parametres du convertisseur. Attention, l’affichage
    // prend beaucoup de place (plusieurs lignes).

//-------------------------------------------- Constructeurs - destructeur
	GraphVizConverter ( const GraphVizConverter & aGraphVizConverter );
	// Contrat :
	// Voir operator =.

	GraphVizConverter ( bool  aPrintPNG	           = true,
						const string & aTitle      = "",
						const string & aShapeArrow = "normal",
						const string & aColorLink  = "lightblue",
						const string & aColorNode  = "lightblue",
						const string & aShapeNode  = "note",
						const string & aShapeTail  = ""
						);
	// Mode d'emploi :
    // Entrer les parametres souhaités.
    //
	// Contrat :
	// Les parametres de forme et de couleur doivent exister dans le
	// langage GraphViz.
	// Forme :
	//  - fleches : http://www.graphviz.org/doc/info/arrows.html
	//  - nœuds : http://www.graphviz.org/doc/info/shapes.html
	// Couleurs : http://www.graphviz.org/doc/info/colors.html

	virtual ~GraphVizConverter ( );
	// Contrat :
	// Rien à detruire.

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
	string colorNode;
    string colorLink;
	string shapeNode;
    string shapeArrow;
    string shapeTail;
	string title;
	bool printPNG;
};

#endif // GRAPHVIZCONVERTER_H
