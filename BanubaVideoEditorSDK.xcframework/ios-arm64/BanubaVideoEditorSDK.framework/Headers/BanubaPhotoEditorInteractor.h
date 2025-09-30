//
//  BanubaPhotoEditorInteractor.h
//  BanubaVideoEditorSDK
//

#import <UIKit/UIKit.h>

@class License;
@protocol PhotoEditor;

@protocol PhotoEditorDelegate <NSObject>

@required

/// User closed photo editor without editing image
- (void)photoEditorDidCancel:(id _Nonnull *_Nonnull)photoEditor;

/// User closed photo editor after saving image
- (void)photoEditorDidFinishWithImage:(id _Nonnull *_Nonnull)photoEditor image:(UIImage *_Nonnull)image;

@end


@protocol PhotoEditor <NSObject>

@property (nonatomic, weak, nullable) id<PhotoEditorDelegate> delegate;

@required
- (void)presentPhotoEditorForImage:(UIImage *_Nonnull)image fromViewController:(UIViewController *_Nonnull)vc;
- (void)dismissPhotoEditorAnimated:(BOOL)animated completion:(void (^ _Nullable)(void))completion;

@end

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(BanubaPhotoEditorInteractor)

// MARK: - BanubaPhotoEditorInteractor interactor
__attribute__((weak_import)) @interface BanubaPhotoEditorInteractor : NSObject

+ (BOOL)isFrameworkAvailable;
+ (nullable id<PhotoEditor>)getPhotoEditorInstance:(License *)license;

@end
NS_ASSUME_NONNULL_END
