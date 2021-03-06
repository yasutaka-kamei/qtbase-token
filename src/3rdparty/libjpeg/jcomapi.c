begin_unit
begin_comment
comment|/*  * jcomapi.c  *  * Copyright (C) 1994-1997, Thomas G. Lane.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file contains application interface routines that are used for both  * compression and decompression.  */
end_comment
begin_define
DECL|macro|JPEG_INTERNALS
define|#
directive|define
name|JPEG_INTERNALS
end_define
begin_include
include|#
directive|include
file|"jinclude.h"
end_include
begin_include
include|#
directive|include
file|"jpeglib.h"
end_include
begin_comment
comment|/*  * Abort processing of a JPEG compression or decompression operation,  * but don't destroy the object itself.  *  * For this, we merely clean up all the nonpermanent memory pools.  * Note that temp files (virtual arrays) are not allowed to belong to  * the permanent pool, so we will be able to close all temp files here.  * Closing a data source or destination, if necessary, is the application's  * responsibility.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_abort
name|jpeg_abort
argument_list|(
argument|j_common_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|int
name|pool
decl_stmt|;
comment|/* Do nothing if called on a not-initialized or destroyed JPEG object. */
if|if
condition|(
name|cinfo
operator|->
name|mem
operator|==
name|NULL
condition|)
return|return;
comment|/* Releasing pools in reverse order might help avoid fragmentation    * with some (brain-damaged) malloc libraries.    */
for|for
control|(
name|pool
operator|=
name|JPOOL_NUMPOOLS
operator|-
literal|1
init|;
name|pool
operator|>
name|JPOOL_PERMANENT
condition|;
name|pool
operator|--
control|)
block|{
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|free_pool
call|)
argument_list|(
name|cinfo
argument_list|,
name|pool
argument_list|)
expr_stmt|;
block|}
comment|/* Reset overall state for possible reuse of object */
if|if
condition|(
name|cinfo
operator|->
name|is_decompressor
condition|)
block|{
name|cinfo
operator|->
name|global_state
operator|=
name|DSTATE_START
expr_stmt|;
comment|/* Try to keep application from accessing now-deleted marker list.      * A bit kludgy to do it here, but this is the most central place.      */
operator|(
operator|(
name|j_decompress_ptr
operator|)
name|cinfo
operator|)
operator|->
name|marker_list
operator|=
name|NULL
expr_stmt|;
block|}
else|else
block|{
name|cinfo
operator|->
name|global_state
operator|=
name|CSTATE_START
expr_stmt|;
block|}
block|}
end_block
begin_comment
comment|/*  * Destruction of a JPEG object.  *  * Everything gets deallocated except the master jpeg_compress_struct itself  * and the error manager struct.  Both of these are supplied by the application  * and must be freed, if necessary, by the application.  (Often they are on  * the stack and so don't need to be freed anyway.)  * Closing a data source or destination, if necessary, is the application's  * responsibility.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_destroy
name|jpeg_destroy
argument_list|(
argument|j_common_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
comment|/* We need only tell the memory manager to release everything. */
comment|/* NB: mem pointer is NULL if memory mgr failed to initialize. */
if|if
condition|(
name|cinfo
operator|->
name|mem
operator|!=
name|NULL
condition|)
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|self_destruct
call|)
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
name|cinfo
operator|->
name|mem
operator|=
name|NULL
expr_stmt|;
comment|/* be safe if jpeg_destroy is called twice */
name|cinfo
operator|->
name|global_state
operator|=
literal|0
expr_stmt|;
comment|/* mark it destroyed */
block|}
end_block
begin_comment
comment|/*  * Convenience routines for allocating quantization and Huffman tables.  * (Would jutils.c be a more reasonable place to put these?)  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|JQUANT_TBL *
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_alloc_quant_table
name|jpeg_alloc_quant_table
argument_list|(
argument|j_common_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|JQUANT_TBL
modifier|*
name|tbl
decl_stmt|;
name|tbl
operator|=
operator|(
name|JQUANT_TBL
operator|*
operator|)
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_small
call|)
argument_list|(
name|cinfo
argument_list|,
name|JPOOL_PERMANENT
argument_list|,
name|SIZEOF
argument_list|(
name|JQUANT_TBL
argument_list|)
argument_list|)
expr_stmt|;
name|tbl
operator|->
name|sent_table
operator|=
name|FALSE
expr_stmt|;
comment|/* make sure this is false in any new table */
return|return
name|tbl
return|;
block|}
end_block
begin_macro
name|GLOBAL
argument_list|(
argument|JHUFF_TBL *
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_alloc_huff_table
name|jpeg_alloc_huff_table
argument_list|(
argument|j_common_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
name|JHUFF_TBL
modifier|*
name|tbl
decl_stmt|;
name|tbl
operator|=
operator|(
name|JHUFF_TBL
operator|*
operator|)
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_small
call|)
argument_list|(
name|cinfo
argument_list|,
name|JPOOL_PERMANENT
argument_list|,
name|SIZEOF
argument_list|(
name|JHUFF_TBL
argument_list|)
argument_list|)
expr_stmt|;
name|tbl
operator|->
name|sent_table
operator|=
name|FALSE
expr_stmt|;
comment|/* make sure this is false in any new table */
return|return
name|tbl
return|;
block|}
end_block
end_unit
