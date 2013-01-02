begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLXCONVENIENCE_H
end_ifndef
begin_define
DECL|macro|QGLXCONVENIENCE_H
define|#
directive|define
name|QGLXCONVENIENCE_H
end_define
begin_include
include|#
directive|include
file|<QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QVector>
end_include
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include
begin_include
include|#
directive|include
file|<GL/glx.h>
end_include
begin_function_decl
name|XVisualInfo
modifier|*
name|qglx_findVisualInfo
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|int
name|screen
parameter_list|,
name|QSurfaceFormat
modifier|*
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|GLXFBConfig
name|qglx_findConfig
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|int
name|screen
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|int
name|drawableBit
init|=
name|GLX_WINDOW_BIT
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QSurfaceFormat
name|qglx_surfaceFormatFromGLXFBConfig
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|GLXFBConfig
name|config
parameter_list|,
name|GLXContext
name|context
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QVector
operator|<
name|int
operator|>
name|qglx_buildSpec
argument_list|(
argument|const QSurfaceFormat&format
argument_list|,
argument|int drawableBit = GLX_WINDOW_BIT
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QSurfaceFormat
name|qglx_reduceSurfaceFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|bool
modifier|*
name|reduced
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGLXCONVENIENCE_H
end_comment
end_unit
