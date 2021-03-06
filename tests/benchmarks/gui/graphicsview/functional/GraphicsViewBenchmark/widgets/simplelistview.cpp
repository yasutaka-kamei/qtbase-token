begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"simplelistview.h"
end_include
begin_include
include|#
directive|include
file|"scrollbar.h"
end_include
begin_include
include|#
directive|include
file|"simplelistview.h"
end_include
begin_include
include|#
directive|include
file|"scrollbar.h"
end_include
begin_include
include|#
directive|include
file|"listitem.h"
end_include
begin_include
include|#
directive|include
file|"listitemcache.h"
end_include
begin_include
include|#
directive|include
file|"theme.h"
end_include
begin_class
DECL|class|SimpleListViewPrivate
class|class
name|SimpleListViewPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|SimpleListView
parameter_list|)
specifier|public
private|:
DECL|function|SimpleListViewPrivate
name|SimpleListViewPrivate
parameter_list|(
name|SimpleListView
modifier|*
name|button
parameter_list|)
member_init_list|:
name|m_content
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_layout
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_twoColumns
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|q_ptr
argument_list|(
name|button
argument_list|)
member_init_list|,
name|m_listItemCaching
argument_list|(
literal|false
argument_list|)
block|{
name|Q_Q
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
name|m_layout
operator|=
operator|new
name|QGraphicsGridLayout
argument_list|()
expr_stmt|;
name|m_layout
operator|->
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setSpacing
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setColumnSpacing
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setColumnSpacing
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setRowSpacing
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setRowSpacing
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_content
operator|=
operator|new
name|QGraphicsWidget
expr_stmt|;
name|m_content
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|m_content
operator|->
name|setParentItem
argument_list|(
name|q
operator|->
name|viewport
argument_list|()
argument_list|)
expr_stmt|;
name|m_content
operator|->
name|setLayout
argument_list|(
name|m_layout
argument_list|)
expr_stmt|;
name|q
operator|->
name|horizontalScrollBar
argument_list|()
operator|->
name|setSliderSize
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|themeChanged
argument_list|()
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|themeChange
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|~SimpleListViewPrivate
name|~
name|SimpleListViewPrivate
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_content
operator|->
name|parentItem
argument_list|()
operator|&&
operator|!
name|m_content
operator|->
name|parent
argument_list|()
condition|)
operator|delete
name|m_content
expr_stmt|;
block|}
DECL|function|resizeContents
name|void
name|resizeContents
parameter_list|(
name|QSizeF
name|s
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|Q_Q
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_content
condition|)
return|return;
specifier|const
name|bool
name|caching
init|=
name|q
operator|->
name|listItemCaching
argument_list|()
decl_stmt|;
name|q
operator|->
name|setListItemCaching
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|m_content
operator|->
name|resize
argument_list|(
name|q
operator|->
name|viewport
argument_list|()
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|m_layout
operator|->
name|preferredHeight
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|clip
init|=
name|m_content
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|>
name|q
operator|->
name|viewport
argument_list|()
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|||
name|m_content
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
operator|>
name|q
operator|->
name|viewport
argument_list|()
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
decl_stmt|;
name|q
operator|->
name|viewport
argument_list|()
operator|->
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemClipsChildrenToShape
argument_list|,
name|clip
argument_list|)
expr_stmt|;
name|q
operator|->
name|setListItemCaching
argument_list|(
name|caching
argument_list|)
expr_stmt|;
block|}
DECL|function|resizeScrollBars
name|void
name|resizeScrollBars
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_content
condition|)
return|return;
name|m_content
operator|->
name|resize
argument_list|(
name|m_content
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|m_layout
operator|->
name|preferredHeight
argument_list|()
argument_list|)
expr_stmt|;
name|QRectF
name|contentRect
init|=
name|m_content
operator|->
name|boundingRect
argument_list|()
decl_stmt|;
name|QRectF
name|listRect
init|=
name|q
operator|->
name|boundingRect
argument_list|()
decl_stmt|;
comment|// List do not have horizontal scroll bar visible.
name|q
operator|->
name|horizontalScrollBar
argument_list|()
operator|->
name|setSliderSize
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
if|if
condition|(
name|contentRect
operator|.
name|height
argument_list|()
operator|-
name|q
operator|->
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
operator|>
literal|0
condition|)
block|{
name|q
operator|->
name|verticalScrollBar
argument_list|()
operator|->
name|setSliderSize
argument_list|(
name|contentRect
operator|.
name|height
argument_list|()
operator|-
name|q
operator|->
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|q
operator|->
name|verticalScrollBarPolicy
argument_list|()
operator|!=
name|Qt
operator|::
name|ScrollBarAlwaysOff
operator|&&
operator|!
name|q
operator|->
name|verticalScrollBar
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
block|{
name|q
operator|->
name|verticalScrollBar
argument_list|()
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|q
operator|->
name|verticalScrollBarPolicy
argument_list|()
operator|==
name|Qt
operator|::
name|ScrollBarAsNeeded
operator|||
name|q
operator|->
name|verticalScrollBarPolicy
argument_list|()
operator|==
name|Qt
operator|::
name|ScrollBarAlwaysOff
condition|)
block|{
name|q
operator|->
name|verticalScrollBar
argument_list|()
operator|->
name|setSliderSize
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
name|q
operator|->
name|verticalScrollBar
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|q
operator|->
name|verticalScrollBar
argument_list|()
operator|->
name|setSliderSize
argument_list|(
literal|0.0
argument_list|)
expr_stmt|;
block|}
name|qreal
name|pos
init|=
literal|0.0
decl_stmt|;
if|if
condition|(
operator|(
name|m_content
operator|->
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
operator|-
name|q
operator|->
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
operator|)
operator|!=
literal|0
condition|)
block|{
name|qreal
name|min
init|=
name|qMin
argument_list|(
operator|-
name|contentRect
operator|.
name|top
argument_list|()
argument_list|,
name|m_content
operator|->
name|pos
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
name|qreal
name|diff
init|=
name|contentRect
operator|.
name|height
argument_list|()
operator|-
name|listRect
operator|.
name|height
argument_list|()
decl_stmt|;
name|pos
operator|=
name|qAbs
argument_list|(
name|contentRect
operator|.
name|top
argument_list|()
operator|+
name|min
argument_list|)
operator|/
name|diff
expr_stmt|;
block|}
name|q
operator|->
name|verticalScrollBar
argument_list|()
operator|->
name|setSliderPosition
argument_list|(
name|pos
argument_list|)
expr_stmt|;
block|}
DECL|function|updateListContents
name|void
name|updateListContents
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|caching
init|=
name|q
operator|->
name|listItemCaching
argument_list|()
decl_stmt|;
name|q
operator|->
name|setListItemCaching
argument_list|(
literal|false
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|defaultIcon
init|=
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmapPath
argument_list|()
operator|+
literal|"contact_default_icon.svg"
decl_stmt|;
specifier|const
name|int
name|itemCount
init|=
name|m_layout
operator|->
name|count
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|itemCount
condition|;
operator|++
name|i
control|)
block|{
name|ListItem
modifier|*
name|item
init|=
cast|static_cast
argument_list|<
name|ListItem
operator|*
argument_list|>
argument_list|(
name|m_layout
operator|->
name|itemAt
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
comment|// Update default icons
specifier|const
name|QString
name|filename
init|=
name|item
operator|->
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|fileName
argument_list|()
decl_stmt|;
if|if
condition|(
name|filename
operator|.
name|contains
argument_list|(
literal|"contact_default_icon"
argument_list|)
condition|)
block|{
name|item
operator|->
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|setFileName
argument_list|(
name|defaultIcon
argument_list|)
expr_stmt|;
block|}
comment|// Update status icons
name|QString
name|statusIcon
init|=
name|item
operator|->
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|fileName
argument_list|()
decl_stmt|;
specifier|const
name|int
name|index
init|=
name|statusIcon
operator|.
name|indexOf
argument_list|(
literal|"contact_status"
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|!=
operator|-
literal|1
condition|)
block|{
name|statusIcon
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|index
argument_list|)
expr_stmt|;
name|item
operator|->
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|setFileName
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|pixmapPath
argument_list|()
operator|+
name|statusIcon
argument_list|)
expr_stmt|;
block|}
comment|// Update fonts
name|item
operator|->
name|setFont
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|font
argument_list|(
name|Theme
operator|::
name|ContactName
argument_list|)
argument_list|,
name|ListItem
operator|::
name|FirstPos
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFont
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|font
argument_list|(
name|Theme
operator|::
name|ContactNumber
argument_list|)
argument_list|,
name|ListItem
operator|::
name|SecondPos
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFont
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|font
argument_list|(
name|Theme
operator|::
name|ContactEmail
argument_list|)
argument_list|,
name|ListItem
operator|::
name|ThirdPos
argument_list|)
expr_stmt|;
comment|// Update list dividers
if|if
condition|(
name|i
operator|%
literal|2
condition|)
block|{
name|item
operator|->
name|setBackgroundBrush
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|listItemBackgroundBrushOdd
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setBackgroundOpacity
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|listItemBackgroundOpacityOdd
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|item
operator|->
name|setBackgroundBrush
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|listItemBackgroundBrushEven
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setBackgroundOpacity
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|listItemBackgroundOpacityEven
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Update borders
name|item
operator|->
name|setBorderPen
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|listItemBorderPen
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setRounding
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|listItemRounding
argument_list|()
argument_list|)
expr_stmt|;
comment|// Update icons
name|item
operator|->
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|setRotation
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|iconRotation
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
argument_list|)
expr_stmt|;
name|item
operator|->
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|setRotation
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|iconRotation
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
argument_list|)
expr_stmt|;
name|item
operator|->
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|setOpacityEffectEnabled
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|isIconOpacityEffectEnabled
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
argument_list|)
expr_stmt|;
name|item
operator|->
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|setOpacityEffectEnabled
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|isIconOpacityEffectEnabled
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
argument_list|)
expr_stmt|;
name|item
operator|->
name|icon
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
operator|->
name|setSmoothTransformationEnabled
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|isIconSmoothTransformationEnabled
argument_list|(
name|ListItem
operator|::
name|LeftIcon
argument_list|)
argument_list|)
expr_stmt|;
name|item
operator|->
name|icon
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
operator|->
name|setSmoothTransformationEnabled
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|isIconSmoothTransformationEnabled
argument_list|(
name|ListItem
operator|::
name|RightIcon
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|q
operator|->
name|setListItemCaching
argument_list|(
name|caching
argument_list|)
expr_stmt|;
block|}
DECL|function|updateListItemBackgrounds
name|void
name|updateListItemBackgrounds
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|caching
init|=
name|q
operator|->
name|listItemCaching
argument_list|()
decl_stmt|;
name|q
operator|->
name|setListItemCaching
argument_list|(
literal|false
argument_list|)
expr_stmt|;
specifier|const
name|int
name|itemCount
init|=
name|m_layout
operator|->
name|count
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|index
init|;
name|i
operator|<
name|itemCount
condition|;
operator|++
name|i
control|)
block|{
name|ListItem
modifier|*
name|item
init|=
cast|static_cast
argument_list|<
name|ListItem
operator|*
argument_list|>
argument_list|(
name|m_layout
operator|->
name|itemAt
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|%
literal|2
condition|)
block|{
name|item
operator|->
name|setBackgroundBrush
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|listItemBackgroundBrushOdd
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setBackgroundOpacity
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|listItemBackgroundOpacityOdd
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|item
operator|->
name|setBackgroundBrush
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|listItemBackgroundBrushEven
argument_list|()
argument_list|)
expr_stmt|;
name|item
operator|->
name|setBackgroundOpacity
argument_list|(
name|Theme
operator|::
name|p
argument_list|()
operator|->
name|listItemBackgroundOpacityEven
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|q
operator|->
name|setListItemCaching
argument_list|(
name|caching
argument_list|)
expr_stmt|;
block|}
DECL|function|setTwoColumns
name|void
name|setTwoColumns
parameter_list|(
specifier|const
name|bool
name|twoColumns
parameter_list|)
block|{
if|if
condition|(
name|twoColumns
operator|==
name|m_twoColumns
condition|)
return|return;
name|Q_Q
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
name|m_twoColumns
operator|=
name|twoColumns
expr_stmt|;
name|bool
name|cache
init|=
name|q
operator|->
name|listItemCaching
argument_list|()
decl_stmt|;
name|q
operator|->
name|setListItemCaching
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QGraphicsLayoutItem
modifier|*
argument_list|>
name|moveditems
decl_stmt|;
if|if
condition|(
name|twoColumns
condition|)
block|{
name|int
name|half
init|=
name|m_layout
operator|->
name|count
argument_list|()
operator|/
literal|2
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|m_layout
operator|->
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
name|half
condition|;
operator|--
name|i
control|)
block|{
name|QGraphicsLayoutItem
modifier|*
name|item
init|=
name|m_layout
operator|->
name|itemAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|m_layout
operator|->
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|moveditems
operator|.
name|append
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|moveditems
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|m_layout
operator|->
name|addItem
argument_list|(
name|moveditems
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|i
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setColumnSpacing
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setColumnSpacing
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setRowSpacing
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|setRowSpacing
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|int
name|count
init|=
name|m_layout
operator|->
name|count
argument_list|()
operator|/
literal|2
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|m_layout
operator|->
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
name|i
operator|>=
name|count
condition|)
name|moveditems
operator|.
name|append
argument_list|(
name|m_layout
operator|->
name|itemAt
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|moveditems
operator|.
name|insert
argument_list|(
name|moveditems
operator|.
name|begin
argument_list|()
argument_list|,
name|m_layout
operator|->
name|itemAt
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|m_layout
operator|->
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|moveditems
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|m_layout
operator|->
name|addItem
argument_list|(
name|moveditems
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|m_layout
operator|->
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
name|resizeContents
argument_list|(
name|q
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|resizeScrollBars
argument_list|()
expr_stmt|;
name|q
operator|->
name|setListItemCaching
argument_list|(
name|cache
argument_list|)
expr_stmt|;
block|}
DECL|function|twoColumns
name|bool
name|twoColumns
parameter_list|()
block|{
return|return
name|m_twoColumns
return|;
block|}
DECL|member|m_content
name|QGraphicsWidget
modifier|*
name|m_content
decl_stmt|;
DECL|member|m_layout
name|QGraphicsGridLayout
modifier|*
name|m_layout
decl_stmt|;
DECL|member|m_twoColumns
name|bool
name|m_twoColumns
decl_stmt|;
DECL|member|q_ptr
name|SimpleListView
modifier|*
name|q_ptr
decl_stmt|;
DECL|member|m_listItemCaching
name|bool
name|m_listItemCaching
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|SimpleListView
name|SimpleListView
operator|::
name|SimpleListView
parameter_list|(
name|QGraphicsWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|AbstractScrollArea
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|SimpleListViewPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|)
expr_stmt|;
name|setContentsMargins
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|verticalScrollBar
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
name|horizontalScrollBar
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~SimpleListView
name|SimpleListView
operator|::
name|~
name|SimpleListView
parameter_list|()
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_content
condition|)
block|{
name|d
operator|->
name|m_content
operator|->
name|setParentItem
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|addItem
name|void
name|SimpleListView
operator|::
name|addItem
parameter_list|(
name|QGraphicsWidget
modifier|*
name|item
parameter_list|)
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|insertItem
argument_list|(
name|d
operator|->
name|m_layout
operator|->
name|count
argument_list|()
argument_list|,
name|item
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertItem
name|void
name|SimpleListView
operator|::
name|insertItem
parameter_list|(
name|int
name|index
parameter_list|,
name|QGraphicsWidget
modifier|*
name|item
parameter_list|)
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
comment|// Grid layout doe not have insert item method.
comment|// We need to first remove all items, add new item and
comment|// append old items to layout.
name|QList
argument_list|<
name|QGraphicsLayoutItem
modifier|*
argument_list|>
name|moveditems
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|d
operator|->
name|m_layout
operator|->
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
name|index
condition|;
operator|--
name|i
control|)
block|{
name|moveditems
operator|.
name|append
argument_list|(
name|d
operator|->
name|m_layout
operator|->
name|itemAt
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|m_layout
operator|->
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|moveditems
operator|.
name|append
argument_list|(
name|item
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|moveditems
operator|.
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
name|d
operator|->
name|m_layout
operator|->
name|addItem
argument_list|(
name|moveditems
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|d
operator|->
name|m_layout
operator|->
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|ListItemCache
modifier|*
name|cache
init|=
operator|new
name|ListItemCache
decl_stmt|;
name|item
operator|->
name|setGraphicsEffect
argument_list|(
name|cache
argument_list|)
expr_stmt|;
name|cache
operator|->
name|setEnabled
argument_list|(
name|listItemCaching
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|resizeScrollBars
argument_list|()
expr_stmt|;
name|d
operator|->
name|updateListItemBackgrounds
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|takeItem
name|QGraphicsWidget
modifier|*
name|SimpleListView
operator|::
name|takeItem
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
name|QGraphicsWidget
modifier|*
name|item
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|index
operator|>=
literal|0
operator|&&
name|d
operator|->
name|m_layout
operator|->
name|count
argument_list|()
operator|>
name|index
condition|)
block|{
name|QList
argument_list|<
name|QGraphicsLayoutItem
modifier|*
argument_list|>
name|moveditems
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|d
operator|->
name|m_layout
operator|->
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
if|if
condition|(
name|index
operator|!=
name|i
condition|)
name|moveditems
operator|.
name|insert
argument_list|(
name|moveditems
operator|.
name|begin
argument_list|()
argument_list|,
name|d
operator|->
name|m_layout
operator|->
name|itemAt
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
else|else
block|{
name|item
operator|=
cast|static_cast
argument_list|<
name|QGraphicsWidget
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|m_layout
operator|->
name|itemAt
argument_list|(
name|index
argument_list|)
argument_list|)
expr_stmt|;
name|item
operator|->
name|setGraphicsEffect
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|m_layout
operator|->
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|moveditems
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|d
operator|->
name|m_layout
operator|->
name|addItem
argument_list|(
name|moveditems
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|d
operator|->
name|m_layout
operator|->
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|resizeScrollBars
argument_list|()
expr_stmt|;
return|return
name|item
return|;
block|}
end_function
begin_function
DECL|function|itemAt
name|QGraphicsWidget
modifier|*
name|SimpleListView
operator|::
name|itemAt
parameter_list|(
name|int
name|row
parameter_list|)
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
name|QGraphicsWidget
modifier|*
name|item
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|row
operator|>=
literal|0
operator|&&
name|d
operator|->
name|m_layout
operator|->
name|count
argument_list|()
operator|>
name|row
condition|)
block|{
name|item
operator|=
cast|static_cast
argument_list|<
name|QGraphicsWidget
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|m_layout
operator|->
name|itemAt
argument_list|(
name|row
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|item
return|;
block|}
end_function
begin_function
DECL|function|itemCount
name|int
name|SimpleListView
operator|::
name|itemCount
parameter_list|()
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|m_layout
operator|->
name|count
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|listItemCaching
name|bool
name|SimpleListView
operator|::
name|listItemCaching
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|SimpleListView
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|m_listItemCaching
return|;
block|}
end_function
begin_function
DECL|function|setListItemCaching
name|void
name|SimpleListView
operator|::
name|setListItemCaching
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_listItemCaching
operator|==
name|enabled
condition|)
return|return;
name|d
operator|->
name|m_listItemCaching
operator|=
name|enabled
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|m_layout
operator|->
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|ListItem
modifier|*
name|item
init|=
cast|static_cast
argument_list|<
name|ListItem
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|m_layout
operator|->
name|itemAt
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|ListItemCache
modifier|*
name|cache
init|=
cast|static_cast
argument_list|<
name|ListItemCache
operator|*
argument_list|>
argument_list|(
name|item
operator|->
name|graphicsEffect
argument_list|()
argument_list|)
decl_stmt|;
name|cache
operator|->
name|setEnabled
argument_list|(
name|enabled
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|scrollContentsBy
name|void
name|SimpleListView
operator|::
name|scrollContentsBy
parameter_list|(
name|qreal
name|dx
parameter_list|,
name|qreal
name|dy
parameter_list|)
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
argument|dx
argument_list|)
name|QRectF
name|contentRect
init|=
name|d
operator|->
name|m_content
operator|->
name|boundingRect
argument_list|()
decl_stmt|;
name|QRectF
name|viewportRect
init|=
name|viewport
argument_list|()
operator|->
name|boundingRect
argument_list|()
decl_stmt|;
name|QPointF
name|contentPos
init|=
name|d
operator|->
name|m_content
operator|->
name|pos
argument_list|()
decl_stmt|;
name|qreal
name|newy
init|=
name|contentPos
operator|.
name|y
argument_list|()
operator|-
name|dy
decl_stmt|;
name|qreal
name|miny
init|=
name|qMin
argument_list|(
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|,
operator|-
operator|(
name|contentRect
operator|.
name|height
argument_list|()
operator|-
name|viewportRect
operator|.
name|height
argument_list|()
operator|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|newy
operator|<
name|miny
condition|)
name|newy
operator|=
name|miny
expr_stmt|;
elseif|else
if|if
condition|(
name|newy
operator|>
literal|0
condition|)
name|newy
operator|=
literal|0.0
expr_stmt|;
name|d
operator|->
name|m_content
operator|->
name|setPos
argument_list|(
name|contentPos
operator|.
name|x
argument_list|()
argument_list|,
name|newy
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|SimpleListView
operator|::
name|resizeEvent
parameter_list|(
name|QGraphicsSceneResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
name|AbstractScrollArea
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|d
operator|->
name|resizeContents
argument_list|(
name|event
operator|->
name|newSize
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|resizeScrollBars
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizeHint
name|QSizeF
name|SimpleListView
operator|::
name|sizeHint
parameter_list|(
name|Qt
operator|::
name|SizeHint
name|which
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|constraint
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|SimpleListView
argument_list|)
expr_stmt|;
if|if
condition|(
name|which
operator|==
name|Qt
operator|::
name|PreferredSize
condition|)
return|return
name|d
operator|->
name|m_content
operator|->
name|size
argument_list|()
return|;
return|return
name|AbstractScrollArea
operator|::
name|sizeHint
argument_list|(
name|which
argument_list|,
name|constraint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|themeChange
name|void
name|SimpleListView
operator|::
name|themeChange
parameter_list|()
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
name|d
operator|->
name|updateListContents
argument_list|()
expr_stmt|;
name|d
operator|->
name|resizeScrollBars
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setTwoColumns
name|void
name|SimpleListView
operator|::
name|setTwoColumns
parameter_list|(
specifier|const
name|bool
name|twoColumns
parameter_list|)
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
name|d
operator|->
name|setTwoColumns
argument_list|(
name|twoColumns
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|twoColumns
name|bool
name|SimpleListView
operator|::
name|twoColumns
parameter_list|()
block|{
name|Q_D
argument_list|(
name|SimpleListView
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|twoColumns
argument_list|()
return|;
block|}
end_function
end_unit
