begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLAINTEXTEDIT_P_H
end_ifndef
begin_define
DECL|macro|QPLAINTEXTEDIT_P_H
define|#
directive|define
name|QPLAINTEXTEDIT_P_H
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
file|"private/qabstractscrollarea_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextdocumentfragment.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qscrollbar.h"
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
file|"QtWidgets/qmenu.h"
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
file|"private/qwidgettextcontrol_p.h"
end_include
begin_include
include|#
directive|include
file|"qplaintextedit.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTEDIT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlainTextEdit
name|class
name|QPlainTextEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ExtraArea
name|class
name|ExtraArea
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPlainTextEditControl
range|:
name|public
name|QWidgetTextControl
block|{
name|Q_OBJECT
name|public
operator|:
name|QPlainTextEditControl
argument_list|(
name|QPlainTextEdit
operator|*
name|parent
argument_list|)
block|;
name|QMimeData
operator|*
name|createMimeDataFromSelection
argument_list|()
specifier|const
block|;
name|bool
name|canInsertFromMimeData
argument_list|(
argument|const QMimeData *source
argument_list|)
specifier|const
block|;
name|void
name|insertFromMimeData
argument_list|(
specifier|const
name|QMimeData
operator|*
name|source
argument_list|)
block|;
name|int
name|hitTest
argument_list|(
argument|const QPointF&point
argument_list|,
argument|Qt::HitTestAccuracy = Qt::FuzzyHit
argument_list|)
specifier|const
block|;
name|QRectF
name|blockBoundingRect
argument_list|(
argument|const QTextBlock&block
argument_list|)
specifier|const
block|;
specifier|inline
name|QRectF
name|cursorRect
argument_list|(
argument|const QTextCursor&cursor
argument_list|)
specifier|const
block|{
name|QRectF
name|r
operator|=
name|QWidgetTextControl
operator|::
name|cursorRect
argument_list|(
name|cursor
argument_list|)
block|;
name|r
operator|.
name|setLeft
argument_list|(
name|qMax
argument_list|(
name|r
operator|.
name|left
argument_list|()
argument_list|,
operator|(
name|qreal
operator|)
literal|0.
argument_list|)
argument_list|)
block|;
return|return
name|r
return|;
block|}
specifier|inline
name|QRectF
name|cursorRect
argument_list|()
block|{
return|return
name|cursorRect
argument_list|(
name|textCursor
argument_list|()
argument_list|)
return|;
block|}
name|void
name|ensureCursorVisible
argument_list|()
block|{
name|textEdit
operator|->
name|ensureCursorVisible
argument_list|()
block|;
name|emit
name|microFocusChanged
argument_list|()
block|;     }
name|QPlainTextEdit
operator|*
name|textEdit
block|;
name|int
name|topBlock
block|;
name|QTextBlock
name|firstVisibleBlock
argument_list|()
specifier|const
block|;
name|QVariant
name|loadResource
argument_list|(
argument|int type
argument_list|,
argument|const QUrl&name
argument_list|)
block|{
return|return
name|textEdit
operator|->
name|loadResource
argument_list|(
name|type
argument_list|,
name|name
argument_list|)
return|;
block|}
expr|}
block|;
name|class
name|QPlainTextEditPrivate
operator|:
name|public
name|QAbstractScrollAreaPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QPlainTextEdit
argument_list|)
name|public
operator|:
name|QPlainTextEditPrivate
argument_list|()
block|;
name|void
name|init
argument_list|(
specifier|const
name|QString
operator|&
name|txt
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|void
name|_q_repaintContents
argument_list|(
specifier|const
name|QRectF
operator|&
name|contentsRect
argument_list|)
block|;
specifier|inline
name|QPoint
name|mapToContents
argument_list|(
argument|const QPoint&point
argument_list|)
specifier|const
block|{
return|return
name|QPoint
argument_list|(
name|point
operator|.
name|x
argument_list|()
operator|+
name|horizontalOffset
argument_list|()
argument_list|,
name|point
operator|.
name|y
argument_list|()
operator|+
name|verticalOffset
argument_list|()
argument_list|)
return|;
block|}
name|void
name|_q_adjustScrollbars
argument_list|()
block|;
name|void
name|_q_verticalScrollbarActionTriggered
argument_list|(
argument|int action
argument_list|)
block|;
name|void
name|ensureViewportLayouted
argument_list|()
block|;
name|void
name|relayoutDocument
argument_list|()
block|;
name|void
name|pageUpDown
argument_list|(
argument|QTextCursor::MoveOperation op
argument_list|,
argument|QTextCursor::MoveMode moveMode
argument_list|,
argument|bool moveCursor = true
argument_list|)
block|;
specifier|inline
name|int
name|horizontalOffset
argument_list|()
specifier|const
block|{
return|return
operator|(
name|q_func
argument_list|()
operator|->
name|isRightToLeft
argument_list|()
operator|?
operator|(
name|hbar
operator|->
name|maximum
argument_list|()
operator|-
name|hbar
operator|->
name|value
argument_list|()
operator|)
operator|:
name|hbar
operator|->
name|value
argument_list|()
operator|)
return|;
block|}
name|qreal
name|verticalOffset
argument_list|(
argument|int topBlock
argument_list|,
argument|int topLine
argument_list|)
specifier|const
block|;
name|qreal
name|verticalOffset
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|sendControlEvent
argument_list|(
argument|QEvent *e
argument_list|)
block|{
name|control
operator|->
name|processEvent
argument_list|(
name|e
argument_list|,
name|QPointF
argument_list|(
name|horizontalOffset
argument_list|()
argument_list|,
name|verticalOffset
argument_list|()
argument_list|)
argument_list|,
name|viewport
argument_list|)
block|; }
name|void
name|updateDefaultTextOption
argument_list|()
block|;
name|QPlainTextEditControl
operator|*
name|control
block|;
name|bool
name|tabChangesFocus
block|;
name|QBasicTimer
name|autoScrollTimer
block|;
name|QPoint
name|autoScrollDragPos
block|;
name|QPlainTextEdit
operator|::
name|LineWrapMode
name|lineWrap
block|;
name|QTextOption
operator|::
name|WrapMode
name|wordWrap
block|;
name|uint
name|showCursorOnInitialShow
operator|:
literal|1
block|;
name|uint
name|backgroundVisible
operator|:
literal|1
block|;
name|uint
name|centerOnScroll
operator|:
literal|1
block|;
name|uint
name|inDrag
operator|:
literal|1
block|;
name|uint
name|clickCausedFocus
operator|:
literal|1
block|;
name|int
name|topLine
block|;
name|qreal
name|topLineFracture
block|;
comment|// for non-int sized fonts
name|void
name|setTopLine
argument_list|(
argument|int visualTopLine
argument_list|,
argument|int dx =
literal|0
argument_list|)
block|;
name|void
name|setTopBlock
argument_list|(
argument|int newTopBlock
argument_list|,
argument|int newTopLine
argument_list|,
argument|int dx =
literal|0
argument_list|)
block|;
name|void
name|ensureVisible
argument_list|(
argument|int position
argument_list|,
argument|bool center
argument_list|,
argument|bool forceCenter = false
argument_list|)
block|;
name|void
name|ensureCursorVisible
argument_list|(
argument|bool center = false
argument_list|)
block|;
name|void
name|updateViewport
argument_list|()
block|;
name|QPointer
operator|<
name|QPlainTextDocumentLayout
operator|>
name|documentLayoutPtr
block|;
name|void
name|append
argument_list|(
argument|const QString&text
argument_list|,
argument|Qt::TextFormat format = Qt::AutoText
argument_list|)
block|;
name|qreal
name|pageUpDownLastCursorY
block|;
name|bool
name|pageUpDownLastCursorYIsValid
block|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|QBasicTimer
name|deleteAllTimer
block|;
endif|#
directive|endif
name|void
name|_q_cursorPositionChanged
argument_list|()
block|;
name|void
name|_q_modificationChanged
argument_list|(
name|bool
argument_list|)
block|;
name|int
name|originalOffsetY
block|;
name|QString
name|placeholderText
block|; }
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTEDIT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLAINTEXTEDIT_P_H
end_comment
end_unit
