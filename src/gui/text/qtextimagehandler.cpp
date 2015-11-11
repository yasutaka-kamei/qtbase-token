begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtextimagehandler_p.h"
end_include
begin_include
include|#
directive|include
file|<qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<qtextformat.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<private/qtextengine_p.h>
end_include
begin_include
include|#
directive|include
file|<qpalette.h>
end_include
begin_include
include|#
directive|include
file|<qthread.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|extern
name|QString
name|qt_findAtNxFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|baseFileName
parameter_list|,
name|qreal
name|targetDevicePixelRatio
parameter_list|,
name|qreal
modifier|*
name|sourceDevicePixelRatio
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|resolveFileName
specifier|static
name|QString
name|resolveFileName
parameter_list|(
name|QString
name|fileName
parameter_list|,
name|QUrl
modifier|*
name|url
parameter_list|,
name|qreal
name|targetDevicePixelRatio
parameter_list|,
name|qreal
modifier|*
name|sourceDevicePixelRatio
parameter_list|)
block|{
comment|// We might use the fileName for loading if url loading fails
comment|// try to make sure it is a valid file path.
comment|// Also, QFile{Info}::exists works only on filepaths (not urls)
if|if
condition|(
name|url
operator|->
name|isValid
argument_list|()
condition|)
block|{
if|if
condition|(
name|url
operator|->
name|scheme
argument_list|()
operator|==
name|QLatin1Literal
argument_list|(
literal|"qrc"
argument_list|)
condition|)
block|{
name|fileName
operator|=
name|fileName
operator|.
name|right
argument_list|(
name|fileName
operator|.
name|length
argument_list|()
operator|-
literal|3
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|url
operator|->
name|scheme
argument_list|()
operator|==
name|QLatin1Literal
argument_list|(
literal|"file"
argument_list|)
condition|)
block|{
name|fileName
operator|=
name|url
operator|->
name|toLocalFile
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
name|targetDevicePixelRatio
operator|<=
literal|1.0
condition|)
return|return
name|fileName
return|;
comment|// try to find a Nx version
return|return
name|qt_findAtNxFile
argument_list|(
name|fileName
argument_list|,
name|targetDevicePixelRatio
argument_list|,
name|sourceDevicePixelRatio
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|getPixmap
specifier|static
name|QPixmap
name|getPixmap
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|,
specifier|const
name|QTextImageFormat
modifier|&
name|format
parameter_list|,
specifier|const
name|qreal
name|devicePixelRatio
init|=
literal|1.0
parameter_list|)
block|{
name|QPixmap
name|pm
decl_stmt|;
name|QString
name|name
init|=
name|format
operator|.
name|name
argument_list|()
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|":/"
argument_list|)
argument_list|)
condition|)
comment|// auto-detect resources and convert them to url
name|name
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"qrc"
argument_list|)
argument_list|)
expr_stmt|;
name|QUrl
name|url
init|=
name|QUrl
argument_list|(
name|name
argument_list|)
decl_stmt|;
name|qreal
name|sourcePixelRatio
init|=
literal|1.0
decl_stmt|;
name|name
operator|=
name|resolveFileName
argument_list|(
name|name
argument_list|,
operator|&
name|url
argument_list|,
name|devicePixelRatio
argument_list|,
operator|&
name|sourcePixelRatio
argument_list|)
expr_stmt|;
specifier|const
name|QVariant
name|data
init|=
name|doc
operator|->
name|resource
argument_list|(
name|QTextDocument
operator|::
name|ImageResource
argument_list|,
name|url
argument_list|)
decl_stmt|;
if|if
condition|(
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Pixmap
operator|||
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Image
condition|)
block|{
name|pm
operator|=
name|qvariant_cast
argument_list|<
name|QPixmap
argument_list|>
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|ByteArray
condition|)
block|{
name|pm
operator|.
name|loadFromData
argument_list|(
name|data
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|pm
operator|.
name|isNull
argument_list|()
condition|)
block|{
if|#
directive|if
literal|0
block|QString context;
comment|// ### Qt5
block|QTextBrowser *browser = qobject_cast<QTextBrowser *>(doc->parent());         if (browser)             context = browser->source().toString();
endif|#
directive|endif
comment|// try direct loading
name|QImage
name|img
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|img
operator|.
name|load
argument_list|(
name|name
argument_list|)
condition|)
return|return
name|QPixmap
argument_list|(
name|QLatin1String
argument_list|(
literal|":/qt-project.org/styles/commonstyle/images/file-16.png"
argument_list|)
argument_list|)
return|;
name|pm
operator|=
name|QPixmap
operator|::
name|fromImage
argument_list|(
name|img
argument_list|)
expr_stmt|;
name|doc
operator|->
name|addResource
argument_list|(
name|QTextDocument
operator|::
name|ImageResource
argument_list|,
name|url
argument_list|,
name|pm
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|name
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"@2x"
argument_list|)
argument_list|)
condition|)
name|pm
operator|.
name|setDevicePixelRatio
argument_list|(
name|sourcePixelRatio
argument_list|)
expr_stmt|;
return|return
name|pm
return|;
block|}
end_function
begin_function
DECL|function|getPixmapSize
specifier|static
name|QSize
name|getPixmapSize
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|,
specifier|const
name|QTextImageFormat
modifier|&
name|format
parameter_list|)
block|{
name|QPixmap
name|pm
decl_stmt|;
specifier|const
name|bool
name|hasWidth
init|=
name|format
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|ImageWidth
argument_list|)
decl_stmt|;
specifier|const
name|int
name|width
init|=
name|qRound
argument_list|(
name|format
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|hasHeight
init|=
name|format
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|ImageHeight
argument_list|)
decl_stmt|;
specifier|const
name|int
name|height
init|=
name|qRound
argument_list|(
name|format
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|QSize
name|size
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|hasWidth
operator|||
operator|!
name|hasHeight
condition|)
block|{
name|pm
operator|=
name|getPixmap
argument_list|(
name|doc
argument_list|,
name|format
argument_list|)
expr_stmt|;
specifier|const
name|int
name|pmWidth
init|=
name|pm
operator|.
name|width
argument_list|()
operator|/
name|pm
operator|.
name|devicePixelRatio
argument_list|()
decl_stmt|;
specifier|const
name|int
name|pmHeight
init|=
name|pm
operator|.
name|height
argument_list|()
operator|/
name|pm
operator|.
name|devicePixelRatio
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|hasWidth
condition|)
block|{
if|if
condition|(
operator|!
name|hasHeight
condition|)
name|size
operator|.
name|setWidth
argument_list|(
name|pmWidth
argument_list|)
expr_stmt|;
else|else
name|size
operator|.
name|setWidth
argument_list|(
name|qRound
argument_list|(
name|height
operator|*
operator|(
name|pmWidth
operator|/
operator|(
name|qreal
operator|)
name|pmHeight
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|hasHeight
condition|)
block|{
if|if
condition|(
operator|!
name|hasWidth
condition|)
name|size
operator|.
name|setHeight
argument_list|(
name|pmHeight
argument_list|)
expr_stmt|;
else|else
name|size
operator|.
name|setHeight
argument_list|(
name|qRound
argument_list|(
name|width
operator|*
operator|(
name|pmHeight
operator|/
operator|(
name|qreal
operator|)
name|pmWidth
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|qreal
name|scale
init|=
literal|1.0
decl_stmt|;
name|QPaintDevice
modifier|*
name|pdev
init|=
name|doc
operator|->
name|documentLayout
argument_list|()
operator|->
name|paintDevice
argument_list|()
decl_stmt|;
if|if
condition|(
name|pdev
condition|)
block|{
if|if
condition|(
name|pm
operator|.
name|isNull
argument_list|()
condition|)
name|pm
operator|=
name|getPixmap
argument_list|(
name|doc
argument_list|,
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pm
operator|.
name|isNull
argument_list|()
condition|)
name|scale
operator|=
name|qreal
argument_list|(
name|pdev
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|qt_defaultDpi
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|size
operator|*=
name|scale
expr_stmt|;
return|return
name|size
return|;
block|}
end_function
begin_function
DECL|function|getImage
specifier|static
name|QImage
name|getImage
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|,
specifier|const
name|QTextImageFormat
modifier|&
name|format
parameter_list|,
specifier|const
name|qreal
name|devicePixelRatio
init|=
literal|1.0
parameter_list|)
block|{
name|QImage
name|image
decl_stmt|;
name|QString
name|name
init|=
name|format
operator|.
name|name
argument_list|()
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|":/"
argument_list|)
argument_list|)
condition|)
comment|// auto-detect resources
name|name
operator|.
name|prepend
argument_list|(
name|QLatin1String
argument_list|(
literal|"qrc"
argument_list|)
argument_list|)
expr_stmt|;
name|QUrl
name|url
init|=
name|QUrl
argument_list|(
name|name
argument_list|)
decl_stmt|;
name|qreal
name|sourcePixelRatio
init|=
literal|1.0
decl_stmt|;
name|name
operator|=
name|resolveFileName
argument_list|(
name|name
argument_list|,
operator|&
name|url
argument_list|,
name|devicePixelRatio
argument_list|,
operator|&
name|sourcePixelRatio
argument_list|)
expr_stmt|;
specifier|const
name|QVariant
name|data
init|=
name|doc
operator|->
name|resource
argument_list|(
name|QTextDocument
operator|::
name|ImageResource
argument_list|,
name|url
argument_list|)
decl_stmt|;
if|if
condition|(
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|Image
condition|)
block|{
name|image
operator|=
name|qvariant_cast
argument_list|<
name|QImage
argument_list|>
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|data
operator|.
name|type
argument_list|()
operator|==
name|QVariant
operator|::
name|ByteArray
condition|)
block|{
name|image
operator|.
name|loadFromData
argument_list|(
name|data
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|image
operator|.
name|isNull
argument_list|()
condition|)
block|{
if|#
directive|if
literal|0
block|QString context;
comment|// ### Qt5
block|QTextBrowser *browser = qobject_cast<QTextBrowser *>(doc->parent());         if (browser)             context = browser->source().toString();
endif|#
directive|endif
comment|// try direct loading
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|image
operator|.
name|load
argument_list|(
name|name
argument_list|)
condition|)
return|return
name|QImage
argument_list|(
name|QLatin1String
argument_list|(
literal|":/qt-project.org/styles/commonstyle/images/file-16.png"
argument_list|)
argument_list|)
return|;
name|doc
operator|->
name|addResource
argument_list|(
name|QTextDocument
operator|::
name|ImageResource
argument_list|,
name|url
argument_list|,
name|image
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sourcePixelRatio
operator|!=
literal|1.0
condition|)
name|image
operator|.
name|setDevicePixelRatio
argument_list|(
name|sourcePixelRatio
argument_list|)
expr_stmt|;
return|return
name|image
return|;
block|}
end_function
begin_function
DECL|function|getImageSize
specifier|static
name|QSize
name|getImageSize
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|,
specifier|const
name|QTextImageFormat
modifier|&
name|format
parameter_list|)
block|{
name|QImage
name|image
decl_stmt|;
specifier|const
name|bool
name|hasWidth
init|=
name|format
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|ImageWidth
argument_list|)
decl_stmt|;
specifier|const
name|int
name|width
init|=
name|qRound
argument_list|(
name|format
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|hasHeight
init|=
name|format
operator|.
name|hasProperty
argument_list|(
name|QTextFormat
operator|::
name|ImageHeight
argument_list|)
decl_stmt|;
specifier|const
name|int
name|height
init|=
name|qRound
argument_list|(
name|format
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|QSize
name|size
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|hasWidth
operator|||
operator|!
name|hasHeight
condition|)
block|{
name|image
operator|=
name|getImage
argument_list|(
name|doc
argument_list|,
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hasWidth
condition|)
name|size
operator|.
name|setWidth
argument_list|(
name|image
operator|.
name|width
argument_list|()
operator|/
name|image
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hasHeight
condition|)
name|size
operator|.
name|setHeight
argument_list|(
name|image
operator|.
name|height
argument_list|()
operator|/
name|image
operator|.
name|devicePixelRatio
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|qreal
name|scale
init|=
literal|1.0
decl_stmt|;
name|QPaintDevice
modifier|*
name|pdev
init|=
name|doc
operator|->
name|documentLayout
argument_list|()
operator|->
name|paintDevice
argument_list|()
decl_stmt|;
if|if
condition|(
name|pdev
condition|)
block|{
if|if
condition|(
name|image
operator|.
name|isNull
argument_list|()
condition|)
name|image
operator|=
name|getImage
argument_list|(
name|doc
argument_list|,
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|image
operator|.
name|isNull
argument_list|()
condition|)
name|scale
operator|=
name|qreal
argument_list|(
name|pdev
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|qt_defaultDpi
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|size
operator|*=
name|scale
expr_stmt|;
return|return
name|size
return|;
block|}
end_function
begin_constructor
DECL|function|QTextImageHandler
name|QTextImageHandler
operator|::
name|QTextImageHandler
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|intrinsicSize
name|QSizeF
name|QTextImageHandler
operator|::
name|intrinsicSize
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|,
name|int
name|posInDocument
parameter_list|,
specifier|const
name|QTextFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|posInDocument
argument_list|)
specifier|const
name|QTextImageFormat
name|imageFormat
init|=
name|format
operator|.
name|toImageFormat
argument_list|()
decl_stmt|;
if|if
condition|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|thread
argument_list|()
operator|!=
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
return|return
name|getImageSize
argument_list|(
name|doc
argument_list|,
name|imageFormat
argument_list|)
return|;
return|return
name|getPixmapSize
argument_list|(
name|doc
argument_list|,
name|imageFormat
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|image
name|QImage
name|QTextImageHandler
operator|::
name|image
parameter_list|(
name|QTextDocument
modifier|*
name|doc
parameter_list|,
specifier|const
name|QTextImageFormat
modifier|&
name|imageFormat
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|doc
operator|!=
literal|0
argument_list|)
expr_stmt|;
return|return
name|getImage
argument_list|(
name|doc
argument_list|,
name|imageFormat
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|drawObject
name|void
name|QTextImageHandler
operator|::
name|drawObject
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|QTextDocument
modifier|*
name|doc
parameter_list|,
name|int
name|posInDocument
parameter_list|,
specifier|const
name|QTextFormat
modifier|&
name|format
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|posInDocument
argument_list|)
specifier|const
name|QTextImageFormat
name|imageFormat
init|=
name|format
operator|.
name|toImageFormat
argument_list|()
decl_stmt|;
if|if
condition|(
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|thread
argument_list|()
operator|!=
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
block|{
specifier|const
name|QImage
name|image
init|=
name|getImage
argument_list|(
name|doc
argument_list|,
name|imageFormat
argument_list|,
name|p
operator|->
name|device
argument_list|()
operator|->
name|devicePixelRatioF
argument_list|()
argument_list|)
decl_stmt|;
name|p
operator|->
name|drawImage
argument_list|(
name|rect
argument_list|,
name|image
argument_list|,
name|image
operator|.
name|rect
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|QPixmap
name|pixmap
init|=
name|getPixmap
argument_list|(
name|doc
argument_list|,
name|imageFormat
argument_list|,
name|p
operator|->
name|device
argument_list|()
operator|->
name|devicePixelRatioF
argument_list|()
argument_list|)
decl_stmt|;
name|p
operator|->
name|drawPixmap
argument_list|(
name|rect
argument_list|,
name|pixmap
argument_list|,
name|pixmap
operator|.
name|rect
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
