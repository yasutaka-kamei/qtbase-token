begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Ivan Komissarov ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"storagemodel.h"
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|<cmath>
end_include
begin_function
DECL|function|sizeToString
specifier|static
name|QString
name|sizeToString
parameter_list|(
name|qint64
name|size
parameter_list|)
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|strings
index|[]
init|=
block|{
literal|"b"
block|,
literal|"kB"
block|,
literal|"MB"
block|,
literal|"GB"
block|,
literal|"TB"
block|,
literal|"PB"
block|,
literal|"EB"
block|,
literal|"ZB"
block|,
literal|"YB"
block|}
decl_stmt|;
if|if
condition|(
name|size
operator|<=
literal|0
condition|)
return|return
name|StorageModel
operator|::
name|tr
argument_list|(
literal|"0 b"
argument_list|)
return|;
name|double
name|power
init|=
name|std
operator|::
name|log
argument_list|(
operator|(
name|double
operator|)
name|size
argument_list|)
operator|/
name|std
operator|::
name|log
argument_list|(
literal|1024.0
argument_list|)
decl_stmt|;
name|int
name|intPower
init|=
operator|(
name|int
operator|)
name|power
decl_stmt|;
name|intPower
operator|=
name|intPower
operator|>=
literal|8
condition|?
literal|8
operator|-
literal|1
else|:
name|intPower
expr_stmt|;
name|double
name|normSize
init|=
name|size
operator|/
name|std
operator|::
name|pow
argument_list|(
literal|1024.0
argument_list|,
name|intPower
argument_list|)
decl_stmt|;
comment|//: this should expand to "1.23 GB"
return|return
name|StorageModel
operator|::
name|tr
argument_list|(
literal|"%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|normSize
argument_list|,
literal|0
argument_list|,
literal|'f'
argument_list|,
name|intPower
operator|>
literal|0
condition|?
literal|2
else|:
literal|0
argument_list|)
operator|.
name|arg
argument_list|(
name|strings
index|[
name|intPower
index|]
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|StorageModel
name|StorageModel
operator|::
name|StorageModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractTableModel
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_volumes
argument_list|(
name|QStorageInfo
operator|::
name|mountedVolumes
argument_list|()
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|columnCount
name|int
name|StorageModel
operator|::
name|columnCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
comment|/*parent*/
parameter_list|)
specifier|const
block|{
return|return
name|ColumnCount
return|;
block|}
end_function
begin_function
DECL|function|rowCount
name|int
name|StorageModel
operator|::
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|parent
operator|.
name|isValid
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|m_volumes
operator|.
name|count
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|data
name|QVariant
name|StorageModel
operator|::
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|index
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
condition|)
block|{
specifier|const
name|QStorageInfo
modifier|&
name|volume
init|=
name|m_volumes
operator|.
name|at
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|index
operator|.
name|column
argument_list|()
condition|)
block|{
case|case
name|ColumnRootPath
case|:
return|return
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|volume
operator|.
name|rootPath
argument_list|()
argument_list|)
return|;
case|case
name|ColumnName
case|:
return|return
name|volume
operator|.
name|name
argument_list|()
return|;
case|case
name|ColumnDevice
case|:
return|return
name|volume
operator|.
name|device
argument_list|()
return|;
case|case
name|ColumnFileSystemName
case|:
return|return
name|volume
operator|.
name|fileSystemType
argument_list|()
return|;
case|case
name|ColumnTotal
case|:
return|return
name|sizeToString
argument_list|(
name|volume
operator|.
name|bytesTotal
argument_list|()
argument_list|)
return|;
case|case
name|ColumnFree
case|:
return|return
name|sizeToString
argument_list|(
name|volume
operator|.
name|bytesFree
argument_list|()
argument_list|)
return|;
case|case
name|ColumnAvailable
case|:
return|return
name|sizeToString
argument_list|(
name|volume
operator|.
name|bytesAvailable
argument_list|()
argument_list|)
return|;
case|case
name|ColumnIsReady
case|:
return|return
name|volume
operator|.
name|isReady
argument_list|()
return|;
case|case
name|ColumnIsReadOnly
case|:
return|return
name|volume
operator|.
name|isReadOnly
argument_list|()
return|;
case|case
name|ColumnIsValid
case|:
return|return
name|volume
operator|.
name|isValid
argument_list|()
return|;
default|default:
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|ToolTipRole
condition|)
block|{
specifier|const
name|QStorageInfo
modifier|&
name|volume
init|=
name|m_volumes
operator|.
name|at
argument_list|(
name|index
operator|.
name|row
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|tr
argument_list|(
literal|"Root path : %1\n"
literal|"Name: %2\n"
literal|"Display Name: %3\n"
literal|"Device: %4\n"
literal|"FileSystem: %5\n"
literal|"Total size: %6\n"
literal|"Free size: %7\n"
literal|"Available size: %8\n"
literal|"Is Ready: %9\n"
literal|"Is Read-only: %10\n"
literal|"Is Valid: %11\n"
literal|"Is Root: %12"
argument_list|)
operator|.
name|arg
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|volume
operator|.
name|rootPath
argument_list|()
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|volume
operator|.
name|name
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|volume
operator|.
name|displayName
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|volume
operator|.
name|device
argument_list|()
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|volume
operator|.
name|fileSystemType
argument_list|()
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|sizeToString
argument_list|(
name|volume
operator|.
name|bytesTotal
argument_list|()
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|sizeToString
argument_list|(
name|volume
operator|.
name|bytesFree
argument_list|()
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|sizeToString
argument_list|(
name|volume
operator|.
name|bytesAvailable
argument_list|()
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|volume
operator|.
name|isReady
argument_list|()
condition|?
name|tr
argument_list|(
literal|"true"
argument_list|)
else|:
name|tr
argument_list|(
literal|"false"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|volume
operator|.
name|isReadOnly
argument_list|()
condition|?
name|tr
argument_list|(
literal|"true"
argument_list|)
else|:
name|tr
argument_list|(
literal|"false"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|volume
operator|.
name|isValid
argument_list|()
condition|?
name|tr
argument_list|(
literal|"true"
argument_list|)
else|:
name|tr
argument_list|(
literal|"false"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|volume
operator|.
name|isRoot
argument_list|()
condition|?
name|tr
argument_list|(
literal|"true"
argument_list|)
else|:
name|tr
argument_list|(
literal|"false"
argument_list|)
argument_list|)
return|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|headerData
name|QVariant
name|StorageModel
operator|::
name|headerData
parameter_list|(
name|int
name|section
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|orientation
operator|!=
name|Qt
operator|::
name|Horizontal
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|role
operator|!=
name|Qt
operator|::
name|DisplayRole
condition|)
return|return
name|QVariant
argument_list|()
return|;
switch|switch
condition|(
name|section
condition|)
block|{
case|case
name|ColumnRootPath
case|:
return|return
name|tr
argument_list|(
literal|"Root path"
argument_list|)
return|;
case|case
name|ColumnName
case|:
return|return
name|tr
argument_list|(
literal|"Volume Name"
argument_list|)
return|;
case|case
name|ColumnDevice
case|:
return|return
name|tr
argument_list|(
literal|"Device"
argument_list|)
return|;
case|case
name|ColumnFileSystemName
case|:
return|return
name|tr
argument_list|(
literal|"File system"
argument_list|)
return|;
case|case
name|ColumnTotal
case|:
return|return
name|tr
argument_list|(
literal|"Total"
argument_list|)
return|;
case|case
name|ColumnFree
case|:
return|return
name|tr
argument_list|(
literal|"Free"
argument_list|)
return|;
case|case
name|ColumnAvailable
case|:
return|return
name|tr
argument_list|(
literal|"Available"
argument_list|)
return|;
case|case
name|ColumnIsReady
case|:
return|return
name|tr
argument_list|(
literal|"Ready"
argument_list|)
return|;
case|case
name|ColumnIsReadOnly
case|:
return|return
name|tr
argument_list|(
literal|"Read-only"
argument_list|)
return|;
case|case
name|ColumnIsValid
case|:
return|return
name|tr
argument_list|(
literal|"Valid"
argument_list|)
return|;
default|default:
break|break;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
end_unit
