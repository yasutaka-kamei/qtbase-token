begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"xbelgenerator.h"
end_include
begin_constructor
DECL|function|XbelGenerator
name|XbelGenerator
operator|::
name|XbelGenerator
parameter_list|(
name|QTreeWidget
modifier|*
name|treeWidget
parameter_list|)
member_init_list|:
name|treeWidget
argument_list|(
name|treeWidget
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|write
name|bool
name|XbelGenerator
operator|::
name|write
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
name|out
operator|.
name|setDevice
argument_list|(
name|device
argument_list|)
expr_stmt|;
name|out
operator|.
name|setCodec
argument_list|(
literal|"UTF-8"
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
operator|<<
literal|"<!DOCTYPE xbel>\n"
operator|<<
literal|"<xbel version=\"1.0\">\n"
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|treeWidget
operator|->
name|topLevelItemCount
argument_list|()
condition|;
operator|++
name|i
control|)
name|generateItem
argument_list|(
name|treeWidget
operator|->
name|topLevelItem
argument_list|(
name|i
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|"</xbel>\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|indent
name|QString
name|XbelGenerator
operator|::
name|indent
parameter_list|(
name|int
name|depth
parameter_list|)
block|{
specifier|const
name|int
name|IndentSize
init|=
literal|4
decl_stmt|;
return|return
name|QString
argument_list|(
name|IndentSize
operator|*
name|depth
argument_list|,
literal|' '
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|escapedText
name|QString
name|XbelGenerator
operator|::
name|escapedText
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
block|{
name|QString
name|result
init|=
name|str
decl_stmt|;
name|result
operator|.
name|replace
argument_list|(
literal|"&"
argument_list|,
literal|"&amp;"
argument_list|)
expr_stmt|;
name|result
operator|.
name|replace
argument_list|(
literal|"<"
argument_list|,
literal|"&lt;"
argument_list|)
expr_stmt|;
name|result
operator|.
name|replace
argument_list|(
literal|">"
argument_list|,
literal|"&gt;"
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|escapedAttribute
name|QString
name|XbelGenerator
operator|::
name|escapedAttribute
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
block|{
name|QString
name|result
init|=
name|escapedText
argument_list|(
name|str
argument_list|)
decl_stmt|;
name|result
operator|.
name|replace
argument_list|(
literal|"\""
argument_list|,
literal|"&quot;"
argument_list|)
expr_stmt|;
name|result
operator|.
name|prepend
argument_list|(
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|generateItem
name|void
name|XbelGenerator
operator|::
name|generateItem
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|,
name|int
name|depth
parameter_list|)
block|{
name|QString
name|tagName
init|=
name|item
operator|->
name|data
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
if|if
condition|(
name|tagName
operator|==
literal|"folder"
condition|)
block|{
name|bool
name|folded
init|=
operator|!
name|treeWidget
operator|->
name|isItemExpanded
argument_list|(
name|item
argument_list|)
decl_stmt|;
name|out
operator|<<
name|indent
argument_list|(
name|depth
argument_list|)
operator|<<
literal|"<folder folded=\""
operator|<<
operator|(
name|folded
condition|?
literal|"yes"
else|:
literal|"no"
operator|)
operator|<<
literal|"\">\n"
operator|<<
name|indent
argument_list|(
name|depth
operator|+
literal|1
argument_list|)
operator|<<
literal|"<title>"
operator|<<
name|escapedText
argument_list|(
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|"</title>\n"
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|item
operator|->
name|childCount
argument_list|()
condition|;
operator|++
name|i
control|)
name|generateItem
argument_list|(
name|item
operator|->
name|child
argument_list|(
name|i
argument_list|)
argument_list|,
name|depth
operator|+
literal|1
argument_list|)
expr_stmt|;
name|out
operator|<<
name|indent
argument_list|(
name|depth
argument_list|)
operator|<<
literal|"</folder>\n"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|tagName
operator|==
literal|"bookmark"
condition|)
block|{
name|out
operator|<<
name|indent
argument_list|(
name|depth
argument_list|)
operator|<<
literal|"<bookmark"
expr_stmt|;
if|if
condition|(
operator|!
name|item
operator|->
name|text
argument_list|(
literal|1
argument_list|)
operator|.
name|isEmpty
argument_list|()
condition|)
name|out
operator|<<
literal|" href="
operator|<<
name|escapedAttribute
argument_list|(
name|item
operator|->
name|text
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|out
operator|<<
literal|">\n"
operator|<<
name|indent
argument_list|(
name|depth
operator|+
literal|1
argument_list|)
operator|<<
literal|"<title>"
operator|<<
name|escapedText
argument_list|(
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|<<
literal|"</title>\n"
operator|<<
name|indent
argument_list|(
name|depth
argument_list|)
operator|<<
literal|"</bookmark>\n"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|tagName
operator|==
literal|"separator"
condition|)
block|{
name|out
operator|<<
name|indent
argument_list|(
name|depth
argument_list|)
operator|<<
literal|"<separator/>\n"
expr_stmt|;
block|}
block|}
end_function
end_unit
