begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TST_QMIMEDATABASE_H
end_ifndef
begin_define
DECL|macro|TST_QMIMEDATABASE_H
define|#
directive|define
name|TST_QMIMEDATABASE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTemporaryDir>
end_include
begin_decl_stmt
name|class
name|tst_QMimeDatabase
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|tst_QMimeDatabase
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|initTestCase
argument_list|()
block|;
name|void
name|mimeTypeForName
argument_list|()
block|;
name|void
name|mimeTypeForFileName_data
argument_list|()
block|;
name|void
name|mimeTypeForFileName
argument_list|()
block|;
name|void
name|mimeTypesForFileName_data
argument_list|()
block|;
name|void
name|mimeTypesForFileName
argument_list|()
block|;
name|void
name|inheritance
argument_list|()
block|;
name|void
name|aliases
argument_list|()
block|;
name|void
name|listAliases_data
argument_list|()
block|;
name|void
name|listAliases
argument_list|()
block|;
name|void
name|icons
argument_list|()
block|;
name|void
name|mimeTypeForFileWithContent
argument_list|()
block|;
name|void
name|mimeTypeForUrl
argument_list|()
block|;
name|void
name|mimeTypeForData_data
argument_list|()
block|;
name|void
name|mimeTypeForData
argument_list|()
block|;
name|void
name|mimeTypeForFileAndContent_data
argument_list|()
block|;
name|void
name|mimeTypeForFileAndContent
argument_list|()
block|;
name|void
name|allMimeTypes
argument_list|()
block|;
name|void
name|suffixes_data
argument_list|()
block|;
name|void
name|suffixes
argument_list|()
block|;
name|void
name|knownSuffix
argument_list|()
block|;
name|void
name|fromThreads
argument_list|()
block|;
comment|// shared-mime-info test suite
name|void
name|findByFileName_data
argument_list|()
block|;
name|void
name|findByFileName
argument_list|()
block|;
name|void
name|findByData_data
argument_list|()
block|;
name|void
name|findByData
argument_list|()
block|;
name|void
name|findByFile_data
argument_list|()
block|;
name|void
name|findByFile
argument_list|()
block|;
comment|//
name|void
name|installNewGlobalMimeType
argument_list|()
block|;
name|void
name|installNewLocalMimeType
argument_list|()
block|;
name|private
operator|:
name|void
name|init
argument_list|()
block|;
comment|// test-specific
name|QString
name|m_globalXdgDir
block|;
name|QString
name|m_localXdgDir
block|;
name|QString
name|m_yastMimeTypes
block|;
name|QString
name|m_qmlAgainFileName
block|;
name|QTemporaryDir
name|m_temporaryDir
block|;
name|QString
name|m_testSuite
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// TST_QMIMEDATABASE_H
end_comment
end_unit
