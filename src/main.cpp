#include "MyApp.h"

int main(){

    Interpolation* interpo = new InterpolationBilineaire(); //Choix de l'interpolation entre Bilineaire et Plus Proche Voisin (PPV)
    Transformation* transfo;
    Similarite* simi = new SimilariteQuadratique(); //Choix de la similarite : pour l'instant, que Quadratique  
    VecDoub parameter; //tableau qui à terme contiendra [Tx,Ty,theta]

    MyApp recalageImage("reference.pgm", "floating.pgm", interpo, transfo, simi); //Mettre obligatoirement les images dans le dossier image
    parameter = recalageImage.process();

    cout << "-- Tx = " << parameter[0] << " -- "  ;
    cout << "Ty = " << parameter[1] << " -- " ;
    cout << "theta = " << parameter[2] << " ° --" << endl ;

    return 0;
}