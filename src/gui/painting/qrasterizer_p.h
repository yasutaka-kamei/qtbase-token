begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QRASTERIZER_P_H
end_ifndef
begin_define
DECL|macro|QRASTERIZER_P_H
define|#
directive|define
name|QRASTERIZER_P_H
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
file|"QtCore/qglobal.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpainter.h"
end_include
begin_include
include|#
directive|include
file|<private/qdrawhelper_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qrasterdefs_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct_decl
struct_decl|struct
name|QSpanData
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QRasterBuffer
name|class
name|QRasterBuffer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRasterizerPrivate
name|class
name|QRasterizerPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QRasterizer
block|{
name|public
label|:
name|QRasterizer
argument_list|()
expr_stmt|;
operator|~
name|QRasterizer
argument_list|()
expr_stmt|;
name|void
name|setAntialiased
parameter_list|(
name|bool
name|antialiased
parameter_list|)
function_decl|;
name|void
name|setClipRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|clipRect
parameter_list|)
function_decl|;
name|void
name|initialize
parameter_list|(
name|ProcessSpans
name|blend
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
name|rasterize
argument_list|(
specifier|const
name|QT_FT_Outline
operator|*
name|outline
argument_list|,
name|Qt
operator|::
name|FillRule
name|fillRule
argument_list|)
decl_stmt|;
name|void
name|rasterize
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|path
argument_list|,
name|Qt
operator|::
name|FillRule
name|fillRule
argument_list|)
decl_stmt|;
comment|// width should be in units of |a-b|
name|void
name|rasterizeLine
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|a
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|b
parameter_list|,
name|qreal
name|width
parameter_list|,
name|bool
name|squareCap
init|=
name|false
parameter_list|)
function_decl|;
name|private
label|:
name|QRasterizerPrivate
modifier|*
name|d
decl_stmt|;
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
end_unit
