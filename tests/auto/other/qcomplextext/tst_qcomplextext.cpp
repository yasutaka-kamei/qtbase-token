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
file|<QtGui/QtGui>
end_include
begin_include
include|#
directive|include
file|<private/qtextengine_p.h>
end_include
begin_include
include|#
directive|include
file|"bidireorderstring.h"
end_include
begin_class
DECL|class|tst_QComplexText
class|class
name|tst_QComplexText
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|bidiReorderString_data
parameter_list|()
function_decl|;
name|void
name|bidiReorderString
parameter_list|()
function_decl|;
name|void
name|bidiCursor_qtbug2795
parameter_list|()
function_decl|;
name|void
name|bidiCursor_PDF
parameter_list|()
function_decl|;
name|void
name|bidiCursorMovement_data
parameter_list|()
function_decl|;
name|void
name|bidiCursorMovement
parameter_list|()
function_decl|;
name|void
name|bidiCursorLogicalMovement_data
parameter_list|()
function_decl|;
name|void
name|bidiCursorLogicalMovement
parameter_list|()
function_decl|;
name|void
name|bidiInvalidCursorNoMovement_data
parameter_list|()
function_decl|;
name|void
name|bidiInvalidCursorNoMovement
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|bidiReorderString_data
name|void
name|tst_QComplexText
operator|::
name|bidiReorderString_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"logical"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"VISUAL"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"basicDir"
argument_list|)
expr_stmt|;
specifier|const
name|LV
modifier|*
name|data
init|=
name|logical_visual
decl_stmt|;
while|while
condition|(
name|data
operator|->
name|name
condition|)
block|{
comment|//next we fill it with data
name|QTest
operator|::
name|newRow
argument_list|(
name|data
operator|->
name|name
argument_list|)
operator|<<
name|QString
operator|::
name|fromUtf8
argument_list|(
name|data
operator|->
name|logical
argument_list|)
operator|<<
name|QString
operator|::
name|fromUtf8
argument_list|(
name|data
operator|->
name|visual
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|data
operator|->
name|basicDir
expr_stmt|;
name|data
operator|++
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|bidiReorderString
name|void
name|tst_QComplexText
operator|::
name|bidiReorderString
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|logical
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|basicDir
argument_list|)
expr_stmt|;
comment|// replace \n with Unicode newline. The new algorithm ignores \n
name|logical
operator|.
name|replace
argument_list|(
name|QChar
argument_list|(
literal|'\n'
argument_list|)
argument_list|,
name|QChar
argument_list|(
literal|0x2028
argument_list|)
argument_list|)
expr_stmt|;
name|QTextEngine
name|e
argument_list|(
name|logical
argument_list|,
name|QFont
argument_list|()
argument_list|)
decl_stmt|;
name|e
operator|.
name|option
operator|.
name|setTextDirection
argument_list|(
operator|(
name|QChar
operator|::
name|Direction
operator|)
name|basicDir
operator|==
name|QChar
operator|::
name|DirL
condition|?
name|Qt
operator|::
name|LeftToRight
else|:
name|Qt
operator|::
name|RightToLeft
argument_list|)
expr_stmt|;
name|e
operator|.
name|itemize
argument_list|()
expr_stmt|;
name|quint8
name|levels
index|[
literal|256
index|]
decl_stmt|;
name|int
name|visualOrder
index|[
literal|256
index|]
decl_stmt|;
name|int
name|nitems
init|=
name|e
operator|.
name|layoutData
operator|->
name|items
operator|.
name|size
argument_list|()
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
condition|;
operator|++
name|i
control|)
block|{
comment|//qDebug("item %d bidiLevel=%d", i,  e.items[i].analysis.bidiLevel);
name|levels
index|[
name|i
index|]
operator|=
name|e
operator|.
name|layoutData
operator|->
name|items
index|[
name|i
index|]
operator|.
name|analysis
operator|.
name|bidiLevel
expr_stmt|;
block|}
name|e
operator|.
name|bidiReorder
argument_list|(
name|nitems
argument_list|,
name|levels
argument_list|,
name|visualOrder
argument_list|)
expr_stmt|;
name|QString
name|visual
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
condition|;
operator|++
name|i
control|)
block|{
name|QScriptItem
modifier|&
name|si
init|=
name|e
operator|.
name|layoutData
operator|->
name|items
index|[
name|visualOrder
index|[
name|i
index|]
index|]
decl_stmt|;
name|QString
name|sub
init|=
name|logical
operator|.
name|mid
argument_list|(
name|si
operator|.
name|position
argument_list|,
name|e
operator|.
name|length
argument_list|(
name|visualOrder
index|[
name|i
index|]
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|si
operator|.
name|analysis
operator|.
name|bidiLevel
operator|%
literal|2
condition|)
block|{
comment|// reverse sub
name|QChar
modifier|*
name|a
init|=
operator|(
name|QChar
operator|*
operator|)
name|sub
operator|.
name|unicode
argument_list|()
decl_stmt|;
name|QChar
modifier|*
name|b
init|=
name|a
operator|+
name|sub
operator|.
name|length
argument_list|()
operator|-
literal|1
decl_stmt|;
while|while
condition|(
name|a
operator|<
name|b
condition|)
block|{
name|QChar
name|tmp
init|=
operator|*
name|a
decl_stmt|;
operator|*
name|a
operator|=
operator|*
name|b
expr_stmt|;
operator|*
name|b
operator|=
name|tmp
expr_stmt|;
operator|++
name|a
expr_stmt|;
operator|--
name|b
expr_stmt|;
block|}
name|a
operator|=
operator|(
name|QChar
operator|*
operator|)
name|sub
operator|.
name|unicode
argument_list|()
expr_stmt|;
name|b
operator|=
name|a
operator|+
name|sub
operator|.
name|length
argument_list|()
expr_stmt|;
while|while
condition|(
name|a
operator|<
name|b
condition|)
block|{
operator|*
name|a
operator|=
name|a
operator|->
name|mirroredChar
argument_list|()
expr_stmt|;
operator|++
name|a
expr_stmt|;
block|}
block|}
name|visual
operator|+=
name|sub
expr_stmt|;
block|}
comment|// replace Unicode newline back with  \n to compare.
name|visual
operator|.
name|replace
argument_list|(
name|QChar
argument_list|(
literal|0x2028
argument_list|)
argument_list|,
name|QChar
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
expr_stmt|;
name|QTEST
argument_list|(
name|visual
argument_list|,
literal|"VISUAL"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bidiCursor_qtbug2795
name|void
name|tst_QComplexText
operator|::
name|bidiCursor_qtbug2795
parameter_list|()
block|{
name|QString
name|str
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"Ø§ÙØ¬Ø²ÙØ±Ø© ÙØª"
argument_list|)
decl_stmt|;
name|QTextLayout
name|l1
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|l1
operator|.
name|beginLayout
argument_list|()
expr_stmt|;
name|l1
operator|.
name|setCacheEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QTextLine
name|line1
init|=
name|l1
operator|.
name|createLine
argument_list|()
decl_stmt|;
name|l1
operator|.
name|endLayout
argument_list|()
expr_stmt|;
name|qreal
name|x1
init|=
name|line1
operator|.
name|cursorToX
argument_list|(
literal|0
argument_list|)
operator|-
name|line1
operator|.
name|cursorToX
argument_list|(
name|str
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|str
operator|.
name|append
argument_list|(
literal|"1"
argument_list|)
expr_stmt|;
name|QTextLayout
name|l2
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|l2
operator|.
name|setCacheEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|l2
operator|.
name|beginLayout
argument_list|()
expr_stmt|;
name|QTextLine
name|line2
init|=
name|l2
operator|.
name|createLine
argument_list|()
decl_stmt|;
name|l2
operator|.
name|endLayout
argument_list|()
expr_stmt|;
name|qreal
name|x2
init|=
name|line2
operator|.
name|cursorToX
argument_list|(
literal|0
argument_list|)
operator|-
name|line2
operator|.
name|cursorToX
argument_list|(
name|str
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
comment|// The cursor should remain at the same position after a digit is appended
name|QCOMPARE
argument_list|(
name|x1
argument_list|,
name|x2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bidiCursorMovement_data
name|void
name|tst_QComplexText
operator|::
name|bidiCursorMovement_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"logical"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"basicDir"
argument_list|)
expr_stmt|;
specifier|const
name|LV
modifier|*
name|data
init|=
name|logical_visual
decl_stmt|;
while|while
condition|(
name|data
operator|->
name|name
condition|)
block|{
comment|//next we fill it with data
name|QTest
operator|::
name|newRow
argument_list|(
name|data
operator|->
name|name
argument_list|)
operator|<<
name|QString
operator|::
name|fromUtf8
argument_list|(
name|data
operator|->
name|logical
argument_list|)
operator|<<
operator|(
name|int
operator|)
name|data
operator|->
name|basicDir
expr_stmt|;
name|data
operator|++
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|bidiCursorMovement
name|void
name|tst_QComplexText
operator|::
name|bidiCursorMovement
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|logical
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|basicDir
argument_list|)
expr_stmt|;
name|QTextLayout
name|layout
argument_list|(
name|logical
argument_list|)
decl_stmt|;
name|layout
operator|.
name|setCacheEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QTextOption
name|option
init|=
name|layout
operator|.
name|textOption
argument_list|()
decl_stmt|;
name|option
operator|.
name|setTextDirection
argument_list|(
name|basicDir
operator|==
name|QChar
operator|::
name|DirL
condition|?
name|Qt
operator|::
name|LeftToRight
else|:
name|Qt
operator|::
name|RightToLeft
argument_list|)
expr_stmt|;
name|layout
operator|.
name|setTextOption
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|layout
operator|.
name|setCursorMoveStyle
argument_list|(
name|Qt
operator|::
name|VisualMoveStyle
argument_list|)
expr_stmt|;
name|bool
name|moved
decl_stmt|;
name|int
name|oldPos
decl_stmt|,
name|newPos
init|=
literal|0
decl_stmt|;
name|qreal
name|x
decl_stmt|,
name|newX
decl_stmt|;
name|layout
operator|.
name|beginLayout
argument_list|()
expr_stmt|;
name|QTextLine
name|line
init|=
name|layout
operator|.
name|createLine
argument_list|()
decl_stmt|;
name|layout
operator|.
name|endLayout
argument_list|()
expr_stmt|;
name|newX
operator|=
name|line
operator|.
name|cursorToX
argument_list|(
literal|0
argument_list|)
expr_stmt|;
do|do
block|{
name|oldPos
operator|=
name|newPos
expr_stmt|;
name|x
operator|=
name|newX
expr_stmt|;
name|newX
operator|=
name|line
operator|.
name|cursorToX
argument_list|(
name|oldPos
argument_list|)
expr_stmt|;
if|if
condition|(
name|basicDir
operator|==
name|QChar
operator|::
name|DirL
condition|)
block|{
name|QVERIFY
argument_list|(
name|newX
operator|>=
name|x
argument_list|)
expr_stmt|;
name|newPos
operator|=
name|layout
operator|.
name|rightCursorPosition
argument_list|(
name|oldPos
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QVERIFY
argument_list|(
name|newX
operator|<=
name|x
argument_list|)
expr_stmt|;
name|newPos
operator|=
name|layout
operator|.
name|leftCursorPosition
argument_list|(
name|oldPos
argument_list|)
expr_stmt|;
block|}
name|moved
operator|=
operator|(
name|oldPos
operator|!=
name|newPos
operator|)
expr_stmt|;
block|}
do|while
condition|(
name|moved
condition|)
do|;
block|}
end_function
begin_function
DECL|function|bidiCursorLogicalMovement_data
name|void
name|tst_QComplexText
operator|::
name|bidiCursorLogicalMovement_data
parameter_list|()
block|{
name|bidiCursorMovement_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bidiCursorLogicalMovement
name|void
name|tst_QComplexText
operator|::
name|bidiCursorLogicalMovement
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|logical
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|basicDir
argument_list|)
expr_stmt|;
name|QTextLayout
name|layout
argument_list|(
name|logical
argument_list|)
decl_stmt|;
name|QTextOption
name|option
init|=
name|layout
operator|.
name|textOption
argument_list|()
decl_stmt|;
name|option
operator|.
name|setTextDirection
argument_list|(
name|basicDir
operator|==
name|QChar
operator|::
name|DirL
condition|?
name|Qt
operator|::
name|LeftToRight
else|:
name|Qt
operator|::
name|RightToLeft
argument_list|)
expr_stmt|;
name|layout
operator|.
name|setTextOption
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|bool
name|moved
decl_stmt|;
name|int
name|oldPos
decl_stmt|,
name|newPos
init|=
literal|0
decl_stmt|;
do|do
block|{
name|oldPos
operator|=
name|newPos
expr_stmt|;
name|newPos
operator|=
name|layout
operator|.
name|nextCursorPosition
argument_list|(
name|oldPos
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|newPos
operator|>=
name|oldPos
argument_list|)
expr_stmt|;
name|moved
operator|=
operator|(
name|oldPos
operator|!=
name|newPos
operator|)
expr_stmt|;
block|}
do|while
condition|(
name|moved
condition|)
do|;
do|do
block|{
name|oldPos
operator|=
name|newPos
expr_stmt|;
name|newPos
operator|=
name|layout
operator|.
name|previousCursorPosition
argument_list|(
name|oldPos
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|newPos
operator|<=
name|oldPos
argument_list|)
expr_stmt|;
name|moved
operator|=
operator|(
name|oldPos
operator|!=
name|newPos
operator|)
expr_stmt|;
block|}
do|while
condition|(
name|moved
condition|)
do|;
block|}
end_function
begin_function
DECL|function|bidiInvalidCursorNoMovement_data
name|void
name|tst_QComplexText
operator|::
name|bidiInvalidCursorNoMovement_data
parameter_list|()
block|{
name|bidiCursorMovement_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bidiInvalidCursorNoMovement
name|void
name|tst_QComplexText
operator|::
name|bidiInvalidCursorNoMovement
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|logical
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|basicDir
argument_list|)
expr_stmt|;
name|QTextLayout
name|layout
argument_list|(
name|logical
argument_list|)
decl_stmt|;
name|QTextOption
name|option
init|=
name|layout
operator|.
name|textOption
argument_list|()
decl_stmt|;
name|option
operator|.
name|setTextDirection
argument_list|(
name|basicDir
operator|==
name|QChar
operator|::
name|DirL
condition|?
name|Qt
operator|::
name|LeftToRight
else|:
name|Qt
operator|::
name|RightToLeft
argument_list|)
expr_stmt|;
name|layout
operator|.
name|setTextOption
argument_list|(
name|option
argument_list|)
expr_stmt|;
comment|// visual
name|QCOMPARE
argument_list|(
name|layout
operator|.
name|rightCursorPosition
argument_list|(
operator|-
literal|1000
argument_list|)
argument_list|,
operator|-
literal|1000
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layout
operator|.
name|rightCursorPosition
argument_list|(
literal|1000
argument_list|)
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layout
operator|.
name|leftCursorPosition
argument_list|(
operator|-
literal|1000
argument_list|)
argument_list|,
operator|-
literal|1000
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layout
operator|.
name|leftCursorPosition
argument_list|(
literal|1000
argument_list|)
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
comment|// logical
name|QCOMPARE
argument_list|(
name|layout
operator|.
name|nextCursorPosition
argument_list|(
operator|-
literal|1000
argument_list|)
argument_list|,
operator|-
literal|1000
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layout
operator|.
name|nextCursorPosition
argument_list|(
literal|1000
argument_list|)
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layout
operator|.
name|previousCursorPosition
argument_list|(
operator|-
literal|1000
argument_list|)
argument_list|,
operator|-
literal|1000
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|layout
operator|.
name|previousCursorPosition
argument_list|(
literal|1000
argument_list|)
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|bidiCursor_PDF
name|void
name|tst_QComplexText
operator|::
name|bidiCursor_PDF
parameter_list|()
block|{
name|QString
name|str
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
literal|"\342\200\252hello\342\200\254"
argument_list|)
decl_stmt|;
name|QTextLayout
name|layout
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|layout
operator|.
name|setCacheEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|layout
operator|.
name|beginLayout
argument_list|()
expr_stmt|;
name|QTextLine
name|line
init|=
name|layout
operator|.
name|createLine
argument_list|()
decl_stmt|;
name|layout
operator|.
name|endLayout
argument_list|()
expr_stmt|;
name|int
name|size
init|=
name|str
operator|.
name|size
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|line
operator|.
name|cursorToX
argument_list|(
name|size
argument_list|)
operator|==
name|line
operator|.
name|cursorToX
argument_list|(
name|size
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QComplexText
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qcomplextext.moc"
end_include
end_unit
