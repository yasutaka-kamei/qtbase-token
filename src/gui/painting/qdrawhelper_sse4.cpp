begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<private/qdrawhelper_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdrawingprimitive_sse2_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_COMPILER_SUPPORTS_SSE4_1
argument_list|)
end_if
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|convertARGB32ToARGB32PM_sse4
specifier|const
name|uint
modifier|*
name|QT_FASTCALL
name|convertARGB32ToARGB32PM_sse4
parameter_list|(
name|uint
modifier|*
name|buffer
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QPixelLayout
modifier|*
parameter_list|,
specifier|const
name|QRgb
modifier|*
parameter_list|)
block|{
return|return
name|qt_convertARGB32ToARGB32PM
argument_list|(
name|buffer
argument_list|,
name|src
argument_list|,
name|count
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|convertRGBA8888ToARGB32PM_sse4
specifier|const
name|uint
modifier|*
name|QT_FASTCALL
name|convertRGBA8888ToARGB32PM_sse4
parameter_list|(
name|uint
modifier|*
name|buffer
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QPixelLayout
modifier|*
parameter_list|,
specifier|const
name|QRgb
modifier|*
parameter_list|)
block|{
return|return
name|qt_convertRGBA8888ToARGB32PM
argument_list|(
name|buffer
argument_list|,
name|src
argument_list|,
name|count
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|convertARGB32FromARGB32PM_sse4
specifier|const
name|uint
modifier|*
name|QT_FASTCALL
name|convertARGB32FromARGB32PM_sse4
parameter_list|(
name|uint
modifier|*
name|buffer
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QPixelLayout
modifier|*
parameter_list|,
specifier|const
name|QRgb
modifier|*
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
operator|++
name|i
control|)
name|buffer
index|[
name|i
index|]
operator|=
name|qUnpremultiply_sse4
argument_list|(
name|src
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_function
begin_function
DECL|function|convertRGBA8888FromARGB32PM_sse4
specifier|const
name|uint
modifier|*
name|QT_FASTCALL
name|convertRGBA8888FromARGB32PM_sse4
parameter_list|(
name|uint
modifier|*
name|buffer
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QPixelLayout
modifier|*
parameter_list|,
specifier|const
name|QRgb
modifier|*
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
operator|++
name|i
control|)
name|buffer
index|[
name|i
index|]
operator|=
name|ARGB2RGBA
argument_list|(
name|qUnpremultiply_sse4
argument_list|(
name|src
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_function
begin_function
DECL|function|convertRGBXFromARGB32PM_sse4
specifier|const
name|uint
modifier|*
name|QT_FASTCALL
name|convertRGBXFromARGB32PM_sse4
parameter_list|(
name|uint
modifier|*
name|buffer
parameter_list|,
specifier|const
name|uint
modifier|*
name|src
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|QPixelLayout
modifier|*
parameter_list|,
specifier|const
name|QRgb
modifier|*
parameter_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
operator|++
name|i
control|)
name|buffer
index|[
name|i
index|]
operator|=
name|ARGB2RGBA
argument_list|(
literal|0xff000000
operator||
name|qUnpremultiply_sse4
argument_list|(
name|src
index|[
name|i
index|]
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|buffer
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit