begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDRAWHELPER_X86_P_H
end_ifndef
begin_define
DECL|macro|QDRAWHELPER_X86_P_H
define|#
directive|define
name|QDRAWHELPER_X86_P_H
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
file|<private/qdrawhelper_p.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|__SSE2__
name|void
name|qt_memfill32
parameter_list|(
name|quint32
modifier|*
name|dest
parameter_list|,
name|quint32
name|value
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_memfill16
parameter_list|(
name|quint16
modifier|*
name|dest
parameter_list|,
name|quint16
name|value
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_bitmapblit32_sse2
parameter_list|(
name|QRasterBuffer
modifier|*
name|rasterBuffer
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
specifier|const
name|QRgba64
modifier|&
name|color
parameter_list|,
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|stride
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_bitmapblit8888_sse2
parameter_list|(
name|QRasterBuffer
modifier|*
name|rasterBuffer
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
specifier|const
name|QRgba64
modifier|&
name|color
parameter_list|,
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|stride
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_bitmapblit16_sse2
parameter_list|(
name|QRasterBuffer
modifier|*
name|rasterBuffer
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
specifier|const
name|QRgba64
modifier|&
name|color
parameter_list|,
specifier|const
name|uchar
modifier|*
name|src
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|stride
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_blend_argb32_on_argb32_sse2
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|qt_blend_rgb32_on_rgb32_sse2
parameter_list|(
name|uchar
modifier|*
name|destPixels
parameter_list|,
name|int
name|dbpl
parameter_list|,
specifier|const
name|uchar
modifier|*
name|srcPixels
parameter_list|,
name|int
name|sbpl
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|const_alpha
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|extern
name|CompositionFunction
name|qt_functionForMode_SSE2
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|CompositionFunctionSolid
name|qt_functionForModeSolid_SSE2
index|[]
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// __SSE2__
end_comment
begin_decl_stmt
DECL|variable|numCompositionFunctions
specifier|static
specifier|const
name|int
name|numCompositionFunctions
init|=
literal|38
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDRAWHELPER_X86_P_H
end_comment
end_unit
