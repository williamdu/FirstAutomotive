//  Copyright (C) __ORGANIZATIONNAME___  6/19/14 william du.
//
//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.
//
//
//  debug.h
//
//
//  Created by DuHailong on 3/20/10. All rights reserved.

#ifndef  _DEBUG_H_
#define  _DEBUG_H_


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//@Notes:
//Suggest import "debug.h" to  Prefix.pch"
/*
 #import <Availability.h>
 #ifdef __OBJC__
 #import "debug.h"
 #endif
 */
//-----------------------------------------------------------------------------//
//Note:Remember to modify project name and version in other project**
#define    PROJECT_NAME                      "sxhsh"
#define    PROJECT_VERSION                   "V1.3.5"



//use this macro to  log information in different mode
//for release version that don't need to output so many
//log information,you can comment it.
#ifdef DEBUG
#define   SIT_VERSION
#define   DUBUG_VERSION                          //debug version
#define   ENABLE_TEST_CODE                  1
#else
#define   SIT_VERSION
#define   ENABLE_TEST_CODE                  0
#endif

//setting destribution version.
#ifdef DISTRIBUTION_VERSION
#define   ENABLE_LOG_VIEWER                 0   //Disable debug viewer.
#define   ENABLE_JAILBROKEN_CHECK           0   //Disable Jail broken checking
#define   ENABLE_LOG_TO_PC                  0   //Disable log to PC, socket enable..
#define   ENABLE_SHOW_FUNCTION_OUTPUT       0   //Disable function output message
#define   ENABLE_DBG_MSG_MANUAL             0   //manual enable/disable debug message..
#else
#define   ENABLE_LOG_VIEWER                 1   //Enable debug viewer.
#define   ENABLE_JAILBROKEN_CHECK           0   //Disable  Jail broken checking
#define   ENABLE_LOG_TO_PC                  0   //enable log to PC, socket enable..
#define   ENABLE_SHOW_FUNCTION_OUTPUT       1   //Eanble function output message
#define   ENABLE_DBG_MSG_MANUAL             1   //manual enable/disable debug message..
#endif


#define    ENABLE_CRASH_CATCH                1    //crash catch macro.
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//Notes: Using to catch exceptions.
/*
 example code:
 #if (ENABLE_CRASH_CATCH == 1)

//define develop email to receive crash email..
*  @param ENABLE_CRASH_CATCH
*
*  @return*/
/*-----------------------------------------------------------------------------//
 
 #define   DEVELOP_ACCOUNT         @"75596569@qq.com"
 
 NSString *emailEncodeOfText(NSString *encodeText) {
 
 NSMutableString *output = [NSMutableString string];
 const unsigned char *source = (const unsigned char *)[encodeText UTF8String];
 long sourceLen = strlen((const char *)source);
 for (int i = 0; i < sourceLen; ++i) {
 const unsigned char thisChar = source[i];
 if (thisChar == ' '){
 [output appendString:@"%20"];
 }else if (thisChar == ':'|| thisChar == '.' || thisChar == '-' || thisChar == '_' || thisChar == '~' || (thisChar >= 'a' && thisChar <= 'z') || (thisChar >= 'A' && thisChar <= 'Z') ||(thisChar >= '0' && thisChar <= '9'))
 {
 [output appendFormat:@"%c", thisChar];
 
 } else {
 [output appendFormat:@"%%%02X", thisChar];
 }
 }
 return output;
 }
 
 //catch un-expected exception...debug using..
 void uncaughtExceptionHandler(NSException *exception) {
 
 NSString *subject = @"Feedback bugs to vinyl team!";
 subject = emailEncodeOfText(subject);
 
 NSString *crashDesp = [exception description];
 DBG_E(@"crash reason: %@", crashDesp);
 
 NSString *crashStack = [[exception callStackSymbols] description];
 DBG_E(@"stack trace: %@", crashStack);
 
 NSString *body = [NSString stringWithFormat:@"Sorry from develop team, Wish you can send crash log to help us improve it! \r\ncrash reason:\r\n %@ \r\nstack trace:\r\n %@", crashDesp, crashStack];
 //---other code email or sending to statics sever..
 body = emailEncodeOfText(body);
 NSString *emailBody = [NSString stringWithFormat:@"mailto:%@?subject=%@&body=%@", DEVELOP_ACCOUNT, subject, body];
 [[UIApplication sharedApplication] openURL:[NSURL URLWithString:emailBody]];
 
 }
1.declare catch functions in AppDelegate.m


 
 //---------------------------------------------------------------------------//
 
 2. Call application to catch exception.
 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 {
 
 #if (ENABLE_CRASH_CATCH == 1)
     //catch en-expend exception..
     NSSetUncaughtExceptionHandler(&uncaughtExceptionHandler);
 #endif
 
 }
 */


//enum  TEST OUTPUT
#define    TEST_INFO_OUTPUT                  0


// debug message level definition
#define   MSG_NONE                           0
#define   MSG_INFO                           1
#define   MSG_TRK                            2
#define   MSG_WARN                           3
#define   MSG_ERR                            4
#define   MSG_MAX                            5

//define the output debug level in different mode.

#ifdef DISTRIBUTION_VERSION

#define   MSG_LEVEL                          MSG_WARN
#define   ENABLE_LOG_TO_FILE                  0

#else

#ifdef    DUBUG_VERSION
#define   MSG_LEVEL                          MSG_TRK
#define   ENABLE_LOG_TO_FILE                  0
#else
#define   MSG_LEVEL                          MSG_WARN
#define   ENABLE_LOG_TO_FILE                  1
#endif

#endif


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//enable log file save to document.
//@Note:
//1. The dubug message will not output to consel again.
//2. Make sure Call SAVE_LOGFILE macro when applicaion launch.
//3. It will create a log file in application document path[BabyOnline.txt]
//4. You can get the  [BabyOnline.txt] from application documents path
/*Example
 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 {
 //save logs to file..
 SAVE_LOGFILE();
 
 ----other codes----
 }
 */
//-----------------------------------------------------------------------------//

#if (ENABLE_LOG_TO_FILE == 1)
#define output(msg)   syslogv(msg);
//define save log to file macro.
//@you can save log information to file in application data path
//@strong recommad to invoke in application start place.
//@like application::didFinishLaunchingWithOptions
//@Note: the log information will not output to consel if enable this macro.
#define  SAVE_LOGFILE()\
do{\
NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES);\
NSString *documentsDirectory = [paths objectAtIndex:0];\
NSString *logFileName  = [NSString stringWithUTF8String:PROJECT_NAME];\
NSString *logPath = [documentsDirectory stringByAppendingPathComponent:[logFileName stringByAppendingFormat:@".txt"]];\
DBG_T(@"Save log information to file: %@", logPath);\
freopen([logPath cStringUsingEncoding:NSASCIIStringEncoding],"a+",stderr);\
}while(0);
#else
#if ENABLE_LOG_TO_PC
#define output(msg)  syslogv(msg);
#else
#define output(msg)  fprintf(stderr,"%s",[msg UTF8String]);
#endif
#define  SAVE_LOGFILE()\
do{\
}while(0);
#endif


//define file path..
#define  LOGFILE_PATH   [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES)  objectAtIndex:0] stringByAppendingPathComponent:[[NSString stringWithUTF8String:PROJECT_NAME] stringByAppendingFormat:@".txt"]]

//manual debug message macro..
#if (ENABLE_DBG_MSG_MANUAL == 1)
#define DBG_MSG(level, msg, ...)\
do{\
if ((level < MSG_MAX) && (level >= MSG_LEVEL))\
{\
NSString *body = [NSString stringWithFormat:@"[%@ %@ %@:(%d)] %@ %@\r\n",[NSString stringWithUTF8String:PROJECT_NAME], [NSString stringWithUTF8String:PROJECT_VERSION],[[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithUTF8String:(#level)], [NSString stringWithFormat:(msg), ##__VA_ARGS__]];\
fprintf(stderr,"%s",[body UTF8String]);\
}\
}while(0);
#else
#define DBG_MSG(level, msg, ...)\
do{\
}while(0);
#endif


//simple debug macros..
#define DBG_I(msg, ...)  DBG_MSG(MSG_INFO, msg,  ##__VA_ARGS__);
#define DBG_T(msg, ...)  DBG_MSG(MSG_TRK,  msg,  ##__VA_ARGS__);
#define DBG_W(msg, ...)  DBG_MSG(MSG_WARN, msg,  ##__VA_ARGS__);
#define DBG_E(msg, ...)  DBG_MSG(MSG_ERR,  msg,  ##__VA_ARGS__);

//---Rugular debug macros--//
#define STR_ENUM(x)   ([NSString stringWithUTF8String:(#x)])
#define DBG_DC(dc)    DBG_MSG(MSG_TRK, @"%@(%@)", @#dc, [dc description]);
#define DBG_PT(pt)    DBG_MSG(MSG_TRK, @"%@(x:%f, y:%f)", @#pt, pt.x, pt.y);
#define DBG_SZ(sz)    DBG_MSG(MSG_TRK, @"%@(width: %f, height: %f)",@#sz, sz.width, sz.height);
#define DBG_RG(rg)    DBG_MSG(MSG_TRK, @"%@(location: %d, length: %d)", @#rg, rg.location, rg.length);
#define DBG_RC(rc)    DBG_MSG(MSG_TRK, @"%@(left: %f, top: %f, width: %f, height: %f)", @#rc,rc.origin.x, rc.origin.y, rc.size.width, rc.size.height);
#define DBG_UNKNOWN(object) DBG_MSG(MSG_WARN, @"un-known object: %@ class: %@", @#object, NSStringFromClass([object class]));
#define DBG_INDEXPATH (ip) DBG_MSG(MSG_TRK, @"%@(section: %ld, row: %ld)", @#ip, ip.section,ip.row);




//condition check message.
#define  CHECK_CONDITION(condition)\
{\
if(!condition)\
{\
DBG_W(@"Check Condition failed: %@", @#condition);\
}\
}\

//NULL check message.
#define  CHECK_NULL(var)\
{\
if(!var)\
{\
DBG_W(@"%@ is NULL", @#var);\
}\
}\

//assert check message
#define  ASSERT_MSG(condition, msg, ...)\
{\
if(!condition)\
{\
DBG_E(@"Assert Message: %@", @#condition);\
NSAssert(condition, msg, [NSString stringWithFormat:(msg), ##__VA_ARGS__]);\
}\
}\

//show enter funtion message.
#if (ENABLE_SHOW_FUNCTION_OUTPUT == 1)
#define  SHOW_ENTER_FUN()\
do{\
DBG_T(@"++%@",  [NSString stringWithUTF8String:__FUNCTION__]);\
}while(0);
#else
#define SHOW_ENTER_FUN()
#endif

//show leave function message.
#if (ENABLE_SHOW_FUNCTION_OUTPUT == 1)
#define  SHOW_LEAVE_FUN()\
do{\
DBG_T(@"--%@",  [NSString stringWithUTF8String:__FUNCTION__]);\
}while(0);
#else
#define  SHOW_LEAVE_FUN()
#endif


#endif
