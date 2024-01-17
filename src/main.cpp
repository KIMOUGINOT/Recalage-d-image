#include "MyApp.h"

int main(){

    string refImage = "reference.pgm"; //Put your image name here
    string Image = "floating.pgm"; //Put your image name here
    Interpolation* interpo = new InterpolationBilineaire(); //Choice of the interpolation method between Bilineaire and Plus Proche Voisin (PPV)
    Transformation* transfo;
    Similarite* simi = new SimilariteQuadratique(); 
    VecDoub parameter; 

    MyApp recalageImage(refImage, Image, interpo, transfo, simi);
    parameter = recalageImage.process();

    cout << "-- Tx = " << parameter[0] << " -- "  ; //image x translation
    cout << "Ty = " << parameter[1] << " -- " ; //image y translation
    cout << "theta = " << parameter[2] << " ° --" << endl ; //image rotation

    return 0;
}