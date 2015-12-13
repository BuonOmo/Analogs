/*************************************************************************
						Graph  -  gestion de graphs
                             -------------------
    début                : 1 dec. 2015
    copyright            : (C) 2015 par Ulysse et Adrien
*************************************************************************/

///---------- Réalisation de la classe <Graph> (fichier Graph.cpp) --

///---------------------------------------------------------------- INCLUDE

///-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//#include <fstream>
#include "Graph.h"

///------------------------------------------------------ Include personnel


///------------------------------------------------------------- Constantes

///---------------------------------------------------- Variables de classe

///----------------------------------------------------------- Types privés


///----------------------------------------------------------------- PUBLIC
///-------------------------------------------------------- Fonctions amies

///----------------------------------------------------- Méthodes publiques

void Graph::insertData()
// Algorithme :
{
#ifdef MAP
    cout << "Appel a la mehtode Graph::insertData()" << endl;
#endif
	Read* data = new Read(dataFile);
	if (data == NULL)
	{
		//cerr<< "No data sources"<< endl;
	}
	else
	{
		graph.erase( graph.begin(),graph.end());
		while (data->hasNextLog ( ))
		{
			Log toInsert (data->readNextLog ( ));
			string root = toInsert.getRoot();
			string target = toInsert.getTarget();
			Date date = toInsert.getDate();
			string extantion = root.substr (root.size()-4,4);

			bool isAWebPage = (extantion.compare(".css")!=0 && extantion.compare(".png")!=0);
			
			if (!optVisual)
			{
				root = "all"; // ------pour les option t et e il n'est pas néésaire de 
						//-----connaitre la rassine du hit;
			}
			bool isOptionMatch = (!optHour || date.getHour() == hourInOpt) // option heur -> heur conincide avec l'heur mise en option.
					&&
					(!optExclude || isAWebPage ); // --------------TODO verifi


			if (isOptionMatch)//--------------------TODO fonctione des options
			{


				map<string, map<string,int>* >::iterator it = graph.find(target);
				if (it == graph.end())
				{
					map<string,int> *pGraphRootPart = new map<string, int>;
					(*pGraphRootPart) [root]=1;
					graph[target]=pGraphRootPart;
					//cout<<"Graph :: insrte Data création d'une target et d'une root"<< endl;
				}
				else
				{
					map<string,int> *pGraphRootPart;
					pGraphRootPart = it->second ;
					map<string,int >::iterator sMIt = pGraphRootPart->find(root);
					if (sMIt == pGraphRootPart->end())
					{
						(*pGraphRootPart)[root]=1;
						//cout << "Graph :: insrte Data  création  d'une root" << endl;
					}
					else
					{
						sMIt->second++;
						//cout << "Graph :: insrte Data  root et taget existe : incrémentation"<< endl;
					}
				}
			}
		}
	}
	delete data;
}

void Graph::insertOption(bool aOptVisual,  bool aOptExclude,  bool aOptHour, int aHourInOpt)
{
	optVisual = aOptVisual;
	optExclude = aOptExclude;
	optHour = aOptHour;
	hourInOpt = aHourInOpt;
}
void Graph::insertDataSources(const string & aDataFile)
{
	dataFile = aDataFile;
}

list<string *> Graph::allLinks()
{
	list<string*> allLink;
    for (map<string,map<string,int>*>::iterator itGraphe = graph.begin(); itGraphe !=graph.end(); itGraphe++)
    	for (map<string,int>::iterator itLinkGraphe = itGraphe->second->begin(); itLinkGraphe != itGraphe->second->end(); itLinkGraphe ++)
    	{
    		string* aLink = new string[3];
    		aLink[2] = itLinkGraphe->second;
    		aLink[0] = itLinkGraphe->first;
    		aLink[1] = itGraphe->first;
    		allLink.push_back(aLink);
    	}
    return allLink;
}

void Graph::print(ostream &flux)
{
	for (int i(0); i< 10 ;i++)
	{
		int max =0;
		string targetMax;
		for (map<string,map<string,int>*>::iterator itGraphe = graph.begin(); itGraphe !=graph.end(); itGraphe++)
		{
			int curNbHit =itGraphe->second->find ("all")->second;
			if (max < curNbHit)
			{
				max =curNbHit;
				targetMax =itGraphe->first;
				itGraphe->second->find ("all")->second= 0;
			}

		}
		if (max >0)
		{
			flux << targetMax << " " << max << endl ;
		}
	}
insertData;
}



///------------------------------------------------- Surcharge d'opérateurs
ostream& operator <<( ostream &flux, const Graph & aGrpah)
{
    aGrpah.print(flux);
    return flux;
}

Graph & Graph::operator = (  Graph & unGraph )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a la surcharge de = de <Graph>" << endl;
#endif
	dataFile = unGraph.dataFile;
	optVisual = unGraph.optVisual;
	optExclude = unGraph.optExclude;
	optHour = unGraph.optHour;
	hourInOpt = unGraph.hourInOpt;

	// ------------------- supertion du graphe existant
    for (map<string,map<string,int>*>::iterator itGraphe = graph.begin(); itGraphe !=graph.end(); itGraphe++)
    {
    	delete itGraphe->second;// -----------------TODO verifier si ok
    }

	graph.erase(graph.begin(),graph.end());


    for ( map<string,map<string,int>*>::iterator itGraphe = unGraph.graph.begin(); itGraphe !=unGraph.graph.end(); itGraphe++)
    {
    	graph[itGraphe->first] = new map<string,int>(  * itGraphe->second );
    }
    return * this ;

} //----- Fin de operator =


///-------------------------------------------- Constructeurs - destructeur
Graph::Graph (const string & aDataFile, bool aOptVisual,  bool aOptExclude,  bool aOptHour, int aHourInOpt)
{
#ifdef MAP
    cout << "Appel au constructeur de <Graph>" << endl;
#endif
	dataFile = aDataFile;
	optVisual = aOptVisual;
	optExclude = aOptExclude;
	optHour = aOptHour;
	hourInOpt = aHourInOpt;
	insertData();
}
Graph::Graph ( Graph & unGraph)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graph>" << endl;
#endif
	dataFile = unGraph.dataFile;
	optVisual = unGraph.optVisual;
	optExclude = unGraph.optExclude;
	optHour = unGraph.optHour;
	hourInOpt = unGraph.hourInOpt;
    for ( map<string,map<string,int>*>::iterator itGraphe = unGraph.graph.begin(); itGraphe !=unGraph.graph.end(); itGraphe++)
    {
    	graph[itGraphe->first] = new map<string,int>(  * itGraphe->second );
    }

} //----- Fin de Read (constructeur de copie)


Graph::Graph()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par défeau de <Graph>" << endl;
#endif
	dataFile = "";
	optVisual = false;
	optExclude = false;
	optHour = false;
	hourInOpt = 0 ;

} //----- Fin de Read


Graph::~Graph ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graph>" << endl;
#endif
    for (map<string,map<string,int>*>::iterator itGraphe = graph.begin(); itGraphe !=graph.end(); itGraphe++)
    {
    	delete itGraphe->second;
    }
} //----- Fin de ~Graph


///------------------------------------------------------------------ PRIVE

///----------------------------------------------------- Méthodes protégées

///------------------------------------------------------- Méthodes privées
