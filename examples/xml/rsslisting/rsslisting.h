begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|RSSLISTING_H
end_ifndef
begin_define
DECL|macro|RSSLISTING_H
define|#
directive|define
name|RSSLISTING_H
end_define
begin_include
include|#
directive|include
file|<QNetworkAccessManager>
end_include
begin_include
include|#
directive|include
file|<QNetworkReply>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_include
include|#
directive|include
file|<QBuffer>
end_include
begin_include
include|#
directive|include
file|<QXmlStreamReader>
end_include
begin_include
include|#
directive|include
file|<QUrl>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QLineEdit
name|class
name|QLineEdit
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeWidget
name|class
name|QTreeWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTreeWidgetItem
name|class
name|QTreeWidgetItem
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPushButton
name|class
name|QPushButton
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|class
name|RSSListing
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|RSSListing
argument_list|(
name|QWidget
operator|*
name|widget
operator|=
literal|0
argument_list|)
block|;
name|public
name|slots
operator|:
name|void
name|fetch
argument_list|()
block|;
name|void
name|finished
argument_list|(
name|QNetworkReply
operator|*
name|reply
argument_list|)
block|;
name|void
name|readyRead
argument_list|()
block|;
name|void
name|metaDataChanged
argument_list|()
block|;
name|void
name|itemActivated
argument_list|(
name|QTreeWidgetItem
operator|*
name|item
argument_list|)
block|;
name|void
name|error
argument_list|(
name|QNetworkReply
operator|::
name|NetworkError
argument_list|)
block|;
name|private
operator|:
name|void
name|parseXml
argument_list|()
block|;
name|void
name|get
argument_list|(
specifier|const
name|QUrl
operator|&
name|url
argument_list|)
block|;
name|QXmlStreamReader
name|xml
block|;
name|QString
name|currentTag
block|;
name|QString
name|linkString
block|;
name|QString
name|titleString
block|;
name|QNetworkAccessManager
name|manager
block|;
name|QNetworkReply
operator|*
name|currentReply
block|;
name|QLineEdit
operator|*
name|lineEdit
block|;
name|QTreeWidget
operator|*
name|treeWidget
block|;
name|QPushButton
operator|*
name|fetchButton
block|;  }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
