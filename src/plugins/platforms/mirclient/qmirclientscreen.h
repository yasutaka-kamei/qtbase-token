begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014-2015 Canonical, Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMIRCLIENTSCREEN_H
end_ifndef
begin_define
DECL|macro|QMIRCLIENTSCREEN_H
define|#
directive|define
name|QMIRCLIENTSCREEN_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|"qmirclientcursor.h"
end_include
begin_struct_decl
struct_decl|struct
name|MirConnection
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QObject
name|class
name|QMirClientScreen
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformScreen
block|{
name|Q_OBJECT
name|public
range|:
name|QMirClientScreen
argument_list|(
name|MirConnection
operator|*
name|connection
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|QMirClientScreen
argument_list|()
expr_stmt|;
comment|// QPlatformScreen methods.
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
name|override
block|{
return|return
name|mFormat
return|;
block|}
name|int
name|depth
argument_list|()
specifier|const
name|override
block|{
return|return
name|mDepth
return|;
block|}
name|QRect
name|geometry
argument_list|()
specifier|const
name|override
block|{
return|return
name|mGeometry
return|;
block|}
name|QRect
name|availableGeometry
argument_list|()
specifier|const
name|override
block|{
return|return
name|mGeometry
return|;
block|}
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
name|override
block|{
return|return
name|mPhysicalSize
return|;
block|}
name|Qt
operator|::
name|ScreenOrientation
name|nativeOrientation
argument_list|()
specifier|const
name|override
block|{
return|return
name|mNativeOrientation
return|;
block|}
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
name|override
block|{
return|return
name|mNativeOrientation
return|;
block|}
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
name|override
block|{
return|return
name|const_cast
operator|<
name|QMirClientCursor
operator|*
operator|>
operator|(
operator|&
name|mCursor
operator|)
return|;
block|}
comment|// New methods.
name|QSurfaceFormat
name|surfaceFormat
argument_list|()
specifier|const
block|{
return|return
name|mSurfaceFormat
return|;
block|}
name|EGLDisplay
name|eglDisplay
argument_list|()
specifier|const
block|{
return|return
name|mEglDisplay
return|;
block|}
name|EGLConfig
name|eglConfig
argument_list|()
specifier|const
block|{
return|return
name|mEglConfig
return|;
block|}
name|EGLNativeDisplayType
name|eglNativeDisplay
argument_list|()
specifier|const
block|{
return|return
name|mEglNativeDisplay
return|;
block|}
name|void
name|handleWindowSurfaceResize
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
function_decl|;
name|uint32_t
name|mirOutputId
argument_list|()
specifier|const
block|{
return|return
name|mOutputId
return|;
block|}
comment|// QObject methods.
name|void
name|customEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
name|override
decl_stmt|;
name|private
label|:
name|QRect
name|mGeometry
decl_stmt|;
name|QSizeF
name|mPhysicalSize
decl_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|mNativeOrientation
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|mCurrentOrientation
expr_stmt|;
name|QImage
operator|::
name|Format
name|mFormat
expr_stmt|;
name|int
name|mDepth
decl_stmt|;
name|uint32_t
name|mOutputId
decl_stmt|;
name|QSurfaceFormat
name|mSurfaceFormat
decl_stmt|;
name|EGLDisplay
name|mEglDisplay
decl_stmt|;
name|EGLConfig
name|mEglConfig
decl_stmt|;
name|EGLNativeDisplayType
name|mEglNativeDisplay
decl_stmt|;
name|QMirClientCursor
name|mCursor
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMIRCLIENTSCREEN_H
end_comment
end_unit
