begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXBUFFER_H
end_ifndef
begin_define
DECL|macro|QQNXBUFFER_H
define|#
directive|define
name|QQNXBUFFER_H
end_define
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|<screen/screen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QQnxBuffer
block|{
name|public
label|:
name|QQnxBuffer
argument_list|()
expr_stmt|;
name|QQnxBuffer
argument_list|(
argument|screen_buffer_t buffer
argument_list|)
empty_stmt|;
name|QQnxBuffer
argument_list|(
specifier|const
name|QQnxBuffer
operator|&
name|other
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QQnxBuffer
argument_list|()
expr_stmt|;
name|screen_buffer_t
name|nativeBuffer
argument_list|()
specifier|const
block|{
return|return
name|m_buffer
return|;
block|}
specifier|const
name|QImage
operator|*
name|image
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_buffer
operator|!=
name|NULL
operator|)
operator|?
operator|&
name|m_image
operator|:
name|NULL
return|;
block|}
name|QImage
modifier|*
name|image
parameter_list|()
block|{
return|return
operator|(
name|m_buffer
operator|!=
name|NULL
operator|)
condition|?
operator|&
name|m_image
else|:
name|NULL
return|;
block|}
name|QRect
name|rect
argument_list|()
specifier|const
block|{
return|return
name|m_image
operator|.
name|rect
argument_list|()
return|;
block|}
name|void
name|invalidateInCache
parameter_list|()
function_decl|;
name|private
label|:
name|screen_buffer_t
name|m_buffer
decl_stmt|;
name|QImage
name|m_image
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
comment|// QQNXBUFFER_H
end_comment
end_unit
