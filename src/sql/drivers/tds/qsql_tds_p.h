begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQL_TDS_H
end_ifndef
begin_define
DECL|macro|QSQL_TDS_H
define|#
directive|define
name|QSQL_TDS_H
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
file|<QtSql/qsqldriver.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN32
end_ifdef
begin_define
DECL|macro|WIN32_LEAN_AND_MEAN
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|Q_USE_SYBASE
end_ifndef
begin_define
DECL|macro|DBNTWIN32
define|#
directive|define
name|DBNTWIN32
end_define
begin_comment
DECL|macro|DBNTWIN32
comment|// indicates 32bit windows dblib
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<winsock2.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<sqlfront.h>
end_include
begin_include
include|#
directive|include
file|<sqldb.h>
end_include
begin_define
DECL|macro|CS_PUBLIC
define|#
directive|define
name|CS_PUBLIC
end_define
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<sybfront.h>
end_include
begin_include
include|#
directive|include
file|<sybdb.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//Q_OS_WIN32
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QT_PLUGIN
end_ifdef
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_TDS
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_TDS
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_TDS
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_TDS
value|Q_SQL_EXPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSqlResult
name|class
name|QSqlResult
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTDSDriverPrivate
name|class
name|QTDSDriverPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_EXPORT_SQLDRIVER_TDS
name|QTDSDriver
range|:
name|public
name|QSqlDriver
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTDSDriver
argument_list|)
name|Q_OBJECT
name|friend
name|class
name|QTDSResultPrivate
block|;
name|public
operator|:
name|explicit
name|QTDSDriver
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QTDSDriver
argument_list|(
name|LOGINREC
operator|*
name|rec
argument_list|,
specifier|const
name|QString
operator|&
name|host
argument_list|,
specifier|const
name|QString
operator|&
name|db
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QTDSDriver
argument_list|()
block|;
name|bool
name|hasFeature
argument_list|(
argument|DriverFeature f
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|open
argument_list|(
argument|const QString&db
argument_list|,
argument|const QString&user
argument_list|,
argument|const QString&password
argument_list|,
argument|const QString&host
argument_list|,
argument|int port
argument_list|,
argument|const QString&connOpts
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|close
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|tables
argument_list|(
argument|QSql::TableType
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSqlResult
operator|*
name|createResult
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSqlRecord
name|record
argument_list|(
argument|const QString&tablename
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSqlIndex
name|primaryIndex
argument_list|(
argument|const QString&tablename
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|formatValue
argument_list|(
argument|const QSqlField&field
argument_list|,
argument|bool trimStrings
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QVariant
name|handle
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|escapeIdentifier
argument_list|(
argument|const QString&identifier
argument_list|,
argument|IdentifierType type
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|bool
name|beginTransaction
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|commitTransaction
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|rollbackTransaction
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|init
argument_list|()
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
comment|// QSQL_TDS_H
end_comment
end_unit
