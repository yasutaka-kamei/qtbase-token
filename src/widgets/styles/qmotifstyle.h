begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMOTIFSTYLE_H
end_ifndef
begin_define
DECL|macro|QMOTIFSTYLE_H
define|#
directive|define
name|QMOTIFSTYLE_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qcommonstyle.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpointer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_STYLE_MOTIF
argument_list|)
DECL|variable|QPalette
name|class
name|QPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFocusFrame
name|class
name|QFocusFrame
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMotifStylePrivate
name|class
name|QMotifStylePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QMotifStyle
range|:
name|public
name|QCommonStyle
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QMotifStyle
argument_list|(
argument|bool useHighlightCols=false
argument_list|)
block|;
name|virtual
operator|~
name|QMotifStyle
argument_list|()
block|;
name|void
name|setUseHighlightColors
argument_list|(
name|bool
argument_list|)
block|;
name|bool
name|useHighlightColors
argument_list|()
specifier|const
block|;
name|void
name|polish
argument_list|(
name|QPalette
operator|&
argument_list|)
block|;
name|void
name|polish
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|void
name|unpolish
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|void
name|polish
argument_list|(
name|QApplication
operator|*
argument_list|)
block|;
name|void
name|unpolish
argument_list|(
name|QApplication
operator|*
argument_list|)
block|;
name|void
name|drawPrimitive
argument_list|(
argument|PrimitiveElement pe
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|QPainter *p
argument_list|,
argument|const QWidget *w =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|drawControl
argument_list|(
argument|ControlElement element
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|QPainter *p
argument_list|,
argument|const QWidget *w =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|drawComplexControl
argument_list|(
argument|ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex *opt
argument_list|,
argument|QPainter *p
argument_list|,
argument|const QWidget *w =
literal|0
argument_list|)
specifier|const
block|;
name|QRect
name|subControlRect
argument_list|(
argument|ComplexControl cc
argument_list|,
argument|const QStyleOptionComplex *opt
argument_list|,
argument|SubControl sc
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|int
name|pixelMetric
argument_list|(
argument|PixelMetric metric
argument_list|,
argument|const QStyleOption *option =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|QSize
name|sizeFromContents
argument_list|(
argument|ContentsType ct
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|const QSize&contentsSize
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|QRect
name|subElementRect
argument_list|(
argument|SubElement r
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|QPixmap
name|standardPixmap
argument_list|(
argument|StandardPixmap standardPixmap
argument_list|,
argument|const QStyleOption *opt
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|int
name|styleHint
argument_list|(
argument|StyleHint hint
argument_list|,
argument|const QStyleOption *opt =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|,
argument|QStyleHintReturn *returnData =
literal|0
argument_list|)
specifier|const
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|QPalette
name|standardPalette
argument_list|()
specifier|const
block|;
name|QIcon
name|standardIcon
argument_list|(
argument|StandardPixmap standardIcon
argument_list|,
argument|const QStyleOption *opt =
literal|0
argument_list|,
argument|const QWidget *widget =
literal|0
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|QPointer
operator|<
name|QFocusFrame
operator|>
name|focus
block|;
name|QMotifStyle
argument_list|(
argument|QMotifStylePrivate&dd
argument_list|,
argument|bool useHighlightCols = false
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QMotifStyle
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QMotifStyle
argument_list|)
name|bool
name|highlightCols
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_STYLE_MOTIF
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMOTIFSTYLE_H
end_comment
end_unit
