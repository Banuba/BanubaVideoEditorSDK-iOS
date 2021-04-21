//
//  BanubaSDKFrameworkInteractor.h
//  BanubaVideoEditorSDK
//
//  Created by Gleb Markin on 2/24/21.
//  Copyright © 2021 Banuba. All rights reserved.
//

@import BanubaSDKServicing;
@import AVKit;

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(BanubaSDKFrameworkInteractor)

// MARK: - Banuba Sdk framework interactor
__attribute__((weak_import)) @interface BanubaSDKFrameworkInteractor : NSObject

@property (strong, nonatomic)  id<CameraModule> cameraModule;

+ (BOOL)isFrameworkAvailable;

+ (void) initializeCameraModule: (NSString * _Nonnull) token
                      videoSize:(CGSize) videoSize
                    videoPreset:(AVCaptureSessionPreset _Nonnull) videoPreset
useHEVCCodecIfPossibleForRecorder:(BOOL) useHEVCCodecIfPossibleForRecorder
                    arCloudPath:(NSString * _Nullable) arCloudPath;

+ (id<CameraModule> _Nullable) getCameraModuleInstance;
+ (BOOL)isTokenExpired;

@end
NS_ASSUME_NONNULL_END
