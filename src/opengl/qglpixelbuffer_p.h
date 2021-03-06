begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLPIXELBUFFER_P_H
end_ifndef
begin_define
DECL|macro|QGLPIXELBUFFER_P_H
define|#
directive|define
name|QGLPIXELBUFFER_P_H
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
comment|// of the QLibrary class.  This header file may change from
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
file|"QtOpenGL/qglpixelbuffer.h"
end_include
begin_include
include|#
directive|include
file|<private/qgl_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qglpaintdevice_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEglContext
name|class
name|QEglContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLFramebufferObject
name|class
name|QOpenGLFramebufferObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGLPBufferGLPaintDevice
range|:
name|public
name|QGLPaintDevice
block|{
name|public
operator|:
name|virtual
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|{
return|return
name|pbuf
operator|->
name|paintEngine
argument_list|()
return|;
block|}
name|virtual
name|QSize
name|size
argument_list|()
specifier|const
block|{
return|return
name|pbuf
operator|->
name|size
argument_list|()
return|;
block|}
name|virtual
name|QGLContext
operator|*
name|context
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|beginPaint
argument_list|()
block|;
name|virtual
name|void
name|endPaint
argument_list|()
block|;
name|void
name|setPBuffer
argument_list|(
name|QGLPixelBuffer
operator|*
name|pb
argument_list|)
block|;
name|void
name|setFbo
argument_list|(
argument|GLuint fbo
argument_list|)
block|;
name|private
operator|:
name|QGLPixelBuffer
operator|*
name|pbuf
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGLPixelBufferPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGLPixelBuffer
argument_list|)
name|public
label|:
name|QGLPixelBufferPrivate
argument_list|(
name|QGLPixelBuffer
operator|*
name|q
argument_list|)
operator|:
name|q_ptr
argument_list|(
name|q
argument_list|)
operator|,
name|invalid
argument_list|(
name|true
argument_list|)
operator|,
name|qctx
argument_list|(
literal|0
argument_list|)
operator|,
name|widget
argument_list|(
literal|0
argument_list|)
operator|,
name|fbo
argument_list|(
literal|0
argument_list|)
operator|,
name|blit_fbo
argument_list|(
literal|0
argument_list|)
operator|,
name|pbuf
argument_list|(
literal|0
argument_list|)
operator|,
name|ctx
argument_list|(
literal|0
argument_list|)
block|{     }
name|bool
name|init
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
specifier|const
name|QGLFormat
operator|&
name|f
argument_list|,
name|QGLWidget
operator|*
name|shareWidget
argument_list|)
expr_stmt|;
name|void
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
name|f
parameter_list|,
name|QGLWidget
modifier|*
name|shareWidget
parameter_list|)
function_decl|;
name|bool
name|cleanup
parameter_list|()
function_decl|;
name|QGLPixelBuffer
modifier|*
name|q_ptr
decl_stmt|;
name|bool
name|invalid
decl_stmt|;
name|QGLContext
modifier|*
name|qctx
decl_stmt|;
name|QGLPBufferGLPaintDevice
name|glDevice
decl_stmt|;
name|QGLWidget
modifier|*
name|widget
decl_stmt|;
name|QOpenGLFramebufferObject
modifier|*
name|fbo
decl_stmt|;
name|QOpenGLFramebufferObject
modifier|*
name|blit_fbo
decl_stmt|;
name|QGLFormat
name|format
decl_stmt|;
name|QGLFormat
name|req_format
decl_stmt|;
name|QPointer
operator|<
name|QGLWidget
operator|>
name|req_shareWidget
expr_stmt|;
name|QSize
name|req_size
decl_stmt|;
comment|//stubs
name|void
modifier|*
name|pbuf
decl_stmt|;
name|void
modifier|*
name|ctx
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGLPIXELBUFFER_P_H
end_comment
end_unit
