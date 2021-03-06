begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxnavigatorpps.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<private/qcore_unix_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXNAVIGATOR_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qNavigatorDebug
define|#
directive|define
name|qNavigatorDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qNavigatorDebug
define|#
directive|define
name|qNavigatorDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|navigatorControlPath
specifier|static
specifier|const
name|char
modifier|*
name|navigatorControlPath
init|=
literal|"/pps/services/navigator/control"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ppsBufferSize
specifier|static
specifier|const
name|int
name|ppsBufferSize
init|=
literal|4096
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxNavigatorPps
name|QQnxNavigatorPps
operator|::
name|QQnxNavigatorPps
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QQnxAbstractNavigator
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_fd
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QQnxNavigatorPps
name|QQnxNavigatorPps
operator|::
name|~
name|QQnxNavigatorPps
parameter_list|()
block|{
comment|// close connection to navigator
if|if
condition|(
name|m_fd
operator|!=
operator|-
literal|1
condition|)
name|qt_safe_close
argument_list|(
name|m_fd
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|openPpsConnection
name|bool
name|QQnxNavigatorPps
operator|::
name|openPpsConnection
parameter_list|()
block|{
if|if
condition|(
name|m_fd
operator|!=
operator|-
literal|1
condition|)
return|return
literal|true
return|;
comment|// open connection to navigator
name|errno
operator|=
literal|0
expr_stmt|;
name|m_fd
operator|=
name|qt_safe_open
argument_list|(
name|navigatorControlPath
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_fd
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QQNX: failed to open navigator pps, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|qNavigatorDebug
argument_list|()
operator|<<
literal|"successfully connected to Navigator. fd="
operator|<<
name|m_fd
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|requestInvokeUrl
name|bool
name|QQnxNavigatorPps
operator|::
name|requestInvokeUrl
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|encodedUrl
parameter_list|)
block|{
if|if
condition|(
operator|!
name|openPpsConnection
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
name|sendPpsMessage
argument_list|(
literal|"invoke"
argument_list|,
name|encodedUrl
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sendPpsMessage
name|bool
name|QQnxNavigatorPps
operator|::
name|sendPpsMessage
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|message
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
block|{
name|QByteArray
name|ppsMessage
init|=
literal|"msg::"
operator|+
name|message
decl_stmt|;
if|if
condition|(
operator|!
name|data
operator|.
name|isEmpty
argument_list|()
condition|)
name|ppsMessage
operator|+=
literal|"\ndat::"
operator|+
name|data
expr_stmt|;
name|ppsMessage
operator|+=
literal|"\n"
expr_stmt|;
name|qNavigatorDebug
argument_list|()
operator|<<
literal|"sending PPS message:\n"
operator|<<
name|ppsMessage
expr_stmt|;
comment|// send pps message to navigator
name|errno
operator|=
literal|0
expr_stmt|;
name|int
name|bytes
init|=
name|qt_safe_write
argument_list|(
name|m_fd
argument_list|,
name|ppsMessage
operator|.
name|constData
argument_list|()
argument_list|,
name|ppsMessage
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|bytes
operator|==
operator|-
literal|1
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"QQNX: failed to write navigator pps, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
comment|// allocate buffer for pps data
name|char
name|buffer
index|[
name|ppsBufferSize
index|]
decl_stmt|;
comment|// attempt to read pps data
do|do
block|{
name|errno
operator|=
literal|0
expr_stmt|;
name|bytes
operator|=
name|qt_safe_read
argument_list|(
name|m_fd
argument_list|,
name|buffer
argument_list|,
name|ppsBufferSize
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|bytes
operator|==
operator|-
literal|1
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"QQNX: failed to read navigator pps, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|bytes
operator|==
literal|0
condition|)
do|;
comment|// ensure data is null terminated
name|buffer
index|[
name|bytes
index|]
operator|=
literal|'\0'
expr_stmt|;
name|qNavigatorDebug
argument_list|()
operator|<<
literal|"received PPS message:\n"
operator|<<
name|buffer
expr_stmt|;
comment|// process received message
name|QByteArray
name|ppsData
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
name|QHash
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
name|responseFields
decl_stmt|;
name|parsePPS
argument_list|(
name|ppsData
argument_list|,
name|responseFields
argument_list|)
expr_stmt|;
if|if
condition|(
name|responseFields
operator|.
name|contains
argument_list|(
literal|"res"
argument_list|)
operator|&&
name|responseFields
operator|.
name|value
argument_list|(
literal|"res"
argument_list|)
operator|==
name|message
condition|)
block|{
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|responseFields
operator|.
name|contains
argument_list|(
literal|"err"
argument_list|)
argument_list|)
condition|)
block|{
name|qCritical
argument_list|()
operator|<<
literal|"navigator responded with error: "
operator|<<
name|responseFields
operator|.
name|value
argument_list|(
literal|"err"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|parsePPS
name|void
name|QQnxNavigatorPps
operator|::
name|parsePPS
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ppsData
parameter_list|,
name|QHash
argument_list|<
name|QByteArray
argument_list|,
name|QByteArray
argument_list|>
modifier|&
name|messageFields
parameter_list|)
block|{
name|qNavigatorDebug
argument_list|()
operator|<<
literal|"data="
operator|<<
name|ppsData
expr_stmt|;
comment|// tokenize pps data into lines
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|lines
init|=
name|ppsData
operator|.
name|split
argument_list|(
literal|'\n'
argument_list|)
decl_stmt|;
comment|// validate pps object
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|lines
operator|.
name|empty
argument_list|()
operator|||
name|lines
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|!=
literal|"@control"
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"QQNX: unrecognized pps object, data=%s"
argument_list|,
name|ppsData
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
comment|// parse pps object attributes and extract values
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|lines
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
comment|// tokenize current attribute
specifier|const
name|QByteArray
modifier|&
name|attr
init|=
name|lines
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|qNavigatorDebug
argument_list|()
operator|<<
literal|"attr="
operator|<<
name|attr
expr_stmt|;
name|int
name|firstColon
init|=
name|attr
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|)
decl_stmt|;
if|if
condition|(
name|firstColon
operator|==
operator|-
literal|1
condition|)
block|{
comment|// abort - malformed attribute
continue|continue;
block|}
name|int
name|secondColon
init|=
name|attr
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|,
name|firstColon
operator|+
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|secondColon
operator|==
operator|-
literal|1
condition|)
block|{
comment|// abort - malformed attribute
continue|continue;
block|}
name|QByteArray
name|key
init|=
name|attr
operator|.
name|left
argument_list|(
name|firstColon
argument_list|)
decl_stmt|;
name|QByteArray
name|value
init|=
name|attr
operator|.
name|mid
argument_list|(
name|secondColon
operator|+
literal|1
argument_list|)
decl_stmt|;
name|qNavigatorDebug
argument_list|()
operator|<<
literal|"key="
operator|<<
name|key
expr_stmt|;
name|qNavigatorDebug
argument_list|()
operator|<<
literal|"val="
operator|<<
name|value
expr_stmt|;
name|messageFields
index|[
name|key
index|]
operator|=
name|value
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
