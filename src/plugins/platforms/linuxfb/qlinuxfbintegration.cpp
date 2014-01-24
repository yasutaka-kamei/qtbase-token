begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlinuxfbintegration.h"
end_include
begin_include
include|#
directive|include
file|"qlinuxfbscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixfontdatabase_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixservices_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qfbvthandler_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qfbbackingstore_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qfbwindow_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qfbcursor_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontextfactory_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QLinuxFbIntegration
name|QLinuxFbIntegration
operator|::
name|QLinuxFbIntegration
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paramList
parameter_list|)
member_init_list|:
name|m_fontDb
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|)
member_init_list|,
name|m_services
argument_list|(
operator|new
name|QGenericUnixServices
argument_list|)
block|{
name|m_primaryScreen
operator|=
operator|new
name|QLinuxFbScreen
argument_list|(
name|paramList
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QLinuxFbIntegration
name|QLinuxFbIntegration
operator|::
name|~
name|QLinuxFbIntegration
parameter_list|()
block|{
operator|delete
name|m_primaryScreen
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initialize
name|void
name|QLinuxFbIntegration
operator|::
name|initialize
parameter_list|()
block|{
if|if
condition|(
name|m_primaryScreen
operator|->
name|initialize
argument_list|()
condition|)
name|screenAdded
argument_list|(
name|m_primaryScreen
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"linuxfb: Failed to initialize screen"
argument_list|)
expr_stmt|;
name|m_inputContext
operator|=
name|QPlatformInputContextFactory
operator|::
name|create
argument_list|()
expr_stmt|;
name|m_vtHandler
operator|.
name|reset
argument_list|(
operator|new
name|QFbVtHandler
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QLinuxFbIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QLinuxFbIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QFbBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QLinuxFbIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QFbWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QLinuxFbIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|createUnixEventDispatcher
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|screens
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|QLinuxFbIntegration
operator|::
name|screens
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|list
decl_stmt|;
name|list
operator|.
name|append
argument_list|(
name|m_primaryScreen
argument_list|)
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QLinuxFbIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
return|return
name|m_fontDb
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QLinuxFbIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
return|return
name|m_services
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
