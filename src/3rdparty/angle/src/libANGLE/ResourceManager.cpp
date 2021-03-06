begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// ResourceManager.cpp: Implements the gl::ResourceManager class, which tracks and
end_comment
begin_comment
comment|// retrieves objects which may be shared by multiple Contexts.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/ResourceManager.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Buffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Program.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Renderbuffer.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Shader.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Texture.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Sampler.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Fence.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/Renderer.h"
end_include
begin_namespace
DECL|namespace|gl
namespace|namespace
name|gl
block|{
DECL|function|ResourceManager
name|ResourceManager
operator|::
name|ResourceManager
parameter_list|(
name|rx
operator|::
name|ImplFactory
modifier|*
name|factory
parameter_list|)
member_init_list|:
name|mFactory
argument_list|(
name|factory
argument_list|)
member_init_list|,
name|mRefCount
argument_list|(
literal|1
argument_list|)
block|{ }
DECL|function|~ResourceManager
name|ResourceManager
operator|::
name|~
name|ResourceManager
parameter_list|()
block|{
while|while
condition|(
operator|!
name|mBufferMap
operator|.
name|empty
argument_list|()
condition|)
block|{
name|deleteBuffer
argument_list|(
name|mBufferMap
operator|.
name|begin
argument_list|()
operator|->
name|first
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|!
name|mProgramMap
operator|.
name|empty
argument_list|()
condition|)
block|{
name|deleteProgram
argument_list|(
name|mProgramMap
operator|.
name|begin
argument_list|()
operator|->
name|first
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|!
name|mShaderMap
operator|.
name|empty
argument_list|()
condition|)
block|{
name|deleteShader
argument_list|(
name|mShaderMap
operator|.
name|begin
argument_list|()
operator|->
name|first
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|!
name|mRenderbufferMap
operator|.
name|empty
argument_list|()
condition|)
block|{
name|deleteRenderbuffer
argument_list|(
name|mRenderbufferMap
operator|.
name|begin
argument_list|()
operator|->
name|first
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|!
name|mTextureMap
operator|.
name|empty
argument_list|()
condition|)
block|{
name|deleteTexture
argument_list|(
name|mTextureMap
operator|.
name|begin
argument_list|()
operator|->
name|first
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|!
name|mSamplerMap
operator|.
name|empty
argument_list|()
condition|)
block|{
name|deleteSampler
argument_list|(
name|mSamplerMap
operator|.
name|begin
argument_list|()
operator|->
name|first
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|!
name|mFenceSyncMap
operator|.
name|empty
argument_list|()
condition|)
block|{
name|deleteFenceSync
argument_list|(
name|mFenceSyncMap
operator|.
name|begin
argument_list|()
operator|->
name|first
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|addRef
name|void
name|ResourceManager
operator|::
name|addRef
parameter_list|()
block|{
name|mRefCount
operator|++
expr_stmt|;
block|}
DECL|function|release
name|void
name|ResourceManager
operator|::
name|release
parameter_list|()
block|{
if|if
condition|(
operator|--
name|mRefCount
operator|==
literal|0
condition|)
block|{
operator|delete
name|this
expr_stmt|;
block|}
block|}
comment|// Returns an unused buffer name
DECL|function|createBuffer
name|GLuint
name|ResourceManager
operator|::
name|createBuffer
parameter_list|()
block|{
name|GLuint
name|handle
init|=
name|mBufferHandleAllocator
operator|.
name|allocate
argument_list|()
decl_stmt|;
name|mBufferMap
index|[
name|handle
index|]
operator|=
name|NULL
expr_stmt|;
return|return
name|handle
return|;
block|}
comment|// Returns an unused shader/program name
DECL|function|createShader
name|GLuint
name|ResourceManager
operator|::
name|createShader
parameter_list|(
specifier|const
name|gl
operator|::
name|Limitations
modifier|&
name|rendererLimitations
parameter_list|,
name|GLenum
name|type
parameter_list|)
block|{
name|GLuint
name|handle
init|=
name|mProgramShaderHandleAllocator
operator|.
name|allocate
argument_list|()
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|GL_VERTEX_SHADER
operator|||
name|type
operator|==
name|GL_FRAGMENT_SHADER
condition|)
block|{
name|mShaderMap
index|[
name|handle
index|]
operator|=
operator|new
name|Shader
argument_list|(
name|this
argument_list|,
name|mFactory
argument_list|,
name|rendererLimitations
argument_list|,
name|type
argument_list|,
name|handle
argument_list|)
expr_stmt|;
block|}
else|else
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|handle
return|;
block|}
comment|// Returns an unused program/shader name
DECL|function|createProgram
name|GLuint
name|ResourceManager
operator|::
name|createProgram
parameter_list|()
block|{
name|GLuint
name|handle
init|=
name|mProgramShaderHandleAllocator
operator|.
name|allocate
argument_list|()
decl_stmt|;
name|mProgramMap
index|[
name|handle
index|]
operator|=
operator|new
name|Program
argument_list|(
name|mFactory
argument_list|,
name|this
argument_list|,
name|handle
argument_list|)
expr_stmt|;
return|return
name|handle
return|;
block|}
comment|// Returns an unused texture name
DECL|function|createTexture
name|GLuint
name|ResourceManager
operator|::
name|createTexture
parameter_list|()
block|{
name|GLuint
name|handle
init|=
name|mTextureHandleAllocator
operator|.
name|allocate
argument_list|()
decl_stmt|;
name|mTextureMap
index|[
name|handle
index|]
operator|=
name|NULL
expr_stmt|;
return|return
name|handle
return|;
block|}
comment|// Returns an unused renderbuffer name
DECL|function|createRenderbuffer
name|GLuint
name|ResourceManager
operator|::
name|createRenderbuffer
parameter_list|()
block|{
name|GLuint
name|handle
init|=
name|mRenderbufferHandleAllocator
operator|.
name|allocate
argument_list|()
decl_stmt|;
name|mRenderbufferMap
index|[
name|handle
index|]
operator|=
name|NULL
expr_stmt|;
return|return
name|handle
return|;
block|}
comment|// Returns an unused sampler name
DECL|function|createSampler
name|GLuint
name|ResourceManager
operator|::
name|createSampler
parameter_list|()
block|{
name|GLuint
name|handle
init|=
name|mSamplerHandleAllocator
operator|.
name|allocate
argument_list|()
decl_stmt|;
name|mSamplerMap
index|[
name|handle
index|]
operator|=
name|NULL
expr_stmt|;
return|return
name|handle
return|;
block|}
comment|// Returns the next unused fence name, and allocates the fence
DECL|function|createFenceSync
name|GLuint
name|ResourceManager
operator|::
name|createFenceSync
parameter_list|()
block|{
name|GLuint
name|handle
init|=
name|mFenceSyncHandleAllocator
operator|.
name|allocate
argument_list|()
decl_stmt|;
name|FenceSync
modifier|*
name|fenceSync
init|=
operator|new
name|FenceSync
argument_list|(
name|mFactory
operator|->
name|createFenceSync
argument_list|()
argument_list|,
name|handle
argument_list|)
decl_stmt|;
name|fenceSync
operator|->
name|addRef
argument_list|()
expr_stmt|;
name|mFenceSyncMap
index|[
name|handle
index|]
operator|=
name|fenceSync
expr_stmt|;
return|return
name|handle
return|;
block|}
DECL|function|deleteBuffer
name|void
name|ResourceManager
operator|::
name|deleteBuffer
parameter_list|(
name|GLuint
name|buffer
parameter_list|)
block|{
name|BufferMap
operator|::
name|iterator
name|bufferObject
init|=
name|mBufferMap
operator|.
name|find
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
if|if
condition|(
name|bufferObject
operator|!=
name|mBufferMap
operator|.
name|end
argument_list|()
condition|)
block|{
name|mBufferHandleAllocator
operator|.
name|release
argument_list|(
name|bufferObject
operator|->
name|first
argument_list|)
expr_stmt|;
if|if
condition|(
name|bufferObject
operator|->
name|second
condition|)
name|bufferObject
operator|->
name|second
operator|->
name|release
argument_list|()
expr_stmt|;
name|mBufferMap
operator|.
name|erase
argument_list|(
name|bufferObject
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|deleteShader
name|void
name|ResourceManager
operator|::
name|deleteShader
parameter_list|(
name|GLuint
name|shader
parameter_list|)
block|{
name|ShaderMap
operator|::
name|iterator
name|shaderObject
init|=
name|mShaderMap
operator|.
name|find
argument_list|(
name|shader
argument_list|)
decl_stmt|;
if|if
condition|(
name|shaderObject
operator|!=
name|mShaderMap
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|shaderObject
operator|->
name|second
operator|->
name|getRefCount
argument_list|()
operator|==
literal|0
condition|)
block|{
name|mProgramShaderHandleAllocator
operator|.
name|release
argument_list|(
name|shaderObject
operator|->
name|first
argument_list|)
expr_stmt|;
operator|delete
name|shaderObject
operator|->
name|second
expr_stmt|;
name|mShaderMap
operator|.
name|erase
argument_list|(
name|shaderObject
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|shaderObject
operator|->
name|second
operator|->
name|flagForDeletion
argument_list|()
expr_stmt|;
block|}
block|}
block|}
DECL|function|deleteProgram
name|void
name|ResourceManager
operator|::
name|deleteProgram
parameter_list|(
name|GLuint
name|program
parameter_list|)
block|{
name|ProgramMap
operator|::
name|iterator
name|programObject
init|=
name|mProgramMap
operator|.
name|find
argument_list|(
name|program
argument_list|)
decl_stmt|;
if|if
condition|(
name|programObject
operator|!=
name|mProgramMap
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|programObject
operator|->
name|second
operator|->
name|getRefCount
argument_list|()
operator|==
literal|0
condition|)
block|{
name|mProgramShaderHandleAllocator
operator|.
name|release
argument_list|(
name|programObject
operator|->
name|first
argument_list|)
expr_stmt|;
operator|delete
name|programObject
operator|->
name|second
expr_stmt|;
name|mProgramMap
operator|.
name|erase
argument_list|(
name|programObject
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|programObject
operator|->
name|second
operator|->
name|flagForDeletion
argument_list|()
expr_stmt|;
block|}
block|}
block|}
DECL|function|deleteTexture
name|void
name|ResourceManager
operator|::
name|deleteTexture
parameter_list|(
name|GLuint
name|texture
parameter_list|)
block|{
name|TextureMap
operator|::
name|iterator
name|textureObject
init|=
name|mTextureMap
operator|.
name|find
argument_list|(
name|texture
argument_list|)
decl_stmt|;
if|if
condition|(
name|textureObject
operator|!=
name|mTextureMap
operator|.
name|end
argument_list|()
condition|)
block|{
name|mTextureHandleAllocator
operator|.
name|release
argument_list|(
name|textureObject
operator|->
name|first
argument_list|)
expr_stmt|;
if|if
condition|(
name|textureObject
operator|->
name|second
condition|)
name|textureObject
operator|->
name|second
operator|->
name|release
argument_list|()
expr_stmt|;
name|mTextureMap
operator|.
name|erase
argument_list|(
name|textureObject
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|deleteRenderbuffer
name|void
name|ResourceManager
operator|::
name|deleteRenderbuffer
parameter_list|(
name|GLuint
name|renderbuffer
parameter_list|)
block|{
name|RenderbufferMap
operator|::
name|iterator
name|renderbufferObject
init|=
name|mRenderbufferMap
operator|.
name|find
argument_list|(
name|renderbuffer
argument_list|)
decl_stmt|;
if|if
condition|(
name|renderbufferObject
operator|!=
name|mRenderbufferMap
operator|.
name|end
argument_list|()
condition|)
block|{
name|mRenderbufferHandleAllocator
operator|.
name|release
argument_list|(
name|renderbufferObject
operator|->
name|first
argument_list|)
expr_stmt|;
if|if
condition|(
name|renderbufferObject
operator|->
name|second
condition|)
name|renderbufferObject
operator|->
name|second
operator|->
name|release
argument_list|()
expr_stmt|;
name|mRenderbufferMap
operator|.
name|erase
argument_list|(
name|renderbufferObject
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|deleteSampler
name|void
name|ResourceManager
operator|::
name|deleteSampler
parameter_list|(
name|GLuint
name|sampler
parameter_list|)
block|{
name|auto
name|samplerObject
init|=
name|mSamplerMap
operator|.
name|find
argument_list|(
name|sampler
argument_list|)
decl_stmt|;
if|if
condition|(
name|samplerObject
operator|!=
name|mSamplerMap
operator|.
name|end
argument_list|()
condition|)
block|{
name|mSamplerHandleAllocator
operator|.
name|release
argument_list|(
name|samplerObject
operator|->
name|first
argument_list|)
expr_stmt|;
if|if
condition|(
name|samplerObject
operator|->
name|second
condition|)
name|samplerObject
operator|->
name|second
operator|->
name|release
argument_list|()
expr_stmt|;
name|mSamplerMap
operator|.
name|erase
argument_list|(
name|samplerObject
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|deleteFenceSync
name|void
name|ResourceManager
operator|::
name|deleteFenceSync
parameter_list|(
name|GLuint
name|fenceSync
parameter_list|)
block|{
name|auto
name|fenceObjectIt
init|=
name|mFenceSyncMap
operator|.
name|find
argument_list|(
name|fenceSync
argument_list|)
decl_stmt|;
if|if
condition|(
name|fenceObjectIt
operator|!=
name|mFenceSyncMap
operator|.
name|end
argument_list|()
condition|)
block|{
name|mFenceSyncHandleAllocator
operator|.
name|release
argument_list|(
name|fenceObjectIt
operator|->
name|first
argument_list|)
expr_stmt|;
if|if
condition|(
name|fenceObjectIt
operator|->
name|second
condition|)
name|fenceObjectIt
operator|->
name|second
operator|->
name|release
argument_list|()
expr_stmt|;
name|mFenceSyncMap
operator|.
name|erase
argument_list|(
name|fenceObjectIt
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|getBuffer
name|Buffer
modifier|*
name|ResourceManager
operator|::
name|getBuffer
parameter_list|(
name|unsigned
name|int
name|handle
parameter_list|)
block|{
name|BufferMap
operator|::
name|iterator
name|buffer
init|=
name|mBufferMap
operator|.
name|find
argument_list|(
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|buffer
operator|==
name|mBufferMap
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|NULL
return|;
block|}
else|else
block|{
return|return
name|buffer
operator|->
name|second
return|;
block|}
block|}
DECL|function|getShader
name|Shader
modifier|*
name|ResourceManager
operator|::
name|getShader
parameter_list|(
name|unsigned
name|int
name|handle
parameter_list|)
block|{
name|ShaderMap
operator|::
name|iterator
name|shader
init|=
name|mShaderMap
operator|.
name|find
argument_list|(
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|shader
operator|==
name|mShaderMap
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|NULL
return|;
block|}
else|else
block|{
return|return
name|shader
operator|->
name|second
return|;
block|}
block|}
DECL|function|getTexture
name|Texture
modifier|*
name|ResourceManager
operator|::
name|getTexture
parameter_list|(
name|unsigned
name|int
name|handle
parameter_list|)
block|{
if|if
condition|(
name|handle
operator|==
literal|0
condition|)
return|return
name|NULL
return|;
name|TextureMap
operator|::
name|iterator
name|texture
init|=
name|mTextureMap
operator|.
name|find
argument_list|(
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|texture
operator|==
name|mTextureMap
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|NULL
return|;
block|}
else|else
block|{
return|return
name|texture
operator|->
name|second
return|;
block|}
block|}
DECL|function|getProgram
name|Program
modifier|*
name|ResourceManager
operator|::
name|getProgram
parameter_list|(
name|unsigned
name|int
name|handle
parameter_list|)
specifier|const
block|{
name|ProgramMap
operator|::
name|const_iterator
name|program
init|=
name|mProgramMap
operator|.
name|find
argument_list|(
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|program
operator|==
name|mProgramMap
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|NULL
return|;
block|}
else|else
block|{
return|return
name|program
operator|->
name|second
return|;
block|}
block|}
DECL|function|getRenderbuffer
name|Renderbuffer
modifier|*
name|ResourceManager
operator|::
name|getRenderbuffer
parameter_list|(
name|unsigned
name|int
name|handle
parameter_list|)
block|{
name|RenderbufferMap
operator|::
name|iterator
name|renderbuffer
init|=
name|mRenderbufferMap
operator|.
name|find
argument_list|(
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|renderbuffer
operator|==
name|mRenderbufferMap
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|NULL
return|;
block|}
else|else
block|{
return|return
name|renderbuffer
operator|->
name|second
return|;
block|}
block|}
DECL|function|getSampler
name|Sampler
modifier|*
name|ResourceManager
operator|::
name|getSampler
parameter_list|(
name|unsigned
name|int
name|handle
parameter_list|)
block|{
name|auto
name|sampler
init|=
name|mSamplerMap
operator|.
name|find
argument_list|(
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|sampler
operator|==
name|mSamplerMap
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|NULL
return|;
block|}
else|else
block|{
return|return
name|sampler
operator|->
name|second
return|;
block|}
block|}
DECL|function|getFenceSync
name|FenceSync
modifier|*
name|ResourceManager
operator|::
name|getFenceSync
parameter_list|(
name|unsigned
name|int
name|handle
parameter_list|)
block|{
name|auto
name|fenceObjectIt
init|=
name|mFenceSyncMap
operator|.
name|find
argument_list|(
name|handle
argument_list|)
decl_stmt|;
if|if
condition|(
name|fenceObjectIt
operator|==
name|mFenceSyncMap
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|NULL
return|;
block|}
else|else
block|{
return|return
name|fenceObjectIt
operator|->
name|second
return|;
block|}
block|}
DECL|function|setRenderbuffer
name|void
name|ResourceManager
operator|::
name|setRenderbuffer
parameter_list|(
name|GLuint
name|handle
parameter_list|,
name|Renderbuffer
modifier|*
name|buffer
parameter_list|)
block|{
name|mRenderbufferMap
index|[
name|handle
index|]
operator|=
name|buffer
expr_stmt|;
block|}
DECL|function|checkBufferAllocation
name|void
name|ResourceManager
operator|::
name|checkBufferAllocation
parameter_list|(
name|GLuint
name|handle
parameter_list|)
block|{
if|if
condition|(
name|handle
operator|!=
literal|0
condition|)
block|{
name|auto
name|bufferMapIt
init|=
name|mBufferMap
operator|.
name|find
argument_list|(
name|handle
argument_list|)
decl_stmt|;
name|bool
name|handleAllocated
init|=
operator|(
name|bufferMapIt
operator|!=
name|mBufferMap
operator|.
name|end
argument_list|()
operator|)
decl_stmt|;
if|if
condition|(
name|handleAllocated
operator|&&
name|bufferMapIt
operator|->
name|second
operator|!=
literal|nullptr
condition|)
block|{
return|return;
block|}
name|Buffer
modifier|*
name|buffer
init|=
operator|new
name|Buffer
argument_list|(
name|mFactory
operator|->
name|createBuffer
argument_list|()
argument_list|,
name|handle
argument_list|)
decl_stmt|;
name|buffer
operator|->
name|addRef
argument_list|()
expr_stmt|;
if|if
condition|(
name|handleAllocated
condition|)
block|{
name|bufferMapIt
operator|->
name|second
operator|=
name|buffer
expr_stmt|;
block|}
else|else
block|{
name|mBufferHandleAllocator
operator|.
name|reserve
argument_list|(
name|handle
argument_list|)
expr_stmt|;
name|mBufferMap
index|[
name|handle
index|]
operator|=
name|buffer
expr_stmt|;
block|}
block|}
block|}
DECL|function|checkTextureAllocation
name|void
name|ResourceManager
operator|::
name|checkTextureAllocation
parameter_list|(
name|GLuint
name|handle
parameter_list|,
name|GLenum
name|type
parameter_list|)
block|{
if|if
condition|(
name|handle
operator|!=
literal|0
condition|)
block|{
name|auto
name|textureMapIt
init|=
name|mTextureMap
operator|.
name|find
argument_list|(
name|handle
argument_list|)
decl_stmt|;
name|bool
name|handleAllocated
init|=
operator|(
name|textureMapIt
operator|!=
name|mTextureMap
operator|.
name|end
argument_list|()
operator|)
decl_stmt|;
if|if
condition|(
name|handleAllocated
operator|&&
name|textureMapIt
operator|->
name|second
operator|!=
literal|nullptr
condition|)
block|{
return|return;
block|}
name|Texture
modifier|*
name|texture
init|=
operator|new
name|Texture
argument_list|(
name|mFactory
operator|->
name|createTexture
argument_list|(
name|type
argument_list|)
argument_list|,
name|handle
argument_list|,
name|type
argument_list|)
decl_stmt|;
name|texture
operator|->
name|addRef
argument_list|()
expr_stmt|;
if|if
condition|(
name|handleAllocated
condition|)
block|{
name|textureMapIt
operator|->
name|second
operator|=
name|texture
expr_stmt|;
block|}
else|else
block|{
name|mTextureHandleAllocator
operator|.
name|reserve
argument_list|(
name|handle
argument_list|)
expr_stmt|;
name|mTextureMap
index|[
name|handle
index|]
operator|=
name|texture
expr_stmt|;
block|}
block|}
block|}
DECL|function|checkRenderbufferAllocation
name|void
name|ResourceManager
operator|::
name|checkRenderbufferAllocation
parameter_list|(
name|GLuint
name|handle
parameter_list|)
block|{
if|if
condition|(
name|handle
operator|!=
literal|0
condition|)
block|{
name|auto
name|renderbufferMapIt
init|=
name|mRenderbufferMap
operator|.
name|find
argument_list|(
name|handle
argument_list|)
decl_stmt|;
name|bool
name|handleAllocated
init|=
operator|(
name|renderbufferMapIt
operator|!=
name|mRenderbufferMap
operator|.
name|end
argument_list|()
operator|)
decl_stmt|;
if|if
condition|(
name|handleAllocated
operator|&&
name|renderbufferMapIt
operator|->
name|second
operator|!=
literal|nullptr
condition|)
block|{
return|return;
block|}
name|Renderbuffer
modifier|*
name|renderbuffer
init|=
operator|new
name|Renderbuffer
argument_list|(
name|mFactory
operator|->
name|createRenderbuffer
argument_list|()
argument_list|,
name|handle
argument_list|)
decl_stmt|;
name|renderbuffer
operator|->
name|addRef
argument_list|()
expr_stmt|;
if|if
condition|(
name|handleAllocated
condition|)
block|{
name|renderbufferMapIt
operator|->
name|second
operator|=
name|renderbuffer
expr_stmt|;
block|}
else|else
block|{
name|mRenderbufferHandleAllocator
operator|.
name|reserve
argument_list|(
name|handle
argument_list|)
expr_stmt|;
name|mRenderbufferMap
index|[
name|handle
index|]
operator|=
name|renderbuffer
expr_stmt|;
block|}
block|}
block|}
DECL|function|checkSamplerAllocation
name|void
name|ResourceManager
operator|::
name|checkSamplerAllocation
parameter_list|(
name|GLuint
name|sampler
parameter_list|)
block|{
if|if
condition|(
name|sampler
operator|!=
literal|0
operator|&&
operator|!
name|getSampler
argument_list|(
name|sampler
argument_list|)
condition|)
block|{
name|Sampler
modifier|*
name|samplerObject
init|=
operator|new
name|Sampler
argument_list|(
name|mFactory
argument_list|,
name|sampler
argument_list|)
decl_stmt|;
name|mSamplerMap
index|[
name|sampler
index|]
operator|=
name|samplerObject
expr_stmt|;
name|samplerObject
operator|->
name|addRef
argument_list|()
expr_stmt|;
comment|// Samplers cannot be created via Bind
block|}
block|}
DECL|function|isSampler
name|bool
name|ResourceManager
operator|::
name|isSampler
parameter_list|(
name|GLuint
name|sampler
parameter_list|)
block|{
return|return
name|mSamplerMap
operator|.
name|find
argument_list|(
name|sampler
argument_list|)
operator|!=
name|mSamplerMap
operator|.
name|end
argument_list|()
return|;
block|}
block|}
end_namespace
end_unit
