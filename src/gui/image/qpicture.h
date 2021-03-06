begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPICTURE_H
end_ifndef
begin_define
DECL|macro|QPICTURE_H
define|#
directive|define
name|QPICTURE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qiodevice.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PICTURE
DECL|variable|QPicturePrivate
name|class
name|QPicturePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPicture
range|:
name|public
name|QPaintDevice
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPicture
argument_list|)
name|public
operator|:
name|explicit
name|QPicture
argument_list|(
argument|int formatVersion = -
literal|1
argument_list|)
block|;
name|QPicture
argument_list|(
specifier|const
name|QPicture
operator|&
argument_list|)
block|;
operator|~
name|QPicture
argument_list|()
block|;
name|bool
name|isNull
argument_list|()
specifier|const
block|;
name|int
name|devType
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|uint
name|size
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|data
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|setData
argument_list|(
argument|const char* data
argument_list|,
argument|uint size
argument_list|)
block|;
name|bool
name|play
argument_list|(
name|QPainter
operator|*
name|p
argument_list|)
block|;
name|bool
name|load
argument_list|(
name|QIODevice
operator|*
name|dev
argument_list|,
specifier|const
name|char
operator|*
name|format
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|bool
name|load
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|char
operator|*
name|format
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|bool
name|save
argument_list|(
name|QIODevice
operator|*
name|dev
argument_list|,
specifier|const
name|char
operator|*
name|format
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|bool
name|save
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|char
operator|*
name|format
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|QRect
name|boundingRect
argument_list|()
specifier|const
block|;
name|void
name|setBoundingRect
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
block|;
name|QPicture
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QPicture
operator|&
name|p
operator|)
block|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QPicture
operator|&
name|operator
operator|=
operator|(
name|QPicture
operator|&&
name|other
operator|)
name|Q_DECL_NOEXCEPT
block|{
name|qSwap
argument_list|(
name|d_ptr
argument_list|,
name|other
operator|.
name|d_ptr
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
argument_list|(
argument|QPicture&other
argument_list|)
name|Q_DECL_NOEXCEPT
block|{
name|d_ptr
operator|.
name|swap
argument_list|(
name|other
operator|.
name|d_ptr
argument_list|)
block|; }
name|void
name|detach
argument_list|()
block|;
name|bool
name|isDetached
argument_list|()
specifier|const
block|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|in
expr|,
specifier|const
name|QPicture
operator|&
name|p
operator|)
block|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
expr|,
name|QPicture
operator|&
name|p
operator|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|pictureFormat
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|inputFormats
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|outputFormats
argument_list|()
block|;
specifier|static
name|QStringList
name|inputFormatList
argument_list|()
block|;
specifier|static
name|QStringList
name|outputFormatList
argument_list|()
block|;
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|protected
operator|:
name|QPicture
argument_list|(
name|QPicturePrivate
operator|&
name|data
argument_list|)
block|;
name|int
name|metric
argument_list|(
argument|PaintDeviceMetric m
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|bool
name|exec
argument_list|(
argument|QPainter *p
argument_list|,
argument|QDataStream&ds
argument_list|,
argument|int i
argument_list|)
block|;
name|QExplicitlySharedDataPointer
operator|<
name|QPicturePrivate
operator|>
name|d_ptr
block|;
name|friend
name|class
name|QPicturePaintEngine
block|;
name|friend
name|class
name|QAlphaPaintEngine
block|;
name|friend
name|class
name|QPreviewPaintEngine
block|;
name|public
operator|:
typedef|typedef
name|QExplicitlySharedDataPointer
operator|<
name|QPicturePrivate
operator|>
name|DataPtr
expr_stmt|;
specifier|inline
name|DataPtr
operator|&
name|data_ptr
argument_list|()
block|{
return|return
name|d_ptr
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QPicture
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PICTUREIO
end_ifndef
begin_decl_stmt
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPictureIO
name|class
name|QPictureIO
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|picture_io_handler
typedef|typedef
name|void
function_decl|(
modifier|*
name|picture_io_handler
function_decl|)
parameter_list|(
name|QPictureIO
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_comment
DECL|typedef|picture_io_handler
comment|// picture IO handler
end_comment
begin_struct_decl
struct_decl|struct
name|QPictureIOData
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPictureIO
block|{
name|public
label|:
name|QPictureIO
argument_list|()
expr_stmt|;
name|QPictureIO
argument_list|(
name|QIODevice
operator|*
name|ioDevice
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|)
expr_stmt|;
name|QPictureIO
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|)
expr_stmt|;
operator|~
name|QPictureIO
argument_list|()
expr_stmt|;
specifier|const
name|QPicture
operator|&
name|picture
argument_list|()
specifier|const
expr_stmt|;
name|int
name|status
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|format
argument_list|()
specifier|const
expr_stmt|;
name|QIODevice
operator|*
name|ioDevice
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|fileName
argument_list|()
specifier|const
expr_stmt|;
name|int
name|quality
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|description
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|parameters
argument_list|()
specifier|const
expr_stmt|;
name|float
name|gamma
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPicture
parameter_list|(
specifier|const
name|QPicture
modifier|&
parameter_list|)
function_decl|;
name|void
name|setStatus
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
name|setFormat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
name|setIODevice
parameter_list|(
name|QIODevice
modifier|*
parameter_list|)
function_decl|;
name|void
name|setFileName
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|void
name|setQuality
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
name|setDescription
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
function_decl|;
name|void
name|setParameters
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
name|setGamma
parameter_list|(
name|float
parameter_list|)
function_decl|;
name|bool
name|read
parameter_list|()
function_decl|;
name|bool
name|write
parameter_list|()
function_decl|;
specifier|static
name|QByteArray
name|pictureFormat
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
specifier|static
name|QByteArray
name|pictureFormat
parameter_list|(
name|QIODevice
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|inputFormats
argument_list|()
expr_stmt|;
specifier|static
name|QList
operator|<
name|QByteArray
operator|>
name|outputFormats
argument_list|()
expr_stmt|;
specifier|static
name|void
name|defineIOHandler
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
specifier|const
name|char
modifier|*
name|header
parameter_list|,
specifier|const
name|char
modifier|*
name|flags
parameter_list|,
name|picture_io_handler
name|read_picture
parameter_list|,
name|picture_io_handler
name|write_picture
parameter_list|)
function_decl|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPictureIO
argument_list|)
name|void
name|init
parameter_list|()
function_decl|;
name|QPictureIOData
modifier|*
name|d
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
comment|//QT_NO_PICTUREIO
end_comment
begin_comment
comment|/*****************************************************************************   QPicture stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QPicture
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QPicture
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PICTURE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPICTURE_H
end_comment
end_unit
