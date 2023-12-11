#include "MyApp.h"

MyApp::MyApp(const string& imageRef_file, const string& image_file, Interpolation* interpo, Transformation* transfo, Similarite* sim){
    cout << "-- Initialisation de l'application --" << endl ;
    imageRef = "../image/" + imageRef_file;
    cout << "-- Image de reference chargee --" << endl ;
    image = "../image/" + image_file;
    cout << "-- Image chargee --" << endl ;
    this->interpo = interpo ;
    this->transfo = transfo;
    simi = sim;
}

bool MyApp::refToMatrix(){
    ifstream file(imageRef);
    if (!file.is_open()) {
        cerr << "Could not open file: " << imageRef << endl;
        return false;
    }

    string magic;
    int m, n, maxGrayValue;

    file >> magic >> m >> n >> maxGrayValue; //premiere ligne contenant les valeurs importantes dont la taille de la matrice

    NRmatrix<double> image(m,n) ; //créer une matrice de 0 de taille m x n

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int pixelValue;
            file >> pixelValue;
            image[i][j] = pixelValue;
        }
    }
    ImRef = image;

    return true;
}

bool MyApp::toMatrix(){
    ifstream file(image);
    if (!file.is_open()) {
        cerr << "Could not open file: " << image << endl;
        return false;
    }

    string magic;
    int m, n, maxGrayValue;

    file >> magic >> m >> n >> maxGrayValue; //premiere ligne contenant les valeurs importantes dont la taille de la matrice

    NRmatrix<double> image(m, n); //créer une matrice de 0 de taille m x n

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int pixelValue;
            file >> pixelValue;
            image[i][j] = pixelValue;
        }
    }
    Im = image;

    return true;
}

void MyApp::toPGM(const NRmatrix<double>& image, string filename){
    ofstream file("../image/"+ filename);

    if (file.is_open()) {
        file << "P2 "; // En-tête PGM pour une image en niveaux de gris ASCII
        file << image.ncols() << " " << image.nrows() << " 255\n"; // Largeur et hauteur de l'image avec val max des pixels

        // Écriture des valeurs de pixels
        for (int i = 0; i < image.nrows(); ++i) {
            for (int j = 0; j < image.ncols(); ++j) {
                if (image[i][j] > 255) {file << 255 << " ";}
                else if (image[i][j] < 0) {file << 0 << " ";}
                else {file << static_cast<int>(image[i][j]) << " ";}
            }
            file << "\n";
        }

        file.close();
        std::cout << "-- Fichier " << filename << " créé avec succès. --\n";
    } else {
        std::cerr << "| Impossible d'ouvrir le fichier. |\n";
    }
}

VecDoub MyApp::process(){
    this->toMatrix();
    this->refToMatrix();

    VecDoub ystart(3);
    Deformation* deform = new Deformation(transfo, interpo);
    Cout C(simi, deform, ImRef, Im);
    Amoeba opt(0.01);
    ystart[0]=0;
    ystart[1]=0;
    ystart[2]=0;
    VecDoub yfinal(3);
    yfinal = opt.minimize(ystart,20.,C);

    this-> display(yfinal);

    return yfinal;
}

void MyApp::display(VecDoub parameter){
    Deformation defo(transfo, interpo) ;
    NRmatrix<double> Imdef(Im.nrows(),Im.ncols());
    NRmatrix<double> defMask(Im.nrows(),Im.ncols());
    defo.deformImage(Im, Imdef,defMask, parameter);
    this->toPGM(Imdef, "image_deforme.pgm");
}