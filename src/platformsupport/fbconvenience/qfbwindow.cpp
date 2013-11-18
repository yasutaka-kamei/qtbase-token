begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfbwindow_p.h"
end_include
begin_include
include|#
directive|include
file|"qfbscreen_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
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
DECL|function|QFbWindow
name|QFbWindow
operator|::
name|QFbWindow
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
member_init_list|,
name|mBackingStore
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mWindowState
argument_list|(
name|Qt
operator|::
name|WindowNoState
argument_list|)
block|{
specifier|static
name|QAtomicInt
name|winIdGenerator
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|mWindowId
operator|=
name|winIdGenerator
operator|.
name|fetchAndAddRelaxed
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QFbWindow
name|QFbWindow
operator|::
name|~
name|QFbWindow
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|platformScreen
name|QFbScreen
modifier|*
name|QFbWindow
operator|::
name|platformScreen
parameter_list|()
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|QFbScreen
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
DECL|function|setGeometry
name|void
name|QFbWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
comment|// store previous geometry for screen update
name|mOldGeometry
operator|=
name|geometry
argument_list|()
expr_stmt|;
name|platformScreen
argument_list|()
operator|->
name|invalidateRectCache
argument_list|()
expr_stmt|;
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
name|QFbWindow
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
block|{
if|if
condition|(
name|mWindowState
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
name|mWindowState
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
name|QPlatformWindow
operator|::
name|setVisible
argument_list|(
name|visible
argument_list|)
expr_stmt|;
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
block|}
end_function
begin_function
DECL|function|setWindowState
name|void
name|QFbWindow
operator|::
name|setWindowState
parameter_list|(
name|Qt
operator|::
name|WindowState
name|state
parameter_list|)
block|{
name|QPlatformWindow
operator|::
name|setWindowState
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|mWindowState
operator|=
name|state
expr_stmt|;
name|platformScreen
argument_list|()
operator|->
name|invalidateRectCache
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setWindowFlags
name|void
name|QFbWindow
operator|::
name|setWindowFlags
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
name|mWindowFlags
operator|=
name|flags
expr_stmt|;
name|platformScreen
argument_list|()
operator|->
name|invalidateRectCache
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|windowFlags
name|Qt
operator|::
name|WindowFlags
name|QFbWindow
operator|::
name|windowFlags
parameter_list|()
specifier|const
block|{
return|return
name|mWindowFlags
return|;
block|}
end_function
begin_function
DECL|function|raise
name|void
name|QFbWindow
operator|::
name|raise
parameter_list|()
block|{
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
DECL|function|lower
name|void
name|QFbWindow
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
DECL|function|repaint
name|void
name|QFbWindow
operator|::
name|repaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|QRect
name|currentGeometry
init|=
name|geometry
argument_list|()
decl_stmt|;
name|QRect
name|dirtyClient
init|=
name|region
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|QRect
name|dirtyRegion
argument_list|(
name|currentGeometry
operator|.
name|left
argument_list|()
operator|+
name|dirtyClient
operator|.
name|left
argument_list|()
argument_list|,
name|currentGeometry
operator|.
name|top
argument_list|()
operator|+
name|dirtyClient
operator|.
name|top
argument_list|()
argument_list|,
name|dirtyClient
operator|.
name|width
argument_list|()
argument_list|,
name|dirtyClient
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|QRect
name|mOldGeometryLocal
init|=
name|mOldGeometry
decl_stmt|;
name|mOldGeometry
operator|=
name|currentGeometry
expr_stmt|;
comment|// If this is a move, redraw the previous location
if|if
condition|(
name|mOldGeometryLocal
operator|!=
name|currentGeometry
condition|)
name|platformScreen
argument_list|()
operator|->
name|setDirty
argument_list|(
name|mOldGeometryLocal
argument_list|)
expr_stmt|;
name|platformScreen
argument_list|()
operator|->
name|setDirty
argument_list|(
name|dirtyRegion
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
