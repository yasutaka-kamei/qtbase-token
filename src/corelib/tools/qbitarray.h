begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBITARRAY_H
end_ifndef
begin_define
DECL|macro|QBITARRAY_H
define|#
directive|define
name|QBITARRAY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QBitRef
name|class
name|QBitRef
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QBitArray
block|{
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QBitArray
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QBitArray
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_CORE_EXPORT
name|uint
name|qHash
argument_list|(
specifier|const
name|QBitArray
operator|&
name|key
argument_list|,
name|uint
name|seed
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|QByteArray
name|d
decl_stmt|;
name|public
label|:
specifier|inline
name|QBitArray
argument_list|()
block|{}
name|explicit
name|QBitArray
argument_list|(
argument|int size
argument_list|,
argument|bool val = false
argument_list|)
expr_stmt|;
name|QBitArray
argument_list|(
specifier|const
name|QBitArray
operator|&
name|other
argument_list|)
operator|:
name|d
argument_list|(
argument|other.d
argument_list|)
block|{}
specifier|inline
name|QBitArray
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QBitArray
operator|&
name|other
operator|)
block|{
name|d
operator|=
name|other
operator|.
name|d
block|;
return|return
operator|*
name|this
return|;
block|}
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QBitArray
modifier|&
name|operator
init|=
operator|(
name|QBitArray
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
parameter_list|(
name|QBitArray
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
operator|(
name|d
operator|.
name|size
argument_list|()
operator|<<
literal|3
operator|)
operator|-
operator|*
name|d
operator|.
name|constData
argument_list|()
return|;
block|}
specifier|inline
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
operator|(
name|d
operator|.
name|size
argument_list|()
operator|<<
literal|3
operator|)
operator|-
operator|*
name|d
operator|.
name|constData
argument_list|()
return|;
block|}
name|int
name|count
argument_list|(
name|bool
name|on
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isEmpty
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isNull
argument_list|()
return|;
block|}
name|void
name|resize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
specifier|inline
name|void
name|detach
parameter_list|()
block|{
name|d
operator|.
name|detach
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|bool
name|isDetached
argument_list|()
specifier|const
block|{
return|return
name|d
operator|.
name|isDetached
argument_list|()
return|;
block|}
specifier|inline
name|void
name|clear
parameter_list|()
block|{
name|d
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|bool
name|testBit
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|void
name|setBit
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
name|void
name|setBit
parameter_list|(
name|int
name|i
parameter_list|,
name|bool
name|val
parameter_list|)
function_decl|;
name|void
name|clearBit
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
name|bool
name|toggleBit
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
name|bool
name|at
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|QBitRef
name|operator
function_decl|[]
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
name|bool
name|operator
index|[]
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|QBitRef
name|operator
function_decl|[]
parameter_list|(
name|uint
name|i
parameter_list|)
function_decl|;
name|bool
name|operator
index|[]
argument_list|(
name|uint
name|i
argument_list|)
decl|const
decl_stmt|;
name|QBitArray
operator|&
name|operator
operator|&=
operator|(
specifier|const
name|QBitArray
operator|&
operator|)
expr_stmt|;
name|QBitArray
operator|&
name|operator
operator||=
operator|(
specifier|const
name|QBitArray
operator|&
operator|)
expr_stmt|;
name|QBitArray
operator|&
name|operator
operator|^=
operator|(
specifier|const
name|QBitArray
operator|&
operator|)
expr_stmt|;
name|QBitArray
name|operator
operator|~
operator|(
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QBitArray
operator|&
name|a
operator|)
specifier|const
block|{
return|return
name|d
operator|==
name|a
operator|.
name|d
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QBitArray
operator|&
name|a
operator|)
specifier|const
block|{
return|return
name|d
operator|!=
name|a
operator|.
name|d
return|;
block|}
specifier|inline
name|bool
name|fill
parameter_list|(
name|bool
name|val
parameter_list|,
name|int
name|size
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
name|void
name|fill
parameter_list|(
name|bool
name|val
parameter_list|,
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
specifier|inline
name|void
name|truncate
parameter_list|(
name|int
name|pos
parameter_list|)
block|{
if|if
condition|(
name|pos
operator|<
name|size
argument_list|()
condition|)
name|resize
argument_list|(
name|pos
argument_list|)
expr_stmt|;
block|}
name|public
label|:
typedef|typedef
name|QByteArray
operator|::
name|DataPtr
name|DataPtr
expr_stmt|;
specifier|inline
name|DataPtr
modifier|&
name|data_ptr
parameter_list|()
block|{
return|return
name|d
operator|.
name|data_ptr
argument_list|()
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|fill
specifier|inline
name|bool
name|QBitArray
operator|::
name|fill
argument_list|(
argument|bool aval
argument_list|,
argument|int asize
argument_list|)
block|{
operator|*
name|this
operator|=
name|QBitArray
argument_list|(
operator|(
name|asize
operator|<
literal|0
operator|?
name|this
operator|->
name|size
argument_list|()
operator|:
name|asize
operator|)
argument_list|,
name|aval
argument_list|)
block|;
return|return
name|true
return|;
block|}
end_expr_stmt
begin_function_decl
name|Q_CORE_EXPORT
name|QBitArray
name|operator
function_decl|&(const
name|QBitArray
function_decl|&
operator|,
function_decl|const QBitArray&
end_function_decl
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QBitArray
name|operator
operator||
operator|(
specifier|const
name|QBitArray
operator|&
operator|,
specifier|const
name|QBitArray
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|Q_CORE_EXPORT
name|QBitArray
name|operator
modifier|^
parameter_list|(
specifier|const
name|QBitArray
modifier|&
parameter_list|,
specifier|const
name|QBitArray
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
DECL|function|testBit
specifier|inline
name|bool
name|QBitArray
operator|::
name|testBit
argument_list|(
argument|int i
argument_list|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<
name|size
argument_list|()
argument_list|)
block|;
return|return
operator|(
operator|*
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|uchar
operator|*
operator|>
operator|(
name|d
operator|.
name|constData
argument_list|()
operator|)
operator|+
literal|1
operator|+
operator|(
name|i
operator|>>
literal|3
operator|)
operator|)
operator|&
operator|(
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
operator|)
operator|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setBit
specifier|inline
name|void
name|QBitArray
operator|::
name|setBit
argument_list|(
argument|int i
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<
name|size
argument_list|()
argument_list|)
block|;
operator|*
operator|(
name|reinterpret_cast
operator|<
name|uchar
operator|*
operator|>
operator|(
name|d
operator|.
name|data
argument_list|()
operator|)
operator|+
literal|1
operator|+
operator|(
name|i
operator|>>
literal|3
operator|)
operator|)
operator||=
name|uchar
argument_list|(
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
argument_list|)
block|; }
DECL|function|clearBit
specifier|inline
name|void
name|QBitArray
operator|::
name|clearBit
argument_list|(
argument|int i
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<
name|size
argument_list|()
argument_list|)
block|;
operator|*
operator|(
name|reinterpret_cast
operator|<
name|uchar
operator|*
operator|>
operator|(
name|d
operator|.
name|data
argument_list|()
operator|)
operator|+
literal|1
operator|+
operator|(
name|i
operator|>>
literal|3
operator|)
operator|)
operator|&=
operator|~
name|uchar
argument_list|(
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
argument_list|)
block|; }
DECL|function|setBit
specifier|inline
name|void
name|QBitArray
operator|::
name|setBit
argument_list|(
argument|int i
argument_list|,
argument|bool val
argument_list|)
block|{
if|if
condition|(
name|val
condition|)
name|setBit
argument_list|(
name|i
argument_list|)
expr_stmt|;
else|else
name|clearBit
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|toggleBit
specifier|inline
name|bool
name|QBitArray
operator|::
name|toggleBit
argument_list|(
argument|int i
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<
name|size
argument_list|()
argument_list|)
block|;
name|uchar
name|b
operator|=
name|uchar
argument_list|(
literal|1
operator|<<
operator|(
name|i
operator|&
literal|7
operator|)
argument_list|)
block|;
name|uchar
operator|*
name|p
operator|=
name|reinterpret_cast
operator|<
name|uchar
operator|*
operator|>
operator|(
name|d
operator|.
name|data
argument_list|()
operator|)
operator|+
literal|1
operator|+
operator|(
name|i
operator|>>
literal|3
operator|)
block|;
name|uchar
name|c
operator|=
name|uchar
argument_list|(
operator|*
name|p
operator|&
name|b
argument_list|)
block|;
operator|*
name|p
operator|^=
name|b
block|;
return|return
name|c
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|QBitArray
operator|::
name|operator
index|[]
operator|(
name|int
name|i
operator|)
specifier|const
block|{
return|return
name|testBit
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|QBitArray
operator|::
name|operator
index|[]
operator|(
name|uint
name|i
operator|)
specifier|const
block|{
return|return
name|testBit
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|at
specifier|inline
name|bool
name|QBitArray
operator|::
name|at
argument_list|(
argument|int i
argument_list|)
specifier|const
block|{
return|return
name|testBit
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QBitRef
block|{
name|private
label|:
name|QBitArray
modifier|&
name|a
decl_stmt|;
name|int
name|i
decl_stmt|;
specifier|inline
name|QBitRef
argument_list|(
argument|QBitArray& array
argument_list|,
argument|int idx
argument_list|)
operator|:
name|a
argument_list|(
name|array
argument_list|)
operator|,
name|i
argument_list|(
argument|idx
argument_list|)
block|{}
name|friend
name|class
name|QBitArray
expr_stmt|;
name|public
label|:
specifier|inline
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|a
operator|.
name|testBit
argument_list|(
name|i
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
operator|!
name|a
operator|.
name|testBit
argument_list|(
name|i
argument_list|)
return|;
block|}
name|QBitRef
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QBitRef
operator|&
name|val
operator|)
block|{
name|a
operator|.
name|setBit
argument_list|(
name|i
argument_list|,
name|val
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|QBitRef
modifier|&
name|operator
init|=
operator|(
name|bool
name|val
operator|)
block|{
name|a
operator|.
name|setBit
argument_list|(
name|i
argument_list|,
name|val
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QBitRef
name|QBitArray
operator|::
name|operator
index|[]
operator|(
name|int
name|i
operator|)
block|{
name|Q_ASSERT
argument_list|(
name|i
operator|>=
literal|0
argument_list|)
block|;
return|return
name|QBitRef
argument_list|(
operator|*
name|this
argument_list|,
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QBitRef
name|QBitArray
operator|::
name|operator
index|[]
operator|(
name|uint
name|i
operator|)
block|{
return|return
name|QBitRef
argument_list|(
operator|*
name|this
argument_list|,
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QBitArray
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QBitArray
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QBitArray
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QBitArray
argument_list|)
end_macro
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBITARRAY_H
end_comment
end_unit
