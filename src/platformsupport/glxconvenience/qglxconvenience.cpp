begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglxconvenience_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QVector>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVarLengthArray>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_XRENDER
end_ifndef
begin_include
include|#
directive|include
file|<X11/extensions/Xrender.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_enum
enum|enum
block|{
DECL|enumerator|XFocusOut
name|XFocusOut
init|=
name|FocusOut
block|,
DECL|enumerator|XFocusIn
name|XFocusIn
init|=
name|FocusIn
block|,
DECL|enumerator|XKeyPress
name|XKeyPress
init|=
name|KeyPress
block|,
DECL|enumerator|XKeyRelease
name|XKeyRelease
init|=
name|KeyRelease
block|,
DECL|enumerator|XNone
name|XNone
init|=
name|None
block|,
DECL|enumerator|XRevertToParent
name|XRevertToParent
init|=
name|RevertToParent
block|,
DECL|enumerator|XGrayScale
name|XGrayScale
init|=
name|GrayScale
block|,
DECL|enumerator|XCursorShape
name|XCursorShape
init|=
name|CursorShape
block|}
enum|;
end_enum
begin_undef
DECL|macro|FocusOut
undef|#
directive|undef
name|FocusOut
end_undef
begin_undef
DECL|macro|FocusIn
undef|#
directive|undef
name|FocusIn
end_undef
begin_undef
DECL|macro|KeyPress
undef|#
directive|undef
name|KeyPress
end_undef
begin_undef
DECL|macro|KeyRelease
undef|#
directive|undef
name|KeyRelease
end_undef
begin_undef
DECL|macro|None
undef|#
directive|undef
name|None
end_undef
begin_undef
DECL|macro|RevertToParent
undef|#
directive|undef
name|RevertToParent
end_undef
begin_undef
DECL|macro|GrayScale
undef|#
directive|undef
name|GrayScale
end_undef
begin_undef
DECL|macro|CursorShape
undef|#
directive|undef
name|CursorShape
end_undef
begin_ifdef
ifdef|#
directive|ifdef
name|FontChange
end_ifdef
begin_undef
DECL|macro|FontChange
undef|#
directive|undef
name|FontChange
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|qglx_buildSpec
name|QVector
argument_list|<
name|int
argument_list|>
name|qglx_buildSpec
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|int
name|drawableBit
parameter_list|)
block|{
name|QVector
argument_list|<
name|int
argument_list|>
name|spec
argument_list|(
literal|48
argument_list|)
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_LEVEL
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
literal|0
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_DRAWABLE_TYPE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|drawableBit
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_RENDER_TYPE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_RGBA_BIT
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_RED_SIZE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
operator|(
name|format
operator|.
name|redBufferSize
argument_list|()
operator|==
operator|-
literal|1
operator|)
condition|?
literal|1
else|:
name|format
operator|.
name|redBufferSize
argument_list|()
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_GREEN_SIZE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
operator|(
name|format
operator|.
name|greenBufferSize
argument_list|()
operator|==
operator|-
literal|1
operator|)
condition|?
literal|1
else|:
name|format
operator|.
name|greenBufferSize
argument_list|()
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_BLUE_SIZE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
operator|(
name|format
operator|.
name|blueBufferSize
argument_list|()
operator|==
operator|-
literal|1
operator|)
condition|?
literal|1
else|:
name|format
operator|.
name|blueBufferSize
argument_list|()
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|hasAlpha
argument_list|()
condition|)
block|{
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_ALPHA_SIZE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|format
operator|.
name|alphaBufferSize
argument_list|()
expr_stmt|;
block|}
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_DOUBLEBUFFER
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|format
operator|.
name|swapBehavior
argument_list|()
operator|!=
name|QSurfaceFormat
operator|::
name|SingleBuffer
condition|?
name|True
else|:
name|False
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_STEREO
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|format
operator|.
name|stereo
argument_list|()
condition|?
name|True
else|:
name|False
expr_stmt|;
if|if
condition|(
name|format
operator|.
name|depthBufferSize
argument_list|()
operator|>
literal|0
condition|)
block|{
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_DEPTH_SIZE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|format
operator|.
name|depthBufferSize
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|format
operator|.
name|stencilBufferSize
argument_list|()
operator|>
literal|0
condition|)
block|{
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_STENCIL_SIZE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
operator|(
name|format
operator|.
name|stencilBufferSize
argument_list|()
operator|==
operator|-
literal|1
operator|)
condition|?
literal|1
else|:
name|format
operator|.
name|stencilBufferSize
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|format
operator|.
name|samples
argument_list|()
operator|>
literal|1
condition|)
block|{
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_SAMPLE_BUFFERS_ARB
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
literal|1
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_SAMPLES_ARB
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|format
operator|.
name|samples
argument_list|()
expr_stmt|;
block|}
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|XNone
expr_stmt|;
return|return
name|spec
return|;
block|}
end_function
begin_function
DECL|function|qglx_findConfig
name|GLXFBConfig
name|qglx_findConfig
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|int
name|screen
parameter_list|,
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|int
name|drawableBit
parameter_list|)
block|{
name|bool
name|reduced
init|=
literal|true
decl_stmt|;
name|GLXFBConfig
name|chosenConfig
init|=
literal|0
decl_stmt|;
name|QSurfaceFormat
name|reducedFormat
init|=
name|format
decl_stmt|;
while|while
condition|(
operator|!
name|chosenConfig
operator|&&
name|reduced
condition|)
block|{
name|QVector
argument_list|<
name|int
argument_list|>
name|spec
init|=
name|qglx_buildSpec
argument_list|(
name|reducedFormat
argument_list|,
name|drawableBit
argument_list|)
decl_stmt|;
name|int
name|confcount
init|=
literal|0
decl_stmt|;
name|GLXFBConfig
modifier|*
name|configs
decl_stmt|;
name|configs
operator|=
name|glXChooseFBConfig
argument_list|(
name|display
argument_list|,
name|screen
argument_list|,
name|spec
operator|.
name|constData
argument_list|()
argument_list|,
operator|&
name|confcount
argument_list|)
expr_stmt|;
if|if
condition|(
name|confcount
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|confcount
condition|;
name|i
operator|++
control|)
block|{
name|chosenConfig
operator|=
name|configs
index|[
name|i
index|]
expr_stmt|;
comment|// Make sure we try to get an ARGB visual if the format asked for an alpha:
if|if
condition|(
name|reducedFormat
operator|.
name|hasAlpha
argument_list|()
condition|)
block|{
name|int
name|alphaSize
decl_stmt|;
name|glXGetFBConfigAttrib
argument_list|(
name|display
argument_list|,
name|configs
index|[
name|i
index|]
argument_list|,
name|GLX_ALPHA_SIZE
argument_list|,
operator|&
name|alphaSize
argument_list|)
expr_stmt|;
if|if
condition|(
name|alphaSize
operator|>
literal|0
condition|)
block|{
name|XVisualInfo
modifier|*
name|visual
init|=
name|glXGetVisualFromFBConfig
argument_list|(
name|display
argument_list|,
name|chosenConfig
argument_list|)
decl_stmt|;
name|bool
name|hasAlpha
init|=
literal|false
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_XRENDER
argument_list|)
name|XRenderPictFormat
modifier|*
name|pictFormat
init|=
name|XRenderFindVisualFormat
argument_list|(
name|display
argument_list|,
name|visual
operator|->
name|visual
argument_list|)
decl_stmt|;
name|hasAlpha
operator|=
name|pictFormat
operator|->
name|direct
operator|.
name|alphaMask
operator|>
literal|0
expr_stmt|;
else|#
directive|else
name|hasAlpha
operator|=
name|visual
operator|->
name|depth
operator|==
literal|32
expr_stmt|;
endif|#
directive|endif
name|XFree
argument_list|(
name|visual
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasAlpha
condition|)
break|break;
block|}
block|}
else|else
block|{
break|break;
comment|// Just choose the first in the list if there's no alpha requested
block|}
block|}
name|XFree
argument_list|(
name|configs
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|chosenConfig
condition|)
name|reducedFormat
operator|=
name|qglx_reduceSurfaceFormat
argument_list|(
name|reducedFormat
argument_list|,
operator|&
name|reduced
argument_list|)
expr_stmt|;
block|}
return|return
name|chosenConfig
return|;
block|}
end_function
begin_function
DECL|function|qglx_findVisualInfo
name|XVisualInfo
modifier|*
name|qglx_findVisualInfo
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|int
name|screen
parameter_list|,
name|QSurfaceFormat
modifier|*
name|format
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|XVisualInfo
modifier|*
name|visualInfo
init|=
literal|0
decl_stmt|;
name|GLXFBConfig
name|config
init|=
name|qglx_findConfig
argument_list|(
name|display
argument_list|,
name|screen
argument_list|,
operator|*
name|format
argument_list|)
decl_stmt|;
if|if
condition|(
name|config
condition|)
block|{
name|visualInfo
operator|=
name|glXGetVisualFromFBConfig
argument_list|(
name|display
argument_list|,
name|config
argument_list|)
expr_stmt|;
operator|*
name|format
operator|=
name|qglx_surfaceFormatFromGLXFBConfig
argument_list|(
name|display
argument_list|,
name|config
argument_list|)
expr_stmt|;
block|}
comment|// attempt to fall back to glXChooseVisual
name|bool
name|reduced
init|=
literal|true
decl_stmt|;
name|QSurfaceFormat
name|reducedFormat
init|=
operator|*
name|format
decl_stmt|;
while|while
condition|(
operator|!
name|visualInfo
operator|&&
name|reduced
condition|)
block|{
name|QVarLengthArray
argument_list|<
name|int
argument_list|,
literal|13
argument_list|>
name|attribs
decl_stmt|;
name|attribs
operator|.
name|append
argument_list|(
name|GLX_RGBA
argument_list|)
expr_stmt|;
if|if
condition|(
name|reducedFormat
operator|.
name|redBufferSize
argument_list|()
operator|>
literal|0
condition|)
block|{
name|attribs
operator|.
name|append
argument_list|(
name|GLX_RED_SIZE
argument_list|)
expr_stmt|;
name|attribs
operator|.
name|append
argument_list|(
name|reducedFormat
operator|.
name|redBufferSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|reducedFormat
operator|.
name|greenBufferSize
argument_list|()
operator|>
literal|0
condition|)
block|{
name|attribs
operator|.
name|append
argument_list|(
name|GLX_GREEN_SIZE
argument_list|)
expr_stmt|;
name|attribs
operator|.
name|append
argument_list|(
name|reducedFormat
operator|.
name|greenBufferSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|reducedFormat
operator|.
name|blueBufferSize
argument_list|()
operator|>
literal|0
condition|)
block|{
name|attribs
operator|.
name|append
argument_list|(
name|GLX_BLUE_SIZE
argument_list|)
expr_stmt|;
name|attribs
operator|.
name|append
argument_list|(
name|reducedFormat
operator|.
name|blueBufferSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|reducedFormat
operator|.
name|stencilBufferSize
argument_list|()
operator|>
literal|0
condition|)
block|{
name|attribs
operator|.
name|append
argument_list|(
name|GLX_STENCIL_SIZE
argument_list|)
expr_stmt|;
name|attribs
operator|.
name|append
argument_list|(
name|reducedFormat
operator|.
name|stencilBufferSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|reducedFormat
operator|.
name|depthBufferSize
argument_list|()
operator|>
literal|0
condition|)
block|{
name|attribs
operator|.
name|append
argument_list|(
name|GLX_DEPTH_SIZE
argument_list|)
expr_stmt|;
name|attribs
operator|.
name|append
argument_list|(
name|reducedFormat
operator|.
name|depthBufferSize
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|reducedFormat
operator|.
name|swapBehavior
argument_list|()
operator|!=
name|QSurfaceFormat
operator|::
name|SingleBuffer
condition|)
name|attribs
operator|.
name|append
argument_list|(
name|GLX_DOUBLEBUFFER
argument_list|)
expr_stmt|;
name|attribs
operator|.
name|append
argument_list|(
name|XNone
argument_list|)
expr_stmt|;
name|visualInfo
operator|=
name|glXChooseVisual
argument_list|(
name|display
argument_list|,
name|screen
argument_list|,
name|attribs
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|reducedFormat
operator|=
name|qglx_reduceSurfaceFormat
argument_list|(
name|reducedFormat
argument_list|,
operator|&
name|reduced
argument_list|)
expr_stmt|;
block|}
return|return
name|visualInfo
return|;
block|}
end_function
begin_function
DECL|function|qglx_surfaceFormatFromGLXFBConfig
name|QSurfaceFormat
name|qglx_surfaceFormatFromGLXFBConfig
parameter_list|(
name|Display
modifier|*
name|display
parameter_list|,
name|GLXFBConfig
name|config
parameter_list|,
name|GLXContext
parameter_list|)
block|{
name|QSurfaceFormat
name|format
decl_stmt|;
name|int
name|redSize
init|=
literal|0
decl_stmt|;
name|int
name|greenSize
init|=
literal|0
decl_stmt|;
name|int
name|blueSize
init|=
literal|0
decl_stmt|;
name|int
name|alphaSize
init|=
literal|0
decl_stmt|;
name|int
name|depthSize
init|=
literal|0
decl_stmt|;
name|int
name|stencilSize
init|=
literal|0
decl_stmt|;
name|int
name|sampleBuffers
init|=
literal|0
decl_stmt|;
name|int
name|sampleCount
init|=
literal|0
decl_stmt|;
name|int
name|stereo
init|=
literal|0
decl_stmt|;
name|XVisualInfo
modifier|*
name|vi
init|=
name|glXGetVisualFromFBConfig
argument_list|(
name|display
argument_list|,
name|config
argument_list|)
decl_stmt|;
name|XFree
argument_list|(
name|vi
argument_list|)
expr_stmt|;
name|glXGetFBConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|GLX_RED_SIZE
argument_list|,
operator|&
name|redSize
argument_list|)
expr_stmt|;
name|glXGetFBConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|GLX_GREEN_SIZE
argument_list|,
operator|&
name|greenSize
argument_list|)
expr_stmt|;
name|glXGetFBConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|GLX_BLUE_SIZE
argument_list|,
operator|&
name|blueSize
argument_list|)
expr_stmt|;
name|glXGetFBConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|GLX_ALPHA_SIZE
argument_list|,
operator|&
name|alphaSize
argument_list|)
expr_stmt|;
name|glXGetFBConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|GLX_DEPTH_SIZE
argument_list|,
operator|&
name|depthSize
argument_list|)
expr_stmt|;
name|glXGetFBConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|GLX_STENCIL_SIZE
argument_list|,
operator|&
name|stencilSize
argument_list|)
expr_stmt|;
name|glXGetFBConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|GLX_SAMPLES
argument_list|,
operator|&
name|sampleBuffers
argument_list|)
expr_stmt|;
name|glXGetFBConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|GLX_STEREO
argument_list|,
operator|&
name|stereo
argument_list|)
expr_stmt|;
name|format
operator|.
name|setRedBufferSize
argument_list|(
name|redSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setGreenBufferSize
argument_list|(
name|greenSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setBlueBufferSize
argument_list|(
name|blueSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setAlphaBufferSize
argument_list|(
name|alphaSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setDepthBufferSize
argument_list|(
name|depthSize
argument_list|)
expr_stmt|;
name|format
operator|.
name|setStencilBufferSize
argument_list|(
name|stencilSize
argument_list|)
expr_stmt|;
if|if
condition|(
name|sampleBuffers
condition|)
block|{
name|glXGetFBConfigAttrib
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
name|GLX_SAMPLES_ARB
argument_list|,
operator|&
name|sampleCount
argument_list|)
expr_stmt|;
name|format
operator|.
name|setSamples
argument_list|(
name|sampleCount
argument_list|)
expr_stmt|;
block|}
name|format
operator|.
name|setStereo
argument_list|(
name|stereo
argument_list|)
expr_stmt|;
return|return
name|format
return|;
block|}
end_function
begin_function
DECL|function|qglx_reduceSurfaceFormat
name|QSurfaceFormat
name|qglx_reduceSurfaceFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|bool
modifier|*
name|reduced
parameter_list|)
block|{
name|QSurfaceFormat
name|retFormat
init|=
name|format
decl_stmt|;
operator|*
name|reduced
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|retFormat
operator|.
name|redBufferSize
argument_list|()
operator|>
literal|1
condition|)
block|{
name|retFormat
operator|.
name|setRedBufferSize
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|retFormat
operator|.
name|greenBufferSize
argument_list|()
operator|>
literal|1
condition|)
block|{
name|retFormat
operator|.
name|setGreenBufferSize
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|retFormat
operator|.
name|blueBufferSize
argument_list|()
operator|>
literal|1
condition|)
block|{
name|retFormat
operator|.
name|setBlueBufferSize
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|retFormat
operator|.
name|samples
argument_list|()
operator|>
literal|1
condition|)
block|{
name|retFormat
operator|.
name|setSamples
argument_list|(
name|qMin
argument_list|(
name|retFormat
operator|.
name|samples
argument_list|()
operator|/
literal|2
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|retFormat
operator|.
name|stereo
argument_list|()
condition|)
block|{
name|retFormat
operator|.
name|setStereo
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|retFormat
operator|.
name|stencilBufferSize
argument_list|()
operator|>
literal|0
condition|)
block|{
name|retFormat
operator|.
name|setStencilBufferSize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|retFormat
operator|.
name|hasAlpha
argument_list|()
condition|)
block|{
name|retFormat
operator|.
name|setAlphaBufferSize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|retFormat
operator|.
name|depthBufferSize
argument_list|()
operator|>
literal|0
condition|)
block|{
name|retFormat
operator|.
name|setDepthBufferSize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|retFormat
operator|.
name|swapBehavior
argument_list|()
operator|!=
name|QSurfaceFormat
operator|::
name|SingleBuffer
condition|)
block|{
name|retFormat
operator|.
name|setSwapBehavior
argument_list|(
name|QSurfaceFormat
operator|::
name|SingleBuffer
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|*
name|reduced
operator|=
literal|false
expr_stmt|;
block|}
return|return
name|retFormat
return|;
block|}
end_function
end_unit
