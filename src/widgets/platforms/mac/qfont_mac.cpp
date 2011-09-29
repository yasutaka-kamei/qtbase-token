begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfont.h"
end_include
begin_include
include|#
directive|include
file|"qfont_p.h"
end_include
begin_include
include|#
directive|include
file|"qfontengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qfontengine_mac_p.h"
end_include
begin_include
include|#
directive|include
file|"qfontengine_coretext_p.h"
end_include
begin_include
include|#
directive|include
file|"qfontinfo.h"
end_include
begin_include
include|#
directive|include
file|"qfontmetrics.h"
end_include
begin_include
include|#
directive|include
file|"qpaintdevice.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|<private/qt_mac_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qtextengine_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qunicodetables_p.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|"qfontdatabase.h"
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|"qtextengine_p.h"
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
specifier|extern
name|float
name|qt_mac_defaultDpi_x
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//qpaintdevice_mac.cpp
end_comment
begin_function
DECL|function|qt_mac_pixelsize
name|int
name|qt_mac_pixelsize
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|def
parameter_list|,
name|int
name|dpi
parameter_list|)
block|{
name|float
name|ret
decl_stmt|;
if|if
condition|(
name|def
operator|.
name|pixelSize
operator|==
operator|-
literal|1
condition|)
name|ret
operator|=
name|def
operator|.
name|pointSize
operator|*
name|dpi
operator|/
name|qt_mac_defaultDpi_x
argument_list|()
expr_stmt|;
else|else
name|ret
operator|=
name|def
operator|.
name|pixelSize
expr_stmt|;
return|return
name|qRound
argument_list|(
name|ret
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_mac_pointsize
name|int
name|qt_mac_pointsize
parameter_list|(
specifier|const
name|QFontDef
modifier|&
name|def
parameter_list|,
name|int
name|dpi
parameter_list|)
block|{
name|float
name|ret
decl_stmt|;
if|if
condition|(
name|def
operator|.
name|pointSize
operator|<
literal|0
condition|)
name|ret
operator|=
name|def
operator|.
name|pixelSize
operator|*
name|qt_mac_defaultDpi_x
argument_list|()
operator|/
name|float
argument_list|(
name|dpi
argument_list|)
expr_stmt|;
else|else
name|ret
operator|=
name|def
operator|.
name|pointSize
expr_stmt|;
return|return
name|qRound
argument_list|(
name|ret
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|rawName
name|QString
name|QFont
operator|::
name|rawName
parameter_list|()
specifier|const
block|{
return|return
name|family
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setRawName
name|void
name|QFont
operator|::
name|setRawName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|setFamily
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|QFont
operator|::
name|cleanup
parameter_list|()
block|{
name|QFontCache
operator|::
name|cleanup
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns an ATSUFontID */
end_comment
begin_function
DECL|function|macFontID
name|quint32
name|QFont
operator|::
name|macFontID
parameter_list|()
specifier|const
comment|// ### need 64-bit version
block|{
return|return
literal|0
return|;
elif|#
directive|elif
literal|1
name|QFontEngine
modifier|*
name|fe
init|=
name|d
operator|->
name|engineForScript
argument_list|(
name|QUnicodeTables
operator|::
name|Common
argument_list|)
decl_stmt|;
if|if
condition|(
name|fe
operator|&&
name|fe
operator|->
name|type
argument_list|()
operator|==
name|QFontEngine
operator|::
name|Multi
condition|)
return|return
cast|static_cast
argument_list|<
name|QFontEngineMacMulti
operator|*
argument_list|>
argument_list|(
name|fe
argument_list|)
operator|->
name|macFontID
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|// Returns an ATSUFonFamilyRef
end_comment
begin_function
DECL|function|handle
name|Qt
operator|::
name|HANDLE
name|QFont
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|QFontEngine
modifier|*
name|fe
init|=
name|d
operator|->
name|engineForScript
argument_list|(
name|QUnicodeTables
operator|::
name|Common
argument_list|)
decl_stmt|;
if|if
condition|(
name|fe
operator|&&
name|fe
operator|->
name|type
argument_list|()
operator|==
name|QFontEngine
operator|::
name|Multi
condition|)
return|return
operator|(
name|Qt
operator|::
name|HANDLE
operator|)
cast|static_cast
argument_list|<
name|QCoreTextFontEngineMulti
operator|*
argument_list|>
argument_list|(
name|fe
argument_list|)
operator|->
name|macFontID
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|initialize
name|void
name|QFont
operator|::
name|initialize
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|defaultFamily
name|QString
name|QFont
operator|::
name|defaultFamily
parameter_list|()
specifier|const
block|{
switch|switch
condition|(
name|d
operator|->
name|request
operator|.
name|styleHint
condition|)
block|{
case|case
name|QFont
operator|::
name|Times
case|:
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Times New Roman"
argument_list|)
return|;
case|case
name|QFont
operator|::
name|Courier
case|:
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Courier New"
argument_list|)
return|;
case|case
name|QFont
operator|::
name|Monospace
case|:
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Courier"
argument_list|)
return|;
case|case
name|QFont
operator|::
name|Decorative
case|:
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Bookman Old Style"
argument_list|)
return|;
case|case
name|QFont
operator|::
name|Cursive
case|:
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Apple Chancery"
argument_list|)
return|;
case|case
name|QFont
operator|::
name|Fantasy
case|:
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Papyrus"
argument_list|)
return|;
case|case
name|QFont
operator|::
name|Helvetica
case|:
case|case
name|QFont
operator|::
name|System
case|:
default|default:
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Helvetica"
argument_list|)
return|;
block|}
block|}
end_function
begin_function
DECL|function|lastResortFamily
name|QString
name|QFont
operator|::
name|lastResortFamily
parameter_list|()
specifier|const
block|{
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Helvetica"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|lastResortFont
name|QString
name|QFont
operator|::
name|lastResortFont
parameter_list|()
specifier|const
block|{
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Geneva"
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
