//
//  SHLogManager.h
//  SohaPlayer
//
//  Created by Le Cuong on 10/14/16.
//  Copyright © 2016 Le Cuong. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SH_DEBUG_MODE				1

typedef NS_ENUM(NSInteger, SHLogLevel) {
    SHLogLevelAll           = 0,
	SHLogLevelTrace         = 10,
	SHLogLevelDebug         = 20,
	SHLogLevelInfo          = 30,
	SHLogLevelWarn          = 40,
	SHLogLevelError         = 50,
	SHLogLevelOff           = 60,
    SHLogLevelChromeCast	= 70
};

// use the `QLogManager` methods to set the desired level of log filter
@interface SHLogManager : NSObject

// gets the current log filter level
+ (SHLogLevel)SHLogLevel;

// set the log filter level
+ (void)setSHLogLevel:(SHLogLevel)level;

+ (NSArray *)levelNames;
@end
