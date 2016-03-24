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
comment|// RenderStateCache.h: Defines rx::RenderStateCache, a cache of Direct3D render
end_comment
begin_comment
comment|// state objects.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D11_RENDERSTATECACHE_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D11_RENDERSTATECACHE_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D11_RENDERSTATECACHE_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/angletypes.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Error.h"
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|<unordered_map>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Framebuffer
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|Renderer11
decl_stmt|;
name|class
name|RenderStateCache
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|RenderStateCache
argument_list|(
name|Renderer11
operator|*
name|renderer
argument_list|)
block|;
name|virtual
operator|~
name|RenderStateCache
argument_list|()
block|;
name|void
name|initialize
argument_list|(
name|ID3D11Device
operator|*
name|device
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|gl
operator|::
name|Error
name|getBlendState
argument_list|(
specifier|const
name|gl
operator|::
name|Framebuffer
operator|*
name|framebuffer
argument_list|,
specifier|const
name|gl
operator|::
name|BlendState
operator|&
name|blendState
argument_list|,
name|ID3D11BlendState
operator|*
operator|*
name|outBlendState
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getRasterizerState
argument_list|(
argument|const gl::RasterizerState&rasterState
argument_list|,
argument|bool scissorEnabled
argument_list|,
argument|ID3D11RasterizerState **outRasterizerState
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getDepthStencilState
argument_list|(
argument|const gl::DepthStencilState&dsState
argument_list|,
argument|bool disableDepth
argument_list|,
argument|bool disableStencil
argument_list|,
argument|ID3D11DepthStencilState **outDSState
argument_list|)
block|;
name|gl
operator|::
name|Error
name|getSamplerState
argument_list|(
specifier|const
name|gl
operator|::
name|SamplerState
operator|&
name|samplerState
argument_list|,
name|ID3D11SamplerState
operator|*
operator|*
name|outSamplerState
argument_list|)
block|;
name|private
operator|:
name|Renderer11
operator|*
name|mRenderer
block|;
name|unsigned
name|long
name|long
name|mCounter
block|;
comment|// Blend state cache
block|struct
name|BlendStateKey
block|{
name|gl
operator|::
name|BlendState
name|blendState
block|;
name|bool
name|rtChannels
index|[
name|D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT
index|]
index|[
literal|4
index|]
block|;     }
block|;
specifier|static
name|std
operator|::
name|size_t
name|hashBlendState
argument_list|(
specifier|const
name|BlendStateKey
operator|&
name|blendState
argument_list|)
block|;
specifier|static
name|bool
name|compareBlendStates
argument_list|(
specifier|const
name|BlendStateKey
operator|&
name|a
argument_list|,
specifier|const
name|BlendStateKey
operator|&
name|b
argument_list|)
block|;
specifier|static
specifier|const
name|unsigned
name|int
name|kMaxBlendStates
block|;
typedef|typedef
name|std
operator|::
name|size_t
argument_list|(
operator|*
name|BlendStateHashFunction
argument_list|)
argument_list|(
specifier|const
name|BlendStateKey
operator|&
argument_list|)
expr_stmt|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|BlendStateEqualityFunction
function_decl|)
parameter_list|(
specifier|const
name|BlendStateKey
modifier|&
parameter_list|,
specifier|const
name|BlendStateKey
modifier|&
parameter_list|)
function_decl|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ID3D11BlendState
operator|*
operator|,
name|unsigned
name|long
name|long
operator|>
name|BlendStateCounterPair
expr_stmt|;
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|BlendStateKey
operator|,
name|BlendStateCounterPair
operator|,
name|BlendStateHashFunction
operator|,
name|BlendStateEqualityFunction
operator|>
name|BlendStateMap
expr_stmt|;
name|BlendStateMap
name|mBlendStateCache
decl_stmt|;
comment|// Rasterizer state cache
struct|struct
name|RasterizerStateKey
block|{
name|gl
operator|::
name|RasterizerState
name|rasterizerState
expr_stmt|;
name|bool
name|scissorEnabled
decl_stmt|;
block|}
struct|;
specifier|static
name|std
operator|::
name|size_t
name|hashRasterizerState
argument_list|(
specifier|const
name|RasterizerStateKey
operator|&
name|rasterState
argument_list|)
expr_stmt|;
specifier|static
name|bool
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
function_decl|;
specifier|static
specifier|const
name|unsigned
name|int
name|kMaxRasterizerStates
decl_stmt|;
typedef|typedef
name|std
operator|::
name|size_t
argument_list|(
operator|*
name|RasterizerStateHashFunction
argument_list|)
argument_list|(
specifier|const
name|RasterizerStateKey
operator|&
argument_list|)
expr_stmt|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|RasterizerStateEqualityFunction
function_decl|)
parameter_list|(
specifier|const
name|RasterizerStateKey
modifier|&
parameter_list|,
specifier|const
name|RasterizerStateKey
modifier|&
parameter_list|)
function_decl|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ID3D11RasterizerState
operator|*
operator|,
name|unsigned
name|long
name|long
operator|>
name|RasterizerStateCounterPair
expr_stmt|;
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|RasterizerStateKey
operator|,
name|RasterizerStateCounterPair
operator|,
name|RasterizerStateHashFunction
operator|,
name|RasterizerStateEqualityFunction
operator|>
name|RasterizerStateMap
expr_stmt|;
name|RasterizerStateMap
name|mRasterizerStateCache
decl_stmt|;
comment|// Depth stencil state cache
specifier|static
name|std
operator|::
name|size_t
name|hashDepthStencilState
argument_list|(
specifier|const
name|gl
operator|::
name|DepthStencilState
operator|&
name|dsState
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|compareDepthStencilStates
argument_list|(
specifier|const
name|gl
operator|::
name|DepthStencilState
operator|&
name|a
argument_list|,
specifier|const
name|gl
operator|::
name|DepthStencilState
operator|&
name|b
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|kMaxDepthStencilStates
decl_stmt|;
typedef|typedef
name|std
operator|::
name|size_t
argument_list|(
operator|*
name|DepthStencilStateHashFunction
argument_list|)
argument_list|(
specifier|const
name|gl
operator|::
name|DepthStencilState
operator|&
argument_list|)
expr_stmt|;
typedef|typedef
name|bool
argument_list|(
operator|*
name|DepthStencilStateEqualityFunction
argument_list|)
argument_list|(
specifier|const
name|gl
operator|::
name|DepthStencilState
operator|&
argument_list|,
specifier|const
name|gl
operator|::
name|DepthStencilState
operator|&
argument_list|)
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ID3D11DepthStencilState
operator|*
operator|,
name|unsigned
name|long
name|long
operator|>
name|DepthStencilStateCounterPair
expr_stmt|;
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|gl
operator|::
name|DepthStencilState
operator|,
name|DepthStencilStateCounterPair
operator|,
name|DepthStencilStateHashFunction
operator|,
name|DepthStencilStateEqualityFunction
operator|>
name|DepthStencilStateMap
expr_stmt|;
name|DepthStencilStateMap
name|mDepthStencilStateCache
decl_stmt|;
comment|// Sample state cache
specifier|static
name|std
operator|::
name|size_t
name|hashSamplerState
argument_list|(
specifier|const
name|gl
operator|::
name|SamplerState
operator|&
name|samplerState
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|compareSamplerStates
argument_list|(
specifier|const
name|gl
operator|::
name|SamplerState
operator|&
name|a
argument_list|,
specifier|const
name|gl
operator|::
name|SamplerState
operator|&
name|b
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|kMaxSamplerStates
decl_stmt|;
typedef|typedef
name|std
operator|::
name|size_t
argument_list|(
operator|*
name|SamplerStateHashFunction
argument_list|)
argument_list|(
specifier|const
name|gl
operator|::
name|SamplerState
operator|&
argument_list|)
expr_stmt|;
typedef|typedef
name|bool
argument_list|(
operator|*
name|SamplerStateEqualityFunction
argument_list|)
argument_list|(
specifier|const
name|gl
operator|::
name|SamplerState
operator|&
argument_list|,
specifier|const
name|gl
operator|::
name|SamplerState
operator|&
argument_list|)
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ID3D11SamplerState
operator|*
operator|,
name|unsigned
name|long
name|long
operator|>
name|SamplerStateCounterPair
expr_stmt|;
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|gl
operator|::
name|SamplerState
operator|,
name|SamplerStateCounterPair
operator|,
name|SamplerStateHashFunction
operator|,
name|SamplerStateEqualityFunction
operator|>
name|SamplerStateMap
expr_stmt|;
name|SamplerStateMap
name|mSamplerStateCache
decl_stmt|;
name|ID3D11Device
modifier|*
name|mDevice
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D11_RENDERSTATECACHE_H_
end_comment
end_unit
