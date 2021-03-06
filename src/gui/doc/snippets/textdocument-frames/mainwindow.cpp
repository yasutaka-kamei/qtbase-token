begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"mainwindow.h"
end_include
begin_include
include|#
directive|include
file|"xmlwriter.h"
end_include
begin_constructor
DECL|function|MainWindow
name|MainWindow
operator|::
name|MainWindow
parameter_list|()
block|{
name|QMenu
modifier|*
name|fileMenu
init|=
operator|new
name|QMenu
argument_list|(
name|tr
argument_list|(
literal|"&File"
argument_list|)
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|saveAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"&Save..."
argument_list|)
argument_list|)
decl_stmt|;
name|saveAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+S"
argument_list|)
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|quitAction
init|=
name|fileMenu
operator|->
name|addAction
argument_list|(
name|tr
argument_list|(
literal|"E&xit"
argument_list|)
argument_list|)
decl_stmt|;
name|quitAction
operator|->
name|setShortcut
argument_list|(
name|tr
argument_list|(
literal|"Ctrl+Q"
argument_list|)
argument_list|)
expr_stmt|;
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|fileMenu
argument_list|)
expr_stmt|;
name|editor
operator|=
operator|new
name|QTextEdit
argument_list|()
expr_stmt|;
name|QTextCursor
name|cursor
argument_list|(
name|editor
operator|->
name|textCursor
argument_list|()
argument_list|)
decl_stmt|;
name|cursor
operator|.
name|movePosition
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|QTextFrame
modifier|*
name|mainFrame
init|=
name|cursor
operator|.
name|currentFrame
argument_list|()
decl_stmt|;
name|QTextCharFormat
name|plainCharFormat
decl_stmt|;
name|QTextCharFormat
name|boldCharFormat
decl_stmt|;
name|boldCharFormat
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
comment|/*  main frame //! [0]     QTextFrame *mainFrame = cursor.currentFrame();     cursor.insertText(...); //! [0] */
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Text documents are represented by the "
literal|"QTextDocument class, rather than by QString objects. "
literal|"Each QTextDocument object contains information about "
literal|"the document's internal representation, its structure, "
literal|"and keeps track of modifications to provide undo/redo "
literal|"facilities. This approach allows features such as the "
literal|"layout management to be delegated to specialized "
literal|"classes, but also provides a focus for the framework."
argument_list|,
name|plainCharFormat
argument_list|)
expr_stmt|;
comment|//! [1]
name|QTextFrameFormat
name|frameFormat
decl_stmt|;
name|frameFormat
operator|.
name|setMargin
argument_list|(
literal|32
argument_list|)
expr_stmt|;
name|frameFormat
operator|.
name|setPadding
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|frameFormat
operator|.
name|setBorder
argument_list|(
literal|4
argument_list|)
expr_stmt|;
comment|//! [1]
name|cursor
operator|.
name|insertFrame
argument_list|(
name|frameFormat
argument_list|)
expr_stmt|;
comment|/*  insert frame //! [2]     cursor.insertFrame(frameFormat);     cursor.insertText(...); //! [2] */
name|cursor
operator|.
name|insertText
argument_list|(
literal|"Documents are either converted from external sources "
literal|"or created from scratch using Qt. The creation process "
literal|"can done by an editor widget, such as QTextEdit, or by "
literal|"explicit calls to the Scribe API."
argument_list|,
name|boldCharFormat
argument_list|)
expr_stmt|;
name|cursor
operator|=
name|mainFrame
operator|->
name|lastCursorPosition
argument_list|()
expr_stmt|;
comment|/*  last cursor //! [3]     cursor = mainFrame->lastCursorPosition();     cursor.insertText(...); //! [3] */
name|cursor
operator|.
name|insertText
argument_list|(
literal|"There are two complementary ways to visualize the "
literal|"contents of a document: as a linear buffer that is "
literal|"used by editors to modify the contents, and as an "
literal|"object hierarchy containing structural information "
literal|"that is useful to layout engines. In the hierarchical "
literal|"model, the objects generally correspond to visual "
literal|"elements such as frames, tables, and lists. At a lower "
literal|"level, these elements describe properties such as the "
literal|"style of text used and its alignment. The linear "
literal|"representation of the document is used for editing and "
literal|"manipulation of the document's contents."
argument_list|,
name|plainCharFormat
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|saveAction
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
name|saveFile
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitAction
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
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|editor
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Text Document Frames"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|saveFile
name|void
name|MainWindow
operator|::
name|saveFile
parameter_list|()
block|{
name|QString
name|fileName
init|=
name|QFileDialog
operator|::
name|getSaveFileName
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Save document as:"
argument_list|)
argument_list|,
literal|""
argument_list|,
name|tr
argument_list|(
literal|"XML (*.xml)"
argument_list|)
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
if|if
condition|(
name|writeXml
argument_list|(
name|fileName
argument_list|)
condition|)
name|setWindowTitle
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
else|else
name|QMessageBox
operator|::
name|warning
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Warning"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Failed to save the document."
argument_list|)
argument_list|,
name|QMessageBox
operator|::
name|Cancel
argument_list|,
name|QMessageBox
operator|::
name|NoButton
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|writeXml
name|bool
name|MainWindow
operator|::
name|writeXml
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|XmlWriter
name|documentWriter
argument_list|(
name|editor
operator|->
name|document
argument_list|()
argument_list|)
decl_stmt|;
name|QDomDocument
modifier|*
name|domDocument
init|=
name|documentWriter
operator|.
name|toXml
argument_list|()
decl_stmt|;
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
argument_list|)
condition|)
block|{
name|QTextStream
name|textStream
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
name|textStream
operator|.
name|setCodec
argument_list|(
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"UTF-8"
argument_list|)
argument_list|)
expr_stmt|;
name|textStream
operator|<<
name|domDocument
operator|->
name|toString
argument_list|(
literal|1
argument_list|)
operator|.
name|toUtf8
argument_list|()
expr_stmt|;
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
else|else
return|return
literal|false
return|;
block|}
end_function
end_unit
