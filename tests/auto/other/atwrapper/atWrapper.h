begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ATWRAPPER_H
end_ifndef
begin_define
DECL|macro|ATWRAPPER_H
define|#
directive|define
name|ATWRAPPER_H
end_define
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QUrlInfo>
end_include
begin_include
include|#
directive|include
file|<QColor>
end_include
begin_decl_stmt
name|class
name|atWrapper
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|atWrapper
argument_list|()
block|;
name|bool
name|runAutoTests
argument_list|()
block|;
name|private
operator|:
name|bool
name|executeTests
argument_list|()
block|;
name|bool
name|initTests
argument_list|(
name|bool
operator|*
name|haveBaseline
argument_list|)
block|;
name|bool
name|compare
argument_list|()
block|;
name|void
name|createBaseline
argument_list|()
block|;
name|bool
name|loadConfig
argument_list|(
name|QString
argument_list|)
block|;
name|void
name|compareDirs
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|)
block|;
name|bool
name|diff
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
block|;
name|void
name|downloadBaseline
argument_list|()
block|;
name|void
name|uploadFailed
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QByteArray
argument_list|)
block|;
name|bool
name|ftpMkDir
argument_list|(
name|QString
argument_list|)
block|;
name|void
name|ftpRmDir
argument_list|(
name|QString
argument_list|)
block|;
name|bool
name|setupFTP
argument_list|()
block|;
name|void
name|uploadDiff
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
block|;
name|QHash
operator|<
name|QString
block|,
name|QString
operator|>
name|enginesToTest
block|;
name|QString
name|framework
block|;
name|QString
name|suite
block|;
name|QString
name|output
block|;
name|QString
name|size
block|;
name|QString
name|ftpUser
block|;
name|QString
name|ftpPass
block|;
name|QString
name|ftpHost
block|;
name|QString
name|ftpBaseDir
block|;
name|QList
operator|<
name|QString
operator|>
name|rmDirList
block|;
name|QList
operator|<
name|QString
operator|>
name|mgetDirList
block|;
name|QString
name|configPath
block|;
name|QString
name|fillColor
block|;
name|private
name|slots
operator|:
name|void
name|ftpRmDirAddToList
argument_list|(
specifier|const
name|QUrlInfo
operator|&
name|urlInfo
argument_list|)
block|;
name|void
name|ftpRmDirDone
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|ftpMgetAddToList
argument_list|(
specifier|const
name|QUrlInfo
operator|&
name|urlInfo
argument_list|)
block|;
name|void
name|ftpMgetDone
argument_list|(
name|bool
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
