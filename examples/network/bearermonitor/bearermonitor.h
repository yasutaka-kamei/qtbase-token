begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|BEARERMONITOR_H
end_ifndef
begin_define
DECL|macro|BEARERMONITOR_H
define|#
directive|define
name|BEARERMONITOR_H
end_define
begin_include
include|#
directive|include
file|<qnetworkconfigmanager.h>
end_include
begin_include
include|#
directive|include
file|<qnetworksession.h>
end_include
begin_include
include|#
directive|include
file|"ui_bearermonitor_640_480.h"
end_include
begin_decl_stmt
name|QT_USE_NAMESPACE
DECL|variable|SessionWidget
name|class
name|SessionWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|BearerMonitor
range|:
name|public
name|QWidget
decl_stmt|,
name|public
name|Ui_BearerMonitor
block|{
name|Q_OBJECT
name|public
range|:
name|BearerMonitor
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
operator|~
name|BearerMonitor
argument_list|()
expr_stmt|;
name|private
name|slots
range|:
name|void
name|configurationAdded
argument_list|(
specifier|const
name|QNetworkConfiguration
operator|&
name|config
argument_list|,
name|QTreeWidgetItem
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
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
name|configurationChanged
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
function_decl|;
name|void
name|updateSnapConfiguration
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|parent
parameter_list|,
specifier|const
name|QNetworkConfiguration
modifier|&
name|snap
parameter_list|)
function_decl|;
name|void
name|updateConfigurations
parameter_list|()
function_decl|;
name|void
name|onlineStateChanged
parameter_list|(
name|bool
name|isOnline
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|void
name|registerNetwork
parameter_list|()
function_decl|;
name|void
name|unregisterNetwork
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|showConfigurationFor
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|void
name|createSessionFor
parameter_list|(
name|QTreeWidgetItem
modifier|*
name|item
parameter_list|)
function_decl|;
name|void
name|createNewSession
parameter_list|()
function_decl|;
name|void
name|deleteSession
parameter_list|()
function_decl|;
name|void
name|performScan
parameter_list|()
function_decl|;
name|private
label|:
name|QNetworkConfigurationManager
name|manager
decl_stmt|;
name|QList
operator|<
name|SessionWidget
operator|*
operator|>
name|sessionWidgets
expr_stmt|;
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
comment|//BEARERMONITOR_H
end_comment
end_unit
