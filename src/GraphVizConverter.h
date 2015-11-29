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

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GraphVizConverter>
//
//
//------------------------------------------------------------------------

class GraphVizConverte
{
//--r--------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    GraphVizConverter & operator = ( const GraphVizConverter & unGraphVizConverter );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    GraphVizConverter ( const GraphVizConverter & unGraphVizConverter );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GraphVizConverter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GraphVizConverter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <GraphVizConverter>

#endif // GRAPHVIZCONVERTER_H
