begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEMPORARYFILE_P_H
end_ifndef
begin_define
DECL|macro|QTEMPORARYFILE_P_H
define|#
directive|define
name|QTEMPORARYFILE_P_H
end_define
begin_include
include|#
directive|include
file|"private/qfsfileengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qfilesystemengine_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qfile_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QTemporaryFilePrivate
range|:
name|public
name|QFilePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QTemporaryFile
argument_list|)
name|protected
operator|:
name|QTemporaryFilePrivate
argument_list|()
block|;
operator|~
name|QTemporaryFilePrivate
argument_list|()
block|;
name|QAbstractFileEngine
operator|*
name|engine
argument_list|()
specifier|const
block|;
name|bool
name|autoRemove
block|;
name|QString
name|templateName
block|;
specifier|static
name|QString
name|defaultTemplateName
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTemporaryFileEngine
range|:
name|public
name|QFSFileEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFSFileEngine
argument_list|)
name|public
operator|:
name|QTemporaryFileEngine
argument_list|(
argument|const QString&file
argument_list|,
argument|bool fileIsTemplate = true
argument_list|)
operator|:
name|QFSFileEngine
argument_list|()
block|,
name|filePathIsTemplate
argument_list|(
name|fileIsTemplate
argument_list|)
block|,
name|filePathWasTemplate
argument_list|(
argument|fileIsTemplate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QFSFileEngine
argument_list|)
block|;
name|d
operator|->
name|fileEntry
operator|=
name|QFileSystemEntry
argument_list|(
name|file
argument_list|)
block|;
if|if
condition|(
operator|!
name|filePathIsTemplate
condition|)
name|QFSFileEngine
operator|::
name|setFileName
argument_list|(
name|file
argument_list|)
expr_stmt|;
block|}
operator|~
name|QTemporaryFileEngine
argument_list|()
block|;
name|bool
name|isReallyOpen
argument_list|()
block|;
name|void
name|setFileName
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|void
name|setFileTemplate
argument_list|(
specifier|const
name|QString
operator|&
name|fileTemplate
argument_list|)
block|;
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|)
block|;
name|bool
name|remove
argument_list|()
block|;
name|bool
name|rename
argument_list|(
specifier|const
name|QString
operator|&
name|newName
argument_list|)
block|;
name|bool
name|renameOverwrite
argument_list|(
specifier|const
name|QString
operator|&
name|newName
argument_list|)
block|;
name|bool
name|close
argument_list|()
block|;
name|bool
name|filePathIsTemplate
block|;
name|bool
name|filePathWasTemplate
block|; }
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
comment|/* QTEMPORARYFILE_P_H */
end_comment
end_unit
