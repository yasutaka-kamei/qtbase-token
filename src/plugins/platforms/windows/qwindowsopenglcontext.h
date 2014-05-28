begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSOPENGLCONTEXT_H
end_ifndef
begin_define
DECL|macro|QWINDOWSOPENGLCONTEXT_H
define|#
directive|define
name|QWINDOWSOPENGLCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformopenglcontext.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
DECL|variable|QWindowsOpenGLContext
name|class
name|QWindowsOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsStaticOpenGLContext
block|{
name|public
label|:
specifier|static
name|QWindowsStaticOpenGLContext
modifier|*
name|create
parameter_list|()
function_decl|;
name|virtual
operator|~
name|QWindowsStaticOpenGLContext
argument_list|()
block|{ }
name|virtual
name|QWindowsOpenGLContext
operator|*
name|createContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
operator|*
name|moduleHandle
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QOpenGLContext
operator|::
name|OpenGLModuleType
name|moduleType
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|supportsThreadedOpenGL
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|// If the windowing system interface needs explicitly created window surfaces (like EGL),
comment|// reimplement these.
name|virtual
name|void
modifier|*
name|createWindowSurface
parameter_list|(
name|void
modifier|*
comment|/*nativeWindow*/
parameter_list|,
name|void
modifier|*
comment|/*nativeConfig*/
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|void
name|destroyWindowSurface
parameter_list|(
name|void
modifier|*
comment|/*nativeSurface*/
parameter_list|)
block|{ }
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QWindowsOpenGLContext
range|:
name|public
name|QPlatformOpenGLContext
block|{
name|public
operator|:
name|virtual
operator|~
name|QWindowsOpenGLContext
argument_list|()
block|{ }
comment|// Returns the native context handle (e.g. HGLRC for WGL, EGLContext for EGL).
name|virtual
name|void
operator|*
name|nativeContext
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|// These should be implemented only for some winsys interfaces, for example EGL.
comment|// For others, like WGL, they are not relevant.
name|virtual
name|void
operator|*
name|nativeDisplay
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|void
operator|*
name|nativeConfig
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
expr|}
block|;
endif|#
directive|endif
comment|// QT_NO_OPENGL
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSOPENGLCONTEXT_H
end_comment
end_unit