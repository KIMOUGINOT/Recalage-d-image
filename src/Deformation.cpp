#include "Deformation.h"

Deformation::Deformation(Transformation* transf, Interpolation* interp){
	this->transf=transf;
	this->interp=interp;
}

void Deformation::deformImage(NRmatrix<double>& im, 
								NRmatrix<double>& IDeforme, 
								NRmatrix<double>& resMask,  
								const VecDoub& param){
	
	double xres,yres;
	int OK;

	for(int i=0; i<im.nrows();i++){
		for(int j=0; j<im.ncols();j++){ 

			VecDoub s(2);
			s[0] = i;
			s[1] = j;
			transf->transfo(param, s[0], s[1], xres, yres);
			double res = interp->interpol(im,xres,yres,OK);
			IDeforme[i][j]=res;
			if (OK == 1) {resMask[i][j]=1;}
			else {resMask[i][j]=0;}
			}
		}
}
                    
