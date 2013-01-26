begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIMAGEIOHANDLER_H
end_ifndef
begin_define
DECL|macro|QIMAGEIOHANDLER_H
define|#
directive|define
name|QIMAGEIOHANDLER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qplugin.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfactoryinterface.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSize
name|class
name|QSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImageIOHandlerPrivate
name|class
name|QImageIOHandlerPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QImageIOHandler
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QImageIOHandler
argument_list|)
name|public
label|:
name|QImageIOHandler
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QImageIOHandler
argument_list|()
expr_stmt|;
name|void
name|setDevice
parameter_list|(
name|QIODevice
modifier|*
name|device
parameter_list|)
function_decl|;
name|QIODevice
operator|*
name|device
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setFormat
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|format
parameter_list|)
function_decl|;
name|void
name|setFormat
argument_list|(
specifier|const
name|QByteArray
operator|&
name|format
argument_list|)
decl|const
decl_stmt|;
name|QByteArray
name|format
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QByteArray
name|name
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|bool
name|canRead
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|read
parameter_list|(
name|QImage
modifier|*
name|image
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|write
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
function_decl|;
enum|enum
name|ImageOption
block|{
name|Size
block|,
name|ClipRect
block|,
name|Description
block|,
name|ScaledClipRect
block|,
name|ScaledSize
block|,
name|CompressionRatio
block|,
name|Gamma
block|,
name|Quality
block|,
name|Name
block|,
name|SubType
block|,
name|IncrementalReading
block|,
name|Endianness
block|,
name|Animation
block|,
name|BackgroundColor
block|,
name|ImageFormat
block|}
enum|;
name|virtual
name|QVariant
name|option
argument_list|(
name|ImageOption
name|option
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|setOption
parameter_list|(
name|ImageOption
name|option
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
function_decl|;
name|virtual
name|bool
name|supportsOption
argument_list|(
name|ImageOption
name|option
argument_list|)
decl|const
decl_stmt|;
comment|// incremental loading
name|virtual
name|bool
name|jumpToNextImage
parameter_list|()
function_decl|;
name|virtual
name|bool
name|jumpToImage
parameter_list|(
name|int
name|imageNumber
parameter_list|)
function_decl|;
name|virtual
name|int
name|loopCount
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|imageCount
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|nextImageDelay
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|currentImageNumber
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QRect
name|currentImageRect
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|QImageIOHandler
argument_list|(
name|QImageIOHandlerPrivate
operator|&
name|dd
argument_list|)
expr_stmt|;
name|QScopedPointer
operator|<
name|QImageIOHandlerPrivate
operator|>
name|d_ptr
expr_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QImageIOHandler
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMATPLUGIN
end_ifndef
begin_define
DECL|macro|QImageIOHandlerFactoryInterface_iid
define|#
directive|define
name|QImageIOHandlerFactoryInterface_iid
value|"org.qt-project.Qt.QImageIOHandlerFactoryInterface"
end_define
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QImageIOPlugin
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QImageIOPlugin
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QImageIOPlugin
argument_list|()
block|;      enum
name|Capability
block|{
name|CanRead
operator|=
literal|0x1
block|,
name|CanWrite
operator|=
literal|0x2
block|,
name|CanReadIncremental
operator|=
literal|0x4
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Capabilities
argument_list|,
argument|Capability
argument_list|)
name|virtual
name|Capabilities
name|capabilities
argument_list|(
argument|QIODevice *device
argument_list|,
argument|const QByteArray&format
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QImageIOHandler
operator|*
name|create
argument_list|(
argument|QIODevice *device
argument_list|,
argument|const QByteArray&format = QByteArray()
argument_list|)
specifier|const
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QImageIOPlugin::Capabilities
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_IMAGEFORMATPLUGIN
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QIMAGEIOHANDLER_H
end_comment
end_unit
