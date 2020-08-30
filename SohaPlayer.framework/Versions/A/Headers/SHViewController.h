//
//  SHViewController.h
//  SohaPlayer
//
//  Created by Le Cuong on 10/14/16.
//  Copyright © 2016 Le Cuong. All rights reserved.
//


@protocol SohaPlayer;

#import "SHViewControllerProtocols.h"
#import "SHPlayerConfig.h"

@protocol SHAdEventDelegate;

typedef NS_ENUM(NSInteger, AdViewTypez) {
    AD_VIEW_TITLE = 0,
    AD_VIEW_PROGRESS,
    AD_VIEW_MUTE
};

#define PLAYER_VERSION @"1.3.5-pro"

// -----------------------------------------------------------------------------
// Media Player Types

typedef NS_ENUM(NSInteger, SHMediaPlaybackState) {
    /* Playback is unknown. */
    SHMediaPlaybackStateUnknown = 0,
    /* Playback is currently loaded. */
    SHMediaPlaybackStateLoaded = 1,
    /* Playback is currently ready. */
    SHMediaPlaybackStateReady = 2,
    /* Playback is currently under way. */
    SHMediaPlaybackStatePlaying = 3,
    /* Playback is currently paused. */
    SHMediaPlaybackStatePaused = 4,
    /* Playback is currently ended. */
    SHMediaPlaybackStateEnded = 5,
    /* Playback is temporarily interrupted, perhaps because the buffer ran out of content. */
    SHMediaPlaybackStateInterrupted = 6,
    /* The movie player is currently seeking towards the end of the movie. */
    SHMediaPlaybackStateSeekingForward = 7,
    /* The movie player is currently seeking towards the beginning of the movie. */
    SHMediaPlaybackStateSeekingBackward = 8,
    /* Playback is currently stalled. */
    SHMediaPlaybackStateStalled = 9,
    /* Playback is currently unstalled. */
    SHMediaPlaybackStateUnStalled = 10,
    /* Playback is currently freeze, player must be reload. */
    SHMediaPlaybackStateFreeze = 11
};


typedef NS_OPTIONS(NSUInteger, SHMediaLoadState) {
    /* The load state is not known. */
    SHMediaLoadStateUnknown        = 0,
    /* The buffer has enough data that playback can begin, but it may run out of data before playback finishes. */
    SHMediaLoadStatePlayable       = 1 << 0, //1
    /* Enough data has been buffered for playback to continue uninterrupted. */
    SHMediaLoadStatePlaythroughOK  = 1 << 1, //2 Playback will be automatically started in this state when shouldAutoplay is YES
    /* The buffering of data has stalled. */
    SHMediaLoadStateStalled        = 1 << 2, //4 Playback will be automatically paused in this state, if started
    /* Start buffering*/
    SHMediaLoadStateStartBuffering = 1 << 3, //8
    /* Stop buffering*/
    SHMediaLoadStateStopBuffering = 1 << 4, //16
    
};


typedef NS_ENUM(int, SHAPIRequestType){
    /* Normal */
    SHAPIRequestNormal = 0,
    /* HeartBeat */
    SHAPIRequestHeartBeat = 1,
    /* Source */
    SHAPIRequestSourceLive = 2,
    /* Online Source */
    SHAPIRequestOnlineSourceReceive = 3,
    /* Key Header */
    SHAPIRequestContainKeyHeader = 4
};

typedef NS_ENUM(int, SHPlayerQuality){
    /* 144p: 256×144 */
    SHPlayerQuality144p = 0,
    /* 240p: 426x240 */
    SHPlayerQuality240p = 1,
    /* 360p: 640x360 */
    SHPlayerQuality360p = 2,
    /* 480p: 854x480 */
    SHPlayerQuality480p = 3,
    /* 720p: 1280x720 */
    SHPlayerQuality720p = 4,
    /* 1080p: 1920x1080 */
    SHPlayerQuality1080p = 5,
    /* 1440p: 2560x1440 */
    SHPlayerQuality1440p = 6,
    /* 2160p: 3840x2160 */
    SHPlayerQuality2160p = 7,
    /* Automatic */
    SHPlayerQualityAuto = 8
};

extern NSString * const SHMediaPlaybackStateDidChangeNotification;

// -----------------------------------------------------------------------------
// Media Player Keys
extern NSString * const SHMediaPlaybackStateKey;

@class SHViewController;
@protocol SHViewControllerDelegate <NSObject>

@optional
/**
 * Current playback time delegate.
 * @param currentPlaybackTime current time player playing.
 */
- (void)updateCurrentPlaybackTime:(double)currentPlaybackTime;

@optional
/**
 * Current playload time delegate.
 * @param currentPlayloadTime current time player loaded.
 */
- (void)updateCurrentPlayloadTime:(double)currentPlayloadTime;

@optional
/**
 * Player change load state delegate.
 * @param state SHMediaLoadState player changed.
 */
- (void)SHPlayer:(SHViewController *)player playerLoadStateDidChange:(SHMediaLoadState)state;

@optional
/**
 * Player change playstate delegate.
 * @param state SHMediaPlaybackState player changed.
 */
- (void)SHPlayer:(SHViewController *)player playerPlaybackStateDidChange:(SHMediaPlaybackState)state;

@optional
/**
 * Player change fullscreen mode delegate.
 * @param isFullScreen Whether is in fullscreen mode or not.
 */
- (void)SHPlayer:(SHViewController *)player playerFullScreenToggled:(BOOL)isFullScreen;

@optional
/**
 * Player load failed delegate.
 * @param error Error.
 */
- (void)SHPlayer:(SHViewController *)player didFailWithError:(NSError *)error;

@optional
/**
 * Advertise events delegate.
 * @param event Event name.
 */
- (void)onAdsEventListener:(NSString*)event;

@optional
/**
 * Advertise progress delegate.
 * @param mediaTime Current time advertise playing.
 * @param totalTime Duration of advertise.
 */
- (void)onAdsProgressListener:(float)mediaTime totalTime:(float)totalTime;

@optional
/**
 * Player log events delegate.
 * @param data Data log event.
 */
- (void)onLogEventListener:(NSDictionary*)data;

@optional
/**
 * HeartBeat log events delegate.
 * @param status status heartBeat.
 * @param backgroundLive backgroundLive heartBeat.
 * @param titleLive backgroundLive heartBeat.
 * @param timeEventLive timeEventLive heartBeat.
 * @param source source heartBeat.
 */
- (void)onHeartBeat:(NSString* _Nullable)status backgroundLive:(NSString* _Nullable)backgroundLive titleLive:(NSString* _Nullable)titleLive timeEventLive:(long long)timeEventLive source:(NSString* _Nullable )source;
@end

@interface SHViewController : UIViewController

/**
 * Get length of video.
 * @return Duration of the current video.
 */
-(NSTimeInterval) duration;

/**
 * Get volume of video.
 * @return The volume of the player.
 */
-(float) volume;

- (void)setVolume:(float)value;

/**
 * Get whether player is muted.
 * @return State mute or unmute of the player.
 */
-(BOOL) isMuted;

/**
 * Set mute or unmute of the player.
 */
-(void)setMute:(BOOL)isMute;

/**
 * Get whether player is playing.
 * @return State of player.
 */
-(BOOL)isPlaying;

/**
 * Get current time of player.
 * @return The currentPlaybackTime.
 */
-(NSTimeInterval) currentPlaybackTime;

/**
 * Get current playback state of player. (read-only)
 * The playback state is affected by programmatic calls to play, pause the player.
 * @return The getPlaybackState.
 */
-(SHMediaPlaybackState)getPlaybackState;

/**
 * Call play player.
 */
- (void)play;

/**
 * Call replay player.
 * @param autoPlay replay player with play or pause mode.
 */
- (void)replay:(BOOL)autoPlay;

/**
 * Call pause player.
 */
- (void)pause;

/**
 * Call seek player with float value.
 * @param value Value of time by float wanna seek.
 */
- (void)seekFloat:(float)value;

/**
 * Call seek player with NSTimeInterval value.
 * @param value Value of time by NSTimeInterval wanna seek.
 */
- (void)seek:(NSTimeInterval)value;

///**
// * Call seek player with NSTimeInterval value.
// * @param value Value of time by NSTimeInterval wanna seek.
// * @param completionHandle block handle seek completion.
// */
//- (void)seek:(NSTimeInterval)value completion:(void(^)(BOOL finished))completionHandle;

/**
 * Set config for player.
 * @param configuration Config define by SHPlayerConfig.
 */
- (void)setConfiguration:(SHPlayerConfig *)configuration;

/**
 * Remove player.
 */
- (void)removePlayer;

/**
 * Reset player.
 */
- (void)resetPlayer;
/**
 * Get whether player is in fullscreen mode.
 * @return State of fullscreen.
 */
- (BOOL)isFullscreen;

/**
 * Set player in fullscreen mode.
 */
- (void)toggleFullscreen;

/**
 * Delete all log files.
 */
-(void)deleteAllLogFile;

/**
 * Delete all log files.
 */
-(void)deleteLogFileByName:(NSString*)name;

/**
 * Get image at current time.
 * @return Screenshot image.
 */
- (UIImage *)screenshotFromPlayer;

/**
 * Get image at any time.
 * @param second Time get image.
 * @param error Get image with error.
 * @return Url of image.
 */
- (NSString*)getImageByAPI:(int)second error:(NSError**)error;

/**
 * Log folder path. (readonly)
 */
@property (nonatomic, readonly) NSString* logDir;

/**
 * Set or get extra log when logging.
 */
@property (nonatomic) NSDictionary* extraLog;

/**
 * SHViewController delegate.
 */
@property (nonatomic, weak) id<SHViewControllerDelegate> delegate;

/// Enables to change the player configuration
@property (nonatomic, strong) SHPlayerConfig *currentConfiguration;

/// Change the source and returns the current source
@property (nonatomic, copy) NSURL *playerSource;

/**
 * Resume player
 */
- (void)resumePlayer;

/**
 * Player whether play or pause when start a new video.
 */
@property (nonatomic, setter=setAutoPlayVideo:) BOOL autoPlay;

/**
 * Player whether write log to files or send delegate by SHViewControllerDelegate onLogEventListener:.
 */
@property (nonatomic, setter=setEnableWriteToFile:) BOOL enableWriteToFile;

/**
 * Pause advertise.
 */
-(void)pauseAds;

/**
 * Play advertise.
 */
-(void)playAds;

/**
 * isPlayingAd.
 * @return whether ad is playing.
 */
-(BOOL)isPlayingAd;

/**
 * Set mute or unmute ad.
 * @param muted Whether ad is muted.
 */
-(void)muteAds:(BOOL)muted;

/**
 * Put more ad.
 * @param urlStr Url ad wanna put more.
 */
-(void)putMoreAds:(NSString*)urlStr;

/**
 * Skip ad.
 */
-(void)skipAds;

/**
 * Get ad marker will show.
 * @return Array of string time marker.
 */
-(NSArray*)getMarkerShowAds;

/**
 * Get ad marker showed.
 * @return Array of string time marker.
 */
-(NSArray*)getMarkerShowed;

/**
 * Get length of advertise.
 * @return Duration of the current advertise.
 */
-(float)getDurationAds;

/**
 * Get current time of advertise.
 * @return The current time advertise is playing.
 */
-(float)getCurrentTimeAds;

/**
 * Get current volume of advertise.
 * @return The current volume advertise.
 */
-(float)getVolumeAds;

/**
 * Get whether current player is muted or not.
 * @return Whether player advertise is muted.
 */
-(BOOL) isMutedAds;

/**
 * Set volume for advertise.
 * @param volume The value of volume to set.
 */
-(void) setVolumeAds:(float)volume;

/**
 * Get advertise view.
 * @return The current advertise view.
 */
-(UIView*)getAdView;

/**
 * Get current info of advertise.
 * @return The current info advertise.
 */
-(NSDictionary*)getCurrentAd;

/**
 * Set time offset (time start) for advertise.
 * @param timeOffset Time offset.
 */
-(void)setTimeOffsetDefault:(int)timeOffset;

/**
 * Set whether skip all advertises or skip one advertise.
 * @param skipAllAds Skip all or one.
 */
-(void)setSkipAllAdWhenPress:(BOOL)skipAllAds;

/**
 * Set whether play multiple advertises or play one advertise at time.
 * @param playMultiAds play all or one.
 */
-(void)setPlayerMultiAdWhenRun:(BOOL)playMultiAds;

/**
 * Get whether advertises isSkipAllAds.
 * @return isSkipAllAds.
 */
-(BOOL)isSkipAllAds;

/**
 * Get whether advertises isPlayMultiAds.
 * @return isPlayMultiAds.
 */
-(BOOL)isPlayMultiAds;

/**
 * Get number of viewers livestream source.
 * @return getLivestreamViewers.
 */
-(int)getLivestreamViewers;

/**
 * Get viewers livestream source asynchronous .
 * @param completionHandle is successed, number of viewers and exception.
 */
-(void)getLivestreamViewersWithCompletion:(void(^)(BOOL success, int viewers, NSError* err))completionHandle;

/**
 * Player whether play or pause in background mode.
 */
@property (nonatomic, setter=setIsPlayingOnBackground:) BOOL isPlayingOnBackground;

/**
 * Ads whether playing ad or pausing ad when showed.
 */
-(BOOL) isPlayingVideoAds;

/**
 * Ads set show and hide view.
 */
-(void)setShowHide:(AdViewTypez)viewType hide:(BOOL)hideView;

/**
 * Ads set image mute button view.
 */
-(void)setImageMute:(UIImage*)image;

/**
 * Call reload player.
 */
-(void)reloadPlayer;

/**
 * Player is playing live source.
 * @return isLiveSrc.
 */
-(BOOL)isLiveSrc;

/**
 * Player is stalled.
 * @return isStallVideo.
 */
-(BOOL)isStallVideo;

/**
 * Request ads asynchronous.
 * @param ad String of ad.
 * @param offset Time offset play ad.
 */
-(void)requestAdsAsync:(NSString*)ad offset:(int)offset;

/**
 * Remove player.
 * @param completion remove asynchronous.
 */
- (void)removePlayer:(void(^)(BOOL success))completion;

@end

