//
//  AudioBrowserInteractor.h
//  BanubaVideoEditorSDK
//
//  Created by Gleb Markin on 2/22/21.
//  Copyright © 2021 Banuba. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(AudioBrowserTrackWrapper)

//MARK: - AudioBrowserTrackAdapter
__attribute__((weak_import)) @interface AudioBrowserTrackWrapper : NSObject

@property (strong, nonatomic) NSUUID *uuid;
@property (strong, nonatomic, nullable) NSString *name;
@property (strong, nonatomic) NSString *additionalName;
@property (strong, nonatomic) NSURL *url;
@property (strong, nonatomic) NSURL *coverURL;

- (instancetype)init: (NSUUID *) uuid
                name: (NSString *) name
      additionalName: (NSString * _Nullable) additionalName
                 url: (NSURL * _Nullable) url
            coverURL: (NSURL * _Nullable) url;
@end
NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(AudioBrowserFrameworkInteractor)

// MARK: - Audio browser framework interactor
__attribute__((weak_import)) @interface AudioBrowserFrameworkInteractor : NSObject

+ (BOOL)isFrameworkAvailable;
+ (void)setMubertKeys: (NSString *)license token:(NSString*)token;

- (instancetype)initWithSelectedTrack: (AudioBrowserTrackWrapper * _Nullable) selectedTrack
                 isSoundstripeEnabled:(BOOL)isSoundstripeEnabled
                 isBanubaMusicEnabled:(BOOL)isBanubaMusicEnabled
                                token:(NSString*)token
                       isAutocutAudio:(BOOL)isAutocutAudio
          isAudioPartSelectionEnabled:(BOOL)isAudioPartSelectionEnabled
                        videoDuration:(double)videoDuration;

-(UIViewController * _Nullable) getAudioBrowserController;

@end
NS_ASSUME_NONNULL_END
