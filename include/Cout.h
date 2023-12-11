#ifndef COUT_H
#define COUT_H

#include "Similarite.h"
#include "Deformation.h"

class Cout{

	private:
		Similarite* sim;
		Deformation* deform;
		NRmatrix<double> Iref;
		NRmatrix<double> I;
		mutable NRmatrix<double> refMask;
		mutable NRmatrix<double> Idef;
		mutable NRmatrix<double> defMask;

	public:
		Cout(Similarite*, Deformation*, NRmatrix<double>&, NRmatrix<double>&);
		double operator()(const VecDoub&) ;
};

#endif
