begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformwindow.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformopenglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformscreen.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimain.h"
end_include
begin_include
include|#
directive|include
file|<qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QAndroidPlatformWindow
name|QAndroidPlatformWindow
operator|::
name|QAndroidPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|window
argument_list|)
block|{
name|m_windowFlags
operator|=
name|Qt
operator|::
name|Widget
expr_stmt|;
name|m_windowState
operator|=
name|Qt
operator|::
name|WindowNoState
expr_stmt|;
specifier|static
name|QAtomicInt
name|winIdGenerator
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|m_windowId
operator|=
name|winIdGenerator
operator|.
name|fetchAndAddRelaxed
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|setWindowState
argument_list|(
name|window
operator|->
name|windowState
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|lower
name|void
name|QAndroidPlatformWindow
operator|::
name|lower
parameter_list|()
block|{
name|platformScreen
argument_list|()
operator|->
name|lower
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|raise
name|void
name|QAndroidPlatformWindow
operator|::
name|raise
parameter_list|()
block|{
name|updateStatusBarVisibility
argument_list|()
expr_stmt|;
name|platformScreen
argument_list|()
operator|->
name|raise
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QAndroidPlatformWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setVisible
name|void
name|QAndroidPlatformWindow
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
if|if
condition|(
name|visible
condition|)
name|updateStatusBarVisibility
argument_list|()
expr_stmt|;
if|if
condition|(
name|visible
condition|)
block|{
if|if
condition|(
name|m_windowState
operator|&
name|Qt
operator|::
name|WindowFullScreen
condition|)
name|setGeometry
argument_list|(
name|platformScreen
argument_list|()
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|m_windowState
operator|&
name|Qt
operator|::
name|WindowMaximized
condition|)
name|setGeometry
argument_list|(
name|platformScreen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|visible
condition|)
name|platformScreen
argument_list|()
operator|->
name|addWindow
argument_list|(
name|this
argument_list|)
expr_stmt|;
else|else
name|platformScreen
argument_list|()
operator|->
name|removeWindow
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QRect
name|availableGeometry
init|=
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
decl_stmt|;
if|if
condition|(
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
operator|>
literal|0
operator|&&
name|availableGeometry
operator|.
name|width
argument_list|()
operator|>
literal|0
operator|&&
name|availableGeometry
operator|.
name|height
argument_list|()
operator|>
literal|0
condition|)
name|QPlatformWindow
operator|::
name|setVisible
argument_list|(
name|visible
argument_list|)
expr_stmt|;
comment|// The Android Activity is activated before Qt is initialized, causing the application state to
comment|// never be set to 'active'. We explicitly set this state when the first window becomes visible.
if|if
condition|(
name|visible
condition|)
name|QtAndroid
operator|::
name|setApplicationActive
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setWindowState
name|void
name|QAndroidPlatformWindow
operator|::
name|setWindowState
parameter_list|(
name|Qt
operator|::
name|WindowState
name|state
parameter_list|)
block|{
if|if
condition|(
name|m_windowState
operator|==
name|state
condition|)
return|return;
name|QPlatformWindow
operator|::
name|setWindowState
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|m_windowState
operator|=
name|state
expr_stmt|;
if|if
condition|(
name|window
argument_list|()
operator|->
name|isVisible
argument_list|()
condition|)
name|updateStatusBarVisibility
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setWindowFlags
name|void
name|QAndroidPlatformWindow
operator|::
name|setWindowFlags
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
if|if
condition|(
name|m_windowFlags
operator|==
name|flags
condition|)
return|return;
name|m_windowFlags
operator|=
name|flags
expr_stmt|;
block|}
end_function
begin_function
DECL|function|windowFlags
name|Qt
operator|::
name|WindowFlags
name|QAndroidPlatformWindow
operator|::
name|windowFlags
parameter_list|()
specifier|const
block|{
return|return
name|m_windowFlags
return|;
block|}
end_function
begin_function
DECL|function|setParent
name|void
name|QAndroidPlatformWindow
operator|::
name|setParent
parameter_list|(
specifier|const
name|QPlatformWindow
modifier|*
name|window
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformScreen
name|QAndroidPlatformScreen
modifier|*
name|QAndroidPlatformWindow
operator|::
name|platformScreen
parameter_list|()
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|QAndroidPlatformScreen
operator|*
argument_list|>
argument_list|(
name|window
argument_list|()
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|propagateSizeHints
name|void
name|QAndroidPlatformWindow
operator|::
name|propagateSizeHints
parameter_list|()
block|{
comment|//shut up warning from default implementation
block|}
end_function
begin_function
DECL|function|requestActivateWindow
name|void
name|QAndroidPlatformWindow
operator|::
name|requestActivateWindow
parameter_list|()
block|{
name|platformScreen
argument_list|()
operator|->
name|topWindowChanged
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateStatusBarVisibility
name|void
name|QAndroidPlatformWindow
operator|::
name|updateStatusBarVisibility
parameter_list|()
block|{
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|window
argument_list|()
operator|->
name|flags
argument_list|()
decl_stmt|;
name|bool
name|isNonRegularWindow
init|=
name|flags
operator|&
operator|(
name|Qt
operator|::
name|Popup
operator||
name|Qt
operator|::
name|Dialog
operator||
name|Qt
operator|::
name|Sheet
operator|)
operator|&
operator|~
name|Qt
operator|::
name|Window
decl_stmt|;
if|if
condition|(
operator|!
name|isNonRegularWindow
condition|)
block|{
if|if
condition|(
name|m_windowState
operator|&
name|Qt
operator|::
name|WindowFullScreen
condition|)
name|QtAndroid
operator|::
name|hideStatusBar
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|m_windowState
operator|&
name|Qt
operator|::
name|WindowMaximized
condition|)
name|QtAndroid
operator|::
name|showStatusBar
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|isExposed
name|bool
name|QAndroidPlatformWindow
operator|::
name|isExposed
parameter_list|()
specifier|const
block|{
return|return
name|qApp
operator|->
name|applicationState
argument_list|()
operator|>
name|Qt
operator|::
name|ApplicationHidden
operator|&&
name|window
argument_list|()
operator|->
name|isVisible
argument_list|()
operator|&&
operator|!
name|window
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|applicationStateChanged
name|void
name|QAndroidPlatformWindow
operator|::
name|applicationStateChanged
parameter_list|(
name|Qt
operator|::
name|ApplicationState
parameter_list|)
block|{
name|QRegion
name|region
decl_stmt|;
if|if
condition|(
name|isExposed
argument_list|()
condition|)
name|region
operator|=
name|QRect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|window
argument_list|()
argument_list|,
name|region
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|flushWindowSystemEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
