//
//  QMediaTrack.h
//  QMediaSDK
//
//  Created by spring on 20/05/2017.
//  Copyright © 2017 QMedia. All rights reserved.
//

#import "QMediaSource.h"
#import "QGraphicNode.h"
#import "QAudioNode.h"

@interface QMediaTrack : NSObject

- (instancetype)initWithMediaSource:(id<QMediaSource>)mediaSource;
- (bool) prepare;
- (bool) setTimeTo:(int)mSec;//set read position to designated location
- (void) stopMedia;//stop

- (bool)isPrepare;
- (float)getPlaySpeed;
- (int64_t)getSourceDuration;

- (NSRange)getDisplayTrackRange;
- (void)setDisplayTrackRange:(NSRange)range;
- (void)setSourceRange:(NSRange)range;

@property (nonatomic) float timeScale;
@property (nonatomic) int repeatTimes;
@property (nonatomic, readonly) id<QMediaSource> source;
@property (nonatomic, readonly) QGraphicNode* graphic;
@property (nonatomic, readonly) QAudioNode* audio;

@end
