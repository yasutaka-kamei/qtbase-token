begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   text.h */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TEXT_H
end_ifndef
begin_define
DECL|macro|TEXT_H
define|#
directive|define
name|TEXT_H
end_define
begin_include
include|#
directive|include
file|"atom.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Text
block|{
name|public
label|:
name|Text
argument_list|()
expr_stmt|;
name|explicit
name|Text
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
function_decl|;
name|Text
argument_list|(
specifier|const
name|Text
operator|&
name|text
argument_list|)
expr_stmt|;
operator|~
name|Text
argument_list|()
expr_stmt|;
name|Text
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Text
operator|&
name|text
operator|)
decl_stmt|;
name|Atom
modifier|*
name|firstAtom
parameter_list|()
block|{
return|return
name|first
return|;
block|}
name|Atom
modifier|*
name|lastAtom
parameter_list|()
block|{
return|return
name|last
return|;
block|}
name|Text
operator|&
name|operator
operator|<<
operator|(
name|Atom
operator|::
name|AtomType
name|atomType
operator|)
expr_stmt|;
name|Text
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|QString
operator|&
name|string
operator|)
expr_stmt|;
name|Text
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|Atom
operator|&
name|atom
operator|)
expr_stmt|;
name|Text
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|LinkAtom
operator|&
name|atom
operator|)
expr_stmt|;
name|Text
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|Text
operator|&
name|text
operator|)
expr_stmt|;
name|void
name|stripFirstAtom
parameter_list|()
function_decl|;
name|void
name|stripLastAtom
parameter_list|()
function_decl|;
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|first
operator|==
literal|0
return|;
block|}
name|QString
name|toString
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|Atom
operator|*
name|firstAtom
argument_list|()
specifier|const
block|{
return|return
name|first
return|;
block|}
specifier|const
name|Atom
operator|*
name|lastAtom
argument_list|()
specifier|const
block|{
return|return
name|last
return|;
block|}
name|Text
name|subText
argument_list|(
name|Atom
operator|::
name|AtomType
name|left
argument_list|,
name|Atom
operator|::
name|AtomType
name|right
argument_list|,
specifier|const
name|Atom
operator|*
name|from
operator|=
literal|0
argument_list|,
name|bool
name|inclusive
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
specifier|static
name|Text
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
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|Text
name|sectionHeading
parameter_list|(
specifier|const
name|Atom
modifier|*
name|sectionBegin
parameter_list|)
function_decl|;
specifier|static
specifier|const
name|Atom
modifier|*
name|sectionHeadingAtom
parameter_list|(
specifier|const
name|Atom
modifier|*
name|sectionLeft
parameter_list|)
function_decl|;
specifier|static
name|int
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
function_decl|;
name|private
label|:
name|Atom
modifier|*
name|first
decl_stmt|;
name|Atom
modifier|*
name|last
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Text
operator|&
name|text1
operator|,
specifier|const
name|Text
operator|&
name|text2
operator|)
block|{
return|return
name|Text
operator|::
name|compare
argument_list|(
name|text1
argument_list|,
name|text2
argument_list|)
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Text
operator|&
name|text1
operator|,
specifier|const
name|Text
operator|&
name|text2
operator|)
block|{
return|return
name|Text
operator|::
name|compare
argument_list|(
name|text1
argument_list|,
name|text2
argument_list|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Text
operator|&
name|text1
operator|,
specifier|const
name|Text
operator|&
name|text2
operator|)
block|{
return|return
name|Text
operator|::
name|compare
argument_list|(
name|text1
argument_list|,
name|text2
argument_list|)
operator|<
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|Text
operator|&
name|text1
operator|,
specifier|const
name|Text
operator|&
name|text2
operator|)
block|{
return|return
name|Text
operator|::
name|compare
argument_list|(
name|text1
argument_list|,
name|text2
argument_list|)
operator|<=
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|Text
operator|&
name|text1
operator|,
specifier|const
name|Text
operator|&
name|text2
operator|)
block|{
return|return
name|Text
operator|::
name|compare
argument_list|(
name|text1
argument_list|,
name|text2
argument_list|)
operator|>
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|Text
operator|&
name|text1
operator|,
specifier|const
name|Text
operator|&
name|text2
operator|)
block|{
return|return
name|Text
operator|::
name|compare
argument_list|(
name|text1
argument_list|,
name|text2
argument_list|)
operator|>=
literal|0
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
