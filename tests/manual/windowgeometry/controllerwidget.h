begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CONTROLLERWIDGET_H
end_ifndef
begin_define
DECL|macro|CONTROLLERWIDGET_H
define|#
directive|define
name|CONTROLLERWIDGET_H
end_define
begin_include
include|#
directive|include
file|<QMainWindow>
end_include
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QScopedPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSpinBox
name|class
name|QSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QLabel
name|class
name|QLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGridLayout
name|class
name|QGridLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
DECL|variable|TypeControl
name|class
name|TypeControl
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|HintControl
name|class
name|HintControl
decl_stmt|;
end_decl_stmt
begin_comment
comment|// A control for editing points or sizes
end_comment
begin_decl_stmt
name|class
name|CoordinateControl
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|CoordinateControl
argument_list|(
specifier|const
name|QString
operator|&
name|sep
argument_list|)
block|;
name|void
name|setPointValue
argument_list|(
argument|const QPoint&p
argument_list|)
block|{
name|setCoordinates
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|p
operator|.
name|y
argument_list|()
argument_list|)
block|; }
name|QPoint
name|pointValue
argument_list|()
specifier|const
block|{
specifier|const
name|QPair
operator|<
name|int
block|,
name|int
operator|>
name|t
operator|=
name|coordinates
argument_list|()
block|;
return|return
name|QPoint
argument_list|(
name|t
operator|.
name|first
argument_list|,
name|t
operator|.
name|second
argument_list|)
return|;
block|}
name|void
name|setSizeValue
argument_list|(
argument|const QSize&s
argument_list|)
block|{
name|setCoordinates
argument_list|(
name|s
operator|.
name|width
argument_list|()
argument_list|,
name|s
operator|.
name|height
argument_list|()
argument_list|)
block|; }
name|QSize
name|sizeValue
argument_list|()
specifier|const
block|{
specifier|const
name|QPair
operator|<
name|int
block|,
name|int
operator|>
name|t
operator|=
name|coordinates
argument_list|()
block|;
return|return
name|QSize
argument_list|(
name|t
operator|.
name|first
argument_list|,
name|t
operator|.
name|second
argument_list|)
return|;
block|}
name|signals
operator|:
name|void
name|pointValueChanged
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
block|;
name|void
name|sizeValueChanged
argument_list|(
specifier|const
name|QSize
operator|&
name|s
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|spinBoxChanged
argument_list|()
block|;
name|private
operator|:
name|void
name|setCoordinates
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
block|;
name|QPair
operator|<
name|int
block|,
name|int
operator|>
name|coordinates
argument_list|()
specifier|const
block|;
name|QSpinBox
operator|*
name|m_x
block|;
name|QSpinBox
operator|*
name|m_y
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// A control for editing QRect
end_comment
begin_decl_stmt
name|class
name|RectControl
range|:
name|public
name|QGroupBox
block|{
name|Q_OBJECT
name|public
operator|:
name|RectControl
argument_list|()
block|;
name|void
name|setRectValue
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
block|;
name|QRect
name|rectValue
argument_list|()
specifier|const
block|;
name|signals
operator|:
name|void
name|changed
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
block|;
name|void
name|sizeChanged
argument_list|(
specifier|const
name|QSize
operator|&
name|s
argument_list|)
block|;
name|void
name|positionChanged
argument_list|(
specifier|const
name|QPoint
operator|&
name|s
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|handleChanged
argument_list|()
block|;
name|private
operator|:
name|CoordinateControl
operator|*
name|m_point
block|;
name|CoordinateControl
operator|*
name|m_size
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Base class for controlling the position of a Window (QWindow or QWidget)
end_comment
begin_decl_stmt
name|class
name|BaseWindowControl
range|:
name|public
name|QGroupBox
block|{
name|Q_OBJECT
name|protected
operator|:
name|explicit
name|BaseWindowControl
argument_list|(
name|QObject
operator|*
name|w
argument_list|)
block|;
name|public
operator|:
name|virtual
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|virtual
name|void
name|refresh
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|posChanged
argument_list|(
specifier|const
name|QPoint
operator|&
argument_list|)
block|;
name|void
name|sizeChanged
argument_list|(
specifier|const
name|QSize
operator|&
argument_list|)
block|;
name|void
name|framePosChanged
argument_list|(
specifier|const
name|QPoint
operator|&
argument_list|)
block|;
name|void
name|windowFlagsChanged
argument_list|()
block|;
name|protected
operator|:
name|QGridLayout
operator|*
name|m_layout
block|;
name|QObject
operator|*
name|m_object
block|;
name|private
operator|:
name|virtual
name|QRect
name|objectGeometry
argument_list|(
argument|const QObject *o
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setObjectGeometry
argument_list|(
argument|QObject *o
argument_list|,
argument|const QRect&
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QPoint
name|objectFramePosition
argument_list|(
argument|const QObject *o
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setObjectFramePosition
argument_list|(
argument|QObject *o
argument_list|,
argument|const QPoint&
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|Qt
operator|::
name|WindowFlags
name|objectWindowFlags
argument_list|(
argument|const QObject *o
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setObjectWindowFlags
argument_list|(
name|QObject
operator|*
name|o
argument_list|,
name|Qt
operator|::
name|WindowFlags
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QPoint
name|objectMapToGlobal
argument_list|(
argument|const QObject *o
argument_list|,
argument|const QPoint&
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|RectControl
operator|*
name|m_geometry
block|;
name|CoordinateControl
operator|*
name|m_framePosition
block|;
name|TypeControl
operator|*
name|m_typeControl
block|;
name|HintControl
operator|*
name|m_hintControl
block|;
name|QLabel
operator|*
name|m_moveEventLabel
block|;
name|QLabel
operator|*
name|m_resizeEventLabel
block|;
name|QLabel
operator|*
name|m_mouseEventLabel
block|;
name|unsigned
name|m_moveCount
block|;
name|unsigned
name|m_resizeCount
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|ControllerWidget
range|:
name|public
name|QMainWindow
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|ControllerWidget
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|ControllerWidget
argument_list|()
block|;
name|private
operator|:
name|QScopedPointer
operator|<
name|QWidget
operator|>
name|m_testWidget
block|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
name|QScopedPointer
operator|<
name|QWindow
operator|>
name|m_testWindow
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// CONTROLLERWIDGET_H
end_comment
end_unit
