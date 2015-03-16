begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfbcursor_p.h"
end_include
begin_include
include|#
directive|include
file|"qfbscreen_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|hasMouse
name|bool
name|QFbCursorDeviceListener
operator|::
name|hasMouse
parameter_list|()
specifier|const
block|{
return|return
name|QGuiApplicationPrivate
operator|::
name|inputDeviceManager
argument_list|()
operator|->
name|deviceCount
argument_list|(
name|QInputDeviceManager
operator|::
name|DeviceTypePointer
argument_list|)
operator|>
literal|0
return|;
block|}
end_function
begin_function
DECL|function|onDeviceListChanged
name|void
name|QFbCursorDeviceListener
operator|::
name|onDeviceListChanged
parameter_list|(
name|QInputDeviceManager
operator|::
name|DeviceType
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|==
name|QInputDeviceManager
operator|::
name|DeviceTypePointer
condition|)
name|m_cursor
operator|->
name|updateMouseStatus
argument_list|()
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QFbCursor
name|QFbCursor
operator|::
name|QFbCursor
parameter_list|(
name|QFbScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|mVisible
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|mScreen
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|mDirty
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mOnScreen
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|mGraphic
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|mDeviceListener
argument_list|(
literal|0
argument_list|)
block|{
name|QByteArray
name|hideCursorVal
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_FB_HIDECURSOR"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|hideCursorVal
operator|.
name|isEmpty
argument_list|()
condition|)
name|mVisible
operator|=
name|hideCursorVal
operator|.
name|toInt
argument_list|()
operator|==
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|mVisible
condition|)
return|return;
name|mGraphic
operator|=
operator|new
name|QPlatformCursorImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setCursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
expr_stmt|;
name|mDeviceListener
operator|=
operator|new
name|QFbCursorDeviceListener
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|inputDeviceManager
argument_list|()
argument_list|,
operator|&
name|QInputDeviceManager
operator|::
name|deviceListChanged
argument_list|,
name|mDeviceListener
argument_list|,
operator|&
name|QFbCursorDeviceListener
operator|::
name|onDeviceListChanged
argument_list|)
expr_stmt|;
name|updateMouseStatus
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QFbCursor
name|QFbCursor
operator|::
name|~
name|QFbCursor
parameter_list|()
block|{
operator|delete
name|mDeviceListener
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|getCurrentRect
name|QRect
name|QFbCursor
operator|::
name|getCurrentRect
parameter_list|()
block|{
name|QRect
name|rect
init|=
name|mGraphic
operator|->
name|image
argument_list|()
operator|->
name|rect
argument_list|()
operator|.
name|translated
argument_list|(
operator|-
name|mGraphic
operator|->
name|hotspot
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
operator|-
name|mGraphic
operator|->
name|hotspot
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
name|rect
operator|.
name|translate
argument_list|(
name|m_pos
argument_list|)
expr_stmt|;
name|QPoint
name|mScreenOffset
init|=
name|mScreen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|rect
operator|.
name|translate
argument_list|(
operator|-
name|mScreenOffset
argument_list|)
expr_stmt|;
comment|// global to local translation
return|return
name|rect
return|;
block|}
end_function
begin_function
DECL|function|pos
name|QPoint
name|QFbCursor
operator|::
name|pos
parameter_list|()
specifier|const
block|{
return|return
name|m_pos
return|;
block|}
end_function
begin_function
DECL|function|setPos
name|void
name|QFbCursor
operator|::
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|QGuiApplicationPrivate
operator|::
name|inputDeviceManager
argument_list|()
operator|->
name|setCursorPos
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|m_pos
operator|=
name|pos
expr_stmt|;
name|mCurrentRect
operator|=
name|getCurrentRect
argument_list|()
expr_stmt|;
if|if
condition|(
name|mOnScreen
operator|||
name|mScreen
operator|->
name|geometry
argument_list|()
operator|.
name|intersects
argument_list|(
name|mCurrentRect
operator|.
name|translated
argument_list|(
name|mScreen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|)
argument_list|)
condition|)
name|setDirty
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pointerEvent
name|void
name|QFbCursor
operator|::
name|pointerEvent
parameter_list|(
specifier|const
name|QMouseEvent
modifier|&
name|e
parameter_list|)
block|{
if|if
condition|(
name|e
operator|.
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|MouseMove
condition|)
return|return;
name|m_pos
operator|=
name|e
operator|.
name|screenPos
argument_list|()
operator|.
name|toPoint
argument_list|()
expr_stmt|;
name|mCurrentRect
operator|=
name|getCurrentRect
argument_list|()
expr_stmt|;
if|if
condition|(
name|mOnScreen
operator|||
name|mScreen
operator|->
name|geometry
argument_list|()
operator|.
name|intersects
argument_list|(
name|mCurrentRect
operator|.
name|translated
argument_list|(
name|mScreen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|)
argument_list|)
condition|)
name|setDirty
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|drawCursor
name|QRect
name|QFbCursor
operator|::
name|drawCursor
parameter_list|(
name|QPainter
modifier|&
name|painter
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mVisible
condition|)
return|return
name|QRect
argument_list|()
return|;
name|mDirty
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|mCurrentRect
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|QRect
argument_list|()
return|;
comment|// We need this because the cursor might be mDirty due to moving off mScreen
name|QPoint
name|mScreenOffset
init|=
name|mScreen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
comment|// global to local translation
if|if
condition|(
operator|!
name|mCurrentRect
operator|.
name|translated
argument_list|(
name|mScreenOffset
argument_list|)
operator|.
name|intersects
argument_list|(
name|mScreen
operator|->
name|geometry
argument_list|()
argument_list|)
condition|)
return|return
name|QRect
argument_list|()
return|;
name|mPrevRect
operator|=
name|mCurrentRect
expr_stmt|;
name|painter
operator|.
name|drawImage
argument_list|(
name|mPrevRect
argument_list|,
operator|*
name|mGraphic
operator|->
name|image
argument_list|()
argument_list|)
expr_stmt|;
name|mOnScreen
operator|=
literal|true
expr_stmt|;
return|return
name|mPrevRect
return|;
block|}
end_function
begin_function
DECL|function|dirtyRect
name|QRect
name|QFbCursor
operator|::
name|dirtyRect
parameter_list|()
block|{
if|if
condition|(
name|mOnScreen
condition|)
block|{
name|mOnScreen
operator|=
literal|false
expr_stmt|;
return|return
name|mPrevRect
return|;
block|}
return|return
name|QRect
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setCursor
name|void
name|QFbCursor
operator|::
name|setCursor
parameter_list|(
name|Qt
operator|::
name|CursorShape
name|shape
parameter_list|)
block|{
name|mGraphic
operator|->
name|set
argument_list|(
name|shape
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCursor
name|void
name|QFbCursor
operator|::
name|setCursor
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|int
name|hotx
parameter_list|,
name|int
name|hoty
parameter_list|)
block|{
name|mGraphic
operator|->
name|set
argument_list|(
name|image
argument_list|,
name|hotx
argument_list|,
name|hoty
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCursor
name|void
name|QFbCursor
operator|::
name|setCursor
parameter_list|(
specifier|const
name|uchar
modifier|*
name|data
parameter_list|,
specifier|const
name|uchar
modifier|*
name|mask
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|hotX
parameter_list|,
name|int
name|hotY
parameter_list|)
block|{
name|mGraphic
operator|->
name|set
argument_list|(
name|data
argument_list|,
name|mask
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|hotX
argument_list|,
name|hotY
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
end_ifndef
begin_function
DECL|function|changeCursor
name|void
name|QFbCursor
operator|::
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|widgetCursor
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
specifier|const
name|Qt
operator|::
name|CursorShape
name|shape
init|=
name|widgetCursor
condition|?
name|widgetCursor
operator|->
name|shape
argument_list|()
else|:
name|Qt
operator|::
name|ArrowCursor
decl_stmt|;
if|if
condition|(
name|shape
operator|==
name|Qt
operator|::
name|BitmapCursor
condition|)
block|{
comment|// application supplied cursor
name|QPoint
name|spot
init|=
name|widgetCursor
operator|->
name|hotSpot
argument_list|()
decl_stmt|;
name|setCursor
argument_list|(
name|widgetCursor
operator|->
name|pixmap
argument_list|()
operator|.
name|toImage
argument_list|()
argument_list|,
name|spot
operator|.
name|x
argument_list|()
argument_list|,
name|spot
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// system cursor
name|setCursor
argument_list|(
name|shape
argument_list|)
expr_stmt|;
block|}
name|mCurrentRect
operator|=
name|getCurrentRect
argument_list|()
expr_stmt|;
name|QPoint
name|mScreenOffset
init|=
name|mScreen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
comment|// global to local translation
if|if
condition|(
name|mOnScreen
operator|||
name|mScreen
operator|->
name|geometry
argument_list|()
operator|.
name|intersects
argument_list|(
name|mCurrentRect
operator|.
name|translated
argument_list|(
name|mScreenOffset
argument_list|)
argument_list|)
condition|)
name|setDirty
argument_list|()
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|setDirty
name|void
name|QFbCursor
operator|::
name|setDirty
parameter_list|()
block|{
if|if
condition|(
operator|!
name|mVisible
condition|)
return|return;
if|if
condition|(
operator|!
name|mDirty
condition|)
block|{
name|mDirty
operator|=
literal|true
expr_stmt|;
name|mScreen
operator|->
name|scheduleUpdate
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|updateMouseStatus
name|void
name|QFbCursor
operator|::
name|updateMouseStatus
parameter_list|()
block|{
name|mVisible
operator|=
name|mDeviceListener
operator|->
name|hasMouse
argument_list|()
expr_stmt|;
name|mScreen
operator|->
name|setDirty
argument_list|(
name|mVisible
condition|?
name|getCurrentRect
argument_list|()
else|:
name|lastPainted
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
