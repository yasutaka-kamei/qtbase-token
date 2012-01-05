begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//#include<QDebug>
end_comment
begin_include
include|#
directive|include
file|"qkmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qkmsdevice.h"
end_include
begin_include
include|#
directive|include
file|"qkmsintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcore_unix_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QKmsDevice
name|QKmsDevice
operator|::
name|QKmsDevice
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|,
name|QKmsIntegration
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_integration
argument_list|(
name|parent
argument_list|)
block|{
name|m_fd
operator|=
name|QT_OPEN
argument_list|(
name|path
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_fd
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not open %s."
argument_list|,
name|path
operator|.
name|toAscii
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"No DRM display device"
argument_list|)
expr_stmt|;
block|}
name|m_graphicsBufferManager
operator|=
name|gbm_create_device
argument_list|(
name|m_fd
argument_list|)
expr_stmt|;
name|m_eglDisplay
operator|=
name|eglGetDisplay
argument_list|(
name|m_graphicsBufferManager
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglDisplay
operator|==
name|EGL_NO_DISPLAY
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not open EGL display"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL error"
argument_list|)
expr_stmt|;
block|}
name|EGLint
name|major
decl_stmt|;
name|EGLint
name|minor
decl_stmt|;
if|if
condition|(
operator|!
name|eglInitialize
argument_list|(
name|m_eglDisplay
argument_list|,
operator|&
name|major
argument_list|,
operator|&
name|minor
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not initialize EGL display"
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL error"
argument_list|)
expr_stmt|;
block|}
name|QString
name|extensions
init|=
name|eglQueryString
argument_list|(
name|m_eglDisplay
argument_list|,
name|EGL_EXTENSIONS
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|extensions
operator|.
name|contains
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"EGL_KHR_surfaceless_opengl"
argument_list|)
argument_list|)
condition|)
block|{
name|qFatal
argument_list|(
literal|"EGL_KHR_surfaceless_opengl extension not available"
argument_list|)
expr_stmt|;
block|}
comment|//Initialize EGLContext
specifier|static
name|EGLint
name|contextAttribs
index|[]
init|=
block|{
name|EGL_CONTEXT_CLIENT_VERSION
block|,
literal|2
block|,
name|EGL_NONE
block|}
decl_stmt|;
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
expr_stmt|;
name|m_eglContext
operator|=
name|eglCreateContext
argument_list|(
name|m_eglDisplay
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|contextAttribs
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglContext
operator|==
name|EGL_NO_CONTEXT
condition|)
block|{
name|qWarning
argument_list|(
literal|"Could not create the EGL context."
argument_list|)
expr_stmt|;
name|eglTerminate
argument_list|(
name|m_eglDisplay
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"EGL error"
argument_list|)
expr_stmt|;
block|}
name|createScreens
argument_list|()
expr_stmt|;
name|QSocketNotifier
modifier|*
name|notifier
init|=
operator|new
name|QSocketNotifier
argument_list|(
name|m_fd
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|notifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|handlePageFlipCompleted
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QKmsDevice
name|QKmsDevice
operator|::
name|~
name|QKmsDevice
parameter_list|()
block|{
if|if
condition|(
name|m_eglContext
operator|!=
name|EGL_NO_CONTEXT
condition|)
block|{
name|eglDestroyContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglContext
argument_list|)
expr_stmt|;
name|m_eglContext
operator|=
name|EGL_NO_CONTEXT
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|createScreens
name|void
name|QKmsDevice
operator|::
name|createScreens
parameter_list|()
block|{
name|drmModeRes
modifier|*
name|resources
init|=
literal|0
decl_stmt|;
name|resources
operator|=
name|drmModeGetResources
argument_list|(
name|m_fd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|resources
condition|)
name|qFatal
argument_list|(
literal|"drmModeGetResources failed"
argument_list|)
expr_stmt|;
comment|//Iterate connectors and create screens on each one active
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|resources
operator|->
name|count_connectors
condition|;
name|i
operator|++
control|)
block|{
name|drmModeConnector
modifier|*
name|connector
init|=
literal|0
decl_stmt|;
name|connector
operator|=
name|drmModeGetConnector
argument_list|(
name|m_fd
argument_list|,
name|resources
operator|->
name|connectors
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|connector
operator|&&
name|connector
operator|->
name|connection
operator|==
name|DRM_MODE_CONNECTED
condition|)
block|{
name|m_integration
operator|->
name|addScreen
argument_list|(
operator|new
name|QKmsScreen
argument_list|(
name|this
argument_list|,
name|connector
operator|->
name|connector_id
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|drmModeFreeConnector
argument_list|(
name|connector
argument_list|)
expr_stmt|;
block|}
name|drmModeFreeResources
argument_list|(
name|resources
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|handlePageFlipCompleted
name|void
name|QKmsDevice
operator|::
name|handlePageFlipCompleted
parameter_list|()
block|{
comment|//qDebug()<< "Display signal recieved";
name|drmEventContext
name|eventContext
decl_stmt|;
name|memset
argument_list|(
operator|&
name|eventContext
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
name|eventContext
argument_list|)
expr_stmt|;
name|eventContext
operator|.
name|version
operator|=
name|DRM_EVENT_CONTEXT_VERSION
expr_stmt|;
name|eventContext
operator|.
name|page_flip_handler
operator|=
name|QKmsDevice
operator|::
name|pageFlipHandler
expr_stmt|;
name|drmHandleEvent
argument_list|(
name|m_fd
argument_list|,
operator|&
name|eventContext
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pageFlipHandler
name|void
name|QKmsDevice
operator|::
name|pageFlipHandler
parameter_list|(
name|int
name|fd
parameter_list|,
name|unsigned
name|int
name|frame
parameter_list|,
name|unsigned
name|int
name|sec
parameter_list|,
name|unsigned
name|int
name|usec
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|fd
argument_list|)
name|Q_UNUSED
argument_list|(
argument|frame
argument_list|)
name|Q_UNUSED
argument_list|(
argument|sec
argument_list|)
name|Q_UNUSED
argument_list|(
argument|usec
argument_list|)
specifier|static
name|unsigned
name|int
name|previousTime
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|currentTime
init|=
name|sec
operator|*
literal|1000000
operator|+
name|usec
decl_stmt|;
name|unsigned
name|int
name|refreshTime
init|=
literal|0
decl_stmt|;
comment|//    qDebug()<< "fd: "<< fd<< " frame: "<< frame<< " sec: "
comment|//<< sec<< " usec: "<< usec<< " data: "<< data
comment|//<< "msecs"<< sec * 1000 + usec / 1000;
name|QKmsScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QKmsScreen
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
name|previousTime
operator|==
literal|0
condition|)
name|refreshTime
operator|=
literal|16000
expr_stmt|;
else|else
name|refreshTime
operator|=
name|currentTime
operator|-
name|previousTime
expr_stmt|;
name|screen
operator|->
name|setFlipReady
argument_list|(
name|refreshTime
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
