begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qabstractnativeeventfilter.h"
end_include
begin_include
include|#
directive|include
file|"qabstracteventdispatcher.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QAbstractNativeEventFilter     \inmodule QtCore     \since 5.0      \brief The QAbstractNativeEventFilter class provides an interface for receiving native     events, such as MSG or XCB event structs. */
comment|/*!     Creates a native event filter.      By default this doesn't do anything. Remember to install it on the application     object. */
DECL|function|QAbstractNativeEventFilter
name|QAbstractNativeEventFilter
operator|::
name|QAbstractNativeEventFilter
parameter_list|()
block|{
name|Q_UNUSED
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Destroys the native event filter.      This automatically removes it from the application. */
end_comment
begin_destructor
DECL|function|~QAbstractNativeEventFilter
name|QAbstractNativeEventFilter
operator|::
name|~
name|QAbstractNativeEventFilter
parameter_list|()
block|{
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
init|=
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
decl_stmt|;
if|if
condition|(
name|eventDispatcher
condition|)
name|eventDispatcher
operator|->
name|removeNativeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \fn bool QAbstractNativeEventFilter::nativeEventFilter(const QByteArray&eventType, void *message, long *result)      This method is called for every native event.      \note The filter function here receives native messages,     for example, MSG or XCB event structs.      It is called by the QPA platform plugin. On Windows, it is called by     the event dispatcher.      The type of event \a eventType is specific to the platform plugin chosen at run-time,     and can be used to cast \a message to the right type.      On X11, \a eventType is set to "xcb_generic_event_t", and the \a message can be casted     to a xcb_generic_event_t pointer.      On Windows, \a eventType is set to "windows_generic_MSG" for messages sent to toplevel windows,     and "windows_dispatcher_MSG" for system-wide messages such as messages from a registered hot key.     In both cases, the \a message can be casted to a MSG pointer.     The \a result pointer is only used on Windows, and corresponds to the LRESULT pointer.      On Mac, \a eventType is set to "mac_generic_NSEvent", and the \a message can be casted to an EventRef.      In your reimplementation of this function, if you want to filter     the \a message out, i.e. stop it being handled further, return     true; otherwise return false.      Example:     \snippet code/src_corelib_kernel_qabstractnativeeventfilter.cpp 0 */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
