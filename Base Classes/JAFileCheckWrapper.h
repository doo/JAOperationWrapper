
/*
 The MIT License (MIT)
 
 Copyright (c) 2013 Justin Amberson
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

/*
 JAFileCheckWrapper.h
 */

#import <Foundation/Foundation.h>
#import "JAOperationWrapperConstants.h"

typedef void (^JAFileCheckCompletedBlock)(NSMutableDictionary *fileInfo);
typedef void (^JAFileCheckFailedBlock)(NSError *error);

@interface JAFileCheckWrapper : NSObject

/*
 NSMutableDictionary *pathsDictionary - should contain objects with these keys:
 NSString *const JAFileUploadNameKey
 NSString *const JAFileUploadRemotePathKey - Please use the "parent ID", see Box.com documentation
 */
@property (nonatomic,strong) NSMutableDictionary *pathsDictionary;

/*
 A block to fire upon completion, or failure */
@property (nonatomic,copy) JAFileCheckCompletedBlock completedBlock; //receives NSDictionary
@property (nonatomic,copy) JAFileCheckFailedBlock failedBlock; //receives NSError

/*
 Main constructor to use to set up a new uploader
 JABoxComFileCheckWrapper *checker = [BoxComFileCheckWrapper checkerWithPaths:... */
+(id)checkerWithPaths:(NSMutableDictionary *)paths completed:(JAFileCheckCompletedBlock)compBlock failed:(JAFileCheckFailedBlock)failBlock;

/*
 Begin upload work
 example:
 JAFileCheckWrapper *checker = [JAFileCheckWrapper checkerWithPaths:...
 [checker checkFile]; */
-(void)checkFile;


@end
