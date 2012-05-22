begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMDRAG_H
end_ifndef
begin_define
DECL|macro|QPLATFORMDRAG_H
define|#
directive|define
name|QPLATFORMDRAG_H
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
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPixmap>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDrag
name|class
name|QDrag
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEvent
name|class
name|QEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformDragPrivate
name|class
name|QPlatformDragPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformDropQtResponse
block|{
name|public
label|:
name|QPlatformDropQtResponse
argument_list|(
argument|bool accepted
argument_list|,
argument|Qt::DropAction acceptedAction
argument_list|)
empty_stmt|;
name|bool
name|isAccepted
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|DropAction
name|acceptedAction
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|bool
name|m_accepted
decl_stmt|;
name|Qt
operator|::
name|DropAction
name|m_accepted_action
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformDragQtResponse
range|:
name|public
name|QPlatformDropQtResponse
block|{
name|public
operator|:
name|QPlatformDragQtResponse
argument_list|(
argument|bool accepted
argument_list|,
argument|Qt::DropAction acceptedAction
argument_list|,
argument|QRect answerRect
argument_list|)
block|;
name|QRect
name|answerRect
argument_list|()
specifier|const
block|;
name|private
operator|:
name|QRect
name|m_answer_rect
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformDrag
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPlatformDrag
argument_list|)
name|public
label|:
name|QPlatformDrag
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QPlatformDrag
argument_list|()
expr_stmt|;
name|QDrag
operator|*
name|currentDrag
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QMimeData
modifier|*
name|platformDropData
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|Qt
operator|::
name|DropAction
name|drag
argument_list|(
name|QDrag
operator|*
name|m_drag
argument_list|)
operator|=
literal|0
expr_stmt|;
name|void
name|updateAction
argument_list|(
name|Qt
operator|::
name|DropAction
name|action
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|DropAction
name|defaultAction
argument_list|(
argument|Qt::DropActions possibleActions
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|)
specifier|const
expr_stmt|;
specifier|static
name|QPixmap
name|defaultPixmap
parameter_list|()
function_decl|;
name|private
label|:
name|QPlatformDragPrivate
modifier|*
name|d_ptr
decl_stmt|;
name|Q_DISABLE_COPY
argument_list|(
argument|QPlatformDrag
argument_list|)
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
end_unit
