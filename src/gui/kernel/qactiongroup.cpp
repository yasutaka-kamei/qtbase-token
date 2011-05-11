begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qactiongroup.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACTION
end_ifndef
begin_include
include|#
directive|include
file|"qaction_p.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QActionGroupPrivate
class|class
name|QActionGroupPrivate
super|:
specifier|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QActionGroup
parameter_list|)
specifier|public
private|:
DECL|function|QActionGroupPrivate
name|QActionGroupPrivate
parameter_list|()
member_init_list|:
name|exclusive
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|enabled
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|visible
argument_list|(
literal|1
argument_list|)
block|{ }
DECL|member|actions
name|QList
argument_list|<
name|QAction
modifier|*
argument_list|>
name|actions
decl_stmt|;
DECL|member|current
name|QPointer
argument_list|<
name|QAction
argument_list|>
name|current
decl_stmt|;
name|uint
name|exclusive
range|:
literal|1
decl_stmt|;
name|uint
name|enabled
range|:
literal|1
decl_stmt|;
name|uint
name|visible
range|:
literal|1
decl_stmt|;
private|private:
name|void
name|_q_actionTriggered
parameter_list|()
function_decl|;
comment|//private slot
name|void
name|_q_actionChanged
parameter_list|()
function_decl|;
comment|//private slot
name|void
name|_q_actionHovered
parameter_list|()
function_decl|;
comment|//private slot
block|}
class|;
end_class
begin_function
DECL|function|_q_actionChanged
name|void
name|QActionGroupPrivate
operator|::
name|_q_actionChanged
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QActionGroup
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|action
init|=
name|qobject_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|q
operator|->
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT_X
argument_list|(
name|action
operator|!=
literal|0
argument_list|,
literal|"QWidgetGroup::_q_actionChanged"
argument_list|,
literal|"internal error"
argument_list|)
expr_stmt|;
if|if
condition|(
name|exclusive
condition|)
block|{
if|if
condition|(
name|action
operator|->
name|isChecked
argument_list|()
condition|)
block|{
if|if
condition|(
name|action
operator|!=
name|current
condition|)
block|{
if|if
condition|(
name|current
condition|)
name|current
operator|->
name|setChecked
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|current
operator|=
name|action
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|action
operator|==
name|current
condition|)
block|{
name|current
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|_q_actionTriggered
name|void
name|QActionGroupPrivate
operator|::
name|_q_actionTriggered
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QActionGroup
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|action
init|=
name|qobject_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|q
operator|->
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT_X
argument_list|(
name|action
operator|!=
literal|0
argument_list|,
literal|"QWidgetGroup::_q_actionTriggered"
argument_list|,
literal|"internal error"
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|triggered
argument_list|(
name|action
argument_list|)
emit|;
emit|emit
name|q
operator|->
name|selected
argument_list|(
name|action
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|_q_actionHovered
name|void
name|QActionGroupPrivate
operator|::
name|_q_actionHovered
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QActionGroup
argument_list|)
expr_stmt|;
name|QAction
modifier|*
name|action
init|=
name|qobject_cast
argument_list|<
name|QAction
operator|*
argument_list|>
argument_list|(
name|q
operator|->
name|sender
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT_X
argument_list|(
name|action
operator|!=
literal|0
argument_list|,
literal|"QWidgetGroup::_q_actionHovered"
argument_list|,
literal|"internal error"
argument_list|)
expr_stmt|;
emit|emit
name|q
operator|->
name|hovered
argument_list|(
name|action
argument_list|)
emit|;
block|}
end_function
begin_comment
comment|/*!     \class QActionGroup     \brief The QActionGroup class groups actions together.      \ingroup mainwindow-classes      In some situations it is useful to group QAction objects together.     For example, if you have a \gui{Left Align} action, a \gui{Right     Align} action, a \gui{Justify} action, and a \gui{Center} action,     only one of these actions should be active at any one time. One     simple way of achieving this is to group the actions together in     an action group.      Here's a example (from the \l{mainwindows/menus}{Menus} example):      \snippet examples/mainwindows/menus/mainwindow.cpp 6      Here we create a new action group. Since the action group is     exclusive by default, only one of the actions in the group is     checked at any one time.      \img qactiongroup-align.png Alignment options in a QMenu      A QActionGroup emits an triggered() signal when one of its     actions is chosen. Each action in an action group emits its     triggered() signal as usual.      As stated above, an action group is \l exclusive by default; it     ensures that only one checkable action is active at any one time.     If you want to group checkable actions without making them     exclusive, you can turn of exclusiveness by calling     setExclusive(false).      Actions can be added to an action group using addAction(), but it     is usually more convenient to specify a group when creating     actions; this ensures that actions are automatically created with     a parent. Actions can be visually separated from each other by     adding a separator action to the group; create an action and use     QAction's \l {QAction::}{setSeparator()} function to make it     considered a separator. Action groups are added to widgets with     the QWidget::addActions() function.      \sa QAction */
end_comment
begin_comment
comment|/*!     Constructs an action group for the \a parent object.      The action group is exclusive by default. Call setExclusive(false)     to make the action group non-exclusive. */
end_comment
begin_constructor
DECL|function|QActionGroup
name|QActionGroup
operator|::
name|QActionGroup
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QActionGroupPrivate
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the action group. */
end_comment
begin_destructor
DECL|function|~QActionGroup
name|QActionGroup
operator|::
name|~
name|QActionGroup
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn QAction *QActionGroup::addAction(QAction *action)      Adds the \a action to this group, and returns it.      Normally an action is added to a group by creating it with the     group as its parent, so this function is not usually used.      \sa QAction::setActionGroup() */
end_comment
begin_function
DECL|function|addAction
name|QAction
modifier|*
name|QActionGroup
operator|::
name|addAction
parameter_list|(
name|QAction
modifier|*
name|a
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QActionGroup
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|actions
operator|.
name|contains
argument_list|(
name|a
argument_list|)
condition|)
block|{
name|d
operator|->
name|actions
operator|.
name|append
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|a
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_actionTriggered
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|a
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_actionChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|a
argument_list|,
name|SIGNAL
argument_list|(
name|hovered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_actionHovered
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|a
operator|->
name|d_func
argument_list|()
operator|->
name|forceDisabled
condition|)
block|{
name|a
operator|->
name|setEnabled
argument_list|(
name|d
operator|->
name|enabled
argument_list|)
expr_stmt|;
name|a
operator|->
name|d_func
argument_list|()
operator|->
name|forceDisabled
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|a
operator|->
name|d_func
argument_list|()
operator|->
name|forceInvisible
condition|)
block|{
name|a
operator|->
name|setVisible
argument_list|(
name|d
operator|->
name|visible
argument_list|)
expr_stmt|;
name|a
operator|->
name|d_func
argument_list|()
operator|->
name|forceInvisible
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
name|a
operator|->
name|isChecked
argument_list|()
condition|)
name|d
operator|->
name|current
operator|=
name|a
expr_stmt|;
name|QActionGroup
modifier|*
name|oldGroup
init|=
name|a
operator|->
name|d_func
argument_list|()
operator|->
name|group
decl_stmt|;
if|if
condition|(
name|oldGroup
operator|!=
name|this
condition|)
block|{
if|if
condition|(
name|oldGroup
condition|)
name|oldGroup
operator|->
name|removeAction
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|a
operator|->
name|d_func
argument_list|()
operator|->
name|group
operator|=
name|this
expr_stmt|;
block|}
return|return
name|a
return|;
block|}
end_function
begin_comment
comment|/*!     Creates and returns an action with \a text.  The newly created     action is a child of this action group.      Normally an action is added to a group by creating it with the     group as parent, so this function is not usually used.      \sa QAction::setActionGroup() */
end_comment
begin_function
DECL|function|addAction
name|QAction
modifier|*
name|QActionGroup
operator|::
name|addAction
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
return|return
operator|new
name|QAction
argument_list|(
name|text
argument_list|,
name|this
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Creates and returns an action with \a text and an \a icon. The     newly created action is a child of this action group.      Normally an action is added to a group by creating it with the     group as its parent, so this function is not usually used.      \sa QAction::setActionGroup() */
end_comment
begin_function
DECL|function|addAction
name|QAction
modifier|*
name|QActionGroup
operator|::
name|addAction
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
return|return
operator|new
name|QAction
argument_list|(
name|icon
argument_list|,
name|text
argument_list|,
name|this
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!   Removes the \a action from this group. The action will have no   parent as a result.    \sa QAction::setActionGroup() */
end_comment
begin_function
DECL|function|removeAction
name|void
name|QActionGroup
operator|::
name|removeAction
parameter_list|(
name|QAction
modifier|*
name|action
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QActionGroup
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|actions
operator|.
name|removeAll
argument_list|(
name|action
argument_list|)
condition|)
block|{
if|if
condition|(
name|action
operator|==
name|d
operator|->
name|current
condition|)
name|d
operator|->
name|current
operator|=
literal|0
expr_stmt|;
name|QObject
operator|::
name|disconnect
argument_list|(
name|action
argument_list|,
name|SIGNAL
argument_list|(
name|triggered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_actionTriggered
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|disconnect
argument_list|(
name|action
argument_list|,
name|SIGNAL
argument_list|(
name|changed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_actionChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|disconnect
argument_list|(
name|action
argument_list|,
name|SIGNAL
argument_list|(
name|hovered
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_actionHovered
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|action
operator|->
name|d_func
argument_list|()
operator|->
name|group
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns the list of this groups's actions. This may be empty. */
end_comment
begin_function
DECL|function|actions
name|QList
argument_list|<
name|QAction
modifier|*
argument_list|>
name|QActionGroup
operator|::
name|actions
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QActionGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|actions
return|;
block|}
end_function
begin_comment
comment|/*!     \property QActionGroup::exclusive     \brief whether the action group does exclusive checking      If exclusive is true, only one checkable action in the action group     can ever be active at any time. If the user chooses another     checkable action in the group, the one they chose becomes active and     the one that was active becomes inactive.      \sa QAction::checkable */
end_comment
begin_function
DECL|function|setExclusive
name|void
name|QActionGroup
operator|::
name|setExclusive
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QActionGroup
argument_list|)
expr_stmt|;
name|d
operator|->
name|exclusive
operator|=
name|b
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isExclusive
name|bool
name|QActionGroup
operator|::
name|isExclusive
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QActionGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|exclusive
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QActionGroup::setDisabled(bool b)      This is a convenience function for the \l enabled property, that     is useful for signals--slots connections. If \a b is true the     action group is disabled; otherwise it is enabled. */
end_comment
begin_comment
comment|/*!     \property QActionGroup::enabled     \brief whether the action group is enabled      Each action in the group will be enabled or disabled unless it     has been explicitly disabled.      \sa QAction::setEnabled() */
end_comment
begin_function
DECL|function|setEnabled
name|void
name|QActionGroup
operator|::
name|setEnabled
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QActionGroup
argument_list|)
expr_stmt|;
name|d
operator|->
name|enabled
operator|=
name|b
expr_stmt|;
for|for
control|(
name|QList
argument_list|<
name|QAction
operator|*
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|d
operator|->
name|actions
operator|.
name|constBegin
argument_list|()
init|;
name|it
operator|!=
name|d
operator|->
name|actions
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
operator|!
operator|(
operator|*
name|it
operator|)
operator|->
name|d_func
argument_list|()
operator|->
name|forceDisabled
condition|)
block|{
operator|(
operator|*
name|it
operator|)
operator|->
name|setEnabled
argument_list|(
name|b
argument_list|)
expr_stmt|;
operator|(
operator|*
name|it
operator|)
operator|->
name|d_func
argument_list|()
operator|->
name|forceDisabled
operator|=
literal|false
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|isEnabled
name|bool
name|QActionGroup
operator|::
name|isEnabled
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QActionGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|enabled
return|;
block|}
end_function
begin_comment
comment|/*!   Returns the currently checked action in the group, or 0 if none   are checked. */
end_comment
begin_function
DECL|function|checkedAction
name|QAction
modifier|*
name|QActionGroup
operator|::
name|checkedAction
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QActionGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|current
return|;
block|}
end_function
begin_comment
comment|/*!     \property QActionGroup::visible     \brief whether the action group is visible      Each action in the action group will match the visible state of     this group unless it has been explicitly hidden.      \sa QAction::setEnabled() */
end_comment
begin_function
DECL|function|setVisible
name|void
name|QActionGroup
operator|::
name|setVisible
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QActionGroup
argument_list|)
expr_stmt|;
name|d
operator|->
name|visible
operator|=
name|b
expr_stmt|;
for|for
control|(
name|QList
argument_list|<
name|QAction
operator|*
argument_list|>
operator|::
name|Iterator
name|it
init|=
name|d
operator|->
name|actions
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|d
operator|->
name|actions
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
operator|!
operator|(
operator|*
name|it
operator|)
operator|->
name|d_func
argument_list|()
operator|->
name|forceInvisible
condition|)
block|{
operator|(
operator|*
name|it
operator|)
operator|->
name|setVisible
argument_list|(
name|b
argument_list|)
expr_stmt|;
operator|(
operator|*
name|it
operator|)
operator|->
name|d_func
argument_list|()
operator|->
name|forceInvisible
operator|=
literal|false
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|isVisible
name|bool
name|QActionGroup
operator|::
name|isVisible
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QActionGroup
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|visible
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QActionGroup::triggered(QAction *action)      This signal is emitted when the given \a action in the action     group is activated by the user; for example, when the user clicks     a menu option, toolbar button, or presses an action's shortcut key     combination.      Connect to this signal for command actions.      \sa QAction::activate() */
end_comment
begin_comment
comment|/*!     \fn void QActionGroup::hovered(QAction *action)      This signal is emitted when the given \a action in the action     group is highlighted by the user; for example, when the user     pauses with the cursor over a menu option, toolbar button, or     presses an action's shortcut key combination.      \sa QAction::activate() */
end_comment
begin_comment
comment|/*!     \fn void QActionGroup::add(QAction* a)      Use addAction() instead. */
end_comment
begin_comment
comment|/*!     \fn void QActionGroup::addSeparator()      Normally you add a separator to the menus or widgets to which     actions are added, so this function is very rarely needed.      \oldcode     actionGroup->addSeparator();     \newcode     QAction *separator = new QAction(this);     separator->setSeparator(true);     actionGroup->addAction(separator);     \endcode */
end_comment
begin_comment
comment|/*!     \fn bool QActionGroup::addTo(QWidget *widget)      \oldcode     actionGroup->addTo(widget);     \newcode     widget->addActions(actionGroup->actions());     \endcode */
end_comment
begin_comment
comment|/*!     \fn void QActionGroup::selected(QAction *action);      Use triggered() instead.  */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qactiongroup.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACTION
end_comment
end_unit
