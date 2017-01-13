//
//  BEManager.h
//  BugEase_iOS
//
//  Created by jc on 16/8/1.
//  Copyright © 2016年 jc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, BEModel){
    BEInvocationEventNone, // 0 直接启动
    BEInvocationEventShake, // 1 摇一摇启动
    BEInvocationEventFloatButton, // 2 悬浮窗启动
    BEInvocationEventScreenShot, // 3 截屏启动
    BEInvocationEventTwoFingerSwipe // 4 双指右滑启动
};

typedef NS_ENUM(NSUInteger,BEIssueType){

    BEISSUE_BUG,      // 0 bug
    BEISSUE_ADVICE,   // 1 建议
    BEISSUE_CRASH,    // 2 crash
};

@interface BEManager : NSObject

/**
 * 集成SDK
 * @param appKey SDK的appKey
 * @param model  SDK启动方式
 *
 **/
+(id)shareManagerWithAppKeys:(NSString *) appKey withModel:(NSUInteger) model;

/**
 * 设置自定义字段
 * @param key   数据名
 * @param value 数据
 *
 **/
+(void) setUserData:(NSString*) key andValue:(NSString*) value;

/**
 * 用户账号信息接口
 * @param userAccountInfo 用户账号信息
 *
 **/
+(void) setUserAccountInfo:(NSString*) userAccountInfo;

/**
 * 清除用户账号信息
 *
 **/
+(void) clearUserAccountInfo;

/**
 * 设置应用日志路径
 * @param logPath 应用日志路径(必选)
 *
 **/
+(void) setAppLogPath:(NSString*) logPath;

/**
 * 设置Crash收集开关
 * @param isOpen 是否收集Crash(必选)
 * true收集，false不收集
 *
 **/
+(void) setTrackingCrash:(BOOL) isOpen;

/**
 * 直接调用API上传文件
 * @param type 反馈类型(必选)
 * @param feedContent 反馈内容(必选)
 * @param reporter 反馈人(可选)
 * @param imagePath 截图文件(可选)
 * @param tags 标签列表(可选)
 *
 **/
+(void) sendFeedBack:(BEIssueType)type andContent:(NSString*) feedContent andReporter:(NSString*)reporter andImage:(UIImage*)image andTags:(NSArray*) tags;


//Demo app 专用API

+(void) selectModel:(BEModel)model;

@end
