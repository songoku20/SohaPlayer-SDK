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
#import "SHAdManager.h"
// -----------------------------------------------------------------------------
// Media Player Types

typedef NS_ENUM(NSInteger, SHMediaPlaybackState) {
    SHMediaPlaybackStateUnknown = 0,
    SHMediaPlaybackStateLoaded = 1,
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
    SHMediaPlaybackStateSeekingBackward = 8
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


extern NSString * const SHMediaPlaybackStateDidChangeNotification;

// -----------------------------------------------------------------------------
// Media Player Keys
extern NSString * const SHMediaPlaybackStateKey;

@class SHViewController;
@protocol SHViewControllerDelegate <NSObject>

@optional
- (void)updateCurrentPlaybackTime:(double)currentPlaybackTime;
- (void)updateCurrentPlayloadTime:(double)currentPlayloadTime;
- (void)SHPlayer:(SHViewController *)player playerLoadStateDidChange:(SHMediaLoadState)state;
- (void)SHPlayer:(SHViewController *)player playerPlaybackStateDidChange:(SHMediaPlaybackState)state;
- (void)SHPlayer:(SHViewController *)player playerFullScreenToggled:(BOOL)isFullScreen;
- (void)SHPlayer:(SHViewController *)player didFailWithError:(NSError *)error;
- (void)onAdsEventListener:(NSString*)event;
- (void)onAdsProgressListener:(float)mediaTime totalTime:(float)totalTime;
@end

@interface SHViewController : UIViewController

/// @return Duration of the current video
-(NSTimeInterval) duration;
/* The volume of the player. */
-(float) volume;
/* state mute or unmute of the player. */
-(BOOL) isMuted;
/* set mute or unmute of the player. */
-(void)setMute:(BOOL)isMute ;
/*Return state of player*/
-(BOOL)isplaying;

/// Perfoms seek to the currentPlaybackTime and returns the currentPlaybackTime
-(NSTimeInterval) currentPlaybackTime;

/* The current playback state of the movie player. (read-only)
 The playback state is affected by programmatic calls to play, pause the SHPlayer. */
/* The current load state of the SHPlayer. (read-only). */
//-(SHMediaLoadState) loadState;
//-(SHMediaPlaybackState) playbackState;
//@property (nonatomic) SHMediaLoadState loadState;

-(SHMediaPlaybackState)getPlaybackState;

- (void)play;

- (void)replay:(BOOL)autoPlay;

- (void)pause;

- (void)seekFloat:(float)value;

- (void)seek:(NSTimeInterval)value;

- (void)setConfiguration:(SHPlayerConfig *)configuration;

- (void)loadPlayerIntoViewController:(UIViewController *)parentViewController;

- (void)removePlayer;

- (void)resetPlayer;

- (void)changeMedia:(NSString *)entryID;

- (void)changeConfiguration:(SHPlayerConfig *)config;

-(void)setPlayerContainer:(UIView*)viewContainer;

-(void)setPlayerKey:(NSString*) key;

- (BOOL)isFullscreen;

- (void)toggleFullscreen;

-(NSString*) getPlayerKey;

-(NSURL*)getURLPlayer;

-(void)deleteAllLogFile;

-(void)deleteLogFileByName:(NSString*)name;

@property (nonatomic, readonly) NSString* logDir;

@property (nonatomic) NSDictionary* extraLog;

- (UIImage *)screenshotFromPlayer;

- (NSString*)getImageByAPI:(int)second error:(NSError**)error;

@property (nonatomic, weak) id<SHViewControllerDelegate> delegate;

/**
 *  Block which notifies that the full screen has been toggeled, when assigning to this block the default full screen behaviour will be canceled and the full screen handling will be your reponsibility. 
 */
@property (nonatomic, copy) void(^fullScreenToggeled)(BOOL isFullScreen);


/// Enables to change the player configuration
@property (nonatomic, strong) SHPlayerConfig *currentConfiguration;

/// Change the source and returns the current source
@property (nonatomic, copy) NSURL *playerSource;

/// Signals that a internal or external web browser has been opened or closed
@property (nonatomic, weak) id kIMAWebOpenerDelegate;

/// Assigning this handler will disable the default share action and will supply the share params for custom use.
- (void)setShareHandler:(void(^)(NSDictionary *shareParams))shareHandler;

- (void)setduration:(NSString*)duration currentTime:(NSString*)currentTime;


#pragma mark - KDPAPIState
// -----------------------------------------------------------------------------
// KDP API Types

typedef NS_ENUM(NSInteger, KDPAPIState) {
    /*  Player is not ready to work with the JavaScript API. */
    KDPAPIStateUnknown,
    /*  Player is ready to work with the JavaScript API (jsCallbackReady). */
    KDPAPIStateReady
};

/* The current kdp api state of the KDP API. (read-only)
 The kdp api state is affected by programmatic call to jsCallbackReady. */
@property (nonatomic, readonly) KDPAPIState kdpAPIState;

/*!
	@property	SHPlayer
	@abstract	The player from which to source the media content for the view controller.
 */
//@property (nonatomic, readonly) id<SHPlayer> SHPlayer;


- (void)registerReadyEvent:(void(^)(void))handler;



//- (void)addSHPlayerEventLvoidistener:(NSString *)event eventID:(NSString *)eventID handler:(void(^)(NSString *eventName, NSString *params))handler;



- (void)removeSHPlayerEventListener:(NSString *)event eventID:(NSString *)eventID;




- (void)asyncEvaluate:(NSString *)expression expressionID:(NSString *)expressionID handler:(void(^)(NSString *value))handler;



- (void)sendNotification:(NSString *)notificationName withParams:(NSString *)params;




- (void)setKDPAttribute:(NSString *)pluginName propertyName:(NSString *)propertyName value:(NSString *)value;



- (void)triggerEvent:(NSString *)event
           withValue:(NSString *)value;

- (void)releaseAndSavePosition;
- (void)resumePlayer;


/// Wraps registerReadyEvent: method by block syntax.
@property (nonatomic, copy) void (^registerReadyEvent)(void(^readyCallback)(void));

/// Wraps addEventListener:eventIDvoid:handler: method by block syntax.
@property (nonatomic, copy, readonly) void (^addEventListener)(NSString *event, NSString *eventID, void(^)(NSString *eventName, NSString *params));

/// Wraps removeEventListener:eventID: method by block syntax.
@property (nonatomic, copy, readonly) void (^removeEventListener)(NSString *event, NSString *eventID);

/// Wraps asyncEvaluate:expressionID:handler: method by block syntax.
@property (nonatomic, copy, readonly) void (^asyncEvaluate)(NSString *expression, NSString *expressionID, void(^)(NSString *value));

/// Wraps sendNotification:expressionID:forName: method by block syntax.
@property (nonatomic, copy, readonly) void (^sendNotification)(NSString *notification, NSString *notificationName);

/// Wraps setKDPAttribute:propertyName:value: method by block syntax.
@property (nonatomic, copy, readonly) void (^setKDPAttribute)(NSString *pluginName, NSString *propertyName, NSString *value);

/// Wraps triggerEvent:withValue: method by block syntax.
@property (nonatomic, copy, readonly) void (^triggerEvent)(NSString *event, NSString *value);

@property (nonatomic) BOOL showControls;

@property (nonatomic) BOOL autoPlay;

-(void)pauseAds;

-(void)playAds;

-(BOOL)isPlayingAd;

-(void)setIMAEventDelegate:(id)delegate;

@end

