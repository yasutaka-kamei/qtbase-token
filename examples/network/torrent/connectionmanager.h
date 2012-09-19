begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CONNECTIONMANAGER_H
end_ifndef
begin_define
DECL|macro|CONNECTIONMANAGER_H
define|#
directive|define
name|CONNECTIONMANAGER_H
end_define
begin_decl_stmt
DECL|variable|PeerWireClient
name|class
name|PeerWireClient
decl_stmt|;
end_decl_stmt
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<QSet>
end_include
begin_decl_stmt
name|class
name|ConnectionManager
block|{
name|public
label|:
specifier|static
name|ConnectionManager
modifier|*
name|instance
parameter_list|()
function_decl|;
name|bool
name|canAddConnection
argument_list|()
specifier|const
expr_stmt|;
name|void
name|addConnection
parameter_list|(
name|PeerWireClient
modifier|*
name|connection
parameter_list|)
function_decl|;
name|void
name|removeConnection
parameter_list|(
name|PeerWireClient
modifier|*
name|connection
parameter_list|)
function_decl|;
name|int
name|maxConnections
argument_list|()
specifier|const
expr_stmt|;
name|QByteArray
name|clientId
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QSet
operator|<
name|PeerWireClient
operator|*
operator|>
name|connections
expr_stmt|;
name|mutable
name|QByteArray
name|id
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
