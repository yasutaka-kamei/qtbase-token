begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   codechunk.cpp */
end_comment
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"codechunk.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enumerator|Other
DECL|enumerator|Alnum
DECL|enumerator|Gizmo
DECL|enumerator|Comma
DECL|enumerator|LParen
DECL|enumerator|RParen
DECL|enumerator|RAngle
DECL|enumerator|Colon
name|enum
type|{
name|Other
decl_stmt|,
name|Alnum
decl_stmt|,
name|Gizmo
decl_stmt|,
name|Comma
decl_stmt|,
name|LParen
decl_stmt|,
name|RParen
decl_stmt|,
name|RAngle
decl_stmt|,
name|Colon
end_decl_stmt
begin_comment
unit|};
comment|// entries 128 and above are Other
end_comment
begin_decl_stmt
DECL|variable|charCategory
specifier|static
specifier|const
name|int
name|charCategory
index|[
literal|256
index|]
init|=
block|{
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
comment|//          !       "       #       $       %&       '
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Gizmo
block|,
name|Gizmo
block|,
name|Other
block|,
comment|//  (       )       *       +       ,       -       .       /
name|LParen
block|,
name|RParen
block|,
name|Gizmo
block|,
name|Gizmo
block|,
name|Comma
block|,
name|Other
block|,
name|Other
block|,
name|Gizmo
block|,
comment|//  0       1       2       3       4       5       6       7
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
comment|//  8       9       :       ;<       =>       ?
name|Alnum
block|,
name|Alnum
block|,
name|Colon
block|,
name|Other
block|,
name|Other
block|,
name|Gizmo
block|,
name|RAngle
block|,
name|Gizmo
block|,
comment|//  @       A       B       C       D       E       F       G
name|Other
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
comment|//  H       I       J       K       L       M       N       O
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
comment|//  P       Q       R       S       T       U       V       W
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
comment|//  X       Y       Z       [       \       ]       ^       _
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Other
block|,
name|Other
block|,
name|Other
block|,
name|Gizmo
block|,
name|Alnum
block|,
comment|//  `       a       b       c       d       e       f       g
name|Other
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
comment|//  h       i       j       k       l       m       n       o
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
comment|//  p       q       r       s       t       u       v       w
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
comment|//  x       y       z       {       |       }       ~
name|Alnum
block|,
name|Alnum
block|,
name|Alnum
block|,
name|LParen
block|,
name|Gizmo
block|,
name|RParen
block|,
name|Other
block|,
name|Other
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|needSpace
specifier|static
specifier|const
name|bool
name|needSpace
index|[
literal|8
index|]
index|[
literal|8
index|]
init|=
block|{
comment|/*        [      a      +      ,      (       )>      :  */
comment|/* [ */
block|{
literal|false
block|,
literal|false
block|,
literal|false
block|,
literal|false
block|,
literal|false
block|,
literal|true
block|,
literal|false
block|,
literal|false
block|}
block|,
comment|/* a */
block|{
literal|false
block|,
literal|true
block|,
literal|true
block|,
literal|false
block|,
literal|false
block|,
literal|true
block|,
literal|false
block|,
literal|false
block|}
block|,
comment|/* + */
block|{
literal|false
block|,
literal|true
block|,
literal|false
block|,
literal|false
block|,
literal|false
block|,
literal|true
block|,
literal|false
block|,
literal|true
block|}
block|,
comment|/* , */
block|{
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|true
block|}
block|,
comment|/* ( */
block|{
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|false
block|,
literal|true
block|,
literal|false
block|,
literal|true
block|,
literal|true
block|}
block|,
comment|/* ) */
block|{
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|false
block|,
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|true
block|}
block|,
comment|/*> */
block|{
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|false
block|,
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|false
block|}
block|,
comment|/* : */
block|{
literal|false
block|,
literal|false
block|,
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|true
block|,
literal|false
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|category
specifier|static
name|int
name|category
parameter_list|(
name|QChar
name|ch
parameter_list|)
block|{
return|return
name|charCategory
index|[
operator|(
name|int
operator|)
name|ch
operator|.
name|toLatin1
argument_list|()
index|]
return|;
block|}
end_function
begin_constructor
DECL|function|CodeChunk
name|CodeChunk
operator|::
name|CodeChunk
parameter_list|()
member_init_list|:
name|hotspot
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|CodeChunk
name|CodeChunk
operator|::
name|CodeChunk
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
member_init_list|:
name|s
argument_list|(
name|str
argument_list|)
member_init_list|,
name|hotspot
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|append
name|void
name|CodeChunk
operator|::
name|append
parameter_list|(
specifier|const
name|QString
modifier|&
name|lexeme
parameter_list|)
block|{
if|if
condition|(
operator|!
name|s
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|lexeme
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|/*           Should there be a space or not between the code chunk so far and the           new lexeme?         */
name|int
name|cat1
init|=
name|category
argument_list|(
name|s
operator|.
name|at
argument_list|(
name|s
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|int
name|cat2
init|=
name|category
argument_list|(
name|lexeme
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|needSpace
index|[
name|cat1
index|]
index|[
name|cat2
index|]
condition|)
name|s
operator|+=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
block|}
name|s
operator|+=
name|lexeme
expr_stmt|;
block|}
end_function
begin_function
DECL|function|appendHotspot
name|void
name|CodeChunk
operator|::
name|appendHotspot
parameter_list|()
block|{
comment|/*       The first hotspot is the right one.     */
if|if
condition|(
name|hotspot
operator|==
operator|-
literal|1
condition|)
name|hotspot
operator|=
name|s
operator|.
name|length
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toString
name|QString
name|CodeChunk
operator|::
name|toString
parameter_list|()
specifier|const
block|{
return|return
name|s
return|;
block|}
end_function
begin_function
DECL|function|toPath
name|QStringList
name|CodeChunk
operator|::
name|toPath
parameter_list|()
specifier|const
block|{
name|QString
name|t
init|=
name|s
decl_stmt|;
name|t
operator|.
name|remove
argument_list|(
name|QRegExp
argument_list|(
name|QLatin1String
argument_list|(
literal|"<([^<>]|<([^<>]|<[^<>]*>)*>)*>"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|t
operator|.
name|split
argument_list|(
name|QLatin1String
argument_list|(
literal|"::"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
