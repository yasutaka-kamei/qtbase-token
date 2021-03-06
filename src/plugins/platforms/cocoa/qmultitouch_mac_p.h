begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
begin_ifndef
ifndef|#
directive|ifndef
name|QMULTITOUCH_MAC_P_H
end_ifndef
begin_define
DECL|macro|QMULTITOUCH_MAC_P_H
define|#
directive|define
name|QMULTITOUCH_MAC_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_empty
empty|#import<AppKit/AppKit.h>
end_empty
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QCocoaTouch
block|{
name|public
label|:
specifier|static
name|QList
operator|<
name|QWindowSystemInterface
operator|::
name|TouchPoint
operator|>
name|getCurrentTouchPointList
argument_list|(
argument|NSEvent *event
argument_list|,
argument|bool acceptSingleTouch
argument_list|)
expr_stmt|;
specifier|static
name|void
name|setMouseInDraggingState
parameter_list|(
name|bool
name|inDraggingState
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
name|QHash
operator|<
name|qint64
operator|,
name|QCocoaTouch
operator|*
operator|>
name|_currentTouches
expr_stmt|;
specifier|static
name|QPointF
name|_screenReferencePos
decl_stmt|;
specifier|static
name|QPointF
name|_trackpadReferencePos
decl_stmt|;
specifier|static
name|int
name|_idAssignmentCount
decl_stmt|;
specifier|static
name|int
name|_touchCount
decl_stmt|;
specifier|static
name|bool
name|_updateInternalStateOnly
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|TouchPoint
name|_touchPoint
expr_stmt|;
name|qint64
name|_identity
decl_stmt|;
name|QCocoaTouch
argument_list|(
name|NSTouch
operator|*
name|nstouch
argument_list|)
expr_stmt|;
operator|~
name|QCocoaTouch
argument_list|()
expr_stmt|;
name|void
name|updateTouchData
parameter_list|(
name|NSTouch
modifier|*
name|nstouch
parameter_list|,
name|NSTouchPhase
name|phase
parameter_list|)
function_decl|;
specifier|static
name|QCocoaTouch
modifier|*
name|findQCocoaTouch
parameter_list|(
name|NSTouch
modifier|*
name|nstouch
parameter_list|)
function_decl|;
specifier|static
name|Qt
operator|::
name|TouchPointState
name|toTouchPointState
argument_list|(
argument|NSTouchPhase nsState
argument_list|)
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
begin_comment
comment|// QMULTITOUCH_MAC_P_H
end_comment
end_unit
