//
//  AudioBrowserInteractor.h
//  BanubaVideoEditorSDK
//
//  Created by Gleb Markin on 2/22/21.
//  Copyright © 2021 Banuba. All rights reserved.
//

@import UIKit;
@import Foundation;
@import BanubaMusicEditorSDK;

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(AudioBrowserTrackWrapper)

//MARK: - AudioBrowserTrackAdapter
__attribute__((weak_import)) @interface AudioBrowserTrackWrapper : NSObject

@property (nonatomic) int32_t trackId;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSURL *url;

- (instancetype)init: (int32_t) trackId
                name: (NSString *) name
                 url: (NSURL * _Nullable) url;
@end
NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(AudioBrowserFrameworkInteractor)

// MARK: - Audio browser framework interactor
__attribute__((weak_import)) @interface AudioBrowserFrameworkInteractor : NSObject

+ (BOOL)isFrameworkAvailable;

- (instancetype)initWithTransitionDelegate: (id<UIViewControllerTransitioningDelegate>) transitionDelegate
                             selectedTrack: (AudioBrowserTrackWrapper * _Nullable) selectedTrack;

-(BaseTrackSelectionViewController * _Nullable) getAudioBrowserController;

@end
NS_ASSUME_NONNULL_END
