begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_comment
comment|//![1]
end_comment
begin_decl_stmt
name|QLoggingCategory
name|theFooArea
argument_list|(
literal|"foo"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLoggingCategory
name|theBarArea
argument_list|(
literal|"bar"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLoggingCategory
name|theBazArea
argument_list|(
literal|"baz"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//![1]
end_comment
begin_comment
comment|// Note: These locations are Ubuntu specific.
end_comment
begin_comment
comment|// Note: To make the example work with user permissions, make sure
end_comment
begin_comment
comment|// the files are user-writable and the path leading there accessible.
end_comment
begin_decl_stmt
DECL|variable|traceSwitch
specifier|const
name|char
name|traceSwitch
index|[]
init|=
literal|"/sys/kernel/debug/tracing/tracing_on"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|traceSink
specifier|const
name|char
name|traceSink
index|[]
init|=
literal|"/sys/kernel/debug/tracing/trace_marker"
decl_stmt|;
end_decl_stmt
begin_comment
comment|// The base class only serves as a facility to share code
end_comment
begin_comment
comment|// between the "single line" data logging aspect and the
end_comment
begin_comment
comment|// scoped "measuring" aspect.
end_comment
begin_comment
comment|// Both aspects and the base class could be combined into
end_comment
begin_comment
comment|// a single tracer serving both purposes, but are split
end_comment
begin_comment
comment|// here for clarity.
end_comment
begin_comment
comment|// Error handling is left as an exercise.
end_comment
begin_comment
comment|//![2]
end_comment
begin_class
DECL|class|MyTracerBase
class|class
name|MyTracerBase
super|:
specifier|public
name|QTracer
block|{
public|public:
DECL|function|MyTracerBase
name|MyTracerBase
parameter_list|()
block|{
name|enable
operator|=
operator|::
name|open
argument_list|(
name|traceSwitch
argument_list|,
name|O_WRONLY
argument_list|)
expr_stmt|;
name|marker
operator|=
operator|::
name|open
argument_list|(
name|traceSink
argument_list|,
name|O_WRONLY
argument_list|)
expr_stmt|;
block|}
DECL|function|~MyTracerBase
name|~
name|MyTracerBase
parameter_list|()
block|{
operator|::
name|close
argument_list|(
name|enable
argument_list|)
expr_stmt|;
operator|::
name|close
argument_list|(
name|marker
argument_list|)
expr_stmt|;
block|}
protected|protected:
DECL|member|enable
name|int
name|enable
decl_stmt|;
DECL|member|marker
name|int
name|marker
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//![2]
end_comment
begin_comment
comment|//![2]
end_comment
begin_class
DECL|class|MyTracer
class|class
name|MyTracer
super|:
specifier|public
name|MyTracerBase
block|{
public|public:
DECL|function|start
name|void
name|start
parameter_list|()
block|{
operator|::
name|write
argument_list|(
name|marker
argument_list|,
literal|"B"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
DECL|function|end
name|void
name|end
parameter_list|()
block|{
operator|::
name|write
argument_list|(
name|marker
argument_list|,
literal|"E"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_comment
comment|//![2]
end_comment
begin_comment
comment|//![3]
end_comment
begin_class
DECL|class|MyDataLogger
class|class
name|MyDataLogger
super|:
specifier|public
name|MyTracerBase
block|{
public|public:
DECL|function|MyDataLogger
name|MyDataLogger
parameter_list|()
block|{
name|buf
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|pos
operator|=
literal|0
expr_stmt|;
block|}
DECL|function|record
name|void
name|record
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|pos
operator|+=
name|sprintf
argument_list|(
name|buf
operator|+
name|pos
argument_list|,
literal|"%d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
DECL|function|record
name|void
name|record
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
block|{
name|pos
operator|+=
name|sprintf
argument_list|(
name|buf
operator|+
name|pos
argument_list|,
literal|"%s"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
block|}
DECL|function|end
name|void
name|end
parameter_list|()
block|{
operator|::
name|write
argument_list|(
name|marker
argument_list|,
name|buf
argument_list|,
name|pos
argument_list|)
expr_stmt|;
name|pos
operator|=
literal|0
expr_stmt|;
block|}
private|private:
DECL|member|buf
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
DECL|member|pos
name|int
name|pos
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|//![3]
end_comment
begin_comment
comment|// Simplest possible example for "measuring".
end_comment
begin_comment
comment|//![4]
end_comment
begin_function
DECL|function|foo
name|int
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|qCTraceGuard
argument_list|(
name|theFooArea
argument_list|)
expr_stmt|;
comment|// Here could be some lengthy code.
return|return
name|i
operator|*
name|i
return|;
block|}
end_function
begin_comment
comment|//![4]
end_comment
begin_comment
comment|// We can switch on/off tracing dynamically.
end_comment
begin_comment
comment|// The tracer will be temporarily switched off at the third call
end_comment
begin_comment
comment|// and re-enabled at the eighth.
end_comment
begin_comment
comment|//![5]
end_comment
begin_function
DECL|function|bar
name|int
name|bar
parameter_list|(
name|int
name|i
parameter_list|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
operator|++
name|n
expr_stmt|;
if|if
condition|(
name|n
operator|==
literal|3
condition|)
name|theBarArea
operator|.
name|setEnabled
argument_list|(
name|QtTraceMsg
argument_list|,
literal|false
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|==
literal|8
condition|)
name|theBarArea
operator|.
name|setEnabled
argument_list|(
name|QtTraceMsg
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|qCTraceGuard
argument_list|(
name|theBarArea
argument_list|)
expr_stmt|;
return|return
name|i
operator|*
name|i
return|;
block|}
end_function
begin_comment
comment|//![5]
end_comment
begin_comment
comment|// An example to create "complex" log messages.
end_comment
begin_comment
comment|//![6]
end_comment
begin_function
DECL|function|baz
name|int
name|baz
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|qCTrace
argument_list|(
name|theBazArea
argument_list|)
operator|<<
literal|32
operator|<<
literal|"some stuff"
expr_stmt|;
return|return
name|i
operator|*
name|i
return|;
block|}
end_function
begin_comment
comment|//![6]
end_comment
begin_comment
comment|//![7]
end_comment
begin_namespace
namespace|namespace
block|{
DECL|struct|Init
specifier|static
struct|struct
name|Init
block|{
DECL|function|Init
name|Init
parameter_list|()
block|{
name|tracer
operator|.
name|addToCategory
argument_list|(
name|theFooArea
argument_list|)
expr_stmt|;
name|tracer
operator|.
name|addToCategory
argument_list|(
name|theBarArea
argument_list|)
expr_stmt|;
name|logger
operator|.
name|addToCategory
argument_list|(
name|theBazArea
argument_list|)
expr_stmt|;
block|}
DECL|member|tracer
name|MyTracer
name|tracer
decl_stmt|;
DECL|member|logger
name|MyDataLogger
name|logger
decl_stmt|;
block|}
DECL|member|initializer
name|initializer
struct|;
block|}
end_namespace
begin_comment
comment|//![7]
end_comment
end_unit