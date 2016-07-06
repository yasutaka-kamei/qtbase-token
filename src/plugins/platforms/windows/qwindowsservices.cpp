begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|QT_NO_URL_CAST_FROM_STRING
define|#
directive|define
name|QT_NO_URL_CAST_FROM_STRING
end_define
begin_include
include|#
directive|include
file|"qwindowsservices.h"
end_include
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<shlobj.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_include
include|#
directive|include
file|<intshcut.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enumerator|debug
name|enum
type|{
name|debug
init|=
literal|0
end_decl_stmt
begin_function
DECL|enumerator|debug
unit|};
DECL|function|shellExecute
specifier|static
specifier|inline
name|bool
name|shellExecute
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINCE
specifier|const
name|QString
name|nativeFilePath
init|=
name|url
operator|.
name|isLocalFile
argument_list|()
condition|?
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|url
operator|.
name|toLocalFile
argument_list|()
argument_list|)
else|:
name|url
operator|.
name|toString
argument_list|(
name|QUrl
operator|::
name|FullyEncoded
argument_list|)
decl_stmt|;
specifier|const
name|quintptr
name|result
init|=
cast|reinterpret_cast
argument_list|<
name|quintptr
argument_list|>
argument_list|(
name|ShellExecute
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|nativeFilePath
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|SW_SHOWNORMAL
argument_list|)
argument_list|)
decl_stmt|;
comment|// ShellExecute returns a value greater than 32 if successful
if|if
condition|(
name|result
operator|<=
literal|32
condition|)
block|{
name|qWarning
argument_list|(
literal|"ShellExecute '%s' failed (error %s)."
argument_list|,
name|qPrintable
argument_list|(
name|url
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|result
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|url
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|// Retrieve the commandline for the default mail client. It contains a
end_comment
begin_comment
comment|// placeholder %1 for the URL. The default key used below is the
end_comment
begin_comment
comment|// command line for the mailto: shell command.
end_comment
begin_function
DECL|function|mailCommand
specifier|static
specifier|inline
name|QString
name|mailCommand
parameter_list|()
block|{
enum|enum
block|{
name|BufferSize
init|=
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
operator|*
name|MAX_PATH
block|}
enum|;
specifier|const
name|wchar_t
name|mailUserKey
index|[]
init|=
literal|L"Software\\Microsoft\\Windows\\Shell\\Associations\\UrlAssociations\\mailto\\UserChoice"
decl_stmt|;
name|wchar_t
name|command
index|[
name|MAX_PATH
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
comment|// Check if user has set preference, otherwise use default.
name|HKEY
name|handle
decl_stmt|;
name|QString
name|keyName
decl_stmt|;
if|if
condition|(
operator|!
name|RegOpenKeyEx
argument_list|(
name|HKEY_CURRENT_USER
argument_list|,
name|mailUserKey
argument_list|,
literal|0
argument_list|,
name|KEY_READ
argument_list|,
operator|&
name|handle
argument_list|)
condition|)
block|{
name|DWORD
name|bufferSize
init|=
name|BufferSize
decl_stmt|;
if|if
condition|(
operator|!
name|RegQueryValueEx
argument_list|(
name|handle
argument_list|,
literal|L"Progid"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
cast|reinterpret_cast
argument_list|<
name|unsigned
name|char
operator|*
argument_list|>
argument_list|(
name|command
argument_list|)
argument_list|,
operator|&
name|bufferSize
argument_list|)
condition|)
name|keyName
operator|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|command
argument_list|)
expr_stmt|;
name|RegCloseKey
argument_list|(
name|handle
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QLatin1String
name|mailto
init|=
name|keyName
operator|.
name|isEmpty
argument_list|()
condition|?
name|QLatin1String
argument_list|(
literal|"mailto"
argument_list|)
else|:
name|QLatin1String
argument_list|()
decl_stmt|;
name|keyName
operator|+=
name|mailto
operator|+
name|QLatin1String
argument_list|(
literal|"\\Shell\\Open\\Command"
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"keyName="
operator|<<
name|keyName
expr_stmt|;
name|command
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|RegOpenKeyExW
argument_list|(
name|HKEY_CLASSES_ROOT
argument_list|,
cast|reinterpret_cast
argument_list|<
specifier|const
name|wchar_t
operator|*
argument_list|>
argument_list|(
name|keyName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|,
name|KEY_READ
argument_list|,
operator|&
name|handle
argument_list|)
condition|)
block|{
name|DWORD
name|bufferSize
init|=
name|BufferSize
decl_stmt|;
name|RegQueryValueEx
argument_list|(
name|handle
argument_list|,
literal|L""
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
cast|reinterpret_cast
argument_list|<
name|unsigned
name|char
operator|*
argument_list|>
argument_list|(
name|command
argument_list|)
argument_list|,
operator|&
name|bufferSize
argument_list|)
expr_stmt|;
name|RegCloseKey
argument_list|(
name|handle
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|command
index|[
literal|0
index|]
condition|)
return|return
name|QString
argument_list|()
return|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|wchar_t
name|expandedCommand
index|[
name|MAX_PATH
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
return|return
name|ExpandEnvironmentStrings
argument_list|(
name|command
argument_list|,
name|expandedCommand
argument_list|,
name|MAX_PATH
argument_list|)
condition|?
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|expandedCommand
argument_list|)
else|:
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|command
argument_list|)
return|;
else|#
directive|else
return|return
name|QString
argument_list|()
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|launchMail
specifier|static
specifier|inline
name|bool
name|launchMail
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
name|QString
name|command
init|=
name|mailCommand
argument_list|()
decl_stmt|;
if|if
condition|(
name|command
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Cannot launch '%s': There is no mail program installed."
argument_list|,
name|qPrintable
argument_list|(
name|url
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|//Make sure the path for the process is in quotes
specifier|const
name|QChar
name|doubleQuote
init|=
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|command
operator|.
name|startsWith
argument_list|(
name|doubleQuote
argument_list|)
condition|)
block|{
specifier|const
name|int
name|exeIndex
init|=
name|command
operator|.
name|indexOf
argument_list|(
name|QStringLiteral
argument_list|(
literal|".exe "
argument_list|)
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
decl_stmt|;
if|if
condition|(
name|exeIndex
operator|!=
operator|-
literal|1
condition|)
block|{
name|command
operator|.
name|insert
argument_list|(
name|exeIndex
operator|+
literal|4
argument_list|,
name|doubleQuote
argument_list|)
expr_stmt|;
name|command
operator|.
name|prepend
argument_list|(
name|doubleQuote
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Pass the url as the parameter. Should use QProcess::startDetached(),
comment|// but that cannot handle a Windows command line [yet].
name|command
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"%1"
argument_list|)
argument_list|,
name|url
operator|.
name|toString
argument_list|(
name|QUrl
operator|::
name|FullyEncoded
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|debug
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"Launching"
operator|<<
name|command
expr_stmt|;
comment|//start the process
name|PROCESS_INFORMATION
name|pi
decl_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|pi
argument_list|,
sizeof|sizeof
argument_list|(
name|pi
argument_list|)
argument_list|)
expr_stmt|;
name|STARTUPINFO
name|si
decl_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|si
argument_list|,
sizeof|sizeof
argument_list|(
name|si
argument_list|)
argument_list|)
expr_stmt|;
name|si
operator|.
name|cb
operator|=
sizeof|sizeof
argument_list|(
name|si
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|CreateProcess
argument_list|(
name|NULL
argument_list|,
cast|reinterpret_cast
argument_list|<
name|wchar_t
operator|*
argument_list|>
argument_list|(
cast|const_cast
argument_list|<
name|ushort
operator|*
argument_list|>
argument_list|(
name|command
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|)
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|FALSE
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
operator|&
name|si
argument_list|,
operator|&
name|pi
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"Unable to launch '%s'"
argument_list|,
name|qPrintable
argument_list|(
name|command
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|CloseHandle
argument_list|(
name|pi
operator|.
name|hProcess
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|pi
operator|.
name|hThread
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|openUrl
name|bool
name|QWindowsServices
operator|::
name|openUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
specifier|const
name|QString
name|scheme
init|=
name|url
operator|.
name|scheme
argument_list|()
decl_stmt|;
if|if
condition|(
name|scheme
operator|==
name|QLatin1String
argument_list|(
literal|"mailto"
argument_list|)
operator|&&
name|launchMail
argument_list|(
name|url
argument_list|)
condition|)
return|return
literal|true
return|;
return|return
name|shellExecute
argument_list|(
name|url
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|openDocument
name|bool
name|QWindowsServices
operator|::
name|openDocument
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
block|{
return|return
name|shellExecute
argument_list|(
name|url
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
