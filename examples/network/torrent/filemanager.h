begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FILEMANAGER_H
end_ifndef
begin_define
DECL|macro|FILEMANAGER_H
define|#
directive|define
name|FILEMANAGER_H
end_define
begin_include
include|#
directive|include
file|<QBitArray>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QMutex>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QWaitCondition>
end_include
begin_include
include|#
directive|include
file|"metainfo.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFile
name|class
name|QFile
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTimerEvent
name|class
name|QTimerEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|FileManager
range|:
name|public
name|QThread
block|{
name|Q_OBJECT
name|public
operator|:
name|FileManager
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|FileManager
argument_list|()
block|;
specifier|inline
name|void
name|setMetaInfo
argument_list|(
argument|const MetaInfo&info
argument_list|)
block|{
name|metaInfo
operator|=
name|info
block|; }
specifier|inline
name|void
name|setDestinationFolder
argument_list|(
argument|const QString&directory
argument_list|)
block|{
name|destinationPath
operator|=
name|directory
block|; }
name|int
name|read
argument_list|(
argument|int pieceIndex
argument_list|,
argument|int offset
argument_list|,
argument|int length
argument_list|)
block|;
name|void
name|write
argument_list|(
argument|int pieceIndex
argument_list|,
argument|int offset
argument_list|,
argument|const QByteArray&data
argument_list|)
block|;
name|void
name|verifyPiece
argument_list|(
argument|int pieceIndex
argument_list|)
block|;
specifier|inline
name|qint64
name|totalSize
argument_list|()
specifier|const
block|{
return|return
name|totalLength
return|;
block|}
specifier|inline
name|int
name|pieceCount
argument_list|()
specifier|const
block|{
return|return
name|numPieces
return|;
block|}
name|int
name|pieceLengthAt
argument_list|(
argument|int pieceIndex
argument_list|)
specifier|const
block|;
name|QBitArray
name|completedPieces
argument_list|()
specifier|const
block|;
name|void
name|setCompletedPieces
argument_list|(
specifier|const
name|QBitArray
operator|&
name|pieces
argument_list|)
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
name|public
name|slots
operator|:
name|void
name|startDataVerification
argument_list|()
block|;
name|signals
operator|:
name|void
name|dataRead
argument_list|(
argument|int id
argument_list|,
argument|int pieceIndex
argument_list|,
argument|int offset
argument_list|,
argument|const QByteArray&data
argument_list|)
block|;
name|void
name|error
argument_list|()
block|;
name|void
name|verificationProgress
argument_list|(
argument|int percent
argument_list|)
block|;
name|void
name|verificationDone
argument_list|()
block|;
name|void
name|pieceVerified
argument_list|(
argument|int pieceIndex
argument_list|,
argument|bool verified
argument_list|)
block|;
name|protected
operator|:
name|void
name|run
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|private
name|slots
operator|:
name|bool
name|verifySinglePiece
argument_list|(
argument|int pieceIndex
argument_list|)
block|;
name|void
name|wakeUp
argument_list|()
block|;
name|private
operator|:
name|bool
name|generateFiles
argument_list|()
block|;
name|QByteArray
name|readBlock
argument_list|(
argument|int pieceIndex
argument_list|,
argument|int offset
argument_list|,
argument|int length
argument_list|)
block|;
name|bool
name|writeBlock
argument_list|(
argument|int pieceIndex
argument_list|,
argument|int offset
argument_list|,
argument|const QByteArray&data
argument_list|)
block|;
name|void
name|verifyFileContents
argument_list|()
block|;      struct
name|WriteRequest
block|{
name|int
name|pieceIndex
block|;
name|int
name|offset
block|;
name|QByteArray
name|data
block|;     }
block|;     struct
name|ReadRequest
block|{
name|int
name|pieceIndex
block|;
name|int
name|offset
block|;
name|int
name|length
block|;
name|int
name|id
block|;     }
block|;
name|QString
name|errString
block|;
name|QString
name|destinationPath
block|;
name|MetaInfo
name|metaInfo
block|;
name|QList
operator|<
name|QFile
operator|*
operator|>
name|files
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|sha1s
block|;
name|QBitArray
name|verifiedPieces
block|;
name|bool
name|newFile
block|;
name|int
name|pieceLength
block|;
name|qint64
name|totalLength
block|;
name|int
name|numPieces
block|;
name|int
name|readId
block|;
name|bool
name|startVerification
block|;
name|bool
name|quit
block|;
name|bool
name|wokeUp
block|;
name|QList
operator|<
name|WriteRequest
operator|>
name|writeRequests
block|;
name|QList
operator|<
name|ReadRequest
operator|>
name|readRequests
block|;
name|QList
operator|<
name|int
operator|>
name|pendingVerificationRequests
block|;
name|QList
operator|<
name|int
operator|>
name|newPendingVerificationRequests
block|;
name|QList
operator|<
name|qint64
operator|>
name|fileSizes
block|;
name|mutable
name|QMutex
name|mutex
block|;
name|mutable
name|QWaitCondition
name|cond
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
