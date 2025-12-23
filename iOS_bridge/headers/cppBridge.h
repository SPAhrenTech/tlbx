//
//  C++ bridge to Obj-C functions
//
//  Created by Phil Ahrenkiel on 6/16/19.
//  Copyright © 2019 Phil Ahrenkiel. All rights reserved.
//


#ifndef CPP_BRIDGE
#define CPP_BRIDGE

//#import <CoreData/CoreData.h>
#import "CoreGraphics/CoreGraphics.h"
//#import <UIKit/UIKit.h>
#include <iostream>
#include <stdio.h>

void drawString(CFStringRef s,CGPoint P);
void drawString(CFStringRef s,CGRect R);

#endif
