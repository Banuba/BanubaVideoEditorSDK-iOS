//
//  AudioBrowserInteractor.h
//  BanubaVideoEditorSDK
//
//  Created by Gleb Markin on 2/22/21.
//  Copyright © 2021 Banuba. All rights reserved.
//

@import UIKit;
@import Foundation;
@import BanubaAudioBrowserSDK;

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(AudioBrowserTrackAdapter)

//MARK: - AudioBrowserTrackAdapter
__attribute__((weak_import)) @interface AudioBrowserTrackAdapter : NSObject <AudioBrowserTrackApplyable>
@property (readwrite, nonatomic) AudioBrowserTrack *track;
- (instancetype)init: (int32_t) trackId
                name: (NSString *) name
                 url: (NSURL * _Nullable) url;
@end
NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(AudioBrowserConfigAdapter)

//MARK: - AudioBrowserConfigAdapter
__attribute__((weak_import)) @interface AudioBrowserConfigAdapter : NSObject <AudioBrowserConfigApplyable>
@property (readwrite, nonatomic) AudioBrowserConfig *config;
- (instancetype)init;
@end
NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(AudioBrowserFrameworkInteractor)

// MARK: - Audio browser framework interactor
__attribute__((weak_import)) @interface AudioBrowserFrameworkInteractor : NSObject

@property (strong, nonatomic) BanubaAudioBrowser *audioBrowser;

+ (BOOL)isFrameworkAvailable;

- (instancetype)init: (AudioBrowserConfig *) audioBrowserConfig
  transitionDelegate: (id<UIViewControllerTransitioningDelegate>) transitionDelegate
        audioService: (id<AudioBrowserServiceAdoptable> _Nullable) audioService
       selectedTrack: (AudioBrowserTrack * _Nullable) selectedTrack;

-(EditorNavigationController * _Nullable) getAudioBrowserController;

@end
NS_ASSUME_NONNULL_END
