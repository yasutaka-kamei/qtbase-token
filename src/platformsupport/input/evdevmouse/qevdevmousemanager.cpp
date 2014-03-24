begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qevdevmousemanager_p.h"
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_comment
comment|//#define QT_QPA_MOUSEMANAGER_DEBUG
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_QPA_MOUSEMANAGER_DEBUG
end_ifdef
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEvdevMouseManager
name|QEvdevMouseManager
operator|::
name|QEvdevMouseManager
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|specification
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
name|m_x
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_y
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_xoffset
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_yoffset
argument_list|(
literal|0
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|key
argument_list|)
expr_stmt|;
name|QString
name|spec
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"QT_QPA_EVDEV_MOUSE_PARAMETERS"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|spec
operator|.
name|isEmpty
argument_list|()
condition|)
name|spec
operator|=
name|specification
expr_stmt|;
name|QStringList
name|args
init|=
name|spec
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
decl_stmt|;
name|QStringList
name|devices
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|arg
decl|,
name|args
control|)
block|{
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"/dev/"
argument_list|)
argument_list|)
condition|)
block|{
comment|// if device is specified try to use it
name|devices
operator|.
name|append
argument_list|(
name|arg
argument_list|)
expr_stmt|;
name|args
operator|.
name|removeAll
argument_list|(
name|arg
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"xoffset="
argument_list|)
argument_list|)
condition|)
block|{
name|m_xoffset
operator|=
name|arg
operator|.
name|mid
argument_list|(
literal|8
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"yoffset="
argument_list|)
argument_list|)
condition|)
block|{
name|m_yoffset
operator|=
name|arg
operator|.
name|mid
argument_list|(
literal|8
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
block|}
comment|// build new specification without /dev/ elements
name|m_spec
operator|=
name|args
operator|.
name|join
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
expr_stmt|;
comment|// add all mice for devices specified in the argument list
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|device
decl|,
name|devices
control|)
name|addMouse
argument_list|(
name|device
argument_list|)
expr_stmt|;
if|if
condition|(
name|devices
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_MOUSEMANAGER_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Use device discovery"
expr_stmt|;
endif|#
directive|endif
name|m_deviceDiscovery
operator|=
name|QDeviceDiscovery
operator|::
name|create
argument_list|(
name|QDeviceDiscovery
operator|::
name|Device_Mouse
operator||
name|QDeviceDiscovery
operator|::
name|Device_Touchpad
argument_list|,
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_deviceDiscovery
condition|)
block|{
comment|// scan and add already connected keyboards
name|QStringList
name|devices
init|=
name|m_deviceDiscovery
operator|->
name|scanConnectedDevices
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|device
decl|,
name|devices
control|)
block|{
name|addMouse
argument_list|(
name|device
argument_list|)
expr_stmt|;
block|}
name|connect
argument_list|(
name|m_deviceDiscovery
argument_list|,
name|SIGNAL
argument_list|(
name|deviceDetected
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|addMouse
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_deviceDiscovery
argument_list|,
name|SIGNAL
argument_list|(
name|deviceRemoved
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|removeMouse
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QEvdevMouseManager
name|QEvdevMouseManager
operator|::
name|~
name|QEvdevMouseManager
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|m_mice
argument_list|)
expr_stmt|;
name|m_mice
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|handleMouseEvent
name|void
name|QEvdevMouseManager
operator|::
name|handleMouseEvent
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|bool
name|abs
parameter_list|,
name|Qt
operator|::
name|MouseButtons
name|buttons
parameter_list|)
block|{
comment|// update current absolute coordinates
if|if
condition|(
operator|!
name|abs
condition|)
block|{
name|m_x
operator|+=
name|x
expr_stmt|;
name|m_y
operator|+=
name|y
expr_stmt|;
block|}
else|else
block|{
name|m_x
operator|=
name|x
expr_stmt|;
name|m_y
operator|=
name|y
expr_stmt|;
block|}
comment|// clamp to screen geometry
name|QRect
name|g
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|virtualGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
name|m_x
operator|+
name|m_xoffset
operator|<
name|g
operator|.
name|left
argument_list|()
condition|)
name|m_x
operator|=
name|g
operator|.
name|left
argument_list|()
operator|-
name|m_xoffset
expr_stmt|;
elseif|else
if|if
condition|(
name|m_x
operator|+
name|m_xoffset
operator|>
name|g
operator|.
name|right
argument_list|()
condition|)
name|m_x
operator|=
name|g
operator|.
name|right
argument_list|()
operator|-
name|m_xoffset
expr_stmt|;
if|if
condition|(
name|m_y
operator|+
name|m_yoffset
operator|<
name|g
operator|.
name|top
argument_list|()
condition|)
name|m_y
operator|=
name|g
operator|.
name|top
argument_list|()
operator|-
name|m_yoffset
expr_stmt|;
elseif|else
if|if
condition|(
name|m_y
operator|+
name|m_yoffset
operator|>
name|g
operator|.
name|bottom
argument_list|()
condition|)
name|m_y
operator|=
name|g
operator|.
name|bottom
argument_list|()
operator|-
name|m_yoffset
expr_stmt|;
name|QPoint
name|pos
argument_list|(
name|m_x
operator|+
name|m_xoffset
argument_list|,
name|m_y
operator|+
name|m_yoffset
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
literal|0
argument_list|,
name|pos
argument_list|,
name|pos
argument_list|,
name|buttons
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_QPA_MOUSEMANAGER_DEBUG
name|qDebug
argument_list|(
literal|"mouse event %d %d %d"
argument_list|,
name|pos
operator|.
name|x
argument_list|()
argument_list|,
name|pos
operator|.
name|y
argument_list|()
argument_list|,
name|int
argument_list|(
name|buttons
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|handleWheelEvent
name|void
name|QEvdevMouseManager
operator|::
name|handleWheelEvent
parameter_list|(
name|int
name|delta
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|)
block|{
name|QPoint
name|pos
argument_list|(
name|m_x
operator|+
name|m_xoffset
argument_list|,
name|m_y
operator|+
name|m_yoffset
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleWheelEvent
argument_list|(
literal|0
argument_list|,
name|pos
argument_list|,
name|pos
argument_list|,
name|delta
argument_list|,
name|orientation
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_QPA_MOUSEMANAGER_DEBUG
name|qDebug
argument_list|(
literal|"mouse wheel event %dx%d %d %d"
argument_list|,
name|pos
operator|.
name|x
argument_list|()
argument_list|,
name|pos
operator|.
name|y
argument_list|()
argument_list|,
name|delta
argument_list|,
name|int
argument_list|(
name|orientation
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|addMouse
name|void
name|QEvdevMouseManager
operator|::
name|addMouse
parameter_list|(
specifier|const
name|QString
modifier|&
name|deviceNode
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_MOUSEMANAGER_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Adding mouse at"
operator|<<
name|deviceNode
expr_stmt|;
endif|#
directive|endif
name|QEvdevMouseHandler
modifier|*
name|handler
decl_stmt|;
name|handler
operator|=
name|QEvdevMouseHandler
operator|::
name|create
argument_list|(
name|deviceNode
argument_list|,
name|m_spec
argument_list|)
expr_stmt|;
if|if
condition|(
name|handler
condition|)
block|{
name|connect
argument_list|(
name|handler
argument_list|,
name|SIGNAL
argument_list|(
name|handleMouseEvent
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|bool
argument_list|,
name|Qt
operator|::
name|MouseButtons
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|handleMouseEvent
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|bool
argument_list|,
name|Qt
operator|::
name|MouseButtons
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|handler
argument_list|,
name|SIGNAL
argument_list|(
name|handleWheelEvent
argument_list|(
name|int
argument_list|,
name|Qt
operator|::
name|Orientation
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|handleWheelEvent
argument_list|(
name|int
argument_list|,
name|Qt
operator|::
name|Orientation
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_mice
operator|.
name|insert
argument_list|(
name|deviceNode
argument_list|,
name|handler
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"Failed to open mouse"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|removeMouse
name|void
name|QEvdevMouseManager
operator|::
name|removeMouse
parameter_list|(
specifier|const
name|QString
modifier|&
name|deviceNode
parameter_list|)
block|{
if|if
condition|(
name|m_mice
operator|.
name|contains
argument_list|(
name|deviceNode
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|QT_QPA_MOUSEMANAGER_DEBUG
name|qWarning
argument_list|()
operator|<<
literal|"Removing mouse at"
operator|<<
name|deviceNode
expr_stmt|;
endif|#
directive|endif
name|QEvdevMouseHandler
modifier|*
name|handler
init|=
name|m_mice
operator|.
name|value
argument_list|(
name|deviceNode
argument_list|)
decl_stmt|;
name|m_mice
operator|.
name|remove
argument_list|(
name|deviceNode
argument_list|)
expr_stmt|;
operator|delete
name|handler
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
