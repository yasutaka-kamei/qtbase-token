begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTACKEDLAYOUT_H
end_ifndef
begin_define
DECL|macro|QSTACKEDLAYOUT_H
define|#
directive|define
name|QSTACKEDLAYOUT_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qlayout.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QStackedLayoutPrivate
name|class
name|QStackedLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QStackedLayout
range|:
name|public
name|QLayout
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QStackedLayout
argument_list|)
name|Q_ENUMS
argument_list|(
argument|StackingMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|StackingMode stackingMode READ stackingMode WRITE setStackingMode
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int count READ count
argument_list|)
name|public
operator|:
expr|enum
name|StackingMode
block|{
name|StackOne
block|,
name|StackAll
block|}
block|;
name|QStackedLayout
argument_list|()
block|;
name|explicit
name|QStackedLayout
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|explicit
name|QStackedLayout
argument_list|(
name|QLayout
operator|*
name|parentLayout
argument_list|)
block|;
operator|~
name|QStackedLayout
argument_list|()
block|;
name|int
name|addWidget
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|int
name|insertWidget
argument_list|(
argument|int index
argument_list|,
argument|QWidget *w
argument_list|)
block|;
name|QWidget
operator|*
name|currentWidget
argument_list|()
specifier|const
block|;
name|int
name|currentIndex
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
specifier|inline
name|QWidget
operator|*
name|widget
argument_list|()
block|{
return|return
name|QLayout
operator|::
name|widget
argument_list|()
return|;
block|}
else|#
directive|else
name|using
name|QLayout
operator|::
name|widget
block|;
endif|#
directive|endif
name|QWidget
operator|*
name|widget
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
name|StackingMode
name|stackingMode
argument_list|()
specifier|const
block|;
name|void
name|setStackingMode
argument_list|(
argument|StackingMode stackingMode
argument_list|)
block|;
comment|// abstract virtual functions:
name|void
name|addItem
argument_list|(
name|QLayoutItem
operator|*
name|item
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
block|;
name|QLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|QLayoutItem
operator|*
name|takeAt
argument_list|(
name|int
argument_list|)
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
block|;
name|int
name|heightForWidth
argument_list|(
argument|int width
argument_list|)
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|widgetRemoved
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|currentChanged
argument_list|(
argument|int index
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setCurrentIndex
argument_list|(
argument|int index
argument_list|)
block|;
name|void
name|setCurrentWidget
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QStackedLayout
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTACKEDLAYOUT_H
end_comment
end_unit
