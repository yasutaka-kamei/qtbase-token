begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QRGBA64_P_H
end_ifndef
begin_define
DECL|macro|QRGBA64_P_H
define|#
directive|define
name|QRGBA64_P_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qrgba64.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qdrawhelper_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|combineAlpha256
specifier|inline
name|QRgba64
name|combineAlpha256
parameter_list|(
name|QRgba64
name|rgba64
parameter_list|,
name|uint
name|alpha256
parameter_list|)
block|{
return|return
name|QRgba64
operator|::
name|fromRgba64
argument_list|(
name|rgba64
operator|.
name|red
argument_list|()
argument_list|,
name|rgba64
operator|.
name|green
argument_list|()
argument_list|,
name|rgba64
operator|.
name|blue
argument_list|()
argument_list|,
operator|(
name|rgba64
operator|.
name|alpha
argument_list|()
operator|*
name|alpha256
operator|)
operator|>>
literal|8
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|multiplyAlpha256
specifier|inline
name|QRgba64
name|multiplyAlpha256
parameter_list|(
name|QRgba64
name|rgba64
parameter_list|,
name|uint
name|alpha256
parameter_list|)
block|{
return|return
name|QRgba64
operator|::
name|fromRgba64
argument_list|(
operator|(
name|rgba64
operator|.
name|red
argument_list|()
operator|*
name|alpha256
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|rgba64
operator|.
name|green
argument_list|()
operator|*
name|alpha256
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|rgba64
operator|.
name|blue
argument_list|()
operator|*
name|alpha256
operator|)
operator|>>
literal|8
argument_list|,
operator|(
name|rgba64
operator|.
name|alpha
argument_list|()
operator|*
name|alpha256
operator|)
operator|>>
literal|8
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|multiplyAlpha255
specifier|inline
name|QRgba64
name|multiplyAlpha255
parameter_list|(
name|QRgba64
name|rgba64
parameter_list|,
name|uint
name|alpha255
parameter_list|)
block|{
return|return
name|QRgba64
operator|::
name|fromRgba64
argument_list|(
name|qt_div_255
argument_list|(
name|rgba64
operator|.
name|red
argument_list|()
operator|*
name|alpha255
argument_list|)
argument_list|,
name|qt_div_255
argument_list|(
name|rgba64
operator|.
name|green
argument_list|()
operator|*
name|alpha255
argument_list|)
argument_list|,
name|qt_div_255
argument_list|(
name|rgba64
operator|.
name|blue
argument_list|()
operator|*
name|alpha255
argument_list|)
argument_list|,
name|qt_div_255
argument_list|(
name|rgba64
operator|.
name|alpha
argument_list|()
operator|*
name|alpha255
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|multiplyAlpha65535
specifier|inline
name|QRgba64
name|multiplyAlpha65535
parameter_list|(
name|QRgba64
name|rgba64
parameter_list|,
name|uint
name|alpha65535
parameter_list|)
block|{
return|return
name|QRgba64
operator|::
name|fromRgba64
argument_list|(
name|qt_div_65535
argument_list|(
name|rgba64
operator|.
name|red
argument_list|()
operator|*
name|alpha65535
argument_list|)
argument_list|,
name|qt_div_65535
argument_list|(
name|rgba64
operator|.
name|green
argument_list|()
operator|*
name|alpha65535
argument_list|)
argument_list|,
name|qt_div_65535
argument_list|(
name|rgba64
operator|.
name|blue
argument_list|()
operator|*
name|alpha65535
argument_list|)
argument_list|,
name|qt_div_65535
argument_list|(
name|rgba64
operator|.
name|alpha
argument_list|()
operator|*
name|alpha65535
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|interpolate256
specifier|inline
name|QRgba64
name|interpolate256
parameter_list|(
name|QRgba64
name|x
parameter_list|,
name|uint
name|alpha1
parameter_list|,
name|QRgba64
name|y
parameter_list|,
name|uint
name|alpha2
parameter_list|)
block|{
return|return
name|QRgba64
operator|::
name|fromRgba64
argument_list|(
name|multiplyAlpha256
argument_list|(
name|x
argument_list|,
name|alpha1
argument_list|)
operator|+
name|multiplyAlpha256
argument_list|(
name|y
argument_list|,
name|alpha2
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|interpolate255
specifier|inline
name|QRgba64
name|interpolate255
parameter_list|(
name|QRgba64
name|x
parameter_list|,
name|uint
name|alpha1
parameter_list|,
name|QRgba64
name|y
parameter_list|,
name|uint
name|alpha2
parameter_list|)
block|{
return|return
name|QRgba64
operator|::
name|fromRgba64
argument_list|(
name|multiplyAlpha255
argument_list|(
name|x
argument_list|,
name|alpha1
argument_list|)
operator|+
name|multiplyAlpha255
argument_list|(
name|y
argument_list|,
name|alpha2
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|interpolate65535
specifier|inline
name|QRgba64
name|interpolate65535
parameter_list|(
name|QRgba64
name|x
parameter_list|,
name|uint
name|alpha1
parameter_list|,
name|QRgba64
name|y
parameter_list|,
name|uint
name|alpha2
parameter_list|)
block|{
return|return
name|QRgba64
operator|::
name|fromRgba64
argument_list|(
name|multiplyAlpha65535
argument_list|(
name|x
argument_list|,
name|alpha1
argument_list|)
operator|+
name|multiplyAlpha65535
argument_list|(
name|y
argument_list|,
name|alpha2
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|addWithSaturation
specifier|inline
name|QRgba64
name|addWithSaturation
parameter_list|(
name|QRgba64
name|a
parameter_list|,
name|QRgba64
name|b
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__SSE2__
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_PROCESSOR_X86_64
argument_list|)
name|__m128i
name|va
init|=
name|_mm_cvtsi64_si128
argument_list|(
operator|(
name|quint64
operator|)
name|a
argument_list|)
decl_stmt|;
name|__m128i
name|vb
init|=
name|_mm_cvtsi64_si128
argument_list|(
operator|(
name|quint64
operator|)
name|b
argument_list|)
decl_stmt|;
name|va
operator|=
name|_mm_adds_epu16
argument_list|(
name|va
argument_list|,
name|vb
argument_list|)
expr_stmt|;
return|return
name|QRgba64
operator|::
name|fromRgba64
argument_list|(
name|_mm_cvtsi128_si64
argument_list|(
name|va
argument_list|)
argument_list|)
return|;
else|#
directive|else
return|return
name|QRgba64
operator|::
name|fromRgba64
argument_list|(
name|qMin
argument_list|(
name|a
operator|.
name|red
argument_list|()
operator|+
name|b
operator|.
name|red
argument_list|()
argument_list|,
literal|65535
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|a
operator|.
name|green
argument_list|()
operator|+
name|b
operator|.
name|green
argument_list|()
argument_list|,
literal|65535
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|a
operator|.
name|blue
argument_list|()
operator|+
name|b
operator|.
name|blue
argument_list|()
argument_list|,
literal|65535
argument_list|)
argument_list|,
name|qMin
argument_list|(
name|a
operator|.
name|alpha
argument_list|()
operator|+
name|b
operator|.
name|alpha
argument_list|()
argument_list|,
literal|65535
argument_list|)
argument_list|)
return|;
endif|#
directive|endif
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
comment|// QRGBA64_P_H
end_comment
end_unit
