begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_empty
empty|#import<UIKit/UIKit.h>
end_empty
begin_include
include|#
directive|include
file|"qioswindow.h"
end_include
begin_decl_stmt
unit|@
name|interface
name|QUIView
range|:
name|UIView
block|{ @
name|public
name|UITextAutocapitalizationType
name|autocapitalizationType
block|;
name|UITextAutocorrectionType
name|autocorrectionType
block|;
name|BOOL
name|enablesReturnKeyAutomatically
block|;
name|UIKeyboardAppearance
name|keyboardAppearance
block|;
name|UIKeyboardType
name|keyboardType
block|;
name|UIReturnKeyType
name|returnKeyType
block|;
name|BOOL
name|secureTextEntry
block|;
name|QIOSWindow
operator|*
name|m_qioswindow
block|;
name|QHash
operator|<
name|UITouch
operator|*
block|,
name|QWindowSystemInterface
operator|::
name|TouchPoint
operator|>
name|m_activeTouches
block|;
name|int
name|m_nextTouchId
block|;
name|QString
name|m_markedText
block|;
name|BOOL
name|m_inSendEventToFocusObject
block|;
name|NSMutableArray
operator|*
name|m_accessibleElements
block|; }
expr|@
name|property
argument_list|(
argument|nonatomic
argument_list|,
argument|assign
argument_list|)
name|id
operator|<
name|UITextInputDelegate
operator|>
name|inputDelegate
decl_stmt|;
end_decl_stmt
begin_macro
unit|@
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
name|UITextAutocapitalizationType
name|autocapitalizationType
decl_stmt|;
end_decl_stmt
begin_macro
unit|@
DECL|variable|autocorrectionType
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|autocorrectionType
name|UITextAutocorrectionType
name|autocorrectionType
decl_stmt|;
end_decl_stmt
begin_macro
DECL|variable|autocorrectionType
unit|@
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
name|UITextSpellCheckingType
name|spellCheckingType
decl_stmt|;
end_decl_stmt
begin_macro
unit|@
DECL|variable|enablesReturnKeyAutomatically
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|enablesReturnKeyAutomatically
name|BOOL
name|enablesReturnKeyAutomatically
decl_stmt|;
end_decl_stmt
begin_macro
DECL|variable|enablesReturnKeyAutomatically
unit|@
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
name|UIKeyboardAppearance
name|keyboardAppearance
decl_stmt|;
end_decl_stmt
begin_macro
unit|@
DECL|variable|keyboardType
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|keyboardType
name|UIKeyboardType
name|keyboardType
decl_stmt|;
end_decl_stmt
begin_macro
DECL|variable|keyboardType
unit|@
name|property
argument_list|(
argument|nonatomic
argument_list|)
end_macro
begin_decl_stmt
name|UIReturnKeyType
name|returnKeyType
decl_stmt|;
end_decl_stmt
begin_macro
unit|@
DECL|variable|secureTextEntry
name|property
argument_list|(
argument|nonatomic
argument_list|,
argument|getter=isSecureTextEntry
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|secureTextEntry
name|BOOL
name|secureTextEntry
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|secureTextEntry
unit|@
name|end
expr|@
name|interface
name|QUIView
argument_list|(
name|TextInput
argument_list|)
operator|<
name|UITextInput
operator|>
operator|-
operator|(
name|void
operator|)
name|updateInputMethodWithQuery
operator|:
operator|(
name|Qt
operator|::
name|InputMethodQueries
operator|)
name|query
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|reset
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|commit
expr_stmt|;
end_expr_stmt
begin_macro
unit|@
name|end
end_macro
end_unit
