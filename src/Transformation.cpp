#include "nr3.h"
#include <cmath>
#include <iostream>
#include "Transformation.h"

using namespace std; 

void Transformation::transfo(const VecDoub& param, //param = tx, ty, teta//
                  double x     ,
                  double y     , 
                  double &xres , 
                  double &yres) {
 
 	xres = x*cos(param[2]*M_PI/180) - y*sin(param[2]*M_PI/180) + param[0] ;
 	yres = x*sin(param[2]*M_PI/180) + y*cos(param[2]*M_PI/180) + param[1] ;
 	
	               
}
