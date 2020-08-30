#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

/// Player events constants
//static NSString *SHPlayerEventCanplay = @"canplay";
//static NSString *SHPlayerEventDurationChange = @"durationchange";
//static NSString *SHPlayerEventLoadedMetadata = @"loadedmetadata";
//static NSString *SHPlayerEventPlay = @"play";
//static NSString *SHPlayerEventPause = @"pause";
//static NSString *SHPlayerEventEnded = @"ended";
//static NSString *SHPlayerEventSeeking = @"seeking";
//static NSString *SHPlayerEventSeeked = @"seeked";
//static NSString *SHPlayerEventTimeupdate = @"timeupdate";
//static NSString *SHPlayerEventProgress = @"progress";
//static NSString *SHPlayerEventToggleFullScreen = @"toggleFullscreen";
//
///// Key names of the video request
//static NSString *SHPlayerDatasourceWidKey = @"wid";
//static NSString *SHPlayerDatasourceUiConfIdKey = @"uiconf_id";
//static NSString *SHPlayerDatasourceCacheStKey = @"cache_st";
//static NSString *SHPlayerDatasourceEntryId = @"entry_id";
//static NSString *SHPlayerDatasourcePlayerIdKey = @"playerId";
//static NSString *SHPlayerDatasourceUridKey = @"urid";
//static NSString *SHPlayerDatasourceDebugKey = @"debug";
//static NSString *SHPlayerDatasourceForceHtml5Key = @"forceMobileHTML5";
//
//typedef enum{
//    // Player Content Source Url
//    src = 0,
//    // Player Current time (Progress Bar)
//    currentTime,
//    // Player Visibility
//    visible,
//    // Player Error
//    playerError,
//    // DRM license uri
//    licenseUri,
//    fpsCertificate,
//    nativeAction,
//    doubleClickRequestAds,
//    language,
//    captions
//} Attribute;

@protocol SHPlayerDelegate;

@protocol SHPlayer <NSObject>

@property (nonatomic, weak) id<SHPlayerDelegate> delegate;
//@property (nonatomic, copy) NSURL *playerSource;
@property (nonatomic) NSTimeInterval currentPlaybackTime;
@property (nonatomic) NSTimeInterval duration;
@property (nonatomic) float volume NS_AVAILABLE(10_7, 7_0);
@property (nonatomic, getter=isMuted) BOOL mute NS_AVAILABLE(10_7, 7_0);
@property (nonatomic, readonly) BOOL isSHPlayer;
@property (nonatomic, readonly) BOOL isPlaying;
@property (nonatomic) BOOL isCheckAuthen;
@property (nonatomic, readonly) BOOL isReplay;
@property (nonatomic) BOOL autoPlay;
@property (nonatomic, readonly) BOOL isStallPlayer;
@property (nonatomic) NSURL* currentPlayerSource;
@property (nonatomic) NSString* currentVid;

//- (void)setCurrentPlaybackTime:(NSTimeInterval)currentPlaybackTime enableUpdate:(BOOL)enableUpdate;
- (instancetype)initWithParentView:(UIView *)parentView;
- (void)setPlayerSource:(NSURL *)playerSource vid:(NSString*)vid;
- (NSURL *)playerSource;
- (void)play;
- (void)pause;
//- (void)changeRatePlayer:(float)rate;
- (void)replay:(BOOL)autoPlay;
- (void)removePlayer;
- (void)updateCurrentTime:(NSTimeInterval )time;
- (void)setlayerGravity:(AVLayerVideoGravity)gravity;
- (void)reload;
- (void)backTo2SecondsPlayer:(float)currentPlaybackTime;
- (BOOL)isLiveSrc;
//- (void)checkReauthenPlayer:(void(^)(int code,NSString* message))completion;
//-(void)pauseWithoutLog;
-(NSInteger)getDropFrames;
//-(void)playWithoutLog;

@optional

//- (void)enableTracks:(BOOL)isEnablingTracks;
//+ (BOOL)isPlayableMIMEType:(NSString *)mimeType;
//- (void)changeSubtitleLanguage:(NSString *)languageCode;
//- (void)setSourceWithAsset:(AVURLAsset*)asset;
//- (void)hidePlayer;
- (UIImage *)screenshotFromPlayer;
- (NSString*)getImageByAPI:(int)second error:(NSError**)error;
@end

@protocol SHPlayerDelegate <NSObject>

- (void)player:(id<SHPlayer>)currentPlayer eventName:(NSString *)event value:(NSString *)value error:(NSError *)error;
- (void)player:(id<SHPlayer>)currentPlayer eventName:(NSString *)event JSON:(NSString *)jsonString;
- (void)contentCompleted:(id<SHPlayer>)currentPlayer;
- (BOOL)isAdPlaying;
@end

