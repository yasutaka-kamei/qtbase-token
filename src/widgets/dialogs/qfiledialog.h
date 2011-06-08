begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILEDIALOG_H
end_ifndef
begin_define
DECL|macro|QFILEDIALOG_H
define|#
directive|define
name|QFILEDIALOG_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qdialog.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_FILEDIALOG
name|class
name|QModelIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QItemSelection
name|class
name|QItemSelection
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QFileDialogArgs
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QFileIconProvider
name|class
name|QFileIconProvider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileDialogPrivate
name|class
name|QFileDialogPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractItemDelegate
name|class
name|QAbstractItemDelegate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractProxyModel
name|class
name|QAbstractProxyModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUrl
name|class
name|QUrl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QFileDialog
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|ViewMode FileMode AcceptMode Option
argument_list|)
name|Q_FLAGS
argument_list|(
argument|Options
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|ViewMode viewMode READ viewMode WRITE setViewMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|FileMode fileMode READ fileMode WRITE setFileMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|AcceptMode acceptMode READ acceptMode WRITE setAcceptMode
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool readOnly READ isReadOnly WRITE setReadOnly DESIGNABLE false
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool resolveSymlinks READ resolveSymlinks WRITE setResolveSymlinks DESIGNABLE false
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool confirmOverwrite READ confirmOverwrite WRITE setConfirmOverwrite DESIGNABLE false
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString defaultSuffix READ defaultSuffix WRITE setDefaultSuffix
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool nameFilterDetailsVisible READ isNameFilterDetailsVisible                WRITE setNameFilterDetailsVisible DESIGNABLE false
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Options options READ options WRITE setOptions
argument_list|)
name|public
operator|:
expr|enum
name|ViewMode
block|{
name|Detail
block|,
name|List
block|}
block|;     enum
name|FileMode
block|{
name|AnyFile
block|,
name|ExistingFile
block|,
name|Directory
block|,
name|ExistingFiles
block|,
name|DirectoryOnly
block|}
block|;     enum
name|AcceptMode
block|{
name|AcceptOpen
block|,
name|AcceptSave
block|}
block|;     enum
name|DialogLabel
block|{
name|LookIn
block|,
name|FileName
block|,
name|FileType
block|,
name|Accept
block|,
name|Reject
block|}
block|;
comment|// ### Rename to FileDialogOption and FileDialogOptions for Qt 5.0
block|enum
name|Option
block|{
name|ShowDirsOnly
operator|=
literal|0x00000001
block|,
name|DontResolveSymlinks
operator|=
literal|0x00000002
block|,
name|DontConfirmOverwrite
operator|=
literal|0x00000004
block|,
name|DontUseSheet
operator|=
literal|0x00000008
block|,
name|DontUseNativeDialog
operator|=
literal|0x00000010
block|,
name|ReadOnly
operator|=
literal|0x00000020
block|,
name|HideNameFilterDetails
operator|=
literal|0x00000040
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Options
argument_list|,
argument|Option
argument_list|)
name|QFileDialog
argument_list|(
argument|QWidget *parent
argument_list|,
argument|Qt::WindowFlags f
argument_list|)
block|;
name|explicit
name|QFileDialog
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|,
specifier|const
name|QString
operator|&
name|caption
operator|=
name|QString
argument_list|()
argument_list|,
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
name|filter
operator|=
name|QString
argument_list|()
argument_list|)
block|;
operator|~
name|QFileDialog
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
specifier|inline
name|void
name|setDirectory
argument_list|(
specifier|const
name|QDir
operator|&
name|directory
argument_list|)
block|;
name|QDir
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
ifdef|#
directive|ifdef
name|QT_DEPRECATED
name|QT_DEPRECATED
name|void
name|setFilter
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
block|;
name|QT_DEPRECATED
name|void
name|setFilters
argument_list|(
specifier|const
name|QStringList
operator|&
name|filters
argument_list|)
block|;
name|QT_DEPRECATED
name|QStringList
name|filters
argument_list|()
specifier|const
block|;
name|QT_DEPRECATED
name|void
name|selectFilter
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
block|;
name|QT_DEPRECATED
name|QString
name|selectedFilter
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|setNameFilterDetailsVisible
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|isNameFilterDetailsVisible
argument_list|()
specifier|const
block|;
name|void
name|setNameFilter
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
block|;
name|void
name|setNameFilters
argument_list|(
specifier|const
name|QStringList
operator|&
name|filters
argument_list|)
block|;
name|QStringList
name|nameFilters
argument_list|()
specifier|const
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
name|QDir
operator|::
name|Filters
name|filter
argument_list|()
specifier|const
block|;
name|void
name|setFilter
argument_list|(
argument|QDir::Filters filters
argument_list|)
block|;
name|void
name|setViewMode
argument_list|(
argument|ViewMode mode
argument_list|)
block|;
name|ViewMode
name|viewMode
argument_list|()
specifier|const
block|;
name|void
name|setFileMode
argument_list|(
argument|FileMode mode
argument_list|)
block|;
name|FileMode
name|fileMode
argument_list|()
specifier|const
block|;
name|void
name|setAcceptMode
argument_list|(
argument|AcceptMode mode
argument_list|)
block|;
name|AcceptMode
name|acceptMode
argument_list|()
specifier|const
block|;
name|void
name|setReadOnly
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|isReadOnly
argument_list|()
specifier|const
block|;
name|void
name|setResolveSymlinks
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|resolveSymlinks
argument_list|()
specifier|const
block|;
name|void
name|setSidebarUrls
argument_list|(
specifier|const
name|QList
operator|<
name|QUrl
operator|>
operator|&
name|urls
argument_list|)
block|;
name|QList
operator|<
name|QUrl
operator|>
name|sidebarUrls
argument_list|()
specifier|const
block|;
name|QByteArray
name|saveState
argument_list|()
specifier|const
block|;
name|bool
name|restoreState
argument_list|(
specifier|const
name|QByteArray
operator|&
name|state
argument_list|)
block|;
name|void
name|setConfirmOverwrite
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|confirmOverwrite
argument_list|()
specifier|const
block|;
name|void
name|setDefaultSuffix
argument_list|(
specifier|const
name|QString
operator|&
name|suffix
argument_list|)
block|;
name|QString
name|defaultSuffix
argument_list|()
specifier|const
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
block|;
name|void
name|setItemDelegate
argument_list|(
name|QAbstractItemDelegate
operator|*
name|delegate
argument_list|)
block|;
name|QAbstractItemDelegate
operator|*
name|itemDelegate
argument_list|()
specifier|const
block|;
name|void
name|setIconProvider
argument_list|(
name|QFileIconProvider
operator|*
name|provider
argument_list|)
block|;
name|QFileIconProvider
operator|*
name|iconProvider
argument_list|()
specifier|const
block|;
name|void
name|setLabelText
argument_list|(
argument|DialogLabel label
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|QString
name|labelText
argument_list|(
argument|DialogLabel label
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_PROXYMODEL
name|void
name|setProxyModel
argument_list|(
name|QAbstractProxyModel
operator|*
name|model
argument_list|)
block|;
name|QAbstractProxyModel
operator|*
name|proxyModel
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|setOption
argument_list|(
argument|Option option
argument_list|,
argument|bool on = true
argument_list|)
block|;
name|bool
name|testOption
argument_list|(
argument|Option option
argument_list|)
specifier|const
block|;
name|void
name|setOptions
argument_list|(
argument|Options options
argument_list|)
block|;
name|Options
name|options
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|Q_NO_USING_KEYWORD
ifndef|#
directive|ifndef
name|Q_QDOC
name|void
name|open
argument_list|()
block|{
name|QDialog
operator|::
name|open
argument_list|()
block|; }
endif|#
directive|endif
else|#
directive|else
name|using
name|QDialog
operator|::
name|open
block|;
endif|#
directive|endif
name|void
name|open
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
specifier|const
name|char
operator|*
name|member
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|fileSelected
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|void
name|filesSelected
argument_list|(
specifier|const
name|QStringList
operator|&
name|files
argument_list|)
block|;
name|void
name|currentChanged
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
name|void
name|directoryEntered
argument_list|(
specifier|const
name|QString
operator|&
name|directory
argument_list|)
block|;
name|void
name|filterSelected
argument_list|(
specifier|const
name|QString
operator|&
name|filter
argument_list|)
block|;
name|public
operator|:
ifdef|#
directive|ifdef
name|QT3_SUPPORT
typedef|typedef
name|FileMode
name|Mode
typedef|;
specifier|inline
name|QT3_SUPPORT
name|void
name|setMode
argument_list|(
argument|FileMode m
argument_list|)
block|{
name|setFileMode
argument_list|(
name|m
argument_list|)
block|; }
specifier|inline
name|QT3_SUPPORT
name|FileMode
name|mode
argument_list|()
specifier|const
block|{
return|return
name|fileMode
argument_list|()
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setDir
parameter_list|(
specifier|const
name|QString
modifier|&
name|directory
parameter_list|)
block|{
name|setDirectory
argument_list|(
name|directory
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|QT3_SUPPORT
name|void
name|setDir
parameter_list|(
specifier|const
name|QDir
modifier|&
name|directory
parameter_list|)
block|{
name|setDirectory
argument_list|(
name|directory
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|QT3_SUPPORT
name|QString
name|selectedFile
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|QString
name|getOpenFileName
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|QString
modifier|&
name|caption
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|dir
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|filter
init|=
name|QString
argument_list|()
parameter_list|,
name|QString
modifier|*
name|selectedFilter
init|=
literal|0
parameter_list|,
name|Options
name|options
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|getSaveFileName
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|QString
modifier|&
name|caption
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|dir
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|filter
init|=
name|QString
argument_list|()
parameter_list|,
name|QString
modifier|*
name|selectedFilter
init|=
literal|0
parameter_list|,
name|Options
name|options
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|getExistingDirectory
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|QString
modifier|&
name|caption
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|dir
init|=
name|QString
argument_list|()
parameter_list|,
name|Options
name|options
init|=
name|ShowDirsOnly
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QStringList
name|getOpenFileNames
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|QString
modifier|&
name|caption
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|dir
init|=
name|QString
argument_list|()
parameter_list|,
specifier|const
name|QString
modifier|&
name|filter
init|=
name|QString
argument_list|()
parameter_list|,
name|QString
modifier|*
name|selectedFilter
init|=
literal|0
parameter_list|,
name|Options
name|options
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|QT3_SUPPORT
end_ifdef
begin_function
specifier|inline
specifier|static
name|QString
name|QT3_SUPPORT
name|getOpenFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|dir
parameter_list|,
specifier|const
name|QString
modifier|&
name|filter
init|=
name|QString
argument_list|()
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
name|name
init|=
literal|0
parameter_list|,
specifier|const
name|QString
modifier|&
name|caption
init|=
name|QString
argument_list|()
parameter_list|,
name|QString
modifier|*
name|selectedFilter
init|=
literal|0
parameter_list|,
name|bool
name|resolveSymlinks
init|=
name|true
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|getOpenFileName
argument_list|(
name|parent
argument_list|,
name|caption
argument_list|,
name|dir
argument_list|,
name|filter
argument_list|,
name|selectedFilter
argument_list|,
name|resolveSymlinks
condition|?
name|Option
argument_list|(
literal|0
argument_list|)
else|:
name|DontResolveSymlinks
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
specifier|static
name|QString
name|QT3_SUPPORT
name|getSaveFileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|dir
parameter_list|,
specifier|const
name|QString
modifier|&
name|filter
init|=
name|QString
argument_list|()
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
name|name
init|=
literal|0
parameter_list|,
specifier|const
name|QString
modifier|&
name|caption
init|=
name|QString
argument_list|()
parameter_list|,
name|QString
modifier|*
name|selectedFilter
init|=
literal|0
parameter_list|,
name|bool
name|resolveSymlinks
init|=
name|true
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|getSaveFileName
argument_list|(
name|parent
argument_list|,
name|caption
argument_list|,
name|dir
argument_list|,
name|filter
argument_list|,
name|selectedFilter
argument_list|,
name|resolveSymlinks
condition|?
name|Option
argument_list|(
literal|0
argument_list|)
else|:
name|DontResolveSymlinks
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
specifier|static
name|QString
name|QT3_SUPPORT
name|getExistingDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
name|dir
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
name|name
init|=
literal|0
parameter_list|,
specifier|const
name|QString
modifier|&
name|caption
init|=
name|QString
argument_list|()
parameter_list|,
name|bool
name|dirOnly
init|=
name|true
parameter_list|,
name|bool
name|resolveSymlinks
init|=
name|true
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|getExistingDirectory
argument_list|(
name|parent
argument_list|,
name|caption
argument_list|,
name|dir
argument_list|,
name|Options
argument_list|(
operator|(
name|resolveSymlinks
condition|?
name|Option
argument_list|(
literal|0
argument_list|)
else|:
name|DontResolveSymlinks
operator|)
operator||
operator|(
name|dirOnly
condition|?
name|ShowDirsOnly
else|:
name|Option
argument_list|(
literal|0
argument_list|)
operator|)
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
specifier|static
name|QStringList
name|QT3_SUPPORT
name|getOpenFileNames
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|,
specifier|const
name|QString
modifier|&
name|dir
init|=
name|QString
argument_list|()
parameter_list|,
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|,
specifier|const
name|char
modifier|*
name|name
init|=
literal|0
parameter_list|,
specifier|const
name|QString
modifier|&
name|caption
init|=
name|QString
argument_list|()
parameter_list|,
name|QString
modifier|*
name|selectedFilter
init|=
literal|0
parameter_list|,
name|bool
name|resolveSymlinks
init|=
name|true
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
name|getOpenFileNames
argument_list|(
name|parent
argument_list|,
name|caption
argument_list|,
name|dir
argument_list|,
name|filter
argument_list|,
name|selectedFilter
argument_list|,
name|resolveSymlinks
condition|?
name|Option
argument_list|(
literal|0
argument_list|)
else|:
name|DontResolveSymlinks
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT3_SUPPORT
end_comment
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|QFileDialog
argument_list|(
specifier|const
name|QFileDialogArgs
operator|&
name|args
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|done
parameter_list|(
name|int
name|result
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|accept
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|changeEvent
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFileDialog
argument_list|)
end_macro
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QFileDialog
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_pathChanged(const QString&)
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_navigateBackward()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_navigateForward()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_navigateToParent()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_createDirectory()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_showListView()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_showDetailsView()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_showContextMenu(const QPoint&)
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_renameCurrent()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_deleteCurrent()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_showHidden()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_updateOkButton()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_currentChanged(const QModelIndex&index)
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_enterDirectory(const QModelIndex&index)
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_goToDirectory(const QString&path)
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_useNameFilter(int index)
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_selectionChanged()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_goToUrl(const QUrl&url)
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_goHome()
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_showHeader(QAction *)
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_autoCompleteFileName(const QString&text)
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_rowsInserted(const QModelIndex& parent)
argument_list|)
end_macro
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_fileRenamed(const QString&path,                 const QString oldName, const QString newName)
argument_list|)
end_macro
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
end_if
begin_macro
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_macRunNativeAppModalPanel()
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
unit|};
DECL|function|setDirectory
specifier|inline
name|void
name|QFileDialog
operator|::
name|setDirectory
argument_list|(
argument|const QDir&adirectory
argument_list|)
block|{
name|setDirectory
argument_list|(
name|adirectory
operator|.
name|absolutePath
argument_list|()
argument_list|)
block|; }
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QFileDialog::Options
argument_list|)
endif|#
directive|endif
comment|// QT_NO_FILEDIALOG
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILEDIALOG_H
end_comment
end_unit
