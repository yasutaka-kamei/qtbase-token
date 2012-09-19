begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qsqldriverplugin.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"../../../sql/drivers/ibase/qsql_ibase.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QIBaseDriverPlugin
class|class
name|QIBaseDriverPlugin
super|:
specifier|public
name|QSqlDriverPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.QSqlDriverFactoryInterface"
name|FILE
literal|"ibase.json"
argument_list|)
decl|public
range|:
name|QIBaseDriverPlugin
argument_list|()
decl_stmt|;
name|QSqlDriver
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|QIBaseDriverPlugin
name|QIBaseDriverPlugin
operator|::
name|QIBaseDriverPlugin
parameter_list|()
member_init_list|:
name|QSqlDriverPlugin
argument_list|()
block|{ }
end_constructor
begin_function
DECL|function|create
name|QSqlDriver
modifier|*
name|QIBaseDriverPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"QIBASE"
argument_list|)
condition|)
block|{
name|QIBaseDriver
modifier|*
name|driver
init|=
operator|new
name|QIBaseDriver
argument_list|()
decl_stmt|;
return|return
name|driver
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
