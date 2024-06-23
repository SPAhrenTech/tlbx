//C<->ObjC bridge - Phil Ahrenkiel
#ifndef CPP_BRIDGE
#define CPP_BRIDGE

#import "CoreGraphics/CoreGraphics.h"
#include <iostream>
#include <stdio.h>


void drawString(CFStringRef s,CGPoint P);
void drawString(CFStringRef s,CGRect R);

/*
//
typedef struct tlbxBridge bridge;

#ifdef TLBX_BRIDGE
extern "C"
{
#endif

	bridge *create_tlbxBridge();
	void release_tlbxBridge(bridge *c);
	
	void tlbxMethod(bridge *c,double x);
	
#ifdef TLBX_BRIDGE
}
#endif
*/
#endif
