begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_decl_stmt
DECL|variable|errorName
specifier|const
name|char
name|errorName
index|[]
init|=
literal|"org.qtproject.tst_QDBusContext.Error"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|errorMsg
specifier|const
name|char
name|errorMsg
index|[]
init|=
literal|"A generic error"
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|TestObject
class|class
name|TestObject
super|:
specifier|public
name|QObject
super|,
specifier|protected
name|QDBusContext
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"org.qtproject.tst_QDBusContext.TestObject"
argument_list|)
decl|public
range|:
DECL|function|TestObject
specifier|inline
name|TestObject
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{ }
specifier|public
name|Q_SLOTS
operator|:
name|void
name|generateError
argument_list|()
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|tst_QDBusContext
class|class
name|tst_QDBusContext
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|sendErrorReply
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|generateError
name|void
name|TestObject
operator|::
name|generateError
parameter_list|()
block|{
name|sendErrorReply
argument_list|(
name|errorName
argument_list|,
name|errorMsg
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_QDBusContext
operator|::
name|initTestCase
parameter_list|()
block|{
name|TestObject
modifier|*
name|obj
init|=
operator|new
name|TestObject
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
operator|.
name|isConnected
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
operator|.
name|registerObject
argument_list|(
literal|"/TestObject"
argument_list|,
name|obj
argument_list|,
name|QDBusConnection
operator|::
name|ExportAllSlots
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sendErrorReply
name|void
name|tst_QDBusContext
operator|::
name|sendErrorReply
parameter_list|()
block|{
name|QDBusInterface
name|iface
argument_list|(
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
operator|.
name|baseService
argument_list|()
argument_list|,
literal|"/TestObject"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|iface
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QDBusReply
argument_list|<
name|void
argument_list|>
name|reply
init|=
name|iface
operator|.
name|call
argument_list|(
literal|"generateError"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|reply
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QDBusError
modifier|&
name|error
init|=
name|reply
operator|.
name|error
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|error
operator|.
name|name
argument_list|()
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
name|errorName
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|error
operator|.
name|message
argument_list|()
argument_list|,
name|QString
operator|::
name|fromLatin1
argument_list|(
name|errorMsg
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QDBusContext
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qdbuscontext.moc"
end_include
end_unit
