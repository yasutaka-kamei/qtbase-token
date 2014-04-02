begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QCryptographicHash>
end_include
begin_include
include|#
directive|include
file|<QDateTime>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QElapsedTimer>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<QStandardPaths>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<d3dcommon.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|D3DCOMPILER_LINKED
end_ifdef
begin_namespace
DECL|namespace|D3D
namespace|namespace
name|D3D
block|{
include|#
directive|include
file|<d3dcompiler.h>
block|}
end_namespace
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// D3DCOMPILER_LINKED
end_comment
begin_macro
name|Q_LOGGING_CATEGORY
argument_list|(
argument|QT_D3DCOMPILER
argument_list|,
literal|"qt.angle.d3dcompiler"
argument_list|)
end_macro
begin_namespace
DECL|namespace|D3DCompiler
namespace|namespace
name|D3DCompiler
block|{
DECL|typedef|D3DCompileFunc
typedef|typedef
name|HRESULT
function_decl|(
name|WINAPI
modifier|*
name|D3DCompileFunc
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
DECL|member|compile
specifier|static
name|D3DCompileFunc
name|compile
decl_stmt|;
DECL|class|Blob
class|class
name|Blob
super|:
specifier|public
name|ID3DBlob
block|{
public|public:
DECL|function|Blob
name|Blob
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
member_init_list|:
name|m_data
argument_list|(
name|data
argument_list|)
block|{
name|IIDFromString
argument_list|(
literal|L"00000000-0000-0000-C000-000000000046"
argument_list|,
operator|&
name|IID_IUnknown
argument_list|)
expr_stmt|;
name|IIDFromString
argument_list|(
literal|L"8BA5FB08-5195-40e2-AC58-0D989C3A0102"
argument_list|,
operator|&
name|IID_ID3DBlob
argument_list|)
expr_stmt|;
block|}
DECL|function|~Blob
specifier|virtual
name|~
name|Blob
parameter_list|()
block|{     }
comment|// ID3DBlob
DECL|function|GetBufferPointer
name|LPVOID
name|__stdcall
name|GetBufferPointer
parameter_list|()
block|{
return|return
name|m_data
operator|.
name|data
argument_list|()
return|;
block|}
DECL|function|GetBufferSize
name|SIZE_T
name|__stdcall
name|GetBufferSize
parameter_list|()
block|{
return|return
name|m_data
operator|.
name|size
argument_list|()
return|;
block|}
comment|// IUnknown
DECL|function|QueryInterface
name|HRESULT
name|__stdcall
name|QueryInterface
parameter_list|(
name|REFIID
name|riid
parameter_list|,
name|void
modifier|*
modifier|*
name|ppv
parameter_list|)
block|{
name|IUnknown
modifier|*
name|out
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|riid
operator|==
name|IID_IUnknown
condition|)
name|out
operator|=
cast|static_cast
argument_list|<
name|IUnknown
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|riid
operator|==
name|IID_ID3DBlob
condition|)
name|out
operator|=
name|this
expr_stmt|;
operator|*
name|ppv
operator|=
name|out
expr_stmt|;
if|if
condition|(
operator|!
name|out
condition|)
return|return
name|E_NOINTERFACE
return|;
name|out
operator|->
name|AddRef
argument_list|()
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|function|AddRef
name|ULONG
name|__stdcall
name|AddRef
parameter_list|()
block|{
return|return
operator|++
name|m_ref
return|;
block|}
DECL|function|Release
name|ULONG
name|__stdcall
name|Release
parameter_list|()
block|{
name|ULONG
name|ref
init|=
operator|--
name|m_ref
decl_stmt|;
if|if
condition|(
operator|!
name|m_ref
condition|)
operator|delete
name|this
expr_stmt|;
return|return
name|ref
return|;
block|}
private|private:
DECL|member|m_data
name|QByteArray
name|m_data
decl_stmt|;
DECL|member|m_ref
name|ULONG
name|m_ref
decl_stmt|;
comment|// These symbols might be missing, so define them here
DECL|member|IID_IUnknown
name|IID
name|IID_IUnknown
decl_stmt|;
DECL|member|IID_ID3DBlob
name|IID
name|IID_ID3DBlob
decl_stmt|;
block|}
class|;
DECL|function|loadCompiler
specifier|static
name|bool
name|loadCompiler
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|D3DCOMPILER_LINKED
specifier|static
name|HMODULE
name|d3dcompiler
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|d3dcompiler
condition|)
block|{
specifier|const
name|wchar_t
modifier|*
name|dllNames
index|[]
init|=
block|{
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
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
specifier|const
name|wchar_t
operator|*
name|name
operator|=
name|dllNames
index|[
name|i
index|]
condition|;
operator|++
name|i
control|)
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINRT
name|d3dcompiler
operator|=
name|LoadLibrary
argument_list|(
name|name
argument_list|)
expr_stmt|;
else|#
directive|else
name|d3dcompiler
operator|=
name|LoadPackagedLibrary
argument_list|(
name|name
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|d3dcompiler
condition|)
block|{
name|qCDebug
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Found"
operator|<<
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|D3DCompiler
operator|::
name|compile
operator|=
cast|reinterpret_cast
argument_list|<
name|D3DCompiler
operator|::
name|D3DCompileFunc
argument_list|>
argument_list|(
name|GetProcAddress
argument_list|(
name|d3dcompiler
argument_list|,
literal|"D3DCompile"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|D3DCompiler
operator|::
name|compile
condition|)
block|{
name|qCDebug
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Loaded"
operator|<<
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|name
argument_list|)
expr_stmt|;
break|break;
block|}
name|qCDebug
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Failed to load"
operator|<<
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|d3dcompiler
condition|)
name|qCDebug
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Unable to load D3D shader compiler."
expr_stmt|;
block|}
else|#
directive|else
comment|// !D3DCOMPILER_LINKED
name|compile
operator|=
operator|&
name|D3D
operator|::
name|D3DCompile
expr_stmt|;
endif|#
directive|endif
comment|// D3DCOMPILER_LINKED
return|return
name|bool
argument_list|(
name|compile
argument_list|)
return|;
block|}
DECL|function|cacheKeyFor
specifier|static
name|QString
name|cacheKeyFor
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|)
block|{
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|QCryptographicHash
operator|::
name|hash
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|QCryptographicHash
operator|::
name|Sha1
argument_list|)
operator|.
name|toHex
argument_list|()
argument_list|)
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace D3DCompiler
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__MINGW32__
end_ifdef
begin_extern
extern|extern
literal|"C"
endif|#
directive|endif
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
name|HRESULT
name|WINAPI
name|D3DCompile
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|SIZE_T
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|D3D_SHADER_MACRO
modifier|*
parameter_list|,
name|ID3DInclude
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|UINT
parameter_list|,
name|UINT
parameter_list|,
name|ID3DBlob
modifier|*
modifier|*
parameter_list|,
name|ID3DBlob
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_extern
begin_function
DECL|function|D3DCompile
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
name|errorMsgs
parameter_list|)
block|{
comment|// Shortcut to compile using the runtime compiler if it is available
specifier|static
name|bool
name|compilerAvailable
init|=
operator|!
name|qgetenv
argument_list|(
literal|"QT_D3DCOMPILER_DISABLE_DLL"
argument_list|)
operator|.
name|toInt
argument_list|()
operator|&&
name|D3DCompiler
operator|::
name|loadCompiler
argument_list|()
decl_stmt|;
if|if
condition|(
name|compilerAvailable
condition|)
block|{
name|HRESULT
name|hr
init|=
name|D3DCompiler
operator|::
name|compile
argument_list|(
name|data
argument_list|,
name|data_size
argument_list|,
name|filename
argument_list|,
name|defines
argument_list|,
name|include
argument_list|,
name|entrypoint
argument_list|,
name|target
argument_list|,
name|sflags
argument_list|,
name|eflags
argument_list|,
name|shader
argument_list|,
name|errorMsgs
argument_list|)
decl_stmt|;
return|return
name|hr
return|;
block|}
specifier|static
name|bool
name|initialized
init|=
literal|false
decl_stmt|;
specifier|static
name|QStringList
name|binaryPaths
decl_stmt|;
specifier|static
name|QString
name|sourcePath
decl_stmt|;
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
comment|// Precompiled directory
name|QString
name|precompiledPath
decl_stmt|;
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
literal|"QT_D3DCOMPILER_BINARY_DIR"
argument_list|)
condition|)
name|precompiledPath
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"QT_D3DCOMPILER_BINARY_DIR"
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|precompiledPath
operator|=
name|QStringLiteral
argument_list|(
literal|":/qt.d3dcompiler"
argument_list|)
expr_stmt|;
comment|// Default QRC path
if|if
condition|(
name|QDir
argument_list|(
name|precompiledPath
argument_list|)
operator|.
name|exists
argument_list|()
condition|)
name|binaryPaths
operator|.
name|append
argument_list|(
name|precompiledPath
argument_list|)
expr_stmt|;
comment|// Service directory
name|QString
name|base
decl_stmt|;
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
literal|"QT_D3DCOMPILER_DIR"
argument_list|)
condition|)
name|base
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
literal|"QT_D3DCOMPILER_DIR"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|base
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|location
init|=
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|DataLocation
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|location
operator|.
name|isEmpty
argument_list|()
condition|)
name|base
operator|=
name|location
operator|+
name|QStringLiteral
argument_list|(
literal|"/d3dcompiler"
argument_list|)
expr_stmt|;
block|}
comment|// Create the directory structure
name|QDir
name|baseDir
argument_list|(
name|base
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|baseDir
operator|.
name|exists
argument_list|()
condition|)
block|{
name|baseDir
operator|.
name|cdUp
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|baseDir
operator|.
name|mkdir
argument_list|(
name|QStringLiteral
argument_list|(
literal|"d3dcompiler"
argument_list|)
argument_list|)
condition|)
block|{
name|qCWarning
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Unable to create shader base directory:"
operator|<<
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|baseDir
operator|.
name|absolutePath
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|binaryPaths
operator|.
name|isEmpty
argument_list|()
condition|)
comment|// No possibility to get a shader, abort
return|return
name|E_FAIL
return|;
block|}
name|baseDir
operator|.
name|cd
argument_list|(
name|QStringLiteral
argument_list|(
literal|"d3dcompiler"
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|baseDir
operator|.
name|exists
argument_list|(
name|QStringLiteral
argument_list|(
literal|"binary"
argument_list|)
argument_list|)
operator|&&
operator|!
name|baseDir
operator|.
name|mkdir
argument_list|(
name|QStringLiteral
argument_list|(
literal|"binary"
argument_list|)
argument_list|)
condition|)
block|{
name|qCWarning
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Unable to create shader binary directory:"
operator|<<
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|baseDir
operator|.
name|absoluteFilePath
argument_list|(
name|QStringLiteral
argument_list|(
literal|"binary"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|binaryPaths
operator|.
name|isEmpty
argument_list|()
condition|)
comment|// No possibility to get a shader, abort
return|return
name|E_FAIL
return|;
block|}
else|else
block|{
name|binaryPaths
operator|.
name|append
argument_list|(
name|baseDir
operator|.
name|absoluteFilePath
argument_list|(
name|QStringLiteral
argument_list|(
literal|"binary/"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|baseDir
operator|.
name|exists
argument_list|(
name|QStringLiteral
argument_list|(
literal|"source"
argument_list|)
argument_list|)
operator|&&
operator|!
name|baseDir
operator|.
name|mkdir
argument_list|(
name|QStringLiteral
argument_list|(
literal|"source"
argument_list|)
argument_list|)
condition|)
block|{
name|qCWarning
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Unable to create shader source directory:"
operator|<<
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|baseDir
operator|.
name|absoluteFilePath
argument_list|(
name|QStringLiteral
argument_list|(
literal|"source"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sourcePath
operator|=
name|baseDir
operator|.
name|absoluteFilePath
argument_list|(
name|QStringLiteral
argument_list|(
literal|"source/"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|initialized
operator|=
literal|true
expr_stmt|;
block|}
name|QByteArray
name|macros
decl_stmt|;
if|if
condition|(
specifier|const
name|D3D_SHADER_MACRO
modifier|*
name|macro
init|=
name|defines
condition|)
block|{
while|while
condition|(
name|macro
condition|)
block|{
name|macros
operator|.
name|append
argument_list|(
literal|'#'
argument_list|)
operator|.
name|append
argument_list|(
name|macro
operator|->
name|Name
argument_list|)
operator|.
name|append
argument_list|(
literal|' '
argument_list|)
operator|.
name|append
argument_list|(
name|macro
operator|->
name|Definition
argument_list|)
operator|.
name|append
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
operator|++
name|macro
expr_stmt|;
block|}
block|}
specifier|const
name|QByteArray
name|sourceData
init|=
name|macros
operator|+
name|QByteArray
operator|::
name|fromRawData
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
argument_list|,
name|data_size
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|fileName
init|=
name|D3DCompiler
operator|::
name|cacheKeyFor
argument_list|(
name|sourceData
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'!'
argument_list|)
operator|+
name|QString
operator|::
name|fromUtf8
argument_list|(
name|entrypoint
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'!'
argument_list|)
operator|+
name|QString
operator|::
name|fromUtf8
argument_list|(
name|target
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|'!'
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|sflags
argument_list|)
decl_stmt|;
comment|// Check if pre-compiled shader blob is available
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|path
decl|,
name|binaryPaths
control|)
block|{
name|QString
name|blobName
init|=
name|path
operator|+
name|fileName
decl_stmt|;
name|QFile
name|blob
argument_list|(
name|blobName
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|blob
operator|.
name|exists
argument_list|()
condition|)
block|{
comment|// Progressively drop optional parts
name|blobName
operator|.
name|truncate
argument_list|(
name|blobName
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'!'
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|blobName
operator|.
name|isEmpty
argument_list|()
condition|)
break|break;
name|blob
operator|.
name|setFileName
argument_list|(
name|blobName
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|blob
operator|.
name|exists
argument_list|()
condition|)
block|{
if|if
condition|(
name|blob
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qCDebug
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Opening precompiled shader blob at"
operator|<<
name|blob
operator|.
name|fileName
argument_list|()
expr_stmt|;
operator|*
name|shader
operator|=
operator|new
name|D3DCompiler
operator|::
name|Blob
argument_list|(
name|blob
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|S_FALSE
return|;
block|}
name|qCDebug
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Found, but unable to open, precompiled shader blob at"
operator|<<
name|blob
operator|.
name|fileName
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
comment|// Shader blob is not available; write out shader source
if|if
condition|(
operator|!
name|sourcePath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// Dump source to source path; wait for blob to appear
name|QFile
name|source
argument_list|(
name|sourcePath
operator|+
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|source
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|qCDebug
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Unable to write shader source to file:"
operator|<<
name|source
operator|.
name|fileName
argument_list|()
operator|<<
name|source
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return
name|E_ACCESSDENIED
return|;
block|}
name|source
operator|.
name|write
argument_list|(
name|sourceData
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Wrote shader source, waiting for blob:"
operator|<<
name|source
operator|.
name|fileName
argument_list|()
expr_stmt|;
name|source
operator|.
name|close
argument_list|()
expr_stmt|;
name|qint64
name|timeout
init|=
name|qgetenv
argument_list|(
literal|"QT_D3DCOMPILER_TIMEOUT"
argument_list|)
operator|.
name|toLong
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|timeout
condition|)
name|timeout
operator|=
literal|3000
expr_stmt|;
name|QElapsedTimer
name|timer
decl_stmt|;
name|timer
operator|.
name|start
argument_list|()
expr_stmt|;
name|QFile
name|blob
argument_list|(
name|binaryPaths
operator|.
name|last
argument_list|()
operator|+
name|fileName
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
operator|(
name|blob
operator|.
name|exists
argument_list|()
operator|&&
name|blob
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
operator|)
operator|&&
name|timer
operator|.
name|elapsed
argument_list|()
operator|<
name|timeout
condition|)
name|QThread
operator|::
name|msleep
argument_list|(
literal|100
argument_list|)
expr_stmt|;
if|if
condition|(
name|blob
operator|.
name|isOpen
argument_list|()
condition|)
block|{
operator|*
name|shader
operator|=
operator|new
name|D3DCompiler
operator|::
name|Blob
argument_list|(
name|blob
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|S_FALSE
return|;
block|}
name|qCDebug
argument_list|(
name|QT_D3DCOMPILER
argument_list|)
operator|<<
literal|"Shader blob failed to materialize after"
operator|<<
name|timeout
operator|<<
literal|"ms."
expr_stmt|;
operator|*
name|errorMsgs
operator|=
operator|new
name|D3DCompiler
operator|::
name|Blob
argument_list|(
literal|"Shader compilation timeout."
argument_list|)
expr_stmt|;
return|return
name|E_ABORT
return|;
block|}
operator|*
name|errorMsgs
operator|=
operator|new
name|D3DCompiler
operator|::
name|Blob
argument_list|(
literal|"No shader compiler or service could be found."
argument_list|)
expr_stmt|;
return|return
name|E_FAIL
return|;
block|}
end_function
end_unit
