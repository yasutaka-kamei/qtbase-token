begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTCONTROL_P_P_H
end_ifndef
begin_define
DECL|macro|QTEXTCONTROL_P_P_H
define|#
directive|define
name|QTEXTCONTROL_P_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtGui/qtextdocumentfragment.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextcursor.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextformat.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qabstracttextdocumentlayout.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractScrollArea
name|class
name|QAbstractScrollArea
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QInputContext
name|class
name|QInputContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTextControlPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTextControl
argument_list|)
name|public
operator|:
name|QTextControlPrivate
argument_list|()
block|;
name|bool
name|cursorMoveKeyEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|updateCurrentCharFormat
argument_list|()
block|;
name|void
name|indent
argument_list|()
block|;
name|void
name|outdent
argument_list|()
block|;
name|void
name|gotoNextTableCell
argument_list|()
block|;
name|void
name|gotoPreviousTableCell
argument_list|()
block|;
name|void
name|createAutoBulletList
argument_list|()
block|;
name|void
name|init
argument_list|(
argument|Qt::TextFormat format = Qt::RichText
argument_list|,
argument|const QString&text = QString()
argument_list|,
argument|QTextDocument *document =
literal|0
argument_list|)
block|;
name|void
name|setContent
argument_list|(
argument|Qt::TextFormat format = Qt::RichText
argument_list|,
argument|const QString&text = QString()
argument_list|,
argument|QTextDocument *document =
literal|0
argument_list|)
block|;
name|void
name|startDrag
argument_list|()
block|;
name|void
name|paste
argument_list|(
specifier|const
name|QMimeData
operator|*
name|source
argument_list|)
block|;
name|void
name|setCursorPosition
argument_list|(
specifier|const
name|QPointF
operator|&
name|pos
argument_list|)
block|;
name|void
name|setCursorPosition
argument_list|(
argument|int pos
argument_list|,
argument|QTextCursor::MoveMode mode = QTextCursor::MoveAnchor
argument_list|)
block|;
name|void
name|repaintCursor
argument_list|()
block|;
specifier|inline
name|void
name|repaintSelection
argument_list|()
block|{
name|repaintOldAndNewSelection
argument_list|(
name|QTextCursor
argument_list|()
argument_list|)
block|; }
name|void
name|repaintOldAndNewSelection
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|oldSelection
argument_list|)
block|;
name|void
name|selectionChanged
argument_list|(
argument|bool forceEmitSelectionChanged = false
argument_list|)
block|;
name|void
name|_q_updateCurrentCharFormatAndSelection
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|void
name|setClipboardSelection
argument_list|()
block|;
endif|#
directive|endif
name|void
name|_q_emitCursorPosChanged
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|someCursor
argument_list|)
block|;
name|void
name|setBlinkingCursorEnabled
argument_list|(
argument|bool enable
argument_list|)
block|;
name|void
name|extendWordwiseSelection
argument_list|(
argument|int suggestedNewPosition
argument_list|,
argument|qreal mouseXPosition
argument_list|)
block|;
name|void
name|extendBlockwiseSelection
argument_list|(
argument|int suggestedNewPosition
argument_list|)
block|;
name|void
name|_q_deleteSelected
argument_list|()
block|;
name|void
name|_q_setCursorAfterUndoRedo
argument_list|(
argument|int undoPosition
argument_list|,
argument|int charsAdded
argument_list|,
argument|int charsRemoved
argument_list|)
block|;
name|QRectF
name|cursorRectPlusUnicodeDirectionMarkers
argument_list|(
argument|const QTextCursor&cursor
argument_list|)
specifier|const
block|;
name|QRectF
name|rectForPosition
argument_list|(
argument|int position
argument_list|)
specifier|const
block|;
name|QRectF
name|selectionRect
argument_list|(
argument|const QTextCursor&cursor
argument_list|)
specifier|const
block|;
specifier|inline
name|QRectF
name|selectionRect
argument_list|()
specifier|const
block|{
return|return
name|selectionRect
argument_list|(
name|this
operator|->
name|cursor
argument_list|)
return|;
block|}
name|QString
name|anchorForCursor
argument_list|(
argument|const QTextCursor&anchor
argument_list|)
specifier|const
block|;
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
argument|QEvent *e
argument_list|,
argument|Qt::MouseButton button
argument_list|,
argument|const QPointF&pos
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|Qt::MouseButtons buttons
argument_list|,
argument|const QPoint&globalPos
argument_list|)
block|;
name|void
name|mouseMoveEvent
argument_list|(
argument|QEvent *e
argument_list|,
argument|Qt::MouseButton button
argument_list|,
argument|const QPointF&pos
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|Qt::MouseButtons buttons
argument_list|,
argument|const QPoint&globalPos
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
argument|QEvent *e
argument_list|,
argument|Qt::MouseButton button
argument_list|,
argument|const QPointF&pos
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|Qt::MouseButtons buttons
argument_list|,
argument|const QPoint&globalPos
argument_list|)
block|;
name|void
name|mouseDoubleClickEvent
argument_list|(
argument|QEvent *e
argument_list|,
argument|Qt::MouseButton button
argument_list|,
argument|const QPointF&pos
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|Qt::MouseButtons buttons
argument_list|,
argument|const QPoint&globalPos
argument_list|)
block|;
name|bool
name|sendMouseEventToInputContext
argument_list|(
argument|QEvent *e
argument_list|,
argument|QEvent::Type eventType
argument_list|,
argument|Qt::MouseButton button
argument_list|,
argument|const QPointF&pos
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|Qt::MouseButtons buttons
argument_list|,
argument|const QPoint&globalPos
argument_list|)
block|;
name|void
name|contextMenuEvent
argument_list|(
specifier|const
name|QPoint
operator|&
name|screenPos
argument_list|,
specifier|const
name|QPointF
operator|&
name|docPos
argument_list|,
name|QWidget
operator|*
name|contextWidget
argument_list|)
block|;
name|void
name|focusEvent
argument_list|(
name|QFocusEvent
operator|*
name|e
argument_list|)
block|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|void
name|editFocusEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
endif|#
directive|endif
name|bool
name|dragEnterEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|,
specifier|const
name|QMimeData
operator|*
name|mimeData
argument_list|)
block|;
name|void
name|dragLeaveEvent
argument_list|()
block|;
name|bool
name|dragMoveEvent
argument_list|(
name|QEvent
operator|*
name|e
argument_list|,
specifier|const
name|QMimeData
operator|*
name|mimeData
argument_list|,
specifier|const
name|QPointF
operator|&
name|pos
argument_list|)
block|;
name|bool
name|dropEvent
argument_list|(
argument|const QMimeData *mimeData
argument_list|,
argument|const QPointF&pos
argument_list|,
argument|Qt::DropAction dropAction
argument_list|,
argument|QObject *source
argument_list|)
block|;
name|void
name|inputMethodEvent
argument_list|(
name|QInputMethodEvent
operator|*
argument_list|)
block|;
name|void
name|activateLinkUnderCursor
argument_list|(
argument|QString href = QString()
argument_list|)
block|;
name|void
name|append
argument_list|(
argument|const QString&text
argument_list|,
argument|Qt::TextFormat format = Qt::AutoText
argument_list|)
block|;
name|QInputContext
operator|*
name|inputContext
argument_list|()
block|;
name|QTextDocument
operator|*
name|doc
block|;
name|bool
name|cursorOn
block|;
name|QTextCursor
name|cursor
block|;
name|bool
name|cursorIsFocusIndicator
block|;
name|QTextCharFormat
name|lastCharFormat
block|;
name|QTextCursor
name|dndFeedbackCursor
block|;
name|Qt
operator|::
name|TextInteractionFlags
name|interactionFlags
block|;
name|QBasicTimer
name|cursorBlinkTimer
block|;
name|QBasicTimer
name|trippleClickTimer
block|;
name|QPointF
name|trippleClickPoint
block|;
name|bool
name|dragEnabled
block|;
name|bool
name|mousePressed
block|;
name|bool
name|mightStartDrag
block|;
name|QPoint
name|dragStartPos
block|;
name|QPointer
operator|<
name|QObject
operator|>
name|contextObject
block|;
name|bool
name|lastSelectionState
block|;
name|bool
name|ignoreAutomaticScrollbarAdjustement
block|;
name|QTextCursor
name|selectedWordOnDoubleClick
block|;
name|QTextCursor
name|selectedBlockOnTrippleClick
block|;
name|bool
name|overwriteMode
block|;
name|bool
name|acceptRichText
block|;
name|int
name|preeditCursor
block|;
name|bool
name|hideCursor
block|;
comment|// used to hide the cursor in the preedit area
name|QVector
operator|<
name|QAbstractTextDocumentLayout
operator|::
name|Selection
operator|>
name|extraSelections
block|;
name|QPalette
name|palette
block|;
name|bool
name|hasFocus
block|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|bool
name|hasEditFocus
block|;
endif|#
directive|endif
name|bool
name|isEnabled
block|;
name|QString
name|highlightedAnchor
block|;
comment|// Anchor below cursor
name|QString
name|anchorOnMousePress
block|;
name|bool
name|hadSelectionOnMousePress
block|;
name|bool
name|ignoreUnusedNavigationEvents
block|;
name|bool
name|openExternalLinks
block|;
name|bool
name|wordSelectionEnabled
block|;
name|QString
name|linkToCopy
block|;
name|void
name|_q_copyLink
argument_list|()
block|;
name|void
name|_q_updateBlock
argument_list|(
specifier|const
name|QTextBlock
operator|&
argument_list|)
block|;
name|void
name|_q_documentLayoutChanged
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTextControl_P_H
end_comment
end_unit
