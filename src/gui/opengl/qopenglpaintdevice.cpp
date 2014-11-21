begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qopenglpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<qpaintengine.h>
end_include
begin_include
include|#
directive|include
file|<qthreadstorage.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglpaintdevice_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglframebufferobject_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglpaintengine_p.h>
end_include
begin_comment
comment|// for qt_defaultDpiX/Y
end_comment
begin_include
include|#
directive|include
file|<private/qfont_p.h>
end_include
begin_include
include|#
directive|include
file|<qopenglfunctions.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QOpenGLPaintDevice     \brief The QOpenGLPaintDevice class enables painting to an OpenGL context using QPainter.     \since 5.0     \inmodule QtGui      \ingroup painting-3D      The QOpenGLPaintDevice uses the \b current QOpenGL context to render     QPainter draw commands. The context is captured upon construction. It     requires support for OpenGL (ES) 2.0 or higher.      \section1 Performance      The QOpenGLPaintDevice is almost always hardware accelerated and     has the potential of being much faster than software     rasterization. However, it is more sensitive to state changes, and     therefore requires the drawing commands to be carefully ordered to     achieve optimal performance.      \section1 Antialiasing and Quality      Antialiasing in the OpenGL paint engine is done using     multisampling. Most hardware require significantly more memory to     do multisampling and the resulting quality is not on par with the     quality of the software paint engine. The OpenGL paint engine's     strength lies in its performance, not its visual rendering     quality.      \section1 State Changes      When painting to a QOpenGLPaintDevice using QPainter, the state of     the current OpenGL context will be altered by the paint engine to     reflect its needs.  Applications should not rely upon the OpenGL     state being reset to its original conditions, particularly the     current shader program, OpenGL viewport, texture units, and     drawing modes.      \section1 Mixing QPainter and OpenGL      When intermixing QPainter and OpenGL, it is important to notify     QPainter that the OpenGL state may have been cluttered so it can     restore its internal state. This is acheived by calling \l     QPainter::beginNativePainting() before starting the OpenGL     rendering and calling \l QPainter::endNativePainting() after     finishing.      \sa {OpenGL Window Example}  */
end_comment
begin_comment
comment|/*!     Constructs a QOpenGLPaintDevice.      The QOpenGLPaintDevice is only valid for the current context.      \sa QOpenGLContext::currentContext() */
end_comment
begin_constructor
DECL|function|QOpenGLPaintDevice
name|QOpenGLPaintDevice
operator|::
name|QOpenGLPaintDevice
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QOpenGLPaintDevicePrivate
argument_list|(
name|QSize
argument_list|()
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a QOpenGLPaintDevice with the given \a size.      The QOpenGLPaintDevice is only valid for the current context.      \sa QOpenGLContext::currentContext() */
end_comment
begin_constructor
DECL|function|QOpenGLPaintDevice
name|QOpenGLPaintDevice
operator|::
name|QOpenGLPaintDevice
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QOpenGLPaintDevicePrivate
argument_list|(
name|size
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a QOpenGLPaintDevice with the given \a width and \a height.      The QOpenGLPaintDevice is only valid for the current context.      \sa QOpenGLContext::currentContext() */
end_comment
begin_constructor
DECL|function|QOpenGLPaintDevice
name|QOpenGLPaintDevice
operator|::
name|QOpenGLPaintDevice
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QOpenGLPaintDevicePrivate
argument_list|(
name|QSize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal  */
end_comment
begin_constructor
DECL|function|QOpenGLPaintDevice
name|QOpenGLPaintDevice
operator|::
name|QOpenGLPaintDevice
parameter_list|(
name|QOpenGLPaintDevicePrivate
modifier|&
name|dd
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|&
name|dd
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the QOpenGLPaintDevice. */
end_comment
begin_destructor
DECL|function|~QOpenGLPaintDevice
name|QOpenGLPaintDevice
operator|::
name|~
name|QOpenGLPaintDevice
parameter_list|()
block|{
operator|delete
name|d_ptr
operator|->
name|engine
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \fn int QOpenGLPaintDevice::devType() const     \internal     \reimp */
end_comment
begin_constructor
DECL|function|QOpenGLPaintDevicePrivate
name|QOpenGLPaintDevicePrivate
operator|::
name|QOpenGLPaintDevicePrivate
parameter_list|(
specifier|const
name|QSize
modifier|&
name|sz
parameter_list|)
member_init_list|:
name|size
argument_list|(
name|sz
argument_list|)
member_init_list|,
name|ctx
argument_list|(
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
member_init_list|,
name|dpmx
argument_list|(
name|qt_defaultDpiX
argument_list|()
operator|*
literal|100.
operator|/
literal|2.54
argument_list|)
member_init_list|,
name|dpmy
argument_list|(
name|qt_defaultDpiY
argument_list|()
operator|*
literal|100.
operator|/
literal|2.54
argument_list|)
member_init_list|,
name|devicePixelRatio
argument_list|(
literal|1.0
argument_list|)
member_init_list|,
name|flipped
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|engine
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_class
DECL|class|QOpenGLEngineThreadStorage
class|class
name|QOpenGLEngineThreadStorage
block|{
public|public:
DECL|function|engine
name|QPaintEngine
modifier|*
name|engine
parameter_list|()
block|{
name|QPaintEngine
modifier|*
modifier|&
name|localEngine
init|=
name|storage
operator|.
name|localData
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|localEngine
condition|)
name|localEngine
operator|=
operator|new
name|QOpenGL2PaintEngineEx
expr_stmt|;
return|return
name|localEngine
return|;
block|}
private|private:
DECL|member|storage
name|QThreadStorage
argument_list|<
name|QPaintEngine
modifier|*
argument_list|>
name|storage
decl_stmt|;
block|}
class|;
end_class
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QOpenGLEngineThreadStorage
argument_list|,
argument|qt_opengl_engine
argument_list|)
end_macro
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|QOpenGLPaintDevice
operator|::
name|paintEngine
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|d_ptr
operator|->
name|engine
condition|)
return|return
name|d_ptr
operator|->
name|engine
return|;
name|QPaintEngine
modifier|*
name|engine
init|=
name|qt_opengl_engine
argument_list|()
operator|->
name|engine
argument_list|()
decl_stmt|;
if|if
condition|(
name|engine
operator|->
name|isActive
argument_list|()
operator|&&
name|engine
operator|->
name|paintDevice
argument_list|()
operator|!=
name|this
condition|)
block|{
name|d_ptr
operator|->
name|engine
operator|=
operator|new
name|QOpenGL2PaintEngineEx
expr_stmt|;
return|return
name|d_ptr
operator|->
name|engine
return|;
block|}
return|return
name|engine
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the OpenGL context associated with the paint device. */
end_comment
begin_function
DECL|function|context
name|QOpenGLContext
modifier|*
name|QOpenGLPaintDevice
operator|::
name|context
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|ctx
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the pixel size of the paint device.      \sa setSize() */
end_comment
begin_function
DECL|function|size
name|QSize
name|QOpenGLPaintDevice
operator|::
name|size
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|size
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the pixel size of the paint device to \a size.      \sa size() */
end_comment
begin_function
DECL|function|setSize
name|void
name|QOpenGLPaintDevice
operator|::
name|setSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|d_ptr
operator|->
name|size
operator|=
name|size
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the device pixel ratio for the paint device to \a devicePixelRatio. */
end_comment
begin_function
DECL|function|setDevicePixelRatio
name|void
name|QOpenGLPaintDevice
operator|::
name|setDevicePixelRatio
parameter_list|(
name|qreal
name|devicePixelRatio
parameter_list|)
block|{
name|d_ptr
operator|->
name|devicePixelRatio
operator|=
name|devicePixelRatio
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|metric
name|int
name|QOpenGLPaintDevice
operator|::
name|metric
parameter_list|(
name|QPaintDevice
operator|::
name|PaintDeviceMetric
name|metric
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|metric
condition|)
block|{
case|case
name|PdmWidth
case|:
return|return
name|d_ptr
operator|->
name|size
operator|.
name|width
argument_list|()
return|;
case|case
name|PdmHeight
case|:
return|return
name|d_ptr
operator|->
name|size
operator|.
name|height
argument_list|()
return|;
case|case
name|PdmDepth
case|:
return|return
literal|32
return|;
case|case
name|PdmWidthMM
case|:
return|return
name|qRound
argument_list|(
name|d_ptr
operator|->
name|size
operator|.
name|width
argument_list|()
operator|*
literal|1000
operator|/
name|d_ptr
operator|->
name|dpmx
argument_list|)
return|;
case|case
name|PdmHeightMM
case|:
return|return
name|qRound
argument_list|(
name|d_ptr
operator|->
name|size
operator|.
name|height
argument_list|()
operator|*
literal|1000
operator|/
name|d_ptr
operator|->
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
name|PdmDpiX
case|:
return|return
name|qRound
argument_list|(
name|d_ptr
operator|->
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
name|d_ptr
operator|->
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
name|d_ptr
operator|->
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
name|d_ptr
operator|->
name|dpmy
operator|*
literal|0.0254
argument_list|)
return|;
case|case
name|PdmDevicePixelRatio
case|:
return|return
name|d_ptr
operator|->
name|devicePixelRatio
return|;
default|default:
name|qWarning
argument_list|(
literal|"QOpenGLPaintDevice::metric() - metric %d not known"
argument_list|,
name|metric
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the number of pixels per meter horizontally.      \sa setDotsPerMeterX() */
end_comment
begin_function
DECL|function|dotsPerMeterX
name|qreal
name|QOpenGLPaintDevice
operator|::
name|dotsPerMeterX
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|dpmx
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of pixels per meter vertically.      \sa setDotsPerMeterY() */
end_comment
begin_function
DECL|function|dotsPerMeterY
name|qreal
name|QOpenGLPaintDevice
operator|::
name|dotsPerMeterY
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|dpmy
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the number of pixels per meter horizontally to \a dpmx.      \sa dotsPerMeterX() */
end_comment
begin_function
DECL|function|setDotsPerMeterX
name|void
name|QOpenGLPaintDevice
operator|::
name|setDotsPerMeterX
parameter_list|(
name|qreal
name|dpmx
parameter_list|)
block|{
name|d_ptr
operator|->
name|dpmx
operator|=
name|dpmx
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the number of pixels per meter vertically to \a dpmy.      \sa dotsPerMeterY() */
end_comment
begin_function
DECL|function|setDotsPerMeterY
name|void
name|QOpenGLPaintDevice
operator|::
name|setDotsPerMeterY
parameter_list|(
name|qreal
name|dpmy
parameter_list|)
block|{
name|d_ptr
operator|->
name|dpmx
operator|=
name|dpmy
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets whether painting should be flipped around the Y-axis or not to \a flipped.      \sa paintFlipped() */
end_comment
begin_function
DECL|function|setPaintFlipped
name|void
name|QOpenGLPaintDevice
operator|::
name|setPaintFlipped
parameter_list|(
name|bool
name|flipped
parameter_list|)
block|{
name|d_ptr
operator|->
name|flipped
operator|=
name|flipped
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if painting is flipped around the Y-axis.      \sa setPaintFlipped() */
end_comment
begin_function
DECL|function|paintFlipped
name|bool
name|QOpenGLPaintDevice
operator|::
name|paintFlipped
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|flipped
return|;
block|}
end_function
begin_comment
comment|/*!     This virtual method is provided as a callback to allow re-binding a target     frame buffer object or context when different QOpenGLPaintDevice instances     are issuing draw calls alternately.      \l{QPainter::beginNativePainting()}{beginNativePainting()} will also trigger     this method.      The default implementation does nothing. */
end_comment
begin_function
DECL|function|ensureActiveTarget
name|void
name|QOpenGLPaintDevice
operator|::
name|ensureActiveTarget
parameter_list|()
block|{ }
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
