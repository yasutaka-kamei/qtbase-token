begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIRECTFBSCREEN_H
end_ifndef
begin_define
DECL|macro|QDIRECTFBSCREEN_H
define|#
directive|define
name|QDIRECTFBSCREEN_H
end_define
begin_include
include|#
directive|include
file|"qdirectfbconvenience.h"
end_include
begin_include
include|#
directive|include
file|"qdirectfbcursor.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<directfb.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDirectFbScreen
range|:
name|public
name|QPlatformScreen
block|{
name|public
operator|:
name|QDirectFbScreen
argument_list|(
argument|int display
argument_list|)
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|{
return|return
name|m_geometry
return|;
block|}
name|int
name|depth
argument_list|()
specifier|const
block|{
return|return
name|m_depth
return|;
block|}
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
block|{
return|return
name|m_physicalSize
return|;
block|}
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
block|{
return|return
name|m_cursor
operator|.
name|data
argument_list|()
return|;
block|}
comment|// DirectFb helpers
name|IDirectFBDisplayLayer
operator|*
name|dfbLayer
argument_list|()
specifier|const
block|;
name|public
operator|:
name|QRect
name|m_geometry
block|;
name|int
name|m_depth
block|;
name|QImage
operator|::
name|Format
name|m_format
block|;
name|QSizeF
name|m_physicalSize
block|;
name|QDirectFBPointer
operator|<
name|IDirectFBDisplayLayer
operator|>
name|m_layer
block|;
name|private
operator|:
name|QScopedPointer
operator|<
name|QDirectFBCursor
operator|>
name|m_cursor
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
