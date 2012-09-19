begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenwfdoutputbuffer.h"
end_include
begin_include
include|#
directive|include
file|"qopenwfdport.h"
end_include
begin_constructor
DECL|function|QOpenWFDOutputBuffer
name|QOpenWFDOutputBuffer
operator|::
name|QOpenWFDOutputBuffer
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|QOpenWFDPort
modifier|*
name|port
parameter_list|)
member_init_list|:
name|mPort
argument_list|(
name|port
argument_list|)
member_init_list|,
name|mAvailable
argument_list|(
literal|true
argument_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"creating output buffer for size"
operator|<<
name|size
expr_stmt|;
name|glGenRenderbuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|mRbo
argument_list|)
expr_stmt|;
name|glBindRenderbuffer
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|mRbo
argument_list|)
expr_stmt|;
name|mGbm_buffer
operator|=
name|gbm_bo_create
argument_list|(
name|port
operator|->
name|device
argument_list|()
operator|->
name|gbmDevice
argument_list|()
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
name|GBM_BO_FORMAT_XRGB8888
argument_list|,
name|GBM_BO_USE_SCANOUT
operator||
name|GBM_BO_USE_RENDERING
argument_list|)
expr_stmt|;
name|mEglImage
operator|=
name|port
operator|->
name|device
argument_list|()
operator|->
name|eglCreateImage
argument_list|(
name|port
operator|->
name|device
argument_list|()
operator|->
name|eglDisplay
argument_list|()
argument_list|,
literal|0
argument_list|,
name|EGL_NATIVE_PIXMAP_KHR
argument_list|,
name|mGbm_buffer
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|port
operator|->
name|device
argument_list|()
operator|->
name|glEglImageTargetRenderBufferStorage
argument_list|(
name|GL_RENDERBUFFER
argument_list|,
name|mEglImage
argument_list|)
expr_stmt|;
name|mWfdSource
operator|=
name|wfdCreateSourceFromImage
argument_list|(
name|port
operator|->
name|device
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|,
name|port
operator|->
name|pipeline
argument_list|()
argument_list|,
name|mEglImage
argument_list|,
name|WFD_NONE
argument_list|)
expr_stmt|;
if|if
condition|(
name|mWfdSource
operator|==
name|WFD_INVALID_HANDLE
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to create wfdSource from image"
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QOpenWFDOutputBuffer
name|QOpenWFDOutputBuffer
operator|::
name|~
name|QOpenWFDOutputBuffer
parameter_list|()
block|{
name|wfdDestroySource
argument_list|(
name|mPort
operator|->
name|device
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|,
name|mWfdSource
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mPort
operator|->
name|device
argument_list|()
operator|->
name|eglDestroyImage
argument_list|(
name|mPort
operator|->
name|device
argument_list|()
operator|->
name|eglDisplay
argument_list|()
argument_list|,
name|mEglImage
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"could not delete eglImage"
expr_stmt|;
block|}
name|gbm_bo_destroy
argument_list|(
name|mGbm_buffer
argument_list|)
expr_stmt|;
name|glDeleteRenderbuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|mRbo
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|bindToCurrentFbo
name|void
name|QOpenWFDOutputBuffer
operator|::
name|bindToCurrentFbo
parameter_list|()
block|{
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_COLOR_ATTACHMENT0
argument_list|,
name|GL_RENDERBUFFER
argument_list|,
name|mRbo
argument_list|)
expr_stmt|;
if|if
condition|(
name|glCheckFramebufferStatus
argument_list|(
name|GL_FRAMEBUFFER
argument_list|)
operator|!=
name|GL_FRAMEBUFFER_COMPLETE
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"framebuffer not ready!"
expr_stmt|;
block|}
block|}
end_function
end_unit
