begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 David Faure<faure@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QCommandLineParser>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
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
name|app
operator|.
name|setApplicationVersion
argument_list|(
literal|"1.0"
argument_list|)
expr_stmt|;
comment|// Test for QCoreApplication::arguments()
specifier|const
name|QStringList
name|incomingArgs
init|=
name|QCoreApplication
operator|::
name|arguments
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
name|argc
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|incomingArgs
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|!=
name|QLatin1String
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"ERROR: arguments["
operator|<<
name|i
operator|<<
literal|"] was"
operator|<<
name|incomingArgs
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|<<
literal|"expected"
operator|<<
name|argv
index|[
name|i
index|]
expr_stmt|;
block|}
name|QCommandLineParser
name|parser
decl_stmt|;
name|parser
operator|.
name|setApplicationDescription
argument_list|(
literal|"Test helper"
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addHelpOption
argument_list|()
expr_stmt|;
name|parser
operator|.
name|addVersionOption
argument_list|()
expr_stmt|;
name|parser
operator|.
name|addPositionalArgument
argument_list|(
literal|"parsingMode"
argument_list|,
literal|"The parsing mode to test."
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addPositionalArgument
argument_list|(
literal|"command"
argument_list|,
literal|"The command to execute."
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|QCommandLineOption
argument_list|(
literal|"load"
argument_list|,
literal|"Load file from URL."
argument_list|,
literal|"url"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|QCommandLineOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
literal|"o"
operator|<<
literal|"output"
argument_list|,
literal|"Set output file."
argument_list|,
literal|"file"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|QCommandLineOption
argument_list|(
literal|"D"
argument_list|,
literal|"Define macro."
argument_list|,
literal|"key=value"
argument_list|)
argument_list|)
expr_stmt|;
comment|// An option with a longer description, to test wrapping
name|QCommandLineOption
name|noImplicitIncludesOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"n"
argument_list|)
operator|<<
name|QStringLiteral
argument_list|(
literal|"no-implicit-includes"
argument_list|)
argument_list|)
decl_stmt|;
name|noImplicitIncludesOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Disable magic generation of implicit #include-directives."
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|noImplicitIncludesOption
argument_list|)
expr_stmt|;
name|QCommandLineOption
name|newlineOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"newline"
argument_list|)
argument_list|)
decl_stmt|;
name|newlineOption
operator|.
name|setDescription
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"This is an option with a rather long\n"
literal|"description using explicit newline characters "
literal|"(but testing automatic wrapping too). In addition, "
literal|"here, we test breaking after a comma. Testing -option. "
literal|"Long URL: http://qt-project.org/wiki/How_to_create_a_library_with_Qt_and_use_it_in_an_application "
literal|"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|newlineOption
argument_list|)
expr_stmt|;
comment|// A hidden option
name|QCommandLineOption
name|hiddenOption
argument_list|(
name|QStringList
argument_list|()
operator|<<
name|QStringLiteral
argument_list|(
literal|"hidden"
argument_list|)
argument_list|)
decl_stmt|;
name|hiddenOption
operator|.
name|setDescription
argument_list|(
name|QStringLiteral
argument_list|(
literal|"THIS SHOULD NEVER APPEAR"
argument_list|)
argument_list|)
expr_stmt|;
name|hiddenOption
operator|.
name|setHidden
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|hiddenOption
argument_list|)
expr_stmt|;
comment|// This program supports different options depending on the "command" (first argument).
comment|// Call parse() to find out the positional arguments.
name|parser
operator|.
name|parse
argument_list|(
name|QCoreApplication
operator|::
name|arguments
argument_list|()
argument_list|)
expr_stmt|;
name|QStringList
name|args
init|=
name|parser
operator|.
name|positionalArguments
argument_list|()
decl_stmt|;
if|if
condition|(
name|args
operator|.
name|isEmpty
argument_list|()
condition|)
name|parser
operator|.
name|showHelp
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|parser
operator|.
name|setSingleDashWordOptionMode
argument_list|(
name|QCommandLineParser
operator|::
name|SingleDashWordOptionMode
argument_list|(
name|args
operator|.
name|takeFirst
argument_list|()
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|command
init|=
name|args
operator|.
name|isEmpty
argument_list|()
condition|?
name|QString
argument_list|()
else|:
name|args
operator|.
name|first
argument_list|()
decl_stmt|;
if|if
condition|(
name|command
operator|==
literal|"resize"
condition|)
block|{
name|parser
operator|.
name|clearPositionalArguments
argument_list|()
expr_stmt|;
name|parser
operator|.
name|addPositionalArgument
argument_list|(
literal|"resize"
argument_list|,
literal|"Resize the object to a new size."
argument_list|,
literal|"resize [resize_options]"
argument_list|)
expr_stmt|;
name|parser
operator|.
name|addOption
argument_list|(
name|QCommandLineOption
argument_list|(
literal|"size"
argument_list|,
literal|"New size."
argument_list|,
literal|"size"
argument_list|)
argument_list|)
expr_stmt|;
name|parser
operator|.
name|process
argument_list|(
name|app
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|size
init|=
name|parser
operator|.
name|value
argument_list|(
literal|"size"
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|"Resizing %s to %s and saving to %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|parser
operator|.
name|value
argument_list|(
literal|"load"
argument_list|)
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|size
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|parser
operator|.
name|value
argument_list|(
literal|"o"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Call process again, to handle unknown options this time.
name|parser
operator|.
name|process
argument_list|(
name|app
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"Positional arguments: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|parser
operator|.
name|positionalArguments
argument_list|()
operator|.
name|join
argument_list|(
literal|","
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Macros: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|parser
operator|.
name|values
argument_list|(
literal|"D"
argument_list|)
operator|.
name|join
argument_list|(
literal|","
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
