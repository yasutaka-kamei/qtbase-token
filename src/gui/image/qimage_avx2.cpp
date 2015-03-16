begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<private/qdrawhelper_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qimage_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qsimd_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_COMPILER_SUPPORTS_AVX2
end_ifdef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|convert_ARGB_to_ARGB_PM_avx2
name|void
name|convert_ARGB_to_ARGB_PM_avx2
parameter_list|(
name|QImageData
modifier|*
name|dest
parameter_list|,
specifier|const
name|QImageData
modifier|*
name|src
parameter_list|,
name|Qt
operator|::
name|ImageConversionFlags
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|src
operator|->
name|format
operator|==
name|QImage
operator|::
name|Format_ARGB32
operator|||
name|src
operator|->
name|format
operator|==
name|QImage
operator|::
name|Format_RGBA8888
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|dest
operator|->
name|format
operator|==
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
operator|||
name|dest
operator|->
name|format
operator|==
name|QImage
operator|::
name|Format_RGBA8888_Premultiplied
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|src
operator|->
name|width
operator|==
name|dest
operator|->
name|width
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|src
operator|->
name|height
operator|==
name|dest
operator|->
name|height
argument_list|)
expr_stmt|;
specifier|const
name|uint
modifier|*
name|src_data
init|=
operator|(
name|uint
operator|*
operator|)
name|src
operator|->
name|data
decl_stmt|;
name|uint
modifier|*
name|dest_data
init|=
operator|(
name|uint
operator|*
operator|)
name|dest
operator|->
name|data
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|src
operator|->
name|height
condition|;
operator|++
name|i
control|)
block|{
name|qt_convertARGB32ToARGB32PM
argument_list|(
name|dest_data
argument_list|,
name|src_data
argument_list|,
name|src
operator|->
name|width
argument_list|)
expr_stmt|;
name|src_data
operator|+=
name|src
operator|->
name|bytes_per_line
operator|>>
literal|2
expr_stmt|;
name|dest_data
operator|+=
name|dest
operator|->
name|bytes_per_line
operator|>>
literal|2
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_COMPILER_SUPPORTS_AVX2
end_comment
end_unit
