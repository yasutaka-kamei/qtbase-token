begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLBUFFER_H
end_ifndef
begin_define
DECL|macro|QGLBUFFER_H
define|#
directive|define
name|QGLBUFFER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/qgl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGLBufferPrivate
name|class
name|QGLBufferPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLBuffer
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|VertexBuffer
init|=
literal|0x8892
block|,
comment|// GL_ARRAY_BUFFER
name|IndexBuffer
init|=
literal|0x8893
block|,
comment|// GL_ELEMENT_ARRAY_BUFFER
name|PixelPackBuffer
init|=
literal|0x88EB
block|,
comment|// GL_PIXEL_PACK_BUFFER
name|PixelUnpackBuffer
init|=
literal|0x88EC
comment|// GL_PIXEL_UNPACK_BUFFER
block|}
enum|;
name|QGLBuffer
argument_list|()
expr_stmt|;
name|explicit
name|QGLBuffer
argument_list|(
name|QGLBuffer
operator|::
name|Type
name|type
argument_list|)
decl_stmt|;
name|QGLBuffer
argument_list|(
specifier|const
name|QGLBuffer
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QGLBuffer
argument_list|()
expr_stmt|;
name|QGLBuffer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QGLBuffer
operator|&
name|other
operator|)
decl_stmt|;
enum|enum
name|UsagePattern
block|{
name|StreamDraw
init|=
literal|0x88E0
block|,
comment|// GL_STREAM_DRAW
name|StreamRead
init|=
literal|0x88E1
block|,
comment|// GL_STREAM_READ
name|StreamCopy
init|=
literal|0x88E2
block|,
comment|// GL_STREAM_COPY
name|StaticDraw
init|=
literal|0x88E4
block|,
comment|// GL_STATIC_DRAW
name|StaticRead
init|=
literal|0x88E5
block|,
comment|// GL_STATIC_READ
name|StaticCopy
init|=
literal|0x88E6
block|,
comment|// GL_STATIC_COPY
name|DynamicDraw
init|=
literal|0x88E8
block|,
comment|// GL_DYNAMIC_DRAW
name|DynamicRead
init|=
literal|0x88E9
block|,
comment|// GL_DYNAMIC_READ
name|DynamicCopy
init|=
literal|0x88EA
comment|// GL_DYNAMIC_COPY
block|}
enum|;
enum|enum
name|Access
block|{
name|ReadOnly
init|=
literal|0x88B8
block|,
comment|// GL_READ_ONLY
name|WriteOnly
init|=
literal|0x88B9
block|,
comment|// GL_WRITE_ONLY
name|ReadWrite
init|=
literal|0x88BA
comment|// GL_READ_WRITE
block|}
enum|;
name|QGLBuffer
operator|::
name|Type
name|type
argument_list|()
specifier|const
expr_stmt|;
name|QGLBuffer
operator|::
name|UsagePattern
name|usagePattern
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setUsagePattern
argument_list|(
name|QGLBuffer
operator|::
name|UsagePattern
name|value
argument_list|)
decl_stmt|;
name|bool
name|create
parameter_list|()
function_decl|;
name|bool
name|isCreated
argument_list|()
specifier|const
expr_stmt|;
name|void
name|destroy
parameter_list|()
function_decl|;
name|bool
name|bind
parameter_list|()
function_decl|;
name|void
name|release
parameter_list|()
function_decl|;
specifier|static
name|void
name|release
argument_list|(
name|QGLBuffer
operator|::
name|Type
name|type
argument_list|)
decl_stmt|;
name|GLuint
name|bufferId
argument_list|()
specifier|const
expr_stmt|;
name|int
name|size
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|read
parameter_list|(
name|int
name|offset
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|void
name|write
parameter_list|(
name|int
name|offset
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|void
name|allocate
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
specifier|inline
name|void
name|allocate
parameter_list|(
name|int
name|count
parameter_list|)
block|{
name|allocate
argument_list|(
name|Q_NULLPTR
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
name|void
modifier|*
name|map
argument_list|(
name|QGLBuffer
operator|::
name|Access
name|access
argument_list|)
decl_stmt|;
name|bool
name|unmap
parameter_list|()
function_decl|;
name|private
label|:
name|QGLBufferPrivate
modifier|*
name|d_ptr
decl_stmt|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGLBuffer
argument_list|)
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
end_unit
