begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
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
comment|// CompilerD3D.h: Defines the rx::CompilerD3D class, an implementation of rx::CompilerImpl.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_COMPILERD3D_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_COMPILERD3D_H_
define|#
directive|define
name|LIBANGLE_RENDERER_COMPILERD3D_H_
end_define
begin_include
include|#
directive|include
file|"libANGLE/renderer/CompilerImpl.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/RendererD3D.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|CompilerD3D
range|:
name|public
name|CompilerImpl
block|{
name|public
operator|:
name|CompilerD3D
argument_list|(
argument|ShShaderOutput translatorOutputType
argument_list|)
block|;
operator|~
name|CompilerD3D
argument_list|()
name|override
block|{}
name|gl
operator|::
name|Error
name|release
argument_list|()
name|override
block|{
return|return
name|gl
operator|::
name|Error
argument_list|(
name|GL_NO_ERROR
argument_list|)
return|;
block|}
name|ShShaderOutput
name|getTranslatorOutputType
argument_list|()
specifier|const
name|override
block|{
return|return
name|mTranslatorOutputType
return|;
block|}
name|private
operator|:
name|ShShaderOutput
name|mTranslatorOutputType
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_COMPILERD3D_H_
end_comment
end_unit
