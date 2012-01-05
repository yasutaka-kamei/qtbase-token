begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qtextstream.h>
end_include
begin_include
include|#
directive|include
file|"parser.h"
end_include
begin_function_decl
specifier|static
name|QTextStream
name|qout
parameter_list|(
name|stdout
parameter_list|,
name|QIODevice
operator|::
name|WriteOnly
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QTextStream
name|qerr
parameter_list|(
name|stderr
parameter_list|,
name|QIODevice
operator|::
name|WriteOnly
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|usage
specifier|static
name|void
name|usage
parameter_list|()
block|{
name|qerr
operator|<<
literal|"Usage: parse [-report-whitespace-only-chardata] [-report-start-end-entity]<in-file> [<out-file>]\n"
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QString
name|file_name
decl_stmt|;
name|QString
name|out_file_name
decl_stmt|;
name|bool
name|report_start_end_entity
init|=
literal|false
decl_stmt|;
name|bool
name|report_whitespace_only_chardata
init|=
literal|false
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|arg
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-report-whitespace-only-chardata"
argument_list|)
condition|)
name|report_whitespace_only_chardata
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-report-start-end-entity"
argument_list|)
condition|)
name|report_start_end_entity
operator|=
literal|true
expr_stmt|;
elseif|else
if|if
condition|(
name|file_name
operator|.
name|isEmpty
argument_list|()
condition|)
name|file_name
operator|=
name|arg
expr_stmt|;
elseif|else
if|if
condition|(
name|out_file_name
operator|.
name|isEmpty
argument_list|()
condition|)
name|out_file_name
operator|=
name|arg
expr_stmt|;
else|else
name|usage
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|file_name
operator|.
name|isEmpty
argument_list|()
condition|)
name|usage
argument_list|()
expr_stmt|;
name|QFile
name|in_file
argument_list|(
name|file_name
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|in_file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|qerr
operator|<<
literal|"Could not open "
operator|<<
name|file_name
operator|<<
literal|": "
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
operator|<<
name|endl
expr_stmt|;
return|return
literal|1
return|;
block|}
if|if
condition|(
name|out_file_name
operator|.
name|isEmpty
argument_list|()
condition|)
name|out_file_name
operator|=
name|file_name
operator|+
literal|".ref"
expr_stmt|;
name|QFile
name|_out_file
decl_stmt|;
name|QTextStream
name|_out_stream
decl_stmt|;
name|QTextStream
modifier|*
name|out_stream
decl_stmt|;
if|if
condition|(
name|out_file_name
operator|==
literal|"-"
condition|)
block|{
name|out_stream
operator|=
operator|&
name|qout
expr_stmt|;
block|}
else|else
block|{
name|_out_file
operator|.
name|setFileName
argument_list|(
name|out_file_name
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|_out_file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QIODevice
operator|::
name|Truncate
argument_list|)
condition|)
block|{
name|qerr
operator|<<
literal|"Could not open "
operator|<<
name|out_file_name
operator|<<
literal|": "
operator|<<
name|strerror
argument_list|(
name|errno
argument_list|)
operator|<<
name|endl
expr_stmt|;
return|return
literal|1
return|;
block|}
name|_out_stream
operator|.
name|setDevice
argument_list|(
operator|&
name|_out_file
argument_list|)
expr_stmt|;
name|out_stream
operator|=
operator|&
name|_out_stream
expr_stmt|;
block|}
name|Parser
name|parser
decl_stmt|;
if|if
condition|(
name|report_start_end_entity
condition|)
name|parser
operator|.
name|setFeature
argument_list|(
literal|"http://trolltech.com/xml/features/report-start-end-entity"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
if|if
condition|(
name|report_whitespace_only_chardata
condition|)
name|parser
operator|.
name|setFeature
argument_list|(
literal|"http://trolltech.com/xml/features/report-whitespace-only-CharData"
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|parser
operator|.
name|parseFile
argument_list|(
operator|&
name|in_file
argument_list|)
expr_stmt|;
name|out_stream
operator|->
name|setCodec
argument_list|(
literal|"utf8"
argument_list|)
expr_stmt|;
operator|*
name|out_stream
operator|<<
name|parser
operator|.
name|result
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
