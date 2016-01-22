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
file|"mysortfilterproxymodel.h"
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_include
include|#
directive|include
file|"filterwidget.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|proxyModel
operator|=
operator|new
name|MySortFilterProxyModel
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
name|sourceView
operator|=
operator|new
name|QTreeView
expr_stmt|;
name|sourceView
operator|->
name|setRootIsDecorated
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|sourceView
operator|->
name|setAlternatingRowColors
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|//! [1]
name|QHBoxLayout
modifier|*
name|sourceLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
comment|//! [2]
name|sourceLayout
operator|->
name|addWidget
argument_list|(
name|sourceView
argument_list|)
expr_stmt|;
name|sourceGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Original Model"
argument_list|)
argument_list|)
expr_stmt|;
name|sourceGroupBox
operator|->
name|setLayout
argument_list|(
name|sourceLayout
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|filterWidget
operator|=
operator|new
name|FilterWidget
expr_stmt|;
name|filterWidget
operator|->
name|setText
argument_list|(
literal|"Grace|Sports"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|filterWidget
argument_list|,
operator|&
name|FilterWidget
operator|::
name|filterChanged
argument_list|,
name|this
argument_list|,
operator|&
name|Window
operator|::
name|textFilterChanged
argument_list|)
expr_stmt|;
name|filterPatternLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Filter pattern:"
argument_list|)
argument_list|)
expr_stmt|;
name|filterPatternLabel
operator|->
name|setBuddy
argument_list|(
name|filterWidget
argument_list|)
expr_stmt|;
name|fromDateEdit
operator|=
operator|new
name|QDateEdit
expr_stmt|;
name|fromDateEdit
operator|->
name|setDate
argument_list|(
name|QDate
argument_list|(
literal|1970
argument_list|,
literal|01
argument_list|,
literal|01
argument_list|)
argument_list|)
expr_stmt|;
name|fromLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"F&rom:"
argument_list|)
argument_list|)
expr_stmt|;
name|fromLabel
operator|->
name|setBuddy
argument_list|(
name|fromDateEdit
argument_list|)
expr_stmt|;
name|toDateEdit
operator|=
operator|new
name|QDateEdit
expr_stmt|;
name|toDateEdit
operator|->
name|setDate
argument_list|(
name|QDate
argument_list|(
literal|2099
argument_list|,
literal|12
argument_list|,
literal|31
argument_list|)
argument_list|)
expr_stmt|;
name|toLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&To:"
argument_list|)
argument_list|)
expr_stmt|;
name|toLabel
operator|->
name|setBuddy
argument_list|(
name|toDateEdit
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|filterWidget
argument_list|,
operator|&
name|QLineEdit
operator|::
name|textChanged
argument_list|,
name|this
argument_list|,
operator|&
name|Window
operator|::
name|textFilterChanged
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fromDateEdit
argument_list|,
operator|&
name|QDateTimeEdit
operator|::
name|dateChanged
argument_list|,
name|this
argument_list|,
operator|&
name|Window
operator|::
name|dateFilterChanged
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|toDateEdit
argument_list|,
operator|&
name|QDateTimeEdit
operator|::
name|dateChanged
argument_list|,
comment|//! [3] //! [4]
name|this
argument_list|,
operator|&
name|Window
operator|::
name|dateFilterChanged
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|proxyView
operator|=
operator|new
name|QTreeView
expr_stmt|;
name|proxyView
operator|->
name|setRootIsDecorated
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|proxyView
operator|->
name|setAlternatingRowColors
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|proxyView
operator|->
name|setModel
argument_list|(
name|proxyModel
argument_list|)
expr_stmt|;
name|proxyView
operator|->
name|setSortingEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|proxyView
operator|->
name|sortByColumn
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|AscendingOrder
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|proxyLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|proxyView
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|filterPatternLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|filterWidget
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|fromLabel
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|fromDateEdit
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|toLabel
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|proxyLayout
operator|->
name|addWidget
argument_list|(
name|toDateEdit
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|proxyGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Sorted/Filtered Model"
argument_list|)
argument_list|)
expr_stmt|;
name|proxyGroupBox
operator|->
name|setLayout
argument_list|(
name|proxyLayout
argument_list|)
expr_stmt|;
comment|//! [5]
comment|//! [6]
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|sourceGroupBox
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|proxyGroupBox
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Custom Sort/Filter Model"
argument_list|)
argument_list|)
expr_stmt|;
name|resize
argument_list|(
literal|500
argument_list|,
literal|450
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|setSourceModel
name|void
name|Window
operator|::
name|setSourceModel
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|)
block|{
name|proxyModel
operator|->
name|setSourceModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|sourceView
operator|->
name|setModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|textFilterChanged
name|void
name|Window
operator|::
name|textFilterChanged
parameter_list|()
block|{
name|QRegExp
name|regExp
argument_list|(
name|filterWidget
operator|->
name|text
argument_list|()
argument_list|,
name|filterWidget
operator|->
name|caseSensitivity
argument_list|()
argument_list|,
name|filterWidget
operator|->
name|patternSyntax
argument_list|()
argument_list|)
decl_stmt|;
name|proxyModel
operator|->
name|setFilterRegExp
argument_list|(
name|regExp
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|dateFilterChanged
name|void
name|Window
operator|::
name|dateFilterChanged
parameter_list|()
block|{
name|proxyModel
operator|->
name|setFilterMinimumDate
argument_list|(
name|fromDateEdit
operator|->
name|date
argument_list|()
argument_list|)
expr_stmt|;
name|proxyModel
operator|->
name|setFilterMaximumDate
argument_list|(
name|toDateEdit
operator|->
name|date
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
end_unit
