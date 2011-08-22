begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwaylandreadbackeglwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwaylandreadbackeglcontext.h"
end_include
begin_constructor
DECL|function|QWaylandReadbackEglWindow
name|QWaylandReadbackEglWindow
operator|::
name|QWaylandReadbackEglWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
name|QWaylandReadbackEglIntegration
modifier|*
name|eglIntegration
parameter_list|)
member_init_list|:
name|QWaylandShmWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|mEglIntegration
argument_list|(
name|eglIntegration
argument_list|)
member_init_list|,
name|mContext
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|windowType
name|QWaylandWindow
operator|::
name|WindowType
name|QWaylandReadbackEglWindow
operator|::
name|windowType
parameter_list|()
specifier|const
block|{
comment|//We'r lying, maybe we should add a type, but for now it will do
comment|//since this is primarly used by the windowsurface.
return|return
name|QWaylandWindow
operator|::
name|Egl
return|;
block|}
end_function
begin_function
DECL|function|glContext
name|QPlatformOpenGLContext
modifier|*
name|QWaylandReadbackEglWindow
operator|::
name|glContext
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|mContext
condition|)
block|{
name|QWaylandReadbackEglWindow
modifier|*
name|that
init|=
cast|const_cast
argument_list|<
name|QWaylandReadbackEglWindow
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|that
operator|->
name|mContext
operator|=
operator|new
name|QWaylandReadbackEglContext
argument_list|(
name|mEglIntegration
argument_list|,
name|that
argument_list|)
expr_stmt|;
block|}
return|return
name|mContext
return|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QWaylandReadbackEglWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
if|if
condition|(
name|mContext
condition|)
name|mContext
operator|->
name|geometryChanged
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
