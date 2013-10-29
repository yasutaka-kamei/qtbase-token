begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfsbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qeglfscompositor.h"
end_include
begin_include
include|#
directive|include
file|"qeglfscursor.h"
end_include
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|"qeglfscontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLPaintDevice>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLShaderProgram>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEglFSBackingStore
name|QEglFSBackingStore
operator|::
name|QEglFSBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
member_init_list|,
name|m_window
argument_list|(
cast|static_cast
argument_list|<
name|QEglFSWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
argument_list|)
member_init_list|,
name|m_texture
argument_list|(
literal|0
argument_list|)
block|{
name|m_window
operator|->
name|setBackingStore
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QEglFSBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
operator|&
name|m_image
return|;
block|}
end_function
begin_function
DECL|function|updateTexture
name|void
name|QEglFSBackingStore
operator|::
name|updateTexture
parameter_list|()
block|{
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_texture
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_dirty
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QRegion
name|fixed
decl_stmt|;
name|QRect
name|imageRect
init|=
name|m_image
operator|.
name|rect
argument_list|()
decl_stmt|;
name|m_dirty
operator||=
name|imageRect
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|m_dirty
operator|.
name|rects
argument_list|()
control|)
block|{
comment|// intersect with image rect to be sure
name|QRect
name|r
init|=
name|imageRect
operator|&
name|rect
decl_stmt|;
comment|// if the rect is wide enough it's cheaper to just
comment|// extend it instead of doing an image copy
if|if
condition|(
name|r
operator|.
name|width
argument_list|()
operator|>=
name|imageRect
operator|.
name|width
argument_list|()
operator|/
literal|2
condition|)
block|{
name|r
operator|.
name|setX
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|r
operator|.
name|setWidth
argument_list|(
name|imageRect
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|fixed
operator||=
name|r
expr_stmt|;
block|}
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|fixed
operator|.
name|rects
argument_list|()
control|)
block|{
comment|// if the sub-rect is full-width we can pass the image data directly to
comment|// OpenGL instead of copying, since there's no gap between scanlines
if|if
condition|(
name|rect
operator|.
name|width
argument_list|()
operator|==
name|imageRect
operator|.
name|width
argument_list|()
condition|)
block|{
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|m_image
operator|.
name|constScanLine
argument_list|(
name|rect
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|m_image
operator|.
name|copy
argument_list|(
name|rect
argument_list|)
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|m_dirty
operator|=
name|QRegion
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QEglFSBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglBackingStore::flush %p"
argument_list|,
name|window
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QEglFSWindow
modifier|*
name|rootWin
init|=
name|m_window
operator|->
name|screen
argument_list|()
operator|->
name|rootWindow
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|rootWin
operator|||
operator|!
name|rootWin
operator|->
name|isRaster
argument_list|()
condition|)
return|return;
name|m_window
operator|->
name|create
argument_list|()
expr_stmt|;
name|rootWin
operator|->
name|screen
argument_list|()
operator|->
name|rootContext
argument_list|()
operator|->
name|makeCurrent
argument_list|(
name|rootWin
operator|->
name|window
argument_list|()
argument_list|)
expr_stmt|;
name|updateTexture
argument_list|()
expr_stmt|;
name|QEglFSCompositor
operator|::
name|instance
argument_list|()
operator|->
name|schedule
argument_list|(
name|rootWin
operator|->
name|screen
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QEglFSBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|rgn
parameter_list|)
block|{
name|m_dirty
operator||=
name|rgn
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QEglFSBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|staticContents
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|staticContents
argument_list|)
expr_stmt|;
name|QEglFSWindow
modifier|*
name|rootWin
init|=
name|m_window
operator|->
name|screen
argument_list|()
operator|->
name|rootWindow
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|rootWin
operator|||
operator|!
name|rootWin
operator|->
name|isRaster
argument_list|()
condition|)
return|return;
name|m_image
operator|=
name|QImage
argument_list|(
name|size
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|m_window
operator|->
name|create
argument_list|()
expr_stmt|;
name|rootWin
operator|->
name|screen
argument_list|()
operator|->
name|rootContext
argument_list|()
operator|->
name|makeCurrent
argument_list|(
name|rootWin
operator|->
name|window
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_texture
condition|)
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_texture
argument_list|)
expr_stmt|;
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_texture
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_texture
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
