begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QGLPixelBuffer     \brief The QGLPixelBuffer class encapsulates an OpenGL pbuffer.     \since 4.1      \ingroup painting-3D      Rendering into a pbuffer is normally done using full hardware     acceleration. This can be significantly faster than rendering     into a QPixmap.      There are three approaches to using this class:      \list 1     \o \bold{We can draw into the pbuffer and convert it to a QImage        using toImage().} This is normally much faster than calling        QGLWidget::renderPixmap().      \o \bold{We can draw into the pbuffer and copy the contents into        an OpenGL texture using updateDynamicTexture().} This allows        us to create dynamic textures and works on all systems        with pbuffer support.      \o \bold{On systems that support it, we can bind the pbuffer to        an OpenGL texture.} The texture is then updated automatically        when the pbuffer contents change, eliminating the need for        additional copy operations. This is supported only on Windows        and Mac OS X systems that provide the \c render_texture        extension. Note that under Windows, a multi-sampled pbuffer        can't be used in conjunction with the \c render_texture        extension. If a multi-sampled pbuffer is requested under        Windows, the \c render_texture extension is turned off for that        pbuffer.       \endlist       \section1 Threading      As of Qt 4.8, it's possible to render into a QGLPixelBuffer using     a QPainter in a separate thread. Note that OpenGL 2.0 or OpenGL ES     2.0 is required for this to work.      Pbuffers are provided by the OpenGL \c pbuffer extension; call     hasOpenGLPbuffer() to find out if the system provides pbuffers.      \sa {opengl/pbuffers}{Pbuffers Example} */
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<gl2paintengineex/qpaintengineex_opengl2_p.h>
end_include
begin_include
include|#
directive|include
file|<qglpixelbuffer.h>
end_include
begin_include
include|#
directive|include
file|<private/qglpixelbuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qfont_p.h>
end_include
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|extern
name|QImage
name|qt_gl_read_framebuffer
parameter_list|(
specifier|const
name|QSize
modifier|&
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|context
name|QGLContext
modifier|*
name|QGLPBufferGLPaintDevice
operator|::
name|context
parameter_list|()
specifier|const
block|{
return|return
name|pbuf
operator|->
name|d_func
argument_list|()
operator|->
name|qctx
return|;
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QGLPBufferGLPaintDevice
operator|::
name|endPaint
parameter_list|()
block|{
name|glFlush
argument_list|()
expr_stmt|;
name|QGLPaintDevice
operator|::
name|endPaint
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setPBuffer
name|void
name|QGLPBufferGLPaintDevice
operator|::
name|setPBuffer
parameter_list|(
name|QGLPixelBuffer
modifier|*
name|pb
parameter_list|)
block|{
name|pbuf
operator|=
name|pb
expr_stmt|;
block|}
end_function
begin_function
DECL|function|common_init
name|void
name|QGLPixelBufferPrivate
operator|::
name|common_init
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QGLFormat
modifier|&
name|format
parameter_list|,
name|QGLWidget
modifier|*
name|shareWidget
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|init
argument_list|(
name|size
argument_list|,
name|format
argument_list|,
name|shareWidget
argument_list|)
condition|)
block|{
name|req_size
operator|=
name|size
expr_stmt|;
name|req_format
operator|=
name|format
expr_stmt|;
name|req_shareWidget
operator|=
name|shareWidget
expr_stmt|;
name|invalid
operator|=
literal|false
expr_stmt|;
name|qctx
operator|=
operator|new
name|QGLContext
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|qctx
operator|->
name|d_func
argument_list|()
operator|->
name|sharing
operator|=
operator|(
name|shareWidget
operator|!=
literal|0
operator|)
expr_stmt|;
if|if
condition|(
name|shareWidget
operator|!=
literal|0
operator|&&
name|shareWidget
operator|->
name|d_func
argument_list|()
operator|->
name|glcx
condition|)
block|{
name|QGLContextGroup
operator|::
name|addShare
argument_list|(
name|qctx
argument_list|,
name|shareWidget
operator|->
name|d_func
argument_list|()
operator|->
name|glcx
argument_list|)
expr_stmt|;
name|shareWidget
operator|->
name|d_func
argument_list|()
operator|->
name|glcx
operator|->
name|d_func
argument_list|()
operator|->
name|sharing
operator|=
literal|true
expr_stmt|;
block|}
name|glDevice
operator|.
name|setPBuffer
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|qctx
operator|->
name|d_func
argument_list|()
operator|->
name|paintDevice
operator|=
name|q
expr_stmt|;
name|qctx
operator|->
name|d_func
argument_list|()
operator|->
name|valid
operator|=
literal|true
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Constructs an OpenGL pbuffer of the given \a size. If no \a     format is specified, the \l{QGLFormat::defaultFormat()}{default     format} is used. If the \a shareWidget parameter points to a     valid QGLWidget, the pbuffer will share its context with \a     shareWidget.      If you intend to bind this pbuffer as a dynamic texture, the width     and height components of \c size must be powers of two (e.g., 512     x 128).      \sa size(), format() */
end_comment
begin_constructor
DECL|function|QGLPixelBuffer
name|QGLPixelBuffer
operator|::
name|QGLPixelBuffer
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QGLFormat
modifier|&
name|format
parameter_list|,
name|QGLWidget
modifier|*
name|shareWidget
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QGLPixelBufferPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
name|d
operator|->
name|common_init
argument_list|(
name|size
argument_list|,
name|format
argument_list|,
name|shareWidget
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*! \overload      Constructs an OpenGL pbuffer with the \a width and \a height. If     no \a format is specified, the     \l{QGLFormat::defaultFormat()}{default format} is used. If the \a     shareWidget parameter points to a valid QGLWidget, the pbuffer     will share its context with \a shareWidget.      If you intend to bind this pbuffer as a dynamic texture, the width     and height components of \c size must be powers of two (e.g., 512     x 128).      \sa size(), format() */
end_comment
begin_constructor
DECL|function|QGLPixelBuffer
name|QGLPixelBuffer
operator|::
name|QGLPixelBuffer
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
specifier|const
name|QGLFormat
modifier|&
name|format
parameter_list|,
name|QGLWidget
modifier|*
name|shareWidget
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QGLPixelBufferPrivate
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
name|d
operator|->
name|common_init
argument_list|(
name|QSize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
argument_list|,
name|format
argument_list|,
name|shareWidget
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*! \fn QGLPixelBuffer::~QGLPixelBuffer()      Destroys the pbuffer and frees any allocated resources. */
end_comment
begin_destructor
DECL|function|~QGLPixelBuffer
name|QGLPixelBuffer
operator|::
name|~
name|QGLPixelBuffer
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
comment|// defined in qpaintengine_opengl.cpp
name|QGLContext
modifier|*
name|current
init|=
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|QGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|current
operator|!=
name|d
operator|->
name|qctx
condition|)
name|makeCurrent
argument_list|()
expr_stmt|;
name|d
operator|->
name|cleanup
argument_list|()
expr_stmt|;
operator|delete
name|d
operator|->
name|qctx
expr_stmt|;
if|if
condition|(
name|current
operator|&&
name|current
operator|!=
name|d
operator|->
name|qctx
condition|)
name|current
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*! \fn bool QGLPixelBuffer::makeCurrent()      Makes this pbuffer the current OpenGL rendering context. Returns     true on success; otherwise returns false.      \sa QGLContext::makeCurrent(), doneCurrent() */
end_comment
begin_function
DECL|function|makeCurrent
name|bool
name|QGLPixelBuffer
operator|::
name|makeCurrent
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|invalid
condition|)
return|return
literal|false
return|;
name|d
operator|->
name|qctx
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*! \fn bool QGLPixelBuffer::doneCurrent()      Makes no context the current OpenGL context. Returns true on     success; otherwise returns false. */
end_comment
begin_function
DECL|function|doneCurrent
name|bool
name|QGLPixelBuffer
operator|::
name|doneCurrent
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|invalid
condition|)
return|return
literal|false
return|;
name|d
operator|->
name|qctx
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     \fn GLuint QGLPixelBuffer::generateDynamicTexture() const      Generates and binds a 2D GL texture that is the same size as the     pbuffer, and returns the texture's ID. This can be used in     conjunction with bindToDynamicTexture() and     updateDynamicTexture().      \sa size() */
end_comment
begin_comment
comment|/*! \fn bool QGLPixelBuffer::bindToDynamicTexture(GLuint texture_id)      Binds the texture specified by \a texture_id to this pbuffer.     Returns true on success; otherwise returns false.      The texture must be of the same size and format as the pbuffer.      To unbind the texture, call releaseFromDynamicTexture(). While     the texture is bound, it is updated automatically when the     pbuffer contents change, eliminating the need for additional copy     operations.      Example:      \snippet doc/src/snippets/code/src_opengl_qglpixelbuffer.cpp 0      \warning This function uses the \c {render_texture} extension,     which is currently not supported under X11. An alternative that     works on all systems (including X11) is to manually copy the     pbuffer contents to a texture using updateDynamicTexture().      \warning For the bindToDynamicTexture() call to succeed on the     Mac OS X, the pbuffer needs a shared context, i.e. the     QGLPixelBuffer must be created with a share widget.      \sa generateDynamicTexture(), releaseFromDynamicTexture() */
end_comment
begin_comment
comment|/*! \fn void QGLPixelBuffer::releaseFromDynamicTexture()      Releases the pbuffer from any previously bound texture.      \sa bindToDynamicTexture() */
end_comment
begin_comment
comment|/*! \fn bool QGLPixelBuffer::hasOpenGLPbuffers()      Returns true if the OpenGL \c pbuffer extension is present on     this system; otherwise returns false. */
end_comment
begin_comment
comment|/*!     Copies the pbuffer contents into the texture specified with \a     texture_id.      The texture must be of the same size and format as the pbuffer.      Example:      \snippet doc/src/snippets/code/src_opengl_qglpixelbuffer.cpp 1      An alternative on Windows and Mac OS X systems that support the     \c render_texture extension is to use bindToDynamicTexture() to     get dynamic updates of the texture.      \sa generateDynamicTexture(), bindToDynamicTexture() */
end_comment
begin_function
DECL|function|updateDynamicTexture
name|void
name|QGLPixelBuffer
operator|::
name|updateDynamicTexture
parameter_list|(
name|GLuint
name|texture_id
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|invalid
condition|)
return|return;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|texture_id
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_OPENGL_ES
name|glCopyTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA8
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|d
operator|->
name|req_size
operator|.
name|width
argument_list|()
argument_list|,
name|d
operator|->
name|req_size
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
name|glCopyTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|d
operator|->
name|req_size
operator|.
name|width
argument_list|()
argument_list|,
name|d
operator|->
name|req_size
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     Returns the size of the pbuffer. */
end_comment
begin_function
DECL|function|size
name|QSize
name|QGLPixelBuffer
operator|::
name|size
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|req_size
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the contents of the pbuffer as a QImage. */
end_comment
begin_function
DECL|function|toImage
name|QImage
name|QGLPixelBuffer
operator|::
name|toImage
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|invalid
condition|)
return|return
name|QImage
argument_list|()
return|;
cast|const_cast
argument_list|<
name|QGLPixelBuffer
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
return|return
name|qt_gl_read_framebuffer
argument_list|(
name|d
operator|->
name|req_size
argument_list|,
name|d
operator|->
name|format
operator|.
name|alpha
argument_list|()
argument_list|,
literal|true
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the native pbuffer handle. */
end_comment
begin_function
DECL|function|handle
name|Qt
operator|::
name|HANDLE
name|QGLPixelBuffer
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|invalid
condition|)
return|return
literal|0
return|;
return|return
operator|(
name|Qt
operator|::
name|HANDLE
operator|)
name|d
operator|->
name|pbuf
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if this pbuffer is valid; otherwise returns false. */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QGLPixelBuffer
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
return|return
operator|!
name|d
operator|->
name|invalid
return|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QGLEngineThreadStorage<QGL2PaintEngineEx>
argument_list|,
argument|qt_buffer_2_engine
argument_list|)
end_macro
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|QGLPixelBuffer
operator|::
name|paintEngine
parameter_list|()
specifier|const
block|{
return|return
name|qt_buffer_2_engine
argument_list|()
operator|->
name|engine
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|metric
name|int
name|QGLPixelBuffer
operator|::
name|metric
parameter_list|(
name|PaintDeviceMetric
name|metric
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
name|float
name|dpmx
init|=
name|qt_defaultDpiX
argument_list|()
operator|*
literal|100.
operator|/
literal|2.54
decl_stmt|;
name|float
name|dpmy
init|=
name|qt_defaultDpiY
argument_list|()
operator|*
literal|100.
operator|/
literal|2.54
decl_stmt|;
name|int
name|w
init|=
name|d
operator|->
name|req_size
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|h
init|=
name|d
operator|->
name|req_size
operator|.
name|height
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|PdmWidth
case|:
return|return
name|w
return|;
case|case
name|PdmHeight
case|:
return|return
name|h
return|;
case|case
name|PdmWidthMM
case|:
return|return
name|qRound
argument_list|(
name|w
operator|*
literal|1000
operator|/
name|dpmx
argument_list|)
return|;
case|case
name|PdmHeightMM
case|:
return|return
name|qRound
argument_list|(
name|h
operator|*
literal|1000
operator|/
name|dpmy
argument_list|)
return|;
case|case
name|PdmNumColors
case|:
return|return
literal|0
return|;
case|case
name|PdmDepth
case|:
return|return
literal|32
return|;
comment|//d->depth;
case|case
name|PdmDpiX
case|:
return|return
name|qRound
argument_list|(
name|dpmx
operator|*
literal|0.0254
argument_list|)
return|;
case|case
name|PdmDpiY
case|:
return|return
name|qRound
argument_list|(
name|dpmy
operator|*
literal|0.0254
argument_list|)
return|;
case|case
name|PdmPhysicalDpiX
case|:
return|return
name|qRound
argument_list|(
name|dpmx
operator|*
literal|0.0254
argument_list|)
return|;
case|case
name|PdmPhysicalDpiY
case|:
return|return
name|qRound
argument_list|(
name|dpmy
operator|*
literal|0.0254
argument_list|)
return|;
default|default:
name|qWarning
argument_list|(
literal|"QGLPixelBuffer::metric(), Unhandled metric type: %d\n"
argument_list|,
name|metric
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Generates and binds a 2D GL texture to the current context, based     on \a image. The generated texture id is returned and can be used     in later glBindTexture() calls.      The \a target parameter specifies the texture target.      Equivalent to calling QGLContext::bindTexture().      \sa deleteTexture() */
end_comment
begin_function
DECL|function|bindTexture
name|GLuint
name|QGLPixelBuffer
operator|::
name|bindTexture
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|GLenum
name|target
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_OPENGL_ES
return|return
name|d
operator|->
name|qctx
operator|->
name|bindTexture
argument_list|(
name|image
argument_list|,
name|target
argument_list|,
name|GLint
argument_list|(
name|GL_RGBA8
argument_list|)
argument_list|)
return|;
else|#
directive|else
return|return
name|d
operator|->
name|qctx
operator|->
name|bindTexture
argument_list|(
name|image
argument_list|,
name|target
argument_list|,
name|GL_RGBA
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*! \overload      Generates and binds a 2D GL texture based on \a pixmap.      Equivalent to calling QGLContext::bindTexture().      \sa deleteTexture() */
end_comment
begin_function
DECL|function|bindTexture
name|GLuint
name|QGLPixelBuffer
operator|::
name|bindTexture
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
name|GLenum
name|target
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_OPENGL_ES
return|return
name|d
operator|->
name|qctx
operator|->
name|bindTexture
argument_list|(
name|pixmap
argument_list|,
name|target
argument_list|,
name|GLint
argument_list|(
name|GL_RGBA8
argument_list|)
argument_list|)
return|;
else|#
directive|else
return|return
name|d
operator|->
name|qctx
operator|->
name|bindTexture
argument_list|(
name|pixmap
argument_list|,
name|target
argument_list|,
name|GL_RGBA
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*! \overload      Reads the DirectDrawSurface (DDS) compressed file \a fileName and     generates a 2D GL texture from it.      Equivalent to calling QGLContext::bindTexture().      \sa deleteTexture() */
end_comment
begin_function
DECL|function|bindTexture
name|GLuint
name|QGLPixelBuffer
operator|::
name|bindTexture
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|qctx
operator|->
name|bindTexture
argument_list|(
name|fileName
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Removes the texture identified by \a texture_id from the texture cache.      Equivalent to calling QGLContext::deleteTexture().  */
end_comment
begin_function
DECL|function|deleteTexture
name|void
name|QGLPixelBuffer
operator|::
name|deleteTexture
parameter_list|(
name|GLuint
name|texture_id
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
name|d
operator|->
name|qctx
operator|->
name|deleteTexture
argument_list|(
name|texture_id
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4      Draws the given texture, \a textureId, to the given target rectangle,     \a target, in OpenGL model space. The \a textureTarget should be a 2D     texture target.      Equivalent to the corresponding QGLContext::drawTexture(). */
end_comment
begin_function
DECL|function|drawTexture
name|void
name|QGLPixelBuffer
operator|::
name|drawTexture
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|target
parameter_list|,
name|GLuint
name|textureId
parameter_list|,
name|GLenum
name|textureTarget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
name|d
operator|->
name|qctx
operator|->
name|drawTexture
argument_list|(
name|target
argument_list|,
name|textureId
argument_list|,
name|textureTarget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 4.4      Draws the given texture, \a textureId, at the given \a point in OpenGL model     space. The textureTarget parameter should be a 2D texture target.      Equivalent to the corresponding QGLContext::drawTexture(). */
end_comment
begin_function
DECL|function|drawTexture
name|void
name|QGLPixelBuffer
operator|::
name|drawTexture
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|point
parameter_list|,
name|GLuint
name|textureId
parameter_list|,
name|GLenum
name|textureTarget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
name|d
operator|->
name|qctx
operator|->
name|drawTexture
argument_list|(
name|point
argument_list|,
name|textureId
argument_list|,
name|textureTarget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the format of the pbuffer. The format may be different     from the one that was requested. */
end_comment
begin_function
DECL|function|format
name|QGLFormat
name|QGLPixelBuffer
operator|::
name|format
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|format
return|;
block|}
end_function
begin_comment
comment|/*! \fn int QGLPixelBuffer::devType() const     \internal */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
