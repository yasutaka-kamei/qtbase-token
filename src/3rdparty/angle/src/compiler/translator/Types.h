begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
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
begin_ifndef
ifndef|#
directive|ifndef
name|_TYPES_INCLUDED
end_ifndef
begin_define
DECL|macro|_TYPES_INCLUDED
define|#
directive|define
name|_TYPES_INCLUDED
end_define
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/BaseTypes.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Common.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/compilerdebug.h"
end_include
begin_struct_decl
struct_decl|struct
name|TPublicType
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|TType
name|class
name|TType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TSymbol
name|class
name|TSymbol
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|TField
block|{
name|public
label|:
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|()
expr_stmt|;
name|TField
argument_list|(
name|TType
operator|*
name|type
argument_list|,
name|TString
operator|*
name|name
argument_list|,
specifier|const
name|TSourceLoc
operator|&
name|line
argument_list|)
operator|:
name|mType
argument_list|(
name|type
argument_list|)
operator|,
name|mName
argument_list|(
name|name
argument_list|)
operator|,
name|mLine
argument_list|(
argument|line
argument_list|)
block|{     }
comment|// TODO(alokp): We should only return const type.
comment|// Fix it by tweaking grammar.
name|TType
operator|*
name|type
argument_list|()
block|{
return|return
name|mType
return|;
block|}
specifier|const
name|TType
operator|*
name|type
argument_list|()
specifier|const
block|{
return|return
name|mType
return|;
block|}
specifier|const
name|TString
operator|&
name|name
argument_list|()
specifier|const
block|{
return|return
operator|*
name|mName
return|;
block|}
specifier|const
name|TSourceLoc
operator|&
name|line
argument_list|()
specifier|const
block|{
return|return
name|mLine
return|;
block|}
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TField
argument_list|)
expr_stmt|;
name|TType
modifier|*
name|mType
decl_stmt|;
name|TString
modifier|*
name|mName
decl_stmt|;
name|TSourceLoc
name|mLine
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
DECL|typedef|TFieldList
typedef|typedef
name|TVector
operator|<
name|TField
operator|*
operator|>
name|TFieldList
expr_stmt|;
end_typedef
begin_function
DECL|function|NewPoolTFieldList
specifier|inline
name|TFieldList
modifier|*
name|NewPoolTFieldList
parameter_list|()
block|{
name|void
modifier|*
name|memory
init|=
name|GetGlobalPoolAllocator
argument_list|()
operator|->
name|allocate
argument_list|(
sizeof|sizeof
argument_list|(
name|TFieldList
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|new
argument_list|(
argument|memory
argument_list|)
name|TFieldList
return|;
block|}
end_function
begin_decl_stmt
name|class
name|TFieldListCollection
block|{
name|public
label|:
specifier|const
name|TString
operator|&
name|name
argument_list|()
specifier|const
block|{
return|return
operator|*
name|mName
return|;
block|}
specifier|const
name|TFieldList
operator|&
name|fields
argument_list|()
specifier|const
block|{
return|return
operator|*
name|mFields
return|;
block|}
specifier|const
name|TString
operator|&
name|mangledName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|mMangledName
operator|.
name|empty
argument_list|()
condition|)
name|mMangledName
operator|=
name|buildMangledName
argument_list|()
expr_stmt|;
return|return
name|mMangledName
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|size_t
name|objectSize
argument_list|()
specifier|const
block|{
if|if
condition|(
name|mObjectSize
operator|==
literal|0
condition|)
name|mObjectSize
operator|=
name|calculateObjectSize
argument_list|()
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|mObjectSize
return|;
end_return
begin_label
unit|};
name|protected
label|:
end_label
begin_expr_stmt
name|TFieldListCollection
argument_list|(
specifier|const
name|TString
operator|*
name|name
argument_list|,
name|TFieldList
operator|*
name|fields
argument_list|)
operator|:
name|mName
argument_list|(
name|name
argument_list|)
operator|,
name|mFields
argument_list|(
name|fields
argument_list|)
operator|,
name|mObjectSize
argument_list|(
literal|0
argument_list|)
block|{     }
name|TString
name|buildMangledName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|size_t
name|calculateObjectSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
name|TString
name|mangledNamePrefix
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|const
name|TString
modifier|*
name|mName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TFieldList
modifier|*
name|mFields
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|TString
name|mMangledName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|size_t
name|mObjectSize
decl_stmt|;
end_decl_stmt
begin_comment
unit|};
comment|// May also represent interface blocks
end_comment
begin_decl_stmt
name|class
name|TStructure
range|:
name|public
name|TFieldListCollection
block|{
name|public
operator|:
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|()
block|;
name|TStructure
argument_list|(
specifier|const
name|TString
operator|*
name|name
argument_list|,
name|TFieldList
operator|*
name|fields
argument_list|)
operator|:
name|TFieldListCollection
argument_list|(
name|name
argument_list|,
name|fields
argument_list|)
block|,
name|mDeepestNesting
argument_list|(
literal|0
argument_list|)
block|,
name|mUniqueId
argument_list|(
literal|0
argument_list|)
block|{     }
name|int
name|deepestNesting
argument_list|()
specifier|const
block|{
if|if
condition|(
name|mDeepestNesting
operator|==
literal|0
condition|)
name|mDeepestNesting
operator|=
name|calculateDeepestNesting
argument_list|()
expr_stmt|;
return|return
name|mDeepestNesting
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|bool
name|containsArrays
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|equals
argument_list|(
specifier|const
name|TStructure
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function
name|void
name|setUniqueId
parameter_list|(
name|int
name|uniqueId
parameter_list|)
block|{
name|mUniqueId
operator|=
name|uniqueId
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|int
name|uniqueId
argument_list|()
specifier|const
block|{
name|ASSERT
argument_list|(
name|mUniqueId
operator|!=
literal|0
argument_list|)
block|;
return|return
name|mUniqueId
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TStructure
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// TODO(zmo): Find a way to get rid of the const_cast in function
end_comment
begin_comment
comment|// setName().  At the moment keep this function private so only
end_comment
begin_comment
comment|// friend class RegenerateStructNames may call it.
end_comment
begin_decl_stmt
name|friend
name|class
name|RegenerateStructNames
decl_stmt|;
end_decl_stmt
begin_function
name|void
name|setName
parameter_list|(
specifier|const
name|TString
modifier|&
name|name
parameter_list|)
block|{
name|TString
modifier|*
name|mutableName
init|=
name|const_cast
operator|<
name|TString
operator|*
operator|>
operator|(
name|mName
operator|)
decl_stmt|;
operator|*
name|mutableName
operator|=
name|name
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|virtual
name|TString
name|mangledNamePrefix
argument_list|()
specifier|const
block|{
return|return
literal|"struct-"
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|calculateDeepestNesting
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|mutable
name|int
name|mDeepestNesting
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|mUniqueId
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|TInterfaceBlock
range|:
name|public
name|TFieldListCollection
block|{
name|public
operator|:
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|()
block|;
name|TInterfaceBlock
argument_list|(
argument|const TString *name
argument_list|,
argument|TFieldList *fields
argument_list|,
argument|const TString *instanceName
argument_list|,
argument|int arraySize
argument_list|,
argument|const TLayoutQualifier&layoutQualifier
argument_list|)
operator|:
name|TFieldListCollection
argument_list|(
name|name
argument_list|,
name|fields
argument_list|)
block|,
name|mInstanceName
argument_list|(
name|instanceName
argument_list|)
block|,
name|mArraySize
argument_list|(
name|arraySize
argument_list|)
block|,
name|mBlockStorage
argument_list|(
name|layoutQualifier
operator|.
name|blockStorage
argument_list|)
block|,
name|mMatrixPacking
argument_list|(
argument|layoutQualifier.matrixPacking
argument_list|)
block|{     }
specifier|const
name|TString
operator|&
name|instanceName
argument_list|()
specifier|const
block|{
return|return
operator|*
name|mInstanceName
return|;
block|}
name|bool
name|hasInstanceName
argument_list|()
specifier|const
block|{
return|return
name|mInstanceName
operator|!=
name|NULL
return|;
block|}
name|bool
name|isArray
argument_list|()
specifier|const
block|{
return|return
name|mArraySize
operator|>
literal|0
return|;
block|}
name|int
name|arraySize
argument_list|()
specifier|const
block|{
return|return
name|mArraySize
return|;
block|}
name|TLayoutBlockStorage
name|blockStorage
argument_list|()
specifier|const
block|{
return|return
name|mBlockStorage
return|;
block|}
name|TLayoutMatrixPacking
name|matrixPacking
argument_list|()
specifier|const
block|{
return|return
name|mMatrixPacking
return|;
block|}
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TInterfaceBlock
argument_list|)
block|;
name|virtual
name|TString
name|mangledNamePrefix
argument_list|()
specifier|const
block|{
return|return
literal|"iblock-"
return|;
block|}
specifier|const
name|TString
operator|*
name|mInstanceName
block|;
comment|// for interface block instance names
name|int
name|mArraySize
block|;
comment|// 0 if not an array
name|TLayoutBlockStorage
name|mBlockStorage
block|;
name|TLayoutMatrixPacking
name|mMatrixPacking
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|//
end_comment
begin_comment
comment|// Base class for things that have a type.
end_comment
begin_comment
comment|//
end_comment
begin_decl_stmt
name|class
name|TType
block|{
name|public
label|:
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|()
expr_stmt|;
name|TType
argument_list|()
block|{     }
name|TType
argument_list|(
argument|TBasicType t
argument_list|,
argument|unsigned char ps =
literal|1
argument_list|,
argument|unsigned char ss =
literal|1
argument_list|)
block|:
name|type
argument_list|(
name|t
argument_list|)
operator|,
name|precision
argument_list|(
name|EbpUndefined
argument_list|)
operator|,
name|qualifier
argument_list|(
name|EvqGlobal
argument_list|)
operator|,
name|layoutQualifier
argument_list|(
name|TLayoutQualifier
operator|::
name|create
argument_list|()
argument_list|)
operator|,
name|primarySize
argument_list|(
name|ps
argument_list|)
operator|,
name|secondarySize
argument_list|(
name|ss
argument_list|)
operator|,
name|array
argument_list|(
name|false
argument_list|)
operator|,
name|arraySize
argument_list|(
literal|0
argument_list|)
operator|,
name|interfaceBlock
argument_list|(
literal|0
argument_list|)
operator|,
name|structure
argument_list|(
literal|0
argument_list|)
block|{     }
name|TType
argument_list|(
argument|TBasicType t
argument_list|,
argument|TPrecision p
argument_list|,
argument|TQualifier q = EvqTemporary
argument_list|,
argument|unsigned char ps =
literal|1
argument_list|,
argument|unsigned char ss =
literal|1
argument_list|,
argument|bool a = false
argument_list|)
operator|:
name|type
argument_list|(
name|t
argument_list|)
operator|,
name|precision
argument_list|(
name|p
argument_list|)
operator|,
name|qualifier
argument_list|(
name|q
argument_list|)
operator|,
name|layoutQualifier
argument_list|(
name|TLayoutQualifier
operator|::
name|create
argument_list|()
argument_list|)
operator|,
name|primarySize
argument_list|(
name|ps
argument_list|)
operator|,
name|secondarySize
argument_list|(
name|ss
argument_list|)
operator|,
name|array
argument_list|(
name|a
argument_list|)
operator|,
name|arraySize
argument_list|(
literal|0
argument_list|)
operator|,
name|interfaceBlock
argument_list|(
literal|0
argument_list|)
operator|,
name|structure
argument_list|(
literal|0
argument_list|)
block|{     }
name|explicit
name|TType
argument_list|(
specifier|const
name|TPublicType
operator|&
name|p
argument_list|)
expr_stmt|;
name|TType
argument_list|(
argument|TStructure *userDef
argument_list|,
argument|TPrecision p = EbpUndefined
argument_list|)
block|:
name|type
argument_list|(
name|EbtStruct
argument_list|)
operator|,
name|precision
argument_list|(
name|p
argument_list|)
operator|,
name|qualifier
argument_list|(
name|EvqTemporary
argument_list|)
operator|,
name|layoutQualifier
argument_list|(
name|TLayoutQualifier
operator|::
name|create
argument_list|()
argument_list|)
operator|,
name|primarySize
argument_list|(
literal|1
argument_list|)
operator|,
name|secondarySize
argument_list|(
literal|1
argument_list|)
operator|,
name|array
argument_list|(
name|false
argument_list|)
operator|,
name|arraySize
argument_list|(
literal|0
argument_list|)
operator|,
name|interfaceBlock
argument_list|(
literal|0
argument_list|)
operator|,
name|structure
argument_list|(
argument|userDef
argument_list|)
block|{     }
name|TType
argument_list|(
argument|TInterfaceBlock *interfaceBlockIn
argument_list|,
argument|TQualifier qualifierIn
argument_list|,
argument|TLayoutQualifier layoutQualifierIn
argument_list|,
argument|int arraySizeIn
argument_list|)
operator|:
name|type
argument_list|(
name|EbtInterfaceBlock
argument_list|)
operator|,
name|precision
argument_list|(
name|EbpUndefined
argument_list|)
operator|,
name|qualifier
argument_list|(
name|qualifierIn
argument_list|)
operator|,
name|layoutQualifier
argument_list|(
name|layoutQualifierIn
argument_list|)
operator|,
name|primarySize
argument_list|(
literal|1
argument_list|)
operator|,
name|secondarySize
argument_list|(
literal|1
argument_list|)
operator|,
name|array
argument_list|(
name|arraySizeIn
operator|>
literal|0
argument_list|)
operator|,
name|arraySize
argument_list|(
name|arraySizeIn
argument_list|)
operator|,
name|interfaceBlock
argument_list|(
name|interfaceBlockIn
argument_list|)
operator|,
name|structure
argument_list|(
literal|0
argument_list|)
block|{     }
name|TBasicType
name|getBasicType
argument_list|()
specifier|const
block|{
return|return
name|type
return|;
block|}
name|void
name|setBasicType
parameter_list|(
name|TBasicType
name|t
parameter_list|)
block|{
name|type
operator|=
name|t
expr_stmt|;
block|}
name|TPrecision
name|getPrecision
argument_list|()
specifier|const
block|{
return|return
name|precision
return|;
block|}
name|void
name|setPrecision
parameter_list|(
name|TPrecision
name|p
parameter_list|)
block|{
name|precision
operator|=
name|p
expr_stmt|;
block|}
name|TQualifier
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|qualifier
return|;
block|}
name|void
name|setQualifier
parameter_list|(
name|TQualifier
name|q
parameter_list|)
block|{
name|qualifier
operator|=
name|q
expr_stmt|;
block|}
name|TLayoutQualifier
name|getLayoutQualifier
argument_list|()
specifier|const
block|{
return|return
name|layoutQualifier
return|;
block|}
name|void
name|setLayoutQualifier
parameter_list|(
name|TLayoutQualifier
name|lq
parameter_list|)
block|{
name|layoutQualifier
operator|=
name|lq
expr_stmt|;
block|}
name|int
name|getNominalSize
argument_list|()
specifier|const
block|{
return|return
name|primarySize
return|;
block|}
name|int
name|getSecondarySize
argument_list|()
specifier|const
block|{
return|return
name|secondarySize
return|;
block|}
name|int
name|getCols
argument_list|()
specifier|const
block|{
name|ASSERT
argument_list|(
name|isMatrix
argument_list|()
argument_list|)
block|;
return|return
name|primarySize
return|;
block|}
name|int
name|getRows
argument_list|()
specifier|const
block|{
name|ASSERT
argument_list|(
name|isMatrix
argument_list|()
argument_list|)
block|;
return|return
name|secondarySize
return|;
block|}
name|void
name|setPrimarySize
parameter_list|(
name|unsigned
name|char
name|ps
parameter_list|)
block|{
name|primarySize
operator|=
name|ps
expr_stmt|;
block|}
name|void
name|setSecondarySize
parameter_list|(
name|unsigned
name|char
name|ss
parameter_list|)
block|{
name|secondarySize
operator|=
name|ss
expr_stmt|;
block|}
comment|// Full size of single instance of type
name|size_t
name|getObjectSize
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isMatrix
argument_list|()
specifier|const
block|{
return|return
name|primarySize
operator|>
literal|1
operator|&&
name|secondarySize
operator|>
literal|1
return|;
block|}
name|bool
name|isArray
argument_list|()
specifier|const
block|{
return|return
name|array
operator|?
name|true
operator|:
name|false
return|;
block|}
name|int
name|getArraySize
argument_list|()
specifier|const
block|{
return|return
name|arraySize
return|;
block|}
name|void
name|setArraySize
parameter_list|(
name|int
name|s
parameter_list|)
block|{
name|array
operator|=
name|true
expr_stmt|;
name|arraySize
operator|=
name|s
expr_stmt|;
block|}
name|void
name|clearArrayness
parameter_list|()
block|{
name|array
operator|=
name|false
expr_stmt|;
name|arraySize
operator|=
literal|0
expr_stmt|;
block|}
name|TInterfaceBlock
operator|*
name|getInterfaceBlock
argument_list|()
specifier|const
block|{
return|return
name|interfaceBlock
return|;
block|}
name|void
name|setInterfaceBlock
parameter_list|(
name|TInterfaceBlock
modifier|*
name|interfaceBlockIn
parameter_list|)
block|{
name|interfaceBlock
operator|=
name|interfaceBlockIn
expr_stmt|;
block|}
name|bool
name|isInterfaceBlock
argument_list|()
specifier|const
block|{
return|return
name|type
operator|==
name|EbtInterfaceBlock
return|;
block|}
name|bool
name|isVector
argument_list|()
specifier|const
block|{
return|return
name|primarySize
operator|>
literal|1
operator|&&
name|secondarySize
operator|==
literal|1
return|;
block|}
name|bool
name|isScalar
argument_list|()
specifier|const
block|{
return|return
name|primarySize
operator|==
literal|1
operator|&&
name|secondarySize
operator|==
literal|1
operator|&&
operator|!
name|structure
return|;
block|}
name|bool
name|isScalarInt
argument_list|()
specifier|const
block|{
return|return
name|isScalar
argument_list|()
operator|&&
operator|(
name|type
operator|==
name|EbtInt
operator|||
name|type
operator|==
name|EbtUInt
operator|)
return|;
block|}
name|TStructure
operator|*
name|getStruct
argument_list|()
specifier|const
block|{
return|return
name|structure
return|;
block|}
name|void
name|setStruct
parameter_list|(
name|TStructure
modifier|*
name|s
parameter_list|)
block|{
name|structure
operator|=
name|s
expr_stmt|;
block|}
specifier|const
name|TString
modifier|&
name|getMangledName
parameter_list|()
block|{
if|if
condition|(
name|mangled
operator|.
name|empty
argument_list|()
condition|)
block|{
name|mangled
operator|=
name|buildMangledName
argument_list|()
expr_stmt|;
name|mangled
operator|+=
literal|';'
expr_stmt|;
block|}
return|return
name|mangled
return|;
block|}
name|bool
name|sameElementType
argument_list|(
specifier|const
name|TType
operator|&
name|right
argument_list|)
decl|const
block|{
return|return
name|type
operator|==
name|right
operator|.
name|type
operator|&&
name|primarySize
operator|==
name|right
operator|.
name|primarySize
operator|&&
name|secondarySize
operator|==
name|right
operator|.
name|secondarySize
operator|&&
name|structure
operator|==
name|right
operator|.
name|structure
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|TType
operator|&
name|right
operator|)
specifier|const
block|{
return|return
name|type
operator|==
name|right
operator|.
name|type
operator|&&
name|primarySize
operator|==
name|right
operator|.
name|primarySize
operator|&&
name|secondarySize
operator|==
name|right
operator|.
name|secondarySize
operator|&&
name|array
operator|==
name|right
operator|.
name|array
operator|&&
operator|(
operator|!
name|array
operator|||
name|arraySize
operator|==
name|right
operator|.
name|arraySize
operator|)
operator|&&
name|structure
operator|==
name|right
operator|.
name|structure
return|;
comment|// don't check the qualifier, it's not ever what's being sought after
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|TType
operator|&
name|right
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|right
operator|)
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|TType
operator|&
name|right
operator|)
specifier|const
block|{
if|if
condition|(
name|type
operator|!=
name|right
operator|.
name|type
condition|)
return|return
name|type
operator|<
name|right
operator|.
name|type
return|;
if|if
condition|(
name|primarySize
operator|!=
name|right
operator|.
name|primarySize
condition|)
return|return
name|primarySize
operator|<
name|right
operator|.
name|primarySize
return|;
if|if
condition|(
name|secondarySize
operator|!=
name|right
operator|.
name|secondarySize
condition|)
return|return
name|secondarySize
operator|<
name|right
operator|.
name|secondarySize
return|;
if|if
condition|(
name|array
operator|!=
name|right
operator|.
name|array
condition|)
return|return
name|array
operator|<
name|right
operator|.
name|array
return|;
if|if
condition|(
name|arraySize
operator|!=
name|right
operator|.
name|arraySize
condition|)
return|return
name|arraySize
operator|<
name|right
operator|.
name|arraySize
return|;
if|if
condition|(
name|structure
operator|!=
name|right
operator|.
name|structure
condition|)
return|return
name|structure
operator|<
name|right
operator|.
name|structure
return|;
return|return
name|false
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|const
name|char
operator|*
name|getBasicString
argument_list|()
specifier|const
block|{
return|return
operator|::
name|getBasicString
argument_list|(
name|type
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|const
name|char
operator|*
name|getPrecisionString
argument_list|()
specifier|const
block|{
return|return
operator|::
name|getPrecisionString
argument_list|(
name|precision
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|const
name|char
operator|*
name|getQualifierString
argument_list|()
specifier|const
block|{
return|return
operator|::
name|getQualifierString
argument_list|(
name|qualifier
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|TString
name|getCompleteString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_comment
comment|// If this type is a struct, returns the deepest struct nesting of
end_comment
begin_comment
comment|// any field in the struct. For example:
end_comment
begin_comment
comment|//   struct nesting1 {
end_comment
begin_comment
comment|//     vec4 position;
end_comment
begin_comment
comment|//   };
end_comment
begin_comment
comment|//   struct nesting2 {
end_comment
begin_comment
comment|//     nesting1 field1;
end_comment
begin_comment
comment|//     vec4 field2;
end_comment
begin_comment
comment|//   };
end_comment
begin_comment
comment|// For type "nesting2", this method would return 2 -- the number
end_comment
begin_comment
comment|// of structures through which indirection must occur to reach the
end_comment
begin_comment
comment|// deepest field (nesting2.field1.position).
end_comment
begin_expr_stmt
name|int
name|getDeepestStructNesting
argument_list|()
specifier|const
block|{
return|return
name|structure
operator|?
name|structure
operator|->
name|deepestNesting
argument_list|()
operator|:
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|isStructureContainingArrays
argument_list|()
specifier|const
block|{
return|return
name|structure
operator|?
name|structure
operator|->
name|containsArrays
argument_list|()
operator|:
name|false
return|;
block|}
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_expr_stmt
name|TString
name|buildMangledName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|size_t
name|getStructSize
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|computeDeepestStructNesting
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|TBasicType
name|type
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TPrecision
name|precision
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TQualifier
name|qualifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TLayoutQualifier
name|layoutQualifier
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|unsigned
name|char
name|primarySize
decl_stmt|;
end_decl_stmt
begin_comment
comment|// size of vector or cols matrix
end_comment
begin_decl_stmt
name|unsigned
name|char
name|secondarySize
decl_stmt|;
end_decl_stmt
begin_comment
comment|// rows of a matrix
end_comment
begin_decl_stmt
name|bool
name|array
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|arraySize
decl_stmt|;
end_decl_stmt
begin_comment
comment|// 0 unless this is an interface block, or interface block member variable
end_comment
begin_decl_stmt
name|TInterfaceBlock
modifier|*
name|interfaceBlock
decl_stmt|;
end_decl_stmt
begin_comment
comment|// 0 unless this is a struct
end_comment
begin_decl_stmt
name|TStructure
modifier|*
name|structure
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|TString
name|mangled
decl_stmt|;
end_decl_stmt
begin_comment
unit|};
comment|//
end_comment
begin_comment
comment|// This is a workaround for a problem with the yacc stack,  It can't have
end_comment
begin_comment
comment|// types that it thinks have non-trivial constructors.  It should
end_comment
begin_comment
comment|// just be used while recognizing the grammar, not anything else.  Pointers
end_comment
begin_comment
comment|// could be used, but also trying to avoid lots of memory management overhead.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Not as bad as it looks, there is no actual assumption that the fields
end_comment
begin_comment
comment|// match up or are name the same or anything like that.
end_comment
begin_comment
comment|//
end_comment
begin_struct
DECL|struct|TPublicType
struct|struct
name|TPublicType
block|{
DECL|member|type
name|TBasicType
name|type
decl_stmt|;
DECL|member|layoutQualifier
name|TLayoutQualifier
name|layoutQualifier
decl_stmt|;
DECL|member|qualifier
name|TQualifier
name|qualifier
decl_stmt|;
DECL|member|precision
name|TPrecision
name|precision
decl_stmt|;
DECL|member|primarySize
name|unsigned
name|char
name|primarySize
decl_stmt|;
comment|// size of vector or cols of matrix
DECL|member|secondarySize
name|unsigned
name|char
name|secondarySize
decl_stmt|;
comment|// rows of matrix
DECL|member|array
name|bool
name|array
decl_stmt|;
DECL|member|arraySize
name|int
name|arraySize
decl_stmt|;
DECL|member|userDef
name|TType
modifier|*
name|userDef
decl_stmt|;
DECL|member|line
name|TSourceLoc
name|line
decl_stmt|;
DECL|function|setBasic
name|void
name|setBasic
parameter_list|(
name|TBasicType
name|bt
parameter_list|,
name|TQualifier
name|q
parameter_list|,
specifier|const
name|TSourceLoc
modifier|&
name|ln
parameter_list|)
block|{
name|type
operator|=
name|bt
expr_stmt|;
name|layoutQualifier
operator|=
name|TLayoutQualifier
operator|::
name|create
argument_list|()
expr_stmt|;
name|qualifier
operator|=
name|q
expr_stmt|;
name|precision
operator|=
name|EbpUndefined
expr_stmt|;
name|primarySize
operator|=
literal|1
expr_stmt|;
name|secondarySize
operator|=
literal|1
expr_stmt|;
name|array
operator|=
name|false
expr_stmt|;
name|arraySize
operator|=
literal|0
expr_stmt|;
name|userDef
operator|=
literal|0
expr_stmt|;
name|line
operator|=
name|ln
expr_stmt|;
block|}
DECL|function|setAggregate
name|void
name|setAggregate
parameter_list|(
name|unsigned
name|char
name|size
parameter_list|)
block|{
name|primarySize
operator|=
name|size
expr_stmt|;
block|}
DECL|function|setMatrix
name|void
name|setMatrix
parameter_list|(
name|unsigned
name|char
name|c
parameter_list|,
name|unsigned
name|char
name|r
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|c
operator|>
literal|1
operator|&&
name|r
operator|>
literal|1
operator|&&
name|c
operator|<=
literal|4
operator|&&
name|r
operator|<=
literal|4
argument_list|)
expr_stmt|;
name|primarySize
operator|=
name|c
expr_stmt|;
name|secondarySize
operator|=
name|r
expr_stmt|;
block|}
DECL|function|setArray
name|void
name|setArray
parameter_list|(
name|bool
name|a
parameter_list|,
name|int
name|s
init|=
literal|0
parameter_list|)
block|{
name|array
operator|=
name|a
expr_stmt|;
name|arraySize
operator|=
name|s
expr_stmt|;
block|}
DECL|function|isStructureContainingArrays
name|bool
name|isStructureContainingArrays
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|userDef
condition|)
block|{
return|return
name|false
return|;
block|}
return|return
name|userDef
operator|->
name|isStructureContainingArrays
argument_list|()
return|;
block|}
DECL|function|isMatrix
name|bool
name|isMatrix
argument_list|()
decl|const
block|{
return|return
name|primarySize
operator|>
literal|1
operator|&&
name|secondarySize
operator|>
literal|1
return|;
block|}
DECL|function|isVector
name|bool
name|isVector
argument_list|()
decl|const
block|{
return|return
name|primarySize
operator|>
literal|1
operator|&&
name|secondarySize
operator|==
literal|1
return|;
block|}
DECL|function|getCols
name|int
name|getCols
argument_list|()
decl|const
block|{
name|ASSERT
argument_list|(
name|isMatrix
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|primarySize
return|;
block|}
DECL|function|getRows
name|int
name|getRows
argument_list|()
decl|const
block|{
name|ASSERT
argument_list|(
name|isMatrix
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|secondarySize
return|;
block|}
DECL|function|getNominalSize
name|int
name|getNominalSize
argument_list|()
decl|const
block|{
return|return
name|primarySize
return|;
block|}
DECL|function|isAggregate
name|bool
name|isAggregate
argument_list|()
decl|const
block|{
return|return
name|array
operator|||
name|isMatrix
argument_list|()
operator|||
name|isVector
argument_list|()
return|;
block|}
end_struct
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// _TYPES_INCLUDED_
end_comment
end_unit
