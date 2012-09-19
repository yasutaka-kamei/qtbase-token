begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbasicmouseeventtransition_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpainterpath.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<private/qabstracttransition_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!   \internal   \class QBasicMouseEventTransition   \since 4.6   \ingroup statemachine    \brief The QBasicMouseEventTransition class provides a transition for Qt mouse events. */
end_comment
begin_class
DECL|class|QBasicMouseEventTransitionPrivate
class|class
name|QBasicMouseEventTransitionPrivate
super|:
specifier|public
name|QAbstractTransitionPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QBasicMouseEventTransition
parameter_list|)
specifier|public
private|:
name|QBasicMouseEventTransitionPrivate
parameter_list|()
constructor_decl|;
specifier|static
name|QBasicMouseEventTransitionPrivate
modifier|*
name|get
parameter_list|(
name|QBasicMouseEventTransition
modifier|*
name|q
parameter_list|)
function_decl|;
DECL|member|eventType
name|QEvent
operator|::
name|Type
name|eventType
decl_stmt|;
DECL|member|button
name|Qt
operator|::
name|MouseButton
name|button
decl_stmt|;
DECL|member|modifierMask
name|Qt
operator|::
name|KeyboardModifiers
name|modifierMask
decl_stmt|;
DECL|member|path
name|QPainterPath
name|path
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QBasicMouseEventTransitionPrivate
name|QBasicMouseEventTransitionPrivate
operator|::
name|QBasicMouseEventTransitionPrivate
parameter_list|()
block|{
name|eventType
operator|=
name|QEvent
operator|::
name|None
expr_stmt|;
name|button
operator|=
name|Qt
operator|::
name|NoButton
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|get
name|QBasicMouseEventTransitionPrivate
modifier|*
name|QBasicMouseEventTransitionPrivate
operator|::
name|get
parameter_list|(
name|QBasicMouseEventTransition
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
begin_comment
comment|/*!   Constructs a new mouse event transition with the given \a sourceState. */
end_comment
begin_constructor
DECL|function|QBasicMouseEventTransition
name|QBasicMouseEventTransition
operator|::
name|QBasicMouseEventTransition
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
name|QBasicMouseEventTransitionPrivate
argument_list|,
name|sourceState
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   Constructs a new mouse event transition for events of the given \a type. */
end_comment
begin_constructor
DECL|function|QBasicMouseEventTransition
name|QBasicMouseEventTransition
operator|::
name|QBasicMouseEventTransition
parameter_list|(
name|QEvent
operator|::
name|Type
name|type
parameter_list|,
name|Qt
operator|::
name|MouseButton
name|button
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
name|QBasicMouseEventTransitionPrivate
argument_list|,
name|sourceState
argument_list|)
block|{
name|Q_D
argument_list|(
name|QBasicMouseEventTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|eventType
operator|=
name|type
expr_stmt|;
name|d
operator|->
name|button
operator|=
name|button
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   Destroys this mouse event transition. */
end_comment
begin_destructor
DECL|function|~QBasicMouseEventTransition
name|QBasicMouseEventTransition
operator|::
name|~
name|QBasicMouseEventTransition
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!   Returns the event type that this mouse event transition is associated with. */
end_comment
begin_function
DECL|function|eventType
name|QEvent
operator|::
name|Type
name|QBasicMouseEventTransition
operator|::
name|eventType
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QBasicMouseEventTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|eventType
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the event \a type that this mouse event transition is associated with. */
end_comment
begin_function
DECL|function|setEventType
name|void
name|QBasicMouseEventTransition
operator|::
name|setEventType
parameter_list|(
name|QEvent
operator|::
name|Type
name|type
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QBasicMouseEventTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|eventType
operator|=
name|type
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the button that this mouse event transition checks for. */
end_comment
begin_function
DECL|function|button
name|Qt
operator|::
name|MouseButton
name|QBasicMouseEventTransition
operator|::
name|button
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QBasicMouseEventTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|button
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the button that this mouse event transition will check for. */
end_comment
begin_function
DECL|function|setButton
name|void
name|QBasicMouseEventTransition
operator|::
name|setButton
parameter_list|(
name|Qt
operator|::
name|MouseButton
name|button
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QBasicMouseEventTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|button
operator|=
name|button
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the keyboard modifier mask that this mouse event transition checks   for. */
end_comment
begin_function
DECL|function|modifierMask
name|Qt
operator|::
name|KeyboardModifiers
name|QBasicMouseEventTransition
operator|::
name|modifierMask
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QBasicMouseEventTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|modifierMask
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the keyboard modifier mask that this mouse event transition will check   for. */
end_comment
begin_function
DECL|function|setModifierMask
name|void
name|QBasicMouseEventTransition
operator|::
name|setModifierMask
parameter_list|(
name|Qt
operator|::
name|KeyboardModifiers
name|modifierMask
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QBasicMouseEventTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|modifierMask
operator|=
name|modifierMask
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the hit test path for this mouse event transition. */
end_comment
begin_function
DECL|function|hitTestPath
name|QPainterPath
name|QBasicMouseEventTransition
operator|::
name|hitTestPath
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QBasicMouseEventTransition
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|path
return|;
block|}
end_function
begin_comment
comment|/*!   Sets the hit test path for this mouse event transition. */
end_comment
begin_function
DECL|function|setHitTestPath
name|void
name|QBasicMouseEventTransition
operator|::
name|setHitTestPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QBasicMouseEventTransition
argument_list|)
expr_stmt|;
name|d
operator|->
name|path
operator|=
name|path
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \reimp */
end_comment
begin_function
DECL|function|eventTest
name|bool
name|QBasicMouseEventTransition
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
name|QBasicMouseEventTransition
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|d
operator|->
name|eventType
condition|)
block|{
name|QMouseEvent
modifier|*
name|me
init|=
cast|static_cast
argument_list|<
name|QMouseEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
decl_stmt|;
return|return
operator|(
name|me
operator|->
name|button
argument_list|()
operator|==
name|d
operator|->
name|button
operator|)
operator|&&
operator|(
operator|(
name|me
operator|->
name|modifiers
argument_list|()
operator|&
name|d
operator|->
name|modifierMask
operator|)
operator|==
name|d
operator|->
name|modifierMask
operator|)
operator|&&
operator|(
name|d
operator|->
name|path
operator|.
name|isEmpty
argument_list|()
operator|||
name|d
operator|->
name|path
operator|.
name|contains
argument_list|(
name|me
operator|->
name|pos
argument_list|()
argument_list|)
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
name|QBasicMouseEventTransition
operator|::
name|onTransition
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
block|{ }
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
