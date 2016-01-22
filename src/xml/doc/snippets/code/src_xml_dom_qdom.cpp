begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|doc
name|QDomDocument
name|doc
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|impl
name|QDomImplementation
name|impl
decl_stmt|;
end_decl_stmt
begin_comment
comment|// This will create the element, but the resulting XML document will
end_comment
begin_comment
comment|// be invalid, because '~' is not a valid character in a tag name.
end_comment
begin_expr_stmt
name|impl
operator|.
name|setInvalidDataPolicy
argument_list|(
name|QDomImplementation
operator|::
name|AcceptInvalidData
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|elt1
name|QDomElement
name|elt1
init|=
name|doc
operator|.
name|createElement
argument_list|(
literal|"foo~bar"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// This will create an element with the tag name "foobar".
end_comment
begin_expr_stmt
name|impl
operator|.
name|setInvalidDataPolicy
argument_list|(
name|QDomImplementation
operator|::
name|DropInvalidData
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|elt2
name|QDomElement
name|elt2
init|=
name|doc
operator|.
name|createElement
argument_list|(
literal|"foo~bar"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// This will create a null element.
end_comment
begin_expr_stmt
name|impl
operator|.
name|setInvalidDataPolicy
argument_list|(
name|QDomImplementation
operator|::
name|ReturnNullNode
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|elt3
name|QDomElement
name|elt3
init|=
name|doc
operator|.
name|createElement
argument_list|(
literal|"foo~bar"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|d
name|QDomDocument
name|d
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|d
operator|.
name|setContent
argument_list|(
name|someXML
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|n
name|QDomNode
name|n
init|=
name|d
operator|.
name|firstChild
argument_list|()
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
operator|!
name|n
operator|.
name|isNull
argument_list|()
condition|)
block|{
if|if
condition|(
name|n
operator|.
name|isElement
argument_list|()
condition|)
block|{
name|QDomElement
name|e
init|=
name|n
operator|.
name|toElement
argument_list|()
decl_stmt|;
name|cout
operator|<<
literal|"Element name: "
operator|<<
name|e
operator|.
name|tagName
argument_list|()
operator|<<
name|endl
expr_stmt|;
break|break;
block|}
name|n
operator|=
name|n
operator|.
name|nextSibling
argument_list|()
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|document
name|QDomDocument
name|document
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|element1
name|QDomElement
name|element1
init|=
name|document
operator|.
name|documentElement
argument_list|()
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|element2
name|QDomElement
name|element2
init|=
name|element1
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|element3
name|QDomElement
name|element3
init|=
name|document
operator|.
name|createElement
argument_list|(
literal|"MyElement"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|element4
name|QDomElement
name|element4
init|=
name|document
operator|.
name|createElement
argument_list|(
literal|"MyElement"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_expr_stmt
operator|<
name|body
operator|>
operator|<
name|h1
operator|>
name|Heading
argument_list|<
operator|/
name|h1
argument_list|>
operator|<
name|p
operator|>
name|Hello
argument_list|<
name|b
argument_list|>
name|you
argument_list|<
operator|/
name|b
argument_list|>
operator|<
operator|/
name|p
operator|>
operator|<
operator|/
name|body
operator|>
comment|//! [4]
comment|//! [5]
operator|<
name|h1
operator|>
name|Heading
argument_list|<
operator|/
name|h1
argument_list|>
operator|<
name|p
operator|>
name|The
name|text
operator|...
operator|<
operator|/
name|p
operator|>
operator|<
name|h2
operator|>
name|Next
name|heading
argument_list|<
operator|/
name|h2
argument_list|>
comment|//! [5]
comment|//! [6]
operator|<
name|h1
operator|>
name|Heading
argument_list|<
operator|/
name|h1
argument_list|>
operator|<
name|p
operator|>
name|The
name|text
operator|...
operator|<
operator|/
name|p
operator|>
operator|<
name|h2
operator|>
name|Next
name|heading
argument_list|<
operator|/
name|h2
argument_list|>
comment|//! [6]
comment|//! [7]
operator|<
name|link
name|href
operator|=
literal|"http://qt-project.org"
name|color
operator|=
literal|"red"
operator|/
operator|>
comment|//! [7]
comment|//! [8]
name|QDomElement
name|e
operator|=
comment|//...
comment|//...
name|QDomAttr
name|a
operator|=
name|e
operator|.
name|attributeNode
argument_list|(
literal|"href"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|cout
operator|<<
name|a
operator|.
name|value
argument_list|()
operator|<<
name|endl
expr_stmt|;
end_expr_stmt
begin_comment
comment|// prints "http://qt-project.org"
end_comment
begin_expr_stmt
name|a
operator|.
name|setValue
argument_list|(
literal|"http://qt-project.org/doc"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// change the node's attribute
end_comment
begin_decl_stmt
DECL|variable|a2
name|QDomAttr
name|a2
init|=
name|e
operator|.
name|attributeNode
argument_list|(
literal|"href"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|cout
operator|<<
name|a2
operator|.
name|value
argument_list|()
operator|<<
name|endl
expr_stmt|;
end_expr_stmt
begin_comment
comment|// prints "http://qt-project.org/doc"
end_comment
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_decl_stmt
DECL|variable|e
name|QDomElement
name|e
init|=
comment|//...
comment|//...
name|QString
name|s
operator|=
name|e
operator|.
name|text
argument_list|()
comment|//! [9]
comment|//! [10]
name|QString
name|text
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|element
name|QDomElement
name|element
init|=
name|doc
operator|.
name|documentElement
argument_list|()
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|QDomNode
name|n
init|=
name|element
operator|.
name|firstChild
argument_list|()
init|;
operator|!
name|n
operator|.
name|isNull
argument_list|()
condition|;
name|n
operator|=
name|n
operator|.
name|nextSibling
argument_list|()
control|)
block|{
name|QDomText
name|t
init|=
name|n
operator|.
name|toText
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|t
operator|.
name|isNull
argument_list|()
condition|)
name|text
operator|+=
name|t
operator|.
name|data
argument_list|()
expr_stmt|;
block|}
end_for
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
DECL|variable|doc
name|QDomDocument
name|doc
init|=
comment|// ...
name|QDomElement
name|root
operator|=
name|doc
operator|.
name|firstChildElement
argument_list|(
literal|"database"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|elt
name|QDomElement
name|elt
init|=
name|root
operator|.
name|firstChildElement
argument_list|(
literal|"entry"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
init|;
operator|!
name|elt
operator|.
name|isNull
argument_list|()
condition|;
name|elt
operator|=
name|elt
operator|.
name|nextSiblingElement
argument_list|(
literal|"entry"
argument_list|)
control|)
block|{
comment|// ...
block|}
end_for
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_expr_stmt
operator|<
name|img
name|src
operator|=
literal|"myimg.png"
operator|>
comment|//! [12]
comment|//! [13]
operator|<
name|h1
operator|>
name|Hello
argument_list|<
name|b
argument_list|>
name|Qt
argument_list|<
operator|/
name|b
argument_list|>
operator|<
operator|!
index|[
name|CDATA
index|[
operator|<
name|xml
name|is
name|cool
operator|>
index|]
index|]
operator|>
operator|<
operator|/
name|h1
operator|>
comment|//! [13]
comment|//! [14]
name|Hello
name|Qt
argument_list|<
name|xml
name|is
name|cool
argument_list|>
comment|//! [14]
comment|//! [15]
operator|<
operator|!
operator|--
name|this
name|is
name|a
name|comment
operator|--
operator|>
comment|//! [15]
comment|//! [16]
name|QDomDocument
name|doc
argument_list|(
literal|"mydocument"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QFile
name|file
argument_list|(
literal|"mydocument.xml"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return;
end_if
begin_if
if|if
condition|(
operator|!
name|doc
operator|.
name|setContent
argument_list|(
operator|&
name|file
argument_list|)
condition|)
block|{
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
return|return;
block|}
end_if
begin_expr_stmt
name|file
operator|.
name|close
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// print out the element names of all elements that are direct children
end_comment
begin_comment
comment|// of the outermost element.
end_comment
begin_decl_stmt
DECL|variable|docElem
name|QDomElement
name|docElem
init|=
name|doc
operator|.
name|documentElement
argument_list|()
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|n
name|QDomNode
name|n
init|=
name|docElem
operator|.
name|firstChild
argument_list|()
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
operator|!
name|n
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QDomElement
name|e
init|=
name|n
operator|.
name|toElement
argument_list|()
decl_stmt|;
comment|// try to convert the node to an element.
if|if
condition|(
operator|!
name|e
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|cout
operator|<<
name|qPrintable
argument_list|(
name|e
operator|.
name|tagName
argument_list|()
argument_list|)
operator|<<
name|endl
expr_stmt|;
comment|// the node really is an element.
block|}
name|n
operator|=
name|n
operator|.
name|nextSibling
argument_list|()
expr_stmt|;
block|}
end_while
begin_comment
comment|// Here we append a new element to the end of the document
end_comment
begin_decl_stmt
DECL|variable|elem
name|QDomElement
name|elem
init|=
name|doc
operator|.
name|createElement
argument_list|(
literal|"img"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|elem
operator|.
name|setAttribute
argument_list|(
literal|"src"
argument_list|,
literal|"myimage.png"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|docElem
operator|.
name|appendChild
argument_list|(
name|elem
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_decl_stmt
name|QDomDocument
name|doc
argument_list|(
literal|"MyML"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|root
name|QDomElement
name|root
init|=
name|doc
operator|.
name|createElement
argument_list|(
literal|"MyML"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|doc
operator|.
name|appendChild
argument_list|(
name|root
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|tag
name|QDomElement
name|tag
init|=
name|doc
operator|.
name|createElement
argument_list|(
literal|"Greeting"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|root
operator|.
name|appendChild
argument_list|(
name|tag
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|t
name|QDomText
name|t
init|=
name|doc
operator|.
name|createTextNode
argument_list|(
literal|"Hello World"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|tag
operator|.
name|appendChild
argument_list|(
name|t
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|xml
name|QString
name|xml
init|=
name|doc
operator|.
name|toString
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [17]
end_comment
end_unit
