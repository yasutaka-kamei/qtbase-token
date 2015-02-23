begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbglxintegration.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_HAS_XCB_GLX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<xcb/glx.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qxcbnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qxcbglxwindow.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|"qglxintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|"qxcbglxnativeinterfacehandler.h"
end_include
begin_include
include|#
directive|include
file|<X11/Xlibint.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_HAS_XCB_GLX
argument_list|)
operator|&&
name|XCB_GLX_MAJOR_VERSION
operator|==
literal|1
operator|&&
name|XCB_GLX_MINOR_VERSION
operator|<
literal|4
end_if
begin_define
DECL|macro|XCB_GLX_BUFFER_SWAP_COMPLETE
define|#
directive|define
name|XCB_GLX_BUFFER_SWAP_COMPLETE
value|1
end_define
begin_typedef
DECL|struct|xcb_glx_buffer_swap_complete_event_t
typedef|typedef
struct|struct
name|xcb_glx_buffer_swap_complete_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
DECL|member|event_type
name|uint16_t
name|event_type
decl_stmt|;
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|2
index|]
decl_stmt|;
DECL|member|drawable
name|xcb_glx_drawable_t
name|drawable
decl_stmt|;
DECL|member|ust_hi
name|uint32_t
name|ust_hi
decl_stmt|;
DECL|member|ust_lo
name|uint32_t
name|ust_lo
decl_stmt|;
DECL|member|msc_hi
name|uint32_t
name|msc_hi
decl_stmt|;
DECL|member|msc_lo
name|uint32_t
name|msc_lo
decl_stmt|;
DECL|member|sbc
name|uint32_t
name|sbc
decl_stmt|;
block|}
DECL|typedef|xcb_glx_buffer_swap_complete_event_t
name|xcb_glx_buffer_swap_complete_event_t
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|XCB_USE_XLIB
argument_list|)
operator|&&
name|defined
argument_list|(
name|XCB_USE_GLX
argument_list|)
end_if
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|type
name|int
name|type
decl_stmt|;
DECL|member|serial
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
DECL|member|send_event
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
DECL|member|display
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
DECL|member|drawable
name|Drawable
name|drawable
decl_stmt|;
comment|/* drawable on which event was requested in event mask */
DECL|member|event_type
name|int
name|event_type
decl_stmt|;
DECL|member|ust
name|int64_t
name|ust
decl_stmt|;
DECL|member|msc
name|int64_t
name|msc
decl_stmt|;
DECL|member|sbc
name|int64_t
name|sbc
decl_stmt|;
block|}
DECL|typedef|QGLXBufferSwapComplete
name|QGLXBufferSwapComplete
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QXcbGlxIntegration
name|QXcbGlxIntegration
operator|::
name|QXcbGlxIntegration
parameter_list|()
member_init_list|:
name|m_connection
argument_list|(
name|Q_NULLPTR
argument_list|)
member_init_list|,
name|m_glx_first_event
argument_list|(
literal|0
argument_list|)
block|{
name|qCDebug
argument_list|(
name|QT_XCB_GLINTEGRATION
argument_list|)
operator|<<
literal|"Xcb GLX gl-integration created"
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QXcbGlxIntegration
name|QXcbGlxIntegration
operator|::
name|~
name|QXcbGlxIntegration
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initialize
name|bool
name|QXcbGlxIntegration
operator|::
name|initialize
parameter_list|(
name|QXcbConnection
modifier|*
name|connection
parameter_list|)
block|{
name|m_connection
operator|=
name|connection
expr_stmt|;
ifdef|#
directive|ifdef
name|XCB_HAS_XCB_GLX
specifier|const
name|xcb_query_extension_reply_t
modifier|*
name|reply
init|=
name|xcb_get_extension_data
argument_list|(
name|m_connection
operator|->
name|xcb_connection
argument_list|()
argument_list|,
operator|&
name|xcb_glx_id
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|reply
operator|||
operator|!
name|reply
operator|->
name|present
condition|)
return|return
literal|false
return|;
name|m_glx_first_event
operator|=
name|reply
operator|->
name|first_event
expr_stmt|;
name|xcb_generic_error_t
modifier|*
name|error
init|=
literal|0
decl_stmt|;
name|xcb_glx_query_version_cookie_t
name|xglx_query_cookie
init|=
name|xcb_glx_query_version
argument_list|(
name|m_connection
operator|->
name|xcb_connection
argument_list|()
argument_list|,
name|XCB_GLX_MAJOR_VERSION
argument_list|,
name|XCB_GLX_MINOR_VERSION
argument_list|)
decl_stmt|;
name|xcb_glx_query_version_reply_t
modifier|*
name|xglx_query
init|=
name|xcb_glx_query_version_reply
argument_list|(
name|m_connection
operator|->
name|xcb_connection
argument_list|()
argument_list|,
name|xglx_query_cookie
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|xglx_query
operator|||
name|error
condition|)
block|{
name|qCWarning
argument_list|(
name|QT_XCB_GLINTEGRATION
argument_list|)
operator|<<
literal|"QXcbConnection: Failed to initialize GLX"
expr_stmt|;
name|free
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|free
argument_list|(
name|xglx_query
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_native_interface_handler
operator|.
name|reset
argument_list|(
operator|new
name|QXcbGlxNativeInterfaceHandler
argument_list|(
name|connection
operator|->
name|nativeInterface
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|QT_XCB_GLINTEGRATION
argument_list|)
operator|<<
literal|"Xcb GLX gl-integration successfully initialized"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|handleXcbEvent
name|bool
name|QXcbGlxIntegration
operator|::
name|handleXcbEvent
parameter_list|(
name|xcb_generic_event_t
modifier|*
name|event
parameter_list|,
name|uint
name|responseType
parameter_list|)
block|{
name|bool
name|handled
init|=
literal|false
decl_stmt|;
comment|// Check if a custom XEvent constructor was registered in xlib for this event type, and call it discarding the constructed XEvent if any.
comment|// XESetWireToEvent might be used by libraries to intercept messages from the X server e.g. the OpenGL lib waiting for DRI2 events.
name|Display
modifier|*
name|xdisplay
init|=
cast|static_cast
argument_list|<
name|Display
operator|*
argument_list|>
argument_list|(
name|m_connection
operator|->
name|xlib_display
argument_list|()
argument_list|)
decl_stmt|;
name|XLockDisplay
argument_list|(
name|xdisplay
argument_list|)
expr_stmt|;
name|bool
name|locked
init|=
literal|true
decl_stmt|;
name|Bool
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|(
name|Display
modifier|*
parameter_list|,
name|XEvent
modifier|*
parameter_list|,
name|xEvent
modifier|*
parameter_list|)
init|=
name|XESetWireToEvent
argument_list|(
name|xdisplay
argument_list|,
name|responseType
argument_list|,
literal|0
argument_list|)
function_decl|;
if|if
condition|(
name|proc
condition|)
block|{
name|XESetWireToEvent
argument_list|(
name|xdisplay
argument_list|,
name|responseType
argument_list|,
name|proc
argument_list|)
expr_stmt|;
name|XEvent
name|dummy
decl_stmt|;
name|event
operator|->
name|sequence
operator|=
name|LastKnownRequestProcessed
argument_list|(
name|xdisplay
argument_list|)
expr_stmt|;
if|if
condition|(
name|proc
argument_list|(
name|xdisplay
argument_list|,
operator|&
name|dummy
argument_list|,
operator|(
name|xEvent
operator|*
operator|)
name|event
argument_list|)
condition|)
block|{
ifdef|#
directive|ifdef
name|XCB_HAS_XCB_GLX
comment|// DRI2 clients don't receive GLXBufferSwapComplete events on the wire.
comment|// Instead the GLX event is synthesized from the DRI2BufferSwapComplete event
comment|// by DRI2WireToEvent(). For an application to be able to see the event
comment|// we have to convert it to an xcb_glx_buffer_swap_complete_event_t and
comment|// pass it to the native event filter.
specifier|const
name|uint
name|swap_complete
init|=
name|m_glx_first_event
operator|+
name|XCB_GLX_BUFFER_SWAP_COMPLETE
decl_stmt|;
name|QAbstractEventDispatcher
modifier|*
name|dispatcher
init|=
name|QAbstractEventDispatcher
operator|::
name|instance
argument_list|()
decl_stmt|;
if|if
condition|(
name|dispatcher
operator|&&
name|uint
argument_list|(
name|dummy
operator|.
name|type
argument_list|)
operator|==
name|swap_complete
operator|&&
name|responseType
operator|!=
name|swap_complete
condition|)
block|{
name|QGLXBufferSwapComplete
modifier|*
name|xev
init|=
cast|reinterpret_cast
argument_list|<
name|QGLXBufferSwapComplete
operator|*
argument_list|>
argument_list|(
operator|&
name|dummy
argument_list|)
decl_stmt|;
name|xcb_glx_buffer_swap_complete_event_t
name|ev
decl_stmt|;
name|memset
argument_list|(
operator|&
name|ev
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|xcb_glx_buffer_swap_complete_event_t
argument_list|)
argument_list|)
expr_stmt|;
name|ev
operator|.
name|response_type
operator|=
name|xev
operator|->
name|type
expr_stmt|;
name|ev
operator|.
name|sequence
operator|=
name|xev
operator|->
name|serial
expr_stmt|;
name|ev
operator|.
name|event_type
operator|=
name|xev
operator|->
name|event_type
expr_stmt|;
name|ev
operator|.
name|drawable
operator|=
name|xev
operator|->
name|drawable
expr_stmt|;
name|ev
operator|.
name|ust_hi
operator|=
name|xev
operator|->
name|ust
operator|>>
literal|32
expr_stmt|;
name|ev
operator|.
name|ust_lo
operator|=
name|xev
operator|->
name|ust
operator|&
literal|0xffffffff
expr_stmt|;
name|ev
operator|.
name|msc_hi
operator|=
name|xev
operator|->
name|msc
operator|>>
literal|32
expr_stmt|;
name|ev
operator|.
name|msc_lo
operator|=
name|xev
operator|->
name|msc
operator|&
literal|0xffffffff
expr_stmt|;
name|ev
operator|.
name|sbc
operator|=
name|xev
operator|->
name|sbc
operator|&
literal|0xffffffff
expr_stmt|;
comment|// Unlock the display before calling the native event filter
name|XUnlockDisplay
argument_list|(
name|xdisplay
argument_list|)
expr_stmt|;
name|locked
operator|=
literal|false
expr_stmt|;
name|QByteArray
name|genericEventFilterType
init|=
name|m_connection
operator|->
name|nativeInterface
argument_list|()
operator|->
name|genericEventFilterType
argument_list|()
decl_stmt|;
name|long
name|result
init|=
literal|0
decl_stmt|;
name|handled
operator|=
name|dispatcher
operator|->
name|filterNativeEvent
argument_list|(
name|genericEventFilterType
argument_list|,
operator|&
name|ev
argument_list|,
operator|&
name|result
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
block|}
if|if
condition|(
name|locked
condition|)
name|XUnlockDisplay
argument_list|(
name|xdisplay
argument_list|)
expr_stmt|;
return|return
name|handled
return|;
block|}
end_function
begin_function
DECL|function|createWindow
name|QXcbWindow
modifier|*
name|QXcbGlxIntegration
operator|::
name|createWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
return|return
operator|new
name|QXcbGlxWindow
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
name|QXcbGlxIntegration
operator|::
name|createPlatformOpenGLContext
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
specifier|const
block|{
name|QXcbScreen
modifier|*
name|screen
init|=
cast|static_cast
argument_list|<
name|QXcbScreen
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|QGLXContext
modifier|*
name|platformContext
init|=
operator|new
name|QGLXContext
argument_list|(
name|screen
argument_list|,
name|context
operator|->
name|format
argument_list|()
argument_list|,
name|context
operator|->
name|shareHandle
argument_list|()
argument_list|,
name|context
operator|->
name|nativeHandle
argument_list|()
argument_list|)
decl_stmt|;
name|context
operator|->
name|setNativeHandle
argument_list|(
name|platformContext
operator|->
name|nativeHandle
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|platformContext
return|;
block|}
end_function
begin_function
DECL|function|createPlatformOffscreenSurface
name|QPlatformOffscreenSurface
modifier|*
name|QXcbGlxIntegration
operator|::
name|createPlatformOffscreenSurface
parameter_list|(
name|QOffscreenSurface
modifier|*
name|surface
parameter_list|)
specifier|const
block|{
specifier|static
name|bool
name|vendorChecked
init|=
literal|false
decl_stmt|;
specifier|static
name|bool
name|glxPbufferUsable
init|=
literal|true
decl_stmt|;
if|if
condition|(
operator|!
name|vendorChecked
condition|)
block|{
name|vendorChecked
operator|=
literal|true
expr_stmt|;
specifier|const
name|char
modifier|*
name|glxvendor
init|=
name|glXGetClientString
argument_list|(
name|glXGetCurrentDisplay
argument_list|()
argument_list|,
name|GLX_VENDOR
argument_list|)
decl_stmt|;
if|if
condition|(
name|glxvendor
operator|&&
operator|!
name|strcmp
argument_list|(
name|glxvendor
argument_list|,
literal|"ATI"
argument_list|)
condition|)
name|glxPbufferUsable
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
name|glxPbufferUsable
condition|)
return|return
operator|new
name|QGLXPbuffer
argument_list|(
name|surface
argument_list|)
return|;
else|else
return|return
literal|0
return|;
comment|// trigger fallback to hidden QWindow
block|}
end_function
begin_function
DECL|function|supportsThreadedOpenGL
name|bool
name|QXcbGlxIntegration
operator|::
name|supportsThreadedOpenGL
parameter_list|()
specifier|const
block|{
return|return
name|QGLXContext
operator|::
name|supportsThreading
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
