begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtGui/qwindowformat_qpa.h>
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
DECL|variable|QPlatformWindow
name|class
name|QPlatformWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowContext
name|class
name|QWindowContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowSurface
name|class
name|QWindowSurface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QWindow
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWindow
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString windowTitle READ windowTitle WRITE setWindowTitle
argument_list|)
name|public
operator|:
expr|enum
name|SurfaceType
block|{
name|RasterSurface
block|,
name|OpenGLSurface
block|}
block|;
name|QWindow
argument_list|(
name|QWindow
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QWindow
argument_list|()
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|bool
name|visible
argument_list|()
specifier|const
block|;
name|void
name|create
argument_list|()
block|;
name|WId
name|winId
argument_list|()
specifier|const
block|;
name|QWindow
operator|*
name|parent
argument_list|()
specifier|const
block|;
name|void
name|setParent
argument_list|(
name|QWindow
operator|*
name|parent
argument_list|)
block|;
name|bool
name|isTopLevel
argument_list|()
specifier|const
block|;
name|bool
name|isModal
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|WindowModality
name|windowModality
argument_list|()
specifier|const
block|;
name|void
name|setWindowModality
argument_list|(
argument|Qt::WindowModality windowModality
argument_list|)
block|;
name|void
name|setWindowFormat
argument_list|(
specifier|const
name|QWindowFormat
operator|&
name|format
argument_list|)
block|;
name|QWindowFormat
name|requestedWindowFormat
argument_list|()
specifier|const
block|;
name|QWindowFormat
name|actualWindowFormat
argument_list|()
specifier|const
block|;
name|void
name|setSurfaceType
argument_list|(
argument|SurfaceType type
argument_list|)
block|;
name|SurfaceType
name|surfaceType
argument_list|()
specifier|const
block|;
name|void
name|setWindowFlags
argument_list|(
argument|Qt::WindowFlags flags
argument_list|)
block|;
name|Qt
operator|::
name|WindowFlags
name|windowFlags
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|WindowType
name|windowType
argument_list|()
specifier|const
block|;
name|QString
name|windowTitle
argument_list|()
specifier|const
block|;
name|void
name|setOpacity
argument_list|(
argument|qreal level
argument_list|)
block|;
name|void
name|requestActivateWindow
argument_list|()
block|;
name|Qt
operator|::
name|WindowState
name|windowState
argument_list|()
specifier|const
block|;
name|void
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
name|void
name|setTransientParent
argument_list|(
name|QWindow
operator|*
name|parent
argument_list|)
block|;
name|QWindow
operator|*
name|transientParent
argument_list|()
specifier|const
block|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
block|;
name|QSize
name|maximumSize
argument_list|()
specifier|const
block|;
name|QSize
name|baseSize
argument_list|()
specifier|const
block|;
name|QSize
name|sizeIncrement
argument_list|()
specifier|const
block|;
name|void
name|setMinimumSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|void
name|setMaximumSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|void
name|setBaseSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|void
name|setSizeIncrement
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|)
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
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|void
name|setWindowIcon
argument_list|(
argument|const QImage&icon
argument_list|)
specifier|const
block|;
name|QWindowContext
operator|*
name|glContext
argument_list|()
specifier|const
block|;
name|void
name|destroy
argument_list|()
block|;
name|QPlatformWindow
operator|*
name|handle
argument_list|()
specifier|const
block|;
name|QWindowSurface
operator|*
name|surface
argument_list|()
specifier|const
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
name|public
name|Q_SLOTS
operator|:
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
block|;
name|void
name|showMaximized
argument_list|()
block|;
name|void
name|showFullScreen
argument_list|()
block|;
name|void
name|showNormal
argument_list|()
block|;
name|bool
name|close
argument_list|()
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
name|setWindowTitle
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|backBufferReady
argument_list|()
block|;
name|protected
operator|:
name|virtual
name|void
name|resizeEvent
argument_list|(
name|QResizeEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|showEvent
argument_list|(
name|QShowEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|hideEvent
argument_list|(
name|QHideEvent
operator|*
argument_list|)
block|;
name|virtual
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|keyReleaseEvent
argument_list|(
name|QKeyEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|inputMethodEvent
argument_list|(
name|QInputMethodEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|mouseDoubleClickEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|mouseMoveEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|virtual
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QWindow
argument_list|)
name|friend
name|class
name|QGuiApplication
block|;
name|friend
name|class
name|QGuiApplicationPrivate
block|;
name|friend
name|class
name|QWindowSurface
block|;
name|friend
name|Q_GUI_EXPORT
name|QWindowPrivate
operator|*
name|qt_window_private
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
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
