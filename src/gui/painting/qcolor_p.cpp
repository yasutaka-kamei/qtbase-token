begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_include
include|#
directive|include
file|"qrgb.h"
end_include
begin_include
include|#
directive|include
file|"qstringlist.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|h2i
specifier|static
specifier|inline
name|int
name|h2i
parameter_list|(
name|char
name|hex
parameter_list|)
block|{
if|if
condition|(
name|hex
operator|>=
literal|'0'
operator|&&
name|hex
operator|<=
literal|'9'
condition|)
return|return
name|hex
operator|-
literal|'0'
return|;
if|if
condition|(
name|hex
operator|>=
literal|'a'
operator|&&
name|hex
operator|<=
literal|'f'
condition|)
return|return
name|hex
operator|-
literal|'a'
operator|+
literal|10
return|;
if|if
condition|(
name|hex
operator|>=
literal|'A'
operator|&&
name|hex
operator|<=
literal|'F'
condition|)
return|return
name|hex
operator|-
literal|'A'
operator|+
literal|10
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|hex2int
specifier|static
specifier|inline
name|int
name|hex2int
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
return|return
operator|(
name|h2i
argument_list|(
name|s
index|[
literal|0
index|]
argument_list|)
operator|<<
literal|4
operator|)
operator||
name|h2i
argument_list|(
name|s
index|[
literal|1
index|]
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|hex2int
specifier|static
specifier|inline
name|int
name|hex2int
parameter_list|(
name|char
name|s
parameter_list|)
block|{
name|int
name|h
init|=
name|h2i
argument_list|(
name|s
argument_list|)
decl_stmt|;
return|return
operator|(
name|h
operator|<<
literal|4
operator|)
operator||
name|h
return|;
block|}
end_function
begin_function
DECL|function|qt_get_hex_rgb
name|bool
name|qt_get_hex_rgb
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|QRgb
modifier|*
name|rgb
parameter_list|)
block|{
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|!=
literal|'#'
condition|)
return|return
literal|false
return|;
name|name
operator|++
expr_stmt|;
name|int
name|len
init|=
name|qstrlen
argument_list|(
name|name
argument_list|)
decl_stmt|;
name|int
name|a
decl_stmt|,
name|r
decl_stmt|,
name|g
decl_stmt|,
name|b
decl_stmt|;
name|a
operator|=
literal|255
expr_stmt|;
if|if
condition|(
name|len
operator|==
literal|12
condition|)
block|{
name|r
operator|=
name|hex2int
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|g
operator|=
name|hex2int
argument_list|(
name|name
operator|+
literal|4
argument_list|)
expr_stmt|;
name|b
operator|=
name|hex2int
argument_list|(
name|name
operator|+
literal|8
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|len
operator|==
literal|9
condition|)
block|{
name|r
operator|=
name|hex2int
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|g
operator|=
name|hex2int
argument_list|(
name|name
operator|+
literal|3
argument_list|)
expr_stmt|;
name|b
operator|=
name|hex2int
argument_list|(
name|name
operator|+
literal|6
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|len
operator|==
literal|8
condition|)
block|{
name|a
operator|=
name|hex2int
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|r
operator|=
name|hex2int
argument_list|(
name|name
operator|+
literal|2
argument_list|)
expr_stmt|;
name|g
operator|=
name|hex2int
argument_list|(
name|name
operator|+
literal|4
argument_list|)
expr_stmt|;
name|b
operator|=
name|hex2int
argument_list|(
name|name
operator|+
literal|6
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|len
operator|==
literal|6
condition|)
block|{
name|r
operator|=
name|hex2int
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|g
operator|=
name|hex2int
argument_list|(
name|name
operator|+
literal|2
argument_list|)
expr_stmt|;
name|b
operator|=
name|hex2int
argument_list|(
name|name
operator|+
literal|4
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|len
operator|==
literal|3
condition|)
block|{
name|r
operator|=
name|hex2int
argument_list|(
name|name
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|g
operator|=
name|hex2int
argument_list|(
name|name
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|b
operator|=
name|hex2int
argument_list|(
name|name
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|r
operator|=
name|g
operator|=
name|b
operator|=
operator|-
literal|1
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|uint
operator|)
name|r
operator|>
literal|255
operator|||
operator|(
name|uint
operator|)
name|g
operator|>
literal|255
operator|||
operator|(
name|uint
operator|)
name|b
operator|>
literal|255
operator|||
operator|(
name|uint
operator|)
name|a
operator|>
literal|255
condition|)
block|{
operator|*
name|rgb
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
operator|*
name|rgb
operator|=
name|qRgba
argument_list|(
name|r
argument_list|,
name|g
argument_list|,
name|b
argument_list|,
name|a
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|qt_get_hex_rgb
name|bool
name|qt_get_hex_rgb
parameter_list|(
specifier|const
name|QChar
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|,
name|QRgb
modifier|*
name|rgb
parameter_list|)
block|{
if|if
condition|(
name|len
operator|>
literal|13
condition|)
return|return
literal|false
return|;
name|char
name|tmp
index|[
literal|16
index|]
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
operator|++
name|i
control|)
name|tmp
index|[
name|i
index|]
operator|=
name|str
index|[
name|i
index|]
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
name|tmp
index|[
name|len
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|qt_get_hex_rgb
argument_list|(
name|tmp
argument_list|,
name|rgb
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COLORNAMES
end_ifndef
begin_comment
comment|/*   CSS color names = SVG 1.0 color names + transparent (rgba(0,0,0,0)) */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|rgb
end_ifdef
begin_undef
DECL|macro|rgb
undef|#
directive|undef
name|rgb
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|rgb
define|#
directive|define
name|rgb
parameter_list|(
name|r
parameter_list|,
name|g
parameter_list|,
name|b
parameter_list|)
value|(0xff000000 | (r<< 16) |  (g<< 8) | b)
end_define
begin_struct
DECL|struct|RGBData
specifier|static
specifier|const
struct|struct
name|RGBData
block|{
DECL|member|name
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
DECL|member|value
name|uint
name|value
decl_stmt|;
block|}
DECL|variable|rgbTbl
name|rgbTbl
index|[]
init|=
block|{
block|{
literal|"aliceblue"
block|,
name|rgb
argument_list|(
literal|240
argument_list|,
literal|248
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"antiquewhite"
block|,
name|rgb
argument_list|(
literal|250
argument_list|,
literal|235
argument_list|,
literal|215
argument_list|)
block|}
block|,
block|{
literal|"aqua"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"aquamarine"
block|,
name|rgb
argument_list|(
literal|127
argument_list|,
literal|255
argument_list|,
literal|212
argument_list|)
block|}
block|,
block|{
literal|"azure"
block|,
name|rgb
argument_list|(
literal|240
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"beige"
block|,
name|rgb
argument_list|(
literal|245
argument_list|,
literal|245
argument_list|,
literal|220
argument_list|)
block|}
block|,
block|{
literal|"bisque"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|228
argument_list|,
literal|196
argument_list|)
block|}
block|,
block|{
literal|"black"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"blanchedalmond"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|235
argument_list|,
literal|205
argument_list|)
block|}
block|,
block|{
literal|"blue"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"blueviolet"
block|,
name|rgb
argument_list|(
literal|138
argument_list|,
literal|43
argument_list|,
literal|226
argument_list|)
block|}
block|,
block|{
literal|"brown"
block|,
name|rgb
argument_list|(
literal|165
argument_list|,
literal|42
argument_list|,
literal|42
argument_list|)
block|}
block|,
block|{
literal|"burlywood"
block|,
name|rgb
argument_list|(
literal|222
argument_list|,
literal|184
argument_list|,
literal|135
argument_list|)
block|}
block|,
block|{
literal|"cadetblue"
block|,
name|rgb
argument_list|(
literal|95
argument_list|,
literal|158
argument_list|,
literal|160
argument_list|)
block|}
block|,
block|{
literal|"chartreuse"
block|,
name|rgb
argument_list|(
literal|127
argument_list|,
literal|255
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"chocolate"
block|,
name|rgb
argument_list|(
literal|210
argument_list|,
literal|105
argument_list|,
literal|30
argument_list|)
block|}
block|,
block|{
literal|"coral"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|127
argument_list|,
literal|80
argument_list|)
block|}
block|,
block|{
literal|"cornflowerblue"
block|,
name|rgb
argument_list|(
literal|100
argument_list|,
literal|149
argument_list|,
literal|237
argument_list|)
block|}
block|,
block|{
literal|"cornsilk"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|248
argument_list|,
literal|220
argument_list|)
block|}
block|,
block|{
literal|"crimson"
block|,
name|rgb
argument_list|(
literal|220
argument_list|,
literal|20
argument_list|,
literal|60
argument_list|)
block|}
block|,
block|{
literal|"cyan"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"darkblue"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|139
argument_list|)
block|}
block|,
block|{
literal|"darkcyan"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|139
argument_list|,
literal|139
argument_list|)
block|}
block|,
block|{
literal|"darkgoldenrod"
block|,
name|rgb
argument_list|(
literal|184
argument_list|,
literal|134
argument_list|,
literal|11
argument_list|)
block|}
block|,
block|{
literal|"darkgray"
block|,
name|rgb
argument_list|(
literal|169
argument_list|,
literal|169
argument_list|,
literal|169
argument_list|)
block|}
block|,
block|{
literal|"darkgreen"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|100
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"darkgrey"
block|,
name|rgb
argument_list|(
literal|169
argument_list|,
literal|169
argument_list|,
literal|169
argument_list|)
block|}
block|,
block|{
literal|"darkkhaki"
block|,
name|rgb
argument_list|(
literal|189
argument_list|,
literal|183
argument_list|,
literal|107
argument_list|)
block|}
block|,
block|{
literal|"darkmagenta"
block|,
name|rgb
argument_list|(
literal|139
argument_list|,
literal|0
argument_list|,
literal|139
argument_list|)
block|}
block|,
block|{
literal|"darkolivegreen"
block|,
name|rgb
argument_list|(
literal|85
argument_list|,
literal|107
argument_list|,
literal|47
argument_list|)
block|}
block|,
block|{
literal|"darkorange"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|140
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"darkorchid"
block|,
name|rgb
argument_list|(
literal|153
argument_list|,
literal|50
argument_list|,
literal|204
argument_list|)
block|}
block|,
block|{
literal|"darkred"
block|,
name|rgb
argument_list|(
literal|139
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"darksalmon"
block|,
name|rgb
argument_list|(
literal|233
argument_list|,
literal|150
argument_list|,
literal|122
argument_list|)
block|}
block|,
block|{
literal|"darkseagreen"
block|,
name|rgb
argument_list|(
literal|143
argument_list|,
literal|188
argument_list|,
literal|143
argument_list|)
block|}
block|,
block|{
literal|"darkslateblue"
block|,
name|rgb
argument_list|(
literal|72
argument_list|,
literal|61
argument_list|,
literal|139
argument_list|)
block|}
block|,
block|{
literal|"darkslategray"
block|,
name|rgb
argument_list|(
literal|47
argument_list|,
literal|79
argument_list|,
literal|79
argument_list|)
block|}
block|,
block|{
literal|"darkslategrey"
block|,
name|rgb
argument_list|(
literal|47
argument_list|,
literal|79
argument_list|,
literal|79
argument_list|)
block|}
block|,
block|{
literal|"darkturquoise"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|206
argument_list|,
literal|209
argument_list|)
block|}
block|,
block|{
literal|"darkviolet"
block|,
name|rgb
argument_list|(
literal|148
argument_list|,
literal|0
argument_list|,
literal|211
argument_list|)
block|}
block|,
block|{
literal|"deeppink"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|20
argument_list|,
literal|147
argument_list|)
block|}
block|,
block|{
literal|"deepskyblue"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|191
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"dimgray"
block|,
name|rgb
argument_list|(
literal|105
argument_list|,
literal|105
argument_list|,
literal|105
argument_list|)
block|}
block|,
block|{
literal|"dimgrey"
block|,
name|rgb
argument_list|(
literal|105
argument_list|,
literal|105
argument_list|,
literal|105
argument_list|)
block|}
block|,
block|{
literal|"dodgerblue"
block|,
name|rgb
argument_list|(
literal|30
argument_list|,
literal|144
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"firebrick"
block|,
name|rgb
argument_list|(
literal|178
argument_list|,
literal|34
argument_list|,
literal|34
argument_list|)
block|}
block|,
block|{
literal|"floralwhite"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|250
argument_list|,
literal|240
argument_list|)
block|}
block|,
block|{
literal|"forestgreen"
block|,
name|rgb
argument_list|(
literal|34
argument_list|,
literal|139
argument_list|,
literal|34
argument_list|)
block|}
block|,
block|{
literal|"fuchsia"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"gainsboro"
block|,
name|rgb
argument_list|(
literal|220
argument_list|,
literal|220
argument_list|,
literal|220
argument_list|)
block|}
block|,
block|{
literal|"ghostwhite"
block|,
name|rgb
argument_list|(
literal|248
argument_list|,
literal|248
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"gold"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|215
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"goldenrod"
block|,
name|rgb
argument_list|(
literal|218
argument_list|,
literal|165
argument_list|,
literal|32
argument_list|)
block|}
block|,
block|{
literal|"gray"
block|,
name|rgb
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
block|}
block|,
block|{
literal|"green"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|128
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"greenyellow"
block|,
name|rgb
argument_list|(
literal|173
argument_list|,
literal|255
argument_list|,
literal|47
argument_list|)
block|}
block|,
block|{
literal|"grey"
block|,
name|rgb
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
block|}
block|,
block|{
literal|"honeydew"
block|,
name|rgb
argument_list|(
literal|240
argument_list|,
literal|255
argument_list|,
literal|240
argument_list|)
block|}
block|,
block|{
literal|"hotpink"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|105
argument_list|,
literal|180
argument_list|)
block|}
block|,
block|{
literal|"indianred"
block|,
name|rgb
argument_list|(
literal|205
argument_list|,
literal|92
argument_list|,
literal|92
argument_list|)
block|}
block|,
block|{
literal|"indigo"
block|,
name|rgb
argument_list|(
literal|75
argument_list|,
literal|0
argument_list|,
literal|130
argument_list|)
block|}
block|,
block|{
literal|"ivory"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|240
argument_list|)
block|}
block|,
block|{
literal|"khaki"
block|,
name|rgb
argument_list|(
literal|240
argument_list|,
literal|230
argument_list|,
literal|140
argument_list|)
block|}
block|,
block|{
literal|"lavender"
block|,
name|rgb
argument_list|(
literal|230
argument_list|,
literal|230
argument_list|,
literal|250
argument_list|)
block|}
block|,
block|{
literal|"lavenderblush"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|240
argument_list|,
literal|245
argument_list|)
block|}
block|,
block|{
literal|"lawngreen"
block|,
name|rgb
argument_list|(
literal|124
argument_list|,
literal|252
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"lemonchiffon"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|250
argument_list|,
literal|205
argument_list|)
block|}
block|,
block|{
literal|"lightblue"
block|,
name|rgb
argument_list|(
literal|173
argument_list|,
literal|216
argument_list|,
literal|230
argument_list|)
block|}
block|,
block|{
literal|"lightcoral"
block|,
name|rgb
argument_list|(
literal|240
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
block|}
block|,
block|{
literal|"lightcyan"
block|,
name|rgb
argument_list|(
literal|224
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"lightgoldenrodyellow"
block|,
name|rgb
argument_list|(
literal|250
argument_list|,
literal|250
argument_list|,
literal|210
argument_list|)
block|}
block|,
block|{
literal|"lightgray"
block|,
name|rgb
argument_list|(
literal|211
argument_list|,
literal|211
argument_list|,
literal|211
argument_list|)
block|}
block|,
block|{
literal|"lightgreen"
block|,
name|rgb
argument_list|(
literal|144
argument_list|,
literal|238
argument_list|,
literal|144
argument_list|)
block|}
block|,
block|{
literal|"lightgrey"
block|,
name|rgb
argument_list|(
literal|211
argument_list|,
literal|211
argument_list|,
literal|211
argument_list|)
block|}
block|,
block|{
literal|"lightpink"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|182
argument_list|,
literal|193
argument_list|)
block|}
block|,
block|{
literal|"lightsalmon"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|160
argument_list|,
literal|122
argument_list|)
block|}
block|,
block|{
literal|"lightseagreen"
block|,
name|rgb
argument_list|(
literal|32
argument_list|,
literal|178
argument_list|,
literal|170
argument_list|)
block|}
block|,
block|{
literal|"lightskyblue"
block|,
name|rgb
argument_list|(
literal|135
argument_list|,
literal|206
argument_list|,
literal|250
argument_list|)
block|}
block|,
block|{
literal|"lightslategray"
block|,
name|rgb
argument_list|(
literal|119
argument_list|,
literal|136
argument_list|,
literal|153
argument_list|)
block|}
block|,
block|{
literal|"lightslategrey"
block|,
name|rgb
argument_list|(
literal|119
argument_list|,
literal|136
argument_list|,
literal|153
argument_list|)
block|}
block|,
block|{
literal|"lightsteelblue"
block|,
name|rgb
argument_list|(
literal|176
argument_list|,
literal|196
argument_list|,
literal|222
argument_list|)
block|}
block|,
block|{
literal|"lightyellow"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|224
argument_list|)
block|}
block|,
block|{
literal|"lime"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|255
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"limegreen"
block|,
name|rgb
argument_list|(
literal|50
argument_list|,
literal|205
argument_list|,
literal|50
argument_list|)
block|}
block|,
block|{
literal|"linen"
block|,
name|rgb
argument_list|(
literal|250
argument_list|,
literal|240
argument_list|,
literal|230
argument_list|)
block|}
block|,
block|{
literal|"magenta"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"maroon"
block|,
name|rgb
argument_list|(
literal|128
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"mediumaquamarine"
block|,
name|rgb
argument_list|(
literal|102
argument_list|,
literal|205
argument_list|,
literal|170
argument_list|)
block|}
block|,
block|{
literal|"mediumblue"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|205
argument_list|)
block|}
block|,
block|{
literal|"mediumorchid"
block|,
name|rgb
argument_list|(
literal|186
argument_list|,
literal|85
argument_list|,
literal|211
argument_list|)
block|}
block|,
block|{
literal|"mediumpurple"
block|,
name|rgb
argument_list|(
literal|147
argument_list|,
literal|112
argument_list|,
literal|219
argument_list|)
block|}
block|,
block|{
literal|"mediumseagreen"
block|,
name|rgb
argument_list|(
literal|60
argument_list|,
literal|179
argument_list|,
literal|113
argument_list|)
block|}
block|,
block|{
literal|"mediumslateblue"
block|,
name|rgb
argument_list|(
literal|123
argument_list|,
literal|104
argument_list|,
literal|238
argument_list|)
block|}
block|,
block|{
literal|"mediumspringgreen"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|250
argument_list|,
literal|154
argument_list|)
block|}
block|,
block|{
literal|"mediumturquoise"
block|,
name|rgb
argument_list|(
literal|72
argument_list|,
literal|209
argument_list|,
literal|204
argument_list|)
block|}
block|,
block|{
literal|"mediumvioletred"
block|,
name|rgb
argument_list|(
literal|199
argument_list|,
literal|21
argument_list|,
literal|133
argument_list|)
block|}
block|,
block|{
literal|"midnightblue"
block|,
name|rgb
argument_list|(
literal|25
argument_list|,
literal|25
argument_list|,
literal|112
argument_list|)
block|}
block|,
block|{
literal|"mintcream"
block|,
name|rgb
argument_list|(
literal|245
argument_list|,
literal|255
argument_list|,
literal|250
argument_list|)
block|}
block|,
block|{
literal|"mistyrose"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|228
argument_list|,
literal|225
argument_list|)
block|}
block|,
block|{
literal|"moccasin"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|228
argument_list|,
literal|181
argument_list|)
block|}
block|,
block|{
literal|"navajowhite"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|222
argument_list|,
literal|173
argument_list|)
block|}
block|,
block|{
literal|"navy"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|128
argument_list|)
block|}
block|,
block|{
literal|"oldlace"
block|,
name|rgb
argument_list|(
literal|253
argument_list|,
literal|245
argument_list|,
literal|230
argument_list|)
block|}
block|,
block|{
literal|"olive"
block|,
name|rgb
argument_list|(
literal|128
argument_list|,
literal|128
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"olivedrab"
block|,
name|rgb
argument_list|(
literal|107
argument_list|,
literal|142
argument_list|,
literal|35
argument_list|)
block|}
block|,
block|{
literal|"orange"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|165
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"orangered"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|69
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"orchid"
block|,
name|rgb
argument_list|(
literal|218
argument_list|,
literal|112
argument_list|,
literal|214
argument_list|)
block|}
block|,
block|{
literal|"palegoldenrod"
block|,
name|rgb
argument_list|(
literal|238
argument_list|,
literal|232
argument_list|,
literal|170
argument_list|)
block|}
block|,
block|{
literal|"palegreen"
block|,
name|rgb
argument_list|(
literal|152
argument_list|,
literal|251
argument_list|,
literal|152
argument_list|)
block|}
block|,
block|{
literal|"paleturquoise"
block|,
name|rgb
argument_list|(
literal|175
argument_list|,
literal|238
argument_list|,
literal|238
argument_list|)
block|}
block|,
block|{
literal|"palevioletred"
block|,
name|rgb
argument_list|(
literal|219
argument_list|,
literal|112
argument_list|,
literal|147
argument_list|)
block|}
block|,
block|{
literal|"papayawhip"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|239
argument_list|,
literal|213
argument_list|)
block|}
block|,
block|{
literal|"peachpuff"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|218
argument_list|,
literal|185
argument_list|)
block|}
block|,
block|{
literal|"peru"
block|,
name|rgb
argument_list|(
literal|205
argument_list|,
literal|133
argument_list|,
literal|63
argument_list|)
block|}
block|,
block|{
literal|"pink"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|192
argument_list|,
literal|203
argument_list|)
block|}
block|,
block|{
literal|"plum"
block|,
name|rgb
argument_list|(
literal|221
argument_list|,
literal|160
argument_list|,
literal|221
argument_list|)
block|}
block|,
block|{
literal|"powderblue"
block|,
name|rgb
argument_list|(
literal|176
argument_list|,
literal|224
argument_list|,
literal|230
argument_list|)
block|}
block|,
block|{
literal|"purple"
block|,
name|rgb
argument_list|(
literal|128
argument_list|,
literal|0
argument_list|,
literal|128
argument_list|)
block|}
block|,
block|{
literal|"red"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"rosybrown"
block|,
name|rgb
argument_list|(
literal|188
argument_list|,
literal|143
argument_list|,
literal|143
argument_list|)
block|}
block|,
block|{
literal|"royalblue"
block|,
name|rgb
argument_list|(
literal|65
argument_list|,
literal|105
argument_list|,
literal|225
argument_list|)
block|}
block|,
block|{
literal|"saddlebrown"
block|,
name|rgb
argument_list|(
literal|139
argument_list|,
literal|69
argument_list|,
literal|19
argument_list|)
block|}
block|,
block|{
literal|"salmon"
block|,
name|rgb
argument_list|(
literal|250
argument_list|,
literal|128
argument_list|,
literal|114
argument_list|)
block|}
block|,
block|{
literal|"sandybrown"
block|,
name|rgb
argument_list|(
literal|244
argument_list|,
literal|164
argument_list|,
literal|96
argument_list|)
block|}
block|,
block|{
literal|"seagreen"
block|,
name|rgb
argument_list|(
literal|46
argument_list|,
literal|139
argument_list|,
literal|87
argument_list|)
block|}
block|,
block|{
literal|"seashell"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|245
argument_list|,
literal|238
argument_list|)
block|}
block|,
block|{
literal|"sienna"
block|,
name|rgb
argument_list|(
literal|160
argument_list|,
literal|82
argument_list|,
literal|45
argument_list|)
block|}
block|,
block|{
literal|"silver"
block|,
name|rgb
argument_list|(
literal|192
argument_list|,
literal|192
argument_list|,
literal|192
argument_list|)
block|}
block|,
block|{
literal|"skyblue"
block|,
name|rgb
argument_list|(
literal|135
argument_list|,
literal|206
argument_list|,
literal|235
argument_list|)
block|}
block|,
block|{
literal|"slateblue"
block|,
name|rgb
argument_list|(
literal|106
argument_list|,
literal|90
argument_list|,
literal|205
argument_list|)
block|}
block|,
block|{
literal|"slategray"
block|,
name|rgb
argument_list|(
literal|112
argument_list|,
literal|128
argument_list|,
literal|144
argument_list|)
block|}
block|,
block|{
literal|"slategrey"
block|,
name|rgb
argument_list|(
literal|112
argument_list|,
literal|128
argument_list|,
literal|144
argument_list|)
block|}
block|,
block|{
literal|"snow"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|250
argument_list|,
literal|250
argument_list|)
block|}
block|,
block|{
literal|"springgreen"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|255
argument_list|,
literal|127
argument_list|)
block|}
block|,
block|{
literal|"steelblue"
block|,
name|rgb
argument_list|(
literal|70
argument_list|,
literal|130
argument_list|,
literal|180
argument_list|)
block|}
block|,
block|{
literal|"tan"
block|,
name|rgb
argument_list|(
literal|210
argument_list|,
literal|180
argument_list|,
literal|140
argument_list|)
block|}
block|,
block|{
literal|"teal"
block|,
name|rgb
argument_list|(
literal|0
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
block|}
block|,
block|{
literal|"thistle"
block|,
name|rgb
argument_list|(
literal|216
argument_list|,
literal|191
argument_list|,
literal|216
argument_list|)
block|}
block|,
block|{
literal|"tomato"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|99
argument_list|,
literal|71
argument_list|)
block|}
block|,
block|{
literal|"transparent"
block|,
literal|0
block|}
block|,
block|{
literal|"turquoise"
block|,
name|rgb
argument_list|(
literal|64
argument_list|,
literal|224
argument_list|,
literal|208
argument_list|)
block|}
block|,
block|{
literal|"violet"
block|,
name|rgb
argument_list|(
literal|238
argument_list|,
literal|130
argument_list|,
literal|238
argument_list|)
block|}
block|,
block|{
literal|"wheat"
block|,
name|rgb
argument_list|(
literal|245
argument_list|,
literal|222
argument_list|,
literal|179
argument_list|)
block|}
block|,
block|{
literal|"white"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
block|}
block|,
block|{
literal|"whitesmoke"
block|,
name|rgb
argument_list|(
literal|245
argument_list|,
literal|245
argument_list|,
literal|245
argument_list|)
block|}
block|,
block|{
literal|"yellow"
block|,
name|rgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|0
argument_list|)
block|}
block|,
block|{
literal|"yellowgreen"
block|,
name|rgb
argument_list|(
literal|154
argument_list|,
literal|205
argument_list|,
literal|50
argument_list|)
block|}
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|rgbTblSize
specifier|static
specifier|const
name|int
name|rgbTblSize
init|=
sizeof|sizeof
argument_list|(
name|rgbTbl
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|RGBData
argument_list|)
decl_stmt|;
end_decl_stmt
begin_undef
DECL|macro|rgb
undef|#
directive|undef
name|rgb
end_undef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1600
end_if
begin_function
DECL|function|operator <
specifier|inline
name|bool
name|operator
name|<
parameter_list|(
specifier|const
name|RGBData
modifier|&
name|data1
parameter_list|,
specifier|const
name|RGBData
modifier|&
name|data2
parameter_list|)
block|{
return|return
name|qstrcmp
argument_list|(
name|data1
operator|.
name|name
argument_list|,
name|data2
operator|.
name|name
argument_list|)
operator|<
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|operator <
specifier|inline
name|bool
name|operator
name|<
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|RGBData
modifier|&
name|data
parameter_list|)
block|{
return|return
name|qstrcmp
argument_list|(
name|name
argument_list|,
name|data
operator|.
name|name
argument_list|)
operator|<
literal|0
return|;
block|}
end_function
begin_function
DECL|function|operator <
specifier|inline
name|bool
name|operator
name|<
parameter_list|(
specifier|const
name|RGBData
modifier|&
name|data
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
name|qstrcmp
argument_list|(
name|data
operator|.
name|name
argument_list|,
name|name
argument_list|)
operator|<
literal|0
return|;
block|}
end_function
begin_function
DECL|function|get_named_rgb
specifier|static
name|bool
name|get_named_rgb
parameter_list|(
specifier|const
name|char
modifier|*
name|name_no_space
parameter_list|,
name|QRgb
modifier|*
name|rgb
parameter_list|)
block|{
name|QByteArray
name|name
init|=
name|QByteArray
argument_list|(
name|name_no_space
argument_list|)
operator|.
name|toLower
argument_list|()
decl_stmt|;
specifier|const
name|RGBData
modifier|*
name|r
init|=
name|std
operator|::
name|lower_bound
argument_list|(
name|rgbTbl
argument_list|,
name|rgbTbl
operator|+
name|rgbTblSize
argument_list|,
name|name
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|r
operator|!=
name|rgbTbl
operator|+
name|rgbTblSize
operator|)
operator|&&
operator|!
operator|(
name|name
operator|.
name|constData
argument_list|()
operator|<
operator|*
name|r
operator|)
condition|)
block|{
operator|*
name|rgb
operator|=
name|r
operator|->
name|value
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
DECL|function|qt_get_named_rgb
name|bool
name|qt_get_named_rgb
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|QRgb
modifier|*
name|rgb
parameter_list|)
block|{
name|int
name|len
init|=
name|int
argument_list|(
name|strlen
argument_list|(
name|name
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|len
operator|>
literal|255
condition|)
return|return
literal|false
return|;
name|char
name|name_no_space
index|[
literal|256
index|]
decl_stmt|;
name|int
name|pos
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
name|len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|name
index|[
name|i
index|]
operator|!=
literal|'\t'
operator|&&
name|name
index|[
name|i
index|]
operator|!=
literal|' '
condition|)
name|name_no_space
index|[
name|pos
operator|++
index|]
operator|=
name|name
index|[
name|i
index|]
expr_stmt|;
block|}
name|name_no_space
index|[
name|pos
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|get_named_rgb
argument_list|(
name|name_no_space
argument_list|,
name|rgb
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_get_named_rgb
name|bool
name|qt_get_named_rgb
parameter_list|(
specifier|const
name|QChar
modifier|*
name|name
parameter_list|,
name|int
name|len
parameter_list|,
name|QRgb
modifier|*
name|rgb
parameter_list|)
block|{
if|if
condition|(
name|len
operator|>
literal|255
condition|)
return|return
literal|false
return|;
name|char
name|name_no_space
index|[
literal|256
index|]
decl_stmt|;
name|int
name|pos
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
name|len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|name
index|[
name|i
index|]
operator|!=
name|QLatin1Char
argument_list|(
literal|'\t'
argument_list|)
operator|&&
name|name
index|[
name|i
index|]
operator|!=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
condition|)
name|name_no_space
index|[
name|pos
operator|++
index|]
operator|=
name|name
index|[
name|i
index|]
operator|.
name|toLatin1
argument_list|()
expr_stmt|;
block|}
name|name_no_space
index|[
name|pos
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|get_named_rgb
argument_list|(
name|name_no_space
argument_list|,
name|rgb
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_get_rgb_val
name|uint
name|qt_get_rgb_val
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|QRgb
name|r
init|=
literal|0
decl_stmt|;
name|qt_get_named_rgb
argument_list|(
name|name
argument_list|,
operator|&
name|r
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function
begin_function
DECL|function|qt_get_colornames
name|QStringList
name|qt_get_colornames
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|QStringList
name|lst
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|rgbTblSize
condition|;
name|i
operator|++
control|)
name|lst
operator|<<
name|QLatin1String
argument_list|(
name|rgbTbl
index|[
name|i
index|]
operator|.
name|name
argument_list|)
expr_stmt|;
return|return
name|lst
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
DECL|function|qt_get_named_rgb
name|bool
name|qt_get_named_rgb
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|QRgb
modifier|*
parameter_list|)
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|qt_get_rgb_val
name|uint
name|qt_get_rgb_val
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_get_colornames
name|QStringList
name|qt_get_colornames
parameter_list|()
block|{
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_COLORNAMES
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
