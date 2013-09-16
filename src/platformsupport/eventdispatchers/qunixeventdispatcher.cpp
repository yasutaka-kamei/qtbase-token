begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"qunixeventdispatcher_qpa_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qguiapplication_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QElapsedTimer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QAtomicInt>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSemaphore>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_macro
name|QT_USE_NAMESPACE
end_macro
begin_constructor
DECL|function|QUnixEventDispatcherQPA
name|QUnixEventDispatcherQPA
operator|::
name|QUnixEventDispatcherQPA
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QEventDispatcherUNIX
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QUnixEventDispatcherQPA
name|QUnixEventDispatcherQPA
operator|::
name|~
name|QUnixEventDispatcherQPA
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|processEvents
name|bool
name|QUnixEventDispatcherQPA
operator|::
name|processEvents
parameter_list|(
name|QEventLoop
operator|::
name|ProcessEventsFlags
name|flags
parameter_list|)
block|{
specifier|const
name|bool
name|didSendEvents
init|=
name|QEventDispatcherUNIX
operator|::
name|processEvents
argument_list|(
name|flags
argument_list|)
decl_stmt|;
return|return
name|QWindowSystemInterface
operator|::
name|sendWindowSystemEvents
argument_list|(
name|flags
argument_list|)
operator|||
name|didSendEvents
return|;
block|}
end_function
begin_function
DECL|function|hasPendingEvents
name|bool
name|QUnixEventDispatcherQPA
operator|::
name|hasPendingEvents
parameter_list|()
block|{
specifier|extern
name|uint
name|qGlobalPostedEventsCount
argument_list|()
decl_stmt|;
comment|// from qapplication.cpp
return|return
name|qGlobalPostedEventsCount
argument_list|()
operator|||
name|QWindowSystemInterface
operator|::
name|windowSystemEventsQueued
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QUnixEventDispatcherQPA
operator|::
name|flush
parameter_list|()
block|{
if|if
condition|(
name|qApp
condition|)
name|qApp
operator|->
name|sendPostedEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
