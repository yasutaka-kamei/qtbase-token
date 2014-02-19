begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTTESTLOGGER_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTTESTLOGGER_P_H
define|#
directive|define
name|QABSTRACTTESTLOGGER_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<qglobal.h>
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QBenchmarkResult
name|class
name|QBenchmarkResult
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAbstractTestLogger
block|{
name|public
label|:
enum|enum
name|IncidentTypes
block|{
name|Pass
block|,
name|XFail
block|,
name|Fail
block|,
name|XPass
block|}
enum|;
enum|enum
name|MessageTypes
block|{
name|Warn
block|,
name|QWarning
block|,
name|QDebug
block|,
name|QSystem
block|,
name|QFatal
block|,
name|Skip
block|,
name|Info
block|}
enum|;
name|QAbstractTestLogger
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QAbstractTestLogger
argument_list|()
expr_stmt|;
name|virtual
name|void
name|startLogging
parameter_list|()
function_decl|;
name|virtual
name|void
name|stopLogging
parameter_list|()
function_decl|;
name|virtual
name|void
name|enterTestFunction
parameter_list|(
specifier|const
name|char
modifier|*
name|function
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|leaveTestFunction
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|addIncident
parameter_list|(
name|IncidentTypes
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|description
parameter_list|,
specifier|const
name|char
modifier|*
name|file
init|=
literal|0
parameter_list|,
name|int
name|line
init|=
literal|0
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|addBenchmarkResult
parameter_list|(
specifier|const
name|QBenchmarkResult
modifier|&
name|result
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|addMessage
parameter_list|(
name|MessageTypes
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|file
init|=
literal|0
parameter_list|,
name|int
name|line
init|=
literal|0
parameter_list|)
init|=
literal|0
function_decl|;
name|void
name|outputString
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
name|protected
label|:
name|void
name|filterUnprintable
argument_list|(
name|char
operator|*
name|str
argument_list|)
decl|const
decl_stmt|;
name|FILE
modifier|*
name|stream
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct
DECL|struct|QTestCharBuffer
struct|struct
name|QTestCharBuffer
block|{
DECL|enumerator|InitialSize
enum|enum
block|{
name|InitialSize
init|=
literal|512
block|}
enum|;
DECL|function|QTestCharBuffer
specifier|inline
name|QTestCharBuffer
argument_list|()
operator|:
name|_size
argument_list|(
name|InitialSize
argument_list|)
operator|,
name|buf
argument_list|(
argument|staticBuf
argument_list|)
block|{
name|staticBuf
index|[
literal|0
index|]
operator|=
literal|'\0'
block|;     }
DECL|function|~QTestCharBuffer
specifier|inline
operator|~
name|QTestCharBuffer
argument_list|()
block|{
if|if
condition|(
name|buf
operator|!=
name|staticBuf
condition|)
name|free
argument_list|(
name|buf
argument_list|)
expr_stmt|;
block|}
DECL|function|data
specifier|inline
name|char
modifier|*
name|data
parameter_list|()
block|{
return|return
name|buf
return|;
block|}
DECL|function|buffer
specifier|inline
name|char
modifier|*
modifier|*
name|buffer
parameter_list|()
block|{
return|return
operator|&
name|buf
return|;
block|}
DECL|function|constData
specifier|inline
specifier|const
name|char
operator|*
name|constData
argument_list|()
specifier|const
block|{
return|return
name|buf
return|;
block|}
DECL|function|size
specifier|inline
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|_size
return|;
block|}
DECL|function|reset
specifier|inline
name|bool
name|reset
parameter_list|(
name|int
name|newSize
parameter_list|)
block|{
name|char
modifier|*
name|newBuf
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|buf
operator|==
name|staticBuf
condition|)
block|{
comment|// if we point to our internal buffer, we need to malloc first
name|newBuf
operator|=
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|malloc
argument_list|(
name|newSize
argument_list|)
operator|)
expr_stmt|;
block|}
else|else
block|{
comment|// if we already malloc'ed, just realloc
name|newBuf
operator|=
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|realloc
argument_list|(
name|buf
argument_list|,
name|newSize
argument_list|)
operator|)
expr_stmt|;
block|}
comment|// if the allocation went wrong (newBuf == 0), we leave the object as is
if|if
condition|(
operator|!
name|newBuf
condition|)
return|return
name|false
return|;
name|_size
operator|=
name|newSize
expr_stmt|;
name|buf
operator|=
name|newBuf
expr_stmt|;
return|return
name|true
return|;
block|}
DECL|member|private
name|private
label|:
name|int
name|_size
decl_stmt|;
DECL|member|buf
name|char
modifier|*
name|buf
decl_stmt|;
DECL|member|staticBuf
name|char
name|staticBuf
index|[
name|InitialSize
index|]
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|namespace
name|QTest
block|{
name|int
name|qt_asprintf
parameter_list|(
name|QTestCharBuffer
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
