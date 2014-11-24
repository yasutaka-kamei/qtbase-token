begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
comment|// main.cpp: DLL entry point and management of thread-local data.
end_comment
begin_include
include|#
directive|include
file|"libEGL/main.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"common/tls.h"
end_include
begin_decl_stmt
DECL|variable|currentTLS
specifier|static
name|TLSIndex
name|currentTLS
init|=
name|TLS_OUT_OF_INDEXES
decl_stmt|;
end_decl_stmt
begin_namespace
DECL|namespace|egl
namespace|namespace
name|egl
block|{
DECL|function|AllocateCurrent
name|Current
modifier|*
name|AllocateCurrent
parameter_list|()
block|{
name|ASSERT
argument_list|(
name|currentTLS
operator|!=
name|TLS_OUT_OF_INDEXES
argument_list|)
expr_stmt|;
if|if
condition|(
name|currentTLS
operator|==
name|TLS_OUT_OF_INDEXES
condition|)
block|{
return|return
name|NULL
return|;
block|}
name|Current
modifier|*
name|current
init|=
operator|new
name|Current
argument_list|()
decl_stmt|;
name|current
operator|->
name|error
operator|=
name|EGL_SUCCESS
expr_stmt|;
name|current
operator|->
name|API
operator|=
name|EGL_OPENGL_ES_API
expr_stmt|;
name|current
operator|->
name|display
operator|=
name|EGL_NO_DISPLAY
expr_stmt|;
name|current
operator|->
name|drawSurface
operator|=
name|EGL_NO_SURFACE
expr_stmt|;
name|current
operator|->
name|readSurface
operator|=
name|EGL_NO_SURFACE
expr_stmt|;
if|if
condition|(
operator|!
name|SetTLSValue
argument_list|(
name|currentTLS
argument_list|,
name|current
argument_list|)
condition|)
block|{
name|ERR
argument_list|(
literal|"Could not set thread local storage."
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|current
return|;
block|}
DECL|function|DeallocateCurrent
name|void
name|DeallocateCurrent
parameter_list|()
block|{
name|Current
modifier|*
name|current
init|=
cast|reinterpret_cast
argument_list|<
name|Current
operator|*
argument_list|>
argument_list|(
name|GetTLSValue
argument_list|(
name|currentTLS
argument_list|)
argument_list|)
decl_stmt|;
name|SafeDelete
argument_list|(
name|current
argument_list|)
expr_stmt|;
name|SetTLSValue
argument_list|(
name|currentTLS
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
block|}
end_namespace
begin_ifndef
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2_ANGLE_STATIC
end_ifndef
begin_extern
DECL|function|DllMain
extern|extern
literal|"C"
name|BOOL
name|WINAPI
name|DllMain
parameter_list|(
name|HINSTANCE
name|instance
parameter_list|,
name|DWORD
name|reason
parameter_list|,
name|LPVOID
name|reserved
parameter_list|)
block|{
switch|switch
condition|(
name|reason
condition|)
block|{
case|case
name|DLL_PROCESS_ATTACH
case|:
block|{
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_ENABLE_DEBUG_TRACE
argument_list|)
name|FILE
modifier|*
name|debug
init|=
name|fopen
argument_list|(
name|TRACE_OUTPUT_FILE
argument_list|,
literal|"rt"
argument_list|)
decl_stmt|;
if|if
condition|(
name|debug
condition|)
block|{
name|fclose
argument_list|(
name|debug
argument_list|)
expr_stmt|;
name|debug
operator|=
name|fopen
argument_list|(
name|TRACE_OUTPUT_FILE
argument_list|,
literal|"wt"
argument_list|)
expr_stmt|;
comment|// Erase
if|if
condition|(
name|debug
condition|)
block|{
name|fclose
argument_list|(
name|debug
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
name|currentTLS
operator|=
name|CreateTLSIndex
argument_list|()
expr_stmt|;
if|if
condition|(
name|currentTLS
operator|==
name|TLS_OUT_OF_INDEXES
condition|)
block|{
return|return
name|FALSE
return|;
block|}
ifdef|#
directive|ifdef
name|ANGLE_ENABLE_DEBUG_ANNOTATIONS
name|gl
operator|::
name|InitializeDebugAnnotations
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
comment|// Fall through to initialize index
case|case
name|DLL_THREAD_ATTACH
case|:
block|{
name|egl
operator|::
name|AllocateCurrent
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|DLL_THREAD_DETACH
case|:
block|{
name|egl
operator|::
name|DeallocateCurrent
argument_list|()
expr_stmt|;
block|}
break|break;
case|case
name|DLL_PROCESS_DETACH
case|:
block|{
name|egl
operator|::
name|DeallocateCurrent
argument_list|()
expr_stmt|;
name|DestroyTLSIndex
argument_list|(
name|currentTLS
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ANGLE_ENABLE_DEBUG_ANNOTATIONS
name|gl
operator|::
name|UninitializeDebugAnnotations
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
break|break;
default|default:
break|break;
block|}
return|return
name|TRUE
return|;
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_OPENGL_ES_2_ANGLE_STATIC
end_comment
begin_namespace
DECL|namespace|egl
namespace|namespace
name|egl
block|{
DECL|function|GetCurrentData
name|Current
modifier|*
name|GetCurrentData
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_OPENGL_ES_2_ANGLE_STATIC
name|Current
modifier|*
name|current
init|=
cast|reinterpret_cast
argument_list|<
name|Current
operator|*
argument_list|>
argument_list|(
name|GetTLSValue
argument_list|(
name|currentTLS
argument_list|)
argument_list|)
decl_stmt|;
comment|// ANGLE issue 488: when the dll is loaded after thread initialization,
comment|// thread local storage (current) might not exist yet.
return|return
operator|(
name|current
condition|?
name|current
else|:
name|AllocateCurrent
argument_list|()
operator|)
return|;
else|#
directive|else
comment|// No precautions for thread safety taken as ANGLE is used single-threaded in Qt.
specifier|static
name|Current
name|current
init|=
block|{
name|EGL_SUCCESS
block|,
name|EGL_OPENGL_ES_API
block|,
name|EGL_NO_DISPLAY
block|,
name|EGL_NO_SURFACE
block|,
name|EGL_NO_SURFACE
block|}
decl_stmt|;
return|return
operator|&
name|current
return|;
endif|#
directive|endif
block|}
DECL|function|recordError
name|void
name|recordError
parameter_list|(
specifier|const
name|Error
modifier|&
name|error
parameter_list|)
block|{
name|Current
modifier|*
name|current
init|=
name|GetCurrentData
argument_list|()
decl_stmt|;
name|current
operator|->
name|error
operator|=
name|error
operator|.
name|getCode
argument_list|()
expr_stmt|;
block|}
DECL|function|getCurrentError
name|EGLint
name|getCurrentError
parameter_list|()
block|{
name|Current
modifier|*
name|current
init|=
name|GetCurrentData
argument_list|()
decl_stmt|;
return|return
name|current
operator|->
name|error
return|;
block|}
DECL|function|setCurrentAPI
name|void
name|setCurrentAPI
parameter_list|(
name|EGLenum
name|API
parameter_list|)
block|{
name|Current
modifier|*
name|current
init|=
name|GetCurrentData
argument_list|()
decl_stmt|;
name|current
operator|->
name|API
operator|=
name|API
expr_stmt|;
block|}
DECL|function|getCurrentAPI
name|EGLenum
name|getCurrentAPI
parameter_list|()
block|{
name|Current
modifier|*
name|current
init|=
name|GetCurrentData
argument_list|()
decl_stmt|;
return|return
name|current
operator|->
name|API
return|;
block|}
DECL|function|setCurrentDisplay
name|void
name|setCurrentDisplay
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|)
block|{
name|Current
modifier|*
name|current
init|=
name|GetCurrentData
argument_list|()
decl_stmt|;
name|current
operator|->
name|display
operator|=
name|dpy
expr_stmt|;
block|}
DECL|function|getCurrentDisplay
name|EGLDisplay
name|getCurrentDisplay
parameter_list|()
block|{
name|Current
modifier|*
name|current
init|=
name|GetCurrentData
argument_list|()
decl_stmt|;
return|return
name|current
operator|->
name|display
return|;
block|}
DECL|function|setCurrentDrawSurface
name|void
name|setCurrentDrawSurface
parameter_list|(
name|EGLSurface
name|surface
parameter_list|)
block|{
name|Current
modifier|*
name|current
init|=
name|GetCurrentData
argument_list|()
decl_stmt|;
name|current
operator|->
name|drawSurface
operator|=
name|surface
expr_stmt|;
block|}
DECL|function|getCurrentDrawSurface
name|EGLSurface
name|getCurrentDrawSurface
parameter_list|()
block|{
name|Current
modifier|*
name|current
init|=
name|GetCurrentData
argument_list|()
decl_stmt|;
return|return
name|current
operator|->
name|drawSurface
return|;
block|}
DECL|function|setCurrentReadSurface
name|void
name|setCurrentReadSurface
parameter_list|(
name|EGLSurface
name|surface
parameter_list|)
block|{
name|Current
modifier|*
name|current
init|=
name|GetCurrentData
argument_list|()
decl_stmt|;
name|current
operator|->
name|readSurface
operator|=
name|surface
expr_stmt|;
block|}
DECL|function|getCurrentReadSurface
name|EGLSurface
name|getCurrentReadSurface
parameter_list|()
block|{
name|Current
modifier|*
name|current
init|=
name|GetCurrentData
argument_list|()
decl_stmt|;
return|return
name|current
operator|->
name|readSurface
return|;
block|}
block|}
end_namespace
end_unit
