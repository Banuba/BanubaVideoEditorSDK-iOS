//
//  BanubaSDKSimpleInteractor.h
//  BanubaVideoEditorSDK
//
//  Created by Andrei Sak on 31.08.23.
//  Copyright © 2023 Banuba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVKit/AVKit.h>

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(BanubaSDKSimpleInteractor)

// MARK: - Banuba SDK Simple framework interactor
__attribute__((weak_import)) @interface BanubaSDKSimpleInteractor : NSObject

+ (id _Nullable) getCameraModuleInstanceWithVideoSize:(CGSize) videoSize
                                          videoPreset:(AVCaptureSessionPreset _Nonnull) videoPreset
                    useHEVCCodecIfPossibleForRecorder:(BOOL) useHEVCCodecIfPossibleForRecorder;

@end

NS_ASSUME_NONNULL_END
