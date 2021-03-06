begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"debugproxystyle.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QStyleOption>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_if
if|#
directive|if
name|QT_VERSION
operator|<
literal|0x050000
end_if
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|d
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|p
parameter_list|)
block|{
name|d
operator|<<
literal|"QPixmap("
operator|<<
name|p
operator|.
name|size
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_VERSION< 0x050000
end_comment
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|debug
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|)
block|{
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
name|QDebugStateSaver
name|saver
argument_list|(
name|debug
argument_list|)
decl_stmt|;
name|debug
operator|.
name|nospace
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|debug
operator|<<
literal|"QStyleOption("
expr_stmt|;
if|if
condition|(
name|option
condition|)
name|debug
operator|<<
literal|"rec="
operator|<<
name|option
operator|->
name|rect
expr_stmt|;
else|else
name|debug
operator|<<
literal|'0'
expr_stmt|;
name|debug
operator|<<
literal|')'
expr_stmt|;
return|return
name|debug
return|;
block|}
end_function
begin_namespace
DECL|namespace|QtDiag
namespace|namespace
name|QtDiag
block|{
DECL|function|DebugProxyStyle
name|DebugProxyStyle
operator|::
name|DebugProxyStyle
parameter_list|(
name|QStyle
modifier|*
name|style
parameter_list|)
member_init_list|:
name|QProxyStyle
argument_list|(
name|style
argument_list|)
block|{
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
specifier|const
name|qreal
name|devicePixelRatio
init|=
name|qApp
operator|->
name|devicePixelRatio
argument_list|()
decl_stmt|;
else|#
directive|else
specifier|const
name|qreal
name|devicePixelRatio
init|=
literal|1
decl_stmt|;
endif|#
directive|endif
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|QT_VERSION_STR
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
operator|<<
name|QGuiApplication
operator|::
name|platformName
argument_list|()
endif|#
directive|endif
operator|<<
name|style
operator|->
name|objectName
argument_list|()
operator|<<
literal|"devicePixelRatio="
operator|<<
name|devicePixelRatio
expr_stmt|;
block|}
DECL|function|drawPrimitive
name|void
name|DebugProxyStyle
operator|::
name|drawPrimitive
parameter_list|(
name|QStyle
operator|::
name|PrimitiveElement
name|element
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"element="
operator|<<
name|element
operator|<<
name|option
operator|<<
name|widget
expr_stmt|;
name|QProxyStyle
operator|::
name|drawPrimitive
argument_list|(
name|element
argument_list|,
name|option
argument_list|,
name|painter
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
DECL|function|drawControl
name|void
name|DebugProxyStyle
operator|::
name|drawControl
parameter_list|(
name|QStyle
operator|::
name|ControlElement
name|element
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"element="
operator|<<
name|element
operator|<<
name|option
operator|<<
name|widget
expr_stmt|;
name|QProxyStyle
operator|::
name|drawControl
argument_list|(
name|element
argument_list|,
name|option
argument_list|,
name|painter
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
DECL|function|drawComplexControl
name|void
name|DebugProxyStyle
operator|::
name|drawComplexControl
parameter_list|(
name|QStyle
operator|::
name|ComplexControl
name|control
parameter_list|,
specifier|const
name|QStyleOptionComplex
modifier|*
name|option
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"control="
operator|<<
name|control
operator|<<
name|option
operator|<<
name|widget
expr_stmt|;
name|QProxyStyle
operator|::
name|drawComplexControl
argument_list|(
name|control
argument_list|,
name|option
argument_list|,
name|painter
argument_list|,
name|widget
argument_list|)
expr_stmt|;
block|}
DECL|function|drawItemPixmap
name|void
name|DebugProxyStyle
operator|::
name|drawItemPixmap
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
name|int
name|alignment
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
specifier|const
block|{
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|rect
operator|<<
literal|"alignment="
operator|<<
name|alignment
operator|<<
name|pixmap
expr_stmt|;
name|QProxyStyle
operator|::
name|drawItemPixmap
argument_list|(
name|painter
argument_list|,
name|rect
argument_list|,
name|alignment
argument_list|,
name|pixmap
argument_list|)
expr_stmt|;
block|}
DECL|function|sizeFromContents
name|QSize
name|DebugProxyStyle
operator|::
name|sizeFromContents
parameter_list|(
name|QStyle
operator|::
name|ContentsType
name|type
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
specifier|const
name|QSize
name|result
init|=
name|QProxyStyle
operator|::
name|sizeFromContents
argument_list|(
name|type
argument_list|,
name|option
argument_list|,
name|size
argument_list|,
name|widget
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|size
operator|<<
literal|"type="
operator|<<
name|type
operator|<<
name|option
operator|<<
name|widget
operator|<<
literal|"returns"
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|subElementRect
name|QRect
name|DebugProxyStyle
operator|::
name|subElementRect
parameter_list|(
name|QStyle
operator|::
name|SubElement
name|element
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
specifier|const
name|QRect
name|result
init|=
name|QProxyStyle
operator|::
name|subElementRect
argument_list|(
name|element
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"element="
operator|<<
name|element
operator|<<
name|option
operator|<<
name|widget
operator|<<
literal|"returns"
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|subControlRect
name|QRect
name|DebugProxyStyle
operator|::
name|subControlRect
parameter_list|(
name|QStyle
operator|::
name|ComplexControl
name|cc
parameter_list|,
specifier|const
name|QStyleOptionComplex
modifier|*
name|opt
parameter_list|,
name|QStyle
operator|::
name|SubControl
name|sc
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
specifier|const
name|QRect
name|result
init|=
name|QProxyStyle
operator|::
name|subControlRect
argument_list|(
name|cc
argument_list|,
name|opt
argument_list|,
name|sc
argument_list|,
name|widget
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"cc="
operator|<<
name|cc
operator|<<
literal|"sc="
operator|<<
name|sc
operator|<<
name|opt
operator|<<
name|widget
operator|<<
literal|"returns"
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|itemTextRect
name|QRect
name|DebugProxyStyle
operator|::
name|itemTextRect
parameter_list|(
specifier|const
name|QFontMetrics
modifier|&
name|fm
parameter_list|,
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
name|int
name|flags
parameter_list|,
name|bool
name|enabled
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
specifier|const
block|{
specifier|const
name|QRect
name|result
init|=
name|QProxyStyle
operator|::
name|itemTextRect
argument_list|(
name|fm
argument_list|,
name|r
argument_list|,
name|flags
argument_list|,
name|enabled
argument_list|,
name|text
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|r
operator|<<
literal|"flags="
operator|<<
name|flags
operator|<<
literal|"enabled="
operator|<<
name|enabled
operator|<<
name|text
operator|<<
literal|"returns"
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|itemPixmapRect
name|QRect
name|DebugProxyStyle
operator|::
name|itemPixmapRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|r
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
specifier|const
block|{
specifier|const
name|QRect
name|result
init|=
name|QProxyStyle
operator|::
name|itemPixmapRect
argument_list|(
name|r
argument_list|,
name|flags
argument_list|,
name|pixmap
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|r
operator|<<
literal|"flags="
operator|<<
name|flags
operator|<<
name|pixmap
operator|<<
literal|"returns"
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|pixelMetric
name|int
name|DebugProxyStyle
operator|::
name|pixelMetric
parameter_list|(
name|QStyle
operator|::
name|PixelMetric
name|metric
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|option
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
specifier|const
name|int
name|result
init|=
name|QProxyStyle
operator|::
name|pixelMetric
argument_list|(
name|metric
argument_list|,
name|option
argument_list|,
name|widget
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"metric="
operator|<<
name|metric
operator|<<
name|option
operator|<<
name|widget
operator|<<
literal|"returns"
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|standardPixmap
name|QPixmap
name|DebugProxyStyle
operator|::
name|standardPixmap
parameter_list|(
name|QStyle
operator|::
name|StandardPixmap
name|standardPixmap
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|opt
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
specifier|const
block|{
specifier|const
name|QPixmap
name|result
init|=
name|QProxyStyle
operator|::
name|standardPixmap
argument_list|(
name|standardPixmap
argument_list|,
name|opt
argument_list|,
name|widget
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"standardPixmap="
operator|<<
name|standardPixmap
operator|<<
name|opt
operator|<<
literal|"returns"
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
DECL|function|generatedIconPixmap
name|QPixmap
name|DebugProxyStyle
operator|::
name|generatedIconPixmap
parameter_list|(
name|QIcon
operator|::
name|Mode
name|iconMode
parameter_list|,
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
specifier|const
name|QStyleOption
modifier|*
name|opt
parameter_list|)
specifier|const
block|{
specifier|const
name|QPixmap
name|result
init|=
name|QProxyStyle
operator|::
name|generatedIconPixmap
argument_list|(
name|iconMode
argument_list|,
name|pixmap
argument_list|,
name|opt
argument_list|)
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
literal|"iconMode="
operator|<<
name|iconMode
operator|<<
name|pixmap
operator|<<
name|opt
operator|<<
literal|"returns"
operator|<<
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace QtDiag
end_comment
end_unit
