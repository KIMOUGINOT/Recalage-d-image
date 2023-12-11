#ifndef INTERPOLATION1_H
#define INTERPOLATION1_H

#include "Interpolation.h"

class InterpolationBilineaire:public Interpolation{ //interpolation bilinéaire

public:
	double interpol(NRmatrix<double>& Image, double x, double y, int& OK)const;

};

#endif
