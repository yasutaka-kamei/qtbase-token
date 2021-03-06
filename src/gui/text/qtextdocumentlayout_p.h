begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTDOCUMENTLAYOUT_P_H
end_ifndef
begin_define
DECL|macro|QTEXTDOCUMENTLAYOUT_P_H
define|#
directive|define
name|QTEXTDOCUMENTLAYOUT_P_H
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
file|"QtGui/qabstracttextdocumentlayout.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextoption.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtextobject.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextListFormat
name|class
name|QTextListFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextTableCell
name|class
name|QTextTableCell
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextDocumentLayoutPrivate
name|class
name|QTextDocumentLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextDocumentLayout
range|:
name|public
name|QAbstractTextDocumentLayout
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTextDocumentLayout
argument_list|)
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|int cursorWidth READ cursorWidth WRITE setCursorWidth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|qreal idealWidth READ idealWidth
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool contentHasAlignment READ contentHasAlignment
argument_list|)
name|public
operator|:
name|explicit
name|QTextDocumentLayout
argument_list|(
name|QTextDocument
operator|*
name|doc
argument_list|)
block|;
comment|// from the abstract layout
name|void
name|draw
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const PaintContext&context
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|int
name|hitTest
argument_list|(
argument|const QPointF&point
argument_list|,
argument|Qt::HitTestAccuracy accuracy
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|pageCount
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSizeF
name|documentSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setCursorWidth
argument_list|(
argument|int width
argument_list|)
block|;
name|int
name|cursorWidth
argument_list|()
specifier|const
block|;
comment|// internal, to support the ugly FixedColumnWidth wordwrap mode in QTextEdit
name|void
name|setFixedColumnWidth
argument_list|(
argument|int width
argument_list|)
block|;
comment|// internal for QTextEdit's NoWrap mode
name|void
name|setViewport
argument_list|(
specifier|const
name|QRectF
operator|&
name|viewport
argument_list|)
block|;
name|virtual
name|QRectF
name|frameBoundingRect
argument_list|(
argument|QTextFrame *frame
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QRectF
name|blockBoundingRect
argument_list|(
argument|const QTextBlock&block
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QRectF
name|tableBoundingRect
argument_list|(
argument|QTextTable *table
argument_list|)
specifier|const
block|;
name|QRectF
name|tableCellBoundingRect
argument_list|(
argument|QTextTable *table
argument_list|,
argument|const QTextTableCell&cell
argument_list|)
specifier|const
block|;
comment|// ####
name|int
name|layoutStatus
argument_list|()
specifier|const
block|;
name|int
name|dynamicPageCount
argument_list|()
specifier|const
block|;
name|QSizeF
name|dynamicDocumentSize
argument_list|()
specifier|const
block|;
name|void
name|ensureLayouted
argument_list|(
name|qreal
argument_list|)
block|;
name|qreal
name|idealWidth
argument_list|()
specifier|const
block|;
name|bool
name|contentHasAlignment
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|void
name|documentChanged
argument_list|(
argument|int from
argument_list|,
argument|int oldLength
argument_list|,
argument|int length
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resizeInlineObject
argument_list|(
argument|QTextInlineObject item
argument_list|,
argument|int posInDocument
argument_list|,
argument|const QTextFormat&format
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|positionInlineObject
argument_list|(
argument|QTextInlineObject item
argument_list|,
argument|int posInDocument
argument_list|,
argument|const QTextFormat&format
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|drawInlineObject
argument_list|(
argument|QPainter *p
argument_list|,
argument|const QRectF&rect
argument_list|,
argument|QTextInlineObject item
argument_list|,
argument|int posInDocument
argument_list|,
argument|const QTextFormat&format
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|timerEvent
argument_list|(
argument|QTimerEvent *e
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QRectF
name|doLayout
argument_list|(
argument|int from
argument_list|,
argument|int oldLength
argument_list|,
argument|int length
argument_list|)
block|;
name|void
name|layoutFinished
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
comment|// QTEXTDOCUMENTLAYOUT_P_H
end_comment
end_unit
