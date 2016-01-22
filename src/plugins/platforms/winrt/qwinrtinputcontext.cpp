begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrtinputcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<private/qeventdispatcher_winrt_p.h>
end_include
begin_include
include|#
directive|include
file|<functional>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<roapi.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.viewmanagement.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.core.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
namespace|;
end_using
begin_typedef
DECL|typedef|InputPaneVisibilityHandler
typedef|typedef
name|ITypedEventHandler
argument_list|<
name|InputPane
modifier|*
argument_list|,
name|InputPaneVisibilityEventArgs
modifier|*
argument_list|>
name|InputPaneVisibilityHandler
typedef|;
end_typedef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|lcQpaInputMethods
argument_list|,
literal|"qt.qpa.input.methods"
argument_list|)
DECL|function|getInputPaneRect
specifier|inline
namespace|QRectF
name|getInputPaneRect
namespace|(
name|IInputPane
modifier|*
name|pane
operator|,
name|qreal
name|scaleFactor
decl_stmt|)
block|{
name|Rect
name|rect
decl_stmt|;
name|pane
operator|->
name|get_OccludedRect
argument_list|(
operator|&
name|rect
argument_list|)
expr_stmt|;
return|return
name|QRectF
argument_list|(
name|qRound
argument_list|(
name|rect
operator|.
name|X
operator|*
name|scaleFactor
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|rect
operator|.
name|Y
operator|*
name|scaleFactor
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|rect
operator|.
name|Width
operator|*
name|scaleFactor
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|rect
operator|.
name|Height
operator|*
name|scaleFactor
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_comment
comment|/*!     \class QWinRTInputContext     \brief Manages Input Method visibility     \internal     \ingroup qt-qpa-winrt      Listens to the native virtual keyboard for hide/show events and provides     hints to the OS for showing/hiding. On WinRT, showInputPanel()/hideInputPanel()     have no effect because WinRT dictates that keyboard presence is user-driven:     (http://msdn.microsoft.com/en-us/library/windows/apps/hh465404.aspx)     Windows Phone, however, supports direct hiding/showing of the keyboard. */
end_comment
begin_constructor
DECL|function|QWinRTInputContext
name|QWinRTInputContext
operator|::
name|QWinRTInputContext
parameter_list|(
name|QWinRTScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|m_screen
argument_list|(
name|screen
argument_list|)
block|{
name|qCDebug
argument_list|(
name|lcQpaInputMethods
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|screen
expr_stmt|;
name|IInputPaneStatics
modifier|*
name|statics
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_UI_ViewManagement_InputPane
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|statics
argument_list|)
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to retrieve input pane statics."
argument_list|)
expr_stmt|;
return|return;
block|}
name|IInputPane
modifier|*
name|inputPane
decl_stmt|;
name|statics
operator|->
name|GetForCurrentView
argument_list|(
operator|&
name|inputPane
argument_list|)
expr_stmt|;
name|statics
operator|->
name|Release
argument_list|()
expr_stmt|;
if|if
condition|(
name|inputPane
condition|)
block|{
name|EventRegistrationToken
name|showToken
decl_stmt|,
name|hideToken
decl_stmt|;
name|inputPane
operator|->
name|add_Showing
argument_list|(
name|Callback
argument_list|<
name|InputPaneVisibilityHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTInputContext
operator|::
name|onShowing
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|showToken
argument_list|)
expr_stmt|;
name|inputPane
operator|->
name|add_Hiding
argument_list|(
name|Callback
argument_list|<
name|InputPaneVisibilityHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTInputContext
operator|::
name|onHiding
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|hideToken
argument_list|)
expr_stmt|;
name|m_keyboardRect
operator|=
name|getInputPaneRect
argument_list|(
name|inputPane
argument_list|,
name|m_screen
operator|->
name|scaleFactor
argument_list|()
argument_list|)
expr_stmt|;
name|m_isInputPanelVisible
operator|=
operator|!
name|m_keyboardRect
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"failed to retrieve InputPane."
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_function
DECL|function|keyboardRect
name|QRectF
name|QWinRTInputContext
operator|::
name|keyboardRect
parameter_list|()
specifier|const
block|{
return|return
name|m_keyboardRect
return|;
block|}
end_function
begin_function
DECL|function|isInputPanelVisible
name|bool
name|QWinRTInputContext
operator|::
name|isInputPanelVisible
parameter_list|()
specifier|const
block|{
return|return
name|m_isInputPanelVisible
return|;
block|}
end_function
begin_function
DECL|function|onShowing
name|HRESULT
name|QWinRTInputContext
operator|::
name|onShowing
parameter_list|(
name|IInputPane
modifier|*
name|pane
parameter_list|,
name|IInputPaneVisibilityEventArgs
modifier|*
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|lcQpaInputMethods
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|pane
expr_stmt|;
name|m_isInputPanelVisible
operator|=
literal|true
expr_stmt|;
name|emitInputPanelVisibleChanged
argument_list|()
expr_stmt|;
return|return
name|handleVisibilityChange
argument_list|(
name|pane
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|onHiding
name|HRESULT
name|QWinRTInputContext
operator|::
name|onHiding
parameter_list|(
name|IInputPane
modifier|*
name|pane
parameter_list|,
name|IInputPaneVisibilityEventArgs
modifier|*
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|lcQpaInputMethods
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|pane
expr_stmt|;
name|m_isInputPanelVisible
operator|=
literal|false
expr_stmt|;
name|emitInputPanelVisibleChanged
argument_list|()
expr_stmt|;
return|return
name|handleVisibilityChange
argument_list|(
name|pane
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|handleVisibilityChange
name|HRESULT
name|QWinRTInputContext
operator|::
name|handleVisibilityChange
parameter_list|(
name|IInputPane
modifier|*
name|pane
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|lcQpaInputMethods
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|pane
expr_stmt|;
specifier|const
name|QRectF
name|keyboardRect
init|=
name|getInputPaneRect
argument_list|(
name|pane
argument_list|,
name|m_screen
operator|->
name|scaleFactor
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_keyboardRect
operator|!=
name|keyboardRect
condition|)
block|{
name|m_keyboardRect
operator|=
name|keyboardRect
expr_stmt|;
name|emitKeyboardRectChanged
argument_list|()
expr_stmt|;
block|}
return|return
name|S_OK
return|;
block|}
end_function
begin_if
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
end_if
begin_function
DECL|function|getInputPane
specifier|static
name|HRESULT
name|getInputPane
parameter_list|(
name|ComPtr
argument_list|<
name|IInputPane2
argument_list|>
modifier|*
name|inputPane2
parameter_list|)
block|{
name|ComPtr
argument_list|<
name|IInputPaneStatics
argument_list|>
name|factory
decl_stmt|;
name|HRESULT
name|hr
init|=
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_UI_ViewManagement_InputPane
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|factory
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to get input pane factory."
argument_list|)
expr_stmt|;
return|return
name|hr
return|;
block|}
name|ComPtr
argument_list|<
name|IInputPane
argument_list|>
name|inputPane
decl_stmt|;
name|hr
operator|=
name|factory
operator|->
name|GetForCurrentView
argument_list|(
operator|&
name|inputPane
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to get input pane."
argument_list|)
expr_stmt|;
return|return
name|hr
return|;
block|}
name|hr
operator|=
name|inputPane
operator|.
name|As
argument_list|(
name|inputPane2
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to get extended input pane."
argument_list|)
expr_stmt|;
return|return
name|hr
return|;
block|}
return|return
name|hr
return|;
block|}
end_function
begin_function
DECL|function|showInputPanel
name|void
name|QWinRTInputContext
operator|::
name|showInputPanel
parameter_list|()
block|{
name|qCDebug
argument_list|(
name|lcQpaInputMethods
argument_list|)
operator|<<
name|__FUNCTION__
expr_stmt|;
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
modifier|&
capture|]
parameter_list|()
block|{
name|ComPtr
argument_list|<
name|IInputPane2
argument_list|>
name|inputPane
decl_stmt|;
name|HRESULT
name|hr
type|=
name|getInputPane
type|(
modifier|&
name|inputPane
decl_stmt|);
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
return|return
name|S_OK
return|;
name|boolean
name|success
decl_stmt|;
name|hr
operator|=
name|inputPane
operator|->
name|TryShow
argument_list|(
operator|&
name|success
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
operator|||
operator|!
name|success
condition|)
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to show input panel."
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hideInputPanel
name|void
name|QWinRTInputContext
operator|::
name|hideInputPanel
parameter_list|()
block|{
name|qCDebug
argument_list|(
name|lcQpaInputMethods
argument_list|)
operator|<<
name|__FUNCTION__
expr_stmt|;
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
modifier|&
capture|]
parameter_list|()
block|{
name|ComPtr
argument_list|<
name|IInputPane2
argument_list|>
name|inputPane
decl_stmt|;
name|HRESULT
name|hr
type|=
name|getInputPane
type|(
modifier|&
name|inputPane
decl_stmt|);
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
return|return
name|S_OK
return|;
name|boolean
name|success
decl_stmt|;
name|hr
operator|=
name|inputPane
operator|->
name|TryHide
argument_list|(
operator|&
name|success
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
operator|||
operator|!
name|success
condition|)
name|qErrnoWarning
argument_list|(
name|hr
argument_list|,
literal|"Failed to hide input panel."
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP)
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
