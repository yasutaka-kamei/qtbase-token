begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLSHADERCACHE_P_H
end_ifndef
begin_define
DECL|macro|QGLSHADERCACHE_P_H
define|#
directive|define
name|QGLSHADERCACHE_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_MEEGO_EXPERIMENTAL_SHADERCACHE
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qglshadercache_meego_p.h"
end_include
begin_else
else|#
directive|else
end_else
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGLShaderProgram
name|class
name|QGLShaderProgram
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGLContext
name|class
name|QGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|CachedShader
block|{
name|public
label|:
specifier|inline
name|CachedShader
argument_list|(
argument|const QByteArray&
argument_list|,
argument|const QByteArray&
argument_list|)
block|{}
specifier|inline
name|bool
name|isCached
argument_list|()
block|{
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|load
parameter_list|(
name|QGLShaderProgram
modifier|*
parameter_list|,
specifier|const
name|QGLContext
modifier|*
parameter_list|)
block|{
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|store
parameter_list|(
name|QGLShaderProgram
modifier|*
parameter_list|,
specifier|const
name|QGLContext
modifier|*
parameter_list|)
block|{
return|return
name|false
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
