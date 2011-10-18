begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"stardelegate.h"
end_include
begin_include
include|#
directive|include
file|"stareditor.h"
end_include
begin_include
include|#
directive|include
file|"starrating.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|populateTableWidget
name|void
name|populateTableWidget
parameter_list|(
name|QTableWidget
modifier|*
name|tableWidget
parameter_list|)
block|{
specifier|static
specifier|const
struct|struct
block|{
specifier|const
name|char
modifier|*
name|title
decl_stmt|;
specifier|const
name|char
modifier|*
name|genre
decl_stmt|;
specifier|const
name|char
modifier|*
name|artist
decl_stmt|;
name|int
name|rating
decl_stmt|;
block|}
name|staticData
index|[]
init|=
block|{
comment|//! [0] //! [1]
block|{
literal|"Mass in B-Minor"
block|,
literal|"Baroque"
block|,
literal|"J.S. Bach"
block|,
literal|5
block|}
block|,
comment|//! [1]
block|{
literal|"Three More Foxes"
block|,
literal|"Jazz"
block|,
literal|"Maynard Ferguson"
block|,
literal|4
block|}
block|,
block|{
literal|"Sex Bomb"
block|,
literal|"Pop"
block|,
literal|"Tom Jones"
block|,
literal|3
block|}
block|,
block|{
literal|"Barbie Girl"
block|,
literal|"Pop"
block|,
literal|"Aqua"
block|,
literal|5
block|}
block|,
comment|//! [2]
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
comment|//! [2] //! [3]
block|}
struct|;
comment|//! [3] //! [4]
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|staticData
index|[
name|row
index|]
operator|.
name|title
operator|!=
literal|0
condition|;
operator|++
name|row
control|)
block|{
name|QTableWidgetItem
modifier|*
name|item0
init|=
operator|new
name|QTableWidgetItem
argument_list|(
name|staticData
index|[
name|row
index|]
operator|.
name|title
argument_list|)
decl_stmt|;
name|QTableWidgetItem
modifier|*
name|item1
init|=
operator|new
name|QTableWidgetItem
argument_list|(
name|staticData
index|[
name|row
index|]
operator|.
name|genre
argument_list|)
decl_stmt|;
name|QTableWidgetItem
modifier|*
name|item2
init|=
operator|new
name|QTableWidgetItem
argument_list|(
name|staticData
index|[
name|row
index|]
operator|.
name|artist
argument_list|)
decl_stmt|;
name|QTableWidgetItem
modifier|*
name|item3
init|=
operator|new
name|QTableWidgetItem
decl_stmt|;
name|item3
operator|->
name|setData
argument_list|(
literal|0
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|StarRating
argument_list|(
name|staticData
index|[
name|row
index|]
operator|.
name|rating
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|tableWidget
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|0
argument_list|,
name|item0
argument_list|)
expr_stmt|;
name|tableWidget
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|1
argument_list|,
name|item1
argument_list|)
expr_stmt|;
name|tableWidget
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|2
argument_list|,
name|item2
argument_list|)
expr_stmt|;
name|tableWidget
operator|->
name|setItem
argument_list|(
name|row
argument_list|,
literal|3
argument_list|,
name|item3
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
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
name|QTableWidget
name|tableWidget
argument_list|(
literal|4
argument_list|,
literal|4
argument_list|)
decl_stmt|;
name|tableWidget
operator|.
name|setItemDelegate
argument_list|(
operator|new
name|StarDelegate
argument_list|)
expr_stmt|;
name|tableWidget
operator|.
name|setEditTriggers
argument_list|(
name|QAbstractItemView
operator|::
name|DoubleClicked
operator||
name|QAbstractItemView
operator|::
name|SelectedClicked
argument_list|)
expr_stmt|;
name|tableWidget
operator|.
name|setSelectionBehavior
argument_list|(
name|QAbstractItemView
operator|::
name|SelectRows
argument_list|)
expr_stmt|;
name|QStringList
name|headerLabels
decl_stmt|;
name|headerLabels
operator|<<
literal|"Title"
operator|<<
literal|"Genre"
operator|<<
literal|"Artist"
operator|<<
literal|"Rating"
expr_stmt|;
name|tableWidget
operator|.
name|setHorizontalHeaderLabels
argument_list|(
name|headerLabels
argument_list|)
expr_stmt|;
name|populateTableWidget
argument_list|(
operator|&
name|tableWidget
argument_list|)
expr_stmt|;
name|tableWidget
operator|.
name|resizeColumnsToContents
argument_list|()
expr_stmt|;
name|tableWidget
operator|.
name|resize
argument_list|(
literal|500
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|tableWidget
operator|.
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
begin_comment
comment|//! [5]
end_comment
end_unit
