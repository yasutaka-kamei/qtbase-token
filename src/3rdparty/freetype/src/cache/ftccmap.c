begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftccmap.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType CharMap cache (body)                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2000-2015 by                                                 */
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
include|FT_FREETYPE_H
end_include
begin_include
include|#
directive|include
include|FT_CACHE_H
end_include
begin_include
include|#
directive|include
file|"ftcmanag.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_MEMORY_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
file|"ftccback.h"
end_include
begin_include
include|#
directive|include
file|"ftcerror.h"
end_include
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
value|trace_cache
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Each FTC_CMapNode contains a simple array to map a range of character */
end_comment
begin_comment
comment|/* codes to equivalent glyph indices.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* For now, the implementation is very basic: Each node maps a range of  */
end_comment
begin_comment
comment|/* 128 consecutive character codes to their corresponding glyph indices. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* We could do more complex things, but I don't think it is really very  */
end_comment
begin_comment
comment|/* useful.                                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* number of glyph indices / character code per node */
end_comment
begin_define
DECL|macro|FTC_CMAP_INDICES_MAX
define|#
directive|define
name|FTC_CMAP_INDICES_MAX
value|128
end_define
begin_comment
comment|/* compute a query/node hash */
end_comment
begin_define
DECL|macro|FTC_CMAP_HASH
define|#
directive|define
name|FTC_CMAP_HASH
parameter_list|(
name|faceid
parameter_list|,
name|index
parameter_list|,
name|charcode
parameter_list|)
define|\
value|( _FTC_FACE_ID_HASH( faceid ) + 211 * (index) + \             ( (charcode) / FTC_CMAP_INDICES_MAX )      )
end_define
begin_comment
comment|/* the charmap query */
end_comment
begin_typedef
DECL|struct|FTC_CMapQueryRec_
typedef|typedef
struct|struct
name|FTC_CMapQueryRec_
block|{
DECL|member|face_id
name|FTC_FaceID
name|face_id
decl_stmt|;
DECL|member|cmap_index
name|FT_UInt
name|cmap_index
decl_stmt|;
DECL|member|char_code
name|FT_UInt32
name|char_code
decl_stmt|;
block|}
DECL|typedef|FTC_CMapQueryRec
DECL|typedef|FTC_CMapQuery
name|FTC_CMapQueryRec
operator|,
typedef|*
name|FTC_CMapQuery
typedef|;
end_typedef
begin_define
DECL|macro|FTC_CMAP_QUERY
define|#
directive|define
name|FTC_CMAP_QUERY
parameter_list|(
name|x
parameter_list|)
value|((FTC_CMapQuery)(x))
end_define
begin_comment
comment|/* the cmap cache node */
end_comment
begin_typedef
DECL|struct|FTC_CMapNodeRec_
typedef|typedef
struct|struct
name|FTC_CMapNodeRec_
block|{
DECL|member|node
name|FTC_NodeRec
name|node
decl_stmt|;
DECL|member|face_id
name|FTC_FaceID
name|face_id
decl_stmt|;
DECL|member|cmap_index
name|FT_UInt
name|cmap_index
decl_stmt|;
DECL|member|first
name|FT_UInt32
name|first
decl_stmt|;
comment|/* first character in node */
DECL|member|indices
name|FT_UInt16
name|indices
index|[
name|FTC_CMAP_INDICES_MAX
index|]
decl_stmt|;
comment|/* array of glyph indices  */
block|}
DECL|typedef|FTC_CMapNodeRec
DECL|typedef|FTC_CMapNode
name|FTC_CMapNodeRec
operator|,
typedef|*
name|FTC_CMapNode
typedef|;
end_typedef
begin_define
DECL|macro|FTC_CMAP_NODE
define|#
directive|define
name|FTC_CMAP_NODE
parameter_list|(
name|x
parameter_list|)
value|( (FTC_CMapNode)( x ) )
end_define
begin_comment
comment|/* if (indices[n] == FTC_CMAP_UNKNOWN), we assume that the corresponding */
end_comment
begin_comment
comment|/* glyph indices haven't been queried through FT_Get_Glyph_Index() yet   */
end_comment
begin_define
DECL|macro|FTC_CMAP_UNKNOWN
define|#
directive|define
name|FTC_CMAP_UNKNOWN
value|(FT_UInt16)~0
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                        CHARMAP NODES                          *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_macro
name|FT_CALLBACK_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ftc_cmap_node_free
name|ftc_cmap_node_free
argument_list|(
argument|FTC_Node   ftcnode
argument_list|,
argument|FTC_Cache  cache
argument_list|)
end_macro
begin_block
block|{
name|FTC_CMapNode
name|node
init|=
operator|(
name|FTC_CMapNode
operator|)
name|ftcnode
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|cache
operator|->
name|memory
decl_stmt|;
name|FT_FREE
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/* initialize a new cmap node */
end_comment
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ftc_cmap_node_new
argument_list|(
argument|FTC_Node   *ftcanode
argument_list|,
argument|FT_Pointer  ftcquery
argument_list|,
argument|FTC_Cache   cache
argument_list|)
end_macro
begin_block
block|{
name|FTC_CMapNode
modifier|*
name|anode
init|=
operator|(
name|FTC_CMapNode
operator|*
operator|)
name|ftcanode
decl_stmt|;
name|FTC_CMapQuery
name|query
init|=
operator|(
name|FTC_CMapQuery
operator|)
name|ftcquery
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|cache
operator|->
name|memory
decl_stmt|;
name|FTC_CMapNode
name|node
init|=
name|NULL
decl_stmt|;
name|FT_UInt
name|nn
decl_stmt|;
if|if
condition|(
operator|!
name|FT_NEW
argument_list|(
name|node
argument_list|)
condition|)
block|{
name|node
operator|->
name|face_id
operator|=
name|query
operator|->
name|face_id
expr_stmt|;
name|node
operator|->
name|cmap_index
operator|=
name|query
operator|->
name|cmap_index
expr_stmt|;
name|node
operator|->
name|first
operator|=
operator|(
name|query
operator|->
name|char_code
operator|/
name|FTC_CMAP_INDICES_MAX
operator|)
operator|*
name|FTC_CMAP_INDICES_MAX
expr_stmt|;
for|for
control|(
name|nn
operator|=
literal|0
init|;
name|nn
operator|<
name|FTC_CMAP_INDICES_MAX
condition|;
name|nn
operator|++
control|)
name|node
operator|->
name|indices
index|[
name|nn
index|]
operator|=
name|FTC_CMAP_UNKNOWN
expr_stmt|;
block|}
operator|*
name|anode
operator|=
name|node
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* compute the weight of a given cmap node */
end_comment
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Offset
argument_list|)
end_macro
begin_macro
name|ftc_cmap_node_weight
argument_list|(
argument|FTC_Node   cnode
argument_list|,
argument|FTC_Cache  cache
argument_list|)
end_macro
begin_block
block|{
name|FT_UNUSED
argument_list|(
name|cnode
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|cache
argument_list|)
expr_stmt|;
return|return
sizeof|sizeof
argument_list|(
operator|*
name|cnode
argument_list|)
return|;
block|}
end_block
begin_comment
comment|/* compare a cmap node to a given query */
end_comment
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|ftc_cmap_node_compare
argument_list|(
argument|FTC_Node    ftcnode
argument_list|,
argument|FT_Pointer  ftcquery
argument_list|,
argument|FTC_Cache   cache
argument_list|,
argument|FT_Bool*    list_changed
argument_list|)
end_macro
begin_block
block|{
name|FTC_CMapNode
name|node
init|=
operator|(
name|FTC_CMapNode
operator|)
name|ftcnode
decl_stmt|;
name|FTC_CMapQuery
name|query
init|=
operator|(
name|FTC_CMapQuery
operator|)
name|ftcquery
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|cache
argument_list|)
expr_stmt|;
if|if
condition|(
name|list_changed
condition|)
operator|*
name|list_changed
operator|=
name|FALSE
expr_stmt|;
if|if
condition|(
name|node
operator|->
name|face_id
operator|==
name|query
operator|->
name|face_id
operator|&&
name|node
operator|->
name|cmap_index
operator|==
name|query
operator|->
name|cmap_index
condition|)
block|{
name|FT_UInt32
name|offset
init|=
call|(
name|FT_UInt32
call|)
argument_list|(
name|query
operator|->
name|char_code
operator|-
name|node
operator|->
name|first
argument_list|)
decl_stmt|;
return|return
name|FT_BOOL
argument_list|(
name|offset
operator|<
name|FTC_CMAP_INDICES_MAX
argument_list|)
return|;
block|}
return|return
literal|0
return|;
block|}
end_block
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|ftc_cmap_node_remove_faceid
argument_list|(
argument|FTC_Node    ftcnode
argument_list|,
argument|FT_Pointer  ftcface_id
argument_list|,
argument|FTC_Cache   cache
argument_list|,
argument|FT_Bool*    list_changed
argument_list|)
end_macro
begin_block
block|{
name|FTC_CMapNode
name|node
init|=
operator|(
name|FTC_CMapNode
operator|)
name|ftcnode
decl_stmt|;
name|FTC_FaceID
name|face_id
init|=
operator|(
name|FTC_FaceID
operator|)
name|ftcface_id
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|cache
argument_list|)
expr_stmt|;
if|if
condition|(
name|list_changed
condition|)
operator|*
name|list_changed
operator|=
name|FALSE
expr_stmt|;
return|return
name|FT_BOOL
argument_list|(
name|node
operator|->
name|face_id
operator|==
name|face_id
argument_list|)
return|;
block|}
end_block
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                    GLYPH IMAGE CACHE                          *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_decl_stmt
specifier|static
DECL|variable|ftc_cmap_cache_class
specifier|const
name|FTC_CacheClassRec
name|ftc_cmap_cache_class
init|=
block|{
name|ftc_cmap_node_new
block|,
name|ftc_cmap_node_weight
block|,
name|ftc_cmap_node_compare
block|,
name|ftc_cmap_node_remove_faceid
block|,
name|ftc_cmap_node_free
block|,
sizeof|sizeof
argument_list|(
name|FTC_CacheRec
argument_list|)
block|,
name|ftc_cache_init
block|,
name|ftc_cache_done
block|,   }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* documentation is in ftcache.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FTC_CMapCache_New
argument_list|(
argument|FTC_Manager     manager
argument_list|,
argument|FTC_CMapCache  *acache
argument_list|)
end_macro
begin_block
block|{
return|return
name|FTC_Manager_RegisterCache
argument_list|(
name|manager
argument_list|,
operator|&
name|ftc_cmap_cache_class
argument_list|,
name|FTC_CACHE_P
argument_list|(
name|acache
argument_list|)
argument_list|)
return|;
block|}
end_block
begin_comment
comment|/* documentation is in ftcache.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
name|FTC_CMapCache_Lookup
argument_list|(
argument|FTC_CMapCache  cmap_cache
argument_list|,
argument|FTC_FaceID     face_id
argument_list|,
argument|FT_Int         cmap_index
argument_list|,
argument|FT_UInt32      char_code
argument_list|)
end_macro
begin_block
block|{
name|FTC_Cache
name|cache
init|=
name|FTC_CACHE
argument_list|(
name|cmap_cache
argument_list|)
decl_stmt|;
name|FTC_CMapQueryRec
name|query
decl_stmt|;
name|FTC_Node
name|node
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
name|FT_UInt
name|gindex
init|=
literal|0
decl_stmt|;
name|FT_Offset
name|hash
decl_stmt|;
name|FT_Int
name|no_cmap_change
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|cmap_index
operator|<
literal|0
condition|)
block|{
comment|/* Treat a negative cmap index as a special value, meaning that you */
comment|/* don't want to change the FT_Face's character map through this    */
comment|/* call.  This can be useful if the face requester callback already */
comment|/* sets the face's charmap to the appropriate value.                */
name|no_cmap_change
operator|=
literal|1
expr_stmt|;
name|cmap_index
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|cache
condition|)
block|{
name|FT_TRACE0
argument_list|(
operator|(
literal|"FTC_CMapCache_Lookup: bad arguments, returning 0\n"
operator|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
operator|!
name|face_id
condition|)
return|return
literal|0
return|;
name|query
operator|.
name|face_id
operator|=
name|face_id
expr_stmt|;
name|query
operator|.
name|cmap_index
operator|=
operator|(
name|FT_UInt
operator|)
name|cmap_index
expr_stmt|;
name|query
operator|.
name|char_code
operator|=
name|char_code
expr_stmt|;
name|hash
operator|=
name|FTC_CMAP_HASH
argument_list|(
name|face_id
argument_list|,
operator|(
name|FT_UInt
operator|)
name|cmap_index
argument_list|,
name|char_code
argument_list|)
expr_stmt|;
if|#
directive|if
literal|1
name|FTC_CACHE_LOOKUP_CMP
argument_list|(
name|cache
argument_list|,
name|ftc_cmap_node_compare
argument_list|,
name|hash
argument_list|,
operator|&
name|query
argument_list|,
name|node
argument_list|,
name|error
argument_list|)
expr_stmt|;
else|#
directive|else
name|error
operator|=
name|FTC_Cache_Lookup
argument_list|(
name|cache
argument_list|,
name|hash
argument_list|,
operator|&
name|query
argument_list|,
operator|&
name|node
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
name|FT_ASSERT
argument_list|(
call|(
name|FT_UInt
call|)
argument_list|(
name|char_code
operator|-
name|FTC_CMAP_NODE
argument_list|(
name|node
argument_list|)
operator|->
name|first
argument_list|)
operator|<
name|FTC_CMAP_INDICES_MAX
argument_list|)
expr_stmt|;
comment|/* something rotten can happen with rogue clients */
if|if
condition|(
call|(
name|FT_UInt
call|)
argument_list|(
name|char_code
operator|-
name|FTC_CMAP_NODE
argument_list|(
name|node
argument_list|)
operator|->
name|first
operator|>=
name|FTC_CMAP_INDICES_MAX
argument_list|)
condition|)
return|return
literal|0
return|;
comment|/* XXX: should return appropriate error */
name|gindex
operator|=
name|FTC_CMAP_NODE
argument_list|(
name|node
argument_list|)
operator|->
name|indices
index|[
name|char_code
operator|-
name|FTC_CMAP_NODE
argument_list|(
name|node
argument_list|)
operator|->
name|first
index|]
expr_stmt|;
if|if
condition|(
name|gindex
operator|==
name|FTC_CMAP_UNKNOWN
condition|)
block|{
name|FT_Face
name|face
decl_stmt|;
name|gindex
operator|=
literal|0
expr_stmt|;
name|error
operator|=
name|FTC_Manager_LookupFace
argument_list|(
name|cache
operator|->
name|manager
argument_list|,
name|FTC_CMAP_NODE
argument_list|(
name|node
argument_list|)
operator|->
name|face_id
argument_list|,
operator|&
name|face
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
if|if
condition|(
operator|(
name|FT_UInt
operator|)
name|cmap_index
operator|<
operator|(
name|FT_UInt
operator|)
name|face
operator|->
name|num_charmaps
condition|)
block|{
name|FT_CharMap
name|old
decl_stmt|,
name|cmap
init|=
name|NULL
decl_stmt|;
name|old
operator|=
name|face
operator|->
name|charmap
expr_stmt|;
name|cmap
operator|=
name|face
operator|->
name|charmaps
index|[
name|cmap_index
index|]
expr_stmt|;
if|if
condition|(
name|old
operator|!=
name|cmap
operator|&&
operator|!
name|no_cmap_change
condition|)
name|FT_Set_Charmap
argument_list|(
name|face
argument_list|,
name|cmap
argument_list|)
expr_stmt|;
name|gindex
operator|=
name|FT_Get_Char_Index
argument_list|(
name|face
argument_list|,
name|char_code
argument_list|)
expr_stmt|;
if|if
condition|(
name|old
operator|!=
name|cmap
operator|&&
operator|!
name|no_cmap_change
condition|)
name|FT_Set_Charmap
argument_list|(
name|face
argument_list|,
name|old
argument_list|)
expr_stmt|;
block|}
name|FTC_CMAP_NODE
argument_list|(
name|node
argument_list|)
operator|->
name|indices
index|[
name|char_code
operator|-
name|FTC_CMAP_NODE
argument_list|(
name|node
argument_list|)
operator|->
name|first
index|]
operator|=
operator|(
name|FT_UShort
operator|)
name|gindex
expr_stmt|;
block|}
name|Exit
label|:
return|return
name|gindex
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
