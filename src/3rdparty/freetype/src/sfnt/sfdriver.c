begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  sfdriver.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    High-level SFNT driver interface (body).                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2015 by                                                 */
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
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_SFNT_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
file|"sfdriver.h"
end_include
begin_include
include|#
directive|include
file|"ttload.h"
end_include
begin_include
include|#
directive|include
file|"sfobjs.h"
end_include
begin_include
include|#
directive|include
file|"sfntpic.h"
end_include
begin_include
include|#
directive|include
file|"sferrors.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_EMBEDDED_BITMAPS
end_ifdef
begin_include
include|#
directive|include
file|"ttsbit.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_POSTSCRIPT_NAMES
end_ifdef
begin_include
include|#
directive|include
file|"ttpost.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_BDF
end_ifdef
begin_include
include|#
directive|include
file|"ttbdf.h"
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_BDF_H
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"ttcmap.h"
end_include
begin_include
include|#
directive|include
file|"ttkern.h"
end_include
begin_include
include|#
directive|include
file|"ttmtx.h"
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_GLYPH_DICT_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_NAME_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_SFNT_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_TT_CMAP_H
end_include
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The macro FT_COMPONENT is used in trace mode.  It is an implicit      */
end_comment
begin_comment
comment|/* parameter of the FT_TRACE() and FT_ERROR() macros, used to print/log  */
end_comment
begin_comment
comment|/* messages during execution.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_undef
DECL|macro|FT_COMPONENT
undef|#
directive|undef
name|FT_COMPONENT
end_undef
begin_define
DECL|macro|FT_COMPONENT
define|#
directive|define
name|FT_COMPONENT
value|trace_sfdriver
end_define
begin_comment
comment|/*    *  SFNT TABLE SERVICE    *    */
end_comment
begin_function
specifier|static
name|void
modifier|*
DECL|function|get_sfnt_table
name|get_sfnt_table
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_Sfnt_Tag
name|tag
parameter_list|)
block|{
name|void
modifier|*
name|table
decl_stmt|;
switch|switch
condition|(
name|tag
condition|)
block|{
case|case
name|FT_SFNT_HEAD
case|:
name|table
operator|=
operator|&
name|face
operator|->
name|header
expr_stmt|;
break|break;
case|case
name|FT_SFNT_HHEA
case|:
name|table
operator|=
operator|&
name|face
operator|->
name|horizontal
expr_stmt|;
break|break;
case|case
name|FT_SFNT_VHEA
case|:
name|table
operator|=
name|face
operator|->
name|vertical_info
condition|?
operator|&
name|face
operator|->
name|vertical
else|:
name|NULL
expr_stmt|;
break|break;
case|case
name|FT_SFNT_OS2
case|:
name|table
operator|=
name|face
operator|->
name|os2
operator|.
name|version
operator|==
literal|0xFFFFU
condition|?
name|NULL
else|:
operator|&
name|face
operator|->
name|os2
expr_stmt|;
break|break;
case|case
name|FT_SFNT_POST
case|:
name|table
operator|=
operator|&
name|face
operator|->
name|postscript
expr_stmt|;
break|break;
case|case
name|FT_SFNT_MAXP
case|:
name|table
operator|=
operator|&
name|face
operator|->
name|max_profile
expr_stmt|;
break|break;
case|case
name|FT_SFNT_PCLT
case|:
name|table
operator|=
name|face
operator|->
name|pclt
operator|.
name|Version
condition|?
operator|&
name|face
operator|->
name|pclt
else|:
name|NULL
expr_stmt|;
break|break;
default|default:
name|table
operator|=
name|NULL
expr_stmt|;
block|}
return|return
name|table
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|sfnt_table_info
name|sfnt_table_info
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_UInt
name|idx
parameter_list|,
name|FT_ULong
modifier|*
name|tag
parameter_list|,
name|FT_ULong
modifier|*
name|offset
parameter_list|,
name|FT_ULong
modifier|*
name|length
parameter_list|)
block|{
if|if
condition|(
operator|!
name|offset
operator|||
operator|!
name|length
condition|)
return|return
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
return|;
if|if
condition|(
operator|!
name|tag
condition|)
operator|*
name|length
operator|=
name|face
operator|->
name|num_tables
expr_stmt|;
else|else
block|{
if|if
condition|(
name|idx
operator|>=
name|face
operator|->
name|num_tables
condition|)
return|return
name|FT_THROW
argument_list|(
name|Table_Missing
argument_list|)
return|;
operator|*
name|tag
operator|=
name|face
operator|->
name|dir_tables
index|[
name|idx
index|]
operator|.
name|Tag
expr_stmt|;
operator|*
name|offset
operator|=
name|face
operator|->
name|dir_tables
index|[
name|idx
index|]
operator|.
name|Offset
expr_stmt|;
operator|*
name|length
operator|=
name|face
operator|->
name|dir_tables
index|[
name|idx
index|]
operator|.
name|Length
expr_stmt|;
block|}
return|return
name|FT_Err_Ok
return|;
block|}
end_function
begin_macro
name|FT_DEFINE_SERVICE_SFNT_TABLEREC
argument_list|(
argument|sfnt_service_sfnt_table
argument_list|,
argument|(FT_SFNT_TableLoadFunc)tt_face_load_any
argument_list|,
DECL|variable|get_sfnt_table
argument|(FT_SFNT_TableGetFunc) get_sfnt_table
argument_list|,
argument|(FT_SFNT_TableInfoFunc)sfnt_table_info
argument_list|)
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_POSTSCRIPT_NAMES
end_ifdef
begin_comment
comment|/*    *  GLYPH DICT SERVICE    *    */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|sfnt_get_glyph_name
name|sfnt_get_glyph_name
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_Pointer
name|buffer
parameter_list|,
name|FT_UInt
name|buffer_max
parameter_list|)
block|{
name|FT_String
modifier|*
name|gname
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|error
operator|=
name|tt_face_get_ps_name
argument_list|(
name|face
argument_list|,
name|glyph_index
argument_list|,
operator|&
name|gname
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
name|FT_STRCPYN
argument_list|(
name|buffer
argument_list|,
name|gname
argument_list|,
name|buffer_max
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_function
specifier|static
name|FT_UInt
DECL|function|sfnt_get_name_index
name|sfnt_get_name_index
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_String
modifier|*
name|glyph_name
parameter_list|)
block|{
name|FT_Face
name|root
init|=
operator|&
name|face
operator|->
name|root
decl_stmt|;
name|FT_UInt
name|i
decl_stmt|,
name|max_gid
init|=
name|FT_UINT_MAX
decl_stmt|;
if|if
condition|(
name|root
operator|->
name|num_glyphs
operator|<
literal|0
condition|)
return|return
literal|0
return|;
elseif|else
if|if
condition|(
operator|(
name|FT_ULong
operator|)
name|root
operator|->
name|num_glyphs
operator|<
name|FT_UINT_MAX
condition|)
name|max_gid
operator|=
operator|(
name|FT_UInt
operator|)
name|root
operator|->
name|num_glyphs
expr_stmt|;
else|else
name|FT_TRACE0
argument_list|(
operator|(
literal|"Ignore glyph names for invalid GID 0x%08x - 0x%08x\n"
operator|,
name|FT_UINT_MAX
operator|,
name|root
operator|->
name|num_glyphs
operator|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|max_gid
condition|;
name|i
operator|++
control|)
block|{
name|FT_String
modifier|*
name|gname
decl_stmt|;
name|FT_Error
name|error
init|=
name|tt_face_get_ps_name
argument_list|(
name|face
argument_list|,
name|i
argument_list|,
operator|&
name|gname
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
condition|)
continue|continue;
if|if
condition|(
operator|!
name|ft_strcmp
argument_list|(
name|glyph_name
argument_list|,
name|gname
argument_list|)
condition|)
return|return
name|i
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|FT_DEFINE_SERVICE_GLYPHDICTREC
argument_list|(
argument|sfnt_service_glyph_dict
argument_list|,
argument|(FT_GlyphDict_GetNameFunc)  sfnt_get_glyph_name
argument_list|,
argument|(FT_GlyphDict_NameIndexFunc)sfnt_get_name_index
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TT_CONFIG_OPTION_POSTSCRIPT_NAMES */
end_comment
begin_comment
comment|/*    *  POSTSCRIPT NAME SERVICE    *    */
end_comment
begin_function
specifier|static
specifier|const
name|char
modifier|*
DECL|function|sfnt_get_ps_name
name|sfnt_get_ps_name
parameter_list|(
name|TT_Face
name|face
parameter_list|)
block|{
name|FT_Int
name|n
decl_stmt|,
name|found_win
decl_stmt|,
name|found_apple
decl_stmt|;
specifier|const
name|char
modifier|*
name|result
init|=
name|NULL
decl_stmt|;
comment|/* shouldn't happen, but just in case to avoid memory leaks */
if|if
condition|(
name|face
operator|->
name|postscript_name
condition|)
return|return
name|face
operator|->
name|postscript_name
return|;
comment|/* scan the name table to see whether we have a Postscript name here, */
comment|/* either in Macintosh or Windows platform encodings                  */
name|found_win
operator|=
operator|-
literal|1
expr_stmt|;
name|found_apple
operator|=
operator|-
literal|1
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|face
operator|->
name|num_names
condition|;
name|n
operator|++
control|)
block|{
name|TT_NameEntryRec
modifier|*
name|name
init|=
name|face
operator|->
name|name_table
operator|.
name|names
operator|+
name|n
decl_stmt|;
if|if
condition|(
name|name
operator|->
name|nameID
operator|==
literal|6
operator|&&
name|name
operator|->
name|stringLength
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|name
operator|->
name|platformID
operator|==
literal|3
operator|&&
name|name
operator|->
name|encodingID
operator|==
literal|1
operator|&&
name|name
operator|->
name|languageID
operator|==
literal|0x409
condition|)
name|found_win
operator|=
name|n
expr_stmt|;
if|if
condition|(
name|name
operator|->
name|platformID
operator|==
literal|1
operator|&&
name|name
operator|->
name|encodingID
operator|==
literal|0
operator|&&
name|name
operator|->
name|languageID
operator|==
literal|0
condition|)
name|found_apple
operator|=
name|n
expr_stmt|;
block|}
block|}
if|if
condition|(
name|found_win
operator|!=
operator|-
literal|1
condition|)
block|{
name|FT_Memory
name|memory
init|=
name|face
operator|->
name|root
operator|.
name|memory
decl_stmt|;
name|TT_NameEntryRec
modifier|*
name|name
init|=
name|face
operator|->
name|name_table
operator|.
name|names
operator|+
name|found_win
decl_stmt|;
name|FT_UInt
name|len
init|=
name|name
operator|->
name|stringLength
operator|/
literal|2
decl_stmt|;
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|FT_ALLOC
argument_list|(
name|result
argument_list|,
name|name
operator|->
name|stringLength
operator|+
literal|1
argument_list|)
condition|)
block|{
name|FT_Stream
name|stream
init|=
name|face
operator|->
name|name_table
operator|.
name|stream
decl_stmt|;
name|FT_String
modifier|*
name|r
init|=
operator|(
name|FT_String
operator|*
operator|)
name|result
decl_stmt|;
name|FT_Char
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|FT_STREAM_SEEK
argument_list|(
name|name
operator|->
name|stringOffset
argument_list|)
operator|||
name|FT_FRAME_ENTER
argument_list|(
name|name
operator|->
name|stringLength
argument_list|)
condition|)
block|{
name|FT_FREE
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|name
operator|->
name|stringLength
operator|=
literal|0
expr_stmt|;
name|name
operator|->
name|stringOffset
operator|=
literal|0
expr_stmt|;
name|FT_FREE
argument_list|(
name|name
operator|->
name|string
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
name|p
operator|=
operator|(
name|FT_Char
operator|*
operator|)
name|stream
operator|->
name|cursor
expr_stmt|;
for|for
control|(
init|;
name|len
operator|>
literal|0
condition|;
name|len
operator|--
operator|,
name|p
operator|+=
literal|2
control|)
block|{
if|if
condition|(
name|p
index|[
literal|0
index|]
operator|==
literal|0
operator|&&
name|p
index|[
literal|1
index|]
operator|>=
literal|32
condition|)
operator|*
name|r
operator|++
operator|=
name|p
index|[
literal|1
index|]
expr_stmt|;
block|}
operator|*
name|r
operator|=
literal|'\0'
expr_stmt|;
name|FT_FRAME_EXIT
argument_list|()
expr_stmt|;
block|}
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|found_apple
operator|!=
operator|-
literal|1
condition|)
block|{
name|FT_Memory
name|memory
init|=
name|face
operator|->
name|root
operator|.
name|memory
decl_stmt|;
name|TT_NameEntryRec
modifier|*
name|name
init|=
name|face
operator|->
name|name_table
operator|.
name|names
operator|+
name|found_apple
decl_stmt|;
name|FT_UInt
name|len
init|=
name|name
operator|->
name|stringLength
decl_stmt|;
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|FT_ALLOC
argument_list|(
name|result
argument_list|,
name|len
operator|+
literal|1
argument_list|)
condition|)
block|{
name|FT_Stream
name|stream
init|=
name|face
operator|->
name|name_table
operator|.
name|stream
decl_stmt|;
if|if
condition|(
name|FT_STREAM_SEEK
argument_list|(
name|name
operator|->
name|stringOffset
argument_list|)
operator|||
name|FT_STREAM_READ
argument_list|(
name|result
argument_list|,
name|len
argument_list|)
condition|)
block|{
name|name
operator|->
name|stringOffset
operator|=
literal|0
expr_stmt|;
name|name
operator|->
name|stringLength
operator|=
literal|0
expr_stmt|;
name|FT_FREE
argument_list|(
name|name
operator|->
name|string
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|result
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
operator|(
operator|(
name|char
operator|*
operator|)
name|result
operator|)
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
name|Exit
label|:
name|face
operator|->
name|postscript_name
operator|=
name|result
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_macro
name|FT_DEFINE_SERVICE_PSFONTNAMEREC
argument_list|(
argument|sfnt_service_ps_name
argument_list|,
argument|(FT_PsName_GetFunc)sfnt_get_ps_name
argument_list|)
end_macro
begin_comment
comment|/*    *  TT CMAP INFO    */
end_comment
begin_macro
name|FT_DEFINE_SERVICE_TTCMAPSREC
argument_list|(
argument|tt_service_get_cmap_info
argument_list|,
argument|(TT_CMap_Info_GetFunc)tt_get_cmap_info
argument_list|)
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_BDF
end_ifdef
begin_function
specifier|static
name|FT_Error
DECL|function|sfnt_get_charset_id
name|sfnt_get_charset_id
parameter_list|(
name|TT_Face
name|face
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|acharset_encoding
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|acharset_registry
parameter_list|)
block|{
name|BDF_PropertyRec
name|encoding
decl_stmt|,
name|registry
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
comment|/* XXX: I don't know whether this is correct, since      *      tt_face_find_bdf_prop only returns something correct if we have      *      previously selected a size that is listed in the BDF table.      *      Should we change the BDF table format to include single offsets      *      for `CHARSET_REGISTRY' and `CHARSET_ENCODING'?      */
name|error
operator|=
name|tt_face_find_bdf_prop
argument_list|(
name|face
argument_list|,
literal|"CHARSET_REGISTRY"
argument_list|,
operator|&
name|registry
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
block|{
name|error
operator|=
name|tt_face_find_bdf_prop
argument_list|(
name|face
argument_list|,
literal|"CHARSET_ENCODING"
argument_list|,
operator|&
name|encoding
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|error
condition|)
block|{
if|if
condition|(
name|registry
operator|.
name|type
operator|==
name|BDF_PROPERTY_TYPE_ATOM
operator|&&
name|encoding
operator|.
name|type
operator|==
name|BDF_PROPERTY_TYPE_ATOM
condition|)
block|{
operator|*
name|acharset_encoding
operator|=
name|encoding
operator|.
name|u
operator|.
name|atom
expr_stmt|;
operator|*
name|acharset_registry
operator|=
name|registry
operator|.
name|u
operator|.
name|atom
expr_stmt|;
block|}
else|else
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|error
return|;
block|}
end_function
begin_macro
name|FT_DEFINE_SERVICE_BDFRec
argument_list|(
argument|sfnt_service_bdf
argument_list|,
argument|(FT_BDF_GetCharsetIdFunc)sfnt_get_charset_id
argument_list|,
argument|(FT_BDF_GetPropertyFunc) tt_face_find_bdf_prop
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TT_CONFIG_OPTION_BDF */
end_comment
begin_comment
comment|/*    *  SERVICE LIST    */
end_comment
begin_if
if|#
directive|if
name|defined
name|TT_CONFIG_OPTION_POSTSCRIPT_NAMES
operator|&&
name|defined
name|TT_CONFIG_OPTION_BDF
end_if
begin_macro
name|FT_DEFINE_SERVICEDESCREC5
argument_list|(
argument|sfnt_services
argument_list|,
argument|FT_SERVICE_ID_SFNT_TABLE
argument_list|,
argument|&SFNT_SERVICE_SFNT_TABLE_GET
argument_list|,
argument|FT_SERVICE_ID_POSTSCRIPT_FONT_NAME
argument_list|,
argument|&SFNT_SERVICE_PS_NAME_GET
argument_list|,
argument|FT_SERVICE_ID_GLYPH_DICT
argument_list|,
argument|&SFNT_SERVICE_GLYPH_DICT_GET
argument_list|,
argument|FT_SERVICE_ID_BDF
argument_list|,
argument|&SFNT_SERVICE_BDF_GET
argument_list|,
argument|FT_SERVICE_ID_TT_CMAP
argument_list|,
argument|&TT_SERVICE_CMAP_INFO_GET
argument_list|)
end_macro
begin_elif
elif|#
directive|elif
name|defined
name|TT_CONFIG_OPTION_POSTSCRIPT_NAMES
end_elif
begin_macro
name|FT_DEFINE_SERVICEDESCREC4
argument_list|(
argument|sfnt_services
argument_list|,
argument|FT_SERVICE_ID_SFNT_TABLE
argument_list|,
argument|&SFNT_SERVICE_SFNT_TABLE_GET
argument_list|,
argument|FT_SERVICE_ID_POSTSCRIPT_FONT_NAME
argument_list|,
argument|&SFNT_SERVICE_PS_NAME_GET
argument_list|,
argument|FT_SERVICE_ID_GLYPH_DICT
argument_list|,
argument|&SFNT_SERVICE_GLYPH_DICT_GET
argument_list|,
argument|FT_SERVICE_ID_TT_CMAP
argument_list|,
argument|&TT_SERVICE_CMAP_INFO_GET
argument_list|)
end_macro
begin_elif
elif|#
directive|elif
name|defined
name|TT_CONFIG_OPTION_BDF
end_elif
begin_macro
name|FT_DEFINE_SERVICEDESCREC4
argument_list|(
argument|sfnt_services
argument_list|,
argument|FT_SERVICE_ID_SFNT_TABLE
argument_list|,
argument|&SFNT_SERVICE_SFNT_TABLE_GET
argument_list|,
argument|FT_SERVICE_ID_POSTSCRIPT_FONT_NAME
argument_list|,
argument|&SFNT_SERVICE_PS_NAME_GET
argument_list|,
argument|FT_SERVICE_ID_BDF
argument_list|,
argument|&SFNT_SERVICE_BDF_GET
argument_list|,
argument|FT_SERVICE_ID_TT_CMAP
argument_list|,
argument|&TT_SERVICE_CMAP_INFO_GET
argument_list|)
end_macro
begin_else
else|#
directive|else
end_else
begin_macro
name|FT_DEFINE_SERVICEDESCREC3
argument_list|(
argument|sfnt_services
argument_list|,
argument|FT_SERVICE_ID_SFNT_TABLE
argument_list|,
argument|&SFNT_SERVICE_SFNT_TABLE_GET
argument_list|,
argument|FT_SERVICE_ID_POSTSCRIPT_FONT_NAME
argument_list|,
argument|&SFNT_SERVICE_PS_NAME_GET
argument_list|,
argument|FT_SERVICE_ID_TT_CMAP
argument_list|,
argument|&TT_SERVICE_CMAP_INFO_GET
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Module_Interface
argument_list|)
end_macro
begin_macro
name|sfnt_get_interface
argument_list|(
argument|FT_Module    module
argument_list|,
argument|const char*  module_interface
argument_list|)
end_macro
begin_block
block|{
comment|/* SFNT_SERVICES_GET dereferences `library' in PIC mode */
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_PIC
name|FT_Library
name|library
decl_stmt|;
if|if
condition|(
operator|!
name|module
condition|)
return|return
name|NULL
return|;
name|library
operator|=
name|module
operator|->
name|library
expr_stmt|;
if|if
condition|(
operator|!
name|library
condition|)
return|return
name|NULL
return|;
else|#
directive|else
name|FT_UNUSED
argument_list|(
name|module
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|ft_service_list_lookup
argument_list|(
name|SFNT_SERVICES_GET
argument_list|,
name|module_interface
argument_list|)
return|;
block|}
end_block
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_EMBEDDED_BITMAPS
end_ifdef
begin_define
DECL|macro|PUT_EMBEDDED_BITMAPS
define|#
directive|define
name|PUT_EMBEDDED_BITMAPS
parameter_list|(
name|a
parameter_list|)
value|a
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|PUT_EMBEDDED_BITMAPS
define|#
directive|define
name|PUT_EMBEDDED_BITMAPS
parameter_list|(
name|a
parameter_list|)
value|NULL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_POSTSCRIPT_NAMES
end_ifdef
begin_define
DECL|macro|PUT_PS_NAMES
define|#
directive|define
name|PUT_PS_NAMES
parameter_list|(
name|a
parameter_list|)
value|a
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|PUT_PS_NAMES
define|#
directive|define
name|PUT_PS_NAMES
parameter_list|(
name|a
parameter_list|)
value|NULL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|FT_DEFINE_SFNT_INTERFACE
argument_list|(
argument|sfnt_interface
argument_list|,
argument|tt_face_goto_table
argument_list|,
argument|sfnt_init_face
argument_list|,
argument|sfnt_load_face
argument_list|,
argument|sfnt_done_face
argument_list|,
argument|sfnt_get_interface
argument_list|,
argument|tt_face_load_any
argument_list|,
argument|tt_face_load_head
argument_list|,
argument|tt_face_load_hhea
argument_list|,
argument|tt_face_load_cmap
argument_list|,
argument|tt_face_load_maxp
argument_list|,
argument|tt_face_load_os2
argument_list|,
argument|tt_face_load_post
argument_list|,
argument|tt_face_load_name
argument_list|,
argument|tt_face_free_name
argument_list|,
argument|tt_face_load_kern
argument_list|,
argument|tt_face_load_gasp
argument_list|,
argument|tt_face_load_pclt
argument_list|,
comment|/* see `ttload.h' */
argument|PUT_EMBEDDED_BITMAPS( tt_face_load_bhed )
argument_list|,
argument|PUT_EMBEDDED_BITMAPS( tt_face_load_sbit_image )
argument_list|,
comment|/* see `ttpost.h' */
argument|PUT_PS_NAMES( tt_face_get_ps_name   )
argument_list|,
argument|PUT_PS_NAMES( tt_face_free_ps_names )
argument_list|,
comment|/* since version 2.1.8 */
argument|tt_face_get_kerning
argument_list|,
comment|/* since version 2.2 */
argument|tt_face_load_font_dir
argument_list|,
argument|tt_face_load_hmtx
argument_list|,
comment|/* see `ttsbit.h' and `sfnt.h' */
argument|PUT_EMBEDDED_BITMAPS( tt_face_load_sbit )
argument_list|,
argument|PUT_EMBEDDED_BITMAPS( tt_face_free_sbit )
argument_list|,
argument|PUT_EMBEDDED_BITMAPS( tt_face_set_sbit_strike     )
argument_list|,
argument|PUT_EMBEDDED_BITMAPS( tt_face_load_strike_metrics )
argument_list|,
argument|tt_face_get_metrics
argument_list|,
argument|tt_face_get_name
argument_list|)
end_macro
begin_macro
name|FT_DEFINE_MODULE
argument_list|(
argument|sfnt_module_class
argument_list|,
literal|0
argument_list|,
comment|/* not a font driver or renderer */
argument|sizeof ( FT_ModuleRec )
argument_list|,
literal|"sfnt"
argument_list|,
comment|/* driver name                            */
literal|0x10000L
argument_list|,
comment|/* driver version 1.0                     */
literal|0x20000L
argument_list|,
comment|/* driver requires FreeType 2.0 or higher */
argument|(const void*)&SFNT_INTERFACE_GET
argument_list|,
comment|/* module specific interface */
argument|(FT_Module_Constructor)
literal|0
argument_list|,
argument|(FT_Module_Destructor)
literal|0
argument_list|,
argument|(FT_Module_Requester)  sfnt_get_interface
argument_list|)
end_macro
begin_comment
comment|/* END */
end_comment
end_unit
