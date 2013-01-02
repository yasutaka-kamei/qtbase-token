begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"downloadmanager.h"
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QNetworkRequest>
end_include
begin_include
include|#
directive|include
file|<QNetworkReply>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_constructor
DECL|function|DownloadManager
name|DownloadManager
operator|::
name|DownloadManager
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|downloadedCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|totalCount
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|append
name|void
name|DownloadManager
operator|::
name|append
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|urlList
parameter_list|)
block|{
foreach|foreach
control|(
name|QString
name|url
decl|,
name|urlList
control|)
name|append
argument_list|(
name|QUrl
operator|::
name|fromEncoded
argument_list|(
name|url
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|downloadQueue
operator|.
name|isEmpty
argument_list|()
condition|)
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|append
name|void
name|DownloadManager
operator|::
name|append
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
if|if
condition|(
name|downloadQueue
operator|.
name|isEmpty
argument_list|()
condition|)
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|startNextDownload
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|downloadQueue
operator|.
name|enqueue
argument_list|(
name|url
argument_list|)
expr_stmt|;
operator|++
name|totalCount
expr_stmt|;
block|}
end_function
begin_function
DECL|function|saveFileName
name|QString
name|DownloadManager
operator|::
name|saveFileName
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|QString
name|path
init|=
name|url
operator|.
name|path
argument_list|()
decl_stmt|;
name|QString
name|basename
init|=
name|QFileInfo
argument_list|(
name|path
argument_list|)
operator|.
name|fileName
argument_list|()
decl_stmt|;
if|if
condition|(
name|basename
operator|.
name|isEmpty
argument_list|()
condition|)
name|basename
operator|=
literal|"download"
expr_stmt|;
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|basename
argument_list|)
condition|)
block|{
comment|// already exists, don't overwrite
name|int
name|i
init|=
literal|0
decl_stmt|;
name|basename
operator|+=
literal|'.'
expr_stmt|;
while|while
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|basename
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|)
condition|)
operator|++
name|i
expr_stmt|;
name|basename
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
return|return
name|basename
return|;
block|}
end_function
begin_function
DECL|function|startNextDownload
name|void
name|DownloadManager
operator|::
name|startNextDownload
parameter_list|()
block|{
if|if
condition|(
name|downloadQueue
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|printf
argument_list|(
literal|"%d/%d files downloaded successfully\n"
argument_list|,
name|downloadedCount
argument_list|,
name|totalCount
argument_list|)
expr_stmt|;
emit|emit
name|finished
argument_list|()
emit|;
return|return;
block|}
name|QUrl
name|url
init|=
name|downloadQueue
operator|.
name|dequeue
argument_list|()
decl_stmt|;
name|QString
name|filename
init|=
name|saveFileName
argument_list|(
name|url
argument_list|)
decl_stmt|;
name|output
operator|.
name|setFileName
argument_list|(
name|filename
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|output
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Problem opening save file '%s' for download '%s': %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|filename
argument_list|)
argument_list|,
name|url
operator|.
name|toEncoded
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|output
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|startNextDownload
argument_list|()
expr_stmt|;
return|return;
comment|// skip this download
block|}
name|QNetworkRequest
name|request
argument_list|(
name|url
argument_list|)
decl_stmt|;
name|currentDownload
operator|=
name|manager
operator|.
name|get
argument_list|(
name|request
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|currentDownload
argument_list|,
name|SIGNAL
argument_list|(
name|downloadProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|downloadProgress
argument_list|(
name|qint64
argument_list|,
name|qint64
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|currentDownload
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|downloadFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|currentDownload
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|downloadReadyRead
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// prepare the output
name|printf
argument_list|(
literal|"Downloading %s...\n"
argument_list|,
name|url
operator|.
name|toEncoded
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|downloadTime
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|downloadProgress
name|void
name|DownloadManager
operator|::
name|downloadProgress
parameter_list|(
name|qint64
name|bytesReceived
parameter_list|,
name|qint64
name|bytesTotal
parameter_list|)
block|{
name|progressBar
operator|.
name|setStatus
argument_list|(
name|bytesReceived
argument_list|,
name|bytesTotal
argument_list|)
expr_stmt|;
comment|// calculate the download speed
name|double
name|speed
init|=
name|bytesReceived
operator|*
literal|1000.0
operator|/
name|downloadTime
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|QString
name|unit
decl_stmt|;
if|if
condition|(
name|speed
operator|<
literal|1024
condition|)
block|{
name|unit
operator|=
literal|"bytes/sec"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|speed
operator|<
literal|1024
operator|*
literal|1024
condition|)
block|{
name|speed
operator|/=
literal|1024
expr_stmt|;
name|unit
operator|=
literal|"kB/s"
expr_stmt|;
block|}
else|else
block|{
name|speed
operator|/=
literal|1024
operator|*
literal|1024
expr_stmt|;
name|unit
operator|=
literal|"MB/s"
expr_stmt|;
block|}
name|progressBar
operator|.
name|setMessage
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|speed
argument_list|,
literal|3
argument_list|,
literal|'f'
argument_list|,
literal|1
argument_list|)
operator|.
name|arg
argument_list|(
name|unit
argument_list|)
argument_list|)
expr_stmt|;
name|progressBar
operator|.
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|downloadFinished
name|void
name|DownloadManager
operator|::
name|downloadFinished
parameter_list|()
block|{
name|progressBar
operator|.
name|clear
argument_list|()
expr_stmt|;
name|output
operator|.
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
name|currentDownload
operator|->
name|error
argument_list|()
condition|)
block|{
comment|// download failed
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Failed: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|currentDownload
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"Succeeded.\n"
argument_list|)
expr_stmt|;
operator|++
name|downloadedCount
expr_stmt|;
block|}
name|currentDownload
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|startNextDownload
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|downloadReadyRead
name|void
name|DownloadManager
operator|::
name|downloadReadyRead
parameter_list|()
block|{
name|output
operator|.
name|write
argument_list|(
name|currentDownload
operator|->
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
