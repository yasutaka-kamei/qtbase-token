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
comment|// ImageImpl_mock.h: Defines a mock of the ImageImpl class.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_RENDERER_IMAGEIMPLMOCK_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_RENDERER_IMAGEIMPLMOCK_H_
define|#
directive|define
name|LIBANGLE_RENDERER_IMAGEIMPLMOCK_H_
end_define
begin_include
include|#
directive|include
file|"gmock/gmock.h"
end_include
begin_include
include|#
directive|include
file|"libANGLE/renderer/ImageImpl.h"
end_include
begin_decl_stmt
name|namespace
name|rx
block|{
name|class
name|MockImageImpl
range|:
name|public
name|ImageImpl
block|{
name|public
operator|:
name|virtual
operator|~
name|MockImageImpl
argument_list|()
block|{
name|destructor
argument_list|()
block|; }
name|MOCK_METHOD0
argument_list|(
name|initialize
argument_list|,
name|egl
operator|::
name|Error
argument_list|(
name|void
argument_list|)
argument_list|)
block|;
name|MOCK_METHOD1
argument_list|(
name|orphan
argument_list|,
name|gl
operator|::
name|Error
argument_list|(
name|egl
operator|::
name|ImageSibling
operator|*
argument_list|)
argument_list|)
block|;
name|MOCK_METHOD0
argument_list|(
name|destructor
argument_list|,
name|void
argument_list|()
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBANGLE_RENDERER_IMAGEIMPLMOCK_H_
end_comment
end_unit
