begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMACSTYLE_MAC_P_P_H
end_ifndef
begin_define
DECL|macro|QMACSTYLE_MAC_P_P_H
define|#
directive|define
name|QMACSTYLE_MAC_P_P_H
end_define
begin_include
include|#
directive|include
file|<Carbon/Carbon.h>
end_include
begin_undef
DECL|macro|check
undef|#
directive|undef
name|check
end_undef
begin_include
include|#
directive|include
file|"qmacstyle_mac_p.h"
end_include
begin_include
include|#
directive|include
file|"qcommonstyle_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qcombobox_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpainter_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qstylehelper_p.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qbitmap.h>
end_include
begin_include
include|#
directive|include
file|<qcheckbox.h>
end_include
begin_include
include|#
directive|include
file|<qcombobox.h>
end_include
begin_include
include|#
directive|include
file|<qdialogbuttonbox.h>
end_include
begin_include
include|#
directive|include
file|<qdockwidget.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qfocusframe.h>
end_include
begin_include
include|#
directive|include
file|<qformlayout.h>
end_include
begin_include
include|#
directive|include
file|<qgroupbox.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<qheaderview.h>
end_include
begin_include
include|#
directive|include
file|<qlayout.h>
end_include
begin_include
include|#
directive|include
file|<qlineedit.h>
end_include
begin_include
include|#
directive|include
file|<qlistview.h>
end_include
begin_include
include|#
directive|include
file|<qmainwindow.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qmenubar.h>
end_include
begin_include
include|#
directive|include
file|<qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qpixmapcache.h>
end_include
begin_include
include|#
directive|include
file|<qpointer.h>
end_include
begin_include
include|#
directive|include
file|<qprogressbar.h>
end_include
begin_include
include|#
directive|include
file|<qpushbutton.h>
end_include
begin_include
include|#
directive|include
file|<qradiobutton.h>
end_include
begin_include
include|#
directive|include
file|<qrubberband.h>
end_include
begin_include
include|#
directive|include
file|<qsizegrip.h>
end_include
begin_include
include|#
directive|include
file|<qspinbox.h>
end_include
begin_include
include|#
directive|include
file|<qsplitter.h>
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<qtextedit.h>
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbar.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbutton.h>
end_include
begin_include
include|#
directive|include
file|<qtreeview.h>
end_include
begin_include
include|#
directive|include
file|<qtableview.h>
end_include
begin_include
include|#
directive|include
file|<qwizard.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qlibrary.h>
end_include
begin_include
include|#
directive|include
file|<qdatetimeedit.h>
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|<qpair.h>
end_include
begin_include
include|#
directive|include
file|<qset.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicsproxywidget.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qgraphicsview.h>
end_include
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*     AHIG:         Apple Human Interface Guidelines         http://developer.apple.com/documentation/UserExperience/Conceptual/OSXHIGuidelines/      Builder:         Apple Interface Builder v. 3.1.1 */
comment|// this works as long as we have at most 16 different control types
DECL|macro|CT1
define|#
directive|define
name|CT1
parameter_list|(
name|c
parameter_list|)
value|CT2(c, c)
DECL|macro|CT2
define|#
directive|define
name|CT2
parameter_list|(
name|c1
parameter_list|,
name|c2
parameter_list|)
value|((uint(c1)<< 16) | uint(c2))
DECL|enum|QAquaWidgetSize
DECL|enumerator|QAquaSizeLarge
DECL|enumerator|QAquaSizeSmall
DECL|enumerator|QAquaSizeMini
name|enum
name|QAquaWidgetSize
block|{
name|QAquaSizeLarge
operator|=
literal|0
operator|,
name|QAquaSizeSmall
operator|=
literal|1
operator|,
name|QAquaSizeMini
operator|=
literal|2
operator|,
DECL|enumerator|QAquaSizeUnknown
name|QAquaSizeUnknown
operator|=
operator|-
literal|1
block|}
end_decl_stmt
begin_empty_stmt
DECL|enumerator|QAquaSizeUnknown
empty_stmt|;
end_empty_stmt
begin_enum
DECL|enum|QCocoaWidgetKind
enum|enum
name|QCocoaWidgetKind
block|{
DECL|enumerator|QCocoaArrowButton
name|QCocoaArrowButton
block|,
comment|// Disclosure triangle, like in QTreeView
DECL|enumerator|QCocoaCheckBox
name|QCocoaCheckBox
block|,
DECL|enumerator|QCocoaComboBox
name|QCocoaComboBox
block|,
comment|// Editable QComboBox
DECL|enumerator|QCocoaPopupButton
name|QCocoaPopupButton
block|,
comment|// Non-editable QComboBox
DECL|enumerator|QCocoaPullDownButton
name|QCocoaPullDownButton
block|,
comment|// QPushButton with menu
DECL|enumerator|QCocoaPushButton
name|QCocoaPushButton
block|,
DECL|enumerator|QCocoaRadioButton
name|QCocoaRadioButton
block|}
enum|;
end_enum
begin_typedef
DECL|typedef|QCocoaWidgetKind
DECL|typedef|QCocoaWidget
typedef|typedef
name|QPair
operator|<
name|QCocoaWidgetKind
operator|,
name|QAquaWidgetSize
operator|>
name|QCocoaWidget
expr_stmt|;
end_typedef
begin_define
DECL|macro|SIZE
define|#
directive|define
name|SIZE
parameter_list|(
name|large
parameter_list|,
name|small
parameter_list|,
name|mini
parameter_list|)
define|\
value|(controlSize == QAquaSizeLarge ? (large) : controlSize == QAquaSizeSmall ? (small) : (mini))
end_define
begin_comment
comment|// same as return SIZE(...) but optimized
end_comment
begin_define
DECL|macro|return_SIZE
define|#
directive|define
name|return_SIZE
parameter_list|(
name|large
parameter_list|,
name|small
parameter_list|,
name|mini
parameter_list|)
define|\
value|do { \         static const int sizes[] = { (large), (small), (mini) }; \         return sizes[controlSize]; \     } while (0)
end_define
begin_function_decl
name|bool
name|qt_mac_buttonIsRenderedFlat
parameter_list|(
specifier|const
name|QPushButton
modifier|*
name|pushButton
parameter_list|,
specifier|const
name|QStyleOptionButton
modifier|*
name|option
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|class
name|QMacStylePrivate
range|:
name|public
name|QCommonStylePrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QMacStyle
argument_list|)
name|public
operator|:
name|QMacStylePrivate
argument_list|()
block|;
operator|~
name|QMacStylePrivate
argument_list|()
block|;
comment|// Ideally these wouldn't exist, but since they already exist we need some accessors.
specifier|static
specifier|const
name|int
name|PushButtonLeftOffset
block|;
specifier|static
specifier|const
name|int
name|PushButtonTopOffset
block|;
specifier|static
specifier|const
name|int
name|PushButtonRightOffset
block|;
specifier|static
specifier|const
name|int
name|PushButtonBottomOffset
block|;
specifier|static
specifier|const
name|int
name|MiniButtonH
block|;
specifier|static
specifier|const
name|int
name|SmallButtonH
block|;
specifier|static
specifier|const
name|int
name|BevelButtonW
block|;
specifier|static
specifier|const
name|int
name|BevelButtonH
block|;
specifier|static
specifier|const
name|int
name|PushButtonContentPadding
block|;      enum
name|Animates
block|{
name|AquaPushButton
block|,
name|AquaProgressBar
block|,
name|AquaListViewItemOpen
block|,
name|AquaScrollBar
block|}
block|;
specifier|static
name|ThemeDrawState
name|getDrawState
argument_list|(
argument|QStyle::State flags
argument_list|)
block|;
name|QAquaWidgetSize
name|aquaSizeConstrain
argument_list|(
argument|const QStyleOption *option
argument_list|,
argument|const QWidget *widg
argument_list|,
argument|QStyle::ContentsType ct = QStyle::CT_CustomBase
argument_list|,
argument|QSize szHint=QSize(-
literal|1
argument|, -
literal|1
argument|)
argument_list|,
argument|QSize *insz =
literal|0
argument_list|)
specifier|const
block|;
name|void
name|getSliderInfo
argument_list|(
argument|QStyle::ComplexControl cc
argument_list|,
argument|const QStyleOptionSlider *slider
argument_list|,
argument|HIThemeTrackDrawInfo *tdi
argument_list|,
argument|const QWidget *needToRemoveMe
argument_list|)
specifier|const
block|;
specifier|inline
name|int
name|animateSpeed
argument_list|(
argument|Animates
argument_list|)
specifier|const
block|{
return|return
literal|33
return|;
block|}
comment|// Utility functions
name|void
name|drawColorlessButton
argument_list|(
argument|const HIRect&macRect
argument_list|,
argument|HIThemeButtonDrawInfo *bdi
argument_list|,
argument|QPainter *p
argument_list|,
argument|const QStyleOption *opt
argument_list|)
specifier|const
block|;
name|QSize
name|pushButtonSizeFromContents
argument_list|(
argument|const QStyleOptionButton *btn
argument_list|)
specifier|const
block|;
name|HIRect
name|pushButtonContentBounds
argument_list|(
argument|const QStyleOptionButton *btn
argument_list|,
argument|const HIThemeButtonDrawInfo *bdi
argument_list|)
specifier|const
block|;
name|void
name|initComboboxBdi
argument_list|(
argument|const QStyleOptionComboBox *combo
argument_list|,
argument|HIThemeButtonDrawInfo *bdi
argument_list|,
argument|const QWidget *widget
argument_list|,
argument|const ThemeDrawState&tds
argument_list|)
specifier|const
block|;
specifier|static
name|HIRect
name|comboboxInnerBounds
argument_list|(
argument|const HIRect&outerBounds
argument_list|,
argument|int buttonKind
argument_list|)
block|;
specifier|static
name|QRect
name|comboboxEditBounds
argument_list|(
specifier|const
name|QRect
operator|&
name|outerBounds
argument_list|,
specifier|const
name|HIThemeButtonDrawInfo
operator|&
name|bdi
argument_list|)
block|;
specifier|static
name|void
name|drawCombobox
argument_list|(
specifier|const
name|HIRect
operator|&
name|outerBounds
argument_list|,
specifier|const
name|HIThemeButtonDrawInfo
operator|&
name|bdi
argument_list|,
name|QPainter
operator|*
name|p
argument_list|)
block|;
specifier|static
name|void
name|drawTableHeader
argument_list|(
argument|const HIRect&outerBounds
argument_list|,
argument|bool drawTopBorder
argument_list|,
argument|bool drawLeftBorder
argument_list|,
argument|const HIThemeButtonDrawInfo&bdi
argument_list|,
argument|QPainter *p
argument_list|)
block|;
name|bool
name|contentFitsInPushButton
argument_list|(
argument|const QStyleOptionButton *btn
argument_list|,
argument|HIThemeButtonDrawInfo *bdi
argument_list|,
argument|ThemeButtonKind buttonKindToCheck
argument_list|)
specifier|const
block|;
name|void
name|initHIThemePushButton
argument_list|(
argument|const QStyleOptionButton *btn
argument_list|,
argument|const QWidget *widget
argument_list|,
argument|const ThemeDrawState tds
argument_list|,
argument|HIThemeButtonDrawInfo *bdi
argument_list|)
specifier|const
block|;
name|QPixmap
name|generateBackgroundPattern
argument_list|()
specifier|const
block|;
name|void
name|setAutoDefaultButton
argument_list|(
argument|QObject *button
argument_list|)
specifier|const
block|;
name|NSView
operator|*
name|cocoaControl
argument_list|(
argument|QCocoaWidget widget
argument_list|,
argument|QPoint *offset
argument_list|)
specifier|const
block|;
name|void
name|drawNSViewInRect
argument_list|(
argument|NSView *view
argument_list|,
argument|const QRect&rect
argument_list|,
argument|QPainter *p
argument_list|)
specifier|const
block|;
name|void
name|resolveCurrentNSView
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|public
operator|:
name|mutable
name|QPointer
operator|<
name|QObject
operator|>
name|pressedButton
block|;
name|mutable
name|QPointer
operator|<
name|QObject
operator|>
name|defaultButton
block|;
name|mutable
name|QPointer
operator|<
name|QObject
operator|>
name|autoDefaultButton
block|;
specifier|static
name|QSet
operator|<
name|QPointer
operator|<
name|QObject
operator|>
expr|>
name|scrollBars
block|;      struct
name|ButtonState
block|{
name|int
name|frame
block|;         enum
block|{
name|ButtonDark
block|,
name|ButtonLight
block|}
name|dir
block|;     }
name|buttonState
block|;
name|mutable
name|QPointer
operator|<
name|QFocusFrame
operator|>
name|focusWidget
block|;
name|CFAbsoluteTime
name|defaultButtonStart
block|;
name|bool
name|mouseDown
block|;
if|#
directive|if
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
name|MAC_OS_X_VERSION_10_7
name|void
operator|*
name|receiver
block|;
name|void
operator|*
name|nsscroller
block|;
endif|#
directive|endif
name|void
operator|*
name|indicatorBranchButtonCell
block|;
name|NSView
operator|*
name|backingStoreNSView
block|;
name|QHash
operator|<
name|QCocoaWidget
block|,
name|NSView
operator|*
operator|>
name|cocoaControls
block|; }
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
comment|// QMACSTYLE_MAC_P_P_H
end_comment
end_unit
