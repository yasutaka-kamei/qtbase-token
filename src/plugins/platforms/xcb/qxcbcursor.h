begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBCURSOR_H
end_ifndef
begin_define
DECL|macro|QXCBCURSOR_H
define|#
directive|define
name|QXCBCURSOR_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbObject
name|class
name|QXcbCursor
range|:
name|public
name|QXcbObject
decl_stmt|,
name|public
name|QPlatformCursor
block|{
name|public
label|:
name|QXcbCursor
argument_list|(
name|QXcbConnection
operator|*
name|conn
argument_list|,
name|QXcbScreen
operator|*
name|screen
argument_list|)
expr_stmt|;
operator|~
name|QXcbCursor
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|void
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|,
name|QWindow
modifier|*
name|widget
parameter_list|)
function_decl|;
endif|#
directive|endif
name|QPoint
name|pos
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
function_decl|;
specifier|static
name|void
name|queryPointer
parameter_list|(
name|QXcbConnection
modifier|*
name|c
parameter_list|,
name|xcb_window_t
modifier|*
name|rootWin
parameter_list|,
name|QPoint
modifier|*
name|pos
parameter_list|,
name|int
modifier|*
name|keybMask
init|=
literal|0
parameter_list|)
function_decl|;
name|private
label|:
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|xcb_cursor_t
name|createFontCursor
parameter_list|(
name|int
name|cshape
parameter_list|)
function_decl|;
name|xcb_cursor_t
name|createBitmapCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|)
function_decl|;
name|xcb_cursor_t
name|createNonStandardCursor
parameter_list|(
name|int
name|cshape
parameter_list|)
function_decl|;
endif|#
directive|endif
name|QXcbScreen
modifier|*
name|m_screen
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QMap
operator|<
name|int
operator|,
name|xcb_cursor_t
operator|>
name|m_shapeCursorMap
expr_stmt|;
name|QMap
operator|<
name|qint64
operator|,
name|xcb_cursor_t
operator|>
name|m_bitmapCursorMap
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
