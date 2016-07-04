begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCORE_UNIX_P_H
end_ifndef
begin_define
DECL|macro|QCORE_UNIX_P_H
define|#
directive|define
name|QCORE_UNIX_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of Qt code on Unix. This header file may change from version to
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
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qatomic.h"
end_include
begin_include
include|#
directive|include
file|"qhash.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_UNIX
end_ifndef
begin_error
error|#
directive|error
literal|"qcore_unix_p.h included on a non-Unix system"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
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
file|<sys/wait.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_POSIX_IPC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_SHAREDMEMORY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_if
begin_include
include|#
directive|include
file|<ioLib.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_NO_NATIVE_POLL
end_ifdef
begin_include
include|#
directive|include
file|"qpoll_p.h"
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<poll.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl
begin_define
DECL|macro|EINTR_LOOP
define|#
directive|define
name|EINTR_LOOP
parameter_list|(
name|var
parameter_list|,
name|cmd
parameter_list|)
define|\
value|do {                                        \         var = cmd;                              \     } while (var == -1&& errno == EINTR)
end_define
begin_function
name|QT_BEGIN_NAMESPACE
comment|// Internal operator functions for timespecs
DECL|function|normalizedTimespec
specifier|inline
name|timespec
modifier|&
name|normalizedTimespec
parameter_list|(
name|timespec
modifier|&
name|t
parameter_list|)
block|{
while|while
condition|(
name|t
operator|.
name|tv_nsec
operator|>=
literal|1000000000
condition|)
block|{
operator|++
name|t
operator|.
name|tv_sec
expr_stmt|;
name|t
operator|.
name|tv_nsec
operator|-=
literal|1000000000
expr_stmt|;
block|}
while|while
condition|(
name|t
operator|.
name|tv_nsec
operator|<
literal|0
condition|)
block|{
operator|--
name|t
operator|.
name|tv_sec
expr_stmt|;
name|t
operator|.
name|tv_nsec
operator|+=
literal|1000000000
expr_stmt|;
block|}
return|return
name|t
return|;
block|}
end_function
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|timespec
operator|&
name|t1
operator|,
specifier|const
name|timespec
operator|&
name|t2
operator|)
block|{
return|return
name|t1
operator|.
name|tv_sec
operator|<
name|t2
operator|.
name|tv_sec
operator|||
operator|(
name|t1
operator|.
name|tv_sec
operator|==
name|t2
operator|.
name|tv_sec
operator|&&
name|t1
operator|.
name|tv_nsec
operator|<
name|t2
operator|.
name|tv_nsec
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|timespec
operator|&
name|t1
operator|,
specifier|const
name|timespec
operator|&
name|t2
operator|)
block|{
return|return
name|t1
operator|.
name|tv_sec
operator|==
name|t2
operator|.
name|tv_sec
operator|&&
name|t1
operator|.
name|tv_nsec
operator|==
name|t2
operator|.
name|tv_nsec
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|timespec
operator|&
name|t1
operator|,
specifier|const
name|timespec
operator|&
name|t2
operator|)
block|{
return|return
operator|!
operator|(
name|t1
operator|==
name|t2
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|variable|operator
specifier|inline
name|timespec
operator|&
name|operator
operator|+=
operator|(
name|timespec
operator|&
name|t1
operator|,
specifier|const
name|timespec
operator|&
name|t2
operator|)
block|{
name|t1
operator|.
name|tv_sec
operator|+=
name|t2
operator|.
name|tv_sec
block|;
name|t1
operator|.
name|tv_nsec
operator|+=
name|t2
operator|.
name|tv_nsec
block|;
return|return
name|normalizedTimespec
argument_list|(
name|t1
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|timespec
name|operator
operator|+
operator|(
specifier|const
name|timespec
operator|&
name|t1
operator|,
specifier|const
name|timespec
operator|&
name|t2
operator|)
block|{
name|timespec
name|tmp
block|;
name|tmp
operator|.
name|tv_sec
operator|=
name|t1
operator|.
name|tv_sec
operator|+
name|t2
operator|.
name|tv_sec
block|;
name|tmp
operator|.
name|tv_nsec
operator|=
name|t1
operator|.
name|tv_nsec
operator|+
name|t2
operator|.
name|tv_nsec
block|;
return|return
name|normalizedTimespec
argument_list|(
name|tmp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|timespec
name|operator
operator|-
operator|(
specifier|const
name|timespec
operator|&
name|t1
operator|,
specifier|const
name|timespec
operator|&
name|t2
operator|)
block|{
name|timespec
name|tmp
block|;
name|tmp
operator|.
name|tv_sec
operator|=
name|t1
operator|.
name|tv_sec
operator|-
operator|(
name|t2
operator|.
name|tv_sec
operator|-
literal|1
operator|)
block|;
name|tmp
operator|.
name|tv_nsec
operator|=
name|t1
operator|.
name|tv_nsec
operator|-
operator|(
name|t2
operator|.
name|tv_nsec
operator|+
literal|1000000000
operator|)
block|;
return|return
name|normalizedTimespec
argument_list|(
name|tmp
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|timespec
name|operator
modifier|*
parameter_list|(
specifier|const
name|timespec
modifier|&
name|t1
parameter_list|,
name|int
name|mul
parameter_list|)
block|{
name|timespec
name|tmp
decl_stmt|;
name|tmp
operator|.
name|tv_sec
operator|=
name|t1
operator|.
name|tv_sec
operator|*
name|mul
expr_stmt|;
name|tmp
operator|.
name|tv_nsec
operator|=
name|t1
operator|.
name|tv_nsec
operator|*
name|mul
expr_stmt|;
return|return
name|normalizedTimespec
argument_list|(
name|tmp
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|timeval
name|timespecToTimeval
parameter_list|(
specifier|const
name|timespec
modifier|&
name|ts
parameter_list|)
block|{
name|timeval
name|tv
decl_stmt|;
name|tv
operator|.
name|tv_sec
operator|=
name|ts
operator|.
name|tv_sec
expr_stmt|;
name|tv
operator|.
name|tv_usec
operator|=
name|ts
operator|.
name|tv_nsec
operator|/
literal|1000
expr_stmt|;
return|return
name|tv
return|;
block|}
end_function
begin_function
specifier|inline
name|void
name|qt_ignore_sigpipe
parameter_list|()
block|{
comment|// Set to ignore SIGPIPE once only.
specifier|static
name|QBasicAtomicInt
name|atom
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|atom
operator|.
name|load
argument_list|()
condition|)
block|{
comment|// More than one thread could turn off SIGPIPE at the same time
comment|// But that's acceptable because they all would be doing the same
comment|// action
name|struct
name|sigaction
name|noaction
decl_stmt|;
name|memset
argument_list|(
operator|&
name|noaction
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|noaction
argument_list|)
argument_list|)
expr_stmt|;
name|noaction
operator|.
name|sa_handler
operator|=
name|SIG_IGN
expr_stmt|;
operator|::
name|sigaction
argument_list|(
name|SIGPIPE
argument_list|,
operator|&
name|noaction
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|atom
operator|.
name|store
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|// don't call QT_OPEN or ::open
end_comment
begin_comment
comment|// call qt_safe_open
end_comment
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_open
parameter_list|(
specifier|const
name|char
modifier|*
name|pathname
parameter_list|,
name|int
name|flags
parameter_list|,
name|mode_t
name|mode
init|=
literal|0777
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|O_CLOEXEC
name|flags
operator||=
name|O_CLOEXEC
expr_stmt|;
endif|#
directive|endif
name|int
name|fd
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|fd
argument_list|,
name|QT_OPEN
argument_list|(
name|pathname
argument_list|,
name|flags
argument_list|,
name|mode
argument_list|)
argument_list|)
expr_stmt|;
comment|// unknown flags are ignored, so we have no way of verifying if
comment|// O_CLOEXEC was accepted
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
condition|)
operator|::
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFD
argument_list|,
name|FD_CLOEXEC
argument_list|)
expr_stmt|;
return|return
name|fd
return|;
block|}
end_function
begin_undef
DECL|macro|QT_OPEN
undef|#
directive|undef
name|QT_OPEN
end_undef
begin_define
DECL|macro|QT_OPEN
define|#
directive|define
name|QT_OPEN
value|qt_safe_open
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_VXWORKS
end_ifndef
begin_comment
comment|// no POSIX pipes in VxWorks
end_comment
begin_comment
comment|// don't call ::pipe
end_comment
begin_comment
comment|// call qt_safe_pipe
end_comment
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_pipe
parameter_list|(
name|int
name|pipefd
index|[
literal|2
index|]
parameter_list|,
name|int
name|flags
init|=
literal|0
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|(
name|flags
operator|&
operator|~
name|O_NONBLOCK
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_THREADSAFE_CLOEXEC
comment|// use pipe2
name|flags
operator||=
name|O_CLOEXEC
expr_stmt|;
return|return
operator|::
name|pipe2
argument_list|(
name|pipefd
argument_list|,
name|flags
argument_list|)
return|;
comment|// pipe2 is documented not to return EINTR
else|#
directive|else
name|int
name|ret
init|=
operator|::
name|pipe
argument_list|(
name|pipefd
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|0
index|]
argument_list|,
name|F_SETFD
argument_list|,
name|FD_CLOEXEC
argument_list|)
expr_stmt|;
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|1
index|]
argument_list|,
name|F_SETFD
argument_list|,
name|FD_CLOEXEC
argument_list|)
expr_stmt|;
comment|// set non-block too?
if|if
condition|(
name|flags
operator|&
name|O_NONBLOCK
condition|)
block|{
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|0
index|]
argument_list|,
name|F_SETFL
argument_list|,
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|0
index|]
argument_list|,
name|F_GETFL
argument_list|)
operator||
name|O_NONBLOCK
argument_list|)
expr_stmt|;
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|1
index|]
argument_list|,
name|F_SETFL
argument_list|,
operator|::
name|fcntl
argument_list|(
name|pipefd
index|[
literal|1
index|]
argument_list|,
name|F_GETFL
argument_list|)
operator||
name|O_NONBLOCK
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_VXWORKS
end_comment
begin_comment
comment|// don't call dup or fcntl(F_DUPFD)
end_comment
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_dup
parameter_list|(
name|int
name|oldfd
parameter_list|,
name|int
name|atleast
init|=
literal|0
parameter_list|,
name|int
name|flags
init|=
name|FD_CLOEXEC
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|flags
operator|==
name|FD_CLOEXEC
operator|||
name|flags
operator|==
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|F_DUPFD_CLOEXEC
name|int
name|cmd
init|=
name|F_DUPFD
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|FD_CLOEXEC
condition|)
name|cmd
operator|=
name|F_DUPFD_CLOEXEC
expr_stmt|;
return|return
operator|::
name|fcntl
argument_list|(
name|oldfd
argument_list|,
name|cmd
argument_list|,
name|atleast
argument_list|)
return|;
else|#
directive|else
comment|// use F_DUPFD
name|int
name|ret
init|=
operator|::
name|fcntl
argument_list|(
name|oldfd
argument_list|,
name|F_DUPFD
argument_list|,
name|atleast
argument_list|)
decl_stmt|;
if|if
condition|(
name|flags
operator|&&
name|ret
operator|!=
operator|-
literal|1
condition|)
operator|::
name|fcntl
argument_list|(
name|ret
argument_list|,
name|F_SETFD
argument_list|,
name|flags
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|// don't call dup2
end_comment
begin_comment
comment|// call qt_safe_dup2
end_comment
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_dup2
parameter_list|(
name|int
name|oldfd
parameter_list|,
name|int
name|newfd
parameter_list|,
name|int
name|flags
init|=
name|FD_CLOEXEC
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|flags
operator|==
name|FD_CLOEXEC
operator|||
name|flags
operator|==
literal|0
argument_list|)
expr_stmt|;
name|int
name|ret
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_THREADSAFE_CLOEXEC
comment|// use dup3
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|dup3
argument_list|(
name|oldfd
argument_list|,
name|newfd
argument_list|,
name|flags
condition|?
name|O_CLOEXEC
else|:
literal|0
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
else|#
directive|else
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|dup2
argument_list|(
name|oldfd
argument_list|,
name|newfd
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|flags
condition|)
operator|::
name|fcntl
argument_list|(
name|newfd
argument_list|,
name|F_SETFD
argument_list|,
name|flags
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
specifier|static
specifier|inline
name|qint64
name|qt_safe_read
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|qint64
name|maxlen
parameter_list|)
block|{
name|qint64
name|ret
init|=
literal|0
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
name|QT_READ
argument_list|(
name|fd
argument_list|,
name|data
argument_list|,
name|maxlen
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_undef
DECL|macro|QT_READ
undef|#
directive|undef
name|QT_READ
end_undef
begin_define
DECL|macro|QT_READ
define|#
directive|define
name|QT_READ
value|qt_safe_read
end_define
begin_function
specifier|static
specifier|inline
name|qint64
name|qt_safe_write
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
block|{
name|qint64
name|ret
init|=
literal|0
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
name|QT_WRITE
argument_list|(
name|fd
argument_list|,
name|data
argument_list|,
name|len
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_undef
DECL|macro|QT_WRITE
undef|#
directive|undef
name|QT_WRITE
end_undef
begin_define
DECL|macro|QT_WRITE
define|#
directive|define
name|QT_WRITE
value|qt_safe_write
end_define
begin_function
specifier|static
specifier|inline
name|qint64
name|qt_safe_write_nosignal
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|qint64
name|len
parameter_list|)
block|{
name|qt_ignore_sigpipe
argument_list|()
expr_stmt|;
return|return
name|qt_safe_write
argument_list|(
name|fd
argument_list|,
name|data
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_close
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
name|QT_CLOSE
argument_list|(
name|fd
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_undef
DECL|macro|QT_CLOSE
undef|#
directive|undef
name|QT_CLOSE
end_undef
begin_define
DECL|macro|QT_CLOSE
define|#
directive|define
name|QT_CLOSE
value|qt_safe_close
end_define
begin_comment
comment|// - VxWorks doesn't have processes
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_if
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_execve
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|,
name|char
modifier|*
specifier|const
name|envp
index|[]
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|execve
argument_list|(
name|filename
argument_list|,
name|argv
argument_list|,
name|envp
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_execv
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|execv
argument_list|(
name|path
argument_list|,
name|argv
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|int
name|qt_safe_execvp
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|execvp
argument_list|(
name|file
argument_list|,
name|argv
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|pid_t
name|qt_safe_waitpid
parameter_list|(
name|pid_t
name|pid
parameter_list|,
name|int
modifier|*
name|status
parameter_list|,
name|int
name|options
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|ret
argument_list|,
operator|::
name|waitpid
argument_list|(
name|pid
argument_list|,
name|status
argument_list|,
name|options
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_VXWORKS
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_MONOTONIC_CLOCK
argument_list|)
end_if
begin_define
DECL|macro|_POSIX_MONOTONIC_CLOCK
define|#
directive|define
name|_POSIX_MONOTONIC_CLOCK
value|-1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// in qelapsedtimer_mac.cpp or qtimestamp_unix.cpp
end_comment
begin_expr_stmt
name|timespec
name|qt_gettime
argument_list|()
name|Q_DECL_NOTHROW
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|qt_nanosleep
parameter_list|(
name|timespec
name|amount
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|Q_CORE_EXPORT
name|int
name|qt_safe_poll
parameter_list|(
name|struct
name|pollfd
modifier|*
name|fds
parameter_list|,
name|nfds_t
name|nfds
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout_ts
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|qt_poll_msecs
specifier|static
specifier|inline
name|int
name|qt_poll_msecs
parameter_list|(
name|struct
name|pollfd
modifier|*
name|fds
parameter_list|,
name|nfds_t
name|nfds
parameter_list|,
name|int
name|timeout
parameter_list|)
block|{
name|timespec
name|ts
decl_stmt|,
modifier|*
name|pts
init|=
name|Q_NULLPTR
decl_stmt|;
if|if
condition|(
name|timeout
operator|>=
literal|0
condition|)
block|{
name|ts
operator|.
name|tv_sec
operator|=
name|timeout
operator|/
literal|1000
expr_stmt|;
name|ts
operator|.
name|tv_nsec
operator|=
operator|(
name|timeout
operator|%
literal|1000
operator|)
operator|*
literal|1000
operator|*
literal|1000
expr_stmt|;
name|pts
operator|=
operator|&
name|ts
expr_stmt|;
block|}
return|return
name|qt_safe_poll
argument_list|(
name|fds
argument_list|,
name|nfds
argument_list|,
name|pts
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_make_pollfd
specifier|static
specifier|inline
name|struct
name|pollfd
name|qt_make_pollfd
parameter_list|(
name|int
name|fd
parameter_list|,
name|short
name|events
parameter_list|)
block|{
name|struct
name|pollfd
name|pfd
init|=
block|{
name|fd
block|,
name|events
block|,
literal|0
block|}
decl_stmt|;
return|return
name|pfd
return|;
block|}
end_function
begin_comment
comment|// according to X/OPEN we have to define semun ourselves
end_comment
begin_comment
comment|// we use prefix as on some systems sem.h will have it
end_comment
begin_struct_decl
struct_decl|struct
name|semid_ds
struct_decl|;
end_struct_decl
begin_union
DECL|union|qt_semun
union|union
name|qt_semun
block|{
DECL|member|val
name|int
name|val
decl_stmt|;
comment|/* value for SETVAL */
DECL|member|buf
name|struct
name|semid_ds
modifier|*
name|buf
decl_stmt|;
comment|/* buffer for IPC_STAT, IPC_SET */
DECL|member|array
name|unsigned
name|short
modifier|*
name|array
decl_stmt|;
comment|/* array for GETALL, SETALL */
block|}
union|;
end_union
begin_ifndef
ifndef|#
directive|ifndef
name|QT_POSIX_IPC
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SHAREDMEMORY
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_ANDROID
end_ifndef
begin_function
DECL|function|qt_safe_ftok
specifier|static
specifier|inline
name|key_t
name|qt_safe_ftok
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|filename
parameter_list|,
name|int
name|proj_id
parameter_list|)
block|{
comment|// Unfortunately ftok can return colliding keys even for different files.
comment|// Try to add some more entropy via qHash.
return|return
operator|::
name|ftok
argument_list|(
name|filename
operator|.
name|constData
argument_list|()
argument_list|,
name|qHash
argument_list|(
name|filename
argument_list|,
name|proj_id
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !Q_OS_ANDROID
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_SHAREDMEMORY
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_POSIX_IPC
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
