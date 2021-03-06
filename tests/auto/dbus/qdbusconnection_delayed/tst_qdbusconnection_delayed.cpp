begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtDBus>
end_include
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<process.h>
end_include
begin_define
DECL|macro|getpid
define|#
directive|define
name|getpid
value|_getpid
end_define
begin_else
else|#
directive|else
end_else
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
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QDBusConnection_Delayed
class|class
name|tst_QDBusConnection_Delayed
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|delayedMessages
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|Foo
class|class
name|Foo
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"org.qtproject.tst_qdbusconnection_delayed.Foo"
argument_list|)
decl|public
name|slots
range|:
DECL|function|bar
name|int
name|bar
argument_list|()
block|{
return|return
literal|42
return|;
block|}
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|executedOnce
specifier|static
name|bool
name|executedOnce
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|delayedMessages
name|void
name|tst_QDBusConnection_Delayed
operator|::
name|delayedMessages
parameter_list|()
block|{
if|if
condition|(
name|executedOnce
condition|)
name|QSKIP
argument_list|(
literal|"This test can only be executed once"
argument_list|)
expr_stmt|;
name|executedOnce
operator|=
literal|true
expr_stmt|;
name|int
name|argc
init|=
literal|1
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
init|=
block|{
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
literal|"tst_qdbusconnection_delayed"
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QDBusConnection
name|session
init|=
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|session
operator|.
name|isConnected
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|session
operator|.
name|baseService
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QDBusConnection
name|other
init|=
name|QDBusConnection
operator|::
name|connectToBus
argument_list|(
name|QDBusConnection
operator|::
name|SessionBus
argument_list|,
literal|"other"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|other
operator|.
name|isConnected
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|other
operator|.
name|baseService
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
comment|// make a method call: those should work even if delivery is disabled
name|QVERIFY
argument_list|(
name|session
operator|.
name|interface
argument_list|()
operator|->
name|isServiceRegistered
argument_list|(
name|other
operator|.
name|baseService
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// acquire a name in the main session bus connection: the effect is immediate
name|QString
name|name
init|=
literal|"org.qtproject.tst_qdbusconnection_delayed-"
operator|+
name|QString
operator|::
name|number
argument_list|(
name|getpid
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|session
operator|.
name|registerService
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|other
operator|.
name|interface
argument_list|()
operator|->
name|isServiceRegistered
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
comment|// make an asynchronous call to a yet-unregistered object
name|QDBusPendingCallWatcher
name|pending
argument_list|(
name|other
operator|.
name|asyncCall
argument_list|(
name|QDBusMessage
operator|::
name|createMethodCall
argument_list|(
name|name
argument_list|,
literal|"/foo"
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|"bar"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
comment|// sleep the main thread without running the event loop;
comment|// the call must not be delivered
name|QTest
operator|::
name|qSleep
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pending
operator|.
name|isFinished
argument_list|()
argument_list|)
expr_stmt|;
comment|// now register the object
name|Foo
name|foo
decl_stmt|;
name|session
operator|.
name|registerObject
argument_list|(
literal|"/foo"
argument_list|,
operator|&
name|foo
argument_list|,
name|QDBusConnection
operator|::
name|ExportAllSlots
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|pending
argument_list|,
operator|&
name|QDBusPendingCallWatcher
operator|::
name|finished
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|instance
argument_list|()
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|exitLoop
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|timeout
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|pending
operator|.
name|isFinished
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY2
argument_list|(
operator|!
name|pending
operator|.
name|isError
argument_list|()
argument_list|,
name|pending
operator|.
name|error
argument_list|()
operator|.
name|name
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|pending
operator|.
name|reply
argument_list|()
operator|.
name|arguments
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pending
operator|.
name|reply
argument_list|()
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QVariant
argument_list|(
literal|42
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QDBusConnection_Delayed
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdbusconnection_delayed.moc"
end_include
end_unit
