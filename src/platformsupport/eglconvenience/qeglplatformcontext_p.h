begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLPLATFORMCONTEXT_H
end_ifndef
begin_define
DECL|macro|QEGLPLATFORMCONTEXT_H
define|#
directive|define
name|QEGLPLATFORMCONTEXT_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QEGLPlatformContext
range|:
name|public
name|QPlatformOpenGLContext
block|{
name|public
operator|:
name|QEGLPlatformContext
argument_list|(
argument|const QSurfaceFormat&format
argument_list|,
argument|QPlatformOpenGLContext *share
argument_list|,
argument|EGLDisplay display
argument_list|,
argument|EGLConfig *config =
literal|0
argument_list|,
argument|const QVariant&nativeHandle = QVariant()
argument_list|)
block|;
operator|~
name|QEGLPlatformContext
argument_list|()
block|;
name|void
name|initialize
argument_list|()
block|;
name|bool
name|makeCurrent
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
block|;
name|void
name|doneCurrent
argument_list|()
block|;
name|void
name|swapBuffers
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
block|;
name|void
argument_list|(
operator|*
name|getProcAddress
argument_list|(
specifier|const
name|QByteArray
operator|&
name|procName
argument_list|)
argument_list|)
argument_list|()
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|bool
name|isSharing
argument_list|()
specifier|const
block|{
return|return
name|m_shareContext
operator|!=
name|EGL_NO_CONTEXT
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|m_eglContext
operator|!=
name|EGL_NO_CONTEXT
return|;
block|}
name|EGLContext
name|eglContext
argument_list|()
specifier|const
block|;
name|EGLDisplay
name|eglDisplay
argument_list|()
specifier|const
block|;
name|EGLConfig
name|eglConfig
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|virtual
name|EGLSurface
name|eglSurfaceForPlatformSurface
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|EGLSurface
name|createTemporaryOffscreenSurface
argument_list|()
block|;
name|virtual
name|void
name|destroyTemporaryOffscreenSurface
argument_list|(
argument|EGLSurface surface
argument_list|)
block|;
name|private
operator|:
name|void
name|init
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|,
name|QPlatformOpenGLContext
operator|*
name|share
argument_list|)
block|;
name|void
name|adopt
argument_list|(
specifier|const
name|QVariant
operator|&
name|nativeHandle
argument_list|,
name|QPlatformOpenGLContext
operator|*
name|share
argument_list|)
block|;
name|void
name|updateFormatFromGL
argument_list|()
block|;
name|EGLContext
name|m_eglContext
block|;
name|EGLContext
name|m_shareContext
block|;
name|EGLDisplay
name|m_eglDisplay
block|;
name|EGLConfig
name|m_eglConfig
block|;
name|QSurfaceFormat
name|m_format
block|;
name|EGLenum
name|m_api
block|;
name|int
name|m_swapInterval
block|;
name|bool
name|m_swapIntervalEnvChecked
block|;
name|int
name|m_swapIntervalFromEnv
block|;
name|bool
name|m_ownsContext
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
comment|//QEGLPLATFORMCONTEXT_H
end_comment
end_unit
