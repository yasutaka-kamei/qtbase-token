begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 Pier Luigi Fiorini<pierluigi.fiorini@gmail.com> ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfskmscursor.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsscreen.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsdevice.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonDocument>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<xf86drm.h>
end_include
begin_include
include|#
directive|include
file|<xf86drmMode.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|DRM_CAP_CURSOR_WIDTH
end_ifndef
begin_define
DECL|macro|DRM_CAP_CURSOR_WIDTH
define|#
directive|define
name|DRM_CAP_CURSOR_WIDTH
value|0x8
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|DRM_CAP_CURSOR_HEIGHT
end_ifndef
begin_define
DECL|macro|DRM_CAP_CURSOR_HEIGHT
define|#
directive|define
name|DRM_CAP_CURSOR_HEIGHT
value|0x9
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
DECL|function|QEglFSKmsCursor
name|QEglFSKmsCursor
operator|::
name|QEglFSKmsCursor
argument_list|(
name|QEglFSKmsScreen
operator|*
name|screen
argument_list|)
range|:
name|m_screen
argument_list|(
name|screen
argument_list|)
decl_stmt|,
name|m_cursorSize
argument_list|(
literal|64
argument_list|,
literal|64
argument_list|)
comment|// 64x64 is the old standard size, we now try to query the real size below
decl_stmt|,
name|m_bo
argument_list|(
name|Q_NULLPTR
argument_list|)
decl_stmt|,
name|m_cursorImage
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
decl_stmt|,
name|m_visible
argument_list|(
literal|true
argument_list|)
argument_list|{
name|uint64_t
name|width
argument_list|,
name|height
argument_list|;     if
operator|(
operator|(
name|drmGetCap
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|DRM_CAP_CURSOR_WIDTH
argument_list|,
operator|&
name|width
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|drmGetCap
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|DRM_CAP_CURSOR_HEIGHT
argument_list|,
operator|&
name|height
argument_list|)
operator|==
literal|0
operator|)
operator|)
block|{
name|m_cursorSize
operator|.
name|setWidth
argument_list|(
name|width
argument_list|)
block|;
name|m_cursorSize
operator|.
name|setHeight
argument_list|(
name|height
argument_list|)
block|;     }
name|m_bo
operator|=
name|gbm_bo_create
argument_list|(
name|m_screen
operator|->
name|device
argument_list|()
operator|->
name|device
argument_list|()
argument_list|,
name|m_cursorSize
operator|.
name|width
argument_list|()
argument_list|,
name|m_cursorSize
operator|.
name|height
argument_list|()
argument_list|,
name|GBM_FORMAT_ARGB8888
argument_list|,
name|GBM_BO_USE_CURSOR_64X64
operator||
name|GBM_BO_USE_WRITE
argument_list|)
argument_list|;     if
operator|(
operator|!
name|m_bo
operator|)
block|{
name|qWarning
argument_list|(
literal|"Could not create buffer for cursor!"
argument_list|)
block|;     }
else|else
block|{
name|initCursorAtlas
argument_list|()
block|;     }
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|QCursor
name|cursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
expr_stmt|;
name|changeCursor
argument_list|(
operator|&
name|cursor
argument_list|,
literal|0
argument_list|)
argument_list|;
endif|#
directive|endif
name|setPos
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|; }
DECL|function|~QEglFSKmsCursor
name|QEglFSKmsCursor
operator|::
name|~
name|QEglFSKmsCursor
argument_list|()
argument_list|{
name|Q_FOREACH
argument_list|(
argument|QPlatformScreen *screen
argument_list|,
argument|m_screen->virtualSiblings()
argument_list|)
block|{
name|QEglFSKmsScreen
operator|*
name|kmsScreen
operator|=
cast|static_cast
argument_list|<
name|QEglFSKmsScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|)
block|;
name|drmModeSetCursor
argument_list|(
name|kmsScreen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|kmsScreen
operator|->
name|output
argument_list|()
operator|.
name|crtc_id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|;
name|drmModeMoveCursor
argument_list|(
name|kmsScreen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|kmsScreen
operator|->
name|output
argument_list|()
operator|.
name|crtc_id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|;     }
name|gbm_bo_destroy
argument_list|(
name|m_bo
argument_list|)
argument_list|;
name|m_bo
operator|=
name|Q_NULLPTR
argument_list|; }
DECL|function|pointerEvent
name|void
name|QEglFSKmsCursor
operator|::
name|pointerEvent
argument_list|(
specifier|const
name|QMouseEvent
operator|&
name|event
argument_list|)
argument_list|{
name|setPos
argument_list|(
name|event
operator|.
name|screenPos
argument_list|()
operator|.
name|toPoint
argument_list|()
argument_list|)
argument_list|; }
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
DECL|function|changeCursor
name|void
name|QEglFSKmsCursor
operator|::
name|changeCursor
argument_list|(
name|QCursor
operator|*
name|windowCursor
argument_list|,
name|QWindow
operator|*
name|window
argument_list|)
argument_list|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
argument_list|;      if
operator|(
operator|!
name|m_visible
operator|)
return|return;
end_decl_stmt
begin_decl_stmt
specifier|const
name|Qt
operator|::
name|CursorShape
name|newShape
init|=
name|windowCursor
condition|?
name|windowCursor
operator|->
name|shape
argument_list|()
else|:
name|Qt
operator|::
name|ArrowCursor
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|newShape
operator|==
name|Qt
operator|::
name|BitmapCursor
condition|)
block|{
name|m_cursorImage
operator|.
name|set
argument_list|(
name|windowCursor
operator|->
name|pixmap
argument_list|()
operator|.
name|toImage
argument_list|()
argument_list|,
name|windowCursor
operator|->
name|hotSpot
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|windowCursor
operator|->
name|hotSpot
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Standard cursor, look up in atlas
specifier|const
name|int
name|width
init|=
name|m_cursorAtlas
operator|.
name|cursorWidth
decl_stmt|;
specifier|const
name|int
name|height
init|=
name|m_cursorAtlas
operator|.
name|cursorHeight
decl_stmt|;
specifier|const
name|qreal
name|ws
init|=
operator|(
name|qreal
operator|)
name|m_cursorAtlas
operator|.
name|cursorWidth
operator|/
name|m_cursorAtlas
operator|.
name|width
decl_stmt|;
specifier|const
name|qreal
name|hs
init|=
operator|(
name|qreal
operator|)
name|m_cursorAtlas
operator|.
name|cursorHeight
operator|/
name|m_cursorAtlas
operator|.
name|height
decl_stmt|;
name|QRect
name|textureRect
argument_list|(
name|ws
operator|*
operator|(
name|newShape
operator|%
name|m_cursorAtlas
operator|.
name|cursorsPerRow
operator|)
operator|*
name|m_cursorAtlas
operator|.
name|width
argument_list|,
name|hs
operator|*
operator|(
name|newShape
operator|/
name|m_cursorAtlas
operator|.
name|cursorsPerRow
operator|)
operator|*
name|m_cursorAtlas
operator|.
name|height
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
name|QPoint
name|hotSpot
init|=
name|m_cursorAtlas
operator|.
name|hotSpots
index|[
name|newShape
index|]
decl_stmt|;
name|m_cursorImage
operator|.
name|set
argument_list|(
name|m_cursorAtlas
operator|.
name|image
operator|.
name|copy
argument_list|(
name|textureRect
argument_list|)
argument_list|,
name|hotSpot
operator|.
name|x
argument_list|()
argument_list|,
name|hotSpot
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_if
begin_if
if|if
condition|(
name|m_cursorImage
operator|.
name|image
argument_list|()
operator|->
name|width
argument_list|()
operator|>
name|m_cursorSize
operator|.
name|width
argument_list|()
operator|||
name|m_cursorImage
operator|.
name|image
argument_list|()
operator|->
name|height
argument_list|()
operator|>
name|m_cursorSize
operator|.
name|height
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"Cursor larger than %dx%d, cursor will be clipped."
argument_list|,
name|m_cursorSize
operator|.
name|width
argument_list|()
argument_list|,
name|m_cursorSize
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
end_if
begin_function_decl
name|QImage
name|cursorImage
parameter_list|(
name|m_cursorSize
parameter_list|,
name|QImage
operator|::
name|Format_ARGB32
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|cursorImage
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QPainter
name|painter
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|cursorImage
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|drawImage
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
operator|*
name|m_cursorImage
operator|.
name|image
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|gbm_bo_write
argument_list|(
name|m_bo
argument_list|,
name|cursorImage
operator|.
name|constBits
argument_list|()
argument_list|,
name|cursorImage
operator|.
name|byteCount
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|uint32_t
name|handle
init|=
name|gbm_bo_get_handle
argument_list|(
name|m_bo
argument_list|)
operator|.
name|u32
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_FOREACH
argument_list|(
argument|QPlatformScreen *screen
argument_list|,
argument|m_screen->virtualSiblings()
argument_list|)
end_macro
begin_block
block|{
name|QEglFSKmsScreen
modifier|*
name|kmsScreen
init|=
cast|static_cast
argument_list|<
name|QEglFSKmsScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|)
decl_stmt|;
name|int
name|status
init|=
name|drmModeSetCursor
argument_list|(
name|kmsScreen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|kmsScreen
operator|->
name|output
argument_list|()
operator|.
name|crtc_id
argument_list|,
name|handle
argument_list|,
name|m_cursorSize
operator|.
name|width
argument_list|()
argument_list|,
name|m_cursorSize
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
name|qWarning
argument_list|(
literal|"Could not set cursor on screen %s: %d"
argument_list|,
name|kmsScreen
operator|->
name|name
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|status
argument_list|)
expr_stmt|;
block|}
end_block
begin_endif
unit|}
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CURSOR
end_comment
begin_macro
unit|QPoint
DECL|function|pos
name|QEglFSKmsCursor
end_macro
begin_expr_stmt
DECL|function|pos
operator|::
name|pos
operator|(
operator|)
specifier|const
block|{
return|return
name|m_pos
return|;
block|}
end_expr_stmt
begin_function
DECL|function|setPos
name|void
name|QEglFSKmsCursor
operator|::
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|Q_FOREACH
argument_list|(
argument|QPlatformScreen *screen
argument_list|,
argument|m_screen->virtualSiblings()
argument_list|)
block|{
name|QEglFSKmsScreen
modifier|*
name|kmsScreen
init|=
cast|static_cast
argument_list|<
name|QEglFSKmsScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|)
decl_stmt|;
name|QPoint
name|origin
init|=
name|kmsScreen
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
decl_stmt|;
name|QPoint
name|localPos
init|=
name|pos
operator|-
name|origin
decl_stmt|;
name|QPoint
name|adjustedPos
init|=
name|localPos
operator|-
name|m_cursorImage
operator|.
name|hotspot
argument_list|()
decl_stmt|;
name|int
name|ret
init|=
name|drmModeMoveCursor
argument_list|(
name|kmsScreen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|kmsScreen
operator|->
name|output
argument_list|()
operator|.
name|crtc_id
argument_list|,
name|adjustedPos
operator|.
name|x
argument_list|()
argument_list|,
name|adjustedPos
operator|.
name|y
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
literal|0
condition|)
name|m_pos
operator|=
name|pos
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"Failed to move cursor on screen %s: %d"
argument_list|,
name|kmsScreen
operator|->
name|name
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|ret
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|initCursorAtlas
name|void
name|QEglFSKmsCursor
operator|::
name|initCursorAtlas
parameter_list|()
block|{
specifier|static
name|QByteArray
name|json
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_CURSOR"
argument_list|)
decl_stmt|;
if|if
condition|(
name|json
operator|.
name|isEmpty
argument_list|()
condition|)
name|json
operator|=
literal|":/cursor.json"
expr_stmt|;
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|)
operator|<<
literal|"Initializing cursor atlas from"
operator|<<
name|json
expr_stmt|;
name|QFile
name|file
argument_list|(
name|QString
operator|::
name|fromUtf8
argument_list|(
name|json
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|Q_FOREACH
argument_list|(
argument|QPlatformScreen *screen
argument_list|,
argument|m_screen->virtualSiblings()
argument_list|)
block|{
name|QEglFSKmsScreen
modifier|*
name|kmsScreen
init|=
cast|static_cast
argument_list|<
name|QEglFSKmsScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|)
decl_stmt|;
name|drmModeSetCursor
argument_list|(
name|kmsScreen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|kmsScreen
operator|->
name|output
argument_list|()
operator|.
name|crtc_id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|drmModeMoveCursor
argument_list|(
name|kmsScreen
operator|->
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|kmsScreen
operator|->
name|output
argument_list|()
operator|.
name|crtc_id
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
name|m_visible
operator|=
literal|false
expr_stmt|;
return|return;
block|}
name|QJsonDocument
name|doc
init|=
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|file
operator|.
name|readAll
argument_list|()
argument_list|)
decl_stmt|;
name|QJsonObject
name|object
init|=
name|doc
operator|.
name|object
argument_list|()
decl_stmt|;
name|QString
name|atlas
init|=
name|object
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"image"
argument_list|)
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|atlas
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|int
name|cursorsPerRow
init|=
name|object
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"cursorsPerRow"
argument_list|)
argument_list|)
operator|.
name|toDouble
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|cursorsPerRow
argument_list|)
expr_stmt|;
name|m_cursorAtlas
operator|.
name|cursorsPerRow
operator|=
name|cursorsPerRow
expr_stmt|;
specifier|const
name|QJsonArray
name|hotSpots
init|=
name|object
operator|.
name|value
argument_list|(
name|QLatin1String
argument_list|(
literal|"hotSpots"
argument_list|)
argument_list|)
operator|.
name|toArray
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|hotSpots
operator|.
name|count
argument_list|()
operator|==
name|Qt
operator|::
name|LastCursor
operator|+
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|hotSpots
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QPoint
name|hotSpot
argument_list|(
name|hotSpots
index|[
name|i
index|]
operator|.
name|toArray
argument_list|()
index|[
literal|0
index|]
operator|.
name|toDouble
argument_list|()
argument_list|,
name|hotSpots
index|[
name|i
index|]
operator|.
name|toArray
argument_list|()
index|[
literal|1
index|]
operator|.
name|toDouble
argument_list|()
argument_list|)
decl_stmt|;
name|m_cursorAtlas
operator|.
name|hotSpots
operator|<<
name|hotSpot
expr_stmt|;
block|}
name|QImage
name|image
init|=
name|QImage
argument_list|(
name|atlas
argument_list|)
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
decl_stmt|;
name|m_cursorAtlas
operator|.
name|cursorWidth
operator|=
name|image
operator|.
name|width
argument_list|()
operator|/
name|m_cursorAtlas
operator|.
name|cursorsPerRow
expr_stmt|;
name|m_cursorAtlas
operator|.
name|cursorHeight
operator|=
name|image
operator|.
name|height
argument_list|()
operator|/
operator|(
operator|(
name|Qt
operator|::
name|LastCursor
operator|+
name|cursorsPerRow
operator|)
operator|/
name|cursorsPerRow
operator|)
expr_stmt|;
name|m_cursorAtlas
operator|.
name|width
operator|=
name|image
operator|.
name|width
argument_list|()
expr_stmt|;
name|m_cursorAtlas
operator|.
name|height
operator|=
name|image
operator|.
name|height
argument_list|()
expr_stmt|;
name|m_cursorAtlas
operator|.
name|image
operator|=
name|image
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
