#include "Cout.h"

Cout::Cout(Similarite* sim, Deformation* deform, NRmatrix<double>& Iref, NRmatrix<double>& I)
    : sim(sim), deform(deform), Iref(Iref), I(I), Idef(Iref.ncols(), Iref.nrows()), defMask(Iref.ncols(), Iref.nrows()), refMask(Iref.ncols(), Iref.nrows(), 1) {	
}

double Cout::operator()(const VecDoub& u) {

	deform->deformImage(I,Idef,defMask,u);
	double result = sim->similaire(Idef,defMask,Iref,refMask);
	
	return result;
}
