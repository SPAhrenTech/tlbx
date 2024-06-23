//colors - P. Ahrenkiel

#include <cstdlib>
#include <math.h>
#include "col.hpp"

constexpr colRGB colRGB::Black(0.,0.,0.);
constexpr colRGB colRGB::White(1.,1.,1.);
constexpr colRGB colRGB::Red(1.,0.,0.);
constexpr colRGB colRGB::Green(0.,1.,0.);
constexpr colRGB colRGB::Blue(0.,0.,1.);
constexpr colRGB colRGB::Yellow(1.,1.,0.);
constexpr colRGB colRGB::Magenta(1.,0.,1.);
constexpr colRGB colRGB::Cyan(1.,0.,1.);

//
CGColorRef col::cgColor() const
{
	return CGColorCreateGenericRGB(_red,_green,_blue,_alpha);
}

//
col col::operator+(const col& c) const
{
	col cp;
	cp._red=_red+c._red;
	cp._green=_green+c._green;
	cp._blue+=_blue+c._blue;
	cp._alpha=(_alpha+c._alpha)/2.;
	return cp;
}
	
//
col col::operator-(const col& c) const
{
	col cp;
	cp._red=_red-c._red;
	cp._green=_green-c._green;
	cp._blue=_blue-c._blue;
	cp._alpha=(_alpha+c._alpha)/2.;
	return cp;
}
	
//
col col::operator/(const float x) const
{
	return (1./x)*(*this);
}
	
//
col operator*(float x,const col& c)
{
	col cp;
	cp.red()=x*c.red();
	cp.green()=x*c.green();
	cp.blue()=x*c.blue();
	cp.alpha()=c.alpha();
	return cp;
}

//
void col::setFill(CGContextRef &context) const
{
    CGContextSetRGBFillColor(context,_red,_green,_blue,_alpha);

}

//
void col::setStroke(CGContextRef &context) const
{
	CGContextSetRGBStrokeColor(context,_red,_green,_blue,_alpha);
}

//
void col::setFill(CGContextRef &context,const float alpha) const
{
	CGContextSetRGBFillColor(context,_red,_green,_blue,_alpha);
}

//
void col::setStroke(CGContextRef &context,const float alpha) const
{
	CGContextSetRGBStrokeColor(context,_red,_green,_blue,_alpha);
}
	
//
col::operator simd::float4()
{
	simd::float4 res={_blue,_green,_red,_alpha};
	return res;
}

//
colRGB::operator simd::float3()
{
	simd::float3 res={_blue,_green,_red};
	return res;
}

//
colRGB colRGB::operator+(const colRGB& c) const
{
	colRGB cp;
	cp._red=_red+c._red;
	cp._green=_green+c._green;
	cp._blue+=_blue+c._blue;
	return cp;
}
	
//
colRGB colRGB::operator-(const colRGB& c) const
{
	colRGB cp;
	cp._red=_red-c._red;
	cp._green=_green-c._green;
	cp._blue=_blue-c._blue;
	return cp;
}
	
//
colRGB operator*(const float x,const colRGB& c)
{
	colRGB cp;
	cp.red()=x*c.red();
	cp.green()=x*c.green();
	cp.blue()=x*c.blue();
	return cp;
}

//
colRGB colRGB::operator/(const float x) const
{
	return (1./x)*(*this);
}
	
