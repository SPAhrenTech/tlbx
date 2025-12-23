//strings - P. Ahrenkiel

#include <cstdlib>
#include <string>
#include <math.h>

#include "mth.hpp"
#include "str.hpp"
#include <CoreServices/CoreServices.h>
#include <CoreGraphics/CoreGraphics.h>

#if defined(TARGET_IOS)
#include "cppBridge.h"
#endif

const str null_str;

str::str(const char &c)
{
	_s=c;
}

str::str(const double Num,const int nDig)
{
	_s="";
	if(Num<0)
		_s="-";
	
	int nMag=0;
	double  pDig=mth::pwr(10.,nDig);
	double nRem=fabs(Num);
	if(nRem>0.)nMag=(int)log10(nRem);
	if(nMag<0)nMag=0;


	for(int i=nMag;i>=-nDig;i--){

		double p=mth::pwr(10.,(double)i);

		double tVal=mth::roundoff(nRem*pDig)/pDig;
		int nVal=(int)(tVal/p+1./pDig/10.);

		char c=(char)(nVal+(int)'0');/*ascii*/
		if(((int)c>=(int)'0')&&((int)c<=(int)'9'))
			_s+=c;

		if((i==0)&&(nDig>0))
			_s+=".";/*decimal point*/

		double dVal=mth::roundoff(nRem*pDig);
		double dpVal=mth::roundoff(nVal*p*pDig);
		nRem=(dVal-dpVal)/pDig;
		}
	}
	
str::str(const float Num,const int nDig):str((double)Num,nDig)
{
}
	
str::str(const long Num)
{
	int nVal;
	if(Num<0)
		(*this)=str("-");
	
	int nMag=0;
	double nRem=fabs(Num);
	if(nRem>0.)nMag=(int)log10(nRem);
		
	if(nMag<0)nMag=0;
	
	for(int i=nMag;i>=0;i--){

		nVal=(int)(nRem/pow(10.,(double)i));
		nRem=nRem-nVal*pow(10.,(double)i);

		char c=(char)(nVal+(int)'0');/*ascii*/
		if((int(c)>=(int)'0')&&(int(c)<=(int)'9'))
			_s+=c;

		}
}

str::str(const int Num)
{
	(*this)=str((long)Num);
}
	
str::str(int Num,int nDig)
{
	(*this)=str(Num);
	while(len()<nDig)
		_s="0"+_s;
}
	
str str::operator+(const str &s) const
{
	return _s+s();
}

str str::operator+=(const str &s)
{
	return *this=_s+s();
}

short str::len() const
{
	return _s.size();
}
			
char *str::schar(size_t n,size_t pos) const
{
	//copy(c,Lp,pos1);
	size_t L=_s.size();
	size_t pos1=pos;
	size_t pos2=pos+n;

	if(pos1>L-1)
		return NULL;

	if(pos2>L-1)pos2=L-1;
	
	size_t Lp=pos2-pos1+1;
	char *c=new char[Lp+1];
	_s.copy(c,Lp,pos1);
	c[Lp]='\0';
	return c;
}

bool str::operator==(const std::string& s) const
{
	return _s==s;
}

bool str::operator==(const char *c) const
{
	return str::operator()()==str(c)();
}

bool str::operator==(const str &s) const
{
	return _s==s();
}

bool str::operator!=(const std::string& s) const
{
	return _s!=s;
}

char *str::schar() const
{
	return schar(len(),0);
}

str str::mid(const short pos,const short slen)
{
	short l=len();
	str res;
	
	short i;
	for(i=pos;(i<pos+slen)&&(i<l);++i)
	{
		char c=_s[i];
		res+=c;
	}
	return res;
}

str str::left(const short slen)
{
	return mid(0,slen);
}

str str::right(const short slen)
{
	int l=len();
	return mid(l-slen,slen);
}

//
bool str::contains(const str &s,short *pos)
{
	short l=s.len();
	short l0=len();
	short i;
	for(i=0;i<l0-l;++i)
	{
		str ssub=mid(i,l);
		if(ssub()==s())
		{
			*pos=i;
			return true;
		}
	}
	return false;
}

bool str::containsRight(const str &s,short *pos)
{
	short l=s.len();
	short l0=len();
	short i;
	for(i=0;i<l0-l;i++)
	{
		short j=(l0-l)-i-1;
		str ssub=mid(j,l);
		if(ssub()==s())
		{
			*pos=j;
			return true;
		}
	}
	return false;
}

str str::allcaps()
{
	str scap=*this;
	std::size_t L=_s.size();
	for(std::size_t i=0; i<L; i++)
	{
		char c=_s[i+1];
		if(('a'<=c)&&(c<='z'))
			c-=(short)'a'-(short)'A';
		scap._s[i+1]=c;
	}
	return scap;
}

void str::find(str &s,const char delim,const short occurence)
{
	size_t L=_s.size();
	
	short jocc=0;
	for(std::size_t i=0;i<L;++i)
	{
		str sc=mid(i,1);
		if(sc()==str(delim)())
		{
			++jocc;
			if(jocc==occurence)
				break;
			else
				s=str('\0');
		}
		else
			s+=sc;
	}
}

void str::find(int &i,const char delim,const short occurence)
{
	str S;
	find(S,delim,occurence);
	i=S.sint();
}

void str::find(float &f,const char delim,const short occurence)
{
	str S;
	find(S,delim,occurence);
	f=S.sfloat();
}

int str::sint()
{
	return atoi(_s.c_str());
}
	
float str::sfloat()
{
	return atof(_s.c_str());
}

std::istream& operator>>(std::istream &is,str &s)
{
	is>>(std::string &)(s);
	return is;
}

std::ostream& operator<<(std::ostream &os,const str &s)
{
	os<<s();
	return os;
}

#if defined(TARGET_IOS)
CFStringRef str::cfStringRef(CFAllocatorRef allocator,CFStringEncoding encoding) const
{
	return CFStringCreateWithCString(allocator,_s.c_str(),encoding);
}

str::str(UniChar *s,const UInt16 slen):_s()
{
	for(short i=0;i<slen;++i)
		_s+=s[i];
}

void str::draw(CGPoint P) const
{
	drawString(cfStringRef(),P);
}

void str::draw(CGRect R) const
{
	drawString(cfStringRef(),R);
}
#endif
