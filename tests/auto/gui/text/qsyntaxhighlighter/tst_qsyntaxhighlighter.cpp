begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QTextDocument>
end_include
begin_include
include|#
directive|include
file|<QTextLayout>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QAbstractTextDocumentLayout>
end_include
begin_include
include|#
directive|include
file|<QSyntaxHighlighter>
end_include
begin_class
DECL|class|QTestDocumentLayout
class|class
name|QTestDocumentLayout
super|:
specifier|public
name|QAbstractTextDocumentLayout
block|{
name|Q_OBJECT
public|public:
DECL|function|QTestDocumentLayout
specifier|inline
name|QTestDocumentLayout
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|)
member_init_list|:
name|QAbstractTextDocumentLayout
argument_list|(
name|doc
argument_list|)
member_init_list|,
name|documentChangedCalled
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|draw
specifier|virtual
name|void
name|draw
parameter_list|(
name|QPainter
modifier|*
parameter_list|,
specifier|const
name|QAbstractTextDocumentLayout
operator|::
name|PaintContext
modifier|&
parameter_list|)
block|{}
DECL|function|hitTest
specifier|virtual
name|int
name|hitTest
parameter_list|(
specifier|const
name|QPointF
modifier|&
parameter_list|,
name|Qt
operator|::
name|HitTestAccuracy
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
DECL|function|documentChanged
specifier|virtual
name|void
name|documentChanged
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
block|{
name|documentChangedCalled
operator|=
literal|true
expr_stmt|;
block|}
DECL|function|pageCount
specifier|virtual
name|int
name|pageCount
parameter_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
DECL|function|documentSize
specifier|virtual
name|QSizeF
name|documentSize
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|()
return|;
block|}
DECL|function|frameBoundingRect
specifier|virtual
name|QRectF
name|frameBoundingRect
parameter_list|(
name|QTextFrame
modifier|*
parameter_list|)
specifier|const
block|{
return|return
name|QRectF
argument_list|()
return|;
block|}
DECL|function|blockBoundingRect
specifier|virtual
name|QRectF
name|blockBoundingRect
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
parameter_list|)
specifier|const
block|{
return|return
name|QRectF
argument_list|()
return|;
block|}
DECL|member|documentChangedCalled
name|bool
name|documentChangedCalled
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|tst_QSyntaxHighlighter
class|class
name|tst_QSyntaxHighlighter
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_QSyntaxHighlighter
specifier|inline
name|tst_QSyntaxHighlighter
parameter_list|()
block|{}
public|public
name|slots
public|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|basic
parameter_list|()
function_decl|;
name|void
name|basicTwo
parameter_list|()
function_decl|;
name|void
name|removeFormatsOnDelete
parameter_list|()
function_decl|;
name|void
name|emptyBlocks
parameter_list|()
function_decl|;
name|void
name|setCharFormat
parameter_list|()
function_decl|;
name|void
name|highlightOnInit
parameter_list|()
function_decl|;
name|void
name|stopHighlightingWhenStateDoesNotChange
parameter_list|()
function_decl|;
name|void
name|unindent
parameter_list|()
function_decl|;
name|void
name|highlightToEndOfDocument
parameter_list|()
function_decl|;
name|void
name|highlightToEndOfDocument2
parameter_list|()
function_decl|;
name|void
name|preservePreeditArea
parameter_list|()
function_decl|;
name|void
name|task108530
parameter_list|()
function_decl|;
name|void
name|avoidUnnecessaryRehighlight
parameter_list|()
function_decl|;
name|void
name|noContentsChangedDuringHighlight
parameter_list|()
function_decl|;
name|void
name|rehighlight
parameter_list|()
function_decl|;
name|void
name|rehighlightBlock
parameter_list|()
function_decl|;
private|private:
DECL|member|doc
name|QTextDocument
modifier|*
name|doc
decl_stmt|;
DECL|member|lout
name|QTestDocumentLayout
modifier|*
name|lout
decl_stmt|;
DECL|member|cursor
name|QTextCursor
name|cursor
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|init
name|void
name|tst_QSyntaxHighlighter
operator|::
name|init
parameter_list|()
block|{
name|doc
operator|=
operator|new
name|QTextDocument
expr_stmt|;
name|lout
operator|=
operator|new
name|QTestDocumentLayout
argument_list|(
name|doc
argument_list|)
expr_stmt|;
name|doc
operator|->
name|setDocumentLayout
argument_list|(
name|lout
argument_list|)
expr_stmt|;
name|cursor
operator|=
name|QTextCursor
argument_list|(
name|doc
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QSyntaxHighlighter
operator|::
name|cleanup
parameter_list|()
block|{
operator|delete
name|doc
expr_stmt|;
name|doc
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_class
DECL|class|TestHighlighter
class|class
name|TestHighlighter
super|:
specifier|public
name|QSyntaxHighlighter
block|{
public|public:
DECL|function|TestHighlighter
specifier|inline
name|TestHighlighter
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QTextLayout
operator|::
name|FormatRange
argument_list|>
modifier|&
name|fmts
parameter_list|,
name|QTextDocument
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QSyntaxHighlighter
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|formats
argument_list|(
name|fmts
argument_list|)
member_init_list|,
name|highlighted
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|callCount
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|TestHighlighter
specifier|inline
name|TestHighlighter
parameter_list|(
name|QTextDocument
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QSyntaxHighlighter
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|highlighted
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|callCount
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|highlightBlock
specifier|virtual
name|void
name|highlightBlock
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
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
name|formats
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QTextLayout
operator|::
name|FormatRange
modifier|&
name|range
init|=
name|formats
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|setFormat
argument_list|(
name|range
operator|.
name|start
argument_list|,
name|range
operator|.
name|length
argument_list|,
name|range
operator|.
name|format
argument_list|)
expr_stmt|;
block|}
name|highlighted
operator|=
literal|true
expr_stmt|;
name|highlightedText
operator|+=
name|text
expr_stmt|;
operator|++
name|callCount
expr_stmt|;
block|}
DECL|member|formats
name|QList
argument_list|<
name|QTextLayout
operator|::
name|FormatRange
argument_list|>
name|formats
decl_stmt|;
DECL|member|highlighted
name|bool
name|highlighted
decl_stmt|;
DECL|member|callCount
name|int
name|callCount
decl_stmt|;
DECL|member|highlightedText
name|QString
name|highlightedText
decl_stmt|;
block|}
class|;
end_class
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|operator ==
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|QTextLayout
operator|::
name|FormatRange
modifier|&
name|lhs
parameter_list|,
specifier|const
name|QTextLayout
operator|::
name|FormatRange
modifier|&
name|rhs
parameter_list|)
block|{
return|return
name|lhs
operator|.
name|start
operator|==
name|rhs
operator|.
name|start
operator|&&
name|lhs
operator|.
name|length
operator|==
name|rhs
operator|.
name|length
operator|&&
name|lhs
operator|.
name|format
operator|==
name|rhs
operator|.
name|format
return|;
block|}
end_function
begin_function
name|QT_END_NAMESPACE
DECL|function|basic
name|void
name|tst_QSyntaxHighlighter
operator|::
name|basic
parameter_list|()
block|{
name|QList
argument_list|<
name|QTextLayout
operator|::
name|FormatRange
argument_list|>
name|formats
decl_stmt|;
name|QTextLayout
operator|::
name|FormatRange
name|range
decl_stmt|;
name|range
operator|.
name|start
operator|=
literal|0
expr_stmt|;
name|range
operator|.
name|length
operator|=
literal|2
expr_stmt|;
name|range
operator|.
name|format
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|formats
operator|.
name|append
argument_list|(
name|range
argument_list|)
expr_stmt|;
name|range
operator|.
name|start
operator|=
literal|4
expr_stmt|;
name|range
operator|.
name|length
operator|=
literal|2
expr_stmt|;
name|range
operator|.
name|format
operator|.
name|setFontItalic
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|formats
operator|.
name|append
argument_list|(
name|range
argument_list|)
expr_stmt|;
name|range
operator|.
name|start
operator|=
literal|9
expr_stmt|;
name|range
operator|.
name|length
operator|=
literal|2
expr_stmt|;
name|range
operator|.
name|format
operator|.
name|setFontUnderline
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|formats
operator|.
name|append
argument_list|(
name|range
argument_list|)
expr_stmt|;
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|formats
argument_list|,
name|doc
argument_list|)
decl_stmt|;
name|lout
operator|->
name|documentChangedCalled
operator|=
literal|false
expr_stmt|;
name|doc
operator|->
name|setPlainText
argument_list|(
literal|"Hello World"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|hl
operator|->
name|highlighted
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lout
operator|->
name|documentChangedCalled
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|doc
operator|->
name|begin
argument_list|()
operator|.
name|layout
argument_list|()
operator|->
name|additionalFormats
argument_list|()
operator|==
name|formats
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|CommentTestHighlighter
class|class
name|CommentTestHighlighter
super|:
specifier|public
name|QSyntaxHighlighter
block|{
public|public:
DECL|function|CommentTestHighlighter
specifier|inline
name|CommentTestHighlighter
parameter_list|(
name|QTextDocument
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QSyntaxHighlighter
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|highlighted
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|reset
specifier|inline
name|void
name|reset
parameter_list|()
block|{
name|highlighted
operator|=
literal|false
expr_stmt|;
block|}
DECL|function|highlightBlock
specifier|virtual
name|void
name|highlightBlock
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QTextCharFormat
name|commentFormat
decl_stmt|;
name|commentFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|darkGreen
argument_list|)
expr_stmt|;
name|commentFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|StyleItalic
argument_list|)
expr_stmt|;
name|commentFormat
operator|.
name|setFontFixedPitch
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|int
name|textLength
init|=
name|text
operator|.
name|length
argument_list|()
decl_stmt|;
if|if
condition|(
name|text
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|';'
argument_list|)
argument_list|)
condition|)
block|{
comment|// The entire line is a comment
name|setFormat
argument_list|(
literal|0
argument_list|,
name|textLength
argument_list|,
name|commentFormat
argument_list|)
expr_stmt|;
name|highlighted
operator|=
literal|true
expr_stmt|;
block|}
block|}
DECL|member|highlighted
name|bool
name|highlighted
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|basicTwo
name|void
name|tst_QSyntaxHighlighter
operator|::
name|basicTwo
parameter_list|()
block|{
comment|// Done for task 104409
name|CommentTestHighlighter
modifier|*
name|hl
init|=
operator|new
name|CommentTestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|doc
operator|->
name|setPlainText
argument_list|(
literal|"; a test"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|hl
operator|->
name|highlighted
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lout
operator|->
name|documentChangedCalled
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeFormatsOnDelete
name|void
name|tst_QSyntaxHighlighter
operator|::
name|removeFormatsOnDelete
parameter_list|()
block|{
name|QList
argument_list|<
name|QTextLayout
operator|::
name|FormatRange
argument_list|>
name|formats
decl_stmt|;
name|QTextLayout
operator|::
name|FormatRange
name|range
decl_stmt|;
name|range
operator|.
name|start
operator|=
literal|0
expr_stmt|;
name|range
operator|.
name|length
operator|=
literal|9
expr_stmt|;
name|range
operator|.
name|format
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|formats
operator|.
name|append
argument_list|(
name|range
argument_list|)
expr_stmt|;
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|formats
argument_list|,
name|doc
argument_list|)
decl_stmt|;
name|lout
operator|->
name|documentChangedCalled
operator|=
literal|false
expr_stmt|;
name|doc
operator|->
name|setPlainText
argument_list|(
literal|"Hello World"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|hl
operator|->
name|highlighted
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lout
operator|->
name|documentChangedCalled
argument_list|)
expr_stmt|;
name|lout
operator|->
name|documentChangedCalled
operator|=
literal|false
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|doc
operator|->
name|begin
argument_list|()
operator|.
name|layout
argument_list|()
operator|->
name|additionalFormats
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|hl
expr_stmt|;
name|QVERIFY
argument_list|(
name|doc
operator|->
name|begin
argument_list|()
operator|.
name|layout
argument_list|()
operator|->
name|additionalFormats
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lout
operator|->
name|documentChangedCalled
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|emptyBlocks
name|void
name|tst_QSyntaxHighlighter
operator|::
name|emptyBlocks
parameter_list|()
block|{
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Foo"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|hl
operator|->
name|highlighted
operator|=
literal|false
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|hl
operator|->
name|highlighted
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCharFormat
name|void
name|tst_QSyntaxHighlighter
operator|::
name|setCharFormat
parameter_list|()
block|{
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"FooBar"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Blah"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|End
argument_list|,
name|QTextCursor
operator|::
name|KeepAnchor
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setFontItalic
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|hl
operator|->
name|highlighted
operator|=
literal|false
expr_stmt|;
name|hl
operator|->
name|callCount
operator|=
literal|0
expr_stmt|;
name|cursor
operator|.
name|mergeCharFormat
argument_list|(
name|fmt
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|hl
operator|->
name|highlighted
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|callCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|highlightOnInit
name|void
name|tst_QSyntaxHighlighter
operator|::
name|highlightOnInit
parameter_list|()
block|{
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Hello"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"World"
argument_list|)
expr_stmt|;
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|hl
operator|->
name|highlighted
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|StateTestHighlighter
class|class
name|StateTestHighlighter
super|:
specifier|public
name|QSyntaxHighlighter
block|{
public|public:
DECL|function|StateTestHighlighter
specifier|inline
name|StateTestHighlighter
parameter_list|(
name|QTextDocument
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QSyntaxHighlighter
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|state
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|highlighted
argument_list|(
literal|false
argument_list|)
block|{}
DECL|function|reset
specifier|inline
name|void
name|reset
parameter_list|()
block|{
name|highlighted
operator|=
literal|false
expr_stmt|;
name|state
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|highlightBlock
specifier|virtual
name|void
name|highlightBlock
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|highlighted
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|text
operator|==
name|QLatin1String
argument_list|(
literal|"changestate"
argument_list|)
condition|)
name|setCurrentBlockState
argument_list|(
name|state
operator|++
argument_list|)
expr_stmt|;
block|}
DECL|member|state
name|int
name|state
decl_stmt|;
DECL|member|highlighted
name|bool
name|highlighted
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|stopHighlightingWhenStateDoesNotChange
name|void
name|tst_QSyntaxHighlighter
operator|::
name|stopHighlightingWhenStateDoesNotChange
parameter_list|()
block|{
name|cursor
operator|.
name|insertText
argument_list|(
literal|"state"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"changestate"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"keepstate"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"changestate"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"changestate"
argument_list|)
expr_stmt|;
name|StateTestHighlighter
modifier|*
name|hl
init|=
operator|new
name|StateTestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|hl
operator|->
name|highlighted
argument_list|)
expr_stmt|;
name|hl
operator|->
name|reset
argument_list|()
expr_stmt|;
comment|// turn the text of the first block into 'changestate'
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"change"
argument_list|)
expr_stmt|;
comment|// verify that we highlighted only to the 'keepstate' block,
comment|// not beyond
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|state
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unindent
name|void
name|tst_QSyntaxHighlighter
operator|::
name|unindent
parameter_list|()
block|{
specifier|const
name|QString
name|spaces
argument_list|(
literal|"    "
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|text
argument_list|(
literal|"Foobar"
argument_list|)
decl_stmt|;
name|QString
name|plainText
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
literal|5
condition|;
operator|++
name|i
control|)
block|{
name|cursor
operator|.
name|insertText
argument_list|(
name|spaces
operator|+
name|text
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|plainText
operator|+=
name|spaces
expr_stmt|;
name|plainText
operator|+=
name|text
expr_stmt|;
name|plainText
operator|+=
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|doc
operator|->
name|toPlainText
argument_list|()
argument_list|,
name|plainText
argument_list|)
expr_stmt|;
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|hl
operator|->
name|callCount
operator|=
literal|0
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|plainText
operator|.
name|clear
argument_list|()
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
literal|5
condition|;
operator|++
name|i
control|)
block|{
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|NextCharacter
argument_list|,
name|QTextCursor
operator|::
name|KeepAnchor
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|removeSelectedText
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|NextBlock
argument_list|)
expr_stmt|;
name|plainText
operator|+=
name|text
expr_stmt|;
name|plainText
operator|+=
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|doc
operator|->
name|toPlainText
argument_list|()
argument_list|,
name|plainText
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|callCount
argument_list|,
literal|5
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|highlightToEndOfDocument
name|void
name|tst_QSyntaxHighlighter
operator|::
name|highlightToEndOfDocument
parameter_list|()
block|{
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|hl
operator|->
name|callCount
operator|=
literal|0
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Hello"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"World"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|callCount
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|highlightToEndOfDocument2
name|void
name|tst_QSyntaxHighlighter
operator|::
name|highlightToEndOfDocument2
parameter_list|()
block|{
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|hl
operator|->
name|callCount
operator|=
literal|0
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|End
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|QTextBlockFormat
name|fmt
decl_stmt|;
name|fmt
operator|.
name|setAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|setBlockFormat
argument_list|(
name|fmt
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Three\nLines\nHere"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|callCount
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|preservePreeditArea
name|void
name|tst_QSyntaxHighlighter
operator|::
name|preservePreeditArea
parameter_list|()
block|{
name|QList
argument_list|<
name|QTextLayout
operator|::
name|FormatRange
argument_list|>
name|formats
decl_stmt|;
name|QTextLayout
operator|::
name|FormatRange
name|range
decl_stmt|;
name|range
operator|.
name|start
operator|=
literal|0
expr_stmt|;
name|range
operator|.
name|length
operator|=
literal|8
expr_stmt|;
name|range
operator|.
name|format
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|formats
operator|<<
name|range
expr_stmt|;
name|range
operator|.
name|start
operator|=
literal|9
expr_stmt|;
name|range
operator|.
name|length
operator|=
literal|1
expr_stmt|;
name|range
operator|.
name|format
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|formats
operator|<<
name|range
expr_stmt|;
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|formats
argument_list|,
name|doc
argument_list|)
decl_stmt|;
name|doc
operator|->
name|setPlainText
argument_list|(
literal|"Hello World"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|QTextLayout
modifier|*
name|layout
init|=
name|cursor
operator|.
name|block
argument_list|()
operator|.
name|layout
argument_list|()
decl_stmt|;
name|layout
operator|->
name|setPreeditArea
argument_list|(
literal|5
argument_list|,
name|QString
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
expr_stmt|;
name|range
operator|.
name|start
operator|=
literal|5
expr_stmt|;
name|range
operator|.
name|length
operator|=
literal|3
expr_stmt|;
name|range
operator|.
name|format
operator|.
name|setFontUnderline
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|formats
operator|.
name|clear
argument_list|()
expr_stmt|;
name|formats
operator|<<
name|range
expr_stmt|;
name|hl
operator|->
name|callCount
operator|=
literal|0
expr_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|layout
operator|->
name|setAdditionalFormats
argument_list|(
name|formats
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|callCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|formats
operator|=
name|layout
operator|->
name|additionalFormats
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|formats
operator|.
name|count
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|range
operator|=
name|formats
operator|.
name|at
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|range
operator|.
name|start
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|range
operator|.
name|length
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|range
operator|.
name|format
operator|.
name|fontUnderline
argument_list|()
argument_list|)
expr_stmt|;
name|range
operator|=
name|formats
operator|.
name|at
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|range
operator|.
name|start
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|range
operator|.
name|length
argument_list|,
literal|8
operator|+
literal|3
argument_list|)
expr_stmt|;
name|range
operator|=
name|formats
operator|.
name|at
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|range
operator|.
name|start
argument_list|,
literal|9
operator|+
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|range
operator|.
name|length
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task108530
name|void
name|tst_QSyntaxHighlighter
operator|::
name|task108530
parameter_list|()
block|{
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"test"
argument_list|)
expr_stmt|;
name|hl
operator|->
name|callCount
operator|=
literal|0
expr_stmt|;
name|hl
operator|->
name|highlightedText
operator|.
name|clear
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|highlightedText
argument_list|,
name|QString
argument_list|(
literal|"test"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|callCount
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|avoidUnnecessaryRehighlight
name|void
name|tst_QSyntaxHighlighter
operator|::
name|avoidUnnecessaryRehighlight
parameter_list|()
block|{
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|hl
operator|->
name|highlighted
argument_list|)
expr_stmt|;
name|doc
operator|->
name|setPlainText
argument_list|(
literal|"Hello World"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|hl
operator|->
name|highlighted
argument_list|)
expr_stmt|;
name|hl
operator|->
name|highlighted
operator|=
literal|false
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|hl
operator|->
name|highlighted
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|noContentsChangedDuringHighlight
name|void
name|tst_QSyntaxHighlighter
operator|::
name|noContentsChangedDuringHighlight
parameter_list|()
block|{
name|QList
argument_list|<
name|QTextLayout
operator|::
name|FormatRange
argument_list|>
name|formats
decl_stmt|;
name|QTextLayout
operator|::
name|FormatRange
name|range
decl_stmt|;
name|range
operator|.
name|start
operator|=
literal|0
expr_stmt|;
name|range
operator|.
name|length
operator|=
literal|10
expr_stmt|;
name|range
operator|.
name|format
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|formats
operator|.
name|append
argument_list|(
name|range
argument_list|)
expr_stmt|;
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|formats
argument_list|,
name|doc
argument_list|)
decl_stmt|;
name|lout
operator|->
name|documentChangedCalled
operator|=
literal|false
expr_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|QSignalSpy
name|contentsChangedSpy
argument_list|(
name|doc
argument_list|,
name|SIGNAL
argument_list|(
name|contentsChanged
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Hello World"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|contentsChangedSpy
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|hl
operator|->
name|highlighted
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|lout
operator|->
name|documentChangedCalled
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rehighlight
name|void
name|tst_QSyntaxHighlighter
operator|::
name|rehighlight
parameter_list|()
block|{
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|hl
operator|->
name|callCount
operator|=
literal|0
expr_stmt|;
name|doc
operator|->
name|setPlainText
argument_list|(
literal|"Hello"
argument_list|)
expr_stmt|;
name|hl
operator|->
name|callCount
operator|=
literal|0
expr_stmt|;
name|hl
operator|->
name|rehighlight
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|callCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rehighlightBlock
name|void
name|tst_QSyntaxHighlighter
operator|::
name|rehighlightBlock
parameter_list|()
block|{
name|TestHighlighter
modifier|*
name|hl
init|=
operator|new
name|TestHighlighter
argument_list|(
name|doc
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Hello"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|insertBlock
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|insertText
argument_list|(
literal|"World"
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
name|hl
operator|->
name|callCount
operator|=
literal|0
expr_stmt|;
name|hl
operator|->
name|highlightedText
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QTextBlock
name|block
init|=
name|doc
operator|->
name|begin
argument_list|()
decl_stmt|;
name|hl
operator|->
name|rehighlightBlock
argument_list|(
name|block
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|highlightedText
argument_list|,
name|QString
argument_list|(
literal|"Hello"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|callCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|hl
operator|->
name|callCount
operator|=
literal|0
expr_stmt|;
name|hl
operator|->
name|highlightedText
operator|.
name|clear
argument_list|()
expr_stmt|;
name|hl
operator|->
name|rehighlightBlock
argument_list|(
name|block
operator|.
name|next
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|highlightedText
argument_list|,
name|QString
argument_list|(
literal|"World"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|hl
operator|->
name|callCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QSyntaxHighlighter
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qsyntaxhighlighter.moc"
end_include
end_unit
