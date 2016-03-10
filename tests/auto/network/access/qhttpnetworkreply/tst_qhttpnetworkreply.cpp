begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QBuffer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|"private/qhttpnetworkconnection_p.h"
end_include
begin_class
DECL|class|tst_QHttpNetworkReply
class|class
name|tst_QHttpNetworkReply
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|Q_SLOTS
private|:
name|void
name|parseHeader_data
parameter_list|()
function_decl|;
name|void
name|parseHeader
parameter_list|()
function_decl|;
name|void
name|parseEndOfHeader_data
parameter_list|()
function_decl|;
name|void
name|parseEndOfHeader
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|parseHeader_data
name|void
name|tst_QHttpNetworkReply
operator|::
name|parseHeader_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"headers"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"fields"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"values"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty-field"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"Set-Cookie: \r\n"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Set-Cookie"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|""
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"single-field"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"Content-Type: text/html; charset=utf-8\r\n"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Content-Type"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"text/html; charset=utf-8"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"single-field-continued"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"Content-Type: text/html;\r\n"
literal|" charset=utf-8\r\n"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Content-Type"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"text/html; charset=utf-8"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"multi-field"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"Content-Type: text/html; charset=utf-8\r\n"
literal|"Content-Length: 1024\r\n"
literal|"Content-Encoding: gzip\r\n"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Content-Type"
operator|<<
literal|"Content-Length"
operator|<<
literal|"Content-Encoding"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"text/html; charset=utf-8"
operator|<<
literal|"1024"
operator|<<
literal|"gzip"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"multi-field-with-emtpy"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"Content-Type: text/html; charset=utf-8\r\n"
literal|"Content-Length: 1024\r\n"
literal|"Set-Cookie: \r\n"
literal|"Content-Encoding: gzip\r\n"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Content-Type"
operator|<<
literal|"Content-Length"
operator|<<
literal|"Set-Cookie"
operator|<<
literal|"Content-Encoding"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"text/html; charset=utf-8"
operator|<<
literal|"1024"
operator|<<
literal|""
operator|<<
literal|"gzip"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lws-field"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"Content-Type: text/html; charset=utf-8\r\n"
literal|"Content-Length:\r\n 1024\r\n"
literal|"Content-Encoding: gzip\r\n"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Content-Type"
operator|<<
literal|"Content-Length"
operator|<<
literal|"Content-Encoding"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"text/html; charset=utf-8"
operator|<<
literal|"1024"
operator|<<
literal|"gzip"
operator|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"duplicated-field"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"Vary: Accept-Language\r\n"
literal|"Vary: Cookie\r\n"
literal|"Vary: User-Agent\r\n"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Vary"
operator|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"Accept-Language, Cookie, User-Agent"
operator|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parseHeader
name|void
name|tst_QHttpNetworkReply
operator|::
name|parseHeader
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|headers
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|fields
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|values
argument_list|)
expr_stmt|;
name|QHttpNetworkReply
name|reply
decl_stmt|;
name|reply
operator|.
name|parseHeader
argument_list|(
name|headers
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
name|fields
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
comment|//qDebug()<< "field"<< fields.at(i)<< "value"<< reply.headerField(fields.at(i))<< "expected"<< values.at(i);
name|QString
name|field
init|=
name|reply
operator|.
name|headerField
argument_list|(
name|fields
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|field
argument_list|,
name|values
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_class
DECL|class|TestHeaderSocket
class|class
name|TestHeaderSocket
super|:
specifier|public
name|QAbstractSocket
block|{
public|public:
DECL|function|TestHeaderSocket
specifier|explicit
name|TestHeaderSocket
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|input
parameter_list|)
member_init_list|:
name|QAbstractSocket
argument_list|(
name|QAbstractSocket
operator|::
name|TcpSocket
argument_list|,
name|Q_NULLPTR
argument_list|)
block|{
name|inputBuffer
operator|.
name|setData
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|inputBuffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Unbuffered
argument_list|)
expr_stmt|;
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Unbuffered
argument_list|)
expr_stmt|;
block|}
DECL|function|readData
name|qint64
name|readData
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
block|{
return|return
name|inputBuffer
operator|.
name|read
argument_list|(
name|data
argument_list|,
name|maxlen
argument_list|)
return|;
block|}
DECL|member|inputBuffer
name|QBuffer
name|inputBuffer
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|TestHeaderReply
class|class
name|TestHeaderReply
super|:
specifier|public
name|QHttpNetworkReply
block|{
public|public:
DECL|function|replyPrivate
name|QHttpNetworkReplyPrivate
modifier|*
name|replyPrivate
parameter_list|()
block|{
return|return
cast|static_cast
argument_list|<
name|QHttpNetworkReplyPrivate
operator|*
argument_list|>
argument_list|(
name|d_ptr
operator|.
name|data
argument_list|()
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|parseEndOfHeader_data
name|void
name|tst_QHttpNetworkReply
operator|::
name|parseEndOfHeader_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QByteArray
argument_list|>
argument_list|(
literal|"headers"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qint64
argument_list|>
argument_list|(
literal|"lengths"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"CRLFCRLF"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"Content-Type: text/html; charset=utf-8\r\n"
literal|"Content-Length:\r\n 1024\r\n"
literal|"Content-Encoding: gzip\r\n\r\nHTTPBODY"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|90
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"CRLFLF"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"Content-Type: text/html; charset=utf-8\r\n"
literal|"Content-Length:\r\n 1024\r\n"
literal|"Content-Encoding: gzip\r\n\nHTTPBODY"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|89
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"LFCRLF"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"Content-Type: text/html; charset=utf-8\r\n"
literal|"Content-Length:\r\n 1024\r\n"
literal|"Content-Encoding: gzip\n\r\nHTTPBODY"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|89
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"LFLF"
argument_list|)
operator|<<
name|QByteArray
argument_list|(
literal|"Content-Type: text/html; charset=utf-8\r\n"
literal|"Content-Length:\r\n 1024\r\n"
literal|"Content-Encoding: gzip\n\nHTTPBODY"
argument_list|)
operator|<<
name|qint64
argument_list|(
literal|88
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parseEndOfHeader
name|void
name|tst_QHttpNetworkReply
operator|::
name|parseEndOfHeader
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QByteArray
argument_list|,
name|headers
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qint64
argument_list|,
name|lengths
argument_list|)
expr_stmt|;
name|TestHeaderSocket
name|socket
argument_list|(
name|headers
argument_list|)
decl_stmt|;
name|TestHeaderReply
name|reply
decl_stmt|;
name|QHttpNetworkReplyPrivate
modifier|*
name|replyPrivate
init|=
name|reply
operator|.
name|replyPrivate
argument_list|()
decl_stmt|;
name|qint64
name|headerBytes
init|=
name|replyPrivate
operator|->
name|readHeader
argument_list|(
operator|&
name|socket
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|headerBytes
argument_list|,
name|lengths
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QHttpNetworkReply
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qhttpnetworkreply.moc"
end_include
end_unit
