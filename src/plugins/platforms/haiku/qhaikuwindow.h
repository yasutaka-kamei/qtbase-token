begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2015 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Tobias Koenig<tobias.koenig@kdab.com> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHAIKUWINDOW_H
end_ifndef
begin_define
DECL|macro|QHAIKUWINDOW_H
define|#
directive|define
name|QHAIKUWINDOW_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<Window.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QObject
name|class
name|HaikuWindowProxy
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|BWindow
block|{
name|Q_OBJECT
name|public
range|:
name|explicit
name|HaikuWindowProxy
argument_list|(
name|QWindow
operator|*
name|window
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
decl_stmt|;
name|void
name|FrameMoved
argument_list|(
name|BPoint
name|pos
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|FrameResized
argument_list|(
name|float
name|width
argument_list|,
name|float
name|height
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|WindowActivated
argument_list|(
name|bool
name|activated
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|Minimize
argument_list|(
name|bool
name|minimize
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|Zoom
argument_list|(
name|BPoint
name|pos
argument_list|,
name|float
name|width
argument_list|,
name|float
name|height
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|QuitRequested
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|zoomByQt
parameter_list|()
function_decl|;
name|Q_SIGNALS
label|:
name|void
name|moved
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
function_decl|;
name|void
name|resized
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|bool
name|zoomInProgress
parameter_list|)
function_decl|;
name|void
name|windowActivated
parameter_list|(
name|bool
name|activated
parameter_list|)
function_decl|;
name|void
name|minimized
parameter_list|(
name|bool
name|minimize
parameter_list|)
function_decl|;
name|void
name|zoomed
parameter_list|()
function_decl|;
name|void
name|quitRequested
parameter_list|()
function_decl|;
name|private
label|:
name|bool
name|m_qtCalledZoom
decl_stmt|;
name|bool
name|m_zoomInProgress
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QHaikuWindow
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformWindow
block|{
name|Q_OBJECT
name|public
range|:
name|explicit
name|QHaikuWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|QHaikuWindow
argument_list|()
expr_stmt|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QMargins
name|frameMargins
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|setVisible
argument_list|(
name|bool
name|visible
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|isExposed
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|bool
name|isActive
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|WId
name|winId
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|BWindow
operator|*
name|nativeHandle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|requestActivateWindow
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|setWindowState
argument_list|(
name|Qt
operator|::
name|WindowState
name|state
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setWindowFlags
argument_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|setWindowTitle
argument_list|(
specifier|const
name|QString
operator|&
name|title
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
name|propagateSizeHints
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|protected
label|:
name|HaikuWindowProxy
modifier|*
name|m_window
decl_stmt|;
name|private
name|Q_SLOTS
range|:
name|void
name|haikuWindowMoved
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
decl_stmt|;
name|void
name|haikuWindowResized
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
name|bool
name|zoomInProgress
parameter_list|)
function_decl|;
name|void
name|haikuWindowActivated
parameter_list|(
name|bool
name|activated
parameter_list|)
function_decl|;
name|void
name|haikuWindowMinimized
parameter_list|(
name|bool
name|minimize
parameter_list|)
function_decl|;
name|void
name|haikuWindowZoomed
parameter_list|()
function_decl|;
name|void
name|haikuWindowQuitRequested
parameter_list|()
function_decl|;
name|void
name|haikuMouseEvent
argument_list|(
specifier|const
name|QPoint
operator|&
name|localPosition
argument_list|,
specifier|const
name|QPoint
operator|&
name|globalPosition
argument_list|,
name|Qt
operator|::
name|MouseButtons
name|buttons
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
argument_list|,
name|Qt
operator|::
name|MouseEventSource
name|source
argument_list|)
decl_stmt|;
name|void
name|haikuWheelEvent
argument_list|(
specifier|const
name|QPoint
operator|&
name|localPosition
argument_list|,
specifier|const
name|QPoint
operator|&
name|globalPosition
argument_list|,
name|int
name|delta
argument_list|,
name|Qt
operator|::
name|Orientation
name|orientation
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
argument_list|)
decl_stmt|;
name|void
name|haikuKeyEvent
argument_list|(
name|QEvent
operator|::
name|Type
name|type
argument_list|,
name|int
name|key
argument_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
decl_stmt|;
name|void
name|haikuEnteredView
parameter_list|()
function_decl|;
name|void
name|haikuExitedView
parameter_list|()
function_decl|;
name|void
name|haikuDrawRequest
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|private
label|:
name|Qt
operator|::
name|WindowState
name|m_windowState
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit