begin_unit
begin_comment
comment|/************************************************************  * Copyright (c) 1994 by Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both that copyright  * notice and this permission notice appear in supporting  * documentation, and that the name of Silicon Graphics not be  * used in advertising or publicity pertaining to distribution  * of the software without specific prior written permission.  * Silicon Graphics makes no representation about the suitability  * of this software for any purpose. It is provided "as is"  * without any express or implied warranty.  *  * SILICON GRAPHICS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS  * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL SILICON  * GRAPHICS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  WITH  * THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  ********************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|XKBCOMP_EXPR_H
end_ifndef
begin_define
DECL|macro|XKBCOMP_EXPR_H
define|#
directive|define
name|XKBCOMP_EXPR_H
end_define
begin_function_decl
name|bool
name|ExprResolveLhs
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|elem_rtrn
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|field_rtrn
parameter_list|,
name|ExprDef
modifier|*
modifier|*
name|index_rtrn
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveModMask
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
name|enum
name|mod_type
name|mod_type
parameter_list|,
name|xkb_mod_mask_t
modifier|*
name|mask_rtrn
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveMod
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|def
parameter_list|,
name|enum
name|mod_type
name|mod_type
parameter_list|,
name|xkb_mod_index_t
modifier|*
name|ndx_rtrn
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveBoolean
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
name|bool
modifier|*
name|set_rtrn
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveKeyCode
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
name|xkb_keycode_t
modifier|*
name|kc
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveInteger
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
name|int
modifier|*
name|val_rtrn
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveLevel
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
name|xkb_level_index_t
modifier|*
name|level_rtrn
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveGroup
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
name|xkb_layout_index_t
modifier|*
name|group_rtrn
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveButton
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
name|int
modifier|*
name|btn_rtrn
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveString
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
name|xkb_atom_t
modifier|*
name|val_rtrn
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveEnum
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
name|unsigned
name|int
modifier|*
name|val_rtrn
parameter_list|,
specifier|const
name|LookupEntry
modifier|*
name|values
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveMask
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
name|unsigned
name|int
modifier|*
name|mask_rtrn
parameter_list|,
specifier|const
name|LookupEntry
modifier|*
name|values
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|ExprResolveKeySym
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|ExprDef
modifier|*
name|expr
parameter_list|,
name|xkb_keysym_t
modifier|*
name|sym_rtrn
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
end_unit
