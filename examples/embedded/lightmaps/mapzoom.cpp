begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|"lightmaps.h"
end_include
begin_include
include|#
directive|include
file|"mapzoom.h"
end_include
begin_constructor
DECL|function|MapZoom
name|MapZoom
operator|::
name|MapZoom
parameter_list|()
member_init_list|:
name|QMainWindow
argument_list|(
literal|0
argument_list|)
block|{
name|map
operator|=
operator|new
name|LightMaps
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|setCentralWidget
argument_list|(
name|map
argument_list|)
expr_stmt|;
name|map
operator|->
name|setFocus
argument_list|()
expr_stmt|;
name|QAction
modifier|*
name|osloAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Oslo"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|berlinAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Berlin"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|jakartaAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"&Jakarta"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|QAction
modifier|*
name|nightModeAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"Night Mode"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|nightModeAction
operator|->
name|setCheckable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|nightModeAction
operator|->
name|setChecked
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|osmAction
init|=
operator|new
name|QAction
argument_list|(
name|tr
argument_list|(
literal|"About OpenStreetMap"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|osloAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|chooseOslo
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|berlinAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|chooseBerlin
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|jakartaAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|chooseJakarta
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|nightModeAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|map
argument_list|,
name|SLOT
argument_list|(
name|toggleNightMode
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|osmAction
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|aboutOsm
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QMenu
modifier|*
name|menu
init|=
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
name|tr
argument_list|(
literal|"&Options"
argument_list|)
argument_list|)
decl_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|osloAction
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|berlinAction
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|jakartaAction
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addSeparator
argument_list|()
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|nightModeAction
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|osmAction
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
literal|"Trolltech"
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
comment|// If the saved network configuration is not currently discovered use the system
comment|// default
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
name|SIGNAL
argument_list|(
name|opened
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|sessionOpened
argument_list|()
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
name|networkSession
operator|=
literal|0
expr_stmt|;
block|}
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Light Maps"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|sessionOpened
name|void
name|MapZoom
operator|::
name|sessionOpened
parameter_list|()
block|{
comment|// Save the used configuration
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
block|{
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
block|}
else|else
block|{
name|id
operator|=
name|config
operator|.
name|identifier
argument_list|()
expr_stmt|;
block|}
name|QSettings
name|settings
argument_list|(
name|QSettings
operator|::
name|UserScope
argument_list|,
name|QLatin1String
argument_list|(
literal|"Trolltech"
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
end_function
begin_function
DECL|function|chooseOslo
name|void
name|MapZoom
operator|::
name|chooseOslo
parameter_list|()
block|{
name|map
operator|->
name|setCenter
argument_list|(
literal|59.9138204
argument_list|,
literal|10.7387413
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|chooseBerlin
name|void
name|MapZoom
operator|::
name|chooseBerlin
parameter_list|()
block|{
name|map
operator|->
name|setCenter
argument_list|(
literal|52.52958999943302
argument_list|,
literal|13.383053541183472
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|chooseJakarta
name|void
name|MapZoom
operator|::
name|chooseJakarta
parameter_list|()
block|{
name|map
operator|->
name|setCenter
argument_list|(
operator|-
literal|6.211544
argument_list|,
literal|106.845172
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|aboutOsm
name|void
name|MapZoom
operator|::
name|aboutOsm
parameter_list|()
block|{
name|QDesktopServices
operator|::
name|openUrl
argument_list|(
name|QUrl
argument_list|(
literal|"http://www.openstreetmap.org"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
