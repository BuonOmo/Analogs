/*************************************************************************
                           GraphVizConverter
                             -------------------
    début                : 29 nov. 2015
    copyright            : (C) 2015 par ulysse
*************************************************************************/

//---------- Interface de la classe <GraphVizConverter> (fichier GraphVizConverter.h) ------
#ifndef GRAPHVIZCONVERTER_H
#define GRAPHVIZCONVERTER_H

//--------------------------------------------------- Interfaces utilisées



//------------------------------------------------------------- Constantes
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <GraphVizConverter>
//
//
//------------------------------------------------------------------------
void graphVizConvert(int * list [3], int length, string shape = "note", string style = "\"\"", string color = "lightblue");


#endif // GRAPHVIZCONVERTER_H