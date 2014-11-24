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
comment|// SwapChainPanelNativeWindow.cpp: NativeWindow for managing ISwapChainPanel native window types.
end_comment
begin_include
include|#
directive|include
file|"common/winrt/SwapChainPanelNativeWindow.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|<math.h>
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
name|Collections
namespace|;
end_using
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|~SwapChainPanelNativeWindow
name|SwapChainPanelNativeWindow
operator|::
name|~
name|SwapChainPanelNativeWindow
parameter_list|()
block|{
name|unregisterForSizeChangeEvents
argument_list|()
expr_stmt|;
block|}
DECL|function|initialize
name|bool
name|SwapChainPanelNativeWindow
operator|::
name|initialize
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|,
name|EGLNativeDisplayType
name|display
parameter_list|,
name|IPropertySet
modifier|*
name|propertySet
parameter_list|)
block|{
name|ComPtr
argument_list|<
name|IPropertySet
argument_list|>
name|props
init|=
name|propertySet
decl_stmt|;
name|ComPtr
argument_list|<
name|IInspectable
argument_list|>
name|win
init|=
name|window
decl_stmt|;
name|SIZE
name|swapChainSize
init|=
block|{}
decl_stmt|;
name|bool
name|swapChainSizeSpecified
init|=
literal|false
decl_stmt|;
name|HRESULT
name|result
init|=
name|S_OK
decl_stmt|;
comment|// IPropertySet is an optional parameter and can be null.
comment|// If one is specified, cache as an IMap and read the properties
comment|// used for initial host initialization.
if|if
condition|(
name|propertySet
condition|)
block|{
name|result
operator|=
name|props
operator|.
name|As
argument_list|(
operator|&
name|mPropertyMap
argument_list|)
expr_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
comment|// The EGLRenderSurfaceSizeProperty is optional and may be missing.  The IPropertySet
comment|// was prevalidated to contain the EGLNativeWindowType before being passed to
comment|// this host.
name|result
operator|=
name|GetOptionalSizePropertyValue
argument_list|(
name|mPropertyMap
argument_list|,
name|EGLRenderSurfaceSizeProperty
argument_list|,
operator|&
name|swapChainSize
argument_list|,
operator|&
name|swapChainSizeSpecified
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|result
operator|=
name|win
operator|.
name|As
argument_list|(
operator|&
name|mSwapChainPanel
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
comment|// If a swapchain size is specfied, then the automatic resize
comment|// behaviors implemented by the host should be disabled.  The swapchain
comment|// will be still be scaled when being rendered to fit the bounds
comment|// of the host.
comment|// Scaling of the swapchain output needs to be handled by the
comment|// host for swapchain panels even though the scaling mode setting
comment|// DXGI_SCALING_STRETCH is configured on the swapchain.
if|if
condition|(
name|swapChainSizeSpecified
condition|)
block|{
name|mClientRect
operator|=
block|{
literal|0
block|,
literal|0
block|,
name|swapChainSize
operator|.
name|cx
block|,
name|swapChainSize
operator|.
name|cy
block|}
expr_stmt|;
comment|// Enable host swapchain scaling
name|mRequiresSwapChainScaling
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|result
operator|=
name|GetSwapChainPanelSize
argument_list|(
name|mSwapChainPanel
argument_list|,
operator|&
name|mClientRect
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|mNewClientRect
operator|=
name|mClientRect
expr_stmt|;
name|mClientRectChanged
operator|=
literal|false
expr_stmt|;
return|return
name|registerForSizeChangeEvents
argument_list|()
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|registerForSizeChangeEvents
name|bool
name|SwapChainPanelNativeWindow
operator|::
name|registerForSizeChangeEvents
parameter_list|()
block|{
name|ComPtr
argument_list|<
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Xaml
operator|::
name|ISizeChangedEventHandler
argument_list|>
name|sizeChangedHandler
decl_stmt|;
name|ComPtr
argument_list|<
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Xaml
operator|::
name|IFrameworkElement
argument_list|>
name|frameworkElement
decl_stmt|;
name|HRESULT
name|result
init|=
name|Microsoft
operator|::
name|WRL
operator|::
name|MakeAndInitialize
argument_list|<
name|SwapChainPanelSizeChangedHandler
argument_list|>
argument_list|(
name|sizeChangedHandler
operator|.
name|ReleaseAndGetAddressOf
argument_list|()
argument_list|,
name|this
operator|->
name|shared_from_this
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|result
operator|=
name|mSwapChainPanel
operator|.
name|As
argument_list|(
operator|&
name|frameworkElement
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|result
operator|=
name|frameworkElement
operator|->
name|add_SizeChanged
argument_list|(
name|sizeChangedHandler
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|mSizeChangedEventToken
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
DECL|function|unregisterForSizeChangeEvents
name|void
name|SwapChainPanelNativeWindow
operator|::
name|unregisterForSizeChangeEvents
parameter_list|()
block|{
name|ComPtr
argument_list|<
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Xaml
operator|::
name|IFrameworkElement
argument_list|>
name|frameworkElement
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|mSwapChainPanel
operator|.
name|As
argument_list|(
operator|&
name|frameworkElement
argument_list|)
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|frameworkElement
operator|->
name|remove_SizeChanged
argument_list|(
name|mSizeChangedEventToken
argument_list|)
expr_stmt|;
block|}
name|mSizeChangedEventToken
operator|.
name|value
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|createSwapChain
name|HRESULT
name|SwapChainPanelNativeWindow
operator|::
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
block|{
if|if
condition|(
name|device
operator|==
name|NULL
operator|||
name|factory
operator|==
name|NULL
operator|||
name|swapChain
operator|==
name|NULL
operator|||
name|width
operator|==
literal|0
operator|||
name|height
operator|==
literal|0
condition|)
block|{
return|return
name|E_INVALIDARG
return|;
block|}
name|DXGI_SWAP_CHAIN_DESC1
name|swapChainDesc
init|=
block|{
literal|0
block|}
decl_stmt|;
name|swapChainDesc
operator|.
name|Width
operator|=
name|width
expr_stmt|;
name|swapChainDesc
operator|.
name|Height
operator|=
name|height
expr_stmt|;
name|swapChainDesc
operator|.
name|Format
operator|=
name|format
expr_stmt|;
name|swapChainDesc
operator|.
name|Stereo
operator|=
name|FALSE
expr_stmt|;
name|swapChainDesc
operator|.
name|SampleDesc
operator|.
name|Count
operator|=
literal|1
expr_stmt|;
name|swapChainDesc
operator|.
name|SampleDesc
operator|.
name|Quality
operator|=
literal|0
expr_stmt|;
name|swapChainDesc
operator|.
name|BufferUsage
operator|=
name|DXGI_USAGE_RENDER_TARGET_OUTPUT
operator||
name|DXGI_USAGE_BACK_BUFFER
expr_stmt|;
name|swapChainDesc
operator|.
name|BufferCount
operator|=
literal|2
expr_stmt|;
name|swapChainDesc
operator|.
name|SwapEffect
operator|=
name|DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL
expr_stmt|;
name|swapChainDesc
operator|.
name|Scaling
operator|=
name|DXGI_SCALING_STRETCH
expr_stmt|;
name|swapChainDesc
operator|.
name|AlphaMode
operator|=
name|DXGI_ALPHA_MODE_IGNORE
expr_stmt|;
operator|*
name|swapChain
operator|=
literal|nullptr
expr_stmt|;
name|ComPtr
argument_list|<
name|IDXGISwapChain1
argument_list|>
name|newSwapChain
decl_stmt|;
name|ComPtr
argument_list|<
name|ISwapChainPanelNative
argument_list|>
name|swapChainPanelNative
decl_stmt|;
name|RECT
name|currentPanelSize
init|=
block|{}
decl_stmt|;
name|HRESULT
name|result
init|=
name|factory
operator|->
name|CreateSwapChainForComposition
argument_list|(
name|device
argument_list|,
operator|&
name|swapChainDesc
argument_list|,
literal|nullptr
argument_list|,
name|newSwapChain
operator|.
name|ReleaseAndGetAddressOf
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|result
operator|=
name|mSwapChainPanel
operator|.
name|As
argument_list|(
operator|&
name|swapChainPanelNative
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|result
operator|=
name|swapChainPanelNative
operator|->
name|SetSwapChain
argument_list|(
name|newSwapChain
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
comment|// The swapchain panel host requires an instance of the swapchain set on the SwapChainPanel
comment|// to perform the runtime-scale behavior.  This swapchain is cached here because there are
comment|// no methods for retreiving the currently configured on from ISwapChainPanelNative.
name|mSwapChain
operator|=
name|newSwapChain
expr_stmt|;
name|result
operator|=
name|newSwapChain
operator|.
name|CopyTo
argument_list|(
name|swapChain
argument_list|)
expr_stmt|;
block|}
comment|// If the host is responsible for scaling the output of the swapchain, then
comment|// scale it now before returning an instance to the caller.  This is done by
comment|// first reading the current size of the swapchain panel, then scaling
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
operator|&&
name|mRequiresSwapChainScaling
condition|)
block|{
name|result
operator|=
name|GetSwapChainPanelSize
argument_list|(
name|mSwapChainPanel
argument_list|,
operator|&
name|currentPanelSize
argument_list|)
expr_stmt|;
block|}
comment|// Scale the swapchain to fit inside the contents of the panel.
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
operator|&&
name|mRequiresSwapChainScaling
condition|)
block|{
name|SIZE
name|currentSize
init|=
block|{
name|currentPanelSize
operator|.
name|right
block|,
name|currentPanelSize
operator|.
name|bottom
block|}
decl_stmt|;
name|result
operator|=
name|scaleSwapChain
argument_list|(
name|currentSize
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
comment|// If automatic swapchain resize behaviors have been disabled, then
comment|// unregister for the resize change events.
if|if
condition|(
name|mSupportsSwapChainResize
operator|==
literal|false
condition|)
block|{
name|unregisterForSizeChangeEvents
argument_list|()
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
DECL|function|scaleSwapChain
name|HRESULT
name|SwapChainPanelNativeWindow
operator|::
name|scaleSwapChain
parameter_list|(
specifier|const
name|SIZE
modifier|&
name|newSize
parameter_list|)
block|{
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Size
name|renderScale
init|=
block|{
operator|(
name|float
operator|)
name|newSize
operator|.
name|cx
operator|/
operator|(
name|float
operator|)
name|mClientRect
operator|.
name|right
block|,
operator|(
name|float
operator|)
name|newSize
operator|.
name|cy
operator|/
operator|(
name|float
operator|)
name|mClientRect
operator|.
name|bottom
block|}
decl_stmt|;
comment|// Setup a scale matrix for the swap chain
name|DXGI_MATRIX_3X2_F
name|scaleMatrix
init|=
block|{}
decl_stmt|;
name|scaleMatrix
operator|.
name|_11
operator|=
name|renderScale
operator|.
name|Width
expr_stmt|;
name|scaleMatrix
operator|.
name|_22
operator|=
name|renderScale
operator|.
name|Height
expr_stmt|;
name|ComPtr
argument_list|<
name|IDXGISwapChain2
argument_list|>
name|swapChain2
decl_stmt|;
name|HRESULT
name|result
init|=
name|mSwapChain
operator|.
name|As
argument_list|(
operator|&
name|swapChain2
argument_list|)
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|result
operator|=
name|swapChain2
operator|->
name|SetMatrixTransform
argument_list|(
operator|&
name|scaleMatrix
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
DECL|function|GetSwapChainPanelSize
name|HRESULT
name|GetSwapChainPanelSize
parameter_list|(
specifier|const
name|ComPtr
argument_list|<
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
argument_list|>
modifier|&
name|swapChainPanel
parameter_list|,
name|RECT
modifier|*
name|windowSize
parameter_list|)
block|{
name|ComPtr
argument_list|<
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Xaml
operator|::
name|IUIElement
argument_list|>
name|uiElement
decl_stmt|;
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Size
name|renderSize
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|HRESULT
name|result
init|=
name|swapChainPanel
operator|.
name|As
argument_list|(
operator|&
name|uiElement
argument_list|)
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|result
operator|=
name|uiElement
operator|->
name|get_RenderSize
argument_list|(
operator|&
name|renderSize
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|result
argument_list|)
condition|)
block|{
operator|*
name|windowSize
operator|=
block|{
literal|0
block|,
literal|0
block|,
name|lround
argument_list|(
name|renderSize
operator|.
name|Width
argument_list|)
block|,
name|lround
argument_list|(
argument|renderSize.Height
argument_list|)
block|}
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
block|}
end_namespace
end_unit
