#ifndef INTERPOLATION2_H
#define INTERPOLATION2_H

#include"Interpolation.h"

class InterpolationPPVoisin:public Interpolation{ //Interpolation au plus proche voisin

public:
	double interpol(const NRmatrix<double>& Image, double x, double y, int& OK)const;

};

#endif
