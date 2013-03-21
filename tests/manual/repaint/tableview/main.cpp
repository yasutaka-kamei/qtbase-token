begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"../shared/shared.h"
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QTableWidget>
end_include
begin_include
include|#
directive|include
file|<QPaintEvent>
end_include
begin_class
DECL|class|CellWidget
class|class
name|CellWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|CellWidget
name|CellWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{}
DECL|function|paintEvent
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
specifier|static
name|int
name|value
init|=
literal|200
decl_stmt|;
name|value
operator|=
operator|(
name|value
operator|+
literal|41
operator|)
operator|%
literal|205
operator|+
literal|50
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
name|event
operator|->
name|rect
argument_list|()
argument_list|,
name|QColor
operator|::
name|fromHsv
argument_list|(
literal|100
argument_list|,
literal|255
argument_list|,
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
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
modifier|*
name|argv
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
decl_stmt|;
comment|//    tableWidget.setAttribute(Qt::WA_StaticContents);
name|tableWidget
operator|.
name|viewport
argument_list|()
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_StaticContents
argument_list|)
expr_stmt|;
name|tableWidget
operator|.
name|setRowCount
argument_list|(
literal|15
argument_list|)
expr_stmt|;
name|tableWidget
operator|.
name|setColumnCount
argument_list|(
literal|4
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
literal|15
condition|;
operator|++
name|row
control|)
for|for
control|(
name|int
name|col
init|=
literal|0
init|;
name|col
operator|<
literal|4
condition|;
operator|++
name|col
control|)
comment|//        tableWidget.setCellWidget(row, col, new StaticWidget());
name|tableWidget
operator|.
name|setCellWidget
argument_list|(
name|row
argument_list|,
name|col
argument_list|,
operator|new
name|CellWidget
argument_list|()
argument_list|)
expr_stmt|;
name|tableWidget
operator|.
name|resize
argument_list|(
literal|400
argument_list|,
literal|600
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
end_unit
