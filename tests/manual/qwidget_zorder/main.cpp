begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|Widget
class|class
name|Widget
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|Widget
name|Widget
parameter_list|()
block|{
name|QWidget
modifier|*
name|stackWidget
init|=
operator|new
name|QWidget
decl_stmt|;
name|stackWidget
operator|->
name|setFixedSize
argument_list|(
literal|400
argument_list|,
literal|300
argument_list|)
expr_stmt|;
name|button
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"pushbutton"
argument_list|,
name|stackWidget
argument_list|)
expr_stmt|;
name|plainTextEdit
operator|=
operator|new
name|QPlainTextEdit
argument_list|(
name|stackWidget
argument_list|)
expr_stmt|;
name|plainTextEdit
operator|->
name|setWordWrapMode
argument_list|(
name|QTextOption
operator|::
name|NoWrap
argument_list|)
expr_stmt|;
name|QString
name|s
init|=
literal|"foo bar bar foo foo bar bar foo"
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|plainTextEdit
operator|->
name|appendPlainText
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|s
operator|.
name|remove
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
name|calendar
operator|=
operator|new
name|QCalendarWidget
argument_list|(
name|stackWidget
argument_list|)
expr_stmt|;
name|button
operator|->
name|move
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|button
operator|->
name|resize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|plainTextEdit
operator|->
name|move
argument_list|(
literal|30
argument_list|,
literal|70
argument_list|)
expr_stmt|;
name|plainTextEdit
operator|->
name|resize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|move
argument_list|(
literal|80
argument_list|,
literal|40
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|buttonOps
init|=
operator|new
name|QWidget
decl_stmt|;
name|QVBoxLayout
modifier|*
name|l
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|buttonOps
argument_list|)
decl_stmt|;
name|QPushButton
modifier|*
name|lower
init|=
operator|new
name|QPushButton
argument_list|(
literal|"button: lower"
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|lower
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|button
argument_list|,
name|SLOT
argument_list|(
name|lower
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|lower
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|raise
init|=
operator|new
name|QPushButton
argument_list|(
literal|"button: raise"
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|raise
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|button
argument_list|,
name|SLOT
argument_list|(
name|raise
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|raise
argument_list|)
expr_stmt|;
name|lower
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"calendar: lower"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|lower
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|calendar
argument_list|,
name|SLOT
argument_list|(
name|lower
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|lower
argument_list|)
expr_stmt|;
name|raise
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"calendar: raise"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|raise
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|calendar
argument_list|,
name|SLOT
argument_list|(
name|raise
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|raise
argument_list|)
expr_stmt|;
name|QPushButton
modifier|*
name|stackUnder
init|=
operator|new
name|QPushButton
argument_list|(
literal|"calendar: stack under textedit"
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|stackUnder
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|stackCalendarUnderTextEdit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|stackUnder
argument_list|)
expr_stmt|;
name|lower
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"lower textedit"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|lower
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|plainTextEdit
argument_list|,
name|SLOT
argument_list|(
name|lower
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|lower
argument_list|)
expr_stmt|;
name|raise
operator|=
operator|new
name|QPushButton
argument_list|(
literal|"raise textedit"
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|raise
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
name|plainTextEdit
argument_list|,
name|SLOT
argument_list|(
name|raise
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|raise
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QHBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonOps
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|stackWidget
argument_list|)
expr_stmt|;
block|}
private|private
name|Q_SLOTS
private|:
DECL|function|stackCalendarUnderTextEdit
name|void
name|stackCalendarUnderTextEdit
parameter_list|()
block|{
name|calendar
operator|->
name|stackUnder
argument_list|(
name|plainTextEdit
argument_list|)
expr_stmt|;
block|}
private|private:
DECL|member|button
name|QPushButton
modifier|*
name|button
decl_stmt|;
DECL|member|plainTextEdit
name|QPlainTextEdit
modifier|*
name|plainTextEdit
decl_stmt|;
DECL|member|calendar
name|QCalendarWidget
modifier|*
name|calendar
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
name|Widget
name|w
decl_stmt|;
name|w
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
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
