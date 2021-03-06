//
//  HTTPClient.h
//  FM_CZFW
//
//  Created by liyuhui on 14-4-14.
//  Copyright (c) 2014年 ETelecom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking.h"
#import "WebAPIDefine.h"
#import "WebAPIResponse.h"

typedef void (^WebAPIRequestCompletionBlock)(WebAPIResponse* response);

//定义网络错误提示信息
#define NETERROR_LOADERR_TIP            @"读取失败"


#define FMHTTPClient [HTTPClient sharedHTTPClient]
#define FMImageClient [HTTPClient sharedImageClient]


@interface HTTPClient : AFHTTPClient

//获取API单实例
+ (HTTPClient *)sharedHTTPClient;

//获取图片服务器单实例
+ (HTTPClient *)sharedImageClient;

//判断是否WIFI连接
- (BOOL)isWiFiConnection;

//get请求
- (AFHTTPRequestOperation *)getPath:(NSString *)path
                       parameters:(NSDictionary *)parameters
                       completion:(WebAPIRequestCompletionBlock)completionBlock;


//post请求
- (AFHTTPRequestOperation *)postPath:(NSString *)path
                        parameters:(NSDictionary *)parameters
                        completion:(WebAPIRequestCompletionBlock)completionBlock;


//图片上传,上传成功返回图片key,只能由FMImageClient调用
//type 图片的类型
//1：interact:
//2：car_pic
//3：road_condition
//4：avatar，
//5：driver_license
//6：second_hand_car
- (AFHTTPRequestOperation *)imageUpload:(UIImage *)image
                              imageType:(NSString *)type
                             completion:(WebAPIRequestCompletionBlock)completionBlock;
/** 音频源上传处理接口
 
 *@param audioData 为音频源信息
 @See 音频上传成功后，可解析到音频对应的KEY信息内容。
 **/
- (AFHTTPRequestOperation *)audioUpload:(NSData *)audioData
                             completion:(WebAPIRequestCompletionBlock)completionBlock;
@end