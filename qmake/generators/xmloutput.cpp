begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"xmloutput.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|XmlOutput
name|XmlOutput
operator|::
name|XmlOutput
parameter_list|(
name|QTextStream
modifier|&
name|file
parameter_list|,
name|ConverstionType
name|type
parameter_list|)
member_init_list|:
name|xmlFile
argument_list|(
name|file
argument_list|)
member_init_list|,
name|indent
argument_list|(
literal|"\t"
argument_list|)
member_init_list|,
name|currentLevel
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|currentState
argument_list|(
name|Bare
argument_list|)
member_init_list|,
name|format
argument_list|(
name|NewLine
argument_list|)
member_init_list|,
name|conversion
argument_list|(
name|type
argument_list|)
block|{
name|tagStack
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~XmlOutput
name|XmlOutput
operator|::
name|~
name|XmlOutput
parameter_list|()
block|{
name|closeAll
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|// Settings ------------------------------------------------------------------
end_comment
begin_function
DECL|function|setIndentString
name|void
name|XmlOutput
operator|::
name|setIndentString
parameter_list|(
specifier|const
name|QString
modifier|&
name|indentString
parameter_list|)
block|{
name|indent
operator|=
name|indentString
expr_stmt|;
block|}
end_function
begin_function
DECL|function|indentString
name|QString
name|XmlOutput
operator|::
name|indentString
parameter_list|()
block|{
return|return
name|indent
return|;
block|}
end_function
begin_function
DECL|function|setIndentLevel
name|void
name|XmlOutput
operator|::
name|setIndentLevel
parameter_list|(
name|int
name|level
parameter_list|)
block|{
name|currentLevel
operator|=
name|level
expr_stmt|;
block|}
end_function
begin_function
DECL|function|indentLevel
name|int
name|XmlOutput
operator|::
name|indentLevel
parameter_list|()
block|{
return|return
name|currentLevel
return|;
block|}
end_function
begin_function
DECL|function|setState
name|void
name|XmlOutput
operator|::
name|setState
parameter_list|(
name|XMLState
name|state
parameter_list|)
block|{
name|currentState
operator|=
name|state
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setFormat
name|void
name|XmlOutput
operator|::
name|setFormat
parameter_list|(
name|XMLFormat
name|newFormat
parameter_list|)
block|{
name|format
operator|=
name|newFormat
expr_stmt|;
block|}
end_function
begin_function
DECL|function|state
name|XmlOutput
operator|::
name|XMLState
name|XmlOutput
operator|::
name|state
parameter_list|()
block|{
return|return
name|currentState
return|;
block|}
end_function
begin_function
DECL|function|updateIndent
name|void
name|XmlOutput
operator|::
name|updateIndent
parameter_list|()
block|{
name|currentIndent
operator|.
name|clear
argument_list|()
expr_stmt|;
name|currentIndent
operator|.
name|reserve
argument_list|(
name|currentLevel
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|currentLevel
condition|;
operator|++
name|i
control|)
name|currentIndent
operator|.
name|append
argument_list|(
name|indent
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|increaseIndent
name|void
name|XmlOutput
operator|::
name|increaseIndent
parameter_list|()
block|{
operator|++
name|currentLevel
expr_stmt|;
name|updateIndent
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|decreaseIndent
name|void
name|XmlOutput
operator|::
name|decreaseIndent
parameter_list|()
block|{
if|if
condition|(
name|currentLevel
condition|)
operator|--
name|currentLevel
expr_stmt|;
name|updateIndent
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|currentLevel
condition|)
name|currentState
operator|=
name|Bare
expr_stmt|;
block|}
end_function
begin_function
DECL|function|doConversion
name|QString
name|XmlOutput
operator|::
name|doConversion
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
if|if
condition|(
operator|!
name|text
operator|.
name|count
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
elseif|else
if|if
condition|(
name|conversion
operator|==
name|NoConversion
condition|)
return|return
name|text
return|;
name|QString
name|output
decl_stmt|;
if|if
condition|(
name|conversion
operator|==
name|XMLConversion
condition|)
block|{
comment|// this is a way to escape characters that shouldn't be converted
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|text
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|text
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'&'
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|i
operator|+
literal|7
operator|)
operator|<
name|text
operator|.
name|count
argument_list|()
operator|&&
name|text
operator|.
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'#'
argument_list|)
operator|&&
name|text
operator|.
name|at
argument_list|(
name|i
operator|+
literal|2
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'x'
argument_list|)
operator|&&
name|text
operator|.
name|at
argument_list|(
name|i
operator|+
literal|7
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|';'
argument_list|)
condition|)
block|{
name|output
operator|+=
name|text
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|output
operator|+=
name|QLatin1String
argument_list|(
literal|"&amp;"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|QChar
name|c
init|=
name|text
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|c
operator|.
name|unicode
argument_list|()
operator|<
literal|0x20
condition|)
block|{
name|output
operator|+=
name|QString
argument_list|(
literal|"&#x%1;"
argument_list|)
operator|.
name|arg
argument_list|(
name|c
operator|.
name|unicode
argument_list|()
argument_list|,
literal|2
argument_list|,
literal|16
argument_list|,
name|QLatin1Char
argument_list|(
literal|'0'
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|output
operator|+=
name|text
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
else|else
block|{
name|output
operator|=
name|text
expr_stmt|;
block|}
if|if
condition|(
name|conversion
operator|==
name|XMLConversion
condition|)
block|{
name|output
operator|.
name|replace
argument_list|(
literal|'\"'
argument_list|,
name|QLatin1String
argument_list|(
literal|"&quot;"
argument_list|)
argument_list|)
expr_stmt|;
name|output
operator|.
name|replace
argument_list|(
literal|'\''
argument_list|,
name|QLatin1String
argument_list|(
literal|"&apos;"
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|conversion
operator|==
name|EscapeConversion
condition|)
block|{
name|output
operator|.
name|replace
argument_list|(
literal|'\"'
argument_list|,
name|QLatin1String
argument_list|(
literal|"\\\""
argument_list|)
argument_list|)
expr_stmt|;
name|output
operator|.
name|replace
argument_list|(
literal|'\''
argument_list|,
name|QLatin1String
argument_list|(
literal|"\\\'"
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|output
return|;
block|}
end_function
begin_comment
comment|// Stream functions ----------------------------------------------------------
end_comment
begin_function
DECL|function|operator <<
name|XmlOutput
modifier|&
name|XmlOutput
operator|::
name|operator
name|<<
parameter_list|(
specifier|const
name|QString
modifier|&
name|o
parameter_list|)
block|{
return|return
name|operator
name|<<
argument_list|(
name|data
argument_list|(
name|o
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|XmlOutput
modifier|&
name|XmlOutput
operator|::
name|operator
name|<<
parameter_list|(
specifier|const
name|xml_output
modifier|&
name|o
parameter_list|)
block|{
switch|switch
condition|(
name|o
operator|.
name|xo_type
condition|)
block|{
case|case
name|tNothing
case|:
break|break;
case|case
name|tRaw
case|:
name|addRaw
argument_list|(
name|o
operator|.
name|xo_text
argument_list|)
expr_stmt|;
break|break;
case|case
name|tDeclaration
case|:
name|addDeclaration
argument_list|(
name|o
operator|.
name|xo_text
argument_list|,
name|o
operator|.
name|xo_value
argument_list|)
expr_stmt|;
break|break;
case|case
name|tTag
case|:
name|newTagOpen
argument_list|(
name|o
operator|.
name|xo_text
argument_list|)
expr_stmt|;
break|break;
case|case
name|tTagValue
case|:
name|addRaw
argument_list|(
name|QString
argument_list|(
literal|"\n%1<%2>"
argument_list|)
operator|.
name|arg
argument_list|(
name|currentIndent
argument_list|)
operator|.
name|arg
argument_list|(
name|o
operator|.
name|xo_text
argument_list|)
argument_list|)
expr_stmt|;
name|addRaw
argument_list|(
name|doConversion
argument_list|(
name|o
operator|.
name|xo_value
argument_list|)
argument_list|)
expr_stmt|;
name|addRaw
argument_list|(
name|QString
argument_list|(
literal|"</%1>"
argument_list|)
operator|.
name|arg
argument_list|(
name|o
operator|.
name|xo_text
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|tValueTag
case|:
name|addRaw
argument_list|(
name|doConversion
argument_list|(
name|o
operator|.
name|xo_text
argument_list|)
argument_list|)
expr_stmt|;
name|setFormat
argument_list|(
name|NoNewLine
argument_list|)
expr_stmt|;
name|closeTag
argument_list|()
expr_stmt|;
name|setFormat
argument_list|(
name|NewLine
argument_list|)
expr_stmt|;
break|break;
case|case
name|tImport
case|:
name|addRaw
argument_list|(
name|QString
argument_list|(
literal|"\n%1<Import %2=\"%3\" />"
argument_list|)
operator|.
name|arg
argument_list|(
name|currentIndent
argument_list|)
operator|.
name|arg
argument_list|(
name|o
operator|.
name|xo_text
argument_list|)
operator|.
name|arg
argument_list|(
name|o
operator|.
name|xo_value
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|tCloseTag
case|:
if|if
condition|(
name|o
operator|.
name|xo_value
operator|.
name|count
argument_list|()
condition|)
name|closeAll
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|o
operator|.
name|xo_text
operator|.
name|count
argument_list|()
condition|)
name|closeTo
argument_list|(
name|o
operator|.
name|xo_text
argument_list|)
expr_stmt|;
else|else
name|closeTag
argument_list|()
expr_stmt|;
break|break;
case|case
name|tAttribute
case|:
name|addAttribute
argument_list|(
name|o
operator|.
name|xo_text
argument_list|,
name|o
operator|.
name|xo_value
argument_list|)
expr_stmt|;
break|break;
case|case
name|tAttributeTag
case|:
name|addAttributeTag
argument_list|(
name|o
operator|.
name|xo_text
argument_list|,
name|o
operator|.
name|xo_value
argument_list|)
expr_stmt|;
break|break;
case|case
name|tData
case|:
block|{
comment|// Special case to be able to close tag in normal
comment|// way ("</tag>", not "/>") without using addRaw()..
if|if
condition|(
operator|!
name|o
operator|.
name|xo_text
operator|.
name|count
argument_list|()
condition|)
block|{
name|closeOpen
argument_list|()
expr_stmt|;
break|break;
block|}
name|QString
name|output
init|=
name|doConversion
argument_list|(
name|o
operator|.
name|xo_text
argument_list|)
decl_stmt|;
name|output
operator|.
name|replace
argument_list|(
literal|'\n'
argument_list|,
literal|"\n"
operator|+
name|currentIndent
argument_list|)
expr_stmt|;
name|addRaw
argument_list|(
name|QString
argument_list|(
literal|"\n%1%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|currentIndent
argument_list|)
operator|.
name|arg
argument_list|(
name|output
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|tComment
case|:
block|{
name|QString
name|output
argument_list|(
literal|"<!--%1-->"
argument_list|)
decl_stmt|;
name|addRaw
argument_list|(
name|output
operator|.
name|arg
argument_list|(
name|o
operator|.
name|xo_text
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|tCDATA
case|:
block|{
name|QString
name|output
argument_list|(
literal|"<![CDATA[\n%1\n]]>"
argument_list|)
decl_stmt|;
name|addRaw
argument_list|(
name|output
operator|.
name|arg
argument_list|(
name|o
operator|.
name|xo_text
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|// Output functions ----------------------------------------------------------
end_comment
begin_function
DECL|function|newTag
name|void
name|XmlOutput
operator|::
name|newTag
parameter_list|(
specifier|const
name|QString
modifier|&
name|tag
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|tag
operator|.
name|count
argument_list|()
argument_list|,
literal|"XmlOutput"
argument_list|,
literal|"Cannot open an empty tag"
argument_list|)
expr_stmt|;
name|newTagOpen
argument_list|(
name|tag
argument_list|)
expr_stmt|;
name|closeOpen
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|newTagOpen
name|void
name|XmlOutput
operator|::
name|newTagOpen
parameter_list|(
specifier|const
name|QString
modifier|&
name|tag
parameter_list|)
block|{
name|Q_ASSERT_X
argument_list|(
name|tag
operator|.
name|count
argument_list|()
argument_list|,
literal|"XmlOutput"
argument_list|,
literal|"Cannot open an empty tag"
argument_list|)
expr_stmt|;
name|closeOpen
argument_list|()
expr_stmt|;
if|if
condition|(
name|format
operator|==
name|NewLine
condition|)
name|xmlFile
operator|<<
name|endl
operator|<<
name|currentIndent
expr_stmt|;
name|xmlFile
operator|<<
literal|'<'
operator|<<
name|doConversion
argument_list|(
name|tag
argument_list|)
expr_stmt|;
name|currentState
operator|=
name|Attribute
expr_stmt|;
name|tagStack
operator|.
name|append
argument_list|(
name|tag
argument_list|)
expr_stmt|;
name|increaseIndent
argument_list|()
expr_stmt|;
comment|// ---> indent
block|}
end_function
begin_function
DECL|function|closeOpen
name|void
name|XmlOutput
operator|::
name|closeOpen
parameter_list|()
block|{
switch|switch
condition|(
name|currentState
condition|)
block|{
case|case
name|Bare
case|:
case|case
name|Tag
case|:
return|return;
case|case
name|Attribute
case|:
break|break;
block|}
name|xmlFile
operator|<<
literal|'>'
expr_stmt|;
name|currentState
operator|=
name|Tag
expr_stmt|;
block|}
end_function
begin_function
DECL|function|closeTag
name|void
name|XmlOutput
operator|::
name|closeTag
parameter_list|()
block|{
switch|switch
condition|(
name|currentState
condition|)
block|{
case|case
name|Bare
case|:
if|if
condition|(
name|tagStack
operator|.
name|count
argument_list|()
condition|)
comment|//warn_msg(WarnLogic, "<Root>: Cannot close tag in Bare state, %d tags on stack", tagStack.count());
name|qDebug
argument_list|(
literal|"<Root>: Cannot close tag in Bare state, %d tags on stack"
argument_list|,
name|tagStack
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
else|else
comment|//warn_msg(WarnLogic, "<Root>: Cannot close tag, no tags on stack");
name|qDebug
argument_list|(
literal|"<Root>: Cannot close tag, no tags on stack"
argument_list|)
expr_stmt|;
return|return;
case|case
name|Tag
case|:
name|decreaseIndent
argument_list|()
expr_stmt|;
comment|//<--- Pre-decrease indent
if|if
condition|(
name|format
operator|==
name|NewLine
condition|)
name|xmlFile
operator|<<
name|endl
operator|<<
name|currentIndent
expr_stmt|;
name|xmlFile
operator|<<
literal|"</"
operator|<<
name|doConversion
argument_list|(
name|tagStack
operator|.
name|last
argument_list|()
argument_list|)
operator|<<
literal|'>'
expr_stmt|;
name|tagStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
break|break;
case|case
name|Attribute
case|:
name|xmlFile
operator|<<
literal|" />"
expr_stmt|;
name|tagStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|currentState
operator|=
name|Tag
expr_stmt|;
name|decreaseIndent
argument_list|()
expr_stmt|;
comment|//<--- Post-decrease indent
break|break;
block|}
block|}
end_function
begin_function
DECL|function|closeTo
name|void
name|XmlOutput
operator|::
name|closeTo
parameter_list|(
specifier|const
name|QString
modifier|&
name|tag
parameter_list|)
block|{
name|bool
name|cont
init|=
literal|true
decl_stmt|;
if|if
condition|(
operator|!
name|tagStack
operator|.
name|contains
argument_list|(
name|tag
argument_list|)
operator|&&
operator|!
name|tag
operator|.
name|isNull
argument_list|()
condition|)
block|{
comment|//warn_msg(WarnLogic, "<%s>: Cannot close to tag<%s>, not on stack", tagStack.last().latin1(), tag.latin1());
name|qDebug
argument_list|(
literal|"<%s>: Cannot close to tag<%s>, not on stack"
argument_list|,
name|tagStack
operator|.
name|last
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|tag
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|int
name|left
init|=
name|tagStack
operator|.
name|count
argument_list|()
decl_stmt|;
while|while
condition|(
name|left
operator|--
operator|&&
name|cont
condition|)
block|{
name|cont
operator|=
name|tagStack
operator|.
name|last
argument_list|()
operator|.
name|compare
argument_list|(
name|tag
argument_list|)
operator|!=
literal|0
expr_stmt|;
name|closeTag
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|closeAll
name|void
name|XmlOutput
operator|::
name|closeAll
parameter_list|()
block|{
if|if
condition|(
operator|!
name|tagStack
operator|.
name|count
argument_list|()
condition|)
return|return;
name|closeTo
argument_list|(
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addDeclaration
name|void
name|XmlOutput
operator|::
name|addDeclaration
parameter_list|(
specifier|const
name|QString
modifier|&
name|version
parameter_list|,
specifier|const
name|QString
modifier|&
name|encoding
parameter_list|)
block|{
switch|switch
condition|(
name|currentState
condition|)
block|{
case|case
name|Bare
case|:
break|break;
case|case
name|Tag
case|:
case|case
name|Attribute
case|:
comment|//warn_msg(WarnLogic, "<%s>: Cannot add declaration when not in bare state", tagStack.last().toLatin1().constData());
name|qDebug
argument_list|(
literal|"<%s>: Cannot add declaration when not in bare state"
argument_list|,
name|tagStack
operator|.
name|last
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|QString
name|outData
init|=
name|QString
argument_list|(
literal|"<?xml version=\"%1\" encoding=\"%2\"?>"
argument_list|)
operator|.
name|arg
argument_list|(
name|doConversion
argument_list|(
name|version
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|doConversion
argument_list|(
name|encoding
argument_list|)
argument_list|)
decl_stmt|;
name|addRaw
argument_list|(
name|outData
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addRaw
name|void
name|XmlOutput
operator|::
name|addRaw
parameter_list|(
specifier|const
name|QString
modifier|&
name|rawText
parameter_list|)
block|{
name|closeOpen
argument_list|()
expr_stmt|;
name|xmlFile
operator|<<
name|rawText
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addAttribute
name|void
name|XmlOutput
operator|::
name|addAttribute
parameter_list|(
specifier|const
name|QString
modifier|&
name|attribute
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
switch|switch
condition|(
name|currentState
condition|)
block|{
case|case
name|Bare
case|:
case|case
name|Tag
case|:
comment|//warn_msg(WarnLogic, "<%s>: Cannot add attribute since tags not open", tagStack.last().toLatin1().constData());
name|qDebug
argument_list|(
literal|"<%s>: Cannot add attribute (%s) since tag's not open"
argument_list|,
operator|(
name|tagStack
operator|.
name|count
argument_list|()
condition|?
name|tagStack
operator|.
name|last
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
else|:
literal|"Root"
operator|)
argument_list|,
name|attribute
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return;
case|case
name|Attribute
case|:
break|break;
block|}
if|if
condition|(
name|format
operator|==
name|NewLine
condition|)
name|xmlFile
operator|<<
name|endl
expr_stmt|;
name|xmlFile
operator|<<
name|currentIndent
operator|<<
name|doConversion
argument_list|(
name|attribute
argument_list|)
operator|<<
literal|"=\""
operator|<<
name|doConversion
argument_list|(
name|value
argument_list|)
operator|<<
literal|"\""
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addAttributeTag
name|void
name|XmlOutput
operator|::
name|addAttributeTag
parameter_list|(
specifier|const
name|QString
modifier|&
name|attribute
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
switch|switch
condition|(
name|currentState
condition|)
block|{
case|case
name|Bare
case|:
case|case
name|Tag
case|:
comment|//warn_msg(WarnLogic, "<%s>: Cannot add attribute since tags not open", tagStack.last().toLatin1().constData());
name|qDebug
argument_list|(
literal|"<%s>: Cannot add attribute (%s) since tag's not open"
argument_list|,
operator|(
name|tagStack
operator|.
name|count
argument_list|()
condition|?
name|tagStack
operator|.
name|last
argument_list|()
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
else|:
literal|"Root"
operator|)
argument_list|,
name|attribute
operator|.
name|toLatin1
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return;
case|case
name|Attribute
case|:
break|break;
block|}
name|xmlFile
operator|<<
literal|" "
operator|<<
name|doConversion
argument_list|(
name|attribute
argument_list|)
operator|<<
literal|"=\""
operator|<<
name|doConversion
argument_list|(
name|value
argument_list|)
operator|<<
literal|"\""
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
