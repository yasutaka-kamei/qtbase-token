begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLAYOUTITEM_H
end_ifndef
begin_define
DECL|macro|QLAYOUTITEM_H
define|#
directive|define
name|QLAYOUTITEM_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qsizepolicy.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QLAYOUTSIZE_MAX
specifier|static
specifier|const
name|Q_DECL_UNUSED
name|int
name|QLAYOUTSIZE_MAX
init|=
name|INT_MAX
operator|/
literal|256
operator|/
literal|16
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLayout
name|class
name|QLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLayoutItem
name|class
name|QLayoutItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSpacerItem
name|class
name|QSpacerItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSize
name|class
name|QSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QLayoutItem
block|{
name|public
label|:
specifier|inline
name|explicit
name|QLayoutItem
argument_list|(
name|Qt
operator|::
name|Alignment
name|alignment
operator|=
name|Qt
operator|::
name|Alignment
argument_list|()
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|QLayoutItem
argument_list|()
expr_stmt|;
name|virtual
name|QSize
name|sizeHint
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QSize
name|minimumSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QSize
name|maximumSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QRect
name|geometry
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|isEmpty
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|heightForWidth
argument_list|(
name|int
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|int
name|minimumHeightForWidth
argument_list|(
name|int
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|invalidate
parameter_list|()
function_decl|;
name|virtual
name|QWidget
modifier|*
name|widget
parameter_list|()
function_decl|;
name|virtual
name|QLayout
modifier|*
name|layout
parameter_list|()
function_decl|;
name|virtual
name|QSpacerItem
modifier|*
name|spacerItem
parameter_list|()
function_decl|;
name|Qt
operator|::
name|Alignment
name|alignment
argument_list|()
specifier|const
block|{
return|return
name|align
return|;
block|}
name|void
name|setAlignment
argument_list|(
name|Qt
operator|::
name|Alignment
name|a
argument_list|)
decl_stmt|;
name|virtual
name|QSizePolicy
operator|::
name|ControlTypes
name|controlTypes
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|Qt
operator|::
name|Alignment
name|align
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|QLayoutItem
specifier|inline
name|QLayoutItem
operator|::
name|QLayoutItem
argument_list|(
argument|Qt::Alignment aalignment
argument_list|)
operator|:
name|align
argument_list|(
argument|aalignment
argument_list|)
block|{ }
name|class
name|Q_WIDGETS_EXPORT
name|QSpacerItem
operator|:
name|public
name|QLayoutItem
block|{
name|public
operator|:
name|QSpacerItem
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|QSizePolicy::Policy hData = QSizePolicy::Minimum
argument_list|,
argument|QSizePolicy::Policy vData = QSizePolicy::Minimum
argument_list|)
operator|:
name|width
argument_list|(
name|w
argument_list|)
block|,
name|height
argument_list|(
name|h
argument_list|)
block|,
name|sizeP
argument_list|(
argument|hData
argument_list|,
argument|vData
argument_list|)
block|{ }
operator|~
name|QSpacerItem
argument_list|()
block|;
name|void
name|changeSize
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|QSizePolicy::Policy hData = QSizePolicy::Minimum
argument_list|,
argument|QSizePolicy::Policy vData = QSizePolicy::Minimum
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
name|QSize
name|maximumSize
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
block|;
name|bool
name|isEmpty
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
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|QSpacerItem
operator|*
name|spacerItem
argument_list|()
block|;
name|QSizePolicy
name|sizePolicy
argument_list|()
specifier|const
block|{
return|return
name|sizeP
return|;
block|}
name|private
operator|:
name|int
name|width
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|height
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSizePolicy
name|sizeP
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|rect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|Q_WIDGETS_EXPORT
name|QWidgetItem
range|:
name|public
name|QLayoutItem
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWidgetItem
argument_list|)
name|public
operator|:
name|explicit
name|QWidgetItem
argument_list|(
name|QWidget
operator|*
name|w
argument_list|)
operator|:
name|wid
argument_list|(
argument|w
argument_list|)
block|{ }
operator|~
name|QWidgetItem
argument_list|()
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
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
block|;
name|bool
name|isEmpty
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
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|virtual
name|QWidget
operator|*
name|widget
argument_list|()
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
name|QSizePolicy
operator|::
name|ControlTypes
name|controlTypes
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QWidget
operator|*
name|wid
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QWidgetItemV2
range|:
name|public
name|QWidgetItem
block|{
name|public
operator|:
name|explicit
name|QWidgetItemV2
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
operator|~
name|QWidgetItemV2
argument_list|()
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
name|int
name|heightForWidth
argument_list|(
argument|int width
argument_list|)
specifier|const
block|;
name|private
operator|:
expr|enum
block|{
name|Dirty
operator|=
operator|-
literal|123
block|,
name|HfwCacheMaxSize
operator|=
literal|3
block|}
block|;
specifier|inline
name|bool
name|useSizeCache
argument_list|()
specifier|const
block|;
name|void
name|updateCacheIfNecessary
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|invalidateSizeCache
argument_list|()
block|{
name|q_cachedMinimumSize
operator|.
name|setWidth
argument_list|(
name|Dirty
argument_list|)
block|;
name|q_hfwCacheSize
operator|=
literal|0
block|;     }
name|mutable
name|QSize
name|q_cachedMinimumSize
block|;
name|mutable
name|QSize
name|q_cachedSizeHint
block|;
name|mutable
name|QSize
name|q_cachedMaximumSize
block|;
name|mutable
name|QSize
name|q_cachedHfws
index|[
name|HfwCacheMaxSize
index|]
block|;
name|mutable
name|short
name|q_firstCachedHfw
block|;
name|mutable
name|short
name|q_hfwCacheSize
block|;
name|void
operator|*
name|d
block|;
name|friend
name|class
name|QWidgetPrivate
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QWidgetItemV2
argument_list|)
block|}
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
comment|// QLAYOUTITEM_H
end_comment
end_unit
