begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNSVIEW_H
end_ifndef
begin_define
DECL|macro|QNSVIEW_H
define|#
directive|define
name|QNSVIEW_H
end_define
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QPointer>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtGui/QAccessible>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCocoaWindow
name|class
name|QCocoaWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCocoaBackingStore
name|class
name|QCocoaBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCocoaGLContext
name|class
name|QCocoaGLContext
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
expr|@
name|interface
name|QNSView
operator|:
name|NSView
operator|<
name|NSTextInputClient
operator|>
block|{
name|QCocoaBackingStore
operator|*
name|m_backingStore
block|;
name|QPoint
name|m_backingStoreOffset
block|;
name|CGImageRef
name|m_maskImage
block|;
name|uchar
operator|*
name|m_maskData
block|;
name|QWindow
operator|*
name|m_window
block|;
name|QCocoaWindow
operator|*
name|m_platformWindow
block|;
name|Qt
operator|::
name|MouseButtons
name|m_buttons
block|;
name|QAccessibleInterface
operator|*
name|m_accessibleRoot
block|;
name|QString
name|m_composingText
block|;
name|bool
name|m_sendKeyEvent
block|;
name|QStringList
operator|*
name|currentCustomDragTypes
block|;
name|bool
name|m_sendUpAsRightButton
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|currentWheelModifiers
block|;
name|bool
name|m_subscribesForGlobalFrameNotifications
block|; }
operator|-
operator|(
name|id
operator|)
name|init
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|initWithQWindow
operator|:
operator|(
name|QWindow
operator|*
operator|)
name|window
name|platformWindow
operator|:
operator|(
name|QCocoaWindow
operator|*
operator|)
name|platformWindow
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setQCocoaGLContext
operator|:
operator|(
name|QCocoaGLContext
operator|*
operator|)
name|context
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|flushBackingStore
operator|:
operator|(
name|QCocoaBackingStore
operator|*
operator|)
name|backingStore
name|region
operator|:
operator|(
specifier|const
name|QRegion
operator|&
operator|)
name|region
name|offset
operator|:
operator|(
name|QPoint
operator|)
name|offset
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setMaskRegion
operator|:
operator|(
specifier|const
name|QRegion
operator|*
operator|)
name|region
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|drawRect
operator|:
operator|(
name|NSRect
operator|)
name|dirtyRect
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|updateGeometry
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|windowNotification
operator|:
operator|(
name|NSNotification
operator|*
operator|)
name|windowNotification
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isFlipped
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|acceptsFirstResponder
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|becomeFirstResponder
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|resetMouseButtons
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|handleMouseEvent
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseDown
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseDragged
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseUp
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseMoved
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseEntered
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|mouseExited
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|rightMouseDown
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|rightMouseDragged
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|rightMouseUp
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|otherMouseDown
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|otherMouseDragged
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|otherMouseUp
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|handleFrameStrutMouseEvent
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|int
operator|)
name|convertKeyCode
operator|:
operator|(
name|QChar
operator|)
name|keyCode
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|Qt
operator|::
name|KeyboardModifiers
operator|)
name|convertKeyModifiers
operator|:
operator|(
name|ulong
operator|)
name|modifierFlags
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|handleKeyEvent
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
name|eventType
operator|:
operator|(
name|int
operator|)
name|eventType
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|keyDown
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|keyUp
operator|:
operator|(
name|NSEvent
operator|*
operator|)
name|theEvent
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|registerDragTypes
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|NSDragOperation
operator|)
name|handleDrag
operator|:
operator|(
name|id
operator|<
name|NSDraggingInfo
operator|>
operator|)
name|sender
expr_stmt|;
end_expr_stmt
begin_macro
unit|@
name|end
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QNSVIEW_H
end_comment
end_unit
