begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014-2015 Canonical, Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL3$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPLv3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or later as published by the Free ** Software Foundation and appearing in the file LICENSE.GPL included in ** the packaging of this file. Please review the following information to ** ensure the GNU General Public License version 2.0 requirements will be ** met: http://www.gnu.org/licenses/gpl-2.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// Qt
end_comment
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontextfactory_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixfontdatabase_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qgenericunixeventdispatcher_p.h>
end_include
begin_include
include|#
directive|include
file|<QOpenGLContext>
end_include
begin_comment
comment|// Local
end_comment
begin_include
include|#
directive|include
file|"qmirclientbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientclipboard.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientinput.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientintegration.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientlogging.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientscreen.h"
end_include
begin_include
include|#
directive|include
file|"qmirclienttheme.h"
end_include
begin_include
include|#
directive|include
file|"qmirclientwindow.h"
end_include
begin_comment
comment|// platform-api
end_comment
begin_include
include|#
directive|include
file|<ubuntu/application/lifecycle_delegate.h>
end_include
begin_include
include|#
directive|include
file|<ubuntu/application/id.h>
end_include
begin_include
include|#
directive|include
file|<ubuntu/application/options.h>
end_include
begin_function
DECL|function|resumedCallback
specifier|static
name|void
name|resumedCallback
parameter_list|(
specifier|const
name|UApplicationOptions
modifier|*
name|options
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|options
argument_list|)
name|Q_UNUSED
argument_list|(
argument|context
argument_list|)
name|DASSERT
argument_list|(
name|context
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
argument_list|,
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|ApplicationActivate
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|aboutToStopCallback
specifier|static
name|void
name|aboutToStopCallback
parameter_list|(
name|UApplicationArchive
modifier|*
name|archive
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|archive
argument_list|)
name|DASSERT
argument_list|(
name|context
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|QMirClientClientIntegration
modifier|*
name|integration
init|=
cast|static_cast
argument_list|<
name|QMirClientClientIntegration
operator|*
argument_list|>
argument_list|(
name|context
argument_list|)
decl_stmt|;
name|integration
operator|->
name|inputContext
argument_list|()
operator|->
name|hideInputPanel
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
argument_list|,
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|ApplicationDeactivate
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QMirClientClientIntegration
name|QMirClientClientIntegration
operator|::
name|QMirClientClientIntegration
parameter_list|()
member_init_list|:
name|QPlatformIntegration
argument_list|()
member_init_list|,
name|mNativeInterface
argument_list|(
operator|new
name|QMirClientNativeInterface
argument_list|)
member_init_list|,
name|mFontDb
argument_list|(
operator|new
name|QGenericUnixFontDatabase
argument_list|)
member_init_list|,
name|mServices
argument_list|(
operator|new
name|QMirClientPlatformServices
argument_list|)
member_init_list|,
name|mClipboard
argument_list|(
operator|new
name|QMirClientClipboard
argument_list|)
member_init_list|,
name|mScaleFactor
argument_list|(
literal|1.0
argument_list|)
block|{
name|setupOptions
argument_list|()
expr_stmt|;
name|setupDescription
argument_list|()
expr_stmt|;
comment|// Create new application instance
name|mInstance
operator|=
name|u_application_instance_new_from_description_with_options
argument_list|(
name|mDesc
argument_list|,
name|mOptions
argument_list|)
expr_stmt|;
if|if
condition|(
name|mInstance
operator|==
literal|nullptr
condition|)
name|qFatal
argument_list|(
literal|"QMirClientClientIntegration: connection to Mir server failed. Check that a Mir server is\n"
literal|"running, and the correct socket is being used and is accessible. The shell may have\n"
literal|"rejected the incoming connection, so check its log file"
argument_list|)
expr_stmt|;
comment|// Create default screen.
name|mScreen
operator|=
operator|new
name|QMirClientScreen
argument_list|(
name|u_application_instance_get_mir_connection
argument_list|(
name|mInstance
argument_list|)
argument_list|)
expr_stmt|;
name|screenAdded
argument_list|(
name|mScreen
argument_list|)
expr_stmt|;
comment|// Initialize input.
if|if
condition|(
name|qEnvironmentVariableIsEmpty
argument_list|(
literal|"QTUBUNTU_NO_INPUT"
argument_list|)
condition|)
block|{
name|mInput
operator|=
operator|new
name|QMirClientInput
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|mInputContext
operator|=
name|QPlatformInputContextFactory
operator|::
name|create
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|mInput
operator|=
literal|nullptr
expr_stmt|;
name|mInputContext
operator|=
literal|nullptr
expr_stmt|;
block|}
comment|// compute the scale factor
specifier|const
name|int
name|defaultGridUnit
init|=
literal|8
decl_stmt|;
name|int
name|gridUnit
init|=
name|defaultGridUnit
decl_stmt|;
name|QByteArray
name|gridUnitString
init|=
name|qgetenv
argument_list|(
literal|"GRID_UNIT_PX"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|gridUnitString
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|bool
name|ok
decl_stmt|;
name|gridUnit
operator|=
name|gridUnitString
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
name|gridUnit
operator|=
name|defaultGridUnit
expr_stmt|;
block|}
block|}
name|mScaleFactor
operator|=
cast|static_cast
argument_list|<
name|qreal
argument_list|>
argument_list|(
name|gridUnit
argument_list|)
operator|/
name|defaultGridUnit
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QMirClientClientIntegration
name|QMirClientClientIntegration
operator|::
name|~
name|QMirClientClientIntegration
parameter_list|()
block|{
operator|delete
name|mInput
expr_stmt|;
operator|delete
name|mInputContext
expr_stmt|;
operator|delete
name|mScreen
expr_stmt|;
operator|delete
name|mServices
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QMirClientClientIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
return|return
name|mServices
return|;
block|}
end_function
begin_function
DECL|function|setupOptions
name|void
name|QMirClientClientIntegration
operator|::
name|setupOptions
parameter_list|()
block|{
name|QStringList
name|args
init|=
name|QCoreApplication
operator|::
name|arguments
argument_list|()
decl_stmt|;
name|int
name|argc
init|=
name|args
operator|.
name|size
argument_list|()
operator|+
literal|1
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
init|=
operator|new
name|char
operator|*
index|[
name|argc
index|]
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|argc
operator|-
literal|1
condition|;
name|i
operator|++
control|)
name|argv
index|[
name|i
index|]
operator|=
name|qstrdup
argument_list|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
name|argv
index|[
name|argc
operator|-
literal|1
index|]
operator|=
literal|nullptr
expr_stmt|;
name|mOptions
operator|=
name|u_application_options_new_from_cmd_line
argument_list|(
name|argc
operator|-
literal|1
argument_list|,
name|argv
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|argc
condition|;
name|i
operator|++
control|)
operator|delete
index|[]
name|argv
index|[
name|i
index|]
expr_stmt|;
operator|delete
index|[]
name|argv
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setupDescription
name|void
name|QMirClientClientIntegration
operator|::
name|setupDescription
parameter_list|()
block|{
name|mDesc
operator|=
name|u_application_description_new
argument_list|()
expr_stmt|;
name|UApplicationId
modifier|*
name|id
init|=
name|u_application_id_new_from_stringn
argument_list|(
literal|"QtUbuntu"
argument_list|,
literal|8
argument_list|)
decl_stmt|;
name|u_application_description_set_application_id
argument_list|(
name|mDesc
argument_list|,
name|id
argument_list|)
expr_stmt|;
name|UApplicationLifecycleDelegate
modifier|*
name|delegate
init|=
name|u_application_lifecycle_delegate_new
argument_list|()
decl_stmt|;
name|u_application_lifecycle_delegate_set_application_resumed_cb
argument_list|(
name|delegate
argument_list|,
operator|&
name|resumedCallback
argument_list|)
expr_stmt|;
name|u_application_lifecycle_delegate_set_application_about_to_stop_cb
argument_list|(
name|delegate
argument_list|,
operator|&
name|aboutToStopCallback
argument_list|)
expr_stmt|;
name|u_application_lifecycle_delegate_set_context
argument_list|(
name|delegate
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|u_application_description_set_application_lifecycle_delegate
argument_list|(
name|mDesc
argument_list|,
name|delegate
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QMirClientClientIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
cast|const_cast
argument_list|<
name|QMirClientClientIntegration
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|createPlatformWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QMirClientClientIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|QPlatformWindow
modifier|*
name|platformWindow
init|=
operator|new
name|QMirClientWindow
argument_list|(
name|window
argument_list|,
name|mClipboard
argument_list|,
cast|static_cast
argument_list|<
name|QMirClientScreen
operator|*
argument_list|>
argument_list|(
name|mScreen
argument_list|)
argument_list|,
name|mInput
argument_list|,
name|u_application_instance_get_mir_connection
argument_list|(
name|mInstance
argument_list|)
argument_list|)
decl_stmt|;
name|platformWindow
operator|->
name|requestActivateWindow
argument_list|()
expr_stmt|;
return|return
name|platformWindow
return|;
block|}
end_function
begin_function
DECL|function|hasCapability
name|bool
name|QMirClientClientIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
return|return
literal|true
return|;
break|break;
case|case
name|OpenGL
case|:
return|return
literal|true
return|;
break|break;
case|case
name|ThreadedOpenGL
case|:
if|if
condition|(
name|qEnvironmentVariableIsEmpty
argument_list|(
literal|"QTUBUNTU_NO_THREADED_OPENGL"
argument_list|)
condition|)
block|{
return|return
literal|true
return|;
block|}
else|else
block|{
name|DLOG
argument_list|(
literal|"ubuntumirclient: disabled threaded OpenGL"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
break|break;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QMirClientClientIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
name|createUnixEventDispatcher
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QMirClientClientIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QMirClientBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QMirClientClientIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
return|return
cast|const_cast
argument_list|<
name|QMirClientClientIntegration
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
operator|->
name|createPlatformOpenGLContext
argument_list|(
name|context
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QMirClientClientIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
return|return
operator|new
name|QMirClientOpenGLContext
argument_list|(
cast|static_cast
argument_list|<
name|QMirClientScreen
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|QMirClientOpenGLContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|shareHandle
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|themeNames
name|QStringList
name|QMirClientClientIntegration
operator|::
name|themeNames
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|QMirClientTheme
operator|::
name|name
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformTheme
name|QPlatformTheme
modifier|*
name|QMirClientClientIntegration
operator|::
name|createPlatformTheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
operator|new
name|QMirClientTheme
return|;
block|}
end_function
begin_function
DECL|function|styleHint
name|QVariant
name|QMirClientClientIntegration
operator|::
name|styleHint
parameter_list|(
name|StyleHint
name|hint
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|QPlatformIntegration
operator|::
name|StartDragDistance
case|:
block|{
comment|// default is 10 pixels (see QPlatformTheme::defaultThemeHint)
return|return
literal|10.0
operator|*
name|mScaleFactor
return|;
block|}
case|case
name|QPlatformIntegration
operator|::
name|PasswordMaskDelay
case|:
block|{
comment|// return time in milliseconds - 1 second
return|return
name|QVariant
argument_list|(
literal|1000
argument_list|)
return|;
block|}
default|default:
break|break;
block|}
return|return
name|QPlatformIntegration
operator|::
name|styleHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QMirClientClientIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
return|return
name|mClipboard
operator|.
name|data
argument_list|()
return|;
block|}
end_function
end_unit