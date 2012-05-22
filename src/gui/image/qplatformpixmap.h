begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXMAPDATA_P_H
end_ifndef
begin_define
DECL|macro|QPIXMAPDATA_P_H
define|#
directive|define
name|QPIXMAPDATA_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QImageReader
name|class
name|QImageReader
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformPixmap
block|{
name|public
label|:
enum|enum
name|PixelType
block|{
comment|// WARNING: Do not change the first two
comment|// Must match QPixmap::Type
name|PixmapType
block|,
name|BitmapType
block|}
enum|;
enum|enum
name|ClassId
block|{
name|RasterClass
block|,
name|DirectFBClass
block|,
name|BlitterClass
block|,
name|CustomClass
init|=
literal|1024
block|}
enum|;
name|QPlatformPixmap
argument_list|(
argument|PixelType pixelType
argument_list|,
argument|int classId
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|QPlatformPixmap
argument_list|()
expr_stmt|;
name|virtual
name|QPlatformPixmap
operator|*
name|createCompatiblePlatformPixmap
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|resize
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|fromImage
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|fromImageReader
argument_list|(
name|QImageReader
operator|*
name|imageReader
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|fromFile
argument_list|(
specifier|const
name|QString
operator|&
name|filename
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|fromData
argument_list|(
specifier|const
name|uchar
operator|*
name|buffer
argument_list|,
name|uint
name|len
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
name|flags
argument_list|)
decl_stmt|;
name|virtual
name|void
name|copy
parameter_list|(
specifier|const
name|QPlatformPixmap
modifier|*
name|data
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|virtual
name|bool
name|scroll
parameter_list|(
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|virtual
name|int
name|metric
argument_list|(
name|QPaintDevice
operator|::
name|PaintDeviceMetric
name|metric
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|fill
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QPixmap
name|transformed
argument_list|(
specifier|const
name|QTransform
operator|&
name|matrix
argument_list|,
name|Qt
operator|::
name|TransformationMode
name|mode
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QImage
name|toImage
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QImage
name|toImage
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
specifier|inline
name|int
name|serialNumber
argument_list|()
specifier|const
block|{
return|return
name|ser_no
return|;
block|}
specifier|inline
name|PixelType
name|pixelType
argument_list|()
specifier|const
block|{
return|return
name|type
return|;
block|}
specifier|inline
name|ClassId
name|classId
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ClassId
operator|>
operator|(
name|id
operator|)
return|;
block|}
name|virtual
name|QImage
modifier|*
name|buffer
parameter_list|()
function_decl|;
specifier|inline
name|int
name|width
argument_list|()
specifier|const
block|{
return|return
name|w
return|;
block|}
specifier|inline
name|int
name|height
argument_list|()
specifier|const
block|{
return|return
name|h
return|;
block|}
specifier|inline
name|int
name|colorCount
argument_list|()
specifier|const
block|{
return|return
name|metric
argument_list|(
name|QPaintDevice
operator|::
name|PdmNumColors
argument_list|)
return|;
block|}
specifier|inline
name|int
name|depth
argument_list|()
specifier|const
block|{
return|return
name|d
return|;
block|}
specifier|inline
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|is_null
return|;
block|}
specifier|inline
name|qint64
name|cacheKey
argument_list|()
specifier|const
block|{
name|int
name|classKey
operator|=
name|id
block|;
if|if
condition|(
name|classKey
operator|>=
literal|1024
condition|)
name|classKey
operator|=
operator|-
operator|(
name|classKey
operator|>>
literal|10
operator|)
expr_stmt|;
return|return
operator|(
operator|(
operator|(
operator|(
name|qint64
operator|)
name|classKey
operator|)
operator|<<
literal|56
operator|)
operator||
operator|(
operator|(
operator|(
name|qint64
operator|)
name|ser_no
operator|)
operator|<<
literal|32
operator|)
operator||
operator|(
operator|(
name|qint64
operator|)
name|detach_no
operator|)
operator|)
return|;
block|}
end_decl_stmt
begin_function_decl
specifier|static
name|QPlatformPixmap
modifier|*
name|create
parameter_list|(
name|int
name|w
parameter_list|,
name|int
name|h
parameter_list|,
name|PixelType
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_function_decl
name|void
name|setSerialNumber
parameter_list|(
name|int
name|serNo
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|int
name|w
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|h
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|d
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|is_null
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|friend
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QImagePixmapCleanupHooks
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Needs to set is_cached
end_comment
begin_decl_stmt
name|friend
name|class
name|QOpenGLTextureCache
decl_stmt|;
end_decl_stmt
begin_comment
comment|//Needs to check the reference count
end_comment
begin_expr_stmt
name|friend
name|class
name|QExplicitlySharedDataPointer
operator|<
name|QPlatformPixmap
operator|>
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QAtomicInt
name|ref
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|detach_no
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PixelType
name|type
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|id
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|ser_no
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|uint
name|is_cached
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|QT_XFORM_TYPE_MSBFIRST
unit|};
define|#
directive|define
name|QT_XFORM_TYPE_MSBFIRST
value|0
end_define
begin_define
DECL|macro|QT_XFORM_TYPE_LSBFIRST
define|#
directive|define
name|QT_XFORM_TYPE_LSBFIRST
value|1
end_define
begin_function_decl
specifier|extern
name|bool
name|qt_xForm_helper
parameter_list|(
specifier|const
name|QTransform
modifier|&
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uchar
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|uchar
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPIXMAPDATA_P_H
end_comment
end_unit
