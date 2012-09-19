begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEVENTTRANSITION_H
end_ifndef
begin_define
DECL|macro|QEVENTTRANSITION_H
define|#
directive|define
name|QEVENTTRANSITION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstracttransition.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreevent.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
DECL|variable|QEventTransitionPrivate
name|class
name|QEventTransitionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QEventTransition
range|:
name|public
name|QAbstractTransition
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QObject* eventSource READ eventSource WRITE setEventSource
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QEvent::Type eventType READ eventType WRITE setEventType
argument_list|)
name|public
operator|:
name|QEventTransition
argument_list|(
name|QState
operator|*
name|sourceState
operator|=
literal|0
argument_list|)
block|;
name|QEventTransition
argument_list|(
argument|QObject *object
argument_list|,
argument|QEvent::Type type
argument_list|,
argument|QState *sourceState =
literal|0
argument_list|)
block|;
operator|~
name|QEventTransition
argument_list|()
block|;
name|QObject
operator|*
name|eventSource
argument_list|()
specifier|const
block|;
name|void
name|setEventSource
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|QEvent
operator|::
name|Type
name|eventType
argument_list|()
specifier|const
block|;
name|void
name|setEventType
argument_list|(
argument|QEvent::Type type
argument_list|)
block|;
name|protected
operator|:
name|bool
name|eventTest
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|onTransition
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|protected
operator|:
name|QEventTransition
argument_list|(
name|QEventTransitionPrivate
operator|&
name|dd
argument_list|,
name|QState
operator|*
name|parent
argument_list|)
block|;
name|QEventTransition
argument_list|(
argument|QEventTransitionPrivate&dd
argument_list|,
argument|QObject *object
argument_list|,
argument|QEvent::Type type
argument_list|,
argument|QState *parent
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QEventTransition
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QEventTransition
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_STATEMACHINE
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
