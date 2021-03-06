begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"metamakefile.h"
end_include
begin_include
include|#
directive|include
file|"qregexp.h"
end_include
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"makefile.h"
end_include
begin_include
include|#
directive|include
file|"project.h"
end_include
begin_include
include|#
directive|include
file|"cachekeys.h"
end_include
begin_define
DECL|macro|BUILDSMETATYPE
define|#
directive|define
name|BUILDSMETATYPE
value|1
end_define
begin_define
DECL|macro|SUBDIRSMETATYPE
define|#
directive|define
name|SUBDIRSMETATYPE
value|2
end_define
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|function|~MetaMakefileGenerator
name|MetaMakefileGenerator
operator|::
name|~
name|MetaMakefileGenerator
operator|(
operator|)
block|{
if|if
condition|(
name|own_project
condition|)
operator|delete
name|project
expr_stmt|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_QMAKE_PARSER_ONLY
end_ifndef
begin_class
DECL|class|BuildsMetaMakefileGenerator
class|class
name|BuildsMetaMakefileGenerator
super|:
specifier|public
name|MetaMakefileGenerator
block|{
private|private:
DECL|member|init_flag
name|bool
name|init_flag
decl_stmt|;
DECL|struct|Build
struct|struct
name|Build
block|{
DECL|member|name
DECL|member|build
name|QString
name|name
decl_stmt|,
name|build
decl_stmt|;
DECL|member|makefile
name|MakefileGenerator
modifier|*
name|makefile
decl_stmt|;
block|}
struct|;
DECL|member|makefiles
name|QList
argument_list|<
name|Build
modifier|*
argument_list|>
name|makefiles
decl_stmt|;
name|void
name|clearBuilds
parameter_list|()
function_decl|;
name|MakefileGenerator
modifier|*
name|processBuild
parameter_list|(
specifier|const
name|ProString
modifier|&
parameter_list|)
function_decl|;
public|public:
DECL|function|BuildsMetaMakefileGenerator
name|BuildsMetaMakefileGenerator
parameter_list|(
name|QMakeProject
modifier|*
name|p
parameter_list|,
specifier|const
name|QString
modifier|&
name|n
parameter_list|,
name|bool
name|op
parameter_list|)
member_init_list|:
name|MetaMakefileGenerator
argument_list|(
name|p
argument_list|,
name|n
argument_list|,
name|op
argument_list|)
member_init_list|,
name|init_flag
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|~BuildsMetaMakefileGenerator
specifier|virtual
name|~
name|BuildsMetaMakefileGenerator
parameter_list|()
block|{
name|clearBuilds
argument_list|()
expr_stmt|;
block|}
specifier|virtual
name|bool
name|init
parameter_list|()
function_decl|;
DECL|function|type
specifier|virtual
name|int
name|type
parameter_list|()
specifier|const
block|{
return|return
name|BUILDSMETATYPE
return|;
block|}
specifier|virtual
name|bool
name|write
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
name|void
DECL|function|clearBuilds
name|BuildsMetaMakefileGenerator
operator|::
name|clearBuilds
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|makefiles
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|Build
modifier|*
name|build
init|=
name|makefiles
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|QMakeProject
modifier|*
name|p
init|=
name|build
operator|->
name|makefile
operator|->
name|projectFile
argument_list|()
condition|)
block|{
if|if
condition|(
name|p
operator|!=
name|project
condition|)
operator|delete
name|p
expr_stmt|;
block|}
operator|delete
name|build
operator|->
name|makefile
expr_stmt|;
operator|delete
name|build
expr_stmt|;
block|}
name|makefiles
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
name|bool
DECL|function|init
name|BuildsMetaMakefileGenerator
operator|::
name|init
parameter_list|()
block|{
if|if
condition|(
name|init_flag
condition|)
return|return
literal|false
return|;
name|init_flag
operator|=
literal|true
expr_stmt|;
specifier|const
name|ProStringList
modifier|&
name|builds
init|=
name|project
operator|->
name|values
argument_list|(
literal|"BUILDS"
argument_list|)
decl_stmt|;
name|bool
name|use_single_build
init|=
name|builds
operator|.
name|isEmpty
argument_list|()
decl_stmt|;
if|if
condition|(
name|builds
operator|.
name|count
argument_list|()
operator|>
literal|1
operator|&&
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
operator|==
literal|"-"
condition|)
block|{
name|use_single_build
operator|=
literal|true
expr_stmt|;
name|warn_msg
argument_list|(
name|WarnLogic
argument_list|,
literal|"Cannot direct to stdout when using multiple BUILDS."
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
literal|0
operator|&&
operator|!
name|use_single_build
operator|&&
name|project
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|==
literal|"subdirs"
condition|)
block|{
name|use_single_build
operator|=
literal|true
expr_stmt|;
name|warn_msg
argument_list|(
name|WarnLogic
argument_list|,
literal|"Cannot specify multiple builds with TEMPLATE subdirs."
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|use_single_build
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|builds
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|ProString
name|build
init|=
name|builds
index|[
name|i
index|]
decl_stmt|;
name|MakefileGenerator
modifier|*
name|makefile
init|=
name|processBuild
argument_list|(
name|build
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|makefile
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|makefile
operator|->
name|supportsMetaBuild
argument_list|()
condition|)
block|{
name|warn_msg
argument_list|(
name|WarnLogic
argument_list|,
literal|"QMAKESPEC does not support multiple BUILDS."
argument_list|)
expr_stmt|;
name|clearBuilds
argument_list|()
expr_stmt|;
name|use_single_build
operator|=
literal|true
expr_stmt|;
break|break;
block|}
else|else
block|{
name|Build
modifier|*
name|b
init|=
operator|new
name|Build
decl_stmt|;
name|b
operator|->
name|name
operator|=
name|name
expr_stmt|;
if|if
condition|(
name|builds
operator|.
name|count
argument_list|()
operator|!=
literal|1
condition|)
name|b
operator|->
name|build
operator|=
name|build
operator|.
name|toQString
argument_list|()
expr_stmt|;
name|b
operator|->
name|makefile
operator|=
name|makefile
expr_stmt|;
name|makefiles
operator|+=
name|b
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|use_single_build
condition|)
block|{
name|Build
modifier|*
name|build
init|=
operator|new
name|Build
decl_stmt|;
name|build
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|build
operator|->
name|makefile
operator|=
name|createMakefileGenerator
argument_list|(
name|project
argument_list|,
literal|false
argument_list|)
expr_stmt|;
if|if
condition|(
name|build
operator|->
name|makefile
condition|)
block|{
name|makefiles
operator|+=
name|build
expr_stmt|;
block|}
else|else
block|{
operator|delete
name|build
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
name|bool
DECL|function|write
name|BuildsMetaMakefileGenerator
operator|::
name|write
parameter_list|()
block|{
name|Build
modifier|*
name|glue
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|makefiles
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|makefiles
operator|.
name|first
argument_list|()
operator|->
name|build
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|glue
operator|=
operator|new
name|Build
expr_stmt|;
name|glue
operator|->
name|name
operator|=
name|name
expr_stmt|;
name|glue
operator|->
name|makefile
operator|=
name|createMakefileGenerator
argument_list|(
name|project
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|makefiles
operator|+=
name|glue
expr_stmt|;
block|}
name|bool
name|ret
init|=
literal|true
decl_stmt|;
specifier|const
name|QString
modifier|&
name|output_name
init|=
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|ret
operator|&&
name|i
operator|<
name|makefiles
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|Option
operator|::
name|output
operator|.
name|setFileName
argument_list|(
name|output_name
argument_list|)
expr_stmt|;
name|Build
modifier|*
name|build
init|=
name|makefiles
index|[
name|i
index|]
decl_stmt|;
name|bool
name|using_stdout
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|build
operator|->
name|makefile
operator|&&
operator|(
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
name|QMAKE_GENERATE_PROJECT
operator|)
operator|&&
operator|(
operator|!
name|build
operator|->
name|makefile
operator|->
name|supportsMergedBuilds
argument_list|()
operator|||
operator|(
name|build
operator|->
name|makefile
operator|->
name|supportsMergedBuilds
argument_list|()
operator|&&
operator|(
operator|!
name|glue
operator|||
name|build
operator|==
name|glue
operator|)
operator|)
operator|)
condition|)
block|{
comment|//open output
if|if
condition|(
operator|!
operator|(
name|Option
operator|::
name|output
operator|.
name|isOpen
argument_list|()
operator|)
condition|)
block|{
if|if
condition|(
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
operator|==
literal|"-"
condition|)
block|{
name|Option
operator|::
name|output
operator|.
name|setFileName
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|Option
operator|::
name|output_dir
operator|=
name|qmake_getpwd
argument_list|()
expr_stmt|;
name|Option
operator|::
name|output
operator|.
name|open
argument_list|(
name|stdout
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
expr_stmt|;
name|using_stdout
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
operator|.
name|isEmpty
argument_list|()
operator|&&
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_GENERATE_MAKEFILE
condition|)
name|Option
operator|::
name|output
operator|.
name|setFileName
argument_list|(
name|project
operator|->
name|first
argument_list|(
literal|"QMAKE_MAKEFILE"
argument_list|)
operator|.
name|toQString
argument_list|()
argument_list|)
expr_stmt|;
name|QString
name|build_name
init|=
name|build
operator|->
name|name
decl_stmt|;
if|if
condition|(
operator|!
name|build
operator|->
name|build
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|build_name
operator|.
name|isEmpty
argument_list|()
condition|)
name|build_name
operator|+=
literal|"."
expr_stmt|;
name|build_name
operator|+=
name|build
operator|->
name|build
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|build
operator|->
name|makefile
operator|->
name|openOutput
argument_list|(
name|Option
operator|::
name|output
argument_list|,
name|build_name
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Failure to open file: %s\n"
argument_list|,
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|?
literal|"(stdout)"
else|:
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
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
block|}
block|}
block|}
else|else
block|{
name|using_stdout
operator|=
literal|true
expr_stmt|;
comment|//kind of..
block|}
if|if
condition|(
operator|!
name|build
operator|->
name|makefile
condition|)
block|{
name|ret
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|build
operator|==
name|glue
condition|)
block|{
name|ret
operator|=
name|build
operator|->
name|makefile
operator|->
name|writeProjectMakefile
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|ret
operator|=
name|build
operator|->
name|makefile
operator|->
name|write
argument_list|()
expr_stmt|;
if|if
condition|(
name|glue
operator|&&
name|glue
operator|->
name|makefile
operator|->
name|supportsMergedBuilds
argument_list|()
condition|)
name|ret
operator|=
name|glue
operator|->
name|makefile
operator|->
name|mergeBuildProject
argument_list|(
name|build
operator|->
name|makefile
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|using_stdout
condition|)
block|{
name|Option
operator|::
name|output
operator|.
name|close
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|ret
condition|)
name|Option
operator|::
name|output
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
name|MakefileGenerator
DECL|function|processBuild
modifier|*
name|BuildsMetaMakefileGenerator
operator|::
name|processBuild
parameter_list|(
specifier|const
name|ProString
modifier|&
name|build
parameter_list|)
block|{
if|if
condition|(
name|project
condition|)
block|{
name|debug_msg
argument_list|(
literal|1
argument_list|,
literal|"Meta Generator: Parsing '%s' for build [%s]."
argument_list|,
name|project
operator|->
name|projectFile
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|build
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
comment|//initialize the base
name|ProValueMap
name|basevars
decl_stmt|;
name|ProStringList
name|basecfgs
init|=
name|project
operator|->
name|values
argument_list|(
name|ProKey
argument_list|(
name|build
operator|+
literal|".CONFIG"
argument_list|)
argument_list|)
decl_stmt|;
name|basecfgs
operator|+=
name|build
expr_stmt|;
name|basecfgs
operator|+=
literal|"build_pass"
expr_stmt|;
name|basevars
index|[
literal|"BUILD_PASS"
index|]
operator|=
name|ProStringList
argument_list|(
name|build
argument_list|)
expr_stmt|;
name|ProStringList
name|buildname
init|=
name|project
operator|->
name|values
argument_list|(
name|ProKey
argument_list|(
name|build
operator|+
literal|".name"
argument_list|)
argument_list|)
decl_stmt|;
name|basevars
index|[
literal|"BUILD_NAME"
index|]
operator|=
operator|(
name|buildname
operator|.
name|isEmpty
argument_list|()
condition|?
name|ProStringList
argument_list|(
name|build
argument_list|)
else|:
name|buildname
operator|)
expr_stmt|;
comment|//create project
name|QMakeProject
modifier|*
name|build_proj
init|=
operator|new
name|QMakeProject
decl_stmt|;
name|build_proj
operator|->
name|setExtraVars
argument_list|(
name|basevars
argument_list|)
expr_stmt|;
name|build_proj
operator|->
name|setExtraConfigs
argument_list|(
name|basecfgs
argument_list|)
expr_stmt|;
if|if
condition|(
name|build_proj
operator|->
name|read
argument_list|(
name|project
operator|->
name|projectFile
argument_list|()
argument_list|)
condition|)
return|return
name|createMakefileGenerator
argument_list|(
name|build_proj
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_class
DECL|class|SubdirsMetaMakefileGenerator
class|class
name|SubdirsMetaMakefileGenerator
super|:
specifier|public
name|MetaMakefileGenerator
block|{
protected|protected:
DECL|member|init_flag
name|bool
name|init_flag
decl_stmt|;
DECL|struct|Subdir
struct|struct
name|Subdir
block|{
DECL|function|Subdir
name|Subdir
parameter_list|()
member_init_list|:
name|makefile
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|indent
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|function|~Subdir
name|~
name|Subdir
parameter_list|()
block|{
operator|delete
name|makefile
expr_stmt|;
block|}
DECL|member|input_dir
name|QString
name|input_dir
decl_stmt|;
DECL|member|output_dir
DECL|member|output_file
name|QString
name|output_dir
decl_stmt|,
name|output_file
decl_stmt|;
DECL|member|makefile
name|MetaMakefileGenerator
modifier|*
name|makefile
decl_stmt|;
DECL|member|indent
name|int
name|indent
decl_stmt|;
block|}
struct|;
DECL|member|subs
name|QList
argument_list|<
name|Subdir
modifier|*
argument_list|>
name|subs
decl_stmt|;
name|MakefileGenerator
modifier|*
name|processBuild
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
public|public:
DECL|function|SubdirsMetaMakefileGenerator
name|SubdirsMetaMakefileGenerator
parameter_list|(
name|QMakeProject
modifier|*
name|p
parameter_list|,
specifier|const
name|QString
modifier|&
name|n
parameter_list|,
name|bool
name|op
parameter_list|)
member_init_list|:
name|MetaMakefileGenerator
argument_list|(
name|p
argument_list|,
name|n
argument_list|,
name|op
argument_list|)
member_init_list|,
name|init_flag
argument_list|(
literal|false
argument_list|)
block|{ }
specifier|virtual
name|~
name|SubdirsMetaMakefileGenerator
parameter_list|()
destructor_decl|;
specifier|virtual
name|bool
name|init
parameter_list|()
function_decl|;
DECL|function|type
specifier|virtual
name|int
name|type
parameter_list|()
specifier|const
block|{
return|return
name|SUBDIRSMETATYPE
return|;
block|}
specifier|virtual
name|bool
name|write
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
name|bool
DECL|function|init
name|SubdirsMetaMakefileGenerator
operator|::
name|init
parameter_list|()
block|{
if|if
condition|(
name|init_flag
condition|)
return|return
literal|false
return|;
name|init_flag
operator|=
literal|true
expr_stmt|;
name|bool
name|hasError
init|=
literal|false
decl_stmt|;
name|bool
name|recurse
init|=
name|Option
operator|::
name|recursive
decl_stmt|;
if|if
condition|(
name|recurse
operator|&&
name|project
operator|->
name|isActiveConfig
argument_list|(
literal|"dont_recurse"
argument_list|)
condition|)
name|recurse
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|recurse
condition|)
block|{
name|QString
name|old_output_dir
init|=
name|Option
operator|::
name|output_dir
decl_stmt|;
name|QString
name|old_output
init|=
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
decl_stmt|;
name|QString
name|oldpwd
init|=
name|qmake_getpwd
argument_list|()
decl_stmt|;
name|QString
name|thispwd
init|=
name|oldpwd
decl_stmt|;
if|if
condition|(
operator|!
name|thispwd
operator|.
name|endsWith
argument_list|(
literal|'/'
argument_list|)
condition|)
name|thispwd
operator|+=
literal|'/'
expr_stmt|;
specifier|const
name|ProStringList
modifier|&
name|subdirs
init|=
name|project
operator|->
name|values
argument_list|(
literal|"SUBDIRS"
argument_list|)
decl_stmt|;
specifier|static
name|int
name|recurseDepth
init|=
operator|-
literal|1
decl_stmt|;
operator|++
name|recurseDepth
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|subdirs
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|Subdir
modifier|*
name|sub
init|=
operator|new
name|Subdir
decl_stmt|;
name|sub
operator|->
name|indent
operator|=
name|recurseDepth
expr_stmt|;
name|QFileInfo
name|subdir
argument_list|(
name|subdirs
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toQString
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|ProKey
name|fkey
argument_list|(
name|subdirs
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|+
literal|".file"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|isEmpty
argument_list|(
name|fkey
argument_list|)
condition|)
block|{
name|subdir
operator|=
name|project
operator|->
name|first
argument_list|(
name|fkey
argument_list|)
operator|.
name|toQString
argument_list|()
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|ProKey
name|skey
argument_list|(
name|subdirs
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|+
literal|".subdir"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|project
operator|->
name|isEmpty
argument_list|(
name|skey
argument_list|)
condition|)
name|subdir
operator|=
name|project
operator|->
name|first
argument_list|(
name|skey
argument_list|)
operator|.
name|toQString
argument_list|()
expr_stmt|;
block|}
name|QString
name|sub_name
decl_stmt|;
if|if
condition|(
name|subdir
operator|.
name|isDir
argument_list|()
condition|)
name|subdir
operator|=
name|QFileInfo
argument_list|(
name|subdir
operator|.
name|filePath
argument_list|()
operator|+
literal|"/"
operator|+
name|subdir
operator|.
name|fileName
argument_list|()
operator|+
name|Option
operator|::
name|pro_ext
argument_list|)
expr_stmt|;
else|else
name|sub_name
operator|=
name|subdir
operator|.
name|baseName
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|subdir
operator|.
name|isRelative
argument_list|()
condition|)
block|{
comment|//we can try to make it relative
name|QString
name|subdir_path
init|=
name|subdir
operator|.
name|filePath
argument_list|()
decl_stmt|;
if|if
condition|(
name|subdir_path
operator|.
name|startsWith
argument_list|(
name|thispwd
argument_list|)
condition|)
name|subdir
operator|=
name|QFileInfo
argument_list|(
name|subdir_path
operator|.
name|mid
argument_list|(
name|thispwd
operator|.
name|length
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//handle sub project
name|QMakeProject
modifier|*
name|sub_proj
init|=
operator|new
name|QMakeProject
decl_stmt|;
for|for
control|(
name|int
name|ind
init|=
literal|0
init|;
name|ind
operator|<
name|sub
operator|->
name|indent
condition|;
operator|++
name|ind
control|)
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|sub
operator|->
name|input_dir
operator|=
name|subdir
operator|.
name|absolutePath
argument_list|()
expr_stmt|;
if|if
condition|(
name|subdir
operator|.
name|isRelative
argument_list|()
operator|&&
name|old_output_dir
operator|!=
name|oldpwd
condition|)
block|{
name|sub
operator|->
name|output_dir
operator|=
name|old_output_dir
operator|+
operator|(
name|subdir
operator|.
name|path
argument_list|()
operator|!=
literal|"."
condition|?
literal|"/"
operator|+
name|subdir
operator|.
name|path
argument_list|()
else|:
name|QString
argument_list|()
operator|)
expr_stmt|;
name|printf
argument_list|(
literal|"Reading %s [%s]\n"
argument_list|,
name|subdir
operator|.
name|absoluteFilePath
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|sub
operator|->
name|output_dir
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
comment|//what about shadow builds?
name|sub
operator|->
name|output_dir
operator|=
name|sub
operator|->
name|input_dir
expr_stmt|;
name|printf
argument_list|(
literal|"Reading %s\n"
argument_list|,
name|subdir
operator|.
name|absoluteFilePath
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|qmake_setpwd
argument_list|(
name|sub
operator|->
name|input_dir
argument_list|)
expr_stmt|;
name|Option
operator|::
name|output_dir
operator|=
name|sub
operator|->
name|output_dir
expr_stmt|;
name|bool
name|tmpError
init|=
operator|!
name|sub_proj
operator|->
name|read
argument_list|(
name|subdir
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|sub_proj
operator|->
name|isEmpty
argument_list|(
literal|"QMAKE_FAILED_REQUIREMENTS"
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Project file(%s) not recursed because all requirements not met:\n\t%s\n"
argument_list|,
name|subdir
operator|.
name|fileName
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|sub_proj
operator|->
name|values
argument_list|(
literal|"QMAKE_FAILED_REQUIREMENTS"
argument_list|)
operator|.
name|join
argument_list|(
literal|' '
argument_list|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|sub
expr_stmt|;
operator|delete
name|sub_proj
expr_stmt|;
name|Option
operator|::
name|output_dir
operator|=
name|old_output_dir
expr_stmt|;
name|qmake_setpwd
argument_list|(
name|oldpwd
argument_list|)
expr_stmt|;
continue|continue;
block|}
else|else
block|{
name|hasError
operator||=
name|tmpError
expr_stmt|;
block|}
name|sub
operator|->
name|makefile
operator|=
name|MetaMakefileGenerator
operator|::
name|createMetaGenerator
argument_list|(
name|sub_proj
argument_list|,
name|sub_name
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|&&
name|sub
operator|->
name|makefile
operator|->
name|type
argument_list|()
operator|==
name|SUBDIRSMETATYPE
condition|)
block|{
name|subs
operator|.
name|append
argument_list|(
name|sub
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|QString
name|output_name
init|=
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
decl_stmt|;
name|Option
operator|::
name|output
operator|.
name|setFileName
argument_list|(
name|sub
operator|->
name|output_file
argument_list|)
expr_stmt|;
name|hasError
operator||=
operator|!
name|sub
operator|->
name|makefile
operator|->
name|write
argument_list|()
expr_stmt|;
operator|delete
name|sub
expr_stmt|;
name|qmakeClearCaches
argument_list|()
expr_stmt|;
name|sub
operator|=
literal|0
expr_stmt|;
name|Option
operator|::
name|output
operator|.
name|setFileName
argument_list|(
name|output_name
argument_list|)
expr_stmt|;
block|}
name|Option
operator|::
name|output_dir
operator|=
name|old_output_dir
expr_stmt|;
name|qmake_setpwd
argument_list|(
name|oldpwd
argument_list|)
expr_stmt|;
block|}
operator|--
name|recurseDepth
expr_stmt|;
name|Option
operator|::
name|output
operator|.
name|setFileName
argument_list|(
name|old_output
argument_list|)
expr_stmt|;
name|Option
operator|::
name|output_dir
operator|=
name|old_output_dir
expr_stmt|;
name|qmake_setpwd
argument_list|(
name|oldpwd
argument_list|)
expr_stmt|;
block|}
name|Subdir
modifier|*
name|self
init|=
operator|new
name|Subdir
decl_stmt|;
name|self
operator|->
name|input_dir
operator|=
name|qmake_getpwd
argument_list|()
expr_stmt|;
name|self
operator|->
name|output_dir
operator|=
name|Option
operator|::
name|output_dir
expr_stmt|;
if|if
condition|(
operator|!
name|recurse
operator|||
operator|(
operator|!
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
operator|.
name|endsWith
argument_list|(
name|Option
operator|::
name|dir_sep
argument_list|)
operator|&&
operator|!
name|QFileInfo
argument_list|(
name|Option
operator|::
name|output
argument_list|)
operator|.
name|isDir
argument_list|()
operator|)
condition|)
name|self
operator|->
name|output_file
operator|=
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
expr_stmt|;
name|self
operator|->
name|makefile
operator|=
operator|new
name|BuildsMetaMakefileGenerator
argument_list|(
name|project
argument_list|,
name|name
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|self
operator|->
name|makefile
operator|->
name|init
argument_list|()
expr_stmt|;
name|subs
operator|.
name|append
argument_list|(
name|self
argument_list|)
expr_stmt|;
return|return
operator|!
name|hasError
return|;
block|}
end_function
begin_function
name|bool
DECL|function|write
name|SubdirsMetaMakefileGenerator
operator|::
name|write
parameter_list|()
block|{
name|bool
name|ret
init|=
literal|true
decl_stmt|;
specifier|const
name|QString
modifier|&
name|pwd
init|=
name|qmake_getpwd
argument_list|()
decl_stmt|;
specifier|const
name|QString
modifier|&
name|output_dir
init|=
name|Option
operator|::
name|output_dir
decl_stmt|;
specifier|const
name|QString
modifier|&
name|output_name
init|=
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|ret
operator|&&
name|i
operator|<
name|subs
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|Subdir
modifier|*
name|sub
init|=
name|subs
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|qmake_setpwd
argument_list|(
name|sub
operator|->
name|input_dir
argument_list|)
expr_stmt|;
name|Option
operator|::
name|output_dir
operator|=
name|QFileInfo
argument_list|(
name|sub
operator|->
name|output_dir
argument_list|)
operator|.
name|absoluteFilePath
argument_list|()
expr_stmt|;
name|Option
operator|::
name|output
operator|.
name|setFileName
argument_list|(
name|sub
operator|->
name|output_file
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|!=
name|subs
operator|.
name|count
argument_list|()
operator|-
literal|1
condition|)
block|{
for|for
control|(
name|int
name|ind
init|=
literal|0
init|;
name|ind
operator|<
name|sub
operator|->
name|indent
condition|;
operator|++
name|ind
control|)
name|printf
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Writing %s\n"
argument_list|,
name|QDir
operator|::
name|cleanPath
argument_list|(
name|Option
operator|::
name|output_dir
operator|+
literal|"/"
operator|+
name|Option
operator|::
name|output
operator|.
name|fileName
argument_list|()
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
if|if
condition|(
operator|!
operator|(
name|ret
operator|=
name|sub
operator|->
name|makefile
operator|->
name|write
argument_list|()
operator|)
condition|)
break|break;
comment|//restore because I'm paranoid
name|qmake_setpwd
argument_list|(
name|pwd
argument_list|)
expr_stmt|;
name|Option
operator|::
name|output
operator|.
name|setFileName
argument_list|(
name|output_name
argument_list|)
expr_stmt|;
name|Option
operator|::
name|output_dir
operator|=
name|output_dir
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_destructor
DECL|function|~SubdirsMetaMakefileGenerator
name|SubdirsMetaMakefileGenerator
operator|::
name|~
name|SubdirsMetaMakefileGenerator
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|subs
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
operator|delete
name|subs
index|[
name|i
index|]
expr_stmt|;
name|subs
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|//Factory things
end_comment
begin_function
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|"unixmake.h"
include|#
directive|include
file|"mingw_make.h"
include|#
directive|include
file|"projectgenerator.h"
include|#
directive|include
file|"pbuilder_pbx.h"
include|#
directive|include
file|"msvc_nmake.h"
include|#
directive|include
file|"msvc_vcproj.h"
include|#
directive|include
file|"msvc_vcxproj.h"
name|QT_END_INCLUDE_NAMESPACE
name|MakefileGenerator
modifier|*
DECL|function|createMakefileGenerator
name|MetaMakefileGenerator
operator|::
name|createMakefileGenerator
parameter_list|(
name|QMakeProject
modifier|*
name|proj
parameter_list|,
name|bool
name|noIO
parameter_list|)
block|{
name|Option
operator|::
name|postProcessProject
argument_list|(
name|proj
argument_list|)
expr_stmt|;
name|MakefileGenerator
modifier|*
name|mkfile
init|=
name|NULL
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
block|{
name|mkfile
operator|=
operator|new
name|ProjectGenerator
expr_stmt|;
name|mkfile
operator|->
name|setProjectFile
argument_list|(
name|proj
argument_list|)
expr_stmt|;
return|return
name|mkfile
return|;
block|}
name|ProString
name|gen
init|=
name|proj
operator|->
name|first
argument_list|(
literal|"MAKEFILE_GENERATOR"
argument_list|)
decl_stmt|;
if|if
condition|(
name|gen
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"MAKEFILE_GENERATOR variable not set as a result of parsing : %s. Possibly qmake was not able to find files included using \"include(..)\" - enable qmake debugging to investigate more.\n"
argument_list|,
name|proj
operator|->
name|projectFile
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|gen
operator|==
literal|"UNIX"
condition|)
block|{
name|mkfile
operator|=
operator|new
name|UnixMakefileGenerator
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|gen
operator|==
literal|"MINGW"
condition|)
block|{
name|mkfile
operator|=
operator|new
name|MingwMakefileGenerator
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|gen
operator|==
literal|"PROJECTBUILDER"
operator|||
name|gen
operator|==
literal|"XCODE"
condition|)
block|{
ifdef|#
directive|ifdef
name|Q_CC_MSVC
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Generating Xcode projects is not supported with an MSVC build of Qt.\n"
argument_list|)
expr_stmt|;
else|#
directive|else
name|mkfile
operator|=
operator|new
name|ProjectBuilderMakefileGenerator
expr_stmt|;
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|gen
operator|==
literal|"MSVC.NET"
condition|)
block|{
if|if
condition|(
name|proj
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|.
name|startsWith
argument_list|(
literal|"vc"
argument_list|)
condition|)
name|mkfile
operator|=
operator|new
name|VcprojGenerator
expr_stmt|;
else|else
name|mkfile
operator|=
operator|new
name|NmakeMakefileGenerator
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|gen
operator|==
literal|"MSBUILD"
condition|)
block|{
comment|// Visual Studio>= v11.0
if|if
condition|(
name|proj
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|.
name|startsWith
argument_list|(
literal|"vc"
argument_list|)
condition|)
name|mkfile
operator|=
operator|new
name|VcxprojGenerator
expr_stmt|;
else|else
name|mkfile
operator|=
operator|new
name|NmakeMakefileGenerator
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Unknown generator specified: %s\n"
argument_list|,
name|gen
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mkfile
condition|)
block|{
name|mkfile
operator|->
name|setNoIO
argument_list|(
name|noIO
argument_list|)
expr_stmt|;
name|mkfile
operator|->
name|setProjectFile
argument_list|(
name|proj
argument_list|)
expr_stmt|;
block|}
return|return
name|mkfile
return|;
block|}
end_function
begin_function
name|MetaMakefileGenerator
modifier|*
DECL|function|createMetaGenerator
name|MetaMakefileGenerator
operator|::
name|createMetaGenerator
parameter_list|(
name|QMakeProject
modifier|*
name|proj
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|bool
name|op
parameter_list|,
name|bool
modifier|*
name|success
parameter_list|)
block|{
name|Option
operator|::
name|postProcessProject
argument_list|(
name|proj
argument_list|)
expr_stmt|;
name|MetaMakefileGenerator
modifier|*
name|ret
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|(
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
operator|)
condition|)
block|{
if|if
condition|(
name|proj
operator|->
name|first
argument_list|(
literal|"TEMPLATE"
argument_list|)
operator|.
name|endsWith
argument_list|(
literal|"subdirs"
argument_list|)
condition|)
name|ret
operator|=
operator|new
name|SubdirsMetaMakefileGenerator
argument_list|(
name|proj
argument_list|,
name|name
argument_list|,
name|op
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|ret
condition|)
name|ret
operator|=
operator|new
name|BuildsMetaMakefileGenerator
argument_list|(
name|proj
argument_list|,
name|name
argument_list|,
name|op
argument_list|)
expr_stmt|;
name|bool
name|res
init|=
name|ret
operator|->
name|init
argument_list|()
decl_stmt|;
if|if
condition|(
name|success
condition|)
operator|*
name|success
operator|=
name|res
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_QMAKE_PARSER_ONLY
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
