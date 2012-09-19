begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusabstractadaptor.h"
end_include
begin_include
include|#
directive|include
file|"qdbusabstractadaptor_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtimer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qthread.h>
end_include
begin_include
include|#
directive|include
file|"qdbusconnection.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnection_p.h"
end_include
begin_comment
comment|// for qDBusParametersForMethod
end_comment
begin_include
include|#
directive|include
file|"qdbusmetatype_p.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|cachedRelaySlotMethodIndex
specifier|static
name|int
name|cachedRelaySlotMethodIndex
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|relaySlotMethodIndex
name|int
name|QDBusAdaptorConnector
operator|::
name|relaySlotMethodIndex
parameter_list|()
block|{
if|if
condition|(
name|cachedRelaySlotMethodIndex
operator|==
operator|-
literal|1
condition|)
block|{
name|cachedRelaySlotMethodIndex
operator|=
name|staticMetaObject
operator|.
name|indexOfMethod
argument_list|(
literal|"relaySlot()"
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|cachedRelaySlotMethodIndex
operator|!=
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|cachedRelaySlotMethodIndex
return|;
block|}
end_function
begin_function
DECL|function|qDBusFindAdaptorConnector
name|QDBusAdaptorConnector
modifier|*
name|qDBusFindAdaptorConnector
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
block|{
if|if
condition|(
operator|!
name|obj
condition|)
return|return
literal|0
return|;
specifier|const
name|QObjectList
modifier|&
name|children
init|=
name|obj
operator|->
name|children
argument_list|()
decl_stmt|;
name|QObjectList
operator|::
name|ConstIterator
name|it
init|=
name|children
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QObjectList
operator|::
name|ConstIterator
name|end
init|=
name|children
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|QDBusAdaptorConnector
modifier|*
name|connector
init|=
name|qobject_cast
argument_list|<
name|QDBusAdaptorConnector
operator|*
argument_list|>
argument_list|(
operator|*
name|it
argument_list|)
decl_stmt|;
if|if
condition|(
name|connector
condition|)
block|{
name|connector
operator|->
name|polish
argument_list|()
expr_stmt|;
return|return
name|connector
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qDBusFindAdaptorConnector
name|QDBusAdaptorConnector
modifier|*
name|qDBusFindAdaptorConnector
parameter_list|(
name|QDBusAbstractAdaptor
modifier|*
name|adaptor
parameter_list|)
block|{
return|return
name|qDBusFindAdaptorConnector
argument_list|(
name|adaptor
operator|->
name|parent
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qDBusCreateAdaptorConnector
name|QDBusAdaptorConnector
modifier|*
name|qDBusCreateAdaptorConnector
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
block|{
name|QDBusAdaptorConnector
modifier|*
name|connector
init|=
name|qDBusFindAdaptorConnector
argument_list|(
name|obj
argument_list|)
decl_stmt|;
if|if
condition|(
name|connector
condition|)
return|return
name|connector
return|;
return|return
operator|new
name|QDBusAdaptorConnector
argument_list|(
name|obj
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|retrieveIntrospectionXml
name|QString
name|QDBusAbstractAdaptorPrivate
operator|::
name|retrieveIntrospectionXml
parameter_list|(
name|QDBusAbstractAdaptor
modifier|*
name|adaptor
parameter_list|)
block|{
return|return
name|adaptor
operator|->
name|d_func
argument_list|()
operator|->
name|xml
return|;
block|}
end_function
begin_function
DECL|function|saveIntrospectionXml
name|void
name|QDBusAbstractAdaptorPrivate
operator|::
name|saveIntrospectionXml
parameter_list|(
name|QDBusAbstractAdaptor
modifier|*
name|adaptor
parameter_list|,
specifier|const
name|QString
modifier|&
name|xml
parameter_list|)
block|{
name|adaptor
operator|->
name|d_func
argument_list|()
operator|->
name|xml
operator|=
name|xml
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QDBusAbstractAdaptor     \inmodule QtDBus     \since 4.2      \brief The QDBusAbstractAdaptor class is the base class of D-Bus adaptor classes.      The QDBusAbstractAdaptor class is the starting point for all objects intending to provide     interfaces to the external world using D-Bus. This is accomplished by attaching a one or more     classes derived from QDBusAbstractAdaptor to a normal QObject and then registering that QObject     with QDBusConnection::registerObject. QDBusAbstractAdaptor objects are intended to be     light-weight wrappers, mostly just relaying calls into the real object (its parent) and the     signals from it.      Each QDBusAbstractAdaptor-derived class should define the D-Bus interface it is implementing     using the Q_CLASSINFO macro in the class definition. Note that only one interface can be     exposed in this way.      QDBusAbstractAdaptor uses the standard QObject mechanism of signals, slots and properties to     determine what signals, methods and properties to export to the bus. Any signal emitted by     QDBusAbstractAdaptor-derived classes will be automatically be relayed through any D-Bus     connections the object is registered on.      Classes derived from QDBusAbstractAdaptor must be created on the heap using the \a new operator     and must not be deleted by the user (they will be deleted automatically when the object they are     connected to is also deleted).      \sa {usingadaptors.html}{Using adaptors}, QDBusConnection */
end_comment
begin_comment
comment|/*!     Constructs a QDBusAbstractAdaptor with \a obj as the parent object. */
end_comment
begin_constructor
DECL|function|QDBusAbstractAdaptor
name|QDBusAbstractAdaptor
operator|::
name|QDBusAbstractAdaptor
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QDBusAbstractAdaptorPrivate
argument_list|,
name|obj
argument_list|)
block|{
name|QDBusAdaptorConnector
modifier|*
name|connector
init|=
name|qDBusCreateAdaptorConnector
argument_list|(
name|obj
argument_list|)
decl_stmt|;
name|connector
operator|->
name|waitingForPolish
operator|=
literal|true
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|connector
argument_list|,
literal|"polish"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the adaptor.      \warning Adaptors are destroyed automatically when the real object they refer to is              destroyed. Do not delete the adaptors yourself. */
end_comment
begin_destructor
DECL|function|~QDBusAbstractAdaptor
name|QDBusAbstractAdaptor
operator|::
name|~
name|QDBusAbstractAdaptor
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Toggles automatic signal relaying from the real object (see object()).      Automatic signal relaying consists of signal-to-signal connection of the signals on the parent     that have the exact same method signatue in both classes.      If \a enable is set to true, connect the signals; if set to false, disconnect all signals. */
end_comment
begin_function
DECL|function|setAutoRelaySignals
name|void
name|QDBusAbstractAdaptor
operator|::
name|setAutoRelaySignals
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
specifier|const
name|QMetaObject
modifier|*
name|us
init|=
name|metaObject
argument_list|()
decl_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|them
init|=
name|parent
argument_list|()
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|bool
name|connected
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|idx
init|=
name|staticMetaObject
operator|.
name|methodCount
argument_list|()
init|;
name|idx
operator|<
name|us
operator|->
name|methodCount
argument_list|()
condition|;
operator|++
name|idx
control|)
block|{
name|QMetaMethod
name|mm
init|=
name|us
operator|->
name|method
argument_list|(
name|idx
argument_list|)
decl_stmt|;
if|if
condition|(
name|mm
operator|.
name|methodType
argument_list|()
operator|!=
name|QMetaMethod
operator|::
name|Signal
condition|)
continue|continue;
comment|// try to connect/disconnect to a signal on the parent that has the same method signature
name|QByteArray
name|sig
init|=
name|QMetaObject
operator|::
name|normalizedSignature
argument_list|(
name|mm
operator|.
name|methodSignature
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|them
operator|->
name|indexOfSignal
argument_list|(
name|sig
argument_list|)
operator|==
operator|-
literal|1
condition|)
continue|continue;
name|sig
operator|.
name|prepend
argument_list|(
name|QSIGNAL_CODE
operator|+
literal|'0'
argument_list|)
expr_stmt|;
name|parent
argument_list|()
operator|->
name|disconnect
argument_list|(
name|sig
argument_list|,
name|this
argument_list|,
name|sig
argument_list|)
expr_stmt|;
if|if
condition|(
name|enable
condition|)
name|connected
operator|=
name|connect
argument_list|(
name|parent
argument_list|()
argument_list|,
name|sig
argument_list|,
name|sig
argument_list|)
operator|||
name|connected
expr_stmt|;
block|}
name|d_func
argument_list|()
operator|->
name|autoRelaySignals
operator|=
name|connected
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns true if automatic signal relaying from the real object (see object()) is enabled,     otherwiser returns false.      \sa setAutoRelaySignals() */
end_comment
begin_function
DECL|function|autoRelaySignals
name|bool
name|QDBusAbstractAdaptor
operator|::
name|autoRelaySignals
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|autoRelaySignals
return|;
block|}
end_function
begin_constructor
DECL|function|QDBusAdaptorConnector
name|QDBusAdaptorConnector
operator|::
name|QDBusAdaptorConnector
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|obj
argument_list|)
member_init_list|,
name|waitingForPolish
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QDBusAdaptorConnector
name|QDBusAdaptorConnector
operator|::
name|~
name|QDBusAdaptorConnector
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|addAdaptor
name|void
name|QDBusAdaptorConnector
operator|::
name|addAdaptor
parameter_list|(
name|QDBusAbstractAdaptor
modifier|*
name|adaptor
parameter_list|)
block|{
comment|// find the interface name
specifier|const
name|QMetaObject
modifier|*
name|mo
init|=
name|adaptor
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|int
name|ciid
init|=
name|mo
operator|->
name|indexOfClassInfo
argument_list|(
name|QCLASSINFO_DBUS_INTERFACE
argument_list|)
decl_stmt|;
if|if
condition|(
name|ciid
operator|!=
operator|-
literal|1
condition|)
block|{
name|QMetaClassInfo
name|mci
init|=
name|mo
operator|->
name|classInfo
argument_list|(
name|ciid
argument_list|)
decl_stmt|;
if|if
condition|(
operator|*
name|mci
operator|.
name|value
argument_list|()
condition|)
block|{
comment|// find out if this interface exists first
specifier|const
name|char
modifier|*
name|interface
init|=
name|mci
operator|.
name|value
argument_list|()
decl_stmt|;
name|AdaptorMap
operator|::
name|Iterator
name|it
init|=
name|std
operator|::
name|lower_bound
argument_list|(
name|adaptors
operator|.
name|begin
argument_list|()
argument_list|,
name|adaptors
operator|.
name|end
argument_list|()
argument_list|,
name|QByteArray
argument_list|(
name|interface
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|adaptors
operator|.
name|end
argument_list|()
operator|&&
name|qstrcmp
argument_list|(
name|interface
argument_list|,
name|it
operator|->
name|interface
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|// exists. Replace it (though it's probably the same)
if|if
condition|(
name|it
operator|->
name|adaptor
operator|!=
name|adaptor
condition|)
block|{
comment|// reconnect the signals
name|disconnectAllSignals
argument_list|(
name|it
operator|->
name|adaptor
argument_list|)
expr_stmt|;
name|connectAllSignals
argument_list|(
name|adaptor
argument_list|)
expr_stmt|;
block|}
name|it
operator|->
name|adaptor
operator|=
name|adaptor
expr_stmt|;
block|}
else|else
block|{
comment|// create a new one
name|AdaptorData
name|entry
decl_stmt|;
name|entry
operator|.
name|interface
operator|=
name|interface
expr_stmt|;
name|entry
operator|.
name|adaptor
operator|=
name|adaptor
expr_stmt|;
name|adaptors
operator|<<
name|entry
expr_stmt|;
comment|// connect the adaptor's signals to our relaySlot slot
name|connectAllSignals
argument_list|(
name|adaptor
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|disconnectAllSignals
name|void
name|QDBusAdaptorConnector
operator|::
name|disconnectAllSignals
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
block|{
name|QMetaObject
operator|::
name|disconnect
argument_list|(
name|obj
argument_list|,
operator|-
literal|1
argument_list|,
name|this
argument_list|,
name|relaySlotMethodIndex
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|connectAllSignals
name|void
name|QDBusAdaptorConnector
operator|::
name|connectAllSignals
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
block|{
name|QMetaObject
operator|::
name|connect
argument_list|(
name|obj
argument_list|,
operator|-
literal|1
argument_list|,
name|this
argument_list|,
name|relaySlotMethodIndex
argument_list|()
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|polish
name|void
name|QDBusAdaptorConnector
operator|::
name|polish
parameter_list|()
block|{
if|if
condition|(
operator|!
name|waitingForPolish
condition|)
return|return;
comment|// avoid working multiple times if multiple adaptors were added
name|waitingForPolish
operator|=
literal|false
expr_stmt|;
specifier|const
name|QObjectList
modifier|&
name|objs
init|=
name|parent
argument_list|()
operator|->
name|children
argument_list|()
decl_stmt|;
name|QObjectList
operator|::
name|ConstIterator
name|it
init|=
name|objs
operator|.
name|constBegin
argument_list|()
decl_stmt|;
name|QObjectList
operator|::
name|ConstIterator
name|end
init|=
name|objs
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|QDBusAbstractAdaptor
modifier|*
name|adaptor
init|=
name|qobject_cast
argument_list|<
name|QDBusAbstractAdaptor
operator|*
argument_list|>
argument_list|(
operator|*
name|it
argument_list|)
decl_stmt|;
if|if
condition|(
name|adaptor
condition|)
name|addAdaptor
argument_list|(
name|adaptor
argument_list|)
expr_stmt|;
block|}
comment|// sort the adaptor list
name|qSort
argument_list|(
name|adaptors
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|relaySlot
name|void
name|QDBusAdaptorConnector
operator|::
name|relaySlot
parameter_list|(
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|relay
argument_list|(
name|sender
argument_list|()
argument_list|,
name|senderSignalIndex
argument_list|()
argument_list|,
name|argv
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|relay
name|void
name|QDBusAdaptorConnector
operator|::
name|relay
parameter_list|(
name|QObject
modifier|*
name|senderObj
parameter_list|,
name|int
name|lastSignalIdx
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
if|if
condition|(
name|lastSignalIdx
operator|<
name|QObject
operator|::
name|staticMetaObject
operator|.
name|methodCount
argument_list|()
condition|)
comment|// QObject signal (destroyed(QObject *)) -- ignore
return|return;
specifier|const
name|QMetaObject
modifier|*
name|senderMetaObject
init|=
name|senderObj
operator|->
name|metaObject
argument_list|()
decl_stmt|;
name|QMetaMethod
name|mm
init|=
name|senderMetaObject
operator|->
name|method
argument_list|(
name|lastSignalIdx
argument_list|)
decl_stmt|;
name|QObject
modifier|*
name|realObject
init|=
name|senderObj
decl_stmt|;
if|if
condition|(
name|qobject_cast
argument_list|<
name|QDBusAbstractAdaptor
operator|*
argument_list|>
argument_list|(
name|senderObj
argument_list|)
condition|)
comment|// it's an adaptor, so the real object is in fact its parent
name|realObject
operator|=
name|realObject
operator|->
name|parent
argument_list|()
expr_stmt|;
comment|// break down the parameter list
name|QVector
argument_list|<
name|int
argument_list|>
name|types
decl_stmt|;
name|int
name|inputCount
init|=
name|qDBusParametersForMethod
argument_list|(
name|mm
argument_list|,
name|types
argument_list|)
decl_stmt|;
if|if
condition|(
name|inputCount
operator|==
operator|-
literal|1
condition|)
comment|// invalid signal signature
comment|// qDBusParametersForMethod has already complained
return|return;
if|if
condition|(
name|inputCount
operator|+
literal|1
operator|!=
name|types
operator|.
name|count
argument_list|()
operator|||
name|types
operator|.
name|at
argument_list|(
name|inputCount
argument_list|)
operator|==
name|QDBusMetaTypeId
operator|::
name|message
argument_list|()
condition|)
block|{
comment|// invalid signal signature
comment|// qDBusParametersForMethod has not yet complained about this one
name|qWarning
argument_list|(
literal|"QDBusAbstractAdaptor: Cannot relay signal %s::%s"
argument_list|,
name|senderMetaObject
operator|->
name|className
argument_list|()
argument_list|,
name|mm
operator|.
name|methodSignature
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|QVariantList
name|args
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|types
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|args
operator|<<
name|QVariant
argument_list|(
name|types
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|// now emit the signal with all the information
emit|emit
name|relaySignal
argument_list|(
name|realObject
argument_list|,
name|senderMetaObject
argument_list|,
name|lastSignalIdx
argument_list|,
name|args
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|// our Meta Object
end_comment
begin_comment
comment|// modify carefully: this has been hand-edited!
end_comment
begin_comment
comment|// the relaySlot slot gets called with the void** array
end_comment
begin_struct
DECL|struct|qt_meta_stringdata_QDBusAdaptorConnector_t
struct|struct
name|qt_meta_stringdata_QDBusAdaptorConnector_t
block|{
DECL|member|data
name|QByteArrayData
name|data
index|[
literal|10
index|]
decl_stmt|;
DECL|member|stringdata
name|char
name|stringdata
index|[
literal|96
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_define
DECL|macro|QT_MOC_LITERAL
define|#
directive|define
name|QT_MOC_LITERAL
parameter_list|(
name|idx
parameter_list|,
name|ofs
parameter_list|,
name|len
parameter_list|)
define|\
value|Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \         offsetof(qt_meta_stringdata_QDBusAdaptorConnector_t, stringdata) + ofs \         - idx * sizeof(QByteArrayData) \     )
end_define
begin_decl_stmt
DECL|variable|qt_meta_stringdata_QDBusAdaptorConnector
specifier|static
specifier|const
name|qt_meta_stringdata_QDBusAdaptorConnector_t
name|qt_meta_stringdata_QDBusAdaptorConnector
init|=
block|{
block|{
name|QT_MOC_LITERAL
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|21
argument_list|)
block|,
name|QT_MOC_LITERAL
argument_list|(
literal|1
argument_list|,
literal|22
argument_list|,
literal|11
argument_list|)
block|,
name|QT_MOC_LITERAL
argument_list|(
literal|2
argument_list|,
literal|34
argument_list|,
literal|0
argument_list|)
block|,
name|QT_MOC_LITERAL
argument_list|(
literal|3
argument_list|,
literal|35
argument_list|,
literal|3
argument_list|)
block|,
name|QT_MOC_LITERAL
argument_list|(
literal|4
argument_list|,
literal|39
argument_list|,
literal|18
argument_list|)
block|,
name|QT_MOC_LITERAL
argument_list|(
literal|5
argument_list|,
literal|58
argument_list|,
literal|10
argument_list|)
block|,
name|QT_MOC_LITERAL
argument_list|(
literal|6
argument_list|,
literal|69
argument_list|,
literal|3
argument_list|)
block|,
name|QT_MOC_LITERAL
argument_list|(
literal|7
argument_list|,
literal|73
argument_list|,
literal|4
argument_list|)
block|,
name|QT_MOC_LITERAL
argument_list|(
literal|8
argument_list|,
literal|78
argument_list|,
literal|9
argument_list|)
block|,
name|QT_MOC_LITERAL
argument_list|(
literal|9
argument_list|,
literal|88
argument_list|,
literal|6
argument_list|)
block|}
block|,
literal|"QDBusAdaptorConnector\0relaySignal\0\0"
literal|"obj\0const QMetaObject*\0metaObject\0sid\0"
literal|"args\0relaySlot\0polish\0"
block|}
decl_stmt|;
end_decl_stmt
begin_undef
DECL|macro|QT_MOC_LITERAL
undef|#
directive|undef
name|QT_MOC_LITERAL
end_undef
begin_decl_stmt
DECL|variable|qt_meta_data_QDBusAdaptorConnector
specifier|static
specifier|const
name|uint
name|qt_meta_data_QDBusAdaptorConnector
index|[]
init|=
block|{
comment|// content:
literal|7
block|,
comment|// revision
literal|0
block|,
comment|// classname
literal|0
block|,
literal|0
block|,
comment|// classinfo
literal|3
block|,
literal|14
block|,
comment|// methods
literal|0
block|,
literal|0
block|,
comment|// properties
literal|0
block|,
literal|0
block|,
comment|// enums/sets
literal|0
block|,
literal|0
block|,
comment|// constructors
literal|0
block|,
comment|// flags
literal|1
block|,
comment|// signalCount
comment|// signals: name, argc, parameters, tag, flags
literal|1
block|,
literal|4
block|,
literal|29
block|,
literal|2
block|,
literal|0x05
block|,
comment|// slots: name, argc, parameters, tag, flags
literal|8
block|,
literal|0
block|,
literal|38
block|,
literal|2
block|,
literal|0x0a
block|,
literal|9
block|,
literal|0
block|,
literal|39
block|,
literal|2
block|,
literal|0x0a
block|,
comment|// signals: parameters
name|QMetaType
operator|::
name|Void
block|,
name|QMetaType
operator|::
name|QObjectStar
block|,
literal|0x80000000
operator||
literal|4
block|,
name|QMetaType
operator|::
name|Int
block|,
name|QMetaType
operator|::
name|QVariantList
block|,
literal|3
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
comment|// slots: parameters
name|QMetaType
operator|::
name|Void
block|,
name|QMetaType
operator|::
name|Void
block|,
literal|0
comment|// eod
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qt_static_metacall
name|void
name|QDBusAdaptorConnector
operator|::
name|qt_static_metacall
parameter_list|(
name|QObject
modifier|*
name|_o
parameter_list|,
name|QMetaObject
operator|::
name|Call
name|_c
parameter_list|,
name|int
name|_id
parameter_list|,
name|void
modifier|*
modifier|*
name|_a
parameter_list|)
block|{
if|if
condition|(
name|_c
operator|==
name|QMetaObject
operator|::
name|InvokeMetaMethod
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|staticMetaObject
operator|.
name|cast
argument_list|(
name|_o
argument_list|)
argument_list|)
expr_stmt|;
name|QDBusAdaptorConnector
modifier|*
name|_t
init|=
cast|static_cast
argument_list|<
name|QDBusAdaptorConnector
operator|*
argument_list|>
argument_list|(
name|_o
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|_id
condition|)
block|{
case|case
literal|0
case|:
name|_t
operator|->
name|relaySignal
argument_list|(
operator|(
operator|*
cast|reinterpret_cast
argument_list|<
name|QObject
operator|*
operator|(
operator|*
operator|)
argument_list|>
argument_list|(
name|_a
index|[
literal|1
index|]
argument_list|)
operator|)
argument_list|,
operator|(
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|QMetaObject
operator|*
operator|(
operator|*
operator|)
argument_list|>
argument_list|(
name|_a
index|[
literal|2
index|]
argument_list|)
operator|)
argument_list|,
operator|(
operator|*
cast|reinterpret_cast
argument_list|<
name|int
operator|(
operator|*
operator|)
argument_list|>
argument_list|(
name|_a
index|[
literal|3
index|]
argument_list|)
operator|)
argument_list|,
operator|(
operator|*
cast|reinterpret_cast
argument_list|<
specifier|const
name|QVariantList
operator|(
operator|*
operator|)
argument_list|>
argument_list|(
name|_a
index|[
literal|4
index|]
argument_list|)
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|_t
operator|->
name|relaySlot
argument_list|(
name|_a
argument_list|)
expr_stmt|;
break|break;
comment|// HAND EDIT: add the _a parameter
case|case
literal|2
case|:
name|_t
operator|->
name|polish
argument_list|()
expr_stmt|;
break|break;
default|default:
empty_stmt|;
block|}
block|}
block|}
end_function
begin_decl_stmt
DECL|member|staticMetaObject
specifier|const
name|QMetaObject
name|QDBusAdaptorConnector
operator|::
name|staticMetaObject
init|=
block|{
block|{
operator|&
name|QObject
operator|::
name|staticMetaObject
block|,
name|qt_meta_stringdata_QDBusAdaptorConnector
operator|.
name|data
block|,
name|qt_meta_data_QDBusAdaptorConnector
block|,
name|qt_static_metacall
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|metaObject
specifier|const
name|QMetaObject
modifier|*
name|QDBusAdaptorConnector
operator|::
name|metaObject
parameter_list|()
specifier|const
block|{
return|return
operator|&
name|staticMetaObject
return|;
block|}
end_function
begin_function
DECL|function|qt_metacast
name|void
modifier|*
name|QDBusAdaptorConnector
operator|::
name|qt_metacast
parameter_list|(
specifier|const
name|char
modifier|*
name|_clname
parameter_list|)
block|{
if|if
condition|(
operator|!
name|_clname
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|_clname
argument_list|,
name|qt_meta_stringdata_QDBusAdaptorConnector
operator|.
name|stringdata
argument_list|)
condition|)
return|return
cast|static_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
cast|const_cast
argument_list|<
name|QDBusAdaptorConnector
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
return|return
name|QObject
operator|::
name|qt_metacast
argument_list|(
name|_clname
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_metacall
name|int
name|QDBusAdaptorConnector
operator|::
name|qt_metacall
parameter_list|(
name|QMetaObject
operator|::
name|Call
name|_c
parameter_list|,
name|int
name|_id
parameter_list|,
name|void
modifier|*
modifier|*
name|_a
parameter_list|)
block|{
name|_id
operator|=
name|QObject
operator|::
name|qt_metacall
argument_list|(
name|_c
argument_list|,
name|_id
argument_list|,
name|_a
argument_list|)
expr_stmt|;
if|if
condition|(
name|_id
operator|<
literal|0
condition|)
return|return
name|_id
return|;
if|if
condition|(
name|_c
operator|==
name|QMetaObject
operator|::
name|InvokeMetaMethod
condition|)
block|{
if|if
condition|(
name|_id
operator|<
literal|3
condition|)
name|qt_static_metacall
argument_list|(
name|this
argument_list|,
name|_c
argument_list|,
name|_id
argument_list|,
name|_a
argument_list|)
expr_stmt|;
name|_id
operator|-=
literal|3
expr_stmt|;
block|}
return|return
name|_id
return|;
block|}
end_function
begin_comment
comment|// SIGNAL 0
end_comment
begin_function
DECL|function|relaySignal
name|void
name|QDBusAdaptorConnector
operator|::
name|relaySignal
parameter_list|(
name|QObject
modifier|*
name|_t1
parameter_list|,
specifier|const
name|QMetaObject
modifier|*
name|_t2
parameter_list|,
name|int
name|_t3
parameter_list|,
specifier|const
name|QVariantList
modifier|&
name|_t4
parameter_list|)
block|{
name|void
modifier|*
name|_a
index|[]
init|=
block|{
literal|0
block|,
cast|const_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|void
operator|*
argument_list|>
argument_list|(
operator|&
name|_t1
argument_list|)
argument_list|)
block|,
cast|const_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|void
operator|*
argument_list|>
argument_list|(
operator|&
name|_t2
argument_list|)
argument_list|)
block|,
cast|const_cast
argument_list|<
name|void
operator|*
argument_list|>
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|void
operator|*
argument_list|>
argument_list|(
operator|&
name|_t3
argument_list|)
argument_list|)
block|,
expr|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|void
operator|*
argument_list|>
argument_list|(
operator|&
name|_t4
argument_list|)
operator|)
block|}
decl_stmt|;
name|QMetaObject
operator|::
name|activate
argument_list|(
name|this
argument_list|,
operator|&
name|staticMetaObject
argument_list|,
literal|0
argument_list|,
name|_a
argument_list|)
expr_stmt|;
block|}
end_function
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
end_unit
