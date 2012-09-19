begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qsettings.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
specifier|static
specifier|const
expr|struct
block|{
DECL|member|name
specifier|const
name|char
operator|*
name|name
block|;
DECL|member|loc
name|QLibraryInfo
operator|::
name|LibraryLocation
name|loc
block|;
DECL|member|raw
name|bool
name|raw
block|; }
DECL|variable|propList
name|propList
index|[]
operator|=
block|{
block|{
literal|"QT_SYSROOT"
block|,
name|QLibraryInfo
operator|::
name|SysrootPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_INSTALL_PREFIX"
block|,
name|QLibraryInfo
operator|::
name|PrefixPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_DATA"
block|,
name|QLibraryInfo
operator|::
name|DataPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_DOCS"
block|,
name|QLibraryInfo
operator|::
name|DocumentationPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_HEADERS"
block|,
name|QLibraryInfo
operator|::
name|HeadersPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_LIBS"
block|,
name|QLibraryInfo
operator|::
name|LibrariesPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_BINS"
block|,
name|QLibraryInfo
operator|::
name|BinariesPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_TESTS"
block|,
name|QLibraryInfo
operator|::
name|TestsPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_PLUGINS"
block|,
name|QLibraryInfo
operator|::
name|PluginsPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_IMPORTS"
block|,
name|QLibraryInfo
operator|::
name|ImportsPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_TRANSLATIONS"
block|,
name|QLibraryInfo
operator|::
name|TranslationsPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_CONFIGURATION"
block|,
name|QLibraryInfo
operator|::
name|SettingsPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_EXAMPLES"
block|,
name|QLibraryInfo
operator|::
name|ExamplesPath
block|,
literal|false
block|}
block|,
block|{
literal|"QT_INSTALL_DEMOS"
block|,
name|QLibraryInfo
operator|::
name|ExamplesPath
block|,
literal|false
block|}
block|,
comment|// Just backwards compat
block|{
literal|"QT_HOST_PREFIX"
block|,
name|QLibraryInfo
operator|::
name|HostPrefixPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_HOST_DATA"
block|,
name|QLibraryInfo
operator|::
name|HostDataPath
block|,
literal|true
block|}
block|,
block|{
literal|"QT_HOST_BINS"
block|,
name|QLibraryInfo
operator|::
name|HostBinariesPath
block|,
literal|true
block|}
block|, }
expr_stmt|;
end_expr_stmt
begin_constructor
DECL|function|QMakeProperty
name|QMakeProperty
operator|::
name|QMakeProperty
parameter_list|()
member_init_list|:
name|settings
argument_list|(
literal|0
argument_list|)
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
sizeof|sizeof
argument_list|(
name|propList
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|propList
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
name|QString
name|name
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|propList
index|[
name|i
index|]
operator|.
name|name
argument_list|)
decl_stmt|;
name|m_values
index|[
name|ProKey
argument_list|(
name|name
operator|+
literal|"/get"
argument_list|)
index|]
operator|=
name|QLibraryInfo
operator|::
name|rawLocation
argument_list|(
name|propList
index|[
name|i
index|]
operator|.
name|loc
argument_list|,
name|QLibraryInfo
operator|::
name|EffectivePaths
argument_list|)
expr_stmt|;
name|QString
name|val
init|=
name|QLibraryInfo
operator|::
name|rawLocation
argument_list|(
name|propList
index|[
name|i
index|]
operator|.
name|loc
argument_list|,
name|QLibraryInfo
operator|::
name|FinalPaths
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|propList
index|[
name|i
index|]
operator|.
name|raw
condition|)
block|{
name|m_values
index|[
name|ProKey
argument_list|(
name|name
argument_list|)
index|]
operator|=
name|QLibraryInfo
operator|::
name|location
argument_list|(
name|propList
index|[
name|i
index|]
operator|.
name|loc
argument_list|)
expr_stmt|;
name|name
operator|+=
literal|"/raw"
expr_stmt|;
block|}
name|m_values
index|[
name|ProKey
argument_list|(
name|name
argument_list|)
index|]
operator|=
name|val
expr_stmt|;
block|}
name|m_values
index|[
literal|"QMAKE_VERSION"
index|]
operator|=
name|ProString
argument_list|(
name|QMAKE_VERSION_STR
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_VERSION_STR
name|m_values
index|[
literal|"QT_VERSION"
index|]
operator|=
name|ProString
argument_list|(
name|QT_VERSION_STR
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_destructor
DECL|function|~QMakeProperty
name|QMakeProperty
operator|::
name|~
name|QMakeProperty
parameter_list|()
block|{
operator|delete
name|settings
expr_stmt|;
name|settings
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|initSettings
name|void
name|QMakeProperty
operator|::
name|initSettings
parameter_list|()
block|{
if|if
condition|(
operator|!
name|settings
condition|)
block|{
name|settings
operator|=
operator|new
name|QSettings
argument_list|(
name|QSettings
operator|::
name|UserScope
argument_list|,
literal|"Trolltech"
argument_list|,
literal|"QMake"
argument_list|)
expr_stmt|;
name|settings
operator|->
name|setFallbacksEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
name|ProString
DECL|function|value
name|QMakeProperty
operator|::
name|value
parameter_list|(
specifier|const
name|ProKey
modifier|&
name|vk
parameter_list|)
block|{
name|ProString
name|val
init|=
name|m_values
operator|.
name|value
argument_list|(
name|vk
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|val
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|val
return|;
name|initSettings
argument_list|()
expr_stmt|;
name|QString
name|v
init|=
name|vk
operator|.
name|toQString
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|settings
operator|->
name|contains
argument_list|(
name|v
argument_list|)
condition|)
return|return
name|settings
operator|->
name|value
argument_list|(
literal|"2.01a/"
operator|+
name|v
argument_list|)
operator|.
name|toString
argument_list|()
return|;
comment|// Backwards compat
return|return
name|settings
operator|->
name|value
argument_list|(
name|v
argument_list|)
operator|.
name|toString
argument_list|()
return|;
block|}
end_function
begin_function
name|bool
DECL|function|hasValue
name|QMakeProperty
operator|::
name|hasValue
parameter_list|(
specifier|const
name|ProKey
modifier|&
name|v
parameter_list|)
block|{
return|return
operator|!
name|value
argument_list|(
name|v
argument_list|)
operator|.
name|isNull
argument_list|()
return|;
block|}
end_function
begin_function
name|void
DECL|function|setValue
name|QMakeProperty
operator|::
name|setValue
parameter_list|(
name|QString
name|var
parameter_list|,
specifier|const
name|QString
modifier|&
name|val
parameter_list|)
block|{
name|initSettings
argument_list|()
expr_stmt|;
name|settings
operator|->
name|setValue
argument_list|(
name|var
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|settings
operator|->
name|remove
argument_list|(
literal|"2.01a/"
operator|+
name|var
argument_list|)
expr_stmt|;
comment|// Backwards compat
block|}
end_function
begin_function
name|void
DECL|function|remove
name|QMakeProperty
operator|::
name|remove
parameter_list|(
specifier|const
name|QString
modifier|&
name|var
parameter_list|)
block|{
name|initSettings
argument_list|()
expr_stmt|;
name|settings
operator|->
name|remove
argument_list|(
name|var
argument_list|)
expr_stmt|;
name|settings
operator|->
name|remove
argument_list|(
literal|"2.01a/"
operator|+
name|var
argument_list|)
expr_stmt|;
comment|// Backwards compat
block|}
end_function
begin_function
name|bool
DECL|function|exec
name|QMakeProperty
operator|::
name|exec
parameter_list|()
block|{
name|bool
name|ret
init|=
literal|true
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
condition|)
block|{
if|if
condition|(
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|initSettings
argument_list|()
expr_stmt|;
name|QStringList
name|keys
init|=
name|settings
operator|->
name|childKeys
argument_list|()
decl_stmt|;
name|settings
operator|->
name|beginGroup
argument_list|(
literal|"2.01a"
argument_list|)
expr_stmt|;
name|keys
operator|+=
name|settings
operator|->
name|childKeys
argument_list|()
expr_stmt|;
name|settings
operator|->
name|endGroup
argument_list|()
expr_stmt|;
name|keys
operator|.
name|removeDuplicates
argument_list|()
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|key
decl|,
name|keys
control|)
block|{
name|QString
name|val
init|=
name|settings
operator|->
name|value
argument_list|(
name|settings
operator|->
name|contains
argument_list|(
name|key
argument_list|)
condition|?
name|key
else|:
literal|"2.01a/"
operator|+
name|key
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s:%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|key
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|val
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QStringList
name|specialProps
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
sizeof|sizeof
argument_list|(
name|propList
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|propList
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
name|specialProps
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|propList
index|[
name|i
index|]
operator|.
name|name
argument_list|)
argument_list|)
expr_stmt|;
name|specialProps
operator|.
name|append
argument_list|(
literal|"QMAKE_VERSION"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_VERSION_STR
name|specialProps
operator|.
name|append
argument_list|(
literal|"QT_VERSION"
argument_list|)
expr_stmt|;
endif|#
directive|endif
foreach|foreach
control|(
name|QString
name|prop
decl|,
name|specialProps
control|)
block|{
name|ProString
name|val
init|=
name|value
argument_list|(
name|ProKey
argument_list|(
name|prop
argument_list|)
argument_list|)
decl_stmt|;
name|ProString
name|pval
init|=
name|value
argument_list|(
name|ProKey
argument_list|(
name|prop
operator|+
literal|"/raw"
argument_list|)
argument_list|)
decl_stmt|;
name|ProString
name|gval
init|=
name|value
argument_list|(
name|ProKey
argument_list|(
name|prop
operator|+
literal|"/get"
argument_list|)
argument_list|)
decl_stmt|;
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s:%s\n"
argument_list|,
name|prop
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|val
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
name|pval
operator|.
name|isEmpty
argument_list|()
operator|&&
name|pval
operator|!=
name|val
condition|)
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s/raw:%s\n"
argument_list|,
name|prop
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|pval
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
name|gval
operator|.
name|isEmpty
argument_list|()
operator|&&
name|gval
operator|!=
operator|(
name|pval
operator|.
name|isEmpty
argument_list|()
condition|?
name|val
else|:
name|pval
operator|)
condition|)
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s/get:%s\n"
argument_list|,
name|prop
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|gval
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
literal|true
return|;
block|}
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
block|{
if|if
condition|(
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|count
argument_list|()
operator|>
literal|1
condition|)
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s:"
argument_list|,
operator|(
operator|*
name|it
operator|)
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|ProKey
name|pkey
argument_list|(
operator|*
name|it
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|hasValue
argument_list|(
name|pkey
argument_list|)
condition|)
block|{
name|ret
operator|=
literal|false
expr_stmt|;
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"**Unknown**\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stdout
argument_list|,
literal|"%s\n"
argument_list|,
name|value
argument_list|(
name|pkey
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
block|}
elseif|else
if|if
condition|(
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_SET_PROPERTY
condition|)
block|{
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
block|{
name|QString
name|var
init|=
operator|(
operator|*
name|it
operator|)
decl_stmt|;
name|it
operator|++
expr_stmt|;
if|if
condition|(
name|it
operator|==
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|end
argument_list|()
condition|)
block|{
name|ret
operator|=
literal|false
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|!
name|var
operator|.
name|startsWith
argument_list|(
literal|"."
argument_list|)
condition|)
name|setValue
argument_list|(
name|var
argument_list|,
operator|(
operator|*
name|it
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|Option
operator|::
name|qmake_mode
operator|==
name|Option
operator|::
name|QMAKE_UNSET_PROPERTY
condition|)
block|{
for|for
control|(
name|QStringList
operator|::
name|ConstIterator
name|it
init|=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|Option
operator|::
name|prop
operator|::
name|properties
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
block|{
name|QString
name|var
init|=
operator|(
operator|*
name|it
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|var
operator|.
name|startsWith
argument_list|(
literal|"."
argument_list|)
condition|)
name|remove
argument_list|(
name|var
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|ret
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
