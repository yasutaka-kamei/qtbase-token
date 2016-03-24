begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_TRANSLATOR_SYMBOLTABLE_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_SYMBOLTABLE_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_SYMBOLTABLE_H_
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|// Symbol table for parsing.  Has these design characteristics:
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// * Same symbol table can be used to compile many shaders, to preserve
end_comment
begin_comment
comment|//   effort of creating and loading with the large numbers of built-in
end_comment
begin_comment
comment|//   symbols.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// * Name mangling will be used to give each function a unique name
end_comment
begin_comment
comment|//   so that symbol table lookups are never ambiguous.  This allows
end_comment
begin_comment
comment|//   a simpler symbol table structure.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// * Pushing and popping of scope, so symbol table will really be a stack
end_comment
begin_comment
comment|//   of symbol tables.  Searched from the top, with new inserts going into
end_comment
begin_comment
comment|//   the top.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// * Constants:  Compile time constant symbols will keep their values
end_comment
begin_comment
comment|//   in the symbol table.  The parser can substitute constants at parse
end_comment
begin_comment
comment|//   time, including doing constant folding and constant propagation.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// * No temporaries:  Temporaries made from operations (+, --, .xy, etc.)
end_comment
begin_comment
comment|//   are tracked in the intermediate representation, not the symbol table.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<assert.h>
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_include
include|#
directive|include
file|"common/angleutils.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/InfoSink.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_comment
comment|// Symbol base class. (Can build functions or variables out of these...)
end_comment
begin_decl_stmt
name|class
name|TSymbol
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|()
block|;
name|TSymbol
argument_list|(
specifier|const
name|TString
operator|*
name|n
argument_list|)
operator|:
name|uniqueId
argument_list|(
literal|0
argument_list|)
block|,
name|name
argument_list|(
argument|n
argument_list|)
block|{     }
name|virtual
operator|~
name|TSymbol
argument_list|()
block|{
comment|// don't delete name, it's from the pool
block|}
specifier|const
name|TString
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
operator|*
name|name
return|;
block|}
name|virtual
specifier|const
name|TString
operator|&
name|getMangledName
argument_list|()
specifier|const
block|{
return|return
name|getName
argument_list|()
return|;
block|}
name|virtual
name|bool
name|isFunction
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isVariable
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|void
name|setUniqueId
argument_list|(
argument|int id
argument_list|)
block|{
name|uniqueId
operator|=
name|id
block|;     }
name|int
name|getUniqueId
argument_list|()
specifier|const
block|{
return|return
name|uniqueId
return|;
block|}
name|void
name|relateToExtension
argument_list|(
argument|const TString&ext
argument_list|)
block|{
name|extension
operator|=
name|ext
block|;     }
specifier|const
name|TString
operator|&
name|getExtension
argument_list|()
specifier|const
block|{
return|return
name|extension
return|;
block|}
name|private
operator|:
name|int
name|uniqueId
block|;
comment|// For real comparing during code generation
specifier|const
name|TString
operator|*
name|name
block|;
name|TString
name|extension
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Variable class, meaning a symbol that's not a function.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// There could be a separate class heirarchy for Constant variables;
end_comment
begin_comment
comment|// Only one of int, bool, or float, (or none) is correct for
end_comment
begin_comment
comment|// any particular use, but it's easy to do this way, and doesn't
end_comment
begin_comment
comment|// seem worth having separate classes, and "getConst" can't simply return
end_comment
begin_comment
comment|// different values for different types polymorphically, so this is
end_comment
begin_comment
comment|// just simple and pragmatic.
end_comment
begin_decl_stmt
name|class
name|TVariable
range|:
name|public
name|TSymbol
block|{
name|public
operator|:
name|TVariable
argument_list|(
argument|const TString *name
argument_list|,
argument|const TType&t
argument_list|,
argument|bool uT = false
argument_list|)
operator|:
name|TSymbol
argument_list|(
name|name
argument_list|)
block|,
name|type
argument_list|(
name|t
argument_list|)
block|,
name|userType
argument_list|(
name|uT
argument_list|)
block|,
name|unionArray
argument_list|(
literal|0
argument_list|)
block|{     }
operator|~
name|TVariable
argument_list|()
name|override
block|{}
name|bool
name|isVariable
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|TType
operator|&
name|getType
argument_list|()
block|{
return|return
name|type
return|;
block|}
specifier|const
name|TType
operator|&
name|getType
argument_list|()
specifier|const
block|{
return|return
name|type
return|;
block|}
name|bool
name|isUserType
argument_list|()
specifier|const
block|{
return|return
name|userType
return|;
block|}
name|void
name|setQualifier
argument_list|(
argument|TQualifier qualifier
argument_list|)
block|{
name|type
operator|.
name|setQualifier
argument_list|(
name|qualifier
argument_list|)
block|;     }
specifier|const
name|TConstantUnion
operator|*
name|getConstPointer
argument_list|()
specifier|const
block|{
return|return
name|unionArray
return|;
block|}
name|void
name|shareConstPointer
argument_list|(
argument|const TConstantUnion *constArray
argument_list|)
block|{
name|unionArray
operator|=
name|constArray
block|; }
name|private
operator|:
name|TType
name|type
block|;
name|bool
name|userType
block|;
comment|// we are assuming that Pool Allocator will free the memory
comment|// allocated to unionArray when this object is destroyed.
specifier|const
name|TConstantUnion
operator|*
name|unionArray
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Immutable version of TParameter.
end_comment
begin_struct
DECL|struct|TConstParameter
struct|struct
name|TConstParameter
block|{
DECL|function|TConstParameter
name|TConstParameter
argument_list|()
operator|:
name|name
argument_list|(
name|nullptr
argument_list|)
operator|,
name|type
argument_list|(
argument|nullptr
argument_list|)
block|{     }
DECL|function|TConstParameter
name|explicit
name|TConstParameter
argument_list|(
specifier|const
name|TString
operator|*
name|n
argument_list|)
operator|:
name|name
argument_list|(
name|n
argument_list|)
operator|,
name|type
argument_list|(
argument|nullptr
argument_list|)
block|{     }
DECL|function|TConstParameter
name|explicit
name|TConstParameter
argument_list|(
specifier|const
name|TType
operator|*
name|t
argument_list|)
operator|:
name|name
argument_list|(
name|nullptr
argument_list|)
operator|,
name|type
argument_list|(
argument|t
argument_list|)
block|{     }
DECL|function|TConstParameter
name|TConstParameter
argument_list|(
specifier|const
name|TString
operator|*
name|n
argument_list|,
specifier|const
name|TType
operator|*
name|t
argument_list|)
operator|:
name|name
argument_list|(
name|n
argument_list|)
operator|,
name|type
argument_list|(
argument|t
argument_list|)
block|{     }
comment|// Both constructor arguments must be const.
name|TConstParameter
argument_list|(
name|TString
operator|*
name|n
argument_list|,
name|TType
operator|*
name|t
argument_list|)
operator|=
name|delete
expr_stmt|;
name|TConstParameter
argument_list|(
specifier|const
name|TString
operator|*
name|n
argument_list|,
name|TType
operator|*
name|t
argument_list|)
operator|=
name|delete
expr_stmt|;
name|TConstParameter
argument_list|(
name|TString
operator|*
name|n
argument_list|,
specifier|const
name|TType
operator|*
name|t
argument_list|)
operator|=
name|delete
expr_stmt|;
DECL|member|name
specifier|const
name|TString
modifier|*
name|name
decl_stmt|;
DECL|member|type
specifier|const
name|TType
modifier|*
name|type
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|// The function sub-class of symbols and the parser will need to
end_comment
begin_comment
comment|// share this definition of a function parameter.
end_comment
begin_struct
DECL|struct|TParameter
struct|struct
name|TParameter
block|{
comment|// Destructively converts to TConstParameter.
comment|// This method resets name and type to nullptrs to make sure
comment|// their content cannot be modified after the call.
DECL|function|turnToConst
name|TConstParameter
name|turnToConst
parameter_list|()
block|{
specifier|const
name|TString
modifier|*
name|constName
init|=
name|name
decl_stmt|;
specifier|const
name|TType
modifier|*
name|constType
init|=
name|type
decl_stmt|;
name|name
operator|=
name|nullptr
expr_stmt|;
name|type
operator|=
name|nullptr
expr_stmt|;
return|return
name|TConstParameter
argument_list|(
name|constName
argument_list|,
name|constType
argument_list|)
return|;
block|}
DECL|member|name
name|TString
modifier|*
name|name
decl_stmt|;
DECL|member|type
name|TType
modifier|*
name|type
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|// The function sub-class of a symbol.
end_comment
begin_decl_stmt
name|class
name|TFunction
range|:
name|public
name|TSymbol
block|{
name|public
operator|:
name|TFunction
argument_list|(
argument|const TString *name
argument_list|,
argument|const TType *retType
argument_list|,
argument|TOperator tOp   = EOpNull
argument_list|,
argument|const char *ext =
literal|""
argument_list|)
operator|:
name|TSymbol
argument_list|(
name|name
argument_list|)
block|,
name|returnType
argument_list|(
name|retType
argument_list|)
block|,
name|mangledName
argument_list|(
name|nullptr
argument_list|)
block|,
name|op
argument_list|(
name|tOp
argument_list|)
block|,
name|defined
argument_list|(
name|false
argument_list|)
block|,
name|mHasPrototypeDeclaration
argument_list|(
argument|false
argument_list|)
block|{
name|relateToExtension
argument_list|(
name|ext
argument_list|)
block|;     }
operator|~
name|TFunction
argument_list|()
name|override
block|;
name|bool
name|isFunction
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
specifier|static
name|TString
name|mangleName
argument_list|(
argument|const TString&name
argument_list|)
block|{
return|return
name|name
operator|+
literal|'('
return|;
block|}
specifier|static
name|TString
name|unmangleName
argument_list|(
argument|const TString&mangledName
argument_list|)
block|{
return|return
name|TString
argument_list|(
name|mangledName
operator|.
name|c_str
argument_list|()
argument_list|,
name|mangledName
operator|.
name|find_first_of
argument_list|(
literal|'('
argument_list|)
argument_list|)
return|;
block|}
name|void
name|addParameter
argument_list|(
argument|const TConstParameter&p
argument_list|)
block|{
name|parameters
operator|.
name|push_back
argument_list|(
name|p
argument_list|)
block|;
name|mangledName
operator|=
name|nullptr
block|;     }
specifier|const
name|TString
operator|&
name|getMangledName
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|mangledName
operator|==
name|nullptr
condition|)
block|{
name|mangledName
operator|=
name|buildMangledName
argument_list|()
expr_stmt|;
block|}
return|return
operator|*
name|mangledName
return|;
block|}
specifier|const
name|TType
operator|&
name|getReturnType
argument_list|()
specifier|const
block|{
return|return
operator|*
name|returnType
return|;
block|}
name|TOperator
name|getBuiltInOp
argument_list|()
specifier|const
block|{
return|return
name|op
return|;
block|}
name|void
name|setDefined
argument_list|()
block|{
name|defined
operator|=
name|true
block|; }
name|bool
name|isDefined
argument_list|()
block|{
return|return
name|defined
return|;
block|}
name|void
name|setHasPrototypeDeclaration
argument_list|()
block|{
name|mHasPrototypeDeclaration
operator|=
name|true
block|; }
name|bool
name|hasPrototypeDeclaration
argument_list|()
specifier|const
block|{
return|return
name|mHasPrototypeDeclaration
return|;
block|}
name|size_t
name|getParamCount
argument_list|()
specifier|const
block|{
return|return
name|parameters
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|TConstParameter
operator|&
name|getParam
argument_list|(
argument|size_t i
argument_list|)
specifier|const
block|{
return|return
name|parameters
index|[
name|i
index|]
return|;
block|}
name|private
operator|:
specifier|const
name|TString
operator|*
name|buildMangledName
argument_list|()
specifier|const
block|;
typedef|typedef
name|TVector
operator|<
name|TConstParameter
operator|>
name|TParamList
expr_stmt|;
name|TParamList
name|parameters
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|TType
modifier|*
name|returnType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
specifier|const
name|TString
modifier|*
name|mangledName
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|TOperator
name|op
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|defined
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|mHasPrototypeDeclaration
decl_stmt|;
end_decl_stmt
begin_comment
unit|};
comment|// Interface block name sub-symbol
end_comment
begin_decl_stmt
name|class
name|TInterfaceBlockName
range|:
name|public
name|TSymbol
block|{
name|public
operator|:
name|TInterfaceBlockName
argument_list|(
specifier|const
name|TString
operator|*
name|name
argument_list|)
operator|:
name|TSymbol
argument_list|(
argument|name
argument_list|)
block|{     }
name|virtual
operator|~
name|TInterfaceBlockName
argument_list|()
block|{     }
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|TSymbolTableLevel
block|{
name|public
label|:
typedef|typedef
name|TMap
operator|<
name|TString
operator|,
name|TSymbol
operator|*
operator|>
name|tLevel
expr_stmt|;
typedef|typedef
name|tLevel
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
specifier|const
name|tLevel
operator|::
name|value_type
name|tLevelPair
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|tLevel
operator|::
name|iterator
operator|,
name|bool
operator|>
name|tInsertResult
expr_stmt|;
name|TSymbolTableLevel
argument_list|()
block|{     }
operator|~
name|TSymbolTableLevel
argument_list|()
expr_stmt|;
name|bool
name|insert
parameter_list|(
name|TSymbol
modifier|*
name|symbol
parameter_list|)
function_decl|;
comment|// Insert a function using its unmangled name as the key.
name|bool
name|insertUnmangled
parameter_list|(
name|TFunction
modifier|*
name|function
parameter_list|)
function_decl|;
name|TSymbol
modifier|*
name|find
argument_list|(
specifier|const
name|TString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|tLevel
name|level
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// Define ESymbolLevel as int rather than an enum since level can go
end_comment
begin_comment
comment|// above GLOBAL_LEVEL and cause atBuiltInLevel() to fail if the
end_comment
begin_comment
comment|// compiler optimizes the>= of the last element to ==.
end_comment
begin_typedef
DECL|typedef|ESymbolLevel
typedef|typedef
name|int
name|ESymbolLevel
typedef|;
end_typedef
begin_decl_stmt
DECL|variable|COMMON_BUILTINS
specifier|const
name|int
name|COMMON_BUILTINS
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ESSL1_BUILTINS
specifier|const
name|int
name|ESSL1_BUILTINS
init|=
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ESSL3_BUILTINS
specifier|const
name|int
name|ESSL3_BUILTINS
init|=
literal|2
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|LAST_BUILTIN_LEVEL
specifier|const
name|int
name|LAST_BUILTIN_LEVEL
init|=
name|ESSL3_BUILTINS
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|GLOBAL_LEVEL
specifier|const
name|int
name|GLOBAL_LEVEL
init|=
literal|3
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|TSymbolTable
range|:
name|angle
operator|::
name|NonCopyable
block|{
name|public
operator|:
name|TSymbolTable
argument_list|()
operator|:
name|mGlobalInvariant
argument_list|(
argument|false
argument_list|)
block|{
comment|// The symbol table cannot be used until push() is called, but
comment|// the lack of an initial call to push() can be used to detect
comment|// that the symbol table has not been preloaded with built-ins.
block|}
operator|~
name|TSymbolTable
argument_list|()
block|;
comment|// When the symbol table is initialized with the built-ins, there should
comment|// 'push' calls, so that built-ins are at level 0 and the shader
comment|// globals are at level 1.
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|table
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|atBuiltInLevel
argument_list|()
specifier|const
block|{
return|return
name|currentLevel
argument_list|()
operator|<=
name|LAST_BUILTIN_LEVEL
return|;
block|}
name|bool
name|atGlobalLevel
argument_list|()
specifier|const
block|{
return|return
name|currentLevel
argument_list|()
operator|<=
name|GLOBAL_LEVEL
return|;
block|}
name|void
name|push
argument_list|()
block|{
name|table
operator|.
name|push_back
argument_list|(
argument|new TSymbolTableLevel
argument_list|)
block|;
name|precisionStack
operator|.
name|push_back
argument_list|(
argument|new PrecisionStackLevel
argument_list|)
block|;     }
name|void
name|pop
argument_list|()
block|{
name|delete
name|table
operator|.
name|back
argument_list|()
block|;
name|table
operator|.
name|pop_back
argument_list|()
block|;
name|delete
name|precisionStack
operator|.
name|back
argument_list|()
block|;
name|precisionStack
operator|.
name|pop_back
argument_list|()
block|;     }
name|bool
name|declare
argument_list|(
argument|TSymbol *symbol
argument_list|)
block|{
return|return
name|insert
argument_list|(
name|currentLevel
argument_list|()
argument_list|,
name|symbol
argument_list|)
return|;
block|}
name|bool
name|insert
argument_list|(
argument|ESymbolLevel level
argument_list|,
argument|TSymbol *symbol
argument_list|)
block|{
return|return
name|table
index|[
name|level
index|]
operator|->
name|insert
argument_list|(
name|symbol
argument_list|)
return|;
block|}
name|bool
name|insert
argument_list|(
argument|ESymbolLevel level
argument_list|,
argument|const char *ext
argument_list|,
argument|TSymbol *symbol
argument_list|)
block|{
name|symbol
operator|->
name|relateToExtension
argument_list|(
name|ext
argument_list|)
block|;
return|return
name|table
index|[
name|level
index|]
operator|->
name|insert
argument_list|(
name|symbol
argument_list|)
return|;
block|}
name|bool
name|insertConstInt
argument_list|(
argument|ESymbolLevel level
argument_list|,
argument|const char *name
argument_list|,
argument|int value
argument_list|)
block|{
name|TVariable
operator|*
name|constant
operator|=
name|new
name|TVariable
argument_list|(
name|NewPoolTString
argument_list|(
name|name
argument_list|)
argument_list|,
name|TType
argument_list|(
name|EbtInt
argument_list|,
name|EbpUndefined
argument_list|,
name|EvqConst
argument_list|,
literal|1
argument_list|)
argument_list|)
block|;
name|TConstantUnion
operator|*
name|unionArray
operator|=
name|new
name|TConstantUnion
index|[
literal|1
index|]
block|;
name|unionArray
index|[
literal|0
index|]
operator|.
name|setIConst
argument_list|(
name|value
argument_list|)
block|;
name|constant
operator|->
name|shareConstPointer
argument_list|(
name|unionArray
argument_list|)
block|;
return|return
name|insert
argument_list|(
name|level
argument_list|,
name|constant
argument_list|)
return|;
block|}
name|bool
name|insertConstIntExt
argument_list|(
argument|ESymbolLevel level
argument_list|,
argument|const char *ext
argument_list|,
argument|const char *name
argument_list|,
argument|int value
argument_list|)
block|{
name|TVariable
operator|*
name|constant
operator|=
name|new
name|TVariable
argument_list|(
name|NewPoolTString
argument_list|(
name|name
argument_list|)
argument_list|,
name|TType
argument_list|(
name|EbtInt
argument_list|,
name|EbpUndefined
argument_list|,
name|EvqConst
argument_list|,
literal|1
argument_list|)
argument_list|)
block|;
name|TConstantUnion
operator|*
name|unionArray
operator|=
name|new
name|TConstantUnion
index|[
literal|1
index|]
block|;
name|unionArray
index|[
literal|0
index|]
operator|.
name|setIConst
argument_list|(
name|value
argument_list|)
block|;
name|constant
operator|->
name|shareConstPointer
argument_list|(
name|unionArray
argument_list|)
block|;
return|return
name|insert
argument_list|(
name|level
argument_list|,
name|ext
argument_list|,
name|constant
argument_list|)
return|;
block|}
name|void
name|insertBuiltIn
argument_list|(
argument|ESymbolLevel level
argument_list|,
argument|TOperator op
argument_list|,
argument|const char *ext
argument_list|,
argument|const TType *rvalue
argument_list|,
argument|const char *name
argument_list|,
argument|const TType *ptype1
argument_list|,
argument|const TType *ptype2 =
literal|0
argument_list|,
argument|const TType *ptype3 =
literal|0
argument_list|,
argument|const TType *ptype4 =
literal|0
argument_list|,
argument|const TType *ptype5 =
literal|0
argument_list|)
block|;
name|void
name|insertBuiltIn
argument_list|(
argument|ESymbolLevel level
argument_list|,
argument|const TType *rvalue
argument_list|,
argument|const char *name
argument_list|,
argument|const TType *ptype1
argument_list|,
argument|const TType *ptype2 =
literal|0
argument_list|,
argument|const TType *ptype3 =
literal|0
argument_list|,
argument|const TType *ptype4 =
literal|0
argument_list|,
argument|const TType *ptype5 =
literal|0
argument_list|)
block|{
name|insertBuiltIn
argument_list|(
name|level
argument_list|,
name|EOpNull
argument_list|,
literal|""
argument_list|,
name|rvalue
argument_list|,
name|name
argument_list|,
name|ptype1
argument_list|,
name|ptype2
argument_list|,
name|ptype3
argument_list|,
name|ptype4
argument_list|,
name|ptype5
argument_list|)
block|;     }
name|void
name|insertBuiltIn
argument_list|(
argument|ESymbolLevel level
argument_list|,
argument|const char *ext
argument_list|,
argument|const TType *rvalue
argument_list|,
argument|const char *name
argument_list|,
argument|const TType *ptype1
argument_list|,
argument|const TType *ptype2 =
literal|0
argument_list|,
argument|const TType *ptype3 =
literal|0
argument_list|,
argument|const TType *ptype4 =
literal|0
argument_list|,
argument|const TType *ptype5 =
literal|0
argument_list|)
block|{
name|insertBuiltIn
argument_list|(
name|level
argument_list|,
name|EOpNull
argument_list|,
name|ext
argument_list|,
name|rvalue
argument_list|,
name|name
argument_list|,
name|ptype1
argument_list|,
name|ptype2
argument_list|,
name|ptype3
argument_list|,
name|ptype4
argument_list|,
name|ptype5
argument_list|)
block|;     }
name|void
name|insertBuiltIn
argument_list|(
argument|ESymbolLevel level
argument_list|,
argument|TOperator op
argument_list|,
argument|const TType *rvalue
argument_list|,
argument|const char *name
argument_list|,
argument|const TType *ptype1
argument_list|,
argument|const TType *ptype2 =
literal|0
argument_list|,
argument|const TType *ptype3 =
literal|0
argument_list|,
argument|const TType *ptype4 =
literal|0
argument_list|,
argument|const TType *ptype5 =
literal|0
argument_list|)
block|{
name|insertBuiltIn
argument_list|(
name|level
argument_list|,
name|op
argument_list|,
literal|""
argument_list|,
name|rvalue
argument_list|,
name|name
argument_list|,
name|ptype1
argument_list|,
name|ptype2
argument_list|,
name|ptype3
argument_list|,
name|ptype4
argument_list|,
name|ptype5
argument_list|)
block|;     }
name|TSymbol
operator|*
name|find
argument_list|(
argument|const TString&name
argument_list|,
argument|int shaderVersion
argument_list|,
argument|bool *builtIn = NULL
argument_list|,
argument|bool *sameScope = NULL
argument_list|)
specifier|const
block|;
name|TSymbol
operator|*
name|findBuiltIn
argument_list|(
argument|const TString&name
argument_list|,
argument|int shaderVersion
argument_list|)
specifier|const
block|;
name|TSymbolTableLevel
operator|*
name|getOuterLevel
argument_list|()
block|{
name|assert
argument_list|(
name|currentLevel
argument_list|()
operator|>=
literal|1
argument_list|)
block|;
return|return
name|table
index|[
name|currentLevel
argument_list|()
operator|-
literal|1
index|]
return|;
block|}
name|void
name|dump
argument_list|(
argument|TInfoSink&infoSink
argument_list|)
specifier|const
block|;
name|bool
name|setDefaultPrecision
argument_list|(
argument|const TPublicType&type
argument_list|,
argument|TPrecision prec
argument_list|)
block|{
if|if
condition|(
operator|!
name|SupportsPrecision
argument_list|(
name|type
operator|.
name|type
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
name|type
operator|.
name|type
operator|==
name|EbtUInt
condition|)
return|return
name|false
return|;
end_decl_stmt
begin_comment
comment|// ESSL 3.00.4 section 4.5.4
end_comment
begin_if
if|if
condition|(
name|type
operator|.
name|isAggregate
argument_list|()
condition|)
return|return
name|false
return|;
end_if
begin_comment
comment|// Not allowed to set for aggregate types
end_comment
begin_decl_stmt
name|int
name|indexOfLastElement
init|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|precisionStack
operator|.
name|size
argument_list|()
operator|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Uses map operator [], overwrites the current value
end_comment
begin_expr_stmt
operator|(
operator|*
name|precisionStack
index|[
name|indexOfLastElement
index|]
operator|)
index|[
name|type
operator|.
name|type
index|]
operator|=
name|prec
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|true
return|;
end_return
begin_comment
unit|}
comment|// Searches down the precisionStack for a precision qualifier
end_comment
begin_comment
comment|// for the specified TBasicType
end_comment
begin_macro
unit|TPrecision
name|getDefaultPrecision
argument_list|(
argument|TBasicType type
argument_list|)
end_macro
begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt
begin_comment
comment|// This records invariant varyings declared through
end_comment
begin_comment
comment|// "invariant varying_name;".
end_comment
begin_decl_stmt
name|void
name|addInvariantVarying
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|originalName
argument_list|)
block|{
name|mInvariantVaryings
operator|.
name|insert
argument_list|(
name|originalName
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// If this returns false, the varying could still be invariant
end_comment
begin_comment
comment|// if it is set as invariant during the varying variable
end_comment
begin_comment
comment|// declaration - this piece of information is stored in the
end_comment
begin_comment
comment|// variable's type, not here.
end_comment
begin_decl_stmt
name|bool
name|isVaryingInvariant
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|originalName
argument_list|)
decl|const
block|{
return|return
operator|(
name|mGlobalInvariant
operator|||
name|mInvariantVaryings
operator|.
name|count
argument_list|(
name|originalName
argument_list|)
operator|>
literal|0
operator|)
return|;
block|}
end_decl_stmt
begin_function
name|void
name|setGlobalInvariant
parameter_list|()
block|{
name|mGlobalInvariant
operator|=
name|true
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|getGlobalInvariant
argument_list|()
specifier|const
block|{
return|return
name|mGlobalInvariant
return|;
block|}
end_expr_stmt
begin_function
specifier|static
name|int
name|nextUniqueId
parameter_list|()
block|{
return|return
operator|++
name|uniqueIdCounter
return|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_expr_stmt
name|ESymbolLevel
name|currentLevel
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ESymbolLevel
operator|>
operator|(
name|table
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|TSymbolTableLevel
operator|*
operator|>
name|table
expr_stmt|;
end_expr_stmt
begin_typedef
typedef|typedef
name|TMap
operator|<
name|TBasicType
operator|,
name|TPrecision
operator|>
name|PrecisionStackLevel
expr_stmt|;
end_typedef
begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|PrecisionStackLevel
operator|*
operator|>
name|precisionStack
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>
name|mInvariantVaryings
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|mGlobalInvariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|int
name|uniqueIdCounter
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_SYMBOLTABLE_H_
end_comment
end_unit
