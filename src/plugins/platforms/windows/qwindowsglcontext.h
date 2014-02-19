begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSGLCONTEXT_H
end_ifndef
begin_define
DECL|macro|QWINDOWSGLCONTEXT_H
define|#
directive|define
name|QWINDOWSGLCONTEXT_H
end_define
begin_include
include|#
directive|include
file|"array.h"
end_include
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformopenglcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_enum
DECL|enum|QWindowsGLFormatFlags
enum|enum
name|QWindowsGLFormatFlags
block|{
DECL|enumerator|QWindowsGLDirectRendering
name|QWindowsGLDirectRendering
init|=
literal|0x1
block|,
DECL|enumerator|QWindowsGLOverlay
name|QWindowsGLOverlay
init|=
literal|0x2
block|,
DECL|enumerator|QWindowsGLRenderToPixmap
name|QWindowsGLRenderToPixmap
init|=
literal|0x4
block|,
DECL|enumerator|QWindowsGLAccumBuffer
name|QWindowsGLAccumBuffer
init|=
literal|0x8
block|}
enum|;
end_enum
begin_comment
comment|// Additional format information for Windows.
end_comment
begin_struct
DECL|struct|QWindowsOpenGLAdditionalFormat
struct|struct
name|QWindowsOpenGLAdditionalFormat
block|{
DECL|function|QWindowsOpenGLAdditionalFormat
name|QWindowsOpenGLAdditionalFormat
argument_list|(
argument|unsigned formatFlagsIn =
literal|0
argument_list|,
argument|unsigned pixmapDepthIn =
literal|0
argument_list|)
block|:
name|formatFlags
argument_list|(
name|formatFlagsIn
argument_list|)
operator|,
name|pixmapDepth
argument_list|(
argument|pixmapDepthIn
argument_list|)
block|{ }
DECL|member|formatFlags
name|unsigned
name|formatFlags
expr_stmt|;
comment|// QWindowsGLFormatFlags.
DECL|member|pixmapDepth
name|unsigned
name|pixmapDepth
decl_stmt|;
comment|// for QWindowsGLRenderToPixmap
block|}
struct|;
end_struct
begin_comment
comment|// Per-window data for active OpenGL contexts.
end_comment
begin_struct
DECL|struct|QOpenGLContextData
struct|struct
name|QOpenGLContextData
block|{
DECL|function|QOpenGLContextData
name|QOpenGLContextData
argument_list|(
argument|HGLRC r
argument_list|,
argument|HWND h
argument_list|,
argument|HDC d
argument_list|)
block|:
name|renderingContext
argument_list|(
name|r
argument_list|)
operator|,
name|hwnd
argument_list|(
name|h
argument_list|)
operator|,
name|hdc
argument_list|(
argument|d
argument_list|)
block|{}
DECL|function|QOpenGLContextData
name|QOpenGLContextData
argument_list|()
operator|:
name|renderingContext
argument_list|(
literal|0
argument_list|)
operator|,
name|hwnd
argument_list|(
literal|0
argument_list|)
operator|,
name|hdc
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|renderingContext
name|HGLRC
name|renderingContext
expr_stmt|;
DECL|member|hwnd
name|HWND
name|hwnd
decl_stmt|;
DECL|member|hdc
name|HDC
name|hdc
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|QWindowsOpenGLContextFormat
struct|struct
name|QWindowsOpenGLContextFormat
block|{
name|QWindowsOpenGLContextFormat
argument_list|()
expr_stmt|;
specifier|static
name|QWindowsOpenGLContextFormat
name|current
parameter_list|()
function_decl|;
name|void
name|apply
argument_list|(
name|QSurfaceFormat
operator|*
name|format
argument_list|)
decl|const
decl_stmt|;
DECL|member|profile
name|QSurfaceFormat
operator|::
name|OpenGLContextProfile
name|profile
expr_stmt|;
DECL|member|version
name|int
name|version
decl_stmt|;
comment|//! majorVersion<<8 + minorVersion
DECL|member|options
name|QSurfaceFormat
operator|::
name|FormatOptions
name|options
expr_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|QWindowsOpenGLContextFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QOpenGLStaticContext
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLStaticContext
argument_list|)
name|QOpenGLStaticContext
argument_list|()
expr_stmt|;
name|public
label|:
enum|enum
name|Extensions
block|{
name|SampleBuffers
init|=
literal|0x1
block|}
enum|;
typedef|typedef
name|bool
function_decl|(
name|APIENTRY
modifier|*
name|WglGetPixelFormatAttribIVARB
function_decl|)
parameter_list|(
name|HDC
name|hdc
parameter_list|,
name|int
name|iPixelFormat
parameter_list|,
name|int
name|iLayerPlane
parameter_list|,
name|uint
name|nAttributes
parameter_list|,
specifier|const
name|int
modifier|*
name|piAttributes
parameter_list|,
name|int
modifier|*
name|piValues
parameter_list|)
function_decl|;
typedef|typedef
name|bool
function_decl|(
name|APIENTRY
modifier|*
name|WglChoosePixelFormatARB
function_decl|)
parameter_list|(
name|HDC
name|hdc
parameter_list|,
specifier|const
name|int
modifier|*
name|piAttribList
parameter_list|,
specifier|const
name|float
modifier|*
name|pfAttribFList
parameter_list|,
name|uint
name|nMaxFormats
parameter_list|,
name|int
modifier|*
name|piFormats
parameter_list|,
name|UINT
modifier|*
name|nNumFormats
parameter_list|)
function_decl|;
typedef|typedef
name|HGLRC
function_decl|(
name|APIENTRY
modifier|*
name|WglCreateContextAttribsARB
function_decl|)
parameter_list|(
name|HDC
parameter_list|,
name|HGLRC
parameter_list|,
specifier|const
name|int
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|BOOL
function_decl|(
name|APIENTRY
modifier|*
name|WglSwapInternalExt
function_decl|)
parameter_list|(
name|int
name|interval
parameter_list|)
function_decl|;
typedef|typedef
name|int
function_decl|(
name|APIENTRY
modifier|*
name|WglGetSwapInternalExt
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|hasExtensions
argument_list|()
specifier|const
block|{
return|return
name|wglGetPixelFormatAttribIVARB
operator|&&
name|wglChoosePixelFormatARB
operator|&&
name|wglCreateContextAttribsARB
return|;
block|}
specifier|static
name|QOpenGLStaticContext
modifier|*
name|create
parameter_list|()
function_decl|;
specifier|static
name|QByteArray
name|getGlString
parameter_list|(
name|unsigned
name|int
name|which
parameter_list|)
function_decl|;
specifier|const
name|QByteArray
name|vendor
decl_stmt|;
specifier|const
name|QByteArray
name|renderer
decl_stmt|;
specifier|const
name|QByteArray
name|extensionNames
decl_stmt|;
name|unsigned
name|extensions
decl_stmt|;
specifier|const
name|QWindowsOpenGLContextFormat
name|defaultFormat
decl_stmt|;
name|WglGetPixelFormatAttribIVARB
name|wglGetPixelFormatAttribIVARB
decl_stmt|;
name|WglChoosePixelFormatARB
name|wglChoosePixelFormatARB
decl_stmt|;
name|WglCreateContextAttribsARB
name|wglCreateContextAttribsARB
decl_stmt|;
name|WglSwapInternalExt
name|wglSwapInternalExt
decl_stmt|;
name|WglGetSwapInternalExt
name|wglGetSwapInternalExt
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|d
operator|,
specifier|const
name|QOpenGLStaticContext
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QWindowsGLContext
range|:
name|public
name|QPlatformOpenGLContext
block|{
name|public
operator|:
typedef|typedef
name|QSharedPointer
operator|<
name|QOpenGLStaticContext
operator|>
name|QOpenGLStaticContextPtr
expr_stmt|;
name|explicit
name|QWindowsGLContext
argument_list|(
specifier|const
name|QOpenGLStaticContextPtr
operator|&
name|staticContext
argument_list|,
name|QOpenGLContext
operator|*
name|context
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|virtual
operator|~
name|QWindowsGLContext
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isSharing
argument_list|()
specifier|const
block|{
return|return
name|m_context
operator|->
name|shareHandle
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|m_renderingContext
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|{
return|return
name|m_obtainedFormat
return|;
block|}
end_expr_stmt
begin_function_decl
name|virtual
name|void
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|bool
name|makeCurrent
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|doneCurrent
parameter_list|()
function_decl|;
end_function_decl
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|GL_Proc
function_decl|)
parameter_list|()
function_decl|;
end_typedef
begin_function_decl
name|virtual
name|GL_Proc
name|getProcAddress
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|procName
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|HGLRC
name|renderingContext
argument_list|()
specifier|const
block|{
return|return
name|m_renderingContext
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_function_decl
specifier|inline
name|void
name|releaseDCs
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
specifier|const
name|QOpenGLStaticContextPtr
name|m_staticContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QOpenGLContext
modifier|*
name|m_context
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSurfaceFormat
name|m_obtainedFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|HGLRC
name|m_renderingContext
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Array
operator|<
name|QOpenGLContextData
operator|>
name|m_windowContexts
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|PIXELFORMATDESCRIPTOR
name|m_obtainedPixelFormatDescriptor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_pixelFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_extensionsUsed
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_swapInterval
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
comment|// QWINDOWSGLCONTEXT_H
end_comment
end_unit
