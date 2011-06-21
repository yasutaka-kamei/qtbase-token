begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandxcompositeeglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandxcompositeeglwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtGui/QRegion>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_constructor
DECL|function|QWaylandXCompositeEGLContext
name|QWaylandXCompositeEGLContext
operator|::
name|QWaylandXCompositeEGLContext
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QPlatformGLContext
modifier|*
name|share
parameter_list|,
name|EGLDisplay
name|display
parameter_list|)
member_init_list|:
name|QEGLPlatformContext
argument_list|(
name|format
argument_list|,
name|share
argument_list|,
name|display
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|swapBuffers
name|void
name|QWaylandXCompositeEGLContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|QEGLPlatformContext
operator|::
name|swapBuffers
argument_list|(
name|surface
argument_list|)
expr_stmt|;
name|QWaylandXCompositeEGLWindow
modifier|*
name|w
init|=
cast|static_cast
argument_list|<
name|QWaylandXCompositeEGLWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|QSize
name|size
init|=
name|w
operator|->
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
decl_stmt|;
name|w
operator|->
name|damage
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|w
operator|->
name|waitForFrameSync
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|eglSurfaceForPlatformSurface
name|EGLSurface
name|QWaylandXCompositeEGLContext
operator|::
name|eglSurfaceForPlatformSurface
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|QWaylandXCompositeEGLWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
operator|->
name|eglSurface
argument_list|()
return|;
block|}
end_function
end_unit
