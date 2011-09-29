begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOW_QPA_H
end_ifndef
begin_define
DECL|macro|QWINDOW_QPA_H
define|#
directive|define
name|QWINDOW_QPA_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QEvent>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMargins>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRect>
end_include
begin_include
include|#
directive|include
file|<QtGui/qsurface.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qsurfaceformat.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QWindowPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QExposeEvent
name|class
name|QExposeEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFocusEvent
name|class
name|QFocusEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMoveEvent
name|class
name|QMoveEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QResizeEvent
name|class
name|QResizeEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QShowEvent
name|class
name|QShowEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHideEvent
name|class
name|QHideEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKeyEvent
name|class
name|QKeyEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QInputMethodEvent
name|class
name|QInputMethodEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
end_ifndef
begin_decl_stmt
DECL|variable|QWheelEvent
name|class
name|QWheelEvent
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QPlatformSurface
name|class
name|QPlatformSurface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformWindow
name|class
name|QPlatformWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QBackingStore
name|class
name|QBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScreen
name|class
name|QScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleInterface
name|class
name|QAccessibleInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|Q_GUI_EXPORT
name|QWindow
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QSurface
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
name|QWindow
argument_list|)
name|Q_PROPERTY
argument_list|(
name|QString
name|windowTitle
name|READ
name|windowTitle
name|WRITE
name|setWindowTitle
argument_list|)
name|public
range|:     enum
name|SurfaceType
block|{
name|RasterSurface
block|,
name|OpenGLSurface
block|}
decl_stmt|;
name|QWindow
argument_list|(
name|QScreen
operator|*
name|screen
operator|=
literal|0
argument_list|)
expr_stmt|;
name|QWindow
argument_list|(
name|QWindow
operator|*
name|parent
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QWindow
argument_list|()
expr_stmt|;
name|void
name|setSurfaceType
parameter_list|(
name|SurfaceType
name|surfaceType
parameter_list|)
function_decl|;
name|SurfaceType
name|surfaceType
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
function_decl|;
name|bool
name|visible
argument_list|()
specifier|const
expr_stmt|;
name|void
name|create
parameter_list|()
function_decl|;
name|WId
name|winId
argument_list|()
specifier|const
expr_stmt|;
name|QWindow
operator|*
name|parent
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setParent
parameter_list|(
name|QWindow
modifier|*
name|parent
parameter_list|)
function_decl|;
name|bool
name|isTopLevel
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isModal
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|WindowModality
name|windowModality
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWindowModality
argument_list|(
name|Qt
operator|::
name|WindowModality
name|windowModality
argument_list|)
decl_stmt|;
name|void
name|setFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
expr_stmt|;
name|QSurfaceFormat
name|requestedFormat
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|WindowFlags
name|windowFlags
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|WindowType
name|windowType
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|windowTitle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setOpacity
parameter_list|(
name|qreal
name|level
parameter_list|)
function_decl|;
name|void
name|requestActivateWindow
parameter_list|()
function_decl|;
name|bool
name|isActive
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|WindowState
name|windowState
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setWindowState
argument_list|(
name|Qt
operator|::
name|WindowState
name|state
argument_list|)
decl_stmt|;
name|void
name|setTransientParent
parameter_list|(
name|QWindow
modifier|*
name|parent
parameter_list|)
function_decl|;
name|QWindow
operator|*
name|transientParent
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|AncestorMode
block|{
name|ExcludeTransients
block|,
name|IncludeTransients
block|}
enum|;
name|bool
name|isAncestorOf
argument_list|(
specifier|const
name|QWindow
operator|*
name|child
argument_list|,
name|AncestorMode
name|mode
operator|=
name|IncludeTransients
argument_list|)
decl|const
decl_stmt|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|maximumSize
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|baseSize
argument_list|()
specifier|const
expr_stmt|;
name|QSize
name|sizeIncrement
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMinimumSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|void
name|setMaximumSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|void
name|setBaseSize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|void
name|setSizeIncrement
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
function_decl|;
name|void
name|setGeometry
parameter_list|(
name|int
name|posx
parameter_list|,
name|int
name|posy
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|posx
argument_list|,
name|posy
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|QRect
name|geometry
argument_list|()
specifier|const
expr_stmt|;
name|QMargins
name|frameMargins
argument_list|()
specifier|const
expr_stmt|;
name|QRect
name|frameGeometry
argument_list|()
specifier|const
expr_stmt|;
name|QPoint
name|framePos
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFramePos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|point
parameter_list|)
function_decl|;
specifier|inline
name|int
name|width
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|width
argument_list|()
return|;
block|}
specifier|inline
name|int
name|height
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|height
argument_list|()
return|;
block|}
specifier|inline
name|int
name|x
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|x
argument_list|()
return|;
block|}
specifier|inline
name|int
name|y
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|y
argument_list|()
return|;
block|}
specifier|inline
name|QSize
name|size
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
specifier|inline
name|QPoint
name|pos
argument_list|()
specifier|const
block|{
return|return
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
return|;
block|}
name|QT_DEPRECATED
specifier|inline
name|void
name|move
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|)
block|{
name|setPos
argument_list|(
name|pt
argument_list|)
expr_stmt|;
block|}
name|QT_DEPRECATED
specifier|inline
name|void
name|move
parameter_list|(
name|int
name|posx
parameter_list|,
name|int
name|posy
parameter_list|)
block|{
name|setPos
argument_list|(
name|posx
argument_list|,
name|posy
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|)
block|{
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|pt
argument_list|,
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|void
name|setPos
parameter_list|(
name|int
name|posx
parameter_list|,
name|int
name|posy
parameter_list|)
block|{
name|setPos
argument_list|(
name|QPoint
argument_list|(
name|posx
argument_list|,
name|posy
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|newSize
parameter_list|)
function_decl|;
specifier|inline
name|void
name|resize
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|)
block|{
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|x
argument_list|()
argument_list|,
name|y
argument_list|()
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|setWindowIcon
argument_list|(
specifier|const
name|QImage
operator|&
name|icon
argument_list|)
decl|const
decl_stmt|;
name|void
name|destroy
parameter_list|()
function_decl|;
name|QPlatformWindow
operator|*
name|handle
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|setKeyboardGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
function_decl|;
name|bool
name|setMouseGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
function_decl|;
name|QScreen
operator|*
name|screen
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setScreen
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
name|virtual
name|QAccessibleInterface
operator|*
name|accessibleRoot
argument_list|()
specifier|const
expr_stmt|;
name|QPoint
name|mapToGlobal
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
decl|const
decl_stmt|;
name|QPoint
name|mapFromGlobal
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
decl|const
decl_stmt|;
name|public
name|Q_SLOTS
range|:
specifier|inline
name|void
name|show
argument_list|()
block|{
name|setVisible
argument_list|(
name|true
argument_list|)
block|; }
specifier|inline
name|void
name|hide
argument_list|()
block|{
name|setVisible
argument_list|(
name|false
argument_list|)
block|; }
name|void
name|showMinimized
argument_list|()
decl_stmt|;
name|void
name|showMaximized
parameter_list|()
function_decl|;
name|void
name|showFullScreen
parameter_list|()
function_decl|;
name|void
name|showNormal
parameter_list|()
function_decl|;
name|bool
name|close
parameter_list|()
function_decl|;
name|void
name|raise
parameter_list|()
function_decl|;
name|void
name|lower
parameter_list|()
function_decl|;
name|void
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|Q_SIGNALS
label|:
name|void
name|backBufferReady
parameter_list|()
function_decl|;
name|protected
label|:
name|virtual
name|void
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|moveEvent
parameter_list|(
name|QMoveEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|focusInEvent
parameter_list|(
name|QFocusEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|focusOutEvent
parameter_list|(
name|QFocusEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|showEvent
parameter_list|(
name|QShowEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|hideEvent
parameter_list|(
name|QHideEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|keyPressEvent
parameter_list|(
name|QKeyEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|keyReleaseEvent
parameter_list|(
name|QKeyEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|inputMethodEvent
parameter_list|(
name|QInputMethodEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
function_decl|;
name|virtual
name|void
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|virtual
name|void
name|wheelEvent
parameter_list|(
name|QWheelEvent
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
name|QWindow
argument_list|(
name|QWindowPrivate
operator|&
name|dd
argument_list|,
name|QWindow
operator|*
name|parent
argument_list|)
expr_stmt|;
name|private
label|:
name|QPlatformSurface
operator|*
name|surfaceHandle
argument_list|()
specifier|const
expr_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QWindow
argument_list|)
name|friend
name|class
name|QGuiApplication
decl_stmt|;
name|friend
name|class
name|QGuiApplicationPrivate
decl_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QWindowPrivate
modifier|*
name|qt_window_private
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOW_QPA_H
end_comment
end_unit
