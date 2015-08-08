begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// InspectableNativeWindow.h: Host specific implementation interface for
end_comment
begin_comment
comment|// managing IInspectable native window types.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_D3D_D3D11_WINRT_INSPECTABLENATIVEWINDOW_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_D3D_D3D11_WINRT_INSPECTABLENATIVEWINDOW_H_
define|#
directive|define
name|LIBANGLE_RENDERER_D3D_D3D11_WINRT_INSPECTABLENATIVEWINDOW_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/NativeWindow.h"
end_include
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_include
include|#
directive|include
file|"angle_windowsstore.h"
end_include
begin_include
include|#
directive|include
file|<windows.ui.xaml.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.xaml.media.dxinterop.h>
end_include
begin_expr_stmt
DECL|member|WRL
name|using
name|namespace
name|Microsoft
operator|::
name|WRL
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|member|Wrappers
name|using
name|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|member|Foundation
name|using
name|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|member|Collections
name|using
name|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Collections
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|namespace
name|rx
block|{
name|long
name|ConvertDipsToPixels
parameter_list|(
name|float
name|dips
parameter_list|)
function_decl|;
name|class
name|InspectableNativeWindow
block|{
name|public
label|:
name|InspectableNativeWindow
argument_list|()
operator|:
name|mSupportsSwapChainResize
argument_list|(
name|true
argument_list|)
operator|,
name|mRequiresSwapChainScaling
argument_list|(
name|false
argument_list|)
operator|,
name|mClientRectChanged
argument_list|(
name|false
argument_list|)
operator|,
name|mClientRect
argument_list|(
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
argument_list|)
operator|,
name|mNewClientRect
argument_list|(
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
argument_list|)
operator|,
name|mRotationFlags
argument_list|(
argument|NativeWindow::RotateNone
argument_list|)
block|{
name|mSizeChangedEventToken
operator|.
name|value
operator|=
literal|0
block|;     }
name|virtual
operator|~
name|InspectableNativeWindow
argument_list|()
block|{}
name|virtual
name|bool
name|initialize
argument_list|(
argument|EGLNativeWindowType window
argument_list|,
argument|IPropertySet *propertySet
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|HRESULT
name|createSwapChain
parameter_list|(
name|ID3D11Device
modifier|*
name|device
parameter_list|,
name|DXGIFactory
modifier|*
name|factory
parameter_list|,
name|DXGI_FORMAT
name|format
parameter_list|,
name|unsigned
name|int
name|width
parameter_list|,
name|unsigned
name|int
name|height
parameter_list|,
name|DXGISwapChain
modifier|*
modifier|*
name|swapChain
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|registerForSizeChangeEvents
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|unregisterForSizeChangeEvents
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|HRESULT
name|scaleSwapChain
parameter_list|(
specifier|const
name|Size
modifier|&
name|newSize
parameter_list|)
block|{
return|return
name|S_OK
return|;
block|}
name|bool
name|getClientRect
parameter_list|(
name|RECT
modifier|*
name|rect
parameter_list|)
block|{
if|if
condition|(
name|mClientRectChanged
operator|&&
name|mSupportsSwapChainResize
condition|)
block|{
name|mClientRect
operator|=
name|mNewClientRect
expr_stmt|;
block|}
operator|*
name|rect
operator|=
name|mClientRect
expr_stmt|;
return|return
name|true
return|;
block|}
name|void
name|setNewClientSize
parameter_list|(
specifier|const
name|Size
modifier|&
name|newSize
parameter_list|)
block|{
if|if
condition|(
name|mSupportsSwapChainResize
condition|)
block|{
name|mNewClientRect
operator|=
block|{
literal|0
block|,
literal|0
block|,
name|ConvertDipsToPixels
argument_list|(
name|newSize
operator|.
name|Width
argument_list|)
block|,
name|ConvertDipsToPixels
argument_list|(
argument|newSize.Height
argument_list|)
block|}
expr_stmt|;
name|mClientRectChanged
operator|=
name|true
expr_stmt|;
block|}
if|if
condition|(
name|mRequiresSwapChainScaling
condition|)
block|{
name|scaleSwapChain
argument_list|(
name|newSize
argument_list|)
expr_stmt|;
block|}
block|}
name|NativeWindow
operator|::
name|RotationFlags
name|rotationFlags
argument_list|()
specifier|const
block|{
return|return
name|mRotationFlags
return|;
block|}
name|void
name|setRotationFlags
argument_list|(
name|NativeWindow
operator|::
name|RotationFlags
name|flags
argument_list|)
block|{
name|mRotationFlags
operator|=
name|flags
expr_stmt|;
block|}
name|protected
label|:
name|bool
name|mSupportsSwapChainResize
decl_stmt|;
name|bool
name|mRequiresSwapChainScaling
decl_stmt|;
name|RECT
name|mClientRect
decl_stmt|;
name|RECT
name|mNewClientRect
decl_stmt|;
name|bool
name|mClientRectChanged
decl_stmt|;
name|NativeWindow
operator|::
name|RotationFlags
name|mRotationFlags
expr_stmt|;
name|EventRegistrationToken
name|mSizeChangedEventToken
decl_stmt|;
block|}
empty_stmt|;
name|bool
name|IsValidEGLNativeWindowType
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
function_decl|;
name|bool
name|IsCoreWindow
argument_list|(
name|EGLNativeWindowType
name|window
argument_list|,
name|ComPtr
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|>
operator|*
name|coreWindow
operator|=
name|nullptr
argument_list|)
decl_stmt|;
name|bool
name|IsSwapChainPanel
argument_list|(
name|EGLNativeWindowType
name|window
argument_list|,
name|ComPtr
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Xaml
operator|::
name|Controls
operator|::
name|ISwapChainPanel
operator|>
operator|*
name|swapChainPanel
operator|=
name|nullptr
argument_list|)
decl_stmt|;
name|bool
name|IsEGLConfiguredPropertySet
argument_list|(
name|EGLNativeWindowType
name|window
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Collections
operator|::
name|IPropertySet
operator|*
operator|*
name|propertySet
operator|=
name|nullptr
argument_list|,
name|IInspectable
operator|*
operator|*
name|inspectable
operator|=
name|nullptr
argument_list|)
decl_stmt|;
name|HRESULT
name|GetOptionalSizePropertyValue
argument_list|(
specifier|const
name|ComPtr
operator|<
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Collections
operator|::
name|IMap
operator|<
name|HSTRING
argument_list|,
name|IInspectable
operator|*
operator|>>
operator|&
name|propertyMap
argument_list|,
specifier|const
name|wchar_t
operator|*
name|propertyName
argument_list|,
name|SIZE
operator|*
name|value
argument_list|,
name|bool
operator|*
name|valueExists
argument_list|)
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_D3D_D3D11_WINRT_INSPECTABLENATIVEWINDOW_H_
end_comment
end_unit
