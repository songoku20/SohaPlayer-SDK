//
//  SohaPlayerAdsViewController.h
//  SohaPlayerAds
//
//  Created by Build Server on 5/24/19.
//  Copyright © 2019 SohaPlayer. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SHAdManager.h"


NS_ASSUME_NONNULL_BEGIN

@interface SohaPlayerAdsView : UIView

@property(nonatomic) BOOL playMultiAds;
@property(nonatomic) BOOL skipAllAds;
@property (nonatomic, readonly) NSString* timeOffset;
@property (nonatomic, weak) id<SHPlayerContentDelegate> shPlayerContentDelegate;
@property(nonatomic,weak) id<SHAdEventDelegate> shAdEventDelegate;

+(SohaPlayerAdsView*)instanceFromNib;

- (void)initView;

-(void)requestAds:(NSURL*)url;

-(void)requestAds:(NSURL*)url reset:(BOOL)reset;

-(void)putMoreAds:(NSURL*)url;

-(void) resumeAds;

-(void) pauseAds;

-(void) muteAds:(BOOL) mute;

-(BOOL) isMutedAds;

-(void) skipAds;

-(void) releaseAds;

-(BOOL) isPlayingAds;

-(NSArray*) getMarkerShowAds;

-(NSArray*) getMarkerShowed;

-(float) getDurationAds;

-(float) getCurrentTimeAds;

-(float) getVolumeAds;

-(void) setVolumeAds:(float)volume;

-(NSDictionary*)getCurrentAds;

-(void)setTimeOffsetDefault:(int)timeOffset;

-(void)videoContentSeeked:(NSString*)startPoint endPoint:(NSString*)endPoint;

@end

NS_ASSUME_NONNULL_END
