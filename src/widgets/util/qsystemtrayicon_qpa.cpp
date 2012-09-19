begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsystemtrayicon_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qpa/qplatformsystemtrayicon.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QStyle>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QSystemTrayIconPrivate
name|QSystemTrayIconPrivate
operator|::
name|QSystemTrayIconPrivate
parameter_list|()
member_init_list|:
name|qpa_sys
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|->
name|createPlatformSystemTrayIcon
argument_list|()
argument_list|)
member_init_list|,
name|visible
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QSystemTrayIconPrivate
name|QSystemTrayIconPrivate
operator|::
name|~
name|QSystemTrayIconPrivate
parameter_list|()
block|{
operator|delete
name|qpa_sys
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|install_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|install_sys
parameter_list|()
block|{
if|if
condition|(
name|qpa_sys
condition|)
block|{
name|qpa_sys
operator|->
name|init
argument_list|()
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|qpa_sys
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|QPlatformSystemTrayIcon
operator|::
name|ActivationReason
argument_list|)
argument_list|)
argument_list|,
name|q_func
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|emitActivated
argument_list|(
name|QPlatformSystemTrayIcon
operator|::
name|ActivationReason
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|qpa_sys
argument_list|,
name|SIGNAL
argument_list|(
name|messageClicked
argument_list|()
argument_list|)
argument_list|,
name|q_func
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|messageClicked
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|updateMenu_sys
argument_list|()
expr_stmt|;
name|updateIcon_sys
argument_list|()
expr_stmt|;
name|updateToolTip_sys
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|remove_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|remove_sys
parameter_list|()
block|{
if|if
condition|(
name|qpa_sys
condition|)
name|qpa_sys
operator|->
name|cleanup
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|geometry_sys
name|QRect
name|QSystemTrayIconPrivate
operator|::
name|geometry_sys
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|qpa_sys
condition|)
return|return
name|qpa_sys
operator|->
name|geometry
argument_list|()
return|;
else|else
return|return
name|QRect
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|updateIcon_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|updateIcon_sys
parameter_list|()
block|{
if|if
condition|(
name|qpa_sys
condition|)
name|qpa_sys
operator|->
name|updateIcon
argument_list|(
name|icon
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateMenu_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|updateMenu_sys
parameter_list|()
block|{
if|if
condition|(
name|qpa_sys
operator|&&
name|menu
condition|)
name|qpa_sys
operator|->
name|updateMenu
argument_list|(
name|menu
operator|->
name|platformMenu
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateToolTip_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|updateToolTip_sys
parameter_list|()
block|{
if|if
condition|(
name|qpa_sys
condition|)
name|qpa_sys
operator|->
name|updateToolTip
argument_list|(
name|toolTip
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isSystemTrayAvailable_sys
name|bool
name|QSystemTrayIconPrivate
operator|::
name|isSystemTrayAvailable_sys
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|QPlatformSystemTrayIcon
argument_list|>
name|sys
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|->
name|createPlatformSystemTrayIcon
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|sys
condition|)
return|return
name|sys
operator|->
name|isSystemTrayAvailable
argument_list|()
return|;
else|else
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|supportsMessages_sys
name|bool
name|QSystemTrayIconPrivate
operator|::
name|supportsMessages_sys
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|QPlatformSystemTrayIcon
argument_list|>
name|sys
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|->
name|createPlatformSystemTrayIcon
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|sys
condition|)
return|return
name|sys
operator|->
name|supportsMessages
argument_list|()
return|;
else|else
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|showMessage_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|showMessage_sys
parameter_list|(
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
name|QSystemTrayIcon
operator|::
name|MessageIcon
name|icon
parameter_list|,
name|int
name|msecs
parameter_list|)
block|{
if|if
condition|(
operator|!
name|qpa_sys
condition|)
return|return;
name|QIcon
name|notificationIcon
decl_stmt|;
switch|switch
condition|(
name|icon
condition|)
block|{
case|case
name|QSystemTrayIcon
operator|::
name|Information
case|:
name|notificationIcon
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_MessageBoxInformation
argument_list|)
expr_stmt|;
break|break;
case|case
name|QSystemTrayIcon
operator|::
name|Warning
case|:
name|notificationIcon
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_MessageBoxWarning
argument_list|)
expr_stmt|;
break|break;
case|case
name|QSystemTrayIcon
operator|::
name|Critical
case|:
name|notificationIcon
operator|=
name|QApplication
operator|::
name|style
argument_list|()
operator|->
name|standardIcon
argument_list|(
name|QStyle
operator|::
name|SP_MessageBoxCritical
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
name|qpa_sys
operator|->
name|showMessage
argument_list|(
name|message
argument_list|,
name|title
argument_list|,
name|notificationIcon
argument_list|,
cast|static_cast
argument_list|<
name|QPlatformSystemTrayIcon
operator|::
name|MessageIcon
argument_list|>
argument_list|(
name|icon
argument_list|)
argument_list|,
name|msecs
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMTRAYICON
end_comment
end_unit
