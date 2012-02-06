begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QARRAYDATAOPS_H
end_ifndef
begin_define
DECL|macro|QARRAYDATAOPS_H
define|#
directive|define
name|QARRAYDATAOPS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qarraydata.h>
end_include
begin_include
include|#
directive|include
file|<new>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|namespace
name|QtPrivate
decl_stmt|{  template<class T> struct QPodArrayOps     : QTypedArrayData<T>
block|{
name|void
name|copyAppend
parameter_list|(
specifier|const
name|T
modifier|*
name|b
parameter_list|,
specifier|const
name|T
modifier|*
name|e
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|ref
operator|.
name|isShared
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|b
operator|<
name|e
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|size_t
argument_list|(
name|e
operator|-
name|b
argument_list|)
operator|<=
name|this
operator|->
name|alloc
operator|-
name|uint
argument_list|(
name|this
operator|->
name|size
argument_list|)
argument_list|)
expr_stmt|;
operator|::
name|memcpy
argument_list|(
name|this
operator|->
name|end
argument_list|()
argument_list|,
name|b
argument_list|,
operator|(
name|e
operator|-
name|b
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
name|this
operator|->
name|size
operator|+=
name|e
operator|-
name|b
expr_stmt|;
block|}
name|void
name|copyAppend
parameter_list|(
name|size_t
name|n
parameter_list|,
specifier|const
name|T
modifier|&
name|t
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|ref
operator|.
name|isShared
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|n
operator|<=
name|this
operator|->
name|alloc
operator|-
name|uint
argument_list|(
name|this
operator|->
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|T
modifier|*
name|iter
init|=
name|this
operator|->
name|end
argument_list|()
decl_stmt|;
specifier|const
name|T
modifier|*
specifier|const
name|end
init|=
name|iter
operator|+
name|n
decl_stmt|;
for|for
control|(
init|;
name|iter
operator|!=
name|end
condition|;
operator|++
name|iter
control|)
operator|::
name|memcpy
argument_list|(
name|iter
argument_list|,
operator|&
name|t
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
name|this
operator|->
name|size
operator|+=
name|n
expr_stmt|;
block|}
name|void
name|destroyAll
parameter_list|()
comment|// Call from destructors, ONLY!
block|{
name|Q_ASSERT
argument_list|(
name|this
operator|->
name|ref
operator|.
name|atomic
operator|.
name|load
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// As this is to be called only from destructor, it doesn't need to be
comment|// exception safe; size not updated.
block|}
name|void
name|insert
parameter_list|(
name|T
modifier|*
name|where
parameter_list|,
specifier|const
name|T
modifier|*
name|b
parameter_list|,
specifier|const
name|T
modifier|*
name|e
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|ref
operator|.
name|isShared
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|where
operator|>=
name|this
operator|->
name|begin
argument_list|()
operator|&&
name|where
operator|<
name|this
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
comment|// Use copyAppend at end
name|Q_ASSERT
argument_list|(
name|b
operator|<
name|e
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|e
operator|<=
name|where
operator|||
name|b
operator|>
name|this
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
comment|// No overlap
name|Q_ASSERT
argument_list|(
name|size_t
argument_list|(
name|e
operator|-
name|b
argument_list|)
operator|<=
name|this
operator|->
name|alloc
operator|-
name|uint
argument_list|(
name|this
operator|->
name|size
argument_list|)
argument_list|)
expr_stmt|;
operator|::
name|memmove
argument_list|(
name|where
operator|+
operator|(
name|e
operator|-
name|b
operator|)
argument_list|,
name|where
argument_list|,
operator|(
name|this
operator|->
name|end
argument_list|()
operator|-
name|where
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
operator|::
name|memcpy
argument_list|(
name|where
argument_list|,
name|b
argument_list|,
operator|(
name|e
operator|-
name|b
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
name|this
operator|->
name|size
operator|+=
operator|(
name|e
operator|-
name|b
operator|)
expr_stmt|;
block|}
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|QGenericArrayOps
operator|:
name|QTypedArrayData
operator|<
name|T
operator|>
block|{
name|void
name|copyAppend
argument_list|(
argument|const T *b
argument_list|,
argument|const T *e
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|ref
operator|.
name|isShared
argument_list|()
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|b
operator|<
name|e
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|size_t
argument_list|(
name|e
operator|-
name|b
argument_list|)
operator|<=
name|this
operator|->
name|alloc
operator|-
name|uint
argument_list|(
name|this
operator|->
name|size
argument_list|)
argument_list|)
block|;
name|T
operator|*
name|iter
operator|=
name|this
operator|->
name|end
argument_list|()
block|;
for|for
control|(
init|;
name|b
operator|!=
name|e
condition|;
operator|++
name|iter
operator|,
operator|++
name|b
control|)
block|{
name|new
argument_list|(
argument|iter
argument_list|)
name|T
argument_list|(
operator|*
name|b
argument_list|)
expr_stmt|;
operator|++
name|this
operator|->
name|size
expr_stmt|;
block|}
block|}
name|void
name|copyAppend
argument_list|(
argument|size_t n
argument_list|,
argument|const T&t
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|ref
operator|.
name|isShared
argument_list|()
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|n
operator|<=
name|this
operator|->
name|alloc
operator|-
name|uint
argument_list|(
name|this
operator|->
name|size
argument_list|)
argument_list|)
block|;
name|T
operator|*
name|iter
operator|=
name|this
operator|->
name|end
argument_list|()
block|;
specifier|const
name|T
operator|*
specifier|const
name|end
operator|=
name|iter
operator|+
name|n
block|;
for|for
control|(
init|;
name|iter
operator|!=
name|end
condition|;
operator|++
name|iter
control|)
block|{
name|new
argument_list|(
argument|iter
argument_list|)
name|T
argument_list|(
name|t
argument_list|)
expr_stmt|;
operator|++
name|this
operator|->
name|size
expr_stmt|;
block|}
end_expr_stmt
begin_macro
unit|}      void
name|destroyAll
argument_list|()
end_macro
begin_comment
comment|// Call from destructors, ONLY
end_comment
begin_block
block|{
comment|// As this is to be called only from destructor, it doesn't need to be
comment|// exception safe; size not updated.
name|Q_ASSERT
argument_list|(
name|this
operator|->
name|ref
operator|.
name|atomic
operator|.
name|load
argument_list|()
operator|==
literal|0
argument_list|)
expr_stmt|;
specifier|const
name|T
modifier|*
specifier|const
name|b
init|=
name|this
operator|->
name|begin
argument_list|()
decl_stmt|;
specifier|const
name|T
modifier|*
name|i
init|=
name|this
operator|->
name|end
argument_list|()
decl_stmt|;
while|while
condition|(
name|i
operator|!=
name|b
condition|)
operator|(
operator|--
name|i
operator|)
operator|->
operator|~
name|T
argument_list|()
expr_stmt|;
block|}
end_block
begin_function
name|void
name|insert
parameter_list|(
name|T
modifier|*
name|where
parameter_list|,
specifier|const
name|T
modifier|*
name|b
parameter_list|,
specifier|const
name|T
modifier|*
name|e
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|ref
operator|.
name|isShared
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|where
operator|>=
name|this
operator|->
name|begin
argument_list|()
operator|&&
name|where
operator|<
name|this
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
comment|// Use copyAppend at end
name|Q_ASSERT
argument_list|(
name|b
operator|<
name|e
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|e
operator|<=
name|where
operator|||
name|b
operator|>
name|this
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
comment|// No overlap
name|Q_ASSERT
argument_list|(
name|size_t
argument_list|(
name|e
operator|-
name|b
argument_list|)
operator|<=
name|this
operator|->
name|alloc
operator|-
name|uint
argument_list|(
name|this
operator|->
name|size
argument_list|)
argument_list|)
expr_stmt|;
comment|// Array may be truncated at where in case of exceptions
name|T
modifier|*
specifier|const
name|end
init|=
name|this
operator|->
name|end
argument_list|()
decl_stmt|;
specifier|const
name|T
modifier|*
name|readIter
init|=
name|end
decl_stmt|;
name|T
modifier|*
name|writeIter
init|=
name|end
operator|+
operator|(
name|e
operator|-
name|b
operator|)
decl_stmt|;
specifier|const
name|T
modifier|*
specifier|const
name|step1End
init|=
name|where
operator|+
name|qMax
argument_list|(
name|e
operator|-
name|b
argument_list|,
name|end
operator|-
name|where
argument_list|)
decl_stmt|;
struct|struct
name|Destructor
block|{
name|Destructor
argument_list|(
name|T
operator|*
operator|&
name|iter
argument_list|)
operator|:
name|iter
argument_list|(
operator|&
name|iter
argument_list|)
operator|,
name|end
argument_list|(
argument|iter
argument_list|)
block|{             }
name|void
name|commit
argument_list|()
block|{
name|iter
operator|=
operator|&
name|end
block|;             }
operator|~
name|Destructor
argument_list|()
block|{
for|for
control|(
init|;
operator|*
name|iter
operator|!=
name|end
condition|;
operator|--
operator|*
name|iter
control|)
operator|(
operator|*
name|iter
operator|)
operator|->
expr|~
name|T
argument_list|()
expr_stmt|;
block|}
name|T
modifier|*
modifier|*
name|iter
decl_stmt|;
name|T
modifier|*
name|end
decl_stmt|;
block|}
name|destroyer
argument_list|(
name|writeIter
argument_list|)
struct|;
comment|// Construct new elements in array
do|do
block|{
operator|--
name|readIter
operator|,
operator|--
name|writeIter
expr_stmt|;
name|new
argument_list|(
argument|writeIter
argument_list|)
name|T
argument_list|(
operator|*
name|readIter
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|writeIter
operator|!=
name|step1End
condition|)
do|;
while|while
condition|(
name|writeIter
operator|!=
name|end
condition|)
block|{
operator|--
name|e
operator|,
operator|--
name|writeIter
expr_stmt|;
name|new
argument_list|(
argument|writeIter
argument_list|)
name|T
argument_list|(
operator|*
name|e
argument_list|)
expr_stmt|;
block|}
name|destroyer
operator|.
name|commit
argument_list|()
expr_stmt|;
name|this
operator|->
name|size
operator|+=
name|destroyer
operator|.
name|end
operator|-
name|end
expr_stmt|;
comment|// Copy assign over existing elements
while|while
condition|(
name|readIter
operator|!=
name|where
condition|)
block|{
operator|--
name|readIter
operator|,
operator|--
name|writeIter
expr_stmt|;
operator|*
name|writeIter
operator|=
operator|*
name|readIter
expr_stmt|;
block|}
while|while
condition|(
name|writeIter
operator|!=
name|where
condition|)
block|{
operator|--
name|e
operator|,
operator|--
name|writeIter
expr_stmt|;
operator|*
name|writeIter
operator|=
operator|*
name|e
expr_stmt|;
block|}
block|}
end_function
begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|QMovableArrayOps
operator|:
name|QGenericArrayOps
operator|<
name|T
operator|>
block|{
comment|// using QGenericArrayOps<T>::copyAppend;
comment|// using QGenericArrayOps<T>::destroyAll;
name|void
name|insert
argument_list|(
argument|T *where
argument_list|,
argument|const T *b
argument_list|,
argument|const T *e
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|this
operator|->
name|ref
operator|.
name|isShared
argument_list|()
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|where
operator|>=
name|this
operator|->
name|begin
argument_list|()
operator|&&
name|where
operator|<
name|this
operator|->
name|end
argument_list|()
argument_list|)
block|;
comment|// Use copyAppend at end
name|Q_ASSERT
argument_list|(
name|b
operator|<
name|e
argument_list|)
block|;
name|Q_ASSERT
argument_list|(
name|e
operator|<=
name|where
operator|||
name|b
operator|>
name|this
operator|->
name|end
argument_list|()
argument_list|)
block|;
comment|// No overlap
name|Q_ASSERT
argument_list|(
name|size_t
argument_list|(
name|e
operator|-
name|b
argument_list|)
operator|<=
name|this
operator|->
name|alloc
operator|-
name|uint
argument_list|(
name|this
operator|->
name|size
argument_list|)
argument_list|)
block|;
comment|// Provides strong exception safety guarantee,
comment|// provided T::~T() nothrow
block|struct
name|ReversibleDisplace
block|{
name|ReversibleDisplace
argument_list|(
argument|T *begin
argument_list|,
argument|T *end
argument_list|,
argument|size_t displace
argument_list|)
operator|:
name|begin
argument_list|(
name|begin
argument_list|)
block|,
name|end
argument_list|(
name|end
argument_list|)
block|,
name|displace
argument_list|(
argument|displace
argument_list|)
block|{
operator|::
name|memmove
argument_list|(
name|begin
operator|+
name|displace
argument_list|,
name|begin
argument_list|,
operator|(
name|end
operator|-
name|begin
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
block|;             }
name|void
name|commit
argument_list|()
block|{
name|displace
operator|=
literal|0
block|; }
operator|~
name|ReversibleDisplace
argument_list|()
block|{
if|if
condition|(
name|displace
condition|)
operator|::
name|memmove
argument_list|(
name|begin
argument_list|,
name|begin
operator|+
name|displace
argument_list|,
operator|(
name|end
operator|-
name|begin
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|T
operator|*
specifier|const
name|begin
block|;
name|T
operator|*
specifier|const
name|end
block|;
name|size_t
name|displace
block|;          }
name|displace
argument_list|(
name|where
argument_list|,
name|this
operator|->
name|end
argument_list|()
argument_list|,
name|size_t
argument_list|(
name|e
operator|-
name|b
argument_list|)
argument_list|)
block|;          struct
name|CopyConstructor
block|{
name|CopyConstructor
argument_list|(
name|T
operator|*
name|where
argument_list|)
operator|:
name|where
argument_list|(
argument|where
argument_list|)
block|{}
name|void
name|copy
argument_list|(
argument|const T *src
argument_list|,
argument|const T *const srcEnd
argument_list|)
block|{
name|n
operator|=
literal|0
block|;
for|for
control|(
init|;
name|src
operator|!=
name|srcEnd
condition|;
operator|++
name|src
control|)
block|{
name|new
argument_list|(
argument|where + n
argument_list|)
name|T
argument_list|(
operator|*
name|src
argument_list|)
expr_stmt|;
operator|++
name|n
expr_stmt|;
block|}
name|n
operator|=
literal|0
block|;             }
operator|~
name|CopyConstructor
argument_list|()
block|{
while|while
condition|(
name|n
condition|)
name|where
index|[
operator|--
name|n
index|]
operator|.
operator|~
name|T
argument_list|()
expr_stmt|;
block|}
name|T
operator|*
specifier|const
name|where
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|size_t
name|n
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|} copier
operator|(
name|where
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|copier
operator|.
name|copy
argument_list|(
name|b
argument_list|,
name|e
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|displace
operator|.
name|commit
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|this
operator|->
name|size
operator|+=
operator|(
name|e
operator|-
name|b
operator|)
expr_stmt|;
end_expr_stmt
begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
operator|=
name|void
operator|>
expr|struct
name|QArrayOpsSelector
block|{
typedef|typedef
name|QGenericArrayOps
operator|<
name|T
operator|>
name|Type
expr_stmt|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|QArrayOpsSelector
operator|<
name|T
operator|,
name|typename
name|QEnableIf
operator|<
operator|!
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
operator|&&
operator|!
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isStatic
operator|>
operator|::
name|Type
operator|>
block|{
typedef|typedef
name|QPodArrayOps
operator|<
name|T
operator|>
name|Type
expr_stmt|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|QArrayOpsSelector
operator|<
name|T
operator|,
name|typename
name|QEnableIf
operator|<
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isComplex
operator|&&
operator|!
name|QTypeInfo
operator|<
name|T
operator|>
operator|::
name|isStatic
operator|>
operator|::
name|Type
operator|>
block|{
typedef|typedef
name|QMovableArrayOps
operator|<
name|T
operator|>
name|Type
expr_stmt|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
unit|}
comment|// namespace QtPrivate
end_comment
begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
expr|struct
name|QArrayDataOps
DECL|struct|Type
operator|:
name|QtPrivate
operator|::
name|QArrayOpsSelector
operator|<
name|T
operator|>
operator|::
name|Type
block|{ }
expr_stmt|;
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
comment|// include guard
end_comment
end_unit
