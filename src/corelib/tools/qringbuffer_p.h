begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QRINGBUFFER_P_H
end_ifndef
begin_define
DECL|macro|QRINGBUFFER_P_H
define|#
directive|define
name|QRINGBUFFER_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of a number of Qt sources files.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QRingBuffer
block|{
name|public
label|:
name|explicit
specifier|inline
name|QRingBuffer
argument_list|(
argument|int growth =
literal|4096
argument_list|)
operator|:
name|basicBlockSize
argument_list|(
argument|growth
argument_list|)
block|{
name|buffers
operator|<<
name|QByteArray
argument_list|()
block|;
name|clear
argument_list|()
block|;     }
specifier|inline
name|int
name|nextDataBlockSize
argument_list|()
specifier|const
block|{
return|return
operator|(
name|tailBuffer
operator|==
literal|0
operator|?
name|tail
operator|:
name|buffers
operator|.
name|first
argument_list|()
operator|.
name|size
argument_list|()
operator|)
operator|-
name|head
return|;
block|}
specifier|inline
specifier|const
name|char
operator|*
name|readPointer
argument_list|()
specifier|const
block|{
return|return
name|buffers
operator|.
name|isEmpty
argument_list|()
operator|?
literal|0
operator|:
operator|(
name|buffers
operator|.
name|first
argument_list|()
operator|.
name|constData
argument_list|()
operator|+
name|head
operator|)
return|;
block|}
comment|// access the bytes at a specified position
comment|// the out-variable length will contain the amount of bytes readable
comment|// from there, e.g. the amount still the same QByteArray
specifier|inline
specifier|const
name|char
modifier|*
name|readPointerAtPosition
argument_list|(
name|qint64
name|pos
argument_list|,
name|qint64
operator|&
name|length
argument_list|)
decl|const
block|{
if|if
condition|(
name|buffers
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|length
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|pos
operator|>=
name|bufferSize
condition|)
block|{
name|length
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|// special case: it is in the first buffer
name|int
name|nextDataBlockSizeValue
init|=
name|nextDataBlockSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|pos
operator|-
name|head
operator|<
name|nextDataBlockSizeValue
condition|)
block|{
name|length
operator|=
name|nextDataBlockSizeValue
operator|-
name|pos
expr_stmt|;
return|return
name|buffers
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|constData
argument_list|()
operator|+
name|head
operator|+
name|pos
return|;
block|}
comment|// special case: we only had one buffer and tried to read over it
if|if
condition|(
name|buffers
operator|.
name|length
argument_list|()
operator|==
literal|1
condition|)
block|{
name|length
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|// skip the first
name|pos
operator|-=
name|nextDataBlockSizeValue
expr_stmt|;
comment|// normal case: it is somewhere in the second to the-one-before-the-tailBuffer
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|tailBuffer
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|pos
operator|>=
name|buffers
index|[
name|i
index|]
operator|.
name|size
argument_list|()
condition|)
block|{
name|pos
operator|-=
name|buffers
index|[
name|i
index|]
operator|.
name|size
argument_list|()
expr_stmt|;
continue|continue;
block|}
name|length
operator|=
name|buffers
index|[
name|i
index|]
operator|.
name|length
argument_list|()
operator|-
name|pos
expr_stmt|;
return|return
name|buffers
index|[
name|i
index|]
operator|.
name|constData
argument_list|()
operator|+
name|pos
return|;
block|}
comment|// it is in the tail buffer
name|length
operator|=
name|tail
operator|-
name|pos
expr_stmt|;
return|return
name|buffers
index|[
name|tailBuffer
index|]
operator|.
name|constData
argument_list|()
operator|+
name|pos
return|;
block|}
specifier|inline
name|void
name|free
parameter_list|(
name|int
name|bytes
parameter_list|)
block|{
name|bufferSize
operator|-=
name|bytes
expr_stmt|;
if|if
condition|(
name|bufferSize
operator|<
literal|0
condition|)
name|bufferSize
operator|=
literal|0
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|int
name|nextBlockSize
init|=
name|nextDataBlockSize
argument_list|()
decl_stmt|;
if|if
condition|(
name|bytes
operator|<
name|nextBlockSize
condition|)
block|{
name|head
operator|+=
name|bytes
expr_stmt|;
if|if
condition|(
name|head
operator|==
name|tail
operator|&&
name|tailBuffer
operator|==
literal|0
condition|)
name|head
operator|=
name|tail
operator|=
literal|0
expr_stmt|;
break|break;
block|}
name|bytes
operator|-=
name|nextBlockSize
expr_stmt|;
if|if
condition|(
name|buffers
operator|.
name|count
argument_list|()
operator|==
literal|1
condition|)
block|{
if|if
condition|(
name|buffers
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|size
argument_list|()
operator|!=
name|basicBlockSize
condition|)
name|buffers
index|[
literal|0
index|]
operator|.
name|resize
argument_list|(
name|basicBlockSize
argument_list|)
expr_stmt|;
name|head
operator|=
name|tail
operator|=
literal|0
expr_stmt|;
name|tailBuffer
operator|=
literal|0
expr_stmt|;
break|break;
block|}
name|buffers
operator|.
name|removeAt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
operator|--
name|tailBuffer
expr_stmt|;
name|head
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|isEmpty
argument_list|()
condition|)
name|clear
argument_list|()
expr_stmt|;
comment|// try to minify/squeeze us
block|}
specifier|inline
name|char
modifier|*
name|reserve
parameter_list|(
name|int
name|bytes
parameter_list|)
block|{
comment|// if this is a fresh empty QRingBuffer
if|if
condition|(
name|bufferSize
operator|==
literal|0
condition|)
block|{
name|buffers
index|[
literal|0
index|]
operator|.
name|resize
argument_list|(
name|qMax
argument_list|(
name|basicBlockSize
argument_list|,
name|bytes
argument_list|)
argument_list|)
expr_stmt|;
name|bufferSize
operator|+=
name|bytes
expr_stmt|;
name|tail
operator|=
name|bytes
expr_stmt|;
return|return
name|buffers
index|[
name|tailBuffer
index|]
operator|.
name|data
argument_list|()
return|;
block|}
name|bufferSize
operator|+=
name|bytes
expr_stmt|;
comment|// if there is already enough space, simply return.
if|if
condition|(
name|tail
operator|+
name|bytes
operator|<=
name|buffers
operator|.
name|at
argument_list|(
name|tailBuffer
argument_list|)
operator|.
name|size
argument_list|()
condition|)
block|{
name|char
modifier|*
name|writePtr
init|=
name|buffers
index|[
name|tailBuffer
index|]
operator|.
name|data
argument_list|()
operator|+
name|tail
decl_stmt|;
name|tail
operator|+=
name|bytes
expr_stmt|;
return|return
name|writePtr
return|;
block|}
comment|// if our buffer isn't half full yet, simply resize it.
if|if
condition|(
name|tail
operator|<
name|buffers
operator|.
name|at
argument_list|(
name|tailBuffer
argument_list|)
operator|.
name|size
argument_list|()
operator|/
literal|2
condition|)
block|{
name|buffers
index|[
name|tailBuffer
index|]
operator|.
name|resize
argument_list|(
name|tail
operator|+
name|bytes
argument_list|)
expr_stmt|;
name|char
modifier|*
name|writePtr
init|=
name|buffers
index|[
name|tailBuffer
index|]
operator|.
name|data
argument_list|()
operator|+
name|tail
decl_stmt|;
name|tail
operator|+=
name|bytes
expr_stmt|;
return|return
name|writePtr
return|;
block|}
comment|// shrink this buffer to its current size
name|buffers
index|[
name|tailBuffer
index|]
operator|.
name|resize
argument_list|(
name|tail
argument_list|)
expr_stmt|;
comment|// create a new QByteArray with the right size
name|buffers
operator|<<
name|QByteArray
argument_list|()
expr_stmt|;
operator|++
name|tailBuffer
expr_stmt|;
name|buffers
index|[
name|tailBuffer
index|]
operator|.
name|resize
argument_list|(
name|qMax
argument_list|(
name|basicBlockSize
argument_list|,
name|bytes
argument_list|)
argument_list|)
expr_stmt|;
name|tail
operator|=
name|bytes
expr_stmt|;
return|return
name|buffers
index|[
name|tailBuffer
index|]
operator|.
name|data
argument_list|()
return|;
block|}
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
name|chop
argument_list|(
name|size
argument_list|()
operator|-
name|pos
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|chop
parameter_list|(
name|int
name|bytes
parameter_list|)
block|{
name|bufferSize
operator|-=
name|bytes
expr_stmt|;
if|if
condition|(
name|bufferSize
operator|<
literal|0
condition|)
name|bufferSize
operator|=
literal|0
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
comment|// special case: head and tail are in the same buffer
if|if
condition|(
name|tailBuffer
operator|==
literal|0
condition|)
block|{
name|tail
operator|-=
name|bytes
expr_stmt|;
if|if
condition|(
name|tail
operator|<=
name|head
condition|)
name|tail
operator|=
name|head
operator|=
literal|0
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|bytes
operator|<=
name|tail
condition|)
block|{
name|tail
operator|-=
name|bytes
expr_stmt|;
return|return;
block|}
name|bytes
operator|-=
name|tail
expr_stmt|;
name|buffers
operator|.
name|removeAt
argument_list|(
name|tailBuffer
argument_list|)
expr_stmt|;
operator|--
name|tailBuffer
expr_stmt|;
name|tail
operator|=
name|buffers
operator|.
name|at
argument_list|(
name|tailBuffer
argument_list|)
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|isEmpty
argument_list|()
condition|)
name|clear
argument_list|()
expr_stmt|;
comment|// try to minify/squeeze us
block|}
specifier|inline
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|tailBuffer
operator|==
literal|0
operator|&&
name|tail
operator|==
literal|0
return|;
block|}
specifier|inline
name|int
name|getChar
parameter_list|()
block|{
if|if
condition|(
name|isEmpty
argument_list|()
condition|)
return|return
operator|-
literal|1
return|;
name|char
name|c
init|=
operator|*
name|readPointer
argument_list|()
decl_stmt|;
name|free
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
name|int
argument_list|(
name|uchar
argument_list|(
name|c
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|void
name|putChar
parameter_list|(
name|char
name|c
parameter_list|)
block|{
name|char
modifier|*
name|ptr
init|=
name|reserve
argument_list|(
literal|1
argument_list|)
decl_stmt|;
operator|*
name|ptr
operator|=
name|c
expr_stmt|;
block|}
specifier|inline
name|void
name|ungetChar
parameter_list|(
name|char
name|c
parameter_list|)
block|{
operator|--
name|head
expr_stmt|;
if|if
condition|(
name|head
operator|<
literal|0
condition|)
block|{
name|buffers
operator|.
name|prepend
argument_list|(
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
name|buffers
index|[
literal|0
index|]
operator|.
name|resize
argument_list|(
name|basicBlockSize
argument_list|)
expr_stmt|;
name|head
operator|=
name|basicBlockSize
operator|-
literal|1
expr_stmt|;
operator|++
name|tailBuffer
expr_stmt|;
block|}
name|buffers
index|[
literal|0
index|]
index|[
name|head
index|]
operator|=
name|c
expr_stmt|;
operator|++
name|bufferSize
expr_stmt|;
block|}
specifier|inline
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|bufferSize
return|;
block|}
specifier|inline
name|void
name|clear
parameter_list|()
block|{
name|buffers
operator|.
name|erase
argument_list|(
name|buffers
operator|.
name|begin
argument_list|()
operator|+
literal|1
argument_list|,
name|buffers
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|buffers
index|[
literal|0
index|]
operator|.
name|resize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|buffers
index|[
literal|0
index|]
operator|.
name|squeeze
argument_list|()
expr_stmt|;
name|head
operator|=
name|tail
operator|=
literal|0
expr_stmt|;
name|tailBuffer
operator|=
literal|0
expr_stmt|;
name|bufferSize
operator|=
literal|0
expr_stmt|;
block|}
specifier|inline
name|int
name|indexOf
argument_list|(
name|char
name|c
argument_list|)
decl|const
block|{
name|int
name|index
init|=
literal|0
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
name|buffers
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|start
init|=
literal|0
decl_stmt|;
name|int
name|end
init|=
name|buffers
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|start
operator|=
name|head
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|tailBuffer
condition|)
name|end
operator|=
name|tail
expr_stmt|;
specifier|const
name|char
modifier|*
name|ptr
init|=
name|buffers
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|data
argument_list|()
operator|+
name|start
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
name|start
init|;
name|j
operator|<
name|end
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
operator|*
name|ptr
operator|++
operator|==
name|c
condition|)
return|return
name|index
return|;
operator|++
name|index
expr_stmt|;
block|}
block|}
return|return
operator|-
literal|1
return|;
block|}
specifier|inline
name|int
name|indexOf
argument_list|(
name|char
name|c
argument_list|,
name|int
name|maxLength
argument_list|)
decl|const
block|{
name|int
name|index
init|=
literal|0
decl_stmt|;
name|int
name|remain
init|=
name|qMin
argument_list|(
name|size
argument_list|()
argument_list|,
name|maxLength
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|remain
operator|&&
name|i
operator|<
name|buffers
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|start
init|=
literal|0
decl_stmt|;
name|int
name|end
init|=
name|buffers
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|start
operator|=
name|head
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|tailBuffer
condition|)
name|end
operator|=
name|tail
expr_stmt|;
if|if
condition|(
name|remain
operator|<
name|end
operator|-
name|start
condition|)
block|{
name|end
operator|=
name|start
operator|+
name|remain
expr_stmt|;
name|remain
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|remain
operator|-=
name|end
operator|-
name|start
expr_stmt|;
block|}
specifier|const
name|char
modifier|*
name|ptr
init|=
name|buffers
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|data
argument_list|()
operator|+
name|start
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
name|start
init|;
name|j
operator|<
name|end
condition|;
operator|++
name|j
control|)
block|{
if|if
condition|(
operator|*
name|ptr
operator|++
operator|==
name|c
condition|)
return|return
name|index
return|;
operator|++
name|index
expr_stmt|;
block|}
block|}
return|return
operator|-
literal|1
return|;
block|}
specifier|inline
name|int
name|read
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|int
name|maxLength
parameter_list|)
block|{
name|int
name|bytesToRead
init|=
name|qMin
argument_list|(
name|size
argument_list|()
argument_list|,
name|maxLength
argument_list|)
decl_stmt|;
name|int
name|readSoFar
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|readSoFar
operator|<
name|bytesToRead
condition|)
block|{
specifier|const
name|char
modifier|*
name|ptr
init|=
name|readPointer
argument_list|()
decl_stmt|;
name|int
name|bytesToReadFromThisBlock
init|=
name|qMin
argument_list|(
name|bytesToRead
operator|-
name|readSoFar
argument_list|,
name|nextDataBlockSize
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|data
condition|)
name|memcpy
argument_list|(
name|data
operator|+
name|readSoFar
argument_list|,
name|ptr
argument_list|,
name|bytesToReadFromThisBlock
argument_list|)
expr_stmt|;
name|readSoFar
operator|+=
name|bytesToReadFromThisBlock
expr_stmt|;
name|free
argument_list|(
name|bytesToReadFromThisBlock
argument_list|)
expr_stmt|;
block|}
return|return
name|readSoFar
return|;
block|}
specifier|inline
name|QByteArray
name|read
parameter_list|(
name|int
name|maxLength
parameter_list|)
block|{
name|QByteArray
name|tmp
decl_stmt|;
name|tmp
operator|.
name|resize
argument_list|(
name|qMin
argument_list|(
name|maxLength
argument_list|,
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|read
argument_list|(
name|tmp
operator|.
name|data
argument_list|()
argument_list|,
name|tmp
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|tmp
return|;
block|}
specifier|inline
name|QByteArray
name|readAll
parameter_list|()
block|{
return|return
name|read
argument_list|(
name|size
argument_list|()
argument_list|)
return|;
block|}
comment|// read an unspecified amount (will read the first buffer)
specifier|inline
name|QByteArray
name|read
parameter_list|()
block|{
if|if
condition|(
name|bufferSize
operator|==
literal|0
condition|)
return|return
name|QByteArray
argument_list|()
return|;
comment|// multiple buffers, just take the first one
if|if
condition|(
name|head
operator|==
literal|0
operator|&&
name|tailBuffer
operator|!=
literal|0
condition|)
block|{
name|QByteArray
name|qba
init|=
name|buffers
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
operator|--
name|tailBuffer
expr_stmt|;
name|bufferSize
operator|-=
name|qba
operator|.
name|length
argument_list|()
expr_stmt|;
return|return
name|qba
return|;
block|}
comment|// one buffer with good value for head. Just take it.
if|if
condition|(
name|head
operator|==
literal|0
operator|&&
name|tailBuffer
operator|==
literal|0
condition|)
block|{
name|QByteArray
name|qba
init|=
name|buffers
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|qba
operator|.
name|resize
argument_list|(
name|tail
argument_list|)
expr_stmt|;
name|buffers
operator|<<
name|QByteArray
argument_list|()
expr_stmt|;
name|bufferSize
operator|=
literal|0
expr_stmt|;
name|tail
operator|=
literal|0
expr_stmt|;
return|return
name|qba
return|;
block|}
comment|// Bad case: We have to memcpy.
comment|// We can avoid by initializing the QRingBuffer with basicBlockSize of 0
comment|// and only using this read() function.
name|QByteArray
name|qba
argument_list|(
name|readPointer
argument_list|()
argument_list|,
name|nextDataBlockSize
argument_list|()
argument_list|)
decl_stmt|;
name|buffers
operator|.
name|removeFirst
argument_list|()
expr_stmt|;
name|head
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|tailBuffer
operator|==
literal|0
condition|)
block|{
name|buffers
operator|<<
name|QByteArray
argument_list|()
expr_stmt|;
name|tail
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
operator|--
name|tailBuffer
expr_stmt|;
block|}
name|bufferSize
operator|-=
name|qba
operator|.
name|length
argument_list|()
expr_stmt|;
return|return
name|qba
return|;
block|}
comment|// append a new buffer to the end
specifier|inline
name|void
name|append
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|qba
parameter_list|)
block|{
name|buffers
index|[
name|tailBuffer
index|]
operator|.
name|resize
argument_list|(
name|tail
argument_list|)
expr_stmt|;
name|buffers
operator|<<
name|qba
expr_stmt|;
operator|++
name|tailBuffer
expr_stmt|;
name|tail
operator|=
name|qba
operator|.
name|length
argument_list|()
expr_stmt|;
name|bufferSize
operator|+=
name|qba
operator|.
name|length
argument_list|()
expr_stmt|;
block|}
specifier|inline
name|QByteArray
name|peek
argument_list|(
name|int
name|maxLength
argument_list|)
decl|const
block|{
name|int
name|bytesToRead
init|=
name|qMin
argument_list|(
name|size
argument_list|()
argument_list|,
name|maxLength
argument_list|)
decl_stmt|;
if|if
condition|(
name|maxLength
operator|<=
literal|0
condition|)
return|return
name|QByteArray
argument_list|()
return|;
name|QByteArray
name|ret
decl_stmt|;
name|ret
operator|.
name|resize
argument_list|(
name|bytesToRead
argument_list|)
expr_stmt|;
name|int
name|readSoFar
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|readSoFar
operator|<
name|bytesToRead
operator|&&
name|i
operator|<
name|buffers
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|start
init|=
literal|0
decl_stmt|;
name|int
name|end
init|=
name|buffers
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|size
argument_list|()
decl_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|start
operator|=
name|head
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|tailBuffer
condition|)
name|end
operator|=
name|tail
expr_stmt|;
specifier|const
name|int
name|len
init|=
name|qMin
argument_list|(
name|ret
operator|.
name|size
argument_list|()
operator|-
name|readSoFar
argument_list|,
name|end
operator|-
name|start
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|ret
operator|.
name|data
argument_list|()
operator|+
name|readSoFar
argument_list|,
name|buffers
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|constData
argument_list|()
operator|+
name|start
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|readSoFar
operator|+=
name|len
expr_stmt|;
block|}
name|Q_ASSERT
argument_list|(
name|readSoFar
operator|==
name|ret
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
specifier|inline
name|int
name|skip
parameter_list|(
name|int
name|length
parameter_list|)
block|{
return|return
name|read
argument_list|(
literal|0
argument_list|,
name|length
argument_list|)
return|;
block|}
specifier|inline
name|int
name|readLine
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|int
name|maxLength
parameter_list|)
block|{
name|int
name|index
init|=
name|indexOf
argument_list|(
literal|'\n'
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|==
operator|-
literal|1
condition|)
return|return
name|read
argument_list|(
name|data
argument_list|,
name|maxLength
argument_list|)
return|;
if|if
condition|(
name|maxLength
operator|<=
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|int
name|readSoFar
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|readSoFar
operator|<
name|index
operator|+
literal|1
operator|&&
name|readSoFar
operator|<
name|maxLength
operator|-
literal|1
condition|)
block|{
name|int
name|bytesToRead
init|=
name|qMin
argument_list|(
operator|(
name|index
operator|+
literal|1
operator|)
operator|-
name|readSoFar
argument_list|,
name|nextDataBlockSize
argument_list|()
argument_list|)
decl_stmt|;
name|bytesToRead
operator|=
name|qMin
argument_list|(
name|bytesToRead
argument_list|,
operator|(
name|maxLength
operator|-
literal|1
operator|)
operator|-
name|readSoFar
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|data
operator|+
name|readSoFar
argument_list|,
name|readPointer
argument_list|()
argument_list|,
name|bytesToRead
argument_list|)
expr_stmt|;
name|readSoFar
operator|+=
name|bytesToRead
expr_stmt|;
name|free
argument_list|(
name|bytesToRead
argument_list|)
expr_stmt|;
block|}
comment|// Terminate it.
name|data
index|[
name|readSoFar
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|readSoFar
return|;
block|}
specifier|inline
name|bool
name|canReadLine
argument_list|()
specifier|const
block|{
return|return
name|indexOf
argument_list|(
literal|'\n'
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
name|private
label|:
name|QList
operator|<
name|QByteArray
operator|>
name|buffers
expr_stmt|;
name|int
name|head
decl_stmt|,
name|tail
decl_stmt|;
name|int
name|tailBuffer
decl_stmt|;
comment|// always buffers.size() - 1
name|int
name|basicBlockSize
decl_stmt|;
name|int
name|bufferSize
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
begin_comment
comment|// QRINGBUFFER_P_H
end_comment
end_unit
