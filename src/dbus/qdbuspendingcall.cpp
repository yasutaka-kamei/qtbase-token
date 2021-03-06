begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbuspendingcall.h"
end_include
begin_include
include|#
directive|include
file|"qdbuspendingcall_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnection_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmetatype_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusutil_p.h"
end_include
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"qcoreevent.h"
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QDBusPendingCall     \inmodule QtDBus     \ingroup shared     \since 4.5      \brief The QDBusPendingCall class refers to one pending asynchronous call      A QDBusPendingCall object is a reference to a method call that was     sent over D-Bus without waiting for a reply. QDBusPendingCall is an     opaque type, meant to be used as a handle for a pending reply.      In most programs, the QDBusPendingCall class will not be used     directly. It can be safely replaced with the template-based     QDBusPendingReply, in order to access the contents of the reply or     wait for it to be complete.      The QDBusPendingCallWatcher class allows one to connect to a signal     that will indicate when the reply has arrived or if the call has     timed out. It also provides the     QDBusPendingCallWatcher::waitForFinished() method which will suspend     the execution of the program until the reply has arrived.      \note If you create a copy of a QDBusPendingCall object, all           information will be shared among the many copies. Therefore,           QDBusPendingCall is an explicitly-shared object and does not           provide a method of detaching the copies (since they refer           to the same pending call)      \sa QDBusPendingReply, QDBusPendingCallWatcher,         QDBusAbstractInterface::asyncCall() */
comment|/*!     \class QDBusPendingCallWatcher     \inmodule QtDBus     \since 4.5      \brief The QDBusPendingCallWatcher class provides a convenient way for     waiting for asynchronous replies      The QDBusPendingCallWatcher provides the finished() signal that will be     emitted when a reply arrives.      It is usually used like the following example:      \snippet code/src_qdbus_qdbuspendingcall.cpp 0      Note that it is not necessary to keep the original QDBusPendingCall     object around since QDBusPendingCallWatcher inherits from that class     too.      The slot connected to by the above code could be something similar     to the following:      \snippet code/src_qdbus_qdbuspendingcall.cpp 1      Note the use of QDBusPendingReply to validate the argument types in     the reply. If the reply did not contain exactly two arguments     (one string and one QByteArray), QDBusPendingReply::isError() will     return true.      \sa QDBusPendingReply, QDBusAbstractInterface::asyncCall() */
comment|/*!     \fn void QDBusPendingCallWatcher::finished(QDBusPendingCallWatcher *self)      This signal is emitted when the pending call has finished and its     reply is available. The \a self parameter is a pointer to the     object itself, passed for convenience so that the slot can access     the properties and determine the contents of the reply. */
DECL|function|add
name|void
name|QDBusPendingCallWatcherHelper
operator|::
name|add
parameter_list|(
name|QDBusPendingCallWatcher
modifier|*
name|watcher
parameter_list|)
block|{
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|watcher
argument_list|,
name|SLOT
argument_list|(
name|_q_finished
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QDBusPendingCallPrivate
name|QDBusPendingCallPrivate
operator|::
name|~
name|QDBusPendingCallPrivate
parameter_list|()
block|{
if|if
condition|(
name|pending
condition|)
block|{
name|q_dbus_pending_call_cancel
argument_list|(
name|pending
argument_list|)
expr_stmt|;
name|q_dbus_pending_call_unref
argument_list|(
name|pending
argument_list|)
expr_stmt|;
block|}
operator|delete
name|watcherHelper
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|setReplyCallback
name|bool
name|QDBusPendingCallPrivate
operator|::
name|setReplyCallback
parameter_list|(
name|QObject
modifier|*
name|target
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|)
block|{
name|receiver
operator|=
name|target
expr_stmt|;
name|metaTypes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|methodIdx
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
operator|!
name|target
condition|)
return|return
literal|true
return|;
empty_stmt|;
comment|// unsetting
if|if
condition|(
operator|!
name|member
operator|||
operator|!
operator|*
name|member
condition|)
block|{
comment|// would not be able to deliver a reply
name|qWarning
argument_list|(
literal|"QDBusPendingCall::setReplyCallback: error: cannot deliver a reply to %s::%s (%s)"
argument_list|,
name|target
condition|?
name|target
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
else|:
literal|"(null)"
argument_list|,
name|member
condition|?
name|member
operator|+
literal|1
else|:
literal|"(null)"
argument_list|,
name|target
condition|?
name|qPrintable
argument_list|(
name|target
operator|->
name|objectName
argument_list|()
argument_list|)
else|:
literal|"no name"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|methodIdx
operator|=
name|QDBusConnectionPrivate
operator|::
name|findSlot
argument_list|(
name|target
argument_list|,
name|member
operator|+
literal|1
argument_list|,
name|metaTypes
argument_list|)
expr_stmt|;
if|if
condition|(
name|methodIdx
operator|==
operator|-
literal|1
condition|)
block|{
name|QByteArray
name|normalizedName
init|=
name|QMetaObject
operator|::
name|normalizedSignature
argument_list|(
name|member
operator|+
literal|1
argument_list|)
decl_stmt|;
name|methodIdx
operator|=
name|QDBusConnectionPrivate
operator|::
name|findSlot
argument_list|(
name|target
argument_list|,
name|normalizedName
argument_list|,
name|metaTypes
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|methodIdx
operator|==
operator|-
literal|1
condition|)
block|{
comment|// would not be able to deliver a reply
name|qWarning
argument_list|(
literal|"QDBusPendingCall::setReplyCallback: error: cannot deliver a reply to %s::%s (%s)"
argument_list|,
name|target
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|,
name|member
operator|+
literal|1
argument_list|,
name|qPrintable
argument_list|(
name|target
operator|->
name|objectName
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// success
comment|// construct the expected signature
name|int
name|count
init|=
name|metaTypes
operator|.
name|count
argument_list|()
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|count
operator|==
literal|1
operator|&&
name|metaTypes
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|QDBusMetaTypeId
operator|::
name|message
argument_list|()
condition|)
block|{
comment|// wildcard slot, can receive anything, so don't set the signature
return|return
literal|true
return|;
block|}
if|if
condition|(
name|metaTypes
operator|.
name|at
argument_list|(
name|count
argument_list|)
operator|==
name|QDBusMetaTypeId
operator|::
name|message
argument_list|()
condition|)
operator|--
name|count
expr_stmt|;
name|setMetaTypes
argument_list|(
name|count
argument_list|,
name|count
condition|?
name|metaTypes
operator|.
name|constData
argument_list|()
operator|+
literal|1
else|:
literal|0
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|setMetaTypes
name|void
name|QDBusPendingCallPrivate
operator|::
name|setMetaTypes
parameter_list|(
name|int
name|count
parameter_list|,
specifier|const
name|int
modifier|*
name|types
parameter_list|)
block|{
if|if
condition|(
name|count
operator|==
literal|0
condition|)
block|{
name|expectedReplySignature
operator|=
name|QLatin1String
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|// not null
return|return;
block|}
name|QByteArray
name|sig
decl_stmt|;
name|sig
operator|.
name|reserve
argument_list|(
name|count
operator|+
name|count
operator|/
literal|2
argument_list|)
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
name|count
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|typeSig
init|=
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|types
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
operator|!
name|typeSig
argument_list|)
condition|)
block|{
name|qFatal
argument_list|(
literal|"QDBusPendingReply: type %s is not registered with QtDBus"
argument_list|,
name|QMetaType
operator|::
name|typeName
argument_list|(
name|types
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|sig
operator|+=
name|typeSig
expr_stmt|;
block|}
name|expectedReplySignature
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|sig
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkReceivedSignature
name|void
name|QDBusPendingCallPrivate
operator|::
name|checkReceivedSignature
parameter_list|()
block|{
comment|// MUST BE CALLED WITH A LOCKED MUTEX!
if|if
condition|(
name|replyMessage
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|InvalidMessage
condition|)
return|return;
comment|// not yet finished - no message to
comment|// validate against
if|if
condition|(
name|replyMessage
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ErrorMessage
condition|)
return|return;
comment|// we don't have to check the signature of an error reply
if|if
condition|(
name|expectedReplySignature
operator|.
name|isNull
argument_list|()
condition|)
return|return;
comment|// no signature to validate against
comment|// can't use startsWith here because a null string doesn't start or end with an empty string
if|if
condition|(
name|replyMessage
operator|.
name|signature
argument_list|()
operator|.
name|indexOf
argument_list|(
name|expectedReplySignature
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|QString
name|errorMsg
init|=
name|QLatin1String
argument_list|(
literal|"Unexpected reply signature: got \"%1\", "
literal|"expected \"%2\""
argument_list|)
decl_stmt|;
name|replyMessage
operator|=
name|QDBusMessage
operator|::
name|createError
argument_list|(
name|QDBusError
operator|::
name|InvalidSignature
argument_list|,
name|errorMsg
operator|.
name|arg
argument_list|(
name|replyMessage
operator|.
name|signature
argument_list|()
argument_list|,
name|expectedReplySignature
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|waitForFinished
name|void
name|QDBusPendingCallPrivate
operator|::
name|waitForFinished
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|replyMessage
operator|.
name|type
argument_list|()
operator|!=
name|QDBusMessage
operator|::
name|InvalidMessage
condition|)
return|return;
comment|// already finished
name|waitForFinishedCondition
operator|.
name|wait
argument_list|(
operator|&
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Creates a copy of the \a other pending asynchronous call. Note     that both objects will refer to the same pending call. */
end_comment
begin_constructor
DECL|function|QDBusPendingCall
name|QDBusPendingCall
operator|::
name|QDBusPendingCall
parameter_list|(
specifier|const
name|QDBusPendingCall
modifier|&
name|other
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QDBusPendingCall
name|QDBusPendingCall
operator|::
name|QDBusPendingCall
parameter_list|(
name|QDBusPendingCallPrivate
modifier|*
name|dd
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|dd
argument_list|)
block|{
if|if
condition|(
name|dd
condition|)
block|{
name|bool
name|r
init|=
name|dd
operator|->
name|ref
operator|.
name|deref
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|r
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|r
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|/*!     Destroys this copy of the QDBusPendingCall object. If this copy is     also the last copy of a pending asynchronous call, the call will     be canceled and no further notifications will be received. There     will be no way of accessing the reply's contents when it arrives. */
end_comment
begin_destructor
DECL|function|~QDBusPendingCall
name|QDBusPendingCall
operator|::
name|~
name|QDBusPendingCall
parameter_list|()
block|{
comment|// d deleted by QExplicitlySharedDataPointer
block|}
end_destructor
begin_comment
comment|/*!     Creates a copy of the \a other pending asynchronous call and drops     the reference to the previously-referenced call. Note that both     objects will refer to the same pending call after this function.      If this object contained the last reference of a pending     asynchronous call, the call will be canceled and no further     notifications will be received. There will be no way of accessing     the reply's contents when it arrives. */
end_comment
begin_function
DECL|function|operator =
name|QDBusPendingCall
modifier|&
name|QDBusPendingCall
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QDBusPendingCall
modifier|&
name|other
parameter_list|)
block|{
name|d
operator|=
name|other
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QDBusPendingCall::swap(QDBusPendingCall&other)     \since 5.0      Swaps this pending call instance with \a other. This function is     very fast and never fails. */
end_comment
begin_comment
comment|/*!     \fn bool QDBusPendingCallWatcher::isFinished() const      Returns \c true if the pending call has finished processing and the     reply has been received.      Note that this function only changes state if you call     waitForFinished() or if an external D-Bus event happens, which in     general only happens if you return to the event loop execution.      \sa QDBusPendingReply::isFinished() */
end_comment
begin_comment
comment|/*!     \fn bool QDBusPendingReply::isFinished() const      Returns \c true if the pending call has finished processing and the     reply has been received. If this function returns \c true, the     isError(), error() and reply() methods should return valid     information.      Note that this function only changes state if you call     waitForFinished() or if an external D-Bus event happens, which in     general only happens if you return to the event loop execution.      \sa QDBusPendingCallWatcher::isFinished() */
end_comment
begin_function
DECL|function|isFinished
name|bool
name|QDBusPendingCall
operator|::
name|isFinished
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|true
return|;
comment|// considered finished
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|replyMessage
operator|.
name|type
argument_list|()
operator|!=
name|QDBusMessage
operator|::
name|InvalidMessage
return|;
block|}
end_function
begin_function
DECL|function|waitForFinished
name|void
name|QDBusPendingCall
operator|::
name|waitForFinished
parameter_list|()
block|{
if|if
condition|(
name|d
condition|)
name|d
operator|->
name|waitForFinished
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QDBusPendingReply::isValid() const      Returns \c true if the reply contains a normal reply message, false     if it contains anything else.      If the pending call has not finished processing, this function     return false. */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QDBusPendingCall
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|false
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|replyMessage
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ReplyMessage
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QDBusPendingReply::isError() const      Returns \c true if the reply contains an error message, false if it     contains a normal method reply.      If the pending call has not finished processing, this function     also returns \c true. */
end_comment
begin_function
DECL|function|isError
name|bool
name|QDBusPendingCall
operator|::
name|isError
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
literal|true
return|;
comment|// considered finished and an error
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|replyMessage
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ErrorMessage
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QDBusError QDBusPendingReply::error() const      Retrieves the error content of the reply message, if it has     finished processing. If the reply message has not finished     processing or if it contains a normal reply message (non-error),     this function returns an invalid QDBusError. */
end_comment
begin_function
DECL|function|error
name|QDBusError
name|QDBusPendingCall
operator|::
name|error
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d
condition|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|QDBusError
argument_list|(
name|d
operator|->
name|replyMessage
argument_list|)
return|;
block|}
comment|// not connected, return an error
name|QDBusError
name|err
init|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|Disconnected
argument_list|,
name|QDBusUtil
operator|::
name|disconnectedErrorMessage
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|err
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QDBusMessage QDBusPendingReply::reply() const      Retrieves the reply message received for the asynchronous call     that was sent, if it has finished processing. If the pending call     is not finished, this function returns a QDBusMessage of type     QDBusMessage::InvalidMessage.      After it has finished processing, the message type will either be     an error message or a normal method reply message. */
end_comment
begin_function
DECL|function|reply
name|QDBusMessage
name|QDBusPendingCall
operator|::
name|reply
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d
condition|)
return|return
name|QDBusMessage
operator|::
name|createError
argument_list|(
name|error
argument_list|()
argument_list|)
return|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|replyMessage
return|;
block|}
end_function
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/*!     Sets the slot \a member in object \a target to be called when the     reply arrives. The slot's parameter list must match the reply     message's arguments for it to be called.      It may, optionally, contain a QDBusMessage final parameter. If it     is present, the parameter will contain the reply message object.      The callback will not be called if the reply is an error message.      This function returns \c true if it could set the callback, false     otherwise. It is not a guarantee that the callback will be     called.      \warning QDBusPendingCall only supports one callback per pending              asynchronous call, even if multiple QDBusPendingCall              objects are referencing the same pending call. */
end_comment
begin_endif
unit|bool QDBusPendingCall::setReplyCallback(QObject *target, const char *member) {     if (!d)         return false;      return d->setReplyCallback(target, member); }
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \since 4.6     Creates a QDBusPendingCall object based on the error condition     \a error. The resulting pending call object will be in the     "finished" state and QDBusPendingReply::isError() will return true.      \sa fromCompletedCall() */
end_comment
begin_function
DECL|function|fromError
name|QDBusPendingCall
name|QDBusPendingCall
operator|::
name|fromError
parameter_list|(
specifier|const
name|QDBusError
modifier|&
name|error
parameter_list|)
block|{
return|return
name|fromCompletedCall
argument_list|(
name|QDBusMessage
operator|::
name|createError
argument_list|(
name|error
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.6     Creates a QDBusPendingCall object based on the message \a msg.     The message must be of type QDBusMessage::ErrorMessage or     QDBusMessage::ReplyMessage (that is, a message that is typical     of a completed call).      This function is useful for code that requires simulating a pending     call, but that has already finished.      \sa fromError() */
end_comment
begin_function
DECL|function|fromCompletedCall
name|QDBusPendingCall
name|QDBusPendingCall
operator|::
name|fromCompletedCall
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|msg
parameter_list|)
block|{
name|QDBusPendingCallPrivate
modifier|*
name|d
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|msg
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ErrorMessage
operator|||
name|msg
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ReplyMessage
condition|)
block|{
name|d
operator|=
operator|new
name|QDBusPendingCallPrivate
argument_list|(
name|QDBusMessage
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|replyMessage
operator|=
name|msg
expr_stmt|;
name|d
operator|->
name|ref
operator|.
name|store
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|QDBusPendingCall
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function
begin_class
DECL|class|QDBusPendingCallWatcherPrivate
class|class
name|QDBusPendingCallWatcherPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
public|public:
name|void
name|_q_finished
parameter_list|()
function_decl|;
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QDBusPendingCallWatcher
argument_list|)
block|}
class|;
end_class
begin_function
DECL|function|_q_finished
specifier|inline
name|void
name|QDBusPendingCallWatcherPrivate
operator|::
name|_q_finished
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QDBusPendingCallWatcher
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|finished
argument_list|(
name|q
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|/*!     Creates a QDBusPendingCallWatcher object to watch for replies on the     asynchronous pending call \a call and sets this object's parent     to \a parent. */
end_comment
begin_constructor
DECL|function|QDBusPendingCallWatcher
name|QDBusPendingCallWatcher
operator|::
name|QDBusPendingCallWatcher
parameter_list|(
specifier|const
name|QDBusPendingCall
modifier|&
name|call
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QDBusPendingCallWatcherPrivate
argument_list|,
name|parent
argument_list|)
member_init_list|,
name|QDBusPendingCall
argument_list|(
name|call
argument_list|)
block|{
if|if
condition|(
name|d
condition|)
block|{
comment|// QDBusPendingCall::d
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|d
operator|->
name|mutex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|watcherHelper
condition|)
block|{
name|d
operator|->
name|watcherHelper
operator|=
operator|new
name|QDBusPendingCallWatcherHelper
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|replyMessage
operator|.
name|type
argument_list|()
operator|!=
name|QDBusMessage
operator|::
name|InvalidMessage
condition|)
block|{
comment|// cause a signal emission anyways
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|d
operator|->
name|watcherHelper
argument_list|,
literal|"finished"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
block|}
name|d
operator|->
name|watcherHelper
operator|->
name|add
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|/*!     Destroys this object. If this QDBusPendingCallWatcher object was the     last reference to the unfinished pending call, the call will be     canceled. */
end_comment
begin_destructor
DECL|function|~QDBusPendingCallWatcher
name|QDBusPendingCallWatcher
operator|::
name|~
name|QDBusPendingCallWatcher
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn void QDBusPendingCallWatcher::waitForFinished()      Suspends the execution of the calling thread until the reply is     received and processed. After this function returns, isFinished()     should return true, indicating the reply's contents are ready to     be processed.      \sa QDBusPendingReply::waitForFinished() */
end_comment
begin_function
DECL|function|waitForFinished
name|void
name|QDBusPendingCallWatcher
operator|::
name|waitForFinished
parameter_list|()
block|{
if|if
condition|(
name|d
condition|)
block|{
name|d
operator|->
name|waitForFinished
argument_list|()
expr_stmt|;
comment|// our signals were queued, so deliver them
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|(
name|d
operator|->
name|watcherHelper
argument_list|,
name|QEvent
operator|::
name|MetaCall
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|(
name|this
argument_list|,
name|QEvent
operator|::
name|MetaCall
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
begin_include
include|#
directive|include
file|"moc_qdbuspendingcall.cpp"
end_include
end_unit
