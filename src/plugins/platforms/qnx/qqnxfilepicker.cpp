begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 Research In Motion ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxfilepicker.h"
end_include
begin_include
include|#
directive|include
file|<QAbstractEventDispatcher>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QJsonDocument>
end_include
begin_include
include|#
directive|include
file|<QJsonObject>
end_include
begin_include
include|#
directive|include
file|<QJsonArray>
end_include
begin_include
include|#
directive|include
file|<QJsonParseError>
end_include
begin_include
include|#
directive|include
file|<QMimeDatabase>
end_include
begin_include
include|#
directive|include
file|<QUrl>
end_include
begin_include
include|#
directive|include
file|<private/qppsobject_p.h>
end_include
begin_include
include|#
directive|include
file|<bps/navigator.h>
end_include
begin_include
include|#
directive|include
file|<bps/navigator_invoke.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QQNXFILEPICKER_DEBUG
end_ifdef
begin_define
DECL|macro|qFilePickerDebug
define|#
directive|define
name|qFilePickerDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qFilePickerDebug
define|#
directive|define
name|qFilePickerDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|s_filePickerTarget
specifier|static
specifier|const
name|char
name|s_filePickerTarget
index|[]
init|=
literal|"sys.filepicker.target"
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QQnxFilePicker
name|QQnxFilePicker
operator|::
name|QQnxFilePicker
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
name|m_invocationHandle
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_mode
argument_list|(
name|QQnxFilePicker
operator|::
name|Picker
argument_list|)
member_init_list|,
name|m_title
argument_list|(
name|tr
argument_list|(
literal|"Pick a file"
argument_list|)
argument_list|)
block|{
name|QCoreApplication
operator|::
name|eventDispatcher
argument_list|()
operator|->
name|installNativeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QQnxFilePicker
name|QQnxFilePicker
operator|::
name|~
name|QQnxFilePicker
parameter_list|()
block|{
name|cleanup
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|eventDispatcher
argument_list|()
operator|->
name|removeNativeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|open
name|void
name|QQnxFilePicker
operator|::
name|open
parameter_list|()
block|{
if|if
condition|(
name|m_invocationHandle
condition|)
return|return;
comment|// Clear any previous results
name|m_selectedFiles
operator|.
name|clear
argument_list|()
expr_stmt|;
name|int
name|errorCode
init|=
name|BPS_SUCCESS
decl_stmt|;
name|errorCode
operator|=
name|navigator_invoke_invocation_create
argument_list|(
operator|&
name|m_invocationHandle
argument_list|)
expr_stmt|;
if|if
condition|(
name|errorCode
operator|!=
name|BPS_SUCCESS
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QQnxFilePicker: unable to create invocation:"
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
return|return;
block|}
name|errorCode
operator|=
name|navigator_invoke_invocation_set_target
argument_list|(
name|m_invocationHandle
argument_list|,
name|s_filePickerTarget
argument_list|)
expr_stmt|;
if|if
condition|(
name|errorCode
operator|!=
name|BPS_SUCCESS
condition|)
block|{
name|cleanup
argument_list|()
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"QQnxFilePicker: unable to set target:"
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
return|return;
block|}
name|errorCode
operator|=
name|navigator_invoke_invocation_set_action
argument_list|(
name|m_invocationHandle
argument_list|,
literal|"bb.action.OPEN"
argument_list|)
expr_stmt|;
if|if
condition|(
name|errorCode
operator|!=
name|BPS_SUCCESS
condition|)
block|{
name|cleanup
argument_list|()
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"QQnxFilePicker: unable to set action:"
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
return|return;
block|}
name|errorCode
operator|=
name|navigator_invoke_invocation_set_type
argument_list|(
name|m_invocationHandle
argument_list|,
literal|"application/vnd.blackberry.file_picker"
argument_list|)
expr_stmt|;
if|if
condition|(
name|errorCode
operator|!=
name|BPS_SUCCESS
condition|)
block|{
name|cleanup
argument_list|()
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"QQnxFilePicker: unable to set mime type:"
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
return|return;
block|}
name|QVariantMap
name|map
decl_stmt|;
name|map
index|[
name|QStringLiteral
argument_list|(
literal|"Type"
argument_list|)
index|]
operator|=
name|filePickerType
argument_list|()
expr_stmt|;
name|map
index|[
name|QStringLiteral
argument_list|(
literal|"Mode"
argument_list|)
index|]
operator|=
name|modeToString
argument_list|(
name|m_mode
argument_list|)
expr_stmt|;
name|map
index|[
name|QStringLiteral
argument_list|(
literal|"Title"
argument_list|)
index|]
operator|=
name|m_title
expr_stmt|;
name|map
index|[
name|QStringLiteral
argument_list|(
literal|"ViewMode"
argument_list|)
index|]
operator|=
name|QStringLiteral
argument_list|(
literal|"Default"
argument_list|)
expr_stmt|;
name|map
index|[
name|QStringLiteral
argument_list|(
literal|"SortBy"
argument_list|)
index|]
operator|=
name|QStringLiteral
argument_list|(
literal|"Default"
argument_list|)
expr_stmt|;
name|map
index|[
name|QStringLiteral
argument_list|(
literal|"SortOrder"
argument_list|)
index|]
operator|=
name|QStringLiteral
argument_list|(
literal|"Default"
argument_list|)
expr_stmt|;
name|map
index|[
name|QStringLiteral
argument_list|(
literal|"ImageCrop"
argument_list|)
index|]
operator|=
literal|false
expr_stmt|;
name|map
index|[
name|QStringLiteral
argument_list|(
literal|"AllowOverwrite"
argument_list|)
index|]
operator|=
literal|false
expr_stmt|;
if|if
condition|(
operator|!
name|m_defaultSaveFileNames
operator|.
name|isEmpty
argument_list|()
condition|)
name|map
index|[
name|QStringLiteral
argument_list|(
literal|"DefaultFileNames"
argument_list|)
index|]
operator|=
name|m_defaultSaveFileNames
operator|.
name|join
argument_list|(
name|QLatin1Char
argument_list|(
literal|','
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_filters
operator|.
name|isEmpty
argument_list|()
condition|)
name|map
index|[
name|QStringLiteral
argument_list|(
literal|"Filter"
argument_list|)
index|]
operator|=
name|m_filters
operator|.
name|join
argument_list|(
name|QLatin1Char
argument_list|(
literal|';'
argument_list|)
argument_list|)
expr_stmt|;
name|QByteArray
name|ppsData
decl_stmt|;
name|ppsData
operator|=
name|QPpsObject
operator|::
name|encode
argument_list|(
name|map
argument_list|)
expr_stmt|;
name|errorCode
operator|=
name|navigator_invoke_invocation_set_data
argument_list|(
name|m_invocationHandle
argument_list|,
name|ppsData
operator|.
name|constData
argument_list|()
argument_list|,
name|ppsData
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|errorCode
operator|!=
name|BPS_SUCCESS
condition|)
block|{
name|cleanup
argument_list|()
expr_stmt|;
name|qWarning
argument_list|()
operator|<<
literal|"QQnxFilePicker: unable to set data:"
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
return|return;
block|}
name|navigator_invoke_invocation_send
argument_list|(
name|m_invocationHandle
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|close
name|void
name|QQnxFilePicker
operator|::
name|close
parameter_list|()
block|{
name|navigator_card_close_child
argument_list|()
expr_stmt|;
name|cleanup
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nativeEventFilter
name|bool
name|QQnxFilePicker
operator|::
name|nativeEventFilter
parameter_list|(
specifier|const
name|QByteArray
modifier|&
parameter_list|,
name|void
modifier|*
name|message
parameter_list|,
name|long
modifier|*
parameter_list|)
block|{
name|bps_event_t
modifier|*
specifier|const
name|event
init|=
cast|static_cast
argument_list|<
name|bps_event_t
operator|*
argument_list|>
argument_list|(
name|message
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|event
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|bps_event_get_code
argument_list|(
name|event
argument_list|)
operator|==
name|NAVIGATOR_INVOKE_TARGET_RESULT
condition|)
block|{
specifier|const
name|char
modifier|*
name|id
init|=
name|navigator_event_get_id
argument_list|(
name|event
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|err
init|=
name|navigator_event_get_err
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|qFilePickerDebug
argument_list|(
literal|"received invocation response: id=%s err=%s"
argument_list|,
name|id
argument_list|,
name|err
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|bps_event_get_code
argument_list|(
name|event
argument_list|)
operator|==
name|NAVIGATOR_CHILD_CARD_CLOSED
condition|)
block|{
specifier|const
name|char
modifier|*
name|data
init|=
name|navigator_event_get_card_closed_data
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|qFilePickerDebug
argument_list|(
literal|"received data: data='%s'"
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|handleFilePickerResponse
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
return|return
literal|false
return|;
comment|// do not drop the event
block|}
end_function
begin_function
DECL|function|setMode
name|void
name|QQnxFilePicker
operator|::
name|setMode
parameter_list|(
name|QQnxFilePicker
operator|::
name|Mode
name|mode
parameter_list|)
block|{
name|m_mode
operator|=
name|mode
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDefaultSaveFileNames
name|void
name|QQnxFilePicker
operator|::
name|setDefaultSaveFileNames
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|fileNames
parameter_list|)
block|{
name|m_defaultSaveFileNames
operator|=
name|fileNames
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addDefaultSaveFileName
name|void
name|QQnxFilePicker
operator|::
name|addDefaultSaveFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|m_defaultSaveFileNames
operator|.
name|append
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDirectories
name|void
name|QQnxFilePicker
operator|::
name|setDirectories
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|directories
parameter_list|)
block|{
name|m_directories
operator|=
name|directories
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addDirectory
name|void
name|QQnxFilePicker
operator|::
name|addDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
name|directory
parameter_list|)
block|{
name|m_directories
operator|.
name|append
argument_list|(
name|directory
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFilters
name|void
name|QQnxFilePicker
operator|::
name|setFilters
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|filters
parameter_list|)
block|{
name|m_filters
operator|=
name|filters
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setTitle
name|void
name|QQnxFilePicker
operator|::
name|setTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
name|m_title
operator|=
name|title
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mode
name|QQnxFilePicker
operator|::
name|Mode
name|QQnxFilePicker
operator|::
name|mode
parameter_list|()
specifier|const
block|{
return|return
name|m_mode
return|;
block|}
end_function
begin_function
DECL|function|defaultSaveFileNames
name|QStringList
name|QQnxFilePicker
operator|::
name|defaultSaveFileNames
parameter_list|()
specifier|const
block|{
return|return
name|m_defaultSaveFileNames
return|;
block|}
end_function
begin_function
DECL|function|directories
name|QStringList
name|QQnxFilePicker
operator|::
name|directories
parameter_list|()
specifier|const
block|{
return|return
name|m_directories
return|;
block|}
end_function
begin_function
DECL|function|filters
name|QStringList
name|QQnxFilePicker
operator|::
name|filters
parameter_list|()
specifier|const
block|{
return|return
name|m_filters
return|;
block|}
end_function
begin_function
DECL|function|selectedFiles
name|QStringList
name|QQnxFilePicker
operator|::
name|selectedFiles
parameter_list|()
specifier|const
block|{
return|return
name|m_selectedFiles
return|;
block|}
end_function
begin_function
DECL|function|title
name|QString
name|QQnxFilePicker
operator|::
name|title
parameter_list|()
specifier|const
block|{
return|return
name|m_title
return|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|QQnxFilePicker
operator|::
name|cleanup
parameter_list|()
block|{
if|if
condition|(
name|m_invocationHandle
condition|)
block|{
name|navigator_invoke_invocation_destroy
argument_list|(
name|m_invocationHandle
argument_list|)
expr_stmt|;
name|m_invocationHandle
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handleFilePickerResponse
name|void
name|QQnxFilePicker
operator|::
name|handleFilePickerResponse
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|)
block|{
name|QJsonParseError
name|jsonError
decl_stmt|;
name|QJsonDocument
name|document
init|=
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|data
argument_list|,
operator|&
name|jsonError
argument_list|)
decl_stmt|;
if|if
condition|(
name|jsonError
operator|.
name|error
operator|!=
name|QJsonParseError
operator|::
name|NoError
condition|)
block|{
name|qFilePickerDebug
argument_list|()
operator|<<
literal|"Error parsing FilePicker response: "
operator|<<
name|jsonError
operator|.
name|errorString
argument_list|()
expr_stmt|;
name|Q_EMIT
name|closed
argument_list|()
decl_stmt|;
name|cleanup
argument_list|()
expr_stmt|;
return|return;
block|}
comment|// The response is a list of Json objects.
specifier|const
name|QVariantList
name|array
init|=
name|document
operator|.
name|array
argument_list|()
operator|.
name|toVariantList
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QVariant
modifier|&
name|variant
decl|,
name|array
control|)
block|{
specifier|const
name|QJsonObject
name|object
init|=
name|QJsonObject
operator|::
name|fromVariantMap
argument_list|(
name|variant
operator|.
name|toMap
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QUrl
name|url
argument_list|(
name|object
operator|.
name|value
argument_list|(
name|QStringLiteral
argument_list|(
literal|"uri"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|localFile
init|=
name|url
operator|.
name|toLocalFile
argument_list|()
decl_stmt|;
comment|// strip "file://"
if|if
condition|(
operator|!
name|localFile
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_selectedFiles
operator|<<
name|localFile
expr_stmt|;
name|qFilePickerDebug
argument_list|()
operator|<<
literal|"FilePicker uri response:"
operator|<<
name|localFile
expr_stmt|;
block|}
name|Q_EMIT
name|closed
argument_list|()
decl_stmt|;
name|cleanup
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|filePickerType
name|QString
name|QQnxFilePicker
operator|::
name|filePickerType
parameter_list|()
specifier|const
block|{
name|bool
name|images
init|=
literal|false
decl_stmt|;
name|bool
name|video
init|=
literal|false
decl_stmt|;
name|bool
name|music
init|=
literal|false
decl_stmt|;
name|QMimeDatabase
name|mimeDb
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
name|m_filters
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QList
argument_list|<
name|QMimeType
argument_list|>
name|mimeTypes
init|=
name|mimeDb
operator|.
name|mimeTypesForFileName
argument_list|(
name|m_filters
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|mimeTypes
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QStringLiteral
argument_list|(
literal|"Other"
argument_list|)
return|;
if|if
condition|(
name|mimeTypes
operator|.
name|first
argument_list|()
operator|.
name|name
argument_list|()
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"image"
argument_list|)
argument_list|)
condition|)
name|images
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|mimeTypes
operator|.
name|first
argument_list|()
operator|.
name|name
argument_list|()
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"audio"
argument_list|)
argument_list|)
condition|)
name|music
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|mimeTypes
operator|.
name|first
argument_list|()
operator|.
name|name
argument_list|()
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"video"
argument_list|)
argument_list|)
condition|)
name|video
operator|=
literal|true
expr_stmt|;
else|else
return|return
name|QStringLiteral
argument_list|(
literal|"Other"
argument_list|)
return|;
block|}
if|if
condition|(
operator|!
name|video
operator|&&
operator|!
name|music
condition|)
return|return
name|QStringLiteral
argument_list|(
literal|"Picture"
argument_list|)
return|;
if|if
condition|(
operator|!
name|images
operator|&&
operator|!
name|music
condition|)
return|return
name|QStringLiteral
argument_list|(
literal|"Video"
argument_list|)
return|;
if|if
condition|(
operator|!
name|images
operator|&&
operator|!
name|video
condition|)
return|return
name|QStringLiteral
argument_list|(
literal|"Music"
argument_list|)
return|;
return|return
name|QStringLiteral
argument_list|(
literal|"Other"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|modeToString
name|QString
name|QQnxFilePicker
operator|::
name|modeToString
parameter_list|(
name|QQnxFilePicker
operator|::
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|mode
condition|)
block|{
case|case
name|Picker
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Picker"
argument_list|)
return|;
case|case
name|Saver
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"Saver"
argument_list|)
return|;
case|case
name|PickerMultiple
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"PickerMultiple"
argument_list|)
return|;
case|case
name|SaverMultiple
case|:
return|return
name|QStringLiteral
argument_list|(
literal|"SaverMultiple"
argument_list|)
return|;
block|}
return|return
name|QStringLiteral
argument_list|(
literal|"Picker"
argument_list|)
return|;
block|}
end_function
end_unit
