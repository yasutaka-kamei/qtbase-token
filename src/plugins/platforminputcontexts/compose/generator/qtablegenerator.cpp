begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtablegenerator.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QRegularExpression>
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextCodec>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<xkbcommon/xkbcommon.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|XKBCOMMON_0_2_0
end_ifdef
begin_include
include|#
directive|include
file|<xkbcommon_workaround.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//#define DEBUG_GENERATOR
end_comment
begin_constructor
DECL|function|TableGenerator
name|TableGenerator
operator|::
name|TableGenerator
parameter_list|()
member_init_list|:
name|m_state
argument_list|(
name|NoErrors
argument_list|)
member_init_list|,
name|m_systemComposeDir
argument_list|(
name|QString
argument_list|()
argument_list|)
block|{
name|initPossibleLocations
argument_list|()
expr_stmt|;
name|findComposeFile
argument_list|()
expr_stmt|;
name|orderComposeTable
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG_GENERATOR
name|printComposeTable
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_function
DECL|function|initPossibleLocations
name|void
name|TableGenerator
operator|::
name|initPossibleLocations
parameter_list|()
block|{
comment|// AFAICT there is no way to know the exact location
comment|// of the compose files. It depends on how Xlib was configured
comment|// on a specific platform. During the "./configure" process
comment|// xlib generates a config.h file which contains a bunch of defines,
comment|// including XLOCALEDIR which points to the location of the compose file dir.
comment|// To add an extra system path use the QTCOMPOSE environment variable
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
literal|"QTCOMPOSE"
argument_list|)
condition|)
block|{
name|m_possibleLocations
operator|.
name|append
argument_list|(
name|QString
argument_list|(
name|qgetenv
argument_list|(
literal|"QTCOMPOSE"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|m_possibleLocations
operator|.
name|append
argument_list|(
name|QStringLiteral
argument_list|(
literal|"/usr/share/X11/locale"
argument_list|)
argument_list|)
expr_stmt|;
name|m_possibleLocations
operator|.
name|append
argument_list|(
name|QStringLiteral
argument_list|(
literal|"/usr/lib/X11/locale"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|findComposeFile
name|void
name|TableGenerator
operator|::
name|findComposeFile
parameter_list|()
block|{
name|bool
name|found
init|=
literal|false
decl_stmt|;
comment|// check if XCOMPOSEFILE points to a Compose file
if|if
condition|(
name|qEnvironmentVariableIsSet
argument_list|(
literal|"XCOMPOSEFILE"
argument_list|)
condition|)
block|{
name|QString
name|composeFile
argument_list|(
name|qgetenv
argument_list|(
literal|"XCOMPOSEFILE"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|composeFile
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"Compose"
argument_list|)
argument_list|)
condition|)
name|found
operator|=
name|processFile
argument_list|(
name|composeFile
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"Qt Warning: XCOMPOSEFILE doesn't point to a valid Compose file"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG_GENERATOR
if|if
condition|(
name|found
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Using Compose file from: "
operator|<<
name|composeFile
expr_stmt|;
endif|#
directive|endif
block|}
comment|// check if userâs home directory has a file named .XCompose
if|if
condition|(
operator|!
name|found
operator|&&
name|cleanState
argument_list|()
condition|)
block|{
name|QString
name|composeFile
init|=
name|qgetenv
argument_list|(
literal|"HOME"
argument_list|)
operator|+
name|QStringLiteral
argument_list|(
literal|"/.XCompose"
argument_list|)
decl_stmt|;
if|if
condition|(
name|QFile
argument_list|(
name|composeFile
argument_list|)
operator|.
name|exists
argument_list|()
condition|)
name|found
operator|=
name|processFile
argument_list|(
name|composeFile
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG_GENERATOR
if|if
condition|(
name|found
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Using Compose file from: "
operator|<<
name|composeFile
expr_stmt|;
endif|#
directive|endif
block|}
comment|// check for the system provided compose files
if|if
condition|(
operator|!
name|found
operator|&&
name|cleanState
argument_list|()
condition|)
block|{
name|readLocaleMappings
argument_list|()
expr_stmt|;
if|if
condition|(
name|cleanState
argument_list|()
condition|)
block|{
name|QString
name|table
init|=
name|m_localeToTable
operator|.
name|value
argument_list|(
name|locale
argument_list|()
operator|.
name|toUpper
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|table
operator|.
name|isEmpty
argument_list|()
condition|)
comment|// no table mappings for the system's locale in the compose.dir
name|m_state
operator|=
name|UnsupportedLocale
expr_stmt|;
else|else
name|found
operator|=
name|processFile
argument_list|(
name|systemComposeDir
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/"
argument_list|)
operator|+
name|table
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG_GENERATOR
if|if
condition|(
name|found
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Using Compose file from: "
operator|<<
name|systemComposeDir
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/"
argument_list|)
operator|+
name|table
expr_stmt|;
endif|#
directive|endif
block|}
block|}
if|if
condition|(
name|found
operator|&&
name|m_composeTable
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_state
operator|=
name|EmptyTable
expr_stmt|;
if|if
condition|(
operator|!
name|found
condition|)
name|m_state
operator|=
name|MissingComposeFile
expr_stmt|;
block|}
end_function
begin_function
DECL|function|findSystemComposeDir
name|bool
name|TableGenerator
operator|::
name|findSystemComposeDir
parameter_list|()
block|{
name|bool
name|found
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|m_possibleLocations
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|path
init|=
name|m_possibleLocations
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|QFile
argument_list|(
name|path
operator|+
name|QLatin1String
argument_list|(
literal|"/compose.dir"
argument_list|)
argument_list|)
operator|.
name|exists
argument_list|()
condition|)
block|{
name|m_systemComposeDir
operator|=
name|path
expr_stmt|;
name|found
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
operator|!
name|found
condition|)
block|{
comment|// should we ask to report this in the qt bug tracker?
name|m_state
operator|=
name|UnknownSystemComposeDir
expr_stmt|;
name|qWarning
argument_list|(
literal|"Qt Warning: Could not find a location of the system's Compose files. "
literal|"Consider setting the QTCOMPOSE environment variable."
argument_list|)
expr_stmt|;
block|}
return|return
name|found
return|;
block|}
end_function
begin_function
DECL|function|systemComposeDir
name|QString
name|TableGenerator
operator|::
name|systemComposeDir
parameter_list|()
block|{
if|if
condition|(
name|m_systemComposeDir
operator|.
name|isNull
argument_list|()
operator|&&
operator|!
name|findSystemComposeDir
argument_list|()
condition|)
block|{
return|return
name|QLatin1String
argument_list|(
literal|"$QTCOMPOSE"
argument_list|)
return|;
block|}
return|return
name|m_systemComposeDir
return|;
block|}
end_function
begin_function
DECL|function|locale
name|QString
name|TableGenerator
operator|::
name|locale
parameter_list|()
specifier|const
block|{
name|char
modifier|*
name|name
init|=
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
decl_stmt|;
return|return
name|QLatin1String
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|readLocaleMappings
name|void
name|TableGenerator
operator|::
name|readLocaleMappings
parameter_list|()
block|{
name|QFile
name|mappings
argument_list|(
name|systemComposeDir
argument_list|()
operator|+
name|QLatin1String
argument_list|(
literal|"/compose.dir"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|mappings
operator|.
name|exists
argument_list|()
condition|)
block|{
name|mappings
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QTextStream
name|in
argument_list|(
operator|&
name|mappings
argument_list|)
decl_stmt|;
comment|// formating of compose.dir has some inconsistencies
while|while
condition|(
operator|!
name|in
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QString
name|line
init|=
name|in
operator|.
name|readLine
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|line
operator|.
name|startsWith
argument_list|(
literal|"#"
argument_list|)
operator|&&
name|line
operator|.
name|size
argument_list|()
operator|!=
literal|0
operator|&&
name|line
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|isLower
argument_list|()
condition|)
block|{
name|QStringList
name|pair
init|=
name|line
operator|.
name|split
argument_list|(
name|QRegExp
argument_list|(
name|QLatin1String
argument_list|(
literal|"\\s+"
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|table
init|=
name|pair
operator|.
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|table
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|":"
argument_list|)
argument_list|)
condition|)
name|table
operator|.
name|remove
argument_list|(
name|table
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|m_localeToTable
operator|.
name|insert
argument_list|(
name|pair
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|.
name|toUpper
argument_list|()
argument_list|,
name|table
argument_list|)
expr_stmt|;
block|}
block|}
name|mappings
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|processFile
name|bool
name|TableGenerator
operator|::
name|processFile
parameter_list|(
name|QString
name|composeFileName
parameter_list|)
block|{
name|QFile
name|composeFile
argument_list|(
name|composeFileName
argument_list|)
decl_stmt|;
if|if
condition|(
name|composeFile
operator|.
name|exists
argument_list|()
condition|)
block|{
name|composeFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|parseComposeFile
argument_list|(
operator|&
name|composeFile
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
name|qWarning
argument_list|()
operator|<<
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"Qt Warning: Compose file: \"%1\" can't be found"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|composeFile
operator|.
name|fileName
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_destructor
DECL|function|~TableGenerator
name|TableGenerator
operator|::
name|~
name|TableGenerator
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|composeTable
name|QList
argument_list|<
name|QComposeTableElement
argument_list|>
name|TableGenerator
operator|::
name|composeTable
parameter_list|()
specifier|const
block|{
return|return
name|m_composeTable
return|;
block|}
end_function
begin_function
DECL|function|parseComposeFile
name|void
name|TableGenerator
operator|::
name|parseComposeFile
parameter_list|(
name|QFile
modifier|*
name|composeFile
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|DEBUG_GENERATOR
name|qDebug
argument_list|()
operator|<<
literal|"TableGenerator::parseComposeFile: "
operator|<<
name|composeFile
operator|->
name|fileName
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|QTextStream
name|in
argument_list|(
name|composeFile
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|in
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QString
name|line
init|=
name|in
operator|.
name|readLine
argument_list|()
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"<"
argument_list|)
argument_list|)
condition|)
block|{
name|parseKeySequence
argument_list|(
name|line
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"include"
argument_list|)
argument_list|)
condition|)
block|{
name|parseIncludeInstruction
argument_list|(
name|line
argument_list|)
expr_stmt|;
block|}
block|}
name|composeFile
operator|->
name|close
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|parseIncludeInstruction
name|void
name|TableGenerator
operator|::
name|parseIncludeInstruction
parameter_list|(
name|QString
name|line
parameter_list|)
block|{
comment|// Parse something that looks like:
comment|// include "/usr/share/X11/locale/en_US.UTF-8/Compose"
name|QString
name|quote
init|=
name|QStringLiteral
argument_list|(
literal|"\""
argument_list|)
decl_stmt|;
name|line
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
name|line
operator|.
name|indexOf
argument_list|(
name|quote
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|line
operator|.
name|chop
argument_list|(
name|line
operator|.
name|length
argument_list|()
operator|-
name|line
operator|.
name|indexOf
argument_list|(
name|quote
argument_list|)
argument_list|)
expr_stmt|;
comment|// expand substitutions if present
name|line
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"%H"
argument_list|)
argument_list|,
name|QString
argument_list|(
name|qgetenv
argument_list|(
literal|"HOME"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|line
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"%L"
argument_list|)
argument_list|,
name|locale
argument_list|()
argument_list|)
expr_stmt|;
name|line
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"%S"
argument_list|)
argument_list|,
name|systemComposeDir
argument_list|()
argument_list|)
expr_stmt|;
name|processFile
argument_list|(
name|line
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keysymToUtf8
name|ushort
name|TableGenerator
operator|::
name|keysymToUtf8
parameter_list|(
name|quint32
name|sym
parameter_list|)
block|{
name|QByteArray
name|chars
decl_stmt|;
name|int
name|bytes
decl_stmt|;
name|chars
operator|.
name|resize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|XKBCOMMON_0_2_0
if|if
condition|(
name|needWorkaround
argument_list|(
name|sym
argument_list|)
condition|)
block|{
name|quint32
name|codepoint
decl_stmt|;
if|if
condition|(
name|sym
operator|==
name|XKB_KEY_KP_Space
condition|)
name|codepoint
operator|=
name|XKB_KEY_space
operator|&
literal|0x7f
expr_stmt|;
else|else
name|codepoint
operator|=
name|sym
operator|&
literal|0x7f
expr_stmt|;
name|bytes
operator|=
name|utf32_to_utf8
argument_list|(
name|codepoint
argument_list|,
name|chars
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|bytes
operator|=
name|xkb_keysym_to_utf8
argument_list|(
name|sym
argument_list|,
name|chars
operator|.
name|data
argument_list|()
argument_list|,
name|chars
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|bytes
operator|=
name|xkb_keysym_to_utf8
argument_list|(
name|sym
argument_list|,
name|chars
operator|.
name|data
argument_list|()
argument_list|,
name|chars
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|bytes
operator|==
operator|-
literal|1
condition|)
name|qWarning
argument_list|(
literal|"TableGenerator::keysymToUtf8 - buffer too small"
argument_list|)
expr_stmt|;
name|chars
operator|.
name|resize
argument_list|(
name|bytes
operator|-
literal|1
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG_GENERATOR
name|QTextCodec
modifier|*
name|codec
init|=
name|QTextCodec
operator|::
name|codecForLocale
argument_list|()
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"keysym - 0x%1 : utf8 - %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|sym
argument_list|,
literal|16
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|codec
operator|->
name|toUnicode
argument_list|(
name|chars
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|QString
operator|::
name|fromUtf8
argument_list|(
name|chars
argument_list|)
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|unicode
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|stringToKeysym
name|quint32
name|TableGenerator
operator|::
name|stringToKeysym
parameter_list|(
name|QString
name|keysymName
parameter_list|)
block|{
name|quint32
name|keysym
decl_stmt|;
name|QByteArray
name|keysymArray
init|=
name|keysymName
operator|.
name|toLatin1
argument_list|()
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
init|=
name|keysymArray
operator|.
name|constData
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|keysym
operator|=
name|xkb_keysym_from_name
argument_list|(
name|name
argument_list|,
operator|(
name|xkb_keysym_flags
operator|)
literal|0
argument_list|)
operator|)
operator|==
name|XKB_KEY_NoSymbol
condition|)
name|qWarning
argument_list|()
operator|<<
name|QString
argument_list|(
literal|"Qt Warning - invalid keysym: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|keysymName
argument_list|)
expr_stmt|;
return|return
name|keysym
return|;
block|}
end_function
begin_function
DECL|function|parseKeySequence
name|void
name|TableGenerator
operator|::
name|parseKeySequence
parameter_list|(
name|QString
name|line
parameter_list|)
block|{
comment|// we are interested in the lines with the following format:
comment|//<Multi_key><numbersign><S> : "â¬"   U266c # BEAMED SIXTEENTH NOTE
name|int
name|keysEnd
init|=
name|line
operator|.
name|indexOf
argument_list|(
name|QLatin1String
argument_list|(
literal|":"
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|keys
init|=
name|line
operator|.
name|left
argument_list|(
name|keysEnd
argument_list|)
operator|.
name|trimmed
argument_list|()
decl_stmt|;
comment|// find the key sequence
name|QString
name|regexp
init|=
name|QStringLiteral
argument_list|(
literal|"<[^>]+>"
argument_list|)
decl_stmt|;
name|QRegularExpression
name|reg
argument_list|(
name|regexp
argument_list|)
decl_stmt|;
name|QRegularExpressionMatchIterator
name|i
init|=
name|reg
operator|.
name|globalMatch
argument_list|(
name|keys
argument_list|)
decl_stmt|;
name|QStringList
name|keyList
decl_stmt|;
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|QRegularExpressionMatch
name|match
init|=
name|i
operator|.
name|next
argument_list|()
decl_stmt|;
name|QString
name|word
init|=
name|match
operator|.
name|captured
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|keyList
operator|<<
name|word
expr_stmt|;
block|}
name|QComposeTableElement
name|elem
decl_stmt|;
name|QString
name|quote
init|=
name|QStringLiteral
argument_list|(
literal|"\""
argument_list|)
decl_stmt|;
comment|// find the composed value - strings may be direct text encoded in the locale
comment|// for which the compose file is to be used, or an escaped octal or hexadecimal
comment|// character code. Octal codes are specified as "\123" and hexadecimal codes as "\0x123a".
name|int
name|composeValueIndex
init|=
name|line
operator|.
name|indexOf
argument_list|(
name|quote
argument_list|,
name|keysEnd
argument_list|)
operator|+
literal|1
decl_stmt|;
specifier|const
name|QChar
name|valueType
argument_list|(
name|line
operator|.
name|at
argument_list|(
name|composeValueIndex
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|valueType
operator|==
literal|'\\'
operator|&&
name|line
operator|.
name|at
argument_list|(
name|composeValueIndex
operator|+
literal|1
argument_list|)
operator|.
name|isDigit
argument_list|()
condition|)
block|{
comment|// handle octal and hex code values
name|QChar
name|detectBase
argument_list|(
name|line
operator|.
name|at
argument_list|(
name|composeValueIndex
operator|+
literal|2
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|codeValue
init|=
name|line
operator|.
name|mid
argument_list|(
name|composeValueIndex
operator|+
literal|1
argument_list|,
name|line
operator|.
name|lastIndexOf
argument_list|(
name|quote
argument_list|)
operator|-
name|composeValueIndex
operator|-
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|detectBase
operator|==
literal|'x'
condition|)
block|{
comment|// hexadecimal character code
name|elem
operator|.
name|value
operator|=
name|keysymToUtf8
argument_list|(
name|codeValue
operator|.
name|toUInt
argument_list|(
literal|0
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// octal character code
name|QString
name|hexStr
init|=
name|QString
operator|::
name|number
argument_list|(
name|codeValue
operator|.
name|toUInt
argument_list|(
literal|0
argument_list|,
literal|8
argument_list|)
argument_list|,
literal|16
argument_list|)
decl_stmt|;
name|elem
operator|.
name|value
operator|=
name|keysymToUtf8
argument_list|(
name|hexStr
operator|.
name|toUInt
argument_list|(
literal|0
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// handle direct text encoded in the locale
specifier|const
name|QChar
name|localeValueType
init|=
operator|(
name|valueType
operator|==
literal|'\\'
operator|)
condition|?
name|line
operator|.
name|at
argument_list|(
name|composeValueIndex
operator|+
literal|1
argument_list|)
else|:
name|valueType
decl_stmt|;
name|elem
operator|.
name|value
operator|=
name|localeValueType
operator|.
name|unicode
argument_list|()
expr_stmt|;
block|}
comment|// find the comment
name|int
name|commnetIndex
init|=
name|line
operator|.
name|lastIndexOf
argument_list|(
name|quote
argument_list|)
operator|+
literal|1
decl_stmt|;
name|elem
operator|.
name|comment
operator|=
name|line
operator|.
name|mid
argument_list|(
name|commnetIndex
argument_list|)
operator|.
name|trimmed
argument_list|()
expr_stmt|;
comment|// Convert to X11 keysym
name|int
name|count
init|=
name|keyList
operator|.
name|length
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|QT_KEYSEQUENCE_MAX_LEN
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|<
name|count
condition|)
block|{
name|QString
name|keysym
init|=
name|keyList
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|keysym
operator|.
name|remove
argument_list|(
name|keysym
operator|.
name|length
argument_list|()
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|keysym
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|keysym
operator|==
name|QLatin1String
argument_list|(
literal|"dead_inverted_breve"
argument_list|)
condition|)
name|keysym
operator|=
name|QStringLiteral
argument_list|(
literal|"dead_invertedbreve"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keysym
operator|==
name|QLatin1String
argument_list|(
literal|"dead_double_grave"
argument_list|)
condition|)
name|keysym
operator|=
name|QStringLiteral
argument_list|(
literal|"dead_doublegrave"
argument_list|)
expr_stmt|;
name|elem
operator|.
name|keys
index|[
name|i
index|]
operator|=
name|stringToKeysym
argument_list|(
name|keysym
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|elem
operator|.
name|keys
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
name|m_composeTable
operator|.
name|append
argument_list|(
name|elem
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|printComposeTable
name|void
name|TableGenerator
operator|::
name|printComposeTable
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|composeTable
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QString
name|output
decl_stmt|;
name|QComposeTableElement
name|elem
decl_stmt|;
name|QString
name|comma
init|=
name|QStringLiteral
argument_list|(
literal|","
argument_list|)
decl_stmt|;
name|int
name|tableSize
init|=
name|m_composeTable
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|tableSize
condition|;
operator|++
name|i
control|)
block|{
name|elem
operator|=
name|m_composeTable
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|output
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
literal|"{ {"
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|QT_KEYSEQUENCE_MAX_LEN
condition|;
name|j
operator|++
control|)
block|{
name|output
operator|.
name|append
argument_list|(
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"0x%1, "
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|elem
operator|.
name|keys
index|[
name|j
index|]
argument_list|,
literal|16
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// take care of the trailing comma
if|if
condition|(
name|i
operator|==
name|tableSize
operator|-
literal|1
condition|)
name|comma
operator|=
name|QStringLiteral
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|output
operator|.
name|append
argument_list|(
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"}, 0x%1, \"\" }%2 // %3 \n"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|elem
operator|.
name|value
argument_list|,
literal|16
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|comma
argument_list|)
operator|.
name|arg
argument_list|(
name|elem
operator|.
name|comment
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|qDebug
argument_list|()
operator|<<
literal|"output: \n"
operator|<<
name|output
expr_stmt|;
block|}
end_function
begin_function
DECL|function|orderComposeTable
name|void
name|TableGenerator
operator|::
name|orderComposeTable
parameter_list|()
block|{
comment|// Stable-sorting to ensure that the item that appeared before the other in the
comment|// original container will still appear first after the sort. This property is
comment|// needed to handle the cases when user re-defines already defined key sequence
name|qStableSort
argument_list|(
name|m_composeTable
operator|.
name|begin
argument_list|()
argument_list|,
name|m_composeTable
operator|.
name|end
argument_list|()
argument_list|,
name|Compare
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
