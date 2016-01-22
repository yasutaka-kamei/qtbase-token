begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|MyStylePlugin
class|class
name|MyStylePlugin
super|:
specifier|public
name|QStylePlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.Qt.QStyleFactoryInterface"
name|FILE
literal|"mystyleplugin.json"
argument_list|)
decl|public
range|:
name|MyStylePlugin
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
name|QStyle
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|RocketStyle
class|class
name|RocketStyle
super|:
specifier|public
name|QCommonStyle
block|{
public|public:
DECL|function|RocketStyle
name|RocketStyle
parameter_list|()
block|{}
empty_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|StarBusterStyle
class|class
name|StarBusterStyle
super|:
specifier|public
name|QCommonStyle
block|{
public|public:
DECL|function|StarBusterStyle
name|StarBusterStyle
parameter_list|()
block|{}
empty_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|MyStylePlugin
name|MyStylePlugin
operator|::
name|MyStylePlugin
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QStylePlugin
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|keys
name|QStringList
name|MyStylePlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|()
operator|<<
literal|"Rocket"
operator|<<
literal|"StarBuster"
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|create
name|QStyle
modifier|*
name|MyStylePlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
block|{
name|QString
name|lcKey
init|=
name|key
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|lcKey
operator|==
literal|"rocket"
condition|)
block|{
return|return
operator|new
name|RocketStyle
return|;
block|}
elseif|else
if|if
condition|(
name|lcKey
operator|==
literal|"starbuster"
condition|)
block|{
return|return
operator|new
name|StarBusterStyle
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
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
name|MyStylePlugin
name|plugin
decl_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
