begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2014 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|COMPILER_TRANSLATOR_CONSTANTUNION_H_
end_ifndef
begin_define
DECL|macro|COMPILER_TRANSLATOR_CONSTANTUNION_H_
define|#
directive|define
name|COMPILER_TRANSLATOR_CONSTANTUNION_H_
end_define
begin_include
include|#
directive|include
file|<assert.h>
end_include
begin_include
include|#
directive|include
file|"compiler/translator/BaseTypes.h"
end_include
begin_decl_stmt
name|class
name|TConstantUnion
block|{
name|public
label|:
name|POOL_ALLOCATOR_NEW_DELETE
argument_list|()
expr_stmt|;
name|TConstantUnion
argument_list|()
block|{
name|iConst
operator|=
literal|0
expr_stmt|;
name|type
operator|=
name|EbtVoid
expr_stmt|;
block|}
name|bool
name|cast
parameter_list|(
name|TBasicType
name|newType
parameter_list|,
specifier|const
name|TConstantUnion
modifier|&
name|constant
parameter_list|)
block|{
switch|switch
condition|(
name|newType
condition|)
block|{
case|case
name|EbtFloat
case|:
switch|switch
condition|(
name|constant
operator|.
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|setFConst
argument_list|(
name|static_cast
operator|<
name|float
operator|>
operator|(
name|constant
operator|.
name|getIConst
argument_list|()
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|setFConst
argument_list|(
name|static_cast
operator|<
name|float
operator|>
operator|(
name|constant
operator|.
name|getUConst
argument_list|()
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtBool
case|:
name|setFConst
argument_list|(
name|static_cast
operator|<
name|float
operator|>
operator|(
name|constant
operator|.
name|getBConst
argument_list|()
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtFloat
case|:
name|setFConst
argument_list|(
name|static_cast
operator|<
name|float
operator|>
operator|(
name|constant
operator|.
name|getFConst
argument_list|()
operator|)
argument_list|)
expr_stmt|;
break|break;
default|default:
return|return
name|false
return|;
block|}
break|break;
case|case
name|EbtInt
case|:
switch|switch
condition|(
name|constant
operator|.
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|setIConst
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|constant
operator|.
name|getIConst
argument_list|()
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|setIConst
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|constant
operator|.
name|getUConst
argument_list|()
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtBool
case|:
name|setIConst
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|constant
operator|.
name|getBConst
argument_list|()
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtFloat
case|:
name|setIConst
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|constant
operator|.
name|getFConst
argument_list|()
operator|)
argument_list|)
expr_stmt|;
break|break;
default|default:
return|return
name|false
return|;
block|}
break|break;
case|case
name|EbtUInt
case|:
switch|switch
condition|(
name|constant
operator|.
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|setUConst
argument_list|(
argument|static_cast<unsigned int>(constant.getIConst())
argument_list|)
empty_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|setUConst
argument_list|(
argument|static_cast<unsigned int>(constant.getUConst())
argument_list|)
empty_stmt|;
break|break;
case|case
name|EbtBool
case|:
name|setUConst
argument_list|(
argument|static_cast<unsigned int>(constant.getBConst())
argument_list|)
empty_stmt|;
break|break;
case|case
name|EbtFloat
case|:
name|setUConst
argument_list|(
argument|static_cast<unsigned int>(constant.getFConst())
argument_list|)
empty_stmt|;
break|break;
default|default:
return|return
name|false
return|;
block|}
break|break;
case|case
name|EbtBool
case|:
switch|switch
condition|(
name|constant
operator|.
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|setBConst
argument_list|(
name|constant
operator|.
name|getIConst
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|setBConst
argument_list|(
name|constant
operator|.
name|getUConst
argument_list|()
operator|!=
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtBool
case|:
name|setBConst
argument_list|(
name|constant
operator|.
name|getBConst
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtFloat
case|:
name|setBConst
argument_list|(
name|constant
operator|.
name|getFConst
argument_list|()
operator|!=
literal|0.0f
argument_list|)
expr_stmt|;
break|break;
default|default:
return|return
name|false
return|;
block|}
break|break;
case|case
name|EbtStruct
case|:
comment|// Struct fields don't get cast
switch|switch
condition|(
name|constant
operator|.
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|setIConst
argument_list|(
name|constant
operator|.
name|getIConst
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|setUConst
argument_list|(
name|constant
operator|.
name|getUConst
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtBool
case|:
name|setBConst
argument_list|(
name|constant
operator|.
name|getBConst
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtFloat
case|:
name|setFConst
argument_list|(
name|constant
operator|.
name|getFConst
argument_list|()
argument_list|)
expr_stmt|;
break|break;
default|default:
return|return
name|false
return|;
block|}
break|break;
default|default:
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
name|void
name|setIConst
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|iConst
operator|=
name|i
expr_stmt|;
name|type
operator|=
name|EbtInt
expr_stmt|;
block|}
name|void
name|setUConst
parameter_list|(
name|unsigned
name|int
name|u
parameter_list|)
block|{
name|uConst
operator|=
name|u
expr_stmt|;
name|type
operator|=
name|EbtUInt
expr_stmt|;
block|}
name|void
name|setFConst
parameter_list|(
name|float
name|f
parameter_list|)
block|{
name|fConst
operator|=
name|f
expr_stmt|;
name|type
operator|=
name|EbtFloat
expr_stmt|;
block|}
name|void
name|setBConst
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|bConst
operator|=
name|b
expr_stmt|;
name|type
operator|=
name|EbtBool
expr_stmt|;
block|}
name|int
name|getIConst
argument_list|()
specifier|const
block|{
return|return
name|iConst
return|;
block|}
name|unsigned
name|int
name|getUConst
argument_list|()
specifier|const
block|{
return|return
name|uConst
return|;
block|}
name|float
name|getFConst
argument_list|()
specifier|const
block|{
return|return
name|fConst
return|;
block|}
name|bool
name|getBConst
argument_list|()
specifier|const
block|{
return|return
name|bConst
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|int
name|i
operator|)
specifier|const
block|{
return|return
name|i
operator|==
name|iConst
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|unsigned
name|int
name|u
operator|)
specifier|const
block|{
return|return
name|u
operator|==
name|uConst
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|float
name|f
operator|)
specifier|const
block|{
return|return
name|f
operator|==
name|fConst
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|bool
name|b
operator|)
specifier|const
block|{
return|return
name|b
operator|==
name|bConst
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
if|if
condition|(
name|constant
operator|.
name|type
operator|!=
name|type
condition|)
return|return
name|false
return|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
return|return
name|constant
operator|.
name|iConst
operator|==
name|iConst
return|;
case|case
name|EbtUInt
case|:
return|return
name|constant
operator|.
name|uConst
operator|==
name|uConst
return|;
case|case
name|EbtFloat
case|:
return|return
name|constant
operator|.
name|fConst
operator|==
name|fConst
return|;
case|case
name|EbtBool
case|:
return|return
name|constant
operator|.
name|bConst
operator|==
name|bConst
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
end_decl_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|int
name|i
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|i
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|unsigned
name|int
name|u
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|u
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|float
name|f
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|f
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|bool
name|b
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|b
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|constant
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|>
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
return|return
name|iConst
operator|>
name|constant
operator|.
name|iConst
return|;
case|case
name|EbtUInt
case|:
return|return
name|uConst
operator|>
name|constant
operator|.
name|uConst
return|;
case|case
name|EbtFloat
case|:
return|return
name|fConst
operator|>
name|constant
operator|.
name|fConst
return|;
default|default:
return|return
name|false
return|;
comment|// Invalid operation, handled at semantic analysis
block|}
end_expr_stmt
begin_expr_stmt
unit|}      bool
name|operator
operator|<
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
return|return
name|iConst
operator|<
name|constant
operator|.
name|iConst
return|;
case|case
name|EbtUInt
case|:
return|return
name|uConst
operator|<
name|constant
operator|.
name|uConst
return|;
case|case
name|EbtFloat
case|:
return|return
name|fConst
operator|<
name|constant
operator|.
name|fConst
return|;
default|default:
return|return
name|false
return|;
comment|// Invalid operation, handled at semantic analysis
block|}
end_expr_stmt
begin_expr_stmt
unit|}      TConstantUnion
name|operator
operator|+
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|TConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|+
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|returnValue
operator|.
name|setUConst
argument_list|(
name|uConst
operator|+
name|constant
operator|.
name|uConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtFloat
case|:
name|returnValue
operator|.
name|setFConst
argument_list|(
name|fConst
operator|+
name|constant
operator|.
name|fConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      TConstantUnion
name|operator
operator|-
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|TConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|-
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|returnValue
operator|.
name|setUConst
argument_list|(
name|uConst
operator|-
name|constant
operator|.
name|uConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtFloat
case|:
name|returnValue
operator|.
name|setFConst
argument_list|(
name|fConst
operator|-
name|constant
operator|.
name|fConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_macro
unit|}      TConstantUnion
name|operator
end_macro
begin_expr_stmt
operator|*
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|TConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|*
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|returnValue
operator|.
name|setUConst
argument_list|(
name|uConst
operator|*
name|constant
operator|.
name|uConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtFloat
case|:
name|returnValue
operator|.
name|setFConst
argument_list|(
name|fConst
operator|*
name|constant
operator|.
name|fConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      TConstantUnion
name|operator
operator|%
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|TConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|%
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|returnValue
operator|.
name|setUConst
argument_list|(
name|uConst
operator|%
name|constant
operator|.
name|uConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      TConstantUnion
name|operator
operator|>>
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|TConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|>>
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|returnValue
operator|.
name|setUConst
argument_list|(
name|uConst
operator|>>
name|constant
operator|.
name|uConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      TConstantUnion
name|operator
operator|<<
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|TConstantUnion
name|returnValue
block|;
comment|// The signedness of the second parameter might be different, but we
comment|// don't care, since the result is undefined if the second parameter is
comment|// negative, and aliasing should not be a problem with unions.
name|assert
argument_list|(
name|constant
operator|.
name|type
operator|==
name|EbtInt
operator|||
name|constant
operator|.
name|type
operator|==
name|EbtUInt
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|<<
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|returnValue
operator|.
name|setUConst
argument_list|(
name|uConst
operator|<<
name|constant
operator|.
name|uConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_decl_stmt
unit|}      TConstantUnion
name|operator
modifier|&
argument_list|(
specifier|const
name|TConstantUnion
operator|&
name|constant
argument_list|)
decl|const
block|{
name|TConstantUnion
name|returnValue
decl_stmt|;
name|assert
argument_list|(
name|constant
operator|.
name|type
operator|==
name|EbtInt
operator|||
name|constant
operator|.
name|type
operator|==
name|EbtUInt
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|&
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|returnValue
operator|.
name|setUConst
argument_list|(
name|uConst
operator|&
name|constant
operator|.
name|uConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
return|return
name|returnValue
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|TConstantUnion
name|operator
operator||
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|TConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator||
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|returnValue
operator|.
name|setUConst
argument_list|(
name|uConst
operator||
name|constant
operator|.
name|uConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_macro
unit|}      TConstantUnion
name|operator
end_macro
begin_expr_stmt
operator|^
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|TConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtInt
case|:
name|returnValue
operator|.
name|setIConst
argument_list|(
name|iConst
operator|^
name|constant
operator|.
name|iConst
argument_list|)
expr_stmt|;
break|break;
case|case
name|EbtUInt
case|:
name|returnValue
operator|.
name|setUConst
argument_list|(
name|uConst
operator|^
name|constant
operator|.
name|uConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      TConstantUnion
name|operator
operator|&&
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|TConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtBool
case|:
name|returnValue
operator|.
name|setBConst
argument_list|(
name|bConst
operator|&&
name|constant
operator|.
name|bConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_expr_stmt
unit|}      TConstantUnion
name|operator
operator|||
operator|(
specifier|const
name|TConstantUnion
operator|&
name|constant
operator|)
specifier|const
block|{
name|TConstantUnion
name|returnValue
block|;
name|assert
argument_list|(
name|type
operator|==
name|constant
operator|.
name|type
argument_list|)
block|;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|EbtBool
case|:
name|returnValue
operator|.
name|setBConst
argument_list|(
name|bConst
operator|||
name|constant
operator|.
name|bConst
argument_list|)
expr_stmt|;
break|break;
default|default:
name|assert
argument_list|(
name|false
operator|&&
literal|"Default missing"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|returnValue
return|;
end_return
begin_macro
unit|}      TBasicType
name|getType
argument_list|()
end_macro
begin_expr_stmt
specifier|const
block|{
return|return
name|type
return|;
block|}
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_union
union|union
block|{
name|int
name|iConst
decl_stmt|;
comment|// used for ivec, scalar ints
name|unsigned
name|int
name|uConst
decl_stmt|;
comment|// used for uvec, scalar uints
name|bool
name|bConst
decl_stmt|;
comment|// used for bvec, scalar bools
name|float
name|fConst
decl_stmt|;
comment|// used for vec, mat, scalar floats
block|}
union|;
end_union
begin_decl_stmt
name|TBasicType
name|type
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// COMPILER_TRANSLATOR_CONSTANTUNION_H_
end_comment
end_unit
