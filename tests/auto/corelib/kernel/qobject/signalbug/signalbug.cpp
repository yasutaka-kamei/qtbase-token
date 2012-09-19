begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"signalbug.h"
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_decl_stmt
DECL|variable|Step
specifier|static
name|int
name|Step
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Sender
name|RandomSender
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|TRACE
name|void
name|TRACE
parameter_list|(
name|int
name|step
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
for|for
control|(
name|int
name|t
init|=
literal|0
init|;
name|t
operator|<
name|step
operator|-
literal|1
condition|;
name|t
operator|++
control|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Step %d: %s\n"
argument_list|,
name|step
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return;
block|}
end_function
begin_constructor
DECL|function|Receiver
name|Receiver
operator|::
name|Receiver
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
block|{ }
end_constructor
begin_function
DECL|function|received
name|void
name|Receiver
operator|::
name|received
parameter_list|()
block|{
operator|::
name|Step
operator|++
expr_stmt|;
specifier|const
name|int
name|stepCopy
init|=
operator|::
name|Step
decl_stmt|;
name|TRACE
argument_list|(
name|stepCopy
argument_list|,
literal|"Receiver::received()"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|::
name|Step
operator|!=
literal|2
operator|&&
operator|::
name|Step
operator|!=
literal|4
condition|)
name|qFatal
argument_list|(
literal|"%s: Incorrect Step: %d (should be 2 or 4)"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
operator|::
name|Step
argument_list|)
expr_stmt|;
if|if
condition|(
operator|::
name|Step
operator|==
literal|2
condition|)
name|s
operator|->
name|fire
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Receiver<%s>::received() sender=%s\n"
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|objectName
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|sender
argument_list|()
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|)
expr_stmt|;
name|TRACE
argument_list|(
name|stepCopy
argument_list|,
literal|"ends Receiver::received()"
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|Disconnector
name|Disconnector
operator|::
name|Disconnector
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
block|{ }
end_constructor
begin_function
DECL|function|received
name|void
name|Disconnector
operator|::
name|received
parameter_list|()
block|{
operator|::
name|Step
operator|++
expr_stmt|;
specifier|const
name|int
name|stepCopy
init|=
operator|::
name|Step
decl_stmt|;
name|TRACE
argument_list|(
name|stepCopy
argument_list|,
literal|"Disconnector::received()"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|::
name|Step
operator|!=
literal|5
operator|&&
operator|::
name|Step
operator|!=
literal|6
condition|)
name|qFatal
argument_list|(
literal|"%s: Incorrect Step: %d (should be 5 or 6)"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
operator|::
name|Step
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Disconnector<%s>::received() sender=%s\n"
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|objectName
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|,
name|sender
argument_list|()
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|sender
argument_list|()
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"WE SHOULD NOT BE RECEIVING THIS SIGNAL\n"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|::
name|Step
operator|==
literal|5
condition|)
block|{
name|disconnect
argument_list|(
name|s
argument_list|,
name|SIGNAL
argument_list|(
name|fired
argument_list|()
argument_list|)
argument_list|,
name|s
operator|->
name|d
argument_list|,
name|SLOT
argument_list|(
name|received
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|RandomSender
argument_list|,
name|SIGNAL
argument_list|(
name|fired
argument_list|()
argument_list|)
argument_list|,
name|s
operator|->
name|d
argument_list|,
name|SLOT
argument_list|(
name|received
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|TRACE
argument_list|(
name|stepCopy
argument_list|,
literal|"ends Disconnector::received()"
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|Sender
name|Sender
operator|::
name|Sender
parameter_list|(
name|Receiver
modifier|*
name|r
parameter_list|,
name|Disconnector
modifier|*
name|d
parameter_list|)
member_init_list|:
name|QObject
argument_list|()
block|{
name|this
operator|->
name|r
operator|=
name|r
expr_stmt|;
name|this
operator|->
name|d
operator|=
name|d
expr_stmt|;
if|if
condition|(
name|r
condition|)
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|fired
argument_list|()
argument_list|)
argument_list|,
name|r
argument_list|,
name|SLOT
argument_list|(
name|received
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
condition|)
name|connect
argument_list|(
name|this
argument_list|,
name|SIGNAL
argument_list|(
name|fired
argument_list|()
argument_list|)
argument_list|,
name|d
argument_list|,
name|SLOT
argument_list|(
name|received
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function
DECL|function|fire
name|void
name|Sender
operator|::
name|fire
parameter_list|()
block|{
operator|::
name|Step
operator|++
expr_stmt|;
specifier|const
name|int
name|stepCopy
init|=
operator|::
name|Step
decl_stmt|;
name|TRACE
argument_list|(
name|stepCopy
argument_list|,
literal|"Sender::fire()"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|::
name|Step
operator|!=
literal|1
operator|&&
operator|::
name|Step
operator|!=
literal|3
condition|)
name|qFatal
argument_list|(
literal|"%s: Incorrect Step: %d (should be 1 or 3)"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
operator|::
name|Step
argument_list|)
expr_stmt|;
emit|emit
name|fired
argument_list|()
emit|;
name|TRACE
argument_list|(
name|stepCopy
argument_list|,
literal|"ends Sender::fire()"
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
name|Receiver
name|r
decl_stmt|;
name|Disconnector
name|d
decl_stmt|;
name|Sender
name|s
argument_list|(
operator|&
name|r
argument_list|,
operator|&
name|d
argument_list|)
decl_stmt|;
name|r
operator|.
name|s
operator|=
operator|&
name|s
expr_stmt|;
name|d
operator|.
name|s
operator|=
operator|&
name|s
expr_stmt|;
operator|::
name|Step
operator|=
literal|0
expr_stmt|;
name|s
operator|.
name|fire
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
