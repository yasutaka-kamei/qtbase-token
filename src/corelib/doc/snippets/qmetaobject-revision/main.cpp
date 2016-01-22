begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 Research In Motion. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QMetaObject>
end_include
begin_include
include|#
directive|include
file|<QMetaMethod>
end_include
begin_include
include|#
directive|include
file|<QMetaProperty>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_function
DECL|function|exposeMethod
name|void
name|exposeMethod
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|exposeProperty
name|void
name|exposeProperty
parameter_list|(
specifier|const
name|QMetaProperty
modifier|&
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
comment|//! [Window class using revision]
name|Window
name|window
decl_stmt|;
name|int
name|expectedRevision
init|=
literal|0
decl_stmt|;
specifier|const
name|QMetaObject
modifier|*
name|windowMetaObject
init|=
name|window
operator|.
name|metaObject
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|windowMetaObject
operator|->
name|methodCount
argument_list|()
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|windowMetaObject
operator|->
name|method
argument_list|(
name|i
argument_list|)
operator|.
name|revision
argument_list|()
operator|<=
name|expectedRevision
condition|)
name|exposeMethod
argument_list|(
name|windowMetaObject
operator|->
name|method
argument_list|(
name|i
argument_list|)
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
name|windowMetaObject
operator|->
name|propertyCount
argument_list|()
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|windowMetaObject
operator|->
name|property
argument_list|(
name|i
argument_list|)
operator|.
name|revision
argument_list|()
operator|<=
name|expectedRevision
condition|)
name|exposeProperty
argument_list|(
name|windowMetaObject
operator|->
name|property
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [Window class using revision]
name|window
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
