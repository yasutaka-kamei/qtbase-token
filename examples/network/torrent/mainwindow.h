begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MAINWINDOW_H
end_ifndef
begin_define
DECL|macro|MAINWINDOW_H
define|#
directive|define
name|MAINWINDOW_H
end_define
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|"torrentclient.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAction
name|class
name|QAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCloseEvent
name|class
name|QCloseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QProgressDialog
name|class
name|QProgressDialog
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSlider
name|class
name|QSlider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|variable|TorrentView
name|class
name|TorrentView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|MainWindow
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|MainWindow
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
specifier|const
name|TorrentClient
operator|*
name|clientForRow
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|void
name|closeEvent
argument_list|(
name|QCloseEvent
operator|*
name|event
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|loadSettings
argument_list|()
block|;
name|void
name|saveSettings
argument_list|()
block|;
name|bool
name|addTorrent
argument_list|()
block|;
name|void
name|removeTorrent
argument_list|()
block|;
name|void
name|pauseTorrent
argument_list|()
block|;
name|void
name|moveTorrentUp
argument_list|()
block|;
name|void
name|moveTorrentDown
argument_list|()
block|;
name|void
name|torrentStopped
argument_list|()
block|;
name|void
name|torrentError
argument_list|(
argument|TorrentClient::Error error
argument_list|)
block|;
name|void
name|updateState
argument_list|(
argument|TorrentClient::State state
argument_list|)
block|;
name|void
name|updatePeerInfo
argument_list|()
block|;
name|void
name|updateProgress
argument_list|(
argument|int percent
argument_list|)
block|;
name|void
name|updateDownloadRate
argument_list|(
argument|int bytesPerSecond
argument_list|)
block|;
name|void
name|updateUploadRate
argument_list|(
argument|int bytesPerSecond
argument_list|)
block|;
name|void
name|setUploadLimit
argument_list|(
argument|int bytes
argument_list|)
block|;
name|void
name|setDownloadLimit
argument_list|(
argument|int bytes
argument_list|)
block|;
name|void
name|about
argument_list|()
block|;
name|void
name|setActionsEnabled
argument_list|()
block|;
name|void
name|acceptFileDrop
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|private
operator|:
name|int
name|rowOfClient
argument_list|(
argument|TorrentClient *client
argument_list|)
specifier|const
block|;
name|bool
name|addTorrent
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|QString
operator|&
name|destinationFolder
argument_list|,
specifier|const
name|QByteArray
operator|&
name|resumeState
operator|=
name|QByteArray
argument_list|()
argument_list|)
block|;
name|TorrentView
operator|*
name|torrentView
block|;
name|QAction
operator|*
name|pauseTorrentAction
block|;
name|QAction
operator|*
name|removeTorrentAction
block|;
name|QAction
operator|*
name|upActionTool
block|;
name|QAction
operator|*
name|downActionTool
block|;
name|QSlider
operator|*
name|uploadLimitSlider
block|;
name|QSlider
operator|*
name|downloadLimitSlider
block|;
name|QLabel
operator|*
name|uploadLimitLabel
block|;
name|QLabel
operator|*
name|downloadLimitLabel
block|;
name|int
name|uploadLimit
block|;
name|int
name|downloadLimit
block|;      struct
name|Job
block|{
name|TorrentClient
operator|*
name|client
block|;
name|QString
name|torrentFileName
block|;
name|QString
name|destinationDirectory
block|;     }
block|;
name|QList
operator|<
name|Job
operator|>
name|jobs
block|;
name|int
name|jobsStopped
block|;
name|int
name|jobsToStop
block|;
name|QString
name|lastDirectory
block|;
name|QProgressDialog
operator|*
name|quitDialog
block|;
name|bool
name|saveChanges
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
