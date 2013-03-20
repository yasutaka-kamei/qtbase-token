begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLSHADERCACHE_MEEGO_P_H
end_ifndef
begin_define
DECL|macro|QOPENGLSHADERCACHE_MEEGO_P_H
define|#
directive|define
name|QOPENGLSHADERCACHE_MEEGO_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qopenglobal.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_MEEGO_EXPERIMENTAL_SHADERCACHE
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qcryptographichash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedmemory.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsystemsemaphore.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
end_ifndef
begin_include
include|#
directive|include
file|<GLES2/gl2ext.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_MEEGO_EXPERIMENTAL_SHADERCACHE_TRACE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<syslog.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*     This cache stores internal Qt shader programs in shared memory.      This header file is ugly on purpose and can only be included once. It is only to be used     for the internal shader cache, not as a generic cache for anyone's shaders.      The cache stores either ShaderCacheMaxEntries shader programs or ShaderCacheDataSize kilobytes     of shader programs, whatever limit is reached first.      The layout of the cache is as outlined in the CachedShaders struct. After some     integers, an array of headers is reserved, then comes the space for the actual binaries.      Shader Programs are identified by the md5sum of their frag and vertex shader source code.      Shader Programs are never removed. The cache never shrinks or re-shuffles. This is done     on purpose to ensure minimum amount of locking, no alignment problems and very few write     operations.      Note: Locking the shader cache could be expensive, because the entire system might hang.     That's why the cache is immutable to minimize the time we need to keep it locked.      Why is it Meego specific?      First, the size is chosen so that it fits to generic meego usage. Second, on Meego, there's     always at least one Qt application active (the launcher), so the cache will never be destroyed.     Only when the last Qt app exits, the cache dies, which should only be when someone kills the     X11 server. And last but not least it was only tested with Meego's SGX driver.      There's a small tool in src/opengl/util/meego that dumps the contents of the cache.  */
end_comment
begin_comment
comment|// anonymous namespace, prevent exporting of the private symbols
end_comment
begin_macro
name|namespace
end_macro
begin_block
block|{
struct|struct
name|CachedShaderHeader
block|{
comment|/* the index in the data[] member of CachedShaders */
name|int
name|index
decl_stmt|;
comment|/* the size of the binary shader */
name|GLsizei
name|size
decl_stmt|;
comment|/* the format of the binary shader */
name|GLenum
name|format
decl_stmt|;
comment|/* the md5sum of the frag+vertex shaders */
name|char
name|md5Sum
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
enum|enum
block|{
comment|/* The maximum amount of shader programs the cache can hold */
name|ShaderCacheMaxEntries
init|=
literal|20
block|}
enum|;
typedef|typedef
name|CachedShaderHeader
name|CachedShaderHeaders
index|[
name|ShaderCacheMaxEntries
index|]
typedef|;
enum|enum
block|{
comment|// ShaderCacheDataSize is 20k minus the other data members of CachedShaders
name|ShaderCacheDataSize
init|=
literal|1024
operator|*
name|ShaderCacheMaxEntries
operator|-
sizeof|sizeof
argument_list|(
name|CachedShaderHeaders
argument_list|)
operator|-
literal|2
operator|*
expr|sizeof
operator|(
name|int
operator|)
block|}
enum|;
struct|struct
name|CachedShaders
block|{
comment|/* How much space is still available in the cache */
specifier|inline
name|int
name|availableSize
argument_list|()
specifier|const
block|{
return|return
name|ShaderCacheDataSize
operator|-
name|dataSize
return|;
block|}
comment|/* The current amount of cached shaders */
name|int
name|shaderCount
decl_stmt|;
comment|/* The current amount (in bytes) of cached data */
name|int
name|dataSize
decl_stmt|;
comment|/* The headers describing the shaders */
name|CachedShaderHeaders
name|headers
decl_stmt|;
comment|/* The actual binary data of the shader programs */
name|char
name|data
index|[
name|ShaderCacheDataSize
index|]
decl_stmt|;
block|}
struct|;
comment|//#define QT_DEBUG_SHADER_CACHE
ifdef|#
directive|ifdef
name|QT_DEBUG_SHADER_CACHE
specifier|static
name|QDebug
name|shaderCacheDebug
parameter_list|()
block|{
return|return
name|QDebug
argument_list|(
name|QtDebugMsg
argument_list|)
return|;
block|}
else|#
directive|else
specifier|static
specifier|inline
name|QNoDebug
name|shaderCacheDebug
parameter_list|()
block|{
return|return
name|QNoDebug
argument_list|()
return|;
block|}
endif|#
directive|endif
name|class
name|ShaderCacheSharedMemory
block|{
name|public
label|:
name|ShaderCacheSharedMemory
argument_list|()
operator|:
name|shm
argument_list|(
argument|QLatin1String(
literal|"qt_gles2_shadercache_"
argument|QT_VERSION_STR)
argument_list|)
block|{
comment|// we need a system semaphore here, since cache creation and initialization must be atomic
name|QSystemSemaphore
name|attachSemaphore
argument_list|(
name|QLatin1String
argument_list|(
literal|"qt_gles2_shadercache_mutex_"
name|QT_VERSION_STR
argument_list|)
argument_list|,
literal|1
argument_list|)
block|;
if|if
condition|(
operator|!
name|attachSemaphore
operator|.
name|acquire
argument_list|()
condition|)
block|{
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"Unable to require shader cache semaphore:"
operator|<<
name|attachSemaphore
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|shm
operator|.
name|attach
argument_list|()
condition|)
block|{
comment|// success!
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"Attached to shader cache"
expr_stmt|;
block|}
else|else
block|{
comment|// no cache exists - create and initialize it
if|if
condition|(
name|shm
operator|.
name|create
argument_list|(
sizeof|sizeof
argument_list|(
name|CachedShaders
argument_list|)
argument_list|)
condition|)
block|{
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"Created new shader cache"
expr_stmt|;
name|initializeCache
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"Unable to create shader cache:"
operator|<<
name|shm
operator|.
name|errorString
argument_list|()
expr_stmt|;
block|}
block|}
name|attachSemaphore
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|bool
name|isAttached
argument_list|()
specifier|const
block|{
return|return
name|shm
operator|.
name|isAttached
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|lock
parameter_list|()
block|{
return|return
name|shm
operator|.
name|lock
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|unlock
parameter_list|()
block|{
return|return
name|shm
operator|.
name|unlock
argument_list|()
return|;
block|}
specifier|inline
name|void
modifier|*
name|data
parameter_list|()
block|{
return|return
name|shm
operator|.
name|data
argument_list|()
return|;
block|}
specifier|inline
name|QString
name|errorString
parameter_list|()
block|{
return|return
name|shm
operator|.
name|errorString
argument_list|()
return|;
block|}
operator|~
name|ShaderCacheSharedMemory
argument_list|()
block|{
if|if
condition|(
operator|!
name|shm
operator|.
name|detach
argument_list|()
condition|)
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"Unable to detach shader cache"
operator|<<
name|shm
operator|.
name|errorString
argument_list|()
expr_stmt|;
block|}
name|private
label|:
name|void
name|initializeCache
parameter_list|()
block|{
comment|// no need to lock the shared memory since we're already protected by the
comment|// attach system semaphore.
name|void
modifier|*
name|data
init|=
name|shm
operator|.
name|data
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|data
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|CachedShaders
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QSharedMemory
name|shm
decl_stmt|;
block|}
empty_stmt|;
name|class
name|ShaderCacheLocker
block|{
name|public
label|:
specifier|inline
name|ShaderCacheLocker
argument_list|(
name|ShaderCacheSharedMemory
operator|*
name|cache
argument_list|)
operator|:
name|shm
argument_list|(
argument|cache->lock() ? cache : (ShaderCacheSharedMemory *)
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|shm
condition|)
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"Unable to lock shader cache"
operator|<<
name|cache
operator|->
name|errorString
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|bool
name|isLocked
argument_list|()
specifier|const
block|{
return|return
name|shm
return|;
block|}
specifier|inline
operator|~
name|ShaderCacheLocker
argument_list|()
block|{
if|if
condition|(
operator|!
name|shm
condition|)
return|return;
if|if
condition|(
operator|!
name|shm
operator|->
name|unlock
argument_list|()
condition|)
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"Unable to unlock shader cache"
operator|<<
name|shm
operator|->
name|errorString
argument_list|()
expr_stmt|;
block|}
name|private
label|:
name|ShaderCacheSharedMemory
modifier|*
name|shm
decl_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_BOOTSTRAPPED
end_ifdef
begin_comment
unit|}
comment|// end namespace
end_comment
begin_else
else|#
directive|else
end_else
begin_function
unit|static
name|void
name|traceCacheOverflow
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QT_DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|QT_MEEGO_EXPERIMENTAL_SHADERCACHE_TRACE
argument_list|)
name|openlog
argument_list|(
name|qPrintable
argument_list|(
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
argument_list|)
argument_list|,
name|LOG_PID
operator||
name|LOG_ODELAY
argument_list|,
name|LOG_USER
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_DEBUG
argument_list|,
name|message
argument_list|)
expr_stmt|;
name|closelog
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|shaderCacheDebug
argument_list|()
operator|<<
name|message
expr_stmt|;
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|ShaderCacheSharedMemory
argument_list|,
argument|shaderCacheSharedMemory
argument_list|)
end_macro
begin_comment
comment|/*    Finds the index of the shader program identified by md5Sum in the cache.    Note: Does NOT lock the cache for reading, the cache must already be locked!     Returns -1 when no shader was found.  */
end_comment
begin_function
specifier|static
name|int
name|qt_cache_index_unlocked
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|md5Sum
parameter_list|,
name|CachedShaders
modifier|*
name|cache
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|cache
operator|->
name|shaderCount
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|qstrncmp
argument_list|(
name|md5Sum
operator|.
name|constData
argument_list|()
argument_list|,
name|cache
operator|->
name|headers
index|[
name|i
index|]
operator|.
name|md5Sum
argument_list|,
literal|16
argument_list|)
operator|==
literal|0
condition|)
block|{
return|return
name|i
return|;
block|}
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|/* Returns the index of the shader identified by md5Sum */
end_comment
begin_function
specifier|static
name|int
name|qt_cache_index
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|md5Sum
parameter_list|)
block|{
name|ShaderCacheSharedMemory
modifier|*
name|shm
init|=
name|shaderCacheSharedMemory
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|shm
operator|||
operator|!
name|shm
operator|->
name|isAttached
argument_list|()
condition|)
return|return
name|false
return|;
name|Q_ASSERT
argument_list|(
name|md5Sum
operator|.
name|length
argument_list|()
operator|==
literal|16
argument_list|)
expr_stmt|;
name|ShaderCacheLocker
name|locker
argument_list|(
name|shm
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|locker
operator|.
name|isLocked
argument_list|()
condition|)
return|return
name|false
return|;
name|void
modifier|*
name|data
init|=
name|shm
operator|->
name|data
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|CachedShaders
modifier|*
name|cache
init|=
name|reinterpret_cast
operator|<
name|CachedShaders
operator|*
operator|>
operator|(
name|data
operator|)
decl_stmt|;
return|return
name|qt_cache_index_unlocked
argument_list|(
name|md5Sum
argument_list|,
name|cache
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/* Loads the cached shader at index \a shaderIndex into \a program  * Note: Since the cache is immutable, this operation doesn't lock the shared memory.  */
end_comment
begin_function
specifier|static
name|bool
name|qt_cached_shader
parameter_list|(
name|QOpenGLShaderProgram
modifier|*
name|program
parameter_list|,
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|,
name|int
name|shaderIndex
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|shaderIndex
operator|>=
literal|0
operator|&&
name|shaderIndex
operator|<=
name|ShaderCacheMaxEntries
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|program
argument_list|)
expr_stmt|;
name|ShaderCacheSharedMemory
modifier|*
name|shm
init|=
name|shaderCacheSharedMemory
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|shm
operator|||
operator|!
name|shm
operator|->
name|isAttached
argument_list|()
condition|)
return|return
name|false
return|;
name|void
modifier|*
name|data
init|=
name|shm
operator|->
name|data
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|CachedShaders
modifier|*
name|cache
init|=
name|reinterpret_cast
operator|<
name|CachedShaders
operator|*
operator|>
operator|(
name|data
operator|)
decl_stmt|;
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"fetching cached shader at index"
operator|<<
name|shaderIndex
operator|<<
literal|"dataIndex"
operator|<<
name|cache
operator|->
name|headers
index|[
name|shaderIndex
index|]
operator|.
name|index
operator|<<
literal|"size"
operator|<<
name|cache
operator|->
name|headers
index|[
name|shaderIndex
index|]
operator|.
name|size
operator|<<
literal|"format"
operator|<<
name|cache
operator|->
name|headers
index|[
name|shaderIndex
index|]
operator|.
name|format
expr_stmt|;
comment|// call program->programId first, since that resolves the glProgramBinaryOES symbol
name|GLuint
name|programId
init|=
name|program
operator|->
name|programId
argument_list|()
decl_stmt|;
name|glProgramBinaryOES
argument_list|(
name|programId
argument_list|,
name|cache
operator|->
name|headers
index|[
name|shaderIndex
index|]
operator|.
name|format
argument_list|,
name|cache
operator|->
name|data
operator|+
name|cache
operator|->
name|headers
index|[
name|shaderIndex
index|]
operator|.
name|index
argument_list|,
name|cache
operator|->
name|headers
index|[
name|shaderIndex
index|]
operator|.
name|size
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function
begin_comment
comment|/* Stores the shader program in the cache. Returns false if there's an error with the cache, or    if the cache is too small to hold the shader. */
end_comment
begin_function
specifier|static
name|bool
name|qt_cache_shader
parameter_list|(
specifier|const
name|QOpenGLShaderProgram
modifier|*
name|shader
parameter_list|,
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|md5Sum
parameter_list|)
block|{
name|ShaderCacheSharedMemory
modifier|*
name|shm
init|=
name|shaderCacheSharedMemory
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|shm
operator|||
operator|!
name|shm
operator|->
name|isAttached
argument_list|()
condition|)
return|return
name|false
return|;
name|void
modifier|*
name|data
init|=
name|shm
operator|->
name|data
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|CachedShaders
modifier|*
name|cache
init|=
name|reinterpret_cast
operator|<
name|CachedShaders
operator|*
operator|>
operator|(
name|data
operator|)
decl_stmt|;
name|ShaderCacheLocker
name|locker
argument_list|(
name|shm
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|locker
operator|.
name|isLocked
argument_list|()
condition|)
return|return
name|false
return|;
name|int
name|cacheIdx
init|=
name|cache
operator|->
name|shaderCount
decl_stmt|;
if|if
condition|(
name|cacheIdx
operator|>=
name|ShaderCacheMaxEntries
condition|)
block|{
name|traceCacheOverflow
argument_list|(
literal|"Qt OpenGL shader cache index overflow!"
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
comment|// now that we have the lock on the shared memory, make sure no one
comment|// inserted the shader already while we were unlocked
if|if
condition|(
name|qt_cache_index_unlocked
argument_list|(
name|md5Sum
argument_list|,
name|cache
argument_list|)
operator|!=
operator|-
literal|1
condition|)
return|return
name|true
return|;
comment|// already cached
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"Caching shader at index"
operator|<<
name|cacheIdx
expr_stmt|;
name|GLint
name|binaryLength
init|=
literal|0
decl_stmt|;
name|glGetProgramiv
argument_list|(
name|shader
operator|->
name|programId
argument_list|()
argument_list|,
name|GL_PROGRAM_BINARY_LENGTH_OES
argument_list|,
operator|&
name|binaryLength
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|binaryLength
condition|)
block|{
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"Unable to determine binary shader size!"
expr_stmt|;
return|return
name|false
return|;
block|}
if|if
condition|(
name|binaryLength
operator|>
name|cache
operator|->
name|availableSize
argument_list|()
condition|)
block|{
name|traceCacheOverflow
argument_list|(
literal|"Qt OpenGL shader cache data overflow!"
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
name|GLsizei
name|size
init|=
literal|0
decl_stmt|;
name|GLenum
name|format
init|=
literal|0
decl_stmt|;
name|glGetProgramBinaryOES
argument_list|(
name|shader
operator|->
name|programId
argument_list|()
argument_list|,
name|binaryLength
argument_list|,
operator|&
name|size
argument_list|,
operator|&
name|format
argument_list|,
name|cache
operator|->
name|data
operator|+
name|cache
operator|->
name|dataSize
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|size
condition|)
block|{
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"Unable to get binary shader!"
expr_stmt|;
return|return
name|false
return|;
block|}
name|cache
operator|->
name|headers
index|[
name|cacheIdx
index|]
operator|.
name|index
operator|=
name|cache
operator|->
name|dataSize
expr_stmt|;
name|cache
operator|->
name|dataSize
operator|+=
name|binaryLength
expr_stmt|;
operator|++
name|cache
operator|->
name|shaderCount
expr_stmt|;
name|cache
operator|->
name|headers
index|[
name|cacheIdx
index|]
operator|.
name|size
operator|=
name|binaryLength
expr_stmt|;
name|cache
operator|->
name|headers
index|[
name|cacheIdx
index|]
operator|.
name|format
operator|=
name|format
expr_stmt|;
name|memcpy
argument_list|(
name|cache
operator|->
name|headers
index|[
name|cacheIdx
index|]
operator|.
name|md5Sum
argument_list|,
name|md5Sum
operator|.
name|constData
argument_list|()
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|shaderCacheDebug
argument_list|()
operator|<<
literal|"cached shader size"
operator|<<
name|size
operator|<<
literal|"format"
operator|<<
name|format
operator|<<
literal|"binarySize"
operator|<<
name|binaryLength
operator|<<
literal|"cache index"
operator|<<
name|cacheIdx
operator|<<
literal|"data index"
operator|<<
name|cache
operator|->
name|headers
index|[
name|cacheIdx
index|]
operator|.
name|index
expr_stmt|;
return|return
name|true
return|;
block|}
end_function
begin_comment
unit|}
comment|// namespace
end_comment
begin_decl_stmt
unit|QT_BEGIN_NAMESPACE
name|class
name|CachedShader
block|{
name|public
label|:
name|CachedShader
argument_list|(
specifier|const
name|QByteArray
operator|&
name|fragSource
argument_list|,
specifier|const
name|QByteArray
operator|&
name|vertexSource
argument_list|)
operator|:
name|cacheIdx
argument_list|(
argument|-
literal|1
argument_list|)
block|{
name|QCryptographicHash
name|md5Hash
argument_list|(
name|QCryptographicHash
operator|::
name|Md5
argument_list|)
block|;
name|md5Hash
operator|.
name|addData
argument_list|(
name|fragSource
argument_list|)
block|;
name|md5Hash
operator|.
name|addData
argument_list|(
name|vertexSource
argument_list|)
block|;
name|md5Sum
operator|=
name|md5Hash
operator|.
name|result
argument_list|()
block|;     }
name|bool
name|isCached
argument_list|()
block|{
return|return
name|cacheIndex
argument_list|()
operator|!=
operator|-
literal|1
return|;
block|}
name|int
name|cacheIndex
parameter_list|()
block|{
if|if
condition|(
name|cacheIdx
operator|!=
operator|-
literal|1
condition|)
return|return
name|cacheIdx
return|;
name|cacheIdx
operator|=
name|qt_cache_index
argument_list|(
name|md5Sum
argument_list|)
expr_stmt|;
return|return
name|cacheIdx
return|;
block|}
name|bool
name|load
parameter_list|(
name|QOpenGLShaderProgram
modifier|*
name|program
parameter_list|,
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|)
block|{
if|if
condition|(
name|cacheIndex
argument_list|()
operator|==
operator|-
literal|1
condition|)
return|return
name|false
return|;
return|return
name|qt_cached_shader
argument_list|(
name|program
argument_list|,
name|ctx
argument_list|,
name|cacheIdx
argument_list|)
return|;
block|}
name|bool
name|store
parameter_list|(
name|QOpenGLShaderProgram
modifier|*
name|program
parameter_list|,
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|)
block|{
return|return
name|qt_cache_shader
argument_list|(
name|program
argument_list|,
name|ctx
argument_list|,
name|md5Sum
argument_list|)
return|;
block|}
name|private
label|:
name|QByteArray
name|md5Sum
decl_stmt|;
name|int
name|cacheIdx
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
