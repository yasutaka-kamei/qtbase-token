begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILESYSTEMENTRY_P_H_INCLUDED
end_ifndef
begin_define
DECL|macro|QFILESYSTEMENTRY_P_H_INCLUDED
define|#
directive|define
name|QFILESYSTEMENTRY_P_H_INCLUDED
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
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
end_if
begin_define
DECL|macro|QFILESYSTEMENTRY_NATIVE_PATH_IS_UTF16
define|#
directive|define
name|QFILESYSTEMENTRY_NATIVE_PATH_IS_UTF16
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QFileSystemEntry
block|{
name|public
label|:
ifndef|#
directive|ifndef
name|QFILESYSTEMENTRY_NATIVE_PATH_IS_UTF16
typedef|typedef
name|QByteArray
name|NativePath
typedef|;
else|#
directive|else
typedef|typedef
name|QString
name|NativePath
typedef|;
endif|#
directive|endif
struct|struct
name|FromNativePath
block|{}
struct|;
struct|struct
name|FromInternalPath
block|{}
struct|;
name|QFileSystemEntry
argument_list|()
expr_stmt|;
name|explicit
name|QFileSystemEntry
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
function_decl|;
name|QFileSystemEntry
argument_list|(
argument|const QString&filePath
argument_list|,
argument|FromInternalPath dummy
argument_list|)
empty_stmt|;
name|QFileSystemEntry
argument_list|(
argument|const NativePath&nativeFilePath
argument_list|,
argument|FromNativePath dummy
argument_list|)
empty_stmt|;
name|QFileSystemEntry
argument_list|(
specifier|const
name|QString
operator|&
name|filePath
argument_list|,
specifier|const
name|NativePath
operator|&
name|nativeFilePath
argument_list|)
expr_stmt|;
name|QString
name|filePath
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|fileName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|path
argument_list|()
specifier|const
expr_stmt|;
name|NativePath
name|nativeFilePath
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|baseName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|completeBaseName
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|suffix
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|completeSuffix
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isAbsolute
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isRelative
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isClean
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|bool
name|isDriveRoot
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|bool
name|isRoot
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clear
parameter_list|()
block|{
operator|*
name|this
operator|=
name|QFileSystemEntry
argument_list|()
expr_stmt|;
block|}
name|private
label|:
comment|// creates the QString version out of the bytearray version
name|void
name|resolveFilePath
argument_list|()
specifier|const
expr_stmt|;
comment|// creates the bytearray version out of the QString version
name|void
name|resolveNativeFilePath
argument_list|()
specifier|const
expr_stmt|;
comment|// resolves the separator
name|void
name|findLastSeparator
argument_list|()
specifier|const
expr_stmt|;
comment|// resolves the dots and the separator
name|void
name|findFileNameSeparators
argument_list|()
specifier|const
expr_stmt|;
name|mutable
name|QString
name|m_filePath
decl_stmt|;
comment|// always has slashes as separator
name|mutable
name|NativePath
name|m_nativeFilePath
decl_stmt|;
comment|// native encoding and separators
name|mutable
name|qint16
name|m_lastSeparator
decl_stmt|;
comment|// index in m_filePath of last separator
name|mutable
name|qint16
name|m_firstDotInFileName
decl_stmt|;
comment|// index after m_filePath for first dot (.)
name|mutable
name|qint16
name|m_lastDotInFileName
decl_stmt|;
comment|// index after m_firstDotInFileName for last dot (.)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// include guard
end_comment
end_unit
