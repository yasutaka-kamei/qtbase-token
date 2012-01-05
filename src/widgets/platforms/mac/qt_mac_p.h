begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_MAC_P_H
end_ifndef
begin_define
DECL|macro|QT_MAC_P_H
define|#
directive|define
name|QT_MAC_P_H
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
begin_include
include|#
directive|include
file|"qmacdefines_mac.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|__OBJC__
end_ifdef
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|<objc/runtime.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<CoreServices/CoreServices.h>
end_include
begin_include
include|#
directive|include
file|"QtCore/qglobal.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvariant.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmimedata.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"private/qcore_mac_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qpainter.h"
end_include
begin_include
include|#
directive|include
file|<Carbon/Carbon.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDragMoveEvent
name|class
name|QDragMoveEvent
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Event masks */
end_comment
begin_comment
comment|// internal Qt types
end_comment
begin_comment
comment|// Event class for our own Carbon events.
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_NAMESPACE
argument_list|)
operator|&&
name|defined
argument_list|(
name|QT_NAMESPACE_MAC_CRC
argument_list|)
end_if
begin_comment
comment|// Take the CRC we generated at configure time. This *may* result in a
end_comment
begin_comment
comment|// collision with another value If that is the case, please change the value
end_comment
begin_comment
comment|// here to something other than 'Cute'.
end_comment
begin_decl_stmt
DECL|variable|kEventClassQt
specifier|const
name|UInt32
name|kEventClassQt
init|=
name|QT_NAMESPACE_MAC_CRC
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
DECL|variable|kEventClassQt
specifier|const
name|UInt32
name|kEventClassQt
init|=
literal|'Cute'
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_enum
enum|enum
block|{
comment|//AE types
DECL|enumerator|typeAEClipboardChanged
name|typeAEClipboardChanged
init|=
literal|1
block|,
comment|//types
DECL|enumerator|typeQWidget
name|typeQWidget
init|=
literal|1
block|,
comment|/* QWidget *  */
comment|//params
DECL|enumerator|kEventParamQWidget
name|kEventParamQWidget
init|=
literal|'qwid'
block|,
comment|/* typeQWidget */
comment|//events
DECL|enumerator|kEventQtRequestContext
name|kEventQtRequestContext
init|=
literal|13
block|,
DECL|enumerator|kEventQtRequestMenubarUpdate
name|kEventQtRequestMenubarUpdate
init|=
literal|14
block|,
DECL|enumerator|kEventQtRequestShowSheet
name|kEventQtRequestShowSheet
init|=
literal|17
block|,
DECL|enumerator|kEventQtRequestActivate
name|kEventQtRequestActivate
init|=
literal|18
block|,
DECL|enumerator|kEventQtRequestWindowChange
name|kEventQtRequestWindowChange
init|=
literal|20
block|}
enum|;
end_enum
begin_comment
comment|// Simple class to manage short-lived regions
end_comment
begin_decl_stmt
name|class
name|QMacSmartQuickDrawRegion
block|{
name|RgnHandle
name|qdRgn
decl_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QMacSmartQuickDrawRegion
argument_list|)
name|public
label|:
name|explicit
name|QMacSmartQuickDrawRegion
argument_list|(
argument|RgnHandle rgn
argument_list|)
block|:
name|qdRgn
argument_list|(
argument|rgn
argument_list|)
block|{}
operator|~
name|QMacSmartQuickDrawRegion
argument_list|()
block|{
specifier|extern
name|void
name|qt_mac_dispose_rgn
argument_list|(
name|RgnHandle
argument_list|)
block|;
comment|// qregion_mac.cpp
name|qt_mac_dispose_rgn
argument_list|(
name|qdRgn
argument_list|)
block|;     }
name|operator
name|RgnHandle
argument_list|()
block|{
return|return
name|qdRgn
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// Class for chaining to gether a bunch of fades. It pretty much is only used for qmenu fading.
end_comment
begin_decl_stmt
name|class
name|QMacWindowFader
block|{
name|QWidgetList
name|m_windowsToFade
decl_stmt|;
name|float
name|m_duration
decl_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QMacWindowFader
argument_list|)
name|public
label|:
name|QMacWindowFader
argument_list|()
expr_stmt|;
comment|// PLEASE DON'T CALL THIS.
specifier|static
name|QMacWindowFader
modifier|*
name|currentFader
parameter_list|()
function_decl|;
name|void
name|registerWindowToFade
parameter_list|(
name|QWidget
modifier|*
name|window
parameter_list|)
function_decl|;
name|void
name|setFadeDuration
parameter_list|(
name|float
name|durationInSecs
parameter_list|)
block|{
name|m_duration
operator|=
name|durationInSecs
expr_stmt|;
block|}
name|float
name|fadeDuration
argument_list|()
specifier|const
block|{
return|return
name|m_duration
return|;
block|}
name|void
name|performFade
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QMacCocoaAutoReleasePool
block|{
name|private
label|:
name|void
modifier|*
name|pool
decl_stmt|;
name|public
label|:
name|QMacCocoaAutoReleasePool
argument_list|()
expr_stmt|;
operator|~
name|QMacCocoaAutoReleasePool
argument_list|()
expr_stmt|;
specifier|inline
name|void
operator|*
name|handle
argument_list|()
specifier|const
block|{
return|return
name|pool
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function_decl
name|QString
name|qt_mac_removeMnemonics
parameter_list|(
specifier|const
name|QString
modifier|&
name|original
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//implemented in qmacstyle_mac.cpp
end_comment
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QMacWindowChangeEvent
block|{
name|private
label|:
specifier|static
name|QList
operator|<
name|QMacWindowChangeEvent
operator|*
operator|>
operator|*
name|change_events
expr_stmt|;
name|public
label|:
name|QMacWindowChangeEvent
argument_list|()
block|{     }
name|virtual
operator|~
name|QMacWindowChangeEvent
argument_list|()
block|{     }
specifier|static
specifier|inline
name|void
name|exec
argument_list|(
argument|bool
argument_list|)
block|{     }
name|protected
operator|:
name|virtual
name|void
name|windowChanged
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|flushWindowChanged
parameter_list|()
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QMacCGContext
block|{
name|CGContextRef
name|context
decl_stmt|;
name|public
label|:
name|QMacCGContext
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
expr_stmt|;
comment|//qpaintengine_mac.cpp
specifier|inline
name|QMacCGContext
argument_list|()
block|{
name|context
operator|=
literal|0
block|; }
specifier|inline
name|QMacCGContext
argument_list|(
argument|const QPaintDevice *pdev
argument_list|)
block|{
specifier|extern
name|CGContextRef
name|qt_mac_cg_context
argument_list|(
specifier|const
name|QPaintDevice
operator|*
argument_list|)
block|;
name|context
operator|=
name|qt_mac_cg_context
argument_list|(
name|pdev
argument_list|)
block|;     }
specifier|inline
name|QMacCGContext
argument_list|(
argument|CGContextRef cg
argument_list|,
argument|bool takeOwnership=false
argument_list|)
block|{
name|context
operator|=
name|cg
block|;
if|if
condition|(
operator|!
name|takeOwnership
condition|)
name|CGContextRetain
argument_list|(
name|context
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|QMacCGContext
argument_list|(
specifier|const
name|QMacCGContext
operator|&
name|copy
argument_list|)
operator|:
name|context
argument_list|(
literal|0
argument_list|)
block|{
operator|*
name|this
operator|=
name|copy
block|; }
specifier|inline
operator|~
name|QMacCGContext
argument_list|()
block|{
if|if
condition|(
name|context
condition|)
name|CGContextRelease
argument_list|(
name|context
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|context
return|;
block|}
specifier|inline
name|operator
name|CGContextRef
parameter_list|()
block|{
return|return
name|context
return|;
block|}
specifier|inline
name|QMacCGContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QMacCGContext
operator|&
name|copy
operator|)
block|{
if|if
condition|(
name|context
condition|)
name|CGContextRelease
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|context
operator|=
name|copy
operator|.
name|context
decl_stmt|;
name|CGContextRetain
argument_list|(
name|context
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_decl_stmt
specifier|inline
name|QMacCGContext
modifier|&
name|operator
init|=
operator|(
name|CGContextRef
name|cg
operator|)
block|{
if|if
condition|(
name|context
condition|)
name|CGContextRelease
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|context
operator|=
name|cg
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|CGContextRetain
argument_list|(
name|context
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//we do not take ownership
end_comment
begin_return
return|return
operator|*
name|this
return|;
end_return
begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QMacPasteboardMime
name|class
name|QMacPasteboardMime
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMacPasteboard
block|{
struct|struct
name|Promise
block|{
name|Promise
argument_list|()
operator|:
name|itemId
argument_list|(
literal|0
argument_list|)
operator|,
name|convertor
argument_list|(
literal|0
argument_list|)
block|{ }
name|Promise
argument_list|(
argument|int itemId
argument_list|,
argument|QMacPasteboardMime *c
argument_list|,
argument|QString m
argument_list|,
argument|QVariant d
argument_list|,
argument|int o=
literal|0
argument_list|)
operator|:
name|itemId
argument_list|(
name|itemId
argument_list|)
operator|,
name|offset
argument_list|(
name|o
argument_list|)
operator|,
name|convertor
argument_list|(
name|c
argument_list|)
operator|,
name|mime
argument_list|(
name|m
argument_list|)
operator|,
name|data
argument_list|(
argument|d
argument_list|)
block|{ }
name|int
name|itemId
operator|,
name|offset
expr_stmt|;
name|QMacPasteboardMime
modifier|*
name|convertor
decl_stmt|;
name|QString
name|mime
decl_stmt|;
name|QVariant
name|data
decl_stmt|;
block|}
struct|;
name|QList
operator|<
name|Promise
operator|>
name|promises
expr_stmt|;
name|OSPasteboardRef
name|paste
decl_stmt|;
name|uchar
name|mime_type
decl_stmt|;
name|mutable
name|QPointer
operator|<
name|QMimeData
operator|>
name|mime
expr_stmt|;
name|mutable
name|bool
name|mac_mime_source
decl_stmt|;
specifier|static
name|OSStatus
name|promiseKeeper
parameter_list|(
name|OSPasteboardRef
parameter_list|,
name|PasteboardItemID
parameter_list|,
name|CFStringRef
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
name|clear_helper
parameter_list|()
function_decl|;
name|public
label|:
name|QMacPasteboard
argument_list|(
argument|OSPasteboardRef p
argument_list|,
argument|uchar mime_type=
literal|0
argument_list|)
empty_stmt|;
name|QMacPasteboard
argument_list|(
argument|uchar mime_type
argument_list|)
empty_stmt|;
name|QMacPasteboard
argument_list|(
argument|CFStringRef name=
literal|0
argument_list|,
argument|uchar mime_type=
literal|0
argument_list|)
empty_stmt|;
operator|~
name|QMacPasteboard
argument_list|()
expr_stmt|;
name|bool
name|hasFlavor
argument_list|(
name|QString
name|flavor
argument_list|)
decl|const
decl_stmt|;
name|bool
name|hasOSType
argument_list|(
name|int
name|c_flavor
argument_list|)
decl|const
decl_stmt|;
name|OSPasteboardRef
name|pasteBoard
argument_list|()
specifier|const
expr_stmt|;
name|QMimeData
operator|*
name|mimeData
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMimeData
parameter_list|(
name|QMimeData
modifier|*
name|mime
parameter_list|)
function_decl|;
name|QStringList
name|formats
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasFormat
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|)
decl|const
decl_stmt|;
name|QVariant
name|retrieveData
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|,
name|QVariant
operator|::
name|Type
argument_list|)
decl|const
decl_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|bool
name|sync
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
specifier|extern
name|QPaintDevice
modifier|*
name|qt_mac_safe_pdev
decl_stmt|;
end_decl_stmt
begin_comment
comment|//qapplication_mac.cpp
end_comment
begin_function_decl
specifier|extern
name|OSWindowRef
name|qt_mac_window_for
parameter_list|(
specifier|const
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//qwidget_mac.mm
end_comment
begin_function_decl
specifier|extern
name|OSViewRef
name|qt_mac_nativeview_for
parameter_list|(
specifier|const
name|QWidget
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//qwidget_mac.mm
end_comment
begin_function_decl
specifier|extern
name|QPoint
name|qt_mac_nativeMapFromParent
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|child
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//qwidget_mac.mm
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|check
end_ifdef
begin_undef
DECL|macro|check
undef|#
directive|undef
name|check
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|QFont
name|qfontForThemeFont
parameter_list|(
name|ThemeFontID
name|themeID
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QColor
name|qcolorForTheme
parameter_list|(
name|ThemeBrush
name|brush
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QColor
name|qcolorForThemeTextColor
parameter_list|(
name|ThemeTextColor
name|themeColor
parameter_list|)
function_decl|;
end_function_decl
begin_struct
DECL|struct|QMacDndAnswerRecord
struct|struct
name|QMacDndAnswerRecord
block|{
DECL|member|rect
name|QRect
name|rect
decl_stmt|;
DECL|member|modifiers
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
expr_stmt|;
DECL|member|buttons
name|Qt
operator|::
name|MouseButtons
name|buttons
expr_stmt|;
DECL|member|lastAction
name|Qt
operator|::
name|DropAction
name|lastAction
expr_stmt|;
DECL|member|lastOperation
name|unsigned
name|int
name|lastOperation
decl_stmt|;
DECL|function|clear
name|void
name|clear
parameter_list|()
block|{
name|rect
operator|=
name|QRect
argument_list|()
expr_stmt|;
name|modifiers
operator|=
name|Qt
operator|::
name|NoModifier
expr_stmt|;
name|buttons
operator|=
name|Qt
operator|::
name|NoButton
expr_stmt|;
name|lastAction
operator|=
name|Qt
operator|::
name|IgnoreAction
expr_stmt|;
name|lastOperation
operator|=
literal|0
expr_stmt|;
block|}
block|}
struct|;
end_struct
begin_decl_stmt
specifier|extern
name|QMacDndAnswerRecord
name|qt_mac_dnd_answer_rec
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|qt_mac_copy_answer_rect
parameter_list|(
specifier|const
name|QDragMoveEvent
modifier|&
name|event
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|qt_mac_mouse_inside_answer_rect
parameter_list|(
name|QPoint
name|mouse
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_MAC_P_H
end_comment
end_unit
