begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/* rsslisting.cpp  Provides a widget for displaying news items from RDF news sources. RDF is an XML-based format for storing items of information (see http://www.w3.org/RDF/ for details).  The widget itself provides a simple user interface for specifying the URL of a news source, and controlling the downloading of news.  The widget downloads and parses the XML asynchronously, feeding the data to an XML reader in pieces. This allows the user to interrupt its operation, and also allows very large data sources to be read. */
end_comment
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|<QtXml>
end_include
begin_include
include|#
directive|include
file|"rsslisting.h"
end_include
begin_comment
comment|/*     Constructs an RSSListing widget with a simple user interface, and sets     up the XML reader to use a custom handler class.      The user interface consists of a line edit, two push buttons, and a     list view widget. The line edit is used for entering the URLs of news     sources; the push buttons start and abort the process of reading the     news. */
end_comment
begin_constructor
DECL|function|RSSListing
name|RSSListing
operator|::
name|RSSListing
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|lineEdit
operator|=
operator|new
name|QLineEdit
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|fetchButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Fetch"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|abortButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Abort"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|abortButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|treeWidget
operator|=
operator|new
name|QTreeWidget
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QStringList
name|headerLabels
decl_stmt|;
name|headerLabels
operator|<<
name|tr
argument_list|(
literal|"Title"
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Link"
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|setHeaderLabels
argument_list|(
name|headerLabels
argument_list|)
expr_stmt|;
name|handler
operator|=
literal|0
expr_stmt|;
name|connect
argument_list|(
operator|&
name|http
argument_list|,
name|SIGNAL
argument_list|(
name|readyRead
argument_list|(
name|QHttpResponseHeader
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readData
argument_list|(
name|QHttpResponseHeader
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|http
argument_list|,
name|SIGNAL
argument_list|(
name|requestFinished
argument_list|(
name|int
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|finished
argument_list|(
name|int
argument_list|,
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|lineEdit
argument_list|,
name|SIGNAL
argument_list|(
name|returnPressed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|fetch
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fetchButton
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
name|fetch
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|abortButton
argument_list|,
name|SIGNAL
argument_list|(
name|clicked
argument_list|()
argument_list|)
argument_list|,
operator|&
name|http
argument_list|,
name|SLOT
argument_list|(
name|abort
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QHBoxLayout
modifier|*
name|hboxLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|lineEdit
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|fetchButton
argument_list|)
expr_stmt|;
name|hboxLayout
operator|->
name|addWidget
argument_list|(
name|abortButton
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addLayout
argument_list|(
name|hboxLayout
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|treeWidget
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"RSS listing example"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*     Starts fetching data from a news source specified in the line     edit widget.      The line edit is made read only to prevent the user from modifying its     contents during the fetch; this is only for cosmetic purposes.     The fetch button is disabled, and the abort button is enabled to allow     the user to interrupt processing. The list view is cleared, and we     define the last list view item to be 0, meaning that there are no     existing items in the list.      We reset the flag used to determine whether parsing should begin again     or continue. A new handler is created, if required, and made available     to the reader.      The HTTP handler is supplied with the raw contents of the line edit and     a fetch is initiated. We keep the ID value returned by the HTTP handler     for future reference. */
end_comment
begin_function
DECL|function|fetch
name|void
name|RSSListing
operator|::
name|fetch
parameter_list|()
block|{
name|lineEdit
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|fetchButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|abortButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|treeWidget
operator|->
name|clear
argument_list|()
expr_stmt|;
name|lastItemCreated
operator|=
literal|0
expr_stmt|;
name|newInformation
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|handler
operator|!=
literal|0
condition|)
operator|delete
name|handler
expr_stmt|;
name|handler
operator|=
operator|new
name|Handler
expr_stmt|;
comment|//! [0]
name|xmlReader
operator|.
name|setContentHandler
argument_list|(
name|handler
argument_list|)
expr_stmt|;
name|xmlReader
operator|.
name|setErrorHandler
argument_list|(
name|handler
argument_list|)
expr_stmt|;
comment|//! [0]
name|connect
argument_list|(
name|handler
argument_list|,
name|SIGNAL
argument_list|(
name|newItem
argument_list|(
name|QString
operator|&
argument_list|,
name|QString
operator|&
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|addItem
argument_list|(
name|QString
operator|&
argument_list|,
name|QString
operator|&
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QUrl
name|url
argument_list|(
name|lineEdit
operator|->
name|text
argument_list|()
argument_list|)
decl_stmt|;
name|http
operator|.
name|setHost
argument_list|(
name|url
operator|.
name|host
argument_list|()
argument_list|)
expr_stmt|;
name|connectionId
operator|=
name|http
operator|.
name|get
argument_list|(
name|url
operator|.
name|path
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*     Reads data received from the RDF source.      We read all the available data, and pass it to the XML     input source. The first time we receive new information,     the reader is set up for a new incremental parse;     we continue parsing using a different function on     subsequent calls involving the same data source.      If parsing fails for any reason, we abort the fetch. */
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|readData
name|void
name|RSSListing
operator|::
name|readData
parameter_list|(
specifier|const
name|QHttpResponseHeader
modifier|&
name|resp
parameter_list|)
block|{
name|bool
name|ok
decl_stmt|;
if|if
condition|(
name|resp
operator|.
name|statusCode
argument_list|()
operator|!=
literal|200
condition|)
name|http
operator|.
name|abort
argument_list|()
expr_stmt|;
else|else
block|{
name|xmlInput
operator|.
name|setData
argument_list|(
name|http
operator|.
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|newInformation
condition|)
block|{
name|ok
operator|=
name|xmlReader
operator|.
name|parse
argument_list|(
operator|&
name|xmlInput
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|newInformation
operator|=
literal|false
expr_stmt|;
block|}
else|else
name|ok
operator|=
name|xmlReader
operator|.
name|parseContinue
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|http
operator|.
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|/*     Finishes processing an HTTP request.      The default behavior is to keep the text edit read only.      If an error has occurred, the user interface is made available     to the user for further input, allowing a new fetch to be     started.      If the HTTP get request has finished, we perform a final     parsing operation on the data returned to ensure that it was     well-formed. Whether this is successful or not, we make the     user interface available to the user for further input. */
end_comment
begin_function
DECL|function|finished
name|void
name|RSSListing
operator|::
name|finished
parameter_list|(
name|int
name|id
parameter_list|,
name|bool
name|error
parameter_list|)
block|{
if|if
condition|(
name|error
condition|)
block|{
name|qWarning
argument_list|(
literal|"Received error during HTTP fetch."
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|setReadOnly
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|abortButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|fetchButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|id
operator|==
name|connectionId
condition|)
block|{
name|bool
name|ok
init|=
name|xmlReader
operator|.
name|parseContinue
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"Parse error at the end of input."
argument_list|)
expr_stmt|;
name|lineEdit
operator|->
name|setReadOnly
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|abortButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|fetchButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*     Adds an item to the list view as it is reported by the handler.      We keep a record of the last item created to ensure that the     items are created in sequence. */
end_comment
begin_function
DECL|function|addItem
name|void
name|RSSListing
operator|::
name|addItem
parameter_list|(
name|QString
modifier|&
name|title
parameter_list|,
name|QString
modifier|&
name|link
parameter_list|)
block|{
name|QTreeWidgetItem
modifier|*
name|item
decl_stmt|;
name|item
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|treeWidget
argument_list|,
name|lastItemCreated
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|0
argument_list|,
name|title
argument_list|)
expr_stmt|;
name|item
operator|->
name|setText
argument_list|(
literal|1
argument_list|,
name|link
argument_list|)
expr_stmt|;
name|lastItemCreated
operator|=
name|item
expr_stmt|;
block|}
end_function
end_unit
