begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTIMESTAMP_H
end_ifndef
begin_define
DECL|macro|QTIMESTAMP_H
define|#
directive|define
name|QTIMESTAMP_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|Q_CORE_EXPORT
name|QElapsedTimer
decl_stmt|{ public:     enum ClockType
block|{
name|SystemTime
operator|,
name|MonotonicClock
operator|,
name|TickCounter
operator|,
name|MachAbsoluteTime
operator|,
name|PerformanceCounter
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_function_decl
specifier|static
name|ClockType
name|clockType
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isMonotonic
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|start
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|qint64
name|restart
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|invalidate
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qint64
name|nsecsElapsed
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|qint64
name|elapsed
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|hasExpired
argument_list|(
name|qint64
name|timeout
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qint64
name|msecsSinceReference
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|qint64
name|msecsTo
argument_list|(
specifier|const
name|QElapsedTimer
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qint64
name|secsTo
argument_list|(
specifier|const
name|QElapsedTimer
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QElapsedTimer
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|t1
operator|==
name|other
operator|.
name|t1
operator|&&
name|t2
operator|==
name|other
operator|.
name|t2
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QElapsedTimer
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|friend
name|bool
name|Q_CORE_EXPORT
name|operator
operator|<
operator|(
specifier|const
name|QElapsedTimer
operator|&
name|v1
operator|,
specifier|const
name|QElapsedTimer
operator|&
name|v2
operator|)
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|qint64
name|t1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qint64
name|t2
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTIMESTAMP_H
end_comment
end_unit
