begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandwindowmanagerintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandwindowmanager-client-protocol.h"
end_include
begin_include
include|#
directive|include
file|<stdint.h>
end_include
begin_function
DECL|function|createIntegration
name|QWaylandWindowManagerIntegration
modifier|*
name|QWaylandWindowManagerIntegration
operator|::
name|createIntegration
parameter_list|(
name|QWaylandDisplay
modifier|*
name|waylandDisplay
parameter_list|)
block|{
return|return
operator|new
name|QWaylandWindowManagerIntegration
argument_list|(
name|waylandDisplay
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QWaylandWindowManagerIntegration
name|QWaylandWindowManagerIntegration
operator|::
name|QWaylandWindowManagerIntegration
parameter_list|(
name|QWaylandDisplay
modifier|*
name|waylandDisplay
parameter_list|)
member_init_list|:
name|mWaylandDisplay
argument_list|(
name|waylandDisplay
argument_list|)
member_init_list|,
name|mWaylandWindowManager
argument_list|(
literal|0
argument_list|)
block|{
name|wl_display_add_global_listener
argument_list|(
name|mWaylandDisplay
operator|->
name|wl_display
argument_list|()
argument_list|,
name|QWaylandWindowManagerIntegration
operator|::
name|wlHandleListenerGlobal
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWaylandWindowManagerIntegration
name|QWaylandWindowManagerIntegration
operator|::
name|~
name|QWaylandWindowManagerIntegration
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|windowManager
name|struct
name|wl_windowmanager
modifier|*
name|QWaylandWindowManagerIntegration
operator|::
name|windowManager
parameter_list|()
specifier|const
block|{
return|return
name|mWaylandWindowManager
return|;
block|}
end_function
begin_function
DECL|function|wlHandleListenerGlobal
name|void
name|QWaylandWindowManagerIntegration
operator|::
name|wlHandleListenerGlobal
parameter_list|(
name|wl_display
modifier|*
name|display
parameter_list|,
name|uint32_t
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|interface
parameter_list|,
name|uint32_t
name|version
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|interface
argument_list|,
literal|"wl_windowmanager"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|QWaylandWindowManagerIntegration
modifier|*
name|integration
init|=
cast|static_cast
argument_list|<
name|QWaylandWindowManagerIntegration
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|integration
operator|->
name|mWaylandWindowManager
operator|=
name|wl_windowmanager_create
argument_list|(
name|display
argument_list|,
name|id
argument_list|,
name|version
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|mapClientToProcess
name|void
name|QWaylandWindowManagerIntegration
operator|::
name|mapClientToProcess
parameter_list|(
name|long
name|long
name|processId
parameter_list|)
block|{
name|wl_windowmanager_map_client_to_process
argument_list|(
name|mWaylandWindowManager
argument_list|,
operator|(
name|uint32_t
operator|)
name|processId
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
