begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPALETTE_H
end_ifndef
begin_define
DECL|macro|QPALETTE_H
define|#
directive|define
name|QPALETTE_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qbrush.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPalettePrivate
name|class
name|QPalettePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPalette
block|{
name|Q_GADGET
name|public
range|:
name|QPalette
argument_list|()
decl_stmt|;
name|QPalette
argument_list|(
specifier|const
name|QColor
operator|&
name|button
argument_list|)
expr_stmt|;
name|QPalette
argument_list|(
argument|Qt::GlobalColor button
argument_list|)
empty_stmt|;
name|QPalette
argument_list|(
specifier|const
name|QColor
operator|&
name|button
argument_list|,
specifier|const
name|QColor
operator|&
name|window
argument_list|)
expr_stmt|;
name|QPalette
argument_list|(
specifier|const
name|QBrush
operator|&
name|windowText
argument_list|,
specifier|const
name|QBrush
operator|&
name|button
argument_list|,
specifier|const
name|QBrush
operator|&
name|light
argument_list|,
specifier|const
name|QBrush
operator|&
name|dark
argument_list|,
specifier|const
name|QBrush
operator|&
name|mid
argument_list|,
specifier|const
name|QBrush
operator|&
name|text
argument_list|,
specifier|const
name|QBrush
operator|&
name|bright_text
argument_list|,
specifier|const
name|QBrush
operator|&
name|base
argument_list|,
specifier|const
name|QBrush
operator|&
name|window
argument_list|)
expr_stmt|;
name|QPalette
argument_list|(
specifier|const
name|QColor
operator|&
name|windowText
argument_list|,
specifier|const
name|QColor
operator|&
name|window
argument_list|,
specifier|const
name|QColor
operator|&
name|light
argument_list|,
specifier|const
name|QColor
operator|&
name|dark
argument_list|,
specifier|const
name|QColor
operator|&
name|mid
argument_list|,
specifier|const
name|QColor
operator|&
name|text
argument_list|,
specifier|const
name|QColor
operator|&
name|base
argument_list|)
expr_stmt|;
name|QPalette
argument_list|(
specifier|const
name|QPalette
operator|&
name|palette
argument_list|)
expr_stmt|;
operator|~
name|QPalette
argument_list|()
expr_stmt|;
name|QPalette
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QPalette
operator|&
name|palette
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QPalette
argument_list|(
argument|QPalette&&other
argument_list|)
name|Q_DECL_NOTHROW
label|:
name|d
argument_list|(
name|other
operator|.
name|d
argument_list|)
operator|,
name|data
argument_list|(
argument|other.data
argument_list|)
block|{
name|other
operator|.
name|d
operator|=
name|Q_NULLPTR
block|; }
specifier|inline
name|QPalette
operator|&
name|operator
operator|=
operator|(
name|QPalette
operator|&&
name|other
operator|)
name|Q_DECL_NOEXCEPT
block|{
name|for_faster_swapping_dont_use
operator|=
name|other
operator|.
name|for_faster_swapping_dont_use
block|;
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|void
name|swap
parameter_list|(
name|QPalette
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOEXCEPT
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
name|qSwap
argument_list|(
name|for_faster_swapping_dont_use
argument_list|,
name|other
operator|.
name|for_faster_swapping_dont_use
argument_list|)
expr_stmt|;
block|}
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
comment|// Do not change the order, the serialization format depends on it
enum|enum
name|ColorGroup
block|{
name|Active
block|,
name|Disabled
block|,
name|Inactive
block|,
name|NColorGroups
block|,
name|Current
block|,
name|All
block|,
name|Normal
init|=
name|Active
block|}
enum|;
name|Q_ENUM
argument_list|(
name|ColorGroup
argument_list|)
expr|enum
name|ColorRole
block|{
name|WindowText
block|,
name|Button
block|,
name|Light
block|,
name|Midlight
block|,
name|Dark
block|,
name|Mid
block|,
name|Text
block|,
name|BrightText
block|,
name|ButtonText
block|,
name|Base
block|,
name|Window
block|,
name|Shadow
block|,
name|Highlight
block|,
name|HighlightedText
block|,
name|Link
block|,
name|LinkVisited
block|,
name|AlternateBase
block|,
name|NoRole
block|,
name|ToolTipBase
block|,
name|ToolTipText
block|,
name|NColorRoles
operator|=
name|ToolTipText
operator|+
literal|1
block|,
name|Foreground
operator|=
name|WindowText
block|,
name|Background
operator|=
name|Window
block|}
expr_stmt|;
name|Q_ENUM
argument_list|(
argument|ColorRole
argument_list|)
specifier|inline
name|ColorGroup
name|currentColorGroup
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ColorGroup
operator|>
operator|(
name|data
operator|.
name|current_group
operator|)
return|;
block|}
specifier|inline
name|void
name|setCurrentColorGroup
parameter_list|(
name|ColorGroup
name|cg
parameter_list|)
block|{
name|data
operator|.
name|current_group
operator|=
name|cg
expr_stmt|;
block|}
specifier|inline
specifier|const
name|QColor
modifier|&
name|color
argument_list|(
name|ColorGroup
name|cg
argument_list|,
name|ColorRole
name|cr
argument_list|)
decl|const
block|{
return|return
name|brush
argument_list|(
name|cg
argument_list|,
name|cr
argument_list|)
operator|.
name|color
argument_list|()
return|;
block|}
specifier|const
name|QBrush
modifier|&
name|brush
argument_list|(
name|ColorGroup
name|cg
argument_list|,
name|ColorRole
name|cr
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|void
name|setColor
parameter_list|(
name|ColorGroup
name|cg
parameter_list|,
name|ColorRole
name|cr
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setColor
parameter_list|(
name|ColorRole
name|cr
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
function_decl|;
specifier|inline
name|void
name|setBrush
parameter_list|(
name|ColorRole
name|cr
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
function_decl|;
name|bool
name|isBrushSet
argument_list|(
name|ColorGroup
name|cg
argument_list|,
name|ColorRole
name|cr
argument_list|)
decl|const
decl_stmt|;
name|void
name|setBrush
parameter_list|(
name|ColorGroup
name|cg
parameter_list|,
name|ColorRole
name|cr
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|brush
parameter_list|)
function_decl|;
name|void
name|setColorGroup
parameter_list|(
name|ColorGroup
name|cr
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|windowText
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|button
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|light
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|dark
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|mid
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|bright_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|base
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|window
parameter_list|)
function_decl|;
name|bool
name|isEqual
argument_list|(
name|ColorGroup
name|cr1
argument_list|,
name|ColorGroup
name|cr2
argument_list|)
decl|const
decl_stmt|;
specifier|inline
specifier|const
name|QColor
modifier|&
name|color
argument_list|(
name|ColorRole
name|cr
argument_list|)
decl|const
block|{
return|return
name|color
argument_list|(
name|Current
argument_list|,
name|cr
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
modifier|&
name|brush
argument_list|(
name|ColorRole
name|cr
argument_list|)
decl|const
block|{
return|return
name|brush
argument_list|(
name|Current
argument_list|,
name|cr
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|foreground
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|WindowText
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|windowText
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|WindowText
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|button
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Button
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|light
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Light
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|dark
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Dark
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|mid
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Mid
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|text
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Text
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|base
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Base
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|alternateBase
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|AlternateBase
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|toolTipBase
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|ToolTipBase
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|toolTipText
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|ToolTipText
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|background
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Window
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|window
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Window
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|midlight
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Midlight
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|brightText
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|BrightText
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|buttonText
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|ButtonText
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|shadow
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Shadow
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|highlight
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Highlight
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|highlightedText
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|HighlightedText
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|link
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|Link
argument_list|)
return|;
block|}
specifier|inline
specifier|const
name|QBrush
operator|&
name|linkVisited
argument_list|()
specifier|const
block|{
return|return
name|brush
argument_list|(
name|LinkVisited
argument_list|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QPalette
operator|&
name|p
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QPalette
operator|&
name|p
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|operator
operator|==
operator|(
name|p
operator|)
operator|)
return|;
block|}
name|bool
name|isCopyOf
argument_list|(
specifier|const
name|QPalette
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|int
name|serialNumber
argument_list|()
specifier|const
block|{
return|return
name|cacheKey
argument_list|()
operator|>>
literal|32
return|;
block|}
endif|#
directive|endif
name|qint64
name|cacheKey
argument_list|()
specifier|const
expr_stmt|;
name|QPalette
name|resolve
argument_list|(
specifier|const
name|QPalette
operator|&
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|uint
name|resolve
argument_list|()
specifier|const
block|{
return|return
name|data
operator|.
name|resolve_mask
return|;
block|}
specifier|inline
name|void
name|resolve
parameter_list|(
name|uint
name|mask
parameter_list|)
block|{
name|data
operator|.
name|resolve_mask
operator|=
name|mask
expr_stmt|;
block|}
name|private
label|:
name|void
name|setColorGroup
parameter_list|(
name|ColorGroup
name|cr
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|windowText
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|button
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|light
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|dark
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|mid
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|bright_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|base
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|alternate_base
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|window
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|midlight
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|button_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|shadow
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|highlight
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|highlighted_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|link
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|link_visited
parameter_list|)
function_decl|;
name|void
name|setColorGroup
parameter_list|(
name|ColorGroup
name|cr
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|windowText
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|button
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|light
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|dark
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|mid
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|bright_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|base
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|alternate_base
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|window
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|midlight
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|button_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|shadow
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|highlight
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|highlighted_text
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|link
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|link_visited
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|toolTipBase
parameter_list|,
specifier|const
name|QBrush
modifier|&
name|toolTipText
parameter_list|)
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|detach
parameter_list|()
function_decl|;
name|QPalettePrivate
modifier|*
name|d
decl_stmt|;
struct|struct
name|Data
block|{
name|uint
name|current_group
range|:
literal|4
decl_stmt|;
name|uint
name|resolve_mask
range|:
literal|28
decl_stmt|;
block|}
struct|;
union|union
block|{
name|Data
name|data
decl_stmt|;
name|quint32
name|for_faster_swapping_dont_use
decl_stmt|;
block|}
union|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|s
operator|,
specifier|const
name|QPalette
operator|&
name|p
operator|)
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QPalette
argument_list|)
end_macro
begin_expr_stmt
specifier|inline
name|void
name|QPalette
operator|::
name|setColor
argument_list|(
argument|ColorGroup acg
argument_list|,
argument|ColorRole acr
argument_list|,
argument|const QColor&acolor
argument_list|)
block|{
name|setBrush
argument_list|(
name|acg
argument_list|,
name|acr
argument_list|,
name|QBrush
argument_list|(
name|acolor
argument_list|)
argument_list|)
block|; }
DECL|function|setColor
specifier|inline
name|void
name|QPalette
operator|::
name|setColor
argument_list|(
argument|ColorRole acr
argument_list|,
argument|const QColor&acolor
argument_list|)
block|{
name|setColor
argument_list|(
name|All
argument_list|,
name|acr
argument_list|,
name|acolor
argument_list|)
block|; }
DECL|function|setBrush
specifier|inline
name|void
name|QPalette
operator|::
name|setBrush
argument_list|(
argument|ColorRole acr
argument_list|,
argument|const QBrush&abrush
argument_list|)
block|{
name|setBrush
argument_list|(
name|All
argument_list|,
name|acr
argument_list|,
name|abrush
argument_list|)
block|; }
comment|/*****************************************************************************   QPalette stream functions  *****************************************************************************/
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|ds
operator|,
specifier|const
name|QPalette
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|ds
operator|,
name|QPalette
operator|&
name|p
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QPalette
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPALETTE_H
end_comment
end_unit
