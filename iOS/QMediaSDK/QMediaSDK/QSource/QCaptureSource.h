//
//  QCaptureSource.h
//  QMediaSDK
//
//  Created by spring on 20/05/2017.
//  Copyright © 2017 QMedia. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import "QMediaSource.h"
#import "VideoCaptureSession.h"

@interface QCaptureSource : NSObject<QMediaSource>

- (instancetype)initWithPreset:(AVCaptureSessionPreset)preset position:(AVCaptureDevicePosition)position;
@property (nonatomic, readonly) VideoCaptureSession* captureSession;

/**output target
 * MediaSource can adaptive by output target
 */
@property (nonatomic, weak) id<QVideoTarget> videoTarget;
@property (nonatomic, weak) id<QAudioTarget> audioTarget;

//media source describe
@property (nonatomic, readonly) QVideoDescribe* videoDesc;
@property (nonatomic, readonly) QAudioDescribe* audioDesc;

//after load, media describe is ready
- (bool)load;
- (void)unload;
- (bool)isInit;

//these methods called by mediaTrack
- (bool)start:(int64_t)startMSec end:(int64_t)endMSec;
- (void)stop;
- (bool)seekTo:(int64_t)mSec;
- (bool)isEOF;
- (bool)isStarted;
- (int64_t)getMediaDuration;

- (SampleBufferFrame)readNextVideoFrame;
- (SampleBufferFrame)readNextAudioFrame;

//for capture source
@property (nonatomic) bool enableVideo;
@property (nonatomic) bool enableAudio;

- (bool)swapFrontAndBackCameras;

@end
