begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"info.h"
end_include
begin_include
include|#
directive|include
file|<QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QScrollArea>
end_include
begin_include
include|#
directive|include
file|<QGridLayout>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QLocale>
end_include
begin_constructor
DECL|function|InfoWidget
name|InfoWidget
operator|::
name|InfoWidget
parameter_list|()
block|{
name|scrollArea
operator|=
operator|new
name|QScrollArea
expr_stmt|;
name|scrollAreaWidget
operator|=
operator|new
name|QWidget
expr_stmt|;
name|scrollArea
operator|->
name|setWidget
argument_list|(
name|scrollAreaWidget
argument_list|)
expr_stmt|;
name|scrollArea
operator|->
name|setWidgetResizable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|layout
operator|=
operator|new
name|QGridLayout
argument_list|()
expr_stmt|;
name|QVBoxLayout
modifier|*
name|v
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|scrollAreaWidget
argument_list|)
decl_stmt|;
name|v
operator|->
name|addLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|v
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|QVBoxLayout
modifier|*
name|l
init|=
operator|new
name|QVBoxLayout
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|l
operator|->
name|addWidget
argument_list|(
name|scrollArea
argument_list|)
expr_stmt|;
name|name
operator|=
name|addItem
argument_list|(
literal|"Name:"
argument_list|)
expr_stmt|;
name|bcp47Name
operator|=
name|addItem
argument_list|(
literal|"Bcp47 name:"
argument_list|)
expr_stmt|;
name|languageName
operator|=
name|addItem
argument_list|(
literal|"Language name:"
argument_list|)
expr_stmt|;
name|nativeLanguageName
operator|=
name|addItem
argument_list|(
literal|"Native language name:"
argument_list|)
expr_stmt|;
name|scriptName
operator|=
name|addItem
argument_list|(
literal|"Script name:"
argument_list|)
expr_stmt|;
name|countryName
operator|=
name|addItem
argument_list|(
literal|"Country name:"
argument_list|)
expr_stmt|;
name|nativeCountryName
operator|=
name|addItem
argument_list|(
literal|"Native country name:"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|localeChanged
name|void
name|InfoWidget
operator|::
name|localeChanged
parameter_list|(
name|QLocale
name|locale
parameter_list|)
block|{
name|setLocale
argument_list|(
name|locale
argument_list|)
expr_stmt|;
name|name
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
name|bcp47Name
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|bcp47Name
argument_list|()
argument_list|)
expr_stmt|;
name|languageName
operator|->
name|setText
argument_list|(
name|QLocale
operator|::
name|languageToString
argument_list|(
name|locale
operator|.
name|language
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|nativeLanguageName
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|nativeLanguageName
argument_list|()
argument_list|)
expr_stmt|;
name|scriptName
operator|->
name|setText
argument_list|(
name|QLocale
operator|::
name|scriptToString
argument_list|(
name|locale
operator|.
name|script
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|countryName
operator|->
name|setText
argument_list|(
name|QLocale
operator|::
name|countryToString
argument_list|(
name|locale
operator|.
name|country
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|nativeCountryName
operator|->
name|setText
argument_list|(
name|locale
operator|.
name|nativeCountryName
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addItem
name|void
name|InfoWidget
operator|::
name|addItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|label
parameter_list|,
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
name|QLabel
modifier|*
name|lbl
init|=
operator|new
name|QLabel
argument_list|(
name|label
argument_list|)
decl_stmt|;
name|int
name|row
init|=
name|layout
operator|->
name|rowCount
argument_list|()
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|lbl
argument_list|,
name|row
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|w
argument_list|,
name|row
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addItem
name|QLineEdit
modifier|*
name|InfoWidget
operator|::
name|addItem
parameter_list|(
specifier|const
name|QString
modifier|&
name|label
parameter_list|)
block|{
name|QLineEdit
modifier|*
name|le
init|=
operator|new
name|QLineEdit
decl_stmt|;
name|le
operator|->
name|setReadOnly
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|addItem
argument_list|(
name|label
argument_list|,
name|le
argument_list|)
expr_stmt|;
return|return
name|le
return|;
block|}
end_function
end_unit
