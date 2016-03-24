begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// SurfaceImpl.h: Implementation methods of egl::Surface
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_SURFACEIMPL_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_SURFACEIMPL_H_
define|#
directive|define
name|LIBANGLE_RENDERER_SURFACEIMPL_H_
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Framebuffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/FramebufferAttachment.h"
end_include
begin_decl_stmt
name|namespace
name|egl
block|{
name|class
name|Display
decl_stmt|;
struct_decl|struct
name|Config
struct_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|FramebufferImpl
decl_stmt|;
name|class
name|SurfaceImpl
range|:
name|public
name|FramebufferAttachmentObjectImpl
block|{
name|public
operator|:
name|SurfaceImpl
argument_list|()
block|;
name|virtual
operator|~
name|SurfaceImpl
argument_list|()
block|;
name|virtual
name|egl
operator|::
name|Error
name|initialize
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|FramebufferImpl
operator|*
name|createDefaultFramebuffer
argument_list|(
specifier|const
name|gl
operator|::
name|Framebuffer
operator|::
name|Data
operator|&
name|data
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|egl
operator|::
name|Error
name|swap
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|egl
operator|::
name|Error
name|postSubBuffer
argument_list|(
argument|EGLint x
argument_list|,
argument|EGLint y
argument_list|,
argument|EGLint width
argument_list|,
argument|EGLint height
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|egl
operator|::
name|Error
name|querySurfacePointerANGLE
argument_list|(
argument|EGLint attribute
argument_list|,
argument|void **value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|egl
operator|::
name|Error
name|bindTexImage
argument_list|(
argument|gl::Texture *texture
argument_list|,
argument|EGLint buffer
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|egl
operator|::
name|Error
name|releaseTexImage
argument_list|(
argument|EGLint buffer
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|setSwapInterval
argument_list|(
argument|EGLint interval
argument_list|)
operator|=
literal|0
block|;
comment|// width and height can change with client window resizing
name|virtual
name|EGLint
name|getWidth
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|EGLint
name|getHeight
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|EGLint
name|isPostSubBufferSupported
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|EGLint
name|getSwapBehavior
argument_list|()
specifier|const
operator|=
literal|0
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_SURFACEIMPL_H_
end_comment
end_unit
