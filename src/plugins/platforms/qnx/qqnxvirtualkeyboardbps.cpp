begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxvirtualkeyboardbps.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<bps/event.h>
end_include
begin_include
include|#
directive|include
file|<bps/locale.h>
end_include
begin_include
include|#
directive|include
file|<bps/virtualkeyboard.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
end_if
begin_include
include|#
directive|include
file|<bbndk.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
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
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxVirtualKeyboardBps
name|QQnxVirtualKeyboardBps
operator|::
name|QQnxVirtualKeyboardBps
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QQnxAbstractVirtualKeyboard
argument_list|(
name|parent
argument_list|)
block|{
if|if
condition|(
name|locale_request_events
argument_list|(
literal|0
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QQNX: Failed to register for locale events"
argument_list|)
expr_stmt|;
if|if
condition|(
name|virtualkeyboard_request_events
argument_list|(
literal|0
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QQNX: Failed to register for virtual keyboard events"
argument_list|)
expr_stmt|;
name|int
name|height
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|virtualkeyboard_get_height
argument_list|(
operator|&
name|height
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QQNX: Failed to get virtual keyboard height"
argument_list|)
expr_stmt|;
name|setHeight
argument_list|(
name|height
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|handleEvent
name|bool
name|QQnxVirtualKeyboardBps
operator|::
name|handleEvent
parameter_list|(
name|bps_event_t
modifier|*
name|event
parameter_list|)
block|{
specifier|const
name|int
name|eventDomain
init|=
name|bps_event_get_domain
argument_list|(
name|event
argument_list|)
decl_stmt|;
if|if
condition|(
name|eventDomain
operator|==
name|locale_get_domain
argument_list|()
condition|)
return|return
name|handleLocaleEvent
argument_list|(
name|event
argument_list|)
return|;
if|if
condition|(
name|eventDomain
operator|==
name|virtualkeyboard_get_domain
argument_list|()
condition|)
return|return
name|handleVirtualKeyboardEvent
argument_list|(
name|event
argument_list|)
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|showKeyboard
name|bool
name|QQnxVirtualKeyboardBps
operator|::
name|showKeyboard
parameter_list|()
block|{
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"current visibility="
operator|<<
name|isVisible
argument_list|()
expr_stmt|;
comment|// They keyboard's mode is global between applications, we have to set it each time
if|if
condition|(
operator|!
name|isVisible
argument_list|()
condition|)
name|applyKeyboardOptions
argument_list|()
expr_stmt|;
name|virtualkeyboard_show
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|hideKeyboard
name|bool
name|QQnxVirtualKeyboardBps
operator|::
name|hideKeyboard
parameter_list|()
block|{
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"current visibility="
operator|<<
name|isVisible
argument_list|()
expr_stmt|;
name|virtualkeyboard_hide
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|applyKeyboardOptions
name|void
name|QQnxVirtualKeyboardBps
operator|::
name|applyKeyboardOptions
parameter_list|()
block|{
name|virtualkeyboard_layout_t
name|layout
init|=
name|keyboardLayout
argument_list|()
decl_stmt|;
name|virtualkeyboard_enter_t
name|enter
init|=
name|enterKey
argument_list|()
decl_stmt|;
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"mode="
operator|<<
name|keyboardMode
argument_list|()
operator|<<
literal|"enterKey="
operator|<<
name|enterKeyType
argument_list|()
expr_stmt|;
name|virtualkeyboard_change_options
argument_list|(
name|layout
argument_list|,
name|enter
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyboardLayout
name|virtualkeyboard_layout_t
name|QQnxVirtualKeyboardBps
operator|::
name|keyboardLayout
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
name|VIRTUALKEYBOARD_LAYOUT_URL
return|;
case|case
name|Email
case|:
return|return
name|VIRTUALKEYBOARD_LAYOUT_EMAIL
return|;
case|case
name|Web
case|:
return|return
name|VIRTUALKEYBOARD_LAYOUT_WEB
return|;
case|case
name|NumPunc
case|:
return|return
name|VIRTUALKEYBOARD_LAYOUT_NUM_PUNC
return|;
case|case
name|Number
case|:
return|return
name|VIRTUALKEYBOARD_LAYOUT_NUMBER
return|;
case|case
name|Symbol
case|:
return|return
name|VIRTUALKEYBOARD_LAYOUT_SYMBOL
return|;
case|case
name|Phone
case|:
return|return
name|VIRTUALKEYBOARD_LAYOUT_PHONE
return|;
case|case
name|Pin
case|:
return|return
name|VIRTUALKEYBOARD_LAYOUT_PIN
return|;
case|case
name|Password
case|:
return|return
name|VIRTUALKEYBOARD_LAYOUT_PASSWORD
return|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BLACKBERRY
argument_list|)
if|#
directive|if
name|BBNDK_VERSION_AT_LEAST
argument_list|(
literal|10
operator|,
literal|2
operator|,
literal|1
argument_list|)
case|case
name|Alphanumeric
case|:
return|return
name|VIRTUALKEYBOARD_LAYOUT_ALPHANUMERIC
return|;
endif|#
directive|endif
endif|#
directive|endif
case|case
name|Default
case|:
comment|// fall through
default|default:
return|return
name|VIRTUALKEYBOARD_LAYOUT_DEFAULT
return|;
block|}
return|return
name|VIRTUALKEYBOARD_LAYOUT_DEFAULT
return|;
block|}
end_function
begin_function
DECL|function|enterKey
name|virtualkeyboard_enter_t
name|QQnxVirtualKeyboardBps
operator|::
name|enterKey
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
name|Connect
case|:
return|return
name|VIRTUALKEYBOARD_ENTER_CONNECT
return|;
case|case
name|Done
case|:
return|return
name|VIRTUALKEYBOARD_ENTER_DONE
return|;
case|case
name|Go
case|:
return|return
name|VIRTUALKEYBOARD_ENTER_GO
return|;
case|case
name|Join
case|:
return|return
name|VIRTUALKEYBOARD_ENTER_JOIN
return|;
case|case
name|Next
case|:
return|return
name|VIRTUALKEYBOARD_ENTER_NEXT
return|;
case|case
name|Search
case|:
return|return
name|VIRTUALKEYBOARD_ENTER_SEARCH
return|;
case|case
name|Send
case|:
return|return
name|VIRTUALKEYBOARD_ENTER_SEND
return|;
case|case
name|Submit
case|:
return|return
name|VIRTUALKEYBOARD_ENTER_SUBMIT
return|;
case|case
name|Default
case|:
comment|// fall through
default|default:
return|return
name|VIRTUALKEYBOARD_ENTER_DEFAULT
return|;
block|}
return|return
name|VIRTUALKEYBOARD_ENTER_DEFAULT
return|;
block|}
end_function
begin_function
DECL|function|handleLocaleEvent
name|bool
name|QQnxVirtualKeyboardBps
operator|::
name|handleLocaleEvent
parameter_list|(
name|bps_event_t
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|bps_event_get_code
argument_list|(
name|event
argument_list|)
operator|==
name|LOCALE_INFO
condition|)
block|{
specifier|const
name|QString
name|language
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|locale_event_get_language
argument_list|(
name|event
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|country
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|locale_event_get_country
argument_list|(
name|event
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QLocale
name|newLocale
argument_list|(
name|language
operator|+
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
operator|+
name|country
argument_list|)
decl_stmt|;
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"current locale"
operator|<<
name|locale
argument_list|()
operator|<<
literal|"new locale="
operator|<<
name|newLocale
expr_stmt|;
name|setLocale
argument_list|(
name|newLocale
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"Unhandled locale event. code="
operator|<<
name|bps_event_get_code
argument_list|(
name|event
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|handleVirtualKeyboardEvent
name|bool
name|QQnxVirtualKeyboardBps
operator|::
name|handleVirtualKeyboardEvent
parameter_list|(
name|bps_event_t
modifier|*
name|event
parameter_list|)
block|{
switch|switch
condition|(
name|bps_event_get_code
argument_list|(
name|event
argument_list|)
condition|)
block|{
case|case
name|VIRTUALKEYBOARD_EVENT_VISIBLE
case|:
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"EVENT VISIBLE: current visibility="
operator|<<
name|isVisible
argument_list|()
expr_stmt|;
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
break|break;
case|case
name|VIRTUALKEYBOARD_EVENT_HIDDEN
case|:
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"EVENT HIDDEN: current visibility="
operator|<<
name|isVisible
argument_list|()
expr_stmt|;
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
break|break;
case|case
name|VIRTUALKEYBOARD_EVENT_INFO
case|:
block|{
specifier|const
name|int
name|newHeight
init|=
name|virtualkeyboard_event_get_height
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"EVENT INFO: current height="
operator|<<
name|height
argument_list|()
operator|<<
literal|"new height="
operator|<<
name|newHeight
expr_stmt|;
name|setHeight
argument_list|(
name|newHeight
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
name|qVirtualKeyboardDebug
argument_list|()
operator|<<
literal|"Unhandled virtual keyboard event. code="
operator|<<
name|bps_event_get_code
argument_list|(
name|event
argument_list|)
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
