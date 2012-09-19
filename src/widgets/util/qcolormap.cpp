begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcolormap.h"
end_include
begin_include
include|#
directive|include
file|"qcolor.h"
end_include
begin_include
include|#
directive|include
file|"qpaintdevice.h"
end_include
begin_include
include|#
directive|include
file|"qscreen.h"
end_include
begin_include
include|#
directive|include
file|"qguiapplication.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QColormapPrivate
class|class
name|QColormapPrivate
block|{
public|public:
DECL|function|QColormapPrivate
specifier|inline
name|QColormapPrivate
parameter_list|()
member_init_list|:
name|ref
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|mode
argument_list|(
name|QColormap
operator|::
name|Direct
argument_list|)
member_init_list|,
name|depth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|numcolors
argument_list|(
literal|0
argument_list|)
block|{ }
DECL|member|ref
name|QAtomicInt
name|ref
decl_stmt|;
DECL|member|mode
name|QColormap
operator|::
name|Mode
name|mode
decl_stmt|;
DECL|member|depth
name|int
name|depth
decl_stmt|;
DECL|member|numcolors
name|int
name|numcolors
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|screenMap
specifier|static
name|QColormapPrivate
modifier|*
name|screenMap
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|initialize
name|void
name|QColormap
operator|::
name|initialize
parameter_list|()
block|{
name|screenMap
operator|=
operator|new
name|QColormapPrivate
expr_stmt|;
name|screenMap
operator|->
name|depth
operator|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|depth
argument_list|()
expr_stmt|;
if|if
condition|(
name|screenMap
operator|->
name|depth
operator|<
literal|8
condition|)
block|{
name|screenMap
operator|->
name|mode
operator|=
name|QColormap
operator|::
name|Indexed
expr_stmt|;
name|screenMap
operator|->
name|numcolors
operator|=
literal|256
expr_stmt|;
block|}
else|else
block|{
name|screenMap
operator|->
name|mode
operator|=
name|QColormap
operator|::
name|Direct
expr_stmt|;
name|screenMap
operator|->
name|numcolors
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|QColormap
operator|::
name|cleanup
parameter_list|()
block|{
operator|delete
name|screenMap
expr_stmt|;
name|screenMap
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|instance
name|QColormap
name|QColormap
operator|::
name|instance
parameter_list|(
name|int
comment|/*screen*/
parameter_list|)
block|{
return|return
name|QColormap
argument_list|()
return|;
block|}
end_function
begin_constructor
DECL|function|QColormap
name|QColormap
operator|::
name|QColormap
parameter_list|()
member_init_list|:
name|d
argument_list|(
name|screenMap
argument_list|)
block|{
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_constructor
DECL|function|QColormap
name|QColormap
operator|::
name|QColormap
parameter_list|(
specifier|const
name|QColormap
modifier|&
name|colormap
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|colormap
operator|.
name|d
argument_list|)
block|{
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_destructor
DECL|function|~QColormap
name|QColormap
operator|::
name|~
name|QColormap
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|mode
name|QColormap
operator|::
name|Mode
name|QColormap
operator|::
name|mode
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|mode
return|;
block|}
end_function
begin_function
DECL|function|depth
name|int
name|QColormap
operator|::
name|depth
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|depth
return|;
block|}
end_function
begin_function
DECL|function|size
name|int
name|QColormap
operator|::
name|size
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|numcolors
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_QWS_DEPTH16_RGB
end_ifndef
begin_define
DECL|macro|QT_QWS_DEPTH16_RGB
define|#
directive|define
name|QT_QWS_DEPTH16_RGB
value|565
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|qt_rbits
specifier|static
specifier|const
name|int
name|qt_rbits
init|=
operator|(
name|QT_QWS_DEPTH16_RGB
operator|/
literal|100
operator|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_gbits
specifier|static
specifier|const
name|int
name|qt_gbits
init|=
operator|(
name|QT_QWS_DEPTH16_RGB
operator|/
literal|10
operator|%
literal|10
operator|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_bbits
specifier|static
specifier|const
name|int
name|qt_bbits
init|=
operator|(
name|QT_QWS_DEPTH16_RGB
operator|%
literal|10
operator|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_red_shift
specifier|static
specifier|const
name|int
name|qt_red_shift
init|=
name|qt_bbits
operator|+
name|qt_gbits
operator|-
operator|(
literal|8
operator|-
name|qt_rbits
operator|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_green_shift
specifier|static
specifier|const
name|int
name|qt_green_shift
init|=
name|qt_bbits
operator|-
operator|(
literal|8
operator|-
name|qt_gbits
operator|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_neg_blue_shift
specifier|static
specifier|const
name|int
name|qt_neg_blue_shift
init|=
literal|8
operator|-
name|qt_bbits
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_blue_mask
specifier|static
specifier|const
name|int
name|qt_blue_mask
init|=
operator|(
literal|1
operator|<<
name|qt_bbits
operator|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_green_mask
specifier|static
specifier|const
name|int
name|qt_green_mask
init|=
operator|(
literal|1
operator|<<
operator|(
name|qt_gbits
operator|+
name|qt_bbits
operator|)
operator|)
operator|-
operator|(
literal|1
operator|<<
name|qt_bbits
operator|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_red_mask
specifier|static
specifier|const
name|int
name|qt_red_mask
init|=
operator|(
literal|1
operator|<<
operator|(
name|qt_rbits
operator|+
name|qt_gbits
operator|+
name|qt_bbits
operator|)
operator|)
operator|-
operator|(
literal|1
operator|<<
operator|(
name|qt_gbits
operator|+
name|qt_bbits
operator|)
operator|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_red_rounding_shift
specifier|static
specifier|const
name|int
name|qt_red_rounding_shift
init|=
name|qt_red_shift
operator|+
name|qt_rbits
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_green_rounding_shift
specifier|static
specifier|const
name|int
name|qt_green_rounding_shift
init|=
name|qt_green_shift
operator|+
name|qt_gbits
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_blue_rounding_shift
specifier|static
specifier|const
name|int
name|qt_blue_rounding_shift
init|=
name|qt_bbits
operator|-
name|qt_neg_blue_shift
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qt_convRgbTo16
specifier|inline
name|ushort
name|qt_convRgbTo16
parameter_list|(
name|QRgb
name|c
parameter_list|)
block|{
specifier|const
name|int
name|tr
init|=
name|qRed
argument_list|(
name|c
argument_list|)
operator|<<
name|qt_red_shift
decl_stmt|;
specifier|const
name|int
name|tg
init|=
name|qGreen
argument_list|(
name|c
argument_list|)
operator|<<
name|qt_green_shift
decl_stmt|;
specifier|const
name|int
name|tb
init|=
name|qBlue
argument_list|(
name|c
argument_list|)
operator|>>
name|qt_neg_blue_shift
decl_stmt|;
return|return
operator|(
name|tb
operator|&
name|qt_blue_mask
operator|)
operator||
operator|(
name|tg
operator|&
name|qt_green_mask
operator|)
operator||
operator|(
name|tr
operator|&
name|qt_red_mask
operator|)
return|;
block|}
end_function
begin_function
DECL|function|qt_conv16ToRgb
specifier|inline
name|QRgb
name|qt_conv16ToRgb
parameter_list|(
name|ushort
name|c
parameter_list|)
block|{
specifier|const
name|int
name|r
init|=
operator|(
name|c
operator|&
name|qt_red_mask
operator|)
decl_stmt|;
specifier|const
name|int
name|g
init|=
operator|(
name|c
operator|&
name|qt_green_mask
operator|)
decl_stmt|;
specifier|const
name|int
name|b
init|=
operator|(
name|c
operator|&
name|qt_blue_mask
operator|)
decl_stmt|;
specifier|const
name|int
name|tr
init|=
name|r
operator|>>
name|qt_red_shift
operator||
name|r
operator|>>
name|qt_red_rounding_shift
decl_stmt|;
specifier|const
name|int
name|tg
init|=
name|g
operator|>>
name|qt_green_shift
operator||
name|g
operator|>>
name|qt_green_rounding_shift
decl_stmt|;
specifier|const
name|int
name|tb
init|=
name|b
operator|<<
name|qt_neg_blue_shift
operator||
name|b
operator|>>
name|qt_blue_rounding_shift
decl_stmt|;
return|return
name|qRgb
argument_list|(
name|tr
argument_list|,
name|tg
argument_list|,
name|tb
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pixel
name|uint
name|QColormap
operator|::
name|pixel
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
specifier|const
block|{
name|QRgb
name|rgb
init|=
name|color
operator|.
name|rgba
argument_list|()
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|mode
operator|==
name|QColormap
operator|::
name|Direct
condition|)
block|{
switch|switch
condition|(
name|d
operator|->
name|depth
condition|)
block|{
case|case
literal|16
case|:
return|return
name|qt_convRgbTo16
argument_list|(
name|rgb
argument_list|)
return|;
case|case
literal|24
case|:
case|case
literal|32
case|:
block|{
specifier|const
name|int
name|r
init|=
name|qRed
argument_list|(
name|rgb
argument_list|)
decl_stmt|;
specifier|const
name|int
name|g
init|=
name|qGreen
argument_list|(
name|rgb
argument_list|)
decl_stmt|;
specifier|const
name|int
name|b
init|=
name|qBlue
argument_list|(
name|rgb
argument_list|)
decl_stmt|;
specifier|const
name|int
name|red_shift
init|=
literal|16
decl_stmt|;
specifier|const
name|int
name|green_shift
init|=
literal|8
decl_stmt|;
specifier|const
name|int
name|red_mask
init|=
literal|0xff0000
decl_stmt|;
specifier|const
name|int
name|green_mask
init|=
literal|0x00ff00
decl_stmt|;
specifier|const
name|int
name|blue_mask
init|=
literal|0x0000ff
decl_stmt|;
specifier|const
name|int
name|tg
init|=
name|g
operator|<<
name|green_shift
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_QWS_DEPTH_32_BGR
if|if
condition|(
name|qt_screen
operator|->
name|pixelType
argument_list|()
operator|==
name|QScreen
operator|::
name|BGRPixel
condition|)
block|{
specifier|const
name|int
name|tb
init|=
name|b
operator|<<
name|red_shift
decl_stmt|;
return|return
literal|0xff000000
operator||
operator|(
name|r
operator|&
name|blue_mask
operator|)
operator||
operator|(
name|tg
operator|&
name|green_mask
operator|)
operator||
operator|(
name|tb
operator|&
name|red_mask
operator|)
return|;
block|}
endif|#
directive|endif
specifier|const
name|int
name|tr
init|=
name|r
operator|<<
name|red_shift
decl_stmt|;
return|return
literal|0xff000000
operator||
operator|(
name|b
operator|&
name|blue_mask
operator|)
operator||
operator|(
name|tg
operator|&
name|green_mask
operator|)
operator||
operator|(
name|tr
operator|&
name|red_mask
operator|)
return|;
block|}
block|}
block|}
comment|//XXX
comment|//return qt_screen->alloc(qRed(rgb), qGreen(rgb), qBlue(rgb));
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|colorAt
specifier|const
name|QColor
name|QColormap
operator|::
name|colorAt
parameter_list|(
name|uint
name|pixel
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|mode
operator|==
name|Direct
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|depth
operator|==
literal|16
condition|)
block|{
name|pixel
operator|=
name|qt_conv16ToRgb
argument_list|(
name|pixel
argument_list|)
expr_stmt|;
block|}
specifier|const
name|int
name|red_shift
init|=
literal|16
decl_stmt|;
specifier|const
name|int
name|green_shift
init|=
literal|8
decl_stmt|;
specifier|const
name|int
name|red_mask
init|=
literal|0xff0000
decl_stmt|;
specifier|const
name|int
name|green_mask
init|=
literal|0x00ff00
decl_stmt|;
specifier|const
name|int
name|blue_mask
init|=
literal|0x0000ff
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_QWS_DEPTH_32_BGR
if|if
condition|(
name|qt_screen
operator|->
name|pixelType
argument_list|()
operator|==
name|QScreen
operator|::
name|BGRPixel
condition|)
block|{
return|return
name|QColor
argument_list|(
operator|(
name|pixel
operator|&
name|blue_mask
operator|)
argument_list|,
operator|(
name|pixel
operator|&
name|green_mask
operator|)
operator|>>
name|green_shift
argument_list|,
operator|(
name|pixel
operator|&
name|red_mask
operator|)
operator|>>
name|red_shift
argument_list|)
return|;
block|}
endif|#
directive|endif
return|return
name|QColor
argument_list|(
operator|(
name|pixel
operator|&
name|red_mask
operator|)
operator|>>
name|red_shift
argument_list|,
operator|(
name|pixel
operator|&
name|green_mask
operator|)
operator|>>
name|green_shift
argument_list|,
operator|(
name|pixel
operator|&
name|blue_mask
operator|)
argument_list|)
return|;
block|}
if|#
directive|if
literal|0
comment|// XXX
block|Q_ASSERT_X(int(pixel)< qt_screen->numCols(), "QColormap::colorAt", "pixel out of bounds of palette");     return QColor(qt_screen->clut()[pixel]);
endif|#
directive|endif
return|return
name|QColor
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|colormap
specifier|const
name|QVector
argument_list|<
name|QColor
argument_list|>
name|QColormap
operator|::
name|colormap
parameter_list|()
specifier|const
block|{
return|return
name|QVector
argument_list|<
name|QColor
argument_list|>
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|operator =
name|QColormap
modifier|&
name|QColormap
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QColormap
modifier|&
name|colormap
parameter_list|)
block|{
name|qAtomicAssign
argument_list|(
name|d
argument_list|,
name|colormap
operator|.
name|d
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
