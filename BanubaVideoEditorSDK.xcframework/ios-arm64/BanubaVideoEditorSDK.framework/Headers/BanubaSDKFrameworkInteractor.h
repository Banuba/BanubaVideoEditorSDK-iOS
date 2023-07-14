//
//  BanubaSDKFrameworkInteractor.h
//  BanubaVideoEditorSDK
//
//  Created by Gleb Markin on 2/24/21.
//  Copyright © 2021 Banuba. All rights reserved.
//

@import AVKit;

#include "VisualClipVideo.h"

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(BanubaSDKFrameworkInteractor)

// MARK: - Banuba Sdk framework interactor
__attribute__((weak_import)) @interface BanubaSDKFrameworkInteractor : NSObject

+ (BOOL)isFrameworkAvailable;

+ (void) initializeCameraModule: (NSString * _Nonnull) token
                      videoSize:(CGSize) videoSize
                    videoPreset:(AVCaptureSessionPreset _Nonnull) videoPreset
useHEVCCodecIfPossibleForRecorder:(BOOL) useHEVCCodecIfPossibleForRecorder
                    arCloudPath:(NSString * _Nullable) arCloudPath;

+ (id _Nullable) getCameraModuleInstance;
+ (id _Nullable) getMaskPostprocessingServiceWithVideoSize:(CGSize) videoSize;

+ (nullable NSArray<NSString *> *)createAutoCutVideosWithMusicPath:(NSString *)musicDbPath
                                                     visualEffects:(NSArray<NSString *> *)visualEffects
                                                 transitionEffects:(NSArray<NSString *> *)transitionEffects
                                                            videos:(NSArray<VisualClipVideo *> *)videos
                                                         numFrames:(int32_t)numFrames
                                                        resultSize:(int32_t)resultSize;


@end
NS_ASSUME_NONNULL_END
