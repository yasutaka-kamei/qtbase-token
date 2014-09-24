begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLPLATFORMCURSOR_H
end_ifndef
begin_define
DECL|macro|QEGLPLATFORMCURSOR_H
define|#
directive|define
name|QEGLPLATFORMCURSOR_H
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
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLShaderProgram
name|class
name|QOpenGLShaderProgram
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDeviceDiscovery
name|class
name|QDeviceDiscovery
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEGLPlatformCursor
name|class
name|QEGLPlatformCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEGLPlatformCursorDeviceListener
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QEGLPlatformCursorDeviceListener
argument_list|(
name|QDeviceDiscovery
operator|*
name|dd
argument_list|,
name|QEGLPlatformCursor
operator|*
name|cursor
argument_list|)
block|;
name|bool
name|hasMouse
argument_list|()
specifier|const
block|;
name|private
name|slots
operator|:
name|void
name|onDeviceAdded
argument_list|()
block|;
name|void
name|onDeviceRemoved
argument_list|()
block|;
name|private
operator|:
name|QEGLPlatformCursor
operator|*
name|m_cursor
block|;
name|int
name|m_mouseCount
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QEGLPlatformCursorUpdater
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|QEGLPlatformCursorUpdater
argument_list|(
name|QPlatformScreen
operator|*
name|screen
argument_list|)
operator|:
name|m_screen
argument_list|(
name|screen
argument_list|)
block|,
name|m_active
argument_list|(
argument|false
argument_list|)
block|{ }
name|void
name|scheduleUpdate
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
specifier|const
name|QRegion
operator|&
name|rgn
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|update
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|,
specifier|const
name|QRegion
operator|&
name|rgn
argument_list|)
block|;
name|private
operator|:
name|QPlatformScreen
operator|*
name|m_screen
block|;
name|bool
name|m_active
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformCursor
name|class
name|QEGLPlatformCursor
range|:
name|public
name|QPlatformCursor
decl_stmt|,
name|protected
name|QOpenGLFunctions
block|{
name|public
label|:
name|QEGLPlatformCursor
argument_list|(
name|QPlatformScreen
operator|*
name|screen
argument_list|)
expr_stmt|;
operator|~
name|QEGLPlatformCursor
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|void
name|changeCursor
argument_list|(
name|QCursor
operator|*
name|cursor
argument_list|,
name|QWindow
operator|*
name|widget
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
endif|#
directive|endif
name|void
name|pointerEvent
argument_list|(
specifier|const
name|QMouseEvent
operator|&
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPoint
name|pos
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|setPos
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QRect
name|cursorRect
argument_list|()
specifier|const
expr_stmt|;
name|void
name|paintOnScreen
parameter_list|()
function_decl|;
name|void
name|resetResources
parameter_list|()
function_decl|;
name|void
name|setMouseDeviceDiscovery
parameter_list|(
name|QDeviceDiscovery
modifier|*
name|dd
parameter_list|)
function_decl|;
name|void
name|updateMouseStatus
parameter_list|()
function_decl|;
name|private
label|:
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|bool
name|setCurrentCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|draw
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
function_decl|;
name|void
name|update
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
function_decl|;
name|void
name|createShaderPrograms
parameter_list|()
function_decl|;
name|void
name|createCursorTexture
parameter_list|(
name|uint
modifier|*
name|texture
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
function_decl|;
name|void
name|initCursorAtlas
parameter_list|()
function_decl|;
comment|// current cursor information
struct|struct
name|Cursor
block|{
name|Cursor
argument_list|()
operator|:
name|texture
argument_list|(
literal|0
argument_list|)
operator|,
name|shape
argument_list|(
name|Qt
operator|::
name|BlankCursor
argument_list|)
operator|,
name|customCursorTexture
argument_list|(
literal|0
argument_list|)
operator|,
name|customCursorPending
argument_list|(
argument|false
argument_list|)
block|{ }
name|uint
name|texture
expr_stmt|;
comment|// a texture from 'image' or the atlas
name|Qt
operator|::
name|CursorShape
name|shape
expr_stmt|;
name|QRectF
name|textureRect
decl_stmt|;
comment|// normalized rect inside texture
name|QSize
name|size
decl_stmt|;
comment|// size of the cursor
name|QPoint
name|hotSpot
decl_stmt|;
name|QImage
name|customCursorImage
decl_stmt|;
name|QPoint
name|pos
decl_stmt|;
comment|// current cursor position
name|uint
name|customCursorTexture
decl_stmt|;
name|bool
name|customCursorPending
decl_stmt|;
block|}
name|m_cursor
struct|;
comment|// cursor atlas information
struct|struct
name|CursorAtlas
block|{
name|CursorAtlas
argument_list|()
operator|:
name|cursorsPerRow
argument_list|(
literal|0
argument_list|)
operator|,
name|texture
argument_list|(
literal|0
argument_list|)
operator|,
name|cursorWidth
argument_list|(
literal|0
argument_list|)
operator|,
name|cursorHeight
argument_list|(
literal|0
argument_list|)
block|{ }
name|int
name|cursorsPerRow
expr_stmt|;
name|uint
name|texture
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|// width and height of the atlas
name|int
name|cursorWidth
decl_stmt|,
name|cursorHeight
decl_stmt|;
comment|// width and height of cursors inside the atlas
name|QList
operator|<
name|QPoint
operator|>
name|hotSpots
expr_stmt|;
name|QImage
name|image
decl_stmt|;
comment|// valid until it's uploaded
block|}
name|m_cursorAtlas
struct|;
name|bool
name|m_visible
decl_stmt|;
name|QPlatformScreen
modifier|*
name|m_screen
decl_stmt|;
name|QOpenGLShaderProgram
modifier|*
name|m_program
decl_stmt|;
name|int
name|m_vertexCoordEntry
decl_stmt|;
name|int
name|m_textureCoordEntry
decl_stmt|;
name|int
name|m_textureEntry
decl_stmt|;
name|QEGLPlatformCursorDeviceListener
modifier|*
name|m_deviceListener
decl_stmt|;
name|QEGLPlatformCursorUpdater
name|m_updater
decl_stmt|;
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
begin_comment
comment|// QEGLPLATFORMCURSOR_H
end_comment
end_unit
