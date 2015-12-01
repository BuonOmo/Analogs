/*************************************************************************
                           GraphVizConverter  -  description
                             -------------------
    début                : 29 nov. 2015
    copyright            : (C) 2015 par ulysse
*************************************************************************/

///---------- Réalisation de la classe <GraphVizConverter> (fichier GraphVizConverter.cpp) --

///---------------------------------------------------------------- INCLUDE

///-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

///------------------------------------------------------ Include personnel
#include "GraphVizConverter.h"

///---------------------------------------------------- Variables de classe
using namespace std;


///----------------------------------------------------------------- PUBLIC

///----------------------------------------------------- Méthodes publiques


void graphVizConvert(int * list [3],
					 int length,
					 string shape,
					 string style,
					 string color)
{
	// création ou écrasement du fichier dot
	ofstream file ("results/graph.dot", ios::out | ios::trunc);
	
	if(file){

		file << "digraph AnalysisResult {" << endl;
		file << "node [color="<<color;
		file << ",style=" << style;
		file << ", shape=" << shape;
		file << "];" << endl;

		for (int i(0) ; i < length ; i++)
		{
			file << '"' <<(char)list[i][0] << '"';
			file<< " -> ";
			file << '"' << (char)list[i][1]<< '"';
			file << " [label="<<list[i][2]<<", color="<<color<<"];";
			file << endl;
		}
		file << "}" << endl;
		file.close();
	}
	else
	{
		cerr << "Impossible de creer le fichier !" << endl;
	}
	system("dot -Tpng -o results/graph.png results/graph.dot");
	system("eog results/graph.png");
}