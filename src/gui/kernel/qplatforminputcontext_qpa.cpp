begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qplatforminputcontext_qpa.h>
end_include
begin_include
include|#
directive|include
file|<qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<QRect>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPlatformInputContext     \brief The QPlatformInputContext class abstracts the input method dependent data and composing state.      An input method is responsible for inputting complex text that cannot     be inputted via simple keymap. It converts a sequence of input     events (typically key events) into a text string through the input     method specific converting process. The class of the processes are     widely ranging from simple finite state machine to complex text     translator that pools a whole paragraph of a text with text     editing capability to perform grammar and semantic analysis.      To abstract such different input method specific intermediate     information, Qt offers the QPlatformInputContext as base class. The     concept is well known as 'input context' in the input method     domain. An input context is created for a text widget in response     to a demand. It is ensured that an input context is prepared for     an input method before input to a text widget.      QPlatformInputContext provides an interface the actual input methods     can derive from by reimplementing methods.      \sa QInputPanel */
comment|/*!     \internal  */
DECL|function|QPlatformInputContext
name|QPlatformInputContext
operator|::
name|QPlatformInputContext
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     \internal  */
end_comment
begin_destructor
DECL|function|~QPlatformInputContext
name|QPlatformInputContext
operator|::
name|~
name|QPlatformInputContext
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns input context validity. Deriving implementations should return true.  */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QPlatformInputContext
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Method to be called when input method needs to be reset. Called by QInputPanel::reset().     No further QInputMethodEvents should be sent as response.  */
end_comment
begin_function
DECL|function|reset
name|void
name|QPlatformInputContext
operator|::
name|reset
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|commit
name|void
name|QPlatformInputContext
operator|::
name|commit
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     Notification on editor updates. Called by QInputPanel::update().  */
end_comment
begin_function
DECL|function|update
name|void
name|QPlatformInputContext
operator|::
name|update
parameter_list|(
name|Qt
operator|::
name|InputMethodQueries
parameter_list|)
block|{ }
end_function
begin_comment
comment|/*!     Called when when the word currently being composed in input item is tapped by     the user. Input methods often use this information to offer more word     suggestions to the user.  */
end_comment
begin_function
DECL|function|invokeAction
name|void
name|QPlatformInputContext
operator|::
name|invokeAction
parameter_list|(
name|QInputPanel
operator|::
name|Action
name|action
parameter_list|,
name|int
name|cursorPosition
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|cursorPosition
argument_list|)
comment|// Default behavior for simple ephemeral input contexts. Some
comment|// complex input contexts should not be reset here.
if|if
condition|(
name|action
operator|==
name|QInputPanel
operator|::
name|Click
condition|)
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     This function can be reimplemented to filter input events.     Return true if the event has been consumed. Otherwise, the unfiltered event will     be forwarded to widgets as ordinary way. Although the input events have accept()     and ignore() methods, leave it untouched. */
end_comment
begin_function
DECL|function|filterEvent
name|bool
name|QPlatformInputContext
operator|::
name|filterEvent
parameter_list|(
specifier|const
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|event
argument_list|)
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     This function can be reimplemented to return virtual keyboard rectangle in currently active     window coordinates. Default implementation returns invalid rectangle.  */
end_comment
begin_function
DECL|function|keyboardRect
name|QRectF
name|QPlatformInputContext
operator|::
name|keyboardRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Active QPlatformInputContext is responsible for providing keyboardRectangle property to QInputPanel.     In addition of providing the value in keyboardRect function, it also needs to call this emit     function whenever the property changes.  */
end_comment
begin_function
DECL|function|emitKeyboardRectChanged
name|void
name|QPlatformInputContext
operator|::
name|emitKeyboardRectChanged
parameter_list|()
block|{
emit|emit
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|keyboardRectangleChanged
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!     This function can be reimplemented to return true whenever input panel is animating     shown or hidden. Default implementation returns false.  */
end_comment
begin_function
DECL|function|isAnimating
name|bool
name|QPlatformInputContext
operator|::
name|isAnimating
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Active QPlatformInputContext is responsible for providing animating property to QInputPanel.     In addition of providing the value in isAnimation function, it also needs to call this emit     function whenever the property changes.  */
end_comment
begin_function
DECL|function|emitAnimatingChanged
name|void
name|QPlatformInputContext
operator|::
name|emitAnimatingChanged
parameter_list|()
block|{
emit|emit
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|animatingChanged
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!     Request to show input panel.  */
end_comment
begin_function
DECL|function|showInputPanel
name|void
name|QPlatformInputContext
operator|::
name|showInputPanel
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     Request to hide input panel.  */
end_comment
begin_function
DECL|function|hideInputPanel
name|void
name|QPlatformInputContext
operator|::
name|hideInputPanel
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     Returns input panel visibility status. Default implementation returns false.  */
end_comment
begin_function
DECL|function|isInputPanelVisible
name|bool
name|QPlatformInputContext
operator|::
name|isInputPanelVisible
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Active QPlatformInputContext is responsible for providing visible property to QInputPanel.     In addition of providing the value in isInputPanelVisible function, it also needs to call this emit     function whenever the property changes.  */
end_comment
begin_function
DECL|function|emitInputPanelVisibleChanged
name|void
name|QPlatformInputContext
operator|::
name|emitInputPanelVisibleChanged
parameter_list|()
block|{
emit|emit
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|visibleChanged
argument_list|()
emit|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
