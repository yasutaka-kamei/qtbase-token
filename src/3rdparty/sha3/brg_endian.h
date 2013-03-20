begin_unit
begin_comment
comment|/*  ---------------------------------------------------------------------------  Copyright (c) 1998-2008, Brian Gladman, Worcester, UK. All rights reserved.   LICENSE TERMS   The redistribution and use of this software (with or without changes)  is allowed without the payment of fees or royalties provided that:    1. source code distributions include the above copyright notice, this      list of conditions and the following disclaimer;    2. binary distributions include the above copyright notice, this list      of conditions and the following disclaimer in their documentation;    3. the name of the copyright holder is not used to endorse products      built using this software without specific written permission.   DISCLAIMER   This software is provided 'as is' with no explicit or implied warranties  in respect of its properties, including, but not limited to, correctness  and/or fitness for purpose.  ---------------------------------------------------------------------------  Issue Date: 20/12/2007  Changes for ARM 9/9/2010 */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_BRG_ENDIAN_H
end_ifndef
begin_define
DECL|macro|_BRG_ENDIAN_H
define|#
directive|define
name|_BRG_ENDIAN_H
end_define
begin_define
DECL|macro|IS_BIG_ENDIAN
define|#
directive|define
name|IS_BIG_ENDIAN
value|4321
end_define
begin_comment
DECL|macro|IS_BIG_ENDIAN
comment|/* byte 0 is most significant (mc68k) */
end_comment
begin_define
DECL|macro|IS_LITTLE_ENDIAN
define|#
directive|define
name|IS_LITTLE_ENDIAN
value|1234
end_define
begin_comment
DECL|macro|IS_LITTLE_ENDIAN
comment|/* byte 0 is least significant (i386) */
end_comment
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* Include files where endian defines and byteswap functions may reside */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sun
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/isa_defs.h>
end_include
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
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<sys/endian.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|||
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__CYGWIN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|__DJGPP__
argument_list|)
operator|||
name|defined
argument_list|(
name|__osf__
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<machine/endian.h>
end_include
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
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNU_LIBRARY__
argument_list|)
end_elif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_AIX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<endian.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__BEOS__
argument_list|)
end_if
begin_include
include|#
directive|include
file|<byteswap.h>
end_include
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Now attempt to set the define for platform byte order using any  */
end_comment
begin_comment
comment|/* of the four forms SYMBOL, _SYMBOL, __SYMBOL& __SYMBOL__, which  */
end_comment
begin_comment
comment|/* seem to encompass most endian symbol definitions                 */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|BIG_ENDIAN
argument_list|)
operator|&&
name|defined
argument_list|(
name|LITTLE_ENDIAN
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_BIG_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_LITTLE_ENDIAN
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
name|BIG_ENDIAN
argument_list|)
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_BIG_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|LITTLE_ENDIAN
argument_list|)
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_LITTLE_ENDIAN
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
name|_BIG_ENDIAN
argument_list|)
operator|&&
name|defined
argument_list|(
name|_LITTLE_ENDIAN
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_BYTE_ORDER
argument_list|)
operator|&&
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_BIG_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_BYTE_ORDER
argument_list|)
operator|&&
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_LITTLE_ENDIAN
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
name|_BIG_ENDIAN
argument_list|)
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_BIG_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_LITTLE_ENDIAN
argument_list|)
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_LITTLE_ENDIAN
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
name|__BIG_ENDIAN
argument_list|)
operator|&&
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BYTE_ORDER
argument_list|)
operator|&&
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
end_if
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_BIG_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__BYTE_ORDER
argument_list|)
operator|&&
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_LITTLE_ENDIAN
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
name|__BIG_ENDIAN
argument_list|)
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_BIG_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_LITTLE_ENDIAN
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
name|__BIG_ENDIAN__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__LITTLE_ENDIAN__
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BYTE_ORDER__
argument_list|)
operator|&&
name|__BYTE_ORDER__
operator|==
name|__BIG_ENDIAN__
end_if
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_BIG_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__BYTE_ORDER__
argument_list|)
operator|&&
name|__BYTE_ORDER__
operator|==
name|__LITTLE_ENDIAN__
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_LITTLE_ENDIAN
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
name|__BIG_ENDIAN__
argument_list|)
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_BIG_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN__
argument_list|)
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_LITTLE_ENDIAN
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*  if the platform byte order could not be determined, then try to */
end_comment
begin_comment
comment|/*  set this define using common machine defines                    */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PLATFORM_BYTE_ORDER
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_I86
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__OS2__
argument_list|)
operator|||
name|defined
argument_list|(
name|sun386
argument_list|)
operator|||
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|vms
argument_list|)
operator|||
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
end_if
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_LITTLE_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|AMIGA
argument_list|)
operator|||
name|defined
argument_list|(
name|applec
argument_list|)
operator|||
name|defined
argument_list|(
name|__AS400__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|_CRAY
argument_list|)
operator|||
name|defined
argument_list|(
name|__hppa
argument_list|)
operator|||
name|defined
argument_list|(
name|__hp9000
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ibm370
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68000
argument_list|)
operator|||
name|defined
argument_list|(
name|m68k
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__MRC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MVS__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|SYMANTEC_C
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__VOS__
argument_list|)
operator|||
name|defined
argument_list|(
name|__TIGCC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__TANDEM
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|THINK_C
argument_list|)
operator|||
name|defined
argument_list|(
name|__VMCMS__
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
end_elif
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_BIG_ENDIAN
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif
begin_ifdef
ifdef|#
directive|ifdef
name|__BIG_ENDIAN
end_ifdef
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_BIG_ENDIAN
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_LITTLE_ENDIAN
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
literal|1
end_elif
begin_comment
comment|/* **** EDIT HERE IF NECESSARY **** */
end_comment
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_LITTLE_ENDIAN
end_define
begin_elif
elif|#
directive|elif
literal|0
end_elif
begin_comment
comment|/* **** EDIT HERE IF NECESSARY **** */
end_comment
begin_define
DECL|macro|PLATFORM_BYTE_ORDER
define|#
directive|define
name|PLATFORM_BYTE_ORDER
value|IS_BIG_ENDIAN
end_define
begin_else
else|#
directive|else
end_else
begin_error
error|#
directive|error
error|Please edit lines 132 or 134 in brg_endian.h to set the platform byte order
end_error
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
end_unit
