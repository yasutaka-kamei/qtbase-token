begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBOXLAYOUT_H
end_ifndef
begin_define
DECL|macro|QBOXLAYOUT_H
define|#
directive|define
name|QBOXLAYOUT_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qlayout.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_INCLUDE_COMPAT
end_ifdef
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QBoxLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QBoxLayout
range|:
name|public
name|QLayout
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QBoxLayout
argument_list|)
name|public
operator|:
expr|enum
name|Direction
block|{
name|LeftToRight
block|,
name|RightToLeft
block|,
name|TopToBottom
block|,
name|BottomToTop
block|,
name|Down
operator|=
name|TopToBottom
block|,
name|Up
operator|=
name|BottomToTop
block|}
block|;
name|explicit
name|QBoxLayout
argument_list|(
name|Direction
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QBoxLayout
argument_list|()
block|;
name|Direction
name|direction
argument_list|()
specifier|const
block|;
name|void
name|setDirection
argument_list|(
name|Direction
argument_list|)
block|;
name|void
name|addSpacing
argument_list|(
argument|int size
argument_list|)
block|;
name|void
name|addStretch
argument_list|(
argument|int stretch =
literal|0
argument_list|)
block|;
name|void
name|addSpacerItem
argument_list|(
name|QSpacerItem
operator|*
name|spacerItem
argument_list|)
block|;
name|void
name|addWidget
argument_list|(
argument|QWidget *
argument_list|,
argument|int stretch =
literal|0
argument_list|,
argument|Qt::Alignment alignment =
literal|0
argument_list|)
block|;
name|void
name|addLayout
argument_list|(
argument|QLayout *layout
argument_list|,
argument|int stretch =
literal|0
argument_list|)
block|;
name|void
name|addStrut
argument_list|(
name|int
argument_list|)
block|;
name|void
name|addItem
argument_list|(
name|QLayoutItem
operator|*
argument_list|)
block|;
name|void
name|insertSpacing
argument_list|(
argument|int index
argument_list|,
argument|int size
argument_list|)
block|;
name|void
name|insertStretch
argument_list|(
argument|int index
argument_list|,
argument|int stretch =
literal|0
argument_list|)
block|;
name|void
name|insertSpacerItem
argument_list|(
argument|int index
argument_list|,
argument|QSpacerItem *spacerItem
argument_list|)
block|;
name|void
name|insertWidget
argument_list|(
argument|int index
argument_list|,
argument|QWidget *widget
argument_list|,
argument|int stretch =
literal|0
argument_list|,
argument|Qt::Alignment alignment =
literal|0
argument_list|)
block|;
name|void
name|insertLayout
argument_list|(
argument|int index
argument_list|,
argument|QLayout *layout
argument_list|,
argument|int stretch =
literal|0
argument_list|)
block|;
name|int
name|spacing
argument_list|()
specifier|const
block|;
name|void
name|setSpacing
argument_list|(
argument|int spacing
argument_list|)
block|;
name|bool
name|setStretchFactor
argument_list|(
argument|QWidget *w
argument_list|,
argument|int stretch
argument_list|)
block|;
name|bool
name|setStretchFactor
argument_list|(
argument|QLayout *l
argument_list|,
argument|int stretch
argument_list|)
block|;
name|void
name|setStretch
argument_list|(
argument|int index
argument_list|,
argument|int stretch
argument_list|)
block|;
name|int
name|stretch
argument_list|(
argument|int index
argument_list|)
specifier|const
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
name|QSize
name|maximumSize
argument_list|()
specifier|const
block|;
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
block|;
name|int
name|heightForWidth
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|int
name|minimumHeightForWidth
argument_list|(
argument|int
argument_list|)
specifier|const
block|;
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
block|;
name|void
name|invalidate
argument_list|()
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
name|int
name|count
argument_list|()
specifier|const
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|)
block|;
name|protected
operator|:
comment|// ### Qt 5: make public
name|void
name|insertItem
argument_list|(
argument|int index
argument_list|,
argument|QLayoutItem *
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QBoxLayout
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QHBoxLayout
range|:
name|public
name|QBoxLayout
block|{
name|Q_OBJECT
name|public
operator|:
name|QHBoxLayout
argument_list|()
block|;
name|explicit
name|QHBoxLayout
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
operator|~
name|QHBoxLayout
argument_list|()
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QHBoxLayout
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QVBoxLayout
range|:
name|public
name|QBoxLayout
block|{
name|Q_OBJECT
name|public
operator|:
name|QVBoxLayout
argument_list|()
block|;
name|explicit
name|QVBoxLayout
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
operator|~
name|QVBoxLayout
argument_list|()
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QVBoxLayout
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
comment|// QBOXLAYOUT_H
end_comment
end_unit
