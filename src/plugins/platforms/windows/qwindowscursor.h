begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSCURSOR_H
end_ifndef
begin_define
DECL|macro|QWINDOWSCURSOR_H
define|#
directive|define
name|QWINDOWSCURSOR_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedDataPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindowsWindowCursorData
name|class
name|QWindowsWindowCursorData
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QWindowsCursorCacheKey
struct|struct
name|QWindowsCursorCacheKey
block|{
name|explicit
name|QWindowsCursorCacheKey
parameter_list|(
specifier|const
name|QCursor
modifier|&
name|c
parameter_list|)
function_decl|;
DECL|function|QWindowsCursorCacheKey
name|explicit
name|QWindowsCursorCacheKey
argument_list|(
name|Qt
operator|::
name|CursorShape
name|s
argument_list|)
range|:
name|shape
argument_list|(
name|s
argument_list|)
decl_stmt|,
name|bitmapCacheKey
argument_list|(
literal|0
argument_list|)
decl_stmt|,
name|maskCacheKey
argument_list|(
literal|0
argument_list|)
block|{}
DECL|function|QWindowsCursorCacheKey
name|QWindowsCursorCacheKey
argument_list|()
operator|:
name|shape
argument_list|(
name|Qt
operator|::
name|CustomCursor
argument_list|)
operator|,
name|bitmapCacheKey
argument_list|(
literal|0
argument_list|)
operator|,
name|maskCacheKey
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|shape
name|Qt
operator|::
name|CursorShape
name|shape
expr_stmt|;
DECL|member|bitmapCacheKey
name|qint64
name|bitmapCacheKey
decl_stmt|;
DECL|member|maskCacheKey
name|qint64
name|maskCacheKey
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QWindowsCursorCacheKey
operator|&
name|k1
operator|,
specifier|const
name|QWindowsCursorCacheKey
operator|&
name|k2
operator|)
block|{
return|return
name|k1
operator|.
name|shape
operator|==
name|k2
operator|.
name|shape
operator|&&
name|k1
operator|.
name|bitmapCacheKey
operator|==
name|k2
operator|.
name|bitmapCacheKey
operator|&&
name|k1
operator|.
name|maskCacheKey
operator|==
name|k2
operator|.
name|maskCacheKey
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QWindowsCursorCacheKey
modifier|&
name|k
parameter_list|,
name|uint
name|seed
parameter_list|)
function|Q_DECL_NOTHROW
block|{
return|return
operator|(
name|uint
argument_list|(
name|k
operator|.
name|shape
argument_list|)
operator|+
name|uint
argument_list|(
name|k
operator|.
name|bitmapCacheKey
argument_list|)
operator|+
name|uint
argument_list|(
name|k
operator|.
name|maskCacheKey
argument_list|)
operator|)
operator|^
name|seed
return|;
block|}
end_function
begin_decl_stmt
name|class
name|QWindowsWindowCursor
block|{
name|public
label|:
name|QWindowsWindowCursor
argument_list|()
expr_stmt|;
name|explicit
name|QWindowsWindowCursor
parameter_list|(
specifier|const
name|QCursor
modifier|&
name|c
parameter_list|)
function_decl|;
operator|~
name|QWindowsWindowCursor
argument_list|()
expr_stmt|;
name|QWindowsWindowCursor
argument_list|(
specifier|const
name|QWindowsWindowCursor
operator|&
name|c
argument_list|)
expr_stmt|;
name|QWindowsWindowCursor
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QWindowsWindowCursor
operator|&
name|c
operator|)
decl_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|QCursor
name|cursor
argument_list|()
specifier|const
expr_stmt|;
name|HCURSOR
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QWindowsWindowCursorData
operator|>
name|m_data
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QWindowsCursor
range|:
name|public
name|QPlatformCursor
block|{
name|public
operator|:
expr|enum
name|CursorState
block|{
name|CursorShowing
block|,
name|CursorHidden
block|,
name|CursorSuppressed
comment|// Cursor suppressed by touch interaction (Windows 8).
block|}
block|;
name|QWindowsCursor
argument_list|()
block|{}
name|virtual
name|void
name|changeCursor
argument_list|(
name|QCursor
operator|*
name|widgetCursor
argument_list|,
name|QWindow
operator|*
name|widget
argument_list|)
block|;
name|virtual
name|QPoint
name|pos
argument_list|()
specifier|const
block|{
return|return
name|mousePosition
argument_list|()
return|;
block|}
name|virtual
name|void
name|setPos
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
specifier|static
name|HCURSOR
name|createPixmapCursor
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
specifier|const
name|QPoint
operator|&
name|hotSpot
argument_list|)
block|;
specifier|static
name|HCURSOR
name|createSystemCursor
argument_list|(
specifier|const
name|QCursor
operator|&
name|c
argument_list|)
block|;
specifier|static
name|QCursor
name|customCursor
argument_list|(
argument|Qt::CursorShape cursorShape
argument_list|)
block|;
specifier|static
name|QPoint
name|mousePosition
argument_list|()
block|;
specifier|static
name|CursorState
name|cursorState
argument_list|()
block|;
name|QWindowsWindowCursor
name|standardWindowCursor
argument_list|(
argument|Qt::CursorShape s = Qt::ArrowCursor
argument_list|)
block|;
name|QWindowsWindowCursor
name|pixmapWindowCursor
argument_list|(
specifier|const
name|QCursor
operator|&
name|c
argument_list|)
block|;
name|private
operator|:
typedef|typedef
name|QHash
operator|<
name|QWindowsCursorCacheKey
operator|,
name|QWindowsWindowCursor
operator|>
name|CursorCache
expr_stmt|;
name|CursorCache
name|m_cursorCache
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSCURSOR_H
end_comment
end_unit
