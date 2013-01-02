begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtNetwork>
end_include
begin_include
include|#
directive|include
file|"blockingclient.h"
end_include
begin_constructor
DECL|function|BlockingClient
name|BlockingClient
operator|::
name|BlockingClient
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
name|hostLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Server name:"
argument_list|)
argument_list|)
expr_stmt|;
name|portLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"S&erver port:"
argument_list|)
argument_list|)
expr_stmt|;
comment|// find out which IP to connect to
name|QString
name|ipAddress
decl_stmt|;
name|QList
argument_list|<
name|QHostAddress
argument_list|>
name|ipAddressesList
init|=
name|QNetworkInterface
operator|::
name|allAddresses
argument_list|()
decl_stmt|;
comment|// use the first non-localhost IPv4 address
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ipAddressesList
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|ipAddressesList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|!=
name|QHostAddress
operator|::
name|LocalHost
operator|&&
name|ipAddressesList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toIPv4Address
argument_list|()
condition|)
block|{
name|ipAddress
operator|=
name|ipAddressesList
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
comment|// if we did not find one, use IPv4 localhost
if|if
condition|(
name|ipAddress
operator|.
name|isEmpty
argument_list|()
condition|)
name|ipAddress
operator|=
name|QHostAddress
argument_list|(
name|QHostAddress
operator|::
name|LocalHost
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|hostLineEdit
operator|=
operator|new
name|QLineEdit
argument_list|(
name|ipAddress
argument_list|)
expr_stmt|;
name|portLineEdit
operator|=
operator|new
name|QLineEdit
expr_stmt|;
name|portLineEdit
operator|->
name|setValidator
argument_list|(
operator|new
name|QIntValidator
argument_list|(
literal|1
argument_list|,
literal|65535
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
name|hostLabel
operator|->
name|setBuddy
argument_list|(
name|hostLineEdit
argument_list|)
expr_stmt|;
name|portLabel
operator|->
name|setBuddy
argument_list|(
name|portLineEdit
argument_list|)
expr_stmt|;
name|statusLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"This examples requires that you run the "
literal|"Fortune Server example as well."
argument_list|)
argument_list|)
expr_stmt|;
name|statusLabel
operator|->
name|setWordWrap
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|getFortuneButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Get Fortune"
argument_list|)
argument_list|)
expr_stmt|;
name|getFortuneButton
operator|->
name|setDefault
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|getFortuneButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|quitButton
operator|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Quit"
argument_list|)
argument_list|)
expr_stmt|;
name|buttonBox
operator|=
operator|new
name|QDialogButtonBox
expr_stmt|;
name|buttonBox
operator|->
name|addButton
argument_list|(
name|getFortuneButton
argument_list|,
name|QDialogButtonBox
operator|::
name|ActionRole
argument_list|)
expr_stmt|;
name|buttonBox
operator|->
name|addButton
argument_list|(
name|quitButton
argument_list|,
name|QDialogButtonBox
operator|::
name|RejectRole
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|getFortuneButton
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
name|requestNewFortune
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitButton
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
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|hostLineEdit
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|enableGetFortuneButton
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|portLineEdit
argument_list|,
name|SIGNAL
argument_list|(
name|textChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|enableGetFortuneButton
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0]
name|connect
argument_list|(
operator|&
name|thread
argument_list|,
name|SIGNAL
argument_list|(
name|newFortune
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showFortune
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [0] //! [1]
name|connect
argument_list|(
operator|&
name|thread
argument_list|,
name|SIGNAL
argument_list|(
name|error
argument_list|(
name|int
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|displayError
argument_list|(
name|int
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1]
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|hostLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|hostLineEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|portLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|portLineEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|statusLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|buttonBox
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
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Blocking Fortune Client"
argument_list|)
argument_list|)
expr_stmt|;
name|portLineEdit
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|requestNewFortune
name|void
name|BlockingClient
operator|::
name|requestNewFortune
parameter_list|()
block|{
name|getFortuneButton
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|thread
operator|.
name|requestNewFortune
argument_list|(
name|hostLineEdit
operator|->
name|text
argument_list|()
argument_list|,
name|portLineEdit
operator|->
name|text
argument_list|()
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|showFortune
name|void
name|BlockingClient
operator|::
name|showFortune
parameter_list|(
specifier|const
name|QString
modifier|&
name|nextFortune
parameter_list|)
block|{
if|if
condition|(
name|nextFortune
operator|==
name|currentFortune
condition|)
block|{
name|requestNewFortune
argument_list|()
expr_stmt|;
return|return;
block|}
comment|//! [3]
comment|//! [4]
name|currentFortune
operator|=
name|nextFortune
expr_stmt|;
name|statusLabel
operator|->
name|setText
argument_list|(
name|currentFortune
argument_list|)
expr_stmt|;
name|getFortuneButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|displayError
name|void
name|BlockingClient
operator|::
name|displayError
parameter_list|(
name|int
name|socketError
parameter_list|,
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
block|{
switch|switch
condition|(
name|socketError
condition|)
block|{
case|case
name|QAbstractSocket
operator|::
name|HostNotFoundError
case|:
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Blocking Fortune Client"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The host was not found. Please check the "
literal|"host and port settings."
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|QAbstractSocket
operator|::
name|ConnectionRefusedError
case|:
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Blocking Fortune Client"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The connection was refused by the peer. "
literal|"Make sure the fortune server is running, "
literal|"and check that the host name and port "
literal|"settings are correct."
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|QMessageBox
operator|::
name|information
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Blocking Fortune Client"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"The following error occurred: %1."
argument_list|)
operator|.
name|arg
argument_list|(
name|message
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|getFortuneButton
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableGetFortuneButton
name|void
name|BlockingClient
operator|::
name|enableGetFortuneButton
parameter_list|()
block|{
name|bool
name|enable
argument_list|(
operator|!
name|hostLineEdit
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|portLineEdit
operator|->
name|text
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
decl_stmt|;
name|getFortuneButton
operator|->
name|setEnabled
argument_list|(
name|enable
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
