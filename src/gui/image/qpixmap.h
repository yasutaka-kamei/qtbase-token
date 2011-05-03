begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPIXMAP_H
end_ifndef
begin_define
DECL|macro|QPIXMAP_H
define|#
directive|define
name|QPIXMAP_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qpaintdevice.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_comment
comment|// char*->QString conversion
end_comment
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtransform.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
DECL|variable|CFbsBitmap
name|class
name|CFbsBitmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|RSgImage
name|class
name|RSgImage
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QImageWriter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImageReader
name|class
name|QImageReader
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QColor
name|class
name|QColor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QX11Info
name|class
name|QX11Info
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmapData
name|class
name|QPixmapData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPixmap
range|:
name|public
name|QPaintDevice
block|{
name|public
operator|:
name|QPixmap
argument_list|()
block|;
name|explicit
name|QPixmap
argument_list|(
name|QPixmapData
operator|*
name|data
argument_list|)
block|;
name|QPixmap
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|QPixmap
argument_list|(
specifier|const
name|QSize
operator|&
argument_list|)
block|;
name|QPixmap
argument_list|(
argument|const QString& fileName
argument_list|,
argument|const char *format =
literal|0
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_XPM
name|QPixmap
argument_list|(
specifier|const
name|char
operator|*
specifier|const
name|xpm
index|[]
argument_list|)
block|;
endif|#
directive|endif
name|QPixmap
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|)
block|;
operator|~
name|QPixmap
argument_list|()
block|;
name|QPixmap
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QPixmap
operator|&
operator|)
block|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QPixmap
operator|&
name|operator
operator|=
operator|(
name|QPixmap
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|data
argument_list|,
name|other
operator|.
name|data
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
argument|QPixmap&other
argument_list|)
block|{
name|qSwap
argument_list|(
name|data
argument_list|,
name|other
operator|.
name|data
argument_list|)
block|; }
name|operator
name|QVariant
argument_list|()
specifier|const
block|;
name|bool
name|isNull
argument_list|()
specifier|const
block|;
comment|// ### Qt 5: make inline
name|int
name|devType
argument_list|()
specifier|const
block|;
name|int
name|width
argument_list|()
specifier|const
block|;
comment|// ### Qt 5: make inline
name|int
name|height
argument_list|()
specifier|const
block|;
comment|// ### Qt 5: make inline
name|QSize
name|size
argument_list|()
specifier|const
block|;
name|QRect
name|rect
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
specifier|static
name|int
name|defaultDepth
argument_list|()
block|;
name|void
name|fill
argument_list|(
specifier|const
name|QColor
operator|&
name|fillColor
operator|=
name|Qt
operator|::
name|white
argument_list|)
block|;
name|void
name|fill
argument_list|(
specifier|const
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QPoint
operator|&
name|ofs
argument_list|)
block|;
specifier|inline
name|void
name|fill
argument_list|(
argument|const QWidget *widget
argument_list|,
argument|int xofs
argument_list|,
argument|int yofs
argument_list|)
block|{
name|fill
argument_list|(
name|widget
argument_list|,
name|QPoint
argument_list|(
name|xofs
argument_list|,
name|yofs
argument_list|)
argument_list|)
block|; }
name|QBitmap
name|mask
argument_list|()
specifier|const
block|;
name|void
name|setMask
argument_list|(
specifier|const
name|QBitmap
operator|&
argument_list|)
block|;
name|QPixmap
name|alphaChannel
argument_list|()
specifier|const
block|;
name|void
name|setAlphaChannel
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|)
block|;
name|bool
name|hasAlpha
argument_list|()
specifier|const
block|;
name|bool
name|hasAlphaChannel
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_IMAGE_HEURISTIC_MASK
name|QBitmap
name|createHeuristicMask
argument_list|(
argument|bool clipTight = true
argument_list|)
specifier|const
block|;
endif|#
directive|endif
name|QBitmap
name|createMaskFromColor
argument_list|(
argument|const QColor&maskColor
argument_list|)
specifier|const
block|;
comment|// ### Qt 5: remove
name|QBitmap
name|createMaskFromColor
argument_list|(
argument|const QColor&maskColor
argument_list|,
argument|Qt::MaskMode mode
argument_list|)
specifier|const
block|;
specifier|static
name|QPixmap
name|grabWindow
argument_list|(
argument|WId
argument_list|,
argument|int x=
literal|0
argument_list|,
argument|int y=
literal|0
argument_list|,
argument|int w=-
literal|1
argument_list|,
argument|int h=-
literal|1
argument_list|)
block|;
specifier|static
name|QPixmap
name|grabWidget
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
specifier|static
specifier|inline
name|QPixmap
name|grabWidget
argument_list|(
argument|QWidget *widget
argument_list|,
argument|int x=
literal|0
argument_list|,
argument|int y=
literal|0
argument_list|,
argument|int w=-
literal|1
argument_list|,
argument|int h=-
literal|1
argument_list|)
block|{
return|return
name|grabWidget
argument_list|(
name|widget
argument_list|,
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|QPixmap
name|scaled
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|,
argument|Qt::AspectRatioMode aspectMode = Qt::IgnoreAspectRatio
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|{
return|return
name|scaled
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|aspectMode
argument_list|,
name|mode
argument_list|)
return|;
block|}
name|QPixmap
name|scaled
argument_list|(
argument|const QSize&s
argument_list|,
argument|Qt::AspectRatioMode aspectMode = Qt::IgnoreAspectRatio
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
name|QPixmap
name|scaledToWidth
argument_list|(
argument|int w
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
name|QPixmap
name|scaledToHeight
argument_list|(
argument|int h
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
name|QPixmap
name|transformed
argument_list|(
argument|const QMatrix&
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
specifier|static
name|QMatrix
name|trueMatrix
argument_list|(
argument|const QMatrix&m
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|QPixmap
name|transformed
argument_list|(
argument|const QTransform&
argument_list|,
argument|Qt::TransformationMode mode = Qt::FastTransformation
argument_list|)
specifier|const
block|;
specifier|static
name|QTransform
name|trueMatrix
argument_list|(
argument|const QTransform&m
argument_list|,
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
block|;
specifier|static
name|QPixmap
name|fromImage
argument_list|(
argument|const QImage&image
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
specifier|static
name|QPixmap
name|fromImageReader
argument_list|(
argument|QImageReader *imageReader
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
name|bool
name|load
argument_list|(
argument|const QString& fileName
argument_list|,
argument|const char *format =
literal|0
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
name|bool
name|loadFromData
argument_list|(
argument|const uchar *buf
argument_list|,
argument|uint len
argument_list|,
argument|const char* format =
literal|0
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
specifier|inline
name|bool
name|loadFromData
argument_list|(
argument|const QByteArray&data
argument_list|,
argument|const char* format =
literal|0
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
name|bool
name|save
argument_list|(
argument|const QString& fileName
argument_list|,
argument|const char* format =
literal|0
argument_list|,
argument|int quality = -
literal|1
argument_list|)
specifier|const
block|;
name|bool
name|save
argument_list|(
argument|QIODevice* device
argument_list|,
argument|const char* format =
literal|0
argument_list|,
argument|int quality = -
literal|1
argument_list|)
specifier|const
block|;
name|bool
name|convertFromImage
argument_list|(
argument|const QImage&img
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
block|enum
name|HBitmapFormat
block|{
name|NoAlpha
block|,
name|PremultipliedAlpha
block|,
name|Alpha
block|}
block|;
name|HBITMAP
name|toWinHBITMAP
argument_list|(
argument|HBitmapFormat format = NoAlpha
argument_list|)
specifier|const
block|;
name|HICON
name|toWinHICON
argument_list|()
specifier|const
block|;
specifier|static
name|QPixmap
name|fromWinHBITMAP
argument_list|(
argument|HBITMAP hbitmap
argument_list|,
argument|HBitmapFormat format = NoAlpha
argument_list|)
block|;
specifier|static
name|QPixmap
name|fromWinHICON
argument_list|(
argument|HICON hicon
argument_list|)
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|CGImageRef
name|toMacCGImageRef
argument_list|()
specifier|const
block|;
specifier|static
name|QPixmap
name|fromMacCGImageRef
argument_list|(
argument|CGImageRef image
argument_list|)
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|CFbsBitmap
operator|*
name|toSymbianCFbsBitmap
argument_list|()
specifier|const
block|;
specifier|static
name|QPixmap
name|fromSymbianCFbsBitmap
argument_list|(
name|CFbsBitmap
operator|*
name|bitmap
argument_list|)
block|;
name|RSgImage
operator|*
name|toSymbianRSgImage
argument_list|()
specifier|const
block|;
specifier|static
name|QPixmap
name|fromSymbianRSgImage
argument_list|(
name|RSgImage
operator|*
name|sgImage
argument_list|)
block|;
endif|#
directive|endif
specifier|inline
name|QPixmap
name|copy
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|)
specifier|const
block|;
name|QPixmap
name|copy
argument_list|(
argument|const QRect&rect = QRect()
argument_list|)
specifier|const
block|;
specifier|inline
name|void
name|scroll
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|,
argument|int x
argument_list|,
argument|int y
argument_list|,
argument|int width
argument_list|,
argument|int height
argument_list|,
argument|QRegion *exposed =
literal|0
argument_list|)
block|;
name|void
name|scroll
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|,
argument|const QRect&rect
argument_list|,
argument|QRegion *exposed =
literal|0
argument_list|)
block|;
name|int
name|serialNumber
argument_list|()
specifier|const
block|;
name|qint64
name|cacheKey
argument_list|()
specifier|const
block|;
name|bool
name|isDetached
argument_list|()
specifier|const
block|;
name|void
name|detach
argument_list|()
block|;
name|bool
name|isQBitmap
argument_list|()
specifier|const
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
specifier|const
name|uchar
operator|*
name|qwsBits
argument_list|()
specifier|const
block|;
name|int
name|qwsBytesPerLine
argument_list|()
specifier|const
block|;
name|QRgb
operator|*
name|clut
argument_list|()
specifier|const
block|;
ifdef|#
directive|ifdef
name|QT_DEPRECATED
name|QT_DEPRECATED
name|int
name|numCols
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|int
name|colorCount
argument_list|()
specifier|const
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|Qt
operator|::
name|HANDLE
name|macQDHandle
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|HANDLE
name|macQDAlphaHandle
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|HANDLE
name|macCGHandle
argument_list|()
specifier|const
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
block|enum
name|ShareMode
block|{
name|ImplicitlyShared
block|,
name|ExplicitlyShared
block|}
block|;
specifier|static
name|QPixmap
name|fromX11Pixmap
argument_list|(
argument|Qt::HANDLE pixmap
argument_list|,
argument|ShareMode mode = ImplicitlyShared
argument_list|)
block|;
specifier|static
name|int
name|x11SetDefaultScreen
argument_list|(
argument|int screen
argument_list|)
block|;
name|void
name|x11SetScreen
argument_list|(
argument|int screen
argument_list|)
block|;
specifier|const
name|QX11Info
operator|&
name|x11Info
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|HANDLE
name|x11PictureHandle
argument_list|()
specifier|const
block|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|QPaintEngine
operator|*
name|paintEngine
argument_list|()
specifier|const
block|;
specifier|inline
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
name|isNull
argument_list|()
return|;
block|}
name|protected
operator|:
name|int
name|metric
argument_list|(
argument|PaintDeviceMetric
argument_list|)
specifier|const
block|;
name|private
operator|:
name|QExplicitlySharedDataPointer
operator|<
name|QPixmapData
operator|>
name|data
block|;
name|bool
name|doImageIO
argument_list|(
argument|QImageWriter *io
argument_list|,
argument|int quality
argument_list|)
specifier|const
block|;
comment|// ### Qt5: remove the following three lines
block|enum
name|Type
block|{
name|PixmapType
block|,
name|BitmapType
block|}
block|;
comment|// must match QPixmapData::PixelType
name|QPixmap
argument_list|(
specifier|const
name|QSize
operator|&
name|s
argument_list|,
name|Type
argument_list|)
block|;
name|void
name|init
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|Type
operator|=
name|PixmapType
argument_list|)
block|;
name|QPixmap
argument_list|(
argument|const QSize&s
argument_list|,
argument|int type
argument_list|)
block|;
name|void
name|init
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
block|;
name|void
name|deref
argument_list|()
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_WIN
argument_list|)
name|void
name|initAlphaPixmap
argument_list|(
argument|uchar *bytes
argument_list|,
argument|int length
argument_list|,
argument|struct tagBITMAPINFO *bmi
argument_list|)
block|;
endif|#
directive|endif
name|Q_DUMMY_COMPARISON_OPERATOR
argument_list|(
argument|QPixmap
argument_list|)
ifdef|#
directive|ifdef
name|Q_WS_MAC
name|friend
name|CGContextRef
name|qt_mac_cg_context
argument_list|(
specifier|const
name|QPaintDevice
operator|*
argument_list|)
block|;
name|friend
name|CGImageRef
name|qt_mac_create_imagemask
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|,
specifier|const
name|QRectF
operator|&
argument_list|)
block|;
name|friend
name|IconRef
name|qt_mac_create_iconref
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|)
block|;
name|friend
name|quint32
operator|*
name|qt_mac_pixmap_get_base
argument_list|(
specifier|const
name|QPixmap
operator|*
argument_list|)
block|;
name|friend
name|int
name|qt_mac_pixmap_get_bytes_per_line
argument_list|(
specifier|const
name|QPixmap
operator|*
argument_list|)
block|;
endif|#
directive|endif
name|friend
name|class
name|QPixmapData
block|;
name|friend
name|class
name|QX11PixmapData
block|;
name|friend
name|class
name|QMacPixmapData
block|;
name|friend
name|class
name|QS60PixmapData
block|;
name|friend
name|class
name|QBitmap
block|;
name|friend
name|class
name|QPaintDevice
block|;
name|friend
name|class
name|QPainter
block|;
name|friend
name|class
name|QGLWidget
block|;
name|friend
name|class
name|QX11PaintEngine
block|;
name|friend
name|class
name|QCoreGraphicsPaintEngine
block|;
name|friend
name|class
name|QWidgetPrivate
block|;
name|friend
name|class
name|QRasterBuffer
block|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DATASTREAM
argument_list|)
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
expr|,
name|QPixmap
operator|&
operator|)
block|;
endif|#
directive|endif
name|friend
name|Q_GUI_EXPORT
name|qint64
name|qt_pixmap_id
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|)
block|;
name|public
operator|:
name|QPixmapData
operator|*
name|pixmapData
argument_list|()
specifier|const
block|;
name|public
operator|:
typedef|typedef
name|QExplicitlySharedDataPointer
operator|<
name|QPixmapData
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
name|data
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QPixmap
argument_list|)
end_macro
begin_expr_stmt
specifier|inline
name|QPixmap
name|QPixmap
operator|::
name|copy
argument_list|(
argument|int ax
argument_list|,
argument|int ay
argument_list|,
argument|int awidth
argument_list|,
argument|int aheight
argument_list|)
specifier|const
block|{
return|return
name|copy
argument_list|(
name|QRect
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|awidth
argument_list|,
name|aheight
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|scroll
specifier|inline
name|void
name|QPixmap
operator|::
name|scroll
argument_list|(
argument|int dx
argument_list|,
argument|int dy
argument_list|,
argument|int ax
argument_list|,
argument|int ay
argument_list|,
argument|int awidth
argument_list|,
argument|int aheight
argument_list|,
argument|QRegion *exposed
argument_list|)
block|{
name|scroll
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|,
name|QRect
argument_list|(
name|ax
argument_list|,
name|ay
argument_list|,
name|awidth
argument_list|,
name|aheight
argument_list|)
argument_list|,
name|exposed
argument_list|)
block|; }
DECL|function|loadFromData
specifier|inline
name|bool
name|QPixmap
operator|::
name|loadFromData
argument_list|(
argument|const QByteArray&buf
argument_list|,
argument|const char *format
argument_list|,
argument|Qt::ImageConversionFlags flags
argument_list|)
block|{
return|return
name|loadFromData
argument_list|(
name|reinterpret_cast
operator|<
specifier|const
name|uchar
operator|*
operator|>
operator|(
name|buf
operator|.
name|constData
argument_list|()
operator|)
argument_list|,
name|buf
operator|.
name|size
argument_list|()
argument_list|,
name|format
argument_list|,
name|flags
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|/*****************************************************************************  QPixmap stream functions *****************************************************************************/
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DATASTREAM
argument_list|)
end_if
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
name|QPixmap
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
name|QPixmap
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPIXMAP_H
end_comment
end_unit
