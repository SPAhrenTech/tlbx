//
//  ObjC_Interop.h
//  invaders
//
//  Created by Phil Ahrenkiel on 9/24/22.
//  Copyright © 2022 Phil Ahrenkiel. All rights reserved.
//

#ifndef _OBJC_INTEROP_
#define _OBJC_INTEROP_

#import <CoreGraphics/CoreGraphics.h>

#if defined(TARGET_IOS) || defined(TARGET_TVOS)
#import <UIKit/UIKit.h>
#define PlatformFont UIFont
#else
#define PlatformFont NSFont
#endif

#include <iostream>

//class bridgeClass;

@interface ObjC_Interop:NSObject
{
@public

};

-(void)drawString:(CFStringRef)s point:(CGPoint)P;
-(void)drawString:(CFStringRef)s rect:(CGRect)R;

@end

#endif //_OBJC_INTEROP_
