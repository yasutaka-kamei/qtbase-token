begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsyntaxhighlighter.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYNTAXHIGHLIGHTER
end_ifndef
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<qtextdocument.h>
end_include
begin_include
include|#
directive|include
file|<private/qtextdocument_p.h>
end_include
begin_include
include|#
directive|include
file|<qtextlayout.h>
end_include
begin_include
include|#
directive|include
file|<qpointer.h>
end_include
begin_include
include|#
directive|include
file|<qtextobject.h>
end_include
begin_include
include|#
directive|include
file|<qtextcursor.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QSyntaxHighlighterPrivate
class|class
name|QSyntaxHighlighterPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QSyntaxHighlighter
parameter_list|)
specifier|public
private|:
DECL|function|QSyntaxHighlighterPrivate
specifier|inline
name|QSyntaxHighlighterPrivate
parameter_list|()
member_init_list|:
name|rehighlightPending
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|inReformatBlocks
argument_list|(
literal|false
argument_list|)
block|{}
DECL|member|doc
name|QPointer
argument_list|<
name|QTextDocument
argument_list|>
name|doc
decl_stmt|;
name|void
name|_q_reformatBlocks
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|charsRemoved
parameter_list|,
name|int
name|charsAdded
parameter_list|)
function_decl|;
name|void
name|reformatBlocks
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|charsRemoved
parameter_list|,
name|int
name|charsAdded
parameter_list|)
function_decl|;
name|void
name|reformatBlock
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|block
parameter_list|)
function_decl|;
DECL|function|rehighlight
specifier|inline
name|void
name|rehighlight
parameter_list|(
name|QTextCursor
modifier|&
name|cursor
parameter_list|,
name|QTextCursor
operator|::
name|MoveOperation
name|operation
parameter_list|)
block|{
name|inReformatBlocks
operator|=
literal|true
expr_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
name|int
name|from
init|=
name|cursor
operator|.
name|position
argument_list|()
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|operation
argument_list|)
expr_stmt|;
name|reformatBlocks
argument_list|(
name|from
argument_list|,
literal|0
argument_list|,
name|cursor
operator|.
name|position
argument_list|()
operator|-
name|from
argument_list|)
expr_stmt|;
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
name|inReformatBlocks
operator|=
literal|false
expr_stmt|;
block|}
DECL|function|_q_delayedRehighlight
specifier|inline
name|void
name|_q_delayedRehighlight
parameter_list|()
block|{
if|if
condition|(
operator|!
name|rehighlightPending
condition|)
return|return;
name|rehighlightPending
operator|=
literal|false
expr_stmt|;
name|q_func
argument_list|()
operator|->
name|rehighlight
argument_list|()
expr_stmt|;
block|}
name|void
name|applyFormatChanges
parameter_list|()
function_decl|;
DECL|member|formatChanges
name|QVector
argument_list|<
name|QTextCharFormat
argument_list|>
name|formatChanges
decl_stmt|;
DECL|member|currentBlock
name|QTextBlock
name|currentBlock
decl_stmt|;
DECL|member|rehighlightPending
name|bool
name|rehighlightPending
decl_stmt|;
DECL|member|inReformatBlocks
name|bool
name|inReformatBlocks
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|applyFormatChanges
name|void
name|QSyntaxHighlighterPrivate
operator|::
name|applyFormatChanges
parameter_list|()
block|{
name|bool
name|formatsChanged
init|=
literal|false
decl_stmt|;
name|QTextLayout
modifier|*
name|layout
init|=
name|currentBlock
operator|.
name|layout
argument_list|()
decl_stmt|;
name|QList
argument_list|<
name|QTextLayout
operator|::
name|FormatRange
argument_list|>
name|ranges
init|=
name|layout
operator|->
name|additionalFormats
argument_list|()
decl_stmt|;
specifier|const
name|int
name|preeditAreaStart
init|=
name|layout
operator|->
name|preeditAreaPosition
argument_list|()
decl_stmt|;
specifier|const
name|int
name|preeditAreaLength
init|=
name|layout
operator|->
name|preeditAreaText
argument_list|()
operator|.
name|length
argument_list|()
decl_stmt|;
if|if
condition|(
name|preeditAreaLength
operator|!=
literal|0
condition|)
block|{
name|QList
argument_list|<
name|QTextLayout
operator|::
name|FormatRange
argument_list|>
operator|::
name|Iterator
name|it
init|=
name|ranges
operator|.
name|begin
argument_list|()
decl_stmt|;
while|while
condition|(
name|it
operator|!=
name|ranges
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|it
operator|->
name|start
operator|>=
name|preeditAreaStart
operator|&&
name|it
operator|->
name|start
operator|+
name|it
operator|->
name|length
operator|<=
name|preeditAreaStart
operator|+
name|preeditAreaLength
condition|)
block|{
operator|++
name|it
expr_stmt|;
block|}
else|else
block|{
name|it
operator|=
name|ranges
operator|.
name|erase
argument_list|(
name|it
argument_list|)
expr_stmt|;
name|formatsChanged
operator|=
literal|true
expr_stmt|;
block|}
block|}
block|}
elseif|else
if|if
condition|(
operator|!
name|ranges
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|ranges
operator|.
name|clear
argument_list|()
expr_stmt|;
name|formatsChanged
operator|=
literal|true
expr_stmt|;
block|}
name|QTextCharFormat
name|emptyFormat
decl_stmt|;
name|QTextLayout
operator|::
name|FormatRange
name|r
decl_stmt|;
name|r
operator|.
name|start
operator|=
operator|-
literal|1
expr_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|formatChanges
operator|.
name|count
argument_list|()
condition|)
block|{
while|while
condition|(
name|i
operator|<
name|formatChanges
operator|.
name|count
argument_list|()
operator|&&
name|formatChanges
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|emptyFormat
condition|)
operator|++
name|i
expr_stmt|;
if|if
condition|(
name|i
operator|>=
name|formatChanges
operator|.
name|count
argument_list|()
condition|)
break|break;
name|r
operator|.
name|start
operator|=
name|i
expr_stmt|;
name|r
operator|.
name|format
operator|=
name|formatChanges
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
while|while
condition|(
name|i
operator|<
name|formatChanges
operator|.
name|count
argument_list|()
operator|&&
name|formatChanges
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|r
operator|.
name|format
condition|)
operator|++
name|i
expr_stmt|;
if|if
condition|(
name|i
operator|>=
name|formatChanges
operator|.
name|count
argument_list|()
condition|)
break|break;
name|r
operator|.
name|length
operator|=
name|i
operator|-
name|r
operator|.
name|start
expr_stmt|;
if|if
condition|(
name|preeditAreaLength
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|r
operator|.
name|start
operator|>=
name|preeditAreaStart
condition|)
name|r
operator|.
name|start
operator|+=
name|preeditAreaLength
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|.
name|start
operator|+
name|r
operator|.
name|length
operator|>=
name|preeditAreaStart
condition|)
name|r
operator|.
name|length
operator|+=
name|preeditAreaLength
expr_stmt|;
block|}
name|ranges
operator|<<
name|r
expr_stmt|;
name|formatsChanged
operator|=
literal|true
expr_stmt|;
name|r
operator|.
name|start
operator|=
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|r
operator|.
name|start
operator|!=
operator|-
literal|1
condition|)
block|{
name|r
operator|.
name|length
operator|=
name|formatChanges
operator|.
name|count
argument_list|()
operator|-
name|r
operator|.
name|start
expr_stmt|;
if|if
condition|(
name|preeditAreaLength
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|r
operator|.
name|start
operator|>=
name|preeditAreaStart
condition|)
name|r
operator|.
name|start
operator|+=
name|preeditAreaLength
expr_stmt|;
elseif|else
if|if
condition|(
name|r
operator|.
name|start
operator|+
name|r
operator|.
name|length
operator|>=
name|preeditAreaStart
condition|)
name|r
operator|.
name|length
operator|+=
name|preeditAreaLength
expr_stmt|;
block|}
name|ranges
operator|<<
name|r
expr_stmt|;
name|formatsChanged
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|formatsChanged
condition|)
block|{
name|layout
operator|->
name|setAdditionalFormats
argument_list|(
name|ranges
argument_list|)
expr_stmt|;
name|doc
operator|->
name|markContentsDirty
argument_list|(
name|currentBlock
operator|.
name|position
argument_list|()
argument_list|,
name|currentBlock
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|_q_reformatBlocks
name|void
name|QSyntaxHighlighterPrivate
operator|::
name|_q_reformatBlocks
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|charsRemoved
parameter_list|,
name|int
name|charsAdded
parameter_list|)
block|{
if|if
condition|(
operator|!
name|inReformatBlocks
condition|)
name|reformatBlocks
argument_list|(
name|from
argument_list|,
name|charsRemoved
argument_list|,
name|charsAdded
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reformatBlocks
name|void
name|QSyntaxHighlighterPrivate
operator|::
name|reformatBlocks
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|charsRemoved
parameter_list|,
name|int
name|charsAdded
parameter_list|)
block|{
name|rehighlightPending
operator|=
literal|false
expr_stmt|;
name|QTextBlock
name|block
init|=
name|doc
operator|->
name|findBlock
argument_list|(
name|from
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|block
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|int
name|endPosition
decl_stmt|;
name|QTextBlock
name|lastBlock
init|=
name|doc
operator|->
name|findBlock
argument_list|(
name|from
operator|+
name|charsAdded
operator|+
operator|(
name|charsRemoved
operator|>
literal|0
condition|?
literal|1
else|:
literal|0
operator|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|lastBlock
operator|.
name|isValid
argument_list|()
condition|)
name|endPosition
operator|=
name|lastBlock
operator|.
name|position
argument_list|()
operator|+
name|lastBlock
operator|.
name|length
argument_list|()
expr_stmt|;
else|else
name|endPosition
operator|=
name|doc
operator|->
name|docHandle
argument_list|()
operator|->
name|length
argument_list|()
expr_stmt|;
name|bool
name|forceHighlightOfNextBlock
init|=
literal|false
decl_stmt|;
while|while
condition|(
name|block
operator|.
name|isValid
argument_list|()
operator|&&
operator|(
name|block
operator|.
name|position
argument_list|()
operator|<
name|endPosition
operator|||
name|forceHighlightOfNextBlock
operator|)
condition|)
block|{
specifier|const
name|int
name|stateBeforeHighlight
init|=
name|block
operator|.
name|userState
argument_list|()
decl_stmt|;
name|reformatBlock
argument_list|(
name|block
argument_list|)
expr_stmt|;
name|forceHighlightOfNextBlock
operator|=
operator|(
name|block
operator|.
name|userState
argument_list|()
operator|!=
name|stateBeforeHighlight
operator|)
expr_stmt|;
name|block
operator|=
name|block
operator|.
name|next
argument_list|()
expr_stmt|;
block|}
name|formatChanges
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reformatBlock
name|void
name|QSyntaxHighlighterPrivate
operator|::
name|reformatBlock
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|block
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
operator|!
name|currentBlock
operator|.
name|isValid
argument_list|()
argument_list|,
literal|"QSyntaxHighlighter::reformatBlock()"
argument_list|,
literal|"reFormatBlock() called recursively"
argument_list|)
expr_stmt|;
name|currentBlock
operator|=
name|block
expr_stmt|;
name|formatChanges
operator|.
name|fill
argument_list|(
name|QTextCharFormat
argument_list|()
argument_list|,
name|block
operator|.
name|length
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|q
operator|->
name|highlightBlock
argument_list|(
name|block
operator|.
name|text
argument_list|()
argument_list|)
expr_stmt|;
name|applyFormatChanges
argument_list|()
expr_stmt|;
name|currentBlock
operator|=
name|QTextBlock
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QSyntaxHighlighter     \reentrant      \brief The QSyntaxHighlighter class allows you to define syntax     highlighting rules, and in addition you can use the class to query     a document's current formatting or user data.      \since 4.1      \ingroup richtext-processing      The QSyntaxHighlighter class is a base class for implementing     QTextEdit syntax highlighters.  A syntax highligher automatically     highlights parts of the text in a QTextEdit, or more generally in     a QTextDocument. Syntax highlighters are often used when the user     is entering text in a specific format (for example source code)     and help the user to read the text and identify syntax errors.      To provide your own syntax highlighting, you must subclass     QSyntaxHighlighter and reimplement highlightBlock().      When you create an instance of your QSyntaxHighlighter subclass,     pass it the QTextEdit or QTextDocument that you want the syntax     highlighting to be applied to. For example:      \snippet code/src_gui_text_qsyntaxhighlighter.cpp 0      After this your highlightBlock() function will be called     automatically whenever necessary. Use your highlightBlock()     function to apply formatting (e.g. setting the font and color) to     the text that is passed to it. QSyntaxHighlighter provides the     setFormat() function which applies a given QTextCharFormat on     the current text block. For example:      \snippet code/src_gui_text_qsyntaxhighlighter.cpp 1      Some syntaxes can have constructs that span several text     blocks. For example, a C++ syntax highlighter should be able to     cope with \c{/}\c{*...*}\c{/} multiline comments. To deal with     these cases it is necessary to know the end state of the previous     text block (e.g. "in comment").      Inside your highlightBlock() implementation you can query the end     state of the previous text block using the previousBlockState()     function. After parsing the block you can save the last state     using setCurrentBlockState().      The currentBlockState() and previousBlockState() functions return     an int value. If no state is set, the returned value is -1. You     can designate any other value to identify any given state using     the setCurrentBlockState() function. Once the state is set the     QTextBlock keeps that value until it is set set again or until the     corresponding paragraph of text is deleted.      For example, if you're writing a simple C++ syntax highlighter,     you might designate 1 to signify "in comment":      \snippet code/src_gui_text_qsyntaxhighlighter.cpp 2      In the example above, we first set the current block state to     0. Then, if the previous block ended within a comment, we higlight     from the beginning of the current block (\c {startIndex =     0}). Otherwise, we search for the given start expression. If the     specified end expression cannot be found in the text block, we     change the current block state by calling setCurrentBlockState(),     and make sure that the rest of the block is higlighted.      In addition you can query the current formatting and user data     using the format() and currentBlockUserData() functions     respectively. You can also attach user data to the current text     block using the setCurrentBlockUserData() function.     QTextBlockUserData can be used to store custom settings. In the     case of syntax highlighting, it is in particular interesting as     cache storage for information that you may figure out while     parsing the paragraph's text. For an example, see the     setCurrentBlockUserData() documentation.      \sa QTextEdit, {Syntax Highlighter Example} */
end_comment
begin_comment
comment|/*!     Constructs a QSyntaxHighlighter with the given \a parent.      If the parent is a QTextEdit, it installs the syntaxhighlighter on the     parents document. The specified QTextEdit also becomes the owner of     the QSyntaxHighlighter. */
end_comment
begin_constructor
DECL|function|QSyntaxHighlighter
name|QSyntaxHighlighter
operator|::
name|QSyntaxHighlighter
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QSyntaxHighlighterPrivate
argument_list|,
name|parent
argument_list|)
block|{
if|if
condition|(
name|parent
operator|->
name|inherits
argument_list|(
literal|"QTextEdit"
argument_list|)
condition|)
block|{
name|QTextDocument
modifier|*
name|doc
init|=
name|qobject_cast
argument_list|<
name|QTextDocument
operator|*
argument_list|>
argument_list|(
name|parent
operator|->
name|property
argument_list|(
literal|"document"
argument_list|)
operator|.
name|value
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|doc
condition|)
name|setDocument
argument_list|(
name|doc
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|/*!     Constructs a QSyntaxHighlighter and installs it on \a parent.     The specified QTextDocument also becomes the owner of the     QSyntaxHighlighter. */
end_comment
begin_constructor
DECL|function|QSyntaxHighlighter
name|QSyntaxHighlighter
operator|::
name|QSyntaxHighlighter
parameter_list|(
name|QTextDocument
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QSyntaxHighlighterPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|setDocument
argument_list|(
name|parent
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destructor. Uninstalls this syntax highlighter from the text document. */
end_comment
begin_destructor
DECL|function|~QSyntaxHighlighter
name|QSyntaxHighlighter
operator|::
name|~
name|QSyntaxHighlighter
parameter_list|()
block|{
name|setDocument
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Installs the syntax highlighter on the given QTextDocument \a doc.     A QSyntaxHighlighter can only be used with one document at a time. */
end_comment
begin_function
DECL|function|setDocument
name|void
name|QSyntaxHighlighter
operator|::
name|setDocument
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|doc
condition|)
block|{
name|disconnect
argument_list|(
name|d
operator|->
name|doc
argument_list|,
name|SIGNAL
argument_list|(
name|contentsChange
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_reformatBlocks
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|d
operator|->
name|doc
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|beginEditBlock
argument_list|()
expr_stmt|;
for|for
control|(
name|QTextBlock
name|blk
init|=
name|d
operator|->
name|doc
operator|->
name|begin
argument_list|()
init|;
name|blk
operator|.
name|isValid
argument_list|()
condition|;
name|blk
operator|=
name|blk
operator|.
name|next
argument_list|()
control|)
name|blk
operator|.
name|layout
argument_list|()
operator|->
name|clearAdditionalFormats
argument_list|()
expr_stmt|;
name|cursor
operator|.
name|endEditBlock
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|doc
operator|=
name|doc
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|doc
condition|)
block|{
name|connect
argument_list|(
name|d
operator|->
name|doc
argument_list|,
name|SIGNAL
argument_list|(
name|contentsChange
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_reformatBlocks
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|rehighlightPending
operator|=
literal|true
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_delayedRehighlight
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the QTextDocument on which this syntax highlighter is     installed. */
end_comment
begin_function
DECL|function|document
name|QTextDocument
modifier|*
name|QSyntaxHighlighter
operator|::
name|document
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|doc
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.2      Reapplies the highlighting to the whole document.      \sa rehighlightBlock() */
end_comment
begin_function
DECL|function|rehighlight
name|void
name|QSyntaxHighlighter
operator|::
name|rehighlight
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|doc
condition|)
return|return;
name|QTextCursor
name|cursor
argument_list|(
name|d
operator|->
name|doc
argument_list|)
decl_stmt|;
name|d
operator|->
name|rehighlight
argument_list|(
name|cursor
argument_list|,
name|QTextCursor
operator|::
name|End
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.6      Reapplies the highlighting to the given QTextBlock \a block.          \sa rehighlight() */
end_comment
begin_function
DECL|function|rehighlightBlock
name|void
name|QSyntaxHighlighter
operator|::
name|rehighlightBlock
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|block
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|doc
operator|||
operator|!
name|block
operator|.
name|isValid
argument_list|()
operator|||
name|block
operator|.
name|document
argument_list|()
operator|!=
name|d
operator|->
name|doc
condition|)
return|return;
specifier|const
name|bool
name|rehighlightPending
init|=
name|d
operator|->
name|rehighlightPending
decl_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|block
argument_list|)
decl_stmt|;
name|d
operator|->
name|rehighlight
argument_list|(
name|cursor
argument_list|,
name|QTextCursor
operator|::
name|EndOfBlock
argument_list|)
expr_stmt|;
if|if
condition|(
name|rehighlightPending
condition|)
name|d
operator|->
name|rehighlightPending
operator|=
name|rehighlightPending
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn void QSyntaxHighlighter::highlightBlock(const QString&text)      Highlights the given text block. This function is called when     necessary by the rich text engine, i.e. on text blocks which have     changed.      To provide your own syntax highlighting, you must subclass     QSyntaxHighlighter and reimplement highlightBlock(). In your     reimplementation you should parse the block's \a text and call     setFormat() as often as necessary to apply any font and color     changes that you require. For example:      \snippet code/src_gui_text_qsyntaxhighlighter.cpp 3      Some syntaxes can have constructs that span several text     blocks. For example, a C++ syntax highlighter should be able to     cope with \c{/}\c{*...*}\c{/} multiline comments. To deal with     these cases it is necessary to know the end state of the previous     text block (e.g. "in comment").      Inside your highlightBlock() implementation you can query the end     state of the previous text block using the previousBlockState()     function. After parsing the block you can save the last state     using setCurrentBlockState().      The currentBlockState() and previousBlockState() functions return     an int value. If no state is set, the returned value is -1. You     can designate any other value to identify any given state using     the setCurrentBlockState() function. Once the state is set the     QTextBlock keeps that value until it is set set again or until the     corresponding paragraph of text gets deleted.      For example, if you're writing a simple C++ syntax highlighter,     you might designate 1 to signify "in comment". For a text block     that ended in the middle of a comment you'd set 1 using     setCurrentBlockState, and for other paragraphs you'd set 0.     In your parsing code if the return value of previousBlockState()     is 1, you would highlight the text as a C++ comment until you     reached the closing \c{*}\c{/}.      \sa previousBlockState(), setFormat(), setCurrentBlockState() */
end_comment
begin_comment
comment|/*!     This function is applied to the syntax highlighter's current text     block (i.e. the text that is passed to the highlightBlock()     function).      The specified \a format is applied to the text from the \a start     position for a length of \a count characters (if \a count is 0,     nothing is done). The formatting properties set in \a format are     merged at display time with the formatting information stored     directly in the document, for example as previously set with     QTextCursor's functions. Note that the document itself remains     unmodified by the format set through this function.      \sa format(), highlightBlock() */
end_comment
begin_function
DECL|function|setFormat
name|void
name|QSyntaxHighlighter
operator|::
name|setFormat
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QTextCharFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
if|if
condition|(
name|start
operator|<
literal|0
operator|||
name|start
operator|>=
name|d
operator|->
name|formatChanges
operator|.
name|count
argument_list|()
condition|)
return|return;
specifier|const
name|int
name|end
init|=
name|qMin
argument_list|(
name|start
operator|+
name|count
argument_list|,
name|d
operator|->
name|formatChanges
operator|.
name|count
argument_list|()
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|start
init|;
name|i
operator|<
name|end
condition|;
operator|++
name|i
control|)
name|d
operator|->
name|formatChanges
index|[
name|i
index|]
operator|=
name|format
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \overload      The specified \a color is applied to the current text block from     the \a start position for a length of \a count characters.      The other attributes of the current text block, e.g. the font and     background color, are reset to default values.      \sa format(), highlightBlock() */
end_comment
begin_function
DECL|function|setFormat
name|void
name|QSyntaxHighlighter
operator|::
name|setFormat
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|QTextCharFormat
name|format
decl_stmt|;
name|format
operator|.
name|setForeground
argument_list|(
name|color
argument_list|)
expr_stmt|;
name|setFormat
argument_list|(
name|start
argument_list|,
name|count
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \overload      The specified \a font is applied to the current text block from     the \a start position for a length of \a count characters.      The other attributes of the current text block, e.g. the font and     background color, are reset to default values.      \sa format(), highlightBlock() */
end_comment
begin_function
DECL|function|setFormat
name|void
name|QSyntaxHighlighter
operator|::
name|setFormat
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
name|QTextCharFormat
name|format
decl_stmt|;
name|format
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|setFormat
argument_list|(
name|start
argument_list|,
name|count
argument_list|,
name|format
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn QTextCharFormat QSyntaxHighlighter::format(int position) const      Returns the format at \a position inside the syntax highlighter's     current text block. */
end_comment
begin_function
DECL|function|format
name|QTextCharFormat
name|QSyntaxHighlighter
operator|::
name|format
parameter_list|(
name|int
name|pos
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|<
literal|0
operator|||
name|pos
operator|>=
name|d
operator|->
name|formatChanges
operator|.
name|count
argument_list|()
condition|)
return|return
name|QTextCharFormat
argument_list|()
return|;
return|return
name|d
operator|->
name|formatChanges
operator|.
name|at
argument_list|(
name|pos
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the end state of the text block previous to the     syntax highlighter's current block. If no value was     previously set, the returned value is -1.      \sa highlightBlock(), setCurrentBlockState() */
end_comment
begin_function
DECL|function|previousBlockState
name|int
name|QSyntaxHighlighter
operator|::
name|previousBlockState
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|currentBlock
operator|.
name|isValid
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
specifier|const
name|QTextBlock
name|previous
init|=
name|d
operator|->
name|currentBlock
operator|.
name|previous
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|previous
operator|.
name|isValid
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|previous
operator|.
name|userState
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the state of the current text block. If no value is set,     the returned value is -1. */
end_comment
begin_function
DECL|function|currentBlockState
name|int
name|QSyntaxHighlighter
operator|::
name|currentBlockState
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|currentBlock
operator|.
name|isValid
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|d
operator|->
name|currentBlock
operator|.
name|userState
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the state of the current text block to \a newState.      \sa highlightBlock() */
end_comment
begin_function
DECL|function|setCurrentBlockState
name|void
name|QSyntaxHighlighter
operator|::
name|setCurrentBlockState
parameter_list|(
name|int
name|newState
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|currentBlock
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|d
operator|->
name|currentBlock
operator|.
name|setUserState
argument_list|(
name|newState
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Attaches the given \a data to the current text block.  The     ownership is passed to the underlying text document, i.e. the     provided QTextBlockUserData object will be deleted if the     corresponding text block gets deleted.      QTextBlockUserData can be used to store custom settings. In the     case of syntax highlighting, it is in particular interesting as     cache storage for information that you may figure out while     parsing the paragraph's text.      For example while parsing the text, you can keep track of     parenthesis characters that you encounter ('{[(' and the like),     and store their relative position and the actual QChar in a simple     class derived from QTextBlockUserData:      \snippet code/src_gui_text_qsyntaxhighlighter.cpp 4      During cursor navigation in the associated editor, you can ask the     current QTextBlock (retrieved using the QTextCursor::block()     function) if it has a user data object set and cast it to your \c     BlockData object. Then you can check if the current cursor     position matches with a previously recorded parenthesis position,     and, depending on the type of parenthesis (opening or closing),     find the next opening or closing parenthesis on the same level.      In this way you can do a visual parenthesis matching and highlight     from the current cursor position to the matching parenthesis. That     makes it easier to spot a missing parenthesis in your code and to     find where a corresponding opening/closing parenthesis is when     editing parenthesis intensive code.      \sa QTextBlock::setUserData() */
end_comment
begin_function
DECL|function|setCurrentBlockUserData
name|void
name|QSyntaxHighlighter
operator|::
name|setCurrentBlockUserData
parameter_list|(
name|QTextBlockUserData
modifier|*
name|data
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|currentBlock
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|d
operator|->
name|currentBlock
operator|.
name|setUserData
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the QTextBlockUserData object previously attached to the     current text block.      \sa QTextBlock::userData(), setCurrentBlockUserData() */
end_comment
begin_function
DECL|function|currentBlockUserData
name|QTextBlockUserData
modifier|*
name|QSyntaxHighlighter
operator|::
name|currentBlockUserData
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|currentBlock
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|d
operator|->
name|currentBlock
operator|.
name|userData
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4      Returns the current text block. */
end_comment
begin_function
DECL|function|currentBlock
name|QTextBlock
name|QSyntaxHighlighter
operator|::
name|currentBlock
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSyntaxHighlighter
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|currentBlock
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qsyntaxhighlighter.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYNTAXHIGHLIGHTER
end_comment
end_unit
