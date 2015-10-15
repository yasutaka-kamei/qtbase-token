begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|<private/qcore_unix_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
end_ifdef
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|Q_AUTOTEST_EXPORT
name|int
name|qt_poll
parameter_list|(
name|struct
name|pollfd
modifier|*
name|fds
parameter_list|,
name|nfds_t
name|nfds
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout_ts
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QT_END_NAMESPACE
endif|#
directive|endif
comment|// QT_BUILD_INTERNAL
name|QT_USE_NAMESPACE
DECL|class|tst_qt_poll
name|class
name|tst_qt_poll
operator|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
specifier|private
name|slots
operator|:
name|void
name|pollout
argument_list|()
block|;
name|void
name|pollin
argument_list|()
block|;
name|void
name|pollnval
argument_list|()
block|;
name|void
name|pollprihup
argument_list|()
block|;
endif|#
directive|endif
comment|// QT_BUILD_INTERNAL
block|}
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BUILD_INTERNAL
end_ifdef
begin_function
DECL|function|pollout
name|void
name|tst_qt_poll
operator|::
name|pollout
parameter_list|()
block|{
name|int
name|fds
index|[
literal|2
index|]
decl_stmt|;
name|QCOMPARE
argument_list|(
name|pipe
argument_list|(
name|fds
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|struct
name|pollfd
name|pfd
init|=
block|{
name|fds
index|[
literal|1
index|]
block|,
name|POLLOUT
block|,
literal|0
block|}
decl_stmt|;
specifier|const
name|int
name|nready
init|=
name|qt_poll
argument_list|(
operator|&
name|pfd
argument_list|,
literal|1
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|nready
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pfd
operator|.
name|revents
argument_list|,
name|short
argument_list|(
name|POLLOUT
argument_list|)
argument_list|)
expr_stmt|;
name|qt_safe_close
argument_list|(
name|fds
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|qt_safe_close
argument_list|(
name|fds
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pollin
name|void
name|tst_qt_poll
operator|::
name|pollin
parameter_list|()
block|{
name|int
name|fds
index|[
literal|2
index|]
decl_stmt|;
name|QCOMPARE
argument_list|(
name|pipe
argument_list|(
name|fds
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
specifier|const
name|char
name|data
init|=
literal|'Q'
decl_stmt|;
name|QCOMPARE
argument_list|(
name|qt_safe_write
argument_list|(
name|fds
index|[
literal|1
index|]
argument_list|,
operator|&
name|data
argument_list|,
literal|1
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|struct
name|pollfd
name|pfd
init|=
block|{
name|fds
index|[
literal|0
index|]
block|,
name|POLLIN
block|,
literal|0
block|}
decl_stmt|;
specifier|const
name|int
name|nready
init|=
name|qt_poll
argument_list|(
operator|&
name|pfd
argument_list|,
literal|1
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|nready
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pfd
operator|.
name|revents
argument_list|,
name|short
argument_list|(
name|POLLIN
argument_list|)
argument_list|)
expr_stmt|;
name|qt_safe_close
argument_list|(
name|fds
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|qt_safe_close
argument_list|(
name|fds
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pollnval
name|void
name|tst_qt_poll
operator|::
name|pollnval
parameter_list|()
block|{
name|struct
name|pollfd
name|pfd
init|=
block|{
literal|42
block|,
name|POLLOUT
block|,
literal|0
block|}
decl_stmt|;
name|int
name|nready
init|=
name|qt_poll
argument_list|(
operator|&
name|pfd
argument_list|,
literal|1
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|nready
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pfd
operator|.
name|revents
argument_list|,
name|short
argument_list|(
name|POLLNVAL
argument_list|)
argument_list|)
expr_stmt|;
name|pfd
operator|.
name|events
operator|=
literal|0
expr_stmt|;
name|pfd
operator|.
name|revents
operator|=
literal|0
expr_stmt|;
name|nready
operator|=
name|qt_poll
argument_list|(
operator|&
name|pfd
argument_list|,
literal|1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|nready
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pfd
operator|.
name|revents
argument_list|,
name|short
argument_list|(
name|POLLNVAL
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pollprihup
name|void
name|tst_qt_poll
operator|::
name|pollprihup
parameter_list|()
block|{
name|QTcpServer
name|server
decl_stmt|;
name|QTcpSocket
name|client_socket
decl_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|listen
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|quint16
name|server_port
init|=
name|server
operator|.
name|serverPort
argument_list|()
decl_stmt|;
name|client_socket
operator|.
name|connectToHost
argument_list|(
name|server
operator|.
name|serverAddress
argument_list|()
argument_list|,
name|server_port
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|client_socket
operator|.
name|waitForConnected
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|server
operator|.
name|waitForNewConnection
argument_list|()
argument_list|)
expr_stmt|;
name|QTcpSocket
modifier|*
name|server_socket
init|=
name|server
operator|.
name|nextPendingConnection
argument_list|()
decl_stmt|;
name|server
operator|.
name|close
argument_list|()
expr_stmt|;
comment|// TCP supports only a single byte of urgent data
specifier|static
specifier|const
name|char
name|oob_out
init|=
literal|'Q'
decl_stmt|;
name|QCOMPARE
argument_list|(
operator|::
name|send
argument_list|(
name|server_socket
operator|->
name|socketDescriptor
argument_list|()
argument_list|,
operator|&
name|oob_out
argument_list|,
literal|1
argument_list|,
name|MSG_OOB
argument_list|)
argument_list|,
name|ssize_t
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|struct
name|pollfd
name|pfd
init|=
block|{
name|int
argument_list|(
name|client_socket
operator|.
name|socketDescriptor
argument_list|()
argument_list|)
block|,
name|POLLPRI
operator||
name|POLLIN
block|,
literal|0
block|}
decl_stmt|;
name|int
name|res
init|=
name|qt_poll
argument_list|(
operator|&
name|pfd
argument_list|,
literal|1
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|res
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pfd
operator|.
name|revents
argument_list|,
name|short
argument_list|(
name|POLLPRI
operator||
name|POLLIN
argument_list|)
argument_list|)
expr_stmt|;
name|char
name|oob_in
init|=
literal|0
decl_stmt|;
comment|// We do not specify MSG_OOB here as SO_OOBINLINE is turned on by default
comment|// in the native socket engine
name|QCOMPARE
argument_list|(
operator|::
name|recv
argument_list|(
name|client_socket
operator|.
name|socketDescriptor
argument_list|()
argument_list|,
operator|&
name|oob_in
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|,
name|ssize_t
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|oob_in
argument_list|,
name|oob_out
argument_list|)
expr_stmt|;
name|server_socket
operator|->
name|close
argument_list|()
expr_stmt|;
name|pfd
operator|.
name|events
operator|=
name|POLLIN
expr_stmt|;
name|res
operator|=
name|qt_poll
argument_list|(
operator|&
name|pfd
argument_list|,
literal|1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|res
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pfd
operator|.
name|revents
argument_list|,
name|short
argument_list|(
name|POLLHUP
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_BUILD_INTERNAL
end_comment
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_qt_poll
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qt_poll.moc"
end_include
end_unit
