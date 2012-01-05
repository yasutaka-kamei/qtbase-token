begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusservicewatcher.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnection.h"
end_include
begin_include
include|#
directive|include
file|"qdbus_symbols_p.h"
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QString
argument_list|,
name|busService
argument_list|,
operator|(
name|QLatin1String
argument_list|(
name|DBUS_SERVICE_DBUS
argument_list|)
operator|)
argument_list|)
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QString
argument_list|,
name|busInterface
argument_list|,
operator|(
name|QLatin1String
argument_list|(
name|DBUS_INTERFACE_DBUS
argument_list|)
operator|)
argument_list|)
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QString
argument_list|,
name|signalName
argument_list|,
operator|(
name|QLatin1String
argument_list|(
literal|"NameOwnerChanged"
argument_list|)
operator|)
argument_list|)
DECL|class|QDBusServiceWatcherPrivate
name|class
name|QDBusServiceWatcherPrivate
range|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QDBusServiceWatcher
argument_list|)
specifier|public
operator|:
DECL|function|QDBusServiceWatcherPrivate
name|QDBusServiceWatcherPrivate
argument_list|(
argument|const QDBusConnection&c
argument_list|,
argument|QDBusServiceWatcher::WatchMode wm
argument_list|)
operator|:
name|connection
argument_list|(
name|c
argument_list|)
block|,
name|watchMode
argument_list|(
argument|wm
argument_list|)
block|{     }
DECL|member|servicesWatched
name|QStringList
name|servicesWatched
block|;
DECL|member|connection
name|QDBusConnection
name|connection
block|;
DECL|member|watchMode
name|QDBusServiceWatcher
operator|::
name|WatchMode
name|watchMode
block|;
name|void
name|_q_serviceOwnerChanged
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|void
name|setConnection
argument_list|(
argument|const QStringList&services
argument_list|,
argument|const QDBusConnection&c
argument_list|,
argument|QDBusServiceWatcher::WatchMode watchMode
argument_list|)
block|;
name|QStringList
name|matchArgsForService
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|)
block|;
name|void
name|addService
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|)
block|;
name|void
name|removeService
argument_list|(
specifier|const
name|QString
operator|&
name|service
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|_q_serviceOwnerChanged
name|void
name|QDBusServiceWatcherPrivate
operator|::
name|_q_serviceOwnerChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QString
modifier|&
name|oldOwner
parameter_list|,
specifier|const
name|QString
modifier|&
name|newOwner
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|serviceOwnerChanged
argument_list|(
name|service
argument_list|,
name|oldOwner
argument_list|,
name|newOwner
argument_list|)
emit|;
if|if
condition|(
name|oldOwner
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|q
operator|->
name|serviceRegistered
argument_list|(
name|service
argument_list|)
emit|;
elseif|else
if|if
condition|(
name|newOwner
operator|.
name|isEmpty
argument_list|()
condition|)
emit|emit
name|q
operator|->
name|serviceUnregistered
argument_list|(
name|service
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|setConnection
name|void
name|QDBusServiceWatcherPrivate
operator|::
name|setConnection
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|s
parameter_list|,
specifier|const
name|QDBusConnection
modifier|&
name|c
parameter_list|,
name|QDBusServiceWatcher
operator|::
name|WatchMode
name|wm
parameter_list|)
block|{
if|if
condition|(
name|connection
operator|.
name|isConnected
argument_list|()
condition|)
block|{
comment|// remove older rules
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|s
decl|,
name|servicesWatched
control|)
name|removeService
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
name|connection
operator|=
name|c
expr_stmt|;
name|watchMode
operator|=
name|wm
expr_stmt|;
name|servicesWatched
operator|=
name|s
expr_stmt|;
if|if
condition|(
name|connection
operator|.
name|isConnected
argument_list|()
condition|)
block|{
comment|// add new rules
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|s
decl|,
name|servicesWatched
control|)
name|addService
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|matchArgsForService
name|QStringList
name|QDBusServiceWatcherPrivate
operator|::
name|matchArgsForService
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|)
block|{
name|QStringList
name|matchArgs
decl_stmt|;
name|matchArgs
operator|<<
name|service
expr_stmt|;
switch|switch
condition|(
name|watchMode
condition|)
block|{
case|case
name|QDBusServiceWatcher
operator|::
name|WatchForOwnerChange
case|:
break|break;
case|case
name|QDBusServiceWatcher
operator|::
name|WatchForRegistration
case|:
name|matchArgs
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|QDBusServiceWatcher
operator|::
name|WatchForUnregistration
case|:
name|matchArgs
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|matchArgs
return|;
block|}
end_function
begin_function
DECL|function|addService
name|void
name|QDBusServiceWatcherPrivate
operator|::
name|addService
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|)
block|{
name|QStringList
name|matchArgs
init|=
name|matchArgsForService
argument_list|(
name|service
argument_list|)
decl_stmt|;
name|connection
operator|.
name|connect
argument_list|(
operator|*
name|busService
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|,
operator|*
name|busInterface
argument_list|()
argument_list|,
operator|*
name|signalName
argument_list|()
argument_list|,
name|matchArgs
argument_list|,
name|QString
argument_list|()
argument_list|,
name|q_func
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|_q_serviceOwnerChanged
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeService
name|void
name|QDBusServiceWatcherPrivate
operator|::
name|removeService
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|)
block|{
name|QStringList
name|matchArgs
init|=
name|matchArgsForService
argument_list|(
name|service
argument_list|)
decl_stmt|;
name|connection
operator|.
name|disconnect
argument_list|(
operator|*
name|busService
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|,
operator|*
name|busInterface
argument_list|()
argument_list|,
operator|*
name|signalName
argument_list|()
argument_list|,
name|matchArgs
argument_list|,
name|QString
argument_list|()
argument_list|,
name|q_func
argument_list|()
argument_list|,
name|SLOT
argument_list|(
name|_q_serviceOwnerChanged
argument_list|(
name|QString
argument_list|,
name|QString
argument_list|,
name|QString
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QDBusServiceWatcher     \since 4.6     \inmodule QtDBus      \brief The QDBusServiceWatcher class allows the user to watch for a bus service change.      A QDBusServiceWatcher object can be used to notify the application about     an ownership change of a service name on the bus. It has three watch     modes:      \list       \o Watching for service registration only.       \o Watching for service unregistration only.       \o Watching for any kind of service ownership change (the default mode).     \endlist      Besides being created or deleted, services may change owners without a     unregister/register operation happening. So the serviceRegistered()     and serviceUnregistered() signals may not be emitted if that     happens.      This class is more efficient than using the     QDBusConnectionInterface::serviceOwnerChanged() signal because it allows     one to receive only the signals for which the class is interested in.      \sa QDBusConnection */
end_comment
begin_comment
comment|/*!     \enum QDBusServiceWatcher::WatchModeFlag      QDBusServiceWatcher supports three different watch modes, which are configured by this flag:      \value WatchForRegistration watch for service registration only, ignoring     any signals related to other service ownership change.      \value WatchForUnregistration watch for service unregistration only,     ignoring any signals related to other service ownership change.      \value WatchForOwnerChange watch for any kind of service ownership     change. */
end_comment
begin_comment
comment|/*!     \property QDBusServiceWatcher::watchMode      The \c watchMode property holds the current watch mode for this     QDBusServiceWatcher object. The default value for this property is     QDBusServiceWatcher::WatchForOwnershipChange. */
end_comment
begin_comment
comment|/*!     \property QDBusServiceWatcher::watchedServices      The \c servicesWatched property holds the list of services watched.      Note that modifying this list with setServicesWatched() is an expensive     operation. If you can, prefer to change it by way of addWatchedService()     and removeWatchedService(). */
end_comment
begin_comment
comment|/*!     \fn void QDBusServiceWatcher::serviceRegistered(const QString&serviceName)      This signal is emitted whenever this object detects that the service \a     serviceName became available on the bus.      \sa serviceUnregistered(), serviceOwnerChanged() */
end_comment
begin_comment
comment|/*!     \fn void QDBusServiceWatcher::serviceUnregistered(const QString&serviceName)      This signal is emitted whenever this object detects that the service \a     serviceName was unregistered from the bus and is no longer available.      \sa serviceRegistered(), serviceOwnerChanged() */
end_comment
begin_comment
comment|/*!     \fn void QDBusServiceWatcher::serviceOwnerChanged(const QString&serviceName, const QString&oldOwner, const QString&newOwner)      This signal is emitted whenever this object detects that there was a     service ownership change relating to the \a serviceName service. The \a     oldOwner parameter contains the old owner name and \a newOwner is the new     owner. Both \a oldOwner and \a newOwner are unique connection names.      Note that this signal is also emitted whenever the \a serviceName service     was registered or unregistered. If it was registered, \a oldOwner will     contain an empty string, whereas if it was unregistered, \a newOwner will     contain an empty string.      If you need only to find out if the service is registered or unregistered     only, without being notified that the ownership changed, consider using     the specific modes for those operations. This class is more efficient if     you use the more specific modes.      \sa serviceRegistered(), serviceUnregistered() */
end_comment
begin_comment
comment|/*!     Creates a QDBusServiceWatcher object. Note that until you set a     connection with setConnection(), this object will not emit any signals.      The \a parent parameter is passed to QObject to set the parent of this     object. */
end_comment
begin_constructor
DECL|function|QDBusServiceWatcher
name|QDBusServiceWatcher
operator|::
name|QDBusServiceWatcher
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QDBusServiceWatcherPrivate
argument_list|(
name|QDBusConnection
argument_list|(
name|QString
argument_list|()
argument_list|)
argument_list|,
name|WatchForOwnerChange
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Creates a QDBusServiceWatcher object and attaches it to the \a connection     connection. Also, this function immediately starts watching for \a     watchMode changes to service \a service.      The \a parent parameter is passed to QObject to set the parent of this     object. */
end_comment
begin_constructor
DECL|function|QDBusServiceWatcher
name|QDBusServiceWatcher
operator|::
name|QDBusServiceWatcher
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|,
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|,
name|WatchMode
name|watchMode
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QDBusServiceWatcherPrivate
argument_list|(
name|connection
argument_list|,
name|watchMode
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|setConnection
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|service
argument_list|,
name|connection
argument_list|,
name|watchMode
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QDBusServiceWatcher object and releases any resources     associated with it. */
end_comment
begin_destructor
DECL|function|~QDBusServiceWatcher
name|QDBusServiceWatcher
operator|::
name|~
name|QDBusServiceWatcher
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns the list of D-Bus services that are being watched.      \sa setWatchedServices() */
end_comment
begin_function
DECL|function|watchedServices
name|QStringList
name|QDBusServiceWatcher
operator|::
name|watchedServices
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|servicesWatched
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the list of D-Bus services being watched to be \a services.      Note that setting the entire list means removing all previous rules for     watching services and adding new ones. This is an expensive operation and     should be avoided, if possible. Instead, use addWatchedService() and     removeWatchedService() if you can to manipulate entries in the list. */
end_comment
begin_function
DECL|function|setWatchedServices
name|void
name|QDBusServiceWatcher
operator|::
name|setWatchedServices
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|services
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
name|services
operator|==
name|d
operator|->
name|servicesWatched
condition|)
return|return;
name|d
operator|->
name|setConnection
argument_list|(
name|services
argument_list|,
name|d
operator|->
name|connection
argument_list|,
name|d
operator|->
name|watchMode
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Adds \a newService to the list of services to be watched by this object.     This function is more efficient than setWatchedServices() and should be     used whenever possible to add services. */
end_comment
begin_function
DECL|function|addWatchedService
name|void
name|QDBusServiceWatcher
operator|::
name|addWatchedService
parameter_list|(
specifier|const
name|QString
modifier|&
name|newService
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|servicesWatched
operator|.
name|contains
argument_list|(
name|newService
argument_list|)
condition|)
return|return;
name|d
operator|->
name|addService
argument_list|(
name|newService
argument_list|)
expr_stmt|;
name|d
operator|->
name|servicesWatched
operator|<<
name|newService
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes the \a service from the list of services being watched by this     object. Note that D-Bus notifications are asynchronous, so there may     still be signals pending delivery about \a service. Those signals will     still be emitted whenever the D-Bus messages are processed.      This function returns true if any services were removed. */
end_comment
begin_function
DECL|function|removeWatchedService
name|bool
name|QDBusServiceWatcher
operator|::
name|removeWatchedService
parameter_list|(
specifier|const
name|QString
modifier|&
name|service
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
name|d
operator|->
name|removeService
argument_list|(
name|service
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|servicesWatched
operator|.
name|removeOne
argument_list|(
name|service
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|watchMode
name|QDBusServiceWatcher
operator|::
name|WatchMode
name|QDBusServiceWatcher
operator|::
name|watchMode
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|watchMode
return|;
block|}
end_function
begin_function
DECL|function|setWatchMode
name|void
name|QDBusServiceWatcher
operator|::
name|setWatchMode
parameter_list|(
name|WatchMode
name|mode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|d
operator|->
name|watchMode
condition|)
return|return;
name|d
operator|->
name|setConnection
argument_list|(
name|d
operator|->
name|servicesWatched
argument_list|,
name|d
operator|->
name|connection
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the QDBusConnection that this object is attached to.      \sa setConnection() */
end_comment
begin_function
DECL|function|connection
name|QDBusConnection
name|QDBusServiceWatcher
operator|::
name|connection
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|connection
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the D-Bus connection that this object is attached to be \a     connection. All services watched will be transferred to this connection.      Note that QDBusConnection objects are reference counted:     QDBusServiceWatcher will keep a reference for this connection while it     exists. The connection is not closed until the reference count drops to     zero, so this will ensure that any notifications are received while this     QDBusServiceWatcher object exists.      \sa connection() */
end_comment
begin_function
DECL|function|setConnection
name|void
name|QDBusServiceWatcher
operator|::
name|setConnection
parameter_list|(
specifier|const
name|QDBusConnection
modifier|&
name|connection
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QDBusServiceWatcher
argument_list|)
expr_stmt|;
if|if
condition|(
name|connection
operator|.
name|name
argument_list|()
operator|==
name|d
operator|->
name|connection
operator|.
name|name
argument_list|()
condition|)
return|return;
name|d
operator|->
name|setConnection
argument_list|(
name|d
operator|->
name|servicesWatched
argument_list|,
name|connection
argument_list|,
name|d
operator|->
name|watchMode
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
begin_include
include|#
directive|include
file|"moc_qdbusservicewatcher.cpp"
end_include
end_unit
