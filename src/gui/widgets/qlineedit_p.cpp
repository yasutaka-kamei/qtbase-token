begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlineedit.h"
end_include
begin_include
include|#
directive|include
file|"qlineedit_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LINEEDIT
end_ifndef
begin_include
include|#
directive|include
file|"qabstractitemview.h"
end_include
begin_include
include|#
directive|include
file|"qdrag.h"
end_include
begin_include
include|#
directive|include
file|"qclipboard.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|"qaccessible.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IM
end_ifndef
begin_include
include|#
directive|include
file|"qinputcontext.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
specifier|const
name|int
name|QLineEditPrivate
operator|::
name|verticalMargin
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|int
name|QLineEditPrivate
operator|::
name|horizontalMargin
argument_list|(
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|adjustedControlRect
name|QRect
name|QLineEditPrivate
operator|::
name|adjustedControlRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
specifier|const
block|{
name|QRect
name|cr
init|=
name|adjustedContentsRect
argument_list|()
decl_stmt|;
name|int
name|cix
init|=
name|cr
operator|.
name|x
argument_list|()
operator|-
name|hscroll
operator|+
name|horizontalMargin
decl_stmt|;
return|return
name|rect
operator|.
name|translated
argument_list|(
name|QPoint
argument_list|(
name|cix
argument_list|,
name|vscroll
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|xToPos
name|int
name|QLineEditPrivate
operator|::
name|xToPos
parameter_list|(
name|int
name|x
parameter_list|,
name|QTextLine
operator|::
name|CursorPosition
name|betweenOrOn
parameter_list|)
specifier|const
block|{
name|QRect
name|cr
init|=
name|adjustedContentsRect
argument_list|()
decl_stmt|;
name|x
operator|-=
name|cr
operator|.
name|x
argument_list|()
operator|-
name|hscroll
operator|+
name|horizontalMargin
expr_stmt|;
return|return
name|control
operator|->
name|xToPos
argument_list|(
name|x
argument_list|,
name|betweenOrOn
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|cursorRect
name|QRect
name|QLineEditPrivate
operator|::
name|cursorRect
parameter_list|()
specifier|const
block|{
return|return
name|adjustedControlRect
argument_list|(
name|control
operator|->
name|cursorRect
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
end_ifndef
begin_function
DECL|function|_q_completionHighlighted
name|void
name|QLineEditPrivate
operator|::
name|_q_completionHighlighted
parameter_list|(
name|QString
name|newText
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
name|control
operator|->
name|completer
argument_list|()
operator|->
name|completionMode
argument_list|()
operator|!=
name|QCompleter
operator|::
name|InlineCompletion
condition|)
block|{
name|q
operator|->
name|setText
argument_list|(
name|newText
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|int
name|c
init|=
name|control
operator|->
name|cursor
argument_list|()
decl_stmt|;
name|QString
name|text
init|=
name|control
operator|->
name|text
argument_list|()
decl_stmt|;
name|q
operator|->
name|setText
argument_list|(
name|text
operator|.
name|left
argument_list|(
name|c
argument_list|)
operator|+
name|newText
operator|.
name|mid
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
name|control
operator|->
name|moveCursor
argument_list|(
name|control
operator|->
name|end
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|control
operator|->
name|moveCursor
argument_list|(
name|c
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COMPLETER
end_comment
begin_function
DECL|function|_q_handleWindowActivate
name|void
name|QLineEditPrivate
operator|::
name|_q_handleWindowActivate
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|q
operator|->
name|hasFocus
argument_list|()
operator|&&
name|control
operator|->
name|hasSelectedText
argument_list|()
condition|)
name|control
operator|->
name|deselect
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_textEdited
name|void
name|QLineEditPrivate
operator|::
name|_q_textEdited
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|textEdited
argument_list|(
name|text
argument_list|)
emit|;
ifndef|#
directive|ifndef
name|QT_NO_COMPLETER
if|if
condition|(
name|control
operator|->
name|completer
argument_list|()
operator|&&
name|control
operator|->
name|completer
argument_list|()
operator|->
name|completionMode
argument_list|()
operator|!=
name|QCompleter
operator|::
name|InlineCompletion
condition|)
name|control
operator|->
name|complete
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// update the popup on cut/paste/del
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|_q_cursorPositionChanged
name|void
name|QLineEditPrivate
operator|::
name|_q_cursorPositionChanged
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|to
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
name|q
operator|->
name|update
argument_list|()
expr_stmt|;
emit|emit
name|q
operator|->
name|cursorPositionChanged
argument_list|(
name|from
argument_list|,
name|to
argument_list|)
emit|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
end_ifdef
begin_function
DECL|function|_q_editFocusChange
name|void
name|QLineEditPrivate
operator|::
name|_q_editFocusChange
parameter_list|(
name|bool
name|e
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
name|q
operator|->
name|setEditFocus
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|_q_selectionChanged
name|void
name|QLineEditPrivate
operator|::
name|_q_selectionChanged
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|control
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
name|control
operator|->
name|preeditAreaText
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QStyleOptionFrameV2
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|bool
name|showCursor
init|=
name|control
operator|->
name|hasSelectedText
argument_list|()
condition|?
name|q
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_BlinkCursorWhenTextSelected
argument_list|,
operator|&
name|opt
argument_list|,
name|q
argument_list|)
else|:
name|q
operator|->
name|hasFocus
argument_list|()
decl_stmt|;
name|setCursorVisible
argument_list|(
name|showCursor
argument_list|)
expr_stmt|;
block|}
emit|emit
name|q
operator|->
name|selectionChanged
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|_q_updateNeeded
name|void
name|QLineEditPrivate
operator|::
name|_q_updateNeeded
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|q_func
argument_list|()
operator|->
name|update
argument_list|(
name|adjustedControlRect
argument_list|(
name|rect
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|QLineEditPrivate
operator|::
name|init
parameter_list|(
specifier|const
name|QString
modifier|&
name|txt
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
name|control
operator|=
operator|new
name|QLineControl
argument_list|(
name|txt
argument_list|)
expr_stmt|;
name|control
operator|->
name|setFont
argument_list|(
name|q
operator|->
name|font
argument_list|()
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|textEdited
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_textEdited
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|cursorPositionChanged
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_cursorPositionChanged
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_selectionChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|accepted
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|returnPressed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SIGNAL
argument_list|(
name|editingFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|editFocusChange
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_editFocusChange
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|cursorPositionChanged
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|updateMicroFocus
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|updateMicroFocus
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// for now, going completely overboard with updates.
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|update
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|displayTextChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|update
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|control
argument_list|,
name|SIGNAL
argument_list|(
name|updateNeeded
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_updateNeeded
argument_list|(
name|QRect
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QStyleOptionFrameV2
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|control
operator|->
name|setPasswordCharacter
argument_list|(
name|q
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_LineEdit_PasswordCharacter
argument_list|,
operator|&
name|opt
argument_list|,
name|q
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|q
operator|->
name|setCursor
argument_list|(
name|Qt
operator|::
name|IBeamCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|q
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|StrongFocus
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_InputMethodEnabled
argument_list|)
expr_stmt|;
comment|//   Specifies that this widget can use more, but is able to survive on
comment|//   less, horizontal space; and is fixed vertically.
name|q
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|LineEdit
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|->
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_KeyCompression
argument_list|)
expr_stmt|;
name|q
operator|->
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAcceptDrops
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_MacShowFocusRect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|adjustedContentsRect
name|QRect
name|QLineEditPrivate
operator|::
name|adjustedContentsRect
parameter_list|()
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QLineEdit
argument_list|)
expr_stmt|;
name|QStyleOptionFrameV2
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|QRect
name|r
init|=
name|q
operator|->
name|style
argument_list|()
operator|->
name|subElementRect
argument_list|(
name|QStyle
operator|::
name|SE_LineEditContents
argument_list|,
operator|&
name|opt
argument_list|,
name|q
argument_list|)
decl_stmt|;
name|r
operator|.
name|setX
argument_list|(
name|r
operator|.
name|x
argument_list|()
operator|+
name|leftTextMargin
argument_list|)
expr_stmt|;
name|r
operator|.
name|setY
argument_list|(
name|r
operator|.
name|y
argument_list|()
operator|+
name|topTextMargin
argument_list|)
expr_stmt|;
name|r
operator|.
name|setRight
argument_list|(
name|r
operator|.
name|right
argument_list|()
operator|-
name|rightTextMargin
argument_list|)
expr_stmt|;
name|r
operator|.
name|setBottom
argument_list|(
name|r
operator|.
name|bottom
argument_list|()
operator|-
name|bottomTextMargin
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function
begin_function
DECL|function|setCursorVisible
name|void
name|QLineEditPrivate
operator|::
name|setCursorVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|bool
operator|)
name|cursorVisible
operator|==
name|visible
condition|)
return|return;
name|cursorVisible
operator|=
name|visible
expr_stmt|;
if|if
condition|(
name|control
operator|->
name|inputMask
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|q
operator|->
name|update
argument_list|(
name|cursorRect
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|q
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updatePasswordEchoEditing
name|void
name|QLineEditPrivate
operator|::
name|updatePasswordEchoEditing
parameter_list|(
name|bool
name|editing
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
name|control
operator|->
name|updatePasswordEchoEditing
argument_list|(
name|editing
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_InputMethodEnabled
argument_list|,
name|shouldEnableInputMethod
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   This function is not intended as polymorphic usage. Just a shared code   fragment that calls QInputContext::mouseHandler for this   class. */
end_comment
begin_function
DECL|function|sendMouseEventToInputContext
name|bool
name|QLineEditPrivate
operator|::
name|sendMouseEventToInputContext
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
name|QT_NO_IM
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
if|if
condition|(
name|control
operator|->
name|composeMode
argument_list|()
condition|)
block|{
name|int
name|tmp_cursor
init|=
name|xToPos
argument_list|(
name|e
operator|->
name|pos
argument_list|()
operator|.
name|x
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|mousePos
init|=
name|tmp_cursor
operator|-
name|control
operator|->
name|cursor
argument_list|()
decl_stmt|;
if|if
condition|(
name|mousePos
argument_list|<
literal|0
operator|||
name|mousePos
argument_list|>
name|control
operator|->
name|preeditAreaText
argument_list|()
operator|.
name|length
argument_list|()
condition|)
block|{
name|mousePos
operator|=
operator|-
literal|1
expr_stmt|;
comment|// don't send move events outside the preedit area
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MouseMove
condition|)
return|return
literal|true
return|;
block|}
name|QInputContext
modifier|*
name|qic
init|=
name|q
operator|->
name|inputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|qic
condition|)
comment|// may be causing reset() in some input methods
name|qic
operator|->
name|mouseHandler
argument_list|(
name|mousePos
argument_list|,
name|e
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|control
operator|->
name|preeditAreaText
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|true
return|;
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|e
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_function
DECL|function|drag
name|void
name|QLineEditPrivate
operator|::
name|drag
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLineEdit
argument_list|)
expr_stmt|;
name|dndTimer
operator|.
name|stop
argument_list|()
expr_stmt|;
name|QMimeData
modifier|*
name|data
init|=
operator|new
name|QMimeData
decl_stmt|;
name|data
operator|->
name|setText
argument_list|(
name|control
operator|->
name|selectedText
argument_list|()
argument_list|)
expr_stmt|;
name|QDrag
modifier|*
name|drag
init|=
operator|new
name|QDrag
argument_list|(
name|q
argument_list|)
decl_stmt|;
name|drag
operator|->
name|setMimeData
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|DropAction
name|action
init|=
name|drag
operator|->
name|start
argument_list|()
decl_stmt|;
if|if
condition|(
name|action
operator|==
name|Qt
operator|::
name|MoveAction
operator|&&
operator|!
name|control
operator|->
name|isReadOnly
argument_list|()
operator|&&
name|drag
operator|->
name|target
argument_list|()
operator|!=
name|q
condition|)
name|control
operator|->
name|removeSelection
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DRAGANDDROP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
