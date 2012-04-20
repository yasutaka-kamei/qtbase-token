begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAWINDOW_H
end_ifndef
begin_define
DECL|macro|QCOCOAWINDOW_H
define|#
directive|define
name|QCOCOAWINDOW_H
end_define
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|<QPlatformWindow>
end_include
begin_include
include|#
directive|include
file|<QRect>
end_include
begin_include
include|#
directive|include
file|"qcocoaglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qnsview.h"
end_include
begin_function_decl
name|class
name|QT_PREPEND_NAMESPACE
parameter_list|(
name|QCocoaWindow
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
unit|@
name|interface
name|QNSWindow
range|:
name|NSWindow
block|{     @
name|public
name|QCocoaWindow
operator|*
name|m_cocoaPlatformWindow
block|; }
operator|-
operator|(
name|BOOL
operator|)
name|canBecomeKeyWindow
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|QNSPanel
operator|:
name|NSPanel
block|{     @
name|public
name|QT_PREPEND_NAMESPACE
argument_list|(
name|QCocoaWindow
argument_list|)
operator|*
name|m_cocoaPlatformWindow
block|; }
operator|-
operator|(
name|BOOL
operator|)
name|canBecomeKeyWindow
expr_stmt|;
end_expr_stmt
begin_decl_stmt
unit|@
name|end
name|QT_BEGIN_NAMESPACE
comment|// QCocoaWindow
comment|//
comment|// QCocoaWindow is an NSView (not an NSWindow!) in the sense
comment|// that it relies on a NSView for all event handling and
comment|// graphics output and does not require a NSWindow, except for
comment|// for the window-related functions like setWindowTitle.
comment|//
comment|// As a consequence of this it is possible to embed the QCocoaWindow
comment|// in an NSView hierarchy by getting a pointer to the "backing"
comment|// NSView and not calling QCocoaWindow::show():
comment|//
comment|// QWindow *qtWindow = new MyWindow();
comment|// qtWindow->create();
comment|// QPlatformNativeInterface *platformNativeInterface = QGuiApplication::platformNativeInterface();
comment|// NSView *qtView = (NSView *)platformNativeInterface->nativeResourceForWindow("nsview", qtWindow);
comment|// [parentView addSubview:qtView];
comment|//
comment|// See the qt_on_cocoa manual tests for a working example, located
comment|// in tests/manual/cocoa at the time of writing.
name|class
name|QCocoaWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
name|QCocoaWindow
argument_list|(
name|QWindow
operator|*
name|tlw
argument_list|)
block|;
operator|~
name|QCocoaWindow
argument_list|()
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|setCocoaGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|Qt
operator|::
name|WindowFlags
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|Qt
operator|::
name|WindowState
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
name|void
name|setWindowTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
block|;
name|void
name|raise
argument_list|()
block|;
name|void
name|lower
argument_list|()
block|;
name|void
name|propagateSizeHints
argument_list|()
block|;
name|void
name|setOpacity
argument_list|(
argument|qreal level
argument_list|)
block|;
name|bool
name|setKeyboardGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|;
name|bool
name|setMouseGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|;
name|WId
name|winId
argument_list|()
specifier|const
block|;
name|void
name|setParent
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|window
argument_list|)
block|;
name|NSView
operator|*
name|contentView
argument_list|()
specifier|const
block|;
name|void
name|windowWillMove
argument_list|()
block|;
name|void
name|windowDidMove
argument_list|()
block|;
name|void
name|windowDidResize
argument_list|()
block|;
name|void
name|windowWillClose
argument_list|()
block|;
name|bool
name|windowIsPopupType
argument_list|()
specifier|const
block|;
name|void
name|setCurrentContext
argument_list|(
name|QCocoaGLContext
operator|*
name|context
argument_list|)
block|;
name|QCocoaGLContext
operator|*
name|currentContext
argument_list|()
specifier|const
block|;
name|bool
name|setWindowModified
argument_list|(
argument|bool modified
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
comment|// NSWindow handling. The QCocoaWindow/QNSView can either be displayed
comment|// in an existing NSWindow or in one created by Qt.
name|void
name|recreateWindow
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|parentWindow
argument_list|)
block|;
name|NSWindow
operator|*
name|createNSWindow
argument_list|()
block|;
name|void
name|setNSWindow
argument_list|(
name|NSWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|clearNSWindow
argument_list|(
name|NSWindow
operator|*
name|window
argument_list|)
block|;
name|QRect
name|windowGeometry
argument_list|()
specifier|const
block|;
name|QCocoaWindow
operator|*
name|parentCocoaWindow
argument_list|()
specifier|const
block|;
name|void
name|syncWindowState
argument_list|(
argument|Qt::WindowState newState
argument_list|)
block|;
comment|// private:
name|public
operator|:
comment|// for QNSView
name|friend
name|class
name|QCocoaBackingStore
block|;
name|friend
name|class
name|QCocoaNativeInterface
block|;
name|QNSView
operator|*
name|m_contentView
block|;
name|NSWindow
operator|*
name|m_nsWindow
block|;
name|Qt
operator|::
name|WindowFlags
name|m_windowFlags
block|;
name|QPointer
operator|<
name|QWindow
operator|>
name|m_activePopupWindow
block|;
name|bool
name|m_inConstructor
block|;
name|QCocoaGLContext
operator|*
name|m_glContext
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
comment|// QCOCOAWINDOW_H
end_comment
end_unit
