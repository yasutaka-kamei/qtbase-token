begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"softkeys.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QMainWindow
argument_list|(
name|parent
argument_list|)
block|{
name|central
operator|=
operator|new
name|QWidget
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|central
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|NoContextMenu
argument_list|)
expr_stmt|;
comment|// explicitly forbid usage of context menu so actions item is not shown menu
name|setCentralWidget
argument_list|(
name|central
argument_list|)
expr_stmt|;
comment|// Create text editor and set softkeys to it
name|textEditor
operator|=
operator|new
name|QTextEdit
argument_list|(
name|tr
argument_list|(
literal|"Navigate in UI to see context sensitive softkeys in action"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|clear
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Clear"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|clear
operator|->
name|setSoftKeyRole
argument_list|(
name|QAction
operator|::
name|NegativeSoftKey
argument_list|)
expr_stmt|;
name|textEditor
operator|->
name|addAction
argument_list|(
name|clear
argument_list|)
expr_stmt|;
name|ok
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Ok"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|ok
operator|->
name|setSoftKeyRole
argument_list|(
name|QAction
operator|::
name|PositiveSoftKey
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|ok
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
name|okPressed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|cancel
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Cancel"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|cancel
operator|->
name|setSoftKeyRole
argument_list|(
name|QAction
operator|::
name|NegativeSoftKey
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|cancel
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
name|cancelPressed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|infoLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|""
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|infoLabel
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|NoContextMenu
argument_list|)
expr_stmt|;
name|toggleButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Custom"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|toggleButton
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|NoContextMenu
argument_list|)
expr_stmt|;
name|toggleButton
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|modeButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Loop SK window type"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|modeButton
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|NoContextMenu
argument_list|)
expr_stmt|;
name|modeLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Normal maximized"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|modeLabel
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|NoContextMenu
argument_list|)
expr_stmt|;
name|pushButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"File Dialog"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|pushButton
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|NoContextMenu
argument_list|)
expr_stmt|;
name|QComboBox
modifier|*
name|comboBox
init|=
operator|new
name|QComboBox
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|comboBox
operator|->
name|setContextMenuPolicy
argument_list|(
name|Qt
operator|::
name|NoContextMenu
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|insertItems
argument_list|(
literal|0
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"MainWindow"
argument_list|,
literal|"Selection1"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"MainWindow"
argument_list|,
literal|"Selection2"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
operator|<<
name|QApplication
operator|::
name|translate
argument_list|(
literal|"MainWindow"
argument_list|,
literal|"Selection3"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|=
operator|new
name|QGridLayout
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|textEditor
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|infoLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|toggleButton
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|pushButton
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|comboBox
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|modeButton
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|modeLabel
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|central
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
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
name|exit
operator|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Exit"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|fileMenu
operator|->
name|addAction
argument_list|(
name|exit
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|clear
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
name|clearTextEditor
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|pushButton
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
name|openDialog
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|exit
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
name|exitApplication
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|toggleButton
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
name|setCustomSoftKeys
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|modeButton
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
name|setMode
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|pushButton
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~MainWindow
name|MainWindow
operator|::
name|~
name|MainWindow
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|clearTextEditor
name|void
name|MainWindow
operator|::
name|clearTextEditor
parameter_list|()
block|{
name|textEditor
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|""
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|openDialog
name|void
name|MainWindow
operator|::
name|openDialog
parameter_list|()
block|{
name|QFileDialog
operator|::
name|getOpenFileName
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addSoftKeys
name|void
name|MainWindow
operator|::
name|addSoftKeys
parameter_list|()
block|{
name|addAction
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|addAction
argument_list|(
name|cancel
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCustomSoftKeys
name|void
name|MainWindow
operator|::
name|setCustomSoftKeys
parameter_list|()
block|{
if|if
condition|(
name|toggleButton
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Custom softkeys set"
argument_list|)
argument_list|)
expr_stmt|;
name|addSoftKeys
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Custom softkeys removed"
argument_list|)
argument_list|)
expr_stmt|;
name|removeAction
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|removeAction
argument_list|(
name|cancel
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setMode
name|void
name|MainWindow
operator|::
name|setMode
parameter_list|()
block|{
if|if
condition|(
name|isMaximized
argument_list|()
condition|)
block|{
name|showFullScreen
argument_list|()
expr_stmt|;
name|modeLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Normal Fullscreen"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|windowFlags
argument_list|()
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowSoftkeysRespondHint
condition|)
block|{
name|flags
operator||=
name|Qt
operator|::
name|WindowSoftkeysVisibleHint
expr_stmt|;
name|flags
operator|&=
operator|~
name|Qt
operator|::
name|WindowSoftkeysRespondHint
expr_stmt|;
name|setWindowFlags
argument_list|(
name|flags
argument_list|)
expr_stmt|;
comment|// Hides visible window
name|showFullScreen
argument_list|()
expr_stmt|;
name|modeLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Fullscreen with softkeys"
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|flags
operator|&
name|Qt
operator|::
name|WindowSoftkeysVisibleHint
condition|)
block|{
name|flags
operator|&=
operator|~
name|Qt
operator|::
name|WindowSoftkeysVisibleHint
expr_stmt|;
name|flags
operator|&=
operator|~
name|Qt
operator|::
name|WindowSoftkeysRespondHint
expr_stmt|;
name|setWindowFlags
argument_list|(
name|flags
argument_list|)
expr_stmt|;
comment|// Hides visible window
name|showMaximized
argument_list|()
expr_stmt|;
name|modeLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Normal Maximized"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|flags
operator|&=
operator|~
name|Qt
operator|::
name|WindowSoftkeysVisibleHint
expr_stmt|;
name|flags
operator||=
name|Qt
operator|::
name|WindowSoftkeysRespondHint
expr_stmt|;
name|setWindowFlags
argument_list|(
name|flags
argument_list|)
expr_stmt|;
comment|// Hides visible window
name|showFullScreen
argument_list|()
expr_stmt|;
name|modeLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Fullscreen with SK respond"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|exitApplication
name|void
name|MainWindow
operator|::
name|exitApplication
parameter_list|()
block|{
name|qApp
operator|->
name|exit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|okPressed
name|void
name|MainWindow
operator|::
name|okPressed
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"OK pressed"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cancelPressed
name|void
name|MainWindow
operator|::
name|cancelPressed
parameter_list|()
block|{
name|infoLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Cancel pressed"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
