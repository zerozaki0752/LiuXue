/*
 *  Copyright (c) 2013 The CCP project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a Beijing Speedtong Information Technology Co.,Ltd license
 *  that can be found in the LICENSE file in the root of the web site.
 *
 *                    http://www.cloopen.com
 *
 *  An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#import <Foundation/Foundation.h>
#import "DBConnection.h"
#import "Statement.h"
#import "IMCommon.h"
#import "CommonClass.h"
#import "ALXMPPHelper.h"

@interface IMMsgDBAccess : NSObject
{
    sqlite3 * shareDB;
}

- (IMMsgDBAccess *)init;

#pragma mark - 会话函数
//获取会话列表
- (NSArray *)getIMListArray;

//获取未读会话列表
- (NSArray *)getUnreadIMListArray;

//删除所有会话 通知消息和聊天消息
- (void)deleteAllIMMsg;

#pragma mark - 聊天记录函数
//获取某个会话的全部聊天记录
- (NSArray *)getMessageOfSessionId:(NSString *)sessionId;

//获取某个会话的未读聊天记录
- (NSArray *)getUnreadMessageOfSessionId:(NSString *)sessionId;

//删除某个会话的聊天记录
- (BOOL)deleteMessageOfSessionId:(NSString *)sessionId;

/*
{
    group =     (
                 {
                     count = 11;
                     groupId = g8039074045376;
                 }
                 );
    user =     (
                {
                    count = 17;
                    user = "<PFUser:rRXOnjc0Ql:(null)> {\n}";
                    userId = 80390700000001;
                },
                {
                    count = 10;
                    user = "<PFUser:sv5qoc4CBK:(null)> {\n}";
                    userId = 80390700000002;
                }
                );
}
*/
//获取某个会话的全部聊天记录
- (void)getALLMessageCountWithBlock:(void(^)(NSDictionary *messages ,NSError *error))resultBlock;

//获取某个会话的全部未读聊天记录
- (void)getALLUnreadMessageCountWithBlock:(void(^)(NSDictionary *messages ,NSError *error))resultBlock;

//获取某个会话中全部消息数
- (NSInteger)getCountOfSessionId:(NSString *)sessionId;

//获取某个会话中未读消息数
- (NSInteger)getUnreadCountOfSessionId:(NSString *)sessionId;

//更改会话中未读状态为已读
- (BOOL)updateUnreadStateOfSessionId:(NSString *)sessionId;

//更改会话中发送中状态为发送失败
- (BOOL)updateAllSendingToFailed;

//更新某消息的本地文件路径
- (BOOL)updateFilePath:(NSString*)path andMsgid:(NSString*)msgid;

//判断消息是否存在
- (BOOL)isMessageExistOfMsgid:(NSString*)msgid;

//添加聊天消息
- (BOOL)insertIMMessage:(IMMessageObj*)im;

//更新某个消息发送状态
- (BOOL)updateimState:(EMessageState)status OfmsgId:(NSString *)msgId;

//获取所有的本地文件路径
- (NSArray*)getAllFilePath;

//获取某个会话的本地文件路径
- (NSArray*)getAllFilePathOfSessionId:(NSString*)sessionId;

#pragma mark - 通知消息
//添加新的通知消息
- (BOOL)insertNoticeMessage:(InstanceMsg *)notice withType:(EGroupNoticeType)type;

//更新通知的未读状态为已读
- (BOOL)updateUnreadGroupNotice;

//获取未读通知消息数
- (NSInteger)getUnreadCountOfGroupNotice;

//删除所有通知消息
- (BOOL)deleteAllGroupNotice;

//获取所有通知消息
- (NSArray *)getAllGroupNotices;

//更新某些通知消息的操作状态
- (BOOL)updateGroupNoticeState:(EGroupNoticeOperation)state OfGroupId:(NSString *)groupid andPushMsgType:(EGroupNoticeType)msgType andWho:(NSString*)who;

#pragma mark - 群组消息函数
//判断群组是否存在
- (BOOL)isGroupExistOfGroupId:(NSString*)groupId;

//获取群组名字
- (NSString*)queryNameOfGroupId:(NSString*)groupId;

//批量更新群组消息
- (void)updateGroupInfos:(NSArray*)groupInfos;

//更新群组消息
- (BOOL)updateGroupInfo:(IMGroupInfo*)groupinfo;

//批量添加群组消息
- (void)insertGroupInfos:(NSArray*)groupInfoArr;

//添加群组消息
- (BOOL)insertGroupInfo:(IMGroupInfo *)groupInfo;

//批量操作群组消息
- (void)insertOrUpdateGroupInfos:(NSArray*)groupInfos;
@end
