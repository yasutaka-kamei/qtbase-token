begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBSCREEN_H
end_ifndef
begin_define
DECL|macro|QXCBSCREEN_H
define|#
directive|define
name|QXCBSCREEN_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<xcb/xcb.h>
end_include
begin_include
include|#
directive|include
file|<xcb/randr.h>
end_include
begin_include
include|#
directive|include
file|"qxcbobject.h"
end_include
begin_include
include|#
directive|include
file|"qxcbscreen.h"
end_include
begin_include
include|#
directive|include
file|<private/qfontengine_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QXcbConnection
name|class
name|QXcbConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbCursor
name|class
name|QXcbCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbXSettings
name|class
name|QXcbXSettings
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_decl_stmt
DECL|variable|QDebug
name|class
name|QDebug
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|QXcbVirtualDesktop
range|:
name|public
name|QXcbObject
block|{
name|public
operator|:
name|QXcbVirtualDesktop
argument_list|(
argument|QXcbConnection *connection
argument_list|,
argument|xcb_screen_t *screen
argument_list|,
argument|int number
argument_list|)
block|;
operator|~
name|QXcbVirtualDesktop
argument_list|()
block|;
name|xcb_screen_t
operator|*
name|screen
argument_list|()
specifier|const
block|{
return|return
name|m_screen
return|;
block|}
name|int
name|number
argument_list|()
specifier|const
block|{
return|return
name|m_number
return|;
block|}
name|QSize
name|size
argument_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
name|m_screen
operator|->
name|width_in_pixels
argument_list|,
name|m_screen
operator|->
name|height_in_pixels
argument_list|)
return|;
block|}
name|QSize
name|physicalSize
argument_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
name|m_screen
operator|->
name|width_in_millimeters
argument_list|,
name|m_screen
operator|->
name|height_in_millimeters
argument_list|)
return|;
block|}
name|QXcbXSettings
operator|*
name|xSettings
argument_list|()
specifier|const
block|;
name|private
operator|:
name|xcb_screen_t
operator|*
name|m_screen
block|;
name|int
name|m_number
block|;
name|QXcbXSettings
operator|*
name|m_xSettings
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QXcbObject
name|class
name|Q_XCB_EXPORT
name|QXcbScreen
range|:
name|public
name|QXcbObject
decl_stmt|,
name|public
name|QPlatformScreen
block|{
name|public
label|:
name|QXcbScreen
argument_list|(
argument|QXcbConnection *connection
argument_list|,
argument|QXcbVirtualDesktop *virtualDesktop
argument_list|,
argument|xcb_randr_output_t outputId
argument_list|,
argument|xcb_randr_get_output_info_reply_t *output
argument_list|,
argument|QString outputName
argument_list|)
empty_stmt|;
operator|~
name|QXcbScreen
argument_list|()
expr_stmt|;
name|QPixmap
name|grabWindow
argument_list|(
name|WId
name|window
argument_list|,
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
name|int
name|width
argument_list|,
name|int
name|height
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QWindow
modifier|*
name|topLevelAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|point
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QRect
name|geometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_geometry
return|;
block|}
name|QRect
name|nativeGeometry
argument_list|()
specifier|const
block|{
return|return
name|m_nativeGeometry
return|;
block|}
name|QRect
name|availableGeometry
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_availableGeometry
return|;
block|}
name|int
name|depth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|screen
argument_list|()
operator|->
name|root_depth
return|;
block|}
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_sizeMillimeters
return|;
block|}
name|QSize
name|virtualSize
argument_list|()
specifier|const
block|{
return|return
name|m_virtualSize
return|;
block|}
name|QSizeF
name|physicalVirtualSize
argument_list|()
specifier|const
block|{
return|return
name|m_virtualSizeMillimeters
return|;
block|}
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|qreal
name|refreshRate
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_refreshRate
return|;
block|}
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_orientation
return|;
block|}
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|virtualSiblings
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_siblings
return|;
block|}
name|void
name|setVirtualSiblings
argument_list|(
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|sl
argument_list|)
block|{
name|m_siblings
operator|=
name|sl
expr_stmt|;
block|}
name|void
name|removeVirtualSibling
parameter_list|(
name|QPlatformScreen
modifier|*
name|s
parameter_list|)
block|{
name|m_siblings
operator|.
name|removeOne
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
name|void
name|addVirtualSibling
parameter_list|(
name|QPlatformScreen
modifier|*
name|s
parameter_list|)
block|{
operator|(
operator|(
name|QXcbScreen
operator|*
operator|)
name|s
operator|)
operator|->
name|isPrimary
argument_list|()
condition|?
name|m_siblings
operator|.
name|prepend
argument_list|(
name|s
argument_list|)
else|:
name|m_siblings
operator|.
name|append
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
name|void
name|setPrimary
parameter_list|(
name|bool
name|primary
parameter_list|)
block|{
name|m_primary
operator|=
name|primary
expr_stmt|;
block|}
name|bool
name|isPrimary
argument_list|()
specifier|const
block|{
return|return
name|m_primary
return|;
block|}
name|int
name|screenNumber
argument_list|()
specifier|const
block|{
return|return
name|m_virtualDesktop
operator|->
name|number
argument_list|()
return|;
block|}
name|xcb_screen_t
operator|*
name|screen
argument_list|()
specifier|const
block|{
return|return
name|m_virtualDesktop
operator|->
name|screen
argument_list|()
return|;
block|}
name|xcb_window_t
name|root
argument_list|()
specifier|const
block|{
return|return
name|screen
argument_list|()
operator|->
name|root
return|;
block|}
name|xcb_randr_output_t
name|output
argument_list|()
specifier|const
block|{
return|return
name|m_output
return|;
block|}
name|xcb_randr_crtc_t
name|crtc
argument_list|()
specifier|const
block|{
return|return
name|m_crtc
return|;
block|}
name|xcb_randr_mode_t
name|mode
argument_list|()
specifier|const
block|{
return|return
name|m_mode
return|;
block|}
name|xcb_window_t
name|clientLeader
argument_list|()
specifier|const
block|{
return|return
name|m_clientLeader
return|;
block|}
name|void
name|windowShown
parameter_list|(
name|QXcbWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|QString
name|windowManagerName
argument_list|()
specifier|const
block|{
return|return
name|m_windowManagerName
return|;
block|}
name|bool
name|syncRequestSupported
argument_list|()
specifier|const
block|{
return|return
name|m_syncRequestSupported
return|;
block|}
specifier|const
name|xcb_visualtype_t
modifier|*
name|visualForId
argument_list|(
name|xcb_visualid_t
argument_list|)
decl|const
decl_stmt|;
name|quint8
name|depthOfVisual
argument_list|(
name|xcb_visualid_t
argument_list|)
decl|const
decl_stmt|;
name|QString
name|name
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_outputName
return|;
block|}
name|void
name|handleScreenChange
parameter_list|(
name|xcb_randr_screen_change_notify_event_t
modifier|*
name|change_event
parameter_list|)
function_decl|;
name|void
name|updateGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|geom
parameter_list|,
name|uint8_t
name|rotation
parameter_list|)
function_decl|;
name|void
name|updateGeometry
parameter_list|(
name|xcb_timestamp_t
name|timestamp
init|=
name|XCB_TIME_CURRENT_TIME
parameter_list|)
function_decl|;
name|void
name|updateRefreshRate
parameter_list|(
name|xcb_randr_mode_t
name|mode
parameter_list|)
function_decl|;
name|void
name|readXResources
parameter_list|()
function_decl|;
name|QFontEngine
operator|::
name|HintStyle
name|hintStyle
argument_list|()
specifier|const
block|{
return|return
name|m_hintStyle
return|;
block|}
name|bool
name|noFontHinting
argument_list|()
specifier|const
block|{
return|return
name|m_noFontHinting
return|;
block|}
name|QFontEngine
operator|::
name|SubpixelAntialiasingType
name|subpixelType
argument_list|()
specifier|const
block|{
return|return
name|m_subpixelType
return|;
block|}
name|int
name|antialiasingEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_antialiasingEnabled
return|;
block|}
name|QXcbXSettings
operator|*
name|xSettings
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
specifier|static
name|bool
name|xResource
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|identifier
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|expectedIdentifier
parameter_list|,
name|QByteArray
modifier|&
name|stringValue
parameter_list|)
function_decl|;
name|void
name|sendStartupMessage
argument_list|(
specifier|const
name|QByteArray
operator|&
name|message
argument_list|)
decl|const
decl_stmt|;
name|QXcbVirtualDesktop
modifier|*
name|m_virtualDesktop
decl_stmt|;
name|xcb_randr_output_t
name|m_output
decl_stmt|;
name|xcb_randr_crtc_t
name|m_crtc
decl_stmt|;
name|xcb_randr_mode_t
name|m_mode
decl_stmt|;
name|bool
name|m_primary
decl_stmt|;
name|uint8_t
name|m_rotation
decl_stmt|;
name|QString
name|m_outputName
decl_stmt|;
name|QSizeF
name|m_outputSizeMillimeters
decl_stmt|;
name|QSizeF
name|m_sizeMillimeters
decl_stmt|;
name|QRect
name|m_geometry
decl_stmt|;
name|QRect
name|m_nativeGeometry
decl_stmt|;
name|QRect
name|m_availableGeometry
decl_stmt|;
name|QSize
name|m_virtualSize
decl_stmt|;
name|QSizeF
name|m_virtualSizeMillimeters
decl_stmt|;
name|QList
operator|<
name|QPlatformScreen
operator|*
operator|>
name|m_siblings
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|m_orientation
expr_stmt|;
name|QString
name|m_windowManagerName
decl_stmt|;
name|bool
name|m_syncRequestSupported
decl_stmt|;
name|xcb_window_t
name|m_clientLeader
decl_stmt|;
name|QMap
operator|<
name|xcb_visualid_t
operator|,
name|xcb_visualtype_t
operator|>
name|m_visuals
expr_stmt|;
name|QMap
operator|<
name|xcb_visualid_t
operator|,
name|quint8
operator|>
name|m_visualDepths
expr_stmt|;
name|QXcbCursor
modifier|*
name|m_cursor
decl_stmt|;
name|int
name|m_refreshRate
decl_stmt|;
name|int
name|m_forcedDpi
decl_stmt|;
name|int
name|m_devicePixelRatio
decl_stmt|;
name|QFontEngine
operator|::
name|HintStyle
name|m_hintStyle
expr_stmt|;
name|bool
name|m_noFontHinting
decl_stmt|;
name|QFontEngine
operator|::
name|SubpixelAntialiasingType
name|m_subpixelType
expr_stmt|;
name|int
name|m_antialiasingEnabled
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QXcbScreen
operator|*
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
