begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qpa/qplatformwindow.h>
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
begin_expr_stmt
name|QT_FORWARD_DECLARE_CLASS
argument_list|(
name|QCocoaWindow
argument_list|)
expr|@
name|class
name|QNSWindowDelegate
expr_stmt|;
end_expr_stmt
begin_decl_stmt
unit|@
name|interface
name|QNSWindow
range|:
name|NSPanel
block|{ @
name|public
name|QCocoaWindow
operator|*
name|m_cocoaPlatformWindow
block|; }
operator|-
operator|(
name|void
operator|)
name|clearPlatformWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|@
name|end
name|QT_BEGIN_NAMESPACE
comment|// QCocoaWindow
comment|//
comment|// A QCocoaWindow is backed by a NSView and optionally a NSWindow.
comment|//
comment|// The NSView is used for most event handling and graphics output.
comment|//
comment|// Top-level QWindows are always backed by a NSWindow in addition to
comment|// the NSView. Child QWindows can also be backed by NSWindows, which
comment|// enables proper stacking of GL Widgets and threaded GL rendering
comment|// to multiple contexts.
comment|//
comment|// It is possible to embed the QCocoaWindow in an NSView hierarchy
comment|// by getting a pointer to the backing NSView and not calling
comment|// QCocoaWindow::show():
comment|//
comment|// QWindow *qtWindow = new MyWindow();
comment|// qtWindow->create();
comment|// QPlatformNativeInterface *platformNativeInterface = QGuiApplication::platformNativeInterface();
comment|// NSView *qtView = (NSView *)platformNativeInterface->nativeResourceForWindow("nsview", qtWindow);
comment|// [parentView addSubview:qtView];
comment|//
comment|// See the qt_on_cocoa manual tests for a working example, located
comment|// in tests/manual/cocoa at the time of writing.
DECL|variable|QCocoaMenuBar
name|class
name|QCocoaMenuBar
decl_stmt|;
end_decl_stmt
begin_decl_stmt
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
name|void
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|void
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
name|setWindowFilePath
argument_list|(
specifier|const
name|QString
operator|&
name|filePath
argument_list|)
block|;
name|void
name|setWindowIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
name|void
name|setAlertState
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|isAlertState
argument_list|()
specifier|const
block|;
name|void
name|raise
argument_list|()
block|;
name|void
name|lower
argument_list|()
block|;
name|bool
name|isExposed
argument_list|()
specifier|const
block|;
name|bool
name|isOpaque
argument_list|()
specifier|const
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
name|void
name|setMask
argument_list|(
specifier|const
name|QRegion
operator|&
name|region
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
name|QMargins
name|frameMargins
argument_list|()
specifier|const
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|void
name|requestActivateWindow
argument_list|()
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
name|setContentView
argument_list|(
name|NSView
operator|*
name|contentView
argument_list|)
block|;
name|void
name|setEmbeddedInForeignView
argument_list|(
argument|bool subwindow
argument_list|)
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
name|bool
name|windowShouldClose
argument_list|()
block|;
name|bool
name|windowIsPopupType
argument_list|(
argument|Qt::WindowType type = Qt::Widget
argument_list|)
specifier|const
block|;
name|bool
name|windowShouldBehaveAsPanel
argument_list|()
specifier|const
block|;
name|void
name|setSynchedWindowStateFromWindow
argument_list|()
block|;
name|NSInteger
name|windowLevel
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|NSUInteger
name|windowStyleMask
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|void
name|setWindowShadow
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
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
name|void
name|setFrameStrutEventsEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|bool
name|frameStrutEventsEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_frameStrutEventsEnabled
return|;
block|}
name|void
name|setMenubar
argument_list|(
name|QCocoaMenuBar
operator|*
name|mb
argument_list|)
block|;
name|QCocoaMenuBar
operator|*
name|menubar
argument_list|()
specifier|const
block|;
name|void
name|setWindowCursor
argument_list|(
name|NSCursor
operator|*
name|cursor
argument_list|)
block|;
name|void
name|registerTouch
argument_list|(
argument|bool enable
argument_list|)
block|;
name|void
name|setContentBorderThickness
argument_list|(
argument|int topThickness
argument_list|,
argument|int bottomThickness
argument_list|)
block|;
name|void
name|applyContentBorderThickness
argument_list|(
name|NSWindow
operator|*
name|window
argument_list|)
block|;
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
block|;
name|bool
name|isWindowExposable
argument_list|()
block|;
name|void
name|exposeWindow
argument_list|()
block|;
name|void
name|obscureWindow
argument_list|()
block|;
name|void
name|updateExposedGeometry
argument_list|()
block|;
name|QWindow
operator|*
name|childWindowAt
argument_list|(
argument|QPoint windowPoint
argument_list|)
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
name|QNSWindow
operator|*
name|createNSWindow
argument_list|()
block|;
name|void
name|setNSWindow
argument_list|(
name|QNSWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|clearNSWindow
argument_list|(
name|QNSWindow
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
name|NSView
operator|*
name|m_contentView
block|;
name|QNSView
operator|*
name|m_qtView
block|;
name|QNSWindow
operator|*
name|m_nsWindow
block|;
comment|// TODO merge to one variable if possible
name|bool
name|m_contentViewIsEmbedded
block|;
comment|// true if the m_contentView is actually embedded in a "foreign" NSView hiearchy
name|bool
name|m_contentViewIsToBeEmbedded
block|;
comment|// true if the m_contentView is intended to be embedded in a "foreign" NSView hiearchy
name|QCocoaWindow
operator|*
name|m_parentCocoaWindow
block|;
name|QNSWindowDelegate
operator|*
name|m_nsWindowDelegate
block|;
name|Qt
operator|::
name|WindowFlags
name|m_windowFlags
block|;
name|Qt
operator|::
name|WindowState
name|m_synchedWindowState
block|;
name|Qt
operator|::
name|WindowModality
name|m_windowModality
block|;
name|QPointer
operator|<
name|QWindow
operator|>
name|m_activePopupWindow
block|;
name|QPointer
operator|<
name|QWindow
operator|>
name|m_enterLeaveTargetWindow
block|;
name|bool
name|m_windowUnderMouse
block|;
name|bool
name|m_inConstructor
block|;
name|QCocoaGLContext
operator|*
name|m_glContext
block|;
name|QCocoaMenuBar
operator|*
name|m_menubar
block|;
name|NSCursor
operator|*
name|m_windowCursor
block|;
name|bool
name|m_hasModalSession
block|;
name|bool
name|m_frameStrutEventsEnabled
block|;
name|bool
name|m_geometryUpdateExposeAllowed
block|;
name|bool
name|m_isExposed
block|;
name|QRect
name|m_exposedGeometry
block|;
name|int
name|m_registerTouchCount
block|;
name|bool
name|m_resizableTransientParent
block|;
name|bool
name|m_overrideBecomeKey
block|;
specifier|static
specifier|const
name|int
name|NoAlertRequest
block|;
name|NSInteger
name|m_alertRequest
block|;
name|id
name|monitor
block|;
name|bool
name|m_drawContentBorderGradient
block|;
name|int
name|m_topContentBorderThickness
block|;
name|int
name|m_bottomContentBorderThickness
block|;
comment|// used by showFullScreen in fake mode
name|QRect
name|m_normalGeometry
block|;
name|Qt
operator|::
name|WindowFlags
name|m_oldWindowFlags
block|;
name|NSApplicationPresentationOptions
name|m_presentationOptions
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
