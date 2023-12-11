#ifndef _DEFORMATION_H_
#define _DEFORMATION_H_

#include "nr3.h"
#include "Interpolation.h"
#include "Transformation.h"

class Deformation
{
    private : 
        Transformation* transf;
        Interpolation* interp;
    public:
        Deformation(Transformation* transf, Interpolation* interp);      
        void deformImage(NRmatrix<double>& im, 
                        NRmatrix<double>& IDeforme, 
                        NRmatrix<double>& resMask,  
                        const VecDoub& param);
};

#endif
