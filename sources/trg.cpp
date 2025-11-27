//trigonometry - P. Ahrenkiel

#include <cstdlib>
#include <iostream>
#include <math.h>

#include "mth.hpp"
#include "trg.hpp"

namespace trg {

const double Pi(4.*atan(1.));
const double degtorad(180./Pi);

//trg
double asincos(double s, double c){return atan2(s,c);}
double acossin(double c, double s){return atan2(s,c);}
double asn(const double s){return (fabs(s)<1.)?asin(s):((s>0.)?Pi/2.:-Pi/2.);}
double acs(const double c){return (fabs(c)<1.)?acos(c):((c>0.)?0.:Pi);}

//special function(s)
double sinc(double x){
	constexpr double tol = 1.e-18;
	if (fabs(x)<tol) return 1.;
	return sin(x)/x;
}

}
