begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINRTINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|QWINRTINPUTCONTEXT_H
define|#
directive|define
name|QWINRTINPUTCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRectF>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLoggingCategory>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_decl_stmt
name|namespace
name|ABI
block|{
name|namespace
name|Windows
block|{
name|namespace
name|UI
block|{
name|namespace
name|Core
block|{
struct_decl|struct
name|ICoreWindow
struct_decl|;
block|}
name|namespace
name|ViewManagement
block|{
struct_decl|struct
name|IInputPane
struct_decl|;
struct_decl|struct
name|IInputPaneVisibilityEventArgs
struct_decl|;
block|}
block|}
block|}
block|}
end_decl_stmt
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_DECLARE_LOGGING_CATEGORY
argument_list|(
name|lcQpaInputMethods
argument_list|)
name|class
name|QWinRTScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWinRTInputContext
range|:
name|public
name|QPlatformInputContext
block|{
name|public
operator|:
name|explicit
name|QWinRTInputContext
argument_list|(
name|QWinRTScreen
operator|*
argument_list|)
block|;
name|QRectF
name|keyboardRect
argument_list|()
specifier|const
block|;
name|bool
name|isInputPanelVisible
argument_list|()
specifier|const
block|;
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
name|void
name|showInputPanel
argument_list|()
block|;
name|void
name|hideInputPanel
argument_list|()
block|;
endif|#
directive|endif
name|private
operator|:
name|HRESULT
name|onShowing
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
operator|::
name|IInputPane
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
operator|::
name|IInputPaneVisibilityEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onHiding
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
operator|::
name|IInputPane
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
operator|::
name|IInputPaneVisibilityEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|handleVisibilityChange
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
operator|::
name|IInputPane
operator|*
argument_list|)
block|;
name|QWinRTScreen
operator|*
name|m_screen
block|;
name|QRectF
name|m_keyboardRect
block|;
name|bool
name|m_isInputPanelVisible
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
comment|// QWINRTINPUTCONTEXT_H
end_comment
end_unit
