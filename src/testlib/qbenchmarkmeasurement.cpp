begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkmeasurement_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmark_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkmetric_p.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qbenchmark.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|// QBenchmarkTimeMeasurer implementation
DECL|function|start
name|void
name|QBenchmarkTimeMeasurer
operator|::
name|start
parameter_list|()
block|{
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkpoint
name|qint64
name|QBenchmarkTimeMeasurer
operator|::
name|checkpoint
parameter_list|()
block|{
return|return
name|time
operator|.
name|elapsed
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|stop
name|qint64
name|QBenchmarkTimeMeasurer
operator|::
name|stop
parameter_list|()
block|{
return|return
name|time
operator|.
name|elapsed
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isMeasurementAccepted
name|bool
name|QBenchmarkTimeMeasurer
operator|::
name|isMeasurementAccepted
parameter_list|(
name|qint64
name|measurement
parameter_list|)
block|{
return|return
operator|(
name|measurement
operator|>
literal|50
operator|)
return|;
block|}
end_function
begin_function
DECL|function|adjustIterationCount
name|int
name|QBenchmarkTimeMeasurer
operator|::
name|adjustIterationCount
parameter_list|(
name|int
name|suggestion
parameter_list|)
block|{
return|return
name|suggestion
return|;
block|}
end_function
begin_function
DECL|function|needsWarmupIteration
name|bool
name|QBenchmarkTimeMeasurer
operator|::
name|needsWarmupIteration
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|adjustMedianCount
name|int
name|QBenchmarkTimeMeasurer
operator|::
name|adjustMedianCount
parameter_list|(
name|int
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|metricType
name|QTest
operator|::
name|QBenchmarkMetric
name|QBenchmarkTimeMeasurer
operator|::
name|metricType
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|WalltimeMilliseconds
return|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TICK_COUNTER
end_ifdef
begin_comment
comment|// defined in 3rdparty/cycle_p.h
end_comment
begin_function
DECL|function|start
name|void
name|QBenchmarkTickMeasurer
operator|::
name|start
parameter_list|()
block|{
name|startTicks
operator|=
name|getticks
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkpoint
name|qint64
name|QBenchmarkTickMeasurer
operator|::
name|checkpoint
parameter_list|()
block|{
name|CycleCounterTicks
name|now
init|=
name|getticks
argument_list|()
decl_stmt|;
return|return
name|qRound64
argument_list|(
name|elapsed
argument_list|(
name|now
argument_list|,
name|startTicks
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|stop
name|qint64
name|QBenchmarkTickMeasurer
operator|::
name|stop
parameter_list|()
block|{
name|CycleCounterTicks
name|now
init|=
name|getticks
argument_list|()
decl_stmt|;
return|return
name|qRound64
argument_list|(
name|elapsed
argument_list|(
name|now
argument_list|,
name|startTicks
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|isMeasurementAccepted
name|bool
name|QBenchmarkTickMeasurer
operator|::
name|isMeasurementAccepted
parameter_list|(
name|qint64
parameter_list|)
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|adjustIterationCount
name|int
name|QBenchmarkTickMeasurer
operator|::
name|adjustIterationCount
parameter_list|(
name|int
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|adjustMedianCount
name|int
name|QBenchmarkTickMeasurer
operator|::
name|adjustMedianCount
parameter_list|(
name|int
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|needsWarmupIteration
name|bool
name|QBenchmarkTickMeasurer
operator|::
name|needsWarmupIteration
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|metricType
name|QTest
operator|::
name|QBenchmarkMetric
name|QBenchmarkTickMeasurer
operator|::
name|metricType
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|CPUTicks
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
