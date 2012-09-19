begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTATEMACHINE_H
end_ifndef
begin_define
DECL|macro|QSTATEMACHINE_H
define|#
directive|define
name|QSTATEMACHINE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstate.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreevent.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
DECL|variable|QStateMachinePrivate
name|class
name|QStateMachinePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractAnimation
name|class
name|QAbstractAnimation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QStateMachine
range|:
name|public
name|QState
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QString errorString READ errorString
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QState::RestorePolicy globalRestorePolicy READ globalRestorePolicy WRITE setGlobalRestorePolicy
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|Q_PROPERTY
argument_list|(
argument|bool animated READ isAnimated WRITE setAnimated
argument_list|)
endif|#
directive|endif
name|public
operator|:
name|class
name|Q_CORE_EXPORT
name|SignalEvent
operator|:
name|public
name|QEvent
block|{
name|public
operator|:
name|SignalEvent
argument_list|(
argument|QObject *sender
argument_list|,
argument|int signalIndex
argument_list|,
argument|const QList<QVariant>&arguments
argument_list|)
block|;
operator|~
name|SignalEvent
argument_list|()
block|;
specifier|inline
name|QObject
operator|*
name|sender
argument_list|()
specifier|const
block|{
return|return
name|m_sender
return|;
block|}
specifier|inline
name|int
name|signalIndex
argument_list|()
specifier|const
block|{
return|return
name|m_signalIndex
return|;
block|}
specifier|inline
name|QList
operator|<
name|QVariant
operator|>
name|arguments
argument_list|()
specifier|const
block|{
return|return
name|m_arguments
return|;
block|}
name|private
operator|:
name|QObject
operator|*
name|m_sender
block|;
name|int
name|m_signalIndex
block|;
name|QList
operator|<
name|QVariant
operator|>
name|m_arguments
block|;
name|friend
name|class
name|QSignalTransitionPrivate
block|;     }
block|;
name|class
name|Q_CORE_EXPORT
name|WrappedEvent
operator|:
name|public
name|QEvent
block|{
name|public
operator|:
name|WrappedEvent
argument_list|(
name|QObject
operator|*
name|object
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
operator|~
name|WrappedEvent
argument_list|()
block|;
specifier|inline
name|QObject
operator|*
name|object
argument_list|()
specifier|const
block|{
return|return
name|m_object
return|;
block|}
specifier|inline
name|QEvent
operator|*
name|event
argument_list|()
specifier|const
block|{
return|return
name|m_event
return|;
block|}
name|private
operator|:
name|QObject
operator|*
name|m_object
block|;
name|QEvent
operator|*
name|m_event
block|;     }
block|;      enum
name|EventPriority
block|{
name|NormalPriority
block|,
name|HighPriority
block|}
block|;      enum
name|Error
block|{
name|NoError
block|,
name|NoInitialStateError
block|,
name|NoDefaultStateInHistoryStateError
block|,
name|NoCommonAncestorForTransitionError
block|}
block|;
name|explicit
name|QStateMachine
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QStateMachine
argument_list|(
argument|QState::ChildMode childMode
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
operator|~
name|QStateMachine
argument_list|()
block|;
name|void
name|addState
argument_list|(
name|QAbstractState
operator|*
name|state
argument_list|)
block|;
name|void
name|removeState
argument_list|(
name|QAbstractState
operator|*
name|state
argument_list|)
block|;
name|Error
name|error
argument_list|()
specifier|const
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
name|void
name|clearError
argument_list|()
block|;
name|bool
name|isRunning
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|bool
name|isAnimated
argument_list|()
specifier|const
block|;
name|void
name|setAnimated
argument_list|(
argument|bool enabled
argument_list|)
block|;
name|void
name|addDefaultAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|defaultAnimations
argument_list|()
specifier|const
block|;
name|void
name|removeDefaultAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
endif|#
directive|endif
comment|// QT_NO_ANIMATION
name|QState
operator|::
name|RestorePolicy
name|globalRestorePolicy
argument_list|()
specifier|const
block|;
name|void
name|setGlobalRestorePolicy
argument_list|(
argument|QState::RestorePolicy restorePolicy
argument_list|)
block|;
name|void
name|postEvent
argument_list|(
argument|QEvent *event
argument_list|,
argument|EventPriority priority = NormalPriority
argument_list|)
block|;
name|int
name|postDelayedEvent
argument_list|(
argument|QEvent *event
argument_list|,
argument|int delay
argument_list|)
block|;
name|bool
name|cancelDelayedEvent
argument_list|(
argument|int id
argument_list|)
block|;
name|QSet
operator|<
name|QAbstractState
operator|*
operator|>
name|configuration
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE_EVENTFILTER
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|watched
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
name|public
name|Q_SLOTS
operator|:
name|void
name|start
argument_list|()
block|;
name|void
name|stop
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|started
argument_list|()
block|;
name|void
name|stopped
argument_list|()
block|;
name|protected
operator|:
name|void
name|onEntry
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|onExit
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|beginSelectTransitions
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|endSelectTransitions
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|beginMicrostep
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|endMicrostep
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
name|QStateMachine
argument_list|(
name|QStateMachinePrivate
operator|&
name|dd
argument_list|,
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QStateMachine
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QStateMachine
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_start()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_process()
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_animationFinished()
argument_list|)
endif|#
directive|endif
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_startDelayedEventTimer(int, int)
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_killDelayedEventTimer(int, int)
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
