//
//  SHLog.h
//  SohaPlayer
//
//  Created by Le Cuong on 10/14/16.
//  Copyright © 2016 Le Cuong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SHLogManager.h"


extern NSString *const SHLoggingNotification;
extern NSString *const SHLogMessageKey;
extern NSString *const SHLogMessageLevelKey;


void _SHLog(SHLogLevel logLevel, NSString *methodName, int lineNumber, NSString *format, ...);
void notifyListener(NSString *message, NSInteger messageLevel);

#ifdef DEBUG
#define __FileName__ [[NSString stringWithUTF8String:__FILE__] lastPathComponent]
#define __LineNumber__ __LINE__
#define __MethodName__ [[NSString stringWithUTF8String:__func__] lastPathComponent]

#define SHLogTrace(...) SHLogManager.SHLogLevel <= SHLogLevelTrace ? _SHLog(SHLogLevelTrace,__MethodName__,__LineNumber__,__VA_ARGS__):nil
#define SHLogDebug(...) SHLogManager.SHLogLevel <= SHLogLevelDebug ? _SHLog(SHLogLevelDebug,__MethodName__,__LineNumber__,__VA_ARGS__):nil
#define SHLogInfo(...) SHLogManager.SHLogLevel <= SHLogLevelInfo ? _SHLog(SHLogLevelInfo,__MethodName__,__LineNumber__,__VA_ARGS__):nil
#define SHLogWarn(...) SHLogManager.SHLogLevel <= SHLogLevelWarn ? _SHLog(SHLogLevelWarn,__MethodName__,__LineNumber__,__VA_ARGS__):nil
#define SHLogError(...) SHLogManager.SHLogLevel <= SHLogLevelError ? _SHLog(SHLogLevelError,__MethodName__,__LineNumber__,__VA_ARGS__):nil
#else
#define SHLogTrace(...) /* */
#define SHLogDebug(...) /* */
#define SHLogInfo(...) /* */
#define SHLogWarn(...) /* */
#define SHLogError(...) /* */
#endif

#if !defined(DEBUGCC)
#define SHLogChromeCast(...)
#else
#define SHLogChromeCast(...) SHLogManager.SHLogLevel <= SHLogLevelChromeCast ? _SHLog(SHLogLevelChromeCast,__MethodName__,__LineNumber__,__VA_ARGS__):nil
#endif

#ifdef DEBUG
#    define DLog(...) NSLog(__VA_ARGS__)
#else
#    define DLog(...) /* */
#endif
#define ALog(...) NSLog(__VA_ARGS__)
