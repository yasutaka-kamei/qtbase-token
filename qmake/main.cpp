begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"project.h"
end_include
begin_include
include|#
directive|include
file|"property.h"
end_include
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|"cachekeys.h"
end_include
begin_include
include|#
directive|include
file|"metamakefile.h"
end_include
begin_include
include|#
directive|include
file|<qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
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
begin_include
include|#
directive|include
file|<ctype.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/* This is to work around lame implementation on Darwin. It has been noted that the getpwd(3) function    is much too slow, and called much too often inside of Qt (every fileFixify). With this we use a locally    cached copy because I can control all the times it is set (because Qt never sets the pwd under me). */
DECL|variable|pwd
specifier|static
name|QString
name|pwd
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qmake_getpwd
name|QString
name|qmake_getpwd
parameter_list|()
block|{
if|if
condition|(
name|pwd
operator|.
name|isNull
argument_list|()
condition|)
name|pwd
operator|=
name|QDir
operator|::
name|currentPath
argument_list|()
expr_stmt|;
return|return
name|pwd
return|;
block|}
end_function
begin_function
DECL|function|qmake_setpwd
name|bool
name|qmake_setpwd
parameter_list|(
specifier|const
name|QString
modifier|&
name|p
parameter_list|)
block|{
if|if
condition|(
name|QDir
operator|::
name|setCurrent
argument_list|(
name|p
argument_list|)
condition|)
block|{
name|pwd
operator|=
name|QDir
operator|::
name|currentPath
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|runQMake
name|int
name|runQMake
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
comment|// stderr is unbuffered by default, but stdout buffering depends on whether
comment|// there is a terminal attached. Buffering can make output from stderr and stdout
comment|// appear out of sync, so force stdout to be unbuffered as well.
comment|// This is particularly important for things like QtCreator and scripted builds.
name|setvbuf
argument_list|(
name|stdout
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
name|_IONBF
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QMakeGlobals
name|globals
decl_stmt|;
name|Option
operator|::
name|globals
operator|=
operator|&
name|globals
expr_stmt|;
comment|// parse command line
name|int
name|ret
init|=
name|Option
operator|::
name|init
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|!=
name|Option
operator|::
name|QMAKE_CMDLINE_SUCCESS
condition|)
block|{
if|if
condition|(
operator|(
name|ret
operator|&
name|Option
operator|::
name|QMAKE_CMDLINE_ERROR
operator|)
operator|!=
literal|0
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
name|QString
name|oldpwd
init|=
name|qmake_getpwd
argument_list|()
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
operator|!
operator|(
name|oldpwd
operator|.
name|length
argument_list|()
operator|==
literal|3
operator|&&
name|oldpwd
index|[
literal|0
index|]
operator|.
name|isLetter
argument_list|()
operator|&&
name|oldpwd
operator|.
name|endsWith
argument_list|(
literal|":/"
argument_list|)
operator|)
condition|)
endif|#
directive|endif
block|{
if|if
condition|(
operator|!
name|oldpwd
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|oldpwd
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
block|}
name|Option
operator|::
name|output_dir
operator|=
name|oldpwd
expr_stmt|;
comment|//for now this is the output dir
if|if
condition|(
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
operator|!=
literal|"-"
condition|)
block|{
name|QFileInfo
name|fi
argument_list|(
name|Option
operator|::
name|output
argument_list|)
decl_stmt|;
name|QString
name|dir
decl_stmt|;
if|if
condition|(
name|fi
operator|.
name|isDir
argument_list|()
condition|)
block|{
name|dir
operator|=
name|fi
operator|.
name|filePath
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QString
name|tmp_dir
init|=
name|fi
operator|.
name|path
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|tmp_dir
operator|.
name|isEmpty
argument_list|()
operator|&&
name|QFile
operator|::
name|exists
argument_list|(
name|tmp_dir
argument_list|)
condition|)
name|dir
operator|=
name|tmp_dir
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|Q_OS_MAC
if|if
condition|(
name|fi
operator|.
name|fileName
argument_list|()
operator|.
name|endsWith
argument_list|(
name|QStringLiteral
argument_list|(
literal|".pbxproj"
argument_list|)
argument_list|)
operator|&&
name|dir
operator|.
name|endsWith
argument_list|(
name|QStringLiteral
argument_list|(
literal|".xcodeproj"
argument_list|)
argument_list|)
condition|)
name|dir
operator|+=
name|QStringLiteral
argument_list|(
literal|"/.."
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|dir
operator|.
name|isNull
argument_list|()
operator|&&
name|dir
operator|!=
literal|"."
condition|)
name|Option
operator|::
name|output_dir
operator|=
name|dir
expr_stmt|;
if|if
condition|(
name|QDir
operator|::
name|isRelativePath
argument_list|(
name|Option
operator|::
name|output_dir
argument_list|)
condition|)
name|Option
operator|::
name|output_dir
operator|.
name|prepend
argument_list|(
name|oldpwd
argument_list|)
expr_stmt|;
name|Option
operator|::
name|output_dir
operator|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|Option
operator|::
name|output_dir
argument_list|)
expr_stmt|;
block|}
name|QMakeProperty
name|prop
decl_stmt|;
if|if
condition|(
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_QUERY_PROPERTY
operator|||
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_SET_PROPERTY
operator|||
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_UNSET_PROPERTY
condition|)
return|return
name|prop
operator|.
name|exec
argument_list|()
condition|?
literal|0
else|:
literal|101
return|;
name|globals
operator|.
name|setQMakeProperty
argument_list|(
operator|&
name|prop
argument_list|)
expr_stmt|;
name|ProFileCache
name|proFileCache
decl_stmt|;
name|Option
operator|::
name|proFileCache
operator|=
operator|&
name|proFileCache
expr_stmt|;
name|QMakeParser
name|parser
argument_list|(
operator|&
name|proFileCache
argument_list|,
operator|&
name|Option
operator|::
name|evalHandler
argument_list|)
decl_stmt|;
name|Option
operator|::
name|parser
operator|=
operator|&
name|parser
expr_stmt|;
name|QMakeProject
name|project
decl_stmt|;
name|int
name|exit_val
init|=
literal|0
decl_stmt|;
name|QStringList
name|files
decl_stmt|;
if|if
condition|(
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_GENERATE_PROJECT
condition|)
name|files
operator|<<
literal|"(*hack*)"
expr_stmt|;
comment|//we don't even use files, but we do the for() body once
else|else
name|files
operator|=
name|Option
operator|::
name|mkfile
operator|::
name|project_files
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|Iterator
name|pfile
init|=
name|files
operator|.
name|begin
argument_list|()
init|;
name|pfile
operator|!=
name|files
operator|.
name|end
argument_list|()
condition|;
name|pfile
operator|++
control|)
block|{
if|if
condition|(
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_GENERATE_MAKEFILE
operator|||
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_GENERATE_PRL
condition|)
block|{
name|QString
name|fn
init|=
name|Option
operator|::
name|normalizePath
argument_list|(
operator|*
name|pfile
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|fn
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot find file: %s.\n"
argument_list|,
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fn
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|exit_val
operator|=
literal|2
expr_stmt|;
continue|continue;
block|}
comment|//setup pwd properly
name|debug_msg
argument_list|(
literal|1
argument_list|,
literal|"Resetting dir to: %s"
argument_list|,
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|oldpwd
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|qmake_setpwd
argument_list|(
name|oldpwd
argument_list|)
expr_stmt|;
comment|//reset the old pwd
name|int
name|di
init|=
name|fn
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|di
operator|!=
operator|-
literal|1
condition|)
block|{
name|debug_msg
argument_list|(
literal|1
argument_list|,
literal|"Changing dir to: %s"
argument_list|,
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fn
operator|.
name|left
argument_list|(
name|di
argument_list|)
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|qmake_setpwd
argument_list|(
name|fn
operator|.
name|left
argument_list|(
name|di
argument_list|)
argument_list|)
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot find directory: %s\n"
argument_list|,
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|fn
operator|.
name|left
argument_list|(
name|di
argument_list|)
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|fn
operator|=
name|fn
operator|.
name|right
argument_list|(
name|fn
operator|.
name|length
argument_list|()
operator|-
name|di
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|Option
operator|::
name|prepareProject
argument_list|(
name|fn
argument_list|)
expr_stmt|;
comment|// read project..
if|if
condition|(
operator|!
name|project
operator|.
name|read
argument_list|(
name|fn
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error processing project file: %s\n"
argument_list|,
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
operator|*
name|pfile
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|exit_val
operator|=
literal|3
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|Option
operator|::
name|mkfile
operator|::
name|do_preprocess
condition|)
block|{
name|project
operator|.
name|dump
argument_list|()
expr_stmt|;
continue|continue;
comment|//no need to create makefile
block|}
block|}
name|bool
name|success
init|=
literal|true
decl_stmt|;
name|MetaMakefileGenerator
modifier|*
name|mkfile
init|=
name|MetaMakefileGenerator
operator|::
name|createMetaGenerator
argument_list|(
operator|&
name|project
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|false
argument_list|,
operator|&
name|success
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|success
condition|)
name|exit_val
operator|=
literal|3
expr_stmt|;
if|if
condition|(
name|mkfile
operator|&&
operator|!
name|mkfile
operator|->
name|write
argument_list|()
condition|)
block|{
if|if
condition|(
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_GENERATE_PROJECT
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Unable to generate project file.\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Unable to generate makefile for: %s\n"
argument_list|,
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
operator|*
name|pfile
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|exit_val
operator|=
literal|5
expr_stmt|;
block|}
operator|delete
name|mkfile
expr_stmt|;
name|mkfile
operator|=
name|NULL
expr_stmt|;
block|}
name|qmakeClearCaches
argument_list|()
expr_stmt|;
return|return
name|exit_val
return|;
block|}
end_function
begin_function
name|QT_END_NAMESPACE
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
return|return
name|QT_PREPEND_NAMESPACE
argument_list|(
name|runQMake
argument_list|)
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
return|;
block|}
end_function
end_unit
