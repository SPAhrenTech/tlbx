// trigenomtry - P. Ahrenkiel

#ifndef _TRG_
#define _TRG_

#include <cstdlib>
#include <math.h>

namespace trg {

extern const double Pi;
extern const double degtorad;

//trg
double asincos(double s, double c);
double acossin(double c, double s);
double asn(const double s);
double acs(const double c);

//special function(s)
double sinc(double x);

} // namespace trg

#endif
