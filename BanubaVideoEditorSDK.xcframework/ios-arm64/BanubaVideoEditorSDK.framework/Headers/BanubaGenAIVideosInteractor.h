//
//  BanubaGenAIVideosInteractor.h
//  BanubaVideoEditorSDK
//
//  Created by Andrei Sak on 08.01.26.
//  Copyright © 2026 Banuba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class GenAIVideo;

@protocol GenAIVideosSDKDelegate <NSObject>

- (void)genAIVideosSDKDidCancel;
- (void)genAIVideosSDKDidAddNewSession;
- (void)genAIVideosSDKDidRequestHome;
- (void)genAIVideoSDKDidSelectGenAIVideo:(GenAIVideo * _Nonnull)genAIVideo;

@end

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GenAIVideoGenerationState) {
  GenAIVideoGenerationStateInProgress = 0,
  GenAIVideoGenerationStateFailed,
  GenAIVideoGenerationStateDone
};

typedef NS_ENUM(NSInteger, GenAIVideoEntryPoint) {
  GenAIVideoEntryPointGallery = 0,
  GenAIVideoEntryPointVideos = 1
};

NS_SWIFT_NAME(GenAIVideo)
__attribute__((weak_import)) @interface GenAIVideo : NSObject

@property (readonly, nonatomic) GenAIVideoGenerationState generationState;
@property (readonly, copy, nonatomic) UIImage *previewImage;
@property (readonly, nullable, copy, nonatomic) NSURL *videoURL;

- (nonnull instancetype)initWithState:(GenAIVideoGenerationState)generationState
                         previewImage:(UIImage * _Nullable)previewImage
                             videoURL:(NSURL * _Nullable)videoURL;
@end

NS_ASSUME_NONNULL_END

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(BanubaGenAIVideosInteractor)

// MARK: - BanubaGenAIVideosSDK framework interactor
__attribute__((weak_import)) @interface BanubaGenAIVideosInteractor : NSObject

+ (BOOL)isFrameworkAvailable;

@property (nonatomic, weak, nullable) id<GenAIVideosSDKDelegate> delegate;

- (instancetype)initWithToken:(NSString *)token genAISecret:(NSString *)genAISecret;
- (UINavigationController *)getGenAIVideosController:(GenAIVideoEntryPoint)entryPoint;
- (nonnull NSArray<GenAIVideo *> *)getGenAIVides;

// MARK: - Banner State Management
- (BOOL)hasActiveGeneration;
- (void)cancelActiveGeneration;

@end

NS_ASSUME_NONNULL_END
