begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__RESOURCEMONINTERFACE_H__
end_ifndef
begin_define
DECL|macro|__RESOURCEMONINTERFACE_H__
define|#
directive|define
name|__RESOURCEMONINTERFACE_H__
end_define
begin_decl_stmt
name|class
name|ResourceMonitorInterface
block|{
name|public
label|:
struct|struct
name|MemoryAllocation
block|{
name|int
name|allocatedInAppThread
decl_stmt|;
name|int
name|numberOfAllocatedCellsInAppThread
decl_stmt|;
name|int
name|availableMemoryInAppThreadHeap
decl_stmt|;
name|qint64
name|availableMemoryInSystem
decl_stmt|;
name|qint64
name|totalMemoryInSystem
decl_stmt|;
name|MemoryAllocation
argument_list|()
operator|:
name|allocatedInAppThread
argument_list|(
literal|0
argument_list|)
operator|,
name|numberOfAllocatedCellsInAppThread
argument_list|(
literal|0
argument_list|)
operator|,
name|availableMemoryInAppThreadHeap
argument_list|(
literal|0
argument_list|)
operator|,
name|availableMemoryInSystem
argument_list|(
literal|0
argument_list|)
operator|,
name|totalMemoryInSystem
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
struct|struct
name|CpuUsage
block|{
name|qreal
name|systemUsage
decl_stmt|;
name|qreal
name|appTreadUsage
decl_stmt|;
name|CpuUsage
argument_list|()
operator|:
name|systemUsage
argument_list|(
literal|0.0
argument_list|)
operator|,
name|appTreadUsage
argument_list|(
literal|0.0
argument_list|)
block|{}
block|}
struct|;
name|public
label|:
name|virtual
operator|~
name|ResourceMonitorInterface
argument_list|()
block|{}
name|public
operator|:
comment|//for symbian, prepares the resource monitor for data capture, opens handle to ekern null
comment|//thread and sets initial values
name|virtual
name|bool
name|Prepare
argument_list|(
argument|QString applicationThreadName
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|//functions for CPU load and memory - Call Prepare before calling these
name|virtual
name|CpuUsage
name|CPULoad
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|MemoryAllocation
name|MemoryLoad
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|BeginMeasureMemoryLoad
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|MemoryAllocation
name|EndMeasureMemoryLoad
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|BeginMeasureCPULoad
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|CpuUsage
name|EndMeasureCPULoad
parameter_list|()
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_INTERFACE
argument_list|(
name|ResourceMonitorInterface
argument_list|,
literal|"com.trolltech.Plugin.ResourceMonitorInterface/1.0"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//__RESOURCEMONINTERFACE_H__
end_comment
end_unit
