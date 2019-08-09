//
//  SHResources.h
//  VietIdLib
//
//  Created by Sam Green on 5/2/16.
//  Copyright © 2016 VietIdLib. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ShAdsResources : NSObject

+ (UIStoryboard *)storyboardWithName:(NSString *)name;
+ (UINib *)nibWithName:(NSString *)name;
+ (NSBundle *)frameworkBundle;
+ (UIImage *)imageNamed:(NSString *)name;

@end
