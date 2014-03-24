begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
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
name|COMPILER_MAP_LONG_VARIABLE_NAMES_H_
end_ifndef
begin_define
DECL|macro|COMPILER_MAP_LONG_VARIABLE_NAMES_H_
define|#
directive|define
name|COMPILER_MAP_LONG_VARIABLE_NAMES_H_
end_define
begin_include
include|#
directive|include
file|"GLSLANG/ShaderLang.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/intermediate.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/VariableInfo.h"
end_include
begin_comment
comment|// This size does not include '\0' in the end.
end_comment
begin_define
DECL|macro|MAX_SHORTENED_IDENTIFIER_SIZE
define|#
directive|define
name|MAX_SHORTENED_IDENTIFIER_SIZE
value|32
end_define
begin_comment
comment|// This is a ref-counted singleton. GetInstance() returns a pointer to the
end_comment
begin_comment
comment|// singleton, and after use, call Release(). GetInstance() and Release() should
end_comment
begin_comment
comment|// be paired.
end_comment
begin_decl_stmt
name|class
name|LongNameMap
block|{
name|public
label|:
specifier|static
name|LongNameMap
modifier|*
name|GetInstance
parameter_list|()
function_decl|;
name|void
name|Release
parameter_list|()
function_decl|;
comment|// Return the mapped name if<originalName, mappedName> is in the map;
comment|// otherwise, return NULL.
specifier|const
name|char
modifier|*
name|Find
argument_list|(
specifier|const
name|char
operator|*
name|originalName
argument_list|)
decl|const
decl_stmt|;
comment|// Insert a pair into the map.
name|void
name|Insert
parameter_list|(
specifier|const
name|char
modifier|*
name|originalName
parameter_list|,
specifier|const
name|char
modifier|*
name|mappedName
parameter_list|)
function_decl|;
comment|// Return the number of entries in the map.
name|size_t
name|Size
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|LongNameMap
argument_list|()
expr_stmt|;
operator|~
name|LongNameMap
argument_list|()
expr_stmt|;
name|size_t
name|refCount
decl_stmt|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|string
operator|>
name|mLongNameMap
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// Traverses intermediate tree to map attributes and uniforms names that are
end_comment
begin_comment
comment|// longer than MAX_SHORTENED_IDENTIFIER_SIZE to MAX_SHORTENED_IDENTIFIER_SIZE.
end_comment
begin_decl_stmt
name|class
name|MapLongVariableNames
range|:
name|public
name|TIntermTraverser
block|{
name|public
operator|:
name|MapLongVariableNames
argument_list|(
name|LongNameMap
operator|*
name|globalMap
argument_list|)
block|;
name|virtual
name|void
name|visitSymbol
argument_list|(
name|TIntermSymbol
operator|*
argument_list|)
block|;
name|private
operator|:
name|TString
name|mapGlobalLongName
argument_list|(
specifier|const
name|TString
operator|&
name|name
argument_list|)
block|;
name|LongNameMap
operator|*
name|mGlobalMap
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_MAP_LONG_VARIABLE_NAMES_H_
end_comment
end_unit