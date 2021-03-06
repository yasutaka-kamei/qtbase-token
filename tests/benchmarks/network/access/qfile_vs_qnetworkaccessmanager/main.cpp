begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkreply.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkrequest.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qnetworkaccessmanager.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTemporaryFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_class
DECL|class|qfile_vs_qnetworkaccessmanager
class|class
name|qfile_vs_qnetworkaccessmanager
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
protected|protected:
name|void
name|qnamFileRead_iteration
parameter_list|(
name|QNetworkAccessManager
modifier|&
name|manager
parameter_list|,
name|QNetworkRequest
modifier|&
name|request
parameter_list|)
function_decl|;
name|void
name|qnamImmediateFileRead_iteration
parameter_list|(
name|QNetworkAccessManager
modifier|&
name|manager
parameter_list|,
name|QNetworkRequest
modifier|&
name|request
parameter_list|)
function_decl|;
name|void
name|qfileFileRead_iteration
parameter_list|()
function_decl|;
DECL|member|iterations
specifier|static
specifier|const
name|int
name|iterations
init|=
literal|10
decl_stmt|;
private|private
name|slots
private|:
name|void
name|qnamFileRead
parameter_list|()
function_decl|;
name|void
name|qnamImmediateFileRead
parameter_list|()
function_decl|;
name|void
name|qfileFileRead
parameter_list|()
function_decl|;
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
public|public:
DECL|member|size
name|qint64
name|size
decl_stmt|;
DECL|member|testFile
name|QTemporaryFile
name|testFile
decl_stmt|;
DECL|function|qfile_vs_qnetworkaccessmanager
name|qfile_vs_qnetworkaccessmanager
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
member_init_list|,
name|size
argument_list|(
literal|0
argument_list|)
block|{}
empty_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|qfile_vs_qnetworkaccessmanager
operator|::
name|initTestCase
parameter_list|()
block|{
name|testFile
operator|.
name|open
argument_list|()
expr_stmt|;
name|QByteArray
name|qba
argument_list|(
literal|1
operator|*
literal|1024
operator|*
literal|1024
argument_list|,
literal|'x'
argument_list|)
decl_stmt|;
comment|// 1 MB
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|100
condition|;
name|i
operator|++
control|)
block|{
name|testFile
operator|.
name|write
argument_list|(
name|qba
argument_list|)
expr_stmt|;
name|testFile
operator|.
name|flush
argument_list|()
expr_stmt|;
name|size
operator|+=
name|qba
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
comment|// 100 MB or 10 MB
name|testFile
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|qfile_vs_qnetworkaccessmanager
operator|::
name|cleanupTestCase
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|qnamFileRead_iteration
name|void
name|qfile_vs_qnetworkaccessmanager
operator|::
name|qnamFileRead_iteration
parameter_list|(
name|QNetworkAccessManager
modifier|&
name|manager
parameter_list|,
name|QNetworkRequest
modifier|&
name|request
parameter_list|)
block|{
name|QNetworkReply
modifier|*
name|reply
init|=
name|manager
operator|.
name|get
argument_list|(
name|request
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|reply
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
operator|&
name|QTestEventLoop
operator|::
name|instance
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|exitLoop
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
name|QTestEventLoop
operator|::
name|instance
argument_list|()
operator|.
name|enterLoop
argument_list|(
literal|10
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
name|QByteArray
name|qba
init|=
name|reply
operator|->
name|readAll
argument_list|()
decl_stmt|;
operator|delete
name|reply
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qnamFileRead
name|void
name|qfile_vs_qnetworkaccessmanager
operator|::
name|qnamFileRead
parameter_list|()
block|{
name|QNetworkAccessManager
name|manager
decl_stmt|;
name|QTime
name|t
decl_stmt|;
name|QNetworkRequest
name|request
argument_list|(
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testFile
operator|.
name|fileName
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
comment|// do 3 dry runs for cache warmup
name|qnamFileRead_iteration
argument_list|(
name|manager
argument_list|,
name|request
argument_list|)
expr_stmt|;
name|qnamFileRead_iteration
argument_list|(
name|manager
argument_list|,
name|request
argument_list|)
expr_stmt|;
name|qnamFileRead_iteration
argument_list|(
name|manager
argument_list|,
name|request
argument_list|)
expr_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
comment|// 10 real runs
name|QBENCHMARK_ONCE
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iterations
condition|;
name|i
operator|++
control|)
block|{
name|qnamFileRead_iteration
argument_list|(
name|manager
argument_list|,
name|request
argument_list|)
expr_stmt|;
block|}
block|}
name|qint64
name|elapsed
init|=
name|t
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|endl
operator|<<
literal|"Finished!"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Bytes:"
operator|<<
name|size
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Speed:"
operator|<<
operator|(
name|qreal
argument_list|(
name|size
operator|*
name|iterations
argument_list|)
operator|/
literal|1024.0
operator|)
operator|/
operator|(
name|qreal
argument_list|(
name|elapsed
argument_list|)
operator|/
literal|1000.0
operator|)
operator|<<
literal|"KB/sec"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qnamImmediateFileRead_iteration
name|void
name|qfile_vs_qnetworkaccessmanager
operator|::
name|qnamImmediateFileRead_iteration
parameter_list|(
name|QNetworkAccessManager
modifier|&
name|manager
parameter_list|,
name|QNetworkRequest
modifier|&
name|request
parameter_list|)
block|{
name|QNetworkReply
modifier|*
name|reply
init|=
name|manager
operator|.
name|get
argument_list|(
name|request
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|reply
operator|->
name|isFinished
argument_list|()
argument_list|)
expr_stmt|;
comment|// should be like that!
name|QByteArray
name|qba
init|=
name|reply
operator|->
name|readAll
argument_list|()
decl_stmt|;
operator|delete
name|reply
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qnamImmediateFileRead
name|void
name|qfile_vs_qnetworkaccessmanager
operator|::
name|qnamImmediateFileRead
parameter_list|()
block|{
name|QNetworkAccessManager
name|manager
decl_stmt|;
name|QTime
name|t
decl_stmt|;
name|QNetworkRequest
name|request
argument_list|(
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|testFile
operator|.
name|fileName
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
comment|// do 3 dry runs for cache warmup
name|qnamImmediateFileRead_iteration
argument_list|(
name|manager
argument_list|,
name|request
argument_list|)
expr_stmt|;
name|qnamImmediateFileRead_iteration
argument_list|(
name|manager
argument_list|,
name|request
argument_list|)
expr_stmt|;
name|qnamImmediateFileRead_iteration
argument_list|(
name|manager
argument_list|,
name|request
argument_list|)
expr_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
comment|// 10 real runs
name|QBENCHMARK_ONCE
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iterations
condition|;
name|i
operator|++
control|)
block|{
name|qnamImmediateFileRead_iteration
argument_list|(
name|manager
argument_list|,
name|request
argument_list|)
expr_stmt|;
block|}
block|}
name|qint64
name|elapsed
init|=
name|t
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|endl
operator|<<
literal|"Finished!"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Bytes:"
operator|<<
name|size
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Speed:"
operator|<<
operator|(
name|qreal
argument_list|(
name|size
operator|*
name|iterations
argument_list|)
operator|/
literal|1024.0
operator|)
operator|/
operator|(
name|qreal
argument_list|(
name|elapsed
argument_list|)
operator|/
literal|1000.0
operator|)
operator|<<
literal|"KB/sec"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qfileFileRead_iteration
name|void
name|qfile_vs_qnetworkaccessmanager
operator|::
name|qfileFileRead_iteration
parameter_list|()
block|{
name|testFile
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QByteArray
name|qba
init|=
name|testFile
operator|.
name|readAll
argument_list|()
decl_stmt|;
block|}
end_function
begin_function
DECL|function|qfileFileRead
name|void
name|qfile_vs_qnetworkaccessmanager
operator|::
name|qfileFileRead
parameter_list|()
block|{
name|QTime
name|t
decl_stmt|;
comment|// do 3 dry runs for cache warmup
name|qfileFileRead_iteration
argument_list|()
expr_stmt|;
name|qfileFileRead_iteration
argument_list|()
expr_stmt|;
name|qfileFileRead_iteration
argument_list|()
expr_stmt|;
name|t
operator|.
name|start
argument_list|()
expr_stmt|;
comment|// 10 real runs
name|QBENCHMARK_ONCE
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|iterations
condition|;
name|i
operator|++
control|)
block|{
name|qfileFileRead_iteration
argument_list|()
expr_stmt|;
block|}
block|}
name|qint64
name|elapsed
init|=
name|t
operator|.
name|elapsed
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|endl
operator|<<
literal|"Finished!"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Bytes:"
operator|<<
name|size
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Speed:"
operator|<<
operator|(
name|qreal
argument_list|(
name|size
operator|*
name|iterations
argument_list|)
operator|/
literal|1024.0
operator|)
operator|/
operator|(
name|qreal
argument_list|(
name|elapsed
argument_list|)
operator|/
literal|1000.0
operator|)
operator|<<
literal|"KB/sec"
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|qfile_vs_qnetworkaccessmanager
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
