begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLUGINLOADER_H
end_ifndef
begin_define
DECL|macro|QPLUGINLOADER_H
define|#
directive|define
name|QPLUGINLOADER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qlibrary.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QLibraryPrivate
name|class
name|QLibraryPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QJsonObject
name|class
name|QJsonObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QPluginLoader
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString fileName READ fileName WRITE setFileName
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QLibrary::LoadHints loadHints READ loadHints WRITE setLoadHints
argument_list|)
name|public
operator|:
name|explicit
name|QPluginLoader
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QPluginLoader
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QPluginLoader
argument_list|()
block|;
name|QObject
operator|*
name|instance
argument_list|()
block|;
name|QJsonObject
name|metaData
argument_list|()
specifier|const
block|;
specifier|static
name|QObjectList
name|staticInstances
argument_list|()
block|;
name|bool
name|load
argument_list|()
block|;
name|bool
name|unload
argument_list|()
block|;
name|bool
name|isLoaded
argument_list|()
specifier|const
block|;
name|void
name|setFileName
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|QString
name|fileName
argument_list|()
specifier|const
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
name|void
name|setLoadHints
argument_list|(
argument|QLibrary::LoadHints loadHints
argument_list|)
block|;
name|QLibrary
operator|::
name|LoadHints
name|loadHints
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QLibraryPrivate
operator|*
name|d
block|;
name|bool
name|did_load
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QPluginLoader
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QPLUGINLOADER_H
end_comment
end_unit
