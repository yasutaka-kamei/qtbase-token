begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxbpseventfilter.h"
end_include
begin_include
include|#
directive|include
file|"qqnxnavigatoreventhandler.h"
end_include
begin_include
include|#
directive|include
file|"qqnxfiledialoghelper.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreeneventhandler.h"
end_include
begin_include
include|#
directive|include
file|"qqnxvirtualkeyboardbps.h"
end_include
begin_include
include|#
directive|include
file|<QAbstractEventDispatcher>
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
file|<bps/navigator.h>
end_include
begin_include
include|#
directive|include
file|<bps/screen.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QQNXBPSEVENTFILTER_DEBUG
end_ifdef
begin_define
DECL|macro|qBpsEventFilterDebug
define|#
directive|define
name|qBpsEventFilterDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qBpsEventFilterDebug
define|#
directive|define
name|qBpsEventFilterDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|s_instance
specifier|static
name|QQnxBpsEventFilter
modifier|*
name|s_instance
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QQnxBpsEventFilter
name|QQnxBpsEventFilter
operator|::
name|QQnxBpsEventFilter
parameter_list|(
name|QQnxNavigatorEventHandler
modifier|*
name|navigatorEventHandler
parameter_list|,
name|QQnxScreenEventHandler
modifier|*
name|screenEventHandler
parameter_list|,
name|QQnxVirtualKeyboardBps
modifier|*
name|virtualKeyboard
parameter_list|,
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
name|m_navigatorEventHandler
argument_list|(
name|navigatorEventHandler
argument_list|)
member_init_list|,
name|m_screenEventHandler
argument_list|(
name|screenEventHandler
argument_list|)
member_init_list|,
name|m_virtualKeyboard
argument_list|(
name|virtualKeyboard
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|s_instance
operator|==
literal|0
argument_list|)
expr_stmt|;
name|s_instance
operator|=
name|this
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QQnxBpsEventFilter
name|QQnxBpsEventFilter
operator|::
name|~
name|QQnxBpsEventFilter
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|s_instance
operator|==
name|this
argument_list|)
expr_stmt|;
name|s_instance
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|installOnEventDispatcher
name|void
name|QQnxBpsEventFilter
operator|::
name|installOnEventDispatcher
parameter_list|(
name|QAbstractEventDispatcher
modifier|*
name|dispatcher
parameter_list|)
block|{
name|qBpsEventFilterDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"dispatcher="
operator|<<
name|dispatcher
expr_stmt|;
if|if
condition|(
name|navigator_request_events
argument_list|(
literal|0
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QQNX: failed to register for navigator events"
argument_list|)
expr_stmt|;
name|dispatcher
operator|->
name|installNativeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|registerForScreenEvents
name|void
name|QQnxBpsEventFilter
operator|::
name|registerForScreenEvents
parameter_list|(
name|QQnxScreen
modifier|*
name|screen
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_screenEventHandler
condition|)
block|{
name|qWarning
argument_list|(
literal|"QQNX: trying to register for screen events, but no handler provided."
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|screen_request_events
argument_list|(
name|screen
operator|->
name|nativeContext
argument_list|()
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QQNX: failed to register for screen events on screen %p"
argument_list|,
name|screen
operator|->
name|nativeContext
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterForScreenEvents
name|void
name|QQnxBpsEventFilter
operator|::
name|unregisterForScreenEvents
parameter_list|(
name|QQnxScreen
modifier|*
name|screen
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_screenEventHandler
condition|)
block|{
name|qWarning
argument_list|(
literal|"QQNX: trying to unregister for screen events, but no handler provided."
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|screen_stop_events
argument_list|(
name|screen
operator|->
name|nativeContext
argument_list|()
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QQNX: failed to unregister for screen events on screen %p"
argument_list|,
name|screen
operator|->
name|nativeContext
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|registerForDialogEvents
name|void
name|QQnxBpsEventFilter
operator|::
name|registerForDialogEvents
parameter_list|(
name|QQnxFileDialogHelper
modifier|*
name|dialog
parameter_list|)
block|{
if|if
condition|(
name|dialog_request_events
argument_list|(
literal|0
argument_list|)
operator|!=
name|BPS_SUCCESS
condition|)
name|qWarning
argument_list|(
literal|"QQNX: failed to register for dialog events"
argument_list|)
expr_stmt|;
name|dialog_instance_t
name|nativeDialog
init|=
name|dialog
operator|->
name|nativeDialog
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|m_dialogMapper
operator|.
name|contains
argument_list|(
name|nativeDialog
argument_list|)
condition|)
name|m_dialogMapper
operator|.
name|insert
argument_list|(
name|nativeDialog
argument_list|,
name|dialog
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterForDialogEvents
name|void
name|QQnxBpsEventFilter
operator|::
name|unregisterForDialogEvents
parameter_list|(
name|QQnxFileDialogHelper
modifier|*
name|dialog
parameter_list|)
block|{
name|int
name|count
init|=
name|m_dialogMapper
operator|.
name|remove
argument_list|(
name|dialog
operator|->
name|nativeDialog
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|count
operator|==
literal|0
condition|)
name|qWarning
argument_list|(
literal|"QQNX: attempting to unregister dialog that was not registered"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nativeEventFilter
name|bool
name|QQnxBpsEventFilter
operator|::
name|nativeEventFilter
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|eventType
parameter_list|,
name|void
modifier|*
name|message
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|eventType
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|bps_event_t
modifier|*
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
specifier|const
name|int
name|eventDomain
init|=
name|bps_event_get_domain
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|qBpsEventFilterDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"event="
operator|<<
name|event
operator|<<
literal|"domain="
operator|<<
name|eventDomain
expr_stmt|;
if|if
condition|(
name|eventDomain
operator|==
name|screen_get_domain
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|m_screenEventHandler
condition|)
block|{
name|qWarning
argument_list|(
literal|"QQNX: registered for screen events, but no handler provided."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|screen_event_t
name|screenEvent
init|=
name|screen_event_get_event
argument_list|(
name|event
argument_list|)
decl_stmt|;
return|return
name|m_screenEventHandler
operator|->
name|handleEvent
argument_list|(
name|screenEvent
argument_list|)
return|;
block|}
if|if
condition|(
name|eventDomain
operator|==
name|dialog_get_domain
argument_list|()
condition|)
block|{
name|dialog_instance_t
name|nativeDialog
init|=
name|dialog_event_get_dialog_instance
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|QQnxFileDialogHelper
modifier|*
name|dialog
init|=
name|m_dialogMapper
operator|.
name|value
argument_list|(
name|nativeDialog
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|dialog
condition|)
return|return
name|dialog
operator|->
name|handleEvent
argument_list|(
name|event
argument_list|)
return|;
block|}
if|if
condition|(
name|eventDomain
operator|==
name|navigator_get_domain
argument_list|()
condition|)
return|return
name|handleNavigatorEvent
argument_list|(
name|event
argument_list|)
return|;
if|if
condition|(
name|m_virtualKeyboard
operator|->
name|handleEvent
argument_list|(
name|event
argument_list|)
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|handleNavigatorEvent
name|bool
name|QQnxBpsEventFilter
operator|::
name|handleNavigatorEvent
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
name|NAVIGATOR_ORIENTATION_CHECK
case|:
block|{
specifier|const
name|int
name|angle
init|=
name|navigator_event_get_orientation_angle
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|qBpsEventFilterDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"ORIENTATION CHECK event. angle="
operator|<<
name|angle
expr_stmt|;
specifier|const
name|bool
name|result
init|=
name|m_navigatorEventHandler
operator|->
name|handleOrientationCheck
argument_list|(
name|angle
argument_list|)
decl_stmt|;
name|qBpsEventFilterDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"ORIENTATION CHECK event. result="
operator|<<
name|result
expr_stmt|;
comment|// reply to navigator whether orientation is acceptable
name|navigator_orientation_check_response
argument_list|(
name|event
argument_list|,
name|result
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|NAVIGATOR_ORIENTATION
case|:
block|{
specifier|const
name|int
name|angle
init|=
name|navigator_event_get_orientation_angle
argument_list|(
name|event
argument_list|)
decl_stmt|;
name|qBpsEventFilterDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"ORIENTATION event. angle="
operator|<<
name|angle
expr_stmt|;
name|m_navigatorEventHandler
operator|->
name|handleOrientationChange
argument_list|(
name|angle
argument_list|)
expr_stmt|;
name|navigator_done_orientation
argument_list|(
name|event
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|NAVIGATOR_SWIPE_DOWN
case|:
name|qBpsEventFilterDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"SWIPE DOWN event"
expr_stmt|;
name|m_navigatorEventHandler
operator|->
name|handleSwipeDown
argument_list|()
expr_stmt|;
break|break;
case|case
name|NAVIGATOR_EXIT
case|:
name|qBpsEventFilterDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"EXIT event"
expr_stmt|;
name|m_navigatorEventHandler
operator|->
name|handleExit
argument_list|()
expr_stmt|;
break|break;
case|case
name|NAVIGATOR_WINDOW_ACTIVE
case|:
block|{
name|qBpsEventFilterDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"WINDOW ACTIVE event"
expr_stmt|;
specifier|const
name|QByteArray
name|id
argument_list|(
name|navigator_event_get_groupid
argument_list|(
name|event
argument_list|)
argument_list|)
decl_stmt|;
name|m_navigatorEventHandler
operator|->
name|handleWindowGroupActivated
argument_list|(
name|id
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|NAVIGATOR_WINDOW_INACTIVE
case|:
block|{
name|qBpsEventFilterDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"WINDOW INACTIVE event"
expr_stmt|;
specifier|const
name|QByteArray
name|id
argument_list|(
name|navigator_event_get_groupid
argument_list|(
name|event
argument_list|)
argument_list|)
decl_stmt|;
name|m_navigatorEventHandler
operator|->
name|handleWindowGroupDeactivated
argument_list|(
name|id
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
name|qBpsEventFilterDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"Unhandled navigator event. code="
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
