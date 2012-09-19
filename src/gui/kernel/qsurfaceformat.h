begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSURFACEFORMAT_H
end_ifndef
begin_define
DECL|macro|QSURFACEFORMAT_H
define|#
directive|define
name|QSURFACEFORMAT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSurfaceFormatPrivate
name|class
name|QSurfaceFormatPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QSurfaceFormat
block|{
name|public
label|:
enum|enum
name|FormatOption
block|{
name|StereoBuffers
init|=
literal|0x0001
block|,
name|DebugContext
init|=
literal|0x0002
block|,
name|DeprecatedFunctions
init|=
literal|0x0004
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
name|FormatOptions
argument_list|,
name|FormatOption
argument_list|)
expr|enum
name|SwapBehavior
block|{
name|DefaultSwapBehavior
block|,
name|SingleBuffer
block|,
name|DoubleBuffer
block|,
name|TripleBuffer
block|}
expr_stmt|;
enum|enum
name|RenderableType
block|{
name|DefaultRenderableType
init|=
literal|0x0
block|,
name|OpenGL
init|=
literal|0x1
block|,
name|OpenGLES
init|=
literal|0x2
block|,
name|OpenVG
init|=
literal|0x4
block|}
enum|;
enum|enum
name|OpenGLContextProfile
block|{
name|NoProfile
block|,
name|CoreProfile
block|,
name|CompatibilityProfile
block|}
enum|;
name|QSurfaceFormat
argument_list|()
expr_stmt|;
comment|/*implicit*/
name|QSurfaceFormat
argument_list|(
argument|FormatOptions options
argument_list|)
empty_stmt|;
name|QSurfaceFormat
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|other
argument_list|)
expr_stmt|;
name|QSurfaceFormat
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QSurfaceFormat
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QSurfaceFormat
argument_list|()
expr_stmt|;
name|void
name|setDepthBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|depthBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStencilBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|stencilBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRedBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|redBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setGreenBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|greenBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setBlueBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|blueBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setAlphaBufferSize
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|alphaBufferSize
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSamples
parameter_list|(
name|int
name|numSamples
parameter_list|)
function_decl|;
name|int
name|samples
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSwapBehavior
parameter_list|(
name|SwapBehavior
name|behavior
parameter_list|)
function_decl|;
name|SwapBehavior
name|swapBehavior
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasAlpha
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setProfile
parameter_list|(
name|OpenGLContextProfile
name|profile
parameter_list|)
function_decl|;
name|OpenGLContextProfile
name|profile
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRenderableType
parameter_list|(
name|RenderableType
name|type
parameter_list|)
function_decl|;
name|RenderableType
name|renderableType
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMajorVersion
parameter_list|(
name|int
name|majorVersion
parameter_list|)
function_decl|;
name|int
name|majorVersion
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMinorVersion
parameter_list|(
name|int
name|minorVersion
parameter_list|)
function_decl|;
name|int
name|minorVersion
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|stereo
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setStereo
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|void
name|setOption
argument_list|(
name|QSurfaceFormat
operator|::
name|FormatOptions
name|opt
argument_list|)
decl_stmt|;
name|bool
name|testOption
argument_list|(
name|QSurfaceFormat
operator|::
name|FormatOptions
name|opt
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|QSurfaceFormatPrivate
modifier|*
name|d
decl_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
name|friend
name|Q_GUI_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSurfaceFormat
operator|&
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_GUI_EXPORT
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSurfaceFormat
operator|&
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
name|friend
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QSurfaceFormat
operator|&
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QSurfaceFormat
operator|&
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QSurfaceFormat
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QSurfaceFormat::FormatOptions
argument_list|)
end_macro
begin_expr_stmt
DECL|function|stereo
specifier|inline
name|bool
name|QSurfaceFormat
operator|::
name|stereo
argument_list|()
specifier|const
block|{
return|return
name|testOption
argument_list|(
name|QSurfaceFormat
operator|::
name|StereoBuffers
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QSURFACEFORMAT_H
end_comment
end_unit
