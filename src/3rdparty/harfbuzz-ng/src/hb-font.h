begin_unit
begin_comment
comment|/*  * Copyright Â© 2009  Red Hat, Inc.  *  *  This is part of HarfBuzz, a text shaping library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Red Hat Author(s): Behdad Esfahbod  */
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
name|HB_FONT_H
end_ifndef
begin_define
DECL|macro|HB_FONT_H
define|#
directive|define
name|HB_FONT_H
end_define
begin_include
include|#
directive|include
file|"hb-common.h"
end_include
begin_include
include|#
directive|include
file|"hb-face.h"
end_include
begin_macro
name|HB_BEGIN_DECLS
end_macro
begin_typedef
DECL|typedef|hb_font_t
typedef|typedef
name|struct
name|hb_font_t
name|hb_font_t
typedef|;
end_typedef
begin_comment
comment|/*  * hb_font_funcs_t  */
end_comment
begin_typedef
DECL|typedef|hb_font_funcs_t
typedef|typedef
name|struct
name|hb_font_funcs_t
name|hb_font_funcs_t
typedef|;
end_typedef
begin_function_decl
name|hb_font_funcs_t
modifier|*
name|hb_font_funcs_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_font_funcs_t
modifier|*
name|hb_font_funcs_get_empty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_font_funcs_t
modifier|*
name|hb_font_funcs_reference
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_funcs_destroy
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_funcs_set_user_data
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_user_data_key_t
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|,
name|hb_bool_t
name|replace
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
modifier|*
name|hb_font_funcs_get_user_data
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_user_data_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_funcs_make_immutable
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_funcs_is_immutable
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* glyph extents */
end_comment
begin_comment
comment|/* Note that height is negative in coordinate systems that grow up. */
end_comment
begin_typedef
DECL|struct|hb_glyph_extents_t
typedef|typedef
struct|struct
name|hb_glyph_extents_t
block|{
DECL|member|x_bearing
name|hb_position_t
name|x_bearing
decl_stmt|;
comment|/* left side of glyph from origin. */
DECL|member|y_bearing
name|hb_position_t
name|y_bearing
decl_stmt|;
comment|/* top side of glyph from origin. */
DECL|member|width
name|hb_position_t
name|width
decl_stmt|;
comment|/* distance from left to right side. */
DECL|member|height
name|hb_position_t
name|height
decl_stmt|;
comment|/* distance from top to bottom side. */
block|}
DECL|typedef|hb_glyph_extents_t
name|hb_glyph_extents_t
typedef|;
end_typedef
begin_comment
comment|/* func types */
end_comment
begin_typedef
DECL|typedef|hb_font_get_glyph_func_t
typedef|typedef
name|hb_bool_t
function_decl|(
modifier|*
name|hb_font_get_glyph_func_t
function_decl|)
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|void
modifier|*
name|font_data
parameter_list|,
name|hb_codepoint_t
name|unicode
parameter_list|,
name|hb_codepoint_t
name|variation_selector
parameter_list|,
name|hb_codepoint_t
modifier|*
name|glyph
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_advance_func_t
typedef|typedef
name|hb_position_t
function_decl|(
modifier|*
name|hb_font_get_glyph_advance_func_t
function_decl|)
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|void
modifier|*
name|font_data
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_h_advance_func_t
typedef|typedef
name|hb_font_get_glyph_advance_func_t
name|hb_font_get_glyph_h_advance_func_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_v_advance_func_t
typedef|typedef
name|hb_font_get_glyph_advance_func_t
name|hb_font_get_glyph_v_advance_func_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_origin_func_t
typedef|typedef
name|hb_bool_t
function_decl|(
modifier|*
name|hb_font_get_glyph_origin_func_t
function_decl|)
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|void
modifier|*
name|font_data
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|hb_position_t
modifier|*
name|x
parameter_list|,
name|hb_position_t
modifier|*
name|y
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_h_origin_func_t
typedef|typedef
name|hb_font_get_glyph_origin_func_t
name|hb_font_get_glyph_h_origin_func_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_v_origin_func_t
typedef|typedef
name|hb_font_get_glyph_origin_func_t
name|hb_font_get_glyph_v_origin_func_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_kerning_func_t
typedef|typedef
name|hb_position_t
function_decl|(
modifier|*
name|hb_font_get_glyph_kerning_func_t
function_decl|)
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|void
modifier|*
name|font_data
parameter_list|,
name|hb_codepoint_t
name|first_glyph
parameter_list|,
name|hb_codepoint_t
name|second_glyph
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_h_kerning_func_t
typedef|typedef
name|hb_font_get_glyph_kerning_func_t
name|hb_font_get_glyph_h_kerning_func_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_v_kerning_func_t
typedef|typedef
name|hb_font_get_glyph_kerning_func_t
name|hb_font_get_glyph_v_kerning_func_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_extents_func_t
typedef|typedef
name|hb_bool_t
function_decl|(
modifier|*
name|hb_font_get_glyph_extents_func_t
function_decl|)
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|void
modifier|*
name|font_data
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|hb_glyph_extents_t
modifier|*
name|extents
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_contour_point_func_t
typedef|typedef
name|hb_bool_t
function_decl|(
modifier|*
name|hb_font_get_glyph_contour_point_func_t
function_decl|)
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|void
modifier|*
name|font_data
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|unsigned
name|int
name|point_index
parameter_list|,
name|hb_position_t
modifier|*
name|x
parameter_list|,
name|hb_position_t
modifier|*
name|y
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_name_func_t
typedef|typedef
name|hb_bool_t
function_decl|(
modifier|*
name|hb_font_get_glyph_name_func_t
function_decl|)
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|void
modifier|*
name|font_data
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|hb_font_get_glyph_from_name_func_t
typedef|typedef
name|hb_bool_t
function_decl|(
modifier|*
name|hb_font_get_glyph_from_name_func_t
function_decl|)
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|void
modifier|*
name|font_data
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|len
parameter_list|,
comment|/* -1 means nul-terminated */
name|hb_codepoint_t
modifier|*
name|glyph
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* func setters */
end_comment
begin_comment
comment|/**  * hb_font_funcs_set_glyph_func:  * @ffuncs: font functions.  * @func: (closure user_data) (destroy destroy) (scope notified):  * @user_data:  * @destroy:  *  *   *  * Since: 0.9.2  **/
end_comment
begin_function_decl
name|void
name|hb_font_funcs_set_glyph_func
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_font_get_glyph_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**  * hb_font_funcs_set_glyph_h_advance_func:  * @ffuncs: font functions.  * @func: (closure user_data) (destroy destroy) (scope notified):  * @user_data:  * @destroy:  *  *   *  * Since: 0.9.2  **/
end_comment
begin_function_decl
name|void
name|hb_font_funcs_set_glyph_h_advance_func
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_font_get_glyph_h_advance_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**  * hb_font_funcs_set_glyph_v_advance_func:  * @ffuncs: font functions.  * @func: (closure user_data) (destroy destroy) (scope notified):  * @user_data:  * @destroy:  *  *   *  * Since: 0.9.2  **/
end_comment
begin_function_decl
name|void
name|hb_font_funcs_set_glyph_v_advance_func
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_font_get_glyph_v_advance_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**  * hb_font_funcs_set_glyph_h_origin_func:  * @ffuncs: font functions.  * @func: (closure user_data) (destroy destroy) (scope notified):  * @user_data:  * @destroy:  *  *   *  * Since: 0.9.2  **/
end_comment
begin_function_decl
name|void
name|hb_font_funcs_set_glyph_h_origin_func
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_font_get_glyph_h_origin_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**  * hb_font_funcs_set_glyph_v_origin_func:  * @ffuncs: font functions.  * @func: (closure user_data) (destroy destroy) (scope notified):  * @user_data:  * @destroy:  *  *   *  * Since: 0.9.2  **/
end_comment
begin_function_decl
name|void
name|hb_font_funcs_set_glyph_v_origin_func
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_font_get_glyph_v_origin_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**  * hb_font_funcs_set_glyph_h_kerning_func:  * @ffuncs: font functions.  * @func: (closure user_data) (destroy destroy) (scope notified):  * @user_data:  * @destroy:  *  *   *  * Since: 0.9.2  **/
end_comment
begin_function_decl
name|void
name|hb_font_funcs_set_glyph_h_kerning_func
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_font_get_glyph_h_kerning_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**  * hb_font_funcs_set_glyph_v_kerning_func:  * @ffuncs: font functions.  * @func: (closure user_data) (destroy destroy) (scope notified):  * @user_data:  * @destroy:  *  *   *  * Since: 0.9.2  **/
end_comment
begin_function_decl
name|void
name|hb_font_funcs_set_glyph_v_kerning_func
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_font_get_glyph_v_kerning_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**  * hb_font_funcs_set_glyph_extents_func:  * @ffuncs: font functions.  * @func: (closure user_data) (destroy destroy) (scope notified):  * @user_data:  * @destroy:  *  *   *  * Since: 0.9.2  **/
end_comment
begin_function_decl
name|void
name|hb_font_funcs_set_glyph_extents_func
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_font_get_glyph_extents_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**  * hb_font_funcs_set_glyph_contour_point_func:  * @ffuncs: font functions.  * @func: (closure user_data) (destroy destroy) (scope notified):  * @user_data:  * @destroy:  *  *   *  * Since: 0.9.2  **/
end_comment
begin_function_decl
name|void
name|hb_font_funcs_set_glyph_contour_point_func
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_font_get_glyph_contour_point_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**  * hb_font_funcs_set_glyph_name_func:  * @ffuncs: font functions.  * @func: (closure user_data) (destroy destroy) (scope notified):  * @user_data:  * @destroy:  *  *   *  * Since: 0.9.2  **/
end_comment
begin_function_decl
name|void
name|hb_font_funcs_set_glyph_name_func
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_font_get_glyph_name_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/**  * hb_font_funcs_set_glyph_from_name_func:  * @ffuncs: font functions.  * @func: (closure user_data) (destroy destroy) (scope notified):  * @user_data:  * @destroy:  *  *   *  * Since: 0.9.2  **/
end_comment
begin_function_decl
name|void
name|hb_font_funcs_set_glyph_from_name_func
parameter_list|(
name|hb_font_funcs_t
modifier|*
name|ffuncs
parameter_list|,
name|hb_font_get_glyph_from_name_func_t
name|func
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* func dispatch */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_font_get_glyph
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|unicode
parameter_list|,
name|hb_codepoint_t
name|variation_selector
parameter_list|,
name|hb_codepoint_t
modifier|*
name|glyph
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_position_t
name|hb_font_get_glyph_h_advance
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_position_t
name|hb_font_get_glyph_v_advance
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_get_glyph_h_origin
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|hb_position_t
modifier|*
name|x
parameter_list|,
name|hb_position_t
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_get_glyph_v_origin
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|hb_position_t
modifier|*
name|x
parameter_list|,
name|hb_position_t
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_position_t
name|hb_font_get_glyph_h_kerning
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|left_glyph
parameter_list|,
name|hb_codepoint_t
name|right_glyph
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_position_t
name|hb_font_get_glyph_v_kerning
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|top_glyph
parameter_list|,
name|hb_codepoint_t
name|bottom_glyph
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_get_glyph_extents
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|hb_glyph_extents_t
modifier|*
name|extents
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_get_glyph_contour_point
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|unsigned
name|int
name|point_index
parameter_list|,
name|hb_position_t
modifier|*
name|x
parameter_list|,
name|hb_position_t
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_get_glyph_name
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_get_glyph_from_name
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|len
parameter_list|,
comment|/* -1 means nul-terminated */
name|hb_codepoint_t
modifier|*
name|glyph
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* high-level funcs, with fallback */
end_comment
begin_function_decl
name|void
name|hb_font_get_glyph_advance_for_direction
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|hb_direction_t
name|direction
parameter_list|,
name|hb_position_t
modifier|*
name|x
parameter_list|,
name|hb_position_t
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_get_glyph_origin_for_direction
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|hb_direction_t
name|direction
parameter_list|,
name|hb_position_t
modifier|*
name|x
parameter_list|,
name|hb_position_t
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_add_glyph_origin_for_direction
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|hb_direction_t
name|direction
parameter_list|,
name|hb_position_t
modifier|*
name|x
parameter_list|,
name|hb_position_t
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_subtract_glyph_origin_for_direction
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|hb_direction_t
name|direction
parameter_list|,
name|hb_position_t
modifier|*
name|x
parameter_list|,
name|hb_position_t
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_get_glyph_kerning_for_direction
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|first_glyph
parameter_list|,
name|hb_codepoint_t
name|second_glyph
parameter_list|,
name|hb_direction_t
name|direction
parameter_list|,
name|hb_position_t
modifier|*
name|x
parameter_list|,
name|hb_position_t
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_get_glyph_extents_for_origin
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|hb_direction_t
name|direction
parameter_list|,
name|hb_glyph_extents_t
modifier|*
name|extents
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_get_glyph_contour_point_for_origin
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|unsigned
name|int
name|point_index
parameter_list|,
name|hb_direction_t
name|direction
parameter_list|,
name|hb_position_t
modifier|*
name|x
parameter_list|,
name|hb_position_t
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Generates gidDDD if glyph has no name. */
end_comment
begin_function_decl
name|void
name|hb_font_glyph_to_string
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|char
modifier|*
name|s
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Parses gidDDD and uniUUUU strings automatically. */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_font_glyph_from_string
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|,
comment|/* -1 means nul-terminated */
name|hb_codepoint_t
modifier|*
name|glyph
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*  * hb_font_t  */
end_comment
begin_comment
comment|/* Fonts are very light-weight objects */
end_comment
begin_function_decl
name|hb_font_t
modifier|*
name|hb_font_create
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_font_t
modifier|*
name|hb_font_create_sub_font
parameter_list|(
name|hb_font_t
modifier|*
name|parent
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_font_t
modifier|*
name|hb_font_get_empty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_font_t
modifier|*
name|hb_font_reference
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_destroy
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_set_user_data
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_user_data_key_t
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|,
name|hb_bool_t
name|replace
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
modifier|*
name|hb_font_get_user_data
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_user_data_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_make_immutable
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_font_is_immutable
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_set_parent
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_font_t
modifier|*
name|parent
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_font_t
modifier|*
name|hb_font_get_parent
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_face_t
modifier|*
name|hb_font_get_face
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_set_funcs
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_font_funcs_t
modifier|*
name|klass
parameter_list|,
name|void
modifier|*
name|font_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Be *very* careful with this function! */
end_comment
begin_function_decl
name|void
name|hb_font_set_funcs_data
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|void
modifier|*
name|font_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_set_scale
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|int
name|x_scale
parameter_list|,
name|int
name|y_scale
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_get_scale
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|int
modifier|*
name|x_scale
parameter_list|,
name|int
modifier|*
name|y_scale
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*  * A zero value means "no hinting in that direction"  */
end_comment
begin_function_decl
name|void
name|hb_font_set_ppem
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|unsigned
name|int
name|x_ppem
parameter_list|,
name|unsigned
name|int
name|y_ppem
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_font_get_ppem
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|unsigned
name|int
modifier|*
name|x_ppem
parameter_list|,
name|unsigned
name|int
modifier|*
name|y_ppem
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
comment|/* HB_FONT_H */
end_comment
end_unit
