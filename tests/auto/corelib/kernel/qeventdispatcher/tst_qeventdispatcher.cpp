begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_GUI_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_enum
enum|enum
block|{
DECL|enumerator|PreciseTimerInterval
name|PreciseTimerInterval
init|=
literal|10
block|,
DECL|enumerator|CoarseTimerInterval
name|CoarseTimerInterval
init|=
literal|200
block|,
DECL|enumerator|VeryCoarseTimerInterval
name|VeryCoarseTimerInterval
init|=
literal|1000
block|}
enum|;
end_enum
begin_class
DECL|class|tst_QEventDispatcher
class|class
name|tst_QEventDispatcher
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
DECL|member|eventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|eventDispatcher
decl_stmt|;
DECL|member|receivedEventType
name|int
name|receivedEventType
decl_stmt|;
DECL|member|timerIdFromEvent
name|int
name|timerIdFromEvent
decl_stmt|;
protected|protected:
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
function_decl|;
public|public:
DECL|function|tst_QEventDispatcher
specifier|inline
name|tst_QEventDispatcher
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
member_init_list|,
name|eventDispatcher
argument_list|(
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|(
name|thread
argument_list|()
argument_list|)
argument_list|)
member_init_list|,
name|receivedEventType
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|timerIdFromEvent
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
private|private
name|slots
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|registerTimer
parameter_list|()
function_decl|;
comment|/* void registerSocketNotifier(); */
comment|// Not implemented here, see tst_QSocketNotifier instead
comment|/* void registerEventNotifiier(); */
comment|// Not implemented here, see tst_QWinEventNotifier instead
name|void
name|sendPostedEvents_data
parameter_list|()
function_decl|;
name|void
name|sendPostedEvents
parameter_list|()
function_decl|;
name|void
name|processEventsOnlySendsQueuedEvents
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|event
name|bool
name|tst_QEventDispatcher
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|receivedEventType
operator|=
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|Timer
case|:
block|{
name|timerIdFromEvent
operator|=
cast|static_cast
argument_list|<
name|QTimerEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
operator|->
name|timerId
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
default|default:
break|break;
block|}
return|return
name|QObject
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// drain the system event queue after the test starts to avoid destabilizing the test functions
end_comment
begin_function
DECL|function|initTestCase
name|void
name|tst_QEventDispatcher
operator|::
name|initTestCase
parameter_list|()
block|{
name|QElapsedTimer
name|elapsedTimer
decl_stmt|;
name|elapsedTimer
operator|.
name|start
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|elapsedTimer
operator|.
name|hasExpired
argument_list|(
name|CoarseTimerInterval
argument_list|)
operator|&&
name|eventDispatcher
operator|->
name|processEvents
argument_list|(
name|QEventLoop
operator|::
name|AllEvents
argument_list|)
condition|)
block|{
empty_stmt|;
block|}
block|}
end_function
begin_comment
comment|// test that the eventDispatcher's timer implementation is complete and working
end_comment
begin_function
DECL|function|registerTimer
name|void
name|tst_QEventDispatcher
operator|::
name|registerTimer
parameter_list|()
block|{
DECL|macro|FIND_TIMERS
define|#
directive|define
name|FIND_TIMERS
parameter_list|()
define|\
value|do { \             foundPrecise = false; \             foundCoarse = false; \             foundVeryCoarse = false; \             for (int i = 0; i< registeredTimers.count(); ++i) { \                 const QAbstractEventDispatcher::TimerInfo&timerInfo = registeredTimers.at(i); \                 if (timerInfo.timerId == preciseTimerId) { \                     QCOMPARE(timerInfo.interval, int(PreciseTimerInterval)); \                     QCOMPARE(timerInfo.timerType, Qt::PreciseTimer); \                     foundPrecise = true; \                 } else if (timerInfo.timerId == coarseTimerId) { \                     QCOMPARE(timerInfo.interval, int(CoarseTimerInterval)); \                     QCOMPARE(timerInfo.timerType, Qt::CoarseTimer); \                     foundCoarse = true; \                 } else if (timerInfo.timerId == veryCoarseTimerId) { \                     QCOMPARE(timerInfo.interval, int(VeryCoarseTimerInterval)); \                     QCOMPARE(timerInfo.timerType, Qt::VeryCoarseTimer); \                     foundVeryCoarse = true; \                 } \             } \         } while (0)
comment|// start 3 timers, each with the different timer types and different intervals
name|int
name|preciseTimerId
init|=
name|eventDispatcher
operator|->
name|registerTimer
argument_list|(
name|PreciseTimerInterval
argument_list|,
name|Qt
operator|::
name|PreciseTimer
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|int
name|coarseTimerId
init|=
name|eventDispatcher
operator|->
name|registerTimer
argument_list|(
name|CoarseTimerInterval
argument_list|,
name|Qt
operator|::
name|CoarseTimer
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|int
name|veryCoarseTimerId
init|=
name|eventDispatcher
operator|->
name|registerTimer
argument_list|(
name|VeryCoarseTimerInterval
argument_list|,
name|Qt
operator|::
name|VeryCoarseTimer
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|preciseTimerId
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|coarseTimerId
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|veryCoarseTimerId
operator|>
literal|0
argument_list|)
expr_stmt|;
comment|// check that all 3 are present in the eventDispatcher's registeredTimer() list
name|QList
argument_list|<
name|QAbstractEventDispatcher
operator|::
name|TimerInfo
argument_list|>
name|registeredTimers
init|=
name|eventDispatcher
operator|->
name|registeredTimers
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|registeredTimers
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|bool
name|foundPrecise
decl_stmt|,
name|foundCoarse
decl_stmt|,
name|foundVeryCoarse
decl_stmt|;
name|FIND_TIMERS
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|foundPrecise
operator|&&
name|foundCoarse
operator|&&
name|foundVeryCoarse
argument_list|)
expr_stmt|;
comment|// process events, waiting for the next event... this should only fire the precise timer
name|receivedEventType
operator|=
operator|-
literal|1
expr_stmt|;
name|timerIdFromEvent
operator|=
operator|-
literal|1
expr_stmt|;
name|QTRY_COMPARE_WITH_TIMEOUT
argument_list|(
name|receivedEventType
argument_list|,
name|int
argument_list|(
name|QEvent
operator|::
name|Timer
argument_list|)
argument_list|,
name|PreciseTimerInterval
operator|*
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|timerIdFromEvent
argument_list|,
name|preciseTimerId
argument_list|)
expr_stmt|;
comment|// now unregister it and make sure it's gone
name|eventDispatcher
operator|->
name|unregisterTimer
argument_list|(
name|preciseTimerId
argument_list|)
expr_stmt|;
name|registeredTimers
operator|=
name|eventDispatcher
operator|->
name|registeredTimers
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|registeredTimers
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|FIND_TIMERS
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|foundPrecise
operator|&&
name|foundCoarse
operator|&&
name|foundVeryCoarse
argument_list|)
expr_stmt|;
comment|// do the same again for the coarse timer
name|receivedEventType
operator|=
operator|-
literal|1
expr_stmt|;
name|timerIdFromEvent
operator|=
operator|-
literal|1
expr_stmt|;
name|QTRY_COMPARE_WITH_TIMEOUT
argument_list|(
name|receivedEventType
argument_list|,
name|int
argument_list|(
name|QEvent
operator|::
name|Timer
argument_list|)
argument_list|,
name|CoarseTimerInterval
operator|*
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|timerIdFromEvent
argument_list|,
name|coarseTimerId
argument_list|)
expr_stmt|;
comment|// now unregister it and make sure it's gone
name|eventDispatcher
operator|->
name|unregisterTimer
argument_list|(
name|coarseTimerId
argument_list|)
expr_stmt|;
name|registeredTimers
operator|=
name|eventDispatcher
operator|->
name|registeredTimers
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|registeredTimers
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|FIND_TIMERS
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|foundPrecise
operator|&&
operator|!
name|foundCoarse
operator|&&
name|foundVeryCoarse
argument_list|)
expr_stmt|;
comment|// not going to wait for the VeryCoarseTimer, would take too long, just unregister it
name|eventDispatcher
operator|->
name|unregisterTimers
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|registeredTimers
operator|=
name|eventDispatcher
operator|->
name|registeredTimers
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|registeredTimers
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
DECL|macro|FIND_TIMERS
undef|#
directive|undef
name|FIND_TIMERS
block|}
end_function
begin_function
DECL|function|sendPostedEvents_data
name|void
name|tst_QEventDispatcher
operator|::
name|sendPostedEvents_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"processEventsFlagsInt"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"WaitForMoreEvents"
argument_list|)
operator|<<
name|int
argument_list|(
name|QEventLoop
operator|::
name|WaitForMoreEvents
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"AllEvents"
argument_list|)
operator|<<
name|int
argument_list|(
name|QEventLoop
operator|::
name|AllEvents
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// test that the eventDispatcher sends posted events correctly
end_comment
begin_function
DECL|function|sendPostedEvents
name|void
name|tst_QEventDispatcher
operator|::
name|sendPostedEvents
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|processEventsFlagsInt
argument_list|)
expr_stmt|;
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|processEventsFlags
init|=
name|QEventLoop
operator|::
name|ProcessEventsFlags
argument_list|(
name|processEventsFlagsInt
argument_list|)
decl_stmt|;
name|QElapsedTimer
name|elapsedTimer
decl_stmt|;
name|elapsedTimer
operator|.
name|start
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|elapsedTimer
operator|.
name|hasExpired
argument_list|(
literal|200
argument_list|)
condition|)
block|{
name|receivedEventType
operator|=
operator|-
literal|1
expr_stmt|;
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
comment|// event shouldn't be delivered as a result of posting
name|QCOMPARE
argument_list|(
name|receivedEventType
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// since there is a pending posted event, this should not actually block, it should send the posted event and return
name|QVERIFY
argument_list|(
name|eventDispatcher
operator|->
name|processEvents
argument_list|(
name|processEventsFlags
argument_list|)
argument_list|)
expr_stmt|;
comment|// event shouldn't be delivered as a result of posting
name|QCOMPARE
argument_list|(
name|receivedEventType
argument_list|,
name|int
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|ProcessEventsOnlySendsQueuedEvents
class|class
name|ProcessEventsOnlySendsQueuedEvents
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|member|eventsReceived
name|int
name|eventsReceived
decl_stmt|;
DECL|function|ProcessEventsOnlySendsQueuedEvents
specifier|inline
name|ProcessEventsOnlySendsQueuedEvents
parameter_list|()
member_init_list|:
name|eventsReceived
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|event
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
operator|++
name|eventsReceived
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|User
condition|)
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|(
name|QEvent
operator|::
name|User
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QObject
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
public|public
name|slots
public|:
DECL|function|timerFired
name|void
name|timerFired
parameter_list|()
block|{
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|this
argument_list|,
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|Type
argument_list|(
name|QEvent
operator|::
name|User
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|processEventsOnlySendsQueuedEvents
name|void
name|tst_QEventDispatcher
operator|::
name|processEventsOnlySendsQueuedEvents
parameter_list|()
block|{
name|ProcessEventsOnlySendsQueuedEvents
name|object
decl_stmt|;
comment|// Posted events during event processing should be handled on
comment|// the next processEvents iteration.
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
operator|&
name|object
argument_list|,
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|User
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|object
operator|.
name|eventsReceived
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|object
operator|.
name|eventsReceived
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// The same goes for posted events during timer processing
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
operator|&
name|object
argument_list|,
name|SLOT
argument_list|(
name|timerFired
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|object
operator|.
name|eventsReceived
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|object
operator|.
name|eventsReceived
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QEventDispatcher
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qeventdispatcher.moc"
end_include
end_unit
