begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGL_P_H
end_ifndef
begin_define
DECL|macro|QOPENGL_P_H
define|#
directive|define
name|QOPENGL_P_H
end_define
begin_include
include|#
directive|include
file|<qopengl.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<qthreadstorage.h>
end_include
begin_include
include|#
directive|include
file|<qcache.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|QOpenGLExtensionMatcher
block|{
name|public
label|:
name|QOpenGLExtensionMatcher
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
expr_stmt|;
name|QOpenGLExtensionMatcher
argument_list|()
expr_stmt|;
name|bool
name|match
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
decl|const
block|{
name|int
name|str_length
init|=
name|qstrlen
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|str
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|str_length
operator|>
literal|0
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|str
index|[
name|str_length
operator|-
literal|1
index|]
operator|!=
literal|' '
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_offsets
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|char
modifier|*
name|extension
init|=
name|m_extensions
operator|.
name|constData
argument_list|()
operator|+
name|m_offsets
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|qstrncmp
argument_list|(
name|extension
argument_list|,
name|str
argument_list|,
name|str_length
argument_list|)
operator|==
literal|0
operator|&&
name|extension
index|[
name|str_length
index|]
operator|==
literal|' '
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|private
label|:
name|void
name|init
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
name|QByteArray
name|m_extensions
decl_stmt|;
name|QVector
operator|<
name|int
operator|>
name|m_offsets
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// this is a class that wraps a QThreadStorage object for storing
end_comment
begin_comment
comment|// thread local instances of the GL 1 and GL 2 paint engines
end_comment
begin_decl_stmt
DECL|variable|QPaintEngine
name|class
name|QPaintEngine
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QOpenGLEngineThreadStorage
block|{
name|public
operator|:
name|QPaintEngine
operator|*
name|engine
argument_list|()
block|{
name|QPaintEngine
operator|*
operator|&
name|localEngine
operator|=
name|storage
operator|.
name|localData
argument_list|()
block|;
if|if
condition|(
operator|!
name|localEngine
condition|)
name|localEngine
operator|=
name|new
name|T
expr_stmt|;
return|return
name|localEngine
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|QThreadStorage
operator|<
name|QPaintEngine
operator|*
operator|>
name|storage
expr_stmt|;
end_expr_stmt
begin_decl_stmt
unit|};
name|class
name|QOpenGLTexture
range|:
name|public
name|QOpenGLSharedResource
block|{
name|public
operator|:
name|QOpenGLTexture
argument_list|(
argument|QOpenGLContext *ctx
argument_list|,
argument|GLuint id
argument_list|,
argument|bool inverted
argument_list|)
operator|:
name|QOpenGLSharedResource
argument_list|(
name|ctx
operator|->
name|shareGroup
argument_list|()
argument_list|)
block|,
name|m_id
argument_list|(
name|id
argument_list|)
block|,
name|m_inverted
argument_list|(
argument|inverted
argument_list|)
block|{     }
name|GLuint
name|id
argument_list|()
specifier|const
block|{
return|return
name|m_id
return|;
block|}
name|bool
name|invertedY
argument_list|()
specifier|const
block|{
return|return
name|m_inverted
return|;
block|}
name|protected
operator|:
name|void
name|invalidateResource
argument_list|()
block|{
name|m_id
operator|=
literal|0
block|;     }
name|void
name|freeResource
argument_list|(
argument|QOpenGLContext *
argument_list|)
block|{
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_id
argument_list|)
block|;     }
name|private
operator|:
name|GLuint
name|m_id
block|;
name|bool
name|m_inverted
block|; }
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QOpenGLTextureCacheKey
struct|struct
name|QOpenGLTextureCacheKey
block|{
DECL|member|key
name|qint64
name|key
decl_stmt|;
DECL|member|group
name|QOpenGLContextGroup
modifier|*
name|group
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QOpenGLTextureCacheKey
operator|&
name|a
operator|,
specifier|const
name|QOpenGLTextureCacheKey
operator|&
name|b
operator|)
block|{
return|return
name|a
operator|.
name|key
operator|==
name|b
operator|.
name|key
operator|&&
name|a
operator|.
name|group
operator|==
name|b
operator|.
name|group
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|QOpenGLTextureCacheKey
modifier|&
name|key
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|key
operator|.
name|key
argument_list|)
operator|^
name|qHash
argument_list|(
name|key
operator|.
name|group
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|QPlatformPixmap
name|class
name|QPlatformPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOpenGLTextureCache
block|{
name|public
label|:
name|QOpenGLTextureCache
argument_list|()
expr_stmt|;
operator|~
name|QOpenGLTextureCache
argument_list|()
expr_stmt|;
name|void
name|insert
parameter_list|(
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|,
name|qint64
name|key
parameter_list|,
name|QOpenGLTexture
modifier|*
name|texture
parameter_list|,
name|int
name|cost
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
name|qint64
name|key
parameter_list|)
function_decl|;
specifier|inline
name|int
name|size
parameter_list|()
function_decl|;
specifier|inline
name|void
name|setMaxCost
parameter_list|(
name|int
name|newMax
parameter_list|)
function_decl|;
specifier|inline
name|int
name|maxCost
parameter_list|()
function_decl|;
specifier|inline
name|QOpenGLTexture
modifier|*
name|getTexture
parameter_list|(
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|,
name|qint64
name|key
parameter_list|)
function_decl|;
name|bool
name|remove
parameter_list|(
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|,
name|GLuint
name|textureId
parameter_list|)
function_decl|;
name|void
name|removeContextTextures
parameter_list|(
name|QOpenGLContext
modifier|*
name|ctx
parameter_list|)
function_decl|;
specifier|static
name|QOpenGLTextureCache
modifier|*
name|instance
parameter_list|()
function_decl|;
specifier|static
name|void
name|cleanupTexturesForCacheKey
parameter_list|(
name|qint64
name|cacheKey
parameter_list|)
function_decl|;
specifier|static
name|void
name|cleanupTexturesForPixampData
parameter_list|(
name|QPlatformPixmap
modifier|*
name|pixmap
parameter_list|)
function_decl|;
specifier|static
name|void
name|cleanupBeforePixmapDestruction
parameter_list|(
name|QPlatformPixmap
modifier|*
name|pixmap
parameter_list|)
function_decl|;
name|private
label|:
name|QCache
operator|<
name|QOpenGLTextureCacheKey
operator|,
name|QOpenGLTexture
operator|>
name|m_cache
expr_stmt|;
name|QReadWriteLock
name|m_lock
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|size
name|int
name|QOpenGLTextureCache
operator|::
name|size
argument_list|()
block|{
name|QReadLocker
name|locker
argument_list|(
operator|&
name|m_lock
argument_list|)
block|;
return|return
name|m_cache
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setMaxCost
name|void
name|QOpenGLTextureCache
operator|::
name|setMaxCost
argument_list|(
argument|int newMax
argument_list|)
block|{
name|QWriteLocker
name|locker
argument_list|(
operator|&
name|m_lock
argument_list|)
block|;
name|m_cache
operator|.
name|setMaxCost
argument_list|(
name|newMax
argument_list|)
block|; }
DECL|function|maxCost
name|int
name|QOpenGLTextureCache
operator|::
name|maxCost
argument_list|()
block|{
name|QReadLocker
name|locker
argument_list|(
operator|&
name|m_lock
argument_list|)
block|;
return|return
name|m_cache
operator|.
name|maxCost
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|getTexture
name|QOpenGLTexture
operator|*
name|QOpenGLTextureCache
operator|::
name|getTexture
argument_list|(
argument|QOpenGLContext *ctx
argument_list|,
argument|qint64 key
argument_list|)
block|{
name|QReadLocker
name|locker
argument_list|(
operator|&
name|m_lock
argument_list|)
block|;
specifier|const
name|QOpenGLTextureCacheKey
name|cacheKey
operator|=
block|{
name|key
block|,
name|ctx
operator|->
name|shareGroup
argument_list|()
block|}
block|;
return|return
name|m_cache
operator|.
name|object
argument_list|(
name|cacheKey
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGL_H
end_comment
end_unit
