begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSMOBILESTYLE_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSMOBILESTYLE_P_H
define|#
directive|define
name|QWINDOWSMOBILESTYLE_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
end_comment
begin_comment
comment|// file may change from version to version without notice, or even be removed.
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
file|"qwindowsmobilestyle.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsstyle_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_STYLE_WINDOWSMOBILE
DECL|variable|QStyleOptionTab
name|class
name|QStyleOptionTab
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionSlider
name|class
name|QStyleOptionSlider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsMobileStylePrivate
range|:
name|public
name|QWindowsStylePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QWindowsMobileStyle
argument_list|)
name|public
operator|:
name|QWindowsMobileStylePrivate
argument_list|()
block|;
name|bool
name|doubleControls
block|;
name|bool
name|smartphone
block|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE_WM
name|bool
name|wm65
block|;
endif|#
directive|endif
name|QImage
name|imageRadioButton
block|;
name|QImage
name|imageRadioButtonChecked
block|;
name|QImage
name|imageRadioButtonHighlighted
block|;
name|QImage
name|imageChecked
block|;
name|QImage
name|imageCheckedBold
block|;
name|QImage
name|imageArrowDown
block|;
name|QImage
name|imageArrowUp
block|;
name|QImage
name|imageArrowLeft
block|;
name|QImage
name|imageArrowRight
block|;
name|QImage
name|imageArrowDownBig
block|;
name|QImage
name|imageArrowUpBig
block|;
name|QImage
name|imageArrowLeftBig
block|;
name|QImage
name|imageArrowRightBig
block|;
name|QImage
name|imageClose
block|;
name|QImage
name|imageMaximize
block|;
name|QImage
name|imageNormalize
block|;
name|QImage
name|imageMinimize
block|;
name|void
name|setupWindowsMobileStyle65
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE_WM
comment|//Windows Mobile 6.5 images
name|QImage
name|imageScrollbarHandleUp
block|;
name|QImage
name|imageScrollbarHandleDown
block|;
name|QImage
name|imageScrollbarHandleUpHigh
block|;
name|QImage
name|imageScrollbarHandleDownHigh
block|;
name|QImage
name|imageScrollbarGripUp
block|;
name|QImage
name|imageScrollbarGripDown
block|;
name|QImage
name|imageScrollbarGripMiddle
block|;
name|QImage
name|imageListViewHighlightCornerLeft
block|;
name|QImage
name|imageListViewHighlightCornerRight
block|;
name|QImage
name|imageListViewHighlightMiddle
block|;
name|QImage
name|imageTabEnd
block|;
name|QImage
name|imageTabSelectedEnd
block|;
name|QImage
name|imageTabSelectedBegin
block|;
name|QImage
name|imageTabMiddle
block|;
name|QColor
name|currentTintHigh
block|;
name|QColor
name|currentTintButton
block|;
name|void
name|tintImagesHigh
argument_list|(
argument|QColor color
argument_list|)
block|;
name|void
name|tintImagesButton
argument_list|(
argument|QColor color
argument_list|)
block|;
name|void
name|tintListViewHighlight
argument_list|(
argument|QColor color
argument_list|)
block|;
endif|#
directive|endif
comment|//Q_OS_WINCE_WM
name|void
name|drawScrollbarHandleUp
argument_list|(
argument|QPainter *p
argument_list|,
argument|QStyleOptionSlider *opt
argument_list|,
argument|bool completeFrame = false
argument_list|,
argument|bool secondScrollBar = false
argument_list|)
block|;
name|void
name|drawScrollbarHandleDown
argument_list|(
argument|QPainter *p
argument_list|,
argument|QStyleOptionSlider *opt
argument_list|,
argument|bool completeFrame = false
argument_list|,
argument|bool secondScrollBar = false
argument_list|)
block|;
name|void
name|drawScrollbarGroove
argument_list|(
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QStyleOptionSlider
operator|*
name|opt
argument_list|)
block|;
name|void
name|drawScrollbarGrip
argument_list|(
argument|QPainter *p
argument_list|,
argument|QStyleOptionSlider *newScrollbar
argument_list|,
argument|const QStyleOptionComplex *option
argument_list|,
argument|bool drawCompleteFrame
argument_list|)
block|;
name|void
name|drawTabBarTab
argument_list|(
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QStyleOptionTab
operator|*
name|tab
argument_list|)
block|;
name|void
name|drawPanelItemViewSelected
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItemV4 *option
argument_list|,
argument|QRect rect = QRect()
argument_list|)
block|;  }
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
comment|// QT_NO_STYLE_WINDOWSMOBILE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QWINDOWSMOBILESTYLE_P_H
end_comment
end_unit
