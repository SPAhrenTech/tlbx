//C<->ObjC bridge - Phil Ahrenkiel

#import <Foundation/Foundation.h>
#import "ObjC_Interop.h"
#include <iostream>

std::string defaultFontName("Georgia");
float defaultFontSize(14.0);

@implementation ObjC_Interop
//using namespace std;

//
-(void)drawString:(CFStringRef)s point:(CGPoint)P
{
	NSString *ns=(NSString *)CFBridgingRelease(s);
	NSString *nsFont=[[NSString alloc] initWithUTF8String:defaultFontName.c_str()];
	PlatformFont *pfont=[PlatformFont fontWithName:nsFont size:defaultFontSize];
	NSDictionary *attrs=[NSDictionary dictionaryWithObject:pfont forKey:NSFontAttributeName];
	[ns drawAtPoint:P withAttributes:attrs];
}

//
-(void)drawString:(CFStringRef)s rect:(CGRect)R
{
	NSString *ns=(NSString *)CFBridgingRelease(s);
	NSString *nsFont=[[NSString alloc] initWithUTF8String:defaultFontName.c_str()];
	PlatformFont *pfont=[PlatformFont fontWithName:nsFont size:defaultFontSize];
	NSDictionary *attrs=[NSDictionary dictionaryWithObject:pfont forKey:NSFontAttributeName];
	[ns drawInRect:R withAttributes:attrs];
}

@end

//Provide access from C++
void drawString(CFStringRef s,CGPoint P)
{
	ObjC_Interop *objC=[ObjC_Interop alloc];
	[objC drawString:s point:P];
}
void drawString(CFStringRef s,CGRect R)
{
	ObjC_Interop *objC=[ObjC_Interop alloc];
	[objC drawString:s rect:R];
}
