begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLOBAL_H
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QSYSTEMDETECTION_H
end_ifndef
begin_define
DECL|macro|QSYSTEMDETECTION_H
define|#
directive|define
name|QSYSTEMDETECTION_H
end_define
begin_comment
comment|/*    The operating system, must be one of: (Q_OS_x)       DARWIN   - Any Darwin system (OS X, iOS, watchOS, tvOS)      OSX      - OS X      IOS      - iOS      WATCHOS  - watchOS      TVOS     - tvOS      MSDOS    - MS-DOS and Windows      OS2      - OS/2      OS2EMX   - XFree86 on OS/2 (not PM)      WIN32    - Win32 (Windows 2000/XP/Vista/7 and Windows Server 2003/2008)      WINCE    - WinCE (Windows CE 5.0)      WINRT    - WinRT (Windows 8 Runtime)      CYGWIN   - Cygwin      SOLARIS  - Sun Solaris      HPUX     - HP-UX      ULTRIX   - DEC Ultrix      LINUX    - Linux [has variants]      FREEBSD  - FreeBSD [has variants]      NETBSD   - NetBSD      OPENBSD  - OpenBSD      BSDI     - BSD/OS      INTERIX  - Interix      IRIX     - SGI Irix      OSF      - HP Tru64 UNIX      SCO      - SCO OpenServer 5      UNIXWARE - UnixWare 7, Open UNIX 8      AIX      - AIX      HURD     - GNU Hurd      DGUX     - DG/UX      RELIANT  - Reliant UNIX      DYNIX    - DYNIX/ptx      QNX      - QNX [has variants]      QNX6     - QNX RTP 6.1      LYNX     - LynxOS      BSD4     - Any BSD 4.4 system      UNIX     - Any UNIX BSD/SYSV system      ANDROID  - Android platform      HAIKU    - Haiku     The following operating systems have variants:      LINUX    - both Q_OS_LINUX and Q_OS_ANDROID are defined when building for Android               - only Q_OS_LINUX is defined if building for other Linux systems      FREEBSD  - Q_OS_FREEBSD is defined only when building for FreeBSD with a BSD userland               - Q_OS_FREEBSD_KERNEL is always defined on FreeBSD, even if the userland is from GNU */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__xlC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__xlc__
argument_list|)
operator|)
end_if
begin_include
include|#
directive|include
file|<TargetConditionals.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|TARGET_OS_MAC
argument_list|)
operator|&&
name|TARGET_OS_MAC
end_if
begin_define
DECL|macro|Q_OS_DARWIN
define|#
directive|define
name|Q_OS_DARWIN
end_define
begin_define
DECL|macro|Q_OS_BSD4
define|#
directive|define
name|Q_OS_BSD4
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef
begin_define
DECL|macro|Q_OS_DARWIN64
define|#
directive|define
name|Q_OS_DARWIN64
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_OS_DARWIN32
define|#
directive|define
name|Q_OS_DARWIN32
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|TARGET_OS_IPHONE
argument_list|)
operator|&&
name|TARGET_OS_IPHONE
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|TARGET_OS_TV
argument_list|)
operator|&&
name|TARGET_OS_TV
end_if
begin_define
DECL|macro|Q_OS_TVOS
define|#
directive|define
name|Q_OS_TVOS
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|TARGET_OS_WATCH
argument_list|)
operator|&&
name|TARGET_OS_WATCH
end_elif
begin_define
DECL|macro|Q_OS_WATCHOS
define|#
directive|define
name|Q_OS_WATCHOS
end_define
begin_else
else|#
directive|else
end_else
begin_empty
empty|#
end_empty
begin_comment
comment|// TARGET_OS_IOS is only available in newer SDKs,
end_comment
begin_empty
empty|#
end_empty
begin_comment
comment|// so assume any other iOS-based platform is iOS for now
end_comment
begin_define
DECL|macro|Q_OS_IOS
define|#
directive|define
name|Q_OS_IOS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_empty
empty|#
end_empty
begin_comment
comment|// there is no "real" OS X define (rdar://22640089),
end_comment
begin_empty
empty|#
end_empty
begin_comment
comment|// assume any non iOS-based platform is OS X for now
end_comment
begin_define
DECL|macro|Q_OS_OSX
define|#
directive|define
name|Q_OS_OSX
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_error
error|#
directive|error
literal|"Qt has not been ported to this Apple platform - see http://www.qt.io/developers"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ANDROID__
argument_list|)
operator|||
name|defined
argument_list|(
name|ANDROID
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_ANDROID
define|#
directive|define
name|Q_OS_ANDROID
end_define
begin_define
DECL|macro|Q_OS_LINUX
define|#
directive|define
name|Q_OS_LINUX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_CYGWIN
define|#
directive|define
name|Q_OS_CYGWIN
end_define
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|SAG_COM
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|WINAPI_FAMILY
argument_list|)
operator|||
name|WINAPI_FAMILY
operator|==
name|WINAPI_FAMILY_DESKTOP_APP
operator|)
operator|&&
operator|(
name|defined
argument_list|(
name|WIN64
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN64
argument_list|)
operator|||
name|defined
argument_list|(
name|__WIN64__
argument_list|)
operator|)
end_elif
begin_define
DECL|macro|Q_OS_WIN32
define|#
directive|define
name|Q_OS_WIN32
end_define
begin_define
DECL|macro|Q_OS_WIN64
define|#
directive|define
name|Q_OS_WIN64
end_define
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|SAG_COM
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__WIN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NT__
argument_list|)
operator|)
end_elif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|WINCE
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32_WCE
argument_list|)
end_if
begin_define
DECL|macro|Q_OS_WINCE
define|#
directive|define
name|Q_OS_WINCE
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|WINAPI_FAMILY
argument_list|)
end_elif
begin_ifndef
ifndef|#
directive|ifndef
name|WINAPI_FAMILY_PC_APP
end_ifndef
begin_define
DECL|macro|WINAPI_FAMILY_PC_APP
define|#
directive|define
name|WINAPI_FAMILY_PC_APP
value|WINAPI_FAMILY_APP
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|WINAPI_FAMILY_PHONE_APP
argument_list|)
operator|&&
name|WINAPI_FAMILY
operator|==
name|WINAPI_FAMILY_PHONE_APP
end_if
begin_define
DECL|macro|Q_OS_WINPHONE
define|#
directive|define
name|Q_OS_WINPHONE
end_define
begin_define
DECL|macro|Q_OS_WINRT
define|#
directive|define
name|Q_OS_WINRT
end_define
begin_elif
elif|#
directive|elif
name|WINAPI_FAMILY
operator|==
name|WINAPI_FAMILY_PC_APP
end_elif
begin_define
DECL|macro|Q_OS_WINRT
define|#
directive|define
name|Q_OS_WINRT
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_OS_WIN32
define|#
directive|define
name|Q_OS_WIN32
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_OS_WIN32
define|#
directive|define
name|Q_OS_WIN32
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sun
argument_list|)
operator|||
name|defined
argument_list|(
name|sun
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_SOLARIS
define|#
directive|define
name|Q_OS_SOLARIS
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_HPUX
define|#
directive|define
name|Q_OS_HPUX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|ultrix
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_ULTRIX
define|#
directive|define
name|Q_OS_ULTRIX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sinix
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_RELIANT
define|#
directive|define
name|Q_OS_RELIANT
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__native_client__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_NACL
define|#
directive|define
name|Q_OS_NACL
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__linux
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_LINUX
define|#
directive|define
name|Q_OS_LINUX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD_kernel__
argument_list|)
end_elif
begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD_kernel__
end_ifndef
begin_define
DECL|macro|Q_OS_FREEBSD
define|#
directive|define
name|Q_OS_FREEBSD
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_OS_FREEBSD_KERNEL
define|#
directive|define
name|Q_OS_FREEBSD_KERNEL
end_define
begin_define
DECL|macro|Q_OS_BSD4
define|#
directive|define
name|Q_OS_BSD4
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_NETBSD
define|#
directive|define
name|Q_OS_NETBSD
end_define
begin_define
DECL|macro|Q_OS_BSD4
define|#
directive|define
name|Q_OS_BSD4
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_OPENBSD
define|#
directive|define
name|Q_OS_OPENBSD
end_define
begin_define
DECL|macro|Q_OS_BSD4
define|#
directive|define
name|Q_OS_BSD4
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_BSDI
define|#
directive|define
name|Q_OS_BSDI
end_define
begin_define
DECL|macro|Q_OS_BSD4
define|#
directive|define
name|Q_OS_BSD4
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__INTERIX
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_INTERIX
define|#
directive|define
name|Q_OS_INTERIX
end_define
begin_define
DECL|macro|Q_OS_BSD4
define|#
directive|define
name|Q_OS_BSD4
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sgi
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_IRIX
define|#
directive|define
name|Q_OS_IRIX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__osf__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_OSF
define|#
directive|define
name|Q_OS_OSF
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AIX
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_AIX
define|#
directive|define
name|Q_OS_AIX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__Lynx__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_LYNX
define|#
directive|define
name|Q_OS_LYNX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNU__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_HURD
define|#
directive|define
name|Q_OS_HURD
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__DGUX__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_DGUX
define|#
directive|define
name|Q_OS_DGUX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__QNXNTO__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_QNX
define|#
directive|define
name|Q_OS_QNX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_SEQUENT_
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_DYNIX
define|#
directive|define
name|Q_OS_DYNIX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_SCO_DS
argument_list|)
end_elif
begin_comment
comment|/* SCO OpenServer 5 + GCC */
end_comment
begin_define
DECL|macro|Q_OS_SCO
define|#
directive|define
name|Q_OS_SCO
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__USLC__
argument_list|)
end_elif
begin_comment
comment|/* all SCO platforms + UDK or OUDK */
end_comment
begin_define
DECL|macro|Q_OS_UNIXWARE
define|#
directive|define
name|Q_OS_UNIXWARE
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|&&
name|defined
argument_list|(
name|i386
argument_list|)
end_elif
begin_comment
comment|/* Open UNIX 8 + GCC */
end_comment
begin_define
DECL|macro|Q_OS_UNIXWARE
define|#
directive|define
name|Q_OS_UNIXWARE
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__INTEGRITY
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_INTEGRITY
define|#
directive|define
name|Q_OS_INTEGRITY
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|VXWORKS
argument_list|)
end_elif
begin_comment
comment|/* there is no "real" VxWorks define - this has to be set in the mkspec! */
end_comment
begin_define
DECL|macro|Q_OS_VXWORKS
define|#
directive|define
name|Q_OS_VXWORKS
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__HAIKU__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_HAIKU
define|#
directive|define
name|Q_OS_HAIKU
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MAKEDEPEND__
argument_list|)
end_elif
begin_else
else|#
directive|else
end_else
begin_error
error|#
directive|error
literal|"Qt has not been ported to this OS - see http://www.qt-project.org/"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WIN64
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
end_if
begin_define
DECL|macro|Q_OS_WIN
define|#
directive|define
name|Q_OS_WIN
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_undef
DECL|macro|Q_OS_UNIX
undef|#
directive|undef
name|Q_OS_UNIX
end_undef
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_UNIX
define|#
directive|define
name|Q_OS_UNIX
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Compatibility synonyms
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_DARWIN
end_ifdef
begin_define
DECL|macro|Q_OS_MAC
define|#
directive|define
name|Q_OS_MAC
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_DARWIN32
end_ifdef
begin_define
DECL|macro|Q_OS_MAC32
define|#
directive|define
name|Q_OS_MAC32
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_DARWIN64
end_ifdef
begin_define
DECL|macro|Q_OS_MAC64
define|#
directive|define
name|Q_OS_MAC64
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_OSX
end_ifdef
begin_define
DECL|macro|Q_OS_MACX
define|#
directive|define
name|Q_OS_MACX
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_DARWIN
end_ifdef
begin_include
include|#
directive|include
file|<Availability.h>
end_include
begin_include
include|#
directive|include
file|<AvailabilityMacros.h>
end_include
begin_empty
empty|#
end_empty
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_OSX
end_ifdef
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MAC_OS_X_VERSION_MIN_REQUIRED
argument_list|)
operator|||
name|__MAC_OS_X_VERSION_MIN_REQUIRED
operator|<
name|__MAC_10_6
end_if
begin_undef
DECL|macro|__MAC_OS_X_VERSION_MIN_REQUIRED
undef|#
directive|undef
name|__MAC_OS_X_VERSION_MIN_REQUIRED
end_undef
begin_define
DECL|macro|__MAC_OS_X_VERSION_MIN_REQUIRED
define|#
directive|define
name|__MAC_OS_X_VERSION_MIN_REQUIRED
value|__MAC_10_6
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAC_OS_X_VERSION_MIN_REQUIRED
argument_list|)
operator|||
name|MAC_OS_X_VERSION_MIN_REQUIRED
operator|<
name|MAC_OS_X_VERSION_10_6
end_if
begin_undef
DECL|macro|MAC_OS_X_VERSION_MIN_REQUIRED
undef|#
directive|undef
name|MAC_OS_X_VERSION_MIN_REQUIRED
end_undef
begin_define
DECL|macro|MAC_OS_X_VERSION_MIN_REQUIRED
define|#
directive|define
name|MAC_OS_X_VERSION_MIN_REQUIRED
value|MAC_OS_X_VERSION_10_6
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_empty
empty|#
end_empty
begin_empty
empty|#
end_empty
begin_comment
comment|// Numerical checks are preferred to named checks, but to be safe
end_comment
begin_empty
empty|#
end_empty
begin_comment
comment|// we define the missing version names in case Qt uses them.
end_comment
begin_empty
empty|#
end_empty
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MAC_10_7
argument_list|)
end_if
begin_define
DECL|macro|__MAC_10_7
define|#
directive|define
name|__MAC_10_7
value|1070
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MAC_10_8
argument_list|)
end_if
begin_define
DECL|macro|__MAC_10_8
define|#
directive|define
name|__MAC_10_8
value|1080
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MAC_10_9
argument_list|)
end_if
begin_define
DECL|macro|__MAC_10_9
define|#
directive|define
name|__MAC_10_9
value|1090
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MAC_10_10
argument_list|)
end_if
begin_define
DECL|macro|__MAC_10_10
define|#
directive|define
name|__MAC_10_10
value|101000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MAC_10_11
argument_list|)
end_if
begin_define
DECL|macro|__MAC_10_11
define|#
directive|define
name|__MAC_10_11
value|101100
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAC_OS_X_VERSION_10_7
argument_list|)
end_if
begin_define
DECL|macro|MAC_OS_X_VERSION_10_7
define|#
directive|define
name|MAC_OS_X_VERSION_10_7
value|1070
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAC_OS_X_VERSION_10_8
argument_list|)
end_if
begin_define
DECL|macro|MAC_OS_X_VERSION_10_8
define|#
directive|define
name|MAC_OS_X_VERSION_10_8
value|1080
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAC_OS_X_VERSION_10_9
argument_list|)
end_if
begin_define
DECL|macro|MAC_OS_X_VERSION_10_9
define|#
directive|define
name|MAC_OS_X_VERSION_10_9
value|1090
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAC_OS_X_VERSION_10_10
argument_list|)
end_if
begin_define
DECL|macro|MAC_OS_X_VERSION_10_10
define|#
directive|define
name|MAC_OS_X_VERSION_10_10
value|101000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAC_OS_X_VERSION_10_11
argument_list|)
end_if
begin_define
DECL|macro|MAC_OS_X_VERSION_10_11
define|#
directive|define
name|MAC_OS_X_VERSION_10_11
value|101100
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_empty
empty|#
end_empty
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_4_3
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_4_3
define|#
directive|define
name|__IPHONE_4_3
value|40300
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_5_0
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_5_0
define|#
directive|define
name|__IPHONE_5_0
value|50000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_5_1
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_5_1
define|#
directive|define
name|__IPHONE_5_1
value|50100
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_6_0
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_6_0
define|#
directive|define
name|__IPHONE_6_0
value|60000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_6_1
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_6_1
define|#
directive|define
name|__IPHONE_6_1
value|60100
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_7_0
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_7_0
define|#
directive|define
name|__IPHONE_7_0
value|70000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_7_1
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_7_1
define|#
directive|define
name|__IPHONE_7_1
value|70100
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_8_0
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_8_0
define|#
directive|define
name|__IPHONE_8_0
value|80000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_8_1
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_8_1
define|#
directive|define
name|__IPHONE_8_1
value|80100
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_8_2
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_8_2
define|#
directive|define
name|__IPHONE_8_2
value|80200
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_8_3
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_8_3
define|#
directive|define
name|__IPHONE_8_3
value|80300
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_8_4
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_8_4
define|#
directive|define
name|__IPHONE_8_4
value|80400
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IPHONE_9_0
argument_list|)
end_if
begin_define
DECL|macro|__IPHONE_9_0
define|#
directive|define
name|__IPHONE_9_0
value|90000
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|__LSB_VERSION__
end_ifdef
begin_if
if|#
directive|if
name|__LSB_VERSION__
operator|<
literal|40
end_if
begin_error
error|#
directive|error
literal|"This version of the Linux Standard Base is unsupported"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_LINUXBASE
end_ifndef
begin_define
DECL|macro|QT_LINUXBASE
define|#
directive|define
name|QT_LINUXBASE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSYSTEMDETECTION_H
end_comment
end_unit
