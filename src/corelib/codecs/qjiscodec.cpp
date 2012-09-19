begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Most of the code here was originally written by Serika Kurusugawa,
end_comment
begin_comment
comment|// a.k.a. Junji Takagi, and is included in Qt with the author's permission
end_comment
begin_comment
comment|// and the grateful thanks of the Qt team.
end_comment
begin_comment
comment|/*! \class QJisCodec     \inmodule QtCore     \reentrant     \internal */
end_comment
begin_include
include|#
directive|include
file|"qjiscodec_p.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_BIG_CODECS
name|enum
type|{
DECL|enumerator|Esc
name|Esc
init|=
literal|0x1b
decl_stmt|,
DECL|enumerator|So
name|So
init|=
literal|0x0e
decl_stmt|,
comment|// Shift Out
DECL|enumerator|Si
name|Si
init|=
literal|0x0f
decl_stmt|,
comment|// Shift In
DECL|enumerator|ReverseSolidus
name|ReverseSolidus
init|=
literal|0x5c
decl_stmt|,
DECL|enumerator|YenSign
name|YenSign
init|=
literal|0x5c
decl_stmt|,
DECL|enumerator|Tilde
name|Tilde
init|=
literal|0x7e
decl_stmt|,
DECL|enumerator|Overline
name|Overline
init|=
literal|0x7e
end_decl_stmt
begin_define
DECL|macro|IsKana
unit|};
define|#
directive|define
name|IsKana
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 0xa1)&& ((c)<= 0xdf))
end_define
begin_define
DECL|macro|IsJisChar
define|#
directive|define
name|IsJisChar
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 0x21)&& ((c)<= 0x7e))
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
begin_enum
DECL|enum|Iso2022State
DECL|enumerator|Ascii
DECL|enumerator|MinState
enum|enum
name|Iso2022State
block|{
name|Ascii
block|,
name|MinState
init|=
name|Ascii
block|,
DECL|enumerator|JISX0201_Latin
DECL|enumerator|JISX0201_Kana
name|JISX0201_Latin
block|,
name|JISX0201_Kana
block|,
DECL|enumerator|JISX0208_1978
DECL|enumerator|JISX0208_1983
name|JISX0208_1978
block|,
name|JISX0208_1983
block|,
DECL|enumerator|JISX0212
DECL|enumerator|MaxState
name|JISX0212
block|,
name|MaxState
init|=
name|JISX0212
block|,
DECL|enumerator|UnknownState
name|UnknownState
block|}
enum|;
end_enum
begin_decl_stmt
DECL|variable|Esc_CHARS
specifier|static
specifier|const
name|char
name|Esc_CHARS
index|[]
init|=
literal|"()*+-./"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Esc_Ascii
specifier|static
specifier|const
name|char
name|Esc_Ascii
index|[]
init|=
block|{
name|Esc
block|,
literal|'('
block|,
literal|'B'
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Esc_JISX0201_Latin
specifier|static
specifier|const
name|char
name|Esc_JISX0201_Latin
index|[]
init|=
block|{
name|Esc
block|,
literal|'('
block|,
literal|'J'
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Esc_JISX0201_Kana
specifier|static
specifier|const
name|char
name|Esc_JISX0201_Kana
index|[]
init|=
block|{
name|Esc
block|,
literal|'('
block|,
literal|'I'
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Esc_JISX0208_1978
specifier|static
specifier|const
name|char
name|Esc_JISX0208_1978
index|[]
init|=
block|{
name|Esc
block|,
literal|'$'
block|,
literal|'@'
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Esc_JISX0208_1983
specifier|static
specifier|const
name|char
name|Esc_JISX0208_1983
index|[]
init|=
block|{
name|Esc
block|,
literal|'$'
block|,
literal|'B'
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Esc_JISX0212
specifier|static
specifier|const
name|char
name|Esc_JISX0212
index|[]
init|=
block|{
name|Esc
block|,
literal|'$'
block|,
literal|'('
block|,
literal|'D'
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Esc_SEQ
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|Esc_SEQ
index|[]
init|=
block|{
name|Esc_Ascii
block|,
name|Esc_JISX0201_Latin
block|,
name|Esc_JISX0201_Kana
block|,
name|Esc_JISX0208_1978
block|,
name|Esc_JISX0208_1983
block|,
name|Esc_JISX0212
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QJisCodec
name|QJisCodec
operator|::
name|QJisCodec
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
comment|/*!     \internal */
end_comment
begin_destructor
DECL|function|~QJisCodec
name|QJisCodec
operator|::
name|~
name|QJisCodec
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
name|QJisCodec
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
name|cs
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
name|cs
condition|)
block|{
if|if
condition|(
name|cs
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
name|QByteArray
name|result
decl_stmt|;
name|Iso2022State
name|state
init|=
name|Ascii
decl_stmt|;
name|Iso2022State
name|prev
init|=
name|Ascii
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
name|row
argument_list|()
operator|==
literal|0x00
operator|&&
name|ch
operator|.
name|cell
argument_list|()
operator|<
literal|0x80
condition|)
block|{
comment|// Ascii
if|if
condition|(
name|state
operator|!=
name|JISX0201_Latin
operator|||
name|ch
operator|.
name|cell
argument_list|()
operator|==
name|ReverseSolidus
operator|||
name|ch
operator|.
name|cell
argument_list|()
operator|==
name|Tilde
condition|)
block|{
name|state
operator|=
name|Ascii
expr_stmt|;
block|}
name|j
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
comment|// JIS X 0201 Latin
if|if
condition|(
name|state
operator|!=
name|Ascii
operator|||
name|ch
operator|.
name|cell
argument_list|()
operator|==
name|YenSign
operator|||
name|ch
operator|.
name|cell
argument_list|()
operator|==
name|Overline
condition|)
block|{
name|state
operator|=
name|JISX0201_Latin
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// JIS X 0201 Kana
name|state
operator|=
name|JISX0201_Kana
expr_stmt|;
name|j
operator|&=
literal|0x7f
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
name|state
operator|=
name|JISX0208_1983
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
name|state
operator|=
name|JISX0212
expr_stmt|;
block|}
else|else
block|{
comment|// Invalid
name|state
operator|=
name|UnknownState
expr_stmt|;
name|j
operator|=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
block|}
if|if
condition|(
name|state
operator|!=
name|prev
condition|)
block|{
if|if
condition|(
name|state
operator|==
name|UnknownState
condition|)
block|{
name|result
operator|+=
name|Esc_Ascii
expr_stmt|;
block|}
else|else
block|{
name|result
operator|+=
name|Esc_SEQ
index|[
name|state
operator|-
name|MinState
index|]
expr_stmt|;
block|}
name|prev
operator|=
name|state
expr_stmt|;
block|}
if|if
condition|(
name|j
operator|<
literal|0x0100
condition|)
block|{
name|result
operator|+=
name|j
operator|&
literal|0xff
expr_stmt|;
block|}
else|else
block|{
name|result
operator|+=
operator|(
name|j
operator|>>
literal|8
operator|)
operator|&
literal|0xff
expr_stmt|;
name|result
operator|+=
name|j
operator|&
literal|0xff
expr_stmt|;
block|}
block|}
if|if
condition|(
name|prev
operator|!=
name|Ascii
condition|)
block|{
name|result
operator|+=
name|Esc_Ascii
expr_stmt|;
block|}
if|if
condition|(
name|cs
condition|)
block|{
name|cs
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
DECL|function|convertToUnicode
name|QString
name|QJisCodec
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
name|cs
parameter_list|)
specifier|const
block|{
name|uchar
name|buf
index|[
literal|4
index|]
init|=
block|{
literal|0
block|,
literal|0
block|,
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
name|Iso2022State
name|state
init|=
name|Ascii
decl_stmt|,
name|prev
init|=
name|Ascii
decl_stmt|;
name|bool
name|esc
init|=
literal|false
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
name|cs
condition|)
block|{
if|if
condition|(
name|cs
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
name|cs
operator|->
name|remainingChars
expr_stmt|;
name|buf
index|[
literal|0
index|]
operator|=
operator|(
name|cs
operator|->
name|state_data
index|[
literal|0
index|]
operator|>>
literal|24
operator|)
operator|&
literal|0xff
expr_stmt|;
name|buf
index|[
literal|1
index|]
operator|=
operator|(
name|cs
operator|->
name|state_data
index|[
literal|0
index|]
operator|>>
literal|16
operator|)
operator|&
literal|0xff
expr_stmt|;
name|buf
index|[
literal|2
index|]
operator|=
operator|(
name|cs
operator|->
name|state_data
index|[
literal|0
index|]
operator|>>
literal|8
operator|)
operator|&
literal|0xff
expr_stmt|;
name|buf
index|[
literal|3
index|]
operator|=
operator|(
name|cs
operator|->
name|state_data
index|[
literal|0
index|]
operator|>>
literal|0
operator|)
operator|&
literal|0xff
expr_stmt|;
name|state
operator|=
call|(
name|Iso2022State
call|)
argument_list|(
operator|(
name|cs
operator|->
name|state_data
index|[
literal|1
index|]
operator|>>
literal|0
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|prev
operator|=
call|(
name|Iso2022State
call|)
argument_list|(
operator|(
name|cs
operator|->
name|state_data
index|[
literal|1
index|]
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|esc
operator|=
name|cs
operator|->
name|state_data
index|[
literal|2
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
if|if
condition|(
name|esc
condition|)
block|{
comment|// Escape sequence
name|state
operator|=
name|UnknownState
expr_stmt|;
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
operator|==
literal|'$'
operator|||
name|strchr
argument_list|(
name|Esc_CHARS
argument_list|,
name|ch
argument_list|)
condition|)
block|{
name|buf
index|[
name|nbuf
operator|++
index|]
operator|=
name|ch
expr_stmt|;
block|}
else|else
block|{
name|nbuf
operator|=
literal|0
expr_stmt|;
name|esc
operator|=
literal|false
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
literal|'$'
condition|)
block|{
if|if
condition|(
name|strchr
argument_list|(
name|Esc_CHARS
argument_list|,
name|ch
argument_list|)
condition|)
block|{
name|buf
index|[
name|nbuf
operator|++
index|]
operator|=
name|ch
expr_stmt|;
block|}
else|else
block|{
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'@'
case|:
name|state
operator|=
name|JISX0208_1978
expr_stmt|;
comment|// Esc $ @
break|break;
case|case
literal|'B'
case|:
name|state
operator|=
name|JISX0208_1983
expr_stmt|;
comment|// Esc $ B
break|break;
block|}
name|nbuf
operator|=
literal|0
expr_stmt|;
name|esc
operator|=
literal|false
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|buf
index|[
literal|0
index|]
operator|==
literal|'('
condition|)
block|{
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'B'
case|:
name|state
operator|=
name|Ascii
expr_stmt|;
comment|// Esc (B
break|break;
case|case
literal|'I'
case|:
name|state
operator|=
name|JISX0201_Kana
expr_stmt|;
comment|// Esc (I
break|break;
case|case
literal|'J'
case|:
name|state
operator|=
name|JISX0201_Latin
expr_stmt|;
comment|// Esc (J
break|break;
block|}
block|}
name|nbuf
operator|=
literal|0
expr_stmt|;
name|esc
operator|=
literal|false
expr_stmt|;
block|}
break|break;
case|case
literal|2
case|:
if|if
condition|(
name|buf
index|[
literal|1
index|]
operator|==
literal|'('
condition|)
block|{
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'D'
case|:
name|state
operator|=
name|JISX0212
expr_stmt|;
comment|// Esc $ (D
break|break;
block|}
block|}
name|nbuf
operator|=
literal|0
expr_stmt|;
name|esc
operator|=
literal|false
expr_stmt|;
break|break;
block|}
block|}
else|else
block|{
if|if
condition|(
name|ch
operator|==
name|Esc
condition|)
block|{
comment|// Escape sequence
name|nbuf
operator|=
literal|0
expr_stmt|;
name|esc
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ch
operator|==
name|So
condition|)
block|{
comment|// Shift out
name|prev
operator|=
name|state
expr_stmt|;
name|state
operator|=
name|JISX0201_Kana
expr_stmt|;
name|nbuf
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ch
operator|==
name|Si
condition|)
block|{
comment|// Shift in
if|if
condition|(
name|prev
operator|==
name|Ascii
operator|||
name|prev
operator|==
name|JISX0201_Latin
condition|)
block|{
name|state
operator|=
name|prev
expr_stmt|;
block|}
else|else
block|{
name|state
operator|=
name|Ascii
expr_stmt|;
block|}
name|nbuf
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|uint
name|u
decl_stmt|;
switch|switch
condition|(
name|nbuf
condition|)
block|{
case|case
literal|0
case|:
switch|switch
condition|(
name|state
condition|)
block|{
case|case
name|Ascii
case|:
if|if
condition|(
name|ch
operator|<
literal|0x80
condition|)
block|{
name|result
operator|+=
name|QLatin1Char
argument_list|(
name|ch
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* fall through */
case|case
name|JISX0201_Latin
case|:
name|u
operator|=
name|conv
operator|->
name|jisx0201ToUnicode
argument_list|(
name|ch
argument_list|)
expr_stmt|;
name|result
operator|+=
name|QValidChar
argument_list|(
name|u
argument_list|)
expr_stmt|;
break|break;
case|case
name|JISX0201_Kana
case|:
name|u
operator|=
name|conv
operator|->
name|jisx0201ToUnicode
argument_list|(
name|ch
operator||
literal|0x80
argument_list|)
expr_stmt|;
name|result
operator|+=
name|QValidChar
argument_list|(
name|u
argument_list|)
expr_stmt|;
break|break;
case|case
name|JISX0208_1978
case|:
case|case
name|JISX0208_1983
case|:
case|case
name|JISX0212
case|:
name|buf
index|[
name|nbuf
operator|++
index|]
operator|=
name|ch
expr_stmt|;
break|break;
default|default:
name|result
operator|+=
name|QChar
operator|::
name|ReplacementCharacter
expr_stmt|;
break|break;
block|}
break|break;
case|case
literal|1
case|:
switch|switch
condition|(
name|state
condition|)
block|{
case|case
name|JISX0208_1978
case|:
case|case
name|JISX0208_1983
case|:
name|u
operator|=
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
expr_stmt|;
name|result
operator|+=
name|QValidChar
argument_list|(
name|u
argument_list|)
expr_stmt|;
break|break;
case|case
name|JISX0212
case|:
name|u
operator|=
name|conv
operator|->
name|jisx0212ToUnicode
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
expr_stmt|;
name|result
operator|+=
name|QValidChar
argument_list|(
name|u
argument_list|)
expr_stmt|;
break|break;
default|default:
name|result
operator|+=
name|replacement
expr_stmt|;
operator|++
name|invalid
expr_stmt|;
break|break;
block|}
name|nbuf
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
if|if
condition|(
name|cs
condition|)
block|{
name|cs
operator|->
name|remainingChars
operator|=
name|nbuf
expr_stmt|;
name|cs
operator|->
name|invalidChars
operator|+=
name|invalid
expr_stmt|;
name|cs
operator|->
name|state_data
index|[
literal|0
index|]
operator|=
operator|(
name|buf
index|[
literal|0
index|]
operator|<<
literal|24
operator|)
operator|+
operator|(
name|buf
index|[
literal|1
index|]
operator|<<
literal|16
operator|)
operator|+
operator|(
name|buf
index|[
literal|2
index|]
operator|<<
literal|8
operator|)
operator|+
name|buf
index|[
literal|3
index|]
expr_stmt|;
name|cs
operator|->
name|state_data
index|[
literal|1
index|]
operator|=
operator|(
name|prev
operator|<<
literal|8
operator|)
operator|+
name|state
expr_stmt|;
name|cs
operator|->
name|state_data
index|[
literal|2
index|]
operator|=
name|esc
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|_mibEnum
name|int
name|QJisCodec
operator|::
name|_mibEnum
parameter_list|()
block|{
return|return
literal|39
return|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|_name
name|QByteArray
name|QJisCodec
operator|::
name|_name
parameter_list|()
block|{
return|return
literal|"ISO-2022-JP"
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the codec's mime name. */
end_comment
begin_function
DECL|function|_aliases
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|QJisCodec
operator|::
name|_aliases
parameter_list|()
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|list
decl_stmt|;
name|list
operator|<<
literal|"JIS7"
expr_stmt|;
comment|// Qt 3 compat
return|return
name|list
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
