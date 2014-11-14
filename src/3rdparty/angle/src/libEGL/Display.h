begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
comment|// Display.h: Defines the egl::Display class, representing the abstract
end_comment
begin_comment
comment|// display on which graphics are drawn. Implements EGLDisplay.
end_comment
begin_comment
comment|// [EGL 1.4] section 2.1.2 page 3.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBEGL_DISPLAY_H_
end_ifndef
begin_define
DECL|macro|LIBEGL_DISPLAY_H_
define|#
directive|define
name|LIBEGL_DISPLAY_H_
end_define
begin_include
include|#
directive|include
file|<set>
end_include
begin_include
include|#
directive|include
file|<vector>
end_include
begin_include
include|#
directive|include
file|"libEGL/Error.h"
end_include
begin_include
include|#
directive|include
file|"libEGL/Config.h"
end_include
begin_include
include|#
directive|include
file|"libEGL/AttributeMap.h"
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
name|class
name|Context
decl_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|namespace
name|egl
block|{
name|class
name|Surface
decl_stmt|;
name|class
name|Display
block|{
name|public
label|:
operator|~
name|Display
argument_list|()
expr_stmt|;
name|Error
name|initialize
parameter_list|()
function_decl|;
name|void
name|terminate
parameter_list|()
function_decl|;
specifier|static
name|egl
operator|::
name|Display
operator|*
name|getDisplay
argument_list|(
argument|EGLNativeDisplayType displayId
argument_list|,
argument|const AttributeMap&attribMap
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|getExtensionString
argument_list|(
name|egl
operator|::
name|Display
operator|*
name|display
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|supportsPlatformD3D
parameter_list|()
function_decl|;
specifier|static
name|bool
name|supportsPlatformOpenGL
parameter_list|()
function_decl|;
name|bool
name|getConfigs
parameter_list|(
name|EGLConfig
modifier|*
name|configs
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attribList
parameter_list|,
name|EGLint
name|configSize
parameter_list|,
name|EGLint
modifier|*
name|numConfig
parameter_list|)
function_decl|;
name|bool
name|getConfigAttrib
parameter_list|(
name|EGLConfig
name|config
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLint
modifier|*
name|value
parameter_list|)
function_decl|;
name|Error
name|createWindowSurface
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|,
name|EGLConfig
name|config
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attribList
parameter_list|,
name|EGLSurface
modifier|*
name|outSurface
parameter_list|)
function_decl|;
name|Error
name|createOffscreenSurface
parameter_list|(
name|EGLConfig
name|config
parameter_list|,
name|HANDLE
name|shareHandle
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attribList
parameter_list|,
name|EGLSurface
modifier|*
name|outSurface
parameter_list|)
function_decl|;
name|Error
name|createContext
argument_list|(
name|EGLConfig
name|configHandle
argument_list|,
name|EGLint
name|clientVersion
argument_list|,
specifier|const
name|gl
operator|::
name|Context
operator|*
name|shareContext
argument_list|,
name|bool
name|notifyResets
argument_list|,
name|bool
name|robustAccess
argument_list|,
name|EGLContext
operator|*
name|outContext
argument_list|)
decl_stmt|;
name|void
name|destroySurface
argument_list|(
name|egl
operator|::
name|Surface
operator|*
name|surface
argument_list|)
decl_stmt|;
name|void
name|destroyContext
argument_list|(
name|gl
operator|::
name|Context
operator|*
name|context
argument_list|)
decl_stmt|;
name|bool
name|isInitialized
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValidConfig
parameter_list|(
name|EGLConfig
name|config
parameter_list|)
function_decl|;
name|bool
name|isValidContext
argument_list|(
name|gl
operator|::
name|Context
operator|*
name|context
argument_list|)
decl_stmt|;
name|bool
name|isValidSurface
argument_list|(
name|egl
operator|::
name|Surface
operator|*
name|surface
argument_list|)
decl_stmt|;
name|bool
name|hasExistingWindowSurface
parameter_list|(
name|EGLNativeWindowType
name|window
parameter_list|)
function_decl|;
name|rx
operator|::
name|Renderer
operator|*
name|getRenderer
argument_list|()
block|{
return|return
name|mRenderer
return|;
block|}
empty_stmt|;
comment|// exported methods must be virtual
name|virtual
name|void
name|notifyDeviceLost
parameter_list|()
function_decl|;
name|virtual
name|void
name|recreateSwapChains
parameter_list|()
function_decl|;
specifier|const
name|char
operator|*
name|getExtensionString
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|getVendorString
argument_list|()
specifier|const
expr_stmt|;
name|EGLNativeDisplayType
name|getDisplayId
argument_list|()
specifier|const
block|{
return|return
name|mDisplayId
return|;
block|}
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Display
argument_list|)
expr_stmt|;
name|Display
argument_list|(
argument|EGLNativeDisplayType displayId
argument_list|)
empty_stmt|;
name|void
name|setAttributes
parameter_list|(
specifier|const
name|AttributeMap
modifier|&
name|attribMap
parameter_list|)
function_decl|;
name|Error
name|restoreLostDevice
parameter_list|()
function_decl|;
name|EGLNativeDisplayType
name|mDisplayId
decl_stmt|;
name|AttributeMap
name|mAttributeMap
decl_stmt|;
typedef|typedef
name|std
operator|::
name|set
operator|<
name|Surface
operator|*
operator|>
name|SurfaceSet
expr_stmt|;
name|SurfaceSet
name|mSurfaceSet
decl_stmt|;
name|ConfigSet
name|mConfigSet
decl_stmt|;
typedef|typedef
name|std
operator|::
name|set
operator|<
name|gl
operator|::
name|Context
operator|*
operator|>
name|ContextSet
expr_stmt|;
name|ContextSet
name|mContextSet
decl_stmt|;
name|rx
operator|::
name|Renderer
operator|*
name|mRenderer
expr_stmt|;
specifier|static
name|std
operator|::
name|string
name|generateClientExtensionString
argument_list|()
expr_stmt|;
name|void
name|initDisplayExtensionString
parameter_list|()
function_decl|;
name|std
operator|::
name|string
name|mDisplayExtensionString
expr_stmt|;
name|void
name|initVendorString
parameter_list|()
function_decl|;
name|std
operator|::
name|string
name|mVendorString
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBEGL_DISPLAY_H_
end_comment
end_unit
