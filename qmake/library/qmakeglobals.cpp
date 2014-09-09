begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qmakeglobals.h"
end_include
begin_include
include|#
directive|include
file|"qmakeevaluator.h"
end_include
begin_include
include|#
directive|include
file|"ioutils.h"
end_include
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
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
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|<qstack.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|PROEVALUATOR_THREAD_SAFE
end_ifdef
begin_include
include|#
directive|include
file|<qthreadpool.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_UNIX
end_ifdef
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN32
end_ifdef
begin_define
DECL|macro|QT_POPEN
define|#
directive|define
name|QT_POPEN
value|_popen
end_define
begin_define
DECL|macro|QT_PCLOSE
define|#
directive|define
name|QT_PCLOSE
value|_pclose
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_POPEN
define|#
directive|define
name|QT_POPEN
value|popen
end_define
begin_define
DECL|macro|QT_PCLOSE
define|#
directive|define
name|QT_PCLOSE
value|pclose
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|macro|fL1S
define|#
directive|define
name|fL1S
parameter_list|(
name|s
parameter_list|)
value|QString::fromLatin1(s)
DECL|function|QMakeGlobals
name|QMakeGlobals
operator|::
name|QMakeGlobals
parameter_list|()
block|{
name|do_cache
operator|=
literal|true
expr_stmt|;
ifdef|#
directive|ifdef
name|PROEVALUATOR_DEBUG
name|debugLevel
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|dirlist_sep
operator|=
name|QLatin1Char
argument_list|(
literal|';'
argument_list|)
expr_stmt|;
name|dir_sep
operator|=
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
expr_stmt|;
else|#
directive|else
name|dirlist_sep
operator|=
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
expr_stmt|;
name|dir_sep
operator|=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_destructor
DECL|function|~QMakeGlobals
name|QMakeGlobals
operator|::
name|~
name|QMakeGlobals
parameter_list|()
block|{
name|qDeleteAll
argument_list|(
name|baseEnvs
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|cleanSpec
name|QString
name|QMakeGlobals
operator|::
name|cleanSpec
parameter_list|(
name|QMakeCmdLineParserState
modifier|&
name|state
parameter_list|,
specifier|const
name|QString
modifier|&
name|spec
parameter_list|)
block|{
name|QString
name|ret
init|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|spec
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
block|{
name|QString
name|absRet
init|=
name|QDir
argument_list|(
name|state
operator|.
name|pwd
argument_list|)
operator|.
name|absoluteFilePath
argument_list|(
name|ret
argument_list|)
decl_stmt|;
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|absRet
argument_list|)
condition|)
name|ret
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|absRet
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|addCommandLineArguments
name|QMakeGlobals
operator|::
name|ArgumentReturn
name|QMakeGlobals
operator|::
name|addCommandLineArguments
parameter_list|(
name|QMakeCmdLineParserState
modifier|&
name|state
parameter_list|,
name|QStringList
modifier|&
name|args
parameter_list|,
name|int
modifier|*
name|pos
parameter_list|)
block|{
enum|enum
block|{
name|ArgNone
block|,
name|ArgConfig
block|,
name|ArgSpec
block|,
name|ArgXSpec
block|,
name|ArgTmpl
block|,
name|ArgTmplPfx
block|,
name|ArgCache
block|}
name|argState
init|=
name|ArgNone
enum|;
for|for
control|(
init|;
operator|*
name|pos
operator|<
name|args
operator|.
name|count
argument_list|()
condition|;
operator|(
operator|*
name|pos
operator|)
operator|++
control|)
block|{
name|QString
name|arg
init|=
name|args
operator|.
name|at
argument_list|(
operator|*
name|pos
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|argState
condition|)
block|{
case|case
name|ArgConfig
case|:
if|if
condition|(
name|state
operator|.
name|after
condition|)
name|state
operator|.
name|postconfigs
operator|<<
name|arg
expr_stmt|;
else|else
name|state
operator|.
name|preconfigs
operator|<<
name|arg
expr_stmt|;
break|break;
case|case
name|ArgSpec
case|:
name|qmakespec
operator|=
name|args
index|[
operator|*
name|pos
index|]
operator|=
name|cleanSpec
argument_list|(
name|state
argument_list|,
name|arg
argument_list|)
expr_stmt|;
break|break;
case|case
name|ArgXSpec
case|:
name|xqmakespec
operator|=
name|args
index|[
operator|*
name|pos
index|]
operator|=
name|cleanSpec
argument_list|(
name|state
argument_list|,
name|arg
argument_list|)
expr_stmt|;
break|break;
case|case
name|ArgTmpl
case|:
name|user_template
operator|=
name|arg
expr_stmt|;
break|break;
case|case
name|ArgTmplPfx
case|:
name|user_template_prefix
operator|=
name|arg
expr_stmt|;
break|break;
case|case
name|ArgCache
case|:
name|cachefile
operator|=
name|args
index|[
operator|*
name|pos
index|]
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|QDir
argument_list|(
name|state
operator|.
name|pwd
argument_list|)
operator|.
name|absoluteFilePath
argument_list|(
name|arg
argument_list|)
argument_list|)
expr_stmt|;
break|break;
default|default:
if|if
condition|(
name|arg
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'-'
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-after"
argument_list|)
condition|)
name|state
operator|.
name|after
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-config"
argument_list|)
condition|)
name|argState
operator|=
name|ArgConfig
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-nocache"
argument_list|)
condition|)
name|do_cache
operator|=
literal|false
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-cache"
argument_list|)
condition|)
name|argState
operator|=
name|ArgCache
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-platform"
argument_list|)
operator|||
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-spec"
argument_list|)
condition|)
name|argState
operator|=
name|ArgSpec
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-xplatform"
argument_list|)
operator|||
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-xspec"
argument_list|)
condition|)
name|argState
operator|=
name|ArgXSpec
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-template"
argument_list|)
operator|||
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-t"
argument_list|)
condition|)
name|argState
operator|=
name|ArgTmpl
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-template_prefix"
argument_list|)
operator|||
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-tp"
argument_list|)
condition|)
name|argState
operator|=
name|ArgTmplPfx
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-win32"
argument_list|)
condition|)
name|dir_sep
operator|=
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-unix"
argument_list|)
condition|)
name|dir_sep
operator|=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
else|else
return|return
name|ArgumentUnknown
return|;
block|}
elseif|else
if|if
condition|(
name|arg
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'='
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
name|state
operator|.
name|after
condition|)
name|state
operator|.
name|postcmds
operator|<<
name|arg
expr_stmt|;
else|else
name|state
operator|.
name|precmds
operator|<<
name|arg
expr_stmt|;
block|}
else|else
block|{
return|return
name|ArgumentUnknown
return|;
block|}
continue|continue;
block|}
name|argState
operator|=
name|ArgNone
expr_stmt|;
block|}
if|if
condition|(
name|argState
operator|!=
name|ArgNone
condition|)
return|return
name|ArgumentMalformed
return|;
return|return
name|ArgumentsOk
return|;
block|}
end_function
begin_function
DECL|function|commitCommandLineArguments
name|void
name|QMakeGlobals
operator|::
name|commitCommandLineArguments
parameter_list|(
name|QMakeCmdLineParserState
modifier|&
name|state
parameter_list|)
block|{
if|if
condition|(
operator|!
name|state
operator|.
name|preconfigs
operator|.
name|isEmpty
argument_list|()
condition|)
name|state
operator|.
name|precmds
operator|<<
operator|(
name|fL1S
argument_list|(
literal|"CONFIG += "
argument_list|)
operator|+
name|state
operator|.
name|preconfigs
operator|.
name|join
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|precmds
operator|=
name|state
operator|.
name|precmds
operator|.
name|join
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|state
operator|.
name|postconfigs
operator|.
name|isEmpty
argument_list|()
condition|)
name|state
operator|.
name|postcmds
operator|<<
operator|(
name|fL1S
argument_list|(
literal|"CONFIG += "
argument_list|)
operator|+
name|state
operator|.
name|postconfigs
operator|.
name|join
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
operator|)
expr_stmt|;
name|postcmds
operator|=
name|state
operator|.
name|postcmds
operator|.
name|join
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|xqmakespec
operator|.
name|isEmpty
argument_list|()
condition|)
name|xqmakespec
operator|=
name|qmakespec
expr_stmt|;
block|}
end_function
begin_function
DECL|function|useEnvironment
name|void
name|QMakeGlobals
operator|::
name|useEnvironment
parameter_list|()
block|{
if|if
condition|(
name|xqmakespec
operator|.
name|isEmpty
argument_list|()
condition|)
name|xqmakespec
operator|=
name|getEnv
argument_list|(
name|QLatin1String
argument_list|(
literal|"XQMAKESPEC"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|qmakespec
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qmakespec
operator|=
name|getEnv
argument_list|(
name|QLatin1String
argument_list|(
literal|"QMAKESPEC"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|xqmakespec
operator|.
name|isEmpty
argument_list|()
condition|)
name|xqmakespec
operator|=
name|qmakespec
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setCommandLineArguments
name|void
name|QMakeGlobals
operator|::
name|setCommandLineArguments
parameter_list|(
specifier|const
name|QString
modifier|&
name|pwd
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|_args
parameter_list|)
block|{
name|QStringList
name|args
init|=
name|_args
decl_stmt|;
name|QMakeCmdLineParserState
name|state
argument_list|(
name|pwd
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|pos
init|=
literal|0
init|;
name|pos
operator|<
name|args
operator|.
name|size
argument_list|()
condition|;
name|pos
operator|++
control|)
name|addCommandLineArguments
argument_list|(
name|state
argument_list|,
name|args
argument_list|,
operator|&
name|pos
argument_list|)
expr_stmt|;
name|commitCommandLineArguments
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|useEnvironment
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDirectories
name|void
name|QMakeGlobals
operator|::
name|setDirectories
parameter_list|(
specifier|const
name|QString
modifier|&
name|input_dir
parameter_list|,
specifier|const
name|QString
modifier|&
name|output_dir
parameter_list|)
block|{
if|if
condition|(
name|input_dir
operator|!=
name|output_dir
operator|&&
operator|!
name|output_dir
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QString
name|srcpath
init|=
name|input_dir
decl_stmt|;
if|if
condition|(
operator|!
name|srcpath
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|srcpath
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
name|QString
name|dstpath
init|=
name|output_dir
decl_stmt|;
if|if
condition|(
operator|!
name|dstpath
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|dstpath
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
name|int
name|srcLen
init|=
name|srcpath
operator|.
name|length
argument_list|()
decl_stmt|;
name|int
name|dstLen
init|=
name|dstpath
operator|.
name|length
argument_list|()
decl_stmt|;
name|int
name|lastSl
init|=
operator|-
literal|1
decl_stmt|;
while|while
condition|(
operator|++
name|lastSl
operator|,
operator|--
name|srcLen
operator|,
operator|--
name|dstLen
operator|,
name|srcLen
operator|&&
name|dstLen
operator|&&
name|srcpath
operator|.
name|at
argument_list|(
name|srcLen
argument_list|)
operator|==
name|dstpath
operator|.
name|at
argument_list|(
name|dstLen
argument_list|)
condition|)
if|if
condition|(
name|srcpath
operator|.
name|at
argument_list|(
name|srcLen
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
condition|)
name|lastSl
operator|=
literal|0
expr_stmt|;
name|source_root
operator|=
name|srcpath
operator|.
name|left
argument_list|(
name|srcLen
operator|+
name|lastSl
argument_list|)
expr_stmt|;
name|build_root
operator|=
name|dstpath
operator|.
name|left
argument_list|(
name|dstLen
operator|+
name|lastSl
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|shadowedPath
name|QString
name|QMakeGlobals
operator|::
name|shadowedPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|source_root
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|fileName
return|;
if|if
condition|(
name|fileName
operator|.
name|startsWith
argument_list|(
name|source_root
argument_list|)
operator|&&
operator|(
name|fileName
operator|.
name|length
argument_list|()
operator|==
name|source_root
operator|.
name|length
argument_list|()
operator|||
name|fileName
operator|.
name|at
argument_list|(
name|source_root
operator|.
name|length
argument_list|()
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|)
condition|)
block|{
return|return
name|build_root
operator|+
name|fileName
operator|.
name|mid
argument_list|(
name|source_root
operator|.
name|length
argument_list|()
argument_list|)
return|;
block|}
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|splitPathList
name|QStringList
name|QMakeGlobals
operator|::
name|splitPathList
parameter_list|(
specifier|const
name|QString
modifier|&
name|val
parameter_list|)
specifier|const
block|{
name|QStringList
name|ret
decl_stmt|;
if|if
condition|(
operator|!
name|val
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDir
name|bdir
decl_stmt|;
name|QStringList
name|vals
init|=
name|val
operator|.
name|split
argument_list|(
name|dirlist_sep
argument_list|)
decl_stmt|;
name|ret
operator|.
name|reserve
argument_list|(
name|vals
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|it
decl|,
name|vals
control|)
name|ret
operator|<<
name|QDir
operator|::
name|cleanPath
argument_list|(
name|bdir
operator|.
name|absoluteFilePath
argument_list|(
name|it
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|getEnv
name|QString
name|QMakeGlobals
operator|::
name|getEnv
parameter_list|(
specifier|const
name|QString
modifier|&
name|var
parameter_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|PROEVALUATOR_SETENV
return|return
name|environment
operator|.
name|value
argument_list|(
name|var
argument_list|)
return|;
else|#
directive|else
return|return
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|qgetenv
argument_list|(
name|var
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|getPathListEnv
name|QStringList
name|QMakeGlobals
operator|::
name|getPathListEnv
parameter_list|(
specifier|const
name|QString
modifier|&
name|var
parameter_list|)
specifier|const
block|{
return|return
name|splitPathList
argument_list|(
name|getEnv
argument_list|(
name|var
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|expandEnvVars
name|QString
name|QMakeGlobals
operator|::
name|expandEnvVars
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
specifier|const
block|{
name|QString
name|string
init|=
name|str
decl_stmt|;
name|int
name|startIndex
init|=
literal|0
decl_stmt|;
forever|forever
block|{
name|startIndex
operator|=
name|string
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'$'
argument_list|)
argument_list|,
name|startIndex
argument_list|)
expr_stmt|;
if|if
condition|(
name|startIndex
operator|<
literal|0
condition|)
break|break;
if|if
condition|(
name|string
operator|.
name|length
argument_list|()
operator|<
name|startIndex
operator|+
literal|3
condition|)
break|break;
if|if
condition|(
name|string
operator|.
name|at
argument_list|(
name|startIndex
operator|+
literal|1
argument_list|)
operator|!=
name|QLatin1Char
argument_list|(
literal|'('
argument_list|)
condition|)
block|{
name|startIndex
operator|++
expr_stmt|;
continue|continue;
block|}
name|int
name|endIndex
init|=
name|string
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
argument_list|,
name|startIndex
operator|+
literal|2
argument_list|)
decl_stmt|;
if|if
condition|(
name|endIndex
operator|<
literal|0
condition|)
break|break;
name|QString
name|value
init|=
name|getEnv
argument_list|(
name|string
operator|.
name|mid
argument_list|(
name|startIndex
operator|+
literal|2
argument_list|,
name|endIndex
operator|-
name|startIndex
operator|-
literal|2
argument_list|)
argument_list|)
decl_stmt|;
name|string
operator|.
name|replace
argument_list|(
name|startIndex
argument_list|,
name|endIndex
operator|-
name|startIndex
operator|+
literal|1
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|startIndex
operator|+=
name|value
operator|.
name|length
argument_list|()
expr_stmt|;
block|}
return|return
name|string
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BUILD_QMAKE
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|PROEVALUATOR_INIT_PROPS
end_ifdef
begin_function
DECL|function|initProperties
name|bool
name|QMakeGlobals
operator|::
name|initProperties
parameter_list|()
block|{
name|QByteArray
name|data
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|QProcess
name|proc
decl_stmt|;
name|proc
operator|.
name|start
argument_list|(
name|qmake_abslocation
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"-query"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|proc
operator|.
name|waitForFinished
argument_list|()
condition|)
return|return
literal|false
return|;
name|data
operator|=
name|proc
operator|.
name|readAll
argument_list|()
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|FILE
modifier|*
name|proc
init|=
name|QT_POPEN
argument_list|(
name|QString
argument_list|(
name|QMakeInternal
operator|::
name|IoUtils
operator|::
name|shellQuote
argument_list|(
name|qmake_abslocation
argument_list|)
operator|+
name|QLatin1String
argument_list|(
literal|" -query"
argument_list|)
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
argument_list|,
literal|"r"
argument_list|)
condition|)
block|{
name|char
name|buff
index|[
literal|1024
index|]
decl_stmt|;
while|while
condition|(
operator|!
name|feof
argument_list|(
name|proc
argument_list|)
condition|)
name|data
operator|.
name|append
argument_list|(
name|buff
argument_list|,
name|int
argument_list|(
name|fread
argument_list|(
name|buff
argument_list|,
literal|1
argument_list|,
literal|1023
argument_list|,
name|proc
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QT_PCLOSE
argument_list|(
name|proc
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
foreach|foreach
control|(
name|QByteArray
name|line
decl|,
name|data
operator|.
name|split
argument_list|(
literal|'\n'
argument_list|)
control|)
block|{
name|int
name|off
init|=
name|line
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|)
decl_stmt|;
if|if
condition|(
name|off
operator|<
literal|0
condition|)
comment|// huh?
continue|continue;
if|if
condition|(
name|line
operator|.
name|endsWith
argument_list|(
literal|'\r'
argument_list|)
condition|)
name|line
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QString
name|name
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|line
operator|.
name|left
argument_list|(
name|off
argument_list|)
argument_list|)
decl_stmt|;
name|ProString
name|value
init|=
name|ProString
argument_list|(
name|QDir
operator|::
name|fromNativeSeparators
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|line
operator|.
name|mid
argument_list|(
name|off
operator|+
literal|1
argument_list|)
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|properties
operator|.
name|insert
argument_list|(
name|ProKey
argument_list|(
name|name
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
if|if
condition|(
name|name
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"QT_"
argument_list|)
argument_list|)
condition|)
block|{
name|bool
name|plain
init|=
operator|!
name|name
operator|.
name|contains
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|plain
condition|)
block|{
if|if
condition|(
operator|!
name|name
operator|.
name|endsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"/get"
argument_list|)
argument_list|)
condition|)
continue|continue;
name|name
operator|.
name|chop
argument_list|(
literal|4
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|name
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"QT_INSTALL_"
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
name|plain
condition|)
block|{
name|properties
operator|.
name|insert
argument_list|(
name|ProKey
argument_list|(
name|name
operator|+
name|QLatin1String
argument_list|(
literal|"/raw"
argument_list|)
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|properties
operator|.
name|insert
argument_list|(
name|ProKey
argument_list|(
name|name
operator|+
name|QLatin1String
argument_list|(
literal|"/get"
argument_list|)
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
name|properties
operator|.
name|insert
argument_list|(
name|ProKey
argument_list|(
name|name
operator|+
name|QLatin1String
argument_list|(
literal|"/src"
argument_list|)
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"QT_INSTALL_PREFIX"
argument_list|)
operator|||
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"QT_INSTALL_DATA"
argument_list|)
operator|||
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"QT_INSTALL_BINS"
argument_list|)
condition|)
block|{
name|name
operator|.
name|replace
argument_list|(
literal|3
argument_list|,
literal|7
argument_list|,
name|QLatin1String
argument_list|(
literal|"HOST"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|plain
condition|)
block|{
name|properties
operator|.
name|insert
argument_list|(
name|ProKey
argument_list|(
name|name
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|properties
operator|.
name|insert
argument_list|(
name|ProKey
argument_list|(
name|name
operator|+
name|QLatin1String
argument_list|(
literal|"/get"
argument_list|)
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
name|properties
operator|.
name|insert
argument_list|(
name|ProKey
argument_list|(
name|name
operator|+
name|QLatin1String
argument_list|(
literal|"/src"
argument_list|)
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|name
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"QT_HOST_"
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
name|plain
condition|)
name|properties
operator|.
name|insert
argument_list|(
name|ProKey
argument_list|(
name|name
operator|+
name|QLatin1String
argument_list|(
literal|"/get"
argument_list|)
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|properties
operator|.
name|insert
argument_list|(
name|ProKey
argument_list|(
name|name
operator|+
name|QLatin1String
argument_list|(
literal|"/src"
argument_list|)
argument_list|)
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
DECL|function|setProperties
name|void
name|QMakeGlobals
operator|::
name|setProperties
parameter_list|(
specifier|const
name|QHash
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
modifier|&
name|props
parameter_list|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
operator|::
name|ConstIterator
name|it
init|=
name|props
operator|.
name|constBegin
argument_list|()
decl_stmt|,
name|eit
init|=
name|props
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|eit
condition|;
operator|++
name|it
control|)
name|properties
operator|.
name|insert
argument_list|(
name|ProKey
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|)
argument_list|,
name|ProString
argument_list|(
name|it
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_BUILD_QMAKE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
