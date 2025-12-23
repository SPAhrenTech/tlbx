// trigenomtry - P. Ahrenkiel

#ifndef _TRG_
#define _TRG_

#include <cstdlib>
#include <math.h>

namespace trg {

extern const double pi;
extern const double degtorad;

double asncs(double s, double c);
double acssn(double c, double s);
double asn(const double s);
double acs(const double c);
double snc(double x);

} // namespace trg

#endif
