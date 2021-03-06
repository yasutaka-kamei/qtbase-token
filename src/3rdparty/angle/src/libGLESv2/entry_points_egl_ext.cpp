begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright(c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// entry_points_ext.cpp : Implements the EGL extension entry points.
end_comment
begin_include
include|#
directive|include
file|"libGLESv2/entry_points_egl_ext.h"
end_include
begin_include
include|#
directive|include
file|"libGLESv2/global_state.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Display.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Device.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Surface.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/validationEGL.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_namespace
DECL|namespace|egl
namespace|namespace
name|egl
block|{
comment|// EGL_ANGLE_query_surface_pointer
DECL|function|QuerySurfacePointerANGLE
name|EGLBoolean
name|EGLAPIENTRY
name|QuerySurfacePointerANGLE
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|void
modifier|*
modifier|*
name|value
parameter_list|)
block|{
name|EVENT
argument_list|(
literal|"(EGLDisplay dpy = 0x%0.8p, EGLSurface surface = 0x%0.8p, EGLint attribute = %d, void **value = 0x%0.8p)"
argument_list|,
name|dpy
argument_list|,
name|surface
argument_list|,
name|attribute
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|Display
modifier|*
name|display
init|=
cast|static_cast
argument_list|<
name|Display
operator|*
argument_list|>
argument_list|(
name|dpy
argument_list|)
decl_stmt|;
name|Surface
modifier|*
name|eglSurface
init|=
cast|static_cast
argument_list|<
name|Surface
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|Error
name|error
init|=
name|ValidateSurface
argument_list|(
name|display
argument_list|,
name|eglSurface
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
if|if
condition|(
operator|!
name|display
operator|->
name|getExtensions
argument_list|()
operator|.
name|querySurfacePointer
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
if|if
condition|(
name|surface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_SURFACE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
comment|// validate the attribute parameter
switch|switch
condition|(
name|attribute
condition|)
block|{
case|case
name|EGL_DEVICE_EXT
case|:
break|break;
case|case
name|EGL_D3D_TEXTURE_2D_SHARE_HANDLE_ANGLE
case|:
if|if
condition|(
operator|!
name|display
operator|->
name|getExtensions
argument_list|()
operator|.
name|surfaceD3DTexture2DShareHandle
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
break|break;
case|case
name|EGL_DXGI_KEYED_MUTEX_ANGLE
case|:
if|if
condition|(
operator|!
name|display
operator|->
name|getExtensions
argument_list|()
operator|.
name|keyedMutex
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
break|break;
default|default:
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
name|error
operator|=
name|eglSurface
operator|->
name|querySurfacePointerANGLE
argument_list|(
name|attribute
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|.
name|isError
argument_list|()
condition|?
name|EGL_FALSE
else|:
name|EGL_TRUE
operator|)
return|;
block|}
comment|// EGL_NV_post_sub_buffer
DECL|function|PostSubBufferNV
name|EGLBoolean
name|EGLAPIENTRY
name|PostSubBufferNV
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLint
name|x
parameter_list|,
name|EGLint
name|y
parameter_list|,
name|EGLint
name|width
parameter_list|,
name|EGLint
name|height
parameter_list|)
block|{
name|EVENT
argument_list|(
literal|"(EGLDisplay dpy = 0x%0.8p, EGLSurface surface = 0x%0.8p, EGLint x = %d, EGLint y = %d, EGLint width = %d, EGLint height = %d)"
argument_list|,
name|dpy
argument_list|,
name|surface
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
operator|||
name|y
operator|<
literal|0
operator|||
name|width
operator|<
literal|0
operator|||
name|height
operator|<
literal|0
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_PARAMETER
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
name|Display
modifier|*
name|display
init|=
cast|static_cast
argument_list|<
name|Display
operator|*
argument_list|>
argument_list|(
name|dpy
argument_list|)
decl_stmt|;
name|Surface
modifier|*
name|eglSurface
init|=
cast|static_cast
argument_list|<
name|Surface
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|Error
name|error
init|=
name|ValidateSurface
argument_list|(
name|display
argument_list|,
name|eglSurface
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
if|if
condition|(
name|display
operator|->
name|isDeviceLost
argument_list|()
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_CONTEXT_LOST
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
if|if
condition|(
name|surface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_SURFACE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANGLE_ENABLE_WINDOWS_STORE
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|ANGLE_ENABLE_WINDOWS_STORE
argument_list|)
operator|&&
name|WINAPI_FAMILY
operator|==
name|WINAPI_FAMILY_PC_APP
operator|)
comment|// Qt WP: Allow this entry point as a workaround
if|if
condition|(
operator|!
name|display
operator|->
name|getExtensions
argument_list|()
operator|.
name|postSubBuffer
condition|)
block|{
comment|// Spec is not clear about how this should be handled.
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_TRUE
return|;
block|}
endif|#
directive|endif
name|error
operator|=
name|eglSurface
operator|->
name|postSubBuffer
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_TRUE
return|;
block|}
comment|// EGL_EXT_platform_base
DECL|function|GetPlatformDisplayEXT
name|EGLDisplay
name|EGLAPIENTRY
name|GetPlatformDisplayEXT
parameter_list|(
name|EGLenum
name|platform
parameter_list|,
name|void
modifier|*
name|native_display
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
block|{
name|EVENT
argument_list|(
literal|"(EGLenum platform = %d, void* native_display = 0x%0.8p, const EGLint* attrib_list = 0x%0.8p)"
argument_list|,
name|platform
argument_list|,
name|native_display
argument_list|,
name|attrib_list
argument_list|)
expr_stmt|;
specifier|const
name|ClientExtensions
modifier|&
name|clientExtensions
init|=
name|Display
operator|::
name|getClientExtensions
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|platform
condition|)
block|{
case|case
name|EGL_PLATFORM_ANGLE_ANGLE
case|:
if|if
condition|(
operator|!
name|clientExtensions
operator|.
name|platformANGLE
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_PARAMETER
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
break|break;
case|case
name|EGL_PLATFORM_DEVICE_EXT
case|:
if|if
condition|(
operator|!
name|clientExtensions
operator|.
name|platformDevice
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_PARAMETER
argument_list|,
literal|"Platform Device extension is not active"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
break|break;
default|default:
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_CONFIG
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
if|if
condition|(
name|platform
operator|==
name|EGL_PLATFORM_ANGLE_ANGLE
condition|)
block|{
name|EGLint
name|platformType
init|=
name|EGL_PLATFORM_ANGLE_TYPE_DEFAULT_ANGLE
decl_stmt|;
name|EGLint
name|deviceType
init|=
name|EGL_PLATFORM_ANGLE_DEVICE_TYPE_HARDWARE_ANGLE
decl_stmt|;
name|bool
name|majorVersionSpecified
init|=
literal|false
decl_stmt|;
name|bool
name|minorVersionSpecified
init|=
literal|false
decl_stmt|;
name|bool
name|enableAutoTrimSpecified
init|=
literal|false
decl_stmt|;
name|bool
name|deviceTypeSpecified
init|=
literal|false
decl_stmt|;
name|bool
name|presentPathSpecified
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|attrib_list
condition|)
block|{
for|for
control|(
specifier|const
name|EGLint
modifier|*
name|curAttrib
init|=
name|attrib_list
init|;
name|curAttrib
index|[
literal|0
index|]
operator|!=
name|EGL_NONE
condition|;
name|curAttrib
operator|+=
literal|2
control|)
block|{
switch|switch
condition|(
name|curAttrib
index|[
literal|0
index|]
condition|)
block|{
case|case
name|EGL_PLATFORM_ANGLE_TYPE_ANGLE
case|:
switch|switch
condition|(
name|curAttrib
index|[
literal|1
index|]
condition|)
block|{
case|case
name|EGL_PLATFORM_ANGLE_TYPE_DEFAULT_ANGLE
case|:
break|break;
case|case
name|EGL_PLATFORM_ANGLE_TYPE_D3D9_ANGLE
case|:
case|case
name|EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE
case|:
if|if
condition|(
operator|!
name|clientExtensions
operator|.
name|platformANGLED3D
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
break|break;
case|case
name|EGL_PLATFORM_ANGLE_TYPE_OPENGL_ANGLE
case|:
case|case
name|EGL_PLATFORM_ANGLE_TYPE_OPENGLES_ANGLE
case|:
if|if
condition|(
operator|!
name|clientExtensions
operator|.
name|platformANGLEOpenGL
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
break|break;
default|default:
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
name|platformType
operator|=
name|curAttrib
index|[
literal|1
index|]
expr_stmt|;
break|break;
case|case
name|EGL_PLATFORM_ANGLE_MAX_VERSION_MAJOR_ANGLE
case|:
if|if
condition|(
name|curAttrib
index|[
literal|1
index|]
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|majorVersionSpecified
operator|=
literal|true
expr_stmt|;
block|}
break|break;
case|case
name|EGL_PLATFORM_ANGLE_MAX_VERSION_MINOR_ANGLE
case|:
if|if
condition|(
name|curAttrib
index|[
literal|1
index|]
operator|!=
name|EGL_DONT_CARE
condition|)
block|{
name|minorVersionSpecified
operator|=
literal|true
expr_stmt|;
block|}
break|break;
case|case
name|EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE
case|:
switch|switch
condition|(
name|curAttrib
index|[
literal|1
index|]
condition|)
block|{
case|case
name|EGL_TRUE
case|:
case|case
name|EGL_FALSE
case|:
break|break;
default|default:
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
name|enableAutoTrimSpecified
operator|=
literal|true
expr_stmt|;
break|break;
case|case
name|EGL_EXPERIMENTAL_PRESENT_PATH_ANGLE
case|:
if|if
condition|(
operator|!
name|clientExtensions
operator|.
name|experimentalPresentPath
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|,
literal|"EGL_ANGLE_experimental_present_path extension not active"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
switch|switch
condition|(
name|curAttrib
index|[
literal|1
index|]
condition|)
block|{
case|case
name|EGL_EXPERIMENTAL_PRESENT_PATH_FAST_ANGLE
case|:
case|case
name|EGL_EXPERIMENTAL_PRESENT_PATH_COPY_ANGLE
case|:
break|break;
default|default:
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|,
literal|"Invalid value for EGL_EXPERIMENTAL_PRESENT_PATH_ANGLE"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
name|presentPathSpecified
operator|=
literal|true
expr_stmt|;
break|break;
case|case
name|EGL_PLATFORM_ANGLE_DEVICE_TYPE_ANGLE
case|:
switch|switch
condition|(
name|curAttrib
index|[
literal|1
index|]
condition|)
block|{
case|case
name|EGL_PLATFORM_ANGLE_DEVICE_TYPE_HARDWARE_ANGLE
case|:
case|case
name|EGL_PLATFORM_ANGLE_DEVICE_TYPE_WARP_ANGLE
case|:
case|case
name|EGL_PLATFORM_ANGLE_DEVICE_TYPE_REFERENCE_ANGLE
case|:
name|deviceTypeSpecified
operator|=
literal|true
expr_stmt|;
break|break;
case|case
name|EGL_PLATFORM_ANGLE_DEVICE_TYPE_NULL_ANGLE
case|:
comment|// This is a hidden option, accepted by the OpenGL back-end.
break|break;
default|default:
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|,
literal|"Invalid value for "
literal|"EGL_PLATFORM_ANGLE_DEVICE_TYPE_ANGLE "
literal|"attrib"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
name|deviceType
operator|=
name|curAttrib
index|[
literal|1
index|]
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
block|}
if|if
condition|(
operator|!
name|majorVersionSpecified
operator|&&
name|minorVersionSpecified
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
if|if
condition|(
name|deviceType
operator|==
name|EGL_PLATFORM_ANGLE_DEVICE_TYPE_WARP_ANGLE
operator|&&
name|platformType
operator|!=
name|EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|,
literal|"EGL_PLATFORM_ANGLE_DEVICE_TYPE_WARP_ANGLE requires a device type of "
literal|"EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE."
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
if|if
condition|(
name|enableAutoTrimSpecified
operator|&&
name|platformType
operator|!=
name|EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|,
literal|"EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE requires a device type of "
literal|"EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE."
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
if|if
condition|(
name|presentPathSpecified
operator|&&
name|platformType
operator|!=
name|EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|,
literal|"EGL_EXPERIMENTAL_PRESENT_PATH_ANGLE requires a device type of "
literal|"EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE."
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
if|if
condition|(
name|deviceTypeSpecified
operator|&&
name|platformType
operator|!=
name|EGL_PLATFORM_ANGLE_TYPE_D3D9_ANGLE
operator|&&
name|platformType
operator|!=
name|EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|,
literal|"EGL_PLATFORM_ANGLE_DEVICE_TYPE_ANGLE requires a device type of "
literal|"EGL_PLATFORM_ANGLE_TYPE_D3D9_ANGLE or EGL_PLATFORM_ANGLE_TYPE_D3D9_ANGLE."
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Display
operator|::
name|GetDisplayFromAttribs
argument_list|(
name|native_display
argument_list|,
name|AttributeMap
argument_list|(
name|attrib_list
argument_list|)
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|platform
operator|==
name|EGL_PLATFORM_DEVICE_EXT
condition|)
block|{
name|Device
modifier|*
name|eglDevice
init|=
cast|reinterpret_cast
argument_list|<
name|Device
operator|*
argument_list|>
argument_list|(
name|native_display
argument_list|)
decl_stmt|;
if|if
condition|(
name|eglDevice
operator|==
literal|nullptr
operator|||
operator|!
name|Device
operator|::
name|IsValidDevice
argument_list|(
name|eglDevice
argument_list|)
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|,
literal|"native_display should be a valid EGL device if platform equals "
literal|"EGL_PLATFORM_DEVICE_EXT"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Display
operator|::
name|GetDisplayFromDevice
argument_list|(
name|native_display
argument_list|)
return|;
block|}
else|else
block|{
name|UNREACHABLE
argument_list|()
expr_stmt|;
return|return
name|EGL_NO_DISPLAY
return|;
block|}
block|}
comment|// EGL_EXT_device_query
DECL|function|QueryDeviceAttribEXT
name|EGLBoolean
name|EGLAPIENTRY
name|QueryDeviceAttribEXT
parameter_list|(
name|EGLDeviceEXT
name|device
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLAttrib
modifier|*
name|value
parameter_list|)
block|{
name|EVENT
argument_list|(
literal|"(EGLDeviceEXT device = 0x%0.8p, EGLint attribute = %d, EGLAttrib *value = 0x%0.8p)"
argument_list|,
name|device
argument_list|,
name|attribute
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|Device
modifier|*
name|dev
init|=
cast|static_cast
argument_list|<
name|Device
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
decl_stmt|;
if|if
condition|(
name|dev
operator|==
name|EGL_NO_DEVICE_EXT
operator|||
operator|!
name|Device
operator|::
name|IsValidDevice
argument_list|(
name|dev
argument_list|)
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ACCESS
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
comment|// If the device was created by (and is owned by) a display, and that display doesn't support
comment|// device querying, then this call should fail
name|Display
modifier|*
name|owningDisplay
init|=
name|dev
operator|->
name|getOwningDisplay
argument_list|()
decl_stmt|;
if|if
condition|(
name|owningDisplay
operator|!=
literal|nullptr
operator|&&
operator|!
name|owningDisplay
operator|->
name|getExtensions
argument_list|()
operator|.
name|deviceQuery
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ACCESS
argument_list|,
literal|"Device wasn't created using eglCreateDeviceANGLE, and the Display "
literal|"that created it doesn't support device querying"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
name|Error
name|error
argument_list|(
name|EGL_SUCCESS
argument_list|)
decl_stmt|;
comment|// validate the attribute parameter
switch|switch
condition|(
name|attribute
condition|)
block|{
case|case
name|EGL_D3D11_DEVICE_ANGLE
case|:
case|case
name|EGL_D3D9_DEVICE_ANGLE
case|:
if|if
condition|(
operator|!
name|dev
operator|->
name|getExtensions
argument_list|()
operator|.
name|deviceD3D
operator|||
name|dev
operator|->
name|getType
argument_list|()
operator|!=
name|attribute
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
name|error
operator|=
name|dev
operator|->
name|getDevice
argument_list|(
name|value
argument_list|)
expr_stmt|;
break|break;
default|default:
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|.
name|isError
argument_list|()
condition|?
name|EGL_FALSE
else|:
name|EGL_TRUE
operator|)
return|;
block|}
comment|// EGL_EXT_device_query
DECL|function|QueryDeviceStringEXT
specifier|const
name|char
modifier|*
name|EGLAPIENTRY
name|QueryDeviceStringEXT
parameter_list|(
name|EGLDeviceEXT
name|device
parameter_list|,
name|EGLint
name|name
parameter_list|)
block|{
name|EVENT
argument_list|(
literal|"(EGLDeviceEXT device = 0x%0.8p, EGLint name = %d)"
argument_list|,
name|device
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|Device
modifier|*
name|dev
init|=
cast|static_cast
argument_list|<
name|Device
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
decl_stmt|;
if|if
condition|(
name|dev
operator|==
name|EGL_NO_DEVICE_EXT
operator|||
operator|!
name|Device
operator|::
name|IsValidDevice
argument_list|(
name|dev
argument_list|)
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_DEVICE_EXT
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|nullptr
return|;
block|}
specifier|const
name|char
modifier|*
name|result
decl_stmt|;
switch|switch
condition|(
name|name
condition|)
block|{
case|case
name|EGL_EXTENSIONS
case|:
name|result
operator|=
name|dev
operator|->
name|getExtensionString
argument_list|()
operator|.
name|c_str
argument_list|()
expr_stmt|;
break|break;
default|default:
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_DEVICE_EXT
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|nullptr
return|;
block|}
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_SUCCESS
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
comment|// EGL_EXT_device_query
DECL|function|QueryDisplayAttribEXT
name|EGLBoolean
name|EGLAPIENTRY
name|QueryDisplayAttribEXT
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLAttrib
modifier|*
name|value
parameter_list|)
block|{
name|EVENT
argument_list|(
literal|"(EGLDisplay dpy = 0x%0.8p, EGLint attribute = %d, EGLAttrib *value = 0x%0.8p)"
argument_list|,
name|dpy
argument_list|,
name|attribute
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|Display
modifier|*
name|display
init|=
cast|static_cast
argument_list|<
name|Display
operator|*
argument_list|>
argument_list|(
name|dpy
argument_list|)
decl_stmt|;
name|Error
name|error
argument_list|(
name|EGL_SUCCESS
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|display
operator|->
name|getExtensions
argument_list|()
operator|.
name|deviceQuery
condition|)
block|{
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ACCESS
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
comment|// validate the attribute parameter
switch|switch
condition|(
name|attribute
condition|)
block|{
case|case
name|EGL_DEVICE_EXT
case|:
operator|*
name|value
operator|=
cast|reinterpret_cast
argument_list|<
name|EGLAttrib
argument_list|>
argument_list|(
name|display
operator|->
name|getDevice
argument_list|()
argument_list|)
expr_stmt|;
break|break;
default|default:
name|SetGlobalError
argument_list|(
name|Error
argument_list|(
name|EGL_BAD_ATTRIBUTE
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|.
name|isError
argument_list|()
condition|?
name|EGL_FALSE
else|:
name|EGL_TRUE
operator|)
return|;
block|}
DECL|function|CreateImageKHR
name|ANGLE_EXPORT
name|EGLImageKHR
name|EGLAPIENTRY
name|CreateImageKHR
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLContext
name|ctx
parameter_list|,
name|EGLenum
name|target
parameter_list|,
name|EGLClientBuffer
name|buffer
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
block|{
name|EVENT
argument_list|(
literal|"(EGLDisplay dpy = 0x%0.8p, EGLContext ctx = 0x%0.8p, EGLenum target = 0x%X, "
literal|"EGLClientBuffer buffer = 0x%0.8p, const EGLAttrib *attrib_list = 0x%0.8p)"
argument_list|,
name|dpy
argument_list|,
name|ctx
argument_list|,
name|target
argument_list|,
name|buffer
argument_list|,
name|attrib_list
argument_list|)
expr_stmt|;
name|Display
modifier|*
name|display
init|=
cast|static_cast
argument_list|<
name|Display
operator|*
argument_list|>
argument_list|(
name|dpy
argument_list|)
decl_stmt|;
name|gl
operator|::
name|Context
modifier|*
name|context
init|=
cast|static_cast
argument_list|<
name|gl
operator|::
name|Context
operator|*
argument_list|>
argument_list|(
name|ctx
argument_list|)
decl_stmt|;
name|AttributeMap
name|attributes
argument_list|(
name|attrib_list
argument_list|)
decl_stmt|;
name|Error
name|error
init|=
name|ValidateCreateImageKHR
argument_list|(
name|display
argument_list|,
name|context
argument_list|,
name|target
argument_list|,
name|buffer
argument_list|,
name|attributes
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_IMAGE
return|;
block|}
name|Image
modifier|*
name|image
init|=
literal|nullptr
decl_stmt|;
name|error
operator|=
name|display
operator|->
name|createImage
argument_list|(
name|context
argument_list|,
name|target
argument_list|,
name|buffer
argument_list|,
name|attributes
argument_list|,
operator|&
name|image
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_IMAGE
return|;
block|}
return|return
cast|static_cast
argument_list|<
name|EGLImage
argument_list|>
argument_list|(
name|image
argument_list|)
return|;
block|}
DECL|function|DestroyImageKHR
name|ANGLE_EXPORT
name|EGLBoolean
name|EGLAPIENTRY
name|DestroyImageKHR
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLImageKHR
name|image
parameter_list|)
block|{
name|EVENT
argument_list|(
literal|"(EGLDisplay dpy = 0x%0.8p, EGLImage image = 0x%0.8p)"
argument_list|,
name|dpy
argument_list|,
name|image
argument_list|)
expr_stmt|;
name|Display
modifier|*
name|display
init|=
cast|static_cast
argument_list|<
name|Display
operator|*
argument_list|>
argument_list|(
name|dpy
argument_list|)
decl_stmt|;
name|Image
modifier|*
name|img
init|=
cast|static_cast
argument_list|<
name|Image
operator|*
argument_list|>
argument_list|(
name|image
argument_list|)
decl_stmt|;
name|Error
name|error
init|=
name|ValidateDestroyImageKHR
argument_list|(
name|display
argument_list|,
name|img
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
name|display
operator|->
name|destroyImage
argument_list|(
name|img
argument_list|)
expr_stmt|;
return|return
name|EGL_TRUE
return|;
block|}
DECL|function|CreateDeviceANGLE
name|ANGLE_EXPORT
name|EGLDeviceEXT
name|EGLAPIENTRY
name|CreateDeviceANGLE
parameter_list|(
name|EGLint
name|device_type
parameter_list|,
name|void
modifier|*
name|native_device
parameter_list|,
specifier|const
name|EGLAttrib
modifier|*
name|attrib_list
parameter_list|)
block|{
name|EVENT
argument_list|(
literal|"(EGLint device_type = %d, void* native_device = 0x%0.8p, const EGLAttrib* attrib_list = "
literal|"0x%0.8p)"
argument_list|,
name|device_type
argument_list|,
name|native_device
argument_list|,
name|attrib_list
argument_list|)
expr_stmt|;
name|Error
name|error
init|=
name|ValidateCreateDeviceANGLE
argument_list|(
name|device_type
argument_list|,
name|native_device
argument_list|,
name|attrib_list
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DEVICE_EXT
return|;
block|}
name|Device
modifier|*
name|device
init|=
literal|nullptr
decl_stmt|;
name|error
operator|=
name|Device
operator|::
name|CreateDevice
argument_list|(
name|native_device
argument_list|,
name|device_type
argument_list|,
operator|&
name|device
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
name|ASSERT
argument_list|(
name|device
operator|==
literal|nullptr
argument_list|)
expr_stmt|;
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
name|EGL_NO_DEVICE_EXT
return|;
block|}
return|return
name|device
return|;
block|}
DECL|function|ReleaseDeviceANGLE
name|ANGLE_EXPORT
name|EGLBoolean
name|EGLAPIENTRY
name|ReleaseDeviceANGLE
parameter_list|(
name|EGLDeviceEXT
name|device
parameter_list|)
block|{
name|EVENT
argument_list|(
literal|"(EGLDeviceEXT device = 0x%0.8p)"
argument_list|,
name|device
argument_list|)
expr_stmt|;
name|Device
modifier|*
name|dev
init|=
cast|static_cast
argument_list|<
name|Device
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
decl_stmt|;
name|Error
name|error
init|=
name|ValidateReleaseDeviceANGLE
argument_list|(
name|dev
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
name|SetGlobalError
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
name|EGL_FALSE
return|;
block|}
name|SafeDelete
argument_list|(
name|dev
argument_list|)
expr_stmt|;
return|return
name|EGL_TRUE
return|;
block|}
block|}
end_namespace
end_unit
