// math - P. Ahrenkiel

#ifndef _MTH_
#define _MTH_

#include <cstdlib>
#include <math.h>

namespace mth {

double sqr(const double x);
double sgn(const double x);
double sgnp(const double x);
double pwr(const double x,const std::size_t y);
double pwr(const double x,const int y);
double pwr(const double x,const double y);
double logy(const double x,const double y);
std::size_t cyc(std::size_t i);
std::size_t cyc(std::size_t i, const std::size_t N);
double Kdelta(std::size_t i, std::size_t j);
double dexp(const double x);
double dmod(double x,double y);
int mod(const int x,const int y);
double rndom();
double roundoff(const double x);
double magsqr(double *x,const size_t N);

} // namespace mth

#endif
