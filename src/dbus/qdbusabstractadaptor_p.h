begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
comment|// This file is not part of the public API.  This header file may
end_comment
begin_comment
comment|// change from version to version without notice, or even be
end_comment
begin_comment
comment|// removed.
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
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUSABSTRACTADAPTORPRIVATE_H
end_ifndef
begin_define
DECL|macro|QDBUSABSTRACTADAPTORPRIVATE_H
define|#
directive|define
name|QDBUSABSTRACTADAPTORPRIVATE_H
end_define
begin_include
include|#
directive|include
file|<qdbusabstractadaptor.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qreadwritelock.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_define
DECL|macro|QCLASSINFO_DBUS_INTERFACE
define|#
directive|define
name|QCLASSINFO_DBUS_INTERFACE
value|"D-Bus Interface"
end_define
begin_define
DECL|macro|QCLASSINFO_DBUS_INTROSPECTION
define|#
directive|define
name|QCLASSINFO_DBUS_INTROSPECTION
value|"D-Bus Introspection"
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QDBusAbstractAdaptor
name|class
name|QDBusAbstractAdaptor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusAdaptorConnector
name|class
name|QDBusAdaptorConnector
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusAdaptorManager
name|class
name|QDBusAdaptorManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDBusConnectionPrivate
name|class
name|QDBusConnectionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusAbstractAdaptorPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QDBusAbstractAdaptor
argument_list|)
name|public
operator|:
name|QDBusAbstractAdaptorPrivate
argument_list|()
operator|:
name|autoRelaySignals
argument_list|(
argument|false
argument_list|)
block|{}
name|QString
name|xml
block|;
name|bool
name|autoRelaySignals
block|;
specifier|static
name|QString
name|retrieveIntrospectionXml
argument_list|(
name|QDBusAbstractAdaptor
operator|*
name|adaptor
argument_list|)
block|;
specifier|static
name|void
name|saveIntrospectionXml
argument_list|(
name|QDBusAbstractAdaptor
operator|*
name|adaptor
argument_list|,
specifier|const
name|QString
operator|&
name|xml
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDBusAdaptorConnector
range|:
name|public
name|QObject
block|{
name|Q_OBJECT_FAKE
name|public
operator|:
comment|// typedefs
expr|struct
name|AdaptorData
block|{
specifier|const
name|char
operator|*
name|interface
block|;
name|QDBusAbstractAdaptor
operator|*
name|adaptor
block|;
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|AdaptorData
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|QByteArray
argument_list|(
name|interface
argument_list|)
operator|<
name|other
operator|.
name|interface
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QString
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|QLatin1String
argument_list|(
name|interface
argument_list|)
operator|<
name|other
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QByteArray
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|interface
operator|<
name|other
return|;
block|}
expr|}
block|;
typedef|typedef
name|QVector
operator|<
name|AdaptorData
operator|>
name|AdaptorMap
expr_stmt|;
name|public
operator|:
comment|// methods
name|explicit
name|QDBusAdaptorConnector
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
operator|~
name|QDBusAdaptorConnector
argument_list|()
block|;
name|void
name|addAdaptor
argument_list|(
name|QDBusAbstractAdaptor
operator|*
name|adaptor
argument_list|)
block|;
name|void
name|connectAllSignals
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|void
name|disconnectAllSignals
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|void
name|relay
argument_list|(
argument|QObject *sender
argument_list|,
argument|int id
argument_list|,
argument|void **
argument_list|)
block|;
comment|//public slots:
name|void
name|relaySlot
argument_list|(
name|void
operator|*
operator|*
argument_list|)
block|;
name|void
name|polish
argument_list|()
block|;
name|protected
operator|:
comment|//signals:
name|void
name|relaySignal
argument_list|(
argument|QObject *obj
argument_list|,
argument|const QMetaObject *metaObject
argument_list|,
argument|int sid
argument_list|,
argument|const QVariantList&args
argument_list|)
block|;
name|public
operator|:
comment|// member variables
name|AdaptorMap
name|adaptors
block|;
name|bool
name|waitingForPolish
operator|:
literal|1
block|;
name|private
operator|:
specifier|static
name|int
name|relaySlotMethodIndex
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|extern
name|QDBusAdaptorConnector
modifier|*
name|qDBusFindAdaptorConnector
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|QDBusAdaptorConnector
modifier|*
name|qDBusCreateAdaptorConnector
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
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
begin_comment
comment|// QDBUSABSTRACTADAPTORPRIVATE_H
end_comment
end_unit
