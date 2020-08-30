//
//  SohaPlayerManager.h
//  SohaPlayer
//
//  Created by Hung Nguyen Thac on 10/10/18.
//  Copyright © 2018 Hung Nguyen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SohaPlayer/SHViewController.h"

//update seek from end video

//NS_ASSUME_NONNULL_BEGIN

typedef enum{
    NON_PERMISSION = -1,
    PERMISSION_ACCEPTED = 1,
    PERMISSION_DENIED = 0
} PermissionState;

typedef enum {
    MANIFEST_PERMISSION = 0,
    PLAYER_AUTHENTICATION = 1,
    PARAMESTER_REQUIRED = 2
} TypePlayerManagerError;

@protocol OnPreparePlayerManager <NSObject>

@optional

/**
 * Reponse when player manager start prepare
 */
-(void) onPrepare;

@optional

/**
 * Reponse when player start prepare and notify for user initializing player manager
 */
-(void) onInitializing;

@optional

/**
 * Reponse when create player managerment successfully
 */
-(void) onInitSuccessfully;

@optional

/**
 * Response error when initialize for player manager
 *
 * @param errorCode {{@see {@link PreparePlayerManagerErrorType }}}
 * @param message   Message for description of error
 */
-(void) onInitFailed:(NSInteger*)errorCode message:(NSString*)message;

@end

@interface SohaPlayerManager : NSObject

#pragma Method public for user
/**
 *Init instance of player manager and return singeton instance of player manager
 */
+(void) initialized:(id<OnPreparePlayerManager>) delegate;
/**
 * Shared instance of place
 */
+(SohaPlayerManager*) shared;
/**
 *Return your permission to using player
 */
-(BOOL) isAllowUsingPlayer;
/**
 * Return shared instance of playermanager, that's created before.
 */
-(SohaPlayerManager*)shared;
/**
 * Create player and return a new instance player
 */
-(SHViewController*)createPlayer:(UIView*)playerContainer;
/**
 * Get Player app key
 */
-(NSString*)getAppKey;
/**
 * Get Player secret key
 */
-(NSString*)getSecretKey;
/**
 * Get Player player id
 */
-(NSString*)getPlayerId;
/**
 * set Player manager delegate when player manager initialized
 */
-(void)setOnPlayerPrepare:(id<OnPreparePlayerManager>)reponse;

-(PermissionState)getPermissionPlayer;

-(void)authenPlayerSynchronous:(void(^)(int code,NSString* message))completion;

-(void)getBandwidth;

-(void)removeDelegateGetBandwidth;

@property (nonatomic, readonly) float speed;

@property (nonatomic, readonly) BOOL isGettingBandwidth;
@end

//NS_ASSUME_NONNULL_END

