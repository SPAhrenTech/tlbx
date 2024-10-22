/*
Colors - P. Ahrenkiel
*/

#include <cstdlib>
#include <math.h>

#include "col.hpp"

const col blackcol(0.,0.,0.);
const col whitecol(1.,1.,1.);

const col redcol(1.,0.,0.);
const col greencol(0.,1.,0.);
const col bluecol(0.,0.,1.);

const col yellowcol(1.,1.,0.);
const col magentacol(1.,0.,0.);
const col cyancol(0.,1.,1.);


//
col::col(const float r,const float g,const float b,const float a):m_red(r),m_green(g),m_blue(b),m_alpha(a)
{}
	
//
col::~col()
{}

CGColorRef col::cgColor() const
{
	return CGColorCreateGenericRGB(m_red,m_green,m_blue,m_alpha);
}

//
col col::operator+(const col& c) const
{
	col cp;
	cp.m_red=m_red+c.m_red;
	cp.m_green=m_green+c.m_green;
	cp.m_blue+=m_blue+c.m_blue;
	cp.m_alpha=(m_alpha+c.m_alpha)/2.;
	return cp;
}
	
//
col col::operator-(const col& c) const
{
	col cp;
	cp.m_red=red()-c.red();
	cp.m_green=green()-c.green();
	cp.m_blue+=blue()-c.blue();
	cp.m_alpha=(alpha()+c.alpha())/2.;
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
    CGContextSetRGBFillColor(context,red(),green(),blue(),alpha());

}

//
void col::setStroke(CGContextRef &context) const
{
	CGContextSetRGBStrokeColor(context,red(),green(),blue(),alpha());
}

//
void col::setFill(CGContextRef &context,const float alph) const
{
	CGContextSetRGBFillColor(context,red(),green(),blue(),alph);
}

//
void col::setStroke(CGContextRef &context,const float alph) const
{
	CGContextSetRGBStrokeColor(context,red(),green(),blue(),alph);
}
	
