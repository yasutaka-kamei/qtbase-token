begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBEGLWINDOW_H
end_ifndef
begin_define
DECL|macro|QXCBEGLWINDOW_H
define|#
directive|define
name|QXCBEGLWINDOW_H
end_define
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxcbeglinclude.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbEglIntegration
name|class
name|QXcbEglIntegration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXcbEglWindow
range|:
name|public
name|QXcbWindow
block|{
name|public
operator|:
name|QXcbEglWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
name|QXcbEglIntegration
operator|*
name|glIntegration
argument_list|)
block|;
operator|~
name|QXcbEglWindow
argument_list|()
block|;
name|EGLSurface
name|eglSurface
argument_list|()
specifier|const
block|{
return|return
name|m_surface
return|;
block|}
name|QXcbEglIntegration
operator|*
name|glIntegration
argument_list|()
specifier|const
block|{
return|return
name|m_glIntegration
return|;
block|}
name|protected
operator|:
name|void
name|create
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|resolveFormat
argument_list|(
argument|const QSurfaceFormat&format
argument_list|)
name|Q_DECL_OVERRIDE
block|;
ifdef|#
directive|ifdef
name|XCB_USE_XLIB
specifier|const
name|xcb_visualtype_t
operator|*
name|createVisual
argument_list|()
name|Q_DECL_OVERRIDE
block|;
endif|#
directive|endif
name|private
operator|:
name|QXcbEglIntegration
operator|*
name|m_glIntegration
block|;
name|EGLConfig
name|m_config
block|;
name|EGLSurface
name|m_surface
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
comment|//QXCBEGLWINDOW_H
end_comment
end_unit
