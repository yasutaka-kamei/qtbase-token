begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"spreadsheetitem.h"
end_include
begin_constructor
DECL|function|SpreadSheetItem
name|SpreadSheetItem
operator|::
name|SpreadSheetItem
parameter_list|()
member_init_list|:
name|QTableWidgetItem
argument_list|()
member_init_list|,
name|isResolving
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|SpreadSheetItem
name|SpreadSheetItem
operator|::
name|SpreadSheetItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
member_init_list|:
name|QTableWidgetItem
argument_list|(
name|text
argument_list|)
member_init_list|,
name|isResolving
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|clone
name|QTableWidgetItem
modifier|*
name|SpreadSheetItem
operator|::
name|clone
parameter_list|()
specifier|const
block|{
name|SpreadSheetItem
modifier|*
name|item
init|=
operator|new
name|SpreadSheetItem
argument_list|()
decl_stmt|;
operator|*
name|item
operator|=
operator|*
name|this
expr_stmt|;
return|return
name|item
return|;
block|}
end_function
begin_function
DECL|function|data
name|QVariant
name|SpreadSheetItem
operator|::
name|data
parameter_list|(
name|int
name|role
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|EditRole
operator|||
name|role
operator|==
name|Qt
operator|::
name|StatusTipRole
condition|)
return|return
name|formula
argument_list|()
return|;
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|DisplayRole
condition|)
return|return
name|display
argument_list|()
return|;
name|QString
name|t
init|=
name|display
argument_list|()
operator|.
name|toString
argument_list|()
decl_stmt|;
name|bool
name|isNumber
init|=
literal|false
decl_stmt|;
name|int
name|number
init|=
name|t
operator|.
name|toInt
argument_list|(
operator|&
name|isNumber
argument_list|)
decl_stmt|;
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|TextColorRole
condition|)
block|{
if|if
condition|(
operator|!
name|isNumber
condition|)
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
argument_list|)
return|;
elseif|else
if|if
condition|(
name|number
operator|<
literal|0
condition|)
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
return|;
return|return
name|QVariant
operator|::
name|fromValue
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
return|;
block|}
if|if
condition|(
name|role
operator|==
name|Qt
operator|::
name|TextAlignmentRole
condition|)
if|if
condition|(
operator|!
name|t
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|(
name|t
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|isNumber
argument_list|()
operator|||
name|t
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|==
literal|'-'
operator|)
condition|)
return|return
call|(
name|int
call|)
argument_list|(
name|Qt
operator|::
name|AlignRight
operator||
name|Qt
operator|::
name|AlignVCenter
argument_list|)
return|;
return|return
name|QTableWidgetItem
operator|::
name|data
argument_list|(
name|role
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setData
name|void
name|SpreadSheetItem
operator|::
name|setData
parameter_list|(
name|int
name|role
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|QTableWidgetItem
operator|::
name|setData
argument_list|(
name|role
argument_list|,
name|value
argument_list|)
expr_stmt|;
if|if
condition|(
name|tableWidget
argument_list|()
condition|)
name|tableWidget
argument_list|()
operator|->
name|viewport
argument_list|()
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|display
name|QVariant
name|SpreadSheetItem
operator|::
name|display
parameter_list|()
specifier|const
block|{
comment|// avoid circular dependencies
if|if
condition|(
name|isResolving
condition|)
return|return
name|QVariant
argument_list|()
return|;
name|isResolving
operator|=
literal|true
expr_stmt|;
name|QVariant
name|result
init|=
name|computeFormula
argument_list|(
name|formula
argument_list|()
argument_list|,
name|tableWidget
argument_list|()
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|isResolving
operator|=
literal|false
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|computeFormula
name|QVariant
name|SpreadSheetItem
operator|::
name|computeFormula
parameter_list|(
specifier|const
name|QString
modifier|&
name|formula
parameter_list|,
specifier|const
name|QTableWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QTableWidgetItem
modifier|*
name|self
parameter_list|)
block|{
comment|// check if the s tring is actually a formula or not
name|QStringList
name|list
init|=
name|formula
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
if|if
condition|(
name|list
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|widget
condition|)
return|return
name|formula
return|;
comment|// it is a normal string
name|QString
name|op
init|=
name|list
operator|.
name|value
argument_list|(
literal|0
argument_list|)
operator|.
name|toLower
argument_list|()
decl_stmt|;
name|int
name|firstRow
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|firstCol
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|secondRow
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|secondCol
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|list
operator|.
name|count
argument_list|()
operator|>
literal|1
condition|)
name|decode_pos
argument_list|(
name|list
operator|.
name|value
argument_list|(
literal|1
argument_list|)
argument_list|,
operator|&
name|firstRow
argument_list|,
operator|&
name|firstCol
argument_list|)
expr_stmt|;
if|if
condition|(
name|list
operator|.
name|count
argument_list|()
operator|>
literal|2
condition|)
name|decode_pos
argument_list|(
name|list
operator|.
name|value
argument_list|(
literal|2
argument_list|)
argument_list|,
operator|&
name|secondRow
argument_list|,
operator|&
name|secondCol
argument_list|)
expr_stmt|;
specifier|const
name|QTableWidgetItem
modifier|*
name|start
init|=
name|widget
operator|->
name|item
argument_list|(
name|firstRow
argument_list|,
name|firstCol
argument_list|)
decl_stmt|;
specifier|const
name|QTableWidgetItem
modifier|*
name|end
init|=
name|widget
operator|->
name|item
argument_list|(
name|secondRow
argument_list|,
name|secondCol
argument_list|)
decl_stmt|;
name|int
name|firstVal
init|=
name|start
condition|?
name|start
operator|->
name|text
argument_list|()
operator|.
name|toInt
argument_list|()
else|:
literal|0
decl_stmt|;
name|int
name|secondVal
init|=
name|end
condition|?
name|end
operator|->
name|text
argument_list|()
operator|.
name|toInt
argument_list|()
else|:
literal|0
decl_stmt|;
name|QVariant
name|result
decl_stmt|;
if|if
condition|(
name|op
operator|==
literal|"sum"
condition|)
block|{
name|int
name|sum
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|r
init|=
name|firstRow
init|;
name|r
operator|<=
name|secondRow
condition|;
operator|++
name|r
control|)
block|{
for|for
control|(
name|int
name|c
init|=
name|firstCol
init|;
name|c
operator|<=
name|secondCol
condition|;
operator|++
name|c
control|)
block|{
specifier|const
name|QTableWidgetItem
modifier|*
name|tableItem
init|=
name|widget
operator|->
name|item
argument_list|(
name|r
argument_list|,
name|c
argument_list|)
decl_stmt|;
if|if
condition|(
name|tableItem
operator|&&
name|tableItem
operator|!=
name|self
condition|)
name|sum
operator|+=
name|tableItem
operator|->
name|text
argument_list|()
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
block|}
name|result
operator|=
name|sum
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|op
operator|==
literal|"+"
condition|)
block|{
name|result
operator|=
operator|(
name|firstVal
operator|+
name|secondVal
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|op
operator|==
literal|"-"
condition|)
block|{
name|result
operator|=
operator|(
name|firstVal
operator|-
name|secondVal
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|op
operator|==
literal|"*"
condition|)
block|{
name|result
operator|=
operator|(
name|firstVal
operator|*
name|secondVal
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|op
operator|==
literal|"/"
condition|)
block|{
if|if
condition|(
name|secondVal
operator|==
literal|0
condition|)
name|result
operator|=
name|QString
argument_list|(
literal|"nan"
argument_list|)
expr_stmt|;
else|else
name|result
operator|=
operator|(
name|firstVal
operator|/
name|secondVal
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|op
operator|==
literal|"="
condition|)
block|{
if|if
condition|(
name|start
condition|)
name|result
operator|=
name|start
operator|->
name|text
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|result
operator|=
name|formula
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
end_unit
