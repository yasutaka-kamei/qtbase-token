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
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QBuffer>
end_include
begin_include
include|#
directive|include
file|<QImageReader>
end_include
begin_include
include|#
directive|include
file|<QSize>
end_include
begin_class
DECL|class|tst_jpeg
class|class
name|tst_jpeg
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|jpegDecodingQtWebkitStyle
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|jpegDecodingQtWebkitStyle
name|void
name|tst_jpeg
operator|::
name|jpegDecodingQtWebkitStyle
parameter_list|()
block|{
comment|// QtWebkit currently calls size() to get the image size for layouting purposes.
comment|// Then when it is in the viewport (we assume that here) it actually gets decoded.
name|QString
name|testFile
init|=
name|QFINDTESTDATA
argument_list|(
literal|"n900.jpeg"
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
operator|!
name|testFile
operator|.
name|isEmpty
argument_list|()
argument_list|,
literal|"cannot find test file n900.jpeg!"
argument_list|)
expr_stmt|;
name|QFile
name|inputJpeg
argument_list|(
name|testFile
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|inputJpeg
operator|.
name|exists
argument_list|()
argument_list|)
expr_stmt|;
name|inputJpeg
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QByteArray
name|imageData
init|=
name|inputJpeg
operator|.
name|readAll
argument_list|()
decl_stmt|;
name|QBuffer
name|buffer
decl_stmt|;
name|buffer
operator|.
name|setData
argument_list|(
name|imageData
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QBuffer
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|buffer
operator|.
name|size
argument_list|()
argument_list|,
name|qint64
argument_list|(
literal|19016
argument_list|)
argument_list|)
expr_stmt|;
name|QBENCHMARK
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
literal|50
condition|;
name|i
operator|++
control|)
block|{
name|QImageReader
name|reader
argument_list|(
operator|&
name|buffer
argument_list|,
literal|"jpeg"
argument_list|)
decl_stmt|;
name|QSize
name|size
init|=
name|reader
operator|.
name|size
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|size
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|QByteArray
name|format
init|=
name|reader
operator|.
name|format
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|format
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QImage
name|img
init|=
name|reader
operator|.
name|read
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|img
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_jpeg
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"jpeg.moc"
end_include
end_unit
