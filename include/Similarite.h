#ifndef SIMILARITE_H
#define SIMILARITE_H

#include "nr3.h"

class Similarite{ //classe abstraite
      public:
            virtual double similaire(const NRmatrix<double>& Im1, 
                              const NRmatrix<double>& Mask1, 
                              const NRmatrix<double>& Im2,
                              const NRmatrix<double>& Mask2)=0;
};

#endif
