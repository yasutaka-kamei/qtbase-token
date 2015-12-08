begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|"server.h"
end_include
begin_constructor
DECL|function|Server
name|Server
operator|::
name|Server
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
member_init_list|,
name|statusLabel
argument_list|(
operator|new
name|QLabel
argument_list|)
member_init_list|,
name|tcpServer
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|networkSession
argument_list|(
literal|0
argument_list|)
block|{
name|setWindowFlags
argument_list|(
name|windowFlags
argument_list|()
operator|&
operator|~
name|Qt
operator|::
name|WindowContextHelpButtonHint
argument_list|)
expr_stmt|;
name|statusLabel
operator|->
name|setTextInteractionFlags
argument_list|(
name|Qt
operator|::
name|TextBrowserInteraction
argument_list|)
expr_stmt|;
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
if|if
condition|(
name|manager
operator|.
name|capabilities
argument_list|()
operator|&
name|QNetworkConfigurationManager
operator|::
name|NetworkSessionRequired
condition|)
block|{
comment|// Get saved network configuration
name|QSettings
name|settings
argument_list|(
name|QSettings
operator|::
name|UserScope
argument_list|,
name|QLatin1String
argument_list|(
literal|"QtProject"
argument_list|)
argument_list|)
decl_stmt|;
name|settings
operator|.
name|beginGroup
argument_list|(
name|QLatin1String
argument_list|(
literal|"QtNetwork"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|id
init|=
name|settings
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"DefaultNetworkConfiguration"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
comment|// If the saved network configuration is not currently discovered use the system default
name|QNetworkConfiguration
name|config
init|=
name|manager
operator|.
name|configurationFromIdentifier
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|(
name|config
operator|.
name|state
argument_list|()
operator|&
name|QNetworkConfiguration
operator|::
name|Discovered
operator|)
operator|!=
name|QNetworkConfiguration
operator|::
name|Discovered
condition|)
block|{
name|config
operator|=
name|manager
operator|.
name|defaultConfiguration
argument_list|()
expr_stmt|;
block|}
name|networkSession
operator|=
operator|new
name|QNetworkSession
argument_list|(
name|config
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|networkSession
argument_list|,
operator|&
name|QNetworkSession
operator|::
name|opened
argument_list|,
name|this
argument_list|,
operator|&
name|Server
operator|::
name|sessionOpened
argument_list|)
expr_stmt|;
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"Opening network session."
argument_list|)
argument_list|)
expr_stmt|;
name|networkSession
operator|->
name|open
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|sessionOpened
argument_list|()
expr_stmt|;
block|}
comment|//! [2]
name|fortunes
operator|<<
name|tr
argument_list|(
literal|"You've been leading a dog's life. Stay off the furniture."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"You've got to think about tomorrow."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"You will be surprised by a loud noise."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"You will feel hungry again in another hour."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"You might have mail."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"You cannot kill time without injuring eternity."
argument_list|)
operator|<<
name|tr
argument_list|(
literal|"Computers are not intelligent. They only think they are."
argument_list|)
expr_stmt|;
comment|//! [2]
name|QPushButton
modifier|*
name|quitButton
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Quit"
argument_list|)
argument_list|)
decl_stmt|;
name|quitButton
operator|->
name|setAutoDefault
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|quitButton
argument_list|,
operator|&
name|QAbstractButton
operator|::
name|clicked
argument_list|,
name|this
argument_list|,
operator|&
name|QWidget
operator|::
name|close
argument_list|)
expr_stmt|;
comment|//! [3]
name|connect
argument_list|(
name|tcpServer
argument_list|,
operator|&
name|QTcpServer
operator|::
name|newConnection
argument_list|,
name|this
argument_list|,
operator|&
name|Server
operator|::
name|sendFortune
argument_list|)
expr_stmt|;
comment|//! [3]
name|QHBoxLayout
modifier|*
name|buttonLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|buttonLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addWidget
argument_list|(
name|quitButton
argument_list|)
expr_stmt|;
name|buttonLayout
operator|->
name|addStretch
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|mainLayout
init|=
name|Q_NULLPTR
decl_stmt|;
if|if
condition|(
name|QGuiApplication
operator|::
name|styleHints
argument_list|()
operator|->
name|showIsFullScreen
argument_list|()
operator|||
name|QGuiApplication
operator|::
name|styleHints
argument_list|()
operator|->
name|showIsMaximized
argument_list|()
condition|)
block|{
name|QVBoxLayout
modifier|*
name|outerVerticalLayout
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|outerVerticalLayout
operator|->
name|addItem
argument_list|(
operator|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|outerHorizontalLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|outerHorizontalLayout
operator|->
name|addItem
argument_list|(
operator|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|)
argument_list|)
expr_stmt|;
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|QGuiApplication
operator|::
name|applicationDisplayName
argument_list|()
argument_list|)
decl_stmt|;
name|mainLayout
operator|=
operator|new
name|QVBoxLayout
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|outerHorizontalLayout
operator|->
name|addWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|outerHorizontalLayout
operator|->
name|addItem
argument_list|(
operator|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|)
argument_list|)
expr_stmt|;
name|outerVerticalLayout
operator|->
name|addLayout
argument_list|(
name|outerHorizontalLayout
argument_list|)
expr_stmt|;
name|outerVerticalLayout
operator|->
name|addItem
argument_list|(
operator|new
name|QSpacerItem
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QSizePolicy
operator|::
name|Ignored
argument_list|,
name|QSizePolicy
operator|::
name|MinimumExpanding
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|mainLayout
operator|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|statusLabel
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|buttonLayout
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|QGuiApplication
operator|::
name|applicationDisplayName
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|sessionOpened
name|void
name|Server
operator|::
name|sessionOpened
parameter_list|()
block|{
comment|// Save the used configuration
if|if
condition|(
name|networkSession
condition|)
block|{
name|QNetworkConfiguration
name|config
init|=
name|networkSession
operator|->
name|configuration
argument_list|()
decl_stmt|;
name|QString
name|id
decl_stmt|;
if|if
condition|(
name|config
operator|.
name|type
argument_list|()
operator|==
name|QNetworkConfiguration
operator|::
name|UserChoice
condition|)
name|id
operator|=
name|networkSession
operator|->
name|sessionProperty
argument_list|(
name|QLatin1String
argument_list|(
literal|"UserChoiceConfiguration"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
else|else
name|id
operator|=
name|config
operator|.
name|identifier
argument_list|()
expr_stmt|;
name|QSettings
name|settings
argument_list|(
name|QSettings
operator|::
name|UserScope
argument_list|,
name|QLatin1String
argument_list|(
literal|"QtProject"
argument_list|)
argument_list|)
decl_stmt|;
name|settings
operator|.
name|beginGroup
argument_list|(
name|QLatin1String
argument_list|(
literal|"QtNetwork"
argument_list|)
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
name|QLatin1String
argument_list|(
literal|"DefaultNetworkConfiguration"
argument_list|)
argument_list|,
name|id
argument_list|)
expr_stmt|;
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
block|}
comment|//! [0] //! [1]
name|tcpServer
operator|=
operator|new
name|QTcpServer
argument_list|(
name|this
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|tcpServer
operator|->
name|listen
argument_list|()
condition|)
block|{
name|QMessageBox
operator|::
name|critical
argument_list|(
name|this
argument_list|,
name|tr
argument_list|(
literal|"Fortune Server"
argument_list|)
argument_list|,
name|tr
argument_list|(
literal|"Unable to start the server: %1."
argument_list|)
operator|.
name|arg
argument_list|(
name|tcpServer
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|close
argument_list|()
expr_stmt|;
return|return;
block|}
comment|//! [0]
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
name|statusLabel
operator|->
name|setText
argument_list|(
name|tr
argument_list|(
literal|"The server is running on\n\nIP: %1\nport: %2\n\n"
literal|"Run the Fortune Client example now."
argument_list|)
operator|.
name|arg
argument_list|(
name|ipAddress
argument_list|)
operator|.
name|arg
argument_list|(
name|tcpServer
operator|->
name|serverPort
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [1]
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|sendFortune
name|void
name|Server
operator|::
name|sendFortune
parameter_list|()
block|{
comment|//! [5]
name|QByteArray
name|block
decl_stmt|;
name|QDataStream
name|out
argument_list|(
operator|&
name|block
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|out
operator|.
name|setVersion
argument_list|(
name|QDataStream
operator|::
name|Qt_4_0
argument_list|)
expr_stmt|;
comment|//! [4] //! [6]
name|out
operator|<<
operator|(
name|quint16
operator|)
literal|0
expr_stmt|;
name|out
operator|<<
name|fortunes
operator|.
name|at
argument_list|(
name|qrand
argument_list|()
operator|%
name|fortunes
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|out
operator|.
name|device
argument_list|()
operator|->
name|seek
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|out
operator|<<
call|(
name|quint16
call|)
argument_list|(
name|block
operator|.
name|size
argument_list|()
operator|-
sizeof|sizeof
argument_list|(
name|quint16
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [6] //! [7]
name|QTcpSocket
modifier|*
name|clientConnection
init|=
name|tcpServer
operator|->
name|nextPendingConnection
argument_list|()
decl_stmt|;
name|connect
argument_list|(
name|clientConnection
argument_list|,
operator|&
name|QAbstractSocket
operator|::
name|disconnected
argument_list|,
name|clientConnection
argument_list|,
operator|&
name|QObject
operator|::
name|deleteLater
argument_list|)
expr_stmt|;
comment|//! [7] //! [8]
name|clientConnection
operator|->
name|write
argument_list|(
name|block
argument_list|)
expr_stmt|;
name|clientConnection
operator|->
name|disconnectFromHost
argument_list|()
expr_stmt|;
comment|//! [5]
block|}
end_function
begin_comment
comment|//! [8]
end_comment
end_unit
