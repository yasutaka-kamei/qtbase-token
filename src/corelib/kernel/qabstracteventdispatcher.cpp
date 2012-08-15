begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qabstracteventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|"qabstracteventdispatcher_p.h"
end_include
begin_include
include|#
directive|include
file|"qabstractnativeeventfilter.h"
end_include
begin_include
include|#
directive|include
file|"qthread.h"
end_include
begin_include
include|#
directive|include
file|<private/qthread_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qcoreapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qfreelist_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// we allow for 2^24 = 8^8 = 16777216 simultaneously running timers
end_comment
begin_struct
DECL|struct|QtTimerIdFreeListConstants
struct|struct
name|QtTimerIdFreeListConstants
super|:
specifier|public
name|QFreeListDefaultConstants
block|{
enum|enum
block|{
DECL|enumerator|InitialNextValue
name|InitialNextValue
init|=
literal|1
block|,
DECL|enumerator|BlockCount
name|BlockCount
init|=
literal|6
block|,     }
enum|;
DECL|member|Sizes
specifier|static
specifier|const
name|int
name|Sizes
index|[
name|BlockCount
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_enum
enum|enum
block|{
DECL|enumerator|Offset0
name|Offset0
init|=
literal|0x00000000
block|,
DECL|enumerator|Offset1
name|Offset1
init|=
literal|0x00000040
block|,
DECL|enumerator|Offset2
name|Offset2
init|=
literal|0x00000100
block|,
DECL|enumerator|Offset3
name|Offset3
init|=
literal|0x00001000
block|,
DECL|enumerator|Offset4
name|Offset4
init|=
literal|0x00010000
block|,
DECL|enumerator|Offset5
name|Offset5
init|=
literal|0x00100000
block|,
DECL|enumerator|Size0
name|Size0
init|=
name|Offset1
operator|-
name|Offset0
block|,
DECL|enumerator|Size1
name|Size1
init|=
name|Offset2
operator|-
name|Offset1
block|,
DECL|enumerator|Size2
name|Size2
init|=
name|Offset3
operator|-
name|Offset2
block|,
DECL|enumerator|Size3
name|Size3
init|=
name|Offset4
operator|-
name|Offset3
block|,
DECL|enumerator|Size4
name|Size4
init|=
name|Offset5
operator|-
name|Offset4
block|,
DECL|enumerator|Size5
name|Size5
init|=
name|QtTimerIdFreeListConstants
operator|::
name|MaxIndex
operator|-
name|Offset5
block|}
enum|;
end_enum
begin_decl_stmt
DECL|member|Sizes
specifier|const
name|int
name|QtTimerIdFreeListConstants
operator|::
name|Sizes
index|[
name|QtTimerIdFreeListConstants
operator|::
name|BlockCount
index|]
init|=
block|{
name|Size0
block|,
name|Size1
block|,
name|Size2
block|,
name|Size3
block|,
name|Size4
block|,
name|Size5
block|}
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|QtTimerIdFreeList
typedef|typedef
name|QFreeList
argument_list|<
name|void
argument_list|,
name|QtTimerIdFreeListConstants
argument_list|>
name|QtTimerIdFreeList
typedef|;
end_typedef
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QtTimerIdFreeList
argument_list|,
argument|timerIdFreeList
argument_list|)
end_macro
begin_function
DECL|function|allocateTimerId
name|int
name|QAbstractEventDispatcherPrivate
operator|::
name|allocateTimerId
parameter_list|()
block|{
return|return
name|timerIdFreeList
argument_list|()
operator|->
name|next
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|releaseTimerId
name|void
name|QAbstractEventDispatcherPrivate
operator|::
name|releaseTimerId
parameter_list|(
name|int
name|timerId
parameter_list|)
block|{
comment|// this function may be called by a global destructor after
comment|// timerIdFreeList() has been destructed
if|if
condition|(
name|QtTimerIdFreeList
modifier|*
name|fl
init|=
name|timerIdFreeList
argument_list|()
condition|)
name|fl
operator|->
name|release
argument_list|(
name|timerId
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QAbstractEventDispatcher     \brief The QAbstractEventDispatcher class provides an interface to manage Qt's event queue.      \ingroup events      An event dispatcher receives events from the window system and other     sources. It then sends them to the QCoreApplication or QApplication     instance for processing and delivery. QAbstractEventDispatcher provides     fine-grained control over event delivery.      For simple control of event processing use     QCoreApplication::processEvents().      For finer control of the application's event loop, call     instance() and call functions on the QAbstractEventDispatcher     object that is returned. If you want to use your own instance of     QAbstractEventDispatcher or of a QAbstractEventDispatcher     subclass, you must install it with QCoreApplication::setEventDispatcher()     or QThread::setEventDispatcher() \e before a default event dispatcher has     been installed.      The main event loop is started by calling     QCoreApplication::exec(), and stopped by calling     QCoreApplication::exit(). Local event loops can be created using     QEventLoop.      Programs that perform long operations can call processEvents()     with a bitwise OR combination of various QEventLoop::ProcessEventsFlag     values to control which events should be delivered.      QAbstractEventDispatcher also allows the integration of an     external event loop with the Qt event loop. For example, the     \l{Motif Extension}     includes a reimplementation of QAbstractEventDispatcher that merges Qt and     Motif events together.      \sa QEventLoop, QCoreApplication, QThread */
end_comment
begin_comment
comment|/*!     Constructs a new event dispatcher with the given \a parent. */
end_comment
begin_constructor
DECL|function|QAbstractEventDispatcher
name|QAbstractEventDispatcher
operator|::
name|QAbstractEventDispatcher
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QAbstractEventDispatcherPrivate
argument_list|,
name|parent
argument_list|)
block|{}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QAbstractEventDispatcher
name|QAbstractEventDispatcher
operator|::
name|QAbstractEventDispatcher
parameter_list|(
name|QAbstractEventDispatcherPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{}
end_constructor
begin_comment
comment|/*!     Destroys the event dispatcher. */
end_comment
begin_destructor
DECL|function|~QAbstractEventDispatcher
name|QAbstractEventDispatcher
operator|::
name|~
name|QAbstractEventDispatcher
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns a pointer to the event dispatcher object for the specified     \a thread. If \a thread is zero, the current thread is used. If no     event dispatcher exists for the specified thread, this function     returns 0.      \b{Note:} If Qt is built without thread support, the \a thread     argument is ignored.  */
end_comment
begin_function
DECL|function|instance
name|QAbstractEventDispatcher
modifier|*
name|QAbstractEventDispatcher
operator|::
name|instance
parameter_list|(
name|QThread
modifier|*
name|thread
parameter_list|)
block|{
name|QThreadData
modifier|*
name|data
init|=
name|thread
condition|?
name|QThreadData
operator|::
name|get2
argument_list|(
name|thread
argument_list|)
else|:
name|QThreadData
operator|::
name|current
argument_list|()
decl_stmt|;
return|return
name|data
operator|->
name|eventDispatcher
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QAbstractEventDispatcher::processEvents(QEventLoop::ProcessEventsFlags flags)      Processes pending events that match \a flags until there are no     more events to process. Returns true if an event was processed;     otherwise returns false.      This function is especially useful if you have a long running     operation and want to show its progress without allowing user     input; i.e. by using the QEventLoop::ExcludeUserInputEvents flag.      If the QEventLoop::WaitForMoreEvents flag is set in \a flags, the     behavior of this function is as follows:      \list      \li If events are available, this function returns after processing     them.      \li If no events are available, this function will wait until more     are available and return after processing newly available events.      \endlist      If the QEventLoop::WaitForMoreEvents flag is not set in \a flags,     and no events are available, this function will return     immediately.      \b{Note:} This function does not process events continuously; it     returns after all available events are processed.      \sa hasPendingEvents() */
end_comment
begin_comment
comment|/*! \fn bool QAbstractEventDispatcher::hasPendingEvents()      Returns true if there is an event waiting; otherwise returns     false. */
end_comment
begin_comment
comment|/*!     \fn void QAbstractEventDispatcher::registerSocketNotifier(QSocketNotifier *notifier)      Registers \a notifier with the event loop. Subclasses must     implement this method to tie a socket notifier into another     event loop. */
end_comment
begin_comment
comment|/*! \fn void QAbstractEventDispatcher::unregisterSocketNotifier(QSocketNotifier *notifier)      Unregisters \a notifier from the event dispatcher. Subclasses must     reimplement this method to tie a socket notifier into another     event loop. Reimplementations must call the base     implementation. */
end_comment
begin_comment
comment|/*!     \obsolete      \fn int QAbstractEventDispatcher::registerTimer(int interval, QObject *object)      Registers a timer with the specified \a interval for the given \a object     and returns the timer id. */
end_comment
begin_comment
comment|/*!     \obsolete      \fn void QAbstractEventDispatcher::registerTimer(int timerId, int interval, QObject *object)      Register a timer with the specified \a timerId and \a interval for the     given \a object. */
end_comment
begin_comment
comment|/*!     Registers a timer with the specified \a interval and \a timerType for the     given \a object and returns the timer id. */
end_comment
begin_function
DECL|function|registerTimer
name|int
name|QAbstractEventDispatcher
operator|::
name|registerTimer
parameter_list|(
name|int
name|interval
parameter_list|,
name|Qt
operator|::
name|TimerType
name|timerType
parameter_list|,
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|int
name|id
init|=
name|QAbstractEventDispatcherPrivate
operator|::
name|allocateTimerId
argument_list|()
decl_stmt|;
name|registerTimer
argument_list|(
name|id
argument_list|,
name|interval
argument_list|,
name|timerType
argument_list|,
name|object
argument_list|)
expr_stmt|;
return|return
name|id
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QAbstractEventDispatcher::registerTimer(int timerId, int interval, Qt::TimerType timerType, QObject *object)      Register a timer with the specified \a timerId, \a interval, and \a     timerType for the given \a object. */
end_comment
begin_comment
comment|/*!     \fn bool QAbstractEventDispatcher::unregisterTimer(int timerId)      Unregisters the timer with the given \a timerId.     Returns true if successful; otherwise returns false.      \sa registerTimer(), unregisterTimers() */
end_comment
begin_comment
comment|/*!     \fn bool QAbstractEventDispatcher::unregisterTimers(QObject *object)      Unregisters all the timers associated with the given \a object.     Returns true if all timers were successful removed; otherwise returns false.      \sa unregisterTimer(), registeredTimers() */
end_comment
begin_comment
comment|/*!     \fn QList<TimerInfo> QAbstractEventDispatcher::registeredTimers(QObject *object) const      Returns a list of registered timers for \a object. The TimerInfo struct has     \c timerId, \c interval, and \c timerType members.      \sa Qt::TimerType */
end_comment
begin_comment
comment|/*!     \fn int QAbstractEventDispatcher::remainingTime(int timerId)      Returns the remaining time in milliseconds with the given \a timerId.     If the timer is inactive, the returned value will be -1. If the timer is     overdue, the returned value will be 0.      \sa Qt::TimerType */
end_comment
begin_comment
comment|/*! \fn void QAbstractEventDispatcher::wakeUp()     \threadsafe      Wakes up the event loop.      \sa awake() */
end_comment
begin_comment
comment|/*!     \fn void QAbstractEventDispatcher::interrupt()      Interrupts event dispatching; i.e. the event dispatcher will     return from processEvents() as soon as possible. */
end_comment
begin_comment
comment|/*! \fn void QAbstractEventDispatcher::flush()      Flushes the event queue. This normally returns almost     immediately. Does nothing on platforms other than X11. */
end_comment
begin_comment
comment|// ### DOC: Are these called when the _application_ starts/stops or just
end_comment
begin_comment
comment|// when the current _event loop_ starts/stops?
end_comment
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|startingUp
name|void
name|QAbstractEventDispatcher
operator|::
name|startingUp
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|closingDown
name|void
name|QAbstractEventDispatcher
operator|::
name|closingDown
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     \class QAbstractEventDispatcher::TimerInfo      This struct represents information about a timer:     \l{QAbstractEventDispatcher::TimerInfo::timerId}{timerId},     \l{QAbstractEventDispatcher::TimerInfo::interval}{interval}, and     \l{QAbstractEventDispatcher::TimerInfo::timerType}{timerType}.      \sa registeredTimers() */
end_comment
begin_comment
comment|/*! \fn QAbstractEventDispatcher::TimerInfo::TimerInfo(int timerId, int interval, Qt::TimerType timerType)      Constructs a TimerInfo struct with the given \a timerId, \a interval, and     \a timerType. */
end_comment
begin_comment
comment|/*!     \variable QAbstractEventDispatcher::TimerInfo::timerId      The timer's unique id. */
end_comment
begin_comment
comment|/*!     \variable QAbstractEventDispatcher::TimerInfo::interval      The timer's interval. */
end_comment
begin_comment
comment|/*!     \variable QAbstractEventDispatcher::TimerInfo::timerType      The timer's type      \sa Qt::TimerType */
end_comment
begin_comment
comment|/*!     Installs an event filter \a filterObj for all native event filters     received by the application.      The event filter \a filterObj receives events via its nativeEventFilter()     function, which is called for all events received by all threads.      The nativeEventFilter() function should return true if the event should     be filtered, (i.e. stopped). It should return false to allow     normal Qt processing to continue: the native event can then be translated     into a QEvent and handled by the standard Qt \l{QEvent} {event} filtering,     e.g. QObject::installEventFilter().      If multiple event filters are installed, the filter that was installed last     is activated first.      \note The filter function set here receives native messages,     i.e. MSG or XEvent structs.      For maximum portability, you should always try to use QEvents     and QObject::installEventFilter() whenever possible.      \sa QObject::installEventFilter()      \since 5.0 */
end_comment
begin_function
DECL|function|installNativeEventFilter
name|void
name|QAbstractEventDispatcher
operator|::
name|installNativeEventFilter
parameter_list|(
name|QAbstractNativeEventFilter
modifier|*
name|filterObj
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractEventDispatcher
argument_list|)
expr_stmt|;
comment|// clean up unused items in the list
name|d
operator|->
name|eventFilters
operator|.
name|removeAll
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|eventFilters
operator|.
name|removeAll
argument_list|(
name|filterObj
argument_list|)
expr_stmt|;
name|d
operator|->
name|eventFilters
operator|.
name|prepend
argument_list|(
name|filterObj
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes an event filter object \a obj from this object. The     request is ignored if such an event filter has not been installed.      All event filters for this object are automatically removed when     this object is destroyed.      It is always safe to remove an event filter, even during event     filter activation (i.e. from the nativeEventFilter() function).      \sa installNativeEventFilter(), QAbstractNativeEventFilter     \since 5.0 */
end_comment
begin_function
DECL|function|removeNativeEventFilter
name|void
name|QAbstractEventDispatcher
operator|::
name|removeNativeEventFilter
parameter_list|(
name|QAbstractNativeEventFilter
modifier|*
name|filterObj
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractEventDispatcher
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
name|d
operator|->
name|eventFilters
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|d
operator|->
name|eventFilters
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|filterObj
condition|)
block|{
name|d
operator|->
name|eventFilters
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     Sends \a message through the event filters that were set by     installNativeEventFilter().  This function returns true as soon as an     event filter returns true, and false otherwise to indicate that     the processing of the event should continue.      Subclasses of QAbstractEventDispatcher \e must call this function     for \e all messages received from the system to ensure     compatibility with any extensions that may be used in the     application. The type of event \a eventType is specific to the platform     plugin chosen at run-time, and can be used to cast message to the right type.     The result pointer is only used on Windows, and corresponds to the LRESULT pointer.      Note that the type of \a message is platform dependent. See     QAbstractNativeEventFilter for details.      \sa installNativeEventFilter(), QAbstractNativeEventFilter::nativeEventFilter()     \since 5.0 */
end_comment
begin_function
DECL|function|filterNativeEvent
name|bool
name|QAbstractEventDispatcher
operator|::
name|filterNativeEvent
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
name|Q_D
argument_list|(
name|QAbstractEventDispatcher
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|eventFilters
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// Raise the loopLevel so that deleteLater() calls in or triggered
comment|// by event_filter() will be processed from the main event loop.
name|QScopedLoopLevelCounter
name|loopLevelCounter
argument_list|(
name|d
operator|->
name|threadData
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
name|d
operator|->
name|eventFilters
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QAbstractNativeEventFilter
modifier|*
name|filter
init|=
name|d
operator|->
name|eventFilters
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|filter
condition|)
continue|continue;
if|if
condition|(
name|filter
operator|->
name|nativeEventFilter
argument_list|(
name|eventType
argument_list|,
name|message
argument_list|,
name|result
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*! \fn void QAbstractEventDispatcher::awake()      This signal is emitted after the event loop returns from a     function that could block.      \sa wakeUp(), aboutToBlock() */
end_comment
begin_comment
comment|/*! \fn void QAbstractEventDispatcher::aboutToBlock()      This signal is emitted before the event loop calls a function that     could block.      \sa awake() */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
