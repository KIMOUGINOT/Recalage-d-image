#ifndef _MYAPP_H_
#define _MYAPP_H_
#include "nr3.h"
#include "amoeba.h"
#include "SimilariteQuadratique.h"
#include "InterpolationBilineaire.h"
#include "InterpolationPPVoisin.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class MyApp
{
    private:
        string imageRef; //chemin de l'image de reference
        string image; //chemin de l'image de reference
        NRmatrix<double> ImRef ;
        NRmatrix<double> Im ;
        Interpolation* interpo;
        Transformation* transfo;
        Similarite* simi;

    public:
        MyApp(const string&, const string&, Interpolation*, Transformation*, Similarite*); // constructeur
        bool refToMatrix();  // transforme le fichiers ref .pgm en matrice 
        bool toMatrix() ;  // transforme le fichiers a recaler .pgm en matrice
        VecDoub process() ; // renvoie les paramètres tx, ty et theta en utilisant tout le processus d'optimisation
        void toPGM(const NRmatrix<double>&, string); // fonction qui créer une image .pgm à partir d'une matrice
        void display(VecDoub); // affiche l'image deformee
};

#endif
