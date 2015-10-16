//
// Created by SocialRadar on 8/18/15.
// Copyright (c) 2015 SocialRadar. All rights reserved.
//

#import <Foundation/Foundation.h>


extern NSUInteger const kLKRadiusNone ;
extern NSUInteger const kLKRadiusHundredMeters;


@interface LKVisitCriteria : NSObject<NSCoding>


+ (LKVisitCriteria *)anyVenue;

@property (nonatomic) BOOL anyVenue;
@property(nonatomic, copy) NSString *venueCategory;
@property(nonatomic, copy) NSString *venueName;
@property(nonatomic, copy) NSString *addressId;

@property(nonatomic) double radius;

- (id)initWithJson:(NSDictionary *)dictionary;
@end