begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatformintegrationfactory_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegrationplugin.h>
end_include
begin_include
include|#
directive|include
file|"private/qfactoryloader_p.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_include
include|#
directive|include
file|"qguiapplication.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|loader
argument_list|,
operator|(
name|QPlatformIntegrationFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|"/platforms"
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QFactoryLoader
argument_list|,
name|directLoader
argument_list|,
operator|(
name|QPlatformIntegrationFactoryInterface_iid
operator|,
name|QLatin1String
argument_list|(
literal|""
argument_list|)
operator|,
name|Qt
operator|::
name|CaseInsensitive
operator|)
argument_list|)
endif|#
directive|endif
DECL|function|create
name|QPlatformIntegration
modifier|*
name|QPlatformIntegrationFactory
operator|::
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|platform
argument_list|,
specifier|const
name|QStringList
operator|&
name|paramList
argument_list|,
specifier|const
name|QString
operator|&
name|platformPluginPath
argument_list|)
argument_list|{
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
comment|// Try loading the plugin from platformPluginPath first:
argument_list|if
operator|(
operator|!
name|platformPluginPath
operator|.
name|isEmpty
argument_list|()
operator|)
block|{
name|QCoreApplication
operator|::
name|addLibraryPath
argument_list|(
name|platformPluginPath
argument_list|)
block|;
if|if
condition|(
name|QPlatformIntegration
modifier|*
name|ret
type|=
name|qLoadPlugin1
argument_list|<
name|QPlatformIntegration
argument_list|,
name|QPlatformIntegrationPlugin
argument_list|>
type|(
name|directLoader
type|(
condition|)
operator|,
condition|platform
operator|,
condition|paramList))
return|return
name|ret
return|;
block|}
if|if
condition|(
name|QPlatformIntegration
modifier|*
name|ret
type|=
name|qLoadPlugin1
argument_list|<
name|QPlatformIntegration
argument_list|,
name|QPlatformIntegrationPlugin
argument_list|>
type|(
name|loader
type|(
condition|)
operator|,
condition|platform
operator|,
condition|paramList))
return|return
name|ret
return|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_return
return|return
literal|0
return|;
end_return
begin_comment
unit|}
comment|/*!     Returns the list of valid keys, i.e. the keys this factory can     create styles for.      \sa create() */
end_comment
begin_macro
unit|QStringList
DECL|function|keys
name|QPlatformIntegrationFactory
end_macro
begin_expr_stmt
DECL|function|keys
operator|::
name|keys
operator|(
specifier|const
name|QString
operator|&
name|platformPluginPath
operator|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
name|QStringList
name|list
block|;
if|if
condition|(
operator|!
name|platformPluginPath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QCoreApplication
operator|::
name|addLibraryPath
argument_list|(
name|platformPluginPath
argument_list|)
expr_stmt|;
name|list
operator|=
name|directLoader
argument_list|()
operator|->
name|keyMap
argument_list|()
operator|.
name|values
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|list
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|postFix
init|=
name|QStringLiteral
argument_list|(
literal|" (from "
argument_list|)
operator|+
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|platformPluginPath
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
decl_stmt|;
specifier|const
name|QStringList
operator|::
name|iterator
name|end
init|=
name|list
operator|.
name|end
argument_list|()
decl_stmt|;
for|for
control|(
name|QStringList
operator|::
name|iterator
name|it
init|=
name|list
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
operator|(
operator|*
name|it
operator|)
operator|.
name|append
argument_list|(
name|postFix
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_expr_stmt
unit|}     list
operator|.
name|append
argument_list|(
name|loader
argument_list|()
operator|->
name|keyMap
argument_list|()
operator|.
name|values
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|list
return|;
end_return
begin_else
else|#
directive|else
end_else
begin_return
return|return
name|QStringList
argument_list|()
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
unit|}  QT_END_NAMESPACE
end_unit
