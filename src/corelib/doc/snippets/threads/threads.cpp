begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QCache>
end_include
begin_include
include|#
directive|include
file|<QMutex>
end_include
begin_include
include|#
directive|include
file|<QThreadStorage>
end_include
begin_include
include|#
directive|include
file|"threads.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|run
name|void
name|MyThread
operator|::
name|run
parameter_list|()
comment|//! [0] //! [1]
block|{
comment|//! [1] //! [2]
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_define
DECL|macro|Counter
define|#
directive|define
name|Counter
value|ReentrantCounter
end_define
begin_comment
comment|//! [3]
end_comment
begin_class
DECL|class|Counter
class|class
name|Counter
comment|//! [3] //! [4]
block|{
public|public:
DECL|function|Counter
name|Counter
parameter_list|()
block|{
name|n
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|increment
name|void
name|increment
parameter_list|()
block|{
operator|++
name|n
expr_stmt|;
block|}
DECL|function|decrement
name|void
name|decrement
parameter_list|()
block|{
operator|--
name|n
expr_stmt|;
block|}
DECL|function|value
name|int
name|value
parameter_list|()
specifier|const
block|{
return|return
name|n
return|;
block|}
private|private:
DECL|member|n
name|int
name|n
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [4]
end_comment
begin_undef
DECL|macro|Counter
undef|#
directive|undef
name|Counter
end_undef
begin_define
DECL|macro|Counter
define|#
directive|define
name|Counter
value|ThreadSafeCounter
end_define
begin_comment
comment|//! [5]
end_comment
begin_class
DECL|class|Counter
class|class
name|Counter
comment|//! [5] //! [6]
block|{
public|public:
DECL|function|Counter
name|Counter
parameter_list|()
block|{
name|n
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|increment
name|void
name|increment
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
operator|++
name|n
expr_stmt|;
block|}
DECL|function|decrement
name|void
name|decrement
parameter_list|()
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
operator|--
name|n
expr_stmt|;
block|}
DECL|function|value
name|int
name|value
parameter_list|()
specifier|const
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|mutex
argument_list|)
decl_stmt|;
return|return
name|n
return|;
block|}
private|private:
DECL|member|mutex
specifier|mutable
name|QMutex
name|mutex
decl_stmt|;
DECL|member|n
name|int
name|n
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//! [6]
end_comment
begin_typedef
DECL|typedef|SomeClass
typedef|typedef
name|int
name|SomeClass
typedef|;
end_typedef
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
DECL|variable|caches
name|QThreadStorage
argument_list|<
name|QCache
argument_list|<
name|QString
argument_list|,
name|SomeClass
argument_list|>
argument_list|>
name|caches
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|cacheObject
name|void
name|cacheObject
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
name|SomeClass
modifier|*
name|object
parameter_list|)
comment|//! [7] //! [8]
block|{
name|caches
operator|.
name|localData
argument_list|()
operator|.
name|insert
argument_list|(
name|key
argument_list|,
name|object
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeFromCache
name|void
name|removeFromCache
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
comment|//! [8] //! [9]
block|{
if|if
condition|(
operator|!
name|caches
operator|.
name|hasLocalData
argument_list|()
condition|)
return|return;
name|caches
operator|.
name|localData
argument_list|()
operator|.
name|remove
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
end_unit
