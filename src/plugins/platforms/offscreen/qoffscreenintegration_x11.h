begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOFFSCREENINTEGRATION_X11_H
end_ifndef
begin_define
DECL|macro|QOFFSCREENINTEGRATION_X11_H
define|#
directive|define
name|QOFFSCREENINTEGRATION_X11_H
end_define
begin_include
include|#
directive|include
file|"qoffscreenintegration.h"
end_include
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_include
include|#
directive|include
file|<qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformopenglcontext.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOffscreenX11Connection
name|class
name|QOffscreenX11Connection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOffscreenX11Info
name|class
name|QOffscreenX11Info
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOffscreenX11Integration
range|:
name|public
name|QOffscreenIntegration
block|{
name|public
operator|:
name|bool
name|hasCapability
argument_list|(
argument|QPlatformIntegration::Capability cap
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QPlatformOpenGLContext
operator|*
name|createPlatformOpenGLContext
argument_list|(
argument|QOpenGLContext *context
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|mutable
name|QScopedPointer
operator|<
name|QOffscreenX11Connection
operator|>
name|m_connection
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOffscreenX11Connection
block|{
name|public
label|:
name|QOffscreenX11Connection
argument_list|()
expr_stmt|;
operator|~
name|QOffscreenX11Connection
argument_list|()
expr_stmt|;
name|QOffscreenX11Info
modifier|*
name|x11Info
parameter_list|()
function_decl|;
name|void
operator|*
name|display
argument_list|()
specifier|const
block|{
return|return
name|m_display
return|;
block|}
name|int
name|screenNumber
argument_list|()
specifier|const
block|{
return|return
name|m_screenNumber
return|;
block|}
name|private
label|:
name|void
modifier|*
name|m_display
decl_stmt|;
name|int
name|m_screenNumber
decl_stmt|;
name|QScopedPointer
operator|<
name|QOffscreenX11Info
operator|>
name|m_x11Info
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QOffscreenX11GLXContextData
name|class
name|QOffscreenX11GLXContextData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOffscreenX11GLXContext
range|:
name|public
name|QPlatformOpenGLContext
block|{
name|public
operator|:
name|QOffscreenX11GLXContext
argument_list|(
name|QOffscreenX11Info
operator|*
name|x11
argument_list|,
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
operator|~
name|QOffscreenX11GLXContext
argument_list|()
block|;
name|bool
name|makeCurrent
argument_list|(
argument|QPlatformSurface *surface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|doneCurrent
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|swapBuffers
argument_list|(
argument|QPlatformSurface *surface
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
argument_list|(
argument|*getProcAddress(const QByteArray&procName)
argument_list|)
operator|(
operator|)
name|Q_DECL_OVERRIDE
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isSharing
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|QScopedPointer
operator|<
name|QOffscreenX11GLXContextData
operator|>
name|d
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
