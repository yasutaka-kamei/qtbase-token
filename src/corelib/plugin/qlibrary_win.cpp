begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qlibrary_p.h"
end_include
begin_include
include|#
directive|include
file|"qfile.h"
end_include
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_include
include|#
directive|include
file|"qfileinfo.h"
end_include
begin_include
include|#
directive|include
file|<private/qfilesystementry_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NO_LIBRARY
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_undef
DECL|macro|QT_NO_LIBRARY
undef|#
directive|undef
name|QT_NO_LIBRARY
end_undef
begin_pragma
pragma|#
directive|pragma
name|message
name|(
literal|"QT_NO_LIBRARY is not supported on Windows"
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|extern
name|QString
name|qt_error_string
parameter_list|(
name|int
name|code
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|load_sys
name|bool
name|QLibraryPrivate
operator|::
name|load_sys
parameter_list|()
block|{
comment|//avoid 'Bad Image' message box
name|UINT
name|oldmode
init|=
name|SetErrorMode
argument_list|(
name|SEM_FAILCRITICALERRORS
operator||
name|SEM_NOOPENFILEERRORBOX
argument_list|)
decl_stmt|;
comment|// We make the following attempts at locating the library:
comment|//
comment|// WinCE
comment|// if (absolute)
comment|//     fileName
comment|//     fileName + ".dll"
comment|// else
comment|//     fileName + ".dll"
comment|//     fileName
comment|//     QFileInfo(fileName).absoluteFilePath()
comment|//
comment|// Windows
comment|// if (absolute)
comment|//     fileName
comment|//     fileName + ".dll"
comment|// else
comment|//     fileName + ".dll"
comment|//     fileName
comment|//
comment|// NB If it's a plugin we do not ever try the ".dll" extension
name|QStringList
name|attempts
decl_stmt|;
if|if
condition|(
name|pluginState
operator|!=
name|IsAPlugin
condition|)
name|attempts
operator|.
name|append
argument_list|(
name|fileName
operator|+
name|QLatin1String
argument_list|(
literal|".dll"
argument_list|)
argument_list|)
expr_stmt|;
comment|// If the fileName is an absolute path we try that first, otherwise we
comment|// use the system-specific suffix first
name|QFileSystemEntry
name|fsEntry
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|fsEntry
operator|.
name|isAbsolute
argument_list|()
condition|)
block|{
name|attempts
operator|.
name|prepend
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|attempts
operator|.
name|append
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|attempts
operator|.
name|append
argument_list|(
name|QFileInfo
argument_list|(
name|fileName
argument_list|)
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|Q_FOREACH
argument_list|(
argument|const QString&attempt
argument_list|,
argument|attempts
argument_list|)
block|{
name|pHnd
operator|=
name|LoadLibrary
argument_list|(
operator|(
name|wchar_t
operator|*
operator|)
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|attempt
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
expr_stmt|;
comment|// If we have a handle or the last error is something other than "unable
comment|// to find the module", then bail out
if|if
condition|(
name|pHnd
operator|||
operator|::
name|GetLastError
argument_list|()
operator|!=
name|ERROR_MOD_NOT_FOUND
condition|)
break|break;
block|}
name|SetErrorMode
argument_list|(
name|oldmode
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pHnd
condition|)
block|{
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"Cannot load library %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|qt_error_string
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Query the actual name of the library that was loaded
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
name|wchar_t
name|buffer
index|[
name|MAX_PATH
index|]
decl_stmt|;
operator|::
name|GetModuleFileName
argument_list|(
name|pHnd
argument_list|,
name|buffer
argument_list|,
name|MAX_PATH
argument_list|)
expr_stmt|;
name|QString
name|moduleFileName
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
name|moduleFileName
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|1
operator|+
name|moduleFileName
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QDir
name|dir
argument_list|(
name|fsEntry
operator|.
name|path
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|dir
operator|.
name|path
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"."
argument_list|)
condition|)
name|qualifiedFileName
operator|=
name|moduleFileName
expr_stmt|;
else|else
name|qualifiedFileName
operator|=
name|dir
operator|.
name|filePath
argument_list|(
name|moduleFileName
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|pHnd
operator|!=
literal|0
operator|)
return|;
block|}
end_function
begin_function
DECL|function|unload_sys
name|bool
name|QLibraryPrivate
operator|::
name|unload_sys
parameter_list|()
block|{
if|if
condition|(
operator|!
name|FreeLibrary
argument_list|(
name|pHnd
argument_list|)
condition|)
block|{
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"Cannot unload library %1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|qt_error_string
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|resolve_sys
name|QFunctionPointer
name|QLibraryPrivate
operator|::
name|resolve_sys
parameter_list|(
specifier|const
name|char
modifier|*
name|symbol
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|FARPROC
name|address
init|=
name|GetProcAddress
argument_list|(
name|pHnd
argument_list|,
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|QString
operator|::
name|fromLatin1
argument_list|(
name|symbol
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|)
decl_stmt|;
else|#
directive|else
name|FARPROC
name|address
init|=
name|GetProcAddress
argument_list|(
name|pHnd
argument_list|,
name|symbol
argument_list|)
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|address
condition|)
block|{
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"Cannot resolve symbol \"%1\" in %2: %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|symbol
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
operator|.
name|arg
argument_list|(
name|qt_error_string
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
return|return
name|QFunctionPointer
argument_list|(
name|address
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
