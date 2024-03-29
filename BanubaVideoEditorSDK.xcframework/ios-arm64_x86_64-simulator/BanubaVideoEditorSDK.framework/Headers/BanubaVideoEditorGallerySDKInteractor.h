//
//  BanubaVideoEditorGallerySDKInteractor.h
//  BanubaVideoEditorSDK
//
//  Created by Andrei Sak on 18.04.21.
//  Copyright © 2021 Banuba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BanubaUtilities/BanubaUtilities.h>

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(BanubaVideoEditorGallerySDKInteractor)
__attribute__((weak_import)) @interface BanubaVideoEditorGallerySDKInteractor : NSObject

+ (BOOL)isFrameworkAvailable;

@property (strong, nonatomic)  id<GalleryViewControllerFactory> factory;

- (void)setAutoCutAvailable:(BOOL)isAvailable;

@end

NS_ASSUME_NONNULL_END
