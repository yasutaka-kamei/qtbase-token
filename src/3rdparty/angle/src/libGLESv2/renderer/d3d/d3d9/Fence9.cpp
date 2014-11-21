begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
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
comment|// Fence9.cpp: Defines the rx::FenceNV9 class.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d9/Fence9.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d9/renderer9_utils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d9/Renderer9.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/main.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|FenceNV9
name|FenceNV9
operator|::
name|FenceNV9
parameter_list|(
name|Renderer9
modifier|*
name|renderer
parameter_list|)
member_init_list|:
name|FenceNVImpl
argument_list|()
member_init_list|,
name|mRenderer
argument_list|(
name|renderer
argument_list|)
member_init_list|,
name|mQuery
argument_list|(
name|NULL
argument_list|)
block|{ }
DECL|function|~FenceNV9
name|FenceNV9
operator|::
name|~
name|FenceNV9
parameter_list|()
block|{
name|SafeRelease
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
block|}
DECL|function|set
name|gl
operator|::
name|Error
name|FenceNV9
operator|::
name|set
parameter_list|()
block|{
if|if
condition|(
operator|!
name|mQuery
condition|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|mRenderer
operator|->
name|allocateEventQuery
argument_list|(
operator|&
name|mQuery
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
block|}
name|HRESULT
name|result
init|=
name|mQuery
operator|->
name|Issue
argument_list|(
name|D3DISSUE_END
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|ASSERT
argument_list|(
name|result
operator|==
name|D3DERR_OUTOFVIDEOMEMORY
operator|||
name|result
operator|==
name|E_OUTOFMEMORY
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to end event query, result: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|test
name|gl
operator|::
name|Error
name|FenceNV9
operator|::
name|test
parameter_list|(
name|bool
name|flushCommandBuffer
parameter_list|,
name|GLboolean
modifier|*
name|outFinished
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
name|DWORD
name|getDataFlags
init|=
operator|(
name|flushCommandBuffer
condition|?
name|D3DGETDATA_FLUSH
else|:
literal|0
operator|)
decl_stmt|;
name|HRESULT
name|result
init|=
name|mQuery
operator|->
name|GetData
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|getDataFlags
argument_list|)
decl_stmt|;
if|if
condition|(
name|d3d9
operator|::
name|isDeviceLostError
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|mRenderer
operator|->
name|notifyDeviceLost
argument_list|()
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Device was lost while querying result of an event query."
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to get query data, result: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
name|ASSERT
argument_list|(
name|result
operator|==
name|S_OK
operator|||
name|result
operator|==
name|S_FALSE
argument_list|)
expr_stmt|;
operator|*
name|outFinished
operator|=
operator|(
operator|(
name|result
operator|==
name|S_OK
operator|)
condition|?
name|GL_TRUE
else|:
name|GL_FALSE
operator|)
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
DECL|function|finishFence
name|gl
operator|::
name|Error
name|FenceNV9
operator|::
name|finishFence
parameter_list|(
name|GLboolean
modifier|*
name|outFinished
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|outFinished
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|outFinished
operator|!=
name|GL_TRUE
condition|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|test
argument_list|(
literal|true
argument_list|,
name|outFinished
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|Sleep
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
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
end_namespace
end_unit
