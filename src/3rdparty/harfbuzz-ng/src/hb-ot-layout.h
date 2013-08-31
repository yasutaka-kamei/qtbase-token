begin_unit
begin_comment
comment|/*  * Copyright Â© 2007,2008,2009  Red Hat, Inc.  *  *  This is part of HarfBuzz, a text shaping library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Red Hat Author(s): Behdad Esfahbod  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HB_OT_H_IN
end_ifndef
begin_error
error|#
directive|error
literal|"Include<hb-ot.h> instead."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HB_OT_LAYOUT_H
end_ifndef
begin_define
DECL|macro|HB_OT_LAYOUT_H
define|#
directive|define
name|HB_OT_LAYOUT_H
end_define
begin_include
include|#
directive|include
file|"hb.h"
end_include
begin_include
include|#
directive|include
file|"hb-ot-tag.h"
end_include
begin_function_decl
name|HB_BEGIN_DECLS
DECL|macro|HB_OT_TAG_GDEF
define|#
directive|define
name|HB_OT_TAG_GDEF
value|HB_TAG('G','D','E','F')
DECL|macro|HB_OT_TAG_GSUB
define|#
directive|define
name|HB_OT_TAG_GSUB
value|HB_TAG('G','S','U','B')
DECL|macro|HB_OT_TAG_GPOS
define|#
directive|define
name|HB_OT_TAG_GPOS
value|HB_TAG('G','P','O','S')
comment|/*  * GDEF  */
name|hb_bool_t
name|hb_ot_layout_has_glyph_classes
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|)
function_decl|;
end_function_decl
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_OT_LAYOUT_GLYPH_CLASS_UNCLASSIFIED
name|HB_OT_LAYOUT_GLYPH_CLASS_UNCLASSIFIED
init|=
literal|0
block|,
DECL|enumerator|HB_OT_LAYOUT_GLYPH_CLASS_BASE_GLYPH
name|HB_OT_LAYOUT_GLYPH_CLASS_BASE_GLYPH
init|=
literal|1
block|,
DECL|enumerator|HB_OT_LAYOUT_GLYPH_CLASS_LIGATURE
name|HB_OT_LAYOUT_GLYPH_CLASS_LIGATURE
init|=
literal|2
block|,
DECL|enumerator|HB_OT_LAYOUT_GLYPH_CLASS_MARK
name|HB_OT_LAYOUT_GLYPH_CLASS_MARK
init|=
literal|3
block|,
DECL|enumerator|HB_OT_LAYOUT_GLYPH_CLASS_COMPONENT
name|HB_OT_LAYOUT_GLYPH_CLASS_COMPONENT
init|=
literal|4
block|}
DECL|typedef|hb_ot_layout_glyph_class_t
name|hb_ot_layout_glyph_class_t
typedef|;
end_typedef
begin_function_decl
name|hb_ot_layout_glyph_class_t
name|hb_ot_layout_get_glyph_class
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_ot_layout_get_glyphs_in_class
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_ot_layout_glyph_class_t
name|klass
parameter_list|,
name|hb_set_t
modifier|*
name|glyphs
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Not that useful.  Provides list of attach points for a glyph that a  * client may want to cache */
end_comment
begin_function_decl
name|unsigned
name|int
name|hb_ot_layout_get_attach_points
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|unsigned
name|int
name|start_offset
parameter_list|,
name|unsigned
name|int
modifier|*
name|point_count
comment|/* IN/OUT */
parameter_list|,
name|unsigned
name|int
modifier|*
name|point_array
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Ligature caret positions */
end_comment
begin_function_decl
name|unsigned
name|int
name|hb_ot_layout_get_ligature_carets
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_direction_t
name|direction
parameter_list|,
name|hb_codepoint_t
name|glyph
parameter_list|,
name|unsigned
name|int
name|start_offset
parameter_list|,
name|unsigned
name|int
modifier|*
name|caret_count
comment|/* IN/OUT */
parameter_list|,
name|hb_position_t
modifier|*
name|caret_array
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*  * GSUB/GPOS feature query and enumeration interface  */
end_comment
begin_define
DECL|macro|HB_OT_LAYOUT_NO_SCRIPT_INDEX
define|#
directive|define
name|HB_OT_LAYOUT_NO_SCRIPT_INDEX
value|((unsigned int) 0xFFFF)
end_define
begin_define
DECL|macro|HB_OT_LAYOUT_NO_FEATURE_INDEX
define|#
directive|define
name|HB_OT_LAYOUT_NO_FEATURE_INDEX
value|((unsigned int) 0xFFFF)
end_define
begin_define
DECL|macro|HB_OT_LAYOUT_DEFAULT_LANGUAGE_INDEX
define|#
directive|define
name|HB_OT_LAYOUT_DEFAULT_LANGUAGE_INDEX
value|((unsigned int) 0xFFFF)
end_define
begin_function_decl
name|unsigned
name|int
name|hb_ot_layout_table_get_script_tags
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|start_offset
parameter_list|,
name|unsigned
name|int
modifier|*
name|script_count
comment|/* IN/OUT */
parameter_list|,
name|hb_tag_t
modifier|*
name|script_tags
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_ot_layout_table_find_script
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|hb_tag_t
name|script_tag
parameter_list|,
name|unsigned
name|int
modifier|*
name|script_index
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Like find_script, but takes zero-terminated array of scripts to test */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_ot_layout_table_choose_script
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
specifier|const
name|hb_tag_t
modifier|*
name|script_tags
parameter_list|,
name|unsigned
name|int
modifier|*
name|script_index
parameter_list|,
name|hb_tag_t
modifier|*
name|chosen_script
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|unsigned
name|int
name|hb_ot_layout_table_get_feature_tags
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|start_offset
parameter_list|,
name|unsigned
name|int
modifier|*
name|feature_count
comment|/* IN/OUT */
parameter_list|,
name|hb_tag_t
modifier|*
name|feature_tags
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|unsigned
name|int
name|hb_ot_layout_script_get_language_tags
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|script_index
parameter_list|,
name|unsigned
name|int
name|start_offset
parameter_list|,
name|unsigned
name|int
modifier|*
name|language_count
comment|/* IN/OUT */
parameter_list|,
name|hb_tag_t
modifier|*
name|language_tags
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_ot_layout_script_find_language
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|script_index
parameter_list|,
name|hb_tag_t
name|language_tag
parameter_list|,
name|unsigned
name|int
modifier|*
name|language_index
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_ot_layout_language_get_required_feature_index
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|script_index
parameter_list|,
name|unsigned
name|int
name|language_index
parameter_list|,
name|unsigned
name|int
modifier|*
name|feature_index
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|unsigned
name|int
name|hb_ot_layout_language_get_feature_indexes
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|script_index
parameter_list|,
name|unsigned
name|int
name|language_index
parameter_list|,
name|unsigned
name|int
name|start_offset
parameter_list|,
name|unsigned
name|int
modifier|*
name|feature_count
comment|/* IN/OUT */
parameter_list|,
name|unsigned
name|int
modifier|*
name|feature_indexes
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|unsigned
name|int
name|hb_ot_layout_language_get_feature_tags
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|script_index
parameter_list|,
name|unsigned
name|int
name|language_index
parameter_list|,
name|unsigned
name|int
name|start_offset
parameter_list|,
name|unsigned
name|int
modifier|*
name|feature_count
comment|/* IN/OUT */
parameter_list|,
name|hb_tag_t
modifier|*
name|feature_tags
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_ot_layout_language_find_feature
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|script_index
parameter_list|,
name|unsigned
name|int
name|language_index
parameter_list|,
name|hb_tag_t
name|feature_tag
parameter_list|,
name|unsigned
name|int
modifier|*
name|feature_index
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|unsigned
name|int
name|hb_ot_layout_feature_get_lookups
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|feature_index
parameter_list|,
name|unsigned
name|int
name|start_offset
parameter_list|,
name|unsigned
name|int
modifier|*
name|lookup_count
comment|/* IN/OUT */
parameter_list|,
name|unsigned
name|int
modifier|*
name|lookup_indexes
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_ot_layout_collect_lookups
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
specifier|const
name|hb_tag_t
modifier|*
name|scripts
parameter_list|,
specifier|const
name|hb_tag_t
modifier|*
name|languages
parameter_list|,
specifier|const
name|hb_tag_t
modifier|*
name|features
parameter_list|,
name|hb_set_t
modifier|*
name|lookup_indexes
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_ot_shape_plan_collect_lookups
parameter_list|(
name|hb_shape_plan_t
modifier|*
name|shape_plan
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|hb_set_t
modifier|*
name|lookup_indexes
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_ot_layout_lookup_collect_glyphs
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|lookup_index
parameter_list|,
name|hb_set_t
modifier|*
name|glyphs_before
parameter_list|,
comment|/* OUT. May be NULL */
name|hb_set_t
modifier|*
name|glyphs_input
parameter_list|,
comment|/* OUT. May be NULL */
name|hb_set_t
modifier|*
name|glyphs_after
parameter_list|,
comment|/* OUT. May be NULL */
name|hb_set_t
modifier|*
name|glyphs_output
comment|/* OUT. May be NULL */
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|HB_NOT_IMPLEMENTED
end_ifdef
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|before
specifier|const
name|hb_codepoint_t
modifier|*
name|before
decl_stmt|,
DECL|member|before_length
name|unsigned
name|int
name|before_length
decl_stmt|,   const
DECL|member|input
name|hb_codepoint_t
modifier|*
name|input
decl_stmt|,
DECL|member|input_length
name|unsigned
name|int
name|input_length
decl_stmt|,   const
DECL|member|after
name|hb_codepoint_t
modifier|*
name|after
decl_stmt|,
DECL|member|after_length
name|unsigned
name|int
name|after_length
decl_stmt|,
block|}
DECL|typedef|hb_ot_layout_glyph_sequence_t
name|hb_ot_layout_glyph_sequence_t
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|hb_bool_t
function_decl|(
DECL|typedef|hb_ot_layout_glyph_sequence_func_t
modifier|*
name|hb_ot_layout_glyph_sequence_func_t
function_decl|)
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|lookup_index
parameter_list|,
specifier|const
name|hb_ot_layout_glyph_sequence_t
modifier|*
name|sequence
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
name|void
name|Xhb_ot_layout_lookup_enumerate_sequences
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|hb_tag_t
name|table_tag
parameter_list|,
name|unsigned
name|int
name|lookup_index
parameter_list|,
name|hb_ot_layout_glyph_sequence_func_t
name|callback
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*  * GSUB  */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_ot_layout_has_substitution
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_ot_layout_lookup_would_substitute
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|unsigned
name|int
name|lookup_index
parameter_list|,
specifier|const
name|hb_codepoint_t
modifier|*
name|glyphs
parameter_list|,
name|unsigned
name|int
name|glyphs_length
parameter_list|,
name|hb_bool_t
name|zero_context
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_ot_layout_lookup_substitute_closure
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|unsigned
name|int
name|lookup_index
parameter_list|,
name|hb_set_t
modifier|*
name|glyphs
comment|/*TODO , hb_bool_t  inclusive */
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|HB_NOT_IMPLEMENTED
end_ifdef
begin_comment
comment|/* Note: You better have GDEF when using this API, or marks won't do much. */
end_comment
begin_function_decl
name|hb_bool_t
name|Xhb_ot_layout_lookup_substitute
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|unsigned
name|int
name|lookup_index
parameter_list|,
specifier|const
name|hb_ot_layout_glyph_sequence_t
modifier|*
name|sequence
parameter_list|,
name|unsigned
name|int
name|out_size
parameter_list|,
name|hb_codepoint_t
modifier|*
name|glyphs_out
parameter_list|,
comment|/* OUT */
name|unsigned
name|int
modifier|*
name|clusters_out
parameter_list|,
comment|/* OUT */
name|unsigned
name|int
modifier|*
name|out_length
comment|/* OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*  * GPOS  */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_ot_layout_has_positioning
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|HB_NOT_IMPLEMENTED
end_ifdef
begin_comment
comment|/* Note: You better have GDEF when using this API, or marks won't do much. */
end_comment
begin_function_decl
name|hb_bool_t
name|Xhb_ot_layout_lookup_position
parameter_list|(
name|hb_font_t
modifier|*
name|font
parameter_list|,
name|unsigned
name|int
name|lookup_index
parameter_list|,
specifier|const
name|hb_ot_layout_glyph_sequence_t
modifier|*
name|sequence
parameter_list|,
name|hb_glyph_position_t
modifier|*
name|positions
comment|/* IN / OUT */
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Optical 'size' feature info.  Returns true if found.  * http://www.microsoft.com/typography/otspec/features_pt.htm#size */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_ot_layout_get_size_params
parameter_list|(
name|hb_face_t
modifier|*
name|face
parameter_list|,
name|unsigned
name|int
modifier|*
name|design_size
parameter_list|,
comment|/* OUT.  May be NULL */
name|unsigned
name|int
modifier|*
name|subfamily_id
parameter_list|,
comment|/* OUT.  May be NULL */
name|unsigned
name|int
modifier|*
name|subfamily_name_id
parameter_list|,
comment|/* OUT.  May be NULL */
name|unsigned
name|int
modifier|*
name|range_start
parameter_list|,
comment|/* OUT.  May be NULL */
name|unsigned
name|int
modifier|*
name|range_end
comment|/* OUT.  May be NULL */
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
comment|/* HB_OT_LAYOUT_H */
end_comment
end_unit