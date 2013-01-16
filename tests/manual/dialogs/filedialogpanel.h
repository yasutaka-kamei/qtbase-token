begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FILEDIALOGPANEL_H
end_ifndef
begin_define
DECL|macro|FILEDIALOGPANEL_H
define|#
directive|define
name|FILEDIALOGPANEL_H
end_define
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QFileDialog>
end_include
begin_include
include|#
directive|include
file|<QPointer>
end_include
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCheckBox
name|class
name|QCheckBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QComboBox
name|class
name|QComboBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlainTextEdit
name|class
name|QPlainTextEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|LabelLineEdit
name|class
name|LabelLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|FileDialogPanel
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|FileDialogPanel
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|showModal
argument_list|()
block|;
name|void
name|showNonModal
argument_list|()
block|;
name|void
name|deleteNonModalDialog
argument_list|()
block|;
name|void
name|getOpenFileNames
argument_list|()
block|;
name|void
name|getOpenFileName
argument_list|()
block|;
name|void
name|getSaveFileName
argument_list|()
block|;
name|void
name|getExistingDirectory
argument_list|()
block|;
name|void
name|accepted
argument_list|()
block|;
name|void
name|showAcceptedResult
argument_list|()
block|;
name|void
name|restoreDefaults
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|enableDeleteNonModalDialogButton
argument_list|()
block|;
name|private
operator|:
name|QString
name|filterString
argument_list|()
specifier|const
block|;
name|QFileDialog
operator|::
name|Options
name|options
argument_list|()
specifier|const
block|;
name|void
name|applySettings
argument_list|(
argument|QFileDialog *d
argument_list|)
specifier|const
block|;
name|QCheckBox
operator|*
name|m_readOnly
block|;
name|QCheckBox
operator|*
name|m_confirmOverWrite
block|;
name|QCheckBox
operator|*
name|m_nameFilterDetailsVisible
block|;
name|QCheckBox
operator|*
name|m_resolveSymLinks
block|;
name|QCheckBox
operator|*
name|m_native
block|;
name|QComboBox
operator|*
name|m_acceptMode
block|;
name|QComboBox
operator|*
name|m_fileMode
block|;
name|QComboBox
operator|*
name|m_viewMode
block|;
name|QLineEdit
operator|*
name|m_defaultSuffix
block|;
name|QLineEdit
operator|*
name|m_directory
block|;
name|QLineEdit
operator|*
name|m_selectedFileName
block|;
name|QList
operator|<
name|LabelLineEdit
operator|*
operator|>
name|m_labelLineEdits
block|;
name|QPlainTextEdit
operator|*
name|m_nameFilters
block|;
name|QLineEdit
operator|*
name|m_selectedNameFilter
block|;
name|QPushButton
operator|*
name|m_deleteNonModalDialogButton
block|;
name|QString
name|m_result
block|;
name|QPointer
operator|<
name|QFileDialog
operator|>
name|m_nonModalDialog
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// FILEDIALOGPANEL_H
end_comment
end_unit
