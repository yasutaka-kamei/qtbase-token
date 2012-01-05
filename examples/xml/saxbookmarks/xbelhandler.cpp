begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"xbelhandler.h"
end_include
begin_constructor
DECL|function|XbelHandler
name|XbelHandler
operator|::
name|XbelHandler
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
name|item
operator|=
literal|0
expr_stmt|;
name|metXbelTag
operator|=
literal|false
expr_stmt|;
name|QStyle
modifier|*
name|style
init|=
name|treeWidget
operator|->
name|style
argument_list|()
decl_stmt|;
name|folderIcon
operator|.
name|addPixmap
argument_list|(
name|style
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_DirClosedIcon
argument_list|)
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|Off
argument_list|)
expr_stmt|;
name|folderIcon
operator|.
name|addPixmap
argument_list|(
name|style
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_DirOpenIcon
argument_list|)
argument_list|,
name|QIcon
operator|::
name|Normal
argument_list|,
name|QIcon
operator|::
name|On
argument_list|)
expr_stmt|;
name|bookmarkIcon
operator|.
name|addPixmap
argument_list|(
name|style
operator|->
name|standardPixmap
argument_list|(
name|QStyle
operator|::
name|SP_FileIcon
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|startElement
name|bool
name|XbelHandler
operator|::
name|startElement
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* namespaceURI */
parameter_list|,
specifier|const
name|QString
modifier|&
comment|/* localName */
parameter_list|,
specifier|const
name|QString
modifier|&
name|qName
parameter_list|,
specifier|const
name|QXmlAttributes
modifier|&
name|attributes
parameter_list|)
block|{
if|if
condition|(
operator|!
name|metXbelTag
operator|&&
name|qName
operator|!=
literal|"xbel"
condition|)
block|{
name|errorStr
operator|=
name|QObject
operator|::
name|tr
argument_list|(
literal|"The file is not an XBEL file."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|qName
operator|==
literal|"xbel"
condition|)
block|{
name|QString
name|version
init|=
name|attributes
operator|.
name|value
argument_list|(
literal|"version"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|version
operator|.
name|isEmpty
argument_list|()
operator|&&
name|version
operator|!=
literal|"1.0"
condition|)
block|{
name|errorStr
operator|=
name|QObject
operator|::
name|tr
argument_list|(
literal|"The file is not an XBEL version 1.0 file."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|metXbelTag
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|qName
operator|==
literal|"folder"
condition|)
block|{
name|item
operator|=
name|createChildItem
argument_list|(
name|qName
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFlags
argument_list|(
name|item
operator|->
name|flags
argument_list|()
operator||
name|Qt
operator|::
name|ItemIsEditable
argument_list|)
expr_stmt|;
name|item
operator|->
name|setIcon
argument_list|(
literal|0
argument_list|,
name|folderIcon
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Folder"
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|folded
init|=
operator|(
name|attributes
operator|.
name|value
argument_list|(
literal|"folded"
argument_list|)
operator|!=
literal|"no"
operator|)
decl_stmt|;
name|treeWidget
operator|->
name|setItemExpanded
argument_list|(
name|item
argument_list|,
operator|!
name|folded
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|qName
operator|==
literal|"bookmark"
condition|)
block|{
name|item
operator|=
name|createChildItem
argument_list|(
name|qName
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFlags
argument_list|(
name|item
operator|->
name|flags
argument_list|()
operator||
name|Qt
operator|::
name|ItemIsEditable
argument_list|)
expr_stmt|;
name|item
operator|->
name|setIcon
argument_list|(
literal|0
argument_list|,
name|bookmarkIcon
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Unknown title"
argument_list|)
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|1
argument_list|,
name|attributes
operator|.
name|value
argument_list|(
literal|"href"
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|qName
operator|==
literal|"separator"
condition|)
block|{
name|item
operator|=
name|createChildItem
argument_list|(
name|qName
argument_list|)
expr_stmt|;
name|item
operator|->
name|setFlags
argument_list|(
name|item
operator|->
name|flags
argument_list|()
operator|&
operator|~
name|Qt
operator|::
name|ItemIsSelectable
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|QString
argument_list|(
literal|30
argument_list|,
literal|0xB7
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|currentText
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|endElement
name|bool
name|XbelHandler
operator|::
name|endElement
parameter_list|(
specifier|const
name|QString
modifier|&
comment|/* namespaceURI */
parameter_list|,
specifier|const
name|QString
modifier|&
comment|/* localName */
parameter_list|,
specifier|const
name|QString
modifier|&
name|qName
parameter_list|)
block|{
if|if
condition|(
name|qName
operator|==
literal|"title"
condition|)
block|{
if|if
condition|(
name|item
condition|)
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|currentText
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|qName
operator|==
literal|"folder"
operator|||
name|qName
operator|==
literal|"bookmark"
operator|||
name|qName
operator|==
literal|"separator"
condition|)
block|{
name|item
operator|=
name|item
operator|->
name|parent
argument_list|()
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|characters
name|bool
name|XbelHandler
operator|::
name|characters
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
block|{
name|currentText
operator|+=
name|str
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|fatalError
name|bool
name|XbelHandler
operator|::
name|fatalError
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|treeWidget
operator|->
name|window
argument_list|()
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"SAX Bookmarks"
argument_list|)
argument_list|,
name|QObject
operator|::
name|tr
argument_list|(
literal|"Parse error at line %1, column %2:\n"
literal|"%3"
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|lineNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|columnNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|message
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|errorString
name|QString
name|XbelHandler
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
return|return
name|errorStr
return|;
block|}
end_function
begin_function
DECL|function|createChildItem
name|QTreeWidgetItem
modifier|*
name|XbelHandler
operator|::
name|createChildItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|tagName
parameter_list|)
block|{
name|QTreeWidgetItem
modifier|*
name|childItem
decl_stmt|;
if|if
condition|(
name|item
condition|)
block|{
name|childItem
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|childItem
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|treeWidget
argument_list|)
expr_stmt|;
block|}
name|childItem
operator|->
name|setData
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|UserRole
argument_list|,
name|tagName
argument_list|)
expr_stmt|;
return|return
name|childItem
return|;
block|}
end_function
end_unit
