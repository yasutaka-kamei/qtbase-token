begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"widget.h"
end_include
begin_include
include|#
directive|include
file|"renderwindow.h"
end_include
begin_include
include|#
directive|include
file|<QVBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QComboBox>
end_include
begin_include
include|#
directive|include
file|<QGroupBox>
end_include
begin_include
include|#
directive|include
file|<QRadioButton>
end_include
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QTextEdit>
end_include
begin_include
include|#
directive|include
file|<QSplitter>
end_include
begin_include
include|#
directive|include
file|<QSurfaceFormat>
end_include
begin_include
include|#
directive|include
file|<QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_struct
DECL|struct|Version
struct|struct
name|Version
block|{
DECL|member|str
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
DECL|member|major
name|int
name|major
decl_stmt|;
DECL|member|minor
name|int
name|minor
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|versions
specifier|static
name|struct
name|Version
name|versions
index|[]
init|=
block|{
block|{
literal|"1.0"
block|,
literal|1
block|,
literal|0
block|}
block|,
block|{
literal|"1.1"
block|,
literal|1
block|,
literal|1
block|}
block|,
block|{
literal|"1.2"
block|,
literal|1
block|,
literal|2
block|}
block|,
block|{
literal|"1.3"
block|,
literal|1
block|,
literal|3
block|}
block|,
block|{
literal|"1.4"
block|,
literal|1
block|,
literal|4
block|}
block|,
block|{
literal|"1.5"
block|,
literal|1
block|,
literal|5
block|}
block|,
block|{
literal|"2.0"
block|,
literal|2
block|,
literal|0
block|}
block|,
block|{
literal|"2.1"
block|,
literal|2
block|,
literal|1
block|}
block|,
block|{
literal|"3.0"
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"3.1"
block|,
literal|3
block|,
literal|1
block|}
block|,
block|{
literal|"3.2"
block|,
literal|3
block|,
literal|2
block|}
block|,
block|{
literal|"3.3"
block|,
literal|3
block|,
literal|3
block|}
block|,
block|{
literal|"4.0"
block|,
literal|4
block|,
literal|0
block|}
block|,
block|{
literal|"4.1"
block|,
literal|4
block|,
literal|1
block|}
block|,
block|{
literal|"4.2"
block|,
literal|4
block|,
literal|2
block|}
block|,
block|{
literal|"4.3"
block|,
literal|4
block|,
literal|3
block|}
block|,
block|{
literal|"4.4"
block|,
literal|4
block|,
literal|4
block|}
block|,
block|{
literal|"4.5"
block|,
literal|4
block|,
literal|5
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|Profile
struct|struct
name|Profile
block|{
DECL|member|str
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
DECL|member|profile
name|QSurfaceFormat
operator|::
name|OpenGLContextProfile
name|profile
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|profiles
specifier|static
name|struct
name|Profile
name|profiles
index|[]
init|=
block|{
block|{
literal|"none"
block|,
name|QSurfaceFormat
operator|::
name|NoProfile
block|}
block|,
block|{
literal|"core"
block|,
name|QSurfaceFormat
operator|::
name|CoreProfile
block|}
block|,
block|{
literal|"compatibility"
block|,
name|QSurfaceFormat
operator|::
name|CompatibilityProfile
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|Option
struct|struct
name|Option
block|{
DECL|member|str
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
DECL|member|option
name|QSurfaceFormat
operator|::
name|FormatOption
name|option
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|options
specifier|static
name|struct
name|Option
name|options
index|[]
init|=
block|{
block|{
literal|"deprecated functions (not forward compatible)"
block|,
name|QSurfaceFormat
operator|::
name|DeprecatedFunctions
block|}
block|,
block|{
literal|"debug context"
block|,
name|QSurfaceFormat
operator|::
name|DebugContext
block|}
block|,
block|{
literal|"stereo buffers"
block|,
name|QSurfaceFormat
operator|::
name|StereoBuffers
block|}
block|,
comment|// This is not a QSurfaceFormat option but is helpful to determine if the driver
comment|// allows compiling old-style shaders with core profile.
block|{
literal|"force version 110 shaders"
block|,
name|QSurfaceFormat
operator|::
name|FormatOption
operator|(
literal|0
operator|)
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|Renderable
struct|struct
name|Renderable
block|{
DECL|member|str
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
DECL|member|renderable
name|QSurfaceFormat
operator|::
name|RenderableType
name|renderable
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|renderables
specifier|static
name|struct
name|Renderable
name|renderables
index|[]
init|=
block|{
block|{
literal|"default"
block|,
name|QSurfaceFormat
operator|::
name|DefaultRenderableType
block|}
block|,
block|{
literal|"OpenGL"
block|,
name|QSurfaceFormat
operator|::
name|OpenGL
block|}
block|,
block|{
literal|"OpenGL ES"
block|,
name|QSurfaceFormat
operator|::
name|OpenGLES
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|addVersions
name|void
name|Widget
operator|::
name|addVersions
parameter_list|(
name|QLayout
modifier|*
name|layout
parameter_list|)
block|{
name|QHBoxLayout
modifier|*
name|hbox
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|hbox
operator|->
name|setSpacing
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|QLabel
modifier|*
name|label
init|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Context&version: "
argument_list|)
argument_list|)
decl_stmt|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|label
argument_list|)
expr_stmt|;
name|m_version
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|m_version
operator|->
name|setMinimumWidth
argument_list|(
literal|60
argument_list|)
expr_stmt|;
name|label
operator|->
name|setBuddy
argument_list|(
name|m_version
argument_list|)
expr_stmt|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|m_version
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|versions
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|Version
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
name|m_version
operator|->
name|addItem
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|versions
index|[
name|i
index|]
operator|.
name|str
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|versions
index|[
name|i
index|]
operator|.
name|major
operator|==
literal|2
operator|&&
name|versions
index|[
name|i
index|]
operator|.
name|minor
operator|==
literal|0
condition|)
name|m_version
operator|->
name|setCurrentIndex
argument_list|(
name|m_version
operator|->
name|count
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|QPushButton
modifier|*
name|btn
init|=
operator|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Create context"
argument_list|)
argument_list|)
decl_stmt|;
name|connect
argument_list|(
name|btn
argument_list|,
operator|&
name|QPushButton
operator|::
name|clicked
argument_list|,
name|this
argument_list|,
operator|&
name|Widget
operator|::
name|start
argument_list|)
expr_stmt|;
name|btn
operator|->
name|setMinimumSize
argument_list|(
literal|120
argument_list|,
literal|40
argument_list|)
expr_stmt|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|btn
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addItem
argument_list|(
name|hbox
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addProfiles
name|void
name|Widget
operator|::
name|addProfiles
parameter_list|(
name|QLayout
modifier|*
name|layout
parameter_list|)
block|{
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Profile"
argument_list|)
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vbox
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|profiles
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|Profile
argument_list|)
condition|;
operator|++
name|i
control|)
name|vbox
operator|->
name|addWidget
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|profiles
index|[
name|i
index|]
operator|.
name|str
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
cast|static_cast
argument_list|<
name|QRadioButton
operator|*
argument_list|>
argument_list|(
name|vbox
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
operator|->
name|widget
argument_list|()
argument_list|)
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|vbox
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|m_profiles
operator|=
name|vbox
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addOptions
name|void
name|Widget
operator|::
name|addOptions
parameter_list|(
name|QLayout
modifier|*
name|layout
parameter_list|)
block|{
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Options"
argument_list|)
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vbox
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|options
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|Option
argument_list|)
condition|;
operator|++
name|i
control|)
name|vbox
operator|->
name|addWidget
argument_list|(
operator|new
name|QCheckBox
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|options
index|[
name|i
index|]
operator|.
name|str
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|vbox
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|m_options
operator|=
name|vbox
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addRenderableTypes
name|void
name|Widget
operator|::
name|addRenderableTypes
parameter_list|(
name|QLayout
modifier|*
name|layout
parameter_list|)
block|{
name|QGroupBox
modifier|*
name|groupBox
init|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Renderable type"
argument_list|)
argument_list|)
decl_stmt|;
name|QVBoxLayout
modifier|*
name|vbox
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|renderables
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|Renderable
argument_list|)
condition|;
operator|++
name|i
control|)
name|vbox
operator|->
name|addWidget
argument_list|(
operator|new
name|QRadioButton
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|renderables
index|[
name|i
index|]
operator|.
name|str
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
cast|static_cast
argument_list|<
name|QRadioButton
operator|*
argument_list|>
argument_list|(
name|vbox
operator|->
name|itemAt
argument_list|(
literal|0
argument_list|)
operator|->
name|widget
argument_list|()
argument_list|)
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|groupBox
operator|->
name|setLayout
argument_list|(
name|vbox
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|groupBox
argument_list|)
expr_stmt|;
name|m_renderables
operator|=
name|vbox
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addRenderWindow
name|void
name|Widget
operator|::
name|addRenderWindow
parameter_list|()
block|{
name|m_renderWindowLayout
operator|->
name|addWidget
argument_list|(
name|m_renderWindowContainer
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|widgetWithLayout
specifier|static
name|QWidget
modifier|*
name|widgetWithLayout
parameter_list|(
name|QLayout
modifier|*
name|layout
parameter_list|)
block|{
name|QWidget
modifier|*
name|w
init|=
operator|new
name|QWidget
decl_stmt|;
name|w
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
return|return
name|w
return|;
block|}
end_function
begin_constructor
DECL|function|Widget
name|Widget
operator|::
name|Widget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|QSplitter
modifier|*
name|vsplit
init|=
operator|new
name|QSplitter
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|vsplit
argument_list|)
expr_stmt|;
name|QSplitter
modifier|*
name|hsplit
init|=
operator|new
name|QSplitter
decl_stmt|;
name|QVBoxLayout
modifier|*
name|settingsLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|addVersions
argument_list|(
name|settingsLayout
argument_list|)
expr_stmt|;
name|addProfiles
argument_list|(
name|settingsLayout
argument_list|)
expr_stmt|;
name|addOptions
argument_list|(
name|settingsLayout
argument_list|)
expr_stmt|;
name|addRenderableTypes
argument_list|(
name|settingsLayout
argument_list|)
expr_stmt|;
name|hsplit
operator|->
name|addWidget
argument_list|(
name|widgetWithLayout
argument_list|(
name|settingsLayout
argument_list|)
argument_list|)
expr_stmt|;
name|QVBoxLayout
modifier|*
name|outputLayout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|m_output
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|m_output
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|outputLayout
operator|->
name|addWidget
argument_list|(
name|m_output
argument_list|)
expr_stmt|;
name|m_extensions
operator|=
operator|new
name|QTextEdit
expr_stmt|;
name|m_extensions
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|outputLayout
operator|->
name|addWidget
argument_list|(
name|m_extensions
argument_list|)
expr_stmt|;
name|hsplit
operator|->
name|addWidget
argument_list|(
name|widgetWithLayout
argument_list|(
name|outputLayout
argument_list|)
argument_list|)
expr_stmt|;
name|hsplit
operator|->
name|setStretchFactor
argument_list|(
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|hsplit
operator|->
name|setStretchFactor
argument_list|(
literal|1
argument_list|,
literal|6
argument_list|)
expr_stmt|;
name|vsplit
operator|->
name|addWidget
argument_list|(
name|hsplit
argument_list|)
expr_stmt|;
name|m_renderWindowLayout
operator|=
operator|new
name|QVBoxLayout
expr_stmt|;
name|vsplit
operator|->
name|addWidget
argument_list|(
name|widgetWithLayout
argument_list|(
name|m_renderWindowLayout
argument_list|)
argument_list|)
expr_stmt|;
name|vsplit
operator|->
name|setStretchFactor
argument_list|(
literal|1
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|m_renderWindowContainer
operator|=
operator|new
name|QWidget
expr_stmt|;
name|addRenderWindow
argument_list|()
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|start
name|void
name|Widget
operator|::
name|start
parameter_list|()
block|{
name|QSurfaceFormat
name|fmt
decl_stmt|;
name|int
name|idx
init|=
name|m_version
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
if|if
condition|(
name|idx
operator|<
literal|0
condition|)
return|return;
name|fmt
operator|.
name|setVersion
argument_list|(
name|versions
index|[
name|idx
index|]
operator|.
name|major
argument_list|,
name|versions
index|[
name|idx
index|]
operator|.
name|minor
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|profiles
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|Profile
argument_list|)
condition|;
operator|++
name|i
control|)
if|if
condition|(
cast|static_cast
argument_list|<
name|QRadioButton
operator|*
argument_list|>
argument_list|(
name|m_profiles
operator|->
name|itemAt
argument_list|(
name|int
argument_list|(
name|i
argument_list|)
argument_list|)
operator|->
name|widget
argument_list|()
argument_list|)
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|fmt
operator|.
name|setProfile
argument_list|(
name|profiles
index|[
name|i
index|]
operator|.
name|profile
argument_list|)
expr_stmt|;
break|break;
block|}
name|bool
name|forceGLSL110
init|=
literal|false
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|options
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|Option
argument_list|)
condition|;
operator|++
name|i
control|)
if|if
condition|(
cast|static_cast
argument_list|<
name|QCheckBox
operator|*
argument_list|>
argument_list|(
name|m_options
operator|->
name|itemAt
argument_list|(
name|int
argument_list|(
name|i
argument_list|)
argument_list|)
operator|->
name|widget
argument_list|()
argument_list|)
operator|->
name|isChecked
argument_list|()
condition|)
block|{
if|if
condition|(
name|options
index|[
name|i
index|]
operator|.
name|option
condition|)
name|fmt
operator|.
name|setOption
argument_list|(
name|options
index|[
name|i
index|]
operator|.
name|option
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|i
operator|==
literal|3
condition|)
name|forceGLSL110
operator|=
literal|true
expr_stmt|;
block|}
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|renderables
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|Renderable
argument_list|)
condition|;
operator|++
name|i
control|)
if|if
condition|(
cast|static_cast
argument_list|<
name|QRadioButton
operator|*
argument_list|>
argument_list|(
name|m_renderables
operator|->
name|itemAt
argument_list|(
name|int
argument_list|(
name|i
argument_list|)
argument_list|)
operator|->
name|widget
argument_list|()
argument_list|)
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|fmt
operator|.
name|setRenderableType
argument_list|(
name|renderables
index|[
name|i
index|]
operator|.
name|renderable
argument_list|)
expr_stmt|;
break|break;
block|}
comment|// The example rendering will need a depth buffer.
name|fmt
operator|.
name|setDepthBufferSize
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|clear
argument_list|()
expr_stmt|;
name|m_extensions
operator|->
name|clear
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Requesting surface format"
operator|<<
name|fmt
expr_stmt|;
name|m_renderWindowLayout
operator|->
name|removeWidget
argument_list|(
name|m_renderWindowContainer
argument_list|)
expr_stmt|;
operator|delete
name|m_renderWindowContainer
expr_stmt|;
name|RenderWindow
modifier|*
name|renderWindow
init|=
operator|new
name|RenderWindow
argument_list|(
name|fmt
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|renderWindow
operator|->
name|context
argument_list|()
condition|)
block|{
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Failed to create context"
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
name|renderWindow
expr_stmt|;
name|m_renderWindowContainer
operator|=
operator|new
name|QWidget
expr_stmt|;
name|addRenderWindow
argument_list|()
expr_stmt|;
return|return;
block|}
name|m_surface
operator|=
name|renderWindow
expr_stmt|;
name|renderWindow
operator|->
name|setForceGLSL110
argument_list|(
name|forceGLSL110
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|renderWindow
argument_list|,
operator|&
name|RenderWindow
operator|::
name|ready
argument_list|,
name|this
argument_list|,
operator|&
name|Widget
operator|::
name|renderWindowReady
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|renderWindow
argument_list|,
operator|&
name|RenderWindow
operator|::
name|error
argument_list|,
name|this
argument_list|,
operator|&
name|Widget
operator|::
name|renderWindowError
argument_list|)
expr_stmt|;
name|m_renderWindowContainer
operator|=
name|QWidget
operator|::
name|createWindowContainer
argument_list|(
name|renderWindow
argument_list|)
expr_stmt|;
name|addRenderWindow
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|printFormat
name|void
name|Widget
operator|::
name|printFormat
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|)
block|{
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"OpenGL version: %1.%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|format
operator|.
name|majorVersion
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|format
operator|.
name|minorVersion
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|profiles
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|Profile
argument_list|)
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|profiles
index|[
name|i
index|]
operator|.
name|profile
operator|==
name|format
operator|.
name|profile
argument_list|()
condition|)
block|{
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Profile: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|profiles
index|[
name|i
index|]
operator|.
name|str
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
name|QString
name|opts
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|options
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|Option
argument_list|)
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|format
operator|.
name|testOption
argument_list|(
name|options
index|[
name|i
index|]
operator|.
name|option
argument_list|)
condition|)
name|opts
operator|+=
name|QString
operator|::
name|fromLatin1
argument_list|(
name|options
index|[
name|i
index|]
operator|.
name|str
argument_list|)
operator|+
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Options: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|opts
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|renderables
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|Renderable
argument_list|)
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|renderables
index|[
name|i
index|]
operator|.
name|renderable
operator|==
name|format
operator|.
name|renderableType
argument_list|()
condition|)
block|{
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Renderable type: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|renderables
index|[
name|i
index|]
operator|.
name|str
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Depth buffer size: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|format
operator|.
name|depthBufferSize
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Stencil buffer size: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|format
operator|.
name|stencilBufferSize
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Samples: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|format
operator|.
name|samples
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Red buffer size: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|format
operator|.
name|redBufferSize
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Green buffer size: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|format
operator|.
name|greenBufferSize
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Blue buffer size: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|format
operator|.
name|blueBufferSize
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Alpha buffer size: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|format
operator|.
name|alphaBufferSize
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Swap interval: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|format
operator|.
name|swapInterval
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|renderWindowReady
name|void
name|Widget
operator|::
name|renderWindowReady
parameter_list|()
block|{
name|QOpenGLContext
modifier|*
name|context
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QString
name|vendor
decl_stmt|,
name|renderer
decl_stmt|,
name|version
decl_stmt|,
name|glslVersion
decl_stmt|;
specifier|const
name|GLubyte
modifier|*
name|p
decl_stmt|;
name|QOpenGLFunctions
modifier|*
name|f
init|=
name|context
operator|->
name|functions
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|f
operator|->
name|glGetString
argument_list|(
name|GL_VENDOR
argument_list|)
operator|)
condition|)
name|vendor
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|f
operator|->
name|glGetString
argument_list|(
name|GL_RENDERER
argument_list|)
operator|)
condition|)
name|renderer
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|f
operator|->
name|glGetString
argument_list|(
name|GL_VERSION
argument_list|)
operator|)
condition|)
name|version
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|f
operator|->
name|glGetString
argument_list|(
name|GL_SHADING_LANGUAGE_VERSION
argument_list|)
operator|)
condition|)
name|glslVersion
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"*** Context information ***"
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Vendor: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|vendor
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Renderer: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|renderer
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"OpenGL version: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|version
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"GLSL version: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|glslVersion
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"\n*** QSurfaceFormat from context ***"
argument_list|)
argument_list|)
expr_stmt|;
name|printFormat
argument_list|(
name|context
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"\n*** QSurfaceFormat from window surface ***"
argument_list|)
argument_list|)
expr_stmt|;
name|printFormat
argument_list|(
name|m_surface
operator|->
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"\n*** Qt build information ***"
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|gltype
index|[]
init|=
block|{
literal|"Desktop"
block|,
literal|"GLES 2"
block|,
literal|"GLES 1"
block|}
decl_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Qt OpenGL configuration: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|gltype
index|[
name|QOpenGLContext
operator|::
name|openGLModuleType
argument_list|()
index|]
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Qt OpenGL library handle: %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|qintptr
argument_list|(
name|QOpenGLContext
operator|::
name|openGLModuleHandle
argument_list|()
argument_list|)
argument_list|,
literal|16
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|extensionList
init|=
name|context
operator|->
name|extensions
argument_list|()
operator|.
name|toList
argument_list|()
decl_stmt|;
name|std
operator|::
name|sort
argument_list|(
name|extensionList
operator|.
name|begin
argument_list|()
argument_list|,
name|extensionList
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|m_extensions
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"Found %1 extensions:"
argument_list|)
operator|.
name|arg
argument_list|(
name|extensionList
operator|.
name|count
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|Q_FOREACH
argument_list|(
argument|const QByteArray&ext
argument_list|,
argument|extensionList
argument_list|)
name|m_extensions
operator|->
name|append
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|ext
argument_list|)
argument_list|)
expr_stmt|;
name|m_output
operator|->
name|moveCursor
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
name|m_extensions
operator|->
name|moveCursor
argument_list|(
name|QTextCursor
operator|::
name|Start
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|renderWindowError
name|void
name|Widget
operator|::
name|renderWindowError
parameter_list|(
specifier|const
name|QString
modifier|&
name|msg
parameter_list|)
block|{
name|m_output
operator|->
name|append
argument_list|(
name|tr
argument_list|(
literal|"An error has occurred:\n%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|msg
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
