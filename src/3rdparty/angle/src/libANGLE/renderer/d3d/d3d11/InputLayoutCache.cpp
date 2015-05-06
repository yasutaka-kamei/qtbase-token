begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
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
comment|// InputLayoutCache.cpp: Defines InputLayoutCache, a class that builds and caches
end_comment
begin_comment
comment|// D3D11 input layouts.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/InputLayoutCache.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/VertexBuffer11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/Buffer11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/ShaderExecutable11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/d3d11/formatutils11.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/ProgramD3D.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/VertexDataManager.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/Program.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/VertexAttribute.h"
end_include
begin_include
include|#
directive|include
file|"third_party/murmurhash/MurmurHash3.h"
end_include
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|GetInputLayout
specifier|static
name|void
name|GetInputLayout
parameter_list|(
specifier|const
name|TranslatedAttribute
name|translatedAttributes
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
parameter_list|,
name|gl
operator|::
name|VertexFormat
name|inputLayout
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
parameter_list|)
block|{
for|for
control|(
name|unsigned
name|int
name|attributeIndex
init|=
literal|0
init|;
name|attributeIndex
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|attributeIndex
operator|++
control|)
block|{
specifier|const
name|TranslatedAttribute
modifier|&
name|translatedAttribute
init|=
name|translatedAttributes
index|[
name|attributeIndex
index|]
decl_stmt|;
if|if
condition|(
name|translatedAttributes
index|[
name|attributeIndex
index|]
operator|.
name|active
condition|)
block|{
name|inputLayout
index|[
name|attributeIndex
index|]
operator|=
name|gl
operator|::
name|VertexFormat
argument_list|(
operator|*
name|translatedAttribute
operator|.
name|attribute
argument_list|,
name|translatedAttribute
operator|.
name|currentValueType
argument_list|)
expr_stmt|;
block|}
block|}
block|}
DECL|member|kMaxInputLayouts
specifier|const
name|unsigned
name|int
name|InputLayoutCache
operator|::
name|kMaxInputLayouts
init|=
literal|1024
decl_stmt|;
DECL|function|InputLayoutCache
name|InputLayoutCache
operator|::
name|InputLayoutCache
parameter_list|()
member_init_list|:
name|mInputLayoutMap
argument_list|(
name|kMaxInputLayouts
argument_list|,
name|hashInputLayout
argument_list|,
name|compareInputLayouts
argument_list|)
block|{
name|mCounter
operator|=
literal|0
expr_stmt|;
name|mDevice
operator|=
name|NULL
expr_stmt|;
name|mDeviceContext
operator|=
name|NULL
expr_stmt|;
name|mCurrentIL
operator|=
name|NULL
expr_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|i
operator|++
control|)
block|{
name|mCurrentBuffers
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
name|mCurrentVertexStrides
index|[
name|i
index|]
operator|=
cast|static_cast
argument_list|<
name|UINT
argument_list|>
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|mCurrentVertexOffsets
index|[
name|i
index|]
operator|=
cast|static_cast
argument_list|<
name|UINT
argument_list|>
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|mPointSpriteVertexBuffer
operator|=
name|NULL
expr_stmt|;
name|mPointSpriteIndexBuffer
operator|=
name|NULL
expr_stmt|;
block|}
DECL|function|~InputLayoutCache
name|InputLayoutCache
operator|::
name|~
name|InputLayoutCache
parameter_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
DECL|function|initialize
name|void
name|InputLayoutCache
operator|::
name|initialize
parameter_list|(
name|ID3D11Device
modifier|*
name|device
parameter_list|,
name|ID3D11DeviceContext
modifier|*
name|context
parameter_list|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|mDevice
operator|=
name|device
expr_stmt|;
name|mDeviceContext
operator|=
name|context
expr_stmt|;
name|mFeatureLevel
operator|=
name|device
operator|->
name|GetFeatureLevel
argument_list|()
expr_stmt|;
block|}
DECL|function|clear
name|void
name|InputLayoutCache
operator|::
name|clear
parameter_list|()
block|{
for|for
control|(
name|InputLayoutMap
operator|::
name|iterator
name|i
init|=
name|mInputLayoutMap
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mInputLayoutMap
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|SafeRelease
argument_list|(
name|i
operator|->
name|second
operator|.
name|inputLayout
argument_list|)
expr_stmt|;
block|}
name|mInputLayoutMap
operator|.
name|clear
argument_list|()
expr_stmt|;
name|SafeRelease
argument_list|(
name|mPointSpriteVertexBuffer
argument_list|)
expr_stmt|;
name|SafeRelease
argument_list|(
name|mPointSpriteIndexBuffer
argument_list|)
expr_stmt|;
name|markDirty
argument_list|()
expr_stmt|;
block|}
DECL|function|markDirty
name|void
name|InputLayoutCache
operator|::
name|markDirty
parameter_list|()
block|{
name|mCurrentIL
operator|=
name|NULL
expr_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|i
operator|++
control|)
block|{
name|mCurrentBuffers
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
name|mCurrentVertexStrides
index|[
name|i
index|]
operator|=
cast|static_cast
argument_list|<
name|UINT
argument_list|>
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|mCurrentVertexOffsets
index|[
name|i
index|]
operator|=
cast|static_cast
argument_list|<
name|UINT
argument_list|>
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|applyVertexBuffers
name|gl
operator|::
name|Error
name|InputLayoutCache
operator|::
name|applyVertexBuffers
parameter_list|(
name|TranslatedAttribute
name|attributes
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
parameter_list|,
name|GLenum
name|mode
parameter_list|,
name|gl
operator|::
name|Program
modifier|*
name|program
parameter_list|)
block|{
name|ProgramD3D
modifier|*
name|programD3D
init|=
name|GetImplAs
argument_list|<
name|ProgramD3D
argument_list|>
argument_list|(
name|program
argument_list|)
decl_stmt|;
name|int
name|sortedSemanticIndices
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
decl_stmt|;
name|programD3D
operator|->
name|sortAttributesByLayout
argument_list|(
name|attributes
argument_list|,
name|sortedSemanticIndices
argument_list|)
expr_stmt|;
name|bool
name|programUsesInstancedPointSprites
init|=
name|programD3D
operator|->
name|usesPointSize
argument_list|()
operator|&&
name|programD3D
operator|->
name|usesInstancedPointSpriteEmulation
argument_list|()
decl_stmt|;
name|bool
name|instancedPointSpritesActive
init|=
name|programUsesInstancedPointSprites
operator|&&
operator|(
name|mode
operator|==
name|GL_POINTS
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|mDevice
operator|||
operator|!
name|mDeviceContext
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Internal input layout cache is not initialized."
argument_list|)
return|;
block|}
name|InputLayoutKey
name|ilKey
init|=
block|{
literal|0
block|}
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|semanticName
init|=
literal|"TEXCOORD"
decl_stmt|;
name|unsigned
name|int
name|firstIndexedElement
init|=
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
decl_stmt|;
name|unsigned
name|int
name|firstInstancedElement
init|=
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
decl_stmt|;
name|unsigned
name|int
name|nextAvailableInputSlot
init|=
literal|0
decl_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|attributes
index|[
name|i
index|]
operator|.
name|active
condition|)
block|{
name|D3D11_INPUT_CLASSIFICATION
name|inputClass
init|=
name|attributes
index|[
name|i
index|]
operator|.
name|divisor
operator|>
literal|0
condition|?
name|D3D11_INPUT_PER_INSTANCE_DATA
else|:
name|D3D11_INPUT_PER_VERTEX_DATA
decl_stmt|;
comment|// If rendering points and instanced pointsprite emulation is being used, the inputClass is required to be configured as per instance data
name|inputClass
operator|=
name|instancedPointSpritesActive
condition|?
name|D3D11_INPUT_PER_INSTANCE_DATA
else|:
name|inputClass
expr_stmt|;
name|gl
operator|::
name|VertexFormat
name|vertexFormat
argument_list|(
operator|*
name|attributes
index|[
name|i
index|]
operator|.
name|attribute
argument_list|,
name|attributes
index|[
name|i
index|]
operator|.
name|currentValueType
argument_list|)
decl_stmt|;
specifier|const
name|d3d11
operator|::
name|VertexFormat
modifier|&
name|vertexFormatInfo
init|=
name|d3d11
operator|::
name|GetVertexFormatInfo
argument_list|(
name|vertexFormat
argument_list|,
name|mFeatureLevel
argument_list|)
decl_stmt|;
comment|// Record the type of the associated vertex shader vector in our key
comment|// This will prevent mismatched vertex shaders from using the same input layout
name|GLint
name|attributeSize
decl_stmt|;
name|program
operator|->
name|getActiveAttribute
argument_list|(
name|ilKey
operator|.
name|elementCount
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
operator|&
name|attributeSize
argument_list|,
operator|&
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|glslElementType
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|SemanticName
operator|=
name|semanticName
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|SemanticIndex
operator|=
name|sortedSemanticIndices
index|[
name|i
index|]
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|Format
operator|=
name|vertexFormatInfo
operator|.
name|nativeFormat
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|InputSlot
operator|=
name|i
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|AlignedByteOffset
operator|=
literal|0
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|InputSlotClass
operator|=
name|inputClass
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|InstanceDataStepRate
operator|=
name|instancedPointSpritesActive
condition|?
literal|1
else|:
name|attributes
index|[
name|i
index|]
operator|.
name|divisor
expr_stmt|;
if|if
condition|(
name|inputClass
operator|==
name|D3D11_INPUT_PER_VERTEX_DATA
operator|&&
name|firstIndexedElement
operator|==
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|)
block|{
name|firstIndexedElement
operator|=
name|ilKey
operator|.
name|elementCount
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|inputClass
operator|==
name|D3D11_INPUT_PER_INSTANCE_DATA
operator|&&
name|firstInstancedElement
operator|==
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|)
block|{
name|firstInstancedElement
operator|=
name|ilKey
operator|.
name|elementCount
expr_stmt|;
block|}
name|ilKey
operator|.
name|elementCount
operator|++
expr_stmt|;
name|nextAvailableInputSlot
operator|=
name|i
operator|+
literal|1
expr_stmt|;
block|}
block|}
comment|// Instanced PointSprite emulation requires additional entries in the
comment|// inputlayout to support the vertices that make up the pointsprite quad.
comment|// We do this even if mode != GL_POINTS, since the shader signature has these inputs, and the input layout must match the shader
if|if
condition|(
name|programUsesInstancedPointSprites
condition|)
block|{
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|SemanticName
operator|=
literal|"SPRITEPOSITION"
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|SemanticIndex
operator|=
literal|0
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|Format
operator|=
name|DXGI_FORMAT_R32G32B32_FLOAT
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|InputSlot
operator|=
name|nextAvailableInputSlot
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|AlignedByteOffset
operator|=
literal|0
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|InputSlotClass
operator|=
name|D3D11_INPUT_PER_VERTEX_DATA
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|InstanceDataStepRate
operator|=
literal|0
expr_stmt|;
comment|// The new elements are D3D11_INPUT_PER_VERTEX_DATA data so the indexed element
comment|// tracking must be applied.  This ensures that the instancing specific
comment|// buffer swapping logic continues to work.
if|if
condition|(
name|firstIndexedElement
operator|==
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|)
block|{
name|firstIndexedElement
operator|=
name|ilKey
operator|.
name|elementCount
expr_stmt|;
block|}
name|ilKey
operator|.
name|elementCount
operator|++
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|SemanticName
operator|=
literal|"SPRITETEXCOORD"
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|SemanticIndex
operator|=
literal|0
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|Format
operator|=
name|DXGI_FORMAT_R32G32_FLOAT
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|InputSlot
operator|=
name|nextAvailableInputSlot
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|AlignedByteOffset
operator|=
sizeof|sizeof
argument_list|(
name|float
argument_list|)
operator|*
literal|3
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|InputSlotClass
operator|=
name|D3D11_INPUT_PER_VERTEX_DATA
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|ilKey
operator|.
name|elementCount
index|]
operator|.
name|desc
operator|.
name|InstanceDataStepRate
operator|=
literal|0
expr_stmt|;
name|ilKey
operator|.
name|elementCount
operator|++
expr_stmt|;
block|}
comment|// On 9_3, we must ensure that slot 0 contains non-instanced data.
comment|// If slot 0 currently contains instanced data then we swap it with a non-instanced element.
comment|// Note that instancing is only available on 9_3 via ANGLE_instanced_arrays, since 9_3 doesn't support OpenGL ES 3.0.
comment|// As per the spec for ANGLE_instanced_arrays, not all attributes can be instanced simultaneously, so a non-instanced element must exist.
name|ASSERT
argument_list|(
operator|!
operator|(
name|mFeatureLevel
operator|<=
name|D3D_FEATURE_LEVEL_9_3
operator|&&
name|firstIndexedElement
operator|==
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
operator|)
argument_list|)
expr_stmt|;
name|bool
name|moveFirstIndexedIntoSlotZero
init|=
name|mFeatureLevel
operator|<=
name|D3D_FEATURE_LEVEL_9_3
operator|&&
name|firstInstancedElement
operator|==
literal|0
operator|&&
name|firstIndexedElement
operator|!=
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
decl_stmt|;
if|if
condition|(
name|moveFirstIndexedIntoSlotZero
condition|)
block|{
name|ilKey
operator|.
name|elements
index|[
name|firstInstancedElement
index|]
operator|.
name|desc
operator|.
name|InputSlot
operator|=
name|ilKey
operator|.
name|elements
index|[
name|firstIndexedElement
index|]
operator|.
name|desc
operator|.
name|InputSlot
expr_stmt|;
name|ilKey
operator|.
name|elements
index|[
name|firstIndexedElement
index|]
operator|.
name|desc
operator|.
name|InputSlot
operator|=
literal|0
expr_stmt|;
comment|// Instanced PointSprite emulation uses multiple layout entries across a single vertex buffer.
comment|// If an index swap is performed, we need to ensure that all elements get the proper InputSlot.
if|if
condition|(
name|programUsesInstancedPointSprites
condition|)
block|{
name|ilKey
operator|.
name|elements
index|[
name|firstIndexedElement
operator|+
literal|1
index|]
operator|.
name|desc
operator|.
name|InputSlot
operator|=
literal|0
expr_stmt|;
block|}
block|}
name|ID3D11InputLayout
modifier|*
name|inputLayout
init|=
name|NULL
decl_stmt|;
name|InputLayoutMap
operator|::
name|iterator
name|keyIter
init|=
name|mInputLayoutMap
operator|.
name|find
argument_list|(
name|ilKey
argument_list|)
decl_stmt|;
if|if
condition|(
name|keyIter
operator|!=
name|mInputLayoutMap
operator|.
name|end
argument_list|()
condition|)
block|{
name|inputLayout
operator|=
name|keyIter
operator|->
name|second
operator|.
name|inputLayout
expr_stmt|;
name|keyIter
operator|->
name|second
operator|.
name|lastUsedTime
operator|=
name|mCounter
operator|++
expr_stmt|;
block|}
else|else
block|{
name|gl
operator|::
name|VertexFormat
name|shaderInputLayout
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
decl_stmt|;
name|GetInputLayout
argument_list|(
name|attributes
argument_list|,
name|shaderInputLayout
argument_list|)
expr_stmt|;
name|ShaderExecutableD3D
modifier|*
name|shader
init|=
name|NULL
decl_stmt|;
name|gl
operator|::
name|Error
name|error
init|=
name|programD3D
operator|->
name|getVertexExecutableForInputLayout
argument_list|(
name|shaderInputLayout
argument_list|,
operator|&
name|shader
argument_list|,
literal|nullptr
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
operator|.
name|isError
argument_list|()
condition|)
block|{
return|return
name|error
return|;
block|}
name|ShaderExecutableD3D
modifier|*
name|shader11
init|=
name|ShaderExecutable11
operator|::
name|makeShaderExecutable11
argument_list|(
name|shader
argument_list|)
decl_stmt|;
name|D3D11_INPUT_ELEMENT_DESC
name|descs
index|[
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
index|]
decl_stmt|;
for|for
control|(
name|unsigned
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|ilKey
operator|.
name|elementCount
condition|;
operator|++
name|j
control|)
block|{
name|descs
index|[
name|j
index|]
operator|=
name|ilKey
operator|.
name|elements
index|[
name|j
index|]
operator|.
name|desc
expr_stmt|;
block|}
name|HRESULT
name|result
init|=
name|mDevice
operator|->
name|CreateInputLayout
argument_list|(
name|descs
argument_list|,
name|ilKey
operator|.
name|elementCount
argument_list|,
name|shader11
operator|->
name|getFunction
argument_list|()
argument_list|,
name|shader11
operator|->
name|getLength
argument_list|()
argument_list|,
operator|&
name|inputLayout
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to create internal input layout, HRESULT: 0x%08x"
argument_list|,
name|result
argument_list|)
return|;
block|}
if|if
condition|(
name|mInputLayoutMap
operator|.
name|size
argument_list|()
operator|>=
name|kMaxInputLayouts
condition|)
block|{
name|TRACE
argument_list|(
literal|"Overflowed the limit of %u input layouts, removing the least recently used "
literal|"to make room."
argument_list|,
name|kMaxInputLayouts
argument_list|)
expr_stmt|;
name|InputLayoutMap
operator|::
name|iterator
name|leastRecentlyUsed
init|=
name|mInputLayoutMap
operator|.
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
name|InputLayoutMap
operator|::
name|iterator
name|i
init|=
name|mInputLayoutMap
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|mInputLayoutMap
operator|.
name|end
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|->
name|second
operator|.
name|lastUsedTime
operator|<
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|lastUsedTime
condition|)
block|{
name|leastRecentlyUsed
operator|=
name|i
expr_stmt|;
block|}
block|}
name|SafeRelease
argument_list|(
name|leastRecentlyUsed
operator|->
name|second
operator|.
name|inputLayout
argument_list|)
expr_stmt|;
name|mInputLayoutMap
operator|.
name|erase
argument_list|(
name|leastRecentlyUsed
argument_list|)
expr_stmt|;
block|}
name|InputLayoutCounterPair
name|inputCounterPair
decl_stmt|;
name|inputCounterPair
operator|.
name|inputLayout
operator|=
name|inputLayout
expr_stmt|;
name|inputCounterPair
operator|.
name|lastUsedTime
operator|=
name|mCounter
operator|++
expr_stmt|;
name|mInputLayoutMap
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|ilKey
argument_list|,
name|inputCounterPair
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|inputLayout
operator|!=
name|mCurrentIL
condition|)
block|{
name|mDeviceContext
operator|->
name|IASetInputLayout
argument_list|(
name|inputLayout
argument_list|)
expr_stmt|;
name|mCurrentIL
operator|=
name|inputLayout
expr_stmt|;
block|}
name|bool
name|dirtyBuffers
init|=
literal|false
decl_stmt|;
name|size_t
name|minDiff
init|=
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
decl_stmt|;
name|size_t
name|maxDiff
init|=
literal|0
decl_stmt|;
name|unsigned
name|int
name|nextAvailableIndex
init|=
literal|0
decl_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
condition|;
name|i
operator|++
control|)
block|{
name|ID3D11Buffer
modifier|*
name|buffer
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|attributes
index|[
name|i
index|]
operator|.
name|active
condition|)
block|{
name|VertexBuffer11
modifier|*
name|vertexBuffer
init|=
name|VertexBuffer11
operator|::
name|makeVertexBuffer11
argument_list|(
name|attributes
index|[
name|i
index|]
operator|.
name|vertexBuffer
argument_list|)
decl_stmt|;
name|Buffer11
modifier|*
name|bufferStorage
init|=
name|attributes
index|[
name|i
index|]
operator|.
name|storage
condition|?
name|Buffer11
operator|::
name|makeBuffer11
argument_list|(
name|attributes
index|[
name|i
index|]
operator|.
name|storage
argument_list|)
else|:
name|NULL
decl_stmt|;
name|buffer
operator|=
name|bufferStorage
condition|?
name|bufferStorage
operator|->
name|getBuffer
argument_list|(
name|BUFFER_USAGE_VERTEX_OR_TRANSFORM_FEEDBACK
argument_list|)
else|:
name|vertexBuffer
operator|->
name|getBuffer
argument_list|()
expr_stmt|;
block|}
name|UINT
name|vertexStride
init|=
name|attributes
index|[
name|i
index|]
operator|.
name|stride
decl_stmt|;
name|UINT
name|vertexOffset
init|=
name|attributes
index|[
name|i
index|]
operator|.
name|offset
decl_stmt|;
if|if
condition|(
name|buffer
operator|!=
name|mCurrentBuffers
index|[
name|i
index|]
operator|||
name|vertexStride
operator|!=
name|mCurrentVertexStrides
index|[
name|i
index|]
operator|||
name|vertexOffset
operator|!=
name|mCurrentVertexOffsets
index|[
name|i
index|]
condition|)
block|{
name|dirtyBuffers
operator|=
literal|true
expr_stmt|;
name|minDiff
operator|=
name|std
operator|::
name|min
argument_list|(
name|minDiff
argument_list|,
cast|static_cast
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|maxDiff
operator|=
name|std
operator|::
name|max
argument_list|(
name|maxDiff
argument_list|,
cast|static_cast
argument_list|<
name|size_t
argument_list|>
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|mCurrentBuffers
index|[
name|i
index|]
operator|=
name|buffer
expr_stmt|;
name|mCurrentVertexStrides
index|[
name|i
index|]
operator|=
name|vertexStride
expr_stmt|;
name|mCurrentVertexOffsets
index|[
name|i
index|]
operator|=
name|vertexOffset
expr_stmt|;
comment|// If a non null ID3D11Buffer is being assigned to mCurrentBuffers,
comment|// then the next available index needs to be tracked to ensure
comment|// that any instanced pointsprite emulation buffers will be properly packed.
if|if
condition|(
name|buffer
condition|)
block|{
name|nextAvailableIndex
operator|=
name|i
operator|+
literal|1
expr_stmt|;
block|}
block|}
block|}
comment|// Instanced PointSprite emulation requires two additional ID3D11Buffers.
comment|// A vertex buffer needs to be created and added to the list of current buffers,
comment|// strides and offsets collections.  This buffer contains the vertices for a single
comment|// PointSprite quad.
comment|// An index buffer also needs to be created and applied because rendering instanced
comment|// data on D3D11 FL9_3 requires DrawIndexedInstanced() to be used.
if|if
condition|(
name|instancedPointSpritesActive
condition|)
block|{
name|HRESULT
name|result
init|=
name|S_OK
decl_stmt|;
specifier|const
name|UINT
name|pointSpriteVertexStride
init|=
sizeof|sizeof
argument_list|(
name|float
argument_list|)
operator|*
literal|5
decl_stmt|;
if|if
condition|(
operator|!
name|mPointSpriteVertexBuffer
condition|)
block|{
specifier|static
specifier|const
name|float
name|pointSpriteVertices
index|[]
init|=
block|{
comment|// Position        // TexCoord
operator|-
literal|1.0f
block|,
operator|-
literal|1.0f
block|,
literal|0.0f
block|,
literal|0.0f
block|,
literal|1.0f
block|,
operator|-
literal|1.0f
block|,
literal|1.0f
block|,
literal|0.0f
block|,
literal|0.0f
block|,
literal|0.0f
block|,
literal|1.0f
block|,
literal|1.0f
block|,
literal|0.0f
block|,
literal|1.0f
block|,
literal|0.0f
block|,
literal|1.0f
block|,
operator|-
literal|1.0f
block|,
literal|0.0f
block|,
literal|1.0f
block|,
literal|1.0f
block|,
operator|-
literal|1.0f
block|,
operator|-
literal|1.0f
block|,
literal|0.0f
block|,
literal|0.0f
block|,
literal|1.0f
block|,
literal|1.0f
block|,
literal|1.0f
block|,
literal|0.0f
block|,
literal|1.0f
block|,
literal|0.0f
block|,             }
decl_stmt|;
name|D3D11_SUBRESOURCE_DATA
name|vertexBufferData
init|=
block|{
name|pointSpriteVertices
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|D3D11_BUFFER_DESC
name|vertexBufferDesc
decl_stmt|;
name|vertexBufferDesc
operator|.
name|ByteWidth
operator|=
sizeof|sizeof
argument_list|(
name|pointSpriteVertices
argument_list|)
expr_stmt|;
name|vertexBufferDesc
operator|.
name|BindFlags
operator|=
name|D3D11_BIND_VERTEX_BUFFER
expr_stmt|;
name|vertexBufferDesc
operator|.
name|Usage
operator|=
name|D3D11_USAGE_IMMUTABLE
expr_stmt|;
name|vertexBufferDesc
operator|.
name|CPUAccessFlags
operator|=
literal|0
expr_stmt|;
name|vertexBufferDesc
operator|.
name|MiscFlags
operator|=
literal|0
expr_stmt|;
name|vertexBufferDesc
operator|.
name|StructureByteStride
operator|=
literal|0
expr_stmt|;
name|result
operator|=
name|mDevice
operator|->
name|CreateBuffer
argument_list|(
operator|&
name|vertexBufferDesc
argument_list|,
operator|&
name|vertexBufferData
argument_list|,
operator|&
name|mPointSpriteVertexBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to create instanced pointsprite emulation vertex buffer, HRESULT: 0x%08x"
argument_list|,
name|result
argument_list|)
return|;
block|}
block|}
name|mCurrentBuffers
index|[
name|nextAvailableIndex
index|]
operator|=
name|mPointSpriteVertexBuffer
expr_stmt|;
name|mCurrentVertexStrides
index|[
name|nextAvailableIndex
index|]
operator|=
name|pointSpriteVertexStride
expr_stmt|;
name|mCurrentVertexOffsets
index|[
name|nextAvailableIndex
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|mPointSpriteIndexBuffer
condition|)
block|{
comment|// Create an index buffer and set it for pointsprite rendering
specifier|static
specifier|const
name|unsigned
name|short
name|pointSpriteIndices
index|[]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,             }
decl_stmt|;
name|D3D11_SUBRESOURCE_DATA
name|indexBufferData
init|=
block|{
name|pointSpriteIndices
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|D3D11_BUFFER_DESC
name|indexBufferDesc
decl_stmt|;
name|indexBufferDesc
operator|.
name|ByteWidth
operator|=
sizeof|sizeof
argument_list|(
name|pointSpriteIndices
argument_list|)
expr_stmt|;
name|indexBufferDesc
operator|.
name|BindFlags
operator|=
name|D3D11_BIND_INDEX_BUFFER
expr_stmt|;
name|indexBufferDesc
operator|.
name|Usage
operator|=
name|D3D11_USAGE_IMMUTABLE
expr_stmt|;
name|indexBufferDesc
operator|.
name|CPUAccessFlags
operator|=
literal|0
expr_stmt|;
name|indexBufferDesc
operator|.
name|MiscFlags
operator|=
literal|0
expr_stmt|;
name|indexBufferDesc
operator|.
name|StructureByteStride
operator|=
literal|0
expr_stmt|;
name|result
operator|=
name|mDevice
operator|->
name|CreateBuffer
argument_list|(
operator|&
name|indexBufferDesc
argument_list|,
operator|&
name|indexBufferData
argument_list|,
operator|&
name|mPointSpriteIndexBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|result
argument_list|)
condition|)
block|{
name|SafeRelease
argument_list|(
name|mPointSpriteVertexBuffer
argument_list|)
expr_stmt|;
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_OUT_OF_MEMORY
argument_list|,
literal|"Failed to create instanced pointsprite emulation index buffer, HRESULT: 0x%08x"
argument_list|,
name|result
argument_list|)
return|;
block|}
block|}
comment|// The index buffer is applied here because Instanced PointSprite emulation uses
comment|// the a non-indexed rendering path in ANGLE (DrawArrays).  This means that applyIndexBuffer()
comment|// on the renderer will not be called and setting this buffer here ensures that the rendering
comment|// path will contain the correct index buffers.
name|mDeviceContext
operator|->
name|IASetIndexBuffer
argument_list|(
name|mPointSpriteIndexBuffer
argument_list|,
name|DXGI_FORMAT_R16_UINT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|moveFirstIndexedIntoSlotZero
condition|)
block|{
comment|// In this case, we swapped the slots of the first instanced element and the first indexed element, to ensure
comment|// that the first slot contains non-instanced data (required by Feature Level 9_3).
comment|// We must also swap the corresponding buffers sent to IASetVertexBuffers so that the correct data is sent to each slot.
name|std
operator|::
name|swap
argument_list|(
name|mCurrentBuffers
index|[
name|firstIndexedElement
index|]
argument_list|,
name|mCurrentBuffers
index|[
name|firstInstancedElement
index|]
argument_list|)
expr_stmt|;
name|std
operator|::
name|swap
argument_list|(
name|mCurrentVertexStrides
index|[
name|firstIndexedElement
index|]
argument_list|,
name|mCurrentVertexStrides
index|[
name|firstInstancedElement
index|]
argument_list|)
expr_stmt|;
name|std
operator|::
name|swap
argument_list|(
name|mCurrentVertexOffsets
index|[
name|firstIndexedElement
index|]
argument_list|,
name|mCurrentVertexOffsets
index|[
name|firstInstancedElement
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|dirtyBuffers
condition|)
block|{
name|ASSERT
argument_list|(
name|minDiff
operator|<=
name|maxDiff
operator|&&
name|maxDiff
operator|<
name|gl
operator|::
name|MAX_VERTEX_ATTRIBS
argument_list|)
expr_stmt|;
name|mDeviceContext
operator|->
name|IASetVertexBuffers
argument_list|(
name|minDiff
argument_list|,
name|maxDiff
operator|-
name|minDiff
operator|+
literal|1
argument_list|,
name|mCurrentBuffers
operator|+
name|minDiff
argument_list|,
name|mCurrentVertexStrides
operator|+
name|minDiff
argument_list|,
name|mCurrentVertexOffsets
operator|+
name|minDiff
argument_list|)
expr_stmt|;
block|}
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
DECL|function|hashInputLayout
name|std
operator|::
name|size_t
name|InputLayoutCache
operator|::
name|hashInputLayout
parameter_list|(
specifier|const
name|InputLayoutKey
modifier|&
name|inputLayout
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|int
name|seed
init|=
literal|0xDEADBEEF
decl_stmt|;
name|std
operator|::
name|size_t
name|hash
init|=
literal|0
decl_stmt|;
name|MurmurHash3_x86_32
argument_list|(
name|inputLayout
operator|.
name|begin
argument_list|()
argument_list|,
name|inputLayout
operator|.
name|end
argument_list|()
operator|-
name|inputLayout
operator|.
name|begin
argument_list|()
argument_list|,
name|seed
argument_list|,
operator|&
name|hash
argument_list|)
expr_stmt|;
return|return
name|hash
return|;
block|}
DECL|function|compareInputLayouts
name|bool
name|InputLayoutCache
operator|::
name|compareInputLayouts
parameter_list|(
specifier|const
name|InputLayoutKey
modifier|&
name|a
parameter_list|,
specifier|const
name|InputLayoutKey
modifier|&
name|b
parameter_list|)
block|{
if|if
condition|(
name|a
operator|.
name|elementCount
operator|!=
name|b
operator|.
name|elementCount
condition|)
block|{
return|return
literal|false
return|;
block|}
return|return
name|std
operator|::
name|equal
argument_list|(
name|a
operator|.
name|begin
argument_list|()
argument_list|,
name|a
operator|.
name|end
argument_list|()
argument_list|,
name|b
operator|.
name|begin
argument_list|()
argument_list|)
return|;
block|}
block|}
end_namespace
end_unit