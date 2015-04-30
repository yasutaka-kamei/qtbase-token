begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSNATIVEIMAGE_H
end_ifndef
begin_define
DECL|macro|QWINDOWSNATIVEIMAGE_H
define|#
directive|define
name|QWINDOWSNATIVEIMAGE_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QWindowsNativeImage
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsNativeImage
argument_list|)
name|public
label|:
name|QWindowsNativeImage
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|QImage::Format format
argument_list|)
empty_stmt|;
operator|~
name|QWindowsNativeImage
argument_list|()
expr_stmt|;
specifier|inline
name|int
name|width
argument_list|()
specifier|const
block|{
return|return
name|m_image
operator|.
name|width
argument_list|()
return|;
block|}
specifier|inline
name|int
name|height
argument_list|()
specifier|const
block|{
return|return
name|m_image
operator|.
name|height
argument_list|()
return|;
block|}
name|QImage
modifier|&
name|image
parameter_list|()
block|{
return|return
name|m_image
return|;
block|}
specifier|const
name|QImage
operator|&
name|image
argument_list|()
specifier|const
block|{
return|return
name|m_image
return|;
block|}
name|HDC
name|hdc
argument_list|()
specifier|const
block|{
return|return
name|m_hdc
return|;
block|}
specifier|static
name|QImage
operator|::
name|Format
name|systemFormat
argument_list|()
expr_stmt|;
name|private
label|:
specifier|const
name|HDC
name|m_hdc
decl_stmt|;
name|QImage
name|m_image
decl_stmt|;
name|HBITMAP
name|m_bitmap
decl_stmt|;
name|HBITMAP
name|m_null_bitmap
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSNATIVEIMAGE_H
end_comment
end_unit
