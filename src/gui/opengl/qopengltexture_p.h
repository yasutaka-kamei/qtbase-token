begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB). ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTOPENGLTEXTURE_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTOPENGLTEXTURE_P_H
define|#
directive|define
name|QABSTRACTOPENGLTEXTURE_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"qopengltexture.h"
end_include
begin_include
include|#
directive|include
file|"qopengl.h"
end_include
begin_include
include|#
directive|include
file|<cmath>
end_include
begin_macro
name|namespace
end_macro
begin_block
block|{
specifier|inline
name|double
name|qLog2
parameter_list|(
specifier|const
name|double
name|x
parameter_list|)
block|{
return|return
name|std
operator|::
name|log
argument_list|(
name|x
argument_list|)
operator|/
name|std
operator|::
name|log
argument_list|(
literal|2.0
argument_list|)
return|;
block|}
block|}
end_block
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLTextureHelper
name|class
name|QOpenGLTextureHelper
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOpenGLTexturePrivate
block|{
name|public
label|:
name|QOpenGLTexturePrivate
argument_list|(
argument|QOpenGLTexture::Target textureTarget
argument_list|,
argument|QOpenGLTexture *qq
argument_list|)
empty_stmt|;
operator|~
name|QOpenGLTexturePrivate
argument_list|()
expr_stmt|;
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QOpenGLTexture
argument_list|)
name|void
name|resetFuncs
parameter_list|(
name|QOpenGLTextureHelper
modifier|*
name|funcs
parameter_list|)
function_decl|;
name|void
name|initializeOpenGLFunctions
parameter_list|()
function_decl|;
name|bool
name|create
parameter_list|()
function_decl|;
name|void
name|destroy
parameter_list|()
function_decl|;
name|void
name|bind
parameter_list|()
function_decl|;
name|void
name|bind
argument_list|(
name|uint
name|unit
argument_list|,
name|QOpenGLTexture
operator|::
name|TextureUnitReset
name|reset
operator|=
name|QOpenGLTexture
operator|::
name|DontResetTextureUnit
argument_list|)
decl_stmt|;
name|void
name|release
parameter_list|()
function_decl|;
name|void
name|release
argument_list|(
name|uint
name|unit
argument_list|,
name|QOpenGLTexture
operator|::
name|TextureUnitReset
name|reset
operator|=
name|QOpenGLTexture
operator|::
name|DontResetTextureUnit
argument_list|)
decl_stmt|;
name|bool
name|isBound
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isBound
argument_list|(
name|uint
name|unit
argument_list|)
decl|const
decl_stmt|;
name|void
name|allocateStorage
argument_list|(
name|QOpenGLTexture
operator|::
name|PixelFormat
name|pixelFormat
argument_list|,
name|QOpenGLTexture
operator|::
name|PixelType
name|pixelType
argument_list|)
decl_stmt|;
name|void
name|allocateMutableStorage
argument_list|(
name|QOpenGLTexture
operator|::
name|PixelFormat
name|pixelFormat
argument_list|,
name|QOpenGLTexture
operator|::
name|PixelType
name|pixelType
argument_list|)
decl_stmt|;
name|void
name|allocateImmutableStorage
parameter_list|()
function_decl|;
name|void
name|setData
argument_list|(
name|int
name|mipLevel
argument_list|,
name|int
name|layer
argument_list|,
name|QOpenGLTexture
operator|::
name|CubeMapFace
name|cubeFace
argument_list|,
name|QOpenGLTexture
operator|::
name|PixelFormat
name|sourceFormat
argument_list|,
name|QOpenGLTexture
operator|::
name|PixelType
name|sourceType
argument_list|,
specifier|const
name|void
operator|*
name|data
argument_list|,
specifier|const
name|QOpenGLPixelTransferOptions
operator|*
specifier|const
name|options
argument_list|)
decl_stmt|;
name|void
name|setCompressedData
argument_list|(
name|int
name|mipLevel
argument_list|,
name|int
name|layer
argument_list|,
name|QOpenGLTexture
operator|::
name|CubeMapFace
name|cubeFace
argument_list|,
name|int
name|dataSize
argument_list|,
specifier|const
name|void
operator|*
name|data
argument_list|,
specifier|const
name|QOpenGLPixelTransferOptions
operator|*
specifier|const
name|options
argument_list|)
decl_stmt|;
name|void
name|setWrapMode
argument_list|(
name|QOpenGLTexture
operator|::
name|WrapMode
name|mode
argument_list|)
decl_stmt|;
name|void
name|setWrapMode
argument_list|(
name|QOpenGLTexture
operator|::
name|CoordinateDirection
name|direction
argument_list|,
name|QOpenGLTexture
operator|::
name|WrapMode
name|mode
argument_list|)
decl_stmt|;
name|QOpenGLTexture
operator|::
name|WrapMode
name|wrapMode
argument_list|(
argument|QOpenGLTexture::CoordinateDirection direction
argument_list|)
specifier|const
expr_stmt|;
name|QOpenGLTexture
modifier|*
name|createTextureView
argument_list|(
name|QOpenGLTexture
operator|::
name|Target
name|target
argument_list|,
name|QOpenGLTexture
operator|::
name|TextureFormat
name|viewFormat
argument_list|,
name|int
name|minimumMipmapLevel
argument_list|,
name|int
name|maximumMipmapLevel
argument_list|,
name|int
name|minimumLayer
argument_list|,
name|int
name|maximumLayer
argument_list|)
decl|const
decl_stmt|;
name|int
name|evaluateMipLevels
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|int
name|maximumMipLevelCount
argument_list|()
specifier|const
block|{
return|return
literal|1
operator|+
name|std
operator|::
name|floor
argument_list|(
name|qLog2
argument_list|(
name|qMax
argument_list|(
name|dimensions
index|[
literal|0
index|]
argument_list|,
name|qMax
argument_list|(
name|dimensions
index|[
literal|1
index|]
argument_list|,
name|dimensions
index|[
literal|2
index|]
argument_list|)
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|int
name|mipLevelSize
parameter_list|(
name|int
name|mipLevel
parameter_list|,
name|int
name|baseLevelSize
parameter_list|)
block|{
return|return
name|std
operator|::
name|floor
argument_list|(
name|double
argument_list|(
name|qMax
argument_list|(
literal|1
argument_list|,
name|baseLevelSize
operator|>>
name|mipLevel
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
name|bool
name|isUsingImmutableStorage
argument_list|()
specifier|const
expr_stmt|;
name|QOpenGLTexture
modifier|*
name|q_ptr
decl_stmt|;
name|QOpenGLContext
modifier|*
name|context
decl_stmt|;
name|QOpenGLTexture
operator|::
name|Target
name|target
expr_stmt|;
name|QOpenGLTexture
operator|::
name|BindingTarget
name|bindingTarget
expr_stmt|;
name|GLuint
name|textureId
decl_stmt|;
name|QOpenGLTexture
operator|::
name|TextureFormat
name|format
expr_stmt|;
name|QOpenGLTexture
operator|::
name|TextureFormatClass
name|formatClass
expr_stmt|;
name|int
name|dimensions
index|[
literal|3
index|]
decl_stmt|;
name|int
name|requestedMipLevels
decl_stmt|;
name|int
name|mipLevels
decl_stmt|;
name|int
name|layers
decl_stmt|;
name|int
name|faces
decl_stmt|;
name|int
name|samples
decl_stmt|;
name|bool
name|fixedSamplePositions
decl_stmt|;
name|int
name|baseLevel
decl_stmt|;
name|int
name|maxLevel
decl_stmt|;
name|QOpenGLTexture
operator|::
name|SwizzleValue
name|swizzleMask
index|[
literal|4
index|]
expr_stmt|;
name|QOpenGLTexture
operator|::
name|DepthStencilMode
name|depthStencilMode
expr_stmt|;
name|QOpenGLTexture
operator|::
name|ComparisonFunction
name|comparisonFunction
expr_stmt|;
name|QOpenGLTexture
operator|::
name|ComparisonMode
name|comparisonMode
expr_stmt|;
name|QOpenGLTexture
operator|::
name|Filter
name|minFilter
expr_stmt|;
name|QOpenGLTexture
operator|::
name|Filter
name|magFilter
expr_stmt|;
name|float
name|maxAnisotropy
decl_stmt|;
name|QOpenGLTexture
operator|::
name|WrapMode
name|wrapModes
index|[
literal|3
index|]
expr_stmt|;
name|QVariantList
name|borderColor
decl_stmt|;
name|float
name|minLevelOfDetail
decl_stmt|;
name|float
name|maxLevelOfDetail
decl_stmt|;
name|float
name|levelOfDetailBias
decl_stmt|;
name|bool
name|textureView
decl_stmt|;
name|bool
name|autoGenerateMipMaps
decl_stmt|;
name|bool
name|storageAllocated
decl_stmt|;
name|QPair
operator|<
name|int
operator|,
name|int
operator|>
name|glVersion
expr_stmt|;
name|QOpenGLTextureHelper
modifier|*
name|texFuncs
decl_stmt|;
name|QOpenGLTexture
operator|::
name|Features
name|features
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_undef
DECL|macro|Q_CALL_MEMBER_FUNCTION
undef|#
directive|undef
name|Q_CALL_MEMBER_FUNCTION
end_undef
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
comment|// QABSTRACTOPENGLTEXTURE_P_H
end_comment
end_unit
