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
comment|// Query11.cpp: Defines the rx::Query11 class which implements rx::QueryImpl.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d11/Query11.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d11/Renderer11.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d11/renderer11_utils.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/main.h"
end_include
begin_include
include|#
directive|include
file|"common/utilities.h"
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2ext.h>
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
member_init_list|,
name|mResult
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mQueryFinished
argument_list|(
literal|false
argument_list|)
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
DECL|function|~Query11
name|Query11
operator|::
name|~
name|Query11
parameter_list|()
block|{
name|SafeRelease
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
block|}
DECL|function|begin
name|gl
operator|::
name|Error
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
name|gl_d3d11
operator|::
name|ConvertQueryType
argument_list|(
name|getType
argument_list|()
argument_list|)
expr_stmt|;
name|queryDesc
operator|.
name|MiscFlags
operator|=
literal|0
expr_stmt|;
name|HRESULT
name|result
init|=
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
decl_stmt|;
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
literal|"Internal query creation failed, result: 0x%X."
argument_list|,
name|result
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
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|end
name|gl
operator|::
name|Error
name|Query11
operator|::
name|end
parameter_list|()
block|{
name|ASSERT
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
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
name|mQueryFinished
operator|=
literal|false
expr_stmt|;
name|mResult
operator|=
name|GL_FALSE
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
DECL|function|getResult
name|gl
operator|::
name|Error
name|Query11
operator|::
name|getResult
parameter_list|(
name|GLuint
modifier|*
name|params
parameter_list|)
block|{
while|while
condition|(
operator|!
name|mQueryFinished
condition|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|testQuery
argument_list|()
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
if|if
condition|(
operator|!
name|mQueryFinished
condition|)
block|{
name|Sleep
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
name|ASSERT
argument_list|(
name|mQueryFinished
argument_list|)
expr_stmt|;
operator|*
name|params
operator|=
name|mResult
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
DECL|function|isResultAvailable
name|gl
operator|::
name|Error
name|Query11
operator|::
name|isResultAvailable
parameter_list|(
name|GLuint
modifier|*
name|available
parameter_list|)
block|{
name|gl
operator|::
name|Error
name|error
init|=
name|testQuery
argument_list|()
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
operator|*
name|available
operator|=
operator|(
name|mQueryFinished
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
DECL|function|testQuery
name|gl
operator|::
name|Error
name|Query11
operator|::
name|testQuery
parameter_list|()
block|{
if|if
condition|(
operator|!
name|mQueryFinished
condition|)
block|{
name|ASSERT
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
name|ID3D11DeviceContext
modifier|*
name|context
init|=
name|mRenderer
operator|->
name|getDeviceContext
argument_list|()
decl_stmt|;
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
block|{
name|UINT64
name|numPixels
init|=
literal|0
decl_stmt|;
name|HRESULT
name|result
init|=
name|context
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
name|numPixels
argument_list|)
argument_list|,
literal|0
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
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to get the data of an internal query, result: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
if|if
condition|(
name|result
operator|==
name|S_OK
condition|)
block|{
name|mQueryFinished
operator|=
literal|true
expr_stmt|;
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
block|}
block|}
break|break;
case|case
name|GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
case|:
block|{
name|D3D11_QUERY_DATA_SO_STATISTICS
name|soStats
init|=
block|{
literal|0
block|}
decl_stmt|;
name|HRESULT
name|result
init|=
name|context
operator|->
name|GetData
argument_list|(
name|mQuery
argument_list|,
operator|&
name|soStats
argument_list|,
sizeof|sizeof
argument_list|(
name|soStats
argument_list|)
argument_list|,
literal|0
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
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to get the data of an internal query, result: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
if|if
condition|(
name|result
operator|==
name|S_OK
condition|)
block|{
name|mQueryFinished
operator|=
literal|true
expr_stmt|;
name|mResult
operator|=
cast|static_cast
argument_list|<
name|GLuint
argument_list|>
argument_list|(
name|soStats
operator|.
name|NumPrimitivesWritten
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
default|default:
name|UNREACHABLE
argument_list|()
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|!
name|mQueryFinished
operator|&&
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
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to test get query result, device is lost."
argument_list|)
return|;
block|}
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
