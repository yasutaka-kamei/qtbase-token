begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|multiPart
name|QHttpMultiPart
modifier|*
name|multiPart
init|=
operator|new
name|QHttpMultiPart
argument_list|(
name|QHttpMultiPart
operator|::
name|FormDataType
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|textPart
name|QHttpPart
name|textPart
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|textPart
operator|.
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|ContentDispositionHeader
argument_list|,
name|QVariant
argument_list|(
literal|"form-data; name=\"text\""
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|textPart
operator|.
name|setBody
argument_list|(
literal|"my text"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|imagePart
name|QHttpPart
name|imagePart
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|imagePart
operator|.
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|ContentTypeHeader
argument_list|,
name|QVariant
argument_list|(
literal|"image/jpeg"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|imagePart
operator|.
name|setHeader
argument_list|(
name|QNetworkRequest
operator|::
name|ContentDispositionHeader
argument_list|,
name|QVariant
argument_list|(
literal|"form-data; name=\"image\""
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|file
name|QFile
modifier|*
name|file
init|=
operator|new
name|QFile
argument_list|(
literal|"image.jpg"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|file
operator|->
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|imagePart
operator|.
name|setBodyDevice
argument_list|(
name|file
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|file
operator|->
name|setParent
argument_list|(
name|multiPart
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// we cannot delete the file now, so delete it with the multiPart
end_comment
begin_expr_stmt
name|multiPart
operator|->
name|append
argument_list|(
name|textPart
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|multiPart
operator|->
name|append
argument_list|(
name|imagePart
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QUrl
name|url
argument_list|(
literal|"http://my.server.tld"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QNetworkRequest
name|request
parameter_list|(
name|url
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
DECL|variable|manager
name|QNetworkAccessManager
name|manager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|reply
name|QNetworkReply
modifier|*
name|reply
init|=
name|manager
operator|.
name|post
argument_list|(
name|request
argument_list|,
name|multiPart
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|multiPart
operator|->
name|setParent
argument_list|(
name|reply
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// delete the multiPart with the reply
end_comment
begin_comment
comment|// here connect signals etc.
end_comment
begin_comment
comment|//! [0]
end_comment
end_unit
