begin_unit
begin_comment
comment|/*  * Copyright Â© 2009 Dan Nicholson  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|TEXT_H
end_ifndef
begin_define
DECL|macro|TEXT_H
define|#
directive|define
name|TEXT_H
end_define
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|name
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
DECL|member|value
name|unsigned
name|int
name|value
decl_stmt|;
block|}
DECL|typedef|LookupEntry
name|LookupEntry
typedef|;
end_typedef
begin_function_decl
name|bool
name|LookupString
parameter_list|(
specifier|const
name|LookupEntry
name|tab
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|unsigned
name|int
modifier|*
name|value_rtrn
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|LookupValue
parameter_list|(
specifier|const
name|LookupEntry
name|tab
index|[]
parameter_list|,
name|unsigned
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|extern
specifier|const
name|LookupEntry
name|ctrlMaskNames
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|LookupEntry
name|modComponentMaskNames
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|LookupEntry
name|groupComponentMaskNames
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|LookupEntry
name|groupMaskNames
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|LookupEntry
name|groupNames
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|LookupEntry
name|levelNames
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|LookupEntry
name|buttonNames
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|LookupEntry
name|useModMapValueNames
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|LookupEntry
name|actionTypeNames
index|[]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
specifier|const
name|LookupEntry
name|symInterpretMatchMaskNames
index|[]
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|const
name|char
modifier|*
name|ModMaskText
parameter_list|(
specifier|const
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_mod_mask_t
name|mask
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|ModIndexText
parameter_list|(
specifier|const
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_mod_index_t
name|ndx
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|xkb_mod_index_t
name|ModNameToIndex
parameter_list|(
specifier|const
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_atom_t
name|name
parameter_list|,
name|enum
name|mod_type
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|ActionTypeText
parameter_list|(
name|enum
name|xkb_action_type
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|KeysymText
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
name|xkb_keysym_t
name|sym
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|KeyNameText
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
name|xkb_atom_t
name|name
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|SIMatchText
parameter_list|(
name|enum
name|xkb_match_operation
name|type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|LedStateMaskText
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
name|enum
name|xkb_state_component
name|mask
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|ControlMaskText
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
name|enum
name|xkb_action_controls
name|mask
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TEXT_H */
end_comment
end_unit
