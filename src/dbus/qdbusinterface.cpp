begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusinterface.h"
end_include
begin_include
include|#
directive|include
file|"qdbusinterface_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbus_symbols_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"qdbusmetatype_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnection_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|copyArgument
specifier|static
name|void
name|copyArgument
parameter_list|(
name|void
modifier|*
name|to
parameter_list|,
name|int
name|id
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|arg
parameter_list|)
block|{
if|if
condition|(
name|id
operator|==
name|arg
operator|.
name|userType
argument_list|()
condition|)
block|{
switch|switch
condition|(
name|id
condition|)
block|{
case|case
name|QVariant
operator|::
name|Bool
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|bool
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|toBool
argument_list|()
expr_stmt|;
return|return;
case|case
name|QMetaType
operator|::
name|UChar
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|value
argument_list|<
name|uchar
argument_list|>
argument_list|()
expr_stmt|;
return|return;
case|case
name|QMetaType
operator|::
name|Short
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|short
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|value
argument_list|<
name|short
argument_list|>
argument_list|()
expr_stmt|;
return|return;
case|case
name|QMetaType
operator|::
name|UShort
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|ushort
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|value
argument_list|<
name|ushort
argument_list|>
argument_list|()
expr_stmt|;
return|return;
case|case
name|QVariant
operator|::
name|Int
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|int
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|toInt
argument_list|()
expr_stmt|;
return|return;
case|case
name|QVariant
operator|::
name|UInt
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|uint
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|toUInt
argument_list|()
expr_stmt|;
return|return;
case|case
name|QVariant
operator|::
name|LongLong
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|qlonglong
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|toLongLong
argument_list|()
expr_stmt|;
return|return;
case|case
name|QVariant
operator|::
name|ULongLong
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|qulonglong
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|toULongLong
argument_list|()
expr_stmt|;
return|return;
case|case
name|QVariant
operator|::
name|Double
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|double
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|toDouble
argument_list|()
expr_stmt|;
return|return;
case|case
name|QVariant
operator|::
name|String
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|QString
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|toString
argument_list|()
expr_stmt|;
return|return;
case|case
name|QVariant
operator|::
name|ByteArray
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|QByteArray
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|toByteArray
argument_list|()
expr_stmt|;
return|return;
case|case
name|QVariant
operator|::
name|StringList
case|:
operator|*
cast|reinterpret_cast
argument_list|<
name|QStringList
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|toStringList
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|id
operator|==
name|QDBusMetaTypeId
operator|::
name|variant
argument_list|()
condition|)
block|{
operator|*
cast|reinterpret_cast
argument_list|<
name|QDBusVariant
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|value
argument_list|<
name|QDBusVariant
argument_list|>
argument_list|()
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|id
operator|==
name|QDBusMetaTypeId
operator|::
name|objectpath
argument_list|()
condition|)
block|{
operator|*
cast|reinterpret_cast
argument_list|<
name|QDBusObjectPath
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|value
argument_list|<
name|QDBusObjectPath
argument_list|>
argument_list|()
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|id
operator|==
name|QDBusMetaTypeId
operator|::
name|signature
argument_list|()
condition|)
block|{
operator|*
cast|reinterpret_cast
argument_list|<
name|QDBusSignature
operator|*
argument_list|>
argument_list|(
name|to
argument_list|)
operator|=
name|arg
operator|.
name|value
argument_list|<
name|QDBusSignature
argument_list|>
argument_list|()
expr_stmt|;
return|return;
block|}
comment|// those above are the only types possible
comment|// the demarshaller code doesn't demarshall anything else
name|qFatal
argument_list|(
literal|"Found a decoded basic type in a D-Bus reply that shouldn't be there"
argument_list|)
expr_stmt|;
block|}
comment|// if we got here, it's either an un-dermarshalled type or a mismatch
if|if
condition|(
name|arg
operator|.
name|userType
argument_list|()
operator|!=
name|QDBusMetaTypeId
operator|::
name|argument
argument_list|()
condition|)
block|{
comment|// it's a mismatch
comment|//qWarning?
return|return;
block|}
comment|// is this type registered?
specifier|const
name|char
modifier|*
name|userSignature
init|=
name|QDBusMetaType
operator|::
name|typeToSignature
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|userSignature
operator|||
operator|!
operator|*
name|userSignature
condition|)
block|{
comment|// type not registered
comment|//qWarning?
return|return;
block|}
comment|// is it the same signature?
name|QDBusArgument
name|dbarg
init|=
name|arg
operator|.
name|value
argument_list|<
name|QDBusArgument
argument_list|>
argument_list|()
decl_stmt|;
if|if
condition|(
name|dbarg
operator|.
name|currentSignature
argument_list|()
operator|!=
name|QLatin1String
argument_list|(
name|userSignature
argument_list|)
condition|)
block|{
comment|// not the same signature, another mismatch
comment|//qWarning?
return|return;
block|}
comment|// we can demarshall
name|QDBusMetaType
operator|::
name|demarshall
argument_list|(
name|dbarg
argument_list|,
name|id
argument_list|,
name|to
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QDBusInterfacePrivate
name|QDBusInterfacePrivate
operator|::
name|QDBusInterfacePrivate
parameter_list|(
specifier|const
name|QString
modifier|&
name|serv
parameter_list|,
specifier|const
name|QString
modifier|&
name|p
parameter_list|,
specifier|const
name|QString
modifier|&
name|iface
parameter_list|,
specifier|const
name|QDBusConnection
modifier|&
name|con
parameter_list|)
member_init_list|:
name|QDBusAbstractInterfacePrivate
argument_list|(
name|serv
argument_list|,
name|p
argument_list|,
name|iface
argument_list|,
name|con
argument_list|,
literal|true
argument_list|)
member_init_list|,
name|metaObject
argument_list|(
literal|0
argument_list|)
block|{
comment|// QDBusAbstractInterfacePrivate's constructor checked the parameters for us
if|if
condition|(
name|connection
operator|.
name|isConnected
argument_list|()
condition|)
block|{
name|metaObject
operator|=
name|connectionPrivate
argument_list|()
operator|->
name|findMetaObject
argument_list|(
name|service
argument_list|,
name|path
argument_list|,
name|interface
argument_list|,
name|lastError
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|metaObject
condition|)
block|{
comment|// creation failed, somehow
comment|// most common causes are that the service doesn't exist or doesn't support introspection
comment|// those are not fatal errors, so we continue working
if|if
condition|(
operator|!
name|lastError
operator|.
name|isValid
argument_list|()
condition|)
name|lastError
operator|=
name|QDBusError
argument_list|(
name|QDBusError
operator|::
name|InternalError
argument_list|,
name|QLatin1String
argument_list|(
literal|"Unknown error"
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QDBusInterfacePrivate
name|QDBusInterfacePrivate
operator|::
name|~
name|QDBusInterfacePrivate
parameter_list|()
block|{
if|if
condition|(
name|metaObject
operator|&&
operator|!
name|metaObject
operator|->
name|cached
condition|)
operator|delete
name|metaObject
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \class QDBusInterface     \inmodule QtDBus     \since 4.2      \brief The QDBusInterface class is a proxy for interfaces on remote objects.      QDBusInterface is a generic accessor class that is used to place calls to remote objects,     connect to signals exported by remote objects and get/set the value of remote properties. This     class is useful for dynamic access to remote objects: that is, when you do not have a generated     code that represents the remote interface.      Calls are usually placed by using the call() function, which constructs the message, sends it     over the bus, waits for the reply and decodes the reply. Signals are connected to by using the     normal QObject::connect() function. Finally, properties are accessed using the     QObject::property() and QObject::setProperty() functions.      The following code snippet demonstrates how to perform a     mathematical operation of \tt{"2 + 2"} in a remote application     called \c com.example.Calculator, accessed via the session bus.      \snippet code/src_qdbus_qdbusinterface.cpp 0      \sa {QtDBus XML compiler (qdbusxml2cpp)} */
end_comment
begin_comment
comment|/*!     Creates a dynamic QDBusInterface object associated with the     interface \a interface on object at path \a path on service \a     service, using the given \a connection. If \a interface is an     empty string, the object created will refer to the merging of all     interfaces found in that object.      \a parent is passed to the base class constructor.      If the remote service \a service is not present or if an error     occurs trying to obtain the description of the remote interface     \a interface, the object created will not be valid (see     isValid()). */
end_comment
begin_constructor
DECL|function|QDBusInterface
name|QDBusInterface
operator|::
name|QDBusInterface
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDBusAbstractInterface
argument_list|(
operator|*
operator|new
name|QDBusInterfacePrivate
argument_list|(
name|service
argument_list|,
name|path
argument_list|,
name|interface
argument_list|,
name|connection
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroy the object interface and frees up any resource used. */
end_comment
begin_destructor
DECL|function|~QDBusInterface
name|QDBusInterface
operator|::
name|~
name|QDBusInterface
parameter_list|()
block|{
comment|// resources are freed in QDBusInterfacePrivate::~QDBusInterfacePrivate()
block|}
end_destructor
begin_comment
comment|/*!     \internal     Overrides QObject::metaObject to return our own copy. */
end_comment
begin_function
DECL|function|metaObject
specifier|const
name|QMetaObject
modifier|*
name|QDBusInterface
operator|::
name|metaObject
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|metaObject
condition|?
name|d_func
argument_list|()
operator|->
name|metaObject
else|:
operator|&
name|QDBusAbstractInterface
operator|::
name|staticMetaObject
return|;
block|}
end_function
begin_comment
comment|/*!     \internal     Override QObject::qt_metacast to catch the interface name too. */
end_comment
begin_function
DECL|function|qt_metacast
name|void
modifier|*
name|QDBusInterface
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
literal|"QDBusInterface"
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
name|QDBusInterface
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
if|if
condition|(
name|d_func
argument_list|()
operator|->
name|interface
operator|.
name|toLatin1
argument_list|()
operator|==
name|_clname
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
name|QDBusInterface
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
return|;
return|return
name|QDBusAbstractInterface
operator|::
name|qt_metacast
argument_list|(
name|_clname
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \internal     Dispatch the call through the private. */
end_comment
begin_function
DECL|function|qt_metacall
name|int
name|QDBusInterface
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
name|QDBusAbstractInterface
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
operator|||
operator|!
name|d_func
argument_list|()
operator|->
name|isValid
operator|||
operator|!
name|d_func
argument_list|()
operator|->
name|metaObject
condition|)
return|return
name|_id
return|;
return|return
name|d_func
argument_list|()
operator|->
name|metacall
argument_list|(
name|_c
argument_list|,
name|_id
argument_list|,
name|_a
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|metacall
name|int
name|QDBusInterfacePrivate
operator|::
name|metacall
parameter_list|(
name|QMetaObject
operator|::
name|Call
name|c
parameter_list|,
name|int
name|id
parameter_list|,
name|void
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QDBusInterface
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
name|QMetaObject
operator|::
name|InvokeMetaMethod
condition|)
block|{
name|int
name|offset
init|=
name|metaObject
operator|->
name|methodOffset
argument_list|()
decl_stmt|;
name|QMetaMethod
name|mm
init|=
name|metaObject
operator|->
name|method
argument_list|(
name|id
operator|+
name|offset
argument_list|)
decl_stmt|;
if|if
condition|(
name|mm
operator|.
name|methodType
argument_list|()
operator|==
name|QMetaMethod
operator|::
name|Signal
condition|)
block|{
comment|// signal relay from D-Bus world to Qt world
name|QMetaObject
operator|::
name|activate
argument_list|(
name|q
argument_list|,
name|metaObject
argument_list|,
name|id
argument_list|,
name|argv
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mm
operator|.
name|methodType
argument_list|()
operator|==
name|QMetaMethod
operator|::
name|Slot
operator|||
name|mm
operator|.
name|methodType
argument_list|()
operator|==
name|QMetaMethod
operator|::
name|Method
condition|)
block|{
comment|// method call relay from Qt world to D-Bus world
comment|// get D-Bus equivalent signature
name|QString
name|methodName
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|mm
operator|.
name|name
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|int
modifier|*
name|inputTypes
init|=
name|metaObject
operator|->
name|inputTypesForMethod
argument_list|(
name|id
argument_list|)
decl_stmt|;
name|int
name|inputTypesCount
init|=
operator|*
name|inputTypes
decl_stmt|;
comment|// we will assume that the input arguments were passed correctly
name|QVariantList
name|args
decl_stmt|;
name|int
name|i
init|=
literal|1
decl_stmt|;
for|for
control|(
init|;
name|i
operator|<=
name|inputTypesCount
condition|;
operator|++
name|i
control|)
name|args
operator|<<
name|QVariant
argument_list|(
name|inputTypes
index|[
name|i
index|]
argument_list|,
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|// make the call
name|QDBusMessage
name|reply
init|=
name|q
operator|->
name|callWithArgumentList
argument_list|(
name|QDBus
operator|::
name|Block
argument_list|,
name|methodName
argument_list|,
name|args
argument_list|)
decl_stmt|;
if|if
condition|(
name|reply
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ReplyMessage
condition|)
block|{
comment|// attempt to demarshall the return values
name|args
operator|=
name|reply
operator|.
name|arguments
argument_list|()
expr_stmt|;
name|QVariantList
operator|::
name|ConstIterator
name|it
init|=
name|args
operator|.
name|constBegin
argument_list|()
decl_stmt|;
specifier|const
name|int
modifier|*
name|outputTypes
init|=
name|metaObject
operator|->
name|outputTypesForMethod
argument_list|(
name|id
argument_list|)
decl_stmt|;
name|int
name|outputTypesCount
init|=
operator|*
name|outputTypes
operator|++
decl_stmt|;
if|if
condition|(
name|mm
operator|.
name|returnType
argument_list|()
operator|!=
name|QMetaType
operator|::
name|UnknownType
operator|&&
name|mm
operator|.
name|returnType
argument_list|()
operator|!=
name|QMetaType
operator|::
name|Void
condition|)
block|{
comment|// this method has a return type
if|if
condition|(
name|argv
index|[
literal|0
index|]
operator|&&
name|it
operator|!=
name|args
operator|.
name|constEnd
argument_list|()
condition|)
name|copyArgument
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
operator|*
name|outputTypes
operator|++
argument_list|,
operator|*
name|it
argument_list|)
expr_stmt|;
comment|// skip this argument even if we didn't copy it
operator|--
name|outputTypesCount
expr_stmt|;
operator|++
name|it
expr_stmt|;
block|}
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|outputTypesCount
operator|&&
name|it
operator|!=
name|args
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|i
operator|,
operator|++
name|j
operator|,
operator|++
name|it
control|)
block|{
name|copyArgument
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
name|outputTypes
index|[
name|j
index|]
argument_list|,
operator|*
name|it
argument_list|)
expr_stmt|;
block|}
block|}
comment|// done
name|lastError
operator|=
name|QDBusError
argument_list|(
name|reply
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
return|return
name|id
return|;
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
