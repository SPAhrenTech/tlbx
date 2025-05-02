//colors - P. Ahrenkiel

#ifndef _COL_
#define _COL_

namespace col {

class RGB
{
protected:
	float _red,_green,_blue;

public:
	RGB():_red(0),_green(0),_blue(0){}
	RGB(const float r,const float g,const float b):_red(r),_green(g),_blue(b){}

	float& red(){return _red;}
	float& green(){return _green;}
	float& blue(){return _blue;}

	float red() const{return _red;}
	float green() const{return _green;}
	float blue() const{return _blue;}

	RGB operator+(const RGB& c) const;
	RGB operator-(const RGB& c) const;
	RGB operator/(const float x) const;
	friend RGB operator*(const float x,const RGB& c);

	static const RGB Black;
	static const RGB White;
	static const RGB Red;
	static const RGB Green;
	static const RGB Blue;
	static const RGB Yellow;
	static const RGB Magenta;
	static const RGB Cyan;
	
};

//
class RGBA:public RGB
{
private:
	float _alpha;

public:
	RGBA():RGB(),_alpha(1){}
	RGBA(const float r,const float g,const float b,const float a=1.0):RGB(r,g,b),_alpha(a){}
	RGBA(const RGB &crgb,const float a=1.0):RGB(crgb),_alpha(a){}
	
	RGBA operator+(const RGBA& c) const;
	RGBA operator-(const RGBA& c) const;
	
	float& alpha(){return _alpha;}
	float alpha() const{return _alpha;}

	RGBA operator/(const float x) const;
	friend RGBA operator*(const float x,const RGBA& c);
};

}

#endif

