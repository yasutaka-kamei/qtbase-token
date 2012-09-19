begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSCROLLAREA_H
end_ifndef
begin_define
DECL|macro|QSCROLLAREA_H
define|#
directive|define
name|QSCROLLAREA_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qabstractscrollarea.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SCROLLAREA
DECL|variable|QScrollAreaPrivate
name|class
name|QScrollAreaPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QScrollArea
range|:
name|public
name|QAbstractScrollArea
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool widgetResizable READ widgetResizable WRITE setWidgetResizable
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Alignment alignment READ alignment WRITE setAlignment
argument_list|)
name|public
operator|:
name|explicit
name|QScrollArea
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QScrollArea
argument_list|()
block|;
name|QWidget
operator|*
name|widget
argument_list|()
specifier|const
block|;
name|void
name|setWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|QWidget
operator|*
name|takeWidget
argument_list|()
block|;
name|bool
name|widgetResizable
argument_list|()
specifier|const
block|;
name|void
name|setWidgetResizable
argument_list|(
argument|bool resizable
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|()
specifier|const
block|;
name|void
name|setAlignment
argument_list|(
name|Qt
operator|::
name|Alignment
argument_list|)
block|;
name|void
name|ensureVisible
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int xmargin =
literal|50
argument_list|,
argument|int ymargin =
literal|50
argument_list|)
block|;
name|void
name|ensureWidgetVisible
argument_list|(
argument|QWidget *childWidget
argument_list|,
argument|int xmargin =
literal|50
argument_list|,
argument|int ymargin =
literal|50
argument_list|)
block|;
name|protected
operator|:
name|QScrollArea
argument_list|(
name|QScrollAreaPrivate
operator|&
name|dd
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
name|void
name|scrollContentsBy
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QScrollArea
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QScrollArea
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SCROLLAREA
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSCROLLAREA_H
end_comment
end_unit
