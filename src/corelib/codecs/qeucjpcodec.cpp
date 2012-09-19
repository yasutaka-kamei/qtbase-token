begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Most of the code here was originally written by Serika Kurusugawa
end_comment
begin_comment
comment|// a.k.a. Junji Takagi, and is included in Qt with the author's permission,
end_comment
begin_comment
comment|// and the grateful thanks of the Qt team.
end_comment
begin_comment
comment|/*! \class QEucJpCodec     \inmodule QtCore     \reentrant     \internal */
end_comment
begin_comment
comment|/*  * Copyright (C) 1999 Serika Kurusugawa, All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment
begin_include
include|#
directive|include
file|"qeucjpcodec_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_BIG_CODECS
DECL|variable|Ss2
specifier|static
specifier|const
name|uchar
name|Ss2
init|=
literal|0x8e
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|Ss2
comment|// Single Shift 2
end_comment
begin_decl_stmt
DECL|variable|Ss3
specifier|static
specifier|const
name|uchar
name|Ss3
init|=
literal|0x8f
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|Ss3
comment|// Single Shift 3
end_comment
begin_define
DECL|macro|IsKana
define|#
directive|define
name|IsKana
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 0xa1)&& ((c)<= 0xdf))
end_define
begin_define
DECL|macro|IsEucChar
define|#
directive|define
name|IsEucChar
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 0xa1)&& ((c)<= 0xfe))
end_define
begin_define
DECL|macro|QValidChar
define|#
directive|define
name|QValidChar
parameter_list|(
name|u
parameter_list|)
value|((u) ? QChar((ushort)(u)) : QChar(QChar::ReplacementCharacter))
end_define
begin_comment
comment|/*!   Constructs a QEucJpCodec. */
end_comment
begin_constructor
DECL|function|QEucJpCodec
name|QEucJpCodec
operator|::
name|QEucJpCodec
parameter_list|()
member_init_list|:
name|conv
argument_list|(
name|QJpUnicodeConv
operator|::
name|newConverter
argument_list|(
name|QJpUnicodeConv
operator|::
name|Default
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Destroys the codec. */
end_comment
begin_destructor
DECL|function|~QEucJpCodec
name|QEucJpCodec
operator|::
name|~
name|QEucJpCodec
parameter_list|()
block|{
operator|delete
operator|(
name|QJpUnicodeConv
operator|*
operator|)
name|conv
expr_stmt|;
name|conv
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|convertFromUnicode
name|QByteArray
name|QEucJpCodec
operator|::
name|convertFromUnicode
parameter_list|(
specifier|const
name|QChar
modifier|*
name|uc
parameter_list|,
name|int
name|len
parameter_list|,
name|ConverterState
modifier|*
name|state
parameter_list|)
specifier|const
block|{
name|char
name|replacement
init|=
literal|'?'
decl_stmt|;
if|if
condition|(
name|state
condition|)
block|{
if|if
condition|(
name|state
operator|->
name|flags
operator|&
name|ConvertInvalidToNull
condition|)
name|replacement
operator|=
literal|0
expr_stmt|;
block|}
name|int
name|invalid
init|=
literal|0
decl_stmt|;
name|int
name|rlen
init|=
literal|3
operator|*
name|len
operator|+
literal|1
decl_stmt|;
name|QByteArray
name|rstr
decl_stmt|;
name|rstr
operator|.
name|resize
argument_list|(
name|rlen
argument_list|)
expr_stmt|;
name|uchar
modifier|*
name|cursor
init|=
operator|(
name|uchar
operator|*
operator|)
name|rstr
operator|.
name|data
argument_list|()
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
name|len
condition|;
name|i
operator|++
control|)
block|{
name|QChar
name|ch
init|=
name|uc
index|[
name|i
index|]
decl_stmt|;
name|uint
name|j
decl_stmt|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|<
literal|0x80
condition|)
block|{
comment|// ASCII
operator|*
name|cursor
operator|++
operator|=
name|ch
operator|.
name|cell
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|j
operator|=
name|conv
operator|->
name|unicodeToJisx0201
argument_list|(
name|ch
operator|.
name|row
argument_list|()
argument_list|,
name|ch
operator|.
name|cell
argument_list|()
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|j
operator|<
literal|0x80
condition|)
block|{
comment|// JIS X 0201 Latin ?
operator|*
name|cursor
operator|++
operator|=
name|j
expr_stmt|;
block|}
else|else
block|{
comment|// JIS X 0201 Kana
operator|*
name|cursor
operator|++
operator|=
name|Ss2
expr_stmt|;
operator|*
name|cursor
operator|++
operator|=
name|j
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
operator|(
name|j
operator|=
name|conv
operator|->
name|unicodeToJisx0208
argument_list|(
name|ch
operator|.
name|row
argument_list|()
argument_list|,
name|ch
operator|.
name|cell
argument_list|()
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
comment|// JIS X 0208
operator|*
name|cursor
operator|++
operator|=
operator|(
name|j
operator|>>
literal|8
operator|)
operator||
literal|0x80
expr_stmt|;
operator|*
name|cursor
operator|++
operator|=
operator|(
name|j
operator|&
literal|0xff
operator|)
operator||
literal|0x80
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|j
operator|=
name|conv
operator|->
name|unicodeToJisx0212
argument_list|(
name|ch
operator|.
name|row
argument_list|()
argument_list|,
name|ch
operator|.
name|cell
argument_list|()
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
comment|// JIS X 0212
operator|*
name|cursor
operator|++
operator|=
name|Ss3
expr_stmt|;
operator|*
name|cursor
operator|++
operator|=
operator|(
name|j
operator|>>
literal|8
operator|)
operator||
literal|0x80
expr_stmt|;
operator|*
name|cursor
operator|++
operator|=
operator|(
name|j
operator|&
literal|0xff
operator|)
operator||
literal|0x80
expr_stmt|;
block|}
else|else
block|{
comment|// Error
operator|*
name|cursor
operator|++
operator|=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
block|}
name|rstr
operator|.
name|resize
argument_list|(
name|cursor
operator|-
operator|(
name|uchar
operator|*
operator|)
name|rstr
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
condition|)
block|{
name|state
operator|->
name|invalidChars
operator|+=
name|invalid
expr_stmt|;
block|}
return|return
name|rstr
return|;
block|}
end_function
begin_function
DECL|function|convertToUnicode
name|QString
name|QEucJpCodec
operator|::
name|convertToUnicode
parameter_list|(
specifier|const
name|char
modifier|*
name|chars
parameter_list|,
name|int
name|len
parameter_list|,
name|ConverterState
modifier|*
name|state
parameter_list|)
specifier|const
block|{
name|uchar
name|buf
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|int
name|nbuf
init|=
literal|0
decl_stmt|;
name|QChar
name|replacement
init|=
name|QChar
operator|::
name|ReplacementCharacter
decl_stmt|;
if|if
condition|(
name|state
condition|)
block|{
if|if
condition|(
name|state
operator|->
name|flags
operator|&
name|ConvertInvalidToNull
condition|)
name|replacement
operator|=
name|QChar
operator|::
name|Null
expr_stmt|;
name|nbuf
operator|=
name|state
operator|->
name|remainingChars
expr_stmt|;
name|buf
index|[
literal|0
index|]
operator|=
name|state
operator|->
name|state_data
index|[
literal|0
index|]
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
name|state
operator|->
name|state_data
index|[
literal|1
index|]
expr_stmt|;
block|}
name|int
name|invalid
init|=
literal|0
decl_stmt|;
name|QString
name|result
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
name|len
condition|;
name|i
operator|++
control|)
block|{
name|uchar
name|ch
init|=
name|chars
index|[
name|i
index|]
decl_stmt|;
switch|switch
condition|(
name|nbuf
condition|)
block|{
case|case
literal|0
case|:
if|if
condition|(
name|ch
operator|<
literal|0x80
condition|)
block|{
comment|// ASCII
name|result
operator|+=
name|QLatin1Char
argument_list|(
name|ch
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ch
operator|==
name|Ss2
operator|||
name|ch
operator|==
name|Ss3
condition|)
block|{
comment|// JIS X 0201 Kana or JIS X 0212
name|buf
index|[
literal|0
index|]
operator|=
name|ch
expr_stmt|;
name|nbuf
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|IsEucChar
argument_list|(
name|ch
argument_list|)
condition|)
block|{
comment|// JIS X 0208
name|buf
index|[
literal|0
index|]
operator|=
name|ch
expr_stmt|;
name|nbuf
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
comment|// Invalid
name|result
operator|+=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
break|break;
case|case
literal|1
case|:
if|if
condition|(
name|buf
index|[
literal|0
index|]
operator|==
name|Ss2
condition|)
block|{
comment|// JIS X 0201 Kana
if|if
condition|(
name|IsKana
argument_list|(
name|ch
argument_list|)
condition|)
block|{
name|uint
name|u
init|=
name|conv
operator|->
name|jisx0201ToUnicode
argument_list|(
name|ch
argument_list|)
decl_stmt|;
name|result
operator|+=
name|QValidChar
argument_list|(
name|u
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|result
operator|+=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
name|nbuf
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|buf
index|[
literal|0
index|]
operator|==
name|Ss3
condition|)
block|{
comment|// JIS X 0212-1990
if|if
condition|(
name|IsEucChar
argument_list|(
name|ch
argument_list|)
condition|)
block|{
name|buf
index|[
literal|1
index|]
operator|=
name|ch
expr_stmt|;
name|nbuf
operator|=
literal|2
expr_stmt|;
block|}
else|else
block|{
comment|// Error
name|result
operator|+=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
name|nbuf
operator|=
literal|0
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// JIS X 0208-1990
if|if
condition|(
name|IsEucChar
argument_list|(
name|ch
argument_list|)
condition|)
block|{
name|uint
name|u
init|=
name|conv
operator|->
name|jisx0208ToUnicode
argument_list|(
name|buf
index|[
literal|0
index|]
operator|&
literal|0x7f
argument_list|,
name|ch
operator|&
literal|0x7f
argument_list|)
decl_stmt|;
name|result
operator|+=
name|QValidChar
argument_list|(
name|u
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Error
name|result
operator|+=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
name|nbuf
operator|=
literal|0
expr_stmt|;
block|}
break|break;
case|case
literal|2
case|:
comment|// JIS X 0212
if|if
condition|(
name|IsEucChar
argument_list|(
name|ch
argument_list|)
condition|)
block|{
name|uint
name|u
init|=
name|conv
operator|->
name|jisx0212ToUnicode
argument_list|(
name|buf
index|[
literal|1
index|]
operator|&
literal|0x7f
argument_list|,
name|ch
operator|&
literal|0x7f
argument_list|)
decl_stmt|;
name|result
operator|+=
name|QValidChar
argument_list|(
name|u
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|result
operator|+=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
name|nbuf
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
name|state
condition|)
block|{
name|state
operator|->
name|remainingChars
operator|=
name|nbuf
expr_stmt|;
name|state
operator|->
name|state_data
index|[
literal|0
index|]
operator|=
name|buf
index|[
literal|0
index|]
expr_stmt|;
name|state
operator|->
name|state_data
index|[
literal|1
index|]
operator|=
name|buf
index|[
literal|1
index|]
expr_stmt|;
name|state
operator|->
name|invalidChars
operator|+=
name|invalid
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|_mibEnum
name|int
name|QEucJpCodec
operator|::
name|_mibEnum
parameter_list|()
block|{
return|return
literal|18
return|;
block|}
end_function
begin_function
DECL|function|_name
name|QByteArray
name|QEucJpCodec
operator|::
name|_name
parameter_list|()
block|{
return|return
literal|"EUC-JP"
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BIG_CODECS
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
