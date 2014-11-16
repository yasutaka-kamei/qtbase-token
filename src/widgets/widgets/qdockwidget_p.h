begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDYNAMICDOCKWIDGET_P_H
end_ifndef
begin_define
DECL|macro|QDYNAMICDOCKWIDGET_P_H
define|#
directive|define
name|QDYNAMICDOCKWIDGET_P_H
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
file|"QtWidgets/qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qboxlayout.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qdockwidget.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DOCKWIDGET
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGridLayout
name|class
name|QGridLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidgetResizeHandler
name|class
name|QWidgetResizeHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRubberBand
name|class
name|QRubberBand
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDockWidgetTitleButton
name|class
name|QDockWidgetTitleButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSpacerItem
name|class
name|QSpacerItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDockWidgetItem
name|class
name|QDockWidgetItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDockWidgetPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QDockWidget
argument_list|)
block|struct
name|DragState
block|{
name|QPoint
name|pressPos
block|;
name|bool
name|dragging
block|;
name|QLayoutItem
operator|*
name|widgetItem
block|;
name|bool
name|ownWidgetItem
block|;
name|bool
name|nca
block|;
name|bool
name|ctrlDrag
block|;     }
block|;
name|public
operator|:
specifier|inline
name|QDockWidgetPrivate
argument_list|()
operator|:
name|QWidgetPrivate
argument_list|()
block|,
name|state
argument_list|(
literal|0
argument_list|)
block|,
name|features
argument_list|(
name|QDockWidget
operator|::
name|DockWidgetClosable
operator||
name|QDockWidget
operator|::
name|DockWidgetMovable
operator||
name|QDockWidget
operator|::
name|DockWidgetFloatable
argument_list|)
block|,
name|allowedAreas
argument_list|(
name|Qt
operator|::
name|AllDockWidgetAreas
argument_list|)
block|,
name|resizer
argument_list|(
literal|0
argument_list|)
block|{ }
name|void
name|init
argument_list|()
block|;
name|void
name|_q_toggleView
argument_list|(
name|bool
argument_list|)
block|;
comment|// private slot
name|void
name|_q_toggleTopLevel
argument_list|()
block|;
comment|// private slot
name|void
name|updateButtons
argument_list|()
block|;
name|DragState
operator|*
name|state
block|;
name|QDockWidget
operator|::
name|DockWidgetFeatures
name|features
block|;
name|Qt
operator|::
name|DockWidgetAreas
name|allowedAreas
block|;
ifndef|#
directive|ifndef
name|QT_NO_ACTION
name|QAction
operator|*
name|toggleViewAction
block|;
endif|#
directive|endif
comment|//    QMainWindow *findMainWindow(QWidget *widget) const;
name|QRect
name|undockedGeometry
block|;
name|QString
name|fixedWindowTitle
block|;
name|bool
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|mouseDoubleClickEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|setWindowState
argument_list|(
argument|bool floating
argument_list|,
argument|bool unplug = false
argument_list|,
argument|const QRect&rect = QRect()
argument_list|)
block|;
name|void
name|nonClientAreaMouseEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|initDrag
argument_list|(
argument|const QPoint&pos
argument_list|,
argument|bool nca
argument_list|)
block|;
name|void
name|startDrag
argument_list|()
block|;
name|void
name|endDrag
argument_list|(
argument|bool abort = false
argument_list|)
block|;
name|void
name|moveEvent
argument_list|(
name|QMoveEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|unplug
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|plug
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|setResizerActive
argument_list|(
argument|bool active
argument_list|)
block|;
name|bool
name|isAnimating
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QWidgetResizeHandler
operator|*
name|resizer
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDockWidgetLayout
range|:
name|public
name|QLayout
block|{
name|Q_OBJECT
name|public
operator|:
name|QDockWidgetLayout
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QDockWidgetLayout
argument_list|()
block|;
name|void
name|addItem
argument_list|(
argument|QLayoutItem *item
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QLayoutItem
operator|*
name|takeAt
argument_list|(
argument|int index
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|int
name|count
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|maximumSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|sizeFromContent
argument_list|(
argument|const QSize&content
argument_list|,
argument|bool floating
argument_list|)
specifier|const
block|;
name|void
name|setGeometry
argument_list|(
argument|const QRect&r
argument_list|)
name|Q_DECL_OVERRIDE
block|;      enum
name|Role
block|{
name|Content
block|,
name|CloseButton
block|,
name|FloatButton
block|,
name|TitleBar
block|,
name|RoleCount
block|}
block|;
name|QWidget
operator|*
name|widgetForRole
argument_list|(
argument|Role r
argument_list|)
specifier|const
block|;
name|void
name|setWidgetForRole
argument_list|(
argument|Role r
argument_list|,
argument|QWidget *w
argument_list|)
block|;
name|QLayoutItem
operator|*
name|itemForRole
argument_list|(
argument|Role r
argument_list|)
specifier|const
block|;
name|QRect
name|titleArea
argument_list|()
specifier|const
block|{
return|return
name|_titleArea
return|;
block|}
name|int
name|minimumTitleWidth
argument_list|()
specifier|const
block|;
name|int
name|titleHeight
argument_list|()
specifier|const
block|;
name|void
name|updateMaxSize
argument_list|()
block|;
name|bool
name|nativeWindowDeco
argument_list|()
specifier|const
block|;
name|bool
name|nativeWindowDeco
argument_list|(
argument|bool floating
argument_list|)
specifier|const
block|;
name|void
name|setVerticalTitleBar
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|verticalTitleBar
block|;
name|private
operator|:
name|QVector
operator|<
name|QLayoutItem
operator|*
operator|>
name|item_list
block|;
name|QRect
name|_titleArea
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* The size hints of a QDockWidget will depend on whether it is docked or not.    This layout item always returns the size hints as if the dock widget was docked. */
end_comment
begin_decl_stmt
name|class
name|QDockWidgetItem
range|:
name|public
name|QWidgetItem
block|{
name|public
operator|:
name|QDockWidgetItem
argument_list|(
name|QDockWidget
operator|*
name|dockWidget
argument_list|)
block|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|maximumSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
specifier|inline
name|QLayoutItem
operator|*
name|dockWidgetChildItem
argument_list|()
specifier|const
block|;
specifier|inline
name|QDockWidgetLayout
operator|*
name|dockWidgetLayout
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|dockWidgetChildItem
specifier|inline
name|QLayoutItem
operator|*
name|QDockWidgetItem
operator|::
name|dockWidgetChildItem
argument_list|()
specifier|const
block|{
if|if
condition|(
name|QDockWidgetLayout
modifier|*
name|layout
init|=
name|dockWidgetLayout
argument_list|()
condition|)
return|return
name|layout
operator|->
name|itemForRole
argument_list|(
name|QDockWidgetLayout
operator|::
name|Content
argument_list|)
return|;
end_expr_stmt
begin_return
return|return
literal|0
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|dockWidgetLayout
name|QDockWidgetLayout
operator|*
name|QDockWidgetItem
operator|::
name|dockWidgetLayout
argument_list|()
specifier|const
block|{
name|QWidget
operator|*
name|w
operator|=
name|const_cast
operator|<
name|QDockWidgetItem
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|widget
argument_list|()
block|;
if|if
condition|(
name|w
operator|!=
literal|0
condition|)
return|return
name|qobject_cast
operator|<
name|QDockWidgetLayout
operator|*
operator|>
operator|(
name|w
operator|->
name|layout
argument_list|()
operator|)
return|;
end_expr_stmt
begin_return
return|return
literal|0
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DOCKWIDGET
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDYNAMICDOCKWIDGET_P_H
end_comment
end_unit
