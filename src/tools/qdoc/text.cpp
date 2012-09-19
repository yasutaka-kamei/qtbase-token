begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   text.cpp */
end_comment
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|"text.h"
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|Text
name|Text
operator|::
name|Text
parameter_list|()
member_init_list|:
name|first
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|last
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|Text
name|Text
operator|::
name|Text
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
member_init_list|:
name|first
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|last
argument_list|(
literal|0
argument_list|)
block|{
name|operator
name|<<
parameter_list|(
name|str
parameter_list|)
function_decl|;
block|}
end_constructor
begin_constructor
DECL|function|Text
name|Text
operator|::
name|Text
parameter_list|(
specifier|const
name|Text
modifier|&
name|text
parameter_list|)
member_init_list|:
name|first
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|last
argument_list|(
literal|0
argument_list|)
block|{
name|operator
name|=
parameter_list|(
name|text
parameter_list|)
function_decl|;
block|}
end_constructor
begin_destructor
DECL|function|~Text
name|Text
operator|::
name|~
name|Text
parameter_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|operator =
name|Text
modifier|&
name|Text
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|Text
modifier|&
name|text
parameter_list|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|text
condition|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|operator
name|<<
parameter_list|(
name|text
parameter_list|)
function_decl|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|Text
modifier|&
name|Text
operator|::
name|operator
name|<<
parameter_list|(
name|Atom
operator|::
name|Type
name|atomType
parameter_list|)
block|{
return|return
name|operator
name|<<
argument_list|(
name|Atom
argument_list|(
name|atomType
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|Text
modifier|&
name|Text
operator|::
name|operator
name|<<
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
block|{
return|return
name|operator
name|<<
argument_list|(
name|Atom
argument_list|(
name|Atom
operator|::
name|String
argument_list|,
name|string
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|Text
modifier|&
name|Text
operator|::
name|operator
name|<<
parameter_list|(
specifier|const
name|Atom
modifier|&
name|atom
parameter_list|)
block|{
if|if
condition|(
name|atom
operator|.
name|count
argument_list|()
operator|<
literal|2
condition|)
block|{
if|if
condition|(
name|first
operator|==
literal|0
condition|)
block|{
name|first
operator|=
operator|new
name|Atom
argument_list|(
name|atom
operator|.
name|type
argument_list|()
argument_list|,
name|atom
operator|.
name|string
argument_list|()
argument_list|)
expr_stmt|;
name|last
operator|=
name|first
expr_stmt|;
block|}
else|else
name|last
operator|=
operator|new
name|Atom
argument_list|(
name|last
argument_list|,
name|atom
operator|.
name|type
argument_list|()
argument_list|,
name|atom
operator|.
name|string
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|first
operator|==
literal|0
condition|)
block|{
name|first
operator|=
operator|new
name|Atom
argument_list|(
name|atom
operator|.
name|type
argument_list|()
argument_list|,
name|atom
operator|.
name|string
argument_list|()
argument_list|,
name|atom
operator|.
name|string
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|last
operator|=
name|first
expr_stmt|;
block|}
else|else
name|last
operator|=
operator|new
name|Atom
argument_list|(
name|last
argument_list|,
name|atom
operator|.
name|type
argument_list|()
argument_list|,
name|atom
operator|.
name|string
argument_list|()
argument_list|,
name|atom
operator|.
name|string
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|Text
modifier|&
name|Text
operator|::
name|operator
name|<<
parameter_list|(
specifier|const
name|Text
modifier|&
name|text
parameter_list|)
block|{
specifier|const
name|Atom
modifier|*
name|atom
init|=
name|text
operator|.
name|firstAtom
argument_list|()
decl_stmt|;
while|while
condition|(
name|atom
operator|!=
literal|0
condition|)
block|{
name|operator
name|<<
argument_list|(
operator|*
name|atom
argument_list|)
expr_stmt|;
name|atom
operator|=
name|atom
operator|->
name|next
argument_list|()
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_function
DECL|function|stripFirstAtom
name|void
name|Text
operator|::
name|stripFirstAtom
parameter_list|()
block|{
if|if
condition|(
name|first
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|first
operator|==
name|last
condition|)
name|last
operator|=
literal|0
expr_stmt|;
name|Atom
modifier|*
name|oldFirst
init|=
name|first
decl_stmt|;
name|first
operator|=
name|first
operator|->
name|next
argument_list|()
expr_stmt|;
operator|delete
name|oldFirst
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|stripLastAtom
name|void
name|Text
operator|::
name|stripLastAtom
parameter_list|()
block|{
if|if
condition|(
name|last
operator|!=
literal|0
condition|)
block|{
name|Atom
modifier|*
name|oldLast
init|=
name|last
decl_stmt|;
if|if
condition|(
name|first
operator|==
name|last
condition|)
block|{
name|first
operator|=
literal|0
expr_stmt|;
name|last
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|last
operator|=
name|first
expr_stmt|;
while|while
condition|(
name|last
operator|->
name|next
argument_list|()
operator|!=
name|oldLast
condition|)
name|last
operator|=
name|last
operator|->
name|next
argument_list|()
expr_stmt|;
name|last
operator|->
name|setNext
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
operator|delete
name|oldLast
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|toString
name|QString
name|Text
operator|::
name|toString
parameter_list|()
specifier|const
block|{
name|QString
name|str
decl_stmt|;
specifier|const
name|Atom
modifier|*
name|atom
init|=
name|firstAtom
argument_list|()
decl_stmt|;
while|while
condition|(
name|atom
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|atom
operator|->
name|type
argument_list|()
operator|==
name|Atom
operator|::
name|String
operator|||
name|atom
operator|->
name|type
argument_list|()
operator|==
name|Atom
operator|::
name|AutoLink
operator|||
name|atom
operator|->
name|type
argument_list|()
operator|==
name|Atom
operator|::
name|C
operator|||
name|atom
operator|->
name|type
argument_list|()
operator|==
name|Atom
operator|::
name|GuidLink
condition|)
name|str
operator|+=
name|atom
operator|->
name|string
argument_list|()
expr_stmt|;
name|atom
operator|=
name|atom
operator|->
name|next
argument_list|()
expr_stmt|;
block|}
return|return
name|str
return|;
block|}
end_function
begin_function
DECL|function|subText
name|Text
name|Text
operator|::
name|subText
parameter_list|(
name|Atom
operator|::
name|Type
name|left
parameter_list|,
name|Atom
operator|::
name|Type
name|right
parameter_list|,
specifier|const
name|Atom
modifier|*
name|from
parameter_list|,
name|bool
name|inclusive
parameter_list|)
specifier|const
block|{
specifier|const
name|Atom
modifier|*
name|begin
init|=
name|from
condition|?
name|from
else|:
name|firstAtom
argument_list|()
decl_stmt|;
specifier|const
name|Atom
modifier|*
name|end
decl_stmt|;
while|while
condition|(
name|begin
operator|!=
literal|0
operator|&&
name|begin
operator|->
name|type
argument_list|()
operator|!=
name|left
condition|)
name|begin
operator|=
name|begin
operator|->
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|begin
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|inclusive
condition|)
name|begin
operator|=
name|begin
operator|->
name|next
argument_list|()
expr_stmt|;
block|}
name|end
operator|=
name|begin
expr_stmt|;
while|while
condition|(
name|end
operator|!=
literal|0
operator|&&
name|end
operator|->
name|type
argument_list|()
operator|!=
name|right
condition|)
name|end
operator|=
name|end
operator|->
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|end
operator|==
literal|0
condition|)
name|begin
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|inclusive
condition|)
name|end
operator|=
name|end
operator|->
name|next
argument_list|()
expr_stmt|;
return|return
name|subText
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|sectionHeading
name|Text
name|Text
operator|::
name|sectionHeading
parameter_list|(
specifier|const
name|Atom
modifier|*
name|sectionLeft
parameter_list|)
block|{
if|if
condition|(
name|sectionLeft
operator|!=
literal|0
condition|)
block|{
specifier|const
name|Atom
modifier|*
name|begin
init|=
name|sectionLeft
decl_stmt|;
while|while
condition|(
name|begin
operator|!=
literal|0
operator|&&
name|begin
operator|->
name|type
argument_list|()
operator|!=
name|Atom
operator|::
name|SectionHeadingLeft
condition|)
name|begin
operator|=
name|begin
operator|->
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|begin
operator|!=
literal|0
condition|)
name|begin
operator|=
name|begin
operator|->
name|next
argument_list|()
expr_stmt|;
specifier|const
name|Atom
modifier|*
name|end
init|=
name|begin
decl_stmt|;
while|while
condition|(
name|end
operator|!=
literal|0
operator|&&
name|end
operator|->
name|type
argument_list|()
operator|!=
name|Atom
operator|::
name|SectionHeadingRight
condition|)
name|end
operator|=
name|end
operator|->
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|end
operator|!=
literal|0
condition|)
return|return
name|subText
argument_list|(
name|begin
argument_list|,
name|end
argument_list|)
return|;
block|}
return|return
name|Text
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|sectionHeadingAtom
specifier|const
name|Atom
modifier|*
name|Text
operator|::
name|sectionHeadingAtom
parameter_list|(
specifier|const
name|Atom
modifier|*
name|sectionLeft
parameter_list|)
block|{
if|if
condition|(
name|sectionLeft
operator|!=
literal|0
condition|)
block|{
specifier|const
name|Atom
modifier|*
name|begin
init|=
name|sectionLeft
decl_stmt|;
while|while
condition|(
name|begin
operator|!=
literal|0
operator|&&
name|begin
operator|->
name|type
argument_list|()
operator|!=
name|Atom
operator|::
name|SectionHeadingLeft
condition|)
name|begin
operator|=
name|begin
operator|->
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|begin
operator|!=
literal|0
condition|)
name|begin
operator|=
name|begin
operator|->
name|next
argument_list|()
expr_stmt|;
return|return
name|begin
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|dump
name|void
name|Text
operator|::
name|dump
parameter_list|()
specifier|const
block|{
specifier|const
name|Atom
modifier|*
name|atom
init|=
name|firstAtom
argument_list|()
decl_stmt|;
while|while
condition|(
name|atom
operator|!=
literal|0
condition|)
block|{
name|QString
name|str
init|=
name|atom
operator|->
name|string
argument_list|()
decl_stmt|;
name|str
operator|.
name|replace
argument_list|(
literal|"\\"
argument_list|,
literal|"\\\\"
argument_list|)
expr_stmt|;
name|str
operator|.
name|replace
argument_list|(
literal|"\""
argument_list|,
literal|"\\\""
argument_list|)
expr_stmt|;
name|str
operator|.
name|replace
argument_list|(
literal|"\n"
argument_list|,
literal|"\\n"
argument_list|)
expr_stmt|;
name|str
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
literal|"[^\x20-\x7e]"
argument_list|)
argument_list|,
literal|"?"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|=
literal|" \""
operator|+
name|str
operator|+
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    %-15s%s\n"
argument_list|,
name|atom
operator|->
name|typeString
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|,
name|str
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|atom
operator|=
name|atom
operator|->
name|next
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|subText
name|Text
name|Text
operator|::
name|subText
parameter_list|(
specifier|const
name|Atom
modifier|*
name|begin
parameter_list|,
specifier|const
name|Atom
modifier|*
name|end
parameter_list|)
block|{
name|Text
name|text
decl_stmt|;
if|if
condition|(
name|begin
operator|!=
literal|0
condition|)
block|{
while|while
condition|(
name|begin
operator|!=
name|end
condition|)
block|{
name|text
operator|<<
operator|*
name|begin
expr_stmt|;
name|begin
operator|=
name|begin
operator|->
name|next
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|text
return|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|Text
operator|::
name|clear
parameter_list|()
block|{
while|while
condition|(
name|first
operator|!=
literal|0
condition|)
block|{
name|Atom
modifier|*
name|atom
init|=
name|first
decl_stmt|;
name|first
operator|=
name|first
operator|->
name|next
argument_list|()
expr_stmt|;
operator|delete
name|atom
expr_stmt|;
block|}
name|first
operator|=
literal|0
expr_stmt|;
name|last
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|compare
name|int
name|Text
operator|::
name|compare
parameter_list|(
specifier|const
name|Text
modifier|&
name|text1
parameter_list|,
specifier|const
name|Text
modifier|&
name|text2
parameter_list|)
block|{
if|if
condition|(
name|text1
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|text2
operator|.
name|isEmpty
argument_list|()
condition|?
literal|0
else|:
operator|-
literal|1
return|;
if|if
condition|(
name|text2
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|1
return|;
specifier|const
name|Atom
modifier|*
name|atom1
init|=
name|text1
operator|.
name|firstAtom
argument_list|()
decl_stmt|;
specifier|const
name|Atom
modifier|*
name|atom2
init|=
name|text2
operator|.
name|firstAtom
argument_list|()
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|atom1
operator|->
name|type
argument_list|()
operator|!=
name|atom2
operator|->
name|type
argument_list|()
condition|)
return|return
operator|(
name|int
operator|)
name|atom1
operator|->
name|type
argument_list|()
operator|-
operator|(
name|int
operator|)
name|atom2
operator|->
name|type
argument_list|()
return|;
name|int
name|cmp
init|=
name|QString
operator|::
name|compare
argument_list|(
name|atom1
operator|->
name|string
argument_list|()
argument_list|,
name|atom2
operator|->
name|string
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|cmp
operator|!=
literal|0
condition|)
return|return
name|cmp
return|;
if|if
condition|(
name|atom1
operator|==
name|text1
operator|.
name|lastAtom
argument_list|()
condition|)
return|return
name|atom2
operator|==
name|text2
operator|.
name|lastAtom
argument_list|()
condition|?
literal|0
else|:
operator|-
literal|1
return|;
if|if
condition|(
name|atom2
operator|==
name|text2
operator|.
name|lastAtom
argument_list|()
condition|)
return|return
literal|1
return|;
name|atom1
operator|=
name|atom1
operator|->
name|next
argument_list|()
expr_stmt|;
name|atom2
operator|=
name|atom2
operator|->
name|next
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
