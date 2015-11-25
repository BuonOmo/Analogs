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



int main(int argc, char* argv[])
{

	// ---------------------------------------------------test des argc/argv
	cout << "argc : "<< argc << endl;
	for (int i(0) ; i < argc ; i++)
	{
		cout << "argv[" << i << "] : "<< argv[i] << endl;
	}

	return 0;
	/*
	new gestionArgs(arguments)
	new data(gestionArgs.nameFic)
	new analyse(gestionArgs, data)
	affiche analyse
	 */
}
