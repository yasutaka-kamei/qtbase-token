begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLCONTEXT_H
end_ifndef
begin_define
DECL|macro|QOPENGLCONTEXT_H
define|#
directive|define
name|QOPENGLCONTEXT_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurfaceFormat>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|__GLEW_H__
end_ifdef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_warning
warning|#
directive|warning
warning|qopenglfunctions.h is not compatible with GLEW, GLEW defines will be undefined
end_warning
begin_warning
warning|#
directive|warning
warning|To use GLEW with Qt, do not include<qopengl.h> or<QOpenGLFunctions> after glew.h
end_warning
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLContextPrivate
name|class
name|QOpenGLContextPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLContextGroupPrivate
name|class
name|QOpenGLContextGroupPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLFunctions
name|class
name|QOpenGLFunctions
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformOpenGLContext
name|class
name|QPlatformOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScreen
name|class
name|QScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSurface
name|class
name|QSurface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLContextGroup
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLContextGroup
argument_list|)
name|public
operator|:
operator|~
name|QOpenGLContextGroup
argument_list|()
block|;
name|QList
operator|<
name|QOpenGLContext
operator|*
operator|>
name|shares
argument_list|()
specifier|const
block|;
specifier|static
name|QOpenGLContextGroup
operator|*
name|currentContextGroup
argument_list|()
block|;
name|private
operator|:
name|QOpenGLContextGroup
argument_list|()
block|;
name|friend
name|class
name|QOpenGLContext
block|;
name|friend
name|class
name|QOpenGLContextGroupResourceBase
block|;
name|friend
name|class
name|QOpenGLSharedResource
block|;
name|friend
name|class
name|QOpenGLMultiGroupSharedResource
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLContext
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLContext
argument_list|)
name|public
operator|:
name|explicit
name|QOpenGLContext
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QOpenGLContext
argument_list|()
block|;
name|void
name|setFormat
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|)
block|;
name|void
name|setShareContext
argument_list|(
name|QOpenGLContext
operator|*
name|shareContext
argument_list|)
block|;
name|void
name|setScreen
argument_list|(
name|QScreen
operator|*
name|screen
argument_list|)
block|;
name|bool
name|create
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|QOpenGLContext
operator|*
name|shareContext
argument_list|()
specifier|const
block|;
name|QOpenGLContextGroup
operator|*
name|shareGroup
argument_list|()
specifier|const
block|;
name|QScreen
operator|*
name|screen
argument_list|()
specifier|const
block|;
name|GLuint
name|defaultFramebufferObject
argument_list|()
specifier|const
block|;
name|bool
name|makeCurrent
argument_list|(
name|QSurface
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
name|QSurface
operator|*
name|surface
argument_list|)
block|;
name|QFunctionPointer
name|getProcAddress
argument_list|(
argument|const QByteArray&procName
argument_list|)
specifier|const
block|;
name|QSurface
operator|*
name|surface
argument_list|()
specifier|const
block|;
specifier|static
name|QOpenGLContext
operator|*
name|currentContext
argument_list|()
block|;
specifier|static
name|bool
name|areSharing
argument_list|(
name|QOpenGLContext
operator|*
name|first
argument_list|,
name|QOpenGLContext
operator|*
name|second
argument_list|)
block|;
name|QPlatformOpenGLContext
operator|*
name|handle
argument_list|()
specifier|const
block|;
name|QPlatformOpenGLContext
operator|*
name|shareHandle
argument_list|()
specifier|const
block|;
name|QOpenGLFunctions
operator|*
name|functions
argument_list|()
specifier|const
block|;
name|QSet
operator|<
name|QByteArray
operator|>
name|extensions
argument_list|()
specifier|const
block|;
name|bool
name|hasExtension
argument_list|(
argument|const QByteArray&extension
argument_list|)
specifier|const
block|;
name|Q_SIGNALS
operator|:
name|void
name|aboutToBeDestroyed
argument_list|()
block|;
name|private
operator|:
name|friend
name|class
name|QGLContext
block|;
name|friend
name|class
name|QGLPixelBuffer
block|;
name|friend
name|class
name|QOpenGLContextResourceBase
block|;
name|friend
name|class
name|QOpenGLPaintDevice
block|;
name|friend
name|class
name|QOpenGLGlyphTexture
block|;
name|friend
name|class
name|QOpenGLTextureGlyphCache
block|;
name|friend
name|class
name|QOpenGLEngineShaderManager
block|;
name|friend
name|class
name|QOpenGLFramebufferObject
block|;
name|friend
name|class
name|QOpenGLFramebufferObjectPrivate
block|;
name|friend
name|class
name|QOpenGL2PaintEngineEx
block|;
name|friend
name|class
name|QOpenGL2PaintEngineExPrivate
block|;
name|friend
name|class
name|QSGDistanceFieldGlyphCache
block|;
name|friend
name|class
name|QWidgetPrivate
block|;
name|void
operator|*
name|qGLContextHandle
argument_list|()
specifier|const
block|;
name|void
name|setQGLContextHandle
argument_list|(
name|void
operator|*
name|handle
argument_list|,
name|void
argument_list|(
operator|*
name|qGLContextDeleteFunction
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
block|;
name|void
name|deleteQGLContext
argument_list|()
block|;
name|void
name|destroy
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_OPENGL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGUIGLCONTEXT_H
end_comment
end_unit
