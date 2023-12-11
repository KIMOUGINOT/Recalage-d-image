#ifndef SIMILARITE1_H
#define SIMILARITE1_H
#include "Similarite.h"

class SimilariteQuadratique:public Similarite{
      public:
            double similaire(const NRmatrix<double>& Im1, 
                              const NRmatrix<double>& Mask1, 
                              const NRmatrix<double>& Im2,
                              const NRmatrix<double>& Mask2) ;
                              // constructeur du critere de similarité 1
};

#endif
