//RGBA colors - P. Ahrenkiel

#include <cstdlib>
#include <math.h>
#include "col.hpp"

namespace col {

const RGB RGB::Black(0.,0.,0.);
const RGB RGB::White(1.,1.,1.);
const RGB RGB::Red(1.,0.,0.);
const RGB RGB::Green(0.,1.,0.);
const RGB RGB::Blue(0.,0.,1.);
const RGB RGB::Yellow(1.,1.,0.);
const RGB RGB::Magenta(1.,0.,1.);
const RGB RGB::Cyan(1.,0.,1.);

//
RGB RGB::operator+(const RGB& c) const
{
	RGB cp;
	cp._red=_red+c._red;
	cp._green=_green+c._green;
	cp._blue+=_blue+c._blue;
	return cp;
}
	
//
RGB RGB::operator-(const RGB& c) const
{
	RGB cp;
	cp._red=_red-c._red;
	cp._green=_green-c._green;
	cp._blue=_blue-c._blue;
	return cp;
}
	
//
RGB operator*(const float x,const RGB& c)
{
	RGB cp;
	cp.red()=x*c.red();
	cp.green()=x*c.green();
	cp.blue()=x*c.blue();
	return cp;
}

//
RGB RGB::operator/(const float x) const
{
	return (1./x)*(*this);
}

//
RGBA RGBA::operator+(const RGBA& c) const
{
	RGB cpRGB = *this;
	cpRGB = cpRGB + c;
	return RGBA(cpRGB, 0.5 * (_alpha+c._alpha));
}
	
//
RGBA RGBA::operator-(const RGBA& c) const
{
	RGB cpRGB = *this;
	cpRGB = cpRGB - c;
	return RGBA(cpRGB, 0.5 * (_alpha+c._alpha));
}
	
//
RGBA RGBA::operator/(const float x) const
{
	return (1./x)*(*this);
}
	
//
RGBA operator*(float x,const RGBA& c)
{
	RGB cpRGB = c;
	cpRGB = x * cpRGB;
	return RGBA(cpRGB, c.alpha());
}

}
