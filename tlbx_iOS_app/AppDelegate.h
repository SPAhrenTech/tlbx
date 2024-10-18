//
//  AppDelegate.h
//  tlbx_iOS_app
//
//  Created by Phil Ahrenkiel on 2/10/23.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

