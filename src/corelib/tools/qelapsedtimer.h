begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QELAPSEDTIMER_H
end_ifndef
begin_define
DECL|macro|QELAPSEDTIMER_H
define|#
directive|define
name|QELAPSEDTIMER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|Q_CORE_EXPORT
name|QElapsedTimer
block|{
name|public
label|:
enum|enum
name|ClockType
block|{
name|SystemTime
block|,
name|MonotonicClock
block|,
name|TickCounter
block|,
name|MachAbsoluteTime
block|,
name|PerformanceCounter
block|}
enum|;
specifier|static
name|ClockType
name|clockType
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
specifier|static
name|bool
name|isMonotonic
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|void
name|start
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|qint64
name|restart
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|void
name|invalidate
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|qint64
name|nsecsElapsed
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|qint64
name|elapsed
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|bool
name|hasExpired
argument_list|(
name|qint64
name|timeout
argument_list|)
decl|const
name|Q_DECL_NOTHROW
decl_stmt|;
name|qint64
name|msecsSinceReference
argument_list|()
specifier|const
name|Q_DECL_NOTHROW
expr_stmt|;
name|qint64
name|msecsTo
argument_list|(
specifier|const
name|QElapsedTimer
operator|&
name|other
argument_list|)
decl|const
name|Q_DECL_NOTHROW
decl_stmt|;
name|qint64
name|secsTo
argument_list|(
specifier|const
name|QElapsedTimer
operator|&
name|other
argument_list|)
decl|const
name|Q_DECL_NOTHROW
decl_stmt|;
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
name|Q_DECL_NOTHROW
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
name|Q_DECL_NOTHROW
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
name|Q_DECL_NOTHROW
expr_stmt|;
name|private
label|:
name|qint64
name|t1
decl_stmt|;
name|qint64
name|t2
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QELAPSEDTIMER_H
end_comment
end_unit
