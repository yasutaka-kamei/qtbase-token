begin_unit
begin_comment
comment|/*  * Copyright Â© 2011  Google, Inc.  *  *  This is part of HarfBuzz, a text shaping library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Google Author(s): Behdad Esfahbod  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HB_H_IN
end_ifndef
begin_error
error|#
directive|error
literal|"Include<hb.h> instead."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HB_VERSION_H
end_ifndef
begin_define
DECL|macro|HB_VERSION_H
define|#
directive|define
name|HB_VERSION_H
end_define
begin_include
include|#
directive|include
file|"hb-common.h"
end_include
begin_function_decl
name|HB_BEGIN_DECLS
DECL|macro|HB_VERSION_MAJOR
define|#
directive|define
name|HB_VERSION_MAJOR
value|0
DECL|macro|HB_VERSION_MINOR
define|#
directive|define
name|HB_VERSION_MINOR
value|9
DECL|macro|HB_VERSION_MICRO
define|#
directive|define
name|HB_VERSION_MICRO
value|20
DECL|macro|HB_VERSION_STRING
define|#
directive|define
name|HB_VERSION_STRING
value|"0.9.20"
DECL|macro|HB_VERSION_CHECK
define|#
directive|define
name|HB_VERSION_CHECK
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|,
name|micro
parameter_list|)
define|\
value|((major)*10000+(minor)*100+(micro)>= \ 	 HB_VERSION_MAJOR*10000+HB_VERSION_MINOR*100+HB_VERSION_MICRO)
name|void
name|hb_version
parameter_list|(
name|unsigned
name|int
modifier|*
name|major
parameter_list|,
name|unsigned
name|int
modifier|*
name|minor
parameter_list|,
name|unsigned
name|int
modifier|*
name|micro
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|hb_version_string
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_version_check
parameter_list|(
name|unsigned
name|int
name|major
parameter_list|,
name|unsigned
name|int
name|minor
parameter_list|,
name|unsigned
name|int
name|micro
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|HB_END_DECLS
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* HB_VERSION_H */
end_comment
end_unit