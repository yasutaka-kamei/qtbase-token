begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 ThorbjÃ¸rn Lund Martsum - tmartsum[at]gmail.com ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QTableView>
end_include
begin_include
include|#
directive|include
file|<QStandardItemModel>
end_include
begin_include
include|#
directive|include
file|<QItemDelegate>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_class
DECL|class|ExampleEditor
class|class
name|ExampleEditor
super|:
specifier|public
name|QLineEdit
block|{
public|public:
DECL|function|ExampleEditor
name|ExampleEditor
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QLineEdit
argument_list|(
name|parent
argument_list|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"ctor"
expr_stmt|;
block|}
DECL|function|~ExampleEditor
name|~
name|ExampleEditor
parameter_list|()
block|{
name|QApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|ExampleDelegate
class|class
name|ExampleDelegate
super|:
specifier|public
name|QItemDelegate
block|{
public|public:
DECL|function|ExampleDelegate
name|ExampleDelegate
parameter_list|()
member_init_list|:
name|QItemDelegate
argument_list|()
block|{
name|m_editor
operator|=
operator|new
name|ExampleEditor
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|function|createEditor
name|QWidget
modifier|*
name|createEditor
parameter_list|(
name|QWidget
modifier|*
name|p
parameter_list|,
specifier|const
name|QStyleOptionViewItem
modifier|&
name|o
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
name|m_editor
operator|->
name|setParent
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|m_editor
operator|->
name|setGeometry
argument_list|(
name|o
operator|.
name|rect
argument_list|)
expr_stmt|;
return|return
name|m_editor
return|;
block|}
DECL|function|destroyEditor
name|void
name|destroyEditor
parameter_list|(
name|QWidget
modifier|*
name|editor
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
name|editor
operator|->
name|setParent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"intercepted destroy :)"
expr_stmt|;
block|}
comment|// Avoid setting data - and therefore show that the editor keeps its state.
DECL|function|setEditorData
name|void
name|setEditorData
parameter_list|(
name|QWidget
modifier|*
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{ }
DECL|function|~ExampleDelegate
name|~
name|ExampleDelegate
parameter_list|()
block|{
operator|delete
name|m_editor
expr_stmt|;
block|}
DECL|member|m_editor
specifier|mutable
name|ExampleEditor
modifier|*
name|m_editor
decl_stmt|;
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
name|QTableView
name|tv
decl_stmt|;
name|QStandardItemModel
name|m
decl_stmt|;
name|m
operator|.
name|setRowCount
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|m
operator|.
name|setColumnCount
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|tv
operator|.
name|setModel
argument_list|(
operator|&
name|m
argument_list|)
expr_stmt|;
name|tv
operator|.
name|show
argument_list|()
expr_stmt|;
name|tv
operator|.
name|setItemDelegate
argument_list|(
operator|new
name|ExampleDelegate
argument_list|()
argument_list|)
expr_stmt|;
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
