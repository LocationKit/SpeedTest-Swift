//
// Created by SocialRadar
// Copyright (c) 2015 SocialRadar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>
#import "LKVisit.h"
#import "LKSearchRequest.h"
#import "LKSetting.h"
#import "LKVisitCriteria.h"
#import "LKPerson.h"

UIKIT_EXTERN NSString *const LKUserValueIdentifier;
UIKIT_EXTERN NSString *const LKUserValueName;
UIKIT_EXTERN NSString *const LKUserValueGender;
UIKIT_EXTERN NSString *const LKUserValueAge;
UIKIT_EXTERN NSString *const LKUserValueIncome;
UIKIT_EXTERN NSString *const LKUserValueOccupation;
UIKIT_EXTERN NSString *const LKUserValueMaritalStatus;
UIKIT_EXTERN NSString *const LKUserValueHasInAppPurchases;
UIKIT_EXTERN NSString *const LKUserValueInAppPurchaseTotal;
UIKIT_EXTERN NSString *const LKUserValueDateInstalled;

UIKIT_EXTERN NSString *const LKOptionWhenInUseOnly;
UIKIT_EXTERN NSString *const LKOptionUseiOSMotionActivity;
UIKIT_EXTERN NSString *const LKOptionTimedUpdatesInterval;


typedef NS_OPTIONS(NSUInteger, LKActivityMode) {
    LKActivityModeUnknown,
    LKActivityModeStationary,
    LKActivityModeWalking,
    LKActivityModeRunning,
    LKActivityModeCycling,
    LKActivityModeAutomotive
};


@protocol LocationKitDelegate;


@interface LocationKit : NSObject

@property(nonatomic, readonly) BOOL isRunning;

@property(nonatomic, readonly) NSString *deviceId;

@property(nonatomic, readonly) NSString *version;

@property(nonatomic, copy) void (^getCurrentLocationCallback)(CLLocation *, NSError *);


@property(nonatomic) NSNumber *debugMode;

@property(nonatomic, strong) NSNumber *debugMoved;

+ (LocationKit *)sharedInstance;

- (instancetype)init __attribute__((unavailable("init not available")));


- (void)startWithApiToken:(NSString *)token delegate:(id <LocationKitDelegate>)delegate;

- (void)startWithApiToken:(NSString *)token delegate:(id <LocationKitDelegate>)delegate options:(NSDictionary *)options;

- (void)handleAppLaunch:(NSString *)token delegate:(id <LocationKitDelegate>)delegate;


- (void)getCurrentPlaceWithHandler:(void (^)(LKPlace *place, NSError *error))handler;

- (void)getPlaceForLocation:(CLLocation *)location withHandler:(void (^)(LKPlace *place, NSError *error))handler;

- (void)getCurrentLocationWithHandler:(void (^)(CLLocation *location, NSError *error))handler;


- (void)searchForPlacesWithRequest:(LKSearchRequest *)request completionHandler:(void (^)(NSArray *places, NSError *error))handler;

- (void)getPeopleAtCurrentVenue:(void (^)(NSArray *people, LKVenue *venue, NSError *error))handler;

- (void)getPeopleNearby:(void (^)(NSArray *people, NSError *error))handler;

- (void)getPriorVisits:(void (^)(NSArray *visits, NSError *error))handler;

- (void)getHome:(void (^)(LKAddress *, NSError *))handler;

- (void)getWork:(void (^)(LKAddress *, NSError *))handler;

- (void)optOut:(void (^)( NSError *))handler;

/*
 *  updateUserValues:
 *
 *  Discussion:
 *      Update user values. Use LKUserValue constants as dictionary keys.
 *
 */
- (void)updateUserValues:(NSDictionary *)userValues;


- (void)setOperationMode:(LKSetting *)setting;

- (NSArray *)visitCriteria;

- (void)setVisitCriteria:(NSArray *)visitCriteria;


- (void)pause;

- (NSError *)resume;

@end


@protocol LocationKitDelegate <NSObject>

@optional

- (void)locationKit:(LocationKit *)locationKit didUpdateLocation:(CLLocation *)location;

- (void)locationKit:(LocationKit *)locationKit didEndVisit:(LKVisit *)visit;

- (void)locationKit:(LocationKit *)locationKit didStartVisit:(LKVisit *)visit;

- (void)locationKit:(LocationKit *)locationKit didFailWithError:(NSError *)error;

- (void)locationKit:(LocationKit *)locationKit willChangeActivityMode:(LKActivityMode)mode;

- (void)locationKit:(LocationKit *)locationKit changeRegion:(NSString *)obj;

@end