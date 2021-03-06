begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFBSCREEN_P_H
end_ifndef
begin_define
DECL|macro|QFBSCREEN_P_H
define|#
directive|define
name|QFBSCREEN_P_H
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
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTimer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSize>
end_include
begin_include
include|#
directive|include
file|"qfbcursor_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFbWindow
name|class
name|QFbWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFbCursor
name|class
name|QFbCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFbBackingStore
name|class
name|QFbBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QFbScreen
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformScreen
block|{
name|Q_OBJECT
name|public
range|:
name|QFbScreen
argument_list|()
decl_stmt|;
operator|~
name|QFbScreen
argument_list|()
expr_stmt|;
name|QRect
name|geometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mGeometry
return|;
block|}
name|int
name|depth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mDepth
return|;
block|}
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mFormat
return|;
block|}
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mPhysicalSize
return|;
block|}
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|mCursor
return|;
block|}
name|QWindow
operator|*
name|topWindow
argument_list|()
specifier|const
expr_stmt|;
name|QWindow
modifier|*
name|topLevelAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
comment|// compositor api
name|virtual
name|void
name|addWindow
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|virtual
name|void
name|removeWindow
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|virtual
name|void
name|raise
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|virtual
name|void
name|lower
parameter_list|(
name|QFbWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|virtual
name|void
name|topWindowChanged
parameter_list|(
name|QWindow
modifier|*
parameter_list|)
block|{}
name|void
name|addPendingBackingStore
parameter_list|(
name|QFbBackingStore
modifier|*
name|bs
parameter_list|)
block|{
name|mPendingBackingStores
operator|<<
name|bs
expr_stmt|;
block|}
name|void
name|scheduleUpdate
parameter_list|()
function_decl|;
name|public
name|slots
range|:
name|virtual
name|void
name|setDirty
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
decl_stmt|;
name|void
name|setPhysicalSize
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
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|protected
label|:
name|virtual
name|QRegion
name|doRedraw
parameter_list|()
function_decl|;
name|void
name|initializeCompositor
parameter_list|()
function_decl|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QFbWindow
modifier|*
name|windowForId
argument_list|(
name|WId
name|wid
argument_list|)
decl|const
decl_stmt|;
name|QList
operator|<
name|QFbWindow
operator|*
operator|>
name|mWindowStack
expr_stmt|;
name|QRegion
name|mRepaintRegion
decl_stmt|;
name|bool
name|mUpdatePending
decl_stmt|;
name|QFbCursor
modifier|*
name|mCursor
decl_stmt|;
name|QRect
name|mGeometry
decl_stmt|;
name|int
name|mDepth
decl_stmt|;
name|QImage
operator|::
name|Format
name|mFormat
expr_stmt|;
name|QSizeF
name|mPhysicalSize
decl_stmt|;
name|QImage
modifier|*
name|mScreenImage
decl_stmt|;
name|private
label|:
name|void
name|invalidateRectCache
parameter_list|()
block|{
name|mIsUpToDate
operator|=
name|false
expr_stmt|;
block|}
name|void
name|generateRects
parameter_list|()
function_decl|;
name|QPainter
modifier|*
name|mCompositePainter
decl_stmt|;
name|QVector
operator|<
name|QPair
operator|<
name|QRect
operator|,
name|int
operator|>
expr|>
name|mCachedRects
expr_stmt|;
name|QList
operator|<
name|QFbBackingStore
operator|*
operator|>
name|mPendingBackingStores
expr_stmt|;
name|friend
name|class
name|QFbWindow
decl_stmt|;
name|bool
name|mIsUpToDate
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
comment|// QFBSCREEN_P_H
end_comment
end_unit
