begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglplatformcontext_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglconvenience_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglpbuffer_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtPlatformHeaders/QEGLNativeContext>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QEGLPlatformContext     \brief An EGL context implementation.     \since 5.2     \internal     \ingroup qpa      Implement QPlatformOpenGLContext using EGL. To use it in platform     plugins a subclass must be created since     eglSurfaceForPlatformSurface() has to be reimplemented. This     function is used for mapping platform surfaces (windows) to EGL     surfaces and is necessary since different platform plugins may     have different ways of handling native windows (for example, a     plugin may choose not to back every platform window by a real EGL     surface). Other than that, no further customization is necessary.  */
end_comment
begin_comment
comment|// Constants from EGL_KHR_create_context
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|EGL_CONTEXT_MINOR_VERSION_KHR
end_ifndef
begin_define
DECL|macro|EGL_CONTEXT_MINOR_VERSION_KHR
define|#
directive|define
name|EGL_CONTEXT_MINOR_VERSION_KHR
value|0x30FB
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|EGL_CONTEXT_FLAGS_KHR
end_ifndef
begin_define
DECL|macro|EGL_CONTEXT_FLAGS_KHR
define|#
directive|define
name|EGL_CONTEXT_FLAGS_KHR
value|0x30FC
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR
end_ifndef
begin_define
DECL|macro|EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR
define|#
directive|define
name|EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR
value|0x30FD
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR
end_ifndef
begin_define
DECL|macro|EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR
define|#
directive|define
name|EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR
value|0x00000001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT_KHR
end_ifndef
begin_define
DECL|macro|EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT_KHR
define|#
directive|define
name|EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT_KHR
value|0x00000002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR
end_ifndef
begin_define
DECL|macro|EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR
define|#
directive|define
name|EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR
value|0x00000001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT_KHR
end_ifndef
begin_define
DECL|macro|EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT_KHR
define|#
directive|define
name|EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT_KHR
value|0x00000002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Constants for OpenGL which are not available in the ES headers.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|GL_CONTEXT_FLAGS
end_ifndef
begin_define
DECL|macro|GL_CONTEXT_FLAGS
define|#
directive|define
name|GL_CONTEXT_FLAGS
value|0x821E
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
end_ifndef
begin_define
DECL|macro|GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
define|#
directive|define
name|GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
value|0x0001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_CONTEXT_FLAG_DEBUG_BIT
end_ifndef
begin_define
DECL|macro|GL_CONTEXT_FLAG_DEBUG_BIT
define|#
directive|define
name|GL_CONTEXT_FLAG_DEBUG_BIT
value|0x00000002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_CONTEXT_PROFILE_MASK
end_ifndef
begin_define
DECL|macro|GL_CONTEXT_PROFILE_MASK
define|#
directive|define
name|GL_CONTEXT_PROFILE_MASK
value|0x9126
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_CONTEXT_CORE_PROFILE_BIT
end_ifndef
begin_define
DECL|macro|GL_CONTEXT_CORE_PROFILE_BIT
define|#
directive|define
name|GL_CONTEXT_CORE_PROFILE_BIT
value|0x00000001
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
end_ifndef
begin_define
DECL|macro|GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
define|#
directive|define
name|GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
value|0x00000002
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QEGLPlatformContext
name|QEGLPlatformContext
operator|::
name|QEGLPlatformContext
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|share
parameter_list|,
name|EGLDisplay
name|display
parameter_list|,
name|EGLConfig
modifier|*
name|config
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|nativeHandle
parameter_list|)
member_init_list|:
name|m_eglDisplay
argument_list|(
name|display
argument_list|)
member_init_list|,
name|m_swapInterval
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_swapIntervalEnvChecked
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_swapIntervalFromEnv
argument_list|(
operator|-
literal|1
argument_list|)
block|{
if|if
condition|(
name|nativeHandle
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|m_eglConfig
operator|=
name|config
condition|?
operator|*
name|config
else|:
name|q_configFromGLFormat
argument_list|(
name|display
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|m_ownsContext
operator|=
literal|true
expr_stmt|;
name|init
argument_list|(
name|format
argument_list|,
name|share
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_ownsContext
operator|=
literal|false
expr_stmt|;
name|adopt
argument_list|(
name|nativeHandle
argument_list|,
name|share
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_function
DECL|function|init
name|void
name|QEGLPlatformContext
operator|::
name|init
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|share
parameter_list|)
block|{
name|m_format
operator|=
name|q_glFormatFromConfig
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|)
expr_stmt|;
comment|// m_format now has the renderableType() resolved (it cannot be Default anymore)
comment|// but does not yet contain version, profile, options.
name|m_shareContext
operator|=
name|share
condition|?
cast|static_cast
argument_list|<
name|QEGLPlatformContext
operator|*
argument_list|>
argument_list|(
name|share
argument_list|)
operator|->
name|m_eglContext
else|:
literal|0
expr_stmt|;
name|QVector
argument_list|<
name|EGLint
argument_list|>
name|contextAttrs
decl_stmt|;
name|contextAttrs
operator|.
name|append
argument_list|(
name|EGL_CONTEXT_CLIENT_VERSION
argument_list|)
expr_stmt|;
name|contextAttrs
operator|.
name|append
argument_list|(
name|format
operator|.
name|majorVersion
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|hasKHRCreateContext
init|=
name|q_hasEglExtension
argument_list|(
name|m_eglDisplay
argument_list|,
literal|"EGL_KHR_create_context"
argument_list|)
decl_stmt|;
if|if
condition|(
name|hasKHRCreateContext
condition|)
block|{
name|contextAttrs
operator|.
name|append
argument_list|(
name|EGL_CONTEXT_MINOR_VERSION_KHR
argument_list|)
expr_stmt|;
name|contextAttrs
operator|.
name|append
argument_list|(
name|format
operator|.
name|minorVersion
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|flags
init|=
literal|0
decl_stmt|;
comment|// The debug bit is supported both for OpenGL and OpenGL ES.
if|if
condition|(
name|format
operator|.
name|testOption
argument_list|(
name|QSurfaceFormat
operator|::
name|DebugContext
argument_list|)
condition|)
name|flags
operator||=
name|EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR
expr_stmt|;
comment|// The fwdcompat bit is only for OpenGL 3.0+.
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGL
operator|&&
name|format
operator|.
name|majorVersion
argument_list|()
operator|>=
literal|3
operator|&&
operator|!
name|format
operator|.
name|testOption
argument_list|(
name|QSurfaceFormat
operator|::
name|DeprecatedFunctions
argument_list|)
condition|)
name|flags
operator||=
name|EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT_KHR
expr_stmt|;
if|if
condition|(
name|flags
condition|)
block|{
name|contextAttrs
operator|.
name|append
argument_list|(
name|EGL_CONTEXT_FLAGS_KHR
argument_list|)
expr_stmt|;
name|contextAttrs
operator|.
name|append
argument_list|(
name|flags
argument_list|)
expr_stmt|;
block|}
comment|// Profiles are OpenGL only and mandatory in 3.2+. The value is silently ignored for< 3.2.
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGL
condition|)
block|{
name|contextAttrs
operator|.
name|append
argument_list|(
name|EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR
argument_list|)
expr_stmt|;
name|contextAttrs
operator|.
name|append
argument_list|(
name|format
operator|.
name|profile
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|CoreProfile
condition|?
name|EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR
else|:
name|EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT_KHR
argument_list|)
expr_stmt|;
block|}
block|}
name|contextAttrs
operator|.
name|append
argument_list|(
name|EGL_NONE
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
condition|)
block|{
case|case
name|QSurfaceFormat
operator|::
name|OpenVG
case|:
name|m_api
operator|=
name|EGL_OPENVG_API
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|EGL_VERSION_1_4
case|case
name|QSurfaceFormat
operator|::
name|OpenGL
case|:
name|m_api
operator|=
name|EGL_OPENGL_API
expr_stmt|;
break|break;
endif|#
directive|endif
comment|// EGL_VERSION_1_4
default|default:
name|m_api
operator|=
name|EGL_OPENGL_ES_API
expr_stmt|;
break|break;
block|}
name|eglBindAPI
argument_list|(
name|m_api
argument_list|)
expr_stmt|;
name|m_eglContext
operator|=
name|eglCreateContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|,
name|m_shareContext
argument_list|,
name|contextAttrs
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglContext
operator|==
name|EGL_NO_CONTEXT
operator|&&
name|m_shareContext
operator|!=
name|EGL_NO_CONTEXT
condition|)
block|{
name|m_shareContext
operator|=
literal|0
expr_stmt|;
name|m_eglContext
operator|=
name|eglCreateContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|,
literal|0
argument_list|,
name|contextAttrs
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|m_eglContext
operator|==
name|EGL_NO_CONTEXT
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEGLPlatformContext::init: eglError: %x, this: %p \n"
argument_list|,
name|eglGetError
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
return|return;
block|}
specifier|static
specifier|const
name|bool
name|printConfig
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_DEBUG"
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|printConfig
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Created context for format"
operator|<<
name|format
operator|<<
literal|"with config:"
expr_stmt|;
name|q_printEglConfig
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|)
expr_stmt|;
block|}
name|updateFormatFromGL
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|adopt
name|void
name|QEGLPlatformContext
operator|::
name|adopt
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|nativeHandle
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|share
parameter_list|)
block|{
if|if
condition|(
operator|!
name|nativeHandle
operator|.
name|canConvert
argument_list|<
name|QEGLNativeContext
argument_list|>
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEGLPlatformContext: Requires a QEGLNativeContext"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QEGLNativeContext
name|handle
init|=
name|nativeHandle
operator|.
name|value
argument_list|<
name|QEGLNativeContext
argument_list|>
argument_list|()
decl_stmt|;
name|EGLContext
name|context
init|=
name|handle
operator|.
name|context
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|context
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEGLPlatformContext: No EGLContext given"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// A context belonging to a given EGLDisplay cannot be used with another one.
if|if
condition|(
name|handle
operator|.
name|display
argument_list|()
operator|!=
name|m_eglDisplay
condition|)
block|{
name|qWarning
argument_list|(
literal|"QEGLPlatformContext: Cannot adopt context from different display"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// Figure out the EGLConfig.
name|EGLint
name|value
init|=
literal|0
decl_stmt|;
name|eglQueryContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|context
argument_list|,
name|EGL_CONFIG_ID
argument_list|,
operator|&
name|value
argument_list|)
expr_stmt|;
name|EGLint
name|n
init|=
literal|0
decl_stmt|;
name|EGLConfig
name|cfg
decl_stmt|;
specifier|const
name|EGLint
name|attribs
index|[]
init|=
block|{
name|EGL_CONFIG_ID
block|,
name|value
block|,
name|EGL_NONE
block|}
decl_stmt|;
if|if
condition|(
name|eglChooseConfig
argument_list|(
name|m_eglDisplay
argument_list|,
name|attribs
argument_list|,
operator|&
name|cfg
argument_list|,
literal|1
argument_list|,
operator|&
name|n
argument_list|)
operator|&&
name|n
operator|==
literal|1
condition|)
block|{
name|m_eglConfig
operator|=
name|cfg
expr_stmt|;
name|m_format
operator|=
name|q_glFormatFromConfig
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QEGLPlatformContext: Failed to get framebuffer configuration for context"
argument_list|)
expr_stmt|;
block|}
comment|// Fetch client API type.
name|value
operator|=
literal|0
expr_stmt|;
name|eglQueryContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|context
argument_list|,
name|EGL_CONTEXT_CLIENT_TYPE
argument_list|,
operator|&
name|value
argument_list|)
expr_stmt|;
if|if
condition|(
name|value
operator|==
name|EGL_OPENGL_API
operator|||
name|value
operator|==
name|EGL_OPENGL_ES_API
condition|)
block|{
name|m_api
operator|=
name|value
expr_stmt|;
name|eglBindAPI
argument_list|(
name|m_api
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QEGLPlatformContext: Failed to get client API type"
argument_list|)
expr_stmt|;
name|m_api
operator|=
name|EGL_OPENGL_ES_API
expr_stmt|;
block|}
name|m_eglContext
operator|=
name|context
expr_stmt|;
name|m_shareContext
operator|=
name|share
condition|?
cast|static_cast
argument_list|<
name|QEGLPlatformContext
operator|*
argument_list|>
argument_list|(
name|share
argument_list|)
operator|->
name|m_eglContext
else|:
literal|0
expr_stmt|;
name|updateFormatFromGL
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateFormatFromGL
name|void
name|QEGLPlatformContext
operator|::
name|updateFormatFromGL
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
comment|// Make the context current to ensure the GL version query works. This needs a surface too.
specifier|const
name|EGLint
name|pbufferAttributes
index|[]
init|=
block|{
name|EGL_WIDTH
block|,
literal|1
block|,
name|EGL_HEIGHT
block|,
literal|1
block|,
name|EGL_LARGEST_PBUFFER
block|,
name|EGL_FALSE
block|,
name|EGL_NONE
block|}
decl_stmt|;
name|EGLSurface
name|pbuffer
init|=
name|eglCreatePbufferSurface
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglConfig
argument_list|,
name|pbufferAttributes
argument_list|)
decl_stmt|;
if|if
condition|(
name|pbuffer
operator|==
name|EGL_NO_SURFACE
condition|)
return|return;
if|if
condition|(
name|eglMakeCurrent
argument_list|(
name|m_eglDisplay
argument_list|,
name|pbuffer
argument_list|,
name|pbuffer
argument_list|,
name|m_eglContext
argument_list|)
condition|)
block|{
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGL
operator|||
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGLES
condition|)
block|{
specifier|const
name|GLubyte
modifier|*
name|s
init|=
name|glGetString
argument_list|(
name|GL_VERSION
argument_list|)
decl_stmt|;
if|if
condition|(
name|s
condition|)
block|{
name|QByteArray
name|version
init|=
name|QByteArray
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|s
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|major
decl_stmt|,
name|minor
decl_stmt|;
if|if
condition|(
name|QPlatformOpenGLContext
operator|::
name|parseOpenGLVersion
argument_list|(
name|version
argument_list|,
name|major
argument_list|,
name|minor
argument_list|)
condition|)
block|{
name|m_format
operator|.
name|setMajorVersion
argument_list|(
name|major
argument_list|)
expr_stmt|;
name|m_format
operator|.
name|setMinorVersion
argument_list|(
name|minor
argument_list|)
expr_stmt|;
block|}
block|}
name|m_format
operator|.
name|setProfile
argument_list|(
name|QSurfaceFormat
operator|::
name|NoProfile
argument_list|)
expr_stmt|;
name|m_format
operator|.
name|setOptions
argument_list|(
name|QSurfaceFormat
operator|::
name|FormatOptions
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_format
operator|.
name|renderableType
argument_list|()
operator|==
name|QSurfaceFormat
operator|::
name|OpenGL
condition|)
block|{
comment|// Check profile and options.
if|if
condition|(
name|m_format
operator|.
name|majorVersion
argument_list|()
operator|<
literal|3
condition|)
block|{
name|m_format
operator|.
name|setOption
argument_list|(
name|QSurfaceFormat
operator|::
name|DeprecatedFunctions
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|GLint
name|value
init|=
literal|0
decl_stmt|;
name|glGetIntegerv
argument_list|(
name|GL_CONTEXT_FLAGS
argument_list|,
operator|&
name|value
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|value
operator|&
name|GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
operator|)
condition|)
name|m_format
operator|.
name|setOption
argument_list|(
name|QSurfaceFormat
operator|::
name|DeprecatedFunctions
argument_list|)
expr_stmt|;
if|if
condition|(
name|value
operator|&
name|GL_CONTEXT_FLAG_DEBUG_BIT
condition|)
name|m_format
operator|.
name|setOption
argument_list|(
name|QSurfaceFormat
operator|::
name|DebugContext
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_format
operator|.
name|version
argument_list|()
operator|>=
name|qMakePair
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
condition|)
block|{
name|value
operator|=
literal|0
expr_stmt|;
name|glGetIntegerv
argument_list|(
name|GL_CONTEXT_PROFILE_MASK
argument_list|,
operator|&
name|value
argument_list|)
expr_stmt|;
if|if
condition|(
name|value
operator|&
name|GL_CONTEXT_CORE_PROFILE_BIT
condition|)
name|m_format
operator|.
name|setProfile
argument_list|(
name|QSurfaceFormat
operator|::
name|CoreProfile
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|value
operator|&
name|GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
condition|)
name|m_format
operator|.
name|setProfile
argument_list|(
name|QSurfaceFormat
operator|::
name|CompatibilityProfile
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
name|eglMakeCurrent
argument_list|(
name|m_eglDisplay
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_CONTEXT
argument_list|)
expr_stmt|;
block|}
name|eglDestroySurface
argument_list|(
name|m_eglDisplay
argument_list|,
name|pbuffer
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// QT_NO_OPENGL
block|}
end_function
begin_function
DECL|function|makeCurrent
name|bool
name|QEGLPlatformContext
operator|::
name|makeCurrent
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|supportsOpenGL
argument_list|()
argument_list|)
expr_stmt|;
name|eglBindAPI
argument_list|(
name|m_api
argument_list|)
expr_stmt|;
name|EGLSurface
name|eglSurface
init|=
name|eglSurfaceForPlatformSurface
argument_list|(
name|surface
argument_list|)
decl_stmt|;
comment|// shortcut: on some GPUs, eglMakeCurrent is not a cheap operation
if|if
condition|(
name|eglGetCurrentContext
argument_list|()
operator|==
name|m_eglContext
operator|&&
name|eglGetCurrentDisplay
argument_list|()
operator|==
name|m_eglDisplay
operator|&&
name|eglGetCurrentSurface
argument_list|(
name|EGL_READ
argument_list|)
operator|==
name|eglSurface
operator|&&
name|eglGetCurrentSurface
argument_list|(
name|EGL_DRAW
argument_list|)
operator|==
name|eglSurface
condition|)
block|{
return|return
literal|true
return|;
block|}
specifier|const
name|bool
name|ok
init|=
name|eglMakeCurrent
argument_list|(
name|m_eglDisplay
argument_list|,
name|eglSurface
argument_list|,
name|eglSurface
argument_list|,
name|m_eglContext
argument_list|)
decl_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
if|if
condition|(
operator|!
name|m_swapIntervalEnvChecked
condition|)
block|{
name|m_swapIntervalEnvChecked
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
literal|"QT_QPA_EGLFS_SWAPINTERVAL"
argument_list|)
condition|)
block|{
name|QByteArray
name|swapIntervalString
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_SWAPINTERVAL"
argument_list|)
decl_stmt|;
name|bool
name|intervalOk
decl_stmt|;
specifier|const
name|int
name|swapInterval
init|=
name|swapIntervalString
operator|.
name|toInt
argument_list|(
operator|&
name|intervalOk
argument_list|)
decl_stmt|;
if|if
condition|(
name|intervalOk
condition|)
name|m_swapIntervalFromEnv
operator|=
name|swapInterval
expr_stmt|;
block|}
block|}
specifier|const
name|int
name|requestedSwapInterval
init|=
name|m_swapIntervalFromEnv
operator|>=
literal|0
condition|?
name|m_swapIntervalFromEnv
else|:
name|surface
operator|->
name|format
argument_list|()
operator|.
name|swapInterval
argument_list|()
decl_stmt|;
if|if
condition|(
name|requestedSwapInterval
operator|>=
literal|0
operator|&&
name|m_swapInterval
operator|!=
name|requestedSwapInterval
condition|)
block|{
name|m_swapInterval
operator|=
name|requestedSwapInterval
expr_stmt|;
name|eglSwapInterval
argument_list|(
name|eglDisplay
argument_list|()
argument_list|,
name|m_swapInterval
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QEGLPlatformContext::makeCurrent: eglError: %x, this: %p \n"
argument_list|,
name|eglGetError
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
return|return
name|ok
return|;
block|}
end_function
begin_destructor
DECL|function|~QEGLPlatformContext
name|QEGLPlatformContext
operator|::
name|~
name|QEGLPlatformContext
parameter_list|()
block|{
if|if
condition|(
name|m_ownsContext
operator|&&
name|m_eglContext
operator|!=
name|EGL_NO_CONTEXT
condition|)
name|eglDestroyContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglContext
argument_list|)
expr_stmt|;
name|m_eglContext
operator|=
name|EGL_NO_CONTEXT
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|doneCurrent
name|void
name|QEGLPlatformContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|eglBindAPI
argument_list|(
name|m_api
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
name|eglMakeCurrent
argument_list|(
name|m_eglDisplay
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_CONTEXT
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"QEGLPlatformContext::doneCurrent(): eglError: %d, this: %p \n"
argument_list|,
name|eglGetError
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QEGLPlatformContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|eglBindAPI
argument_list|(
name|m_api
argument_list|)
expr_stmt|;
name|EGLSurface
name|eglSurface
init|=
name|eglSurfaceForPlatformSurface
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|bool
name|ok
init|=
name|eglSwapBuffers
argument_list|(
name|m_eglDisplay
argument_list|,
name|eglSurface
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"QEGLPlatformContext::swapBuffers(): eglError: %d, this: %p \n"
argument_list|,
name|eglGetError
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
DECL|function|getProcAddress
name|void
argument_list|(
argument|*QEGLPlatformContext::getProcAddress(const QByteArray&procName)
argument_list|)
end_macro
begin_expr_stmt
DECL|function|getProcAddress
operator|(
operator|)
block|{
name|eglBindAPI
argument_list|(
name|m_api
argument_list|)
block|;
return|return
name|eglGetProcAddress
argument_list|(
name|procName
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|format
name|QSurfaceFormat
name|QEGLPlatformContext
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
end_function
begin_function
DECL|function|eglContext
name|EGLContext
name|QEGLPlatformContext
operator|::
name|eglContext
parameter_list|()
specifier|const
block|{
return|return
name|m_eglContext
return|;
block|}
end_function
begin_function
DECL|function|eglDisplay
name|EGLDisplay
name|QEGLPlatformContext
operator|::
name|eglDisplay
parameter_list|()
specifier|const
block|{
return|return
name|m_eglDisplay
return|;
block|}
end_function
begin_function
DECL|function|eglConfig
name|EGLConfig
name|QEGLPlatformContext
operator|::
name|eglConfig
parameter_list|()
specifier|const
block|{
return|return
name|m_eglConfig
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
