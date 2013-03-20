begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSERROR_H
end_ifndef
begin_define
DECL|macro|QDBUSERROR_H
define|#
directive|define
name|QDBUSERROR_H
end_define
begin_include
include|#
directive|include
file|<QtDBus/qdbusmacros.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_struct_decl
struct_decl|struct
name|DBusError
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusMessage
name|class
name|QDBusMessage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_DBUS_EXPORT
name|QDBusError
block|{
name|public
label|:
enum|enum
name|ErrorType
block|{
name|NoError
init|=
literal|0
block|,
name|Other
init|=
literal|1
block|,
name|Failed
block|,
name|NoMemory
block|,
name|ServiceUnknown
block|,
name|NoReply
block|,
name|BadAddress
block|,
name|NotSupported
block|,
name|LimitsExceeded
block|,
name|AccessDenied
block|,
name|NoServer
block|,
name|Timeout
block|,
name|NoNetwork
block|,
name|AddressInUse
block|,
name|Disconnected
block|,
name|InvalidArgs
block|,
name|UnknownMethod
block|,
name|TimedOut
block|,
name|InvalidSignature
block|,
name|UnknownInterface
block|,
name|UnknownObject
block|,
name|UnknownProperty
block|,
name|PropertyReadOnly
block|,
name|InternalError
block|,
name|InvalidService
block|,
name|InvalidObjectPath
block|,
name|InvalidInterface
block|,
name|InvalidMember
block|,
ifndef|#
directive|ifndef
name|Q_QDOC
comment|// don't use this one!
name|LastErrorType
init|=
name|InvalidMember
endif|#
directive|endif
block|}
enum|;
name|QDBusError
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|explicit
name|QDBusError
parameter_list|(
specifier|const
name|DBusError
modifier|*
name|error
parameter_list|)
function_decl|;
comment|/*implicit*/
name|QDBusError
argument_list|(
specifier|const
name|QDBusMessage
operator|&
name|msg
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QDBusError
argument_list|(
argument|ErrorType error
argument_list|,
argument|const QString&message
argument_list|)
empty_stmt|;
name|QDBusError
argument_list|(
specifier|const
name|QDBusError
operator|&
name|other
argument_list|)
expr_stmt|;
name|QDBusError
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusError
operator|&
name|other
operator|)
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
name|QDBusError
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDBusMessage
operator|&
name|msg
operator|)
decl_stmt|;
endif|#
directive|endif
name|ErrorType
name|type
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|message
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QString
name|errorString
parameter_list|(
name|ErrorType
name|error
parameter_list|)
function_decl|;
name|private
label|:
name|ErrorType
name|code
decl_stmt|;
name|QString
name|msg
decl_stmt|;
name|QString
name|nm
decl_stmt|;
name|void
modifier|*
name|unused
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_DBUS_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QDBusError
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QDBusError
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
