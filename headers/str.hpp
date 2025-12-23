
//strings - P. Ahrenkiel

#ifndef _STR_
#define _STR_
#include <iostream>
#include <CoreGraphics/CoreGraphics.h>
 
class str
{
private:
	std::string _s;
	
public:
	str():_s(){}
	str(const std::string &s):_s(s){}
	str(const char *c):_s(c){}
	str(const char &c);
	str(const double Num,const int nDig);
	str(const float Num,const int nDig);
	str(const long Num);
	str(const int Num);
	str(const int Num,const int nDig);
	
	std::string& operator()(){return _s;}
	const std::string& operator()() const{return _s;}
	
	char *schar() const;
	char *schar(size_t n,size_t pos=0) const;

	str mid(const short pos,const short slen);
	str left(const short slen);
	str right(const short slen);
	bool contains(const str& s,short *pos);
	bool containsRight(const str& s,short *pos);
	str allcaps();
	
	short len() const;
	void find(str &s,const char delim,const short occurence);
	void find(int &i,const char delim,const short occurence);
	void find(float &f,const char delim,const short occurence);
	
	bool operator==(const std::string& s) const;
	bool operator==(const str &s) const;
	bool operator==(const char *c) const;
	bool operator!=(const std::string& s) const;
	str operator+(const str &s) const;
	str operator+=(const str &s);

	int sint();
	float sfloat();
	
	friend std::istream& operator >>(std::istream &is,str &s);
	friend std::ostream& operator <<(std::ostream &os,const str &s);
	
#if defined(TARGET_IOS)
//#include <CoreServices/CoreServices.h>
	str(UniChar *s,const UInt16 slen);
	CFStringRef cfStringRef(CFAllocatorRef allocator=NULL,CFStringEncoding encoding=kCFStringEncodingUTF8) const;
	void draw(CGPoint P) const;
	void draw(CGRect R) const;
#endif
};

extern const str null_str;
#endif
