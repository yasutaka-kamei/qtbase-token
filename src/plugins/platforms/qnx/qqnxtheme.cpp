begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxtheme.h"
end_include
begin_include
include|#
directive|include
file|"qqnxfiledialoghelper.h"
end_include
begin_include
include|#
directive|include
file|"qqnxsystemsettings.h"
end_include
begin_include
include|#
directive|include
file|"qqnxintegration.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxTheme
name|QQnxTheme
operator|::
name|QQnxTheme
parameter_list|(
specifier|const
name|QQnxIntegration
modifier|*
name|integration
parameter_list|)
member_init_list|:
name|m_integration
argument_list|(
name|integration
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QQnxTheme
name|QQnxTheme
operator|::
name|~
name|QQnxTheme
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|m_fonts
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|usePlatformNativeDialog
name|bool
name|QQnxTheme
operator|::
name|usePlatformNativeDialog
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|type
operator|==
name|QPlatformTheme
operator|::
name|FileDialog
condition|)
return|return
literal|true
return|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_COLORDIALOG
argument_list|)
if|if
condition|(
name|type
operator|==
name|QPlatformTheme
operator|::
name|ColorDialog
condition|)
return|return
literal|false
return|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_FONTDIALOG
argument_list|)
if|if
condition|(
name|type
operator|==
name|QPlatformTheme
operator|::
name|FontDialog
condition|)
return|return
literal|false
return|;
endif|#
directive|endif
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|createPlatformDialogHelper
name|QPlatformDialogHelper
modifier|*
name|QQnxTheme
operator|::
name|createPlatformDialogHelper
parameter_list|(
name|DialogType
name|type
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|QPlatformTheme
operator|::
name|FileDialog
case|:
return|return
operator|new
name|QQnxFileDialogHelper
argument_list|(
name|m_integration
argument_list|)
return|;
ifndef|#
directive|ifndef
name|QT_NO_COLORDIALOG
case|case
name|QPlatformTheme
operator|::
name|ColorDialog
case|:
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_FONTDIALOG
case|case
name|QPlatformTheme
operator|::
name|FontDialog
case|:
endif|#
directive|endif
default|default:
return|return
literal|0
return|;
block|}
block|}
end_function
begin_function
DECL|function|font
specifier|const
name|QFont
modifier|*
name|QQnxTheme
operator|::
name|font
parameter_list|(
name|Font
name|type
parameter_list|)
specifier|const
block|{
name|QPlatformFontDatabase
modifier|*
name|fontDatabase
init|=
name|m_integration
operator|->
name|fontDatabase
argument_list|()
decl_stmt|;
if|if
condition|(
name|fontDatabase
operator|&&
name|m_fonts
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_fonts
operator|=
name|qt_qnx_createRoleFonts
argument_list|(
name|fontDatabase
argument_list|)
expr_stmt|;
return|return
name|m_fonts
operator|.
name|value
argument_list|(
name|type
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
