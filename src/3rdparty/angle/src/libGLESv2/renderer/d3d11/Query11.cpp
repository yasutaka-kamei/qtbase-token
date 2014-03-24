begin_unit
begin_include
include|#
directive|include
file|"precompiled.h"
end_include
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
comment|// Query11.cpp: Defines the rx::Query11 class which implements rx::QueryImpl.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d11/Query11.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d11/Renderer11.h"
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
DECL|function|Query11
name|Query11
operator|::
name|Query11
parameter_list|(
name|rx
operator|::
name|Renderer11
modifier|*
name|renderer
parameter_list|,
name|GLenum
name|type
parameter_list|)
member_init_list|:
name|QueryImpl
argument_list|(
name|type
argument_list|)
block|{
name|mRenderer
operator|=
name|renderer
expr_stmt|;
name|mQuery
operator|=
name|NULL
expr_stmt|;
block|}
DECL|function|~Query11
name|Query11
operator|::
name|~
name|Query11
parameter_list|()
block|{
if|if
condition|(
name|mQuery
condition|)
block|{
name|mQuery
operator|->
name|Release
argument_list|()
expr_stmt|;
name|mQuery
operator|=
name|NULL
expr_stmt|;
block|}
block|}
DECL|function|begin
name|void
name|Query11
operator|::
name|begin
parameter_list|()
block|{
if|if
condition|(
name|mQuery
operator|==
name|NULL
condition|)
block|{
name|D3D11_QUERY_DESC
name|queryDesc
decl_stmt|;
name|queryDesc
operator|.
name|Query
operator|=
name|D3D11_QUERY_OCCLUSION
expr_stmt|;
name|queryDesc
operator|.
name|MiscFlags
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|mRenderer
operator|->
name|getDevice
argument_list|()
operator|->
name|CreateQuery
argument_list|(
operator|&
name|queryDesc
argument_list|,
operator|&
name|mQuery
argument_list|)
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|)
return|;
block|}
block|}
name|mRenderer
operator|->
name|getDeviceContext
argument_list|()
operator|->
name|Begin
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
block|}
DECL|function|end
name|void
name|Query11
operator|::
name|end
parameter_list|()
block|{
if|if
condition|(
name|mQuery
operator|==
name|NULL
condition|)
block|{
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_INVALID_OPERATION
argument_list|)
return|;
block|}
name|mRenderer
operator|->
name|getDeviceContext
argument_list|()
operator|->
name|End
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
name|mStatus
operator|=
name|GL_FALSE
expr_stmt|;
name|mResult
operator|=
name|GL_FALSE
expr_stmt|;
block|}
DECL|function|getResult
name|GLuint
name|Query11
operator|::
name|getResult
parameter_list|()
block|{
if|if
condition|(
name|mQuery
operator|!=
name|NULL
condition|)
block|{
while|while
condition|(
operator|!
name|testQuery
argument_list|()
condition|)
block|{
name|Sleep
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// explicitly check for device loss, some drivers seem to return S_FALSE
comment|// if the device is lost
if|if
condition|(
name|mRenderer
operator|->
name|testDeviceLost
argument_list|(
literal|true
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|0
argument_list|)
return|;
block|}
block|}
block|}
return|return
name|mResult
return|;
block|}
DECL|function|isResultAvailable
name|GLboolean
name|Query11
operator|::
name|isResultAvailable
parameter_list|()
block|{
if|if
condition|(
name|mQuery
operator|!=
name|NULL
condition|)
block|{
name|testQuery
argument_list|()
expr_stmt|;
block|}
return|return
name|mStatus
return|;
block|}
DECL|function|testQuery
name|GLboolean
name|Query11
operator|::
name|testQuery
parameter_list|()
block|{
if|if
condition|(
name|mQuery
operator|!=
name|NULL
operator|&&
name|mStatus
operator|!=
name|GL_TRUE
condition|)
block|{
name|UINT64
name|numPixels
init|=
literal|0
decl_stmt|;
name|HRESULT
name|result
init|=
name|mRenderer
operator|->
name|getDeviceContext
argument_list|()
operator|->
name|GetData
argument_list|(
name|mQuery
argument_list|,
operator|&
name|numPixels
argument_list|,
sizeof|sizeof
argument_list|(
name|UINT64
argument_list|)
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|==
name|S_OK
condition|)
block|{
name|mStatus
operator|=
name|GL_TRUE
expr_stmt|;
switch|switch
condition|(
name|getType
argument_list|()
condition|)
block|{
case|case
name|GL_ANY_SAMPLES_PASSED_EXT
case|:
case|case
name|GL_ANY_SAMPLES_PASSED_CONSERVATIVE_EXT
case|:
name|mResult
operator|=
operator|(
name|numPixels
operator|>
literal|0
operator|)
condition|?
name|GL_TRUE
else|:
name|GL_FALSE
expr_stmt|;
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|mRenderer
operator|->
name|testDeviceLost
argument_list|(
literal|true
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
name|GL_TRUE
argument_list|)
return|;
block|}
return|return
name|mStatus
return|;
block|}
return|return
name|GL_TRUE
return|;
comment|// prevent blocking when query is null
block|}
block|}
end_namespace
end_unit