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
comment|// Query9.cpp: Defines the rx::Query9 class which implements rx::QueryImpl.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/renderer/d3d/d3d9/Query9.h"
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
DECL|function|Query9
name|Query9
operator|::
name|Query9
parameter_list|(
name|Renderer9
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
name|GL_FALSE
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
DECL|function|~Query9
name|Query9
operator|::
name|~
name|Query9
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
name|Query9
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
name|D3DQUERYTYPE_OCCLUSION
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
name|HRESULT
name|result
init|=
name|mQuery
operator|->
name|Issue
argument_list|(
name|D3DISSUE_BEGIN
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
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
literal|"Failed to begin internal query, result: 0x%X."
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
DECL|function|end
name|gl
operator|::
name|Error
name|Query9
operator|::
name|end
parameter_list|()
block|{
name|ASSERT
argument_list|(
name|mQuery
argument_list|)
expr_stmt|;
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
name|ASSERT
argument_list|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
argument_list|)
expr_stmt|;
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
literal|"Failed to end internal query, result: 0x%X."
argument_list|,
name|result
argument_list|)
return|;
block|}
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
name|Query9
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
name|Query9
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
name|Query9
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
name|DWORD
name|numPixels
init|=
literal|0
decl_stmt|;
name|HRESULT
name|hres
init|=
name|mQuery
operator|->
name|GetData
argument_list|(
operator|&
name|numPixels
argument_list|,
sizeof|sizeof
argument_list|(
name|DWORD
argument_list|)
argument_list|,
name|D3DGETDATA_FLUSH
argument_list|)
decl_stmt|;
if|if
condition|(
name|hres
operator|==
name|S_OK
condition|)
block|{
name|mQueryFinished
operator|=
literal|true
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
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|d3d9
operator|::
name|isDeviceLostError
argument_list|(
name|hres
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
literal|"Failed to test get query result, device is lost."
argument_list|)
return|;
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
