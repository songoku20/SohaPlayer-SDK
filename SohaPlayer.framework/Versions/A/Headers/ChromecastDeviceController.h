// Copyright 2014 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and

@import Foundation;

/**
 * @enum SHGCConnectionState
 * Enum defining GCKDeviceManager connection states.
 */
typedef NS_ENUM(NSInteger, SHGCConnectionState) {
    /** Disconnected from the device or application. */
    SHGCConnectionStateDisconnected = 0,
    /** Connecting to the device or application. */
    SHGCConnectionStateConnecting = 1,
    /** Connected to the device or application. */
    SHGCConnectionStateConnected = 2,
    /** Disconnecting from the device. */
    SHGCConnectionStateDisconnecting = 3
};

/**
 * @enum SHGCMediaStreamType
 * Enum defining the media stream type.
 */
typedef NS_ENUM(NSInteger, SHGCMediaStreamType) {
    /** A stream type of "none". */
    SHGCMediaStreamTypeNone = 0,
    /** A buffered stream type. */
    SHGCMediaStreamTypeBuffered = 1,
    /** A live stream type. */
    SHGCMediaStreamTypeLive = 2,
    /** An unknown stream type. */
    SHGCMediaStreamTypeUnknown = 99,
};

/**
 * @enum SHGCErrorCode
 * Description of error codes
 */
typedef NS_ENUM(NSInteger, SHGCErrorCode) {
    /**
     * Error Code indicating no error.
     */
    SHGCErrorCodeNoError = 0,
    
    /**
     * Error code indicating a network I/O error.
     */
    SHGCErrorCodeNetworkError = 1,
    
    /**
     * Error code indicating that an operation has timed out.
     */
    SHGCErrorCodeTimeout = 2,
    
    /**
     * Error code indicating an authentication error.
     */
    SHGCErrorCodeDeviceAuthenticationFailure = 3,
    
    /**
     * Error code indicating that an invalid request was made.
     */
    SHGCErrorCodeInvalidRequest = 4,
    
    /**
     * Error code indicating that an in-progress request has been cancelled, most likely because
     * another action has preempted it.
     */
    SHGCErrorCodeCancelled = 5,
    
    /**
     * Error code indicating that a request has been replaced by another request of the same type.
     */
    SHGCErrorCodeReplaced = 6,
    
    /**
     * Error code indicating that the request was disallowed and could not be completed.
     */
    SHGCErrorCodeNotAllowed = 7,
    
    /**
     * Error code indicating that a request could not be made because the same type of request is
     * still in process.
     */
    SHGCErrorCodeDuplicateRequest = 8,
    
    /**
     * Error code indicating that the request is not allowed in the current state.
     */
    SHGCErrorCodeInvalidState = 9,
    
    /**
     * Error code indicating that a requested application could not be found.
     */
    SHGCErrorCodeApplicationNotFound = 20,
    
    /**
     * Error code indicating that a requested application is not currently running.
     */
    SHGCErrorCodeApplicationNotRunning = 21,
    
    /**
     * Error code indicating that the application session ID was not valid.
     */
    SHGCErrorCodeInvalidApplicationSessionID = 22,
    
    /**
     * Error code indicating that a media load failed on the receiver side.
     */
    SHGCErrorCodeMediaLoadFailed = 30,
    
    /**
     * Error code indicating that a media media command failed because of the media player state.
     */
    SHGCErrorCodeInvalidMediaPlayerState = 31,
    
    /**
     * Error code indicating the app entered the background.
     */
    SHGCErrorCodeAppDidEnterBackground = 91,
    
    /**
     * Error code indicating a disconnection occurred during the request.
     */
    SHGCErrorCodeDisconnected = 92,
    
    /**
     * Error code indicating that an unknown, unexpected error has occurred.
     */
    SHGCErrorCodeUnknown = 99,
};


/**
 * @enum SHGCMediaPlayerIdleReason
 * Media player idle reasons.
 */
typedef NS_ENUM(NSInteger, SHGCMediaPlayerIdleReason) {
    /** Constant indicating that the player currently has no idle reason. */
    SHGCMediaPlayerIdleReasonNone = 0,
    
    /** Constant indicating that the player is idle because playback has finished. */
    SHGCMediaPlayerIdleReasonFinished = 1,
    
    /**
     * Constant indicating that the player is idle because playback has been cancelled in
     * response to a STOP command.
     */
    SHGCMediaPlayerIdleReasonCancelled = 2,
    
    /**
     * Constant indicating that the player is idle because playback has been interrupted by
     * a LOAD command.
     */
    SHGCMediaPlayerIdleReasonInterrupted = 3,
    
    /** Constant indicating that the player is idle because a playback error has occurred. */
    SHGCMediaPlayerIdleReasonError = 4,
};


typedef NS_ENUM(NSInteger, SHGCMediaPlayerState) {
    /** Constant indicating unknown player state. */
    SHGCMediaPlayerStateUnknown = 0,
    /** Constant indicating that the media player is idle. */
    SHGCMediaPlayerStateIdle = 1,
    /** Constant indicating that the media player is playing. */
    SHGCMediaPlayerStatePlaying = 2,
    /** Constant indicating that the media player is paused. */
    SHGCMediaPlayerStatePaused = 3,
    /** Constant indicating that the media player is buffering. */
    SHGCMediaPlayerStateBuffering = 4,
};


@protocol SHGCDevice <NSObject>
@property(nonatomic, copy) NSString *deviceID;
@property(nonatomic, copy) NSString *friendlyName;
@property(nonatomic, copy, readonly) NSString *ipAddress;
@property(nonatomic, readonly) UInt32 servicePort;
@end

@protocol SHGCMediaInformation;
@protocol SHGCMediaStatus <NSObject>
@property(nonatomic, readonly) SHGCMediaPlayerState playerState;
@property(nonatomic, readonly) SHGCMediaPlayerIdleReason idleReason;
@property(nonatomic, strong, readonly) id<SHGCMediaInformation> mediaInformation;
@end

@protocol SHGCMediaControlChannel <NSObject>
@property(nonatomic, strong, readonly) id<SHGCMediaStatus> mediaStatus;
@property(nonatomic, weak) id delegate;
- (NSTimeInterval)approximateStreamPosition;
- (NSInteger)seekToTimeInterval:(NSTimeInterval)position;
- (NSInteger)requestStatus;
- (NSInteger)loadMedia:(id<SHGCMediaInformation>)mediaInfo
              autoplay:(BOOL)autoplay
          playPosition:(NSTimeInterval)playPosition;
- (void)play;
- (void)pause;
@end

@protocol SHGCCastChannel <NSObject>


@end

@protocol SHGCDeviceManager <NSObject>
@property(nonatomic, readonly) id<SHGCDevice> device;
@property(nonatomic, weak) id delegate;
@property(nonatomic, readonly) SHGCConnectionState applicationConnectionState;
- (instancetype)initWithDevice:(id<SHGCDevice>)device clientPackageName:(NSString *)clientPackageName;
- (NSInteger)stopApplicationWithSessionID:(NSString *)sessionID;
- (void)connect;
- (void)disconnect;
- (NSInteger)launchApplication:(NSString *)applicationID;
- (BOOL)addChannel:(id<SHGCMediaControlChannel>)channel;
@end

@protocol SHGCDeviceScannerListener;

@protocol SHGCDeviceScanner <NSObject>
- (void)addListener:(id<SHGCDeviceScannerListener>)listener;
@property(nonatomic, readonly, copy) NSArray *devices;
- (void)startScan;
@end

@protocol SHGCMediaMetadata <NSObject>
- (NSString *)stringForKey:(NSString *)key;
@end

@protocol SHGCMediaInformation <NSObject>
@property(nonatomic, strong, readonly) id<SHGCMediaMetadata> metadata;
@property(nonatomic, readonly) NSTimeInterval streamDuration;
@property(nonatomic, copy, readonly) NSString *contentID;
@property(nonatomic, copy, readonly) NSString *contentType;
- (instancetype)initWithContentID:(NSString *)contentID
                       streamType:(SHGCMediaStreamType)streamType
                      contentType:(NSString *)contentType
                         metadata:(id<SHGCMediaMetadata>)metadata
                   streamDuration:(NSTimeInterval)streamDuration
                       customData:(id)customData;
@end



@protocol SHGCApplicationMetadata <NSObject>
@property(nonatomic, strong, readonly) id<SHGCMediaMetadata> metadata;
@end

@protocol SHGCError <NSObject>
@property (readonly) NSInteger code;
@end




@protocol SHGCDeviceScannerListener <NSObject>

@optional

/**
 * Called when a device has been discovered or has come online.
 *
 * @param device The device.
 */
- (void)deviceDidComeOnline:(id<SHGCDevice>)device;

/**
 * Called when a device has gone offline.
 *
 * @param device The device.
 */
- (void)deviceDidGoOffline:(id<SHGCDevice>)device;

/**
 * Called when there is a change to one or more properties of the device that do not affect
 * connectivity to the device. This includes all properties except the device ID, IP address,
 * and service port; if any of these properties changes, the device will be reported as "offline"
 * and a new device with the updated properties will be reported as "online".
 *
 * @param device The device.
 */
- (void)deviceDidChange:(id<SHGCDevice>)device;

@end
// limitations under the License.

#import <Foundation/Foundation.h>

extern NSString * const kCastViewController;

@protocol ChromecastDeviceControllerDelegate <NSObject>

@optional

/**
 * Called when connection to the device was established.
 *
 * @param device The device to which the connection was established.
 */
- (void)didConnectToDevice:(id<SHGCDevice>)device;

/**
 *  Called when the device disconnects.
 */
- (void)didDisconnect;

/**
 * Called when Cast devices are discoverd on the network.
 */
- (void)didDiscoverDeviceOnNetwork;

/**
 * Called when Cast device is connecting
 */
- (void)castConnectingToDevice;

/**
 * Called when a request to load media has completed.
 */
- (void)didCompleteLoadWithSessionID:(NSInteger)sessionID;

/**
 * Called when updated player status information is received.
 */
- (void)didUpdateStatus:(id<SHGCMediaControlChannel>)mediaControlChannel;

@end

@interface ChromecastDeviceController : NSObject <
    SHGCDeviceScannerListener
>

/**
 *  The storyboard contianing the Cast component views used by the controllers in
 *  the CastComponents group.
 */
//@property(nonatomic, readonly) UIStoryboard *storyboard;

/**
 *  The delegate for this object.
 */
@property(nonatomic, weak) id<ChromecastDeviceControllerDelegate> delegate;

/**
 *  The Cast application ID to launch.
 */
@property(nonatomic, copy) NSString *applicationID;

/**
 *  The device manager used to manage a connection to a Cast device.
 */
@property(nonatomic, strong) id<SHGCDeviceManager> deviceManager;

/**
 *  The device scanner used to detect devices on the network.
 */
@property(nonatomic, strong) id<SHGCDeviceScanner> deviceScanner;

/**
 *  The media information of the loaded media on the device.
 */
@property(nonatomic, strong) id<SHGCMediaInformation> mediaInformation;

/** 
 *  The media control channel for the playing media. 
 */
@property (nonatomic, strong) id<SHGCMediaControlChannel> mediaControlChannel;

/**
 *  Helper accessor for the media player state of the media on the device.
 */
@property(nonatomic, readonly) SHGCMediaPlayerState playerState;

/**
 * The current idle reason. This value is only meaningful if the player state is
 * SHGCMediaPlayerStateIdle.
 */
@property(nonatomic, readonly) SHGCMediaPlayerIdleReason idleReason;

/**
 *  Helper accessor for the duration of the currently casting media.
 */
@property(nonatomic, readonly) NSTimeInterval streamDuration;

/**
 *  The current playback position of the currently casting media.
 */
@property(nonatomic, readonly) NSTimeInterval streamPosition;

/**
 *  Main access point for the class. Use this to retrieve an object you can use.
 *
 *  @return ChromecastDeviceController
 */
+ (instancetype)sharedInstance;

/**
 *  Sets the position of the playback on the Cast device.
 *
 *  @param newPercent 0.0-1.0
 */
- (void)setPlaybackPercent:(float)newPercent;

/**
 *  Connect to the given Cast device.
 *
 *  @param device A GCKDevice from the deviceScanner list.
 */
- (void)connectToDevice:(id<SHGCDevice>)device;

/**
 *  Load media onto the currently connected device.
 *
 *  @param media     The GCKMediaInformation to play, with the URL as the contentID
 *  @param startTime Time to start from if starting a fresh cast
 *  @param autoPlay  Whether to start playing as soon as the media is loaded.
 *
 *  @return YES if we can load the media.
 */
- (BOOL)loadMedia:(id<SHGCMediaInformation>)media
        startTime:(NSTimeInterval)startTime
         autoPlay:(BOOL)autoPlay;

/** 
 *  Enable Cast enhancing of the controller by adding icons
 *  and other UI elements. Signals that this view controller should be 
 *  used for presenting UI elements.
 *
 *  @param controller The UIViewController to decorate.
 */
//- (void)decorateViewController:(UIViewController *)controller;

/**
 *  Request an update for the minicontroller toolbar. Passed UIViewController must have a
 *  toolbar - for example if it is under a UINavigationBar.
 *
 *  @param viewController UIViewController to update the toolbar on.
 */
//- (void)updateToolbarForViewController:(UIViewController *)viewController;

/**
 *  Return the last known stream position for the given contentID. This will generally only
 *  be useful for the last Cast media, and allows a local player to resume playback at the
 *  position noted before disconnect. In many cases it will return 0.
 *
 *  @param contentID The string of the identifier of the media to be displayed.
 *
 *  @return the position in the stream of the media, if any.
 */
- (NSTimeInterval)streamPositionForPreviouslyCastMedia:(NSString *)contentID;

/**
 *  Prevent automatically reconnecting to the Cast device if we see it again.
 */
- (void)clearPreviousSession;

/**
 *  Enable basic logging of all GCKLogger messages to the console.
 */
- (void)enableLogging;

@end
