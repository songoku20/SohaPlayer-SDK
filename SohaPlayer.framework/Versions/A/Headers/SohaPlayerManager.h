//
//  SohaPlayerManager.h
//  SohaPlayer
//
//  Created by Le Minh Son on 10/10/18.
//  Copyright © 2018 Le Cuong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SHViewController/SHViewController.h"

NS_ASSUME_NONNULL_BEGIN

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

/**
 * Reponse when player start prepare and notify for user initializing player manager
 */
-(void) onInitializing;

/**
 * Reponse when create player managerment successfully
 */
-(void) onInitSuccessfully;

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
     * Return list mapping of player is created by user
     */
    -(NSMutableDictionary*)getListPlayer;
    /**
     * Create player and return a new instance player
     */
    -(SHViewController*)createPlayer:(UIView*)playerContainer;
    /**
     * Destroy player by key
     */
    -(BOOL)destroyPlayerByKey:(NSString*)playerKey;
    /**
     * Destroy all player
     */
    -(BOOL)destroyAllPlayer;
    /**
     * Key of player
     */
    -(NSString*)getKeyOfPlayer:(SHViewController*)playerController;
    /**
     * Get player by key
     */
    -(SHViewController*)getPlayerByKey:(NSString*)playerKey;
    /**
     *Destroy instance of player on list
     */
    -(void)destroyPlayer:(SHViewController*) playerController;
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

@end

NS_ASSUME_NONNULL_END

