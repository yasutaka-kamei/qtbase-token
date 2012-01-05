begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ACCESSPOINTMANAGEREX_H
end_ifndef
begin_define
DECL|macro|ACCESSPOINTMANAGEREX_H
define|#
directive|define
name|ACCESSPOINTMANAGEREX_H
end_define
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"ui_detailedinfodialog.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAEMO_6
argument_list|)
end_if
begin_include
include|#
directive|include
file|"ui_bearerex_maemo.h"
end_include
begin_include
include|#
directive|include
file|"ui_sessiondialog_maemo.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"ui_bearerex.h"
end_include
begin_include
include|#
directive|include
file|"ui_sessiondialog.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qnetworkconfigmanager.h"
end_include
begin_include
include|#
directive|include
file|"qnetworksession.h"
end_include
begin_include
include|#
directive|include
file|"datatransferer.h"
end_include
begin_include
include|#
directive|include
file|"xqlistwidget.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QNetworkAccessManager
name|class
name|QNetworkAccessManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkReply
name|class
name|QNetworkReply
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|variable|SessionTab
name|class
name|SessionTab
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DataTransferer
name|class
name|DataTransferer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_USE_NAMESPACE
DECL|variable|QMainWindow
name|class
name|BearerEx
range|:
name|public
name|QMainWindow
decl_stmt|,
name|public
name|Ui
decl|::
name|BearerExMainWindow
block|{
name|Q_OBJECT
name|public
range|:
name|BearerEx
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
name|void
name|createMenus
parameter_list|()
function_decl|;
name|void
name|showConfigurations
parameter_list|()
function_decl|;
name|private
name|Q_SLOTS
range|:
name|void
name|on_updateConfigurationsButton_clicked
argument_list|()
decl_stmt|;
name|void
name|on_updateListButton_clicked
parameter_list|()
function_decl|;
name|void
name|on_showDetailsButton_clicked
parameter_list|()
function_decl|;
name|void
name|on_createSessionButton_clicked
parameter_list|()
function_decl|;
name|void
name|on_clearEventListButton_clicked
parameter_list|()
function_decl|;
name|void
name|configurationsUpdateCompleted
parameter_list|()
function_decl|;
name|void
name|configurationAdded
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
function_decl|;
name|void
name|configurationRemoved
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
function_decl|;
name|void
name|onlineStateChanged
parameter_list|(
name|bool
name|isOnline
parameter_list|)
function_decl|;
name|void
name|configurationChanged
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
function_decl|;
name|private
label|:
name|QNetworkConfigurationManager
name|m_NetworkConfigurationManager
decl_stmt|;
name|QAction
modifier|*
name|m_openAction
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QDialog
name|class
name|DetailedInfoDialog
range|:
name|public
name|QDialog
decl_stmt|,
name|public
name|Ui
decl|::
name|DetailedInfoDialog
block|{
name|Q_OBJECT
name|public
range|:
name|DetailedInfoDialog
argument_list|(
name|QNetworkConfiguration
operator|*
name|apNetworkConfiguration
operator|=
literal|0
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|SessionTab
range|:
name|public
name|QWidget
decl_stmt|,
name|public
name|Ui
decl|::
name|SessionTab
block|{
name|Q_OBJECT
name|public
range|:
name|SessionTab
argument_list|(
argument|QNetworkConfiguration* apNetworkConfiguration =
literal|0
argument_list|,
argument|QNetworkConfigurationManager* configManager =
literal|0
argument_list|,
argument|QListWidget* eventListWidget =
literal|0
argument_list|,
argument|int index =
literal|0
argument_list|,
argument|BearerEx* parent =
literal|0
argument_list|)
decl_stmt|;
operator|~
name|SessionTab
argument_list|()
expr_stmt|;
name|QString
name|stateString
argument_list|(
name|QNetworkSession
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
name|private
name|Q_SLOTS
range|:
name|void
name|on_createQNetworkAccessManagerButton_clicked
argument_list|()
decl_stmt|;
name|void
name|on_sendRequestButton_clicked
parameter_list|()
function_decl|;
name|void
name|on_openSessionButton_clicked
parameter_list|()
function_decl|;
name|void
name|on_closeSessionButton_clicked
parameter_list|()
function_decl|;
name|void
name|on_stopConnectionButton_clicked
parameter_list|()
function_decl|;
name|void
name|on_deleteSessionButton_clicked
parameter_list|()
function_decl|;
name|void
name|on_dataObjectChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|newObjectType
parameter_list|)
function_decl|;
name|void
name|on_alrButton_clicked
parameter_list|()
function_decl|;
name|void
name|finished
parameter_list|(
name|quint32
name|errorCode
parameter_list|,
name|qint64
name|dataReceived
parameter_list|,
name|QString
name|errorType
parameter_list|)
function_decl|;
name|void
name|newConfigurationActivated
parameter_list|()
function_decl|;
name|void
name|preferredConfigurationChanged
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|,
name|bool
name|isSeamless
parameter_list|)
function_decl|;
name|void
name|stateChanged
argument_list|(
name|QNetworkSession
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
name|void
name|newState
argument_list|(
name|QNetworkSession
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
name|void
name|opened
parameter_list|()
function_decl|;
name|void
name|closed
parameter_list|()
function_decl|;
name|void
name|error
argument_list|(
name|QNetworkSession
operator|::
name|SessionError
name|error
argument_list|)
decl_stmt|;
name|private
label|:
comment|//data
comment|// QNetworkAccessManager* m_networkAccessManager;
name|DataTransferer
modifier|*
name|m_dataTransferer
decl_stmt|;
name|QNetworkSession
modifier|*
name|m_NetworkSession
decl_stmt|;
name|QNetworkConfigurationManager
modifier|*
name|m_ConfigManager
decl_stmt|;
name|QListWidget
modifier|*
name|m_eventListWidget
decl_stmt|;
name|QNetworkConfiguration
name|m_config
decl_stmt|;
name|int
name|m_index
decl_stmt|;
name|bool
name|m_dataTransferOngoing
decl_stmt|;
name|bool
name|m_alrEnabled
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ACCESSPOINTMANAGEREX_H
end_comment
begin_comment
comment|// End of file
end_comment
end_unit
