begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qplatformdefs.h>
end_include
begin_include
include|#
directive|include
file|"private/qxbmhandler_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_XBM
end_ifndef
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<qvariant.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<ctype.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*****************************************************************************   X bitmap image read/write functions  *****************************************************************************/
DECL|function|hex2byte
specifier|static
specifier|inline
name|int
name|hex2byte
parameter_list|(
specifier|register
name|char
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
operator|(
name|isdigit
argument_list|(
operator|(
name|uchar
operator|)
operator|*
name|p
argument_list|)
condition|?
operator|*
name|p
operator|-
literal|'0'
else|:
name|toupper
argument_list|(
operator|(
name|uchar
operator|)
operator|*
name|p
argument_list|)
operator|-
literal|'A'
operator|+
literal|10
operator|)
operator|<<
literal|4
operator|)
operator||
operator|(
name|isdigit
argument_list|(
operator|(
name|uchar
operator|)
operator|*
operator|(
name|p
operator|+
literal|1
operator|)
argument_list|)
condition|?
operator|*
operator|(
name|p
operator|+
literal|1
operator|)
operator|-
literal|'0'
else|:
name|toupper
argument_list|(
operator|(
name|uchar
operator|)
operator|*
operator|(
name|p
operator|+
literal|1
operator|)
argument_list|)
operator|-
literal|'A'
operator|+
literal|10
operator|)
return|;
block|}
end_function
begin_function
DECL|function|read_xbm_header
specifier|static
name|bool
name|read_xbm_header
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
name|int
modifier|&
name|w
parameter_list|,
name|int
modifier|&
name|h
parameter_list|)
block|{
specifier|const
name|int
name|buflen
init|=
literal|300
decl_stmt|;
specifier|const
name|int
name|maxlen
init|=
literal|4096
decl_stmt|;
name|char
name|buf
index|[
name|buflen
operator|+
literal|1
index|]
decl_stmt|;
name|QRegExp
name|r1
argument_list|(
name|QLatin1String
argument_list|(
literal|"^#define[ \t]+[a-zA-Z0-9._]+[ \t]+"
argument_list|)
argument_list|)
decl_stmt|;
name|QRegExp
name|r2
argument_list|(
name|QLatin1String
argument_list|(
literal|"[0-9]+"
argument_list|)
argument_list|)
decl_stmt|;
name|qint64
name|readBytes
init|=
literal|0
decl_stmt|;
name|qint64
name|totalReadBytes
init|=
literal|0
decl_stmt|;
name|buf
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|// skip initial comment, if any
while|while
condition|(
name|buf
index|[
literal|0
index|]
operator|!=
literal|'#'
condition|)
block|{
name|readBytes
operator|=
name|device
operator|->
name|readLine
argument_list|(
name|buf
argument_list|,
name|buflen
argument_list|)
expr_stmt|;
comment|// if readBytes>= buflen, it's very probably not a C file
if|if
condition|(
name|readBytes
operator|<=
literal|0
operator|||
name|readBytes
operator|>=
name|buflen
operator|-
literal|1
condition|)
return|return
literal|false
return|;
comment|// limit xbm headers to the first 4k in the file to prevent
comment|// excessive reads on non-xbm files
name|totalReadBytes
operator|+=
name|readBytes
expr_stmt|;
if|if
condition|(
name|totalReadBytes
operator|>=
name|maxlen
condition|)
return|return
literal|false
return|;
block|}
name|buf
index|[
name|readBytes
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|QString
name|sbuf
decl_stmt|;
name|sbuf
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|buf
argument_list|)
expr_stmt|;
comment|// "#define .._width<num>"
if|if
condition|(
name|r1
operator|.
name|indexIn
argument_list|(
name|sbuf
argument_list|)
operator|==
literal|0
operator|&&
name|r2
operator|.
name|indexIn
argument_list|(
name|sbuf
argument_list|,
name|r1
operator|.
name|matchedLength
argument_list|()
argument_list|)
operator|==
name|r1
operator|.
name|matchedLength
argument_list|()
condition|)
name|w
operator|=
name|QByteArray
argument_list|(
operator|&
name|buf
index|[
name|r1
operator|.
name|matchedLength
argument_list|()
index|]
argument_list|)
operator|.
name|trimmed
argument_list|()
operator|.
name|toInt
argument_list|()
expr_stmt|;
comment|// "#define .._height<num>"
name|readBytes
operator|=
name|device
operator|->
name|readLine
argument_list|(
name|buf
argument_list|,
name|buflen
argument_list|)
expr_stmt|;
if|if
condition|(
name|readBytes
operator|<=
literal|0
condition|)
return|return
literal|false
return|;
name|buf
index|[
name|readBytes
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|sbuf
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|r1
operator|.
name|indexIn
argument_list|(
name|sbuf
argument_list|)
operator|==
literal|0
operator|&&
name|r2
operator|.
name|indexIn
argument_list|(
name|sbuf
argument_list|,
name|r1
operator|.
name|matchedLength
argument_list|()
argument_list|)
operator|==
name|r1
operator|.
name|matchedLength
argument_list|()
condition|)
name|h
operator|=
name|QByteArray
argument_list|(
operator|&
name|buf
index|[
name|r1
operator|.
name|matchedLength
argument_list|()
index|]
argument_list|)
operator|.
name|trimmed
argument_list|()
operator|.
name|toInt
argument_list|()
expr_stmt|;
comment|// format error
if|if
condition|(
name|w
operator|<=
literal|0
operator|||
name|w
operator|>
literal|32767
operator|||
name|h
operator|<=
literal|0
operator|||
name|h
operator|>
literal|32767
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|read_xbm_body
specifier|static
name|bool
name|read_xbm_body
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|QImage
modifier|*
name|outImage
parameter_list|)
block|{
specifier|const
name|int
name|buflen
init|=
literal|300
decl_stmt|;
name|char
name|buf
index|[
name|buflen
operator|+
literal|1
index|]
decl_stmt|;
name|qint64
name|readBytes
init|=
literal|0
decl_stmt|;
comment|// scan for database
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
operator|(
name|readBytes
operator|=
name|device
operator|->
name|readLine
argument_list|(
name|buf
argument_list|,
name|buflen
argument_list|)
operator|)
operator|<=
literal|0
condition|)
block|{
comment|// end of file
return|return
literal|false
return|;
block|}
name|buf
index|[
name|readBytes
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|buf
argument_list|,
name|readBytes
argument_list|)
operator|.
name|contains
argument_list|(
literal|"0x"
argument_list|)
condition|)
break|break;
block|}
if|if
condition|(
name|outImage
operator|->
name|size
argument_list|()
operator|!=
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
operator|||
name|outImage
operator|->
name|format
argument_list|()
operator|!=
name|QImage
operator|::
name|Format_MonoLSB
condition|)
block|{
operator|*
name|outImage
operator|=
name|QImage
argument_list|(
name|w
argument_list|,
name|h
argument_list|,
name|QImage
operator|::
name|Format_MonoLSB
argument_list|)
expr_stmt|;
if|if
condition|(
name|outImage
operator|->
name|isNull
argument_list|()
condition|)
return|return
literal|false
return|;
block|}
name|outImage
operator|->
name|setColorCount
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|outImage
operator|->
name|setColor
argument_list|(
literal|0
argument_list|,
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
argument_list|)
expr_stmt|;
comment|// white
name|outImage
operator|->
name|setColor
argument_list|(
literal|1
argument_list|,
name|qRgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|// black
name|int
name|x
init|=
literal|0
decl_stmt|,
name|y
init|=
literal|0
decl_stmt|;
name|uchar
modifier|*
name|b
init|=
name|outImage
operator|->
name|scanLine
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|char
modifier|*
name|p
init|=
name|buf
operator|+
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|buf
argument_list|,
name|readBytes
argument_list|)
operator|.
name|indexOf
argument_list|(
literal|"0x"
argument_list|)
decl_stmt|;
name|w
operator|=
operator|(
name|w
operator|+
literal|7
operator|)
operator|/
literal|8
expr_stmt|;
comment|// byte width
while|while
condition|(
name|y
operator|<
name|h
condition|)
block|{
comment|// for all encoded bytes...
if|if
condition|(
name|p
condition|)
block|{
comment|// p = "0x.."
operator|*
name|b
operator|++
operator|=
name|hex2byte
argument_list|(
name|p
operator|+
literal|2
argument_list|)
expr_stmt|;
name|p
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
operator|++
name|x
operator|==
name|w
operator|&&
operator|++
name|y
operator|<
name|h
condition|)
block|{
name|b
operator|=
name|outImage
operator|->
name|scanLine
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|x
operator|=
literal|0
expr_stmt|;
block|}
name|p
operator|=
name|strstr
argument_list|(
name|p
argument_list|,
literal|"0x"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// read another line
if|if
condition|(
operator|(
name|readBytes
operator|=
name|device
operator|->
name|readLine
argument_list|(
name|buf
argument_list|,
name|buflen
argument_list|)
operator|)
operator|<=
literal|0
condition|)
comment|// EOF ==> truncated image
break|break;
name|p
operator|=
name|buf
operator|+
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|buf
argument_list|,
name|readBytes
argument_list|)
operator|.
name|indexOf
argument_list|(
literal|"0x"
argument_list|)
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|read_xbm_image
specifier|static
name|bool
name|read_xbm_image
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|,
name|QImage
modifier|*
name|outImage
parameter_list|)
block|{
name|int
name|w
init|=
literal|0
decl_stmt|,
name|h
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|read_xbm_header
argument_list|(
name|device
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
condition|)
return|return
literal|false
return|;
return|return
name|read_xbm_body
argument_list|(
name|device
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|outImage
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|write_xbm_image
specifier|static
name|bool
name|write_xbm_image
parameter_list|(
specifier|const
name|QImage
modifier|&
name|sourceImage
parameter_list|,
name|QIODevice
modifier|*
name|device
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QImage
name|image
init|=
name|sourceImage
decl_stmt|;
name|int
name|w
init|=
name|image
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|h
init|=
name|image
operator|.
name|height
argument_list|()
decl_stmt|;
name|int
name|i
decl_stmt|;
name|QString
name|s
init|=
name|fileName
decl_stmt|;
comment|// get file base name
name|int
name|msize
init|=
name|s
operator|.
name|length
argument_list|()
operator|+
literal|100
decl_stmt|;
name|char
modifier|*
name|buf
init|=
operator|new
name|char
index|[
name|msize
index|]
decl_stmt|;
name|qsnprintf
argument_list|(
name|buf
argument_list|,
name|msize
argument_list|,
literal|"#define %s_width %d\n"
argument_list|,
name|s
operator|.
name|toAscii
argument_list|()
operator|.
name|data
argument_list|()
argument_list|,
name|w
argument_list|)
expr_stmt|;
name|device
operator|->
name|write
argument_list|(
name|buf
argument_list|,
name|qstrlen
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
name|qsnprintf
argument_list|(
name|buf
argument_list|,
name|msize
argument_list|,
literal|"#define %s_height %d\n"
argument_list|,
name|s
operator|.
name|toAscii
argument_list|()
operator|.
name|data
argument_list|()
argument_list|,
name|h
argument_list|)
expr_stmt|;
name|device
operator|->
name|write
argument_list|(
name|buf
argument_list|,
name|qstrlen
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
name|qsnprintf
argument_list|(
name|buf
argument_list|,
name|msize
argument_list|,
literal|"static char %s_bits[] = {\n "
argument_list|,
name|s
operator|.
name|toAscii
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|device
operator|->
name|write
argument_list|(
name|buf
argument_list|,
name|qstrlen
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|image
operator|.
name|format
argument_list|()
operator|!=
name|QImage
operator|::
name|Format_MonoLSB
condition|)
name|image
operator|=
name|image
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_MonoLSB
argument_list|)
expr_stmt|;
name|bool
name|invert
init|=
name|qGray
argument_list|(
name|image
operator|.
name|color
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<
name|qGray
argument_list|(
name|image
operator|.
name|color
argument_list|(
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|char
name|hexrep
index|[
literal|16
index|]
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
name|hexrep
index|[
name|i
index|]
operator|=
literal|'0'
operator|+
name|i
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|10
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|++
control|)
name|hexrep
index|[
name|i
index|]
operator|=
literal|'a'
operator|-
literal|10
operator|+
name|i
expr_stmt|;
if|if
condition|(
name|invert
condition|)
block|{
name|char
name|t
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
block|{
name|t
operator|=
name|hexrep
index|[
literal|15
operator|-
name|i
index|]
expr_stmt|;
name|hexrep
index|[
literal|15
operator|-
name|i
index|]
operator|=
name|hexrep
index|[
name|i
index|]
expr_stmt|;
name|hexrep
index|[
name|i
index|]
operator|=
name|t
expr_stmt|;
block|}
block|}
name|int
name|bcnt
init|=
literal|0
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
init|=
name|buf
decl_stmt|;
name|int
name|bpl
init|=
operator|(
name|w
operator|+
literal|7
operator|)
operator|/
literal|8
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|h
condition|;
operator|++
name|y
control|)
block|{
name|uchar
modifier|*
name|b
init|=
name|image
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|bpl
condition|;
operator|++
name|i
control|)
block|{
operator|*
name|p
operator|++
operator|=
literal|'0'
expr_stmt|;
operator|*
name|p
operator|++
operator|=
literal|'x'
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|hexrep
index|[
operator|*
name|b
operator|>>
literal|4
index|]
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|hexrep
index|[
operator|*
name|b
operator|++
operator|&
literal|0xf
index|]
expr_stmt|;
if|if
condition|(
name|i
operator|<
name|bpl
operator|-
literal|1
operator|||
name|y
operator|<
name|h
operator|-
literal|1
condition|)
block|{
operator|*
name|p
operator|++
operator|=
literal|','
expr_stmt|;
if|if
condition|(
operator|++
name|bcnt
operator|>
literal|14
condition|)
block|{
operator|*
name|p
operator|++
operator|=
literal|'\n'
expr_stmt|;
operator|*
name|p
operator|++
operator|=
literal|' '
expr_stmt|;
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|qstrlen
argument_list|(
name|buf
argument_list|)
operator|!=
name|device
operator|->
name|write
argument_list|(
name|buf
argument_list|,
name|qstrlen
argument_list|(
name|buf
argument_list|)
argument_list|)
condition|)
block|{
operator|delete
index|[]
name|buf
expr_stmt|;
return|return
literal|false
return|;
block|}
name|p
operator|=
name|buf
expr_stmt|;
name|bcnt
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
block|}
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
name|strcpy_s
argument_list|(
name|p
argument_list|,
sizeof|sizeof
argument_list|(
literal|" };\n"
argument_list|)
argument_list|,
literal|" };\n"
argument_list|)
expr_stmt|;
else|#
directive|else
name|strcpy
argument_list|(
name|p
argument_list|,
literal|" };\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|int
operator|)
name|qstrlen
argument_list|(
name|buf
argument_list|)
operator|!=
name|device
operator|->
name|write
argument_list|(
name|buf
argument_list|,
name|qstrlen
argument_list|(
name|buf
argument_list|)
argument_list|)
condition|)
block|{
operator|delete
index|[]
name|buf
expr_stmt|;
return|return
literal|false
return|;
block|}
operator|delete
index|[]
name|buf
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_constructor
DECL|function|QXbmHandler
name|QXbmHandler
operator|::
name|QXbmHandler
parameter_list|()
member_init_list|:
name|state
argument_list|(
name|Ready
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|readHeader
name|bool
name|QXbmHandler
operator|::
name|readHeader
parameter_list|()
block|{
name|state
operator|=
name|Error
expr_stmt|;
if|if
condition|(
operator|!
name|read_xbm_header
argument_list|(
name|device
argument_list|()
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
condition|)
return|return
literal|false
return|;
name|state
operator|=
name|ReadHeader
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|canRead
name|bool
name|QXbmHandler
operator|::
name|canRead
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|state
operator|==
name|Ready
operator|&&
operator|!
name|canRead
argument_list|(
name|device
argument_list|()
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|state
operator|!=
name|Error
condition|)
block|{
name|setFormat
argument_list|(
literal|"xbm"
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|canRead
name|bool
name|QXbmHandler
operator|::
name|canRead
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
name|QImage
name|image
decl_stmt|;
comment|// it's impossible to tell whether we can load an XBM or not when
comment|// it's from a sequential device, as the only way to do it is to
comment|// attempt to parse the whole image.
if|if
condition|(
name|device
operator|->
name|isSequential
argument_list|()
condition|)
return|return
literal|false
return|;
name|qint64
name|oldPos
init|=
name|device
operator|->
name|pos
argument_list|()
decl_stmt|;
name|bool
name|success
init|=
name|read_xbm_image
argument_list|(
name|device
argument_list|,
operator|&
name|image
argument_list|)
decl_stmt|;
name|device
operator|->
name|seek
argument_list|(
name|oldPos
argument_list|)
expr_stmt|;
return|return
name|success
return|;
block|}
end_function
begin_function
DECL|function|read
name|bool
name|QXbmHandler
operator|::
name|read
parameter_list|(
name|QImage
modifier|*
name|image
parameter_list|)
block|{
if|if
condition|(
name|state
operator|==
name|Error
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|state
operator|==
name|Ready
operator|&&
operator|!
name|readHeader
argument_list|()
condition|)
block|{
name|state
operator|=
name|Error
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|!
name|read_xbm_body
argument_list|(
name|device
argument_list|()
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|image
argument_list|)
condition|)
block|{
name|state
operator|=
name|Error
expr_stmt|;
return|return
literal|false
return|;
block|}
name|state
operator|=
name|Ready
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|write
name|bool
name|QXbmHandler
operator|::
name|write
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
return|return
name|write_xbm_image
argument_list|(
name|image
argument_list|,
name|device
argument_list|()
argument_list|,
name|fileName
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|supportsOption
name|bool
name|QXbmHandler
operator|::
name|supportsOption
parameter_list|(
name|ImageOption
name|option
parameter_list|)
specifier|const
block|{
return|return
name|option
operator|==
name|Name
operator|||
name|option
operator|==
name|Size
operator|||
name|option
operator|==
name|ImageFormat
return|;
block|}
end_function
begin_function
DECL|function|option
name|QVariant
name|QXbmHandler
operator|::
name|option
parameter_list|(
name|ImageOption
name|option
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|option
operator|==
name|Name
condition|)
block|{
return|return
name|fileName
return|;
block|}
elseif|else
if|if
condition|(
name|option
operator|==
name|Size
condition|)
block|{
if|if
condition|(
name|state
operator|==
name|Error
condition|)
return|return
name|QVariant
argument_list|()
return|;
if|if
condition|(
name|state
operator|==
name|Ready
operator|&&
operator|!
cast|const_cast
argument_list|<
name|QXbmHandler
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|readHeader
argument_list|()
condition|)
return|return
name|QVariant
argument_list|()
return|;
return|return
name|QSize
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|option
operator|==
name|ImageFormat
condition|)
block|{
return|return
name|QImage
operator|::
name|Format_MonoLSB
return|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setOption
name|void
name|QXbmHandler
operator|::
name|setOption
parameter_list|(
name|ImageOption
name|option
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
if|if
condition|(
name|option
operator|==
name|Name
condition|)
name|fileName
operator|=
name|value
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|name
name|QByteArray
name|QXbmHandler
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
literal|"xbm"
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_IMAGEFORMAT_XBM
end_comment
end_unit
