begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtestbasicstreamer.h"
end_include
begin_include
include|#
directive|include
file|"qtestlogger_p.h"
end_include
begin_include
include|#
directive|include
file|"qtestelement.h"
end_include
begin_include
include|#
directive|include
file|"qtestelementattribute.h"
end_include
begin_include
include|#
directive|include
file|"qtestassert.h"
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WIN
end_ifndef
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QTestBasicStreamer
name|QTestBasicStreamer
operator|::
name|QTestBasicStreamer
parameter_list|(
name|QTestLogger
modifier|*
name|logger
parameter_list|)
member_init_list|:
name|testLogger
argument_list|(
name|logger
argument_list|)
block|{
name|QTEST_ASSERT
argument_list|(
name|testLogger
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QTestBasicStreamer
name|QTestBasicStreamer
operator|::
name|~
name|QTestBasicStreamer
parameter_list|()
block|{}
end_destructor
begin_function
DECL|function|formatStart
name|void
name|QTestBasicStreamer
operator|::
name|formatStart
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatEnd
name|void
name|QTestBasicStreamer
operator|::
name|formatEnd
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatBeforeAttributes
name|void
name|QTestBasicStreamer
operator|::
name|formatBeforeAttributes
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatAfterAttributes
name|void
name|QTestBasicStreamer
operator|::
name|formatAfterAttributes
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatAttributes
name|void
name|QTestBasicStreamer
operator|::
name|formatAttributes
parameter_list|(
specifier|const
name|QTestElement
modifier|*
parameter_list|,
specifier|const
name|QTestElementAttribute
modifier|*
name|attribute
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|attribute
operator|||
operator|!
name|formatted
condition|)
return|return;
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function
begin_function
DECL|function|output
name|void
name|QTestBasicStreamer
operator|::
name|output
parameter_list|(
name|QTestElement
modifier|*
name|element
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
condition|)
return|return;
name|outputElements
argument_list|(
name|element
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|outputElements
name|void
name|QTestBasicStreamer
operator|::
name|outputElements
parameter_list|(
name|QTestElement
modifier|*
name|element
parameter_list|,
name|bool
parameter_list|)
specifier|const
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
name|bool
name|hasChildren
decl_stmt|;
comment|/*         Elements are in reverse order of occurrence, so start from the end and work         our way backwards.     */
while|while
condition|(
name|element
operator|&&
name|element
operator|->
name|nextElement
argument_list|()
condition|)
block|{
name|element
operator|=
name|element
operator|->
name|nextElement
argument_list|()
expr_stmt|;
block|}
while|while
condition|(
name|element
condition|)
block|{
name|hasChildren
operator|=
name|element
operator|->
name|childElements
argument_list|()
expr_stmt|;
name|formatStart
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|formatBeforeAttributes
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|outputElementAttributes
argument_list|(
name|element
argument_list|,
name|element
operator|->
name|attributes
argument_list|()
argument_list|)
expr_stmt|;
name|formatAfterAttributes
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasChildren
condition|)
name|outputElements
argument_list|(
name|element
operator|->
name|childElements
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|formatEnd
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|element
operator|=
name|element
operator|->
name|previousElement
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|outputElementAttributes
name|void
name|QTestBasicStreamer
operator|::
name|outputElementAttributes
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestElementAttribute
modifier|*
name|attribute
parameter_list|)
specifier|const
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
while|while
condition|(
name|attribute
condition|)
block|{
name|formatAttributes
argument_list|(
name|element
argument_list|,
name|attribute
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|attribute
operator|=
name|attribute
operator|->
name|nextElement
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|outputString
name|void
name|QTestBasicStreamer
operator|::
name|outputString
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
specifier|const
block|{
name|testLogger
operator|->
name|outputString
argument_list|(
name|msg
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|logger
name|QTestLogger
modifier|*
name|QTestBasicStreamer
operator|::
name|logger
parameter_list|()
specifier|const
block|{
return|return
name|testLogger
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
