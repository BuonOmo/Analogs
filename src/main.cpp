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


///------------------------------------------------------------- Constantes

///---------------------------------------------------- Variables de classe

///----------------------------------------------------------- Types privés

///----------------------------------------------------------------- PUBLIC
///-------------------------------------------------------- Fonctions amies

///----------------------------------------------------- Méthodes publiques
// type main::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

///------------------------------------------------- Surcharge d'opérateurs
main &
main::operator = (const main & unmain)
// Algorithme :
//
{
} //----- Fin de operator =

///-------------------------------------------- Constructeurs - destructeur
main::main (const main & unmain)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <main>" << endl;
#endif
} //----- Fin de main (constructeur de copie)

main::main ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <main>" << endl;
#endif

} //----- Fin de main

main::~main ()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <main>" << endl;
#endif
} //----- Fin de ~main

///------------------------------------------------------------------ PRIVE

///----------------------------------------------------- Méthodes protégées

///------------------------------------------------------- Méthodes privées
