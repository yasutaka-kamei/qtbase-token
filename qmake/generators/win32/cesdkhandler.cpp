begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"cesdkhandler.h"
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qxmlstream.h>
end_include
begin_include
include|#
directive|include
file|<qsettings.h>
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|PropertyContainer
struct|struct
name|PropertyContainer
block|{
DECL|function|clear
name|void
name|clear
parameter_list|()
block|{
name|name
operator|.
name|clear
argument_list|()
expr_stmt|;
name|value
operator|.
name|clear
argument_list|()
expr_stmt|;
name|properties
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|value
name|QString
name|value
decl_stmt|;
DECL|member|properties
name|QMap
argument_list|<
name|QString
argument_list|,
name|PropertyContainer
argument_list|>
name|properties
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|PropertyContainer
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_constructor
DECL|function|CeSdkInfo
name|CeSdkInfo
operator|::
name|CeSdkInfo
parameter_list|()
member_init_list|:
name|m_major
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_minor
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|CeSdkHandler
name|CeSdkHandler
operator|::
name|CeSdkHandler
parameter_list|()
block|{ }
end_constructor
begin_struct
DECL|struct|ContainsPathKey
struct|struct
name|ContainsPathKey
block|{
DECL|function|operator ()
name|bool
name|operator
name|()
parameter_list|(
specifier|const
name|QString
modifier|&
name|val
parameter_list|)
specifier|const
block|{
return|return
operator|!
operator|(
name|val
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"MSBuildToolsPath"
argument_list|)
argument_list|)
operator|||
name|val
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"MSBuildToolsRoot"
argument_list|)
argument_list|)
operator|)
return|;
block|}
block|}
struct|;
end_struct
begin_struct
DECL|struct|ValueFromKey
struct|struct
name|ValueFromKey
block|{
DECL|function|ValueFromKey
specifier|explicit
name|ValueFromKey
parameter_list|(
specifier|const
name|QSettings
modifier|*
name|settings
parameter_list|)
member_init_list|:
name|settings
argument_list|(
name|settings
argument_list|)
block|{}
DECL|function|operator ()
name|QString
name|operator
name|()
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
specifier|const
block|{
return|return
name|settings
operator|->
name|value
argument_list|(
name|key
argument_list|)
operator|.
name|toString
argument_list|()
return|;
block|}
DECL|member|settings
specifier|const
name|QSettings
modifier|*
name|settings
decl_stmt|;
block|}
struct|;
end_struct
begin_function
DECL|function|parseMsBuildFile
name|bool
name|CeSdkHandler
operator|::
name|parseMsBuildFile
parameter_list|(
name|QFile
modifier|*
name|file
parameter_list|,
name|CeSdkInfo
modifier|*
name|info
parameter_list|)
block|{
name|bool
name|result
init|=
name|file
operator|->
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|IncludePath
init|=
name|QStringLiteral
argument_list|(
literal|"IncludePath"
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|LibraryPath
init|=
name|QStringLiteral
argument_list|(
literal|"LibraryPath"
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|PreprocessorDefinitions
init|=
name|QStringLiteral
argument_list|(
literal|"PreprocessorDefinitions"
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|SdkRootPathString
init|=
name|QStringLiteral
argument_list|(
literal|"SdkRootPath"
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|ExecutablePath
init|=
name|QStringLiteral
argument_list|(
literal|"ExecutablePath"
argument_list|)
decl_stmt|;
enum|enum
name|ParserState
block|{
name|Not
block|,
name|Include
block|,
name|Lib
block|,
name|Define
block|,
name|BinDir
block|,
name|SdkRootPath
block|}
enum|;
name|QString
name|includePath
decl_stmt|;
name|QString
name|libraryPath
decl_stmt|;
name|QString
name|defines
decl_stmt|;
name|QString
name|binDirs
decl_stmt|;
name|QString
name|sdkRootPath
decl_stmt|;
name|ParserState
name|state
init|=
name|Not
decl_stmt|;
if|if
condition|(
name|result
condition|)
block|{
name|QXmlStreamReader
name|xml
argument_list|(
name|file
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|xml
operator|.
name|atEnd
argument_list|()
condition|)
block|{
if|if
condition|(
name|xml
operator|.
name|isStartElement
argument_list|()
condition|)
block|{
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|IncludePath
condition|)
name|state
operator|=
name|Include
expr_stmt|;
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|LibraryPath
condition|)
name|state
operator|=
name|Lib
expr_stmt|;
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|PreprocessorDefinitions
condition|)
name|state
operator|=
name|Define
expr_stmt|;
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|SdkRootPathString
condition|)
name|state
operator|=
name|SdkRootPath
expr_stmt|;
elseif|else
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|==
name|ExecutablePath
condition|)
name|state
operator|=
name|BinDir
expr_stmt|;
else|else
name|state
operator|=
name|Not
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|isEndElement
argument_list|()
condition|)
block|{
name|state
operator|=
name|Not
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|isCharacters
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|state
condition|)
block|{
case|case
name|Include
case|:
name|includePath
operator|+=
name|xml
operator|.
name|text
argument_list|()
expr_stmt|;
break|break;
case|case
name|Lib
case|:
name|libraryPath
operator|+=
name|xml
operator|.
name|text
argument_list|()
expr_stmt|;
break|break;
case|case
name|Define
case|:
name|defines
operator|+=
name|xml
operator|.
name|text
argument_list|()
expr_stmt|;
break|break;
case|case
name|SdkRootPath
case|:
name|sdkRootPath
operator|=
name|xml
operator|.
name|text
argument_list|()
operator|.
name|toString
argument_list|()
expr_stmt|;
break|break;
case|case
name|BinDir
case|:
name|binDirs
operator|+=
name|xml
operator|.
name|text
argument_list|()
expr_stmt|;
case|case
operator|(
name|Not
operator|)
case|:
break|break;
block|}
block|}
name|xml
operator|.
name|readNext
argument_list|()
expr_stmt|;
block|}
block|}
name|file
operator|->
name|close
argument_list|()
expr_stmt|;
specifier|const
name|bool
name|success
init|=
name|result
operator|&&
operator|!
name|includePath
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|libraryPath
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|defines
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|sdkRootPath
operator|.
name|isEmpty
argument_list|()
decl_stmt|;
if|if
condition|(
name|success
condition|)
block|{
specifier|const
name|QString
name|startPattern
init|=
name|QStringLiteral
argument_list|(
literal|"$(Registry:"
argument_list|)
decl_stmt|;
specifier|const
name|int
name|startIndex
init|=
name|sdkRootPath
operator|.
name|indexOf
argument_list|(
name|startPattern
argument_list|)
decl_stmt|;
specifier|const
name|int
name|endIndex
init|=
name|sdkRootPath
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|regString
init|=
name|sdkRootPath
operator|.
name|mid
argument_list|(
name|startIndex
operator|+
name|startPattern
operator|.
name|size
argument_list|()
argument_list|,
name|endIndex
operator|-
name|startIndex
operator|-
name|startPattern
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|QSettings
name|sdkRootPathRegistry
argument_list|(
name|regString
argument_list|,
name|QSettings
operator|::
name|NativeFormat
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|erg
init|=
name|sdkRootPathRegistry
operator|.
name|value
argument_list|(
name|QStringLiteral
argument_list|(
literal|"."
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
specifier|const
name|QString
name|fullSdkRootPath
init|=
name|erg
operator|+
name|sdkRootPath
operator|.
name|mid
argument_list|(
name|endIndex
operator|+
literal|1
argument_list|)
decl_stmt|;
specifier|const
name|QLatin1String
name|rootString
argument_list|(
literal|"$(SdkRootPath)"
argument_list|)
decl_stmt|;
name|includePath
operator|=
name|includePath
operator|.
name|replace
argument_list|(
name|rootString
argument_list|,
name|fullSdkRootPath
argument_list|)
expr_stmt|;
name|libraryPath
operator|=
name|libraryPath
operator|.
name|replace
argument_list|(
name|rootString
argument_list|,
name|fullSdkRootPath
argument_list|)
expr_stmt|;
name|binDirs
operator|=
name|binDirs
operator|.
name|replace
argument_list|(
name|rootString
argument_list|,
name|fullSdkRootPath
argument_list|)
expr_stmt|;
name|info
operator|->
name|m_include
operator|=
name|includePath
operator|+
literal|";$(INCLUDE)"
expr_stmt|;
name|info
operator|->
name|m_lib
operator|=
name|libraryPath
expr_stmt|;
name|info
operator|->
name|m_bin
operator|=
name|binDirs
expr_stmt|;
block|}
return|return
name|success
return|;
block|}
end_function
begin_function
DECL|function|getMsBuildToolPaths
name|QStringList
name|CeSdkHandler
operator|::
name|getMsBuildToolPaths
parameter_list|()
specifier|const
block|{
name|QSettings
name|msbuildEntries
argument_list|(
literal|"HKEY_LOCAL_MACHINE\\Software\\Microsoft\\MSBuild\\ToolsVersions"
argument_list|,
name|QSettings
operator|::
name|NativeFormat
argument_list|)
decl_stmt|;
specifier|const
name|QStringList
name|allKeys
init|=
name|msbuildEntries
operator|.
name|allKeys
argument_list|()
decl_stmt|;
name|QStringList
name|toolVersionKeys
decl_stmt|;
name|toolVersionKeys
operator|.
name|push_back
argument_list|(
name|QStringLiteral
argument_list|(
literal|"c:\\Program Files\\MSBuild\\"
argument_list|)
argument_list|)
expr_stmt|;
name|std
operator|::
name|remove_copy_if
argument_list|(
name|allKeys
operator|.
name|cbegin
argument_list|()
argument_list|,
name|allKeys
operator|.
name|cend
argument_list|()
argument_list|,
name|std
operator|::
name|back_inserter
argument_list|(
name|toolVersionKeys
argument_list|)
argument_list|,
name|ContainsPathKey
argument_list|()
argument_list|)
expr_stmt|;
name|QStringList
name|toolVersionValues
decl_stmt|;
name|std
operator|::
name|transform
argument_list|(
name|toolVersionKeys
operator|.
name|constBegin
argument_list|()
argument_list|,
name|toolVersionKeys
operator|.
name|constEnd
argument_list|()
argument_list|,
name|std
operator|::
name|back_inserter
argument_list|(
name|toolVersionValues
argument_list|)
argument_list|,
name|ValueFromKey
argument_list|(
operator|&
name|msbuildEntries
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|toolVersionValues
return|;
block|}
end_function
begin_function
DECL|function|filterMsBuildToolPaths
name|QStringList
name|CeSdkHandler
operator|::
name|filterMsBuildToolPaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|)
specifier|const
block|{
name|QStringList
name|result
decl_stmt|;
for|for
control|(
specifier|const
name|QString
modifier|&
name|path
range|:
name|paths
control|)
block|{
name|QDir
name|dirVC110
argument_list|(
name|path
argument_list|)
decl_stmt|;
if|if
condition|(
name|path
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"bin"
argument_list|)
argument_list|)
condition|)
name|dirVC110
operator|.
name|cdUp
argument_list|()
expr_stmt|;
name|QDir
name|dirVC120
init|=
name|dirVC110
decl_stmt|;
if|if
condition|(
name|dirVC110
operator|.
name|cd
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Microsoft.Cpp\\v4.0\\V110\\Platforms"
argument_list|)
argument_list|)
condition|)
name|result
operator|<<
name|dirVC110
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
if|if
condition|(
name|dirVC120
operator|.
name|cd
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Microsoft.Cpp\\v4.0\\V120\\Platforms"
argument_list|)
argument_list|)
condition|)
name|result
operator|<<
name|dirVC120
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|retrieveEnvironment
name|bool
name|CeSdkHandler
operator|::
name|retrieveEnvironment
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|relativePaths
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|toolPaths
parameter_list|,
name|CeSdkInfo
modifier|*
name|info
parameter_list|)
block|{
name|bool
name|result
init|=
literal|false
decl_stmt|;
for|for
control|(
specifier|const
name|QString
modifier|&
name|path
range|:
name|toolPaths
control|)
block|{
specifier|const
name|QDir
name|dir
argument_list|(
name|path
argument_list|)
decl_stmt|;
for|for
control|(
specifier|const
name|QString
modifier|&
name|filePath
range|:
name|relativePaths
control|)
block|{
name|QFile
name|file
argument_list|(
name|dir
operator|.
name|absoluteFilePath
argument_list|(
name|filePath
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|exists
argument_list|()
condition|)
name|result
operator|=
name|parseMsBuildFile
argument_list|(
operator|&
name|file
argument_list|,
name|info
argument_list|)
operator|||
name|result
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|retrieveWEC2013SDKs
name|void
name|CeSdkHandler
operator|::
name|retrieveWEC2013SDKs
parameter_list|()
block|{
specifier|const
name|QStringList
name|toolPaths
init|=
name|getMsBuildToolPaths
argument_list|()
decl_stmt|;
specifier|const
name|QStringList
name|filteredToolPaths
init|=
name|filterMsBuildToolPaths
argument_list|(
name|toolPaths
argument_list|)
decl_stmt|;
name|QSettings
name|settings
argument_list|(
literal|"HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows CE Tools\\SDKs"
argument_list|,
name|QSettings
operator|::
name|NativeFormat
argument_list|)
decl_stmt|;
specifier|const
name|QStringList
name|keys
init|=
name|settings
operator|.
name|allKeys
argument_list|()
decl_stmt|;
for|for
control|(
specifier|const
name|QString
modifier|&
name|key
range|:
name|keys
control|)
block|{
if|if
condition|(
name|key
operator|.
name|contains
argument_list|(
name|QLatin1String
argument_list|(
literal|"SDKInformation"
argument_list|)
argument_list|)
operator|||
name|key
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'.'
argument_list|)
argument_list|)
condition|)
block|{
name|QFile
name|sdkPropertyFile
argument_list|(
name|settings
operator|.
name|value
argument_list|(
name|key
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|sdkPropertyFile
operator|.
name|exists
argument_list|()
condition|)
continue|continue;
name|QFileInfo
name|info
argument_list|(
name|sdkPropertyFile
argument_list|)
decl_stmt|;
if|if
condition|(
name|info
operator|.
name|isDir
argument_list|()
condition|)
block|{
specifier|const
name|QDir
name|dir
init|=
name|info
operator|.
name|absoluteFilePath
argument_list|()
decl_stmt|;
name|QFileInfo
name|fInfo
argument_list|(
name|dir
operator|.
name|filePath
argument_list|(
name|QLatin1String
argument_list|(
literal|"Properties.xml"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|fInfo
operator|.
name|exists
argument_list|()
condition|)
name|sdkPropertyFile
operator|.
name|setFileName
argument_list|(
name|fInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|sdkPropertyFile
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
continue|continue;
name|QXmlStreamReader
name|xml
argument_list|(
operator|&
name|sdkPropertyFile
argument_list|)
decl_stmt|;
name|QString
name|currentElement
decl_stmt|;
name|QString
name|curName
decl_stmt|;
name|PropertyContainer
name|currentProperty
decl_stmt|;
name|QVector
argument_list|<
name|PropertyContainer
argument_list|>
name|propStack
decl_stmt|;
name|propStack
operator|.
name|push_back
argument_list|(
name|currentProperty
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|xml
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|xml
operator|.
name|readNext
argument_list|()
expr_stmt|;
if|if
condition|(
name|xml
operator|.
name|isStartElement
argument_list|()
condition|)
block|{
name|currentElement
operator|=
name|xml
operator|.
name|name
argument_list|()
operator|.
name|toString
argument_list|()
expr_stmt|;
if|if
condition|(
name|currentElement
operator|==
name|QLatin1String
argument_list|(
literal|"Property"
argument_list|)
condition|)
block|{
name|QXmlStreamAttributes
name|attributes
init|=
name|xml
operator|.
name|attributes
argument_list|()
decl_stmt|;
if|if
condition|(
name|attributes
operator|.
name|hasAttribute
argument_list|(
name|QLatin1String
argument_list|(
literal|"NAME"
argument_list|)
argument_list|)
condition|)
name|curName
operator|=
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"NAME"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|curName
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|currentProperty
operator|.
name|clear
argument_list|()
expr_stmt|;
name|currentProperty
operator|.
name|name
operator|=
name|curName
expr_stmt|;
name|propStack
operator|.
name|push_back
argument_list|(
name|currentProperty
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|currentElement
operator|==
name|QLatin1String
argument_list|(
literal|"PropertyBag"
argument_list|)
condition|)
block|{
name|QXmlStreamAttributes
name|attributes
init|=
name|xml
operator|.
name|attributes
argument_list|()
decl_stmt|;
if|if
condition|(
name|attributes
operator|.
name|hasAttribute
argument_list|(
name|QLatin1String
argument_list|(
literal|"NAME"
argument_list|)
argument_list|)
condition|)
name|curName
operator|=
name|attributes
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"NAME"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|curName
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|currentProperty
operator|.
name|clear
argument_list|()
expr_stmt|;
name|currentProperty
operator|.
name|name
operator|=
name|curName
expr_stmt|;
name|propStack
operator|.
name|push_back
argument_list|(
name|currentProperty
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|isEndElement
argument_list|()
condition|)
block|{
name|currentElement
operator|=
name|xml
operator|.
name|name
argument_list|()
operator|.
name|toString
argument_list|()
expr_stmt|;
name|PropertyContainer
name|self
init|=
name|propStack
operator|.
name|takeLast
argument_list|()
decl_stmt|;
if|if
condition|(
name|currentElement
operator|!=
name|QLatin1String
argument_list|(
literal|"Root"
argument_list|)
condition|)
block|{
name|PropertyContainer
modifier|&
name|last
init|=
name|propStack
operator|.
name|last
argument_list|()
decl_stmt|;
name|last
operator|.
name|properties
index|[
name|self
operator|.
name|name
index|]
operator|=
name|self
expr_stmt|;
block|}
else|else
block|{
name|currentProperty
operator|=
name|self
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|isCharacters
argument_list|()
condition|)
block|{
name|PropertyContainer
modifier|&
name|self
init|=
name|propStack
operator|.
name|last
argument_list|()
decl_stmt|;
name|self
operator|.
name|value
operator|=
name|xml
operator|.
name|text
argument_list|()
operator|.
name|toString
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
name|xml
operator|.
name|error
argument_list|()
operator|&&
name|xml
operator|.
name|error
argument_list|()
operator|!=
name|QXmlStreamReader
operator|::
name|PrematureEndOfDocumentError
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"XML ERROR:"
operator|<<
name|xml
operator|.
name|lineNumber
argument_list|()
operator|<<
literal|": "
operator|<<
name|xml
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return;
block|}
name|CeSdkInfo
name|currentSdk
decl_stmt|;
specifier|const
name|PropertyContainer
modifier|&
name|cpuInfo
init|=
name|currentProperty
operator|.
name|properties
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"CPU info"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|cpuInfo
operator|.
name|properties
operator|.
name|isEmpty
argument_list|()
condition|)
continue|continue;
specifier|const
name|PropertyContainer
modifier|&
name|cpuInfoVal
init|=
name|cpuInfo
operator|.
name|properties
operator|.
name|first
argument_list|()
operator|.
name|properties
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"CpuName"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|cpuInfoVal
operator|.
name|name
operator|!=
name|QLatin1String
argument_list|(
literal|"CpuName"
argument_list|)
condition|)
continue|continue;
specifier|const
name|QString
name|SDKName
init|=
name|QStringLiteral
argument_list|(
literal|"SDK name"
argument_list|)
decl_stmt|;
name|currentSdk
operator|.
name|m_name
operator|=
name|currentProperty
operator|.
name|properties
operator|.
name|value
argument_list|(
name|SDKName
argument_list|)
operator|.
name|value
operator|+
name|QStringLiteral
argument_list|(
literal|" ("
argument_list|)
operator|+
name|cpuInfoVal
operator|.
name|value
operator|+
literal|")"
expr_stmt|;
name|currentSdk
operator|.
name|m_major
operator|=
name|currentProperty
operator|.
name|properties
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"OSMajor"
argument_list|)
argument_list|)
operator|.
name|value
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|currentSdk
operator|.
name|m_minor
operator|=
name|currentProperty
operator|.
name|properties
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"OSMinor"
argument_list|)
argument_list|)
operator|.
name|value
operator|.
name|toInt
argument_list|()
expr_stmt|;
name|retrieveEnvironment
argument_list|(
name|currentProperty
operator|.
name|properties
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"MSBuild Files110"
argument_list|)
argument_list|)
operator|.
name|value
operator|.
name|split
argument_list|(
literal|';'
argument_list|)
argument_list|,
name|filteredToolPaths
argument_list|,
operator|&
name|currentSdk
argument_list|)
expr_stmt|;
name|retrieveEnvironment
argument_list|(
name|currentProperty
operator|.
name|properties
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"MSBuild Files120"
argument_list|)
argument_list|)
operator|.
name|value
operator|.
name|split
argument_list|(
literal|';'
argument_list|)
argument_list|,
name|filteredToolPaths
argument_list|,
operator|&
name|currentSdk
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|currentSdk
operator|.
name|m_include
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_list
operator|.
name|append
argument_list|(
name|currentSdk
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|retrieveWEC6n7SDKs
name|void
name|CeSdkHandler
operator|::
name|retrieveWEC6n7SDKs
parameter_list|()
block|{
comment|// look at the file at %VCInstallDir%/vcpackages/WCE.VCPlatform.config
comment|// and scan through all installed sdks...
name|m_vcInstallDir
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|qgetenv
argument_list|(
literal|"VCInstallDir"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_vcInstallDir
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QDir
name|vStudioDir
argument_list|(
name|m_vcInstallDir
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|vStudioDir
operator|.
name|cd
argument_list|(
name|QLatin1String
argument_list|(
literal|"vcpackages"
argument_list|)
argument_list|)
condition|)
return|return;
name|QFile
name|configFile
argument_list|(
name|vStudioDir
operator|.
name|absoluteFilePath
argument_list|(
name|QLatin1String
argument_list|(
literal|"WCE.VCPlatform.config"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|configFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return;
name|QString
name|currentElement
decl_stmt|;
name|CeSdkInfo
name|currentItem
decl_stmt|;
name|QXmlStreamReader
name|xml
argument_list|(
operator|&
name|configFile
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|xml
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|xml
operator|.
name|readNext
argument_list|()
expr_stmt|;
if|if
condition|(
name|xml
operator|.
name|isStartElement
argument_list|()
condition|)
block|{
name|currentElement
operator|=
name|xml
operator|.
name|name
argument_list|()
operator|.
name|toString
argument_list|()
expr_stmt|;
if|if
condition|(
name|currentElement
operator|==
name|QLatin1String
argument_list|(
literal|"Platform"
argument_list|)
condition|)
block|{
name|currentItem
operator|=
name|CeSdkInfo
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|currentElement
operator|==
name|QLatin1String
argument_list|(
literal|"Directories"
argument_list|)
condition|)
block|{
name|QXmlStreamAttributes
name|attr
init|=
name|xml
operator|.
name|attributes
argument_list|()
decl_stmt|;
name|currentItem
operator|.
name|m_include
operator|=
name|fixPaths
argument_list|(
name|attr
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"Include"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|currentItem
operator|.
name|m_lib
operator|=
name|fixPaths
argument_list|(
name|attr
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"Library"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
name|currentItem
operator|.
name|m_bin
operator|=
name|fixPaths
argument_list|(
name|attr
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"Path"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|isEndElement
argument_list|()
condition|)
block|{
if|if
condition|(
name|xml
operator|.
name|name
argument_list|()
operator|.
name|toString
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"Platform"
argument_list|)
condition|)
name|m_list
operator|.
name|append
argument_list|(
name|currentItem
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|xml
operator|.
name|isCharacters
argument_list|()
operator|&&
operator|!
name|xml
operator|.
name|isWhitespace
argument_list|()
condition|)
block|{
if|if
condition|(
name|currentElement
operator|==
name|QLatin1String
argument_list|(
literal|"PlatformName"
argument_list|)
condition|)
name|currentItem
operator|.
name|m_name
operator|=
name|xml
operator|.
name|text
argument_list|()
operator|.
name|toString
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|currentElement
operator|==
name|QLatin1String
argument_list|(
literal|"OSMajorVersion"
argument_list|)
condition|)
name|currentItem
operator|.
name|m_major
operator|=
name|xml
operator|.
name|text
argument_list|()
operator|.
name|toString
argument_list|()
operator|.
name|toInt
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|currentElement
operator|==
name|QLatin1String
argument_list|(
literal|"OSMinorVersion"
argument_list|)
condition|)
name|currentItem
operator|.
name|m_minor
operator|=
name|xml
operator|.
name|text
argument_list|()
operator|.
name|toString
argument_list|()
operator|.
name|toInt
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
name|xml
operator|.
name|error
argument_list|()
operator|&&
name|xml
operator|.
name|error
argument_list|()
operator|!=
name|QXmlStreamReader
operator|::
name|PrematureEndOfDocumentError
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"XML ERROR:"
operator|<<
name|xml
operator|.
name|lineNumber
argument_list|()
operator|<<
literal|": "
operator|<<
name|xml
operator|.
name|errorString
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
end_function
begin_function
DECL|function|retrieveAvailableSDKs
name|bool
name|CeSdkHandler
operator|::
name|retrieveAvailableSDKs
parameter_list|()
block|{
name|m_list
operator|.
name|clear
argument_list|()
expr_stmt|;
name|retrieveWEC2013SDKs
argument_list|()
expr_stmt|;
name|retrieveWEC6n7SDKs
argument_list|()
expr_stmt|;
return|return
operator|!
name|m_list
operator|.
name|empty
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fixPaths
name|QString
name|CeSdkHandler
operator|::
name|fixPaths
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
specifier|const
block|{
name|QRegExp
name|searchStr
argument_list|(
name|QLatin1String
argument_list|(
literal|"(\\$\\(\\w+\\))"
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|fixedString
init|=
name|path
decl_stmt|;
for|for
control|(
name|int
name|index
init|=
name|fixedString
operator|.
name|indexOf
argument_list|(
name|searchStr
argument_list|,
literal|0
argument_list|)
init|;
name|index
operator|>=
literal|0
condition|;
name|index
operator|=
name|fixedString
operator|.
name|indexOf
argument_list|(
name|searchStr
argument_list|,
name|index
argument_list|)
control|)
block|{
specifier|const
name|QString
name|capture
init|=
name|searchStr
operator|.
name|cap
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|fixedString
operator|.
name|replace
argument_list|(
name|index
argument_list|,
name|capture
operator|.
name|length
argument_list|()
argument_list|,
name|capture
operator|.
name|toUpper
argument_list|()
argument_list|)
expr_stmt|;
name|index
operator|+=
name|capture
operator|.
name|length
argument_list|()
expr_stmt|;
comment|// don't count the zero terminator
name|fixedString
operator|.
name|insert
argument_list|(
name|index
argument_list|,
literal|'\\'
argument_list|)
expr_stmt|;
comment|// the configuration file lacks a directory separator for env vars
operator|++
name|index
expr_stmt|;
block|}
return|return
name|fixedString
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
