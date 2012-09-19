begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcore_unix_p.h"
end_include
begin_include
include|#
directive|include
file|"qelapsedtimer.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_NACL
end_ifdef
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_elif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_HPUX
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/select.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<selectLib.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_include
include|#
directive|include
file|<mach/mach_time.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|time_update
specifier|static
specifier|inline
name|bool
name|time_update
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|&
name|start
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|&
name|timeout
parameter_list|)
block|{
if|if
condition|(
operator|!
name|QElapsedTimer
operator|::
name|isMonotonic
argument_list|()
condition|)
block|{
comment|// we cannot recalculate the timeout without a monotonic clock as the time may have changed
return|return
literal|false
return|;
block|}
comment|// clock source is monotonic, so we can recalculate how much timeout is left
name|struct
name|timeval
name|now
init|=
name|qt_gettime
argument_list|()
decl_stmt|;
operator|*
name|tv
operator|=
name|timeout
operator|+
name|start
operator|-
name|now
expr_stmt|;
return|return
name|tv
operator|->
name|tv_sec
operator|>=
literal|0
return|;
block|}
end_function
begin_function
DECL|function|qt_safe_select
name|int
name|qt_safe_select
parameter_list|(
name|int
name|nfds
parameter_list|,
name|fd_set
modifier|*
name|fdread
parameter_list|,
name|fd_set
modifier|*
name|fdwrite
parameter_list|,
name|fd_set
modifier|*
name|fdexcept
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|orig_timeout
parameter_list|)
block|{
if|if
condition|(
operator|!
name|orig_timeout
condition|)
block|{
comment|// no timeout -> block forever
specifier|register
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
name|select
argument_list|(
name|nfds
argument_list|,
name|fdread
argument_list|,
name|fdwrite
argument_list|,
name|fdexcept
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
name|timeval
name|start
init|=
name|qt_gettime
argument_list|()
decl_stmt|;
name|timeval
name|timeout
init|=
operator|*
name|orig_timeout
decl_stmt|;
comment|// loop and recalculate the timeout as needed
name|int
name|ret
decl_stmt|;
forever|forever
block|{
name|ret
operator|=
operator|::
name|select
argument_list|(
name|nfds
argument_list|,
name|fdread
argument_list|,
name|fdwrite
argument_list|,
name|fdexcept
argument_list|,
operator|&
name|timeout
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
operator|-
literal|1
operator|||
name|errno
operator|!=
name|EINTR
condition|)
return|return
name|ret
return|;
comment|// recalculate the timeout
if|if
condition|(
operator|!
name|time_update
argument_list|(
operator|&
name|timeout
argument_list|,
name|start
argument_list|,
operator|*
name|orig_timeout
argument_list|)
condition|)
block|{
comment|// timeout during update
comment|// or clock reset, fake timeout error
return|return
literal|0
return|;
block|}
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
