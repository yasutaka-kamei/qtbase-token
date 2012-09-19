begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSSHADEREFFECT_P_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSSHADEREFFECT_P_H
define|#
directive|define
name|QGRAPHICSSHADEREFFECT_P_H
end_define
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
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicseffect.h>
end_include
begin_include
include|#
directive|include
file|<QtOpenGL/qtopenglglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QGLShaderProgram
name|class
name|QGLShaderProgram
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGLCustomShaderEffectStage
name|class
name|QGLCustomShaderEffectStage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGraphicsShaderEffectPrivate
name|class
name|QGraphicsShaderEffectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGraphicsShaderEffect
range|:
name|public
name|QGraphicsEffect
block|{
name|Q_OBJECT
name|public
operator|:
name|QGraphicsShaderEffect
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QGraphicsShaderEffect
argument_list|()
block|;
name|QByteArray
name|pixelShaderFragment
argument_list|()
specifier|const
block|;
name|void
name|setPixelShaderFragment
argument_list|(
specifier|const
name|QByteArray
operator|&
name|code
argument_list|)
block|;
name|protected
operator|:
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|void
name|setUniformsDirty
argument_list|()
block|;
name|virtual
name|void
name|setUniforms
argument_list|(
name|QGLShaderProgram
operator|*
name|program
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGraphicsShaderEffect
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QGraphicsShaderEffect
argument_list|)
name|friend
name|class
name|QGLCustomShaderEffectStage
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
comment|// QGRAPHICSSHADEREFFECT_P_H
end_comment
end_unit
