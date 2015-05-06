begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2stack.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Adobe's code for emulating a CFF stack (body).                       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007-2013 Adobe Systems Incorporated.                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This software, and all works of authorship, whether in source or       */
end_comment
begin_comment
comment|/*  object code form as indicated by the copyright notice(s) included      */
end_comment
begin_comment
comment|/*  herein (collectively, the "Work") is made available, and may only be   */
end_comment
begin_comment
comment|/*  used, modified, and distributed under the FreeType Project License,    */
end_comment
begin_comment
comment|/*  LICENSE.TXT.  Additionally, subject to the terms and conditions of the */
end_comment
begin_comment
comment|/*  FreeType Project License, each contributor to the Work hereby grants   */
end_comment
begin_comment
comment|/*  to any individual or legal entity exercising permissions granted by    */
end_comment
begin_comment
comment|/*  the FreeType Project License and this section (hereafter, "You" or     */
end_comment
begin_comment
comment|/*  "Your") a perpetual, worldwide, non-exclusive, no-charge,              */
end_comment
begin_comment
comment|/*  royalty-free, irrevocable (except as stated in this section) patent    */
end_comment
begin_comment
comment|/*  license to make, have made, use, offer to sell, sell, import, and      */
end_comment
begin_comment
comment|/*  otherwise transfer the Work, where such license applies only to those  */
end_comment
begin_comment
comment|/*  patent claims licensable by such contributor that are necessarily      */
end_comment
begin_comment
comment|/*  infringed by their contribution(s) alone or by combination of their    */
end_comment
begin_comment
comment|/*  contribution(s) with the Work to which such contribution(s) was        */
end_comment
begin_comment
comment|/*  submitted.  If You institute patent litigation against any entity      */
end_comment
begin_comment
comment|/*  (including a cross-claim or counterclaim in a lawsuit) alleging that   */
end_comment
begin_comment
comment|/*  the Work or a contribution incorporated within the Work constitutes    */
end_comment
begin_comment
comment|/*  direct or contributory patent infringement, then any patent licenses   */
end_comment
begin_comment
comment|/*  granted to You under this License for that Work shall terminate as of  */
end_comment
begin_comment
comment|/*  the date such litigation is filed.                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  By using, modifying, or distributing the Work you indicate that you    */
end_comment
begin_comment
comment|/*  have read and understood the terms and conditions of the               */
end_comment
begin_comment
comment|/*  FreeType Project License as well as those provided in this section,    */
end_comment
begin_comment
comment|/*  and you accept them fully.                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"cf2ft.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
file|"cf2glue.h"
end_include
begin_include
include|#
directive|include
file|"cf2font.h"
end_include
begin_include
include|#
directive|include
file|"cf2stack.h"
end_include
begin_include
include|#
directive|include
file|"cf2error.h"
end_include
begin_comment
comment|/* Allocate and initialize an instance of CF2_Stack.       */
end_comment
begin_comment
comment|/* Note: This function returns NULL on error (does not set */
end_comment
begin_comment
comment|/* `error').                                               */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|CF2_Stack
argument_list|)
end_macro
begin_macro
name|cf2_stack_init
argument_list|(
argument|FT_Memory  memory
argument_list|,
argument|FT_Error*  e
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
comment|/* for FT_QNEW */
name|CF2_Stack
name|stack
init|=
name|NULL
decl_stmt|;
if|if
condition|(
operator|!
name|FT_QNEW
argument_list|(
name|stack
argument_list|)
condition|)
block|{
comment|/* initialize the structure; FT_QNEW zeroes it */
name|stack
operator|->
name|memory
operator|=
name|memory
expr_stmt|;
name|stack
operator|->
name|error
operator|=
name|e
expr_stmt|;
name|stack
operator|->
name|top
operator|=
operator|&
name|stack
operator|->
name|buffer
index|[
literal|0
index|]
expr_stmt|;
comment|/* empty stack */
block|}
return|return
name|stack
return|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|cf2_stack_free
name|cf2_stack_free
argument_list|(
argument|CF2_Stack  stack
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|stack
condition|)
block|{
name|FT_Memory
name|memory
init|=
name|stack
operator|->
name|memory
decl_stmt|;
comment|/* free the main structure */
name|FT_FREE
argument_list|(
name|stack
argument_list|)
expr_stmt|;
block|}
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|CF2_UInt
argument_list|)
end_macro
begin_macro
name|cf2_stack_count
argument_list|(
argument|CF2_Stack  stack
argument_list|)
end_macro
begin_block
block|{
return|return
call|(
name|CF2_UInt
call|)
argument_list|(
name|stack
operator|->
name|top
operator|-
operator|&
name|stack
operator|->
name|buffer
index|[
literal|0
index|]
argument_list|)
return|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|cf2_stack_pushInt
name|cf2_stack_pushInt
argument_list|(
argument|CF2_Stack  stack
argument_list|,
argument|CF2_Int    val
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|stack
operator|->
name|top
operator|==
operator|&
name|stack
operator|->
name|buffer
index|[
name|CF2_OPERAND_STACK_SIZE
index|]
condition|)
block|{
name|CF2_SET_ERROR
argument_list|(
name|stack
operator|->
name|error
argument_list|,
name|Stack_Overflow
argument_list|)
expr_stmt|;
return|return;
comment|/* stack overflow */
block|}
name|stack
operator|->
name|top
operator|->
name|u
operator|.
name|i
operator|=
name|val
expr_stmt|;
name|stack
operator|->
name|top
operator|->
name|type
operator|=
name|CF2_NumberInt
expr_stmt|;
operator|++
name|stack
operator|->
name|top
expr_stmt|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|cf2_stack_pushFixed
name|cf2_stack_pushFixed
argument_list|(
argument|CF2_Stack  stack
argument_list|,
argument|CF2_Fixed  val
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|stack
operator|->
name|top
operator|==
operator|&
name|stack
operator|->
name|buffer
index|[
name|CF2_OPERAND_STACK_SIZE
index|]
condition|)
block|{
name|CF2_SET_ERROR
argument_list|(
name|stack
operator|->
name|error
argument_list|,
name|Stack_Overflow
argument_list|)
expr_stmt|;
return|return;
comment|/* stack overflow */
block|}
name|stack
operator|->
name|top
operator|->
name|u
operator|.
name|r
operator|=
name|val
expr_stmt|;
name|stack
operator|->
name|top
operator|->
name|type
operator|=
name|CF2_NumberFixed
expr_stmt|;
operator|++
name|stack
operator|->
name|top
expr_stmt|;
block|}
end_block
begin_comment
comment|/* this function is only allowed to pop an integer type */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|CF2_Int
argument_list|)
end_macro
begin_macro
name|cf2_stack_popInt
argument_list|(
argument|CF2_Stack  stack
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|stack
operator|->
name|top
operator|==
operator|&
name|stack
operator|->
name|buffer
index|[
literal|0
index|]
condition|)
block|{
name|CF2_SET_ERROR
argument_list|(
name|stack
operator|->
name|error
argument_list|,
name|Stack_Underflow
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* underflow */
block|}
if|if
condition|(
name|stack
operator|->
name|top
index|[
operator|-
literal|1
index|]
operator|.
name|type
operator|!=
name|CF2_NumberInt
condition|)
block|{
name|CF2_SET_ERROR
argument_list|(
name|stack
operator|->
name|error
argument_list|,
name|Syntax_Error
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* type mismatch */
block|}
operator|--
name|stack
operator|->
name|top
expr_stmt|;
return|return
name|stack
operator|->
name|top
operator|->
name|u
operator|.
name|i
return|;
block|}
end_block
begin_comment
comment|/* Note: type mismatch is silently cast */
end_comment
begin_comment
comment|/* TODO: check this */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|CF2_Fixed
argument_list|)
end_macro
begin_macro
name|cf2_stack_popFixed
argument_list|(
argument|CF2_Stack  stack
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|stack
operator|->
name|top
operator|==
operator|&
name|stack
operator|->
name|buffer
index|[
literal|0
index|]
condition|)
block|{
name|CF2_SET_ERROR
argument_list|(
name|stack
operator|->
name|error
argument_list|,
name|Stack_Underflow
argument_list|)
expr_stmt|;
return|return
name|cf2_intToFixed
argument_list|(
literal|0
argument_list|)
return|;
comment|/* underflow */
block|}
operator|--
name|stack
operator|->
name|top
expr_stmt|;
switch|switch
condition|(
name|stack
operator|->
name|top
operator|->
name|type
condition|)
block|{
case|case
name|CF2_NumberInt
case|:
return|return
name|cf2_intToFixed
argument_list|(
name|stack
operator|->
name|top
operator|->
name|u
operator|.
name|i
argument_list|)
return|;
case|case
name|CF2_NumberFrac
case|:
return|return
name|cf2_fracToFixed
argument_list|(
name|stack
operator|->
name|top
operator|->
name|u
operator|.
name|f
argument_list|)
return|;
default|default:
return|return
name|stack
operator|->
name|top
operator|->
name|u
operator|.
name|r
return|;
block|}
block|}
end_block
begin_comment
comment|/* Note: type mismatch is silently cast */
end_comment
begin_comment
comment|/* TODO: check this */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|CF2_Fixed
argument_list|)
end_macro
begin_macro
name|cf2_stack_getReal
argument_list|(
argument|CF2_Stack  stack
argument_list|,
argument|CF2_UInt   idx
argument_list|)
end_macro
begin_block
block|{
name|FT_ASSERT
argument_list|(
name|cf2_stack_count
argument_list|(
name|stack
argument_list|)
operator|<=
name|CF2_OPERAND_STACK_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|idx
operator|>=
name|cf2_stack_count
argument_list|(
name|stack
argument_list|)
condition|)
block|{
name|CF2_SET_ERROR
argument_list|(
name|stack
operator|->
name|error
argument_list|,
name|Stack_Overflow
argument_list|)
expr_stmt|;
return|return
name|cf2_intToFixed
argument_list|(
literal|0
argument_list|)
return|;
comment|/* bounds error */
block|}
switch|switch
condition|(
name|stack
operator|->
name|buffer
index|[
name|idx
index|]
operator|.
name|type
condition|)
block|{
case|case
name|CF2_NumberInt
case|:
return|return
name|cf2_intToFixed
argument_list|(
name|stack
operator|->
name|buffer
index|[
name|idx
index|]
operator|.
name|u
operator|.
name|i
argument_list|)
return|;
case|case
name|CF2_NumberFrac
case|:
return|return
name|cf2_fracToFixed
argument_list|(
name|stack
operator|->
name|buffer
index|[
name|idx
index|]
operator|.
name|u
operator|.
name|f
argument_list|)
return|;
default|default:
return|return
name|stack
operator|->
name|buffer
index|[
name|idx
index|]
operator|.
name|u
operator|.
name|r
return|;
block|}
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|cf2_stack_clear
name|cf2_stack_clear
argument_list|(
argument|CF2_Stack  stack
argument_list|)
end_macro
begin_block
block|{
name|stack
operator|->
name|top
operator|=
operator|&
name|stack
operator|->
name|buffer
index|[
literal|0
index|]
expr_stmt|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit