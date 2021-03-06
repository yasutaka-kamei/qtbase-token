begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSDIRECT2DHELPERS_H
end_ifndef
begin_define
DECL|macro|QWINDOWSDIRECT2DHELPERS_H
define|#
directive|define
name|QWINDOWSDIRECT2DHELPERS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QRectF>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSizeF>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPointF>
end_include
begin_include
include|#
directive|include
file|<QtGui/QColor>
end_include
begin_include
include|#
directive|include
file|<QtGui/QTransform>
end_include
begin_include
include|#
directive|include
file|<d2d1_1helper.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|to_d2d_rect_u
specifier|inline
name|D2D1_RECT_U
name|to_d2d_rect_u
parameter_list|(
specifier|const
name|QRect
modifier|&
name|qrect
parameter_list|)
block|{
return|return
name|D2D1
operator|::
name|RectU
argument_list|(
name|qrect
operator|.
name|x
argument_list|()
argument_list|,
name|qrect
operator|.
name|y
argument_list|()
argument_list|,
name|qrect
operator|.
name|x
argument_list|()
operator|+
name|qrect
operator|.
name|width
argument_list|()
argument_list|,
name|qrect
operator|.
name|y
argument_list|()
operator|+
name|qrect
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|to_d2d_rect_f
specifier|inline
name|D2D1_RECT_F
name|to_d2d_rect_f
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|qrect
parameter_list|)
block|{
return|return
name|D2D1
operator|::
name|RectF
argument_list|(
name|qrect
operator|.
name|x
argument_list|()
argument_list|,
name|qrect
operator|.
name|y
argument_list|()
argument_list|,
name|qrect
operator|.
name|x
argument_list|()
operator|+
name|qrect
operator|.
name|width
argument_list|()
argument_list|,
name|qrect
operator|.
name|y
argument_list|()
operator|+
name|qrect
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|to_d2d_size_u
specifier|inline
name|D2D1_SIZE_U
name|to_d2d_size_u
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|qsize
parameter_list|)
block|{
return|return
name|D2D1
operator|::
name|SizeU
argument_list|(
name|qsize
operator|.
name|width
argument_list|()
argument_list|,
name|qsize
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|to_d2d_size_u
specifier|inline
name|D2D1_SIZE_U
name|to_d2d_size_u
parameter_list|(
specifier|const
name|QSize
modifier|&
name|qsize
parameter_list|)
block|{
return|return
name|D2D1
operator|::
name|SizeU
argument_list|(
name|qsize
operator|.
name|width
argument_list|()
argument_list|,
name|qsize
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|to_d2d_point_2f
specifier|inline
name|D2D1_POINT_2F
name|to_d2d_point_2f
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|qpoint
parameter_list|)
block|{
return|return
name|D2D1
operator|::
name|Point2F
argument_list|(
name|qpoint
operator|.
name|x
argument_list|()
argument_list|,
name|qpoint
operator|.
name|y
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
DECL|function|to_d2d_color_f
specifier|inline
name|D2D1
operator|::
name|ColorF
name|to_d2d_color_f
argument_list|(
argument|const QColor&c
argument_list|)
block|{
return|return
name|D2D1
operator|::
name|ColorF
argument_list|(
name|c
operator|.
name|redF
argument_list|()
argument_list|,
name|c
operator|.
name|greenF
argument_list|()
argument_list|,
name|c
operator|.
name|blueF
argument_list|()
argument_list|,
name|c
operator|.
name|alphaF
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|to_d2d_matrix_3x2_f
specifier|inline
name|D2D1_MATRIX_3X2_F
name|to_d2d_matrix_3x2_f
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|transform
parameter_list|)
block|{
return|return
name|D2D1
operator|::
name|Matrix3x2F
argument_list|(
name|transform
operator|.
name|m11
argument_list|()
argument_list|,
name|transform
operator|.
name|m12
argument_list|()
argument_list|,
name|transform
operator|.
name|m21
argument_list|()
argument_list|,
name|transform
operator|.
name|m22
argument_list|()
argument_list|,
name|transform
operator|.
name|m31
argument_list|()
argument_list|,
name|transform
operator|.
name|m32
argument_list|()
argument_list|)
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
begin_comment
comment|// QWINDOWSDIRECT2DHELPERS_H
end_comment
end_unit
