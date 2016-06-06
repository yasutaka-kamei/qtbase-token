begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrtintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwinrteventdispatcher.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtscreen.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtinputcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtservices.h"
end_include
begin_include
include|#
directive|include
file|"qwinrteglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|"qwinrttheme.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtclipboard.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_include
include|#
directive|include
file|"qwinrtdrag.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtGui/QOffscreenSurface>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QSurface>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglpbuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformoffscreensurface.h>
end_include
begin_include
include|#
directive|include
file|<qfunctions_winrt.h>
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
file|<windows.ui.xaml.h>
end_include
begin_include
include|#
directive|include
file|<windows.applicationmodel.h>
end_include
begin_include
include|#
directive|include
file|<windows.applicationmodel.core.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.core.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.viewmanagement.h>
end_include
begin_include
include|#
directive|include
file|<windows.graphics.display.h>
end_include
begin_if
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
end_if
begin_include
include|#
directive|include
file|<windows.phone.ui.input.h>
end_include
begin_if
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1900
end_if
begin_include
include|#
directive|include
file|<windows.foundation.metadata.h>
end_include
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Metadata
namespace|;
end_using
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
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
name|ApplicationModel
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
operator|::
name|Core
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
name|Graphics
operator|::
name|Display
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
operator|::
name|Core
namespace|;
end_using
begin_if
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
end_if
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Phone
operator|::
name|UI
operator|::
name|Input
namespace|;
end_using
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
DECL|typedef|ResumeHandler
typedef|typedef
name|IEventHandler
argument_list|<
name|IInspectable
modifier|*
argument_list|>
name|ResumeHandler
typedef|;
end_typedef
begin_typedef
DECL|typedef|SuspendHandler
typedef|typedef
name|IEventHandler
argument_list|<
name|SuspendingEventArgs
modifier|*
argument_list|>
name|SuspendHandler
typedef|;
end_typedef
begin_if
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
end_if
begin_typedef
DECL|typedef|BackPressedHandler
typedef|typedef
name|IEventHandler
argument_list|<
name|BackPressedEventArgs
modifier|*
argument_list|>
name|BackPressedHandler
typedef|;
end_typedef
begin_typedef
DECL|typedef|CameraButtonHandler
typedef|typedef
name|IEventHandler
argument_list|<
name|CameraEventArgs
modifier|*
argument_list|>
name|CameraButtonHandler
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|CoreApplicationCallbackRemover
typedef|typedef
name|HRESULT
function_decl|(
name|__stdcall
name|ICoreApplication
operator|::
modifier|*
name|CoreApplicationCallbackRemover
function_decl|)
parameter_list|(
name|EventRegistrationToken
parameter_list|)
function_decl|;
end_typedef
begin_function
DECL|function|qHash
name|uint
name|qHash
parameter_list|(
name|CoreApplicationCallbackRemover
name|key
parameter_list|)
block|{
name|void
modifier|*
name|ptr
init|=
operator|*
operator|(
name|void
operator|*
operator|*
operator|)
operator|(
operator|&
name|key
operator|)
decl_stmt|;
return|return
name|qHash
argument_list|(
name|ptr
argument_list|)
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
begin_typedef
DECL|typedef|HardwareButtonsCallbackRemover
typedef|typedef
name|HRESULT
function_decl|(
name|__stdcall
name|IHardwareButtonsStatics
operator|::
modifier|*
name|HardwareButtonsCallbackRemover
function_decl|)
parameter_list|(
name|EventRegistrationToken
parameter_list|)
function_decl|;
end_typedef
begin_function
DECL|function|qHash
name|uint
name|qHash
parameter_list|(
name|HardwareButtonsCallbackRemover
name|key
parameter_list|)
block|{
name|void
modifier|*
name|ptr
init|=
operator|*
operator|(
name|void
operator|*
operator|*
operator|)
operator|(
operator|&
name|key
operator|)
decl_stmt|;
return|return
name|qHash
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function
begin_typedef
DECL|typedef|HardwareButtons2CallbackRemover
typedef|typedef
name|HRESULT
function_decl|(
name|__stdcall
name|IHardwareButtonsStatics2
operator|::
modifier|*
name|HardwareButtons2CallbackRemover
function_decl|)
parameter_list|(
name|EventRegistrationToken
parameter_list|)
function_decl|;
end_typedef
begin_function
DECL|function|qHash
name|uint
name|qHash
parameter_list|(
name|HardwareButtons2CallbackRemover
name|key
parameter_list|)
block|{
name|void
modifier|*
name|ptr
init|=
operator|*
operator|(
name|void
operator|*
operator|*
operator|)
operator|(
operator|&
name|key
operator|)
decl_stmt|;
return|return
name|qHash
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|QWinRTIntegrationPrivate
class|class
name|QWinRTIntegrationPrivate
block|{
public|public:
DECL|member|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|fontDatabase
decl_stmt|;
DECL|member|platformServices
name|QPlatformServices
modifier|*
name|platformServices
decl_stmt|;
DECL|member|clipboard
name|QPlatformClipboard
modifier|*
name|clipboard
decl_stmt|;
DECL|member|mainScreen
name|QWinRTScreen
modifier|*
name|mainScreen
decl_stmt|;
DECL|member|inputContext
name|QScopedPointer
argument_list|<
name|QWinRTInputContext
argument_list|>
name|inputContext
decl_stmt|;
DECL|member|application
name|ComPtr
argument_list|<
name|ICoreApplication
argument_list|>
name|application
decl_stmt|;
DECL|member|applicationTokens
name|QHash
argument_list|<
name|CoreApplicationCallbackRemover
argument_list|,
name|EventRegistrationToken
argument_list|>
name|applicationTokens
decl_stmt|;
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
DECL|member|hardwareButtons
name|ComPtr
argument_list|<
name|IHardwareButtonsStatics
argument_list|>
name|hardwareButtons
decl_stmt|;
DECL|member|buttonsTokens
name|QHash
argument_list|<
name|HardwareButtonsCallbackRemover
argument_list|,
name|EventRegistrationToken
argument_list|>
name|buttonsTokens
decl_stmt|;
DECL|member|cameraButtons
name|ComPtr
argument_list|<
name|IHardwareButtonsStatics2
argument_list|>
name|cameraButtons
decl_stmt|;
DECL|member|cameraTokens
name|QHash
argument_list|<
name|HardwareButtons2CallbackRemover
argument_list|,
name|EventRegistrationToken
argument_list|>
name|cameraTokens
decl_stmt|;
DECL|member|hasHardwareButtons
name|boolean
name|hasHardwareButtons
decl_stmt|;
name|bool
name|cameraHalfPressed
range|:
literal|1
decl_stmt|;
name|bool
name|cameraPressed
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
class|;
end_class
begin_constructor
DECL|function|QWinRTIntegration
name|QWinRTIntegration
operator|::
name|QWinRTIntegration
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QWinRTIntegrationPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTIntegration
argument_list|)
expr_stmt|;
name|d
operator|->
name|fontDatabase
operator|=
operator|new
name|QWinRTFontDatabase
expr_stmt|;
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_ApplicationModel_Core_CoreApplication
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|d
operator|->
name|application
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|d
operator|->
name|application
operator|->
name|add_Suspending
argument_list|(
name|Callback
argument_list|<
name|SuspendHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTIntegration
operator|::
name|onSuspended
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|d
operator|->
name|applicationTokens
index|[
operator|&
name|ICoreApplication
operator|::
name|remove_Suspending
index|]
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|d
operator|->
name|application
operator|->
name|add_Resuming
argument_list|(
name|Callback
argument_list|<
name|ResumeHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTIntegration
operator|::
name|onResume
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|d
operator|->
name|applicationTokens
index|[
operator|&
name|ICoreApplication
operator|::
name|remove_Resuming
index|]
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1900
name|d
operator|->
name|hasHardwareButtons
operator|=
literal|false
expr_stmt|;
name|ComPtr
argument_list|<
name|IApiInformationStatics
argument_list|>
name|apiInformationStatics
decl_stmt|;
name|hr
operator|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Foundation_Metadata_ApiInformation
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|apiInformationStatics
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
specifier|const
name|HStringReference
name|valueRef
argument_list|(
literal|L"Windows.Phone.UI.Input.HardwareButtons"
argument_list|)
decl_stmt|;
name|hr
operator|=
name|apiInformationStatics
operator|->
name|IsTypePresent
argument_list|(
name|valueRef
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|d
operator|->
name|hasHardwareButtons
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|d
operator|->
name|hasHardwareButtons
operator|=
literal|true
expr_stmt|;
endif|#
directive|endif
comment|// _MSC_VER>= 1900
if|if
condition|(
name|d
operator|->
name|hasHardwareButtons
condition|)
block|{
name|hr
operator|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Phone_UI_Input_HardwareButtons
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|d
operator|->
name|hardwareButtons
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|d
operator|->
name|hardwareButtons
operator|->
name|add_BackPressed
argument_list|(
name|Callback
argument_list|<
name|BackPressedHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTIntegration
operator|::
name|onBackButtonPressed
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|d
operator|->
name|buttonsTokens
index|[
operator|&
name|IHardwareButtonsStatics
operator|::
name|remove_BackPressed
index|]
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Phone_UI_Input_HardwareButtons
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|d
operator|->
name|cameraButtons
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_ENABLE_CAMERA_KEYS"
argument_list|)
condition|)
block|{
name|hr
operator|=
name|d
operator|->
name|cameraButtons
operator|->
name|add_CameraPressed
argument_list|(
name|Callback
argument_list|<
name|CameraButtonHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTIntegration
operator|::
name|onCameraPressed
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|d
operator|->
name|cameraTokens
index|[
operator|&
name|IHardwareButtonsStatics2
operator|::
name|remove_CameraPressed
index|]
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|d
operator|->
name|cameraButtons
operator|->
name|add_CameraHalfPressed
argument_list|(
name|Callback
argument_list|<
name|CameraButtonHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTIntegration
operator|::
name|onCameraHalfPressed
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|d
operator|->
name|cameraTokens
index|[
operator|&
name|IHardwareButtonsStatics2
operator|::
name|remove_CameraHalfPressed
index|]
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|d
operator|->
name|cameraButtons
operator|->
name|add_CameraReleased
argument_list|(
name|Callback
argument_list|<
name|CameraButtonHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|QWinRTIntegration
operator|::
name|onCameraReleased
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|d
operator|->
name|cameraTokens
index|[
operator|&
name|IHardwareButtonsStatics2
operator|::
name|remove_CameraReleased
index|]
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|cameraPressed
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|cameraHalfPressed
operator|=
literal|false
expr_stmt|;
block|}
endif|#
directive|endif
comment|// WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP)
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
name|d
capture|]
parameter_list|()
block|{
name|d
operator|->
name|mainScreen
operator|=
operator|new
name|QWinRTScreen
expr_stmt|;
name|d
operator|->
name|inputContext
operator|.
name|reset
argument_list|(
operator|new
name|QWinRTInputContext
argument_list|(
name|d
operator|->
name|mainScreen
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
argument_list|)
expr_stmt|;
name|screenAdded
argument_list|(
name|d
operator|->
name|mainScreen
argument_list|)
expr_stmt|;
name|d
operator|->
name|platformServices
operator|=
operator|new
name|QWinRTServices
expr_stmt|;
name|d
operator|->
name|clipboard
operator|=
operator|new
name|QWinRTClipboard
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWinRTIntegration
name|QWinRTIntegration
operator|::
name|~
name|QWinRTIntegration
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWinRTIntegration
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
decl_stmt|;
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
if|if
condition|(
name|d
operator|->
name|hasHardwareButtons
condition|)
block|{
for|for
control|(
name|QHash
argument_list|<
name|HardwareButtonsCallbackRemover
argument_list|,
name|EventRegistrationToken
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|d
operator|->
name|buttonsTokens
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|d
operator|->
name|buttonsTokens
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|hr
operator|=
operator|(
name|d
operator|->
name|hardwareButtons
operator|.
name|Get
argument_list|()
operator|->*
name|i
operator|.
name|key
argument_list|()
operator|)
operator|(
name|i
operator|.
name|value
argument_list|()
operator|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|QHash
argument_list|<
name|HardwareButtons2CallbackRemover
argument_list|,
name|EventRegistrationToken
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|d
operator|->
name|cameraTokens
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|d
operator|->
name|cameraTokens
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|hr
operator|=
operator|(
name|d
operator|->
name|cameraButtons
operator|.
name|Get
argument_list|()
operator|->*
name|i
operator|.
name|key
argument_list|()
operator|)
operator|(
name|i
operator|.
name|value
argument_list|()
operator|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
comment|// Do not execute this on Windows Phone as the application is already
comment|// shutting down and trying to unregister suspending/resume handler will
comment|// cause exceptions and assert in debug mode
ifndef|#
directive|ifndef
name|Q_OS_WINPHONE
for|for
control|(
name|QHash
argument_list|<
name|CoreApplicationCallbackRemover
argument_list|,
name|EventRegistrationToken
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|d
operator|->
name|applicationTokens
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|d
operator|->
name|applicationTokens
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|hr
operator|=
operator|(
name|d
operator|->
name|application
operator|.
name|Get
argument_list|()
operator|->*
name|i
operator|.
name|key
argument_list|()
operator|)
operator|(
name|i
operator|.
name|value
argument_list|()
operator|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|destroyScreen
argument_list|(
name|d
operator|->
name|mainScreen
argument_list|)
expr_stmt|;
name|Windows
operator|::
name|Foundation
operator|::
name|Uninitialize
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|succeeded
name|bool
name|QWinRTIntegration
operator|::
name|succeeded
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTIntegration
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|mainScreen
return|;
block|}
end_function
begin_function
DECL|function|createEventDispatcher
name|QAbstractEventDispatcher
modifier|*
name|QWinRTIntegration
operator|::
name|createEventDispatcher
parameter_list|()
specifier|const
block|{
return|return
operator|new
name|QWinRTEventDispatcher
return|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|QWinRTIntegration
operator|::
name|initialize
parameter_list|()
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTIntegration
argument_list|)
expr_stmt|;
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
name|d
capture|]
parameter_list|()
block|{
name|d
operator|->
name|mainScreen
operator|->
name|initialize
argument_list|()
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
DECL|function|hasCapability
name|bool
name|QWinRTIntegration
operator|::
name|hasCapability
parameter_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
parameter_list|)
specifier|const
block|{
switch|switch
condition|(
name|cap
condition|)
block|{
case|case
name|ThreadedPixmaps
case|:
case|case
name|OpenGL
case|:
case|case
name|ApplicationState
case|:
case|case
name|NonFullScreenWindows
case|:
case|case
name|MultipleWindows
case|:
case|case
name|RasterGLSurface
case|:
return|return
literal|true
return|;
default|default:
return|return
name|QPlatformIntegration
operator|::
name|hasCapability
argument_list|(
name|cap
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|styleHint
name|QVariant
name|QWinRTIntegration
operator|::
name|styleHint
parameter_list|(
name|StyleHint
name|hint
parameter_list|)
specifier|const
block|{
return|return
name|QWinRTTheme
operator|::
name|styleHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformWindow
name|QPlatformWindow
modifier|*
name|QWinRTIntegration
operator|::
name|createPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QWinRTWindow
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformBackingStore
name|QPlatformBackingStore
modifier|*
name|QWinRTIntegration
operator|::
name|createPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QWinRTBackingStore
argument_list|(
name|window
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOpenGLContext
name|QPlatformOpenGLContext
modifier|*
name|QWinRTIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QWinRTEGLContext
argument_list|(
name|context
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fontDatabase
name|QPlatformFontDatabase
modifier|*
name|QWinRTIntegration
operator|::
name|fontDatabase
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTIntegration
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|fontDatabase
return|;
block|}
end_function
begin_function
DECL|function|inputContext
name|QPlatformInputContext
modifier|*
name|QWinRTIntegration
operator|::
name|inputContext
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTIntegration
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|inputContext
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|services
name|QPlatformServices
modifier|*
name|QWinRTIntegration
operator|::
name|services
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTIntegration
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformServices
return|;
block|}
end_function
begin_function
DECL|function|clipboard
name|QPlatformClipboard
modifier|*
name|QWinRTIntegration
operator|::
name|clipboard
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTIntegration
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|clipboard
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
end_ifndef
begin_function
DECL|function|drag
name|QPlatformDrag
modifier|*
name|QWinRTIntegration
operator|::
name|drag
parameter_list|()
specifier|const
block|{
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1900
return|return
name|QWinRTDrag
operator|::
name|instance
argument_list|()
return|;
else|#
directive|else
return|return
name|QPlatformIntegration
operator|::
name|drag
argument_list|()
return|;
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DRAGANDDROP
end_comment
begin_function
DECL|function|queryKeyboardModifiers
name|Qt
operator|::
name|KeyboardModifiers
name|QWinRTIntegration
operator|::
name|queryKeyboardModifiers
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTIntegration
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|mainScreen
operator|->
name|keyboardModifiers
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|themeNames
name|QStringList
name|QWinRTIntegration
operator|::
name|themeNames
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|QLatin1String
argument_list|(
literal|"winrt"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|createPlatformTheme
name|QPlatformTheme
modifier|*
name|QWinRTIntegration
operator|::
name|createPlatformTheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"winrt"
argument_list|)
condition|)
return|return
operator|new
name|QWinRTTheme
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|// System-level integration points
end_comment
begin_if
if|#
directive|if
name|WINAPI_FAMILY_PARTITION
argument_list|(
name|WINAPI_PARTITION_PHONE_APP
argument_list|)
end_if
begin_function
DECL|function|onBackButtonPressed
name|HRESULT
name|QWinRTIntegration
operator|::
name|onBackButtonPressed
parameter_list|(
name|IInspectable
modifier|*
parameter_list|,
name|IBackPressedEventArgs
modifier|*
name|args
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTIntegration
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|window
init|=
name|d
operator|->
name|mainScreen
operator|->
name|topWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|setSynchronousWindowSystemEvents
argument_list|(
literal|true
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|pressed
init|=
name|QWindowSystemInterface
operator|::
name|handleExtendedKeyEvent
argument_list|(
name|window
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Back
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|false
argument_list|,
literal|1
argument_list|,
literal|false
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|released
init|=
name|QWindowSystemInterface
operator|::
name|handleExtendedKeyEvent
argument_list|(
name|window
argument_list|,
name|QEvent
operator|::
name|KeyRelease
argument_list|,
name|Qt
operator|::
name|Key_Back
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|false
argument_list|,
literal|1
argument_list|,
literal|false
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|setSynchronousWindowSystemEvents
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|args
operator|->
name|put_Handled
argument_list|(
name|pressed
operator|||
name|released
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
end_function
begin_function
DECL|function|onCameraPressed
name|HRESULT
name|QWinRTIntegration
operator|::
name|onCameraPressed
parameter_list|(
name|IInspectable
modifier|*
parameter_list|,
name|ICameraEventArgs
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTIntegration
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|window
init|=
name|d
operator|->
name|mainScreen
operator|->
name|topWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleExtendedKeyEvent
argument_list|(
name|window
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Camera
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|false
argument_list|,
literal|1
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|d
operator|->
name|cameraPressed
operator|=
literal|true
expr_stmt|;
return|return
name|S_OK
return|;
block|}
end_function
begin_function
DECL|function|onCameraHalfPressed
name|HRESULT
name|QWinRTIntegration
operator|::
name|onCameraHalfPressed
parameter_list|(
name|IInspectable
modifier|*
parameter_list|,
name|ICameraEventArgs
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTIntegration
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|window
init|=
name|d
operator|->
name|mainScreen
operator|->
name|topWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleExtendedKeyEvent
argument_list|(
name|window
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_CameraFocus
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|false
argument_list|,
literal|1
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|d
operator|->
name|cameraHalfPressed
operator|=
literal|true
expr_stmt|;
return|return
name|S_OK
return|;
block|}
end_function
begin_function
DECL|function|onCameraReleased
name|HRESULT
name|QWinRTIntegration
operator|::
name|onCameraReleased
parameter_list|(
name|IInspectable
modifier|*
parameter_list|,
name|ICameraEventArgs
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTIntegration
argument_list|)
expr_stmt|;
name|QWindow
modifier|*
name|window
init|=
name|d
operator|->
name|mainScreen
operator|->
name|topWindow
argument_list|()
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|cameraHalfPressed
condition|)
name|QWindowSystemInterface
operator|::
name|handleExtendedKeyEvent
argument_list|(
name|window
argument_list|,
name|QEvent
operator|::
name|KeyRelease
argument_list|,
name|Qt
operator|::
name|Key_CameraFocus
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|false
argument_list|,
literal|1
argument_list|,
literal|false
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|cameraPressed
condition|)
name|QWindowSystemInterface
operator|::
name|handleExtendedKeyEvent
argument_list|(
name|window
argument_list|,
name|QEvent
operator|::
name|KeyRelease
argument_list|,
name|Qt
operator|::
name|Key_Camera
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|QString
argument_list|()
argument_list|,
literal|false
argument_list|,
literal|1
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|d
operator|->
name|cameraHalfPressed
operator|=
literal|false
expr_stmt|;
name|d
operator|->
name|cameraPressed
operator|=
literal|false
expr_stmt|;
return|return
name|S_OK
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP)
end_comment
begin_function
DECL|function|onSuspended
name|HRESULT
name|QWinRTIntegration
operator|::
name|onSuspended
parameter_list|(
name|IInspectable
modifier|*
parameter_list|,
name|ISuspendingEventArgs
modifier|*
parameter_list|)
block|{
name|QWindowSystemInterface
operator|::
name|handleApplicationStateChanged
argument_list|(
name|Qt
operator|::
name|ApplicationSuspended
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|flushWindowSystemEvents
argument_list|()
expr_stmt|;
return|return
name|S_OK
return|;
block|}
end_function
begin_function
DECL|function|onResume
name|HRESULT
name|QWinRTIntegration
operator|::
name|onResume
parameter_list|(
name|IInspectable
modifier|*
parameter_list|,
name|IInspectable
modifier|*
parameter_list|)
block|{
comment|// First the system invokes onResume and then changes
comment|// the visibility of the screen to be active.
name|QWindowSystemInterface
operator|::
name|handleApplicationStateChanged
argument_list|(
name|Qt
operator|::
name|ApplicationHidden
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOffscreenSurface
name|QPlatformOffscreenSurface
modifier|*
name|QWinRTIntegration
operator|::
name|createPlatformOffscreenSurface
parameter_list|(
name|QOffscreenSurface
modifier|*
name|surface
parameter_list|)
specifier|const
block|{
name|QEGLPbuffer
modifier|*
name|pbuffer
init|=
literal|nullptr
decl_stmt|;
name|HRESULT
name|hr
init|=
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
modifier|&
name|pbuffer
capture|,
name|surface
capture|]
parameter_list|()
block|{
name|pbuffer
operator|=
operator|new
name|QEGLPbuffer
argument_list|(
name|QWinRTEGLContext
operator|::
name|display
argument_list|()
argument_list|,
name|surface
operator|->
name|requestedFormat
argument_list|()
argument_list|,
name|surface
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
argument_list|)
decl_stmt|;
if|if
condition|(
name|hr
operator|==
name|UI_E_WINDOW_CLOSED
condition|)
block|{
comment|// This is only used for shutdown of applications.
comment|// In case we do not return an empty surface the scenegraph will try
comment|// to create a new native window during application exit causing crashes
comment|// or assertions.
return|return
operator|new
name|QPlatformOffscreenSurface
argument_list|(
name|surface
argument_list|)
return|;
block|}
return|return
name|pbuffer
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
