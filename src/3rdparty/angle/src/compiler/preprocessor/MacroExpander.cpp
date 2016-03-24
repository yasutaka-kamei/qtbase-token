begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2011 The ANGLE Project Authors. All rights reserved.
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
begin_include
include|#
directive|include
file|"MacroExpander.h"
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|<sstream>
end_include
begin_include
include|#
directive|include
file|"DiagnosticsBase.h"
end_include
begin_include
include|#
directive|include
file|"Token.h"
end_include
begin_namespace
DECL|namespace|pp
namespace|namespace
name|pp
block|{
DECL|class|TokenLexer
class|class
name|TokenLexer
super|:
specifier|public
name|Lexer
block|{
public|public:
DECL|typedef|TokenVector
typedef|typedef
name|std
operator|::
name|vector
argument_list|<
name|Token
argument_list|>
name|TokenVector
typedef|;
DECL|function|TokenLexer
name|TokenLexer
parameter_list|(
name|TokenVector
modifier|*
name|tokens
parameter_list|)
block|{
name|tokens
operator|->
name|swap
argument_list|(
name|mTokens
argument_list|)
expr_stmt|;
name|mIter
operator|=
name|mTokens
operator|.
name|begin
argument_list|()
expr_stmt|;
block|}
name|void
name|lex
parameter_list|(
name|Token
modifier|*
name|token
parameter_list|)
specifier|override
block|{
if|if
condition|(
name|mIter
operator|==
name|mTokens
operator|.
name|end
argument_list|()
condition|)
block|{
name|token
operator|->
name|reset
argument_list|()
expr_stmt|;
name|token
operator|->
name|type
operator|=
name|Token
operator|::
name|LAST
expr_stmt|;
block|}
else|else
block|{
operator|*
name|token
operator|=
operator|*
name|mIter
operator|++
expr_stmt|;
block|}
block|}
private|private:
name|PP_DISALLOW_COPY_AND_ASSIGN
parameter_list|(
name|TokenLexer
parameter_list|)
constructor_decl|;
DECL|member|mTokens
name|TokenVector
name|mTokens
decl_stmt|;
DECL|member|mIter
name|TokenVector
operator|::
name|const_iterator
name|mIter
decl_stmt|;
block|}
class|;
DECL|function|MacroExpander
name|MacroExpander
operator|::
name|MacroExpander
parameter_list|(
name|Lexer
modifier|*
name|lexer
parameter_list|,
name|MacroSet
modifier|*
name|macroSet
parameter_list|,
name|Diagnostics
modifier|*
name|diagnostics
parameter_list|,
name|bool
name|parseDefined
parameter_list|)
member_init_list|:
name|mLexer
argument_list|(
name|lexer
argument_list|)
member_init_list|,
name|mMacroSet
argument_list|(
name|macroSet
argument_list|)
member_init_list|,
name|mDiagnostics
argument_list|(
name|diagnostics
argument_list|)
member_init_list|,
name|mParseDefined
argument_list|(
name|parseDefined
argument_list|)
block|{ }
DECL|function|~MacroExpander
name|MacroExpander
operator|::
name|~
name|MacroExpander
parameter_list|()
block|{
for|for
control|(
name|std
operator|::
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mContextStack
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
operator|delete
name|mContextStack
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
DECL|function|lex
name|void
name|MacroExpander
operator|::
name|lex
parameter_list|(
name|Token
modifier|*
name|token
parameter_list|)
block|{
while|while
condition|(
literal|true
condition|)
block|{
specifier|const
name|char
name|kDefined
index|[]
init|=
literal|"defined"
decl_stmt|;
name|getToken
argument_list|(
name|token
argument_list|)
expr_stmt|;
if|if
condition|(
name|token
operator|->
name|type
operator|!=
name|Token
operator|::
name|IDENTIFIER
condition|)
break|break;
comment|// Defined operator is parsed here since it may be generated by macro expansion.
comment|// Defined operator produced by macro expansion has undefined behavior according to C++
comment|// spec, which the GLSL spec references (see C++14 draft spec section 16.1.4), but this
comment|// behavior is needed for passing dEQP tests, which enforce stricter compatibility between
comment|// implementations.
if|if
condition|(
name|mParseDefined
operator|&&
name|token
operator|->
name|text
operator|==
name|kDefined
condition|)
block|{
name|bool
name|paren
init|=
literal|false
decl_stmt|;
name|getToken
argument_list|(
name|token
argument_list|)
expr_stmt|;
if|if
condition|(
name|token
operator|->
name|type
operator|==
literal|'('
condition|)
block|{
name|paren
operator|=
literal|true
expr_stmt|;
name|getToken
argument_list|(
name|token
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|token
operator|->
name|type
operator|!=
name|Token
operator|::
name|IDENTIFIER
condition|)
block|{
name|mDiagnostics
operator|->
name|report
argument_list|(
name|Diagnostics
operator|::
name|PP_UNEXPECTED_TOKEN
argument_list|,
name|token
operator|->
name|location
argument_list|,
name|token
operator|->
name|text
argument_list|)
expr_stmt|;
break|break;
block|}
name|auto
name|iter
init|=
name|mMacroSet
operator|->
name|find
argument_list|(
name|token
operator|->
name|text
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|expression
init|=
name|iter
operator|!=
name|mMacroSet
operator|->
name|end
argument_list|()
condition|?
literal|"1"
else|:
literal|"0"
decl_stmt|;
if|if
condition|(
name|paren
condition|)
block|{
name|getToken
argument_list|(
name|token
argument_list|)
expr_stmt|;
if|if
condition|(
name|token
operator|->
name|type
operator|!=
literal|')'
condition|)
block|{
name|mDiagnostics
operator|->
name|report
argument_list|(
name|Diagnostics
operator|::
name|PP_UNEXPECTED_TOKEN
argument_list|,
name|token
operator|->
name|location
argument_list|,
name|token
operator|->
name|text
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|// We have a valid defined operator.
comment|// Convert the current token into a CONST_INT token.
name|token
operator|->
name|type
operator|=
name|Token
operator|::
name|CONST_INT
expr_stmt|;
name|token
operator|->
name|text
operator|=
name|expression
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|token
operator|->
name|expansionDisabled
argument_list|()
condition|)
break|break;
name|MacroSet
operator|::
name|const_iterator
name|iter
init|=
name|mMacroSet
operator|->
name|find
argument_list|(
name|token
operator|->
name|text
argument_list|)
decl_stmt|;
if|if
condition|(
name|iter
operator|==
name|mMacroSet
operator|->
name|end
argument_list|()
condition|)
break|break;
specifier|const
name|Macro
modifier|&
name|macro
init|=
name|iter
operator|->
name|second
decl_stmt|;
if|if
condition|(
name|macro
operator|.
name|disabled
condition|)
block|{
comment|// If a particular token is not expanded, it is never expanded.
name|token
operator|->
name|setExpansionDisabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
operator|(
name|macro
operator|.
name|type
operator|==
name|Macro
operator|::
name|kTypeFunc
operator|)
operator|&&
operator|!
name|isNextTokenLeftParen
argument_list|()
condition|)
block|{
comment|// If the token immediately after the macro name is not a '(',
comment|// this macro should not be expanded.
break|break;
block|}
name|pushMacro
argument_list|(
name|macro
argument_list|,
operator|*
name|token
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|getToken
name|void
name|MacroExpander
operator|::
name|getToken
parameter_list|(
name|Token
modifier|*
name|token
parameter_list|)
block|{
if|if
condition|(
name|mReserveToken
operator|.
name|get
argument_list|()
condition|)
block|{
operator|*
name|token
operator|=
operator|*
name|mReserveToken
expr_stmt|;
name|mReserveToken
operator|.
name|reset
argument_list|()
expr_stmt|;
return|return;
block|}
comment|// First pop all empty macro contexts.
while|while
condition|(
operator|!
name|mContextStack
operator|.
name|empty
argument_list|()
operator|&&
name|mContextStack
operator|.
name|back
argument_list|()
operator|->
name|empty
argument_list|()
condition|)
block|{
name|popMacro
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|mContextStack
operator|.
name|empty
argument_list|()
condition|)
block|{
operator|*
name|token
operator|=
name|mContextStack
operator|.
name|back
argument_list|()
operator|->
name|get
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|mLexer
operator|->
name|lex
argument_list|(
name|token
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|ungetToken
name|void
name|MacroExpander
operator|::
name|ungetToken
parameter_list|(
specifier|const
name|Token
modifier|&
name|token
parameter_list|)
block|{
if|if
condition|(
operator|!
name|mContextStack
operator|.
name|empty
argument_list|()
condition|)
block|{
name|MacroContext
modifier|*
name|context
init|=
name|mContextStack
operator|.
name|back
argument_list|()
decl_stmt|;
name|context
operator|->
name|unget
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|context
operator|->
name|replacements
index|[
name|context
operator|->
name|index
index|]
operator|==
name|token
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|assert
argument_list|(
operator|!
name|mReserveToken
operator|.
name|get
argument_list|()
argument_list|)
expr_stmt|;
name|mReserveToken
operator|.
name|reset
argument_list|(
operator|new
name|Token
argument_list|(
name|token
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|isNextTokenLeftParen
name|bool
name|MacroExpander
operator|::
name|isNextTokenLeftParen
parameter_list|()
block|{
name|Token
name|token
decl_stmt|;
name|getToken
argument_list|(
operator|&
name|token
argument_list|)
expr_stmt|;
name|bool
name|lparen
init|=
name|token
operator|.
name|type
operator|==
literal|'('
decl_stmt|;
name|ungetToken
argument_list|(
name|token
argument_list|)
expr_stmt|;
return|return
name|lparen
return|;
block|}
DECL|function|pushMacro
name|bool
name|MacroExpander
operator|::
name|pushMacro
parameter_list|(
specifier|const
name|Macro
modifier|&
name|macro
parameter_list|,
specifier|const
name|Token
modifier|&
name|identifier
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|macro
operator|.
name|disabled
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|identifier
operator|.
name|expansionDisabled
argument_list|()
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|identifier
operator|.
name|type
operator|==
name|Token
operator|::
name|IDENTIFIER
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|identifier
operator|.
name|text
operator|==
name|macro
operator|.
name|name
argument_list|)
expr_stmt|;
name|std
operator|::
name|vector
argument_list|<
name|Token
argument_list|>
name|replacements
decl_stmt|;
if|if
condition|(
operator|!
name|expandMacro
argument_list|(
name|macro
argument_list|,
name|identifier
argument_list|,
operator|&
name|replacements
argument_list|)
condition|)
return|return
literal|false
return|;
comment|// Macro is disabled for expansion until it is popped off the stack.
name|macro
operator|.
name|disabled
operator|=
literal|true
expr_stmt|;
name|MacroContext
modifier|*
name|context
init|=
operator|new
name|MacroContext
decl_stmt|;
name|context
operator|->
name|macro
operator|=
operator|&
name|macro
expr_stmt|;
name|context
operator|->
name|replacements
operator|.
name|swap
argument_list|(
name|replacements
argument_list|)
expr_stmt|;
name|mContextStack
operator|.
name|push_back
argument_list|(
name|context
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
DECL|function|popMacro
name|void
name|MacroExpander
operator|::
name|popMacro
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|mContextStack
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|MacroContext
modifier|*
name|context
init|=
name|mContextStack
operator|.
name|back
argument_list|()
decl_stmt|;
name|mContextStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|context
operator|->
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|context
operator|->
name|macro
operator|->
name|disabled
argument_list|)
expr_stmt|;
name|context
operator|->
name|macro
operator|->
name|disabled
operator|=
literal|false
expr_stmt|;
operator|delete
name|context
expr_stmt|;
block|}
DECL|function|expandMacro
name|bool
name|MacroExpander
operator|::
name|expandMacro
parameter_list|(
specifier|const
name|Macro
modifier|&
name|macro
parameter_list|,
specifier|const
name|Token
modifier|&
name|identifier
parameter_list|,
name|std
operator|::
name|vector
argument_list|<
name|Token
argument_list|>
modifier|*
name|replacements
parameter_list|)
block|{
name|replacements
operator|->
name|clear
argument_list|()
expr_stmt|;
comment|// In the case of an object-like macro, the replacement list gets its location
comment|// from the identifier, but in the case of a function-like macro, the replacement
comment|// list gets its location from the closing parenthesis of the macro invocation.
comment|// This is tested by dEQP-GLES3.functional.shaders.preprocessor.predefined_macros.*
name|SourceLocation
name|replacementLocation
init|=
name|identifier
operator|.
name|location
decl_stmt|;
if|if
condition|(
name|macro
operator|.
name|type
operator|==
name|Macro
operator|::
name|kTypeObj
condition|)
block|{
name|replacements
operator|->
name|assign
argument_list|(
name|macro
operator|.
name|replacements
operator|.
name|begin
argument_list|()
argument_list|,
name|macro
operator|.
name|replacements
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|macro
operator|.
name|predefined
condition|)
block|{
specifier|const
name|char
name|kLine
index|[]
init|=
literal|"__LINE__"
decl_stmt|;
specifier|const
name|char
name|kFile
index|[]
init|=
literal|"__FILE__"
decl_stmt|;
name|assert
argument_list|(
name|replacements
operator|->
name|size
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
name|Token
modifier|&
name|repl
init|=
name|replacements
operator|->
name|front
argument_list|()
decl_stmt|;
if|if
condition|(
name|macro
operator|.
name|name
operator|==
name|kLine
condition|)
block|{
name|std
operator|::
name|ostringstream
name|stream
decl_stmt|;
name|stream
operator|<<
name|identifier
operator|.
name|location
operator|.
name|line
expr_stmt|;
name|repl
operator|.
name|text
operator|=
name|stream
operator|.
name|str
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|macro
operator|.
name|name
operator|==
name|kFile
condition|)
block|{
name|std
operator|::
name|ostringstream
name|stream
decl_stmt|;
name|stream
operator|<<
name|identifier
operator|.
name|location
operator|.
name|file
expr_stmt|;
name|repl
operator|.
name|text
operator|=
name|stream
operator|.
name|str
argument_list|()
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|assert
argument_list|(
name|macro
operator|.
name|type
operator|==
name|Macro
operator|::
name|kTypeFunc
argument_list|)
expr_stmt|;
name|std
operator|::
name|vector
argument_list|<
name|MacroArg
argument_list|>
name|args
decl_stmt|;
name|args
operator|.
name|reserve
argument_list|(
name|macro
operator|.
name|parameters
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|collectMacroArgs
argument_list|(
name|macro
argument_list|,
name|identifier
argument_list|,
operator|&
name|args
argument_list|,
operator|&
name|replacementLocation
argument_list|)
condition|)
return|return
literal|false
return|;
name|replaceMacroParams
argument_list|(
name|macro
argument_list|,
name|args
argument_list|,
name|replacements
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|std
operator|::
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|replacements
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|Token
modifier|&
name|repl
init|=
name|replacements
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
block|{
comment|// The first token in the replacement list inherits the padding
comment|// properties of the identifier token.
name|repl
operator|.
name|setAtStartOfLine
argument_list|(
name|identifier
operator|.
name|atStartOfLine
argument_list|()
argument_list|)
expr_stmt|;
name|repl
operator|.
name|setHasLeadingSpace
argument_list|(
name|identifier
operator|.
name|hasLeadingSpace
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|repl
operator|.
name|location
operator|=
name|replacementLocation
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
DECL|function|collectMacroArgs
name|bool
name|MacroExpander
operator|::
name|collectMacroArgs
parameter_list|(
specifier|const
name|Macro
modifier|&
name|macro
parameter_list|,
specifier|const
name|Token
modifier|&
name|identifier
parameter_list|,
name|std
operator|::
name|vector
argument_list|<
name|MacroArg
argument_list|>
modifier|*
name|args
parameter_list|,
name|SourceLocation
modifier|*
name|closingParenthesisLocation
parameter_list|)
block|{
name|Token
name|token
decl_stmt|;
name|getToken
argument_list|(
operator|&
name|token
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|token
operator|.
name|type
operator|==
literal|'('
argument_list|)
expr_stmt|;
name|args
operator|->
name|push_back
argument_list|(
name|MacroArg
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|openParens
init|=
literal|1
init|;
name|openParens
operator|!=
literal|0
condition|;
control|)
block|{
name|getToken
argument_list|(
operator|&
name|token
argument_list|)
expr_stmt|;
if|if
condition|(
name|token
operator|.
name|type
operator|==
name|Token
operator|::
name|LAST
condition|)
block|{
name|mDiagnostics
operator|->
name|report
argument_list|(
name|Diagnostics
operator|::
name|PP_MACRO_UNTERMINATED_INVOCATION
argument_list|,
name|identifier
operator|.
name|location
argument_list|,
name|identifier
operator|.
name|text
argument_list|)
expr_stmt|;
comment|// Do not lose EOF token.
name|ungetToken
argument_list|(
name|token
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|bool
name|isArg
init|=
literal|false
decl_stmt|;
comment|// True if token is part of the current argument.
switch|switch
condition|(
name|token
operator|.
name|type
condition|)
block|{
case|case
literal|'('
case|:
operator|++
name|openParens
expr_stmt|;
name|isArg
operator|=
literal|true
expr_stmt|;
break|break;
case|case
literal|')'
case|:
operator|--
name|openParens
expr_stmt|;
name|isArg
operator|=
name|openParens
operator|!=
literal|0
expr_stmt|;
operator|*
name|closingParenthesisLocation
operator|=
name|token
operator|.
name|location
expr_stmt|;
break|break;
case|case
literal|','
case|:
comment|// The individual arguments are separated by comma tokens, but
comment|// the comma tokens between matching inner parentheses do not
comment|// seperate arguments.
if|if
condition|(
name|openParens
operator|==
literal|1
condition|)
name|args
operator|->
name|push_back
argument_list|(
name|MacroArg
argument_list|()
argument_list|)
expr_stmt|;
name|isArg
operator|=
name|openParens
operator|!=
literal|1
expr_stmt|;
break|break;
default|default:
name|isArg
operator|=
literal|true
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|isArg
condition|)
block|{
name|MacroArg
modifier|&
name|arg
init|=
name|args
operator|->
name|back
argument_list|()
decl_stmt|;
comment|// Initial whitespace is not part of the argument.
if|if
condition|(
name|arg
operator|.
name|empty
argument_list|()
condition|)
name|token
operator|.
name|setHasLeadingSpace
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|arg
operator|.
name|push_back
argument_list|(
name|token
argument_list|)
expr_stmt|;
block|}
block|}
specifier|const
name|Macro
operator|::
name|Parameters
modifier|&
name|params
init|=
name|macro
operator|.
name|parameters
decl_stmt|;
comment|// If there is only one empty argument, it is equivalent to no argument.
if|if
condition|(
name|params
operator|.
name|empty
argument_list|()
operator|&&
operator|(
name|args
operator|->
name|size
argument_list|()
operator|==
literal|1
operator|)
operator|&&
name|args
operator|->
name|front
argument_list|()
operator|.
name|empty
argument_list|()
condition|)
block|{
name|args
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
comment|// Validate the number of arguments.
if|if
condition|(
name|args
operator|->
name|size
argument_list|()
operator|!=
name|params
operator|.
name|size
argument_list|()
condition|)
block|{
name|Diagnostics
operator|::
name|ID
name|id
init|=
name|args
operator|->
name|size
argument_list|()
operator|<
name|macro
operator|.
name|parameters
operator|.
name|size
argument_list|()
condition|?
name|Diagnostics
operator|::
name|PP_MACRO_TOO_FEW_ARGS
else|:
name|Diagnostics
operator|::
name|PP_MACRO_TOO_MANY_ARGS
decl_stmt|;
name|mDiagnostics
operator|->
name|report
argument_list|(
name|id
argument_list|,
name|identifier
operator|.
name|location
argument_list|,
name|identifier
operator|.
name|text
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Pre-expand each argument before substitution.
comment|// This step expands each argument individually before they are
comment|// inserted into the macro body.
for|for
control|(
name|std
operator|::
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|args
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|MacroArg
modifier|&
name|arg
init|=
name|args
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|TokenLexer
name|lexer
argument_list|(
operator|&
name|arg
argument_list|)
decl_stmt|;
name|MacroExpander
name|expander
argument_list|(
operator|&
name|lexer
argument_list|,
name|mMacroSet
argument_list|,
name|mDiagnostics
argument_list|,
name|mParseDefined
argument_list|)
decl_stmt|;
name|arg
operator|.
name|clear
argument_list|()
expr_stmt|;
name|expander
operator|.
name|lex
argument_list|(
operator|&
name|token
argument_list|)
expr_stmt|;
while|while
condition|(
name|token
operator|.
name|type
operator|!=
name|Token
operator|::
name|LAST
condition|)
block|{
name|arg
operator|.
name|push_back
argument_list|(
name|token
argument_list|)
expr_stmt|;
name|expander
operator|.
name|lex
argument_list|(
operator|&
name|token
argument_list|)
expr_stmt|;
block|}
block|}
return|return
literal|true
return|;
block|}
DECL|function|replaceMacroParams
name|void
name|MacroExpander
operator|::
name|replaceMacroParams
parameter_list|(
specifier|const
name|Macro
modifier|&
name|macro
parameter_list|,
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|MacroArg
argument_list|>
modifier|&
name|args
parameter_list|,
name|std
operator|::
name|vector
argument_list|<
name|Token
argument_list|>
modifier|*
name|replacements
parameter_list|)
block|{
for|for
control|(
name|std
operator|::
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|macro
operator|.
name|replacements
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|Token
modifier|&
name|repl
init|=
name|macro
operator|.
name|replacements
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|repl
operator|.
name|type
operator|!=
name|Token
operator|::
name|IDENTIFIER
condition|)
block|{
name|replacements
operator|->
name|push_back
argument_list|(
name|repl
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|// TODO(alokp): Optimize this.
comment|// There is no need to search for macro params every time.
comment|// The param index can be cached with the replacement token.
name|Macro
operator|::
name|Parameters
operator|::
name|const_iterator
name|iter
init|=
name|std
operator|::
name|find
argument_list|(
name|macro
operator|.
name|parameters
operator|.
name|begin
argument_list|()
argument_list|,
name|macro
operator|.
name|parameters
operator|.
name|end
argument_list|()
argument_list|,
name|repl
operator|.
name|text
argument_list|)
decl_stmt|;
if|if
condition|(
name|iter
operator|==
name|macro
operator|.
name|parameters
operator|.
name|end
argument_list|()
condition|)
block|{
name|replacements
operator|->
name|push_back
argument_list|(
name|repl
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|std
operator|::
name|size_t
name|iArg
init|=
name|std
operator|::
name|distance
argument_list|(
name|macro
operator|.
name|parameters
operator|.
name|begin
argument_list|()
argument_list|,
name|iter
argument_list|)
decl_stmt|;
specifier|const
name|MacroArg
modifier|&
name|arg
init|=
name|args
index|[
name|iArg
index|]
decl_stmt|;
if|if
condition|(
name|arg
operator|.
name|empty
argument_list|()
condition|)
block|{
continue|continue;
block|}
name|std
operator|::
name|size_t
name|iRepl
init|=
name|replacements
operator|->
name|size
argument_list|()
decl_stmt|;
name|replacements
operator|->
name|insert
argument_list|(
name|replacements
operator|->
name|end
argument_list|()
argument_list|,
name|arg
operator|.
name|begin
argument_list|()
argument_list|,
name|arg
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
comment|// The replacement token inherits padding properties from
comment|// macro replacement token.
name|replacements
operator|->
name|at
argument_list|(
name|iRepl
argument_list|)
operator|.
name|setHasLeadingSpace
argument_list|(
name|repl
operator|.
name|hasLeadingSpace
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_namespace
begin_comment
comment|// namespace pp
end_comment
end_unit
