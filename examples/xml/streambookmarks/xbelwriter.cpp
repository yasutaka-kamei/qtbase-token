begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"xbelwriter.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|XbelWriter
name|XbelWriter
operator|::
name|XbelWriter
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
block|{
name|xml
operator|.
name|setAutoFormatting
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|writeFile
name|bool
name|XbelWriter
operator|::
name|writeFile
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
block|{
name|xml
operator|.
name|setDevice
argument_list|(
name|device
argument_list|)
expr_stmt|;
name|xml
operator|.
name|writeStartDocument
argument_list|()
expr_stmt|;
name|xml
operator|.
name|writeDTD
argument_list|(
literal|"<!DOCTYPE xbel>"
argument_list|)
expr_stmt|;
name|xml
operator|.
name|writeStartElement
argument_list|(
literal|"xbel"
argument_list|)
expr_stmt|;
name|xml
operator|.
name|writeAttribute
argument_list|(
literal|"version"
argument_list|,
literal|"1.0"
argument_list|)
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
name|writeItem
argument_list|(
name|treeWidget
operator|->
name|topLevelItem
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|xml
operator|.
name|writeEndDocument
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|writeItem
name|void
name|XbelWriter
operator|::
name|writeItem
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
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
name|xml
operator|.
name|writeStartElement
argument_list|(
name|tagName
argument_list|)
expr_stmt|;
name|xml
operator|.
name|writeAttribute
argument_list|(
literal|"folded"
argument_list|,
name|folded
condition|?
literal|"yes"
else|:
literal|"no"
argument_list|)
expr_stmt|;
name|xml
operator|.
name|writeTextElement
argument_list|(
literal|"title"
argument_list|,
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
argument_list|)
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
name|writeItem
argument_list|(
name|item
operator|->
name|child
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|xml
operator|.
name|writeEndElement
argument_list|()
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
name|xml
operator|.
name|writeStartElement
argument_list|(
name|tagName
argument_list|)
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
name|xml
operator|.
name|writeAttribute
argument_list|(
literal|"href"
argument_list|,
name|item
operator|->
name|text
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|xml
operator|.
name|writeTextElement
argument_list|(
literal|"title"
argument_list|,
name|item
operator|->
name|text
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|xml
operator|.
name|writeEndElement
argument_list|()
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
name|xml
operator|.
name|writeEmptyElement
argument_list|(
name|tagName
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [2]
end_comment
end_unit
