begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|QPLATFORMINPUTCONTEXT_H
define|#
directive|define
name|QPLATFORMINPUTCONTEXT_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtGui/qinputpanel.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformInputContextPrivate
name|class
name|QPlatformInputContextPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformInputContext
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPlatformInputContext
argument_list|)
name|public
operator|:
name|QPlatformInputContext
argument_list|()
block|;
name|virtual
operator|~
name|QPlatformInputContext
argument_list|()
block|;
name|virtual
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|reset
argument_list|()
block|;
name|virtual
name|void
name|commit
argument_list|()
block|;
name|virtual
name|void
name|update
argument_list|(
name|Qt
operator|::
name|InputMethodQueries
argument_list|)
block|;
name|virtual
name|void
name|invokeAction
argument_list|(
argument|QInputMethod::Action
argument_list|,
argument|int cursorPosition
argument_list|)
block|;
name|virtual
name|bool
name|filterEvent
argument_list|(
specifier|const
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|QRectF
name|keyboardRect
argument_list|()
specifier|const
block|;
name|void
name|emitKeyboardRectChanged
argument_list|()
block|;
name|virtual
name|bool
name|isAnimating
argument_list|()
specifier|const
block|;
name|void
name|emitAnimatingChanged
argument_list|()
block|;
name|virtual
name|void
name|showInputPanel
argument_list|()
block|;
name|virtual
name|void
name|hideInputPanel
argument_list|()
block|;
name|virtual
name|bool
name|isInputPanelVisible
argument_list|()
specifier|const
block|;
name|void
name|emitInputPanelVisibleChanged
argument_list|()
block|;
name|virtual
name|QLocale
name|locale
argument_list|()
specifier|const
block|;
name|void
name|emitLocaleChanged
argument_list|()
block|;
name|virtual
name|Qt
operator|::
name|LayoutDirection
name|inputDirection
argument_list|()
specifier|const
block|;
name|void
name|emitInputDirectionChanged
argument_list|(
argument|Qt::LayoutDirection newDirection
argument_list|)
block|;
name|virtual
name|void
name|setFocusObject
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|bool
name|inputMethodAccepted
argument_list|()
specifier|const
block|;
name|private
operator|:
name|friend
name|class
name|QGuiApplication
block|;
name|friend
name|class
name|QGuiApplicationPrivate
block|;
name|friend
name|class
name|QInputMethod
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMINPUTCONTEXT_H
end_comment
end_unit
