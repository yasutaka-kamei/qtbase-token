begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAFILEDIALOGHELPER_H
end_ifndef
begin_define
DECL|macro|QCOCOAFILEDIALOGHELPER_H
define|#
directive|define
name|QCOCOAFILEDIALOGHELPER_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformdialoghelper.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFileDialog
name|class
name|QFileDialog
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileDialogPrivate
name|class
name|QFileDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QCocoaFileDialogHelper
range|:
name|public
name|QPlatformFileDialogHelper
block|{
name|public
operator|:
name|QCocoaFileDialogHelper
argument_list|()
block|;
name|virtual
operator|~
name|QCocoaFileDialogHelper
argument_list|()
block|;
name|void
name|exec
argument_list|()
block|;
name|bool
name|defaultNameFilterDisables
argument_list|()
specifier|const
block|;
name|bool
name|show
argument_list|(
argument|Qt::WindowFlags windowFlags
argument_list|,
argument|Qt::WindowModality windowModality
argument_list|,
argument|QWindow *parent
argument_list|)
block|;
name|void
name|hide
argument_list|()
block|;
name|void
name|setDirectory
argument_list|(
specifier|const
name|QString
operator|&
name|directory
argument_list|)
block|;
name|QString
name|directory
argument_list|()
specifier|const
block|;
name|void
name|selectFile
argument_list|(
specifier|const
name|QString
operator|&
name|filename
argument_list|)
block|;
name|QStringList
name|selectedFiles
argument_list|()
specifier|const
block|;
name|void
name|setFilter
argument_list|()
block|;
name|void
name|selectNameFilter
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
block|;
name|QString
name|selectedNameFilter
argument_list|()
specifier|const
block|;
name|public
operator|:
name|bool
name|showCocoaFilePanel
argument_list|(
argument|Qt::WindowModality windowModality
argument_list|,
argument|QWindow *parent
argument_list|)
block|;
name|bool
name|hideCocoaFilePanel
argument_list|()
block|;
name|void
name|createNSOpenSavePanelDelegate
argument_list|()
block|;
name|void
name|QNSOpenSavePanelDelegate_selectionChanged
argument_list|(
specifier|const
name|QString
operator|&
name|newPath
argument_list|)
block|;
name|void
name|QNSOpenSavePanelDelegate_panelClosed
argument_list|(
argument|bool accepted
argument_list|)
block|;
name|void
name|QNSOpenSavePanelDelegate_directoryEntered
argument_list|(
specifier|const
name|QString
operator|&
name|newDir
argument_list|)
block|;
name|void
name|QNSOpenSavePanelDelegate_filterSelected
argument_list|(
argument|int menuIndex
argument_list|)
block|;
name|private
operator|:
name|void
operator|*
name|mDelegate
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
comment|// QCOCOAFILEDIALOGHELPER_H
end_comment
end_unit
