/*************************************************************************
 	 	 	 	 	 	 	 main
 -------------------
 début                : 24 nov. 2015
 copyright            : (C) 2015 par ulysse
 *************************************************************************/

///---------- Réalisation de la classe <main> (fichier main.cpp) --
///---------------------------------------------------------------- INCLUDE
///-------------------------------------------------------- Include système

using namespace std;
#include <iostream>
#include <string>
#include <cstdlib>
#include "Graph.h"


bool setOption (int argc, char* argv[],bool& grapOpt,bool& timeOpt,bool& excludOpt, string& grapOptFile,int& timeOptHour, string& logFilAdresse);

int main(int argc, char* argv[])
{

	// ---------------------------------------------------test des argc/argv

	bool grapOpt= false;
	bool timeOpt = false;
	bool excludOpt = false;
	string grapOptFile;
	int timeOptHour;
	string logFilAdresse;
	if ( !setOption (argc, argv, grapOpt,timeOpt, excludOpt, grapOptFile,timeOptHour, logFilAdresse))
	{
	return 0;
	}
	cout << logFilAdresse << endl;
	Graph graph(logFilAdresse, grapOpt, excludOpt, timeOpt, timeOptHour);
	cout << graph << endl;


	return 0;
	/*
	new gestionArgs(arguments)
	new data(gestionArgs.nameFic)
	new analyse(gestionArgs, data)
	affiche analyse
	 */
}
bool setOption (int argc, char*  argv[], bool& grapOpt,bool& timeOpt,bool& excludOpt, string& grapOptFile,int& timeOptHour, string& logFilAdresse)
{
	for (int i(1) ; i < argc-1 ; i++)
	{
		string option(argv[i]);

		if (option.compare("-g")==0)
		{
			if (grapOpt)
			{
				cerr << "double insertion de l'option -g" << endl;
				return false;
			}
			else
			{
				grapOpt = true;
				i++;
				grapOptFile = argv[i];
				if (grapOptFile.compare("-e")==0 
					|| grapOptFile.compare("-h")==0
					|| grapOptFile.find(".log") != string::npos)

					{
						cerr <<"\"" << grapOptFile <<"\""<< 
						" n'est pas une destination"<<endl<<
						" inssérer une destination aprais -g" << endl;
						
					}
			}

		}


		else if(option.compare("-e")==0)
		{
			if (excludOpt)
			{
				cerr << "double insertion de l'option -e" << endl;
				return false;
			}
			else
			{
				excludOpt = true;
			}
		}


		else if(option.compare("-t")==0)
		{
			if (timeOpt)
			{
				cerr << "double insertion de l'option -t" << endl;
				return false;
			}
			else
			{
				timeOpt = true;
				i++;
				timeOptHour = atoi(argv[i]);
				if (timeOptHour==0 & argv[i][0]!=0)
				{
					cerr <<"\""<< argv[i]<<"\""<<" n'est pas un nombre "<<
						endl<<"incerer un nombre aprés l'option -t"<< endl;
					return false;
				}
			}
		}
		else
		{
			cerr <<"\""<< option <<"\""<< " n'est pas une option reconu "<< endl<< 
				"essayer -g,-h,-t"<<endl;
			return false;
		}

	}
	logFilAdresse = argv[argc-1];
	if (logFilAdresse.find(".log")== string::npos)
	{
		cerr <<"\"" << logFilAdresse <<"\""<< 
			" n'est pas un fichier .log"<<endl<<
			" inssérer un fichier .log" << endl;
		return false;
	}
return true;
}
