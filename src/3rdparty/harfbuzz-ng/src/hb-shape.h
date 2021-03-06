begin_unit
begin_comment
comment|/*  * Copyright Â© 2009  Red Hat, Inc.  * Copyright Â© 2012  Google, Inc.  *  *  This is part of HarfBuzz, a text shaping library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Red Hat Author(s): Behdad Esfahbod  * Google Author(s): Behdad Esfahbod  */
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
name|HB_SHAPE_H
end_ifndef
begin_define
DECL|macro|HB_SHAPE_H
define|#
directive|define
name|HB_SHAPE_H
end_define
begin_include
include|#
directive|include
file|"hb-common.h"
end_include
begin_include
include|#
directive|include
file|"hb-buffer.h"
end_include
begin_include
include|#
directive|include
file|"hb-font.h"
end_include
begin_macro
name|HB_BEGIN_DECLS
end_macro
begin_typedef
DECL|struct|hb_feature_t
typedef|typedef
struct|struct
name|hb_feature_t
block|{
DECL|member|tag
name|hb_tag_t
name|tag
decl_stmt|;
DECL|member|value
name|uint32_t
name|value
decl_stmt|;
DECL|member|start
name|unsigned
name|int
name|start
decl_stmt|;
DECL|member|end
name|unsigned
name|int
name|end
decl_stmt|;
block|}
DECL|typedef|hb_feature_t
name|hb_feature_t
typedef|;
end_typedef
begin_function_decl
name|hb_bool_t
name|hb_feature_from_string
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|,
name|hb_feature_t
modifier|*
name|feature
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_feature_to_string
parameter_list|(
name|hb_feature_t
modifier|*
name|feature
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_shape
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
specifier|const
name|hb_feature_t
modifier|*
name|features
parameter_list|,
name|unsigned
name|int
name|num_features
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_shape_full
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
specifier|const
name|hb_feature_t
modifier|*
name|features
parameter_list|,
name|unsigned
name|int
name|num_features
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|shaper_list
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
modifier|*
name|hb_shape_list_shapers
parameter_list|(
name|void
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
comment|/* HB_SHAPE_H */
end_comment
end_unit
