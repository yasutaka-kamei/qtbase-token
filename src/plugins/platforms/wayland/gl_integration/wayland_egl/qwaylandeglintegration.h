begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWAYLANDEGLINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QWAYLANDEGLINTEGRATION_H
define|#
directive|define
name|QWAYLANDEGLINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|"gl_integration/qwaylandglintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandeglinclude.h"
end_include
begin_decl_stmt
DECL|variable|QWaylandWindow
name|class
name|QWaylandWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWaylandEglIntegration
range|:
name|public
name|QWaylandGLIntegration
block|{
name|public
operator|:
name|QWaylandEglIntegration
argument_list|(
expr|struct
name|wl_display
operator|*
name|waylandDisplay
argument_list|)
block|;
operator|~
name|QWaylandEglIntegration
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
name|EGLDisplay
name|eglDisplay
argument_list|()
specifier|const
block|;     struct
name|wl_egl_display
operator|*
name|nativeDisplay
argument_list|()
specifier|const
block|;
name|private
operator|:
expr|struct
name|wl_display
operator|*
name|mWaylandDisplay
block|;
name|EGLDisplay
name|mEglDisplay
block|;     struct
name|wl_egl_display
operator|*
name|mNativeEglDisplay
block|;   }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWAYLANDEGLINTEGRATION_H
end_comment
end_unit
