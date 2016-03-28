begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Green Hills Software ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qintegrityhidmanager.h"
end_include
begin_include
include|#
directive|include
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QPoint>
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<device/hiddriver.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|IntNotifier
class|class
name|IntNotifier
block|{
DECL|member|ActivityPriority
specifier|static
specifier|const
name|Value
name|ActivityPriority
init|=
literal|2
decl_stmt|;
protected|protected:
DECL|member|act
name|Activity
name|act
decl_stmt|;
public|public:
DECL|function|IntNotifier
name|IntNotifier
parameter_list|()
block|{
name|CheckSuccess
argument_list|(
name|CreateActivity
argument_list|(
name|CurrentTask
argument_list|()
argument_list|,
name|ActivityPriority
argument_list|,
literal|false
argument_list|,
operator|(
name|Value
operator|)
name|this
argument_list|,
operator|&
name|act
argument_list|)
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
DECL|function|~IntNotifier
name|~
name|IntNotifier
parameter_list|()
block|{
name|CheckSuccess
argument_list|(
name|CloseActivity
argument_list|(
name|act
argument_list|)
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
specifier|virtual
name|void
name|process_event
parameter_list|()
function_decl|=
literal|0
function_decl|;
specifier|virtual
name|void
name|async_wait
parameter_list|()
function_decl|=
literal|0
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|HIDDeviceHandler
class|class
name|HIDDeviceHandler
super|:
name|IntNotifier
block|{
public|public:
DECL|function|HIDDeviceHandler
name|HIDDeviceHandler
parameter_list|(
name|HIDDriver
modifier|*
name|hidd
parameter_list|,
name|HIDHandle
name|hidh
parameter_list|)
member_init_list|:
name|driver
argument_list|(
name|hidd
argument_list|)
member_init_list|,
name|handle
argument_list|(
name|hidh
argument_list|)
member_init_list|,
name|currentPos
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
block|{ }
DECL|function|~HIDDeviceHandler
name|~
name|HIDDeviceHandler
parameter_list|()
block|{
name|CheckSuccess
argument_list|(
name|gh_hid_close
argument_list|(
name|handle
argument_list|)
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
DECL|member|Q_DECL_OVERRIDE
name|void
name|process_event
parameter_list|(
name|void
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|Q_DECL_OVERRIDE
name|void
name|async_wait
parameter_list|(
name|void
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
DECL|function|get_driver
name|HIDDriver
modifier|*
name|get_driver
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|driver
return|;
block|}
empty_stmt|;
DECL|function|get_handle
name|HIDHandle
name|get_handle
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|handle
return|;
block|}
empty_stmt|;
private|private:
DECL|member|driver
name|HIDDriver
modifier|*
name|driver
decl_stmt|;
DECL|member|handle
name|HIDHandle
name|handle
decl_stmt|;
DECL|member|currentPos
name|QPoint
name|currentPos
decl_stmt|;
DECL|member|buttons
name|Qt
operator|::
name|MouseButtons
name|buttons
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|HIDDriverHandler
class|class
name|HIDDriverHandler
super|:
name|IntNotifier
block|{
public|public:
DECL|function|HIDDriverHandler
name|HIDDriverHandler
parameter_list|(
name|HIDDriver
modifier|*
name|hidd
parameter_list|)
member_init_list|:
name|IntNotifier
argument_list|()
member_init_list|,
name|driver
argument_list|(
name|hidd
argument_list|)
block|{ }
DECL|function|~HIDDriverHandler
name|~
name|HIDDriverHandler
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|devices
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
DECL|member|Q_DECL_OVERRIDE
name|void
name|process_event
parameter_list|(
name|void
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|Q_DECL_OVERRIDE
name|void
name|async_wait
parameter_list|(
name|void
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
name|void
name|find_devices
parameter_list|(
name|void
parameter_list|)
function_decl|;
private|private:
DECL|member|devices
name|QHash
argument_list|<
name|Value
argument_list|,
name|HIDDeviceHandler
modifier|*
argument_list|>
name|devices
decl_stmt|;
DECL|member|driver
name|HIDDriver
modifier|*
name|driver
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|process_event
name|void
name|HIDDriverHandler
operator|::
name|process_event
parameter_list|()
block|{
name|find_devices
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|async_wait
name|void
name|HIDDriverHandler
operator|::
name|async_wait
parameter_list|()
block|{
name|gh_hid_wait_for_new_device
argument_list|(
name|driver
argument_list|,
name|act
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|find_devices
name|void
name|HIDDriverHandler
operator|::
name|find_devices
parameter_list|()
block|{
name|Error
name|err
decl_stmt|;
name|uintptr_t
name|devicecontext
decl_stmt|;
name|uint32_t
name|device_id
decl_stmt|;
name|HIDHandle
name|handle
decl_stmt|;
name|HIDDeviceHandler
modifier|*
name|hidnot
decl_stmt|;
name|devicecontext
operator|=
literal|0
expr_stmt|;
forever|forever
block|{
name|err
operator|=
name|gh_hid_enum_devices
argument_list|(
name|driver
argument_list|,
operator|&
name|device_id
argument_list|,
operator|&
name|devicecontext
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|==
name|OperationNotImplemented
condition|)
break|break;
elseif|else
if|if
condition|(
name|err
operator|==
name|Failure
condition|)
break|break;
if|if
condition|(
operator|!
name|devices
operator|.
name|contains
argument_list|(
name|device_id
argument_list|)
condition|)
block|{
name|err
operator|=
name|gh_hid_init_device
argument_list|(
name|driver
argument_list|,
name|device_id
argument_list|,
operator|&
name|handle
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|==
name|Success
condition|)
block|{
name|hidnot
operator|=
operator|new
name|HIDDeviceHandler
argument_list|(
name|driver
argument_list|,
name|handle
argument_list|)
expr_stmt|;
name|devices
operator|.
name|insert
argument_list|(
name|device_id
argument_list|,
name|hidnot
argument_list|)
expr_stmt|;
name|hidnot
operator|->
name|async_wait
argument_list|()
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|err
operator|==
name|OperationNotImplemented
condition|)
block|{
comment|/* fallback on legacy enumeration where we assume 0-based          * contiguous indexes */
name|device_id
operator|=
literal|0
expr_stmt|;
name|err
operator|=
name|Success
expr_stmt|;
do|do
block|{
if|if
condition|(
operator|!
name|devices
operator|.
name|contains
argument_list|(
name|device_id
argument_list|)
condition|)
block|{
name|err
operator|=
name|gh_hid_init_device
argument_list|(
name|driver
argument_list|,
name|device_id
argument_list|,
operator|&
name|handle
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
name|Success
condition|)
break|break;
name|hidnot
operator|=
operator|new
name|HIDDeviceHandler
argument_list|(
name|driver
argument_list|,
name|handle
argument_list|)
expr_stmt|;
name|devices
operator|.
name|insert
argument_list|(
name|device_id
argument_list|,
name|hidnot
argument_list|)
expr_stmt|;
name|hidnot
operator|->
name|async_wait
argument_list|()
expr_stmt|;
block|}
name|device_id
operator|++
expr_stmt|;
block|}
do|while
condition|(
name|err
operator|==
name|Success
condition|)
do|;
block|}
name|async_wait
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|process_event
name|void
name|HIDDeviceHandler
operator|::
name|process_event
parameter_list|()
block|{
name|HIDEvent
name|event
decl_stmt|;
name|uint32_t
name|num_events
init|=
literal|1
decl_stmt|;
while|while
condition|(
name|gh_hid_get_event
argument_list|(
name|handle
argument_list|,
operator|&
name|event
argument_list|,
operator|&
name|num_events
argument_list|)
operator|==
name|Success
condition|)
block|{
if|if
condition|(
name|event
operator|.
name|type
operator|==
name|HID_TYPE_AXIS
condition|)
block|{
switch|switch
condition|(
name|event
operator|.
name|index
condition|)
block|{
case|case
name|HID_AXIS_ABSX
case|:
name|currentPos
operator|.
name|setX
argument_list|(
name|event
operator|.
name|value
argument_list|)
expr_stmt|;
break|break;
case|case
name|HID_AXIS_ABSY
case|:
name|currentPos
operator|.
name|setY
argument_list|(
name|event
operator|.
name|value
argument_list|)
expr_stmt|;
break|break;
case|case
name|HID_AXIS_RELX
case|:
name|currentPos
operator|.
name|setX
argument_list|(
name|currentPos
operator|.
name|x
argument_list|()
operator|+
name|event
operator|.
name|value
argument_list|)
expr_stmt|;
break|break;
case|case
name|HID_AXIS_RELY
case|:
name|currentPos
operator|.
name|setY
argument_list|(
name|currentPos
operator|.
name|y
argument_list|()
operator|+
name|event
operator|.
name|value
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* ignore the rest for now */
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|event
operator|.
name|type
operator|==
name|HID_TYPE_KEY
condition|)
block|{
switch|switch
condition|(
name|event
operator|.
name|index
condition|)
block|{
case|case
name|HID_BUTTON_LEFT
case|:
if|if
condition|(
name|event
operator|.
name|value
condition|)
name|buttons
operator||=
name|Qt
operator|::
name|LeftButton
expr_stmt|;
else|else
name|buttons
operator|&=
operator|~
name|Qt
operator|::
name|LeftButton
expr_stmt|;
break|break;
case|case
name|HID_BUTTON_MIDDLE
case|:
if|if
condition|(
name|event
operator|.
name|value
condition|)
name|buttons
operator||=
name|Qt
operator|::
name|MiddleButton
expr_stmt|;
else|else
name|buttons
operator|&=
operator|~
name|Qt
operator|::
name|MiddleButton
expr_stmt|;
break|break;
case|case
name|HID_BUTTON_RIGHT
case|:
if|if
condition|(
name|event
operator|.
name|value
condition|)
name|buttons
operator||=
name|Qt
operator|::
name|RightButton
expr_stmt|;
else|else
name|buttons
operator|&=
operator|~
name|Qt
operator|::
name|RightButton
expr_stmt|;
break|break;
default|default:
comment|/* ignore the rest for now */
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|event
operator|.
name|type
operator|==
name|HID_TYPE_SYNC
condition|)
block|{
name|QWindowSystemInterface
operator|::
name|handleMouseEvent
argument_list|(
literal|0
argument_list|,
name|currentPos
argument_list|,
name|currentPos
argument_list|,
name|buttons
argument_list|,
name|QGuiApplication
operator|::
name|keyboardModifiers
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|event
operator|.
name|type
operator|==
name|HID_TYPE_DISCONNECT
condition|)
block|{
comment|/* FIXME */
block|}
block|}
name|async_wait
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|async_wait
name|void
name|HIDDeviceHandler
operator|::
name|async_wait
parameter_list|()
block|{
name|CheckSuccess
argument_list|(
name|gh_hid_async_wait_for_event
argument_list|(
name|handle
argument_list|,
name|act
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|open_devices
name|void
name|QIntegrityHIDManager
operator|::
name|open_devices
parameter_list|()
block|{
name|HIDDriver
modifier|*
name|hidd
decl_stmt|;
name|uintptr_t
name|context
init|=
literal|0
decl_stmt|;
name|HIDDriverHandler
modifier|*
name|hidnot
decl_stmt|;
while|while
condition|(
name|gh_hid_enum_drivers
argument_list|(
operator|&
name|hidd
argument_list|,
operator|&
name|context
argument_list|)
operator|==
name|Success
condition|)
block|{
name|hidnot
operator|=
operator|new
name|HIDDriverHandler
argument_list|(
name|hidd
argument_list|)
expr_stmt|;
name|m_drivers
operator|.
name|append
argument_list|(
name|hidnot
argument_list|)
expr_stmt|;
name|hidnot
operator|->
name|find_devices
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|run
name|void
name|QIntegrityHIDManager
operator|::
name|run
parameter_list|()
block|{
name|IntNotifier
modifier|*
name|notifier
decl_stmt|;
name|open_devices
argument_list|()
expr_stmt|;
comment|/* main loop */
forever|forever
block|{
name|WaitForActivity
argument_list|(
operator|(
name|Value
operator|*
operator|)
operator|&
name|notifier
argument_list|)
expr_stmt|;
name|notifier
operator|->
name|process_event
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_constructor
DECL|function|QIntegrityHIDManager
name|QIntegrityHIDManager
operator|::
name|QIntegrityHIDManager
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
specifier|const
name|QString
modifier|&
name|spec
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
block|{
name|start
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QIntegrityHIDManager
name|QIntegrityHIDManager
operator|::
name|~
name|QIntegrityHIDManager
parameter_list|()
block|{
name|terminate
argument_list|()
expr_stmt|;
name|qDeleteAll
argument_list|(
name|m_drivers
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit