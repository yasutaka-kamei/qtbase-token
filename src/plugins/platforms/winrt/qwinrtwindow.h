begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINRTWINDOW_H
end_ifndef
begin_define
DECL|macro|QWINRTWINDOW_H
define|#
directive|define
name|QWINRTWINDOW_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWinRTWindowPrivate
name|class
name|QWinRTWindowPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWinRTWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
name|QWinRTWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QWinRTWindow
argument_list|()
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|bool
name|isActive
argument_list|()
specifier|const
block|;
name|bool
name|isExposed
argument_list|()
specifier|const
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
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|setWindowTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|void
name|raise
argument_list|()
block|;
name|void
name|lower
argument_list|()
block|;
name|WId
name|winId
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|EGLSurface
name|eglSurface
argument_list|()
specifier|const
block|;
name|void
name|createEglSurface
argument_list|(
argument|EGLDisplay display
argument_list|,
argument|EGLConfig config
argument_list|)
block|;
name|private
operator|:
name|QScopedPointer
operator|<
name|QWinRTWindowPrivate
operator|>
name|d_ptr
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWinRTWindow
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
comment|// QWINRTWINDOW_H
end_comment
end_unit
