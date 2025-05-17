// trigenomtry - P. Ahrenkiel

#ifndef _TRG_
#define _TRG_

#include <cstdlib>
#include <math.h>

namespace trg {

inline const double Pi(4.*atan(1.));
inline const double degtorad(180./Pi);

//trg
inline double asincos(double s, double c){return atan2(s,c);}
inline double acossin(double c, double s){return atan2(s,c);}

//special function(s)
inline double sinc(double x){
	constexpr double tol = 1.e-18;
	if (fabs(x)<tol) return 1.;
	return sin(x)/x;
}

} // namespace trg

#endif
