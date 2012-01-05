begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIR_H
end_ifndef
begin_define
DECL|macro|QDIR_H
define|#
directive|define
name|QDIR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|QDirPrivate
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QDir
decl_stmt|{ public:     enum Filter
block|{
name|Dirs
operator|=
literal|0x001
operator|,
name|Files
operator|=
literal|0x002
operator|,
name|Drives
operator|=
literal|0x004
operator|,
name|NoSymLinks
operator|=
literal|0x008
operator|,
name|AllEntries
operator|=
name|Dirs
operator||
name|Files
operator||
name|Drives
operator|,
name|TypeMask
operator|=
literal|0x00f
operator|,
name|Readable
operator|=
literal|0x010
operator|,
name|Writable
operator|=
literal|0x020
operator|,
name|Executable
operator|=
literal|0x040
operator|,
name|PermissionMask
operator|=
literal|0x070
operator|,
name|Modified
operator|=
literal|0x080
operator|,
name|Hidden
operator|=
literal|0x100
operator|,
name|System
operator|=
literal|0x200
operator|,
name|AccessMask
operator|=
literal|0x3F0
operator|,
name|AllDirs
operator|=
literal|0x400
operator|,
name|CaseSensitive
operator|=
literal|0x800
operator|,
name|NoDotAndDotDot
operator|=
literal|0x1000
operator|,
comment|// ### Qt5 NoDotAndDotDot = NoDot|NoDotDot
name|NoDot
operator|=
literal|0x2000
operator|,
name|NoDotDot
operator|=
literal|0x4000
operator|,
name|NoFilter
operator|=
operator|-
literal|1
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_FLAGS
argument_list|(
name|Filters
argument_list|,
name|Filter
argument_list|)
expr|enum
name|SortFlag
block|{
name|Name
operator|=
literal|0x00
block|,
name|Time
operator|=
literal|0x01
block|,
name|Size
operator|=
literal|0x02
block|,
name|Unsorted
operator|=
literal|0x03
block|,
name|SortByMask
operator|=
literal|0x03
block|,
name|DirsFirst
operator|=
literal|0x04
block|,
name|Reversed
operator|=
literal|0x08
block|,
name|IgnoreCase
operator|=
literal|0x10
block|,
name|DirsLast
operator|=
literal|0x20
block|,
name|LocaleAware
operator|=
literal|0x40
block|,
name|Type
operator|=
literal|0x80
block|,
name|NoSort
operator|=
operator|-
literal|1
block|}
expr_stmt|;
end_expr_stmt
begin_macro
name|Q_DECLARE_FLAGS
argument_list|(
argument|SortFlags
argument_list|,
argument|SortFlag
argument_list|)
end_macro
begin_expr_stmt
name|QDir
argument_list|(
specifier|const
name|QDir
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDir
argument_list|(
specifier|const
name|QString
operator|&
name|path
operator|=
name|QString
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|QDir
argument_list|(
argument|const QString&path
argument_list|,
argument|const QString&nameFilter
argument_list|,
argument|SortFlags sort = SortFlags(Name | IgnoreCase)
argument_list|,
argument|Filters filter = AllEntries
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
operator|~
name|QDir
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QDir
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDir
operator|&
operator|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDir
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QString
operator|&
name|path
operator|)
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_decl_stmt
specifier|inline
name|QDir
modifier|&
name|operator
init|=
operator|(
name|QDir
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d_ptr
argument_list|,
name|other
operator|.
name|d_ptr
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|void
name|setPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|path
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|absolutePath
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QString
name|canonicalPath
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|void
name|addResourceSearchPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|setSearchPaths
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|searchPaths
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|addSearchPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QStringList
name|searchPaths
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QString
name|dirName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QString
name|filePath
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|absoluteFilePath
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|relativeFilePath
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_DEPRECATED
end_ifdef
begin_function_decl
name|QT_DEPRECATED
specifier|static
name|QString
name|convertSeparators
parameter_list|(
specifier|const
name|QString
modifier|&
name|pathName
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|QString
name|toNativeSeparators
parameter_list|(
specifier|const
name|QString
modifier|&
name|pathName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|fromNativeSeparators
parameter_list|(
specifier|const
name|QString
modifier|&
name|pathName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|cd
parameter_list|(
specifier|const
name|QString
modifier|&
name|dirName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|cdUp
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|QStringList
name|nameFilters
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setNameFilters
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|nameFilters
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|Filters
name|filter
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setFilter
parameter_list|(
name|Filters
name|filter
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|SortFlags
name|sorting
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setSorting
parameter_list|(
name|SortFlags
name|sort
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|uint
name|count
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QString
name|operator
index|[]
argument_list|(
name|int
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|QStringList
name|nameFiltersFromString
parameter_list|(
specifier|const
name|QString
modifier|&
name|nameFilter
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QStringList
name|entryList
argument_list|(
name|Filters
name|filters
operator|=
name|NoFilter
argument_list|,
name|SortFlags
name|sort
operator|=
name|NoSort
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStringList
name|entryList
argument_list|(
specifier|const
name|QStringList
operator|&
name|nameFilters
argument_list|,
name|Filters
name|filters
operator|=
name|NoFilter
argument_list|,
name|SortFlags
name|sort
operator|=
name|NoSort
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFileInfoList
name|entryInfoList
argument_list|(
name|Filters
name|filters
operator|=
name|NoFilter
argument_list|,
name|SortFlags
name|sort
operator|=
name|NoSort
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFileInfoList
name|entryInfoList
argument_list|(
specifier|const
name|QStringList
operator|&
name|nameFilters
argument_list|,
name|Filters
name|filters
operator|=
name|NoFilter
argument_list|,
name|SortFlags
name|sort
operator|=
name|NoSort
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|mkdir
argument_list|(
specifier|const
name|QString
operator|&
name|dirName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|rmdir
argument_list|(
specifier|const
name|QString
operator|&
name|dirName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|mkpath
argument_list|(
specifier|const
name|QString
operator|&
name|dirPath
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|rmpath
argument_list|(
specifier|const
name|QString
operator|&
name|dirPath
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|bool
name|removeRecursively
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isReadable
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|exists
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|isRoot
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
specifier|static
name|bool
name|isRelativePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
specifier|static
name|bool
name|isAbsolutePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
return|return
operator|!
name|isRelativePath
argument_list|(
name|path
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|bool
name|isRelative
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isAbsolute
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isRelative
argument_list|()
return|;
block|}
end_expr_stmt
begin_function_decl
name|bool
name|makeAbsolute
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QDir
operator|&
name|dir
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QDir
operator|&
name|dir
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|dir
operator|)
return|;
block|}
end_expr_stmt
begin_function_decl
name|bool
name|remove
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|rename
parameter_list|(
specifier|const
name|QString
modifier|&
name|oldName
parameter_list|,
specifier|const
name|QString
modifier|&
name|newName
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|exists
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|QFileInfoList
name|drives
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QChar
name|separator
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|setCurrent
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|static
specifier|inline
name|QDir
name|current
parameter_list|()
block|{
return|return
name|QDir
argument_list|(
name|currentPath
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function_decl
specifier|static
name|QString
name|currentPath
parameter_list|()
function_decl|;
end_function_decl
begin_function
specifier|static
specifier|inline
name|QDir
name|home
parameter_list|()
block|{
return|return
name|QDir
argument_list|(
name|homePath
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function_decl
specifier|static
name|QString
name|homePath
parameter_list|()
function_decl|;
end_function_decl
begin_function
specifier|static
specifier|inline
name|QDir
name|root
parameter_list|()
block|{
return|return
name|QDir
argument_list|(
name|rootPath
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function_decl
specifier|static
name|QString
name|rootPath
parameter_list|()
function_decl|;
end_function_decl
begin_function
specifier|static
specifier|inline
name|QDir
name|temp
parameter_list|()
block|{
return|return
name|QDir
argument_list|(
name|tempPath
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function_decl
specifier|static
name|QString
name|tempPath
parameter_list|()
function_decl|;
end_function_decl
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_function_decl
specifier|static
name|bool
name|match
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|filters
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|match
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
specifier|static
name|QString
name|cleanPath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|void
name|refresh
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_function_decl
name|explicit
name|QDir
parameter_list|(
name|QDirPrivate
modifier|&
name|d
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QSharedDataPointer
operator|<
name|QDirPrivate
operator|>
name|d_ptr
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_comment
comment|// Q_DECLARE_PRIVATE equivalent for shared data pointers
end_comment
begin_function_decl
name|QDirPrivate
modifier|*
name|d_func
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
specifier|const
name|QDirPrivate
operator|*
name|d_func
argument_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|.
name|constData
argument_list|()
return|;
block|}
end_expr_stmt
begin_macro
unit|};
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QDir::Filters
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QDir::SortFlags
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_decl_stmt
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
name|QDir
operator|::
name|Filters
name|filters
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QDir
operator|&
name|dir
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDIR_H
end_comment
end_unit
