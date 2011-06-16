//
//  AIMReceivingFileTransfer.h
//  LibOrange
//
//  Created by Alex Nichol on 6/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AIMFileTransfer.h"
#import "OFTConnection.h"
#import "OFTServer.h"
#import "ANIPInformation.h"
#import "OFTProxyConnection.h"

@class AIMReceivingFileTransfer;

@protocol AIMReceivingFileTransferDelegate <NSObject>

@optional
- (void)aimReceivingFileTransferPropositionFailed:(AIMReceivingFileTransfer *)ft counterProposal:(AIMIMRendezvous *)newProp;
- (void)aimReceivingFileTransferPropositionSuccess:(AIMReceivingFileTransfer *)ft;
- (void)aimReceivingFileTransferTransferFailed:(AIMReceivingFileTransfer *)ft;
- (void)aimReceivingFileTransferStarted:(AIMReceivingFileTransfer *)ft;
- (void)aimReceivingFileTransferSendAccept:(AIMReceivingFileTransfer *)ft;

@end

@interface AIMReceivingFileTransfer : AIMFileTransfer {
    NSString * remoteHostAddr;
	NSString * remoteFileName;
	NSString * localUsername;
	NSLock * bgThreadLock;
	NSLock * mainThreadLock;
	NSThread * backgroundThread;
	NSThread * mainThread; // session.backgroundThread
	id<AIMReceivingFileTransferDelegate> delegate;
}

@property (nonatomic, retain) id<AIMReceivingFileTransferDelegate> delegate;
@property (nonatomic, retain) NSString * remoteHostAddr;
@property (nonatomic, retain) NSString * remoteFileName;
@property (nonatomic, retain) NSThread * mainThread;
@property (nonatomic, retain) NSThread * backgroundThread;
@property (nonatomic, retain) NSString * localUsername;

- (void)tryProposal; // try stage 1 (DIRECT)
- (void)newProposal; // stage 3 (PROXY)

@end
