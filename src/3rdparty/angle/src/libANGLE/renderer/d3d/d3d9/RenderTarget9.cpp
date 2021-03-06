begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012-2014 The ANGLE Project Authors. All rights reserved.
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
comment|// RenderTarget9.cpp: Implements a D3D9-specific wrapper for IDirect3DSurface9
end_comment
begin_comment
comment|// pointers retained by renderbuffers.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/RenderTarget9.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/Renderer9.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/renderer9_utils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/SwapChain9.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d9/formatutils9.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
comment|// TODO: AddRef the incoming surface to take ownership instead of expecting that its ref is being given.
DECL|function|TextureRenderTarget9
name|TextureRenderTarget9
operator|::
name|TextureRenderTarget9
parameter_list|(
name|IDirect3DBaseTexture9
modifier|*
name|texture
parameter_list|,
name|size_t
name|textureLevel
parameter_list|,
name|IDirect3DSurface9
modifier|*
name|surface
parameter_list|,
name|GLenum
name|internalFormat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLsizei
name|depth
parameter_list|,
name|GLsizei
name|samples
parameter_list|)
member_init_list|:
name|mWidth
argument_list|(
name|width
argument_list|)
member_init_list|,
name|mHeight
argument_list|(
name|height
argument_list|)
member_init_list|,
name|mDepth
argument_list|(
name|depth
argument_list|)
member_init_list|,
name|mInternalFormat
argument_list|(
name|internalFormat
argument_list|)
member_init_list|,
name|mD3DFormat
argument_list|(
name|D3DFMT_UNKNOWN
argument_list|)
member_init_list|,
name|mSamples
argument_list|(
name|samples
argument_list|)
member_init_list|,
name|mTexture
argument_list|(
name|texture
argument_list|)
member_init_list|,
name|mTextureLevel
argument_list|(
name|textureLevel
argument_list|)
member_init_list|,
name|mRenderTarget
argument_list|(
name|surface
argument_list|)
block|{
name|ASSERT
argument_list|(
name|mDepth
operator|==
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|mRenderTarget
condition|)
block|{
name|D3DSURFACE_DESC
name|description
decl_stmt|;
name|mRenderTarget
operator|->
name|GetDesc
argument_list|(
operator|&
name|description
argument_list|)
expr_stmt|;
name|mD3DFormat
operator|=
name|description
operator|.
name|Format
expr_stmt|;
block|}
block|}
DECL|function|~TextureRenderTarget9
name|TextureRenderTarget9
operator|::
name|~
name|TextureRenderTarget9
parameter_list|()
block|{
name|SafeRelease
argument_list|(
name|mTexture
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|mRenderTarget
argument_list|)
expr_stmt|;
block|}
DECL|function|getWidth
name|GLsizei
name|TextureRenderTarget9
operator|::
name|getWidth
parameter_list|()
specifier|const
block|{
return|return
name|mWidth
return|;
block|}
DECL|function|getHeight
name|GLsizei
name|TextureRenderTarget9
operator|::
name|getHeight
parameter_list|()
specifier|const
block|{
return|return
name|mHeight
return|;
block|}
DECL|function|getDepth
name|GLsizei
name|TextureRenderTarget9
operator|::
name|getDepth
parameter_list|()
specifier|const
block|{
return|return
name|mDepth
return|;
block|}
DECL|function|getInternalFormat
name|GLenum
name|TextureRenderTarget9
operator|::
name|getInternalFormat
parameter_list|()
specifier|const
block|{
return|return
name|mInternalFormat
return|;
block|}
DECL|function|getSamples
name|GLsizei
name|TextureRenderTarget9
operator|::
name|getSamples
parameter_list|()
specifier|const
block|{
return|return
name|mSamples
return|;
block|}
DECL|function|getTexture
name|IDirect3DBaseTexture9
modifier|*
name|TextureRenderTarget9
operator|::
name|getTexture
parameter_list|()
specifier|const
block|{
return|return
name|mTexture
return|;
block|}
DECL|function|getTextureLevel
name|size_t
name|TextureRenderTarget9
operator|::
name|getTextureLevel
parameter_list|()
specifier|const
block|{
return|return
name|mTextureLevel
return|;
block|}
DECL|function|getSurface
name|IDirect3DSurface9
modifier|*
name|TextureRenderTarget9
operator|::
name|getSurface
parameter_list|()
specifier|const
block|{
comment|// Caller is responsible for releasing the returned surface reference.
comment|// TODO: remove the AddRef to match RenderTarget11
if|if
condition|(
name|mRenderTarget
condition|)
block|{
name|mRenderTarget
operator|->
name|AddRef
argument_list|()
expr_stmt|;
block|}
return|return
name|mRenderTarget
return|;
block|}
DECL|function|getD3DFormat
name|D3DFORMAT
name|TextureRenderTarget9
operator|::
name|getD3DFormat
parameter_list|()
specifier|const
block|{
return|return
name|mD3DFormat
return|;
block|}
DECL|function|SurfaceRenderTarget9
name|SurfaceRenderTarget9
operator|::
name|SurfaceRenderTarget9
parameter_list|(
name|SwapChain9
modifier|*
name|swapChain
parameter_list|,
name|bool
name|depth
parameter_list|)
member_init_list|:
name|mSwapChain
argument_list|(
name|swapChain
argument_list|)
member_init_list|,
name|mDepth
argument_list|(
name|depth
argument_list|)
block|{ }
DECL|function|~SurfaceRenderTarget9
name|SurfaceRenderTarget9
operator|::
name|~
name|SurfaceRenderTarget9
parameter_list|()
block|{ }
DECL|function|getWidth
name|GLsizei
name|SurfaceRenderTarget9
operator|::
name|getWidth
parameter_list|()
specifier|const
block|{
return|return
name|mSwapChain
operator|->
name|getWidth
argument_list|()
return|;
block|}
DECL|function|getHeight
name|GLsizei
name|SurfaceRenderTarget9
operator|::
name|getHeight
parameter_list|()
specifier|const
block|{
return|return
name|mSwapChain
operator|->
name|getHeight
argument_list|()
return|;
block|}
DECL|function|getDepth
name|GLsizei
name|SurfaceRenderTarget9
operator|::
name|getDepth
parameter_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
DECL|function|getInternalFormat
name|GLenum
name|SurfaceRenderTarget9
operator|::
name|getInternalFormat
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|mDepth
condition|?
name|mSwapChain
operator|->
name|GetDepthBufferInternalFormat
argument_list|()
else|:
name|mSwapChain
operator|->
name|GetRenderTargetInternalFormat
argument_list|()
operator|)
return|;
block|}
DECL|function|getSamples
name|GLsizei
name|SurfaceRenderTarget9
operator|::
name|getSamples
parameter_list|()
specifier|const
block|{
comment|// Our EGL surfaces do not support multisampling.
return|return
literal|0
return|;
block|}
DECL|function|getSurface
name|IDirect3DSurface9
modifier|*
name|SurfaceRenderTarget9
operator|::
name|getSurface
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|mDepth
condition|?
name|mSwapChain
operator|->
name|getDepthStencil
argument_list|()
else|:
name|mSwapChain
operator|->
name|getRenderTarget
argument_list|()
operator|)
return|;
block|}
DECL|function|getTexture
name|IDirect3DBaseTexture9
modifier|*
name|SurfaceRenderTarget9
operator|::
name|getTexture
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|mDepth
condition|?
literal|nullptr
else|:
name|mSwapChain
operator|->
name|getOffscreenTexture
argument_list|()
operator|)
return|;
block|}
DECL|function|getTextureLevel
name|size_t
name|SurfaceRenderTarget9
operator|::
name|getTextureLevel
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
DECL|function|getD3DFormat
name|D3DFORMAT
name|SurfaceRenderTarget9
operator|::
name|getD3DFormat
parameter_list|()
specifier|const
block|{
return|return
name|d3d9
operator|::
name|GetTextureFormatInfo
argument_list|(
name|getInternalFormat
argument_list|()
argument_list|)
operator|.
name|texFormat
return|;
block|}
block|}
end_namespace
end_unit
