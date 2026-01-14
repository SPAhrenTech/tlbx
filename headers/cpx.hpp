// complex - P. Ahrenkiel

#ifndef _CPX
#define _CPX

#include <cstdlib>
#include <complex>

using cpxd=std::complex<double>;

class cpx:public cpxd
{
	public:
	//member def(s)
	cpx():std::complex<double>(){}
	cpx(const std::complex<double> &c):std::complex<double>(c){}
	cpx(const double x):std::complex<double>(x,0.){}
	cpx(const double x,const double y):std::complex<double>(x,y){}
	~cpx(){}

	cpxd& operator()(){return *this;}

	inline double phase() const{return arg(*this);}
	inline double magsqr() const{return norm(*this);}
	inline double mag() const{return abs(*this);}
	inline double Re() const{return real();}//{const cpxd& c=*this;return std::get<0>(c);}
	inline double Im() const{return imag();}
	
	static const cpx i;
};

inline double phase(const cpx &C){return C.phase();}
inline double magsqr(const cpx &C){return C.magsqr();}
inline double mag(const cpx &C){return C.mag();}
inline double Re(const cpx &C){return C.Re();}
inline double Im(const cpx &C){return C.Im();}

#endif

