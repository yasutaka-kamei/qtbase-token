begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtQml module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQMLJSMEMORYPOOL_P_H
end_ifndef
begin_define
DECL|macro|QQMLJSMEMORYPOOL_P_H
define|#
directive|define
name|QQMLJSMEMORYPOOL_P_H
end_define
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
begin_include
include|#
directive|include
file|"qqmljsglobal_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<cstring>
end_include
begin_decl_stmt
name|QT_QML_BEGIN_NAMESPACE
name|namespace
name|QQmlJS
block|{
name|class
name|Managed
decl_stmt|;
name|class
name|QML_PARSER_EXPORT
name|MemoryPool
range|:
name|public
name|QSharedData
block|{
name|MemoryPool
argument_list|(
specifier|const
name|MemoryPool
operator|&
name|other
argument_list|)
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|MemoryPool
operator|&
name|other
operator|)
block|;
name|public
operator|:
name|MemoryPool
argument_list|()
operator|:
name|_blocks
argument_list|(
literal|0
argument_list|)
block|,
name|_allocatedBlocks
argument_list|(
literal|0
argument_list|)
block|,
name|_blockCount
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|_ptr
argument_list|(
literal|0
argument_list|)
block|,
name|_end
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|MemoryPool
argument_list|()
block|{
if|if
condition|(
name|_blocks
condition|)
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
name|_allocatedBlocks
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|char
modifier|*
name|b
init|=
name|_blocks
index|[
name|i
index|]
condition|)
name|free
argument_list|(
name|b
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|_blocks
argument_list|)
expr_stmt|;
block|}
block|}
specifier|inline
name|void
operator|*
name|allocate
argument_list|(
argument|size_t size
argument_list|)
block|{
name|size
operator|=
operator|(
name|size
operator|+
literal|7
operator|)
operator|&
operator|~
literal|7
block|;
if|if
condition|(
name|_ptr
operator|&&
operator|(
name|_ptr
operator|+
name|size
operator|<
name|_end
operator|)
condition|)
block|{
name|void
modifier|*
name|addr
init|=
name|_ptr
decl_stmt|;
name|_ptr
operator|+=
name|size
expr_stmt|;
return|return
name|addr
return|;
block|}
return|return
name|allocate_helper
argument_list|(
name|size
argument_list|)
return|;
block|}
name|void
name|reset
argument_list|()
block|{
name|_blockCount
operator|=
operator|-
literal|1
block|;
name|_ptr
operator|=
name|_end
operator|=
literal|0
block|;     }
name|template
operator|<
name|typename
name|_Tp
operator|>
name|_Tp
operator|*
name|New
argument_list|()
block|{
return|return
name|new
argument_list|(
argument|this->allocate(sizeof(_Tp))
argument_list|)
name|_Tp
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|PoolContentType
block|,
name|typename
name|Visitor
operator|>
name|void
name|visitManagedPool
argument_list|(
argument|Visitor&visitor
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
name|_blockCount
condition|;
operator|++
name|i
control|)
block|{
name|char
modifier|*
name|p
init|=
name|_blocks
index|[
name|i
index|]
decl_stmt|;
name|char
modifier|*
name|end
init|=
name|p
operator|+
name|BLOCK_SIZE
decl_stmt|;
if|if
condition|(
name|i
operator|==
name|_blockCount
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|_ptr
operator|<=
name|end
argument_list|)
expr_stmt|;
name|end
operator|=
name|_ptr
expr_stmt|;
block|}
name|Q_ASSERT
argument_list|(
name|p
operator|<=
name|end
argument_list|)
expr_stmt|;
specifier|const
name|qptrdiff
name|increment
init|=
operator|(
sizeof|sizeof
argument_list|(
name|PoolContentType
argument_list|)
operator|+
literal|7
operator|)
operator|&
operator|~
literal|7
decl_stmt|;
while|while
condition|(
name|p
operator|+
name|increment
operator|<=
name|end
condition|)
block|{
name|visitor
argument_list|(
name|reinterpret_cast
operator|<
name|PoolContentType
operator|*
operator|>
operator|(
name|p
operator|)
argument_list|)
expr_stmt|;
name|p
operator|+=
name|increment
expr_stmt|;
block|}
block|}
block|}
name|private
operator|:
name|void
operator|*
name|allocate_helper
argument_list|(
argument|size_t size
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|size
operator|<
name|BLOCK_SIZE
argument_list|)
block|;
if|if
condition|(
operator|++
name|_blockCount
operator|==
name|_allocatedBlocks
condition|)
block|{
if|if
condition|(
operator|!
name|_allocatedBlocks
condition|)
name|_allocatedBlocks
operator|=
name|DEFAULT_BLOCK_COUNT
expr_stmt|;
else|else
name|_allocatedBlocks
operator|*=
literal|2
expr_stmt|;
name|_blocks
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
name|realloc
argument_list|(
name|_blocks
argument_list|,
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
operator|*
name|_allocatedBlocks
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|index
init|=
name|_blockCount
init|;
name|index
operator|<
name|_allocatedBlocks
condition|;
operator|++
name|index
control|)
name|_blocks
index|[
name|index
index|]
operator|=
literal|0
expr_stmt|;
block|}
name|char
modifier|*
modifier|&
name|block
init|=
name|_blocks
index|[
name|_blockCount
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|block
condition|)
name|block
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|BLOCK_SIZE
argument_list|)
expr_stmt|;
name|_ptr
operator|=
name|block
decl_stmt|;
name|_end
operator|=
name|_ptr
operator|+
name|BLOCK_SIZE
expr_stmt|;
name|void
modifier|*
name|addr
init|=
name|_ptr
decl_stmt|;
name|_ptr
operator|+=
name|size
expr_stmt|;
return|return
name|addr
return|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|char
modifier|*
modifier|*
name|_blocks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|_allocatedBlocks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|_blockCount
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|char
modifier|*
name|_ptr
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|char
modifier|*
name|_end
decl_stmt|;
end_decl_stmt
begin_enum
enum|enum
block|{
name|BLOCK_SIZE
init|=
literal|8
operator|*
literal|1024
block|,
name|DEFAULT_BLOCK_COUNT
init|=
literal|8
block|}
enum|;
end_enum
begin_decl_stmt
unit|};
name|class
name|QML_PARSER_EXPORT
name|Managed
block|{
name|Managed
argument_list|(
specifier|const
name|Managed
operator|&
name|other
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|Managed
operator|&
name|other
operator|)
decl_stmt|;
name|public
label|:
name|Managed
argument_list|()
block|{}
operator|~
name|Managed
argument_list|()
block|{}
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t size
argument_list|,
argument|MemoryPool *pool
argument_list|)
block|{
return|return
name|pool
operator|->
name|allocate
argument_list|(
name|size
argument_list|)
return|;
block|}
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{}
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
parameter_list|,
name|MemoryPool
modifier|*
parameter_list|)
block|{}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
unit|}
comment|// namespace QQmlJS
end_comment
begin_endif
unit|QT_QML_END_NAMESPACE
endif|#
directive|endif
end_endif
end_unit
