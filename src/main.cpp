#include "MyApp.h"

int main(){

    string imageRef = "reference.pgm"; //Put your image name here
    string image = "floating.pgm"; //Put your image name here
    Interpolation* interpo = new InterpolationBilineaire(); //Choice of the interpolation method between Bilineaire and Plus Proche Voisin (PPV)
    Transformation* transfo;
    Similarite* simi = new SimilariteQuadratique(); 
    VecDoub parameter; 

    MyApp recalageImage(imageRef, image, interpo, transfo, simi);
    parameter = recalageImage.process();

    cout << "-- Tx = " << parameter[0] << " -- "  ; //image x translation
    cout << "Ty = " << parameter[1] << " -- " ; //image y translation
    cout << "theta = " << parameter[2] << " ° --" << endl ; //image rotation

    return 0;
}