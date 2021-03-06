begin_unit
begin_comment
comment|// Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_include
include|#
directive|include
file|"common/event_tracer.h"
end_include
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_namespace
DECL|namespace|angle
namespace|namespace
name|angle
block|{
DECL|function|GetTraceCategoryEnabledFlag
specifier|const
name|unsigned
name|char
modifier|*
name|GetTraceCategoryEnabledFlag
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|angle
operator|::
name|Platform
modifier|*
name|platform
init|=
name|ANGLEPlatformCurrent
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|platform
argument_list|)
expr_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|categoryEnabledFlag
init|=
name|platform
operator|->
name|getTraceCategoryEnabledFlag
argument_list|(
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|categoryEnabledFlag
operator|!=
literal|nullptr
condition|)
block|{
return|return
name|categoryEnabledFlag
return|;
block|}
specifier|static
name|unsigned
name|char
name|disabled
init|=
literal|0
decl_stmt|;
return|return
operator|&
name|disabled
return|;
block|}
DECL|function|AddTraceEvent
name|Platform
operator|::
name|TraceEventHandle
name|AddTraceEvent
parameter_list|(
name|char
name|phase
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|categoryGroupEnabled
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|long
name|long
name|id
parameter_list|,
name|int
name|numArgs
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argNames
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|argTypes
parameter_list|,
specifier|const
name|unsigned
name|long
name|long
modifier|*
name|argValues
parameter_list|,
name|unsigned
name|char
name|flags
parameter_list|)
block|{
name|angle
operator|::
name|Platform
modifier|*
name|platform
init|=
name|ANGLEPlatformCurrent
argument_list|()
decl_stmt|;
name|ASSERT
argument_list|(
name|platform
argument_list|)
expr_stmt|;
name|double
name|timestamp
init|=
name|platform
operator|->
name|monotonicallyIncreasingTime
argument_list|()
decl_stmt|;
if|if
condition|(
name|timestamp
operator|!=
literal|0
condition|)
block|{
name|angle
operator|::
name|Platform
operator|::
name|TraceEventHandle
name|handle
init|=
name|platform
operator|->
name|addTraceEvent
argument_list|(
name|phase
argument_list|,
name|categoryGroupEnabled
argument_list|,
name|name
argument_list|,
name|id
argument_list|,
name|timestamp
argument_list|,
name|numArgs
argument_list|,
name|argNames
argument_list|,
name|argTypes
argument_list|,
name|argValues
argument_list|,
name|flags
argument_list|)
decl_stmt|;
name|ASSERT
argument_list|(
name|handle
operator|!=
literal|0
argument_list|)
expr_stmt|;
return|return
name|handle
return|;
block|}
return|return
cast|static_cast
argument_list|<
name|Platform
operator|::
name|TraceEventHandle
argument_list|>
argument_list|(
literal|0
argument_list|)
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace angle
end_comment
end_unit
