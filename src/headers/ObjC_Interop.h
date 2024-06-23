//C<->ObjC bridge - Phil Ahrenkiel

#import "CoreGraphics/CoreGraphics.h"

#ifdef TARGET_IOS
#import <UIKit/UIKit.h>
#define PlatformFont UIFont
#endif

#ifdef TARGET_MACOS
#import <AppKit/AppKit.h>
#define PlatformFont NSFont
#endif

#include <iostream>

//class bridgeClass;

@interface ObjC_Interop:NSObject
{
@public

	//long pointerToBridge;

};

//-(void)drawString:(CFStringRef)s;
-(void)drawString:(CFStringRef)s point:(CGPoint)P;
-(void)drawString:(CFStringRef)s rect:(CGRect)R;

//-(void)storeBridgePointer:(long)ptr;

@end

//#endif //_OBJC_INTEROP_
