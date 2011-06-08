begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qpaintdevice.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|"qwidget.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qprinter.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<private/qt_mac_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qprintengine_mac_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpixmap_mac_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qpixmap_raster_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*****************************************************************************   Internal variables and functions  *****************************************************************************/
comment|/*! \internal */
DECL|function|qt_mac_defaultDpi_x
name|float
name|qt_mac_defaultDpi_x
parameter_list|()
block|{
comment|// Mac OS X currently assumes things to be 72 dpi.
comment|// (see http://developer.apple.com/releasenotes/GraphicsImaging/RN-ResolutionIndependentUI/)
comment|// This may need to be re-worked as we go further in the resolution-independence stuff.
return|return
literal|72
return|;
block|}
end_function
begin_comment
comment|/*! \internal */
end_comment
begin_function
DECL|function|qt_mac_defaultDpi_y
name|float
name|qt_mac_defaultDpi_y
parameter_list|()
block|{
comment|// Mac OS X currently assumes things to be 72 dpi.
comment|// (see http://developer.apple.com/releasenotes/GraphicsImaging/RN-ResolutionIndependentUI/)
comment|// This may need to be re-worked as we go further in the resolution-independence stuff.
return|return
literal|72
return|;
block|}
end_function
begin_comment
comment|/*! \internal      Returns the QuickDraw CGrafPtr of the paint device. 0 is returned     if it can't be obtained. Do not hold the pointer around for long     as it can be relocated.      \warning This function is only available on Mac OS X. */
end_comment
begin_function
DECL|function|qt_mac_qd_context
name|Q_WIDGETS_EXPORT
name|GrafPtr
name|qt_mac_qd_context
parameter_list|(
specifier|const
name|QPaintDevice
modifier|*
name|device
parameter_list|)
block|{
if|if
condition|(
name|device
operator|->
name|devType
argument_list|()
operator|==
name|QInternal
operator|::
name|Pixmap
condition|)
block|{
return|return
cast|static_cast
argument_list|<
name|GrafPtr
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QPixmap
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
operator|->
name|macQDHandle
argument_list|()
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|device
operator|->
name|devType
argument_list|()
operator|==
name|QInternal
operator|::
name|Widget
condition|)
block|{
return|return
cast|static_cast
argument_list|<
name|GrafPtr
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QWidget
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
operator|->
name|macQDHandle
argument_list|()
argument_list|)
return|;
block|}
elseif|else
if|if
condition|(
name|device
operator|->
name|devType
argument_list|()
operator|==
name|QInternal
operator|::
name|Printer
condition|)
block|{
name|QPaintEngine
modifier|*
name|engine
init|=
cast|static_cast
argument_list|<
specifier|const
name|QPrinter
operator|*
argument_list|>
argument_list|(
name|device
argument_list|)
operator|->
name|paintEngine
argument_list|()
decl_stmt|;
return|return
cast|static_cast
argument_list|<
name|GrafPtr
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QMacPrintEngine
operator|*
argument_list|>
argument_list|(
name|engine
argument_list|)
operator|->
name|handle
argument_list|()
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function_decl
specifier|extern
name|CGColorSpaceRef
name|qt_mac_colorSpaceForDeviceType
parameter_list|(
specifier|const
name|QPaintDevice
modifier|*
name|pdev
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*! \internal      Returns the CoreGraphics CGContextRef of the paint device. 0 is     returned if it can't be obtained. It is the caller's responsiblity to     CGContextRelease the context when finished using it.      \warning This function is only available on Mac OS X. */
end_comment
begin_function
DECL|function|qt_mac_cg_context
name|Q_WIDGETS_EXPORT
name|CGContextRef
name|qt_mac_cg_context
parameter_list|(
specifier|const
name|QPaintDevice
modifier|*
name|pdev
parameter_list|)
block|{
if|if
condition|(
name|pdev
operator|->
name|devType
argument_list|()
operator|==
name|QInternal
operator|::
name|Pixmap
condition|)
block|{
specifier|const
name|QPixmap
modifier|*
name|pm
init|=
cast|static_cast
argument_list|<
specifier|const
name|QPixmap
operator|*
argument_list|>
argument_list|(
name|pdev
argument_list|)
decl_stmt|;
name|CGColorSpaceRef
name|colorspace
init|=
name|qt_mac_colorSpaceForDeviceType
argument_list|(
name|pdev
argument_list|)
decl_stmt|;
name|uint
name|flags
init|=
name|kCGImageAlphaPremultipliedFirst
decl_stmt|;
ifdef|#
directive|ifdef
name|kCGBitmapByteOrder32Host
comment|//only needed because CGImage.h added symbols in the minor version
name|flags
operator||=
name|kCGBitmapByteOrder32Host
expr_stmt|;
endif|#
directive|endif
name|CGContextRef
name|ret
init|=
literal|0
decl_stmt|;
comment|// It would make sense to put this into a mac #ifdef'ed
comment|// virtual function in the QPixmapData at some point
if|if
condition|(
name|pm
operator|->
name|data
operator|->
name|classId
argument_list|()
operator|==
name|QPixmapData
operator|::
name|MacClass
condition|)
block|{
specifier|const
name|QMacPixmapData
modifier|*
name|pmData
init|=
cast|static_cast
argument_list|<
specifier|const
name|QMacPixmapData
operator|*
argument_list|>
argument_list|(
name|pm
operator|->
name|data
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|ret
operator|=
name|CGBitmapContextCreate
argument_list|(
name|pmData
operator|->
name|pixels
argument_list|,
name|pmData
operator|->
name|w
argument_list|,
name|pmData
operator|->
name|h
argument_list|,
literal|8
argument_list|,
name|pmData
operator|->
name|bytesPerRow
argument_list|,
name|colorspace
argument_list|,
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ret
condition|)
name|qWarning
argument_list|(
literal|"QPaintDevice: Unable to create context for pixmap (%d/%d/%d)"
argument_list|,
name|pmData
operator|->
name|w
argument_list|,
name|pmData
operator|->
name|h
argument_list|,
operator|(
name|pmData
operator|->
name|bytesPerRow
operator|*
name|pmData
operator|->
name|h
operator|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pm
operator|->
name|data
operator|->
name|classId
argument_list|()
operator|==
name|QPixmapData
operator|::
name|RasterClass
condition|)
block|{
name|QImage
modifier|*
name|image
init|=
name|pm
operator|->
name|data
operator|->
name|buffer
argument_list|()
decl_stmt|;
name|ret
operator|=
name|CGBitmapContextCreate
argument_list|(
name|image
operator|->
name|bits
argument_list|()
argument_list|,
name|image
operator|->
name|width
argument_list|()
argument_list|,
name|image
operator|->
name|height
argument_list|()
argument_list|,
literal|8
argument_list|,
name|image
operator|->
name|bytesPerLine
argument_list|()
argument_list|,
name|colorspace
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
name|CGContextTranslateCTM
argument_list|(
name|ret
argument_list|,
literal|0
argument_list|,
name|pm
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|CGContextScaleCTM
argument_list|(
name|ret
argument_list|,
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
elseif|else
if|if
condition|(
name|pdev
operator|->
name|devType
argument_list|()
operator|==
name|QInternal
operator|::
name|Widget
condition|)
block|{
name|CGContextRef
name|ret
init|=
cast|static_cast
argument_list|<
name|CGContextRef
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
specifier|const
name|QWidget
operator|*
argument_list|>
argument_list|(
name|pdev
argument_list|)
operator|->
name|macCGHandle
argument_list|()
argument_list|)
decl_stmt|;
name|CGContextRetain
argument_list|(
name|ret
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
elseif|else
if|if
condition|(
name|pdev
operator|->
name|devType
argument_list|()
operator|==
name|QInternal
operator|::
name|MacQuartz
condition|)
block|{
return|return
cast|static_cast
argument_list|<
specifier|const
name|QMacQuartzPaintDevice
operator|*
argument_list|>
argument_list|(
name|pdev
argument_list|)
operator|->
name|cgContext
argument_list|()
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
