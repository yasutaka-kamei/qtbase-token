begin_unit
begin_comment
comment|/* pngrio.c - functions for data input  *  * Last changed in libpng 1.6.17 [March 26, 2015]  * Copyright (c) 1998-2015 Glenn Randers-Pehrson  * (Version 0.96 Copyright (c) 1996, 1997 Andreas Dilger)  * (Version 0.88 Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)  *  * This code is released under the libpng license.  * For conditions of distribution and use, see the disclaimer  * and license in png.h  *  * This file provides a location for all input.  Users who need  * special handling are expected to write a function that has the same  * arguments as this and performs a similar function, but that possibly  * has a different input method.  Note that you shouldn't change this  * function, but rather write a replacement function and then make  * libpng use it at run time with png_set_read_fn(...).  */
end_comment
begin_include
include|#
directive|include
file|"pngpriv.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_READ_SUPPORTED
end_ifdef
begin_comment
comment|/* Read the data from whatever input you are using.  The default routine  * reads from a file pointer.  Note that this routine sometimes gets called  * with very small lengths, so you should implement some kind of simple  * buffering if you are using unbuffered reads.  This should never be asked  * to read more than 64K on a 16 bit machine.  */
end_comment
begin_function
name|void
comment|/* PRIVATE */
DECL|function|png_read_data
name|png_read_data
parameter_list|(
name|png_structrp
name|png_ptr
parameter_list|,
name|png_bytep
name|data
parameter_list|,
name|png_size_t
name|length
parameter_list|)
block|{
name|png_debug1
argument_list|(
literal|4
argument_list|,
literal|"reading %d bytes"
argument_list|,
operator|(
name|int
operator|)
name|length
argument_list|)
expr_stmt|;
if|if
condition|(
name|png_ptr
operator|->
name|read_data_fn
operator|!=
name|NULL
condition|)
operator|(
operator|*
operator|(
name|png_ptr
operator|->
name|read_data_fn
operator|)
operator|)
operator|(
name|png_ptr
operator|,
name|data
operator|,
name|length
operator|)
expr_stmt|;
else|else
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Call to NULL read function"
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_STDIO_SUPPORTED
end_ifdef
begin_comment
comment|/* This is the function that does the actual reading of data.  If you are  * not reading from a standard C stream, you should create a replacement  * read_data function and use it at run time with png_set_read_fn(), rather  * than changing the library.  */
end_comment
begin_function
name|void
name|PNGCBAPI
DECL|function|png_default_read_data
name|png_default_read_data
parameter_list|(
name|png_structp
name|png_ptr
parameter_list|,
name|png_bytep
name|data
parameter_list|,
name|png_size_t
name|length
parameter_list|)
block|{
name|png_size_t
name|check
decl_stmt|;
if|if
condition|(
name|png_ptr
operator|==
name|NULL
condition|)
return|return;
comment|/* fread() returns 0 on error, so it is OK to store this in a png_size_t     * instead of an int, which is what fread() actually returns.     */
name|check
operator|=
name|fread
argument_list|(
name|data
argument_list|,
literal|1
argument_list|,
name|length
argument_list|,
name|png_voidcast
argument_list|(
name|png_FILE_p
argument_list|,
name|png_ptr
operator|->
name|io_ptr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|check
operator|!=
name|length
condition|)
name|png_error
argument_list|(
name|png_ptr
argument_list|,
literal|"Read Error"
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* This function allows the application to supply a new input function  * for libpng if standard C streams aren't being used.  *  * This function takes as its arguments:  *  * png_ptr      - pointer to a png input data structure  *  * io_ptr       - pointer to user supplied structure containing info about  *                the input functions.  May be NULL.  *  * read_data_fn - pointer to a new input function that takes as its  *                arguments a pointer to a png_struct, a pointer to  *                a location where input data can be stored, and a 32-bit  *                unsigned int that is the number of bytes to be read.  *                To exit and output any fatal error messages the new write  *                function should call png_error(png_ptr, "Error msg").  *                May be NULL, in which case libpng's default function will  *                be used.  */
end_comment
begin_function
name|void
name|PNGAPI
DECL|function|png_set_read_fn
name|png_set_read_fn
parameter_list|(
name|png_structrp
name|png_ptr
parameter_list|,
name|png_voidp
name|io_ptr
parameter_list|,
name|png_rw_ptr
name|read_data_fn
parameter_list|)
block|{
if|if
condition|(
name|png_ptr
operator|==
name|NULL
condition|)
return|return;
name|png_ptr
operator|->
name|io_ptr
operator|=
name|io_ptr
expr_stmt|;
ifdef|#
directive|ifdef
name|PNG_STDIO_SUPPORTED
if|if
condition|(
name|read_data_fn
operator|!=
name|NULL
condition|)
name|png_ptr
operator|->
name|read_data_fn
operator|=
name|read_data_fn
expr_stmt|;
else|else
name|png_ptr
operator|->
name|read_data_fn
operator|=
name|png_default_read_data
expr_stmt|;
else|#
directive|else
name|png_ptr
operator|->
name|read_data_fn
operator|=
name|read_data_fn
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_SUPPORTED
comment|/* It is an error to write to a read device */
if|if
condition|(
name|png_ptr
operator|->
name|write_data_fn
operator|!=
name|NULL
condition|)
block|{
name|png_ptr
operator|->
name|write_data_fn
operator|=
name|NULL
expr_stmt|;
name|png_warning
argument_list|(
name|png_ptr
argument_list|,
literal|"Can't set both read_data_fn and write_data_fn in the"
literal|" same structure"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_FLUSH_SUPPORTED
name|png_ptr
operator|->
name|output_flush_fn
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* READ */
end_comment
end_unit
