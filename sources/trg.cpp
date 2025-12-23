//trigonometry - P. Ahrenkiel

#include <cstdlib>
#include <iostream>
#include <math.h>

#include "mth.hpp"
#include "trg.hpp"

namespace trg {

const double pi(4.*atan(1.));
const double degtorad(180./pi);

double asncs(double s, double c){return atan2(s,c);}
double acssn(double c, double s){return atan2(s,c);}
double asn(const double s){return (fabs(s)<1.)?asin(s):((s>0.)?pi/2.:-pi/2.);}
double acs(const double c){return (fabs(c)<1.)?acos(c):((c>0.)?0.:pi);}
double snc(double x){
	constexpr double tol = 1.e-18;
	if(fabs(x)<tol) return 1.;
	return sin(x)/x;
}

}
