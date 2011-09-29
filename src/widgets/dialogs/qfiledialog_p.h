begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILEDIALOG_P_H
end_ifndef
begin_define
DECL|macro|QFILEDIALOG_P_H
define|#
directive|define
name|QFILEDIALOG_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILEDIALOG
end_ifndef
begin_include
include|#
directive|include
file|"qfiledialog.h"
end_include
begin_include
include|#
directive|include
file|"private/qdialog_p.h"
end_include
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qfilesystemmodel_p.h"
end_include
begin_include
include|#
directive|include
file|<qlistview.h>
end_include
begin_include
include|#
directive|include
file|<qtreeview.h>
end_include
begin_include
include|#
directive|include
file|<qcombobox.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbutton.h>
end_include
begin_include
include|#
directive|include
file|<qlabel.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qlineedit.h>
end_include
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_include
include|#
directive|include
file|<qstackedwidget.h>
end_include
begin_include
include|#
directive|include
file|<qdialogbuttonbox.h>
end_include
begin_include
include|#
directive|include
file|<qabstractproxymodel.h>
end_include
begin_include
include|#
directive|include
file|<qcompleter.h>
end_include
begin_include
include|#
directive|include
file|<qpointer.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qsidebar_p.h"
end_include
begin_include
include|#
directive|include
file|"qfscompleter_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qguiplatformplugin_p.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFileDialogListView
name|class
name|QFileDialogListView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileDialogTreeView
name|class
name|QFileDialogTreeView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileDialogLineEdit
name|class
name|QFileDialogLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGridLayout
name|class
name|QGridLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCompleter
name|class
name|QCompleter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHBoxLayout
name|class
name|QHBoxLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Ui_QFileDialog
name|class
name|Ui_QFileDialog
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QFileDialogArgs
struct|struct
name|QFileDialogArgs
block|{
DECL|function|QFileDialogArgs
name|QFileDialogArgs
argument_list|()
operator|:
name|parent
argument_list|(
literal|0
argument_list|)
operator|,
name|mode
argument_list|(
argument|QFileDialog::AnyFile
argument_list|)
block|{}
DECL|member|parent
name|QWidget
operator|*
name|parent
expr_stmt|;
DECL|member|caption
name|QString
name|caption
decl_stmt|;
DECL|member|directory
name|QString
name|directory
decl_stmt|;
DECL|member|selection
name|QString
name|selection
decl_stmt|;
DECL|member|filter
name|QString
name|filter
decl_stmt|;
DECL|member|mode
name|QFileDialog
operator|::
name|FileMode
name|mode
expr_stmt|;
DECL|member|options
name|QFileDialog
operator|::
name|Options
name|options
expr_stmt|;
block|}
struct|;
end_struct
begin_define
DECL|macro|UrlRole
define|#
directive|define
name|UrlRole
value|(Qt::UserRole + 1)
end_define
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QFileDialogPrivate
range|:
name|public
name|QDialogPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFileDialog
argument_list|)
name|public
operator|:
name|QFileDialogPrivate
argument_list|()
block|;
name|void
name|createToolButtons
argument_list|()
block|;
name|void
name|createMenuActions
argument_list|()
block|;
name|void
name|createWidgets
argument_list|()
block|;
name|void
name|init
argument_list|(
specifier|const
name|QString
operator|&
name|directory
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|nameFilter
operator|=
name|QString
argument_list|()
argument_list|,
specifier|const
name|QString
operator|&
name|caption
operator|=
name|QString
argument_list|()
argument_list|)
block|;
name|bool
name|itemViewKeyboardEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|QString
name|getEnvironmentVariable
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
block|;
specifier|static
name|QString
name|workingDirectory
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
specifier|static
name|QString
name|initialSelection
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|QStringList
name|typedFiles
argument_list|()
specifier|const
block|;
name|QStringList
name|addDefaultSuffixToFiles
argument_list|(
argument|const QStringList filesToFix
argument_list|)
specifier|const
block|;
name|bool
name|removeDirectory
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
specifier|inline
name|QModelIndex
name|mapToSource
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
specifier|inline
name|QModelIndex
name|mapFromSource
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
specifier|inline
name|QModelIndex
name|rootIndex
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|setRootIndex
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
specifier|inline
name|QModelIndex
name|select
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
specifier|inline
name|QString
name|rootPath
argument_list|()
specifier|const
block|;
name|QLineEdit
operator|*
name|lineEdit
argument_list|()
specifier|const
block|;
name|int
name|maxNameLength
argument_list|(
argument|const QString&path
argument_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
return|return
operator|::
name|pathconf
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|path
argument_list|)
operator|.
name|data
argument_list|()
argument_list|,
name|_PC_NAME_MAX
argument_list|)
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|DWORD
name|maxLength
block|;
name|QString
name|drive
operator|=
name|path
operator|.
name|left
argument_list|(
literal|3
argument_list|)
block|;
if|if
condition|(
operator|::
name|GetVolumeInformation
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|wchar_t
operator|*
operator|>
operator|(
name|drive
operator|.
name|utf16
argument_list|()
operator|)
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
operator|&
name|maxLength
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|==
name|FALSE
condition|)
return|return
operator|-
literal|1
return|;
end_decl_stmt
begin_return
return|return
name|maxLength
return|;
end_return
begin_else
else|#
directive|else
end_else
begin_expr_stmt
name|Q_UNUSED
argument_list|(
name|path
argument_list|)
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|MAX_PATH
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_OS_WINCE
end_comment
begin_else
else|#
directive|else
end_else
begin_expr_stmt
name|Q_UNUSED
argument_list|(
name|path
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_return
return|return
operator|-
literal|1
return|;
end_return
begin_macro
unit|}      QString
name|basename
argument_list|(
argument|const QString&path
argument_list|)
end_macro
begin_expr_stmt
specifier|const
block|{
name|int
name|separator
operator|=
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|path
argument_list|)
operator|.
name|lastIndexOf
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|separator
operator|!=
operator|-
literal|1
condition|)
return|return
name|path
operator|.
name|mid
argument_list|(
name|separator
operator|+
literal|1
argument_list|)
return|;
end_expr_stmt
begin_return
return|return
name|path
return|;
end_return
begin_expr_stmt
unit|}      QDir
operator|::
name|Filters
name|filterForMode
argument_list|(
argument|QDir::Filters filters
argument_list|)
specifier|const
block|{
if|if
condition|(
name|fileMode
operator|==
name|QFileDialog
operator|::
name|DirectoryOnly
condition|)
block|{
name|filters
operator||=
name|QDir
operator|::
name|Drives
operator||
name|QDir
operator|::
name|AllDirs
operator||
name|QDir
operator|::
name|Dirs
expr_stmt|;
name|filters
operator|&=
operator|~
name|QDir
operator|::
name|Files
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|filters
operator||=
name|QDir
operator|::
name|Drives
operator||
name|QDir
operator|::
name|AllDirs
operator||
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|Dirs
expr_stmt|;
block|}
end_else
begin_return
return|return
name|filters
return|;
end_return
begin_expr_stmt
unit|}      QAbstractItemView
operator|*
name|currentView
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function
specifier|static
specifier|inline
name|QString
name|toInternal
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_FS_FAT
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_OS2EMX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|QString
name|n
argument_list|(
name|path
argument_list|)
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
operator|(
name|int
operator|)
name|n
operator|.
name|length
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|n
index|[
name|i
index|]
operator|==
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
condition|)
name|n
index|[
name|i
index|]
operator|=
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
if|if
condition|(
operator|(
name|n
operator|.
name|size
argument_list|()
operator|>
literal|1
operator|)
operator|&&
operator|(
name|n
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"//"
argument_list|)
argument_list|)
operator|)
condition|)
name|n
operator|=
name|n
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|n
return|;
else|#
directive|else
comment|// the compile should optimize away this
return|return
name|path
return|;
endif|#
directive|endif
block|}
end_function
begin_function_decl
name|void
name|setLastVisitedDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
name|dir
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|retranslateWindowTitle
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|retranslateStrings
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|emitFilesSelected
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|files
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_goHome
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_pathChanged
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_navigateBackward
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_navigateForward
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_navigateToParent
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_createDirectory
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_showListView
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_showDetailsView
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_showContextMenu
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|position
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_renameCurrent
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_deleteCurrent
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_showHidden
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_showHeader
parameter_list|(
name|QAction
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_updateOkButton
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_currentChanged
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_enterDirectory
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_goToDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_useNameFilter
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_selectionChanged
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_goToUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_autoCompleteFileName
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_rowsInserted
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_fileRenamed
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
name|oldName
parameter_list|,
specifier|const
name|QString
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// layout
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROXYMODEL
end_ifndef
begin_decl_stmt
name|QAbstractProxyModel
modifier|*
name|proxyModel
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// data
end_comment
begin_decl_stmt
name|QStringList
name|watching
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFileSystemModel
modifier|*
name|model
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FSCOMPLETER
end_ifndef
begin_decl_stmt
name|QFSCompleter
modifier|*
name|completer
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_FSCOMPLETER
end_comment
begin_expr_stmt
name|QFileDialog
operator|::
name|FileMode
name|fileMode
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QFileDialog
operator|::
name|AcceptMode
name|acceptMode
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|confirmOverwrite
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|defaultSuffix
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|setWindowTitle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStringList
name|currentHistory
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|currentHistoryLocation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|renameAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|deleteAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|showHiddenAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QAction
modifier|*
name|newFolderAction
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|useDefaultCaption
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|defaultFileTypes
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|fileNameLabelExplicitlySat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStringList
name|nameFilters
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Members for using native dialogs:
end_comment
begin_decl_stmt
name|bool
name|nativeDialogInUse
decl_stmt|;
end_decl_stmt
begin_comment
comment|// setVisible_sys returns true if it ends up showing a native
end_comment
begin_comment
comment|// dialog. Returning false means that a non-native dialog must be
end_comment
begin_comment
comment|// used instead.
end_comment
begin_function_decl
name|bool
name|canBeNativeDialog
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|setVisible_sys
parameter_list|(
name|bool
name|visible
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|deleteNativeDialog_sys
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|QDialog
operator|::
name|DialogCode
name|dialogResultCode_sys
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setDirectory_sys
parameter_list|(
specifier|const
name|QString
modifier|&
name|directory
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|directory_sys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|selectFile_sys
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QStringList
name|selectedFiles_sys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setFilter_sys
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setNameFilters_sys
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|filters
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|selectNameFilter_sys
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|selectedNameFilter_sys
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|//////////////////////////////////////////////
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
end_if
begin_decl_stmt
name|void
modifier|*
name|mDelegate
decl_stmt|;
end_decl_stmt
begin_function_decl
name|bool
name|showCocoaFilePanel
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|hideCocoaFilePanel
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|createNSOpenSavePanelDelegate
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QNSOpenSavePanelDelegate_selectionChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|newPath
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QNSOpenSavePanelDelegate_panelClosed
parameter_list|(
name|bool
name|accepted
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QNSOpenSavePanelDelegate_directoryEntered
parameter_list|(
specifier|const
name|QString
modifier|&
name|newDir
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|QNSOpenSavePanelDelegate_filterSelected
parameter_list|(
name|int
name|menuIndex
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_macRunNativeAppModalPanel
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|mac_nativeDialogModalHelp
parameter_list|()
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QScopedPointer
operator|<
name|Ui_QFileDialog
operator|>
name|qFileDialogUi
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QString
name|acceptLabel
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QPointer
operator|<
name|QObject
operator|>
name|receiverToDisconnectOnClose
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QByteArray
name|memberToDisconnectOnClose
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QByteArray
name|signalToDisconnectOnClose
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QFileDialog
operator|::
name|Options
name|opts
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|~
name|QFileDialogPrivate
argument_list|()
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QFileDialogPrivate
argument_list|)
end_macro
begin_decl_stmt
unit|};
name|class
name|QFileDialogLineEdit
range|:
name|public
name|QLineEdit
block|{
name|public
operator|:
name|QFileDialogLineEdit
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QLineEdit
argument_list|(
name|parent
argument_list|)
block|,
name|hideOnEsc
argument_list|(
name|false
argument_list|)
block|,
name|d_ptr
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|init
argument_list|(
argument|QFileDialogPrivate *d_pointer
argument_list|)
block|{
name|d_ptr
operator|=
name|d_pointer
block|; }
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|bool
name|hideOnEsc
block|;
name|private
operator|:
name|QFileDialogPrivate
operator|*
name|d_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFileDialogComboBox
range|:
name|public
name|QComboBox
block|{
name|public
operator|:
name|QFileDialogComboBox
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QComboBox
argument_list|(
name|parent
argument_list|)
block|,
name|urlModel
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|init
argument_list|(
name|QFileDialogPrivate
operator|*
name|d_pointer
argument_list|)
block|;
name|void
name|showPopup
argument_list|()
block|;
name|void
name|setHistory
argument_list|(
specifier|const
name|QStringList
operator|&
name|paths
argument_list|)
block|;
name|QStringList
name|history
argument_list|()
specifier|const
block|{
return|return
name|m_history
return|;
block|}
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|QUrlModel
operator|*
name|urlModel
block|;
name|QFileDialogPrivate
operator|*
name|d_ptr
block|;
name|QStringList
name|m_history
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFileDialogListView
range|:
name|public
name|QListView
block|{
name|public
operator|:
name|QFileDialogListView
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|void
name|init
argument_list|(
name|QFileDialogPrivate
operator|*
name|d_pointer
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|QFileDialogPrivate
operator|*
name|d_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFileDialogTreeView
range|:
name|public
name|QTreeView
block|{
name|public
operator|:
name|QFileDialogTreeView
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|void
name|init
argument_list|(
name|QFileDialogPrivate
operator|*
name|d_pointer
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|QFileDialogPrivate
operator|*
name|d_ptr
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|mapToSource
specifier|inline
name|QModelIndex
name|QFileDialogPrivate
operator|::
name|mapToSource
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|QT_NO_PROXYMODEL
return|return
name|index
return|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_return
return|return
name|proxyModel
condition|?
name|proxyModel
operator|->
name|mapToSource
argument_list|(
name|index
argument_list|)
else|:
name|index
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|} inline
DECL|function|mapFromSource
name|QModelIndex
name|QFileDialogPrivate
operator|::
name|mapFromSource
argument_list|(
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|QT_NO_PROXYMODEL
return|return
name|index
return|;
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_return
return|return
name|proxyModel
condition|?
name|proxyModel
operator|->
name|mapFromSource
argument_list|(
name|index
argument_list|)
else|:
name|index
return|;
end_return
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|}  inline
DECL|function|rootPath
name|QString
name|QFileDialogPrivate
operator|::
name|rootPath
argument_list|()
specifier|const
block|{
return|return
name|model
operator|->
name|rootPath
argument_list|()
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|Q_WS_MAC
end_ifndef
begin_comment
comment|// Dummies for platforms that don't use native dialogs:
end_comment
begin_expr_stmt
DECL|function|deleteNativeDialog_sys
specifier|inline
name|void
name|QFileDialogPrivate
operator|::
name|deleteNativeDialog_sys
argument_list|()
block|{
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileDialogDelete
argument_list|(
name|q_func
argument_list|()
argument_list|)
block|; }
DECL|function|setVisible_sys
specifier|inline
name|bool
name|QFileDialogPrivate
operator|::
name|setVisible_sys
argument_list|(
argument|bool visible
argument_list|)
block|{
return|return
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileDialogSetVisible
argument_list|(
name|q_func
argument_list|()
argument_list|,
name|visible
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|dialogResultCode_sys
specifier|inline
name|QDialog
operator|::
name|DialogCode
name|QFileDialogPrivate
operator|::
name|dialogResultCode_sys
argument_list|()
block|{
return|return
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileDialogResultCode
argument_list|(
name|q_func
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setDirectory_sys
specifier|inline
name|void
name|QFileDialogPrivate
operator|::
name|setDirectory_sys
argument_list|(
argument|const QString&directory
argument_list|)
block|{
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileDialogSetDirectory
argument_list|(
name|q_func
argument_list|()
argument_list|,
name|directory
argument_list|)
block|; }
DECL|function|directory_sys
specifier|inline
name|QString
name|QFileDialogPrivate
operator|::
name|directory_sys
argument_list|()
specifier|const
block|{
return|return
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileDialogDirectory
argument_list|(
name|q_func
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|selectFile_sys
specifier|inline
name|void
name|QFileDialogPrivate
operator|::
name|selectFile_sys
argument_list|(
argument|const QString&filename
argument_list|)
block|{
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileDialogSelectFile
argument_list|(
name|q_func
argument_list|()
argument_list|,
name|filename
argument_list|)
block|; }
DECL|function|selectedFiles_sys
specifier|inline
name|QStringList
name|QFileDialogPrivate
operator|::
name|selectedFiles_sys
argument_list|()
specifier|const
block|{
return|return
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileDialogSelectedFiles
argument_list|(
name|q_func
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setFilter_sys
specifier|inline
name|void
name|QFileDialogPrivate
operator|::
name|setFilter_sys
argument_list|()
block|{
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileDialogSetFilter
argument_list|(
name|q_func
argument_list|()
argument_list|)
block|; }
DECL|function|setNameFilters_sys
specifier|inline
name|void
name|QFileDialogPrivate
operator|::
name|setNameFilters_sys
argument_list|(
argument|const QStringList&filters
argument_list|)
block|{
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileDialogSetNameFilters
argument_list|(
name|q_func
argument_list|()
argument_list|,
name|filters
argument_list|)
block|; }
DECL|function|selectNameFilter_sys
specifier|inline
name|void
name|QFileDialogPrivate
operator|::
name|selectNameFilter_sys
argument_list|(
argument|const QString&filter
argument_list|)
block|{
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileDialogSelectNameFilter
argument_list|(
name|q_func
argument_list|()
argument_list|,
name|filter
argument_list|)
block|; }
DECL|function|selectedNameFilter_sys
specifier|inline
name|QString
name|QFileDialogPrivate
operator|::
name|selectedNameFilter_sys
argument_list|()
specifier|const
block|{
return|return
name|qt_guiPlatformPlugin
argument_list|()
operator|->
name|fileDialogSelectedNameFilter
argument_list|(
name|q_func
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FILEDIALOG
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILEDIALOG_P_H
end_comment
end_unit
