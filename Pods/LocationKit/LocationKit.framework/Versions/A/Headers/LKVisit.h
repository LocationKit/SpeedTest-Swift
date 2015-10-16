//
// Created by SocialRadar on 6/9/15.
// Copyright (c) 2015 SocialRadar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LKPlace.h"
#import "LKVisitCriteria.h"

@interface LKVisit : NSObject <NSCoding>

@property (nonatomic, strong) NSDate *arrivalDate;
@property (nonatomic, strong) NSDate *departureDate;
@property (nonatomic, strong) LKPlace *place;
@property (nonatomic, strong) LKVisitCriteria *criteria;

@end