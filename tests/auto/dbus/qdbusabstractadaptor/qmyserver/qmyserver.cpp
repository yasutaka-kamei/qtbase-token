begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QtCore>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_include
include|#
directive|include
file|"../myobject.h"
end_include
begin_decl_stmt
DECL|variable|serviceName
specifier|static
specifier|const
name|char
name|serviceName
index|[]
init|=
literal|"org.qtproject.autotests.qmyserver"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|objectPath
specifier|static
specifier|const
name|char
name|objectPath
index|[]
init|=
literal|"/org/qtproject/qmyserver"
decl_stmt|;
end_decl_stmt
begin_comment
comment|//static const char *interfaceName = serviceName;
end_comment
begin_decl_stmt
DECL|variable|slotSpy
specifier|const
name|char
modifier|*
name|slotSpy
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|valueSpy
name|QString
name|valueSpy
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QDBusConnection::RegisterOptions
argument_list|)
end_macro
begin_class
DECL|class|MyServer
class|class
name|MyServer
super|:
specifier|public
name|QDBusServer
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"org.qtproject.autotests.qmyserver"
argument_list|)
decl|public
range|:
DECL|function|MyServer
name|MyServer
argument_list|(
argument|QString addr =
literal|"unix:tmpdir=/tmp"
argument_list|,
argument|QObject* parent =
literal|0
argument_list|)
operator|:
name|QDBusServer
argument_list|(
name|addr
argument_list|,
name|parent
argument_list|)
decl_stmt|,
name|m_conn
argument_list|(
literal|"none"
argument_list|)
decl_stmt|,
name|obj
argument_list|(
name|NULL
argument_list|)
argument_list|{
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|newConnection
argument_list|(
name|QDBusConnection
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|handleConnection
argument_list|(
name|QDBusConnection
argument_list|)
argument_list|)
argument_list|)
argument_list|;     }
DECL|function|~MyServer
name|~
name|MyServer
argument_list|()
argument_list|{         if
operator|(
name|obj
operator|)
name|obj
operator|->
name|deleteLater
argument_list|()
argument_list|;     }
decl|public
name|slots
range|:
DECL|function|address
name|QString
name|address
argument_list|()
specifier|const
block|{
return|return
name|QDBusServer
operator|::
name|address
argument_list|()
return|;
block|}
DECL|function|isConnected
name|bool
name|isConnected
parameter_list|()
specifier|const
block|{
return|return
name|m_conn
operator|.
name|isConnected
argument_list|()
return|;
block|}
DECL|function|emitSignal
name|void
name|emitSignal
parameter_list|(
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QDBusVariant
modifier|&
name|parameter
parameter_list|)
block|{
if|if
condition|(
name|interface
operator|.
name|endsWith
argument_list|(
literal|'2'
argument_list|)
condition|)
name|obj
operator|->
name|if2
operator|->
name|emitSignal
argument_list|(
name|name
argument_list|,
name|parameter
operator|.
name|variant
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|interface
operator|.
name|endsWith
argument_list|(
literal|'3'
argument_list|)
condition|)
name|obj
operator|->
name|if3
operator|->
name|emitSignal
argument_list|(
name|name
argument_list|,
name|parameter
operator|.
name|variant
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|interface
operator|.
name|endsWith
argument_list|(
literal|'4'
argument_list|)
condition|)
name|obj
operator|->
name|if4
operator|->
name|emitSignal
argument_list|(
name|name
argument_list|,
name|parameter
operator|.
name|variant
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|obj
operator|->
name|emitSignal
argument_list|(
name|name
argument_list|,
name|parameter
operator|.
name|variant
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|emitSignal2
name|void
name|emitSignal2
parameter_list|(
specifier|const
name|QString
modifier|&
name|interface
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
if|if
condition|(
name|interface
operator|.
name|endsWith
argument_list|(
literal|'2'
argument_list|)
condition|)
name|obj
operator|->
name|if2
operator|->
name|emitSignal
argument_list|(
name|name
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|interface
operator|.
name|endsWith
argument_list|(
literal|'3'
argument_list|)
condition|)
name|obj
operator|->
name|if3
operator|->
name|emitSignal
argument_list|(
name|name
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|interface
operator|.
name|endsWith
argument_list|(
literal|'4'
argument_list|)
condition|)
name|obj
operator|->
name|if4
operator|->
name|emitSignal
argument_list|(
name|name
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|obj
operator|->
name|emitSignal
argument_list|(
name|name
argument_list|,
name|QVariant
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|newMyObject
name|void
name|newMyObject
parameter_list|(
name|int
name|nInterfaces
init|=
literal|4
parameter_list|)
block|{
if|if
condition|(
name|obj
condition|)
name|obj
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|obj
operator|=
operator|new
name|MyObject
argument_list|(
name|nInterfaces
argument_list|)
expr_stmt|;
block|}
DECL|function|registerMyObject
name|void
name|registerMyObject
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|int
name|options
parameter_list|)
block|{
name|m_conn
operator|.
name|registerObject
argument_list|(
name|path
argument_list|,
name|obj
argument_list|,
operator|(
name|QDBusConnection
operator|::
name|RegisterOptions
operator|)
name|options
argument_list|)
expr_stmt|;
block|}
DECL|function|slotSpyServer
name|QString
name|slotSpyServer
parameter_list|()
block|{
return|return
name|QLatin1String
argument_list|(
name|slotSpy
argument_list|)
return|;
block|}
DECL|function|valueSpyServer
name|QString
name|valueSpyServer
parameter_list|()
block|{
return|return
name|valueSpy
return|;
block|}
DECL|function|clearValueSpy
name|void
name|clearValueSpy
parameter_list|()
block|{
name|valueSpy
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
private|private
name|slots
private|:
DECL|function|handleConnection
name|void
name|handleConnection
parameter_list|(
specifier|const
name|QDBusConnection
modifier|&
name|con
parameter_list|)
block|{
name|m_conn
operator|=
name|con
expr_stmt|;
block|}
private|private:
DECL|member|m_conn
name|QDBusConnection
name|m_conn
decl_stmt|;
DECL|member|obj
name|MyObject
modifier|*
name|obj
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QDBusConnection
name|con
init|=
name|QDBusConnection
operator|::
name|sessionBus
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|con
operator|.
name|isConnected
argument_list|()
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|con
operator|.
name|registerService
argument_list|(
name|serviceName
argument_list|)
condition|)
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|MyServer
name|server
decl_stmt|;
name|con
operator|.
name|registerObject
argument_list|(
name|objectPath
argument_list|,
operator|&
name|server
argument_list|,
name|QDBusConnection
operator|::
name|ExportAllSlots
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ready.\n"
argument_list|)
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
begin_include
include|#
directive|include
file|"qmyserver.moc"
end_include
end_unit
