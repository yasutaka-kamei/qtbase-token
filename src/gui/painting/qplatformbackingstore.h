begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMBACKINGSTORE_H
end_ifndef
begin_define
DECL|macro|QPLATFORMBACKINGSTORE_H
define|#
directive|define
name|QPLATFORMBACKINGSTORE_H
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
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qregion.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QRegion
name|class
name|QRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformBackingStorePrivate
name|class
name|QPlatformBackingStorePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformWindow
name|class
name|QPlatformWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformTextureList
name|class
name|QPlatformTextureList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformTextureListPrivate
name|class
name|QPlatformTextureListPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformGraphicsBuffer
name|class
name|QPlatformGraphicsBuffer
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformTextureList
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPlatformTextureList
argument_list|)
name|public
operator|:
expr|enum
name|Flag
block|{
name|StacksOnTop
operator|=
literal|0x01
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Flags
argument_list|,
argument|Flag
argument_list|)
name|explicit
name|QPlatformTextureList
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QPlatformTextureList
argument_list|()
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|count
argument_list|()
operator|==
literal|0
return|;
block|}
name|GLuint
name|textureId
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QRect
name|geometry
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|QWidget
operator|*
name|widget
argument_list|(
argument|int index
argument_list|)
block|;
name|Flags
name|flags
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|lock
argument_list|(
argument|bool on
argument_list|)
block|;
name|bool
name|isLocked
argument_list|()
specifier|const
block|;
name|void
name|appendTexture
argument_list|(
argument|QWidget *widget
argument_list|,
argument|GLuint textureId
argument_list|,
argument|const QRect&geometry
argument_list|,
argument|Flags flags =
literal|0
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|locked
argument_list|(
name|bool
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QPlatformTextureList::Flags
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformBackingStore
block|{
name|public
label|:
name|explicit
name|QPlatformBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|virtual
operator|~
name|QPlatformBackingStore
argument_list|()
expr_stmt|;
name|QWindow
operator|*
name|window
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QPaintDevice
modifier|*
name|paintDevice
parameter_list|()
init|=
literal|0
function_decl|;
comment|// 'window' can be a child window, in which case 'region' is in child window coordinates and
comment|// offset is the (child) window's offset in relation to the window surface.
name|virtual
name|void
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
init|=
literal|0
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|virtual
name|void
name|composeAndFlush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|,
name|QPlatformTextureList
modifier|*
name|textures
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
name|bool
name|translucentBackground
parameter_list|)
function_decl|;
name|virtual
name|QImage
name|toImage
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|TextureFlag
block|{
name|TextureSwizzle
init|=
literal|0x01
block|,
name|TextureFlip
init|=
literal|0x02
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|TextureFlags
argument_list|,
argument|TextureFlag
argument_list|)
name|virtual
name|GLuint
name|toTexture
argument_list|(
specifier|const
name|QRegion
operator|&
name|dirtyRegion
argument_list|,
name|QSize
operator|*
name|textureSize
argument_list|,
name|TextureFlags
operator|*
name|flags
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|virtual
name|QPlatformGraphicsBuffer
operator|*
name|graphicsBuffer
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|staticContents
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
function_decl|;
name|virtual
name|void
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
parameter_list|)
function_decl|;
name|virtual
name|void
name|endPaint
parameter_list|()
function_decl|;
name|private
label|:
name|QPlatformBackingStorePrivate
modifier|*
name|d_ptr
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QPlatformBackingStore::TextureFlags
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMBACKINGSTORE_H
end_comment
end_unit
