begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32_WCE
end_ifdef
begin_comment
comment|//Q_OS_WINCE
end_comment
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_include
include|#
directive|include
file|<winbase.h>
end_include
begin_include
include|#
directive|include
file|<kfuncs.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_if
if|#
directive|if
name|_WIN32_WCE
operator|<
literal|0x800
end_if
begin_include
include|#
directive|include
file|<altcecrt.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qfunctions_wince.h"
end_include
begin_include
include|#
directive|include
file|"qfunctions_fake_env_p.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_expr_stmt
name|QT_USE_NAMESPACE
ifdef|#
directive|ifdef
name|__cplusplus
specifier|extern
literal|"C"
block|{
endif|#
directive|endif
DECL|function|CEPrivConvCharToWide
name|wchar_t
operator|*
name|CEPrivConvCharToWide
argument_list|(
argument|const char* string
argument_list|)
block|{
name|size_t
name|length
operator|=
name|strlen
argument_list|(
name|string
argument_list|)
block|;
name|wchar_t
operator|*
name|wString
operator|=
operator|new
name|wchar_t
index|[
name|length
operator|+
literal|1
index|]
block|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
operator|(
name|length
operator|+
literal|1
operator|)
condition|;
name|i
operator|++
control|)
name|wString
index|[
name|i
index|]
operator|=
name|string
index|[
name|i
index|]
expr_stmt|;
return|return
name|wString
return|;
block|}
end_expr_stmt
begin_comment
comment|// Time -------------------------------------------------------------
end_comment
begin_function
DECL|function|qt_wince_ftToTime_t
name|time_t
name|qt_wince_ftToTime_t
parameter_list|(
specifier|const
name|FILETIME
name|ft
parameter_list|)
block|{
name|ULARGE_INTEGER
name|li
decl_stmt|;
name|li
operator|.
name|LowPart
operator|=
name|ft
operator|.
name|dwLowDateTime
expr_stmt|;
name|li
operator|.
name|HighPart
operator|=
name|ft
operator|.
name|dwHighDateTime
expr_stmt|;
comment|// 100-nanosec to seconds
name|li
operator|.
name|QuadPart
operator|/=
literal|10000000
expr_stmt|;
comment|// FILETIME is from 1601-01-01 T 00:00:00
comment|// time_t   is from 1970-01-01 T 00:00:00
comment|// 1970 - 1601 = 369 year (89 leap years)
comment|//
comment|// ((369y*365d) + 89d) *24h *60min *60sec
comment|// = 11644473600 seconds
name|li
operator|.
name|QuadPart
operator|-=
literal|11644473600
expr_stmt|;
return|return
name|li
operator|.
name|LowPart
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_time_tToFt
name|FILETIME
name|qt_wince_time_tToFt
parameter_list|(
name|time_t
name|tt
parameter_list|)
block|{
name|ULARGE_INTEGER
name|li
decl_stmt|;
name|li
operator|.
name|QuadPart
operator|=
name|tt
expr_stmt|;
name|li
operator|.
name|QuadPart
operator|+=
literal|11644473600
expr_stmt|;
name|li
operator|.
name|QuadPart
operator|*=
literal|10000000
expr_stmt|;
name|FILETIME
name|ft
decl_stmt|;
name|ft
operator|.
name|dwLowDateTime
operator|=
name|li
operator|.
name|LowPart
expr_stmt|;
name|ft
operator|.
name|dwHighDateTime
operator|=
name|li
operator|.
name|HighPart
expr_stmt|;
return|return
name|ft
return|;
block|}
end_function
begin_comment
comment|// File I/O ---------------------------------------------------------
end_comment
begin_if
if|#
directive|if
name|_WIN32_WCE
operator|<
literal|0x800
end_if
begin_decl_stmt
DECL|variable|errno
name|int
name|errno
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|qt_wince__getdrive
name|int
name|qt_wince__getdrive
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__waccess
name|int
name|qt_wince__waccess
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|path
parameter_list|,
name|int
name|pmode
parameter_list|)
block|{
name|DWORD
name|res
init|=
name|GetFileAttributes
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
literal|0xFFFFFFFF
operator|==
name|res
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
operator|(
name|pmode
operator|&
name|W_OK
operator|)
operator|&&
operator|(
name|res
operator|&
name|FILE_ATTRIBUTE_READONLY
operator|)
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
operator|(
name|pmode
operator|&
name|X_OK
operator|)
operator|&&
operator|!
operator|(
name|res
operator|&
name|FILE_ATTRIBUTE_DIRECTORY
operator|)
condition|)
block|{
name|QString
name|file
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|file
operator|.
name|endsWith
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|".exe"
argument_list|)
argument_list|)
operator|||
name|file
operator|.
name|endsWith
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|".com"
argument_list|)
argument_list|)
operator|)
condition|)
return|return
operator|-
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_open
name|int
name|qt_wince_open
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|oflag
parameter_list|,
name|int
name|pmode
parameter_list|)
block|{
name|QString
name|fn
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|filename
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|_wopen
argument_list|(
operator|(
name|wchar_t
operator|*
operator|)
name|fn
operator|.
name|utf16
argument_list|()
argument_list|,
name|oflag
argument_list|,
name|pmode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__wopen
name|int
name|qt_wince__wopen
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|filename
parameter_list|,
name|int
name|oflag
parameter_list|,
name|int
comment|/*pmode*/
parameter_list|)
block|{
name|wchar_t
modifier|*
name|flag
decl_stmt|;
if|if
condition|(
name|oflag
operator|&
name|_O_APPEND
condition|)
block|{
if|if
condition|(
name|oflag
operator|&
name|_O_WRONLY
condition|)
block|{
name|flag
operator|=
literal|L"a"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|oflag
operator|&
name|_O_RDWR
condition|)
block|{
name|flag
operator|=
literal|L"a+"
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|oflag
operator|&
name|_O_BINARY
condition|)
block|{
if|if
condition|(
name|oflag
operator|&
name|_O_WRONLY
condition|)
block|{
name|flag
operator|=
literal|L"wb"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|oflag
operator|&
name|_O_RDWR
condition|)
block|{
name|flag
operator|=
literal|L"w+b"
expr_stmt|;
comment|// slightly different from "r+" where the file must exist
block|}
elseif|else
if|if
condition|(
name|oflag
operator|&
name|_O_RDONLY
condition|)
block|{
name|flag
operator|=
literal|L"rb"
expr_stmt|;
block|}
else|else
block|{
name|flag
operator|=
literal|L"b"
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|oflag
operator|&
name|_O_WRONLY
condition|)
block|{
name|flag
operator|=
literal|L"wt"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|oflag
operator|&
name|_O_RDWR
condition|)
block|{
name|flag
operator|=
literal|L"w+t"
expr_stmt|;
comment|// slightly different from "r+" where the file must exist
block|}
elseif|else
if|if
condition|(
name|oflag
operator|&
name|_O_RDONLY
condition|)
block|{
name|flag
operator|=
literal|L"rt"
expr_stmt|;
block|}
else|else
block|{
name|flag
operator|=
literal|L"t"
expr_stmt|;
block|}
block|}
name|int
name|retval
init|=
operator|(
name|int
operator|)
name|_wfopen
argument_list|(
name|filename
argument_list|,
name|flag
argument_list|)
decl_stmt|;
return|return
operator|(
name|retval
operator|==
name|NULL
operator|)
condition|?
operator|-
literal|1
else|:
name|retval
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__lseek
name|long
name|qt_wince__lseek
parameter_list|(
name|int
name|handle
parameter_list|,
name|long
name|offset
parameter_list|,
name|int
name|origin
parameter_list|)
block|{
return|return
name|fseek
argument_list|(
operator|(
name|FILE
operator|*
operator|)
name|handle
argument_list|,
name|offset
argument_list|,
name|origin
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__read
name|int
name|qt_wince__read
parameter_list|(
name|int
name|handle
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
block|{
return|return
name|fread
argument_list|(
name|buffer
argument_list|,
literal|1
argument_list|,
name|count
argument_list|,
operator|(
name|FILE
operator|*
operator|)
name|handle
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__write
name|int
name|qt_wince__write
parameter_list|(
name|int
name|handle
parameter_list|,
specifier|const
name|void
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
block|{
return|return
name|fwrite
argument_list|(
name|buffer
argument_list|,
literal|1
argument_list|,
name|count
argument_list|,
operator|(
name|FILE
operator|*
operator|)
name|handle
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__close
name|int
name|qt_wince__close
parameter_list|(
name|int
name|handle
parameter_list|)
block|{
if|if
condition|(
operator|!
name|handle
condition|)
return|return
literal|0
return|;
return|return
name|fclose
argument_list|(
operator|(
name|FILE
operator|*
operator|)
name|handle
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__fdopen
name|FILE
modifier|*
name|qt_wince__fdopen
parameter_list|(
name|int
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
comment|/*mode*/
parameter_list|)
block|{
return|return
operator|(
name|FILE
operator|*
operator|)
name|handle
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_fdopen
name|FILE
modifier|*
name|qt_wince_fdopen
parameter_list|(
name|int
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
comment|/*mode*/
parameter_list|)
block|{
return|return
operator|(
name|FILE
operator|*
operator|)
name|handle
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_rewind
name|void
name|qt_wince_rewind
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|)
block|{
name|fseek
argument_list|(
name|stream
argument_list|,
literal|0L
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_wince___fileno
name|int
name|qt_wince___fileno
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|)
block|{
return|return
operator|(
name|int
operator|)
name|_fileno
argument_list|(
name|f
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_tmpfile
name|FILE
modifier|*
name|qt_wince_tmpfile
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|long
name|i
init|=
literal|0
decl_stmt|;
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"tmp%i"
argument_list|,
name|i
operator|++
argument_list|)
expr_stmt|;
return|return
name|fopen
argument_list|(
name|name
argument_list|,
literal|"r+"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__mkdir
name|int
name|qt_wince__mkdir
parameter_list|(
specifier|const
name|char
modifier|*
name|dirname
parameter_list|)
block|{
return|return
name|CreateDirectory
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|QString
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|dirname
argument_list|)
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|)
condition|?
literal|0
else|:
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__rmdir
name|int
name|qt_wince__rmdir
parameter_list|(
specifier|const
name|char
modifier|*
name|dirname
parameter_list|)
block|{
return|return
name|RemoveDirectory
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|dirname
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|)
condition|?
literal|0
else|:
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__access
name|int
name|qt_wince__access
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|int
name|pmode
parameter_list|)
block|{
return|return
name|_waccess
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|path
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|pmode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__rename
name|int
name|qt_wince__rename
parameter_list|(
specifier|const
name|char
modifier|*
name|oldname
parameter_list|,
specifier|const
name|char
modifier|*
name|newname
parameter_list|)
block|{
return|return
operator|!
name|MoveFile
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|oldname
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|newname
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__remove
name|int
name|qt_wince__remove
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
operator|!
name|DeleteFile
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|name
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_stat
name|int
name|qt_wince_stat
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|stat
modifier|*
name|buffer
parameter_list|)
block|{
name|WIN32_FIND_DATA
name|finfo
decl_stmt|;
name|HANDLE
name|ff
init|=
name|FindFirstFile
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|path
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
operator|&
name|finfo
argument_list|)
decl_stmt|;
if|if
condition|(
name|ff
operator|==
name|INVALID_HANDLE_VALUE
condition|)
return|return
operator|-
literal|1
return|;
name|buffer
operator|->
name|st_ctime
operator|=
name|qt_wince_ftToTime_t
argument_list|(
name|finfo
operator|.
name|ftCreationTime
argument_list|)
expr_stmt|;
name|buffer
operator|->
name|st_atime
operator|=
name|qt_wince_ftToTime_t
argument_list|(
name|finfo
operator|.
name|ftLastAccessTime
argument_list|)
expr_stmt|;
name|buffer
operator|->
name|st_mtime
operator|=
name|qt_wince_ftToTime_t
argument_list|(
name|finfo
operator|.
name|ftLastWriteTime
argument_list|)
expr_stmt|;
name|buffer
operator|->
name|st_nlink
operator|=
literal|0
expr_stmt|;
name|buffer
operator|->
name|st_size
operator|=
name|finfo
operator|.
name|nFileSizeLow
expr_stmt|;
comment|// ### missing high!
name|buffer
operator|->
name|st_mode
operator|=
operator|(
name|finfo
operator|.
name|dwFileAttributes
operator|&
name|FILE_ATTRIBUTE_DIRECTORY
operator|)
condition|?
name|_S_IFDIR
else|:
name|_S_IFREG
expr_stmt|;
name|buffer
operator|->
name|st_mode
operator||=
operator|(
name|finfo
operator|.
name|dwFileAttributes
operator|&
name|FILE_ATTRIBUTE_READONLY
operator|)
condition|?
name|_O_RDONLY
else|:
name|_O_RDWR
expr_stmt|;
return|return
operator|(
name|FindClose
argument_list|(
name|ff
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__fstat
name|int
name|qt_wince__fstat
parameter_list|(
name|int
name|handle
parameter_list|,
name|struct
name|stat
modifier|*
name|buffer
parameter_list|)
block|{
name|BY_HANDLE_FILE_INFORMATION
name|fInfo
decl_stmt|;
name|BOOL
name|res
init|=
name|GetFileInformationByHandle
argument_list|(
operator|(
name|HANDLE
operator|)
name|handle
argument_list|,
operator|&
name|fInfo
argument_list|)
decl_stmt|;
name|buffer
operator|->
name|st_ctime
operator|=
name|qt_wince_ftToTime_t
argument_list|(
name|fInfo
operator|.
name|ftCreationTime
argument_list|)
expr_stmt|;
name|buffer
operator|->
name|st_atime
operator|=
name|qt_wince_ftToTime_t
argument_list|(
name|fInfo
operator|.
name|ftLastAccessTime
argument_list|)
expr_stmt|;
name|buffer
operator|->
name|st_mtime
operator|=
name|qt_wince_ftToTime_t
argument_list|(
name|fInfo
operator|.
name|ftLastWriteTime
argument_list|)
expr_stmt|;
name|buffer
operator|->
name|st_nlink
operator|=
literal|0
expr_stmt|;
name|buffer
operator|->
name|st_size
operator|=
name|fInfo
operator|.
name|nFileSizeLow
expr_stmt|;
comment|// ### missing high!
name|buffer
operator|->
name|st_mode
operator|=
operator|(
name|fInfo
operator|.
name|dwFileAttributes
operator|&
name|FILE_ATTRIBUTE_DIRECTORY
operator|)
condition|?
name|_S_IFDIR
else|:
name|_S_IFREG
expr_stmt|;
name|buffer
operator|->
name|st_mode
operator||=
operator|(
name|fInfo
operator|.
name|dwFileAttributes
operator|&
name|FILE_ATTRIBUTE_READONLY
operator|)
condition|?
name|_O_RDONLY
else|:
name|_O_RDWR
expr_stmt|;
return|return
operator|(
name|res
operator|==
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_SetErrorMode
name|int
name|qt_wince_SetErrorMode
parameter_list|(
name|int
name|newValue
parameter_list|)
block|{
specifier|static
name|int
name|oldValue
decl_stmt|;
name|int
name|result
init|=
name|oldValue
decl_stmt|;
name|oldValue
operator|=
name|newValue
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__chmod
name|bool
name|qt_wince__chmod
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|mode
parameter_list|)
block|{
return|return
name|_wchmod
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|file
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__wchmod
name|bool
name|qt_wince__wchmod
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|file
parameter_list|,
name|int
name|mode
parameter_list|)
block|{
name|BOOL
name|success
init|=
name|FALSE
decl_stmt|;
comment|// ### Does not work properly, what about just adding one property?
if|if
condition|(
name|mode
operator|&
name|_S_IWRITE
condition|)
block|{
name|success
operator|=
name|SetFileAttributes
argument_list|(
name|file
argument_list|,
name|FILE_ATTRIBUTE_NORMAL
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|mode
operator|&
name|_S_IREAD
operator|)
operator|&&
operator|!
operator|(
name|mode
operator|&
name|_S_IWRITE
operator|)
condition|)
block|{
name|success
operator|=
name|SetFileAttributes
argument_list|(
name|file
argument_list|,
name|FILE_ATTRIBUTE_READONLY
argument_list|)
expr_stmt|;
block|}
return|return
name|success
condition|?
literal|0
else|:
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_CreateFileA
name|HANDLE
name|qt_wince_CreateFileA
parameter_list|(
name|LPCSTR
name|filename
parameter_list|,
name|DWORD
name|access
parameter_list|,
name|DWORD
name|share
parameter_list|,
name|LPSECURITY_ATTRIBUTES
name|attr
parameter_list|,
name|DWORD
name|dispo
parameter_list|,
name|DWORD
name|flags
parameter_list|,
name|HANDLE
name|tempFile
parameter_list|)
block|{
return|return
name|CreateFileW
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|filename
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|access
argument_list|,
name|share
argument_list|,
name|attr
argument_list|,
name|dispo
argument_list|,
name|flags
argument_list|,
name|tempFile
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// Graphics ---------------------------------------------------------
end_comment
begin_function
DECL|function|qt_wince_SetWindowOrgEx
name|BOOL
name|qt_wince_SetWindowOrgEx
parameter_list|(
name|HDC
comment|/*hdc*/
parameter_list|,
name|int
comment|/*X*/
parameter_list|,
name|int
comment|/*Y*/
parameter_list|,
name|LPPOINT
comment|/*lpPoint*/
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function
begin_comment
comment|// Threading --------------------------------------------------------
end_comment
begin_function
DECL|function|qt_wince__beginthread
name|HANDLE
name|qt_wince__beginthread
parameter_list|(
name|void
function_decl|(
modifier|*
name|start_address
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|unsigned
name|stack_size
parameter_list|,
name|void
modifier|*
name|arglist
parameter_list|)
block|{
name|unsigned
name|initflag
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|stack_size
operator|>
literal|0
condition|)
name|initflag
operator||=
name|STACK_SIZE_PARAM_IS_A_RESERVATION
expr_stmt|;
return|return
name|CreateThread
argument_list|(
name|NULL
argument_list|,
name|stack_size
argument_list|,
operator|(
name|LPTHREAD_START_ROUTINE
operator|)
name|start_address
argument_list|,
name|arglist
argument_list|,
name|initflag
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__beginthreadex
name|unsigned
name|long
name|qt_wince__beginthreadex
parameter_list|(
name|void
modifier|*
name|security
parameter_list|,
name|unsigned
name|stack_size
parameter_list|,
name|unsigned
function_decl|(
name|__stdcall
modifier|*
name|start_address
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arglist
parameter_list|,
name|unsigned
name|initflag
parameter_list|,
name|unsigned
modifier|*
name|thrdaddr
parameter_list|)
block|{
if|if
condition|(
name|stack_size
operator|>
literal|0
condition|)
name|initflag
operator||=
name|STACK_SIZE_PARAM_IS_A_RESERVATION
expr_stmt|;
return|return
operator|(
name|unsigned
name|long
operator|)
name|CreateThread
argument_list|(
operator|(
name|LPSECURITY_ATTRIBUTES
operator|)
name|security
argument_list|,
operator|(
name|DWORD
operator|)
name|stack_size
argument_list|,
operator|(
name|LPTHREAD_START_ROUTINE
operator|)
name|start_address
argument_list|,
operator|(
name|LPVOID
operator|)
name|arglist
argument_list|,
operator|(
name|DWORD
operator|)
name|initflag
operator||
name|CREATE_SUSPENDED
argument_list|,
operator|(
name|LPDWORD
operator|)
name|thrdaddr
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince__endthreadex
name|void
name|qt_wince__endthreadex
parameter_list|(
name|unsigned
name|nExitCode
parameter_list|)
block|{
name|ExitThread
argument_list|(
operator|(
name|DWORD
operator|)
name|nExitCode
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qt_wince_bsearch
name|void
modifier|*
name|qt_wince_bsearch
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|,
specifier|const
name|void
modifier|*
name|base
parameter_list|,
name|size_t
name|num
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
function_decl|(
name|__cdecl
modifier|*
name|compare
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
name|size_t
name|low
init|=
literal|0
decl_stmt|;
name|size_t
name|high
init|=
name|num
operator|-
literal|1
decl_stmt|;
while|while
condition|(
name|low
operator|<=
name|high
condition|)
block|{
name|size_t
name|mid
init|=
operator|(
name|low
operator|+
name|high
operator|)
operator|>>
literal|1
decl_stmt|;
name|int
name|c
init|=
name|compare
argument_list|(
name|key
argument_list|,
operator|(
name|char
operator|*
operator|)
name|base
operator|+
name|mid
operator|*
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|c
operator|<
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|mid
condition|)
break|break;
name|high
operator|=
name|mid
operator|-
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|>
literal|0
condition|)
name|low
operator|=
name|mid
operator|+
literal|1
expr_stmt|;
else|else
return|return
operator|(
name|char
operator|*
operator|)
name|base
operator|+
name|mid
operator|*
name|size
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|lfind
name|void
modifier|*
name|lfind
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|,
specifier|const
name|void
modifier|*
name|base
parameter_list|,
name|size_t
modifier|*
name|elements
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
function_decl|(
name|__cdecl
modifier|*
name|compare
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|current
init|=
operator|(
name|char
operator|*
operator|)
name|base
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|end
init|=
operator|(
name|char
operator|*
operator|)
operator|(
name|current
operator|+
operator|(
operator|*
name|elements
operator|)
operator|*
name|size
operator|)
decl_stmt|;
while|while
condition|(
name|current
operator|!=
name|end
condition|)
block|{
if|if
condition|(
name|compare
argument_list|(
name|current
argument_list|,
name|key
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|void
operator|*
operator|)
name|current
return|;
name|current
operator|+=
name|size
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_GetThreadLocale
name|DWORD
name|qt_wince_GetThreadLocale
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|GetUserDefaultLCID
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_calloc
name|void
modifier|*
name|qt_wince_calloc
parameter_list|(
name|size_t
name|num
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|ptr
init|=
name|malloc
argument_list|(
name|num
operator|*
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|ptr
condition|)
name|memset
argument_list|(
name|ptr
argument_list|,
literal|0
argument_list|,
name|num
operator|*
name|size
argument_list|)
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_function
begin_comment
comment|// _getpid is currently only used for creating a temporary filename
end_comment
begin_function
DECL|function|qt_wince__getpid
name|int
name|qt_wince__getpid
parameter_list|()
block|{
return|return
name|qAbs
argument_list|(
operator|(
name|int
operator|)
name|GetCurrentProcessId
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_comment
unit|}
comment|// extern "C"
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WINCE
end_comment
end_unit
