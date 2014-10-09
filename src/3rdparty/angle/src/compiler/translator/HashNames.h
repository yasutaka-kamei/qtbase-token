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
name|COMPILER_HASH_NAMES_H_
end_ifndef
begin_define
DECL|macro|COMPILER_HASH_NAMES_H_
define|#
directive|define
name|COMPILER_HASH_NAMES_H_
end_define
begin_include
include|#
directive|include
file|<map>
end_include
begin_include
include|#
directive|include
file|"compiler/translator/IntermNode.h"
end_include
begin_define
DECL|macro|HASHED_NAME_PREFIX
define|#
directive|define
name|HASHED_NAME_PREFIX
value|"webgl_"
end_define
begin_typedef
DECL|typedef|TPersistString
DECL|typedef|NameMap
typedef|typedef
name|std
operator|::
name|map
operator|<
name|TPersistString
operator|,
name|TPersistString
operator|>
name|NameMap
expr_stmt|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_HASH_NAMES_H_
end_comment
end_unit
