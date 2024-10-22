/*
Colors - P. Ahrenkiel
*/

#ifndef _COL_
#define _COL_

//#include <Carbon/Carbon.h>
#import "CoreGraphics/CoreGraphics.h"

//
class col
{
private:
	float m_red,m_green,m_blue,m_alpha;

public:
	col(const float r=0.,const float g=0.,const float b=0.,const float a=1.);
	~col();

	col operator+(const col& c) const;
	col operator-(const col& c) const;
	
	CGColorRef cgColor() const;

	float& red(){return m_red;}
	float& green(){return m_green;}
	float& blue(){return m_blue;}
	float& alpha(){return m_alpha;}
	
	const float red() const{return m_red;}
	const float green() const{return m_green;}
	const float blue() const{return m_blue;}
	const float alpha() const{return m_alpha;}

	col operator/(const float x) const;
	friend col operator*(const float x,const col& c);

	void setFill(CGContextRef &context) const;
	void setStroke(CGContextRef &context) const;

	void setFill(CGContextRef &context,const float alph) const;
	void setStroke(CGContextRef &context,const float alph) const;

	//fl_err read(tfl &f);
};

extern const col 
	blackcol,
	whitecol,
	
	redcol,
	greencol,
	bluecol,
	
	yellowcol,
	magentacol,
	cyancol;

#endif

