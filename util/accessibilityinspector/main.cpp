begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtDeclarative/QtDeclarative>
end_include
begin_include
include|#
directive|include
file|<QtUiTools/QtUiTools>
end_include
begin_include
include|#
directive|include
file|"accessibilityinspector.h"
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
if|if
condition|(
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|count
argument_list|()
operator|<
literal|2
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Usage: accessebilityInspector [ ui-file | qml-file ] [Option]"
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Option:"
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_ACCESSIBILITY_INSPECTOR_SCENE_GRAPH
name|qDebug
argument_list|()
operator|<<
literal|"-qtquick1: Use QDeclarativeView instead of QSGView for rendering QML files"
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
name|QString
name|fileName
init|=
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|QString
name|mode
decl_stmt|;
if|if
condition|(
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|count
argument_list|()
operator|>
literal|2
condition|)
block|{
name|mode
operator|=
name|app
operator|.
name|arguments
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
name|QWidget
modifier|*
name|window
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|endsWith
argument_list|(
literal|".ui"
argument_list|)
condition|)
block|{
name|QUiLoader
name|loader
decl_stmt|;
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|window
operator|=
name|loader
operator|.
name|load
argument_list|(
operator|&
name|file
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|fileName
operator|.
name|endsWith
argument_list|(
literal|".qml"
argument_list|)
condition|)
block|{
name|QUrl
name|fileUrl
decl_stmt|;
if|if
condition|(
name|fileName
operator|.
name|startsWith
argument_list|(
literal|":"
argument_list|)
condition|)
block|{
comment|// detect resources.
name|QString
name|name
init|=
name|fileName
decl_stmt|;
name|name
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// reomve ":/"
name|fileUrl
operator|.
name|setUrl
argument_list|(
name|QLatin1String
argument_list|(
literal|"qrc:/"
argument_list|)
operator|+
name|name
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fileUrl
operator|=
name|QUrl
operator|::
name|fromLocalFile
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_ACCESSIBILITY_INSPECTOR_SCENE_GRAPH
if|if
condition|(
name|mode
operator|==
name|QLatin1String
argument_list|(
literal|"-qtquick1"
argument_list|)
condition|)
endif|#
directive|endif
block|{
name|QDeclarativeView
modifier|*
name|declarativeView
init|=
operator|new
name|QDeclarativeView
argument_list|()
decl_stmt|;
name|declarativeView
operator|->
name|setSource
argument_list|(
name|fileUrl
argument_list|)
expr_stmt|;
name|window
operator|=
name|declarativeView
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_ACCESSIBILITY_INSPECTOR_SCENE_GRAPH
else|else
block|{
name|QSGView
modifier|*
name|sceneGraphView
init|=
operator|new
name|QSGView
argument_list|()
decl_stmt|;
name|sceneGraphView
operator|->
name|setSource
argument_list|(
name|fileUrl
argument_list|)
expr_stmt|;
name|window
operator|=
name|sceneGraphView
expr_stmt|;
block|}
endif|#
directive|endif
block|}
else|else
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Error: don't know what to do with"
operator|<<
name|fileName
expr_stmt|;
block|}
name|AccessibilityInspector
modifier|*
name|accessibilityInspector
init|=
operator|new
name|AccessibilityInspector
argument_list|()
decl_stmt|;
name|accessibilityInspector
operator|->
name|inspectWindow
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|window
operator|->
name|move
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|window
operator|->
name|show
argument_list|()
expr_stmt|;
name|int
name|ret
init|=
name|app
operator|.
name|exec
argument_list|()
decl_stmt|;
name|accessibilityInspector
operator|->
name|saveWindowGeometry
argument_list|()
expr_stmt|;
operator|delete
name|accessibilityInspector
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
end_unit
