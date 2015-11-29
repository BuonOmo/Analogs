/*************************************************************************
                           GraphVizConverter  -  description
                             -------------------
    début                : 29 nov. 2015
    copyright            : (C) 2015 par ulysse
*************************************************************************/

///---------- Réalisation de la classe <GraphVizConverter> (fichier GraphVizConverter.cpp) --

///---------------------------------------------------------------- INCLUDE

///-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

///------------------------------------------------------ Include personnel
#include "GraphVizConverter.h"

///------------------------------------------------------------- Constantes

///---------------------------------------------------- Variables de classe

///----------------------------------------------------------- Types privés


///----------------------------------------------------------------- PUBLIC
///-------------------------------------------------------- Fonctions amies

///----------------------------------------------------- Méthodes publiques
// type GraphVizConverter::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


///------------------------------------------------- Surcharge d'opérateurs
GraphVizConverter & GraphVizConverter::operator = ( const GraphVizConverter & unGraphVizConverter )
// Algorithme :
//
{
} //----- Fin de operator =


///-------------------------------------------- Constructeurs - destructeur
GraphVizConverter::GraphVizConverter ( const GraphVizConverter & unGraphVizConverter )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GraphVizConverter>" << endl;
#endif
} //----- Fin de GraphVizConverter (constructeur de copie)


GraphVizConverter::GraphVizConverter ( )
// Algorithme :
//
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

///----------------------------------------------------- Méthodes protégées

///------------------------------------------------------- Méthodes privées
