//
//  SHController.h
//  SohaPlayer
//
//  Created by Le Cuong on 10/14/16.
//  Copyright © 2016 Le Cuong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SHMediaPlayback.h"

// -----------------------------------------------------------------------------
// Media Player Types

typedef NS_ENUM(NSInteger, SHMediaPlaybackState) {
    SHMediaPlaybackStateUnknown,
    SHMediaPlaybackStateLoaded,
    SHMediaPlaybackStateReady,
    /* Playback is currently under way. */
    SHMediaPlaybackStatePlaying,
    /* Playback is currently paused. */
    SHMediaPlaybackStatePaused,
    /* Playback is currently ended. */
    SHMediaPlaybackStateEnded,
    /* Playback is temporarily interrupted, perhaps because the buffer ran out of content. */
    SHMediaPlaybackStateInterrupted,
    /* The movie player is currently seeking towards the end of the movie. */
    SHMediaPlaybackStateSeekingForward,
    /* The movie player is currently seeking towards the beginning of the movie. */
    SHMediaPlaybackStateSeekingBackward
};

///@todo
typedef NS_OPTIONS(NSUInteger, SHMediaLoadState) {
    /* The load state is not known. */
    SHMediaLoadStateUnknown        = 0,
    /* The buffer has enough data that playback can begin, but it may run out of data before playback finishes. */
    SHMediaLoadStatePlayable       = 1 << 0,
    /* Enough data has been buffered for playback to continue uninterrupted. */
    SHMediaLoadStatePlaythroughOK  = 1 << 1, // Playback will be automatically started in this state when shouldAutoplay is YES
    /* The buffering of data has stalled. */
    SHMediaLoadStateStalled        = 1 << 2, // Playback will be automatically paused in this state, if started
	/* Start buffering*/
	SHMediaLoadStateStartBuffering = 1 << 3,
	/* Stop buffering*/
	SHMediaLoadStateStopBuffering = 1 << 4,
};

// -----------------------------------------------------------------------------
// Media Player Notifications

/* Posted when the playback state changes, either programatically or by the user. */
extern NSString * const SHMediaPlaybackStateDidChangeNotification;

// -----------------------------------------------------------------------------
// Media Player Keys
extern NSString * const SHMediaPlaybackStateKey;

@protocol SHMediaPlayback;

@protocol SHControllerDelegate <NSObject>

/*!
 @method        sendSHNotification:withParams:
 @abstract      Call a KDP notification (perform actions using this API, for example: play, pause, changeMedia, etc.) (required)
 */

- (void)sendSHNotification:(NSString *)shNotificationName withParams:(NSString *)shParams;
- (void)sendSHNotification:(NSString *)shNotificationName params:(NSString *)shParams completionHandler:(void(^)())handler;
- (NSTimeInterval)duration;
- (NSTimeInterval)currentPlaybackTime;
- (float)volume;
- (void)setVolume:(float)value;
- (BOOL)mute;
- (void)setMute:(BOOL)isMute;

@end

@interface SHController : NSObject <SHMediaPlayback>

@property (nonatomic, weak) id<SHControllerDelegate> delegate;

/* The URL that points to the movie file. */
@property (nonatomic, copy) NSURL *contentURL;

/// @return Duration of the current video
@property (nonatomic, readonly) NSTimeInterval duration;
/* The volume of the player. */
@property (nonatomic) float volume NS_AVAILABLE(10_7, 7_0);
/* Mute or UnMute the player. */
@property (nonatomic, getter=isMuted) BOOL mute NS_AVAILABLE(10_7, 7_0);

/// Perfoms seek to the currentPlaybackTime and returns the currentPlaybackTime
@property (nonatomic) NSTimeInterval currentPlaybackTime;

/* The current playback state of the movie player. (read-only)
 The playback state is affected by programmatic calls to play, pause the SHPlayer. */
@property (nonatomic, readonly) SHMediaPlaybackState playbackState;
/* The current load state of the SHPlayer. (read-only). */
@property (nonatomic, readonly) SHMediaLoadState loadState;

- (void)seek:(NSTimeInterval)playbackTime;
- (void)seek:(NSTimeInterval)playbackTime completionHandler:(void(^)())handler;

@end

