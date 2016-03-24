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
comment|// RenderStateCache.cpp: Defines rx::RenderStateCache, a cache of Direct3D render
end_comment
begin_comment
comment|// state objects.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/RenderStateCache.h"
end_include
begin_include
include|#
directive|include
file|<float.h>
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
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
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/FramebufferD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/renderer11_utils.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/Renderer11.h"
end_include
begin_include
include|#
directive|include
file|"third_party/murmurhash/MurmurHash3.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
using|using
namespace|namespace
name|gl_d3d11
namespace|;
template|template
parameter_list|<
name|typename
name|mapType
parameter_list|>
DECL|function|ClearStateMap
specifier|static
name|void
name|ClearStateMap
parameter_list|(
name|mapType
modifier|&
name|map
parameter_list|)
block|{
for|for
control|(
typename|typename
name|mapType
operator|::
name|iterator
name|i
init|=
name|map
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|map
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|SafeRelease
argument_list|(
name|i
operator|->
name|second
operator|.
name|first
argument_list|)
expr_stmt|;
block|}
name|map
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|// MSDN's documentation of ID3D11Device::CreateBlendState, ID3D11Device::CreateRasterizerState,
comment|// ID3D11Device::CreateDepthStencilState and ID3D11Device::CreateSamplerState claims the maximum
comment|// number of unique states of each type an application can create is 4096
DECL|member|kMaxBlendStates
specifier|const
name|unsigned
name|int
name|RenderStateCache
operator|::
name|kMaxBlendStates
init|=
literal|4096
decl_stmt|;
DECL|member|kMaxRasterizerStates
specifier|const
name|unsigned
name|int
name|RenderStateCache
operator|::
name|kMaxRasterizerStates
init|=
literal|4096
decl_stmt|;
DECL|member|kMaxDepthStencilStates
specifier|const
name|unsigned
name|int
name|RenderStateCache
operator|::
name|kMaxDepthStencilStates
init|=
literal|4096
decl_stmt|;
DECL|member|kMaxSamplerStates
specifier|const
name|unsigned
name|int
name|RenderStateCache
operator|::
name|kMaxSamplerStates
init|=
literal|4096
decl_stmt|;
DECL|function|RenderStateCache
name|RenderStateCache
operator|::
name|RenderStateCache
parameter_list|(
name|Renderer11
modifier|*
name|renderer
parameter_list|)
member_init_list|:
name|mRenderer
argument_list|(
name|renderer
argument_list|)
member_init_list|,
name|mCounter
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mBlendStateCache
argument_list|(
name|kMaxBlendStates
argument_list|,
name|hashBlendState
argument_list|,
name|compareBlendStates
argument_list|)
member_init_list|,
name|mRasterizerStateCache
argument_list|(
name|kMaxRasterizerStates
argument_list|,
name|hashRasterizerState
argument_list|,
name|compareRasterizerStates
argument_list|)
member_init_list|,
name|mDepthStencilStateCache
argument_list|(
name|kMaxDepthStencilStates
argument_list|,
name|hashDepthStencilState
argument_list|,
name|compareDepthStencilStates
argument_list|)
member_init_list|,
name|mSamplerStateCache
argument_list|(
name|kMaxSamplerStates
argument_list|,
name|hashSamplerState
argument_list|,
name|compareSamplerStates
argument_list|)
member_init_list|,
name|mDevice
argument_list|(
name|NULL
argument_list|)
block|{ }
DECL|function|~RenderStateCache
name|RenderStateCache
operator|::
name|~
name|RenderStateCache
parameter_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|initialize
name|void
name|RenderStateCache
operator|::
name|initialize
parameter_list|(
name|ID3D11Device
modifier|*
name|device
parameter_list|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|mDevice
operator|=
name|device
expr_stmt|;
block|}
DECL|function|clear
name|void
name|RenderStateCache
operator|::
name|clear
parameter_list|()
block|{
name|ClearStateMap
argument_list|(
name|mBlendStateCache
argument_list|)
expr_stmt|;
name|ClearStateMap
argument_list|(
name|mRasterizerStateCache
argument_list|)
expr_stmt|;
name|ClearStateMap
argument_list|(
name|mDepthStencilStateCache
argument_list|)
expr_stmt|;
name|ClearStateMap
argument_list|(
name|mSamplerStateCache
argument_list|)
expr_stmt|;
block|}
DECL|function|hashBlendState
name|std
operator|::
name|size_t
name|RenderStateCache
operator|::
name|hashBlendState
parameter_list|(
specifier|const
name|BlendStateKey
modifier|&
name|blendState
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|int
name|seed
init|=
literal|0xABCDEF98
decl_stmt|;
name|std
operator|::
name|size_t
name|hash
init|=
literal|0
decl_stmt|;
name|MurmurHash3_x86_32
argument_list|(
operator|&
name|blendState
argument_list|,
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|BlendState
argument_list|)
argument_list|,
name|seed
argument_list|,
operator|&
name|hash
argument_list|)
expr_stmt|;
return|return
name|hash
return|;
block|}
DECL|function|compareBlendStates
name|bool
name|RenderStateCache
operator|::
name|compareBlendStates
parameter_list|(
specifier|const
name|BlendStateKey
modifier|&
name|a
parameter_list|,
specifier|const
name|BlendStateKey
modifier|&
name|b
parameter_list|)
block|{
return|return
name|memcmp
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|BlendStateKey
argument_list|)
argument_list|)
operator|==
literal|0
return|;
block|}
DECL|function|getBlendState
name|gl
operator|::
name|Error
name|RenderStateCache
operator|::
name|getBlendState
parameter_list|(
specifier|const
name|gl
operator|::
name|Framebuffer
modifier|*
name|framebuffer
parameter_list|,
specifier|const
name|gl
operator|::
name|BlendState
modifier|&
name|blendState
parameter_list|,
name|ID3D11BlendState
modifier|*
modifier|*
name|outBlendState
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mDevice
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Internal error, RenderStateCache is not initialized."
argument_list|)
return|;
block|}
name|bool
name|mrt
init|=
literal|false
decl_stmt|;
specifier|const
name|FramebufferD3D
modifier|*
name|framebufferD3D
init|=
name|GetImplAs
argument_list|<
name|FramebufferD3D
argument_list|>
argument_list|(
name|framebuffer
argument_list|)
decl_stmt|;
specifier|const
name|gl
operator|::
name|AttachmentList
modifier|&
name|colorbuffers
init|=
name|framebufferD3D
operator|->
name|getColorAttachmentsForRender
argument_list|()
decl_stmt|;
name|BlendStateKey
name|key
init|=
block|{}
decl_stmt|;
name|key
operator|.
name|blendState
operator|=
name|blendState
expr_stmt|;
for|for
control|(
name|size_t
name|colorAttachment
init|=
literal|0
init|;
name|colorAttachment
operator|<
name|colorbuffers
operator|.
name|size
argument_list|()
condition|;
operator|++
name|colorAttachment
control|)
block|{
specifier|const
name|gl
operator|::
name|FramebufferAttachment
modifier|*
name|attachment
init|=
name|colorbuffers
index|[
name|colorAttachment
index|]
decl_stmt|;
name|auto
name|rtChannels
init|=
name|key
operator|.
name|rtChannels
index|[
name|colorAttachment
index|]
decl_stmt|;
if|if
condition|(
name|attachment
condition|)
block|{
if|if
condition|(
name|colorAttachment
operator|>
literal|0
condition|)
block|{
name|mrt
operator|=
literal|true
expr_stmt|;
block|}
name|rtChannels
index|[
literal|0
index|]
operator|=
name|attachment
operator|->
name|getRedSize
argument_list|()
operator|>
literal|0
expr_stmt|;
name|rtChannels
index|[
literal|1
index|]
operator|=
name|attachment
operator|->
name|getGreenSize
argument_list|()
operator|>
literal|0
expr_stmt|;
name|rtChannels
index|[
literal|2
index|]
operator|=
name|attachment
operator|->
name|getBlueSize
argument_list|()
operator|>
literal|0
expr_stmt|;
name|rtChannels
index|[
literal|3
index|]
operator|=
name|attachment
operator|->
name|getAlphaSize
argument_list|()
operator|>
literal|0
expr_stmt|;
block|}
block|}
name|BlendStateMap
operator|::
name|iterator
name|keyIter
init|=
name|mBlendStateCache
operator|.
name|find
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|keyIter
operator|!=
name|mBlendStateCache
operator|.
name|end
argument_list|()
condition|)
block|{
name|BlendStateCounterPair
modifier|&
name|state
init|=
name|keyIter
operator|->
name|second
decl_stmt|;
name|state
operator|.
name|second
operator|=
name|mCounter
operator|++
expr_stmt|;
operator|*
name|outBlendState
operator|=
name|state
operator|.
name|first
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
else|else
block|{
if|if
condition|(
name|mBlendStateCache
operator|.
name|size
argument_list|()
operator|>=
name|kMaxBlendStates
condition|)
block|{
name|TRACE
argument_list|(
literal|"Overflowed the limit of %u blend states, removing the least recently used "
literal|"to make room."
argument_list|,
name|kMaxBlendStates
argument_list|)
expr_stmt|;
name|BlendStateMap
operator|::
name|iterator
name|leastRecentlyUsed
init|=
name|mBlendStateCache
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
name|BlendStateMap
operator|::
name|iterator
name|i
init|=
name|mBlendStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mBlendStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|->
name|second
operator|.
name|second
operator|<
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|second
condition|)
block|{
name|leastRecentlyUsed
operator|=
name|i
expr_stmt|;
block|}
block|}
name|SafeRelease
argument_list|(
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|first
argument_list|)
expr_stmt|;
name|mBlendStateCache
operator|.
name|erase
argument_list|(
name|leastRecentlyUsed
argument_list|)
expr_stmt|;
block|}
comment|// Create a new blend state and insert it into the cache
name|D3D11_BLEND_DESC
name|blendDesc
init|=
block|{
literal|0
block|}
decl_stmt|;
name|blendDesc
operator|.
name|AlphaToCoverageEnable
operator|=
name|blendState
operator|.
name|sampleAlphaToCoverage
expr_stmt|;
name|blendDesc
operator|.
name|IndependentBlendEnable
operator|=
name|mrt
condition|?
name|TRUE
else|:
name|FALSE
expr_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT
condition|;
name|i
operator|++
control|)
block|{
name|D3D11_RENDER_TARGET_BLEND_DESC
modifier|&
name|rtBlend
init|=
name|blendDesc
operator|.
name|RenderTarget
index|[
name|i
index|]
decl_stmt|;
name|rtBlend
operator|.
name|BlendEnable
operator|=
name|blendState
operator|.
name|blend
expr_stmt|;
if|if
condition|(
name|blendState
operator|.
name|blend
condition|)
block|{
name|rtBlend
operator|.
name|SrcBlend
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendFunc
argument_list|(
name|blendState
operator|.
name|sourceBlendRGB
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|rtBlend
operator|.
name|DestBlend
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendFunc
argument_list|(
name|blendState
operator|.
name|destBlendRGB
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|rtBlend
operator|.
name|BlendOp
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendOp
argument_list|(
name|blendState
operator|.
name|blendEquationRGB
argument_list|)
expr_stmt|;
name|rtBlend
operator|.
name|SrcBlendAlpha
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendFunc
argument_list|(
name|blendState
operator|.
name|sourceBlendAlpha
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|rtBlend
operator|.
name|DestBlendAlpha
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendFunc
argument_list|(
name|blendState
operator|.
name|destBlendAlpha
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|rtBlend
operator|.
name|BlendOpAlpha
operator|=
name|gl_d3d11
operator|::
name|ConvertBlendOp
argument_list|(
name|blendState
operator|.
name|blendEquationAlpha
argument_list|)
expr_stmt|;
block|}
name|rtBlend
operator|.
name|RenderTargetWriteMask
operator|=
name|gl_d3d11
operator|::
name|ConvertColorMask
argument_list|(
name|key
operator|.
name|rtChannels
index|[
name|i
index|]
index|[
literal|0
index|]
operator|&&
name|blendState
operator|.
name|colorMaskRed
argument_list|,
name|key
operator|.
name|rtChannels
index|[
name|i
index|]
index|[
literal|1
index|]
operator|&&
name|blendState
operator|.
name|colorMaskGreen
argument_list|,
name|key
operator|.
name|rtChannels
index|[
name|i
index|]
index|[
literal|2
index|]
operator|&&
name|blendState
operator|.
name|colorMaskBlue
argument_list|,
name|key
operator|.
name|rtChannels
index|[
name|i
index|]
index|[
literal|3
index|]
operator|&&
name|blendState
operator|.
name|colorMaskAlpha
argument_list|)
expr_stmt|;
block|}
name|ID3D11BlendState
modifier|*
name|dx11BlendState
init|=
name|NULL
decl_stmt|;
name|HRESULT
name|result
init|=
name|mDevice
operator|->
name|CreateBlendState
argument_list|(
operator|&
name|blendDesc
argument_list|,
operator|&
name|dx11BlendState
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
operator|||
operator|!
name|dx11BlendState
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Unable to create a ID3D11BlendState, HRESULT: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
name|mBlendStateCache
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|key
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|dx11BlendState
argument_list|,
name|mCounter
operator|++
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|outBlendState
operator|=
name|dx11BlendState
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
block|}
DECL|function|hashRasterizerState
name|std
operator|::
name|size_t
name|RenderStateCache
operator|::
name|hashRasterizerState
parameter_list|(
specifier|const
name|RasterizerStateKey
modifier|&
name|rasterState
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|int
name|seed
init|=
literal|0xABCDEF98
decl_stmt|;
name|std
operator|::
name|size_t
name|hash
init|=
literal|0
decl_stmt|;
name|MurmurHash3_x86_32
argument_list|(
operator|&
name|rasterState
argument_list|,
sizeof|sizeof
argument_list|(
name|RasterizerStateKey
argument_list|)
argument_list|,
name|seed
argument_list|,
operator|&
name|hash
argument_list|)
expr_stmt|;
return|return
name|hash
return|;
block|}
DECL|function|compareRasterizerStates
name|bool
name|RenderStateCache
operator|::
name|compareRasterizerStates
parameter_list|(
specifier|const
name|RasterizerStateKey
modifier|&
name|a
parameter_list|,
specifier|const
name|RasterizerStateKey
modifier|&
name|b
parameter_list|)
block|{
return|return
name|memcmp
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|RasterizerStateKey
argument_list|)
argument_list|)
operator|==
literal|0
return|;
block|}
DECL|function|getRasterizerState
name|gl
operator|::
name|Error
name|RenderStateCache
operator|::
name|getRasterizerState
parameter_list|(
specifier|const
name|gl
operator|::
name|RasterizerState
modifier|&
name|rasterState
parameter_list|,
name|bool
name|scissorEnabled
parameter_list|,
name|ID3D11RasterizerState
modifier|*
modifier|*
name|outRasterizerState
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mDevice
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Internal error, RenderStateCache is not initialized."
argument_list|)
return|;
block|}
name|RasterizerStateKey
name|key
init|=
block|{}
decl_stmt|;
name|key
operator|.
name|rasterizerState
operator|=
name|rasterState
expr_stmt|;
name|key
operator|.
name|scissorEnabled
operator|=
name|scissorEnabled
expr_stmt|;
name|RasterizerStateMap
operator|::
name|iterator
name|keyIter
init|=
name|mRasterizerStateCache
operator|.
name|find
argument_list|(
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|keyIter
operator|!=
name|mRasterizerStateCache
operator|.
name|end
argument_list|()
condition|)
block|{
name|RasterizerStateCounterPair
modifier|&
name|state
init|=
name|keyIter
operator|->
name|second
decl_stmt|;
name|state
operator|.
name|second
operator|=
name|mCounter
operator|++
expr_stmt|;
operator|*
name|outRasterizerState
operator|=
name|state
operator|.
name|first
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
else|else
block|{
if|if
condition|(
name|mRasterizerStateCache
operator|.
name|size
argument_list|()
operator|>=
name|kMaxRasterizerStates
condition|)
block|{
name|TRACE
argument_list|(
literal|"Overflowed the limit of %u rasterizer states, removing the least recently used "
literal|"to make room."
argument_list|,
name|kMaxRasterizerStates
argument_list|)
expr_stmt|;
name|RasterizerStateMap
operator|::
name|iterator
name|leastRecentlyUsed
init|=
name|mRasterizerStateCache
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
name|RasterizerStateMap
operator|::
name|iterator
name|i
init|=
name|mRasterizerStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mRasterizerStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|->
name|second
operator|.
name|second
operator|<
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|second
condition|)
block|{
name|leastRecentlyUsed
operator|=
name|i
expr_stmt|;
block|}
block|}
name|SafeRelease
argument_list|(
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|first
argument_list|)
expr_stmt|;
name|mRasterizerStateCache
operator|.
name|erase
argument_list|(
name|leastRecentlyUsed
argument_list|)
expr_stmt|;
block|}
name|D3D11_CULL_MODE
name|cullMode
init|=
name|gl_d3d11
operator|::
name|ConvertCullMode
argument_list|(
name|rasterState
operator|.
name|cullFace
argument_list|,
name|rasterState
operator|.
name|cullMode
argument_list|)
decl_stmt|;
comment|// Disable culling if drawing points
if|if
condition|(
name|rasterState
operator|.
name|pointDrawMode
condition|)
block|{
name|cullMode
operator|=
name|D3D11_CULL_NONE
expr_stmt|;
block|}
name|D3D11_RASTERIZER_DESC
name|rasterDesc
decl_stmt|;
name|rasterDesc
operator|.
name|FillMode
operator|=
name|D3D11_FILL_SOLID
expr_stmt|;
name|rasterDesc
operator|.
name|CullMode
operator|=
name|cullMode
expr_stmt|;
name|rasterDesc
operator|.
name|FrontCounterClockwise
operator|=
operator|(
name|rasterState
operator|.
name|frontFace
operator|==
name|GL_CCW
operator|)
condition|?
name|FALSE
else|:
name|TRUE
expr_stmt|;
name|rasterDesc
operator|.
name|DepthBiasClamp
operator|=
literal|0.0f
expr_stmt|;
comment|// MSDN documentation of DepthBiasClamp implies a value of zero will preform no clamping, must be tested though.
name|rasterDesc
operator|.
name|DepthClipEnable
operator|=
name|TRUE
expr_stmt|;
name|rasterDesc
operator|.
name|ScissorEnable
operator|=
name|scissorEnabled
condition|?
name|TRUE
else|:
name|FALSE
expr_stmt|;
name|rasterDesc
operator|.
name|MultisampleEnable
operator|=
name|rasterState
operator|.
name|multiSample
expr_stmt|;
name|rasterDesc
operator|.
name|AntialiasedLineEnable
operator|=
name|FALSE
expr_stmt|;
if|if
condition|(
name|rasterState
operator|.
name|polygonOffsetFill
condition|)
block|{
name|rasterDesc
operator|.
name|SlopeScaledDepthBias
operator|=
name|rasterState
operator|.
name|polygonOffsetFactor
expr_stmt|;
name|rasterDesc
operator|.
name|DepthBias
operator|=
operator|(
name|INT
operator|)
name|rasterState
operator|.
name|polygonOffsetUnits
expr_stmt|;
block|}
else|else
block|{
name|rasterDesc
operator|.
name|SlopeScaledDepthBias
operator|=
literal|0.0f
expr_stmt|;
name|rasterDesc
operator|.
name|DepthBias
operator|=
literal|0
expr_stmt|;
block|}
name|ID3D11RasterizerState
modifier|*
name|dx11RasterizerState
init|=
name|NULL
decl_stmt|;
name|HRESULT
name|result
init|=
name|mDevice
operator|->
name|CreateRasterizerState
argument_list|(
operator|&
name|rasterDesc
argument_list|,
operator|&
name|dx11RasterizerState
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
operator|||
operator|!
name|dx11RasterizerState
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Unable to create a ID3D11RasterizerState, HRESULT: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
name|mRasterizerStateCache
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|key
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|dx11RasterizerState
argument_list|,
name|mCounter
operator|++
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|outRasterizerState
operator|=
name|dx11RasterizerState
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
block|}
DECL|function|hashDepthStencilState
name|std
operator|::
name|size_t
name|RenderStateCache
operator|::
name|hashDepthStencilState
parameter_list|(
specifier|const
name|gl
operator|::
name|DepthStencilState
modifier|&
name|dsState
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|int
name|seed
init|=
literal|0xABCDEF98
decl_stmt|;
name|std
operator|::
name|size_t
name|hash
init|=
literal|0
decl_stmt|;
name|MurmurHash3_x86_32
argument_list|(
operator|&
name|dsState
argument_list|,
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|DepthStencilState
argument_list|)
argument_list|,
name|seed
argument_list|,
operator|&
name|hash
argument_list|)
expr_stmt|;
return|return
name|hash
return|;
block|}
DECL|function|compareDepthStencilStates
name|bool
name|RenderStateCache
operator|::
name|compareDepthStencilStates
parameter_list|(
specifier|const
name|gl
operator|::
name|DepthStencilState
modifier|&
name|a
parameter_list|,
specifier|const
name|gl
operator|::
name|DepthStencilState
modifier|&
name|b
parameter_list|)
block|{
return|return
name|memcmp
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|DepthStencilState
argument_list|)
argument_list|)
operator|==
literal|0
return|;
block|}
DECL|function|getDepthStencilState
name|gl
operator|::
name|Error
name|RenderStateCache
operator|::
name|getDepthStencilState
parameter_list|(
specifier|const
name|gl
operator|::
name|DepthStencilState
modifier|&
name|originalState
parameter_list|,
name|bool
name|disableDepth
parameter_list|,
name|bool
name|disableStencil
parameter_list|,
name|ID3D11DepthStencilState
modifier|*
modifier|*
name|outDSState
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mDevice
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Internal error, RenderStateCache is not initialized."
argument_list|)
return|;
block|}
name|gl
operator|::
name|DepthStencilState
name|glState
init|=
name|originalState
decl_stmt|;
if|if
condition|(
name|disableDepth
condition|)
block|{
name|glState
operator|.
name|depthTest
operator|=
literal|false
expr_stmt|;
name|glState
operator|.
name|depthMask
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
name|disableStencil
condition|)
block|{
name|glState
operator|.
name|stencilWritemask
operator|=
literal|0
expr_stmt|;
name|glState
operator|.
name|stencilBackWritemask
operator|=
literal|0
expr_stmt|;
name|glState
operator|.
name|stencilTest
operator|=
literal|false
expr_stmt|;
block|}
name|auto
name|keyIter
init|=
name|mDepthStencilStateCache
operator|.
name|find
argument_list|(
name|glState
argument_list|)
decl_stmt|;
if|if
condition|(
name|keyIter
operator|!=
name|mDepthStencilStateCache
operator|.
name|end
argument_list|()
condition|)
block|{
name|DepthStencilStateCounterPair
modifier|&
name|state
init|=
name|keyIter
operator|->
name|second
decl_stmt|;
name|state
operator|.
name|second
operator|=
name|mCounter
operator|++
expr_stmt|;
operator|*
name|outDSState
operator|=
name|state
operator|.
name|first
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
if|if
condition|(
name|mDepthStencilStateCache
operator|.
name|size
argument_list|()
operator|>=
name|kMaxDepthStencilStates
condition|)
block|{
name|TRACE
argument_list|(
literal|"Overflowed the limit of %u depth stencil states, removing the least recently used "
literal|"to make room."
argument_list|,
name|kMaxDepthStencilStates
argument_list|)
expr_stmt|;
name|auto
name|leastRecentlyUsed
init|=
name|mDepthStencilStateCache
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
name|auto
name|i
init|=
name|mDepthStencilStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mDepthStencilStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|->
name|second
operator|.
name|second
operator|<
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|second
condition|)
block|{
name|leastRecentlyUsed
operator|=
name|i
expr_stmt|;
block|}
block|}
name|SafeRelease
argument_list|(
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|first
argument_list|)
expr_stmt|;
name|mDepthStencilStateCache
operator|.
name|erase
argument_list|(
name|leastRecentlyUsed
argument_list|)
expr_stmt|;
block|}
name|D3D11_DEPTH_STENCIL_DESC
name|dsDesc
init|=
block|{
literal|0
block|}
decl_stmt|;
name|dsDesc
operator|.
name|DepthEnable
operator|=
name|glState
operator|.
name|depthTest
condition|?
name|TRUE
else|:
name|FALSE
expr_stmt|;
name|dsDesc
operator|.
name|DepthWriteMask
operator|=
name|ConvertDepthMask
argument_list|(
name|glState
operator|.
name|depthMask
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|DepthFunc
operator|=
name|ConvertComparison
argument_list|(
name|glState
operator|.
name|depthFunc
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|StencilEnable
operator|=
name|glState
operator|.
name|stencilTest
condition|?
name|TRUE
else|:
name|FALSE
expr_stmt|;
name|dsDesc
operator|.
name|StencilReadMask
operator|=
name|ConvertStencilMask
argument_list|(
name|glState
operator|.
name|stencilMask
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|StencilWriteMask
operator|=
name|ConvertStencilMask
argument_list|(
name|glState
operator|.
name|stencilWritemask
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|FrontFace
operator|.
name|StencilFailOp
operator|=
name|ConvertStencilOp
argument_list|(
name|glState
operator|.
name|stencilFail
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|FrontFace
operator|.
name|StencilDepthFailOp
operator|=
name|ConvertStencilOp
argument_list|(
name|glState
operator|.
name|stencilPassDepthFail
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|FrontFace
operator|.
name|StencilPassOp
operator|=
name|ConvertStencilOp
argument_list|(
name|glState
operator|.
name|stencilPassDepthPass
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|FrontFace
operator|.
name|StencilFunc
operator|=
name|ConvertComparison
argument_list|(
name|glState
operator|.
name|stencilFunc
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|BackFace
operator|.
name|StencilFailOp
operator|=
name|ConvertStencilOp
argument_list|(
name|glState
operator|.
name|stencilBackFail
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|BackFace
operator|.
name|StencilDepthFailOp
operator|=
name|ConvertStencilOp
argument_list|(
name|glState
operator|.
name|stencilBackPassDepthFail
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|BackFace
operator|.
name|StencilPassOp
operator|=
name|ConvertStencilOp
argument_list|(
name|glState
operator|.
name|stencilBackPassDepthPass
argument_list|)
expr_stmt|;
name|dsDesc
operator|.
name|BackFace
operator|.
name|StencilFunc
operator|=
name|ConvertComparison
argument_list|(
name|glState
operator|.
name|stencilBackFunc
argument_list|)
expr_stmt|;
name|ID3D11DepthStencilState
modifier|*
name|dx11DepthStencilState
init|=
name|NULL
decl_stmt|;
name|HRESULT
name|result
init|=
name|mDevice
operator|->
name|CreateDepthStencilState
argument_list|(
operator|&
name|dsDesc
argument_list|,
operator|&
name|dx11DepthStencilState
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
operator|||
operator|!
name|dx11DepthStencilState
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Unable to create a ID3D11DepthStencilState, HRESULT: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
name|mDepthStencilStateCache
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|glState
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|dx11DepthStencilState
argument_list|,
name|mCounter
operator|++
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|outDSState
operator|=
name|dx11DepthStencilState
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|hashSamplerState
name|std
operator|::
name|size_t
name|RenderStateCache
operator|::
name|hashSamplerState
parameter_list|(
specifier|const
name|gl
operator|::
name|SamplerState
modifier|&
name|samplerState
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|int
name|seed
init|=
literal|0xABCDEF98
decl_stmt|;
name|std
operator|::
name|size_t
name|hash
init|=
literal|0
decl_stmt|;
name|MurmurHash3_x86_32
argument_list|(
operator|&
name|samplerState
argument_list|,
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|SamplerState
argument_list|)
argument_list|,
name|seed
argument_list|,
operator|&
name|hash
argument_list|)
expr_stmt|;
return|return
name|hash
return|;
block|}
DECL|function|compareSamplerStates
name|bool
name|RenderStateCache
operator|::
name|compareSamplerStates
parameter_list|(
specifier|const
name|gl
operator|::
name|SamplerState
modifier|&
name|a
parameter_list|,
specifier|const
name|gl
operator|::
name|SamplerState
modifier|&
name|b
parameter_list|)
block|{
return|return
name|memcmp
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|gl
operator|::
name|SamplerState
argument_list|)
argument_list|)
operator|==
literal|0
return|;
block|}
DECL|function|getSamplerState
name|gl
operator|::
name|Error
name|RenderStateCache
operator|::
name|getSamplerState
parameter_list|(
specifier|const
name|gl
operator|::
name|SamplerState
modifier|&
name|samplerState
parameter_list|,
name|ID3D11SamplerState
modifier|*
modifier|*
name|outSamplerState
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mDevice
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Internal error, RenderStateCache is not initialized."
argument_list|)
return|;
block|}
name|SamplerStateMap
operator|::
name|iterator
name|keyIter
init|=
name|mSamplerStateCache
operator|.
name|find
argument_list|(
name|samplerState
argument_list|)
decl_stmt|;
if|if
condition|(
name|keyIter
operator|!=
name|mSamplerStateCache
operator|.
name|end
argument_list|()
condition|)
block|{
name|SamplerStateCounterPair
modifier|&
name|state
init|=
name|keyIter
operator|->
name|second
decl_stmt|;
name|state
operator|.
name|second
operator|=
name|mCounter
operator|++
expr_stmt|;
operator|*
name|outSamplerState
operator|=
name|state
operator|.
name|first
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
else|else
block|{
if|if
condition|(
name|mSamplerStateCache
operator|.
name|size
argument_list|()
operator|>=
name|kMaxSamplerStates
condition|)
block|{
name|TRACE
argument_list|(
literal|"Overflowed the limit of %u sampler states, removing the least recently used "
literal|"to make room."
argument_list|,
name|kMaxSamplerStates
argument_list|)
expr_stmt|;
name|SamplerStateMap
operator|::
name|iterator
name|leastRecentlyUsed
init|=
name|mSamplerStateCache
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
name|SamplerStateMap
operator|::
name|iterator
name|i
init|=
name|mSamplerStateCache
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mSamplerStateCache
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|->
name|second
operator|.
name|second
operator|<
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|second
condition|)
block|{
name|leastRecentlyUsed
operator|=
name|i
expr_stmt|;
block|}
block|}
name|SafeRelease
argument_list|(
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|first
argument_list|)
expr_stmt|;
name|mSamplerStateCache
operator|.
name|erase
argument_list|(
name|leastRecentlyUsed
argument_list|)
expr_stmt|;
block|}
name|D3D11_SAMPLER_DESC
name|samplerDesc
decl_stmt|;
name|samplerDesc
operator|.
name|Filter
operator|=
name|gl_d3d11
operator|::
name|ConvertFilter
argument_list|(
name|samplerState
operator|.
name|minFilter
argument_list|,
name|samplerState
operator|.
name|magFilter
argument_list|,
name|samplerState
operator|.
name|maxAnisotropy
argument_list|,
name|samplerState
operator|.
name|compareMode
argument_list|)
expr_stmt|;
name|samplerDesc
operator|.
name|AddressU
operator|=
name|gl_d3d11
operator|::
name|ConvertTextureWrap
argument_list|(
name|samplerState
operator|.
name|wrapS
argument_list|)
expr_stmt|;
name|samplerDesc
operator|.
name|AddressV
operator|=
name|gl_d3d11
operator|::
name|ConvertTextureWrap
argument_list|(
name|samplerState
operator|.
name|wrapT
argument_list|)
expr_stmt|;
name|samplerDesc
operator|.
name|AddressW
operator|=
name|gl_d3d11
operator|::
name|ConvertTextureWrap
argument_list|(
name|samplerState
operator|.
name|wrapR
argument_list|)
expr_stmt|;
name|samplerDesc
operator|.
name|MipLODBias
operator|=
literal|0
expr_stmt|;
name|samplerDesc
operator|.
name|MaxAnisotropy
operator|=
cast|static_cast
argument_list|<
name|UINT
argument_list|>
argument_list|(
name|samplerState
operator|.
name|maxAnisotropy
argument_list|)
expr_stmt|;
name|samplerDesc
operator|.
name|ComparisonFunc
operator|=
name|gl_d3d11
operator|::
name|ConvertComparison
argument_list|(
name|samplerState
operator|.
name|compareFunc
argument_list|)
expr_stmt|;
name|samplerDesc
operator|.
name|BorderColor
index|[
literal|0
index|]
operator|=
literal|0.0f
expr_stmt|;
name|samplerDesc
operator|.
name|BorderColor
index|[
literal|1
index|]
operator|=
literal|0.0f
expr_stmt|;
name|samplerDesc
operator|.
name|BorderColor
index|[
literal|2
index|]
operator|=
literal|0.0f
expr_stmt|;
name|samplerDesc
operator|.
name|BorderColor
index|[
literal|3
index|]
operator|=
literal|0.0f
expr_stmt|;
name|samplerDesc
operator|.
name|MinLOD
operator|=
name|samplerState
operator|.
name|minLod
expr_stmt|;
name|samplerDesc
operator|.
name|MaxLOD
operator|=
name|samplerState
operator|.
name|maxLod
expr_stmt|;
if|if
condition|(
name|mRenderer
operator|->
name|getRenderer11DeviceCaps
argument_list|()
operator|.
name|featureLevel
operator|<=
name|D3D_FEATURE_LEVEL_9_3
condition|)
block|{
comment|// Check that maxLOD is nearly FLT_MAX (1000.0f is the default), since 9_3 doesn't support anything other than FLT_MAX.
comment|// Note that Feature Level 9_* only supports GL ES 2.0, so the consumer of ANGLE can't modify the Max LOD themselves.
name|ASSERT
argument_list|(
name|samplerState
operator|.
name|maxLod
operator|>=
literal|999.9f
argument_list|)
expr_stmt|;
comment|// Now just set MaxLOD to FLT_MAX. Other parts of the renderer (e.g. the non-zero max LOD workaround) should take account of this.
name|samplerDesc
operator|.
name|MaxLOD
operator|=
name|FLT_MAX
expr_stmt|;
block|}
name|ID3D11SamplerState
modifier|*
name|dx11SamplerState
init|=
name|NULL
decl_stmt|;
name|HRESULT
name|result
init|=
name|mDevice
operator|->
name|CreateSamplerState
argument_list|(
operator|&
name|samplerDesc
argument_list|,
operator|&
name|dx11SamplerState
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
operator|||
operator|!
name|dx11SamplerState
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Unable to create a ID3D11SamplerState, HRESULT: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
name|mSamplerStateCache
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|samplerState
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|dx11SamplerState
argument_list|,
name|mCounter
operator|++
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|outSamplerState
operator|=
name|dx11SamplerState
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
block|}
block|}
end_namespace
end_unit
