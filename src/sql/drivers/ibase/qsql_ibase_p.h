begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQL_IBASE_H
end_ifndef
begin_define
DECL|macro|QSQL_IBASE_H
define|#
directive|define
name|QSQL_IBASE_H
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
begin_include
include|#
directive|include
file|<ibase.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_PLUGIN
end_ifdef
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_IBASE
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_IBASE
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_EXPORT_SQLDRIVER_IBASE
define|#
directive|define
name|Q_EXPORT_SQLDRIVER_IBASE
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
DECL|variable|QIBaseDriverPrivate
name|class
name|QIBaseDriverPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_EXPORT_SQLDRIVER_IBASE
name|QIBaseDriver
range|:
name|public
name|QSqlDriver
block|{
name|friend
name|class
name|QIBaseResultPrivate
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QIBaseDriver
argument_list|)
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QIBaseDriver
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QIBaseDriver
argument_list|(
argument|isc_db_handle connection
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QIBaseDriver
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
argument_list|)
block|{
return|return
name|open
argument_list|(
name|db
argument_list|,
name|user
argument_list|,
name|password
argument_list|,
name|host
argument_list|,
name|port
argument_list|,
name|QString
argument_list|()
argument_list|)
return|;
block|}
name|void
name|close
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QSqlResult
operator|*
name|createResult
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
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
name|QStringList
name|tables
argument_list|(
argument|QSql::TableType
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSqlRecord
name|record
argument_list|(
argument|const QString& tablename
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSqlIndex
name|primaryIndex
argument_list|(
argument|const QString&table
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
name|bool
name|subscribeToNotification
argument_list|(
argument|const QString&name
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|unsubscribeFromNotification
argument_list|(
argument|const QString&name
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QStringList
name|subscribedToNotifications
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|qHandleEventNotification
argument_list|(
name|void
operator|*
name|updatedResultBuffer
argument_list|)
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
comment|// QSQL_IBASE_H
end_comment
end_unit
