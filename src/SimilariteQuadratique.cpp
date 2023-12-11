#include "SimilariteQuadratique.h"

double SimilariteQuadratique::similaire(const NRmatrix<double>& Im1, 
                              const NRmatrix<double>& Mask1, 
                              const NRmatrix<double>& Im2,
                              const NRmatrix<double>& Mask2){
	double result;
	int count=0;

	for(int i=0; i<Mask2.nrows();i++){
		for(int j=0; j<Mask2.ncols();j++){

			if (Mask1[i][j]==Mask2[i][j]){
				count+=1;
				result+=(Im1[i][j]-Im2[i][j])*(Im1[i][j]-Im2[i][j]);
				}
			}
		}

	return result/count;
}
