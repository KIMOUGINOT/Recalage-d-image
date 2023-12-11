#include "InterpolationPPVoisin.h"
#include <cmath>

double InterpolationPPVoisin::interpol(const NRmatrix<double>& I, double x, double y, int& OK)const {
    int i, j, res ;
    int H = I.nrows();
    int L = I.ncols();
    
    if( (x<0 || (x>H-1||(y<0)||(y>L-1)))){
            OK=0;
    }

    else
    {
        OK=1;
        i=static_cast<int>(round(x));
        j=static_cast<int>(round(y));
        res = I[i][j];
        return res;
    }
    return -1.0 ; //Indique que l'indice est hors champs
};
