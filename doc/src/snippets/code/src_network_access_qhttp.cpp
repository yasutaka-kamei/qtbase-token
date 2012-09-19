begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_expr_stmt
name|content
operator|-
name|type
operator|:
name|text
operator|/
name|html
comment|//! [0]
comment|//! [1]
name|header
operator|.
name|setValue
argument_list|(
literal|"content-type"
argument_list|,
literal|"text/html"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|contentType
name|QString
name|contentType
init|=
name|header
operator|.
name|value
argument_list|(
literal|"content-type"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|QHttpRequestHeader
name|header
argument_list|(
literal|"GET"
argument_list|,
name|QUrl
operator|::
name|toPercentEncoding
argument_list|(
literal|"/index.html"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|header
operator|.
name|setValue
argument_list|(
literal|"Host"
argument_list|,
literal|"qt.nokia.com"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|http
operator|->
name|setHost
argument_list|(
literal|"qt.nokia.com"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|http
operator|->
name|request
argument_list|(
name|header
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_expr_stmt
name|http
operator|->
name|setHost
argument_list|(
literal|"qt.nokia.com"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// id == 1
end_comment
begin_expr_stmt
name|http
operator|->
name|get
argument_list|(
name|QUrl
operator|::
name|toPercentEncoding
argument_list|(
literal|"/index.html"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// id == 2
end_comment
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_macro
name|requestStarted
argument_list|(
literal|1
argument_list|)
end_macro
begin_macro
name|requestFinished
argument_list|(
literal|1
argument_list|,
literal|false
argument_list|)
end_macro
begin_macro
name|requestStarted
argument_list|(
literal|2
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Connecting
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Sending
argument_list|)
end_macro
begin_macro
name|dataSendProgress
argument_list|(
literal|77
argument_list|,
literal|77
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Reading
argument_list|)
end_macro
begin_macro
name|responseHeaderReceived
argument_list|(
argument|responseheader
argument_list|)
end_macro
begin_macro
name|dataReadProgress
argument_list|(
literal|5388
argument_list|,
literal|0
argument_list|)
end_macro
begin_macro
name|readyRead
argument_list|(
argument|responseheader
argument_list|)
end_macro
begin_macro
name|dataReadProgress
argument_list|(
literal|18300
argument_list|,
literal|0
argument_list|)
end_macro
begin_macro
name|readyRead
argument_list|(
argument|responseheader
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Connected
argument_list|)
end_macro
begin_macro
name|requestFinished
argument_list|(
literal|2
argument_list|,
literal|false
argument_list|)
end_macro
begin_macro
name|done
argument_list|(
literal|false
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Closing
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Unconnected
argument_list|)
end_macro
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_expr_stmt
name|http
operator|->
name|setHost
argument_list|(
literal|"www.foo.bar"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// id == 1
end_comment
begin_expr_stmt
name|http
operator|->
name|get
argument_list|(
literal|"/index.html"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// id == 2
end_comment
begin_expr_stmt
name|http
operator|->
name|post
argument_list|(
literal|"register.html"
argument_list|,
name|data
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// id == 3
end_comment
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_macro
name|requestStarted
argument_list|(
literal|1
argument_list|)
end_macro
begin_macro
name|requestFinished
argument_list|(
literal|1
argument_list|,
literal|false
argument_list|)
end_macro
begin_macro
name|requestStarted
argument_list|(
literal|2
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|HostLookup
argument_list|)
end_macro
begin_macro
name|requestFinished
argument_list|(
literal|2
argument_list|,
literal|true
argument_list|)
end_macro
begin_macro
name|done
argument_list|(
literal|true
argument_list|)
end_macro
begin_macro
name|stateChanged
argument_list|(
argument|Unconnected
argument_list|)
end_macro
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|getTicks
name|void
name|Ticker
operator|::
name|getTicks
parameter_list|()
block|{
name|http
operator|=
operator|new
name|QHttp
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|http
argument_list|,
name|SIGNAL
argument_list|(
name|done
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showPage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|http
operator|->
name|setProxy
argument_list|(
literal|"proxy.example.com"
argument_list|,
literal|3128
argument_list|)
expr_stmt|;
name|http
operator|->
name|setHost
argument_list|(
literal|"ticker.example.com"
argument_list|)
expr_stmt|;
name|http
operator|->
name|get
argument_list|(
literal|"/ticks.asp"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showPage
name|void
name|Ticker
operator|::
name|showPage
parameter_list|()
block|{
name|display
argument_list|(
name|http
operator|->
name|readAll
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
end_unit
