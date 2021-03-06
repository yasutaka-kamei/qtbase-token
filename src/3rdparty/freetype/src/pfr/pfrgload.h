begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pfrgload.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType PFR glyph loader (specification).                           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002-2015 by                                                 */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__PFRGLOAD_H__
end_ifndef
begin_define
DECL|macro|__PFRGLOAD_H__
define|#
directive|define
name|__PFRGLOAD_H__
end_define
begin_include
include|#
directive|include
file|"pfrtypes.h"
end_include
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|void
parameter_list|)
function_decl|pfr_glyph_init
parameter_list|(
name|PFR_Glyph
name|glyph
parameter_list|,
name|FT_GlyphLoader
name|loader
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|glyph
name|pfr_glyph_done
argument_list|(
argument|PFR_Glyph  glyph
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|glyph
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|pfr_glyph_load
argument_list|(
argument|PFR_Glyph  glyph
argument_list|,
argument|FT_Stream  stream
argument_list|,
argument|FT_ULong   gps_offset
argument_list|,
argument|FT_ULong   offset
argument_list|,
argument|FT_ULong   size
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __PFRGLOAD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
