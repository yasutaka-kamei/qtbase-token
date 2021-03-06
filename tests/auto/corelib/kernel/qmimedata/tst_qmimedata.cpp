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
file|<QMimeData>
end_include
begin_class
DECL|class|tst_QMimeData
class|class
name|tst_QMimeData
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|clear
parameter_list|()
specifier|const
function_decl|;
name|void
name|colorData
parameter_list|()
specifier|const
function_decl|;
name|void
name|data
parameter_list|()
specifier|const
function_decl|;
name|void
name|formats
parameter_list|()
specifier|const
function_decl|;
name|void
name|hasColor
parameter_list|()
specifier|const
function_decl|;
name|void
name|hasFormat
parameter_list|()
specifier|const
function_decl|;
name|void
name|hasHtml
parameter_list|()
specifier|const
function_decl|;
name|void
name|hasImage
parameter_list|()
specifier|const
function_decl|;
comment|// hasText() covered by setText()
comment|// hasUrls() covered by setUrls()
comment|// html() covered by setHtml()
name|void
name|imageData
parameter_list|()
specifier|const
function_decl|;
name|void
name|removeFormat
parameter_list|()
specifier|const
function_decl|;
comment|// setColorData() covered by hasColor()
comment|// setData() covered in a few different tests
name|void
name|setHtml
parameter_list|()
specifier|const
function_decl|;
comment|// setImageData() covered in a few tests
name|void
name|setText
parameter_list|()
specifier|const
function_decl|;
name|void
name|setUrls
parameter_list|()
specifier|const
function_decl|;
comment|// text() covered in setText()
comment|// urls() covered by setUrls()
block|}
class|;
end_class
begin_function
DECL|function|clear
name|void
name|tst_QMimeData
operator|::
name|clear
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
comment|// set, clear, verify empty
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/plain"
argument_list|,
literal|"pirates"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasText
argument_list|()
argument_list|)
expr_stmt|;
name|mimeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasText
argument_list|()
argument_list|)
expr_stmt|;
comment|// repopulate, verify not empty
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/plain"
argument_list|,
literal|"pirates"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasText
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|colorData
name|void
name|tst_QMimeData
operator|::
name|colorData
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
name|QColor
name|red
init|=
name|Qt
operator|::
name|red
decl_stmt|;
name|QColor
name|blue
init|=
name|Qt
operator|::
name|blue
decl_stmt|;
comment|// set, verify
name|mimeData
operator|.
name|setColorData
argument_list|(
name|red
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasColor
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|mimeData
operator|.
name|colorData
argument_list|()
argument_list|)
argument_list|,
name|red
argument_list|)
expr_stmt|;
comment|// change, verify
name|mimeData
operator|.
name|setColorData
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasColor
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|mimeData
operator|.
name|colorData
argument_list|()
argument_list|)
argument_list|,
name|blue
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|data
name|void
name|tst_QMimeData
operator|::
name|data
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
comment|// set text, verify
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/plain"
argument_list|,
literal|"pirates"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|data
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"pirates"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|data
argument_list|(
literal|"text/html"
argument_list|)
operator|.
name|length
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// html time
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/html"
argument_list|,
literal|"ninjas"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|data
argument_list|(
literal|"text/html"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"ninjas"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|data
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"pirates"
argument_list|)
argument_list|)
expr_stmt|;
comment|// make sure text not damaged
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|data
argument_list|(
literal|"text/html"
argument_list|)
argument_list|,
name|mimeData
operator|.
name|html
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formats
name|void
name|tst_QMimeData
operator|::
name|formats
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
comment|// set text, verify
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/plain"
argument_list|,
literal|"pirates"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|formats
argument_list|()
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"text/plain"
argument_list|)
expr_stmt|;
comment|// set html, verify
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/html"
argument_list|,
literal|"ninjas"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|formats
argument_list|()
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"text/plain"
operator|<<
literal|"text/html"
argument_list|)
expr_stmt|;
comment|// clear, verify
name|mimeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|formats
argument_list|()
argument_list|,
name|QStringList
argument_list|()
argument_list|)
expr_stmt|;
comment|// set an odd format, verify
name|mimeData
operator|.
name|setData
argument_list|(
literal|"foo/bar"
argument_list|,
literal|"somevalue"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|formats
argument_list|()
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"foo/bar"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasColor
name|void
name|tst_QMimeData
operator|::
name|hasColor
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
comment|// initial state
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasColor
argument_list|()
argument_list|)
expr_stmt|;
comment|// set, verify
name|mimeData
operator|.
name|setColorData
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasColor
argument_list|()
argument_list|)
expr_stmt|;
comment|// clear, verify
name|mimeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasColor
argument_list|()
argument_list|)
expr_stmt|;
comment|// set something else, verify
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/plain"
argument_list|,
literal|"pirates"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasColor
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasFormat
name|void
name|tst_QMimeData
operator|::
name|hasFormat
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
comment|// initial state
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasFormat
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|)
expr_stmt|;
comment|// add, verify
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/plain"
argument_list|,
literal|"pirates"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasFormat
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasFormat
argument_list|(
literal|"text/html"
argument_list|)
argument_list|)
expr_stmt|;
comment|// clear, verify
name|mimeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasFormat
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasFormat
argument_list|(
literal|"text/html"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasHtml
name|void
name|tst_QMimeData
operator|::
name|hasHtml
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
comment|// initial state
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasHtml
argument_list|()
argument_list|)
expr_stmt|;
comment|// add plain, verify false
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/plain"
argument_list|,
literal|"pirates"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasHtml
argument_list|()
argument_list|)
expr_stmt|;
comment|// add html, verify
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/html"
argument_list|,
literal|"ninjas"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasHtml
argument_list|()
argument_list|)
expr_stmt|;
comment|// clear, verify
name|mimeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasHtml
argument_list|()
argument_list|)
expr_stmt|;
comment|// readd, verify
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/html"
argument_list|,
literal|"ninjas"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasHtml
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasImage
name|void
name|tst_QMimeData
operator|::
name|hasImage
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
comment|// initial state
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasImage
argument_list|()
argument_list|)
expr_stmt|;
comment|// add text, verify false
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/plain"
argument_list|,
literal|"pirates"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasImage
argument_list|()
argument_list|)
expr_stmt|;
comment|// add image
name|mimeData
operator|.
name|setImageData
argument_list|(
name|QImage
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasImage
argument_list|()
argument_list|)
expr_stmt|;
comment|// clear, verify
name|mimeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasImage
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|imageData
name|void
name|tst_QMimeData
operator|::
name|imageData
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
comment|// initial state
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|imageData
argument_list|()
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
comment|// set, test
name|mimeData
operator|.
name|setImageData
argument_list|(
name|QImage
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasImage
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|imageData
argument_list|()
argument_list|,
name|QVariant
argument_list|(
name|QImage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// clear, verify
name|mimeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|imageData
argument_list|()
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeFormat
name|void
name|tst_QMimeData
operator|::
name|removeFormat
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
comment|// add, verify
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/plain"
argument_list|,
literal|"pirates"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasFormat
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|)
expr_stmt|;
comment|// add another, verify
name|mimeData
operator|.
name|setData
argument_list|(
literal|"text/html"
argument_list|,
literal|"ninjas"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasFormat
argument_list|(
literal|"text/html"
argument_list|)
argument_list|)
expr_stmt|;
comment|// remove, verify
name|mimeData
operator|.
name|removeFormat
argument_list|(
literal|"text/plain"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasFormat
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasFormat
argument_list|(
literal|"text/html"
argument_list|)
argument_list|)
expr_stmt|;
comment|// remove, verify
name|mimeData
operator|.
name|removeFormat
argument_list|(
literal|"text/html"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasFormat
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasFormat
argument_list|(
literal|"text/html"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setHtml
name|void
name|tst_QMimeData
operator|::
name|setHtml
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
comment|// initial state
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasHtml
argument_list|()
argument_list|)
expr_stmt|;
comment|// add html, verify
name|mimeData
operator|.
name|setHtml
argument_list|(
literal|"ninjas"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasHtml
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|html
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"ninjas"
argument_list|)
argument_list|)
expr_stmt|;
comment|// reset html
name|mimeData
operator|.
name|setHtml
argument_list|(
literal|"pirates"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasHtml
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|html
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"pirates"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setText
name|void
name|tst_QMimeData
operator|::
name|setText
parameter_list|()
specifier|const
block|{
name|QMimeData
name|mimeData
decl_stmt|;
comment|// verify initial state
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|text
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|""
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasText
argument_list|()
argument_list|)
expr_stmt|;
comment|// set, verify
name|mimeData
operator|.
name|setText
argument_list|(
literal|"pirates"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasText
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|text
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"pirates"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|text
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|mimeData
operator|.
name|data
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|)
expr_stmt|;
comment|// reset, verify
name|mimeData
operator|.
name|setText
argument_list|(
literal|"ninjas"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|mimeData
operator|.
name|hasText
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|text
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|"ninjas"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|text
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|mimeData
operator|.
name|data
argument_list|(
literal|"text/plain"
argument_list|)
argument_list|)
expr_stmt|;
comment|// clear, verify
name|mimeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|text
argument_list|()
argument_list|,
name|QLatin1String
argument_list|(
literal|""
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|mimeData
operator|.
name|hasText
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Publish retrieveData for verifying content validity
end_comment
begin_class
DECL|class|TstMetaData
class|class
name|TstMetaData
super|:
specifier|public
name|QMimeData
block|{
public|public:
using|using
name|QMimeData
operator|::
name|retrieveData
using|;
block|}
class|;
end_class
begin_function
DECL|function|setUrls
name|void
name|tst_QMimeData
operator|::
name|setUrls
parameter_list|()
specifier|const
block|{
name|TstMetaData
name|mimeData
decl_stmt|;
name|QList
argument_list|<
name|QUrl
argument_list|>
name|shortUrlList
decl_stmt|;
name|QList
argument_list|<
name|QUrl
argument_list|>
name|longUrlList
decl_stmt|;
comment|// set up
name|shortUrlList
operator|+=
name|QUrl
argument_list|(
literal|"http://qt-project.org"
argument_list|)
expr_stmt|;
name|longUrlList
operator|=
name|shortUrlList
expr_stmt|;
name|longUrlList
operator|+=
name|QUrl
argument_list|(
literal|"http://www.google.com"
argument_list|)
expr_stmt|;
comment|// verify initial state
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|hasUrls
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
comment|// set a few, verify
name|mimeData
operator|.
name|setUrls
argument_list|(
name|shortUrlList
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|urls
argument_list|()
argument_list|,
name|shortUrlList
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"http://qt-project.org"
argument_list|)
argument_list|)
expr_stmt|;
comment|// change them, verify
name|mimeData
operator|.
name|setUrls
argument_list|(
name|longUrlList
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|urls
argument_list|()
argument_list|,
name|longUrlList
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|text
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"http://qt-project.org\nhttp://www.google.com\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|// test and verify that setData doesn't corrupt url content
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|format
decl|,
name|mimeData
operator|.
name|formats
argument_list|()
control|)
block|{
name|QVariant
name|before
init|=
name|mimeData
operator|.
name|retrieveData
argument_list|(
name|format
argument_list|,
name|QVariant
operator|::
name|ByteArray
argument_list|)
decl_stmt|;
name|mimeData
operator|.
name|setData
argument_list|(
name|format
argument_list|,
name|mimeData
operator|.
name|data
argument_list|(
name|format
argument_list|)
argument_list|)
expr_stmt|;
name|QVariant
name|after
init|=
name|mimeData
operator|.
name|retrieveData
argument_list|(
name|format
argument_list|,
name|QVariant
operator|::
name|ByteArray
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|after
argument_list|,
name|before
argument_list|)
expr_stmt|;
block|}
comment|// clear, verify
name|mimeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|hasUrls
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mimeData
operator|.
name|hasText
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QMimeData
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qmimedata.moc"
end_include
end_unit
