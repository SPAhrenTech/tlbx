//colors - P. Ahrenkiel

#ifndef _COL_
#define _COL_

#import "CoreGraphics/CoreGraphics.h"
#include <simd/simd.h>

class colRGB
{
protected:
	float _red,_green,_blue;

public:
	constexpr colRGB():_red(0),_green(0),_blue(0){}
	constexpr colRGB(const float r,const float g,const float b):_red(r),_green(g),_blue(b){}

	float& red(){return _red;}
	float& green(){return _green;}
	float& blue(){return _blue;}

	const float red() const{return _red;}
	const float green() const{return _green;}
	const float blue() const{return _blue;}

	operator simd::float3();

	colRGB operator+(const colRGB& c) const;
	colRGB operator-(const colRGB& c) const;
	colRGB operator/(const float x) const;
	friend colRGB operator*(const float x,const colRGB& c);

	static const colRGB Black;
	static const colRGB White;
	static const colRGB Red;
	static const colRGB Green;
	static const colRGB Blue;
	static const colRGB Yellow;
	static const colRGB Magenta;
	static const colRGB Cyan;

};

//
class col:public colRGB
{
private:
	float _alpha;

public:
	constexpr col():colRGB(),_alpha(1){}
	constexpr col(const float r,const float g,const float b,const float a=1.0):colRGB(r,g,b),_alpha(a){}
	constexpr col(const colRGB &crgb,const float a=1.0):colRGB(crgb),_alpha(a){}
	
	col operator+(const col& c) const;
	col operator-(const col& c) const;
	
	CGColorRef cgColor() const;

	float& alpha(){return _alpha;}
	const float alpha() const{return _alpha;}

	col operator/(const float x) const;
	friend col operator*(const float x,const col& c);

	void setFill(CGContextRef &context) const;
	void setStroke(CGContextRef &context) const;

	void setFill(CGContextRef &context,const float alpha) const;
	void setStroke(CGContextRef &context,const float alpha) const;

	operator simd::float4();

	//fl_err read(tfl &f);
};

#endif

