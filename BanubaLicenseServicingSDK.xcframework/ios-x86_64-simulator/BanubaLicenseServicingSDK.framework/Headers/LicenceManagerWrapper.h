//
//  LicenceManagerWrapper.h
//  BanubaVideoEditorSDK
//
//  Created by Gleb Markin on 10/19/20.
//  Copyright © 2020 Banuba. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LicenceManagerWrapper : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithToken:(NSString *)token;
- (NSString *) getBase64EncodedToken;

@end

NS_ASSUME_NONNULL_END
