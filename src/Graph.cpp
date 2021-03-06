/*************************************************************************
						Graph  -  gestion de graphs
                             -------------------
    début                : 1 dec. 2015
    copyright            : (C) 2015 par Ulysse et Adrien
*************************************************************************/

//----------- Réalisation de la classe <Graph> (fichier Graph.cpp) --

//----------------------------------------------------------------- INCLUDE

//--------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include "Graph.h"
#include <sstream>


//------------------------------------------------------- Include personnel


//-------------------------------------------------------------- Constantes

//----------------------------------------------------- Variables de classe

//------------------------------------------------------------ Types privés
typedef map<string, int> shortGraph;
typedef map<string,shortGraph*> fullGraph;
//------------------------------------------------------------------ PUBLIC
//--------------------------------------------------------- Fonctions amies

//------------------------------------------------------ Méthodes publiques

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
		return ;
	}

	graph.erase( graph.begin(),graph.end());
	while (data->hasNextLog ( ))
	{
		Log toInsert (data->readNextLog ( ));
		string root = toInsert.getRoot();
		string target = toInsert.getTarget();
		Date date = toInsert.getDate();
		bool isAWebPage = true;
		if (root.size() >= 4)
		{
    			string extantion = root.substr (root.size()-4,4);
    			string petitExtantion =root.substr (root.size()-3,3);
    			isAWebPage = (extantion.compare(".css")!=0 && extantion.compare(".png")!=0 && petitExtantion.compare(".js")!=0);
		}
		if (!optVisual)
		{
			root = "all"; // ------pour les option t et e il n'est pas néésaire de
					//-----connaitre la rassine du hit;
		}
		bool tagetExist = !target.compare("")==0;
		bool isOptionMatch = (!optHour || date.getHour() == hourInOpt) // option heur -> heur conincide avec l'heur mise en option.
				&&
				(!optExclude || isAWebPage ); // --------------TODO verifi


		if (isOptionMatch && tagetExist)//--------------------TODO fonctione des options
		{


			fullGraph::iterator it = graph.find(target);
			if (it == graph.end())
			{
				shortGraph *pGraphRootPart = new shortGraph;
				(*pGraphRootPart) [root]=1;
				graph[target]=pGraphRootPart;
				//cout<<"Graph :: insrte Data création d'une target et d'une root"<< endl;
			}
			else
			{
				shortGraph *pGraphRootPart;
				pGraphRootPart = it->second ;
				shortGraph::iterator sMIt = pGraphRootPart->find(root);
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
	}//fin du while
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

list<string> Graph::allLinks()
{
#ifdef MAP
    cout << "Appel a la mehtode Graph::allLinks()" << endl;
#endif
    list<string > allLink;
    for (fullGraph::iterator itGraphe = graph.begin(); itGraphe !=graph.end(); itGraphe++)
    {
    	for (shortGraph::iterator itLinkGraphe = itGraphe->second->begin(); itLinkGraphe != itGraphe->second->end(); itLinkGraphe ++)
    	{
    		string root(itLinkGraphe->first);
    		string target( itGraphe->first);

    		int a = (itLinkGraphe->second);
    		stringstream ss;
    		ss << a;
    		string ponderation = ss.str();

    		allLink.push_back(root);
    		allLink.push_back(target);
    		allLink.push_back(ponderation);
    	}
    }
    return allLink;
}
void Graph::print(ostream &flux) const
{
	string toAffiche[10];
	for (int i(0); i < 10 ;i++)
	{
		int max =0;
		string targetMax;
		for (fullGraph::const_iterator itGraphe = graph.begin(); itGraphe !=graph.end(); itGraphe++)
		{
			int curNbHit =itGraphe->second->find ("all")->second;
			if (max < curNbHit)
			{
				bool strIsIn= false;
				for (int j(0); j<i ; j++)
				{
					strIsIn = (strIsIn || toAffiche[j].compare(itGraphe->first)==0);
				}
				if (!strIsIn)
				{
					max =curNbHit;
					targetMax =itGraphe->first;
					toAffiche[i]=targetMax;
				}
			}

		}
		if (max >0)
		{
			flux << targetMax << " (" << max << " hits)" <<endl ;
		}
	}
//insertData;
}



//-------------------------------------------------- Surcharge d'opérateurs
ostream& operator <<( ostream &flux, const Graph & aGraph)
{
    aGraph.print(flux);
    return flux;
}

Graph & Graph::operator = (  Graph & aGraph )
{
#ifdef MAP
    cout << "Appel a la surcharge de = de <Graph>" << endl;
#endif
	dataFile = aGraph.dataFile;
	optVisual = aGraph.optVisual;
	optExclude = aGraph.optExclude;
	optHour = aGraph.optHour;
	hourInOpt = aGraph.hourInOpt;

	// ------------------- supertion du graphe existant
    for (fullGraph::iterator itGraphe = graph.begin(); itGraphe !=graph.end(); itGraphe++)
    {
    	delete itGraphe->second;// -----------------TODO verifier si ok
    }

	graph.erase(graph.begin(),graph.end());


    for ( fullGraph::iterator itGraphe = aGraph.graph.begin(); itGraphe !=aGraph.graph.end(); itGraphe++)
    {
    	graph[itGraphe->first] = new shortGraph(  * itGraphe->second );
    }
    return * this ;

} //----- Fin de operator =


//--------------------------------------------- Constructeurs - destructeur
Graph::Graph (const string & aDataFile, bool aOptVisual,  bool aOptExclude,  bool aOptHour, int aHourInOpt):
		dataFile(aDataFile),optVisual(aOptVisual),optExclude(aOptExclude),optHour(aOptHour),hourInOpt(aHourInOpt)
{
#ifdef MAP
    cout << "Appel au constructeur de <Graph>" << endl;
#endif
	insertData();
} //----- Fin de Graph

Graph::Graph (const Graph & aGraph)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graph>" << endl;
#endif
	dataFile = aGraph.dataFile;
	optVisual = aGraph.optVisual;
	optExclude = aGraph.optExclude;
	optHour = aGraph.optHour;
	hourInOpt = aGraph.hourInOpt;
    for ( fullGraph::const_iterator itGraphe = aGraph.graph.begin(); itGraphe !=aGraph.graph.end(); itGraphe++)
    {
    	graph[itGraphe->first] = new shortGraph(  * itGraphe->second );
    }
} //----- Fin de Graph (constructeur de copie)


Graph::Graph():
		dataFile(""), optVisual (false), optExclude(false), hourInOpt(0)
{
#ifdef MAP
    cout << "Appel au constructeur par défeau de <Graph>" << endl;
#endif
} //----- Fin de Graph


Graph::~Graph ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Graph>" << endl;
#endif
    for (fullGraph::iterator itGraphe = graph.begin(); itGraphe !=graph.end(); itGraphe++)
    {
    	delete itGraphe->second;
    }
} //----- Fin de ~Graph
