begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QtCore>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
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
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
specifier|const
name|QStringList
name|args
init|=
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|args
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|printf
argument_list|(
literal|"Usage: ./plugintest libplugin.so...\nThis tool loads a plugin and displays whether QPluginLoader could load it or not.\nIf the plugin could not be loaded, it'll display the error string.\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
foreach|foreach
control|(
name|QString
name|plugin
decl|,
name|args
control|)
block|{
name|printf
argument_list|(
literal|"%s: "
argument_list|,
name|qPrintable
argument_list|(
name|plugin
argument_list|)
argument_list|)
expr_stmt|;
name|QPluginLoader
name|loader
argument_list|(
name|plugin
argument_list|)
decl_stmt|;
if|if
condition|(
name|loader
operator|.
name|load
argument_list|()
condition|)
name|printf
argument_list|(
literal|"success!\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"failure: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|loader
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function
end_unit
