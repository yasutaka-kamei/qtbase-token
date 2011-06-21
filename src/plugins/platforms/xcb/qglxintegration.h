begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLXINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QGLXINTEGRATION_H
define|#
directive|define
name|QGLXINTEGRATION_H
end_define
begin_include
include|#
directive|include
file|"qxcbwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMutex>
end_include
begin_include
include|#
directive|include
file|<GL/glx.h>
end_include
begin_decl_stmt
name|class
name|QGLXContext
range|:
name|public
name|QPlatformGLContext
block|{
name|public
operator|:
name|QGLXContext
argument_list|(
name|QXcbScreen
operator|*
name|xd
argument_list|,
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|,
name|QPlatformGLContext
operator|*
name|share
argument_list|)
block|;
operator|~
name|QGLXContext
argument_list|()
block|;
name|bool
name|makeCurrent
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
block|;
name|void
name|doneCurrent
argument_list|()
block|;
name|void
name|swapBuffers
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
block|;
name|void
argument_list|(
operator|*
name|getProcAddress
argument_list|(
specifier|const
name|QByteArray
operator|&
name|procName
argument_list|)
argument_list|)
argument_list|()
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|GLXContext
name|glxContext
argument_list|()
specifier|const
block|{
return|return
name|m_context
return|;
block|}
name|private
operator|:
name|QXcbScreen
operator|*
name|m_screen
block|;
name|GLXContext
name|m_context
block|;
name|QSurfaceFormat
name|m_format
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
