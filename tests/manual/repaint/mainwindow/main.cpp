begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"../shared/shared.h"
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
name|QMainWindow
name|mainWindow
decl_stmt|;
name|mainWindow
operator|.
name|setCentralWidget
argument_list|(
operator|new
name|StaticWidget
argument_list|()
argument_list|)
expr_stmt|;
name|mainWindow
operator|.
name|setStatusBar
argument_list|(
operator|new
name|QStatusBar
argument_list|()
argument_list|)
expr_stmt|;
name|QDockWidget
modifier|*
name|dockWidget
init|=
operator|new
name|QDockWidget
argument_list|()
decl_stmt|;
name|dockWidget
operator|->
name|setWidget
argument_list|(
operator|new
name|StaticWidget
argument_list|()
argument_list|)
expr_stmt|;
name|mainWindow
operator|.
name|addDockWidget
argument_list|(
name|Qt
operator|::
name|LeftDockWidgetArea
argument_list|,
name|dockWidget
argument_list|)
expr_stmt|;
name|QToolBar
modifier|*
name|toolBar
init|=
operator|new
name|QToolBar
argument_list|()
decl_stmt|;
name|toolBar
operator|->
name|addWidget
argument_list|(
operator|new
name|StaticWidget
argument_list|()
argument_list|)
operator|->
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
empty_stmt|;
name|toolBar
operator|->
name|addWidget
argument_list|(
operator|new
name|QSpinBox
argument_list|()
argument_list|)
operator|->
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
empty_stmt|;
name|mainWindow
operator|.
name|addToolBar
argument_list|(
name|toolBar
argument_list|)
expr_stmt|;
name|mainWindow
operator|.
name|resize
argument_list|(
literal|600
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|mainWindow
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
