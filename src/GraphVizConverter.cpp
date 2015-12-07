/*************************************************************************
                           GraphVizConverter  -  description
                             -------------------
    début                : 29 nov. 2015
    copyright            : (C) 2015 par ulysse
*************************************************************************/

//--------------------------- Réalisation de la classe <GraphVizConverter>
//---------------------------------------- (fichier GraphVizConverter.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GraphVizConverter.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void GraphVizConverter::showParameters () const
{
	cout << *this << endl;
} //----- Fin de showParameters

void GraphVizConverter::modifyParameters
	( int param, const string & value )
{
	switch (param) {
		case 0 : printPNG = (value == "true") ? true : false;
			break;
		case 1 : title      = value;
			break;
		case 2 : shapeArrow = value;
			break;
		case 3 : colorLink  = value;
			break;
		case 4 : colorNode  = value;
			break;
		case 5 : shapeNode  = value;
			break;
		case 6 : shapeTail  = value;
			break;
	}
} //----- Fin de modifyParameters

void GraphVizConverter::convert (list<string[3]> & graph,
								 const string & nameBase,
								 const string & path) const
{
	// création ou écrasement du fichier dot
	string toOpen = path + nameBase;
	ofstream file (toOpen.c_str(), ios::out | ios::trunc);

	if(file){

		file << "digraph AnalysisResult {" << endl;
		// Ajout du titre
		file << "label = \"" << title;
		file << "\";"        << endl;
		// Format des nœuds
		file << "node [color=" << colorNode;
		file << ", style="     << "";
		file << ", shape="     << shapeNode;
		file << "];"           << endl;
		// Format des liasions
		file << "edge [color=" << colorLink;
		file << ", arrowhead=" << shapeArrow;
		file << ", arrowtail=" << shapeTail;
		file << "];"           << endl;
		// Création des liens
		for (list<string[3]>::const_iterator it = graph.begin(); it != graph.end(); ++it)
		{
			file << '"' << (*it)[0] << '"';
			file << " -> ";
			file << '"' << (*it)[1] << '"';
			file << " [label=" << '"';
			file << (*it)[2] << "\"];";
			file << endl;
		}
		file << "}" << endl;
		file.close();
		if (printPNG)
		{
			system("dot -Tpng -o results/graph.png results/graph.dot");
			system("eog results/graph.png");
		}
	}
	else
	{
		cerr << "Impossible de creer le fichier,";
		cerr << " verifiez l’existance du chemin" << endl;
	}
} //----- Fin de convert

///------------------------------------------------- Surcharge d'op�rateurs
GraphVizConverter & GraphVizConverter::operator =
	( const GraphVizConverter & aGraphVizConverter )
{
	printPNG   = aGraphVizConverter.printPNG;
	title      = aGraphVizConverter.title;
	shapeArrow = aGraphVizConverter.shapeArrow;
	colorLink  = aGraphVizConverter.colorLink;
	colorNode  = aGraphVizConverter.colorNode;
	shapeNode  = aGraphVizConverter.shapeNode;
	shapeTail  = aGraphVizConverter.shapeTail;
	return *this;
} //----- Fin de operator =

ostream & operator <<
	( ostream & os, const GraphVizConverter & aGVC )
{
	os << "Creation et affichage de l’image : ";
	os << aGVC.printPNG ? "oui" : "non" << endl;
	os << "Titre : "                      << aGVC.title      << endl;
	os << "Forme des fins de fleches : "  << aGVC.shapeArrow << endl;
	os << "Forme des bases de fleches : " << aGVC.shapeTail  << endl;
	os << "Forme des boites : "           << aGVC.shapeNode  << endl;
	os << "Couleur des liens : "          << aGVC.colorLink  << endl;
	os << "Couleur des boites : "         << aGVC.colorNode;


} //----- Fin de operator <<

///-------------------------------------------- Constructeurs - destructeur
GraphVizConverter::GraphVizConverter
	( const GraphVizConverter & aGraphVizConverter )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GraphVizConverter>" << endl;
#endif
	if (this != &aGraphVizConverter)
	{
		*this = aGraphVizConverter;
	}
} //----- Fin de GraphVizConverter (constructeur de copie)


GraphVizConverter::GraphVizConverter ( bool           aPrintPNG,
									   const string & aTitle,
									   const string & aShapeArrow,
									   const string & aColorLink,
									   const string & aColorNode,
									   const string & aShapeNode,
									   const string & aShapeTail) :
									   printPNG (aPrintPNG),
									   title (aTitle),
									   shapeArrow (aShapeArrow),
									   colorLink (aColorLink),
									   colorNode (aColorNode),
									   shapeNode (aShapeNode),
									   shapeTail (aShapeTail)
{
#ifdef MAP
    cout << "Appel au constructeur de <GraphVizConverter>" << endl;
#endif
} //----- Fin de GraphVizConverter


GraphVizConverter::~GraphVizConverter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GraphVizConverter>" << endl;
#endif
} //----- Fin de ~GraphVizConverter


///------------------------------------------------------------------ PRIVE

///----------------------------------------------------- M�thodes prot�g�es

///------------------------------------------------------- M�thodes priv�es
