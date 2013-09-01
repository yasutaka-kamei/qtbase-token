begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTTEXTDOCUMENTLAYOUT_H
end_ifndef
begin_define
DECL|macro|QABSTRACTTEXTDOCUMENTLAYOUT_H
define|#
directive|define
name|QABSTRACTTEXTDOCUMENTLAYOUT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextlayout.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextdocument.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpalette.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAbstractTextDocumentLayoutPrivate
name|class
name|QAbstractTextDocumentLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBlock
name|class
name|QTextBlock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextObjectInterface
name|class
name|QTextObjectInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFrame
name|class
name|QTextFrame
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAbstractTextDocumentLayout
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QAbstractTextDocumentLayout
argument_list|)
name|public
operator|:
name|explicit
name|QAbstractTextDocumentLayout
argument_list|(
name|QTextDocument
operator|*
name|doc
argument_list|)
block|;
operator|~
name|QAbstractTextDocumentLayout
argument_list|()
block|;      struct
name|Selection
block|{
name|QTextCursor
name|cursor
block|;
name|QTextCharFormat
name|format
block|;     }
block|;      struct
name|PaintContext
block|{
name|PaintContext
argument_list|()
operator|:
name|cursorPosition
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|int
name|cursorPosition
block|;
name|QPalette
name|palette
block|;
name|QRectF
name|clip
block|;
name|QVector
operator|<
name|Selection
operator|>
name|selections
block|;     }
block|;
name|virtual
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|PaintContext
operator|&
name|context
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|hitTest
argument_list|(
argument|const QPointF&point
argument_list|,
argument|Qt::HitTestAccuracy accuracy
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|QString
name|anchorAt
argument_list|(
argument|const QPointF& pos
argument_list|)
specifier|const
block|;
name|virtual
name|int
name|pageCount
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QSizeF
name|documentSize
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QRectF
name|frameBoundingRect
argument_list|(
argument|QTextFrame *frame
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QRectF
name|blockBoundingRect
argument_list|(
argument|const QTextBlock&block
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|void
name|setPaintDevice
argument_list|(
name|QPaintDevice
operator|*
name|device
argument_list|)
block|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
specifier|const
block|;
name|QTextDocument
operator|*
name|document
argument_list|()
specifier|const
block|;
name|void
name|registerHandler
argument_list|(
argument|int objectType
argument_list|,
argument|QObject *component
argument_list|)
block|;
name|void
name|unregisterHandler
argument_list|(
argument|int objectType
argument_list|,
argument|QObject *component =
literal|0
argument_list|)
block|;
name|QTextObjectInterface
operator|*
name|handlerForObject
argument_list|(
argument|int objectType
argument_list|)
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|update
argument_list|(
specifier|const
name|QRectF
operator|&
operator|=
name|QRectF
argument_list|(
literal|0.
argument_list|,
literal|0.
argument_list|,
literal|1000000000.
argument_list|,
literal|1000000000.
argument_list|)
argument_list|)
block|;
name|void
name|updateBlock
argument_list|(
specifier|const
name|QTextBlock
operator|&
name|block
argument_list|)
block|;
name|void
name|documentSizeChanged
argument_list|(
specifier|const
name|QSizeF
operator|&
name|newSize
argument_list|)
block|;
name|void
name|pageCountChanged
argument_list|(
argument|int newPages
argument_list|)
block|;
name|protected
operator|:
name|QAbstractTextDocumentLayout
argument_list|(
name|QAbstractTextDocumentLayoutPrivate
operator|&
argument_list|,
name|QTextDocument
operator|*
argument_list|)
block|;
name|virtual
name|void
name|documentChanged
argument_list|(
argument|int from
argument_list|,
argument|int charsRemoved
argument_list|,
argument|int charsAdded
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|resizeInlineObject
argument_list|(
argument|QTextInlineObject item
argument_list|,
argument|int posInDocument
argument_list|,
argument|const QTextFormat&format
argument_list|)
block|;
name|virtual
name|void
name|positionInlineObject
argument_list|(
argument|QTextInlineObject item
argument_list|,
argument|int posInDocument
argument_list|,
argument|const QTextFormat&format
argument_list|)
block|;
name|virtual
name|void
name|drawInlineObject
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRectF&rect
argument_list|,
argument|QTextInlineObject object
argument_list|,
argument|int posInDocument
argument_list|,
argument|const QTextFormat&format
argument_list|)
block|;
name|int
name|formatIndex
argument_list|(
argument|int pos
argument_list|)
block|;
name|QTextCharFormat
name|format
argument_list|(
argument|int pos
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QWidgetTextControl
block|;
name|friend
name|class
name|QTextDocument
block|;
name|friend
name|class
name|QTextDocumentPrivate
block|;
name|friend
name|class
name|QTextEngine
block|;
name|friend
name|class
name|QTextLayout
block|;
name|friend
name|class
name|QTextLine
block|;
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_handlerDestroyed(QObject *obj)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|int _q_dynamicPageCountSlot()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|QSizeF _q_dynamicDocumentSizeSlot()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextObjectInterface
block|{
name|public
label|:
name|virtual
operator|~
name|QTextObjectInterface
argument_list|()
block|{}
name|virtual
name|QSizeF
name|intrinsicSize
argument_list|(
argument|QTextDocument *doc
argument_list|,
argument|int posInDocument
argument_list|,
argument|const QTextFormat&format
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|drawObject
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|QTextDocument
modifier|*
name|doc
parameter_list|,
name|int
name|posInDocument
parameter_list|,
specifier|const
name|QTextFormat
modifier|&
name|format
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_INTERFACE
argument_list|(
argument|QTextObjectInterface
argument_list|,
literal|"org.qt-project.Qt.QTextObjectInterface"
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTTEXTDOCUMENTLAYOUT_H
end_comment
end_unit
