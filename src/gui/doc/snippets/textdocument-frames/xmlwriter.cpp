begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|"xmlwriter.h"
end_include
begin_function
DECL|function|toXml
name|QDomDocument
modifier|*
name|XmlWriter
operator|::
name|toXml
parameter_list|()
block|{
name|QDomImplementation
name|implementation
decl_stmt|;
name|QDomDocumentType
name|docType
init|=
name|implementation
operator|.
name|createDocumentType
argument_list|(
literal|"scribe-document"
argument_list|,
literal|"scribe"
argument_list|,
literal|"qt.nokia.com/scribe"
argument_list|)
decl_stmt|;
name|document
operator|=
operator|new
name|QDomDocument
argument_list|(
name|docType
argument_list|)
expr_stmt|;
comment|// ### This processing instruction is required to ensure that any kind
comment|// of encoding is given when the document is written.
name|QDomProcessingInstruction
name|process
init|=
name|document
operator|->
name|createProcessingInstruction
argument_list|(
literal|"xml"
argument_list|,
literal|"version=\"1.0\" encoding=\"utf-8\""
argument_list|)
decl_stmt|;
name|document
operator|->
name|appendChild
argument_list|(
name|process
argument_list|)
expr_stmt|;
name|QDomElement
name|documentElement
init|=
name|document
operator|->
name|createElement
argument_list|(
literal|"document"
argument_list|)
decl_stmt|;
name|document
operator|->
name|appendChild
argument_list|(
name|documentElement
argument_list|)
expr_stmt|;
comment|//! [0]
name|QTextFrame
modifier|*
name|root
init|=
name|textDocument
operator|->
name|rootFrame
argument_list|()
decl_stmt|;
comment|//! [0]
if|if
condition|(
name|root
condition|)
name|processFrame
argument_list|(
name|documentElement
argument_list|,
name|root
argument_list|)
expr_stmt|;
return|return
name|document
return|;
block|}
end_function
begin_function
DECL|function|processBlock
name|void
name|XmlWriter
operator|::
name|processBlock
parameter_list|(
name|QDomElement
modifier|&
name|parent
parameter_list|,
specifier|const
name|QTextBlock
modifier|&
name|block
parameter_list|)
block|{
name|QDomElement
name|blockElement
init|=
name|document
operator|->
name|createElement
argument_list|(
literal|"block"
argument_list|)
decl_stmt|;
name|blockElement
operator|.
name|setAttribute
argument_list|(
literal|"position"
argument_list|,
name|block
operator|.
name|position
argument_list|()
argument_list|)
expr_stmt|;
name|blockElement
operator|.
name|setAttribute
argument_list|(
literal|"length"
argument_list|,
name|block
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
name|parent
operator|.
name|appendChild
argument_list|(
name|blockElement
argument_list|)
expr_stmt|;
name|QTextBlock
operator|::
name|iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|block
operator|.
name|begin
argument_list|()
init|;
operator|!
operator|(
name|it
operator|.
name|atEnd
argument_list|()
operator|)
condition|;
operator|++
name|it
control|)
block|{
name|QTextFragment
name|fragment
init|=
name|it
operator|.
name|fragment
argument_list|()
decl_stmt|;
if|if
condition|(
name|fragment
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QDomElement
name|fragmentElement
init|=
name|document
operator|->
name|createElement
argument_list|(
literal|"fragment"
argument_list|)
decl_stmt|;
name|blockElement
operator|.
name|appendChild
argument_list|(
name|fragmentElement
argument_list|)
expr_stmt|;
name|fragmentElement
operator|.
name|setAttribute
argument_list|(
literal|"length"
argument_list|,
name|fragment
operator|.
name|length
argument_list|()
argument_list|)
expr_stmt|;
name|QDomText
name|fragmentText
init|=
name|document
operator|->
name|createTextNode
argument_list|(
name|fragment
operator|.
name|text
argument_list|()
argument_list|)
decl_stmt|;
name|fragmentElement
operator|.
name|appendChild
argument_list|(
name|fragmentText
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|processFrame
name|void
name|XmlWriter
operator|::
name|processFrame
parameter_list|(
name|QDomElement
modifier|&
name|parent
parameter_list|,
name|QTextFrame
modifier|*
name|frame
parameter_list|)
block|{
name|QDomElement
name|frameElement
init|=
name|document
operator|->
name|createElement
argument_list|(
literal|"frame"
argument_list|)
decl_stmt|;
name|frameElement
operator|.
name|setAttribute
argument_list|(
literal|"begin"
argument_list|,
name|frame
operator|->
name|firstPosition
argument_list|()
argument_list|)
expr_stmt|;
name|frameElement
operator|.
name|setAttribute
argument_list|(
literal|"end"
argument_list|,
name|frame
operator|->
name|lastPosition
argument_list|()
argument_list|)
expr_stmt|;
name|parent
operator|.
name|appendChild
argument_list|(
name|frameElement
argument_list|)
expr_stmt|;
comment|//! [1]
name|QDomElement
name|frameElement
init|=
operator|...
name|QTextFrame
operator|::
name|iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|frame
operator|->
name|begin
argument_list|()
init|;
operator|!
operator|(
name|it
operator|.
name|atEnd
argument_list|()
operator|)
condition|;
operator|++
name|it
control|)
block|{
name|QTextFrame
modifier|*
name|childFrame
init|=
name|it
operator|.
name|currentFrame
argument_list|()
decl_stmt|;
name|QTextBlock
name|childBlock
init|=
name|it
operator|.
name|currentBlock
argument_list|()
decl_stmt|;
if|if
condition|(
name|childFrame
condition|)
comment|//! [1] //! [2]
name|processFrame
argument_list|(
name|frameElement
argument_list|,
name|childFrame
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|childBlock
operator|.
name|isValid
argument_list|()
condition|)
name|processBlock
argument_list|(
name|frameElement
argument_list|,
name|childBlock
argument_list|)
expr_stmt|;
block|}
comment|//! [2]
block|}
end_function
end_unit
