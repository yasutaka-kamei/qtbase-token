begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
name|QSettings
name|settings
argument_list|(
literal|"MySoft"
argument_list|,
literal|"Star Runner"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|color
name|QColor
name|color
init|=
name|settings
operator|.
name|value
argument_list|(
literal|"DataPump/bgcolor"
argument_list|)
operator|.
name|value
argument_list|<
name|QColor
argument_list|>
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
name|QSettings
name|settings
argument_list|(
literal|"MySoft"
argument_list|,
literal|"Star Runner"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|color
name|QColor
name|color
init|=
name|palette
argument_list|()
operator|.
name|background
argument_list|()
operator|.
name|color
argument_list|()
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"DataPump/bgcolor"
argument_list|,
name|color
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
name|QSettings
name|settings
argument_list|(
literal|"/home/petra/misc/myapp.ini"
argument_list|,
name|QSettings
operator|::
name|IniFormat
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
name|QSettings
name|settings
argument_list|(
literal|"/Users/petra/misc/myapp.plist"
argument_list|,
name|QSettings
operator|::
name|NativeFormat
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
name|QSettings
name|settings
argument_list|(
literal|"HKEY_CURRENT_USER\\Software\\Microsoft\\Office"
argument_list|,
name|QSettings
operator|::
name|NativeFormat
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"11.0/Outlook/Security/DontTrustInstalledFiles"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"HKEY_CURRENT_USER\\MySoft\\Star Runner\\Galaxy"
argument_list|,
literal|"Milkyway"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"HKEY_CURRENT_USER\\MySoft\\Star Runner\\Galaxy\\Sun"
argument_list|,
literal|"OurStar"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|value
argument_list|(
literal|"HKEY_CURRENT_USER\\MySoft\\Star Runner\\Galaxy\\Default"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns "Milkyway"
end_comment
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_decl_stmt
name|QSettings
name|settings
argument_list|(
literal|"grenoullelogique.fr"
argument_list|,
literal|"Squash"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_else
else|#
directive|else
end_else
begin_decl_stmt
name|QSettings
name|settings
argument_list|(
literal|"Grenoulle Logique"
argument_list|,
literal|"Squash"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_expr_stmt
name|pos
operator|=
expr|@
name|Point
argument_list|(
literal|100
literal|100
argument_list|)
comment|//! [8]
comment|//! [9]
name|windir
operator|=
name|C
operator|:
operator|\
name|Windows
comment|//! [9]
comment|//! [10]
name|QSettings
name|settings
argument_list|(
literal|"Moose Tech"
argument_list|,
literal|"Facturo-Pro"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
name|QSettings
name|settings
argument_list|(
literal|"Moose Soft"
argument_list|,
literal|"Facturo-Pro"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_expr_stmt
name|QCoreApplication
operator|::
name|setOrganizationName
argument_list|(
literal|"Moose Soft"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QCoreApplication
operator|::
name|setApplicationName
argument_list|(
literal|"Facturo-Pro"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|settings
name|QSettings
name|settings
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_expr_stmt
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"mainwindow"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"size"
argument_list|,
name|win
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"fullScreen"
argument_list|,
name|win
operator|->
name|isFullScreen
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"outputpanel"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"visible"
argument_list|,
name|panel
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_expr_stmt
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"alpha"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// settings.group() == "alpha"
end_comment
begin_expr_stmt
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"beta"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// settings.group() == "alpha/beta"
end_comment
begin_expr_stmt
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// settings.group() == "alpha"
end_comment
begin_expr_stmt
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// settings.group() == ""
end_comment
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_struct
DECL|struct|Login
struct|struct
name|Login
block|{
DECL|member|userName
name|QString
name|userName
decl_stmt|;
DECL|member|password
name|QString
name|password
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|logins
name|QList
argument_list|<
name|Login
argument_list|>
name|logins
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
name|QSettings
name|settings
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|size
name|int
name|size
init|=
name|settings
operator|.
name|beginReadArray
argument_list|(
literal|"logins"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
name|settings
operator|.
name|setArrayIndex
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|Login
name|login
decl_stmt|;
name|login
operator|.
name|userName
operator|=
name|settings
operator|.
name|value
argument_list|(
literal|"userName"
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|login
operator|.
name|password
operator|=
name|settings
operator|.
name|value
argument_list|(
literal|"password"
argument_list|)
operator|.
name|toString
argument_list|()
expr_stmt|;
name|logins
operator|.
name|append
argument_list|(
name|login
argument_list|)
expr_stmt|;
block|}
end_for
begin_expr_stmt
name|settings
operator|.
name|endArray
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_struct
DECL|struct|Login
struct|struct
name|Login
block|{
DECL|member|userName
name|QString
name|userName
decl_stmt|;
DECL|member|password
name|QString
name|password
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|logins
name|QList
argument_list|<
name|Login
argument_list|>
name|logins
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
name|QSettings
name|settings
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|beginWriteArray
argument_list|(
literal|"logins"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|logins
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|settings
operator|.
name|setArrayIndex
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"userName"
argument_list|,
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|userName
argument_list|)
expr_stmt|;
name|settings
operator|.
name|setValue
argument_list|(
literal|"password"
argument_list|,
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|password
argument_list|)
expr_stmt|;
block|}
end_for
begin_expr_stmt
name|settings
operator|.
name|endArray
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_decl_stmt
DECL|variable|settings
name|QSettings
name|settings
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"fridge/color"
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"fridge/size"
argument_list|,
name|QSize
argument_list|(
literal|32
argument_list|,
literal|96
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"sofa"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"tv"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|keys
name|QStringList
name|keys
init|=
name|settings
operator|.
name|allKeys
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|// keys: ["fridge/color", "fridge/size", "sofa", "tv"]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_expr_stmt
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"fridge"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|keys
operator|=
name|settings
operator|.
name|allKeys
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// keys: ["color", "size"]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_decl_stmt
DECL|variable|settings
name|QSettings
name|settings
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"fridge/color"
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"fridge/size"
argument_list|,
name|QSize
argument_list|(
literal|32
argument_list|,
literal|96
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"sofa"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"tv"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|keys
name|QStringList
name|keys
init|=
name|settings
operator|.
name|childKeys
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|// keys: ["sofa", "tv"]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_expr_stmt
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"fridge"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|keys
operator|=
name|settings
operator|.
name|childKeys
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// keys: ["color", "size"]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_decl_stmt
DECL|variable|settings
name|QSettings
name|settings
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"fridge/color"
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"fridge/size"
argument_list|,
name|QSize
argument_list|(
literal|32
argument_list|,
literal|96
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"sofa"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"tv"
argument_list|,
literal|false
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|groups
name|QStringList
name|groups
init|=
name|settings
operator|.
name|childGroups
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|// groups: ["fridge"]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_comment
comment|//! [22]
end_comment
begin_expr_stmt
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"fridge"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|groups
operator|=
name|settings
operator|.
name|childGroups
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// groups: []
end_comment
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [23]
end_comment
begin_decl_stmt
DECL|variable|settings
name|QSettings
name|settings
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"interval"
argument_list|,
literal|30
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|value
argument_list|(
literal|"interval"
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 30
end_comment
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"interval"
argument_list|,
literal|6.55
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|value
argument_list|(
literal|"interval"
argument_list|)
operator|.
name|toDouble
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 6.55
end_comment
begin_comment
comment|//! [23]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_decl_stmt
DECL|variable|settings
name|QSettings
name|settings
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"ape"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"monkey"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"monkey/sea"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"monkey/doe"
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|remove
argument_list|(
literal|"monkey"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|keys
name|QStringList
name|keys
init|=
name|settings
operator|.
name|allKeys
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|// keys: ["ape"]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [25]
end_comment
begin_decl_stmt
DECL|variable|settings
name|QSettings
name|settings
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"ape"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"monkey"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"monkey/sea"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"monkey/doe"
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|beginGroup
argument_list|(
literal|"monkey"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|remove
argument_list|(
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|endGroup
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|keys
name|QStringList
name|keys
init|=
name|settings
operator|.
name|allKeys
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|// keys: ["ape"]
end_comment
begin_comment
comment|//! [25]
end_comment
begin_comment
comment|//! [26]
end_comment
begin_decl_stmt
DECL|variable|settings
name|QSettings
name|settings
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|settings
operator|.
name|setValue
argument_list|(
literal|"animal/snake"
argument_list|,
literal|58
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|settings
operator|.
name|value
argument_list|(
literal|"animal/snake"
argument_list|,
literal|1024
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 58
end_comment
begin_expr_stmt
name|settings
operator|.
name|value
argument_list|(
literal|"animal/zebra"
argument_list|,
literal|1024
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 1024
end_comment
begin_expr_stmt
name|settings
operator|.
name|value
argument_list|(
literal|"animal/zebra"
argument_list|)
operator|.
name|toInt
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// returns 0
end_comment
begin_comment
comment|//! [26]
end_comment
begin_comment
comment|//! [27]
end_comment
begin_function_decl
name|bool
name|myReadFunc
parameter_list|(
name|QIODevice
modifier|&
name|device
parameter_list|,
name|QSettings
operator|::
name|SettingsMap
modifier|&
name|map
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//! [27]
end_comment
begin_comment
comment|//! [28]
end_comment
begin_function_decl
name|bool
name|myWriteFunc
parameter_list|(
name|QIODevice
modifier|&
name|device
parameter_list|,
specifier|const
name|QSettings
operator|::
name|SettingsMap
modifier|&
name|map
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//! [28]
end_comment
begin_comment
comment|//! [29]
end_comment
begin_function_decl
name|bool
name|readXmlFile
parameter_list|(
name|QIODevice
modifier|&
name|device
parameter_list|,
name|QSettings
operator|::
name|SettingsMap
modifier|&
name|map
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|writeXmlFile
parameter_list|(
name|QIODevice
modifier|&
name|device
parameter_list|,
specifier|const
name|QSettings
operator|::
name|SettingsMap
modifier|&
name|map
parameter_list|)
function_decl|;
end_function_decl
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
specifier|const
name|QSettings
operator|::
name|Format
name|XmlFormat
init|=
name|QSettings
operator|::
name|registerFormat
argument_list|(
literal|"xml"
argument_list|,
name|readXmlFile
argument_list|,
name|writeXmlFile
argument_list|)
decl_stmt|;
name|QSettings
name|settings
argument_list|(
name|XmlFormat
argument_list|,
name|QSettings
operator|::
name|UserScope
argument_list|,
literal|"MySoft"
argument_list|,
literal|"Star Runner"
argument_list|)
decl_stmt|;
operator|...
block|}
end_function
begin_comment
comment|//! [29]
end_comment
end_unit
