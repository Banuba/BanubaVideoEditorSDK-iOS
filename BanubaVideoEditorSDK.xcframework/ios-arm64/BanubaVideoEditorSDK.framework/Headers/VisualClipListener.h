//
//  VisualClipListener.h
//  BanubaVideoEditorSDK
//
//  Created by Rostyslav Dovhaliuk on 20.07.2023.
//  Copyright © 2023 Banuba. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((weak_import)) @interface VisualClipListener : NSObject

- (instancetype)initWithCancellation:(BOOL (^)(double progress))cancellationBlock;

@end

NS_ASSUME_NONNULL_END
