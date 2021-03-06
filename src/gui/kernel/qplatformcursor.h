begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMCURSOR_H
end_ifndef
begin_define
DECL|macro|QPLATFORMCURSOR_H
define|#
directive|define
name|QPLATFORMCURSOR_H
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
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<QtGui/QMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QtCore/QWeakPointer>
end_include
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QCursor>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// Cursor graphics management
name|class
name|Q_GUI_EXPORT
name|QPlatformCursorImage
block|{
name|public
label|:
name|QPlatformCursorImage
argument_list|(
argument|const uchar *data
argument_list|,
argument|const uchar *mask
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|int hotX
argument_list|,
argument|int hotY
argument_list|)
block|{
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
name|QImage
modifier|*
name|image
parameter_list|()
block|{
return|return
operator|&
name|cursorImage
return|;
block|}
name|QPoint
name|hotspot
argument_list|()
specifier|const
block|{
return|return
name|hot
return|;
block|}
name|void
name|set
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
function_decl|;
name|void
name|set
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
name|int
name|hx
parameter_list|,
name|int
name|hy
parameter_list|)
function_decl|;
name|void
name|set
argument_list|(
name|Qt
operator|::
name|CursorShape
argument_list|)
decl_stmt|;
name|private
label|:
specifier|static
name|void
name|createSystemCursor
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
name|QImage
name|cursorImage
decl_stmt|;
name|QPoint
name|hot
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QPlatformCursor
name|class
name|QPlatformCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformCursorPrivate
block|{
name|public
label|:
specifier|static
name|QList
operator|<
name|QPlatformCursor
operator|*
operator|>
name|getInstances
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformCursor
range|:
name|public
name|QObject
block|{
name|public
operator|:
name|QPlatformCursor
argument_list|()
block|;
comment|// input methods
name|virtual
name|void
name|pointerEvent
argument_list|(
argument|const QMouseEvent& event
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
block|; }
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|virtual
name|void
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
operator|=
literal|0
block|;
endif|#
directive|endif
name|virtual
name|QPoint
name|pos
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setPos
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPlatformCursor
argument_list|)
name|friend
name|void
name|qt_qpa_set_cursor
argument_list|(
argument|QWidget * w
argument_list|,
argument|bool force
argument_list|)
block|;
name|friend
name|class
name|QApplicationPrivate
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
comment|// QPLATFORMCURSOR_H
end_comment
end_unit
