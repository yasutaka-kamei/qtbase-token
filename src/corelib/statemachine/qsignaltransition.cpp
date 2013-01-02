begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsignaltransition.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
end_ifndef
begin_include
include|#
directive|include
file|"qsignaltransition_p.h"
end_include
begin_include
include|#
directive|include
file|"qstate.h"
end_include
begin_include
include|#
directive|include
file|"qstate_p.h"
end_include
begin_include
include|#
directive|include
file|"qstatemachine.h"
end_include
begin_include
include|#
directive|include
file|"qstatemachine_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!   \class QSignalTransition   \inmodule QtCore    \brief The QSignalTransition class provides a transition based on a Qt signal.    \since 4.6   \ingroup statemachine    Typically you would use the overload of QState::addTransition() that takes a   sender and signal as arguments, rather than creating QSignalTransition   objects directly. QSignalTransition is part of \l{The State Machine   Framework}.    You can subclass QSignalTransition and reimplement eventTest() to make a   signal transition conditional; the event object passed to eventTest() will   be a QStateMachine::SignalEvent object. Example:    \code   class CheckedTransition : public QSignalTransition   {   public:       CheckedTransition(QCheckBox *check)           : QSignalTransition(check, SIGNAL(stateChanged(int))) {}   protected:       bool eventTest(QEvent *e) {           if (!QSignalTransition::eventTest(e))               return false;           QStateMachine::SignalEvent *se = static_cast<QStateMachine::SignalEvent*>(e);           return (se->arguments().at(0).toInt() == Qt::Checked);       }   };    ...    QCheckBox *check = new QCheckBox();   check->setTristate(true);    QState *s1 = new QState();   QState *s2 = new QState();   CheckedTransition *t1 = new CheckedTransition(check);   t1->setTargetState(s2);   s1->addTransition(t1);   \endcode */
comment|/*!     \property QSignalTransition::senderObject      \brief the sender object that this signal transition is associated with */
comment|/*!     \property QSignalTransition::signal      \brief the signal that this signal transition is associated with */
DECL|function|QSignalTransitionPrivate
name|QSignalTransitionPrivate
operator|::
name|QSignalTransitionPrivate
parameter_list|()
block|{
name|sender
operator|=
literal|0
expr_stmt|;
name|signalIndex
operator|=
operator|-
literal|1
expr_stmt|;
block|}
end_function
begin_function
DECL|function|get
name|QSignalTransitionPrivate
modifier|*
name|QSignalTransitionPrivate
operator|::
name|get
parameter_list|(
name|QSignalTransition
modifier|*
name|q
parameter_list|)
block|{
return|return
name|q
operator|->
name|d_func
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|unregister
name|void
name|QSignalTransitionPrivate
operator|::
name|unregister
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QSignalTransition
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|signalIndex
operator|==
operator|-
literal|1
operator|)
operator|||
operator|!
name|machine
argument_list|()
condition|)
return|return;
name|QStateMachinePrivate
operator|::
name|get
argument_list|(
name|machine
argument_list|()
argument_list|)
operator|->
name|unregisterSignalTransition
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|maybeRegister
name|void
name|QSignalTransitionPrivate
operator|::
name|maybeRegister
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QSignalTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|QStateMachine
modifier|*
name|mach
init|=
name|machine
argument_list|()
condition|)
name|QStateMachinePrivate
operator|::
name|get
argument_list|(
name|mach
argument_list|)
operator|->
name|maybeRegisterSignalTransition
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Constructs a new signal transition with the given \a sourceState. */
end_comment
begin_constructor
DECL|function|QSignalTransition
name|QSignalTransition
operator|::
name|QSignalTransition
parameter_list|(
name|QState
modifier|*
name|sourceState
parameter_list|)
member_init_list|:
name|QAbstractTransition
argument_list|(
operator|*
operator|new
name|QSignalTransitionPrivate
argument_list|,
name|sourceState
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Constructs a new signal transition associated with the given \a signal of   the given \a sender, and with the given \a sourceState. */
end_comment
begin_constructor
DECL|function|QSignalTransition
name|QSignalTransition
operator|::
name|QSignalTransition
parameter_list|(
specifier|const
name|QObject
modifier|*
name|sender
parameter_list|,
specifier|const
name|char
modifier|*
name|signal
parameter_list|,
name|QState
modifier|*
name|sourceState
parameter_list|)
member_init_list|:
name|QAbstractTransition
argument_list|(
operator|*
operator|new
name|QSignalTransitionPrivate
argument_list|,
name|sourceState
argument_list|)
block|{
name|Q_D
argument_list|(
name|QSignalTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|sender
operator|=
name|sender
expr_stmt|;
name|d
operator|->
name|signal
operator|=
name|signal
expr_stmt|;
name|d
operator|->
name|maybeRegister
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Destroys this signal transition. */
end_comment
begin_destructor
DECL|function|~QSignalTransition
name|QSignalTransition
operator|::
name|~
name|QSignalTransition
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   Returns the sender object associated with this signal transition. */
end_comment
begin_function
DECL|function|senderObject
name|QObject
modifier|*
name|QSignalTransition
operator|::
name|senderObject
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSignalTransition
argument_list|)
expr_stmt|;
return|return
cast|const_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|sender
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the \a sender object associated with this signal transition. */
end_comment
begin_function
DECL|function|setSenderObject
name|void
name|QSignalTransition
operator|::
name|setSenderObject
parameter_list|(
specifier|const
name|QObject
modifier|*
name|sender
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSignalTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|sender
operator|==
name|d
operator|->
name|sender
condition|)
return|return;
name|d
operator|->
name|unregister
argument_list|()
expr_stmt|;
name|d
operator|->
name|sender
operator|=
name|sender
expr_stmt|;
name|d
operator|->
name|maybeRegister
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the signal associated with this signal transition. */
end_comment
begin_function
DECL|function|signal
name|QByteArray
name|QSignalTransition
operator|::
name|signal
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSignalTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|signal
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the \a signal associated with this signal transition. */
end_comment
begin_function
DECL|function|setSignal
name|void
name|QSignalTransition
operator|::
name|setSignal
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|signal
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSignalTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|signal
operator|==
name|d
operator|->
name|signal
condition|)
return|return;
name|d
operator|->
name|unregister
argument_list|()
expr_stmt|;
name|d
operator|->
name|signal
operator|=
name|signal
expr_stmt|;
name|d
operator|->
name|maybeRegister
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp    The default implementation returns true if the \a event is a   QStateMachine::SignalEvent object and the event's sender and signal index   match this transition, and returns false otherwise. */
end_comment
begin_function
DECL|function|eventTest
name|bool
name|QSignalTransition
operator|::
name|eventTest
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
specifier|const
name|QSignalTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|StateMachineSignal
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|signalIndex
operator|==
operator|-
literal|1
condition|)
return|return
literal|false
return|;
name|QStateMachine
operator|::
name|SignalEvent
modifier|*
name|se
init|=
cast|static_cast
argument_list|<
name|QStateMachine
operator|::
name|SignalEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
return|return
operator|(
name|se
operator|->
name|sender
argument_list|()
operator|==
name|d
operator|->
name|sender
operator|)
operator|&&
operator|(
name|se
operator|->
name|signalIndex
argument_list|()
operator|==
name|d
operator|->
name|signalIndex
operator|)
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|onTransition
name|void
name|QSignalTransition
operator|::
name|onTransition
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QSignalTransition
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
return|return
name|QAbstractTransition
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|callOnTransition
name|void
name|QSignalTransitionPrivate
operator|::
name|callOnTransition
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QSignalTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|StateMachineSignal
condition|)
block|{
name|QStateMachine
operator|::
name|SignalEvent
modifier|*
name|se
init|=
cast|static_cast
argument_list|<
name|QStateMachine
operator|::
name|SignalEvent
operator|*
argument_list|>
argument_list|(
name|e
argument_list|)
decl_stmt|;
name|int
name|savedSignalIndex
init|=
name|se
operator|->
name|m_signalIndex
decl_stmt|;
name|se
operator|->
name|m_signalIndex
operator|=
name|originalSignalIndex
expr_stmt|;
name|q
operator|->
name|onTransition
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|se
operator|->
name|m_signalIndex
operator|=
name|savedSignalIndex
expr_stmt|;
block|}
else|else
block|{
name|q
operator|->
name|onTransition
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_STATEMACHINE
end_comment
end_unit
