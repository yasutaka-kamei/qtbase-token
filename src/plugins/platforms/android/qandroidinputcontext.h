begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ANDROIDINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|ANDROIDINPUTCONTEXT_H
define|#
directive|define
name|ANDROIDINPUTCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_include
include|#
directive|include
file|<jni.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QAndroidInputContext
range|:
name|public
name|QPlatformInputContext
block|{
name|Q_OBJECT
expr|enum
name|CapsMode
block|{
name|CAP_MODE_CHARACTERS
operator|=
literal|0x00001000
block|,
name|CAP_MODE_SENTENCES
operator|=
literal|0x00004000
block|,
name|CAP_MODE_WORDS
operator|=
literal|0x00002000
block|}
block|;
name|public
operator|:
expr|struct
name|ExtractedText
block|{
name|ExtractedText
argument_list|()
block|{
name|clear
argument_list|()
block|; }
name|void
name|clear
argument_list|()
block|{
name|partialEndOffset
operator|=
name|partialStartOffset
operator|=
name|selectionEnd
operator|=
name|selectionStart
operator|=
name|startOffset
operator|=
operator|-
literal|1
block|;
name|text
operator|.
name|clear
argument_list|()
block|;         }
name|int
name|partialEndOffset
block|;
name|int
name|partialStartOffset
block|;
name|int
name|selectionEnd
block|;
name|int
name|selectionStart
block|;
name|int
name|startOffset
block|;
name|QString
name|text
block|;     }
block|;
name|public
operator|:
name|QAndroidInputContext
argument_list|()
block|;
operator|~
name|QAndroidInputContext
argument_list|()
block|;
specifier|static
name|QAndroidInputContext
operator|*
name|androidInputContext
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|void
name|reset
argument_list|()
block|;
name|void
name|commit
argument_list|()
block|;
name|void
name|update
argument_list|(
argument|Qt::InputMethodQueries queries
argument_list|)
block|;
name|void
name|invokeAction
argument_list|(
argument|QInputMethod::Action action
argument_list|,
argument|int cursorPosition
argument_list|)
block|;
name|QRectF
name|keyboardRect
argument_list|()
specifier|const
block|;
name|bool
name|isAnimating
argument_list|()
specifier|const
block|;
name|void
name|showInputPanel
argument_list|()
block|;
name|void
name|hideInputPanel
argument_list|()
block|;
name|bool
name|isInputPanelVisible
argument_list|()
specifier|const
block|;
name|bool
name|isComposing
argument_list|()
specifier|const
block|;
name|void
name|clear
argument_list|()
block|;
comment|//---------------//
name|jboolean
name|commitText
argument_list|(
argument|const QString&text
argument_list|,
argument|jint newCursorPosition
argument_list|)
block|;
name|jboolean
name|deleteSurroundingText
argument_list|(
argument|jint leftLength
argument_list|,
argument|jint rightLength
argument_list|)
block|;
name|jboolean
name|finishComposingText
argument_list|()
block|;
name|jint
name|getCursorCapsMode
argument_list|(
argument|jint reqModes
argument_list|)
block|;
specifier|const
name|ExtractedText
operator|&
name|getExtractedText
argument_list|(
argument|jint hintMaxChars
argument_list|,
argument|jint hintMaxLines
argument_list|,
argument|jint flags
argument_list|)
block|;
name|QString
name|getSelectedText
argument_list|(
argument|jint flags
argument_list|)
block|;
name|QString
name|getTextAfterCursor
argument_list|(
argument|jint length
argument_list|,
argument|jint flags
argument_list|)
block|;
name|QString
name|getTextBeforeCursor
argument_list|(
argument|jint length
argument_list|,
argument|jint flags
argument_list|)
block|;
name|jboolean
name|setComposingText
argument_list|(
argument|const QString&text
argument_list|,
argument|jint newCursorPosition
argument_list|)
block|;
name|jboolean
name|setComposingRegion
argument_list|(
argument|jint start
argument_list|,
argument|jint end
argument_list|)
block|;
name|jboolean
name|setSelection
argument_list|(
argument|jint start
argument_list|,
argument|jint end
argument_list|)
block|;
name|jboolean
name|selectAll
argument_list|()
block|;
name|jboolean
name|cut
argument_list|()
block|;
name|jboolean
name|copy
argument_list|()
block|;
name|jboolean
name|copyURL
argument_list|()
block|;
name|jboolean
name|paste
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|updateCursorPosition
argument_list|()
block|;
name|private
operator|:
name|QSharedPointer
operator|<
name|QInputMethodQueryEvent
operator|>
name|focusObjectInputMethodQuery
argument_list|(
argument|Qt::InputMethodQueries queries = Qt::ImQueryAll
argument_list|)
block|;
name|void
name|sendInputMethodEvent
argument_list|(
name|QInputMethodEvent
operator|*
name|event
argument_list|)
block|;
name|Q_INVOKABLE
name|QVariant
name|queryFocusObjectUnsafe
argument_list|(
argument|Qt::InputMethodQuery query
argument_list|,
argument|QVariant argument
argument_list|)
block|;
name|QVariant
name|queryFocusObjectThreadSafe
argument_list|(
argument|Qt::InputMethodQuery query
argument_list|,
argument|QVariant argument
argument_list|)
block|;
name|private
name|slots
operator|:
name|virtual
name|void
name|sendEvent
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
name|QInputMethodEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|sendEvent
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
name|QInputMethodQueryEvent
operator|*
name|event
argument_list|)
block|;
name|private
operator|:
name|ExtractedText
name|m_extractedText
block|;
name|QString
name|m_composingText
block|;
name|QMetaObject
operator|::
name|Connection
name|m_updateCursorPosConnection
block|;
name|bool
name|m_blockUpdateSelection
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
comment|// ANDROIDINPUTCONTEXT_H
end_comment
end_unit
