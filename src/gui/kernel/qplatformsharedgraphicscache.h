begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMSHAREDGRAPHICSCACHE_H
end_ifndef
begin_define
DECL|macro|QPLATFORMSHAREDGRAPHICSCACHE_H
define|#
directive|define
name|QPLATFORMSHAREDGRAPHICSCACHE_H
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
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qimage.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|Q_GUI_EXPORT
name|QPlatformSharedGraphicsCache
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|PixelFormat
block|{
name|Alpha8
block|}
block|;      enum
name|BufferType
block|{
name|OpenGLTexture
block|}
block|;
name|explicit
name|QPlatformSharedGraphicsCache
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{}
name|Q_INVOKABLE
name|virtual
name|void
name|ensureCacheInitialized
argument_list|(
argument|const QByteArray&cacheId
argument_list|,
argument|BufferType bufferType
argument_list|,
argument|PixelFormat pixelFormat
argument_list|)
operator|=
literal|0
block|;
name|Q_INVOKABLE
name|virtual
name|void
name|requestItems
argument_list|(
specifier|const
name|QByteArray
operator|&
name|cacheId
argument_list|,
specifier|const
name|QVector
operator|<
name|quint32
operator|>
operator|&
name|itemIds
argument_list|)
operator|=
literal|0
block|;
name|Q_INVOKABLE
name|virtual
name|void
name|insertItems
argument_list|(
specifier|const
name|QByteArray
operator|&
name|cacheId
argument_list|,
specifier|const
name|QVector
operator|<
name|quint32
operator|>
operator|&
name|itemIds
argument_list|,
specifier|const
name|QVector
operator|<
name|QImage
operator|>
operator|&
name|items
argument_list|)
operator|=
literal|0
block|;
name|Q_INVOKABLE
name|virtual
name|void
name|releaseItems
argument_list|(
specifier|const
name|QByteArray
operator|&
name|cacheId
argument_list|,
specifier|const
name|QVector
operator|<
name|quint32
operator|>
operator|&
name|itemIds
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|uint
name|textureIdForBuffer
argument_list|(
name|void
operator|*
name|bufferId
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|referenceBuffer
argument_list|(
name|void
operator|*
name|bufferId
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|dereferenceBuffer
argument_list|(
name|void
operator|*
name|bufferId
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QSize
name|sizeOfBuffer
argument_list|(
name|void
operator|*
name|bufferId
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
operator|*
name|eglImageForBuffer
argument_list|(
name|void
operator|*
name|bufferId
argument_list|)
operator|=
literal|0
block|;
name|Q_SIGNALS
operator|:
name|void
name|itemsMissing
argument_list|(
specifier|const
name|QByteArray
operator|&
name|cacheId
argument_list|,
specifier|const
name|QVector
operator|<
name|quint32
operator|>
operator|&
name|itemIds
argument_list|)
block|;
name|void
name|itemsAvailable
argument_list|(
specifier|const
name|QByteArray
operator|&
name|cacheId
argument_list|,
name|void
operator|*
name|bufferId
argument_list|,
specifier|const
name|QVector
operator|<
name|quint32
operator|>
operator|&
name|itemIds
argument_list|,
specifier|const
name|QVector
operator|<
name|QPoint
operator|>
operator|&
name|positionsInBuffer
argument_list|)
block|;
name|void
name|itemsInvalidated
argument_list|(
specifier|const
name|QByteArray
operator|&
name|cacheId
argument_list|,
specifier|const
name|QVector
operator|<
name|quint32
operator|>
operator|&
name|itemIds
argument_list|)
block|;
name|void
name|itemsUpdated
argument_list|(
specifier|const
name|QByteArray
operator|&
name|cacheId
argument_list|,
name|void
operator|*
name|bufferId
argument_list|,
specifier|const
name|QVector
operator|<
name|quint32
operator|>
operator|&
name|itemIds
argument_list|,
specifier|const
name|QVector
operator|<
name|QPoint
operator|>
operator|&
name|positionsInBuffer
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMSHAREDGRAPHICSCACHE_H
end_comment
end_unit
