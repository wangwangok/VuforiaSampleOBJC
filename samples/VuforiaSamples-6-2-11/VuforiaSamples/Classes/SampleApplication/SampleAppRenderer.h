/*===============================================================================
 Copyright (c) 2016 PTC Inc. All Rights Reserved.
 
 Copyright (c) 2012-2015 Qualcomm Connected Experiences, Inc. All Rights Reserved.
 
 Vuforia is a trademark of PTC Inc., registered in the United States and other
 countries.
 ===============================================================================*/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Vuforia/Device.h>
#import <Vuforia/State.h>

/// 渲染

@protocol SampleAppRendererControl
// This method has to be implemented by the Renderer class which handles the content rendering
// of the sample, this one is called from SampleAppRendering class for each view inside a loop
/// 会多次循环调用
- (void) renderFrameWithState:(const Vuforia::State&) state projectMatrix:(Vuforia::Matrix44F&) projectionMatrix;

@end

@interface SampleAppRenderer : NSObject
// Encapsulates the rendering primitives usage

//Initializes the instance with a SampleAppRendererControl so we can call it to render a frame for the current view, the
//device mode is also provided for AR/VR, the stereo setting and near/far planes for the projection matrix
- (id)initWithSampleAppRendererControl:(id<SampleAppRendererControl>)control deviceMode:(Vuforia::Device::MODE)deviceMode stereo:(bool)stereo nearPlane:(float)nearPlane farPlane:(float)farPlane;

//Initializes the shaders to render the video background using the texture provided by the sdk
- (void) initRendering;

//Set near and far planes for the projection matrix to be used to render the augmentations
- (void) setNearPlane:(CGFloat) near farPlane:(CGFloat) far;

/// 对于可用视图调用renderFrameWithState来包裹渲染所需要的原始数据
//Encapsulates the rendering primitives usage going through the available views and calling renderFrameWithState from SampleAppRendererControl
- (void) renderFrameVuforia;

//Renders the video background using the texture provided by the sdk
- (void) renderVideoBackground;

//Configure the video backgound size
- (void) configureVideoBackgroundWithViewWidth:(float)viewWidth andHeight:(float)viewHeight;

/// 当屏幕尺寸发生改变或者是设备朝向改变之后，调用该方法来更新渲染原始数据
//Updates the rendering primitives to be called when there is a change of screen size or orientation
- (void) updateRenderingPrimitives;

@end
