begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qarraydata.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|shared_null
specifier|const
name|QArrayData
name|QArrayData
operator|::
name|shared_null
init|=
block|{
name|Q_REFCOUNT_INITIALIZER
argument_list|(
operator|-
literal|1
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|shared_empty
specifier|const
name|QArrayData
name|QArrayData
operator|::
name|shared_empty
init|=
block|{
name|Q_REFCOUNT_INITIALIZER
argument_list|(
operator|-
literal|1
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|allocate
name|QArrayData
modifier|*
name|QArrayData
operator|::
name|allocate
parameter_list|(
name|size_t
name|objectSize
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|size_t
name|capacity
parameter_list|,
name|bool
name|reserve
parameter_list|)
block|{
comment|// Alignment is a power of two
name|Q_ASSERT
argument_list|(
name|alignment
operator|>=
name|Q_ALIGNOF
argument_list|(
name|QArrayData
argument_list|)
operator|&&
operator|!
operator|(
name|alignment
operator|&
operator|(
name|alignment
operator|-
literal|1
operator|)
operator|)
argument_list|)
expr_stmt|;
comment|// Don't allocate empty headers
if|if
condition|(
operator|!
name|capacity
condition|)
return|return
cast|const_cast
argument_list|<
name|QArrayData
operator|*
argument_list|>
argument_list|(
operator|&
name|shared_empty
argument_list|)
return|;
comment|// Allocate extra (alignment - Q_ALIGNOF(QArrayData)) padding bytes so we
comment|// can properly align the data array. This assumes malloc is able to
comment|// provide appropriate alignment for the header -- as it should!
name|size_t
name|allocSize
init|=
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
operator|+
name|objectSize
operator|*
name|capacity
operator|+
operator|(
name|alignment
operator|-
name|Q_ALIGNOF
argument_list|(
name|QArrayData
argument_list|)
operator|)
decl_stmt|;
name|QArrayData
modifier|*
name|header
init|=
cast|static_cast
argument_list|<
name|QArrayData
operator|*
argument_list|>
argument_list|(
name|qMalloc
argument_list|(
name|allocSize
argument_list|)
argument_list|)
decl_stmt|;
name|Q_CHECK_PTR
argument_list|(
name|header
argument_list|)
expr_stmt|;
if|if
condition|(
name|header
condition|)
block|{
name|quintptr
name|data
init|=
operator|(
name|quintptr
argument_list|(
name|header
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|QArrayData
argument_list|)
operator|+
name|alignment
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
name|alignment
operator|-
literal|1
operator|)
decl_stmt|;
name|header
operator|->
name|ref
operator|.
name|initializeOwned
argument_list|()
expr_stmt|;
name|header
operator|->
name|size
operator|=
literal|0
expr_stmt|;
name|header
operator|->
name|alloc
operator|=
name|capacity
expr_stmt|;
name|header
operator|->
name|capacityReserved
operator|=
name|reserve
expr_stmt|;
name|header
operator|->
name|offset
operator|=
name|data
operator|-
name|quintptr
argument_list|(
name|header
argument_list|)
expr_stmt|;
block|}
return|return
name|header
return|;
block|}
end_function
begin_function
DECL|function|deallocate
name|void
name|QArrayData
operator|::
name|deallocate
parameter_list|(
name|QArrayData
modifier|*
name|data
parameter_list|,
name|size_t
name|objectSize
parameter_list|,
name|size_t
name|alignment
parameter_list|)
block|{
comment|// Alignment is a power of two
name|Q_ASSERT
argument_list|(
name|alignment
operator|>=
name|Q_ALIGNOF
argument_list|(
name|QArrayData
argument_list|)
operator|&&
operator|!
operator|(
name|alignment
operator|&
operator|(
name|alignment
operator|-
literal|1
operator|)
operator|)
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
argument|objectSize
argument_list|)
name|Q_UNUSED
argument_list|(
argument|alignment
argument_list|)
name|qFree
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
