//math - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "mth.hpp"

namespace mth{

double sqr(const double x){return x*x;}
double sgn(const double x){return (x>0.)?1.:(x<0.)?-1.:0.;}
double sgnp(const double x){return (x>0.)?1.:(x<0.)?-1.:1.;}
double pwr(const double x,const std::size_t y){return pow(x,y);}
double pwr(const double x,const int y){return pow(x,y);}
double pwr(const double x,const double y){return pow(x,y);}
double logy(const double x,const double y){return log(fabs(x))/log(y);}
std::size_t cyc(std::size_t i){while(i>2)i-=3;return i;}
std::size_t cyc(std::size_t i, const std::size_t N){while(!(i<N))i-=N;return i;}
double Kdelta(std::size_t i, std::size_t j){return (i==j)?1.:0.;}
double dexp(const double x){return exp(x);}
double dmod(double x,double y){return x-y*floor(x/y);}
int mod(const int x,const int y){return (x>=0)?x%y:(y-(-x)%y)%y;}
double random(){return 1./(RAND_MAX+1.)*rand();}

double roundoff(const double x){
	double xp=fabs(x);
	double r=trunc(xp);
	if(xp-r>0.5)r++;
	if(x<0)r*=-1;
	return r; 	
}

double magsqr(double *x,const size_t N){
	double res=0.;
	for(std::size_t i=0;i<N-1;++i)
		res+=sqr(x[i]);
	return res;
}

} // namespace mth
