begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TRACKERCLIENT_H
end_ifndef
begin_define
DECL|macro|TRACKERCLIENT_H
define|#
directive|define
name|TRACKERCLIENT_H
end_define
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QHostAddress>
end_include
begin_include
include|#
directive|include
file|<QHttp>
end_include
begin_include
include|#
directive|include
file|"metainfo.h"
end_include
begin_include
include|#
directive|include
file|"torrentclient.h"
end_include
begin_decl_stmt
DECL|variable|TorrentClient
name|class
name|TorrentClient
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|TrackerClient
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|TrackerClient
argument_list|(
name|TorrentClient
operator|*
name|downloader
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|start
argument_list|(
specifier|const
name|MetaInfo
operator|&
name|info
argument_list|)
block|;
name|void
name|stop
argument_list|()
block|;
name|void
name|startSeeding
argument_list|()
block|;
name|signals
operator|:
name|void
name|connectionError
argument_list|(
argument|QHttp::Error error
argument_list|)
block|;
name|void
name|failure
argument_list|(
specifier|const
name|QString
operator|&
name|reason
argument_list|)
block|;
name|void
name|warning
argument_list|(
specifier|const
name|QString
operator|&
name|message
argument_list|)
block|;
name|void
name|peerListUpdated
argument_list|(
specifier|const
name|QList
operator|<
name|TorrentPeer
operator|>
operator|&
name|peerList
argument_list|)
block|;
name|void
name|uploadCountUpdated
argument_list|(
argument|qint64 newUploadCount
argument_list|)
block|;
name|void
name|downloadCountUpdated
argument_list|(
argument|qint64 newDownloadCount
argument_list|)
block|;
name|void
name|stopped
argument_list|()
block|;
name|protected
operator|:
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|event
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|fetchPeerList
argument_list|()
block|;
name|void
name|httpRequestDone
argument_list|(
argument|bool error
argument_list|)
block|;
name|private
operator|:
name|TorrentClient
operator|*
name|torrentDownloader
block|;
name|int
name|requestInterval
block|;
name|int
name|requestIntervalTimer
block|;
name|QHttp
name|http
block|;
name|MetaInfo
name|metaInfo
block|;
name|QByteArray
name|trackerId
block|;
name|QList
operator|<
name|TorrentPeer
operator|>
name|peers
block|;
name|qint64
name|uploadedBytes
block|;
name|qint64
name|downloadedBytes
block|;
name|qint64
name|length
block|;
name|bool
name|firstTrackerRequest
block|;
name|bool
name|lastTrackerRequest
block|;
name|bool
name|firstSeeding
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
