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
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_DIRECTIVE_HANDLER_H_
end_ifndef
begin_define
DECL|macro|COMPILER_DIRECTIVE_HANDLER_H_
define|#
directive|define
name|COMPILER_DIRECTIVE_HANDLER_H_
end_define
begin_include
include|#
directive|include
file|"compiler/translator/ExtensionBehavior.h"
end_include
begin_include
include|#
directive|include
file|"compiler/translator/Pragma.h"
end_include
begin_include
include|#
directive|include
file|"compiler/preprocessor/DirectiveHandlerBase.h"
end_include
begin_decl_stmt
DECL|variable|TDiagnostics
name|class
name|TDiagnostics
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|TDirectiveHandler
range|:
name|public
name|pp
operator|::
name|DirectiveHandler
block|{
name|public
operator|:
name|TDirectiveHandler
argument_list|(
name|TExtensionBehavior
operator|&
name|extBehavior
argument_list|,
name|TDiagnostics
operator|&
name|diagnostics
argument_list|)
block|;
name|virtual
operator|~
name|TDirectiveHandler
argument_list|()
block|;
specifier|const
name|TPragma
operator|&
name|pragma
argument_list|()
specifier|const
block|{
return|return
name|mPragma
return|;
block|}
specifier|const
name|TExtensionBehavior
operator|&
name|extensionBehavior
argument_list|()
specifier|const
block|{
return|return
name|mExtensionBehavior
return|;
block|}
name|virtual
name|void
name|handleError
argument_list|(
specifier|const
name|pp
operator|::
name|SourceLocation
operator|&
name|loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|msg
argument_list|)
block|;
name|virtual
name|void
name|handlePragma
argument_list|(
specifier|const
name|pp
operator|::
name|SourceLocation
operator|&
name|loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|value
argument_list|)
block|;
name|virtual
name|void
name|handleExtension
argument_list|(
specifier|const
name|pp
operator|::
name|SourceLocation
operator|&
name|loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|behavior
argument_list|)
block|;
name|virtual
name|void
name|handleVersion
argument_list|(
argument|const pp::SourceLocation& loc
argument_list|,
argument|int version
argument_list|)
block|;
name|private
operator|:
name|TPragma
name|mPragma
block|;
name|TExtensionBehavior
operator|&
name|mExtensionBehavior
block|;
name|TDiagnostics
operator|&
name|mDiagnostics
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_DIRECTIVE_HANDLER_H_
end_comment
end_unit