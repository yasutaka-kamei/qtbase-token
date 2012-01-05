begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsqlconnectiondialog.h"
end_include
begin_include
include|#
directive|include
file|"ui_qsqlconnectiondialog.h"
end_include
begin_include
include|#
directive|include
file|<QSqlDatabase>
end_include
begin_constructor
DECL|function|QSqlConnectionDialog
name|QSqlConnectionDialog
operator|::
name|QSqlConnectionDialog
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDialog
argument_list|(
name|parent
argument_list|)
block|{
name|ui
operator|.
name|setupUi
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QStringList
name|drivers
init|=
name|QSqlDatabase
operator|::
name|drivers
argument_list|()
decl_stmt|;
comment|// remove compat names
name|drivers
operator|.
name|removeAll
argument_list|(
literal|"QMYSQL3"
argument_list|)
expr_stmt|;
name|drivers
operator|.
name|removeAll
argument_list|(
literal|"QOCI8"
argument_list|)
expr_stmt|;
name|drivers
operator|.
name|removeAll
argument_list|(
literal|"QODBC3"
argument_list|)
expr_stmt|;
name|drivers
operator|.
name|removeAll
argument_list|(
literal|"QPSQL7"
argument_list|)
expr_stmt|;
name|drivers
operator|.
name|removeAll
argument_list|(
literal|"QTDS7"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|drivers
operator|.
name|contains
argument_list|(
literal|"QSQLITE"
argument_list|)
condition|)
name|ui
operator|.
name|dbCheckBox
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|ui
operator|.
name|comboDriver
operator|->
name|addItems
argument_list|(
name|drivers
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QSqlConnectionDialog
name|QSqlConnectionDialog
operator|::
name|~
name|QSqlConnectionDialog
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|driverName
name|QString
name|QSqlConnectionDialog
operator|::
name|driverName
parameter_list|()
specifier|const
block|{
return|return
name|ui
operator|.
name|comboDriver
operator|->
name|currentText
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|databaseName
name|QString
name|QSqlConnectionDialog
operator|::
name|databaseName
parameter_list|()
specifier|const
block|{
return|return
name|ui
operator|.
name|editDatabase
operator|->
name|text
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|userName
name|QString
name|QSqlConnectionDialog
operator|::
name|userName
parameter_list|()
specifier|const
block|{
return|return
name|ui
operator|.
name|editUsername
operator|->
name|text
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|password
name|QString
name|QSqlConnectionDialog
operator|::
name|password
parameter_list|()
specifier|const
block|{
return|return
name|ui
operator|.
name|editPassword
operator|->
name|text
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|hostName
name|QString
name|QSqlConnectionDialog
operator|::
name|hostName
parameter_list|()
specifier|const
block|{
return|return
name|ui
operator|.
name|editHostname
operator|->
name|text
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|port
name|int
name|QSqlConnectionDialog
operator|::
name|port
parameter_list|()
specifier|const
block|{
return|return
name|ui
operator|.
name|portSpinBox
operator|->
name|value
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|useInMemoryDatabase
name|bool
name|QSqlConnectionDialog
operator|::
name|useInMemoryDatabase
parameter_list|()
specifier|const
block|{
return|return
name|ui
operator|.
name|dbCheckBox
operator|->
name|isChecked
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|on_okButton_clicked
name|void
name|QSqlConnectionDialog
operator|::
name|on_okButton_clicked
parameter_list|()
block|{
if|if
condition|(
name|ui
operator|.
name|comboDriver
operator|->
name|currentText
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"No database driver selected"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Please select a database driver"
argument_list|)
argument_list|)
expr_stmt|;
name|ui
operator|.
name|comboDriver
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|accept
argument_list|()
expr_stmt|;
block|}
block|}
end_function
end_unit
