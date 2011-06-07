begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWAYLANDXCOMPOSITEGLXINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QWAYLANDXCOMPOSITEGLXINTEGRATION_H
define|#
directive|define
name|QWAYLANDXCOMPOSITEGLXINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|"gl_integration/qwaylandglintegration.h"
end_include
begin_include
include|#
directive|include
file|"wayland-client.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDataStream>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaType>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_struct_decl
struct_decl|struct
name|wl_xcomposite
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|QWaylandXCompositeGLXIntegration
range|:
name|public
name|QWaylandGLIntegration
block|{
name|public
operator|:
name|QWaylandXCompositeGLXIntegration
argument_list|(
name|QWaylandDisplay
operator|*
name|waylandDispaly
argument_list|)
block|;
operator|~
name|QWaylandXCompositeGLXIntegration
argument_list|()
block|;
name|void
name|initialize
argument_list|()
block|;
name|QWaylandWindow
operator|*
name|createEglWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|QPlatformGLContext
operator|*
name|createPlatformGLContext
argument_list|(
argument|const QGuiGLFormat&glFormat
argument_list|,
argument|QPlatformGLContext *share
argument_list|)
specifier|const
block|;
name|QWaylandDisplay
operator|*
name|waylandDisplay
argument_list|()
specifier|const
block|;     struct
name|wl_xcomposite
operator|*
name|waylandXComposite
argument_list|()
specifier|const
block|;
name|Display
operator|*
name|xDisplay
argument_list|()
specifier|const
block|;
name|int
name|screen
argument_list|()
specifier|const
block|;
name|Window
name|rootWindow
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QWaylandDisplay
operator|*
name|mWaylandDisplay
block|;     struct
name|wl_xcomposite
operator|*
name|mWaylandComposite
block|;
name|Display
operator|*
name|mDisplay
block|;
name|int
name|mScreen
block|;
name|Window
name|mRootWindow
block|;
specifier|static
name|void
name|wlDisplayHandleGlobal
argument_list|(
argument|struct wl_display *display
argument_list|,
argument|uint32_t id
argument_list|,
argument|const char *interface
argument_list|,
argument|uint32_t version
argument_list|,
argument|void *data
argument_list|)
block|;
specifier|static
specifier|const
expr|struct
name|wl_xcomposite_listener
name|xcomposite_listener
block|;
specifier|static
name|void
name|rootInformation
argument_list|(
argument|void *data
argument_list|,
argument|struct wl_xcomposite *xcomposite
argument_list|,
argument|const char *display_name
argument_list|,
argument|uint32_t root_window
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWAYLANDXCOMPOSITEGLXINTEGRATION_H
end_comment
end_unit
