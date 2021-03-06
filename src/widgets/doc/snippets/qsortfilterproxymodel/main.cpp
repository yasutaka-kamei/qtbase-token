begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QObject
modifier|*
name|parent
init|=
operator|&
name|app
decl_stmt|;
name|QStringList
name|numbers
decl_stmt|;
name|numbers
operator|<<
literal|"One"
operator|<<
literal|"Two"
operator|<<
literal|"Three"
operator|<<
literal|"Four"
operator|<<
literal|"Five"
expr_stmt|;
name|QAbstractItemModel
modifier|*
name|stringListModel
init|=
operator|new
name|QStringListModel
argument_list|(
name|numbers
argument_list|,
name|parent
argument_list|)
decl_stmt|;
comment|//! [0]
name|QSortFilterProxyModel
modifier|*
name|filterModel
init|=
operator|new
name|QSortFilterProxyModel
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|filterModel
operator|->
name|setSourceModel
argument_list|(
name|stringListModel
argument_list|)
expr_stmt|;
comment|//! [0]
name|QWidget
modifier|*
name|window
init|=
operator|new
name|QWidget
decl_stmt|;
comment|//! [1]
name|QListView
modifier|*
name|filteredView
init|=
operator|new
name|QListView
decl_stmt|;
name|filteredView
operator|->
name|setModel
argument_list|(
name|filterModel
argument_list|)
expr_stmt|;
comment|//! [1]
name|filteredView
operator|->
name|setWindowTitle
argument_list|(
literal|"Filtered view onto a string list model"
argument_list|)
expr_stmt|;
name|QLineEdit
modifier|*
name|patternEditor
init|=
operator|new
name|QLineEdit
decl_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|patternEditor
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|filterModel
argument_list|,
name|SLOT
argument_list|(
name|setFilterRegExp
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|window
argument_list|)
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|filteredView
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|patternEditor
argument_list|)
expr_stmt|;
name|window
operator|->
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
