//
//  BanubaEffectPlayerInteractor.h
//  BanubaLicenseServicingSDK
//
//  Created by Gleb Markin on 12.07.21.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(BanubaEffectPlayerInteractor)

// MARK: - Banuba Sdk framework interactor
__attribute__((weak_import)) @interface BanubaEffectPlayerInteractor : NSObject

+ (BOOL)isFrameworkAvailable;

+ (void)create: (NSString *) token;

+ (void)sendEvent: (NSString *) key
            value: (NSString *) value;

+ (NSString *)getJson;
@end
NS_ASSUME_NONNULL_END
