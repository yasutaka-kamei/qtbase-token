begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINRTCURSOR_H
end_ifndef
begin_define
DECL|macro|QWINRTCURSOR_H
define|#
directive|define
name|QWINRTCURSOR_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_decl_stmt
name|namespace
name|ABI
block|{
name|namespace
name|Windows
block|{
name|namespace
name|UI
block|{
name|namespace
name|Core
block|{
struct_decl|struct
name|ICoreWindow
struct_decl|;
struct_decl|struct
name|ICoreCursorFactory
struct_decl|;
block|}
block|}
block|}
block|}
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QWinRTCursor
range|:
name|public
name|QPlatformCursor
block|{
name|public
operator|:
name|explicit
name|QWinRTCursor
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QWinRTCursor
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|void
name|changeCursor
argument_list|(
name|QCursor
operator|*
name|windowCursor
argument_list|,
name|QWindow
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|QPoint
name|pos
argument_list|()
specifier|const
block|;
name|private
operator|:
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
name|m_window
block|;
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreCursorFactory
operator|*
name|m_cursorFactory
block|; }
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
comment|// QWINRTCURSOR_H
end_comment
end_unit
