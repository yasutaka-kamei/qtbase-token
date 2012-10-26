begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.
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
comment|//
end_comment
begin_comment
comment|// This file contains the nspr specific functions
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"compiler/osinclude.h"
end_include
begin_comment
comment|//
end_comment
begin_comment
comment|// Thread Local Storage Operations
end_comment
begin_comment
comment|//
end_comment
begin_function
DECL|function|OS_AllocTLSIndex
name|OS_TLSIndex
name|OS_AllocTLSIndex
parameter_list|()
block|{
name|PRUintn
name|index
decl_stmt|;
name|PRStatus
name|status
init|=
name|PR_NewThreadPrivateIndex
argument_list|(
operator|&
name|index
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
if|if
condition|(
name|status
condition|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"OS_AllocTLSIndex(): Unable to allocate Thread Local Storage"
argument_list|)
expr_stmt|;
return|return
name|OS_INVALID_TLS_INDEX
return|;
block|}
return|return
name|index
return|;
block|}
end_function
begin_function
DECL|function|OS_SetTLSValue
name|bool
name|OS_SetTLSValue
parameter_list|(
name|OS_TLSIndex
name|nIndex
parameter_list|,
name|void
modifier|*
name|lpvValue
parameter_list|)
block|{
if|if
condition|(
name|nIndex
operator|==
name|OS_INVALID_TLS_INDEX
condition|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"OS_SetTLSValue(): Invalid TLS Index"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
name|PR_SetThreadPrivate
argument_list|(
name|nIndex
argument_list|,
name|lpvValue
argument_list|)
operator|==
literal|0
return|;
block|}
end_function
begin_function
DECL|function|OS_FreeTLSIndex
name|bool
name|OS_FreeTLSIndex
parameter_list|(
name|OS_TLSIndex
name|nIndex
parameter_list|)
block|{
comment|// Can't delete TLS keys with nspr
return|return
literal|true
return|;
block|}
end_function
end_unit
