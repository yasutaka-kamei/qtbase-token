begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGL_P_H
end_ifndef
begin_define
DECL|macro|QGL_P_H
define|#
directive|define
name|QGL_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QGLWidget class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|"QtOpenGL/qgl.h"
end_include
begin_include
include|#
directive|include
file|"QtOpenGL/qglcolormap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qthread.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qthreadstorage.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qatomic.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/private/qopenglcontext_p.h"
end_include
begin_include
include|#
directive|include
file|"qcache.h"
end_include
begin_include
include|#
directive|include
file|"qglpaintdevice_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGLContext
name|class
name|QGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGLOverlayWidget
name|class
name|QGLOverlayWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|<QtOpenGL/private/qglextensions_p.h>
name|QT_END_INCLUDE_NAMESPACE
name|class
name|QGLFormatPrivate
block|{
name|public
label|:
name|QGLFormatPrivate
argument_list|()
operator|:
name|ref
argument_list|(
literal|1
argument_list|)
block|{
name|opts
operator|=
name|QGL
operator|::
name|DoubleBuffer
operator||
name|QGL
operator|::
name|DepthBuffer
operator||
name|QGL
operator|::
name|Rgba
operator||
name|QGL
operator|::
name|DirectRendering
operator||
name|QGL
operator|::
name|StencilBuffer
operator||
name|QGL
operator|::
name|DeprecatedFunctions
block|;
name|pln
operator|=
literal|0
block|;
name|depthSize
operator|=
name|accumSize
operator|=
name|stencilSize
operator|=
name|redSize
operator|=
name|greenSize
operator|=
name|blueSize
operator|=
name|alphaSize
operator|=
operator|-
literal|1
block|;
name|numSamples
operator|=
operator|-
literal|1
block|;
name|swapInterval
operator|=
operator|-
literal|1
block|;
name|majorVersion
operator|=
literal|1
block|;
name|minorVersion
operator|=
literal|0
block|;
name|profile
operator|=
name|QGLFormat
operator|::
name|NoProfile
block|;     }
name|QGLFormatPrivate
argument_list|(
specifier|const
name|QGLFormatPrivate
operator|*
name|other
argument_list|)
operator|:
name|ref
argument_list|(
literal|1
argument_list|)
operator|,
name|opts
argument_list|(
name|other
operator|->
name|opts
argument_list|)
operator|,
name|pln
argument_list|(
name|other
operator|->
name|pln
argument_list|)
operator|,
name|depthSize
argument_list|(
name|other
operator|->
name|depthSize
argument_list|)
operator|,
name|accumSize
argument_list|(
name|other
operator|->
name|accumSize
argument_list|)
operator|,
name|stencilSize
argument_list|(
name|other
operator|->
name|stencilSize
argument_list|)
operator|,
name|redSize
argument_list|(
name|other
operator|->
name|redSize
argument_list|)
operator|,
name|greenSize
argument_list|(
name|other
operator|->
name|greenSize
argument_list|)
operator|,
name|blueSize
argument_list|(
name|other
operator|->
name|blueSize
argument_list|)
operator|,
name|alphaSize
argument_list|(
name|other
operator|->
name|alphaSize
argument_list|)
operator|,
name|numSamples
argument_list|(
name|other
operator|->
name|numSamples
argument_list|)
operator|,
name|swapInterval
argument_list|(
name|other
operator|->
name|swapInterval
argument_list|)
operator|,
name|majorVersion
argument_list|(
name|other
operator|->
name|majorVersion
argument_list|)
operator|,
name|minorVersion
argument_list|(
name|other
operator|->
name|minorVersion
argument_list|)
operator|,
name|profile
argument_list|(
argument|other->profile
argument_list|)
block|{     }
name|QAtomicInt
name|ref
expr_stmt|;
name|QGL
operator|::
name|FormatOptions
name|opts
expr_stmt|;
name|int
name|pln
decl_stmt|;
name|int
name|depthSize
decl_stmt|;
name|int
name|accumSize
decl_stmt|;
name|int
name|stencilSize
decl_stmt|;
name|int
name|redSize
decl_stmt|;
name|int
name|greenSize
decl_stmt|;
name|int
name|blueSize
decl_stmt|;
name|int
name|alphaSize
decl_stmt|;
name|int
name|numSamples
decl_stmt|;
name|int
name|swapInterval
decl_stmt|;
name|int
name|majorVersion
decl_stmt|;
name|int
name|minorVersion
decl_stmt|;
name|QGLFormat
operator|::
name|OpenGLContextProfile
name|profile
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLWidgetPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGLWidget
argument_list|)
name|public
operator|:
name|QGLWidgetPrivate
argument_list|()
operator|:
name|QWidgetPrivate
argument_list|()
block|,
name|disable_clear_on_painter_begin
argument_list|(
argument|false
argument_list|)
block|{
name|isGLWidget
operator|=
literal|1
block|;     }
operator|~
name|QGLWidgetPrivate
argument_list|()
block|{}
name|void
name|init
argument_list|(
name|QGLContext
operator|*
name|context
argument_list|,
specifier|const
name|QGLWidget
operator|*
name|shareWidget
argument_list|)
block|;
name|void
name|initContext
argument_list|(
name|QGLContext
operator|*
name|context
argument_list|,
specifier|const
name|QGLWidget
operator|*
name|shareWidget
argument_list|)
block|;
name|bool
name|renderCxPm
argument_list|(
name|QPixmap
operator|*
name|pixmap
argument_list|)
block|;
name|void
name|cleanupColormaps
argument_list|()
block|;
name|void
name|aboutToDestroy
argument_list|()
block|{
if|if
condition|(
name|glcx
condition|)
name|glcx
operator|->
name|reset
argument_list|()
expr_stmt|;
block|}
name|QGLContext
operator|*
name|glcx
block|;
name|QGLWidgetGLPaintDevice
name|glDevice
block|;
name|bool
name|autoSwap
block|;
name|QGLColormap
name|cmap
block|;
ifndef|#
directive|ifndef
name|QT_OPENGL_ES
name|QMap
operator|<
name|QString
block|,
name|int
operator|>
name|displayListCache
block|;
endif|#
directive|endif
name|bool
name|disable_clear_on_painter_begin
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// QGLContextPrivate has the responsibility of creating context groups.
end_comment
begin_comment
comment|// QGLContextPrivate maintains the reference counter and destroys
end_comment
begin_comment
comment|// context groups when needed.
end_comment
begin_decl_stmt
name|class
name|QGLContextGroup
block|{
name|public
label|:
operator|~
name|QGLContextGroup
argument_list|()
expr_stmt|;
name|QGLExtensionFuncs
modifier|&
name|extensionFuncs
parameter_list|()
block|{
return|return
name|m_extensionFuncs
return|;
block|}
specifier|const
name|QGLContext
operator|*
name|context
argument_list|()
specifier|const
block|{
return|return
name|m_context
return|;
block|}
name|bool
name|isSharing
argument_list|()
specifier|const
block|{
return|return
name|m_shares
operator|.
name|size
argument_list|()
operator|>=
literal|2
return|;
block|}
name|QList
operator|<
specifier|const
name|QGLContext
operator|*
operator|>
name|shares
argument_list|()
specifier|const
block|{
return|return
name|m_shares
return|;
block|}
specifier|static
name|void
name|addShare
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|context
parameter_list|,
specifier|const
name|QGLContext
modifier|*
name|share
parameter_list|)
function_decl|;
specifier|static
name|void
name|removeShare
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|context
parameter_list|)
function_decl|;
name|private
label|:
name|QGLContextGroup
argument_list|(
specifier|const
name|QGLContext
operator|*
name|context
argument_list|)
expr_stmt|;
name|QGLExtensionFuncs
name|m_extensionFuncs
decl_stmt|;
specifier|const
name|QGLContext
modifier|*
name|m_context
decl_stmt|;
comment|// context group's representative
name|QList
operator|<
specifier|const
name|QGLContext
operator|*
operator|>
name|m_shares
expr_stmt|;
name|QAtomicInt
name|m_refs
decl_stmt|;
name|friend
name|class
name|QGLContext
decl_stmt|;
name|friend
name|class
name|QGLContextPrivate
decl_stmt|;
name|friend
name|class
name|QGLContextGroupResourceBase
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// Get the context that resources for "ctx" will transfer to once
end_comment
begin_comment
comment|// "ctx" is destroyed.  Returns null if nothing is sharing with ctx.
end_comment
begin_function_decl
specifier|const
name|QGLContext
modifier|*
name|qt_gl_transfer_context
parameter_list|(
specifier|const
name|QGLContext
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// GL extension definitions
end_comment
begin_decl_stmt
name|class
name|QGLExtensions
block|{
name|public
label|:
enum|enum
name|Extension
block|{
name|TextureRectangle
init|=
literal|0x00000001
block|,
name|SampleBuffers
init|=
literal|0x00000002
block|,
name|GenerateMipmap
init|=
literal|0x00000004
block|,
name|TextureCompression
init|=
literal|0x00000008
block|,
name|FragmentProgram
init|=
literal|0x00000010
block|,
name|MirroredRepeat
init|=
literal|0x00000020
block|,
name|FramebufferObject
init|=
literal|0x00000040
block|,
name|StencilTwoSide
init|=
literal|0x00000080
block|,
name|StencilWrap
init|=
literal|0x00000100
block|,
name|PackedDepthStencil
init|=
literal|0x00000200
block|,
name|NVFloatBuffer
init|=
literal|0x00000400
block|,
name|PixelBufferObject
init|=
literal|0x00000800
block|,
name|FramebufferBlit
init|=
literal|0x00001000
block|,
name|NPOTTextures
init|=
literal|0x00002000
block|,
name|BGRATextureFormat
init|=
literal|0x00004000
block|,
name|DDSTextureCompression
init|=
literal|0x00008000
block|,
name|ETC1TextureCompression
init|=
literal|0x00010000
block|,
name|PVRTCTextureCompression
init|=
literal|0x00020000
block|,
name|FragmentShader
init|=
literal|0x00040000
block|,
name|ElementIndexUint
init|=
literal|0x00080000
block|,
name|Depth24
init|=
literal|0x00100000
block|,
name|SRGBFrameBuffer
init|=
literal|0x00200000
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Extensions
argument_list|,
argument|Extension
argument_list|)
specifier|static
name|Extensions
name|glExtensions
parameter_list|()
function_decl|;
specifier|static
name|Extensions
name|currentContextExtensions
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*     QGLTemporaryContext - the main objective of this class is to have a way of     creating a GL context and making it current, without going via QGLWidget     and friends. At certain points during GL initialization we need a current     context in order decide what GL features are available, and to resolve GL     extensions. Having a light-weight way of creating such a context saves     initial application startup time, and it doesn't wind up creating recursive     conflicts.     The class currently uses a private d pointer to hide the platform specific     types. This could possibly been done inline with #ifdef'ery, but it causes     major headaches on e.g. X11 due to namespace pollution. */
end_comment
begin_decl_stmt
DECL|variable|QGLTemporaryContextPrivate
name|class
name|QGLTemporaryContextPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGLTemporaryContext
block|{
name|public
label|:
name|QGLTemporaryContext
argument_list|(
argument|bool directRendering = true
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
empty_stmt|;
operator|~
name|QGLTemporaryContext
argument_list|()
expr_stmt|;
name|private
label|:
name|QScopedPointer
operator|<
name|QGLTemporaryContextPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QGLTexture
name|class
name|QGLTexture
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGLTextureDestroyer
name|class
name|QGLTextureDestroyer
decl_stmt|;
end_decl_stmt
begin_comment
comment|// This probably needs to grow to GL_MAX_VERTEX_ATTRIBS, but 3 is ok for now as that's
end_comment
begin_comment
comment|// all the GL2 engine uses:
end_comment
begin_define
DECL|macro|QT_GL_VERTEX_ARRAY_TRACKED_COUNT
define|#
directive|define
name|QT_GL_VERTEX_ARRAY_TRACKED_COUNT
value|3
end_define
begin_decl_stmt
DECL|variable|QGLContextResourceBase
name|class
name|QGLContextResourceBase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGLContextPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGLContext
argument_list|)
name|public
label|:
name|explicit
name|QGLContextPrivate
parameter_list|(
name|QGLContext
modifier|*
name|context
parameter_list|)
function_decl|;
operator|~
name|QGLContextPrivate
argument_list|()
expr_stmt|;
name|QGLTexture
modifier|*
name|bindTexture
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|,
name|GLenum
name|target
argument_list|,
name|GLint
name|format
argument_list|,
name|QGLContext
operator|::
name|BindOptions
name|options
argument_list|)
decl_stmt|;
name|QGLTexture
modifier|*
name|bindTexture
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|,
name|GLenum
name|target
argument_list|,
name|GLint
name|format
argument_list|,
specifier|const
name|qint64
name|key
argument_list|,
name|QGLContext
operator|::
name|BindOptions
name|options
argument_list|)
decl_stmt|;
name|QGLTexture
modifier|*
name|bindTexture
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
name|GLenum
name|target
argument_list|,
name|GLint
name|format
argument_list|,
name|QGLContext
operator|::
name|BindOptions
name|options
argument_list|)
decl_stmt|;
name|QGLTexture
modifier|*
name|textureCacheLookup
parameter_list|(
specifier|const
name|qint64
name|key
parameter_list|,
name|GLenum
name|target
parameter_list|)
function_decl|;
name|void
name|init
parameter_list|(
name|QPaintDevice
modifier|*
name|dev
parameter_list|,
specifier|const
name|QGLFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|QImage
name|convertToGLFormat
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|bool
name|force_premul
parameter_list|,
name|GLenum
name|texture_format
parameter_list|)
function_decl|;
name|int
name|maxTextureSize
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
name|void
name|setVertexAttribArrayEnabled
parameter_list|(
name|int
name|arrayIndex
parameter_list|,
name|bool
name|enabled
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|syncGlState
parameter_list|()
function_decl|;
comment|// Makes sure the GL context's state is what we think it is
name|void
name|swapRegion
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
name|QOpenGLContext
modifier|*
name|guiGlContext
decl_stmt|;
name|bool
name|ownContext
decl_stmt|;
name|void
name|setupSharing
parameter_list|()
function_decl|;
name|QGLFormat
name|glFormat
decl_stmt|;
name|QGLFormat
name|reqFormat
decl_stmt|;
name|GLuint
name|fbo
decl_stmt|;
name|uint
name|valid
range|:
literal|1
decl_stmt|;
name|uint
name|sharing
range|:
literal|1
decl_stmt|;
name|uint
name|initDone
range|:
literal|1
decl_stmt|;
name|uint
name|crWin
range|:
literal|1
decl_stmt|;
name|uint
name|internal_context
range|:
literal|1
decl_stmt|;
name|uint
name|version_flags_cached
range|:
literal|1
decl_stmt|;
name|uint
name|extension_flags_cached
range|:
literal|1
decl_stmt|;
comment|// workarounds for driver/hw bugs on different platforms
name|uint
name|workaround_needsFullClearOnEveryFrame
range|:
literal|1
decl_stmt|;
name|uint
name|workaround_brokenFBOReadBack
range|:
literal|1
decl_stmt|;
name|uint
name|workaround_brokenTexSubImage
range|:
literal|1
decl_stmt|;
name|uint
name|workaroundsCached
range|:
literal|1
decl_stmt|;
name|uint
name|workaround_brokenTextureFromPixmap
range|:
literal|1
decl_stmt|;
name|uint
name|workaround_brokenTextureFromPixmap_init
range|:
literal|1
decl_stmt|;
name|uint
name|workaround_brokenAlphaTexSubImage
range|:
literal|1
decl_stmt|;
name|uint
name|workaround_brokenAlphaTexSubImage_init
range|:
literal|1
decl_stmt|;
name|QPaintDevice
modifier|*
name|paintDevice
decl_stmt|;
name|QColor
name|transpColor
decl_stmt|;
name|QGLContext
modifier|*
name|q_ptr
decl_stmt|;
name|QGLFormat
operator|::
name|OpenGLVersionFlags
name|version_flags
expr_stmt|;
name|QGLExtensions
operator|::
name|Extensions
name|extension_flags
expr_stmt|;
name|QGLContextGroup
modifier|*
name|group
decl_stmt|;
name|GLint
name|max_texture_size
decl_stmt|;
name|GLuint
name|current_fbo
decl_stmt|;
name|GLuint
name|default_fbo
decl_stmt|;
name|QPaintEngine
modifier|*
name|active_engine
decl_stmt|;
name|QGLTextureDestroyer
modifier|*
name|texture_destroyer
decl_stmt|;
name|QGLFunctions
modifier|*
name|functions
decl_stmt|;
name|bool
name|vertexAttributeArraysEnabledState
index|[
name|QT_GL_VERTEX_ARRAY_TRACKED_COUNT
index|]
decl_stmt|;
specifier|static
specifier|inline
name|QGLContextGroup
modifier|*
name|contextGroup
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|ctx
parameter_list|)
block|{
return|return
name|ctx
operator|->
name|d_ptr
operator|->
name|group
return|;
block|}
specifier|static
name|Q_OPENGL_EXPORT
name|QGLExtensionFuncs
name|qt_extensionFuncs
decl_stmt|;
specifier|static
name|Q_OPENGL_EXPORT
name|QGLExtensionFuncs
modifier|&
name|extensionFuncs
parameter_list|(
specifier|const
name|QGLContext
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|void
name|setCurrentContext
parameter_list|(
name|QGLContext
modifier|*
name|context
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QGLExtensions::Extensions
argument_list|)
end_macro
begin_comment
comment|// Temporarily make a context current if not already current or
end_comment
begin_comment
comment|// shared with the current contex.  The previous context is made
end_comment
begin_comment
comment|// current when the object goes out of scope.
end_comment
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLShareContextScope
block|{
name|public
label|:
name|QGLShareContextScope
argument_list|(
specifier|const
name|QGLContext
operator|*
name|ctx
argument_list|)
operator|:
name|m_oldContext
argument_list|(
literal|0
argument_list|)
block|{
name|QGLContext
operator|*
name|currentContext
operator|=
name|const_cast
operator|<
name|QGLContext
operator|*
operator|>
operator|(
name|QGLContext
operator|::
name|currentContext
argument_list|()
operator|)
block|;
if|if
condition|(
name|currentContext
operator|!=
name|ctx
operator|&&
operator|!
name|QGLContext
operator|::
name|areSharing
argument_list|(
name|ctx
argument_list|,
name|currentContext
argument_list|)
condition|)
block|{
name|m_oldContext
operator|=
name|currentContext
expr_stmt|;
name|m_ctx
operator|=
name|const_cast
operator|<
name|QGLContext
operator|*
operator|>
operator|(
name|ctx
operator|)
expr_stmt|;
name|m_ctx
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|m_ctx
operator|=
name|currentContext
expr_stmt|;
block|}
block|}
name|operator
name|QGLContext
operator|*
operator|(
operator|)
block|{
return|return
name|m_ctx
return|;
block|}
name|QGLContext
operator|*
name|operator
operator|->
expr|(
block|)
block|{
return|return
name|m_ctx
return|;
block|}
end_decl_stmt
begin_expr_stmt
operator|~
name|QGLShareContextScope
argument_list|()
block|{
if|if
condition|(
name|m_oldContext
condition|)
name|m_oldContext
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|QGLContext
modifier|*
name|m_oldContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QGLContext
modifier|*
name|m_ctx
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|Q_OPENGL_EXPORT
name|QGLTextureDestroyer
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QGLTextureDestroyer
argument_list|()
operator|:
name|QObject
argument_list|()
block|{
name|qRegisterMetaType
operator|<
name|GLuint
operator|>
operator|(
literal|"GLuint"
operator|)
block|;
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|freeTexture
argument_list|(
name|QGLContext
operator|*
argument_list|,
name|QPlatformPixmap
operator|*
argument_list|,
name|GLuint
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|freeTexture_slot
argument_list|(
name|QGLContext
operator|*
argument_list|,
name|QPlatformPixmap
operator|*
argument_list|,
name|GLuint
argument_list|)
argument_list|)
argument_list|)
block|;     }
name|void
name|emitFreeTexture
argument_list|(
argument|QGLContext *context
argument_list|,
argument|QPlatformPixmap *boundPixmap
argument_list|,
argument|GLuint id
argument_list|)
block|{
name|emit
name|freeTexture
argument_list|(
name|context
argument_list|,
name|boundPixmap
argument_list|,
name|id
argument_list|)
block|;     }
name|Q_SIGNALS
operator|:
name|void
name|freeTexture
argument_list|(
argument|QGLContext *context
argument_list|,
argument|QPlatformPixmap *boundPixmap
argument_list|,
argument|GLuint id
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|freeTexture_slot
argument_list|(
argument|QGLContext *context
argument_list|,
argument|QPlatformPixmap *boundPixmap
argument_list|,
argument|GLuint id
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|boundPixmap
argument_list|)
block|;
name|QGLShareContextScope
name|scope
argument_list|(
name|context
argument_list|)
block|;
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|id
argument_list|)
block|;     }
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// ### make QGLContext a QObject in 5.0 and remove the proxy stuff
end_comment
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLSignalProxy
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|void
name|emitAboutToDestroyContext
argument_list|(
argument|const QGLContext *context
argument_list|)
block|{
name|emit
name|aboutToDestroyContext
argument_list|(
name|context
argument_list|)
block|;     }
specifier|static
name|QGLSignalProxy
operator|*
name|instance
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|aboutToDestroyContext
argument_list|(
specifier|const
name|QGLContext
operator|*
name|context
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGLTexture
block|{
name|public
label|:
name|QGLTexture
argument_list|(
argument|QGLContext *ctx =
literal|0
argument_list|,
argument|GLuint tx_id =
literal|0
argument_list|,
argument|GLenum tx_target = GL_TEXTURE_2D
argument_list|,
argument|QGLContext::BindOptions opt = QGLContext::DefaultBindOption
argument_list|)
block|:
name|context
argument_list|(
name|ctx
argument_list|)
operator|,
name|id
argument_list|(
name|tx_id
argument_list|)
operator|,
name|target
argument_list|(
name|tx_target
argument_list|)
operator|,
name|options
argument_list|(
argument|opt
argument_list|)
block|{}
operator|~
name|QGLTexture
argument_list|()
block|{
if|if
condition|(
name|options
operator|&
name|QGLContext
operator|::
name|MemoryManagedBindOption
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QPlatformPixmap
modifier|*
name|boundPixmap
init|=
literal|0
decl_stmt|;
name|context
operator|->
name|d_ptr
operator|->
name|texture_destroyer
operator|->
name|emitFreeTexture
argument_list|(
name|context
argument_list|,
name|boundPixmap
argument_list|,
name|id
argument_list|)
expr_stmt|;
block|}
block|}
name|QGLContext
operator|*
name|context
expr_stmt|;
name|GLuint
name|id
decl_stmt|;
name|GLenum
name|target
decl_stmt|;
name|QGLContext
operator|::
name|BindOptions
name|options
expr_stmt|;
name|bool
name|canBindCompressedTexture
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|bool
modifier|*
name|hasAlpha
parameter_list|)
function_decl|;
name|QSize
name|bindCompressedTexture
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|char
modifier|*
name|format
init|=
literal|0
parameter_list|)
function_decl|;
name|QSize
name|bindCompressedTexture
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|format
init|=
literal|0
parameter_list|)
function_decl|;
name|QSize
name|bindCompressedTextureDDS
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|QSize
name|bindCompressedTexturePVR
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct
DECL|struct|QGLTextureCacheKey
struct|struct
name|QGLTextureCacheKey
block|{
DECL|member|key
name|qint64
name|key
decl_stmt|;
DECL|member|group
name|QGLContextGroup
modifier|*
name|group
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
name|QGLTextureCacheKey
operator|&
name|a
operator|,
specifier|const
name|QGLTextureCacheKey
operator|&
name|b
operator|)
block|{
return|return
name|a
operator|.
name|key
operator|==
name|b
operator|.
name|key
operator|&&
name|a
operator|.
name|group
operator|==
name|b
operator|.
name|group
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QGLTextureCacheKey
modifier|&
name|key
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|key
operator|.
name|key
argument_list|)
operator|^
name|qHash
argument_list|(
name|key
operator|.
name|group
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QGLTextureCache
block|{
name|public
label|:
name|QGLTextureCache
argument_list|()
expr_stmt|;
operator|~
name|QGLTextureCache
argument_list|()
expr_stmt|;
name|void
name|insert
parameter_list|(
name|QGLContext
modifier|*
name|ctx
parameter_list|,
name|qint64
name|key
parameter_list|,
name|QGLTexture
modifier|*
name|texture
parameter_list|,
name|int
name|cost
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
name|qint64
name|key
parameter_list|)
function_decl|;
specifier|inline
name|int
name|size
parameter_list|()
function_decl|;
specifier|inline
name|void
name|setMaxCost
parameter_list|(
name|int
name|newMax
parameter_list|)
function_decl|;
specifier|inline
name|int
name|maxCost
parameter_list|()
function_decl|;
specifier|inline
name|QGLTexture
modifier|*
name|getTexture
parameter_list|(
name|QGLContext
modifier|*
name|ctx
parameter_list|,
name|qint64
name|key
parameter_list|)
function_decl|;
name|bool
name|remove
parameter_list|(
name|QGLContext
modifier|*
name|ctx
parameter_list|,
name|GLuint
name|textureId
parameter_list|)
function_decl|;
name|void
name|removeContextTextures
parameter_list|(
name|QGLContext
modifier|*
name|ctx
parameter_list|)
function_decl|;
specifier|static
name|QGLTextureCache
modifier|*
name|instance
parameter_list|()
function_decl|;
specifier|static
name|void
name|cleanupTexturesForCacheKey
parameter_list|(
name|qint64
name|cacheKey
parameter_list|)
function_decl|;
specifier|static
name|void
name|cleanupTexturesForPixampData
parameter_list|(
name|QPlatformPixmap
modifier|*
name|pixmap
parameter_list|)
function_decl|;
specifier|static
name|void
name|cleanupBeforePixmapDestruction
parameter_list|(
name|QPlatformPixmap
modifier|*
name|pixmap
parameter_list|)
function_decl|;
name|private
label|:
name|QCache
operator|<
name|QGLTextureCacheKey
operator|,
name|QGLTexture
operator|>
name|m_cache
expr_stmt|;
name|QReadWriteLock
name|m_lock
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|size
name|int
name|QGLTextureCache
operator|::
name|size
argument_list|()
block|{
name|QReadLocker
name|locker
argument_list|(
operator|&
name|m_lock
argument_list|)
block|;
return|return
name|m_cache
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setMaxCost
name|void
name|QGLTextureCache
operator|::
name|setMaxCost
argument_list|(
argument|int newMax
argument_list|)
block|{
name|QWriteLocker
name|locker
argument_list|(
operator|&
name|m_lock
argument_list|)
block|;
name|m_cache
operator|.
name|setMaxCost
argument_list|(
name|newMax
argument_list|)
block|; }
DECL|function|maxCost
name|int
name|QGLTextureCache
operator|::
name|maxCost
argument_list|()
block|{
name|QReadLocker
name|locker
argument_list|(
operator|&
name|m_lock
argument_list|)
block|;
return|return
name|m_cache
operator|.
name|maxCost
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|getTexture
name|QGLTexture
operator|*
name|QGLTextureCache
operator|::
name|getTexture
argument_list|(
argument|QGLContext *ctx
argument_list|,
argument|qint64 key
argument_list|)
block|{
name|QReadLocker
name|locker
argument_list|(
operator|&
name|m_lock
argument_list|)
block|;
specifier|const
name|QGLTextureCacheKey
name|cacheKey
operator|=
block|{
name|key
block|,
name|QGLContextPrivate
operator|::
name|contextGroup
argument_list|(
argument|ctx
argument_list|)
block|}
block|;
return|return
name|m_cache
operator|.
name|object
argument_list|(
name|cacheKey
argument_list|)
return|;
block|}
end_expr_stmt
begin_function_decl
name|Q_OPENGL_EXPORT
specifier|extern
name|QPaintEngine
modifier|*
name|qt_qgl_paint_engine
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// Put a guard around a GL object identifier and its context.
end_comment
begin_comment
comment|// When the context goes away, a shared context will be used
end_comment
begin_comment
comment|// in its place.  If there are no more shared contexts, then
end_comment
begin_comment
comment|// the identifier is returned as zero - it is assumed that the
end_comment
begin_comment
comment|// context destruction cleaned up the identifier in this case.
end_comment
begin_decl_stmt
name|class
name|QGLSharedResourceGuardBase
range|:
name|public
name|QOpenGLSharedResource
block|{
name|public
operator|:
name|QGLSharedResourceGuardBase
argument_list|(
argument|QGLContext *context
argument_list|,
argument|GLuint id
argument_list|)
operator|:
name|QOpenGLSharedResource
argument_list|(
name|context
operator|->
name|contextHandle
argument_list|()
operator|->
name|shareGroup
argument_list|()
argument_list|)
block|,
name|m_id
argument_list|(
argument|id
argument_list|)
block|{     }
name|GLuint
name|id
argument_list|()
specifier|const
block|{
return|return
name|m_id
return|;
block|}
name|protected
operator|:
name|void
name|invalidateResource
argument_list|()
block|{
name|m_id
operator|=
literal|0
block|;     }
name|void
name|freeResource
argument_list|(
argument|QOpenGLContext *context
argument_list|)
block|{
if|if
condition|(
name|m_id
condition|)
block|{
name|freeResource
argument_list|(
name|QGLContext
operator|::
name|fromOpenGLContext
argument_list|(
name|context
argument_list|)
argument_list|,
name|m_id
argument_list|)
expr_stmt|;
block|}
block|}
name|virtual
name|void
name|freeResource
argument_list|(
argument|QGLContext *ctx
argument_list|,
argument|GLuint id
argument_list|)
operator|=
literal|0
block|;
name|private
operator|:
name|GLuint
name|m_id
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|Func
operator|>
name|class
name|QGLSharedResourceGuard
operator|:
name|public
name|QGLSharedResourceGuardBase
block|{
name|public
operator|:
name|QGLSharedResourceGuard
argument_list|(
argument|QGLContext *context
argument_list|,
argument|GLuint id
argument_list|,
argument|Func func
argument_list|)
operator|:
name|QGLSharedResourceGuardBase
argument_list|(
name|context
argument_list|,
name|id
argument_list|)
block|,
name|m_func
argument_list|(
argument|func
argument_list|)
block|{     }
name|protected
operator|:
name|void
name|freeResource
argument_list|(
argument|QGLContext *ctx
argument_list|,
argument|GLuint id
argument_list|)
block|{
name|m_func
argument_list|(
name|ctx
argument_list|,
name|id
argument_list|)
block|;     }
name|private
operator|:
name|Func
name|m_func
block|; }
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|Func
operator|>
DECL|function|createSharedResourceGuard
name|QGLSharedResourceGuardBase
operator|*
name|createSharedResourceGuard
argument_list|(
argument|QGLContext *context
argument_list|,
argument|GLuint id
argument_list|,
argument|Func cleanupFunc
argument_list|)
block|{
return|return
name|new
name|QGLSharedResourceGuard
operator|<
name|Func
operator|>
operator|(
name|context
operator|,
name|id
operator|,
name|cleanupFunc
operator|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|class
name|QGLExtensionMatcher
block|{
name|public
label|:
name|QGLExtensionMatcher
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
expr_stmt|;
name|QGLExtensionMatcher
argument_list|()
expr_stmt|;
name|bool
name|match
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
decl|const
block|{
name|int
name|str_length
init|=
name|qstrlen
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|str
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|str_length
operator|>
literal|0
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|str
index|[
name|str_length
operator|-
literal|1
index|]
operator|!=
literal|' '
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_offsets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|extension
init|=
name|m_extensions
operator|.
name|constData
argument_list|()
operator|+
name|m_offsets
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|qstrncmp
argument_list|(
name|extension
argument_list|,
name|str
argument_list|,
name|str_length
argument_list|)
operator|==
literal|0
operator|&&
name|extension
index|[
name|str_length
index|]
operator|==
literal|' '
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|private
label|:
name|void
name|init
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|QByteArray
name|m_extensions
decl_stmt|;
name|QVector
operator|<
name|int
operator|>
name|m_offsets
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// this is a class that wraps a QThreadStorage object for storing
end_comment
begin_comment
comment|// thread local instances of the GL 1 and GL 2 paint engines
end_comment
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QGLEngineThreadStorage
block|{
name|public
operator|:
name|QPaintEngine
operator|*
name|engine
argument_list|()
block|{
name|QPaintEngine
operator|*
operator|&
name|localEngine
operator|=
name|storage
operator|.
name|localData
argument_list|()
block|;
if|if
condition|(
operator|!
name|localEngine
condition|)
name|localEngine
operator|=
name|new
name|T
expr_stmt|;
return|return
name|localEngine
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QThreadStorage
operator|<
name|QPaintEngine
operator|*
operator|>
name|storage
expr_stmt|;
end_expr_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGL_P_H
end_comment
end_unit
