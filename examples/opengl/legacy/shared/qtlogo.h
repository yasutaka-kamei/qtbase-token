begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTLOGO_H
end_ifndef
begin_define
DECL|macro|QTLOGO_H
define|#
directive|define
name|QTLOGO_H
end_define
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QColor>
end_include
begin_macro
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
argument|QOpenGLFunctions_1_1
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Patch
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|Geometry
struct_decl|;
end_struct_decl
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|class
name|QtLogo
range|:
name|public
name|QObject
block|{
name|public
operator|:
name|explicit
name|QtLogo
argument_list|(
argument|QObject *parent
argument_list|,
argument|int d =
literal|64
argument_list|,
argument|qreal s =
literal|1.0
argument_list|)
block|;
operator|~
name|QtLogo
argument_list|()
block|;
name|void
name|setColor
argument_list|(
argument|QColor c
argument_list|)
block|;
name|void
name|draw
argument_list|(
argument|QOpenGLFunctions_1_1 *functions
argument_list|)
specifier|const
block|;
name|private
operator|:
name|void
name|buildGeometry
argument_list|(
argument|int d
argument_list|,
argument|qreal s
argument_list|)
block|;
name|QList
operator|<
name|Patch
operator|*
operator|>
name|parts
block|;
name|Geometry
operator|*
name|geom
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTLOGO_H
end_comment
end_unit
