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
comment|// Copyright (c) 2012-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// Renderer.cpp: Implements EGL dependencies for creating and destroying Renderer instances.
end_comment
begin_include
include|#
directive|include
file|<EGL/eglext.h>
end_include
begin_include
include|#
directive|include
file|"libGLESv2/main.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/Program.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|ANGLE_ENABLE_D3D11
end_ifndef
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer9.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"libGLESv2/renderer/Renderer11.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"libGLESv2/utilities.h"
end_include
begin_include
include|#
directive|include
file|"third_party/trace_event/trace_event.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_ENABLE_D3D11
argument_list|)
end_if
begin_comment
comment|// Enables use of the Direct3D 11 API for a default display, when available
end_comment
begin_define
DECL|macro|ANGLE_ENABLE_D3D11
define|#
directive|define
name|ANGLE_ENABLE_D3D11
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|D3DERR_OUTOFVIDEOMEMORY
end_ifndef
begin_define
DECL|macro|D3DERR_OUTOFVIDEOMEMORY
define|#
directive|define
name|D3DERR_OUTOFVIDEOMEMORY
value|MAKE_HRESULT(1, 0x876, 380)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|D3DCOMPILER_DLL
end_ifndef
begin_define
DECL|macro|D3DCOMPILER_DLL
define|#
directive|define
name|D3DCOMPILER_DLL
value|L"d3dcompiler_43.dll"
end_define
begin_comment
DECL|macro|D3DCOMPILER_DLL
comment|// Lowest common denominator
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_D3DCOMPILER_DLL
end_ifndef
begin_define
DECL|macro|QT_D3DCOMPILER_DLL
define|#
directive|define
name|QT_D3DCOMPILER_DLL
value|D3DCOMPILER_DLL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|||
name|defined
argument_list|(
name|ANGLE_OS_WINPHONE
argument_list|)
end_if
begin_comment
comment|//Add define + typedefs for older MinGW-w64 headers (pre 5783)
end_comment
begin_comment
comment|//Also define these on Windows Phone, which doesn't have a shader compiler
end_comment
begin_function_decl
name|HRESULT
name|WINAPI
name|D3DCompile
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|SIZE_T
name|data_size
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|D3D_SHADER_MACRO
modifier|*
name|defines
parameter_list|,
name|ID3DInclude
modifier|*
name|include
parameter_list|,
specifier|const
name|char
modifier|*
name|entrypoint
parameter_list|,
specifier|const
name|char
modifier|*
name|target
parameter_list|,
name|UINT
name|sflags
parameter_list|,
name|UINT
name|eflags
parameter_list|,
name|ID3DBlob
modifier|*
modifier|*
name|shader
parameter_list|,
name|ID3DBlob
modifier|*
modifier|*
name|error_messages
parameter_list|)
function_decl|;
end_function_decl
begin_typedef
DECL|typedef|pD3DCompile
typedef|typedef
name|HRESULT
function_decl|(
name|WINAPI
modifier|*
name|pD3DCompile
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|SIZE_T
name|data_size
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|D3D_SHADER_MACRO
modifier|*
name|defines
parameter_list|,
name|ID3DInclude
modifier|*
name|include
parameter_list|,
specifier|const
name|char
modifier|*
name|entrypoint
parameter_list|,
specifier|const
name|char
modifier|*
name|target
parameter_list|,
name|UINT
name|sflags
parameter_list|,
name|UINT
name|eflags
parameter_list|,
name|ID3DBlob
modifier|*
modifier|*
name|shader
parameter_list|,
name|ID3DBlob
modifier|*
modifier|*
name|error_messages
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// __MINGW32__ || ANGLE_OS_WINPHONE
end_comment
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|Renderer
name|Renderer
operator|::
name|Renderer
parameter_list|(
name|egl
operator|::
name|Display
modifier|*
name|display
parameter_list|)
member_init_list|:
name|mDisplay
argument_list|(
name|display
argument_list|)
block|{
name|mD3dCompilerModule
operator|=
name|NULL
expr_stmt|;
name|mD3DCompileFunc
operator|=
name|NULL
expr_stmt|;
block|}
DECL|function|~Renderer
name|Renderer
operator|::
name|~
name|Renderer
parameter_list|()
block|{
if|if
condition|(
name|mD3dCompilerModule
condition|)
block|{
name|FreeLibrary
argument_list|(
name|mD3dCompilerModule
argument_list|)
expr_stmt|;
name|mD3dCompilerModule
operator|=
name|NULL
expr_stmt|;
block|}
block|}
DECL|function|initializeCompiler
name|bool
name|Renderer
operator|::
name|initializeCompiler
parameter_list|()
block|{
name|TRACE_EVENT0
argument_list|(
literal|"gpu"
argument_list|,
literal|"initializeCompiler"
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_PRELOADED_D3DCOMPILER_MODULE_NAMES
argument_list|)
comment|// Find a D3DCompiler module that had already been loaded based on a predefined list of versions.
specifier|static
name|TCHAR
modifier|*
name|d3dCompilerNames
index|[]
init|=
name|ANGLE_PRELOADED_D3DCOMPILER_MODULE_NAMES
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ArraySize
argument_list|(
name|d3dCompilerNames
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|GetModuleHandleEx
argument_list|(
literal|0
argument_list|,
name|d3dCompilerNames
index|[
name|i
index|]
argument_list|,
operator|&
name|mD3dCompilerModule
argument_list|)
condition|)
block|{
break|break;
block|}
block|}
else|#
directive|else
comment|// Load the compiler DLL specified by the environment, or default to QT_D3DCOMPILER_DLL
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_OS_WINRT
argument_list|)
specifier|const
name|wchar_t
modifier|*
name|defaultCompiler
init|=
name|_wgetenv
argument_list|(
literal|L"QT_D3DCOMPILER_DLL"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|defaultCompiler
condition|)
name|defaultCompiler
operator|=
name|QT_D3DCOMPILER_DLL
expr_stmt|;
else|#
directive|else
comment|// !ANGLE_OS_WINRT
ifdef|#
directive|ifdef
name|_DEBUG
specifier|const
name|wchar_t
modifier|*
name|defaultCompiler
init|=
literal|L"d3dcompiler_qtd.dll"
decl_stmt|;
else|#
directive|else
specifier|const
name|wchar_t
modifier|*
name|defaultCompiler
init|=
literal|L"d3dcompiler_qt.dll"
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|// ANGLE_OS_WINRT
specifier|const
name|wchar_t
modifier|*
name|compilerDlls
index|[]
init|=
block|{
name|defaultCompiler
block|,
literal|L"d3dcompiler_47.dll"
block|,
literal|L"d3dcompiler_46.dll"
block|,
literal|L"d3dcompiler_45.dll"
block|,
literal|L"d3dcompiler_44.dll"
block|,
literal|L"d3dcompiler_43.dll"
block|,
literal|0
block|}
decl_stmt|;
comment|// Load the first available known compiler DLL
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|compilerDlls
index|[
name|i
index|]
condition|;
operator|++
name|i
control|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_OS_WINRT
argument_list|)
name|mD3dCompilerModule
operator|=
name|LoadLibrary
argument_list|(
name|compilerDlls
index|[
name|i
index|]
argument_list|)
expr_stmt|;
else|#
directive|else
name|mD3dCompilerModule
operator|=
name|LoadPackagedLibrary
argument_list|(
name|compilerDlls
index|[
name|i
index|]
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|mD3dCompilerModule
condition|)
break|break;
block|}
endif|#
directive|endif
comment|// ANGLE_PRELOADED_D3DCOMPILER_MODULE_NAMES
if|if
condition|(
operator|!
name|mD3dCompilerModule
condition|)
block|{
name|ERR
argument_list|(
literal|"No D3D compiler module found - aborting!\n"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|mD3DCompileFunc
operator|=
cast|reinterpret_cast
argument_list|<
name|pCompileFunc
argument_list|>
argument_list|(
name|GetProcAddress
argument_list|(
name|mD3dCompilerModule
argument_list|,
literal|"D3DCompile"
argument_list|)
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|mD3DCompileFunc
argument_list|)
expr_stmt|;
return|return
name|mD3DCompileFunc
operator|!=
name|NULL
return|;
block|}
comment|// Compiles HLSL code into executable binaries
DECL|function|compileToBinary
name|ShaderBlob
modifier|*
name|Renderer
operator|::
name|compileToBinary
parameter_list|(
name|gl
operator|::
name|InfoLog
modifier|&
name|infoLog
parameter_list|,
specifier|const
name|char
modifier|*
name|hlsl
parameter_list|,
specifier|const
name|char
modifier|*
name|profile
parameter_list|,
name|UINT
name|optimizationFlags
parameter_list|,
name|bool
name|alternateFlags
parameter_list|)
block|{
if|if
condition|(
operator|!
name|hlsl
condition|)
block|{
return|return
name|NULL
return|;
block|}
name|HRESULT
name|result
init|=
name|S_OK
decl_stmt|;
name|UINT
name|flags
init|=
literal|0
decl_stmt|;
name|std
operator|::
name|string
name|sourceText
decl_stmt|;
if|if
condition|(
name|gl
operator|::
name|perfActive
argument_list|()
condition|)
block|{
name|flags
operator||=
name|D3DCOMPILE_DEBUG
expr_stmt|;
ifdef|#
directive|ifdef
name|NDEBUG
name|flags
operator||=
name|optimizationFlags
expr_stmt|;
else|#
directive|else
name|flags
operator||=
name|D3DCOMPILE_SKIP_OPTIMIZATION
expr_stmt|;
endif|#
directive|endif
name|std
operator|::
name|string
name|sourcePath
init|=
name|getTempPath
argument_list|()
decl_stmt|;
name|sourceText
operator|=
name|std
operator|::
name|string
argument_list|(
literal|"#line 2 \""
argument_list|)
operator|+
name|sourcePath
operator|+
name|std
operator|::
name|string
argument_list|(
literal|"\"\n\n"
argument_list|)
operator|+
name|std
operator|::
name|string
argument_list|(
name|hlsl
argument_list|)
expr_stmt|;
name|writeFile
argument_list|(
name|sourcePath
operator|.
name|c_str
argument_list|()
argument_list|,
name|sourceText
operator|.
name|c_str
argument_list|()
argument_list|,
name|sourceText
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|flags
operator||=
name|optimizationFlags
expr_stmt|;
name|sourceText
operator|=
name|hlsl
expr_stmt|;
block|}
comment|// Sometimes D3DCompile will fail with the default compilation flags for complicated shaders when it would otherwise pass with alternative options.
comment|// Try the default flags first and if compilation fails, try some alternatives.
specifier|const
specifier|static
name|UINT
name|extraFlags
index|[]
init|=
block|{
literal|0
block|,
name|D3DCOMPILE_AVOID_FLOW_CONTROL
block|,
name|D3DCOMPILE_PREFER_FLOW_CONTROL
block|}
decl_stmt|;
specifier|const
specifier|static
name|char
modifier|*
specifier|const
name|extraFlagNames
index|[]
init|=
block|{
literal|"default"
block|,
literal|"avoid flow control"
block|,
literal|"prefer flow control"
block|}
decl_stmt|;
name|int
name|attempts
init|=
name|alternateFlags
condition|?
name|ArraySize
argument_list|(
name|extraFlags
argument_list|)
else|:
literal|1
decl_stmt|;
name|pD3DCompile
name|compileFunc
init|=
cast|reinterpret_cast
argument_list|<
name|pD3DCompile
argument_list|>
argument_list|(
name|mD3DCompileFunc
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|attempts
condition|;
operator|++
name|i
control|)
block|{
name|ID3DBlob
modifier|*
name|errorMessage
init|=
name|NULL
decl_stmt|;
name|ID3DBlob
modifier|*
name|binary
init|=
name|NULL
decl_stmt|;
name|result
operator|=
name|compileFunc
argument_list|(
name|hlsl
argument_list|,
name|strlen
argument_list|(
name|hlsl
argument_list|)
argument_list|,
name|gl
operator|::
name|g_fakepath
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
literal|"main"
argument_list|,
name|profile
argument_list|,
name|flags
operator||
name|extraFlags
index|[
name|i
index|]
argument_list|,
literal|0
argument_list|,
operator|&
name|binary
argument_list|,
operator|&
name|errorMessage
argument_list|)
expr_stmt|;
if|if
condition|(
name|errorMessage
condition|)
block|{
specifier|const
name|char
modifier|*
name|message
init|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|errorMessage
operator|->
name|GetBufferPointer
argument_list|()
decl_stmt|;
name|infoLog
operator|.
name|appendSanitized
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|TRACE
argument_list|(
literal|"\n%s"
argument_list|,
name|hlsl
argument_list|)
expr_stmt|;
name|TRACE
argument_list|(
literal|"\n%s"
argument_list|,
name|message
argument_list|)
expr_stmt|;
name|errorMessage
operator|->
name|Release
argument_list|()
expr_stmt|;
name|errorMessage
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
operator|(
name|ShaderBlob
operator|*
operator|)
name|binary
return|;
block|}
else|else
block|{
if|if
condition|(
name|result
operator|==
name|D3DERR_OUTOFVIDEOMEMORY
operator|||
name|result
operator|==
name|E_OUTOFMEMORY
condition|)
block|{
return|return
name|gl
operator|::
name|error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
operator|(
name|ShaderBlob
operator|*
operator|)
name|NULL
argument_list|)
return|;
block|}
name|infoLog
operator|.
name|append
argument_list|(
literal|"Warning: D3D shader compilation failed with "
argument_list|)
expr_stmt|;
name|infoLog
operator|.
name|append
argument_list|(
name|extraFlagNames
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|infoLog
operator|.
name|append
argument_list|(
literal|" flags."
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|+
literal|1
operator|<
name|attempts
condition|)
block|{
name|infoLog
operator|.
name|append
argument_list|(
literal|" Retrying with "
argument_list|)
expr_stmt|;
name|infoLog
operator|.
name|append
argument_list|(
name|extraFlagNames
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
name|infoLog
operator|.
name|append
argument_list|(
literal|".\n"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
name|NULL
return|;
block|}
block|}
end_namespace
begin_extern
extern|extern
literal|"C"
block|{
DECL|function|glCreateRenderer
name|rx
operator|::
name|Renderer
modifier|*
name|glCreateRenderer
parameter_list|(
name|egl
operator|::
name|Display
modifier|*
name|display
parameter_list|,
name|HDC
name|hDc
parameter_list|,
name|EGLNativeDisplayType
name|displayId
parameter_list|)
block|{
name|rx
operator|::
name|Renderer
modifier|*
name|renderer
init|=
name|NULL
decl_stmt|;
name|EGLint
name|status
init|=
name|EGL_BAD_ALLOC
decl_stmt|;
if|#
directive|if
name|ANGLE_ENABLE_D3D11
name|renderer
operator|=
operator|new
name|rx
operator|::
name|Renderer11
argument_list|(
name|display
argument_list|,
name|hDc
argument_list|)
expr_stmt|;
else|#
directive|else
name|bool
name|softwareDevice
init|=
operator|(
name|displayId
operator|==
name|EGL_SOFTWARE_DISPLAY_ANGLE
operator|)
decl_stmt|;
name|renderer
operator|=
operator|new
name|rx
operator|::
name|Renderer9
argument_list|(
name|display
argument_list|,
name|hDc
argument_list|,
name|softwareDevice
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|renderer
condition|)
block|{
name|status
operator|=
name|renderer
operator|->
name|initialize
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|status
operator|==
name|EGL_SUCCESS
condition|)
block|{
return|return
name|renderer
return|;
block|}
return|return
name|NULL
return|;
block|}
DECL|function|glDestroyRenderer
name|void
name|glDestroyRenderer
parameter_list|(
name|rx
operator|::
name|Renderer
modifier|*
name|renderer
parameter_list|)
block|{
operator|delete
name|renderer
expr_stmt|;
block|}
block|}
end_extern
end_unit
