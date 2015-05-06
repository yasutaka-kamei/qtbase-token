begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright(c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// global_state.h : Defines functions for querying the thread-local GL and EGL state.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_GLOBALSTATE_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_GLOBALSTATE_H_
define|#
directive|define
name|LIBGLESV2_GLOBALSTATE_H_
end_define
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Context
decl_stmt|;
name|Context
modifier|*
name|GetGlobalContext
parameter_list|()
function_decl|;
name|Context
modifier|*
name|GetValidGlobalContext
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|egl
block|{
name|class
name|Error
decl_stmt|;
name|class
name|Display
decl_stmt|;
name|class
name|Surface
decl_stmt|;
name|void
name|SetGlobalError
parameter_list|(
specifier|const
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
name|EGLint
name|GetGlobalError
parameter_list|()
function_decl|;
name|void
name|SetGlobalAPI
parameter_list|(
name|EGLenum
name|API
parameter_list|)
function_decl|;
name|EGLenum
name|GetGlobalAPI
parameter_list|()
function_decl|;
name|void
name|SetGlobalDisplay
parameter_list|(
name|Display
modifier|*
name|dpy
parameter_list|)
function_decl|;
name|Display
modifier|*
name|GetGlobalDisplay
parameter_list|()
function_decl|;
name|void
name|SetGlobalDrawSurface
parameter_list|(
name|Surface
modifier|*
name|surface
parameter_list|)
function_decl|;
name|Surface
modifier|*
name|GetGlobalDrawSurface
parameter_list|()
function_decl|;
name|void
name|SetGlobalReadSurface
parameter_list|(
name|Surface
modifier|*
name|surface
parameter_list|)
function_decl|;
name|Surface
modifier|*
name|GetGlobalReadSurface
parameter_list|()
function_decl|;
name|void
name|SetGlobalContext
argument_list|(
name|gl
operator|::
name|Context
operator|*
name|context
argument_list|)
decl_stmt|;
name|gl
operator|::
name|Context
operator|*
name|GetGlobalContext
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_GLOBALSTATE_H_
end_comment
end_unit