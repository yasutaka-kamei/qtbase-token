begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"meta.h"
end_include
begin_include
include|#
directive|include
file|"project.h"
end_include
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|cache_vars
name|QHash
argument_list|<
name|QString
argument_list|,
name|QHash
argument_list|<
name|QString
argument_list|,
name|QStringList
argument_list|>
argument_list|>
name|QMakeMetaInfo
operator|::
name|cache_vars
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QMakeMetaInfo
name|QMakeMetaInfo
operator|::
name|QMakeMetaInfo
parameter_list|(
name|QMakeProject
modifier|*
name|_conf
parameter_list|)
member_init_list|:
name|conf
argument_list|(
name|_conf
argument_list|)
block|{  }
end_constructor
begin_function
name|bool
DECL|function|readLib
name|QMakeMetaInfo
operator|::
name|readLib
parameter_list|(
name|QString
name|lib
parameter_list|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|QString
name|meta_file
init|=
name|findLib
argument_list|(
name|lib
argument_list|)
decl_stmt|;
if|if
condition|(
name|cache_vars
operator|.
name|contains
argument_list|(
name|meta_file
argument_list|)
condition|)
block|{
name|vars
operator|=
name|cache_vars
index|[
name|meta_file
index|]
expr_stmt|;
return|return
literal|true
return|;
block|}
name|bool
name|ret
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|meta_file
operator|.
name|isNull
argument_list|()
condition|)
block|{
if|if
condition|(
name|meta_file
operator|.
name|endsWith
argument_list|(
name|Option
operator|::
name|pkgcfg_ext
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|ret
operator|=
name|readPkgCfgFile
argument_list|(
name|meta_file
argument_list|)
operator|)
condition|)
name|meta_type
operator|=
literal|"pkgcfg"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|meta_file
operator|.
name|endsWith
argument_list|(
name|Option
operator|::
name|libtool_ext
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|ret
operator|=
name|readLibtoolFile
argument_list|(
name|meta_file
argument_list|)
operator|)
condition|)
name|meta_type
operator|=
literal|"libtool"
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|meta_file
operator|.
name|endsWith
argument_list|(
name|Option
operator|::
name|prl_ext
argument_list|)
condition|)
block|{
name|QMakeProject
name|proj
decl_stmt|;
if|if
condition|(
operator|!
name|proj
operator|.
name|read
argument_list|(
name|Option
operator|::
name|normalizePath
argument_list|(
name|meta_file
argument_list|)
argument_list|,
name|QMakeProject
operator|::
name|ReadProFile
argument_list|)
condition|)
return|return
literal|false
return|;
name|meta_type
operator|=
literal|"qmake"
expr_stmt|;
name|vars
operator|=
name|proj
operator|.
name|variables
argument_list|()
expr_stmt|;
name|ret
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|warn_msg
argument_list|(
name|WarnLogic
argument_list|,
literal|"QMakeMetaInfo: unknown file format for %s"
argument_list|,
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|meta_file
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|ret
condition|)
name|cache_vars
operator|.
name|insert
argument_list|(
name|meta_file
argument_list|,
name|vars
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
name|void
DECL|function|clear
name|QMakeMetaInfo
operator|::
name|clear
parameter_list|()
block|{
name|vars
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
name|QString
DECL|function|findLib
name|QMakeMetaInfo
operator|::
name|findLib
parameter_list|(
name|QString
name|lib
parameter_list|)
block|{
if|if
condition|(
operator|(
name|lib
index|[
literal|0
index|]
operator|==
literal|'\''
operator|||
name|lib
index|[
literal|0
index|]
operator|==
literal|'"'
operator|)
operator|&&
name|lib
index|[
name|lib
operator|.
name|length
argument_list|()
operator|-
literal|1
index|]
operator|==
name|lib
index|[
literal|0
index|]
condition|)
name|lib
operator|=
name|lib
operator|.
name|mid
argument_list|(
literal|1
argument_list|,
name|lib
operator|.
name|length
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
name|lib
operator|=
name|Option
operator|::
name|normalizePath
argument_list|(
name|lib
argument_list|)
expr_stmt|;
name|QString
name|ret
decl_stmt|;
name|QString
name|extns
index|[]
init|=
block|{
name|Option
operator|::
name|prl_ext
block|,
comment|/*Option::pkgcfg_ext, Option::libtool_ext,*/
name|QString
argument_list|()
block|}
decl_stmt|;
for|for
control|(
name|int
name|extn
init|=
literal|0
init|;
operator|!
name|extns
index|[
name|extn
index|]
operator|.
name|isNull
argument_list|()
condition|;
name|extn
operator|++
control|)
block|{
if|if
condition|(
name|lib
operator|.
name|endsWith
argument_list|(
name|extns
index|[
name|extn
index|]
argument_list|)
condition|)
name|ret
operator|=
name|QFile
operator|::
name|exists
argument_list|(
name|lib
argument_list|)
condition|?
name|lib
else|:
name|QString
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|ret
operator|.
name|isNull
argument_list|()
condition|)
block|{
for|for
control|(
name|int
name|extn
init|=
literal|0
init|;
operator|!
name|extns
index|[
name|extn
index|]
operator|.
name|isNull
argument_list|()
condition|;
name|extn
operator|++
control|)
block|{
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|lib
operator|+
name|extns
index|[
name|extn
index|]
argument_list|)
condition|)
block|{
name|ret
operator|=
name|lib
operator|+
name|extns
index|[
name|extn
index|]
expr_stmt|;
break|break;
block|}
block|}
block|}
if|if
condition|(
name|ret
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|debug_msg
argument_list|(
literal|2
argument_list|,
literal|"QMakeMetaInfo: Cannot find info file for %s"
argument_list|,
name|lib
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|debug_msg
argument_list|(
literal|2
argument_list|,
literal|"QMakeMetaInfo: Found info file %s for %s"
argument_list|,
name|ret
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|lib
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
name|bool
DECL|function|readLibtoolFile
name|QMakeMetaInfo
operator|::
name|readLibtoolFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|f
parameter_list|)
block|{
comment|/* I can just run the .la through the .pro parser since they are compatible.. */
name|QMakeProject
name|proj
decl_stmt|;
name|QString
name|nf
init|=
name|Option
operator|::
name|normalizePath
argument_list|(
name|f
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|proj
operator|.
name|read
argument_list|(
name|nf
argument_list|,
name|QMakeProject
operator|::
name|ReadProFile
argument_list|)
condition|)
return|return
literal|false
return|;
name|QString
name|dirf
init|=
name|nf
operator|.
name|section
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|,
literal|0
argument_list|,
operator|-
literal|2
argument_list|)
decl_stmt|;
if|if
condition|(
name|dirf
operator|==
name|nf
condition|)
name|dirf
operator|=
literal|""
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|dirf
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|dirf
operator|.
name|endsWith
argument_list|(
name|Option
operator|::
name|output_dir
argument_list|)
condition|)
name|dirf
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
specifier|const
name|QHash
argument_list|<
name|QString
argument_list|,
name|QStringList
argument_list|>
modifier|&
name|v
init|=
name|proj
operator|.
name|variables
argument_list|()
decl_stmt|;
for|for
control|(
name|QHash
argument_list|<
name|QString
argument_list|,
name|QStringList
argument_list|>
operator|::
name|ConstIterator
name|it
init|=
name|v
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|v
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
name|QStringList
name|lst
init|=
name|it
operator|.
name|value
argument_list|()
decl_stmt|;
if|if
condition|(
name|lst
operator|.
name|count
argument_list|()
operator|==
literal|1
operator|&&
operator|(
name|lst
operator|.
name|first
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"'"
argument_list|)
operator|||
name|lst
operator|.
name|first
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|"\""
argument_list|)
operator|)
operator|&&
name|lst
operator|.
name|first
argument_list|()
operator|.
name|endsWith
argument_list|(
name|QString
argument_list|(
name|lst
operator|.
name|first
argument_list|()
index|[
literal|0
index|]
argument_list|)
argument_list|)
condition|)
name|lst
operator|=
name|QStringList
argument_list|(
name|lst
operator|.
name|first
argument_list|()
operator|.
name|mid
argument_list|(
literal|1
argument_list|,
name|lst
operator|.
name|first
argument_list|()
operator|.
name|length
argument_list|()
operator|-
literal|2
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|vars
operator|.
name|contains
argument_list|(
literal|"QMAKE_PRL_TARGET"
argument_list|)
operator|&&
operator|(
name|it
operator|.
name|key
argument_list|()
operator|==
literal|"dlname"
operator|||
name|it
operator|.
name|key
argument_list|()
operator|==
literal|"library_names"
operator|||
name|it
operator|.
name|key
argument_list|()
operator|==
literal|"old_library"
operator|)
condition|)
block|{
name|QString
name|dir
init|=
name|v
index|[
literal|"libdir"
index|]
operator|.
name|first
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|dir
operator|.
name|startsWith
argument_list|(
literal|"'"
argument_list|)
operator|||
name|dir
operator|.
name|startsWith
argument_list|(
literal|"\""
argument_list|)
operator|)
operator|&&
name|dir
operator|.
name|endsWith
argument_list|(
name|QString
argument_list|(
name|dir
index|[
literal|0
index|]
argument_list|)
argument_list|)
condition|)
name|dir
operator|=
name|dir
operator|.
name|mid
argument_list|(
literal|1
argument_list|,
name|dir
operator|.
name|length
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
name|dir
operator|=
name|dir
operator|.
name|trimmed
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|dir
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|dir
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|dir
operator|+=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
name|lst
operator|.
name|count
argument_list|()
operator|==
literal|1
condition|)
name|lst
operator|=
name|lst
operator|.
name|first
argument_list|()
operator|.
name|split
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
for|for
control|(
name|QStringList
operator|::
name|Iterator
name|lst_it
init|=
name|lst
operator|.
name|begin
argument_list|()
init|;
name|lst_it
operator|!=
name|lst
operator|.
name|end
argument_list|()
condition|;
operator|++
name|lst_it
control|)
block|{
name|bool
name|found
init|=
literal|false
decl_stmt|;
name|QString
name|dirs
index|[]
init|=
block|{
literal|""
block|,
name|dir
block|,
name|dirf
block|,
name|dirf
operator|+
literal|".libs/"
block|,
literal|"(term)"
block|}
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
operator|!
name|found
operator|&&
name|dirs
index|[
name|i
index|]
operator|!=
literal|"(term)"
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|dirs
index|[
name|i
index|]
operator|+
operator|(
operator|*
name|lst_it
operator|)
argument_list|)
condition|)
block|{
name|QString
name|targ
init|=
name|dirs
index|[
name|i
index|]
operator|+
operator|(
operator|*
name|lst_it
operator|)
decl_stmt|;
if|if
condition|(
name|QDir
operator|::
name|isRelativePath
argument_list|(
name|targ
argument_list|)
condition|)
name|targ
operator|.
name|prepend
argument_list|(
name|qmake_getpwd
argument_list|()
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
expr_stmt|;
name|vars
index|[
literal|"QMAKE_PRL_TARGET"
index|]
operator|<<
name|targ
expr_stmt|;
name|found
operator|=
literal|true
expr_stmt|;
block|}
block|}
if|if
condition|(
name|found
condition|)
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|it
operator|.
name|key
argument_list|()
operator|==
literal|"dependency_libs"
condition|)
block|{
if|if
condition|(
name|lst
operator|.
name|count
argument_list|()
operator|==
literal|1
condition|)
block|{
name|QString
name|dep
init|=
name|lst
operator|.
name|first
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|dep
operator|.
name|startsWith
argument_list|(
literal|'\''
argument_list|)
operator|||
name|dep
operator|.
name|startsWith
argument_list|(
literal|'"'
argument_list|)
operator|)
operator|&&
name|dep
operator|.
name|endsWith
argument_list|(
name|dep
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
condition|)
name|dep
operator|=
name|dep
operator|.
name|mid
argument_list|(
literal|1
argument_list|,
name|dep
operator|.
name|length
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
name|lst
operator|=
name|dep
operator|.
name|trimmed
argument_list|()
operator|.
name|split
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|QStringList
operator|::
name|Iterator
name|lit
init|=
name|lst
operator|.
name|begin
argument_list|()
init|;
name|lit
operator|!=
name|lst
operator|.
name|end
argument_list|()
condition|;
operator|++
name|lit
control|)
block|{
if|if
condition|(
operator|(
operator|*
name|lit
operator|)
operator|.
name|startsWith
argument_list|(
literal|"-R"
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|conf
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_LFLAGS_RPATH"
argument_list|)
condition|)
operator|(
operator|*
name|lit
operator|)
operator|=
name|conf
operator|->
name|first
argument_list|(
literal|"QMAKE_LFLAGS_RPATH"
argument_list|)
operator|+
operator|(
operator|*
name|lit
operator|)
operator|.
name|mid
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
name|vars
index|[
literal|"QMAKE_PRL_LIBS"
index|]
operator|+=
name|lst
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
name|bool
DECL|function|readPkgCfgFile
name|QMakeMetaInfo
operator|::
name|readPkgCfgFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|f
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Must implement reading in pkg-config files (%s)!!!\n"
argument_list|,
name|f
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
