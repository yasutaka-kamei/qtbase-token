begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TST_QDBUSCONNECTION_H
end_ifndef
begin_define
DECL|macro|TST_QDBUSCONNECTION_H
define|#
directive|define
name|TST_QDBUSCONNECTION_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_decl_stmt
name|class
name|BaseObject
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"local.BaseObject"
argument_list|)
name|public
operator|:
name|BaseObject
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{ }
name|public
name|slots
operator|:
name|void
name|anotherMethod
argument_list|()
block|{ }
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|MyObject
range|:
name|public
name|BaseObject
block|{
name|Q_OBJECT
name|public
name|slots
operator|:
name|void
name|method
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|msg
argument_list|)
block|;
name|public
operator|:
specifier|static
name|QString
name|path
block|;
name|int
name|callCount
block|;
name|MyObject
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|BaseObject
argument_list|(
name|parent
argument_list|)
block|,
name|callCount
argument_list|(
literal|0
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|MyObjectWithoutInterface
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
name|slots
operator|:
name|void
name|method
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|msg
argument_list|)
block|;
name|public
operator|:
specifier|static
name|QString
name|path
block|;
specifier|static
name|QString
name|interface
block|;
name|int
name|callCount
block|;
name|MyObjectWithoutInterface
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|,
name|callCount
argument_list|(
literal|0
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|tst_QDBusConnection
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|int
name|signalsReceived
block|;
name|public
operator|:
specifier|static
name|int
name|hookCallCount
block|;
name|tst_QDBusConnection
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|oneSlot
argument_list|()
block|{
operator|++
name|signalsReceived
block|; }
name|void
name|exitLoop
argument_list|()
block|{
operator|++
name|signalsReceived
block|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|exitLoop
argument_list|()
block|; }
name|void
name|secondCallWithCallback
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|cleanup
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|noConnection
argument_list|()
block|;
name|void
name|connectToBus
argument_list|()
block|;
name|void
name|connectToPeer
argument_list|()
block|;
name|void
name|connect
argument_list|()
block|;
name|void
name|send
argument_list|()
block|;
name|void
name|sendWithGui
argument_list|()
block|;
name|void
name|sendAsync
argument_list|()
block|;
name|void
name|sendSignal
argument_list|()
block|;
name|void
name|sendSignalToName
argument_list|()
block|;
name|void
name|sendSignalToOtherName
argument_list|()
block|;
name|void
name|registerObject_data
argument_list|()
block|;
name|void
name|registerObject
argument_list|()
block|;
name|void
name|registerObjectWithInterface_data
argument_list|()
block|;
name|void
name|registerObjectWithInterface
argument_list|()
block|;
name|void
name|registerObjectPeer_data
argument_list|()
block|;
name|void
name|registerObjectPeer
argument_list|()
block|;
name|void
name|registerObject2
argument_list|()
block|;
name|void
name|registerObjectPeer2
argument_list|()
block|;
name|void
name|registerQObjectChildren
argument_list|()
block|;
name|void
name|registerQObjectChildrenPeer
argument_list|()
block|;
name|void
name|callSelf
argument_list|()
block|;
name|void
name|callSelfByAnotherName_data
argument_list|()
block|;
name|void
name|callSelfByAnotherName
argument_list|()
block|;
name|void
name|multipleInterfacesInQObject
argument_list|()
block|;
name|void
name|slotsWithLessParameters
argument_list|()
block|;
name|void
name|nestedCallWithCallback
argument_list|()
block|;
name|void
name|serviceRegistrationRaceCondition
argument_list|()
block|;
name|void
name|registerVirtualObject
argument_list|()
block|;
name|void
name|callVirtualObject
argument_list|()
block|;
name|void
name|callVirtualObjectLocal
argument_list|()
block|;
name|void
name|pendingCallWhenDisconnected
argument_list|()
block|;
name|public
operator|:
name|QString
name|serviceName
argument_list|()
specifier|const
block|{
return|return
literal|"org.qtproject.Qt.Autotests.QDBusConnection"
return|;
block|}
name|bool
name|callMethod
argument_list|(
specifier|const
name|QDBusConnection
operator|&
name|conn
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|bool
name|callMethod
argument_list|(
specifier|const
name|QDBusConnection
operator|&
name|conn
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QString
operator|&
name|interface
argument_list|)
block|;
name|bool
name|callMethodPeer
argument_list|(
specifier|const
name|QDBusConnection
operator|&
name|conn
argument_list|,
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusSpy
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
name|slots
operator|:
name|void
name|handlePing
argument_list|(
argument|const QString&str
argument_list|)
block|{
name|args
operator|.
name|clear
argument_list|()
block|;
name|args
operator|<<
name|str
block|; }
name|void
name|asyncReply
argument_list|(
argument|const QDBusMessage&msg
argument_list|)
block|{
name|args
operator|=
name|msg
operator|.
name|arguments
argument_list|()
block|; }
name|public
operator|:
name|QList
operator|<
name|QVariant
operator|>
name|args
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|MyServer
range|:
name|public
name|QDBusServer
block|{
name|Q_OBJECT
name|public
operator|:
name|MyServer
argument_list|(
argument|QString path
argument_list|)
operator|:
name|m_path
argument_list|(
name|path
argument_list|)
block|,
name|m_connections
argument_list|()
block|{
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|newConnection
argument_list|(
name|QDBusConnection
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|handleConnection
argument_list|(
name|QDBusConnection
argument_list|)
argument_list|)
argument_list|)
block|;     }
name|bool
name|registerObject
argument_list|(
argument|const QDBusConnection& c
argument_list|)
block|{
name|QDBusConnection
name|conn
argument_list|(
name|c
argument_list|)
block|;
if|if
condition|(
operator|!
name|conn
operator|.
name|registerObject
argument_list|(
name|m_path
argument_list|,
operator|&
name|m_obj
argument_list|,
name|QDBusConnection
operator|::
name|ExportAllSlots
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
operator|!
operator|(
name|conn
operator|.
name|objectRegisteredAt
argument_list|(
name|m_path
argument_list|)
operator|==
operator|&
name|m_obj
operator|)
condition|)
return|return
name|false
return|;
end_decl_stmt
begin_return
return|return
name|true
return|;
end_return
begin_macro
unit|}      bool
name|registerObject
argument_list|()
end_macro
begin_block
block|{
name|Q_FOREACH
argument_list|(
argument|const QString&name
argument_list|,
argument|m_connections
argument_list|)
block|{
if|if
condition|(
operator|!
name|registerObject
argument_list|(
name|QDBusConnection
argument_list|(
name|name
argument_list|)
argument_list|)
condition|)
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
end_block
begin_function
name|void
name|unregisterObject
parameter_list|()
block|{
name|Q_FOREACH
argument_list|(
argument|const QString&name
argument_list|,
argument|m_connections
argument_list|)
block|{
name|QDBusConnection
name|c
argument_list|(
name|name
argument_list|)
decl_stmt|;
name|c
operator|.
name|unregisterObject
argument_list|(
name|m_path
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
name|public
name|slots
range|:
name|void
name|handleConnection
argument_list|(
argument|const QDBusConnection& c
argument_list|)
block|{
name|m_connections
operator|<<
name|c
operator|.
name|name
argument_list|()
block|;
name|QVERIFY
argument_list|(
name|isConnected
argument_list|()
argument_list|)
block|;
name|QVERIFY
argument_list|(
name|c
operator|.
name|isConnected
argument_list|()
argument_list|)
block|;
name|QVERIFY
argument_list|(
name|registerObject
argument_list|(
name|c
argument_list|)
argument_list|)
block|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|exitLoop
argument_list|()
block|;     }
name|private
operator|:
name|MyObject
name|m_obj
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|m_path
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStringList
name|m_connections
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|MyServer2
range|:
name|public
name|QDBusServer
block|{
name|Q_OBJECT
name|public
operator|:
name|MyServer2
argument_list|()
operator|:
name|m_conn
argument_list|(
literal|"none"
argument_list|)
block|{
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|newConnection
argument_list|(
name|QDBusConnection
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|handleConnection
argument_list|(
name|QDBusConnection
argument_list|)
argument_list|)
argument_list|)
block|;     }
name|QDBusConnection
name|connection
argument_list|()
block|{
return|return
name|m_conn
return|;
block|}
name|public
name|slots
operator|:
name|void
name|handleConnection
argument_list|(
argument|const QDBusConnection& c
argument_list|)
block|{
name|m_conn
operator|=
name|c
block|;
name|QVERIFY
argument_list|(
name|isConnected
argument_list|()
argument_list|)
block|;
name|QVERIFY
argument_list|(
name|m_conn
operator|.
name|isConnected
argument_list|()
argument_list|)
block|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|exitLoop
argument_list|()
block|;     }
name|private
operator|:
name|MyObject
name|m_obj
block|;
name|QDBusConnection
name|m_conn
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|TestObject
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|TestObject
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
operator|~
name|TestObject
argument_list|()
block|{}
name|QString
name|func
block|;
name|public
name|slots
operator|:
name|void
name|test0
argument_list|()
block|{
name|func
operator|=
literal|"test0"
block|; }
name|void
name|test1
argument_list|(
argument|int i
argument_list|)
block|{
name|func
operator|=
literal|"test1 "
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
block|; }
name|int
name|test2
argument_list|()
block|{
name|func
operator|=
literal|"test2"
block|;
return|return
literal|43
return|;
block|}
name|int
name|test3
argument_list|(
argument|int i
argument_list|)
block|{
name|func
operator|=
literal|"test2"
block|;
return|return
name|i
operator|+
literal|1
return|;
block|}
expr|}
block|;
name|class
name|RaceConditionSignalWaiter
operator|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|int
name|count
block|;
name|RaceConditionSignalWaiter
argument_list|()
operator|:
name|count
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|RaceConditionSignalWaiter
argument_list|()
block|{}
name|public
name|slots
operator|:
name|void
name|countUp
argument_list|()
block|{
operator|++
name|count
block|;
name|emit
name|done
argument_list|()
block|; }
name|signals
operator|:
name|void
name|done
argument_list|()
block|; }
block|;
name|class
name|VirtualObject
operator|:
name|public
name|QDBusVirtualObject
block|{
name|Q_OBJECT
name|public
operator|:
name|VirtualObject
argument_list|()
operator|:
name|success
argument_list|(
argument|true
argument_list|)
block|{}
name|QString
name|introspect
argument_list|(
argument|const QString&
comment|/* path */
argument_list|)
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
name|bool
name|handleMessage
argument_list|(
argument|const QDBusMessage&message
argument_list|,
argument|const QDBusConnection&connection
argument_list|)
block|{
operator|++
name|callCount
block|;
name|lastMessage
operator|=
name|message
block|;
if|if
condition|(
name|success
condition|)
block|{
name|QDBusMessage
name|reply
init|=
name|message
operator|.
name|createReply
argument_list|(
name|replyArguments
argument_list|)
decl_stmt|;
name|connection
operator|.
name|send
argument_list|(
name|reply
argument_list|)
expr_stmt|;
block|}
name|emit
name|messageReceived
parameter_list|(
name|message
parameter_list|)
function_decl|;
return|return
name|success
return|;
block|}
name|signals
operator|:
name|void
name|messageReceived
argument_list|(
argument|const QDBusMessage&message
argument_list|)
specifier|const
block|;
name|public
operator|:
name|mutable
name|QDBusMessage
name|lastMessage
block|;
name|QVariantList
name|replyArguments
block|;
name|mutable
name|int
name|callCount
block|;
name|bool
name|success
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TST_QDBUSCONNECTION_H
end_comment
end_unit
