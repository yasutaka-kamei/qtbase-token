begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QOffscreenSurface>
end_include
begin_include
include|#
directive|include
file|"qeglpbuffer_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglconvenience_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QEGLPbuffer     \brief A pbuffer-based implementation of QPlatformOffscreenSurface for EGL.     \since 5.2     \internal     \ingroup qpa      To use this implementation in the platform plugin simply     reimplement QPlatformIntegration::createPlatformOffscreenSurface()     and return a new instance of this class. */
end_comment
begin_constructor
DECL|function|QEGLPbuffer
name|QEGLPbuffer
operator|::
name|QEGLPbuffer
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QOffscreenSurface
modifier|*
name|offscreenSurface
parameter_list|)
member_init_list|:
name|QPlatformOffscreenSurface
argument_list|(
name|offscreenSurface
argument_list|)
member_init_list|,
name|m_format
argument_list|(
name|format
argument_list|)
member_init_list|,
name|m_display
argument_list|(
name|display
argument_list|)
member_init_list|,
name|m_pbuffer
argument_list|(
name|EGL_NO_SURFACE
argument_list|)
block|{
name|bool
name|hasSurfaceless
init|=
name|q_hasEglExtension
argument_list|(
name|display
argument_list|,
literal|"EGL_KHR_surfaceless_context"
argument_list|)
decl_stmt|;
comment|// Disable surfaceless contexts on Mesa for now. As of 10.6.0 and Intel at least, some
comment|// operations (glReadPixels) are unable to work without a surface since they at some
comment|// point temporarily unbind the current FBO and then later blow up in some seemingly
comment|// safe operations, like setting the viewport, that apparently need access to the
comment|// read/draw surface in the Intel backend.
specifier|const
name|char
modifier|*
name|vendor
init|=
name|eglQueryString
argument_list|(
name|display
argument_list|,
name|EGL_VENDOR
argument_list|)
decl_stmt|;
comment|// hard to check for GL_ strings here, so blacklist all Mesa
if|if
condition|(
name|vendor
operator|&&
name|strstr
argument_list|(
name|vendor
argument_list|,
literal|"Mesa"
argument_list|)
condition|)
name|hasSurfaceless
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|hasSurfaceless
condition|)
return|return;
name|EGLConfig
name|config
init|=
name|q_configFromGLFormat
argument_list|(
name|m_display
argument_list|,
name|m_format
argument_list|,
literal|false
argument_list|,
name|EGL_PBUFFER_BIT
argument_list|)
decl_stmt|;
if|if
condition|(
name|config
condition|)
block|{
specifier|const
name|EGLint
name|attributes
index|[]
init|=
block|{
name|EGL_WIDTH
block|,
name|offscreenSurface
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
block|,
name|EGL_HEIGHT
block|,
name|offscreenSurface
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
block|,
name|EGL_LARGEST_PBUFFER
block|,
name|EGL_FALSE
block|,
name|EGL_NONE
block|}
decl_stmt|;
name|m_pbuffer
operator|=
name|eglCreatePbufferSurface
argument_list|(
name|m_display
argument_list|,
name|config
argument_list|,
name|attributes
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_pbuffer
operator|!=
name|EGL_NO_SURFACE
condition|)
name|m_format
operator|=
name|q_glFormatFromConfig
argument_list|(
name|m_display
argument_list|,
name|config
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QEGLPbuffer
name|QEGLPbuffer
operator|::
name|~
name|QEGLPbuffer
parameter_list|()
block|{
if|if
condition|(
name|m_pbuffer
operator|!=
name|EGL_NO_SURFACE
condition|)
name|eglDestroySurface
argument_list|(
name|m_display
argument_list|,
name|m_pbuffer
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
