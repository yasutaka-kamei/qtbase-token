begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|QWINDOWSINPUTCONTEXT_H
define|#
directive|define
name|QWINDOWSINPUTCONTEXT_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QPointer>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QInputMethodEvent
name|class
name|QInputMethodEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindowsWindow
name|class
name|QWindowsWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWindowsInputContext
range|:
name|public
name|QPlatformInputContext
block|{
name|Q_OBJECT
expr|struct
name|CompositionContext
block|{
name|CompositionContext
argument_list|()
block|;
name|HWND
name|hwnd
block|;
name|bool
name|haveCaret
block|;
name|QString
name|composition
block|;
name|int
name|position
block|;
name|bool
name|isComposing
block|;
name|QPointer
operator|<
name|QObject
operator|>
name|focusObject
block|;     }
block|;
name|public
operator|:
name|explicit
name|QWindowsInputContext
argument_list|()
block|;
operator|~
name|QWindowsInputContext
argument_list|()
block|;
specifier|static
name|void
name|setWindowsImeEnabled
argument_list|(
argument|QWindowsWindow *platformWindow
argument_list|,
argument|bool enabled
argument_list|)
block|;
name|bool
name|hasCapability
argument_list|(
argument|Capability capability
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|reset
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|update
argument_list|(
argument|Qt::InputMethodQueries
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|invokeAction
argument_list|(
argument|QInputMethod::Action
argument_list|,
argument|int cursorPosition
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setFocusObject
argument_list|(
argument|QObject *object
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|startComposition
argument_list|(
argument|HWND hwnd
argument_list|)
block|;
name|bool
name|composition
argument_list|(
argument|HWND hwnd
argument_list|,
argument|LPARAM lParam
argument_list|)
block|;
name|bool
name|endComposition
argument_list|(
argument|HWND hwnd
argument_list|)
block|;
specifier|inline
name|bool
name|isComposing
argument_list|()
specifier|const
block|{
return|return
name|m_compositionContext
operator|.
name|isComposing
return|;
block|}
name|int
name|reconvertString
argument_list|(
name|RECONVERTSTRING
operator|*
name|reconv
argument_list|)
block|;
name|bool
name|handleIME_Request
argument_list|(
argument|WPARAM wparam
argument_list|,
argument|LPARAM lparam
argument_list|,
argument|LRESULT *result
argument_list|)
block|;
name|private
name|slots
operator|:
name|void
name|cursorRectChanged
argument_list|()
block|;
name|private
operator|:
name|void
name|initContext
argument_list|(
argument|HWND hwnd
argument_list|,
argument|QObject *focusObject
argument_list|)
block|;
name|void
name|doneContext
argument_list|()
block|;
name|void
name|startContextComposition
argument_list|()
block|;
name|void
name|endContextComposition
argument_list|()
block|;
name|void
name|updateEnabled
argument_list|()
block|;
specifier|const
name|DWORD
name|m_WM_MSIME_MOUSE
block|;
specifier|static
name|HIMC
name|m_defaultContext
block|;
name|CompositionContext
name|m_compositionContext
block|;
name|bool
name|m_endCompositionRecursionGuard
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
comment|// QWINDOWSINPUTCONTEXT_H
end_comment
end_unit
