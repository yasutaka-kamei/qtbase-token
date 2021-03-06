begin_unit
begin_comment
comment|/* pngmem.c - stub functions for memory allocation  *  * Last changed in libpng 1.6.15 [November 20, 2014]  * Copyright (c) 1998-2014 Glenn Randers-Pehrson  * (Version 0.96 Copyright (c) 1996, 1997 Andreas Dilger)  * (Version 0.88 Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)  *  * This code is released under the libpng license.  * For conditions of distribution and use, see the disclaimer  * and license in png.h  *  * This file provides a location for all memory allocation.  Users who  * need special memory handling are expected to supply replacement  * functions for png_malloc() and png_free(), and to use  * png_create_read_struct_2() and png_create_write_struct_2() to  * identify the replacement functions.  */
end_comment
begin_include
include|#
directive|include
file|"pngpriv.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PNG_READ_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_WRITE_SUPPORTED
argument_list|)
end_if
begin_comment
comment|/* Free a png_struct */
end_comment
begin_function
name|void
comment|/* PRIVATE */
DECL|function|png_destroy_png_struct
name|png_destroy_png_struct
parameter_list|(
name|png_structrp
name|png_ptr
parameter_list|)
block|{
if|if
condition|(
name|png_ptr
operator|!=
name|NULL
condition|)
block|{
comment|/* png_free might call png_error and may certainly call        * png_get_mem_ptr, so fake a temporary png_struct to support this.        */
name|png_struct
name|dummy_struct
init|=
operator|*
name|png_ptr
decl_stmt|;
name|memset
argument_list|(
name|png_ptr
argument_list|,
literal|0
argument_list|,
operator|(
sizeof|sizeof
expr|*
name|png_ptr
operator|)
argument_list|)
expr_stmt|;
name|png_free
argument_list|(
operator|&
name|dummy_struct
argument_list|,
name|png_ptr
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PNG_SETJMP_SUPPORTED
comment|/* We may have a jmp_buf left to deallocate. */
name|png_free_jmpbuf
argument_list|(
operator|&
name|dummy_struct
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_comment
comment|/* Allocate memory.  For reasonable files, size should never exceed  * 64K.  However, zlib may allocate more than 64K if you don't tell  * it not to.  See zconf.h and png.h for more information.  zlib does  * need to allocate exactly 64K, so whatever you call here must  * have the ability to do that.  */
end_comment
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
argument_list|,
argument|PNGAPI png_calloc
argument_list|,
argument|(png_const_structrp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
name|png_voidp
name|ret
decl_stmt|;
name|ret
operator|=
name|png_malloc
argument_list|(
name|png_ptr
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
name|NULL
condition|)
name|memset
argument_list|(
name|ret
argument_list|,
literal|0
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block
begin_comment
comment|/* png_malloc_base, an internal function added at libpng 1.6.0, does the work of  * allocating memory, taking into account limits and PNG_USER_MEM_SUPPORTED.  * Checking and error handling must happen outside this routine; it returns NULL  * if the allocation cannot be done (for any reason.)  */
end_comment
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
comment|/* PRIVATE */
argument_list|,
argument|png_malloc_base
argument_list|,
argument|(png_const_structrp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
comment|/* Moved to png_malloc_base from png_malloc_default in 1.6.0; the DOS     * allocators have also been removed in 1.6.0, so any 16-bit system now has     * to implement a user memory handler.  This checks to be sure it isn't     * called with big numbers.     */
ifndef|#
directive|ifndef
name|PNG_USER_MEM_SUPPORTED
name|PNG_UNUSED
argument_list|(
argument|png_ptr
argument_list|)
endif|#
directive|endif
comment|/* Some compilers complain that this is always true.  However, it     * can be false when integer overflow happens.     */
if|if
condition|(
name|size
operator|>
literal|0
operator|&&
name|size
operator|<=
name|PNG_SIZE_MAX
ifdef|#
directive|ifdef
name|PNG_MAX_MALLOC_64K
operator|&&
name|size
operator|<=
literal|65536U
endif|#
directive|endif
condition|)
block|{
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|png_ptr
operator|!=
name|NULL
operator|&&
name|png_ptr
operator|->
name|malloc_fn
operator|!=
name|NULL
condition|)
return|return
name|png_ptr
operator|->
name|malloc_fn
argument_list|(
name|png_constcast
argument_list|(
name|png_structrp
argument_list|,
name|png_ptr
argument_list|)
argument_list|,
name|size
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|malloc
argument_list|(
operator|(
name|size_t
operator|)
name|size
argument_list|)
return|;
comment|/* checked for truncation above */
block|}
else|else
return|return
name|NULL
return|;
block|}
end_block
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PNG_TEXT_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_sPLT_SUPPORTED
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED
argument_list|)
end_if
begin_comment
comment|/* This is really here only to work round a spurious warning in GCC 4.6 and 4.7  * that arises because of the checks in png_realloc_array that are repeated in  * png_malloc_array.  */
end_comment
begin_function
specifier|static
name|png_voidp
DECL|function|png_malloc_array_checked
name|png_malloc_array_checked
parameter_list|(
name|png_const_structrp
name|png_ptr
parameter_list|,
name|int
name|nelements
parameter_list|,
name|size_t
name|element_size
parameter_list|)
block|{
name|png_alloc_size_t
name|req
init|=
name|nelements
decl_stmt|;
comment|/* known to be> 0 */
if|if
condition|(
name|req
operator|<=
name|PNG_SIZE_MAX
operator|/
name|element_size
condition|)
return|return
name|png_malloc_base
argument_list|(
name|png_ptr
argument_list|,
name|req
operator|*
name|element_size
argument_list|)
return|;
comment|/* The failure case when the request is too large */
return|return
name|NULL
return|;
block|}
end_function
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
comment|/* PRIVATE */
argument_list|,
argument|png_malloc_array
argument_list|,
argument|(png_const_structrp png_ptr, int nelements,    size_t element_size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|nelements
operator|<=
literal|0
operator|||
name|element_size
operator|==
literal|0
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"internal error: array alloc"
argument_list|)
expr_stmt|;
return|return
name|png_malloc_array_checked
argument_list|(
name|png_ptr
argument_list|,
name|nelements
argument_list|,
name|element_size
argument_list|)
return|;
block|}
end_block
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
comment|/* PRIVATE */
argument_list|,
argument|png_realloc_array
argument_list|,
argument|(png_const_structrp png_ptr, png_const_voidp old_array,    int old_elements, int add_elements, size_t element_size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
comment|/* These are internal errors: */
if|if
condition|(
name|add_elements
operator|<=
literal|0
operator|||
name|element_size
operator|==
literal|0
operator|||
name|old_elements
operator|<
literal|0
operator|||
operator|(
name|old_array
operator|==
name|NULL
operator|&&
name|old_elements
operator|>
literal|0
operator|)
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"internal error: array realloc"
argument_list|)
expr_stmt|;
comment|/* Check for overflow on the elements count (so the caller does not have to     * check.)     */
if|if
condition|(
name|add_elements
operator|<=
name|INT_MAX
operator|-
name|old_elements
condition|)
block|{
name|png_voidp
name|new_array
init|=
name|png_malloc_array_checked
argument_list|(
name|png_ptr
argument_list|,
name|old_elements
operator|+
name|add_elements
argument_list|,
name|element_size
argument_list|)
decl_stmt|;
if|if
condition|(
name|new_array
operator|!=
name|NULL
condition|)
block|{
comment|/* Because png_malloc_array worked the size calculations below cannot           * overflow.           */
if|if
condition|(
name|old_elements
operator|>
literal|0
condition|)
name|memcpy
argument_list|(
name|new_array
argument_list|,
name|old_array
argument_list|,
name|element_size
operator|*
operator|(
name|unsigned
operator|)
name|old_elements
argument_list|)
expr_stmt|;
name|memset
argument_list|(
operator|(
name|char
operator|*
operator|)
name|new_array
operator|+
name|element_size
operator|*
operator|(
name|unsigned
operator|)
name|old_elements
argument_list|,
literal|0
argument_list|,
name|element_size
operator|*
operator|(
name|unsigned
operator|)
name|add_elements
argument_list|)
expr_stmt|;
return|return
name|new_array
return|;
block|}
block|}
return|return
name|NULL
return|;
comment|/* error */
block|}
end_block
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TEXT || sPLT || STORE_UNKNOWN_CHUNKS */
end_comment
begin_comment
comment|/* Various functions that have different error handling are derived from this.  * png_malloc always exists, but if PNG_USER_MEM_SUPPORTED is defined a separate  * function png_malloc_default is also provided.  */
end_comment
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
argument_list|,
argument|PNGAPI png_malloc
argument_list|,
argument|(png_const_structrp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
name|png_voidp
name|ret
decl_stmt|;
if|if
condition|(
name|png_ptr
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|ret
operator|=
name|png_malloc_base
argument_list|(
name|png_ptr
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|NULL
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Out of memory"
argument_list|)
expr_stmt|;
comment|/* 'm' means png_malloc */
return|return
name|ret
return|;
block|}
end_block
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
end_ifdef
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
argument_list|,
argument|PNGAPI png_malloc_default
argument_list|,
argument|(png_const_structrp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED PNG_DEPRECATED
argument_list|)
end_macro
begin_block
block|{
name|png_voidp
name|ret
decl_stmt|;
if|if
condition|(
name|png_ptr
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
comment|/* Passing 'NULL' here bypasses the application provided memory handler. */
name|ret
operator|=
name|png_malloc_base
argument_list|(
name|NULL
comment|/*use malloc*/
argument_list|,
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|NULL
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Out of Memory"
argument_list|)
expr_stmt|;
comment|/* 'M' means png_malloc_default */
return|return
name|ret
return|;
block|}
end_block
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* USER_MEM */
end_comment
begin_comment
comment|/* This function was added at libpng version 1.2.3.  The png_malloc_warn()  * function will issue a png_warning and return NULL instead of issuing a  * png_error, if it fails to allocate the requested memory.  */
end_comment
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|png_voidp
argument_list|,
argument|PNGAPI png_malloc_warn
argument_list|,
argument|(png_const_structrp png_ptr, png_alloc_size_t size)
argument_list|,
argument|PNG_ALLOCATED
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|png_ptr
operator|!=
name|NULL
condition|)
block|{
name|png_voidp
name|ret
init|=
name|png_malloc_base
argument_list|(
name|png_ptr
argument_list|,
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|!=
name|NULL
condition|)
return|return
name|ret
return|;
name|png_warning
argument_list|(
name|png_ptr
argument_list|,
literal|"Out of memory"
argument_list|)
expr_stmt|;
block|}
return|return
name|NULL
return|;
block|}
end_block
begin_comment
comment|/* Free a pointer allocated by png_malloc().  If ptr is NULL, return  * without taking any action.  */
end_comment
begin_function
name|void
name|PNGAPI
DECL|function|png_free
name|png_free
parameter_list|(
name|png_const_structrp
name|png_ptr
parameter_list|,
name|png_voidp
name|ptr
parameter_list|)
block|{
if|if
condition|(
name|png_ptr
operator|==
name|NULL
operator|||
name|ptr
operator|==
name|NULL
condition|)
return|return;
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
if|if
condition|(
name|png_ptr
operator|->
name|free_fn
operator|!=
name|NULL
condition|)
name|png_ptr
operator|->
name|free_fn
argument_list|(
name|png_constcast
argument_list|(
name|png_structrp
argument_list|,
name|png_ptr
argument_list|)
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
else|else
name|png_free_default
argument_list|(
name|png_ptr
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
DECL|function|PNG_FUNCTION
name|PNG_FUNCTION
argument_list|(
argument|void
argument_list|,
argument|PNGAPI png_free_default
argument_list|,
argument|(png_const_structrp png_ptr, png_voidp ptr)
argument_list|,
argument|PNG_DEPRECATED
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|png_ptr
operator|==
name|NULL
operator|||
name|ptr
operator|==
name|NULL
condition|)
return|return;
endif|#
directive|endif
comment|/* USER_MEM */
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_block
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
end_ifdef
begin_comment
comment|/* This function is called when the application wants to use another method  * of allocating and freeing memory.  */
end_comment
begin_function
name|void
name|PNGAPI
DECL|function|png_set_mem_fn
name|png_set_mem_fn
parameter_list|(
name|png_structrp
name|png_ptr
parameter_list|,
name|png_voidp
name|mem_ptr
parameter_list|,
name|png_malloc_ptr
name|malloc_fn
parameter_list|,
name|png_free_ptr
name|free_fn
parameter_list|)
block|{
if|if
condition|(
name|png_ptr
operator|!=
name|NULL
condition|)
block|{
name|png_ptr
operator|->
name|mem_ptr
operator|=
name|mem_ptr
expr_stmt|;
name|png_ptr
operator|->
name|malloc_fn
operator|=
name|malloc_fn
expr_stmt|;
name|png_ptr
operator|->
name|free_fn
operator|=
name|free_fn
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/* This function returns a pointer to the mem_ptr associated with the user  * functions.  The application should free any memory associated with this  * pointer before png_write_destroy and png_read_destroy are called.  */
end_comment
begin_function
name|png_voidp
name|PNGAPI
DECL|function|png_get_mem_ptr
name|png_get_mem_ptr
parameter_list|(
name|png_const_structrp
name|png_ptr
parameter_list|)
block|{
if|if
condition|(
name|png_ptr
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
return|return
name|png_ptr
operator|->
name|mem_ptr
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* USER_MEM */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* READ || WRITE */
end_comment
end_unit
