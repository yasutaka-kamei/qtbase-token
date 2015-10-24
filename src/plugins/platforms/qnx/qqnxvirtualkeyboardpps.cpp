begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxvirtualkeyboardpps.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcore_unix_p.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<sys/iomsg.h>
end_include
begin_include
include|#
directive|include
file|<sys/pps.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXVIRTUALKEYBOARD_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qVirtualKeyboardDebug
define|#
directive|define
name|qVirtualKeyboardDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qVirtualKeyboardDebug
define|#
directive|define
name|qVirtualKeyboardDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|ms_PPSPath
specifier|const
name|char
modifier|*
name|QQnxVirtualKeyboardPps
operator|::
name|ms_PPSPath
init|=
literal|"/pps/services/input/control"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|ms_bufferSize
specifier|const
name|size_t
name|QQnxVirtualKeyboardPps
operator|::
name|ms_bufferSize
init|=
literal|2048
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QQnxVirtualKeyboardPps
name|QQnxVirtualKeyboardPps
operator|::
name|QQnxVirtualKeyboardPps
parameter_list|()
member_init_list|:
name|m_encoder
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_decoder
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_buffer
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_fd
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_readNotifier
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QQnxVirtualKeyboardPps
name|QQnxVirtualKeyboardPps
operator|::
name|~
name|QQnxVirtualKeyboardPps
parameter_list|()
block|{
name|close
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|start
name|void
name|QQnxVirtualKeyboardPps
operator|::
name|start
parameter_list|()
block|{
name|qVirtualKeyboardDebug
argument_list|(
literal|"starting keyboard event processing"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|connect
argument_list|()
condition|)
return|return;
block|}
end_function
begin_function
DECL|function|close
name|void
name|QQnxVirtualKeyboardPps
operator|::
name|close
parameter_list|()
block|{
operator|delete
name|m_readNotifier
expr_stmt|;
name|m_readNotifier
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|m_fd
operator|!=
operator|-
literal|1
condition|)
block|{
operator|::
name|close
argument_list|(
name|m_fd
argument_list|)
expr_stmt|;
name|m_fd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|m_decoder
condition|)
block|{
name|pps_decoder_cleanup
argument_list|(
name|m_decoder
argument_list|)
expr_stmt|;
operator|delete
name|m_decoder
expr_stmt|;
name|m_decoder
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|m_encoder
condition|)
block|{
name|pps_encoder_cleanup
argument_list|(
name|m_encoder
argument_list|)
expr_stmt|;
operator|delete
name|m_encoder
expr_stmt|;
name|m_encoder
operator|=
literal|0
expr_stmt|;
block|}
operator|delete
index|[]
name|m_buffer
expr_stmt|;
name|m_buffer
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|connect
name|bool
name|QQnxVirtualKeyboardPps
operator|::
name|connect
parameter_list|()
block|{
name|close
argument_list|()
expr_stmt|;
name|m_encoder
operator|=
operator|new
name|pps_encoder_t
expr_stmt|;
name|m_decoder
operator|=
operator|new
name|pps_decoder_t
expr_stmt|;
name|pps_encoder_initialize
argument_list|(
name|m_encoder
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|pps_decoder_initialize
argument_list|(
name|m_decoder
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|m_fd
operator|=
operator|::
name|open
argument_list|(
name|ms_PPSPath
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
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"Unable to open"
operator|<<
name|ms_PPSPath
operator|<<
literal|':'
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
expr_stmt|;
name|close
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
name|m_buffer
operator|=
operator|new
name|char
index|[
name|ms_bufferSize
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|m_buffer
condition|)
block|{
name|qCritical
argument_list|(
literal|"QQnxVirtualKeyboard: Unable to allocate buffer of %d bytes. "
literal|"Size is unavailable."
argument_list|,
name|ms_bufferSize
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|!
name|queryPPSInfo
argument_list|()
condition|)
return|return
literal|false
return|;
name|m_readNotifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|m_fd
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|m_readNotifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|ppsDataReady
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|queryPPSInfo
name|bool
name|QQnxVirtualKeyboardPps
operator|::
name|queryPPSInfo
parameter_list|()
block|{
if|if
condition|(
operator|!
name|prepareToSend
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// Request info, requires id to regenerate res message.
name|pps_encoder_add_string
argument_list|(
name|m_encoder
argument_list|,
literal|"msg"
argument_list|,
literal|"info"
argument_list|)
expr_stmt|;
name|pps_encoder_add_string
argument_list|(
name|m_encoder
argument_list|,
literal|"id"
argument_list|,
literal|"1"
argument_list|)
expr_stmt|;
return|return
name|writeCurrentPPSEncoder
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|ppsDataReady
name|void
name|QQnxVirtualKeyboardPps
operator|::
name|ppsDataReady
parameter_list|()
block|{
name|ssize_t
name|nread
init|=
name|qt_safe_read
argument_list|(
name|m_fd
argument_list|,
name|m_buffer
argument_list|,
name|ms_bufferSize
operator|-
literal|1
argument_list|)
decl_stmt|;
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"keyboardMessage size: "
operator|<<
name|nread
expr_stmt|;
if|if
condition|(
name|nread
operator|<
literal|0
condition|)
block|{
name|connect
argument_list|()
expr_stmt|;
comment|// reconnect
return|return;
block|}
comment|// We sometimes get spurious read notifications when no data is available.
comment|// Bail out early in this case
if|if
condition|(
name|nread
operator|==
literal|0
condition|)
return|return;
comment|// nread is the real space necessary, not the amount read.
if|if
condition|(
cast|static_cast
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|nread
argument_list|)
operator|>
name|ms_bufferSize
operator|-
literal|1
condition|)
block|{
name|qCritical
argument_list|(
literal|"QQnxVirtualKeyboard: Keyboard buffer size too short; need %u."
argument_list|,
name|nread
operator|+
literal|1
argument_list|)
expr_stmt|;
name|connect
argument_list|()
expr_stmt|;
comment|// reconnect
return|return;
block|}
name|m_buffer
index|[
name|nread
index|]
operator|=
literal|0
expr_stmt|;
name|pps_decoder_parse_pps_str
argument_list|(
name|m_decoder
argument_list|,
name|m_buffer
argument_list|)
expr_stmt|;
name|pps_decoder_push
argument_list|(
name|m_decoder
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QQNXVIRTUALKEYBOARD_DEBUG
argument_list|)
name|pps_decoder_dump_tree
argument_list|(
name|m_decoder
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
specifier|const
name|char
modifier|*
name|value
decl_stmt|;
if|if
condition|(
name|pps_decoder_get_string
argument_list|(
name|m_decoder
argument_list|,
literal|"error"
argument_list|,
operator|&
name|value
argument_list|)
operator|==
name|PPS_DECODER_OK
condition|)
block|{
name|qCritical
argument_list|(
literal|"QQnxVirtualKeyboard: Keyboard PPS decoder error: %s"
argument_list|,
name|value
condition|?
name|value
else|:
literal|"[null]"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|pps_decoder_get_string
argument_list|(
name|m_decoder
argument_list|,
literal|"msg"
argument_list|,
operator|&
name|value
argument_list|)
operator|==
name|PPS_DECODER_OK
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|value
argument_list|,
literal|"show"
argument_list|)
operator|==
literal|0
condition|)
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|value
argument_list|,
literal|"hide"
argument_list|)
operator|==
literal|0
condition|)
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|value
argument_list|,
literal|"info"
argument_list|)
operator|==
literal|0
condition|)
name|handleKeyboardInfoMessage
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|value
argument_list|,
literal|"connect"
argument_list|)
operator|==
literal|0
condition|)
name|qVirtualKeyboardDebug
argument_list|(
literal|"Unhandled command 'connect'"
argument_list|)
expr_stmt|;
else|else
name|qCritical
argument_list|(
literal|"QQnxVirtualKeyboard: Unexpected keyboard PPS msg value: %s"
argument_list|,
name|value
condition|?
name|value
else|:
literal|"[null]"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pps_decoder_get_string
argument_list|(
name|m_decoder
argument_list|,
literal|"res"
argument_list|,
operator|&
name|value
argument_list|)
operator|==
name|PPS_DECODER_OK
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|value
argument_list|,
literal|"info"
argument_list|)
operator|==
literal|0
condition|)
name|handleKeyboardInfoMessage
argument_list|()
expr_stmt|;
else|else
name|qCritical
argument_list|(
literal|"QQnxVirtualKeyboard: Unexpected keyboard PPS res value: %s"
argument_list|,
name|value
condition|?
name|value
else|:
literal|"[null]"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qCritical
argument_list|(
literal|"QQnxVirtualKeyboard: Unexpected keyboard PPS message type"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handleKeyboardInfoMessage
name|void
name|QQnxVirtualKeyboardPps
operator|::
name|handleKeyboardInfoMessage
parameter_list|()
block|{
name|int
name|newHeight
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|pps_decoder_push
argument_list|(
name|m_decoder
argument_list|,
literal|"dat"
argument_list|)
operator|!=
name|PPS_DECODER_OK
condition|)
block|{
name|qCritical
argument_list|(
literal|"QQnxVirtualKeyboard: Keyboard PPS dat object not found"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|pps_decoder_get_int
argument_list|(
name|m_decoder
argument_list|,
literal|"size"
argument_list|,
operator|&
name|newHeight
argument_list|)
operator|!=
name|PPS_DECODER_OK
condition|)
block|{
name|qCritical
argument_list|(
literal|"QQnxVirtualKeyboard: Keyboard PPS size field not found"
argument_list|)
expr_stmt|;
return|return;
block|}
name|setHeight
argument_list|(
name|newHeight
argument_list|)
expr_stmt|;
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"size="
operator|<<
name|newHeight
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showKeyboard
name|bool
name|QQnxVirtualKeyboardPps
operator|::
name|showKeyboard
parameter_list|()
block|{
name|qVirtualKeyboardDebug
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|prepareToSend
argument_list|()
condition|)
return|return
literal|false
return|;
comment|// NOTE:  This must be done everytime the keyboard is shown even if there is no change because
comment|// hiding the keyboard wipes the setting.
name|applyKeyboardOptions
argument_list|()
expr_stmt|;
if|if
condition|(
name|isVisible
argument_list|()
condition|)
return|return
literal|true
return|;
name|pps_encoder_reset
argument_list|(
name|m_encoder
argument_list|)
expr_stmt|;
comment|// Send the show message.
name|pps_encoder_add_string
argument_list|(
name|m_encoder
argument_list|,
literal|"msg"
argument_list|,
literal|"show"
argument_list|)
expr_stmt|;
return|return
name|writeCurrentPPSEncoder
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|hideKeyboard
name|bool
name|QQnxVirtualKeyboardPps
operator|::
name|hideKeyboard
parameter_list|()
block|{
name|qVirtualKeyboardDebug
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|prepareToSend
argument_list|()
condition|)
return|return
literal|false
return|;
name|pps_encoder_add_string
argument_list|(
name|m_encoder
argument_list|,
literal|"msg"
argument_list|,
literal|"hide"
argument_list|)
expr_stmt|;
return|return
name|writeCurrentPPSEncoder
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|prepareToSend
name|bool
name|QQnxVirtualKeyboardPps
operator|::
name|prepareToSend
parameter_list|()
block|{
if|if
condition|(
name|m_fd
operator|==
operator|-
literal|1
operator|&&
operator|!
name|connect
argument_list|()
condition|)
return|return
literal|false
return|;
name|pps_encoder_reset
argument_list|(
name|m_encoder
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|writeCurrentPPSEncoder
name|bool
name|QQnxVirtualKeyboardPps
operator|::
name|writeCurrentPPSEncoder
parameter_list|()
block|{
if|if
condition|(
operator|::
name|write
argument_list|(
name|m_fd
argument_list|,
name|pps_encoder_buffer
argument_list|(
name|m_encoder
argument_list|)
argument_list|,
name|pps_encoder_length
argument_list|(
name|m_encoder
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|close
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|applyKeyboardOptions
name|void
name|QQnxVirtualKeyboardPps
operator|::
name|applyKeyboardOptions
parameter_list|()
block|{
if|if
condition|(
operator|!
name|prepareToSend
argument_list|()
condition|)
return|return;
comment|// Send the options message.
name|pps_encoder_add_string
argument_list|(
name|m_encoder
argument_list|,
literal|"msg"
argument_list|,
literal|"options"
argument_list|)
expr_stmt|;
name|pps_encoder_start_object
argument_list|(
name|m_encoder
argument_list|,
literal|"dat"
argument_list|)
expr_stmt|;
name|pps_encoder_add_string
argument_list|(
name|m_encoder
argument_list|,
literal|"enter"
argument_list|,
name|enterKeyTypeStr
argument_list|()
argument_list|)
expr_stmt|;
name|pps_encoder_add_string
argument_list|(
name|m_encoder
argument_list|,
literal|"type"
argument_list|,
name|keyboardModeStr
argument_list|()
argument_list|)
expr_stmt|;
name|pps_encoder_end_object
argument_list|(
name|m_encoder
argument_list|)
expr_stmt|;
name|writeCurrentPPSEncoder
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyboardModeStr
specifier|const
name|char
modifier|*
name|QQnxVirtualKeyboardPps
operator|::
name|keyboardModeStr
parameter_list|()
specifier|const
block|{
switch|switch
condition|(
name|keyboardMode
argument_list|()
condition|)
block|{
case|case
name|Url
case|:
return|return
literal|"url"
return|;
case|case
name|Email
case|:
return|return
literal|"email"
return|;
case|case
name|Web
case|:
return|return
literal|"web"
return|;
case|case
name|NumPunc
case|:
return|return
literal|"num_punc"
return|;
case|case
name|Number
case|:
return|return
literal|"number"
return|;
case|case
name|Symbol
case|:
return|return
literal|"symbol"
return|;
case|case
name|Phone
case|:
return|return
literal|"phone"
return|;
case|case
name|Pin
case|:
return|return
literal|"pin"
return|;
case|case
name|Password
case|:
return|return
literal|"password"
return|;
case|case
name|Alphanumeric
case|:
return|return
literal|"alphanumeric"
return|;
case|case
name|Default
case|:
return|return
literal|"default"
return|;
block|}
return|return
literal|""
return|;
block|}
end_function
begin_function
DECL|function|enterKeyTypeStr
specifier|const
name|char
modifier|*
name|QQnxVirtualKeyboardPps
operator|::
name|enterKeyTypeStr
parameter_list|()
specifier|const
block|{
switch|switch
condition|(
name|enterKeyType
argument_list|()
condition|)
block|{
case|case
name|DefaultReturn
case|:
return|return
literal|"enter.default"
return|;
case|case
name|Connect
case|:
return|return
literal|"enter.connect"
return|;
case|case
name|Done
case|:
return|return
literal|"enter.done"
return|;
case|case
name|Go
case|:
return|return
literal|"enter.go"
return|;
case|case
name|Join
case|:
return|return
literal|"enter.join"
return|;
case|case
name|Next
case|:
return|return
literal|"enter.next"
return|;
case|case
name|Search
case|:
return|return
literal|"enter.search"
return|;
case|case
name|Send
case|:
return|return
literal|"enter.send"
return|;
case|case
name|Submit
case|:
return|return
literal|"enter.submit"
return|;
block|}
return|return
literal|""
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
