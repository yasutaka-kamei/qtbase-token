begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the utilities of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"codegenerator.h"
end_include
begin_include
include|#
directive|include
file|"legacyspecparser.h"
end_include
begin_include
include|#
directive|include
file|"xmlspecparser.h"
end_include
begin_include
include|#
directive|include
file|<QCommandLineParser>
end_include
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
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QCommandLineParser
name|cmdParser
decl_stmt|;
comment|// flag whether to use legacy or not
name|QCommandLineOption
name|legacyOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
literal|"l"
operator|<<
literal|"legacy"
argument_list|,
literal|"Use legacy parser."
argument_list|)
decl_stmt|;
name|cmdParser
operator|.
name|addOption
argument_list|(
name|legacyOption
argument_list|)
expr_stmt|;
name|cmdParser
operator|.
name|process
argument_list|(
name|app
argument_list|)
expr_stmt|;
name|SpecParser
modifier|*
name|parser
decl_stmt|;
if|if
condition|(
name|cmdParser
operator|.
name|isSet
argument_list|(
name|legacyOption
argument_list|)
condition|)
block|{
name|parser
operator|=
operator|new
name|LegacySpecParser
argument_list|()
expr_stmt|;
name|parser
operator|->
name|setTypeMapFileName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gl.tm"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|->
name|setSpecFileName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gl.spec"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|parser
operator|=
operator|new
name|XmlSpecParser
argument_list|()
expr_stmt|;
name|parser
operator|->
name|setSpecFileName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"gl.xml"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|parser
operator|->
name|parse
argument_list|()
expr_stmt|;
name|CodeGenerator
name|generator
decl_stmt|;
name|generator
operator|.
name|setParser
argument_list|(
name|parser
argument_list|)
expr_stmt|;
name|generator
operator|.
name|generateCoreClasses
argument_list|(
name|QStringLiteral
argument_list|(
literal|"qopenglversionfunctions"
argument_list|)
argument_list|)
expr_stmt|;
name|generator
operator|.
name|generateExtensionClasses
argument_list|(
name|QStringLiteral
argument_list|(
literal|"qopenglextensions"
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
name|parser
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
