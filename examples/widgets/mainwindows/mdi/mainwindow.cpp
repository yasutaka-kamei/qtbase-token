begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"mdichild.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|mdiArea
operator|=
operator|new
name|QMdiArea
expr_stmt|;
name|mdiArea
operator|->
name|setHorizontalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAsNeeded
argument_list|)
expr_stmt|;
name|mdiArea
operator|->
name|setVerticalScrollBarPolicy
argument_list|(
name|Qt
operator|::
name|ScrollBarAsNeeded
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|mdiArea
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|mdiArea
argument_list|,
name|SIGNAL
argument_list|(
name|subWindowActivated
argument_list|(
name|QMdiSubWindow
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateMenus
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|windowMapper
operator|=
operator|new
name|QSignalMapper
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|windowMapper
argument_list|,
name|SIGNAL
argument_list|(
name|mapped
argument_list|(
name|QWidget
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|setActiveSubWindow
argument_list|(
name|QWidget
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|createActions
argument_list|()
expr_stmt|;
name|createMenus
argument_list|()
expr_stmt|;
name|createToolBars
argument_list|()
expr_stmt|;
name|createStatusBar
argument_list|()
expr_stmt|;
name|updateMenus
argument_list|()
expr_stmt|;
name|readSettings
argument_list|()
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"MDI"
argument_list|)
argument_list|)
expr_stmt|;
name|setUnifiedTitleAndToolBarOnMac
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|closeEvent
name|void
name|MainWindow
operator|::
name|closeEvent
parameter_list|(
name|QCloseEvent
modifier|*
name|event
parameter_list|)
block|{
name|mdiArea
operator|->
name|closeAllSubWindows
argument_list|()
expr_stmt|;
if|if
condition|(
name|mdiArea
operator|->
name|currentSubWindow
argument_list|()
condition|)
block|{
name|event
operator|->
name|ignore
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|writeSettings
argument_list|()
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|newFile
name|void
name|MainWindow
operator|::
name|newFile
parameter_list|()
block|{
name|MdiChild
modifier|*
name|child
init|=
name|createMdiChild
argument_list|()
decl_stmt|;
name|child
operator|->
name|newFile
argument_list|()
expr_stmt|;
name|child
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|open
name|void
name|MainWindow
operator|::
name|open
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QMdiSubWindow
modifier|*
name|existing
init|=
name|findMdiChild
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|existing
condition|)
block|{
name|mdiArea
operator|->
name|setActiveSubWindow
argument_list|(
name|existing
argument_list|)
expr_stmt|;
return|return;
block|}
name|MdiChild
modifier|*
name|child
init|=
name|createMdiChild
argument_list|()
decl_stmt|;
if|if
condition|(
name|child
operator|->
name|loadFile
argument_list|(
name|fileName
argument_list|)
condition|)
block|{
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"File loaded"
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
name|child
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|child
operator|->
name|close
argument_list|()
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|save
name|void
name|MainWindow
operator|::
name|save
parameter_list|()
block|{
if|if
condition|(
name|activeMdiChild
argument_list|()
operator|&&
name|activeMdiChild
argument_list|()
operator|->
name|save
argument_list|()
condition|)
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"File saved"
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|saveAs
name|void
name|MainWindow
operator|::
name|saveAs
parameter_list|()
block|{
if|if
condition|(
name|activeMdiChild
argument_list|()
operator|&&
name|activeMdiChild
argument_list|()
operator|->
name|saveAs
argument_list|()
condition|)
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"File saved"
argument_list|)
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_function
DECL|function|cut
name|void
name|MainWindow
operator|::
name|cut
parameter_list|()
block|{
if|if
condition|(
name|activeMdiChild
argument_list|()
condition|)
name|activeMdiChild
argument_list|()
operator|->
name|cut
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|copy
name|void
name|MainWindow
operator|::
name|copy
parameter_list|()
block|{
if|if
condition|(
name|activeMdiChild
argument_list|()
condition|)
name|activeMdiChild
argument_list|()
operator|->
name|copy
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paste
name|void
name|MainWindow
operator|::
name|paste
parameter_list|()
block|{
if|if
condition|(
name|activeMdiChild
argument_list|()
condition|)
name|activeMdiChild
argument_list|()
operator|->
name|paste
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|about
name|void
name|MainWindow
operator|::
name|about
parameter_list|()
block|{
name|QMessageBox
operator|::
name|about
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"About MDI"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The<b>MDI</b> example demonstrates how to write multiple "
literal|"document interface applications using Qt."
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateMenus
name|void
name|MainWindow
operator|::
name|updateMenus
parameter_list|()
block|{
name|bool
name|hasMdiChild
init|=
operator|(
name|activeMdiChild
argument_list|()
operator|!=
literal|0
operator|)
decl_stmt|;
name|saveAct
operator|->
name|setEnabled
argument_list|(
name|hasMdiChild
argument_list|)
expr_stmt|;
name|saveAsAct
operator|->
name|setEnabled
argument_list|(
name|hasMdiChild
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|pasteAct
operator|->
name|setEnabled
argument_list|(
name|hasMdiChild
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|closeAct
operator|->
name|setEnabled
argument_list|(
name|hasMdiChild
argument_list|)
expr_stmt|;
name|closeAllAct
operator|->
name|setEnabled
argument_list|(
name|hasMdiChild
argument_list|)
expr_stmt|;
name|tileAct
operator|->
name|setEnabled
argument_list|(
name|hasMdiChild
argument_list|)
expr_stmt|;
name|cascadeAct
operator|->
name|setEnabled
argument_list|(
name|hasMdiChild
argument_list|)
expr_stmt|;
name|nextAct
operator|->
name|setEnabled
argument_list|(
name|hasMdiChild
argument_list|)
expr_stmt|;
name|previousAct
operator|->
name|setEnabled
argument_list|(
name|hasMdiChild
argument_list|)
expr_stmt|;
name|separatorAct
operator|->
name|setVisible
argument_list|(
name|hasMdiChild
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|bool
name|hasSelection
init|=
operator|(
name|activeMdiChild
argument_list|()
operator|&&
name|activeMdiChild
argument_list|()
operator|->
name|textCursor
argument_list|()
operator|.
name|hasSelection
argument_list|()
operator|)
decl_stmt|;
name|cutAct
operator|->
name|setEnabled
argument_list|(
name|hasSelection
argument_list|)
expr_stmt|;
name|copyAct
operator|->
name|setEnabled
argument_list|(
name|hasSelection
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|updateWindowMenu
name|void
name|MainWindow
operator|::
name|updateWindowMenu
parameter_list|()
block|{
name|windowMenu
operator|->
name|clear
argument_list|()
expr_stmt|;
name|windowMenu
operator|->
name|addAction
argument_list|(
name|closeAct
argument_list|)
expr_stmt|;
name|windowMenu
operator|->
name|addAction
argument_list|(
name|closeAllAct
argument_list|)
expr_stmt|;
name|windowMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|windowMenu
operator|->
name|addAction
argument_list|(
name|tileAct
argument_list|)
expr_stmt|;
name|windowMenu
operator|->
name|addAction
argument_list|(
name|cascadeAct
argument_list|)
expr_stmt|;
name|windowMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|windowMenu
operator|->
name|addAction
argument_list|(
name|nextAct
argument_list|)
expr_stmt|;
name|windowMenu
operator|->
name|addAction
argument_list|(
name|previousAct
argument_list|)
expr_stmt|;
name|windowMenu
operator|->
name|addAction
argument_list|(
name|separatorAct
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QMdiSubWindow
modifier|*
argument_list|>
name|windows
init|=
name|mdiArea
operator|->
name|subWindowList
argument_list|()
decl_stmt|;
name|separatorAct
operator|->
name|setVisible
argument_list|(
operator|!
name|windows
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|windows
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|MdiChild
modifier|*
name|child
init|=
name|qobject_cast
argument_list|<
name|MdiChild
operator|*
argument_list|>
argument_list|(
name|windows
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|widget
argument_list|()
argument_list|)
decl_stmt|;
name|QString
name|text
decl_stmt|;
if|if
condition|(
name|i
operator|<
literal|9
condition|)
block|{
name|text
operator|=
name|tr
argument_list|(
literal|"&%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|+
literal|1
argument_list|)
operator|.
name|arg
argument_list|(
name|child
operator|->
name|userFriendlyCurrentFile
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|text
operator|=
name|tr
argument_list|(
literal|"%1 %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
operator|+
literal|1
argument_list|)
operator|.
name|arg
argument_list|(
name|child
operator|->
name|userFriendlyCurrentFile
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QAction
modifier|*
name|action
init|=
name|windowMenu
operator|->
name|addAction
argument_list|(
name|text
argument_list|)
decl_stmt|;
name|action
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|action
operator|->
name|setChecked
argument_list|(
name|child
operator|==
name|activeMdiChild
argument_list|()
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|action
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|windowMapper
argument_list|,
name|SLOT
argument_list|(
name|map
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|windowMapper
operator|->
name|setMapping
argument_list|(
name|action
argument_list|,
name|windows
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createMdiChild
name|MdiChild
modifier|*
name|MainWindow
operator|::
name|createMdiChild
parameter_list|()
block|{
name|MdiChild
modifier|*
name|child
init|=
operator|new
name|MdiChild
decl_stmt|;
name|mdiArea
operator|->
name|addSubWindow
argument_list|(
name|child
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|connect
argument_list|(
name|child
argument_list|,
name|SIGNAL
argument_list|(
name|copyAvailable
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|cutAct
argument_list|,
name|SLOT
argument_list|(
name|setEnabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|child
argument_list|,
name|SIGNAL
argument_list|(
name|copyAvailable
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|copyAct
argument_list|,
name|SLOT
argument_list|(
name|setEnabled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|child
return|;
block|}
end_function
begin_function
DECL|function|createActions
name|void
name|MainWindow
operator|::
name|createActions
parameter_list|()
block|{
name|newAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/new.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&New"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|newAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|New
argument_list|)
expr_stmt|;
name|newAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Create a new file"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|newAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|newFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|openAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/open.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Open..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|openAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Open
argument_list|)
expr_stmt|;
name|openAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Open an existing file"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|openAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|open
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|saveAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/save.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Save"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|saveAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Save
argument_list|)
expr_stmt|;
name|saveAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Save the document to disk"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|save
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|saveAsAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Save&As..."
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|saveAsAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|SaveAs
argument_list|)
expr_stmt|;
name|saveAsAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Save the document under a new name"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAsAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|saveAs
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0]
name|exitAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|exitAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Quit
argument_list|)
expr_stmt|;
name|exitAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Exit the application"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exitAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|closeAllWindows
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0]
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|cutAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/cut.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Cu&t"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|cutAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Cut
argument_list|)
expr_stmt|;
name|cutAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Cut the current selection's contents to the "
literal|"clipboard"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|cutAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|cut
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|copyAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/copy.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Copy"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|copyAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Copy
argument_list|)
expr_stmt|;
name|copyAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Copy the current selection's contents to the "
literal|"clipboard"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|copyAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|copy
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|pasteAct
operator|=
operator|new
name|QAction
argument_list|(
name|QIcon
argument_list|(
literal|":/images/paste.png"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"&Paste"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|pasteAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|Paste
argument_list|)
expr_stmt|;
name|pasteAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Paste the clipboard's contents into the current "
literal|"selection"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|pasteAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|paste
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|closeAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Cl&ose"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|closeAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Close the active window"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|closeAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|mdiArea
argument_list|,
name|SLOT
argument_list|(
name|closeActiveSubWindow
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|closeAllAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Close&All"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|closeAllAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Close all the windows"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|closeAllAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|mdiArea
argument_list|,
name|SLOT
argument_list|(
name|closeAllSubWindows
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|tileAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Tile"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|tileAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Tile the windows"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|tileAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|mdiArea
argument_list|,
name|SLOT
argument_list|(
name|tileSubWindows
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|cascadeAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Cascade"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|cascadeAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Cascade the windows"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|cascadeAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|mdiArea
argument_list|,
name|SLOT
argument_list|(
name|cascadeSubWindows
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|nextAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Ne&xt"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|nextAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|NextChild
argument_list|)
expr_stmt|;
name|nextAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Move the focus to the next window"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|nextAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|mdiArea
argument_list|,
name|SLOT
argument_list|(
name|activateNextSubWindow
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|previousAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Pre&vious"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|previousAct
operator|->
name|setShortcuts
argument_list|(
name|QKeySequence
operator|::
name|PreviousChild
argument_list|)
expr_stmt|;
name|previousAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Move the focus to the previous "
literal|"window"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|previousAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|mdiArea
argument_list|,
name|SLOT
argument_list|(
name|activatePreviousSubWindow
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|separatorAct
operator|=
operator|new
name|QAction
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|separatorAct
operator|->
name|setSeparator
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|aboutAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&About"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|aboutAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Show the application's About box"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|about
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|aboutQtAct
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About&Qt"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|aboutQtAct
operator|->
name|setStatusTip
argument_list|(
name|tr
argument_list|(
literal|"Show the Qt library's About box"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|aboutQtAct
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|qApp
argument_list|,
name|SLOT
argument_list|(
name|aboutQt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createMenus
name|void
name|MainWindow
operator|::
name|createMenus
parameter_list|()
block|{
name|fileMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|newAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|openAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|saveAsAct
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|QAction
modifier|*
name|action
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"Switch layout direction"
argument_list|)
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|action
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|switchLayoutDirection
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exitAct
argument_list|)
expr_stmt|;
name|editMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Edit"
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|editMenu
operator|->
name|addAction
argument_list|(
name|cutAct
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|copyAct
argument_list|)
expr_stmt|;
name|editMenu
operator|->
name|addAction
argument_list|(
name|pasteAct
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|windowMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Window"
argument_list|)
argument_list|)
expr_stmt|;
name|updateWindowMenu
argument_list|()
expr_stmt|;
name|connect
argument_list|(
name|windowMenu
argument_list|,
name|SIGNAL
argument_list|(
name|aboutToShow
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|updateWindowMenu
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|helpMenu
operator|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Help"
argument_list|)
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutAct
argument_list|)
expr_stmt|;
name|helpMenu
operator|->
name|addAction
argument_list|(
name|aboutQtAct
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createToolBars
name|void
name|MainWindow
operator|::
name|createToolBars
parameter_list|()
block|{
name|fileToolBar
operator|=
name|addToolBar
argument_list|(
name|tr
argument_list|(
literal|"File"
argument_list|)
argument_list|)
expr_stmt|;
name|fileToolBar
operator|->
name|addAction
argument_list|(
name|newAct
argument_list|)
expr_stmt|;
name|fileToolBar
operator|->
name|addAction
argument_list|(
name|openAct
argument_list|)
expr_stmt|;
name|fileToolBar
operator|->
name|addAction
argument_list|(
name|saveAct
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|editToolBar
operator|=
name|addToolBar
argument_list|(
name|tr
argument_list|(
literal|"Edit"
argument_list|)
argument_list|)
expr_stmt|;
name|editToolBar
operator|->
name|addAction
argument_list|(
name|cutAct
argument_list|)
expr_stmt|;
name|editToolBar
operator|->
name|addAction
argument_list|(
name|copyAct
argument_list|)
expr_stmt|;
name|editToolBar
operator|->
name|addAction
argument_list|(
name|pasteAct
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|createStatusBar
name|void
name|MainWindow
operator|::
name|createStatusBar
parameter_list|()
block|{
name|statusBar
argument_list|()
operator|->
name|showMessage
argument_list|(
name|tr
argument_list|(
literal|"Ready"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|readSettings
name|void
name|MainWindow
operator|::
name|readSettings
parameter_list|()
block|{
name|QSettings
name|settings
argument_list|(
literal|"QtProject"
argument_list|,
literal|"MDI Example"
argument_list|)
decl_stmt|;
name|QPoint
name|pos
init|=
name|settings
operator|.
name|value
argument_list|(
literal|"pos"
argument_list|,
name|QPoint
argument_list|(
literal|200
argument_list|,
literal|200
argument_list|)
argument_list|)
operator|.
name|toPoint
argument_list|()
decl_stmt|;
name|QSize
name|size
init|=
name|settings
operator|.
name|value
argument_list|(
literal|"size"
argument_list|,
name|QSize
argument_list|(
literal|400
argument_list|,
literal|400
argument_list|)
argument_list|)
operator|.
name|toSize
argument_list|()
decl_stmt|;
name|move
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|writeSettings
name|void
name|MainWindow
operator|::
name|writeSettings
parameter_list|()
block|{
name|QSettings
name|settings
argument_list|(
literal|"QtProject"
argument_list|,
literal|"MDI Example"
argument_list|)
decl_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"pos"
argument_list|,
name|pos
argument_list|()
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"size"
argument_list|,
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|activeMdiChild
name|MdiChild
modifier|*
name|MainWindow
operator|::
name|activeMdiChild
parameter_list|()
block|{
if|if
condition|(
name|QMdiSubWindow
modifier|*
name|activeSubWindow
init|=
name|mdiArea
operator|->
name|activeSubWindow
argument_list|()
condition|)
return|return
name|qobject_cast
argument_list|<
name|MdiChild
operator|*
argument_list|>
argument_list|(
name|activeSubWindow
operator|->
name|widget
argument_list|()
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|findMdiChild
name|QMdiSubWindow
modifier|*
name|MainWindow
operator|::
name|findMdiChild
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QString
name|canonicalFilePath
init|=
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|canonicalFilePath
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QMdiSubWindow
modifier|*
name|window
decl|,
name|mdiArea
operator|->
name|subWindowList
argument_list|()
control|)
block|{
name|MdiChild
modifier|*
name|mdiChild
init|=
name|qobject_cast
argument_list|<
name|MdiChild
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|widget
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|mdiChild
operator|->
name|currentFile
argument_list|()
operator|==
name|canonicalFilePath
condition|)
return|return
name|window
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|switchLayoutDirection
name|void
name|MainWindow
operator|::
name|switchLayoutDirection
parameter_list|()
block|{
if|if
condition|(
name|layoutDirection
argument_list|()
operator|==
name|Qt
operator|::
name|LeftToRight
condition|)
name|qApp
operator|->
name|setLayoutDirection
argument_list|(
name|Qt
operator|::
name|RightToLeft
argument_list|)
expr_stmt|;
else|else
name|qApp
operator|->
name|setLayoutDirection
argument_list|(
name|Qt
operator|::
name|LeftToRight
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setActiveSubWindow
name|void
name|MainWindow
operator|::
name|setActiveSubWindow
parameter_list|(
name|QWidget
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
operator|!
name|window
condition|)
return|return;
name|mdiArea
operator|->
name|setActiveSubWindow
argument_list|(
name|qobject_cast
argument_list|<
name|QMdiSubWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
