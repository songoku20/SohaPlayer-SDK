//
//  SHViewController.h
//  SohaPlayer
//
//  Created by Le Cuong on 10/14/16.
//  Copyright © 2016 Le Cuong. All rights reserved.
//


@protocol SohaPlayer;

#import "SHLog.h"
#import "SHViewControllerProtocols.h"
#import "SHPlayerConfig.h"
#import "SHController.h"
#import "ControlsPlayer.h"

@class SHViewController;
@protocol SHViewControllerDelegate <NSObject>

@optional
- (void)updateCurrentPlaybackTime:(double)currentPlaybackTime;
- (void)updateCurrentPlayloadTime:(double)currentPlayloadTime;
- (void)SHPlayer:(SHViewController *)player playerLoadStateDidChange:(SHMediaLoadState)state;
- (void)SHPlayer:(SHViewController *)player playerPlaybackStateDidChange:(SHMediaPlaybackState)state;
- (void)SHPlayer:(SHViewController *)player playerFullScreenToggled:(BOOL)isFullScreen;
- (void)SHPlayer:(SHViewController *)player didFailWithError:(NSError *)error;
@end

@protocol SHSourceURLProvider <NSObject>

- (NSString *)urlForEntryId:(NSString *)entryId currentURL:(NSString*)current;

@end

#import "ChromecastDeviceController.h"


@interface SHViewController : UIViewController

@property (nonatomic,strong) id<ControlsPlayerDelegate> controllerDelegate;

+ (void)setLogLevel:(SHLogLevel)logLevel;

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

@property (nonatomic, weak) id<SHViewControllerDelegate> delegate;

@property (nonatomic, weak) id<SHSourceURLProvider> customSourceURLProvider;

@property (nonatomic, strong) SHController *playerController;

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
@property (nonatomic, readonly) id<SHPlayer> SHPlayer;


- (void)registerReadyEvent:(void(^)(void))handler;



- (void)addSHPlayerEventLvoidistener:(NSString *)event eventID:(NSString *)eventID handler:(void(^)(NSString *eventName, NSString *params))handler;



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

/* The device manager used for the currently casting media. */
@property(weak, nonatomic) ChromecastDeviceController *castDeviceController;

@property (nonatomic) BOOL showControls;

@property (nonatomic) BOOL autoPlay;

@end

