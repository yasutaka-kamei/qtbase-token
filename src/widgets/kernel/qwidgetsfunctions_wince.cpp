begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwidgetsfunctions_wince.h"
end_include
begin_include
include|#
directive|include
file|<shellapi.h>
end_include
begin_function
name|QT_USE_NAMESPACE
ifndef|#
directive|ifndef
name|ShellExecute
DECL|function|qt_wince_ShellExecute
name|HINSTANCE
name|qt_wince_ShellExecute
parameter_list|(
name|HWND
name|hwnd
parameter_list|,
name|LPCWSTR
parameter_list|,
name|LPCWSTR
name|file
parameter_list|,
name|LPCWSTR
name|params
parameter_list|,
name|LPCWSTR
name|dir
parameter_list|,
name|int
name|showCmd
parameter_list|)
block|{
name|SHELLEXECUTEINFO
name|info
decl_stmt|;
name|info
operator|.
name|hwnd
operator|=
name|hwnd
expr_stmt|;
name|info
operator|.
name|lpVerb
operator|=
literal|L"Open"
expr_stmt|;
name|info
operator|.
name|lpFile
operator|=
name|file
expr_stmt|;
name|info
operator|.
name|lpParameters
operator|=
name|params
expr_stmt|;
name|info
operator|.
name|lpDirectory
operator|=
name|dir
expr_stmt|;
name|info
operator|.
name|nShow
operator|=
name|showCmd
expr_stmt|;
name|info
operator|.
name|cbSize
operator|=
sizeof|sizeof
argument_list|(
name|info
argument_list|)
expr_stmt|;
name|ShellExecuteEx
argument_list|(
operator|&
name|info
argument_list|)
expr_stmt|;
return|return
name|info
operator|.
name|hInstApp
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|SPI_GETPLATFORMTYPE
end_ifndef
begin_define
DECL|macro|SPI_GETPLATFORMTYPE
define|#
directive|define
name|SPI_GETPLATFORMTYPE
value|257
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Internal Qt -----------------------------------------------------
end_comment
begin_function
DECL|function|qt_wince_is_platform
name|bool
name|qt_wince_is_platform
parameter_list|(
specifier|const
name|QString
modifier|&
name|platformString
parameter_list|)
block|{
name|wchar_t
name|tszPlatform
index|[
literal|64
index|]
decl_stmt|;
if|if
condition|(
name|SystemParametersInfo
argument_list|(
name|SPI_GETPLATFORMTYPE
argument_list|,
sizeof|sizeof
argument_list|(
name|tszPlatform
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
argument_list|,
name|tszPlatform
argument_list|,
literal|0
argument_list|)
condition|)
if|if
condition|(
literal|0
operator|==
name|_tcsicmp
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|platformString
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
name|tszPlatform
argument_list|)
condition|)
return|return
literal|true
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_get_build
name|int
name|qt_wince_get_build
parameter_list|()
block|{
name|OSVERSIONINFO
name|osvi
decl_stmt|;
name|osvi
operator|.
name|dwOSVersionInfoSize
operator|=
sizeof|sizeof
argument_list|(
name|osvi
argument_list|)
expr_stmt|;
if|if
condition|(
name|GetVersionEx
argument_list|(
operator|&
name|osvi
argument_list|)
condition|)
return|return
name|osvi
operator|.
name|dwBuildNumber
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_get_version
name|int
name|qt_wince_get_version
parameter_list|()
block|{
name|OSVERSIONINFO
name|osvi
decl_stmt|;
name|osvi
operator|.
name|dwOSVersionInfoSize
operator|=
sizeof|sizeof
argument_list|(
name|osvi
argument_list|)
expr_stmt|;
if|if
condition|(
name|GetVersionEx
argument_list|(
operator|&
name|osvi
argument_list|)
condition|)
return|return
operator|(
name|osvi
operator|.
name|dwMajorVersion
operator|*
literal|10
operator|+
name|osvi
operator|.
name|dwMinorVersion
operator|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_is_windows_mobile_65
name|bool
name|qt_wince_is_windows_mobile_65
parameter_list|()
block|{
specifier|const
name|DWORD
name|dwFirstWM65BuildNumber
init|=
literal|21139
decl_stmt|;
name|OSVERSIONINFO
name|osvi
decl_stmt|;
name|osvi
operator|.
name|dwOSVersionInfoSize
operator|=
sizeof|sizeof
argument_list|(
name|osvi
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|GetVersionEx
argument_list|(
operator|&
name|osvi
argument_list|)
condition|)
return|return
literal|false
return|;
return|return
name|osvi
operator|.
name|dwMajorVersion
operator|>
literal|5
operator|||
operator|(
name|osvi
operator|.
name|dwMajorVersion
operator|==
literal|5
operator|&&
operator|(
name|osvi
operator|.
name|dwMinorVersion
operator|>
literal|2
operator|||
operator|(
name|osvi
operator|.
name|dwMinorVersion
operator|==
literal|2
operator|&&
name|osvi
operator|.
name|dwBuildNumber
operator|>=
name|dwFirstWM65BuildNumber
operator|)
operator|)
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_is_pocket_pc
name|bool
name|qt_wince_is_pocket_pc
parameter_list|()
block|{
return|return
name|qt_wince_is_platform
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"PocketPC"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_is_smartphone
name|bool
name|qt_wince_is_smartphone
parameter_list|()
block|{
return|return
name|qt_wince_is_platform
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Smartphone"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_is_mobile
name|bool
name|qt_wince_is_mobile
parameter_list|()
block|{
return|return
operator|(
name|qt_wince_is_smartphone
argument_list|()
operator|||
name|qt_wince_is_pocket_pc
argument_list|()
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qt_wince_is_high_dpi
name|bool
name|qt_wince_is_high_dpi
parameter_list|()
block|{
if|if
condition|(
operator|!
name|qt_wince_is_pocket_pc
argument_list|()
condition|)
return|return
literal|false
return|;
name|HDC
name|deviceContext
init|=
name|GetDC
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|int
name|dpi
init|=
name|GetDeviceCaps
argument_list|(
name|deviceContext
argument_list|,
name|LOGPIXELSX
argument_list|)
decl_stmt|;
name|ReleaseDC
argument_list|(
literal|0
argument_list|,
name|deviceContext
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|dpi
operator|<
literal|1000
operator|)
operator|&&
operator|(
name|dpi
operator|>
literal|0
operator|)
condition|)
return|return
name|dpi
operator|>
literal|96
return|;
else|else
return|return
literal|false
return|;
block|}
end_function
end_unit
