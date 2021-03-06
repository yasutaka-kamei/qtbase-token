begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"treewalker.h"
end_include
begin_include
include|#
directive|include
file|"ui4.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|acceptUI
name|void
name|TreeWalker
operator|::
name|acceptUI
parameter_list|(
name|DomUI
modifier|*
name|ui
parameter_list|)
block|{
name|acceptWidget
argument_list|(
name|ui
operator|->
name|elementWidget
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
specifier|const
name|DomButtonGroups
modifier|*
name|domButtonGroups
init|=
name|ui
operator|->
name|elementButtonGroups
argument_list|()
condition|)
name|acceptButtonGroups
argument_list|(
name|domButtonGroups
argument_list|)
expr_stmt|;
name|acceptTabStops
argument_list|(
name|ui
operator|->
name|elementTabStops
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|ui
operator|->
name|elementImages
argument_list|()
condition|)
name|acceptImages
argument_list|(
name|ui
operator|->
name|elementImages
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptLayoutDefault
name|void
name|TreeWalker
operator|::
name|acceptLayoutDefault
parameter_list|(
name|DomLayoutDefault
modifier|*
name|layoutDefault
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|layoutDefault
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptLayoutFunction
name|void
name|TreeWalker
operator|::
name|acceptLayoutFunction
parameter_list|(
name|DomLayoutFunction
modifier|*
name|layoutFunction
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|layoutFunction
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptTabStops
name|void
name|TreeWalker
operator|::
name|acceptTabStops
parameter_list|(
name|DomTabStops
modifier|*
name|tabStops
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|tabStops
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptLayout
name|void
name|TreeWalker
operator|::
name|acceptLayout
parameter_list|(
name|DomLayout
modifier|*
name|layout
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|layout
operator|->
name|elementProperty
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptProperty
argument_list|(
name|layout
operator|->
name|elementProperty
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
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
name|layout
operator|->
name|elementItem
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptLayoutItem
argument_list|(
name|layout
operator|->
name|elementItem
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptLayoutItem
name|void
name|TreeWalker
operator|::
name|acceptLayoutItem
parameter_list|(
name|DomLayoutItem
modifier|*
name|layoutItem
parameter_list|)
block|{
switch|switch
condition|(
name|layoutItem
operator|->
name|kind
argument_list|()
condition|)
block|{
case|case
name|DomLayoutItem
operator|::
name|Widget
case|:
name|acceptWidget
argument_list|(
name|layoutItem
operator|->
name|elementWidget
argument_list|()
argument_list|)
expr_stmt|;
return|return;
case|case
name|DomLayoutItem
operator|::
name|Layout
case|:
name|acceptLayout
argument_list|(
name|layoutItem
operator|->
name|elementLayout
argument_list|()
argument_list|)
expr_stmt|;
return|return;
case|case
name|DomLayoutItem
operator|::
name|Spacer
case|:
name|acceptSpacer
argument_list|(
name|layoutItem
operator|->
name|elementSpacer
argument_list|()
argument_list|)
expr_stmt|;
return|return;
case|case
name|DomLayoutItem
operator|::
name|Unknown
case|:
break|break;
block|}
name|Q_ASSERT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptWidget
name|void
name|TreeWalker
operator|::
name|acceptWidget
parameter_list|(
name|DomWidget
modifier|*
name|widget
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|widget
operator|->
name|elementAction
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptAction
argument_list|(
name|widget
operator|->
name|elementAction
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
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
name|widget
operator|->
name|elementActionGroup
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptActionGroup
argument_list|(
name|widget
operator|->
name|elementActionGroup
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
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
name|widget
operator|->
name|elementAddAction
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptActionRef
argument_list|(
name|widget
operator|->
name|elementAddAction
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
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
name|widget
operator|->
name|elementProperty
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptProperty
argument_list|(
name|widget
operator|->
name|elementProperty
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
comment|// recurse down
name|DomWidgets
name|childWidgets
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
name|widget
operator|->
name|elementWidget
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|DomWidget
modifier|*
name|child
init|=
name|widget
operator|->
name|elementWidget
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|childWidgets
operator|+=
name|child
expr_stmt|;
name|acceptWidget
argument_list|(
name|child
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|widget
operator|->
name|elementLayout
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|acceptLayout
argument_list|(
name|widget
operator|->
name|elementLayout
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|DomScripts
name|scripts
argument_list|(
name|widget
operator|->
name|elementScript
argument_list|()
argument_list|)
decl_stmt|;
name|acceptWidgetScripts
argument_list|(
name|scripts
argument_list|,
name|widget
argument_list|,
name|childWidgets
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptSpacer
name|void
name|TreeWalker
operator|::
name|acceptSpacer
parameter_list|(
name|DomSpacer
modifier|*
name|spacer
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|spacer
operator|->
name|elementProperty
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptProperty
argument_list|(
name|spacer
operator|->
name|elementProperty
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptColor
name|void
name|TreeWalker
operator|::
name|acceptColor
parameter_list|(
name|DomColor
modifier|*
name|color
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|color
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptColorGroup
name|void
name|TreeWalker
operator|::
name|acceptColorGroup
parameter_list|(
name|DomColorGroup
modifier|*
name|colorGroup
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|colorGroup
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptPalette
name|void
name|TreeWalker
operator|::
name|acceptPalette
parameter_list|(
name|DomPalette
modifier|*
name|palette
parameter_list|)
block|{
name|acceptColorGroup
argument_list|(
name|palette
operator|->
name|elementActive
argument_list|()
argument_list|)
expr_stmt|;
name|acceptColorGroup
argument_list|(
name|palette
operator|->
name|elementInactive
argument_list|()
argument_list|)
expr_stmt|;
name|acceptColorGroup
argument_list|(
name|palette
operator|->
name|elementDisabled
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptFont
name|void
name|TreeWalker
operator|::
name|acceptFont
parameter_list|(
name|DomFont
modifier|*
name|font
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|font
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptPoint
name|void
name|TreeWalker
operator|::
name|acceptPoint
parameter_list|(
name|DomPoint
modifier|*
name|point
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|point
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptRect
name|void
name|TreeWalker
operator|::
name|acceptRect
parameter_list|(
name|DomRect
modifier|*
name|rect
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptSizePolicy
name|void
name|TreeWalker
operator|::
name|acceptSizePolicy
parameter_list|(
name|DomSizePolicy
modifier|*
name|sizePolicy
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptSize
name|void
name|TreeWalker
operator|::
name|acceptSize
parameter_list|(
name|DomSize
modifier|*
name|size
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptDate
name|void
name|TreeWalker
operator|::
name|acceptDate
parameter_list|(
name|DomDate
modifier|*
name|date
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|date
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptTime
name|void
name|TreeWalker
operator|::
name|acceptTime
parameter_list|(
name|DomTime
modifier|*
name|time
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|time
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptDateTime
name|void
name|TreeWalker
operator|::
name|acceptDateTime
parameter_list|(
name|DomDateTime
modifier|*
name|dateTime
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|dateTime
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptProperty
name|void
name|TreeWalker
operator|::
name|acceptProperty
parameter_list|(
name|DomProperty
modifier|*
name|property
parameter_list|)
block|{
switch|switch
condition|(
name|property
operator|->
name|kind
argument_list|()
condition|)
block|{
case|case
name|DomProperty
operator|::
name|Bool
case|:
case|case
name|DomProperty
operator|::
name|Color
case|:
case|case
name|DomProperty
operator|::
name|Cstring
case|:
case|case
name|DomProperty
operator|::
name|Cursor
case|:
case|case
name|DomProperty
operator|::
name|CursorShape
case|:
case|case
name|DomProperty
operator|::
name|Enum
case|:
case|case
name|DomProperty
operator|::
name|Font
case|:
case|case
name|DomProperty
operator|::
name|Pixmap
case|:
case|case
name|DomProperty
operator|::
name|IconSet
case|:
case|case
name|DomProperty
operator|::
name|Palette
case|:
case|case
name|DomProperty
operator|::
name|Point
case|:
case|case
name|DomProperty
operator|::
name|PointF
case|:
case|case
name|DomProperty
operator|::
name|Rect
case|:
case|case
name|DomProperty
operator|::
name|RectF
case|:
case|case
name|DomProperty
operator|::
name|Set
case|:
case|case
name|DomProperty
operator|::
name|Locale
case|:
case|case
name|DomProperty
operator|::
name|SizePolicy
case|:
case|case
name|DomProperty
operator|::
name|Size
case|:
case|case
name|DomProperty
operator|::
name|SizeF
case|:
case|case
name|DomProperty
operator|::
name|String
case|:
case|case
name|DomProperty
operator|::
name|Number
case|:
case|case
name|DomProperty
operator|::
name|LongLong
case|:
case|case
name|DomProperty
operator|::
name|Char
case|:
case|case
name|DomProperty
operator|::
name|Date
case|:
case|case
name|DomProperty
operator|::
name|Time
case|:
case|case
name|DomProperty
operator|::
name|DateTime
case|:
case|case
name|DomProperty
operator|::
name|Url
case|:
case|case
name|DomProperty
operator|::
name|Unknown
case|:
case|case
name|DomProperty
operator|::
name|StringList
case|:
case|case
name|DomProperty
operator|::
name|Float
case|:
case|case
name|DomProperty
operator|::
name|Double
case|:
case|case
name|DomProperty
operator|::
name|UInt
case|:
case|case
name|DomProperty
operator|::
name|ULongLong
case|:
case|case
name|DomProperty
operator|::
name|Brush
case|:
break|break;
block|}
block|}
end_function
begin_function
DECL|function|acceptCustomWidgets
name|void
name|TreeWalker
operator|::
name|acceptCustomWidgets
parameter_list|(
name|DomCustomWidgets
modifier|*
name|customWidgets
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|customWidgets
operator|->
name|elementCustomWidget
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptCustomWidget
argument_list|(
name|customWidgets
operator|->
name|elementCustomWidget
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptCustomWidget
name|void
name|TreeWalker
operator|::
name|acceptCustomWidget
parameter_list|(
name|DomCustomWidget
modifier|*
name|customWidget
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|customWidget
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptAction
name|void
name|TreeWalker
operator|::
name|acceptAction
parameter_list|(
name|DomAction
modifier|*
name|action
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|action
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptActionGroup
name|void
name|TreeWalker
operator|::
name|acceptActionGroup
parameter_list|(
name|DomActionGroup
modifier|*
name|actionGroup
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|actionGroup
operator|->
name|elementAction
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptAction
argument_list|(
name|actionGroup
operator|->
name|elementAction
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
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
name|actionGroup
operator|->
name|elementActionGroup
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptActionGroup
argument_list|(
name|actionGroup
operator|->
name|elementActionGroup
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptActionRef
name|void
name|TreeWalker
operator|::
name|acceptActionRef
parameter_list|(
name|DomActionRef
modifier|*
name|actionRef
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|actionRef
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptImages
name|void
name|TreeWalker
operator|::
name|acceptImages
parameter_list|(
name|DomImages
modifier|*
name|images
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|images
operator|->
name|elementImage
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptImage
argument_list|(
name|images
operator|->
name|elementImage
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptImage
name|void
name|TreeWalker
operator|::
name|acceptImage
parameter_list|(
name|DomImage
modifier|*
name|image
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|image
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptIncludes
name|void
name|TreeWalker
operator|::
name|acceptIncludes
parameter_list|(
name|DomIncludes
modifier|*
name|includes
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|includes
operator|->
name|elementInclude
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptInclude
argument_list|(
name|includes
operator|->
name|elementInclude
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptInclude
name|void
name|TreeWalker
operator|::
name|acceptInclude
parameter_list|(
name|DomInclude
modifier|*
name|incl
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|incl
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptConnections
name|void
name|TreeWalker
operator|::
name|acceptConnections
parameter_list|(
name|DomConnections
modifier|*
name|connections
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|connections
operator|->
name|elementConnection
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptConnection
argument_list|(
name|connections
operator|->
name|elementConnection
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptConnection
name|void
name|TreeWalker
operator|::
name|acceptConnection
parameter_list|(
name|DomConnection
modifier|*
name|connection
parameter_list|)
block|{
name|acceptConnectionHints
argument_list|(
name|connection
operator|->
name|elementHints
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptConnectionHints
name|void
name|TreeWalker
operator|::
name|acceptConnectionHints
parameter_list|(
name|DomConnectionHints
modifier|*
name|connectionHints
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|connectionHints
operator|->
name|elementHint
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|acceptConnectionHint
argument_list|(
name|connectionHints
operator|->
name|elementHint
argument_list|()
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptConnectionHint
name|void
name|TreeWalker
operator|::
name|acceptConnectionHint
parameter_list|(
name|DomConnectionHint
modifier|*
name|connectionHint
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|connectionHint
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptWidgetScripts
name|void
name|TreeWalker
operator|::
name|acceptWidgetScripts
parameter_list|(
specifier|const
name|DomScripts
modifier|&
parameter_list|,
name|DomWidget
modifier|*
parameter_list|,
specifier|const
name|DomWidgets
modifier|&
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|acceptButtonGroups
name|void
name|TreeWalker
operator|::
name|acceptButtonGroups
parameter_list|(
specifier|const
name|DomButtonGroups
modifier|*
name|domButtonGroups
parameter_list|)
block|{
typedef|typedef
name|QList
argument_list|<
name|DomButtonGroup
modifier|*
argument_list|>
name|DomButtonGroupList
typedef|;
specifier|const
name|DomButtonGroupList
name|domGroups
init|=
name|domButtonGroups
operator|->
name|elementButtonGroup
argument_list|()
decl_stmt|;
specifier|const
name|DomButtonGroupList
operator|::
name|const_iterator
name|cend
init|=
name|domGroups
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
name|DomButtonGroupList
operator|::
name|const_iterator
name|it
init|=
name|domGroups
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|cend
condition|;
operator|++
name|it
control|)
name|acceptButtonGroup
argument_list|(
operator|*
name|it
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptButtonGroup
name|void
name|TreeWalker
operator|::
name|acceptButtonGroup
parameter_list|(
specifier|const
name|DomButtonGroup
modifier|*
parameter_list|)
block|{ }
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
