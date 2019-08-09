//
//  Utilities.h
//  SohaPlayerAds
//
//  Created by Build Server on 5/25/19.
//  Copyright © 2019 SohaPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Utilities : NSObject

+(NSString*) miliSecondsToTimer:(long)milliseconds;

+(NSInteger)timerToSeconds:(NSString*)timer;

@end

NS_ASSUME_NONNULL_END
