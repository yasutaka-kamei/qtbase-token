begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOLUMNVIEW_P_H
end_ifndef
begin_define
DECL|macro|QCOLUMNVIEW_P_H
define|#
directive|define
name|QCOLUMNVIEW_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|"qcolumnview.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QCOLUMNVIEW
end_ifndef
begin_include
include|#
directive|include
file|<private/qabstractitemview_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpropertyanimation.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qabstractitemdelegate.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qabstractitemview.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qitemdelegate.h>
end_include
begin_include
include|#
directive|include
file|<qlistview.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qscrollbar.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QColumnViewPreviewColumn
range|:
name|public
name|QAbstractItemView
block|{
name|public
operator|:
name|explicit
name|QColumnViewPreviewColumn
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
operator|:
name|QAbstractItemView
argument_list|(
name|parent
argument_list|)
block|,
name|previewWidget
argument_list|(
literal|0
argument_list|)
block|{     }
name|void
name|setPreviewWidget
argument_list|(
argument|QWidget *widget
argument_list|)
block|{
name|previewWidget
operator|=
name|widget
block|;
name|setMinimumWidth
argument_list|(
name|previewWidget
operator|->
name|minimumWidth
argument_list|()
argument_list|)
block|;     }
name|void
name|resizeEvent
argument_list|(
argument|QResizeEvent * event
argument_list|)
block|{
if|if
condition|(
operator|!
name|previewWidget
condition|)
return|return;
name|previewWidget
operator|->
name|resize
argument_list|(
name|qMax
argument_list|(
name|previewWidget
operator|->
name|minimumWidth
argument_list|()
argument_list|,
name|event
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|)
argument_list|,
name|previewWidget
operator|->
name|height
argument_list|()
argument_list|)
block|;
name|QSize
name|p
operator|=
name|viewport
argument_list|()
operator|->
name|size
argument_list|()
block|;
name|QSize
name|v
operator|=
name|previewWidget
operator|->
name|size
argument_list|()
block|;
name|horizontalScrollBar
argument_list|()
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
name|v
operator|.
name|width
argument_list|()
operator|-
name|p
operator|.
name|width
argument_list|()
argument_list|)
block|;
name|horizontalScrollBar
argument_list|()
operator|->
name|setPageStep
argument_list|(
name|p
operator|.
name|width
argument_list|()
argument_list|)
block|;
name|verticalScrollBar
argument_list|()
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
name|v
operator|.
name|height
argument_list|()
operator|-
name|p
operator|.
name|height
argument_list|()
argument_list|)
block|;
name|verticalScrollBar
argument_list|()
operator|->
name|setPageStep
argument_list|(
name|p
operator|.
name|height
argument_list|()
argument_list|)
block|;
name|QAbstractScrollArea
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
block|;     }
name|QRect
name|visualRect
argument_list|(
argument|const QModelIndex&
argument_list|)
specifier|const
block|{
return|return
name|QRect
argument_list|()
return|;
block|}
end_decl_stmt
begin_function
name|void
name|scrollTo
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
parameter_list|,
name|ScrollHint
parameter_list|)
block|{     }
end_function
begin_decl_stmt
name|QModelIndex
name|indexAt
argument_list|(
specifier|const
name|QPoint
operator|&
argument_list|)
decl|const
block|{
return|return
name|QModelIndex
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QModelIndex
name|moveCursor
argument_list|(
name|CursorAction
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
argument_list|)
block|{
return|return
name|QModelIndex
argument_list|()
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|int
name|horizontalOffset
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|verticalOffset
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|QRegion
name|visualRegionForSelection
argument_list|(
specifier|const
name|QItemSelection
operator|&
argument_list|)
decl|const
block|{
return|return
name|QRegion
argument_list|()
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|bool
name|isIndexHidden
argument_list|(
specifier|const
name|QModelIndex
operator|&
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|void
name|setSelection
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|,
name|QItemSelectionModel
operator|::
name|SelectionFlags
argument_list|)
block|{     }
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QWidget
modifier|*
name|previewWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|Q_AUTOTEST_EXPORT
name|QColumnViewPrivate
range|:
name|public
name|QAbstractItemViewPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QColumnView
argument_list|)
name|public
operator|:
name|QColumnViewPrivate
argument_list|()
block|;
operator|~
name|QColumnViewPrivate
argument_list|()
block|;
name|void
name|initialize
argument_list|()
block|;
name|QAbstractItemView
operator|*
name|createColumn
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|bool show
argument_list|)
block|;
name|void
name|updateScrollbars
argument_list|()
block|;
name|void
name|closeColumns
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|,
argument|bool build = false
argument_list|)
block|;
name|void
name|doLayout
argument_list|()
block|;
name|void
name|setPreviewWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|checkColumnCreation
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|parent
argument_list|)
block|;
name|void
name|_q_gripMoved
argument_list|(
argument|int offset
argument_list|)
block|;
name|void
name|_q_changeCurrentColumn
argument_list|()
block|;
name|void
name|_q_clicked
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|void
name|_q_columnsInserted
argument_list|(
argument|const QModelIndex&parent
argument_list|,
argument|int start
argument_list|,
argument|int end
argument_list|)
block|;
name|QList
operator|<
name|QAbstractItemView
operator|*
operator|>
name|columns
block|;
name|QVector
operator|<
name|int
operator|>
name|columnSizes
block|;
comment|// used during init and corner moving
name|bool
name|showResizeGrips
block|;
name|int
name|offset
block|;
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|QPropertyAnimation
name|currentAnimation
block|;
endif|#
directive|endif
name|QWidget
operator|*
name|previewWidget
block|;
name|QAbstractItemView
operator|*
name|previewColumn
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!  * This is a delegate that will paint the triangle  */
end_comment
begin_decl_stmt
name|class
name|QColumnViewDelegate
range|:
name|public
name|QItemDelegate
block|{
name|public
operator|:
name|explicit
name|QColumnViewDelegate
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QItemDelegate
argument_list|(
argument|parent
argument_list|)
block|{}
operator|~
name|QColumnViewDelegate
argument_list|()
block|{}
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QCOLUMNVIEW
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QCOLUMNVIEW_P_H
end_comment
end_unit
