begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Canonical, Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmirclientclipboard.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QMimeData>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QDBusInterface>
end_include
begin_include
include|#
directive|include
file|<QDBusPendingCallWatcher>
end_include
begin_include
include|#
directive|include
file|<QDBusPendingReply>
end_include
begin_comment
comment|// FIXME(loicm) The clipboard data format is not defined by Ubuntu Platform API
end_comment
begin_comment
comment|//     which makes it impossible to have non-Qt applications communicate with Qt
end_comment
begin_comment
comment|//     applications through the clipboard API. The solution would be to have
end_comment
begin_comment
comment|//     Ubuntu Platform define the data format or propose an API that supports
end_comment
begin_comment
comment|//     embedding different mime types in the clipboard.
end_comment
begin_comment
comment|// Data format:
end_comment
begin_comment
comment|//   number of mime types      (sizeof(int))
end_comment
begin_comment
comment|//   data layout               ((4 * sizeof(int)) * number of mime types)
end_comment
begin_comment
comment|//     mime type string offset (sizeof(int))
end_comment
begin_comment
comment|//     mime type string size   (sizeof(int))
end_comment
begin_comment
comment|//     data offset             (sizeof(int))
end_comment
begin_comment
comment|//     data size               (sizeof(int))
end_comment
begin_comment
comment|//   data                      (n bytes)
end_comment
begin_namespace
namespace|namespace
block|{
DECL|member|maxFormatsCount
specifier|const
name|int
name|maxFormatsCount
init|=
literal|16
decl_stmt|;
DECL|member|maxBufferSize
specifier|const
name|int
name|maxBufferSize
init|=
literal|4
operator|*
literal|1024
operator|*
literal|1024
decl_stmt|;
comment|// 4 Mb
block|}
end_namespace
begin_constructor
DECL|function|QMirClientClipboard
name|QMirClientClipboard
operator|::
name|QMirClientClipboard
parameter_list|()
member_init_list|:
name|mMimeData
argument_list|(
operator|new
name|QMimeData
argument_list|)
member_init_list|,
name|mIsOutdated
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|mUpdatesDisabled
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mDBusSetupDone
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QMirClientClipboard
name|QMirClientClipboard
operator|::
name|~
name|QMirClientClipboard
parameter_list|()
block|{
operator|delete
name|mMimeData
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|requestDBusClipboardContents
name|void
name|QMirClientClipboard
operator|::
name|requestDBusClipboardContents
parameter_list|()
block|{
if|if
condition|(
operator|!
name|mDBusSetupDone
condition|)
block|{
name|setupDBus
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|mPendingGetContentsCall
operator|.
name|isNull
argument_list|()
condition|)
return|return;
name|QDBusPendingCall
name|pendingCall
init|=
name|mDBusClipboard
operator|->
name|asyncCall
argument_list|(
name|QStringLiteral
argument_list|(
literal|"GetContents"
argument_list|)
argument_list|)
decl_stmt|;
name|mPendingGetContentsCall
operator|=
operator|new
name|QDBusPendingCallWatcher
argument_list|(
name|pendingCall
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|mPendingGetContentsCall
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|QDBusPendingCallWatcher
operator|::
name|finished
argument_list|,
name|this
argument_list|,
operator|&
name|QMirClientClipboard
operator|::
name|onDBusClipboardGetContentsFinished
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onDBusClipboardGetContentsFinished
name|void
name|QMirClientClipboard
operator|::
name|onDBusClipboardGetContentsFinished
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|call
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|call
operator|==
name|mPendingGetContentsCall
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|QDBusPendingReply
argument_list|<
name|QByteArray
argument_list|>
name|reply
init|=
operator|*
name|call
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|reply
operator|.
name|isError
argument_list|()
argument_list|)
condition|)
block|{
name|qCritical
argument_list|(
literal|"QMirClientClipboard - Failed to get system clipboard contents via D-Bus. %s, %s"
argument_list|,
name|qPrintable
argument_list|(
name|reply
operator|.
name|error
argument_list|()
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|reply
operator|.
name|error
argument_list|()
operator|.
name|message
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// TODO: Might try again later a number of times...
block|}
else|else
block|{
name|QByteArray
name|serializedMimeData
init|=
name|reply
operator|.
name|argumentAt
argument_list|<
literal|0
argument_list|>
argument_list|()
decl_stmt|;
name|updateMimeData
argument_list|(
name|serializedMimeData
argument_list|)
expr_stmt|;
block|}
name|call
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|onDBusClipboardSetContentsFinished
name|void
name|QMirClientClipboard
operator|::
name|onDBusClipboardSetContentsFinished
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|call
parameter_list|)
block|{
name|QDBusPendingReply
argument_list|<
name|void
argument_list|>
name|reply
init|=
operator|*
name|call
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|reply
operator|.
name|isError
argument_list|()
argument_list|)
condition|)
block|{
name|qCritical
argument_list|(
literal|"QMirClientClipboard - Failed to set the system clipboard contents via D-Bus. %s, %s"
argument_list|,
name|qPrintable
argument_list|(
name|reply
operator|.
name|error
argument_list|()
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|reply
operator|.
name|error
argument_list|()
operator|.
name|message
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// TODO: Might try again later a number of times...
block|}
name|call
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateMimeData
name|void
name|QMirClientClipboard
operator|::
name|updateMimeData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|serializedMimeData
parameter_list|)
block|{
if|if
condition|(
name|mUpdatesDisabled
condition|)
return|return;
name|QMimeData
modifier|*
name|newMimeData
init|=
name|deserializeMimeData
argument_list|(
name|serializedMimeData
argument_list|)
decl_stmt|;
if|if
condition|(
name|newMimeData
condition|)
block|{
operator|delete
name|mMimeData
expr_stmt|;
name|mMimeData
operator|=
name|newMimeData
expr_stmt|;
name|mIsOutdated
operator|=
literal|false
expr_stmt|;
name|emitChanged
argument_list|(
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QMirClientClipboard - Got invalid serialized mime data. Ignoring it."
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setupDBus
name|void
name|QMirClientClipboard
operator|::
name|setupDBus
parameter_list|()
block|{
name|QDBusConnection
name|dbusConnection
init|=
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
decl_stmt|;
name|bool
name|ok
init|=
name|dbusConnection
operator|.
name|connect
argument_list|(
name|QStringLiteral
argument_list|(
literal|"com.canonical.QtMir"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"/com/canonical/QtMir/Clipboard"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"com.canonical.QtMir.Clipboard"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"ContentsChanged"
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateMimeData
argument_list|(
name|QByteArray
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|ok
argument_list|)
condition|)
name|qCritical
argument_list|(
literal|"QMirClientClipboard - Failed to connect to ContentsChanged signal form the D-Bus system clipboard."
argument_list|)
expr_stmt|;
name|mDBusClipboard
operator|=
operator|new
name|QDBusInterface
argument_list|(
name|QStringLiteral
argument_list|(
literal|"com.canonical.QtMir"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"/com/canonical/QtMir/Clipboard"
argument_list|)
argument_list|,
name|QStringLiteral
argument_list|(
literal|"com.canonical.QtMir.Clipboard"
argument_list|)
argument_list|,
name|dbusConnection
argument_list|)
expr_stmt|;
name|mDBusSetupDone
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|serializeMimeData
name|QByteArray
name|QMirClientClipboard
operator|::
name|serializeMimeData
parameter_list|(
name|QMimeData
modifier|*
name|mimeData
parameter_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|mimeData
operator|!=
literal|nullptr
argument_list|)
expr_stmt|;
specifier|const
name|QStringList
name|formats
init|=
name|mimeData
operator|->
name|formats
argument_list|()
decl_stmt|;
specifier|const
name|int
name|formatCount
init|=
name|qMin
argument_list|(
name|formats
operator|.
name|size
argument_list|()
argument_list|,
name|maxFormatsCount
argument_list|)
decl_stmt|;
specifier|const
name|int
name|headerSize
init|=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|+
operator|(
name|formatCount
operator|*
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|)
decl_stmt|;
name|int
name|bufferSize
init|=
name|headerSize
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|formatCount
condition|;
name|i
operator|++
control|)
name|bufferSize
operator|+=
name|formats
index|[
name|i
index|]
operator|.
name|size
argument_list|()
operator|+
name|mimeData
operator|->
name|data
argument_list|(
name|formats
index|[
name|i
index|]
argument_list|)
operator|.
name|size
argument_list|()
expr_stmt|;
name|QByteArray
name|serializedMimeData
decl_stmt|;
if|if
condition|(
name|bufferSize
operator|<=
name|maxBufferSize
condition|)
block|{
comment|// Serialize data.
name|serializedMimeData
operator|.
name|resize
argument_list|(
name|bufferSize
argument_list|)
expr_stmt|;
block|{
name|char
modifier|*
name|buffer
init|=
name|serializedMimeData
operator|.
name|data
argument_list|()
decl_stmt|;
name|int
modifier|*
name|header
init|=
cast|reinterpret_cast
argument_list|<
name|int
operator|*
argument_list|>
argument_list|(
name|serializedMimeData
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|offset
init|=
name|headerSize
decl_stmt|;
name|header
index|[
literal|0
index|]
operator|=
name|formatCount
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|formatCount
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|QByteArray
name|data
init|=
name|mimeData
operator|->
name|data
argument_list|(
name|formats
index|[
name|i
index|]
argument_list|)
decl_stmt|;
specifier|const
name|int
name|formatOffset
init|=
name|offset
decl_stmt|;
specifier|const
name|int
name|formatSize
init|=
name|formats
index|[
name|i
index|]
operator|.
name|size
argument_list|()
decl_stmt|;
specifier|const
name|int
name|dataOffset
init|=
name|offset
operator|+
name|formatSize
decl_stmt|;
specifier|const
name|int
name|dataSize
init|=
name|data
operator|.
name|size
argument_list|()
decl_stmt|;
name|memcpy
argument_list|(
operator|&
name|buffer
index|[
name|formatOffset
index|]
argument_list|,
name|formats
index|[
name|i
index|]
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|,
name|formatSize
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|buffer
index|[
name|dataOffset
index|]
argument_list|,
name|data
operator|.
name|data
argument_list|()
argument_list|,
name|dataSize
argument_list|)
expr_stmt|;
name|header
index|[
name|i
operator|*
literal|4
operator|+
literal|1
index|]
operator|=
name|formatOffset
expr_stmt|;
name|header
index|[
name|i
operator|*
literal|4
operator|+
literal|2
index|]
operator|=
name|formatSize
expr_stmt|;
name|header
index|[
name|i
operator|*
literal|4
operator|+
literal|3
index|]
operator|=
name|dataOffset
expr_stmt|;
name|header
index|[
name|i
operator|*
literal|4
operator|+
literal|4
index|]
operator|=
name|dataSize
expr_stmt|;
name|offset
operator|+=
name|formatSize
operator|+
name|dataSize
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QMirClientClipboard: Not sending contents (%d bytes) to the global clipboard as it's"
literal|" bigger than the maximum allowed size of %d bytes"
argument_list|,
name|bufferSize
argument_list|,
name|maxBufferSize
argument_list|)
expr_stmt|;
block|}
return|return
name|serializedMimeData
return|;
block|}
end_function
begin_function
DECL|function|deserializeMimeData
name|QMimeData
modifier|*
name|QMirClientClipboard
operator|::
name|deserializeMimeData
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|serializedMimeData
parameter_list|)
specifier|const
block|{
if|if
condition|(
cast|static_cast
argument_list|<
name|std
operator|::
name|size_t
argument_list|>
argument_list|(
name|serializedMimeData
operator|.
name|size
argument_list|()
argument_list|)
operator|<
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|)
block|{
comment|// Data is invalid
return|return
literal|nullptr
return|;
block|}
name|QMimeData
modifier|*
name|mimeData
init|=
operator|new
name|QMimeData
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|buffer
init|=
name|serializedMimeData
operator|.
name|constData
argument_list|()
decl_stmt|;
specifier|const
name|int
modifier|*
specifier|const
name|header
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|int
operator|*
argument_list|>
argument_list|(
name|serializedMimeData
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|int
name|count
init|=
name|qMin
argument_list|(
name|header
index|[
literal|0
index|]
argument_list|,
name|maxFormatsCount
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|int
name|formatOffset
init|=
name|header
index|[
name|i
operator|*
literal|4
operator|+
literal|1
index|]
decl_stmt|;
specifier|const
name|int
name|formatSize
init|=
name|header
index|[
name|i
operator|*
literal|4
operator|+
literal|2
index|]
decl_stmt|;
specifier|const
name|int
name|dataOffset
init|=
name|header
index|[
name|i
operator|*
literal|4
operator|+
literal|3
index|]
decl_stmt|;
specifier|const
name|int
name|dataSize
init|=
name|header
index|[
name|i
operator|*
literal|4
operator|+
literal|4
index|]
decl_stmt|;
if|if
condition|(
name|formatOffset
operator|+
name|formatSize
operator|<=
name|serializedMimeData
operator|.
name|size
argument_list|()
operator|&&
name|dataOffset
operator|+
name|dataSize
operator|<=
name|serializedMimeData
operator|.
name|size
argument_list|()
condition|)
block|{
name|QString
name|mimeType
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
operator|&
name|buffer
index|[
name|formatOffset
index|]
argument_list|,
name|formatSize
argument_list|)
decl_stmt|;
name|QByteArray
name|mimeDataBytes
argument_list|(
operator|&
name|buffer
index|[
name|dataOffset
index|]
argument_list|,
name|dataSize
argument_list|)
decl_stmt|;
name|mimeData
operator|->
name|setData
argument_list|(
name|mimeType
argument_list|,
name|mimeDataBytes
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|mimeData
return|;
block|}
end_function
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|QMirClientClipboard
operator|::
name|mimeData
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
if|if
condition|(
name|mode
operator|!=
name|QClipboard
operator|::
name|Clipboard
condition|)
return|return
literal|nullptr
return|;
if|if
condition|(
name|mIsOutdated
operator|&&
name|mPendingGetContentsCall
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|requestDBusClipboardContents
argument_list|()
expr_stmt|;
block|}
comment|// Return whatever we have at the moment instead of blocking until we have something.
comment|//
comment|// This might be called during app startup just for the sake of checking if some
comment|// "Paste" UI control should be enabled or not.
comment|// We will emit QClipboard::changed() once we finally have something.
return|return
name|mMimeData
return|;
block|}
end_function
begin_function
DECL|function|setMimeData
name|void
name|QMirClientClipboard
operator|::
name|setMimeData
parameter_list|(
name|QMimeData
modifier|*
name|mimeData
parameter_list|,
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
if|if
condition|(
name|mode
operator|!=
name|QClipboard
operator|::
name|Clipboard
condition|)
return|return;
if|if
condition|(
operator|!
name|mPendingGetContentsCall
operator|.
name|isNull
argument_list|()
condition|)
block|{
comment|// Ignore whatever comes from the system clipboard as we are going to change it anyway
name|QObject
operator|::
name|disconnect
argument_list|(
name|mPendingGetContentsCall
operator|.
name|data
argument_list|()
argument_list|,
literal|0
argument_list|,
name|this
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mUpdatesDisabled
operator|=
literal|true
expr_stmt|;
name|mPendingGetContentsCall
operator|->
name|waitForFinished
argument_list|()
expr_stmt|;
name|mUpdatesDisabled
operator|=
literal|false
expr_stmt|;
operator|delete
name|mPendingGetContentsCall
operator|.
name|data
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|mimeData
operator|!=
literal|nullptr
condition|)
block|{
name|QByteArray
name|serializedMimeData
init|=
name|serializeMimeData
argument_list|(
name|mimeData
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|serializedMimeData
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|setDBusClipboardContents
argument_list|(
name|serializedMimeData
argument_list|)
expr_stmt|;
block|}
name|mMimeData
operator|=
name|mimeData
expr_stmt|;
name|emitChanged
argument_list|(
name|QClipboard
operator|::
name|Clipboard
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|supportsMode
name|bool
name|QMirClientClipboard
operator|::
name|supportsMode
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
return|return
name|mode
operator|==
name|QClipboard
operator|::
name|Clipboard
return|;
block|}
end_function
begin_function
DECL|function|ownsMode
name|bool
name|QMirClientClipboard
operator|::
name|ownsMode
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|mode
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|setDBusClipboardContents
name|void
name|QMirClientClipboard
operator|::
name|setDBusClipboardContents
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|clipboardContents
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mDBusSetupDone
condition|)
block|{
name|setupDBus
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|mPendingSetContentsCall
operator|.
name|isNull
argument_list|()
condition|)
block|{
comment|// Ignore any previous set call as we are going to overwrite it anyway
name|QObject
operator|::
name|disconnect
argument_list|(
name|mPendingSetContentsCall
operator|.
name|data
argument_list|()
argument_list|,
literal|0
argument_list|,
name|this
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mUpdatesDisabled
operator|=
literal|true
expr_stmt|;
name|mPendingSetContentsCall
operator|->
name|waitForFinished
argument_list|()
expr_stmt|;
name|mUpdatesDisabled
operator|=
literal|false
expr_stmt|;
operator|delete
name|mPendingSetContentsCall
operator|.
name|data
argument_list|()
expr_stmt|;
block|}
name|QDBusPendingCall
name|pendingCall
init|=
name|mDBusClipboard
operator|->
name|asyncCall
argument_list|(
name|QStringLiteral
argument_list|(
literal|"SetContents"
argument_list|)
argument_list|,
name|clipboardContents
argument_list|)
decl_stmt|;
name|mPendingSetContentsCall
operator|=
operator|new
name|QDBusPendingCallWatcher
argument_list|(
name|pendingCall
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|mPendingSetContentsCall
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|QDBusPendingCallWatcher
operator|::
name|finished
argument_list|,
name|this
argument_list|,
operator|&
name|QMirClientClipboard
operator|::
name|onDBusClipboardSetContentsFinished
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
