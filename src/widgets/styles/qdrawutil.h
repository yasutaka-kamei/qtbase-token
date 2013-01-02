begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDRAWUTIL_H
end_ifndef
begin_define
DECL|macro|QDRAWUTIL_H
define|#
directive|define
name|QDRAWUTIL_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_comment
comment|// char*->QString conversion
end_comment
begin_include
include|#
directive|include
file|<QtCore/qmargins.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPalette
name|class
name|QPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBrush
name|class
name|QBrush
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// Standard shade drawing
end_comment
begin_comment
comment|//
end_comment
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawShadeLine
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
name|int
name|x1
parameter_list|,
name|int
name|y1
parameter_list|,
name|int
name|x2
parameter_list|,
name|int
name|y2
parameter_list|,
specifier|const
name|QPalette
modifier|&
name|pal
parameter_list|,
name|bool
name|sunken
init|=
name|true
parameter_list|,
name|int
name|lineWidth
init|=
literal|1
parameter_list|,
name|int
name|midLineWidth
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawShadeLine
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|p1
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|p2
parameter_list|,
specifier|const
name|QPalette
modifier|&
name|pal
parameter_list|,
name|bool
name|sunken
init|=
name|true
parameter_list|,
name|int
name|lineWidth
init|=
literal|1
parameter_list|,
name|int
name|midLineWidth
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawShadeRect
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
specifier|const
name|QPalette
modifier|&
name|pal
parameter_list|,
name|bool
name|sunken
init|=
name|false
parameter_list|,
name|int
name|lineWidth
init|=
literal|1
parameter_list|,
name|int
name|midLineWidth
init|=
literal|0
parameter_list|,
specifier|const
name|QBrush
modifier|*
name|fill
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawShadeRect
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
specifier|const
name|QPalette
modifier|&
name|pal
parameter_list|,
name|bool
name|sunken
init|=
name|false
parameter_list|,
name|int
name|lineWidth
init|=
literal|1
parameter_list|,
name|int
name|midLineWidth
init|=
literal|0
parameter_list|,
specifier|const
name|QBrush
modifier|*
name|fill
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawShadePanel
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
specifier|const
name|QPalette
modifier|&
name|pal
parameter_list|,
name|bool
name|sunken
init|=
name|false
parameter_list|,
name|int
name|lineWidth
init|=
literal|1
parameter_list|,
specifier|const
name|QBrush
modifier|*
name|fill
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawShadePanel
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
specifier|const
name|QPalette
modifier|&
name|pal
parameter_list|,
name|bool
name|sunken
init|=
name|false
parameter_list|,
name|int
name|lineWidth
init|=
literal|1
parameter_list|,
specifier|const
name|QBrush
modifier|*
name|fill
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawWinButton
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
specifier|const
name|QPalette
modifier|&
name|pal
parameter_list|,
name|bool
name|sunken
init|=
name|false
parameter_list|,
specifier|const
name|QBrush
modifier|*
name|fill
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawWinButton
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
specifier|const
name|QPalette
modifier|&
name|pal
parameter_list|,
name|bool
name|sunken
init|=
name|false
parameter_list|,
specifier|const
name|QBrush
modifier|*
name|fill
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawWinPanel
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
specifier|const
name|QPalette
modifier|&
name|pal
parameter_list|,
name|bool
name|sunken
init|=
name|false
parameter_list|,
specifier|const
name|QBrush
modifier|*
name|fill
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawWinPanel
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
specifier|const
name|QPalette
modifier|&
name|pal
parameter_list|,
name|bool
name|sunken
init|=
name|false
parameter_list|,
specifier|const
name|QBrush
modifier|*
name|fill
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawPlainRect
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
specifier|const
name|QColor
modifier|&
parameter_list|,
name|int
name|lineWidth
init|=
literal|1
parameter_list|,
specifier|const
name|QBrush
modifier|*
name|fill
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_WIDGETS_EXPORT
name|void
name|qDrawPlainRect
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
specifier|const
name|QColor
modifier|&
parameter_list|,
name|int
name|lineWidth
init|=
literal|1
parameter_list|,
specifier|const
name|QBrush
modifier|*
name|fill
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_struct
DECL|struct|QTileRules
struct|struct
name|QTileRules
block|{
DECL|function|QTileRules
specifier|inline
name|QTileRules
argument_list|(
argument|Qt::TileRule horizontalRule
argument_list|,
argument|Qt::TileRule verticalRule
argument_list|)
operator|:
name|horizontal
argument_list|(
name|horizontalRule
argument_list|)
operator|,
name|vertical
argument_list|(
argument|verticalRule
argument_list|)
block|{}
DECL|function|QTileRules
specifier|inline
name|QTileRules
argument_list|(
argument|Qt::TileRule rule = Qt::StretchTile
argument_list|)
operator|:
name|horizontal
argument_list|(
name|rule
argument_list|)
operator|,
name|vertical
argument_list|(
argument|rule
argument_list|)
block|{}
DECL|member|horizontal
name|Qt
operator|::
name|TileRule
name|horizontal
expr_stmt|;
DECL|member|vertical
name|Qt
operator|::
name|TileRule
name|vertical
expr_stmt|;
block|}
struct|;
end_struct
begin_ifndef
ifndef|#
directive|ifndef
name|Q_QDOC
end_ifndef
begin_comment
comment|// For internal use only.
end_comment
begin_decl_stmt
name|namespace
name|QDrawBorderPixmap
block|{
enum|enum
name|DrawingHint
block|{
name|OpaqueTopLeft
init|=
literal|0x0001
block|,
name|OpaqueTop
init|=
literal|0x0002
block|,
name|OpaqueTopRight
init|=
literal|0x0004
block|,
name|OpaqueLeft
init|=
literal|0x0008
block|,
name|OpaqueCenter
init|=
literal|0x0010
block|,
name|OpaqueRight
init|=
literal|0x0020
block|,
name|OpaqueBottomLeft
init|=
literal|0x0040
block|,
name|OpaqueBottom
init|=
literal|0x0080
block|,
name|OpaqueBottomRight
init|=
literal|0x0100
block|,
name|OpaqueCorners
init|=
name|OpaqueTopLeft
operator||
name|OpaqueTopRight
operator||
name|OpaqueBottomLeft
operator||
name|OpaqueBottomRight
block|,
name|OpaqueEdges
init|=
name|OpaqueTop
operator||
name|OpaqueLeft
operator||
name|OpaqueRight
operator||
name|OpaqueBottom
block|,
name|OpaqueFrame
init|=
name|OpaqueCorners
operator||
name|OpaqueEdges
block|,
name|OpaqueAll
init|=
name|OpaqueCenter
operator||
name|OpaqueFrame
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|DrawingHints
argument_list|,
argument|DrawingHint
argument_list|)
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|Q_WIDGETS_EXPORT
name|void
name|qDrawBorderPixmap
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QRect
operator|&
name|targetRect
argument_list|,
specifier|const
name|QMargins
operator|&
name|targetMargins
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
specifier|const
name|QRect
operator|&
name|sourceRect
argument_list|,
specifier|const
name|QMargins
operator|&
name|sourceMargins
argument_list|,
specifier|const
name|QTileRules
operator|&
name|rules
operator|=
name|QTileRules
argument_list|()
ifndef|#
directive|ifndef
name|Q_QDOC
argument_list|,
name|QDrawBorderPixmap
operator|::
name|DrawingHints
name|hints
operator|=
literal|0
endif|#
directive|endif
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qDrawBorderPixmap
specifier|inline
name|void
name|qDrawBorderPixmap
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QRect
modifier|&
name|target
parameter_list|,
specifier|const
name|QMargins
modifier|&
name|margins
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
name|qDrawBorderPixmap
argument_list|(
name|painter
argument_list|,
name|target
argument_list|,
name|margins
argument_list|,
name|pixmap
argument_list|,
name|pixmap
operator|.
name|rect
argument_list|()
argument_list|,
name|margins
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDRAWUTIL_H
end_comment
end_unit
