begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMDEFS_H
end_ifndef
begin_define
DECL|macro|QPLATFORMDEFS_H
define|#
directive|define
name|QPLATFORMDEFS_H
end_define
begin_comment
comment|// Get Qt defines/settings
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_comment
comment|// Set any POSIX/XOPEN defines at the top of this file to turn on specific APIs
end_comment
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_comment
comment|// We are hot - unistd.h should have turned on the specific APIs we requested
end_comment
begin_include
include|#
directive|include
file|<pthread.h>
end_include
begin_include
include|#
directive|include
file|<dirent.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<grp.h>
end_include
begin_include
include|#
directive|include
file|<pwd.h>
end_include
begin_include
include|#
directive|include
file|<signal.h>
end_include
begin_include
include|#
directive|include
file|<dlfcn.h>
end_include
begin_include
include|#
directive|include
file|<sys/param.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_include
include|#
directive|include
file|<sys/shm.h>
end_include
begin_include
include|#
directive|include
file|<sys/socket.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<sys/wait.h>
end_include
begin_include
include|#
directive|include
file|<netinet/in.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IPV6IFNAME
end_ifndef
begin_include
include|#
directive|include
file|<net/if.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"../common/posix/qplatformdefs.h"
end_include
begin_undef
DECL|macro|QT_OPEN_LARGEFILE
undef|#
directive|undef
name|QT_OPEN_LARGEFILE
end_undef
begin_define
DECL|macro|QT_OPEN_LARGEFILE
define|#
directive|define
name|QT_OPEN_LARGEFILE
value|0
end_define
begin_comment
comment|// QT_SOCKLEN_T
end_comment
begin_comment
comment|// OpenBSD 2.2 - 2.4            int
end_comment
begin_comment
comment|// OpenBSD 2.5 - 2.8            socklen_t
end_comment
begin_define
DECL|macro|QT_SNPRINTF
define|#
directive|define
name|QT_SNPRINTF
value|::snprintf
end_define
begin_define
DECL|macro|QT_VSNPRINTF
define|#
directive|define
name|QT_VSNPRINTF
value|::vsnprintf
end_define
begin_comment
comment|// 1003.1c-1995 says on page 38 (2.9.3, paragraph 3) that if _POSIX_THREADS
end_comment
begin_comment
comment|// is defined, then _POSIX_THREAD_SAFE_FUNCTIONS must also be defined.
end_comment
begin_comment
comment|// However this looks like a well-known typo (reversed dependency).
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// On the other hand _POSIX_THREAD_SAFE_FUNCTIONS should be defined only
end_comment
begin_comment
comment|// if the Thread-Safe Functions option is implemented. OpenBSD does not
end_comment
begin_comment
comment|// support all of the required _r() interfaces, especially getpwuid_r(),
end_comment
begin_comment
comment|// which means it should not define _POSIX_THREAD_SAFE_FUNCTIONS.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Since OpenBSD does define _POSIX_THREAD_SAFE_FUNCTIONS, we have to
end_comment
begin_comment
comment|// undefine it behind its back.
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_THREAD_SAFE_FUNCTIONS
end_ifdef
begin_undef
DECL|macro|_POSIX_THREAD_SAFE_FUNCTIONS
undef|#
directive|undef
name|_POSIX_THREAD_SAFE_FUNCTIONS
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Older OpenBSD versions may still use the a.out format instead of ELF.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__ELF__
end_ifndef
begin_define
DECL|macro|QT_AOUT_UNDERSCORE
define|#
directive|define
name|QT_AOUT_UNDERSCORE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMDEFS_H
end_comment
end_unit
