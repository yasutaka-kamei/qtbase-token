begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
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
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"usage: stdinprocess<all|line<0|1>>\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"echos all its input to its output.\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|QFile
name|file
decl_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"all"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|file
operator|.
name|open
argument_list|(
name|stdin
argument_list|,
name|QFile
operator|::
name|ReadWrite
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|file
operator|.
name|readAll
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"line"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|,
literal|"0"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|file
operator|.
name|open
argument_list|(
name|stdin
argument_list|,
name|QFile
operator|::
name|ReadWrite
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|file
operator|.
name|open
argument_list|(
literal|0
argument_list|,
name|QFile
operator|::
name|ReadWrite
argument_list|)
expr_stmt|;
block|}
name|char
name|line
index|[
literal|1024
index|]
decl_stmt|;
while|while
condition|(
name|file
operator|.
name|readLine
argument_list|(
name|line
argument_list|,
sizeof|sizeof
argument_list|(
name|line
argument_list|)
argument_list|)
operator|>
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
end_unit
