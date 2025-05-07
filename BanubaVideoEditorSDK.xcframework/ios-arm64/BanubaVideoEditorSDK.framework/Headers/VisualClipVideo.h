//
//  VisualClipVideo.h
//  BanubaVideoEditorSDK
//
//  Created by Rostyslav Dovhaliuk on 14.07.2023.
//  Copyright © 2023 Banuba. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VisualClipVideo : NSObject

@property (nonatomic, strong, nonnull) NSString *path;
@property (nonatomic, assign) float startPosition;
@property (nonatomic, assign) float duration;

- (nonnull instancetype)initWithPath:(nonnull NSString *)path
                       startPosition:(float)startPosition
                            duration:(float)duration;

@end
