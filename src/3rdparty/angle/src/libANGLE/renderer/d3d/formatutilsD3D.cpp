begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// formatutils9.cpp: Queries for GL image formats and their translations to D3D
end_comment
begin_comment
comment|// formats.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/formatutilsD3D.h"
end_include
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/imageformats.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/copyimage.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|typedef|FormatTypePair
typedef|typedef
name|std
operator|::
name|pair
argument_list|<
name|GLenum
argument_list|,
name|GLenum
argument_list|>
name|FormatTypePair
typedef|;
DECL|typedef|FormatWriteFunctionPair
typedef|typedef
name|std
operator|::
name|pair
argument_list|<
name|FormatTypePair
argument_list|,
name|ColorWriteFunction
argument_list|>
name|FormatWriteFunctionPair
typedef|;
DECL|typedef|FormatWriteFunctionMap
typedef|typedef
name|std
operator|::
name|map
argument_list|<
name|FormatTypePair
argument_list|,
name|ColorWriteFunction
argument_list|>
name|FormatWriteFunctionMap
typedef|;
DECL|function|InsertFormatWriteFunctionMapping
specifier|static
specifier|inline
name|void
name|InsertFormatWriteFunctionMapping
parameter_list|(
name|FormatWriteFunctionMap
modifier|*
name|map
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|ColorWriteFunction
name|writeFunc
parameter_list|)
block|{
name|map
operator|->
name|insert
argument_list|(
name|FormatWriteFunctionPair
argument_list|(
name|FormatTypePair
argument_list|(
name|format
argument_list|,
name|type
argument_list|)
argument_list|,
name|writeFunc
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|BuildFormatWriteFunctionMap
specifier|static
name|FormatWriteFunctionMap
name|BuildFormatWriteFunctionMap
parameter_list|()
block|{
name|FormatWriteFunctionMap
name|map
decl_stmt|;
comment|//                                    | Format               | Type                             | Color write function             |
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8B8A8
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8B8A8S
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_SHORT_4_4_4_4
argument_list|,
name|WriteColor
argument_list|<
name|R4G4B4A4
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_SHORT_5_5_5_1
argument_list|,
name|WriteColor
argument_list|<
name|R5G5B5A1
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_INT_2_10_10_10_REV
argument_list|,
name|WriteColor
argument_list|<
name|R10G10B10A2
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|R32G32B32A32F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_HALF_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|R16G16B16A16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_HALF_FLOAT_OES
argument_list|,
name|WriteColor
argument_list|<
name|R16G16B16A16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA_INTEGER
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8B8A8
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA_INTEGER
argument_list|,
name|GL_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8B8A8S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA_INTEGER
argument_list|,
name|GL_UNSIGNED_SHORT
argument_list|,
name|WriteColor
argument_list|<
name|R16G16B16A16
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA_INTEGER
argument_list|,
name|GL_SHORT
argument_list|,
name|WriteColor
argument_list|<
name|R16G16B16A16S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA_INTEGER
argument_list|,
name|GL_UNSIGNED_INT
argument_list|,
name|WriteColor
argument_list|<
name|R32G32B32A32
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA_INTEGER
argument_list|,
name|GL_INT
argument_list|,
name|WriteColor
argument_list|<
name|R32G32B32A32S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGBA_INTEGER
argument_list|,
name|GL_UNSIGNED_INT_2_10_10_10_REV
argument_list|,
name|WriteColor
argument_list|<
name|R10G10B10A2
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8B8
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB
argument_list|,
name|GL_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8B8S
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB
argument_list|,
name|GL_UNSIGNED_SHORT_5_6_5
argument_list|,
name|WriteColor
argument_list|<
name|R5G6B5
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB
argument_list|,
name|GL_UNSIGNED_INT_10F_11F_11F_REV
argument_list|,
name|WriteColor
argument_list|<
name|R11G11B10F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB
argument_list|,
name|GL_UNSIGNED_INT_5_9_9_9_REV
argument_list|,
name|WriteColor
argument_list|<
name|R9G9B9E5
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB
argument_list|,
name|GL_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|R32G32B32F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB
argument_list|,
name|GL_HALF_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|R16G16B16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB
argument_list|,
name|GL_HALF_FLOAT_OES
argument_list|,
name|WriteColor
argument_list|<
name|R16G16B16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB_INTEGER
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8B8
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB_INTEGER
argument_list|,
name|GL_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8B8S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB_INTEGER
argument_list|,
name|GL_UNSIGNED_SHORT
argument_list|,
name|WriteColor
argument_list|<
name|R16G16B16
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB_INTEGER
argument_list|,
name|GL_SHORT
argument_list|,
name|WriteColor
argument_list|<
name|R16G16B16S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB_INTEGER
argument_list|,
name|GL_UNSIGNED_INT
argument_list|,
name|WriteColor
argument_list|<
name|R32G32B32
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RGB_INTEGER
argument_list|,
name|GL_INT
argument_list|,
name|WriteColor
argument_list|<
name|R32G32B32S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RG
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RG
argument_list|,
name|GL_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8S
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RG
argument_list|,
name|GL_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|R32G32F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RG
argument_list|,
name|GL_HALF_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|R16G16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RG
argument_list|,
name|GL_HALF_FLOAT_OES
argument_list|,
name|WriteColor
argument_list|<
name|R16G16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RG_INTEGER
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RG_INTEGER
argument_list|,
name|GL_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RG_INTEGER
argument_list|,
name|GL_UNSIGNED_SHORT
argument_list|,
name|WriteColor
argument_list|<
name|R16G16
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RG_INTEGER
argument_list|,
name|GL_SHORT
argument_list|,
name|WriteColor
argument_list|<
name|R16G16S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RG_INTEGER
argument_list|,
name|GL_UNSIGNED_INT
argument_list|,
name|WriteColor
argument_list|<
name|R32G32
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RG_INTEGER
argument_list|,
name|GL_INT
argument_list|,
name|WriteColor
argument_list|<
name|R32G32S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RED
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RED
argument_list|,
name|GL_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8S
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RED
argument_list|,
name|GL_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|R32F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RED
argument_list|,
name|GL_HALF_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|R16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RED
argument_list|,
name|GL_HALF_FLOAT_OES
argument_list|,
name|WriteColor
argument_list|<
name|R16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RED_INTEGER
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RED_INTEGER
argument_list|,
name|GL_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RED_INTEGER
argument_list|,
name|GL_UNSIGNED_SHORT
argument_list|,
name|WriteColor
argument_list|<
name|R16
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RED_INTEGER
argument_list|,
name|GL_SHORT
argument_list|,
name|WriteColor
argument_list|<
name|R16S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RED_INTEGER
argument_list|,
name|GL_UNSIGNED_INT
argument_list|,
name|WriteColor
argument_list|<
name|R32
argument_list|,
name|GLuint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_RED_INTEGER
argument_list|,
name|GL_INT
argument_list|,
name|WriteColor
argument_list|<
name|R32S
argument_list|,
name|GLint
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_LUMINANCE_ALPHA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|L8A8
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_LUMINANCE
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|L8
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|A8
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_LUMINANCE_ALPHA
argument_list|,
name|GL_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|L32A32F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_LUMINANCE
argument_list|,
name|GL_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|L32F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|A32F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_LUMINANCE_ALPHA
argument_list|,
name|GL_HALF_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|L16A16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_LUMINANCE_ALPHA
argument_list|,
name|GL_HALF_FLOAT_OES
argument_list|,
name|WriteColor
argument_list|<
name|L16A16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_LUMINANCE
argument_list|,
name|GL_HALF_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|L16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_LUMINANCE
argument_list|,
name|GL_HALF_FLOAT_OES
argument_list|,
name|WriteColor
argument_list|<
name|L16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_HALF_FLOAT
argument_list|,
name|WriteColor
argument_list|<
name|A16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_HALF_FLOAT_OES
argument_list|,
name|WriteColor
argument_list|<
name|A16F
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_BGRA_EXT
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|B8G8R8A8
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_BGRA_EXT
argument_list|,
name|GL_UNSIGNED_SHORT_4_4_4_4_REV_EXT
argument_list|,
name|WriteColor
argument_list|<
name|B4G4R4A4
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_BGRA_EXT
argument_list|,
name|GL_UNSIGNED_SHORT_1_5_5_5_REV_EXT
argument_list|,
name|WriteColor
argument_list|<
name|B5G5R5A1
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_SRGB_EXT
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8B8
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_SRGB_ALPHA_EXT
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|WriteColor
argument_list|<
name|R8G8B8A8
argument_list|,
name|GLfloat
argument_list|>
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_COMPRESSED_RGB_S3TC_DXT1_EXT
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_COMPRESSED_RGBA_S3TC_DXT1_EXT
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_DEPTH_COMPONENT
argument_list|,
name|GL_UNSIGNED_SHORT
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_DEPTH_COMPONENT
argument_list|,
name|GL_UNSIGNED_INT
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_DEPTH_COMPONENT
argument_list|,
name|GL_FLOAT
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_STENCIL
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_DEPTH_STENCIL
argument_list|,
name|GL_UNSIGNED_INT_24_8
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|InsertFormatWriteFunctionMapping
argument_list|(
operator|&
name|map
argument_list|,
name|GL_DEPTH_STENCIL
argument_list|,
name|GL_FLOAT_32_UNSIGNED_INT_24_8_REV
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
name|map
return|;
block|}
DECL|function|GetColorWriteFunction
name|ColorWriteFunction
name|GetColorWriteFunction
parameter_list|(
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|)
block|{
specifier|static
specifier|const
name|FormatWriteFunctionMap
name|formatTypeMap
init|=
name|BuildFormatWriteFunctionMap
argument_list|()
decl_stmt|;
name|FormatWriteFunctionMap
operator|::
name|const_iterator
name|iter
init|=
name|formatTypeMap
operator|.
name|find
argument_list|(
name|FormatTypePair
argument_list|(
name|format
argument_list|,
name|type
argument_list|)
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|iter
operator|!=
name|formatTypeMap
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|iter
operator|!=
name|formatTypeMap
operator|.
name|end
argument_list|()
condition|)
block|{
return|return
name|iter
operator|->
name|second
return|;
block|}
else|else
block|{
return|return
name|NULL
return|;
block|}
block|}
block|}
end_namespace
end_unit