begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB). ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLPIXELUPLOADOPTIONS_H
end_ifndef
begin_define
DECL|macro|QOPENGLPIXELUPLOADOPTIONS_H
define|#
directive|define
name|QOPENGLPIXELUPLOADOPTIONS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/QSharedDataPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLPixelTransferOptionsData
name|class
name|QOpenGLPixelTransferOptionsData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLPixelTransferOptions
block|{
name|public
label|:
name|QOpenGLPixelTransferOptions
argument_list|()
expr_stmt|;
name|QOpenGLPixelTransferOptions
argument_list|(
specifier|const
name|QOpenGLPixelTransferOptions
operator|&
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
name|QOpenGLPixelTransferOptions
modifier|&
name|operator
init|=
operator|(
name|QOpenGLPixelTransferOptions
operator|&&
name|other
operator|)
name|Q_DECL_NOTHROW
block|{
name|swap
argument_list|(
name|other
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|QOpenGLPixelTransferOptions
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QOpenGLPixelTransferOptions
operator|&
operator|)
decl_stmt|;
operator|~
name|QOpenGLPixelTransferOptions
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QOpenGLPixelTransferOptions
modifier|&
name|other
parameter_list|)
function|Q_DECL_NOTHROW
block|{
name|data
operator|.
name|swap
argument_list|(
name|other
operator|.
name|data
argument_list|)
expr_stmt|;
block|}
name|void
name|setAlignment
parameter_list|(
name|int
name|alignment
parameter_list|)
function_decl|;
name|int
name|alignment
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSkipImages
parameter_list|(
name|int
name|skipImages
parameter_list|)
function_decl|;
name|int
name|skipImages
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSkipRows
parameter_list|(
name|int
name|skipRows
parameter_list|)
function_decl|;
name|int
name|skipRows
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSkipPixels
parameter_list|(
name|int
name|skipPixels
parameter_list|)
function_decl|;
name|int
name|skipPixels
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setImageHeight
parameter_list|(
name|int
name|imageHeight
parameter_list|)
function_decl|;
name|int
name|imageHeight
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRowLength
parameter_list|(
name|int
name|rowLength
parameter_list|)
function_decl|;
name|int
name|rowLength
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLeastSignificantByteFirst
parameter_list|(
name|bool
name|lsbFirst
parameter_list|)
function_decl|;
name|bool
name|isLeastSignificantBitFirst
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setSwapBytesEnabled
parameter_list|(
name|bool
name|swapBytes
parameter_list|)
function_decl|;
name|bool
name|isSwapBytesEnabled
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QOpenGLPixelTransferOptionsData
operator|>
name|data
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QOpenGLPixelTransferOptions
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_OPENGL
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QOPENGLPIXELUPLOADOPTIONS_H
end_comment
end_unit
