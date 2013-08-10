
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
 JABoxComUploadWrapper.h
 */

#import <Foundation/Foundation.h>
#import "JABoxComUploadWrapper.h"
@class JABoxComUploadOperation;
@protocol JABoxComUploadOperationDelegate <NSObject>

-(void)boxOperation:(JABoxComUploadOperation *)operation didUploadPercentageForItem:(NSMutableDictionary *)uploadInfo;
-(void)boxOperation:(JABoxComUploadOperation *)operation uploadFailedWithError:(NSError *)error;
-(void)boxOperation:(JABoxComUploadOperation *)operation uploadedLocalFileWithInfo:(NSMutableDictionary *)infoDict;

@end

@interface JABoxComUploadOperation : NSOperation

/*
 NSMutableDictionary *itemToUpload - should contain objects with these keys:
 NSString *const JAFileUploadNameKey
 NSString *const JAFileUploadRemotePathKey
 NSString *const JAFileUploadPathIDKey
 NSString *const JAFileUploadLocalPathKey */
@property (nonatomic,strong) NSMutableDictionary *itemToUpload;

/*
 Delegate object to receive callbacks didUploadPercentage, uploadFailedWithError,
 and uploadedLocalFileWithInfo */
@property (nonatomic,weak) id<JABoxComUploadOperationDelegate> operationDelegate;

/*
 Main constructor method */
-(id)initWithUploadInfo:(NSMutableDictionary *)info;

/*
 Call this to end the NSOperation lifecycle */
-(void)updateCompletedState;



@end
