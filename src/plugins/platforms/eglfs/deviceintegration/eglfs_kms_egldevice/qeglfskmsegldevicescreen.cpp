begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Pelagicore AG ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfskmsegldevicescreen.h"
end_include
begin_include
include|#
directive|include
file|"qeglfskmsegldevice.h"
end_include
begin_constructor
DECL|function|QEglFSKmsEglDeviceScreen
name|QEglFSKmsEglDeviceScreen
operator|::
name|QEglFSKmsEglDeviceScreen
parameter_list|(
name|QEglFSKmsIntegration
modifier|*
name|integration
parameter_list|,
name|QEglFSKmsDevice
modifier|*
name|device
parameter_list|,
name|QEglFSKmsOutput
name|output
parameter_list|,
name|QPoint
name|position
parameter_list|)
member_init_list|:
name|QEglFSKmsScreen
argument_list|(
name|integration
argument_list|,
name|device
argument_list|,
name|output
argument_list|,
name|position
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|waitForFlip
name|void
name|QEglFSKmsEglDeviceScreen
operator|::
name|waitForFlip
parameter_list|()
block|{
if|if
condition|(
operator|!
name|output
argument_list|()
operator|.
name|mode_set
condition|)
block|{
name|output
argument_list|()
operator|.
name|mode_set
operator|=
literal|true
expr_stmt|;
name|drmModeCrtcPtr
name|currentMode
init|=
name|drmModeGetCrtc
argument_list|(
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|output
argument_list|()
operator|.
name|crtc_id
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|alreadySet
init|=
name|currentMode
operator|&&
name|currentMode
operator|->
name|width
operator|==
name|output
argument_list|()
operator|.
name|modes
index|[
name|output
argument_list|()
operator|.
name|mode
index|]
operator|.
name|hdisplay
operator|&&
name|currentMode
operator|->
name|height
operator|==
name|output
argument_list|()
operator|.
name|modes
index|[
name|output
argument_list|()
operator|.
name|mode
index|]
operator|.
name|vdisplay
decl_stmt|;
if|if
condition|(
name|currentMode
condition|)
name|drmModeFreeCrtc
argument_list|(
name|currentMode
argument_list|)
expr_stmt|;
if|if
condition|(
name|alreadySet
condition|)
block|{
comment|// Maybe detecting the DPMS mode could help here, but there are no properties
comment|// exposed on the connector apparently. So rely on an env var for now.
specifier|static
name|bool
name|alwaysDoSet
init|=
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_EGLFS_ALWAYS_SET_MODE"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|alwaysDoSet
condition|)
block|{
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Mode already set"
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|qCDebug
argument_list|(
name|qLcEglfsKmsDebug
argument_list|,
literal|"Setting mode"
argument_list|)
expr_stmt|;
name|int
name|ret
init|=
name|drmModeSetCrtc
argument_list|(
name|device
argument_list|()
operator|->
name|fd
argument_list|()
argument_list|,
name|output
argument_list|()
operator|.
name|crtc_id
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|output
argument_list|()
operator|.
name|connector_id
argument_list|,
literal|1
argument_list|,
operator|&
name|output
argument_list|()
operator|.
name|modes
index|[
name|output
argument_list|()
operator|.
name|mode
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
condition|)
name|qFatal
argument_list|(
literal|"drmModeSetCrtc failed"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
