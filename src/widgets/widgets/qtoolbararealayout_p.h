begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTOOLBARAREALAYOUT_P_H
end_ifndef
begin_define
DECL|macro|QTOOLBARAREALAYOUT_P_H
define|#
directive|define
name|QTOOLBARAREALAYOUT_P_H
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
file|<QList>
end_include
begin_include
include|#
directive|include
file|<QSize>
end_include
begin_include
include|#
directive|include
file|<QRect>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|function|pick
specifier|static
specifier|inline
name|int
name|pick
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|Horizontal
condition|?
name|pos
operator|.
name|x
argument_list|()
else|:
name|pos
operator|.
name|y
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|pick
specifier|static
specifier|inline
name|int
name|pick
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|Horizontal
condition|?
name|size
operator|.
name|width
argument_list|()
else|:
name|size
operator|.
name|height
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|rpick
specifier|static
specifier|inline
name|int
modifier|&
name|rpick
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
name|QPoint
operator|&
name|pos
argument_list|)
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|Horizontal
condition|?
name|pos
operator|.
name|rx
argument_list|()
else|:
name|pos
operator|.
name|ry
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|rpick
specifier|static
specifier|inline
name|int
modifier|&
name|rpick
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
name|QSize
operator|&
name|size
argument_list|)
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|Horizontal
condition|?
name|size
operator|.
name|rwidth
argument_list|()
else|:
name|size
operator|.
name|rheight
argument_list|()
return|;
block|}
end_decl_stmt
begin_expr_stmt
DECL|function|pick
specifier|static
specifier|inline
name|QSizePolicy
operator|::
name|Policy
name|pick
argument_list|(
argument|Qt::Orientation o
argument_list|,
argument|const QSizePolicy&policy
argument_list|)
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|Horizontal
operator|?
name|policy
operator|.
name|horizontalPolicy
argument_list|()
operator|:
name|policy
operator|.
name|verticalPolicy
argument_list|()
return|;
block|}
end_expr_stmt
begin_decl_stmt
DECL|function|perp
specifier|static
specifier|inline
name|int
name|perp
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|Vertical
condition|?
name|pos
operator|.
name|x
argument_list|()
else|:
name|pos
operator|.
name|y
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|perp
specifier|static
specifier|inline
name|int
name|perp
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|Vertical
condition|?
name|size
operator|.
name|width
argument_list|()
else|:
name|size
operator|.
name|height
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|rperp
specifier|static
specifier|inline
name|int
modifier|&
name|rperp
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
name|QPoint
operator|&
name|pos
argument_list|)
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|Vertical
condition|?
name|pos
operator|.
name|rx
argument_list|()
else|:
name|pos
operator|.
name|ry
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|function|rperp
specifier|static
specifier|inline
name|int
modifier|&
name|rperp
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
name|QSize
operator|&
name|size
argument_list|)
block|{
return|return
name|o
operator|==
name|Qt
operator|::
name|Vertical
condition|?
name|size
operator|.
name|rwidth
argument_list|()
else|:
name|size
operator|.
name|rheight
argument_list|()
return|;
block|}
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TOOLBAR
end_ifndef
begin_decl_stmt
DECL|variable|QToolBar
name|class
name|QToolBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLayoutItem
name|class
name|QLayoutItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMainWindow
name|class
name|QMainWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionToolBar
name|class
name|QStyleOptionToolBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QToolBarAreaLayoutItem
block|{
name|public
label|:
name|QToolBarAreaLayoutItem
argument_list|(
name|QLayoutItem
operator|*
name|item
operator|=
literal|0
argument_list|)
operator|:
name|widgetItem
argument_list|(
name|item
argument_list|)
operator|,
name|pos
argument_list|(
literal|0
argument_list|)
operator|,
name|size
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|preferredSize
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|gap
argument_list|(
argument|false
argument_list|)
block|{}
name|bool
name|skip
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|realSizeHint
argument_list|()
specifier|const
expr_stmt|;
name|void
name|resize
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
name|int
name|newSize
argument_list|)
block|{
name|newSize
operator|=
name|qMax
argument_list|(
name|pick
argument_list|(
name|o
argument_list|,
name|minimumSize
argument_list|()
argument_list|)
argument_list|,
name|newSize
argument_list|)
expr_stmt|;
name|int
name|sizeh
init|=
name|pick
argument_list|(
name|o
argument_list|,
name|sizeHint
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|newSize
operator|==
name|sizeh
condition|)
block|{
name|preferredSize
operator|=
operator|-
literal|1
expr_stmt|;
name|size
operator|=
name|sizeh
expr_stmt|;
block|}
else|else
block|{
name|preferredSize
operator|=
name|newSize
expr_stmt|;
block|}
block|}
name|void
name|extendSize
argument_list|(
name|Qt
operator|::
name|Orientation
name|o
argument_list|,
name|int
name|extent
argument_list|)
block|{
name|int
name|newSize
init|=
name|qMax
argument_list|(
name|pick
argument_list|(
name|o
argument_list|,
name|minimumSize
argument_list|()
argument_list|)
argument_list|,
operator|(
name|preferredSize
operator|>
literal|0
condition|?
name|preferredSize
else|:
name|pick
argument_list|(
name|o
argument_list|,
name|sizeHint
argument_list|()
argument_list|)
operator|)
operator|+
name|extent
argument_list|)
decl_stmt|;
name|int
name|sizeh
init|=
name|pick
argument_list|(
name|o
argument_list|,
name|sizeHint
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|newSize
operator|==
name|sizeh
condition|)
block|{
name|preferredSize
operator|=
operator|-
literal|1
expr_stmt|;
name|size
operator|=
name|sizeh
expr_stmt|;
block|}
else|else
block|{
name|preferredSize
operator|=
name|newSize
expr_stmt|;
block|}
block|}
name|QLayoutItem
modifier|*
name|widgetItem
decl_stmt|;
name|int
name|pos
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|preferredSize
decl_stmt|;
name|bool
name|gap
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QToolBarAreaLayoutItem
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QToolBarAreaLayoutLine
block|{
name|public
label|:
name|QToolBarAreaLayoutLine
argument_list|()
block|{}
comment|// for QVector, don't use
name|QToolBarAreaLayoutLine
argument_list|(
argument|Qt::Orientation orientation
argument_list|)
empty_stmt|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|fitLayout
parameter_list|()
function_decl|;
name|bool
name|skip
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|rect
decl_stmt|;
name|Qt
operator|::
name|Orientation
name|o
expr_stmt|;
name|QVector
operator|<
name|QToolBarAreaLayoutItem
operator|>
name|toolBarItems
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QToolBarAreaLayoutLine
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QToolBarAreaLayoutInfo
block|{
name|public
label|:
name|QToolBarAreaLayoutInfo
argument_list|(
argument|QInternal::DockPosition pos = QInternal::TopDock
argument_list|)
empty_stmt|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|fitLayout
parameter_list|()
function_decl|;
name|QLayoutItem
modifier|*
name|insertToolBar
parameter_list|(
name|QToolBar
modifier|*
name|before
parameter_list|,
name|QToolBar
modifier|*
name|toolBar
parameter_list|)
function_decl|;
name|void
name|insertItem
parameter_list|(
name|QToolBar
modifier|*
name|before
parameter_list|,
name|QLayoutItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|void
name|removeToolBar
parameter_list|(
name|QToolBar
modifier|*
name|toolBar
parameter_list|)
function_decl|;
name|void
name|insertToolBarBreak
parameter_list|(
name|QToolBar
modifier|*
name|before
parameter_list|)
function_decl|;
name|void
name|removeToolBarBreak
parameter_list|(
name|QToolBar
modifier|*
name|before
parameter_list|)
function_decl|;
name|void
name|moveToolBar
parameter_list|(
name|QToolBar
modifier|*
name|toolbar
parameter_list|,
name|int
name|pos
parameter_list|)
function_decl|;
name|QList
operator|<
name|int
operator|>
name|gapIndex
argument_list|(
argument|const QPoint&pos
argument_list|,
argument|int *maxDistance
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|insertGap
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|,
name|QLayoutItem
operator|*
name|item
argument_list|)
decl_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|QRect
name|itemRect
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|)
decl|const
decl_stmt|;
name|int
name|distance
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
decl|const
decl_stmt|;
name|QVector
operator|<
name|QToolBarAreaLayoutLine
operator|>
name|lines
expr_stmt|;
name|QRect
name|rect
decl_stmt|;
name|Qt
operator|::
name|Orientation
name|o
expr_stmt|;
name|QInternal
operator|::
name|DockPosition
name|dockPos
expr_stmt|;
name|bool
name|dirty
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QToolBarAreaLayoutInfo
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QToolBarAreaLayout
block|{
name|public
label|:
enum|enum
block|{
comment|// sentinel values used to validate state data
name|ToolBarStateMarker
init|=
literal|0xfe
block|,
name|ToolBarStateMarkerEx
init|=
literal|0xfc
block|}
enum|;
name|QRect
name|rect
decl_stmt|;
specifier|const
name|QMainWindow
modifier|*
name|mainWindow
decl_stmt|;
name|QToolBarAreaLayoutInfo
name|docks
index|[
literal|4
index|]
decl_stmt|;
name|bool
name|visible
decl_stmt|;
name|QToolBarAreaLayout
argument_list|(
specifier|const
name|QMainWindow
operator|*
name|win
argument_list|)
expr_stmt|;
name|QRect
name|fitLayout
parameter_list|()
function_decl|;
name|QSize
name|minimumSize
argument_list|(
specifier|const
name|QSize
operator|&
name|centerMin
argument_list|)
decl|const
decl_stmt|;
name|QRect
name|rectHint
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
name|QSize
name|sizeHint
argument_list|(
specifier|const
name|QSize
operator|&
name|center
argument_list|)
decl|const
decl_stmt|;
name|void
name|apply
parameter_list|(
name|bool
name|animate
parameter_list|)
function_decl|;
name|QLayoutItem
modifier|*
name|itemAt
argument_list|(
name|int
operator|*
name|x
argument_list|,
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|QLayoutItem
modifier|*
name|takeAt
parameter_list|(
name|int
modifier|*
name|x
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
name|void
name|deleteAllLayoutItems
parameter_list|()
function_decl|;
name|QLayoutItem
modifier|*
name|insertToolBar
parameter_list|(
name|QToolBar
modifier|*
name|before
parameter_list|,
name|QToolBar
modifier|*
name|toolBar
parameter_list|)
function_decl|;
name|void
name|removeToolBar
parameter_list|(
name|QToolBar
modifier|*
name|toolBar
parameter_list|)
function_decl|;
name|QLayoutItem
modifier|*
name|addToolBar
argument_list|(
name|QInternal
operator|::
name|DockPosition
name|pos
argument_list|,
name|QToolBar
operator|*
name|toolBar
argument_list|)
decl_stmt|;
name|void
name|insertToolBarBreak
parameter_list|(
name|QToolBar
modifier|*
name|before
parameter_list|)
function_decl|;
name|void
name|removeToolBarBreak
parameter_list|(
name|QToolBar
modifier|*
name|before
parameter_list|)
function_decl|;
name|void
name|addToolBarBreak
argument_list|(
name|QInternal
operator|::
name|DockPosition
name|pos
argument_list|)
decl_stmt|;
name|void
name|moveToolBar
parameter_list|(
name|QToolBar
modifier|*
name|toolbar
parameter_list|,
name|int
name|pos
parameter_list|)
function_decl|;
name|void
name|insertItem
argument_list|(
name|QInternal
operator|::
name|DockPosition
name|pos
argument_list|,
name|QLayoutItem
operator|*
name|item
argument_list|)
decl_stmt|;
name|void
name|insertItem
parameter_list|(
name|QToolBar
modifier|*
name|before
parameter_list|,
name|QLayoutItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|QInternal
operator|::
name|DockPosition
name|findToolBar
argument_list|(
argument|QToolBar *toolBar
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|toolBarBreak
argument_list|(
name|QToolBar
operator|*
name|toolBar
argument_list|)
decl|const
decl_stmt|;
name|void
name|getStyleOptionInfo
argument_list|(
name|QStyleOptionToolBar
operator|*
name|option
argument_list|,
name|QToolBar
operator|*
name|toolBar
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|int
operator|>
name|indexOf
argument_list|(
argument|QWidget *toolBar
argument_list|)
specifier|const
expr_stmt|;
name|QList
operator|<
name|int
operator|>
name|gapIndex
argument_list|(
argument|const QPoint&pos
argument_list|)
specifier|const
expr_stmt|;
name|QList
operator|<
name|int
operator|>
name|currentGapIndex
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|insertGap
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|,
name|QLayoutItem
operator|*
name|item
argument_list|)
decl_stmt|;
name|void
name|remove
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|)
decl_stmt|;
name|void
name|remove
parameter_list|(
name|QLayoutItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
name|QToolBarAreaLayoutItem
modifier|*
name|item
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|)
decl_stmt|;
name|QRect
name|itemRect
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|)
decl|const
decl_stmt|;
name|QLayoutItem
modifier|*
name|plug
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|)
decl_stmt|;
name|QLayoutItem
modifier|*
name|unplug
argument_list|(
specifier|const
name|QList
operator|<
name|int
operator|>
operator|&
name|path
argument_list|,
name|QToolBarAreaLayout
operator|*
name|other
argument_list|)
decl_stmt|;
name|void
name|saveState
argument_list|(
name|QDataStream
operator|&
name|stream
argument_list|)
decl|const
decl_stmt|;
name|bool
name|restoreState
argument_list|(
name|QDataStream
operator|&
name|stream
argument_list|,
specifier|const
name|QList
operator|<
name|QToolBar
operator|*
operator|>
operator|&
name|toolBars
argument_list|,
name|uchar
name|tmarker
argument_list|,
name|bool
name|testing
operator|=
name|false
argument_list|)
decl_stmt|;
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TOOLBAR
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTOOLBARAREALAYOUT_P_H
end_comment
end_unit
