//
//  SHRequest.h
//  SohaPlayerAds
//
//  Created by Build Server on 5/24/19.
//  Copyright © 2019 SohaPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SHRequest : NSObject
+(NSDictionary*)dictionaryFromRequestURL:(NSURL*)url;
+(void)dictionaryFromRequestURLAsync:(NSURL*)url response:(void (^)(NSError*,NSDictionary*))response;
+(void) pushEventTracking:(NSString*)urlPush;
@end

NS_ASSUME_NONNULL_END
