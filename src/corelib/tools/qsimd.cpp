begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Copyright (C) 2012 Intel Corporation. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsimd_p.h"
end_include
begin_include
include|#
directive|include
file|<QByteArray>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_LINUX
end_ifdef
begin_include
include|#
directive|include
file|"../testlib/3rdparty/valgrind_p.h"
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
name|Q_OS_WIN
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<cmnintrin.h>
end_include
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
name|Q_CC_GNU
argument_list|)
end_if
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_include
include|#
directive|include
file|<intrin.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|Q_PROCESSOR_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_PROCESSOR_MIPS_32
argument_list|)
operator|)
end_elif
begin_include
include|#
directive|include
file|"private/qcore_unix_p.h"
end_include
begin_comment
comment|// the kernel header definitions for HWCAP_*
end_comment
begin_comment
comment|// (the ones we need/may need anyway)
end_comment
begin_comment
comment|// copied from<asm/hwcap.h> (ARM)
end_comment
begin_define
DECL|macro|HWCAP_CRUNCH
define|#
directive|define
name|HWCAP_CRUNCH
value|1024
end_define
begin_define
DECL|macro|HWCAP_THUMBEE
define|#
directive|define
name|HWCAP_THUMBEE
value|2048
end_define
begin_define
DECL|macro|HWCAP_NEON
define|#
directive|define
name|HWCAP_NEON
value|4096
end_define
begin_define
DECL|macro|HWCAP_VFPv3
define|#
directive|define
name|HWCAP_VFPv3
value|8192
end_define
begin_define
DECL|macro|HWCAP_VFPv3D16
define|#
directive|define
name|HWCAP_VFPv3D16
value|16384
end_define
begin_comment
comment|// copied from<linux/auxvec.h>
end_comment
begin_define
DECL|macro|AT_HWCAP
define|#
directive|define
name|AT_HWCAP
value|16
end_define
begin_comment
DECL|macro|AT_HWCAP
comment|/* arch dependent hints at CPU capabilities */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_NACL
argument_list|)
DECL|function|detectProcessorFeatures
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_elif
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|ARM
argument_list|)
ifdef|#
directive|ifdef
name|PF_ARM_NEON
if|if
condition|(
name|IsProcessorFeaturePresent
argument_list|(
name|PF_ARM_NEON
argument_list|)
condition|)
name|features
operator||=
name|ARM_NEON
expr_stmt|;
endif|#
directive|endif
elif|#
directive|elif
name|defined
argument_list|(
name|_X86_
argument_list|)
if|if
condition|(
name|IsProcessorFeaturePresent
argument_list|(
name|PF_XMMI64_INSTRUCTIONS_AVAILABLE
argument_list|)
condition|)
name|features
operator||=
name|SSE2
expr_stmt|;
if|if
condition|(
name|IsProcessorFeaturePresent
argument_list|(
name|PF_SSE3_INSTRUCTIONS_AVAILABLE
argument_list|)
condition|)
name|features
operator||=
name|SSE3
expr_stmt|;
endif|#
directive|endif
return|return
name|features
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_ARM
argument_list|)
end_elif
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
name|int
name|auxv
init|=
name|qt_safe_open
argument_list|(
literal|"/proc/self/auxv"
argument_list|,
name|O_RDONLY
argument_list|)
decl_stmt|;
if|if
condition|(
name|auxv
operator|!=
operator|-
literal|1
condition|)
block|{
name|unsigned
name|long
name|vector
index|[
literal|64
index|]
decl_stmt|;
name|int
name|nread
decl_stmt|;
while|while
condition|(
name|features
operator|==
literal|0
condition|)
block|{
name|nread
operator|=
name|qt_safe_read
argument_list|(
name|auxv
argument_list|,
operator|(
name|char
operator|*
operator|)
name|vector
argument_list|,
sizeof|sizeof
name|vector
argument_list|)
expr_stmt|;
if|if
condition|(
name|nread
operator|<=
literal|0
condition|)
block|{
comment|// EOF or error
break|break;
block|}
name|int
name|max
init|=
name|nread
operator|/
operator|(
sizeof|sizeof
name|vector
index|[
literal|0
index|]
operator|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|max
condition|;
name|i
operator|+=
literal|2
control|)
if|if
condition|(
name|vector
index|[
name|i
index|]
operator|==
name|AT_HWCAP
condition|)
block|{
if|if
condition|(
name|vector
index|[
name|i
operator|+
literal|1
index|]
operator|&
name|HWCAP_NEON
condition|)
name|features
operator||=
name|NEON
expr_stmt|;
break|break;
block|}
block|}
name|qt_safe_close
argument_list|(
name|auxv
argument_list|)
expr_stmt|;
return|return
name|features
return|;
block|}
comment|// fall back if /proc/self/auxv wasn't found
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__ARM_NEON__
argument_list|)
name|features
operator|=
name|NEON
expr_stmt|;
endif|#
directive|endif
return|return
name|features
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
end_elif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_PROCESSOR_X86_32
end_ifdef
begin_define
define|#
directive|define
name|PICreg
value|"%%ebx"
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|PICreg
value|"%%rbx"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
name|int
name|maxBasicCpuidSupported
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
name|qregisterint
name|tmp1
decl_stmt|;
if|#
directive|if
name|Q_PROCESSOR_X86
operator|<
literal|5
comment|// check if the CPUID instruction is supported
name|long
name|cpuid_supported
decl_stmt|;
asm|asm ("pushf\n"          "pop %0\n"          "mov %0, %1\n"          "xor $0x00200000, %0\n"          "push %0\n"          "popf\n"          "pushf\n"          "pop %0\n"          "xor %1, %0\n"
comment|// %eax is now 0 if CPUID is not supported
asm|: "=a" (cpuid_supported), "=r" (tmp1)          );
if|if
condition|(
operator|!
name|cpuid_supported
condition|)
return|return
literal|0
return|;
endif|#
directive|endif
name|int
name|result
decl_stmt|;
asm|asm ("xchg " PICreg", %1\n"          "cpuid\n"          "xchg " PICreg", %1\n"         : "=&a" (result), "=&r" (tmp1)         : "0" (0)         : "ecx", "edx");
return|return
name|result
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
comment|// Use the __cpuid function; if the CPUID instruction isn't supported, it will return 0
name|int
name|info
index|[
literal|4
index|]
decl_stmt|;
name|__cpuid
argument_list|(
name|info
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|info
index|[
literal|0
index|]
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
specifier|static
name|void
name|cpuidFeatures01
parameter_list|(
name|uint
modifier|&
name|ecx
parameter_list|,
name|uint
modifier|&
name|edx
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
name|qregisterint
name|tmp1
decl_stmt|;
asm|asm ("xchg " PICreg", %2\n"          "cpuid\n"          "xchg " PICreg", %2\n"         : "=&c" (ecx), "=&d" (edx), "=&r" (tmp1)         : "a" (1));
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|int
name|info
index|[
literal|4
index|]
decl_stmt|;
name|__cpuid
argument_list|(
name|info
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|ecx
operator|=
name|info
index|[
literal|2
index|]
expr_stmt|;
name|edx
operator|=
name|info
index|[
literal|3
index|]
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_function
specifier|inline
name|void
name|__cpuidex
parameter_list|(
name|int
name|info
index|[
literal|4
index|]
parameter_list|,
name|int
parameter_list|,
name|__int64
parameter_list|)
block|{
name|memset
argument_list|(
name|info
argument_list|,
literal|0
argument_list|,
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
name|void
name|cpuidFeatures07_00
parameter_list|(
name|uint
modifier|&
name|ebx
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
name|qregisteruint
name|rbx
decl_stmt|;
comment|// in case it's 64-bit
asm|asm ("xchg " PICreg", %0\n"          "cpuid\n"          "xchg " PICreg", %0\n"         : "=&r" (rbx)         : "a" (7), "c" (0)         : "%edx");
name|ebx
operator|=
name|rbx
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|int
name|info
index|[
literal|4
index|]
decl_stmt|;
name|__cpuidex
argument_list|(
name|info
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|ebx
operator|=
name|info
index|[
literal|1
index|]
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_comment
comment|// fallback overload in case this intrinsic does not exist: unsigned __int64 _xgetbv(unsigned int);
end_comment
begin_function
specifier|inline
name|quint64
name|_xgetbv
parameter_list|(
name|__int64
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
name|void
name|xgetbv
parameter_list|(
name|uint
name|in
parameter_list|,
name|uint
modifier|&
name|eax
parameter_list|,
name|uint
modifier|&
name|edx
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
asm|asm (".byte 0x0F, 0x01, 0xD0"
comment|// xgetbv instruction
asm|: "=a" (eax), "=d" (edx)         : "c" (in));
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|quint64
name|result
init|=
name|_xgetbv
argument_list|(
name|in
argument_list|)
decl_stmt|;
name|eax
operator|=
name|result
expr_stmt|;
name|edx
operator|=
name|result
operator|>>
literal|32
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
comment|// Flags from the CR0 / XCR0 state register
enum|enum
name|XCR0Flags
block|{
name|X87
init|=
literal|1
operator|<<
literal|0
block|,
name|XMM0_15
init|=
literal|1
operator|<<
literal|1
block|,
name|YMM0_15Hi128
init|=
literal|1
operator|<<
literal|2
block|,
name|BNDRegs
init|=
literal|1
operator|<<
literal|3
block|,
name|BNDCSR
init|=
literal|1
operator|<<
literal|4
block|,
name|OpMask
init|=
literal|1
operator|<<
literal|5
block|,
name|ZMM0_15Hi256
init|=
literal|1
operator|<<
literal|6
block|,
name|ZMM16_31
init|=
literal|1
operator|<<
literal|7
block|,
name|SSEState
init|=
name|XMM0_15
block|,
name|AVXState
init|=
name|XMM0_15
operator||
name|YMM0_15Hi128
block|,
name|AVX512State
init|=
name|AVXState
operator||
name|OpMask
operator||
name|ZMM0_15Hi256
operator||
name|ZMM16_31
block|}
enum|;
name|uint
name|features
init|=
literal|0
decl_stmt|;
name|int
name|cpuidLevel
init|=
name|maxBasicCpuidSupported
argument_list|()
decl_stmt|;
if|if
condition|(
name|cpuidLevel
operator|<
literal|1
condition|)
return|return
literal|0
return|;
name|uint
name|cpuid01ECX
init|=
literal|0
decl_stmt|,
name|cpuid01EDX
init|=
literal|0
decl_stmt|;
name|cpuidFeatures01
argument_list|(
name|cpuid01ECX
argument_list|,
name|cpuid01EDX
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_PROCESSOR_X86_32
argument_list|)
comment|// x86 might not have SSE2 support
if|if
condition|(
name|cpuid01EDX
operator|&
operator|(
literal|1u
operator|<<
literal|26
operator|)
condition|)
name|features
operator||=
name|SSE2
expr_stmt|;
comment|// we should verify that the OS enabled saving of the SSE state...
else|#
directive|else
comment|// x86-64 or x32
name|features
operator|=
name|SSE2
expr_stmt|;
endif|#
directive|endif
comment|// common part between 32- and 64-bit
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|)
condition|)
name|features
operator||=
name|SSE3
expr_stmt|;
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|9
operator|)
condition|)
name|features
operator||=
name|SSSE3
expr_stmt|;
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|19
operator|)
condition|)
name|features
operator||=
name|SSE4_1
expr_stmt|;
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|20
operator|)
condition|)
name|features
operator||=
name|SSE4_2
expr_stmt|;
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|25
operator|)
condition|)
name|features
operator||=
literal|0
expr_stmt|;
comment|// AES, enable if needed
name|uint
name|xgetbvA
init|=
literal|0
decl_stmt|,
name|xgetbvD
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|27
operator|)
condition|)
block|{
comment|// XGETBV enabled
name|xgetbv
argument_list|(
literal|0
argument_list|,
name|xgetbvA
argument_list|,
name|xgetbvD
argument_list|)
expr_stmt|;
block|}
name|uint
name|cpuid0700EBX
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|cpuidLevel
operator|>=
literal|7
condition|)
name|cpuidFeatures07_00
argument_list|(
name|cpuid0700EBX
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|xgetbvA
operator|&
name|AVXState
operator|)
operator|==
name|AVXState
condition|)
block|{
comment|// support for YMM and XMM registers is enabled
if|if
condition|(
name|cpuid01ECX
operator|&
operator|(
literal|1u
operator|<<
literal|28
operator|)
condition|)
name|features
operator||=
name|AVX
expr_stmt|;
if|if
condition|(
name|cpuid0700EBX
operator|&
operator|(
literal|1u
operator|<<
literal|5
operator|)
condition|)
name|features
operator||=
name|AVX2
expr_stmt|;
block|}
if|if
condition|(
name|cpuid0700EBX
operator|&
operator|(
literal|1u
operator|<<
literal|4
operator|)
condition|)
name|features
operator||=
name|HLE
expr_stmt|;
comment|// Hardware Lock Ellision
if|if
condition|(
name|cpuid0700EBX
operator|&
operator|(
literal|1u
operator|<<
literal|11
operator|)
condition|)
name|features
operator||=
name|RTM
expr_stmt|;
comment|// Restricted Transactional Memory
return|return
name|features
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_PROCESSOR_MIPS_32
argument_list|)
end_elif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
end_if
begin_comment
comment|//
end_comment
begin_comment
comment|// Do not use QByteArray: it could use SIMD instructions itself at
end_comment
begin_comment
comment|// some point, thus creating a recursive dependency. Instead, use a
end_comment
begin_comment
comment|// QSimpleBuffer, which has the bare minimum needed to use memory
end_comment
begin_comment
comment|// dynamically and read lines from /proc/cpuinfo of arbitrary sizes.
end_comment
begin_comment
comment|//
end_comment
begin_struct
struct|struct
name|QSimpleBuffer
block|{
specifier|static
specifier|const
name|int
name|chunk_size
init|=
literal|256
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
name|unsigned
name|alloc
decl_stmt|;
name|unsigned
name|size
decl_stmt|;
name|QSimpleBuffer
parameter_list|()
member_init_list|:
name|data
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|alloc
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|size
argument_list|(
literal|0
argument_list|)
block|{}
name|~
name|QSimpleBuffer
parameter_list|()
block|{
operator|::
name|free
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
name|void
name|resize
parameter_list|(
name|unsigned
name|newsize
parameter_list|)
block|{
if|if
condition|(
name|newsize
operator|>
name|alloc
condition|)
block|{
name|unsigned
name|newalloc
init|=
name|chunk_size
operator|*
operator|(
operator|(
name|newsize
operator|/
name|chunk_size
operator|)
operator|+
literal|1
operator|)
decl_stmt|;
if|if
condition|(
name|newalloc
operator|<
name|newsize
condition|)
name|newalloc
operator|=
name|newsize
expr_stmt|;
if|if
condition|(
name|newalloc
operator|!=
name|alloc
condition|)
block|{
name|data
operator|=
cast|static_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
operator|::
name|realloc
argument_list|(
name|data
argument_list|,
name|newalloc
argument_list|)
argument_list|)
expr_stmt|;
name|alloc
operator|=
name|newalloc
expr_stmt|;
block|}
block|}
name|size
operator|=
name|newsize
expr_stmt|;
block|}
name|void
name|append
parameter_list|(
specifier|const
name|QSimpleBuffer
modifier|&
name|other
parameter_list|,
name|unsigned
name|appendsize
parameter_list|)
block|{
name|unsigned
name|oldsize
init|=
name|size
decl_stmt|;
name|resize
argument_list|(
name|oldsize
operator|+
name|appendsize
argument_list|)
expr_stmt|;
operator|::
name|memcpy
argument_list|(
name|data
operator|+
name|oldsize
argument_list|,
name|other
operator|.
name|data
argument_list|,
name|appendsize
argument_list|)
expr_stmt|;
block|}
name|void
name|popleft
parameter_list|(
name|unsigned
name|amount
parameter_list|)
block|{
if|if
condition|(
name|amount
operator|>=
name|size
condition|)
return|return
name|resize
argument_list|(
literal|0
argument_list|)
return|;
name|size
operator|-=
name|amount
expr_stmt|;
operator|::
name|memmove
argument_list|(
name|data
argument_list|,
name|data
operator|+
name|amount
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
name|char
modifier|*
name|cString
parameter_list|()
block|{
if|if
condition|(
operator|!
name|alloc
condition|)
name|resize
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
name|data
index|[
name|size
index|]
operator|=
literal|'\0'
operator|,
name|data
operator|)
return|;
block|}
block|}
struct|;
end_struct
begin_comment
comment|//
end_comment
begin_comment
comment|// Uses a scratch "buffer" (which must be used for all reads done in the
end_comment
begin_comment
comment|// same file descriptor) to read chunks of data from a file, to read
end_comment
begin_comment
comment|// one line at a time. Lines include the trailing newline character ('\n').
end_comment
begin_comment
comment|// On EOF, line.size is zero.
end_comment
begin_comment
comment|//
end_comment
begin_function
specifier|static
name|void
name|bufReadLine
parameter_list|(
name|int
name|fd
parameter_list|,
name|QSimpleBuffer
modifier|&
name|line
parameter_list|,
name|QSimpleBuffer
modifier|&
name|buffer
parameter_list|)
block|{
for|for
control|(
init|;
condition|;
control|)
block|{
name|char
modifier|*
name|newline
init|=
cast|static_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
operator|::
name|memchr
argument_list|(
name|buffer
operator|.
name|data
argument_list|,
literal|'\n'
argument_list|,
name|buffer
operator|.
name|size
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|newline
condition|)
block|{
name|unsigned
name|piece_size
init|=
name|newline
operator|-
name|buffer
operator|.
name|data
operator|+
literal|1
decl_stmt|;
name|line
operator|.
name|append
argument_list|(
name|buffer
argument_list|,
name|piece_size
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|popleft
argument_list|(
name|piece_size
argument_list|)
expr_stmt|;
name|line
operator|.
name|resize
argument_list|(
name|line
operator|.
name|size
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|buffer
operator|.
name|size
operator|+
name|QSimpleBuffer
operator|::
name|chunk_size
operator|>
name|buffer
operator|.
name|alloc
condition|)
block|{
name|int
name|oldsize
init|=
name|buffer
operator|.
name|size
decl_stmt|;
name|buffer
operator|.
name|resize
argument_list|(
name|buffer
operator|.
name|size
operator|+
name|QSimpleBuffer
operator|::
name|chunk_size
argument_list|)
expr_stmt|;
name|buffer
operator|.
name|size
operator|=
name|oldsize
expr_stmt|;
block|}
name|ssize_t
name|read_bytes
init|=
operator|::
name|qt_safe_read
argument_list|(
name|fd
argument_list|,
name|buffer
operator|.
name|data
operator|+
name|buffer
operator|.
name|size
argument_list|,
name|QSimpleBuffer
operator|::
name|chunk_size
argument_list|)
decl_stmt|;
if|if
condition|(
name|read_bytes
operator|>
literal|0
condition|)
name|buffer
operator|.
name|size
operator|+=
name|read_bytes
expr_stmt|;
else|else
return|return;
block|}
block|}
end_function
begin_comment
comment|//
end_comment
begin_comment
comment|// Checks if any line with a given prefix from /proc/cpuinfo contains
end_comment
begin_comment
comment|// a certain string, surrounded by spaces.
end_comment
begin_comment
comment|//
end_comment
begin_function
specifier|static
name|bool
name|procCpuinfoContains
parameter_list|(
specifier|const
name|char
modifier|*
name|prefix
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|)
block|{
name|int
name|cpuinfo_fd
init|=
operator|::
name|qt_safe_open
argument_list|(
literal|"/proc/cpuinfo"
argument_list|,
name|O_RDONLY
argument_list|)
decl_stmt|;
if|if
condition|(
name|cpuinfo_fd
operator|==
operator|-
literal|1
condition|)
return|return
literal|false
return|;
name|unsigned
name|string_len
init|=
operator|::
name|strlen
argument_list|(
name|string
argument_list|)
decl_stmt|;
name|unsigned
name|prefix_len
init|=
operator|::
name|strlen
argument_list|(
name|prefix
argument_list|)
decl_stmt|;
name|QSimpleBuffer
name|line
decl_stmt|,
name|buffer
decl_stmt|;
name|bool
name|present
init|=
literal|false
decl_stmt|;
do|do
block|{
name|line
operator|.
name|resize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|bufReadLine
argument_list|(
name|cpuinfo_fd
argument_list|,
name|line
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
name|char
modifier|*
name|colon
init|=
cast|static_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
operator|::
name|memchr
argument_list|(
name|line
operator|.
name|data
argument_list|,
literal|':'
argument_list|,
name|line
operator|.
name|size
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|colon
operator|&&
name|line
operator|.
name|size
operator|>
name|prefix_len
operator|+
name|string_len
condition|)
block|{
if|if
condition|(
operator|!
operator|::
name|strncmp
argument_list|(
name|prefix
argument_list|,
name|line
operator|.
name|data
argument_list|,
name|prefix_len
argument_list|)
condition|)
block|{
comment|// prefix matches, next character must be ':' or space
if|if
condition|(
name|line
operator|.
name|data
index|[
name|prefix_len
index|]
operator|==
literal|':'
operator|||
operator|::
name|isspace
argument_list|(
name|line
operator|.
name|data
index|[
name|prefix_len
index|]
argument_list|)
condition|)
block|{
comment|// Does it contain the string?
name|char
modifier|*
name|found
init|=
operator|::
name|strstr
argument_list|(
name|line
operator|.
name|cString
argument_list|()
argument_list|,
name|string
argument_list|)
decl_stmt|;
if|if
condition|(
name|found
operator|&&
operator|::
name|isspace
argument_list|(
name|found
index|[
operator|-
literal|1
index|]
argument_list|)
operator|&&
operator|(
operator|::
name|isspace
argument_list|(
name|found
index|[
name|string_len
index|]
argument_list|)
operator|||
name|found
index|[
name|string_len
index|]
operator|==
literal|'\0'
operator|)
condition|)
block|{
name|present
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
block|}
do|while
condition|(
name|line
operator|.
name|size
condition|)
do|;
operator|::
name|qt_safe_close
argument_list|(
name|cpuinfo_fd
argument_list|)
expr_stmt|;
return|return
name|present
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
comment|// NOTE: MIPS 74K cores are the only ones supporting DSPr2.
name|uint
name|flags
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|defined
name|__mips_dsp
name|flags
operator||=
name|DSP
expr_stmt|;
if|#
directive|if
name|defined
name|__mips_dsp_rev
operator|&&
name|__mips_dsp_rev
operator|>=
literal|2
name|flags
operator||=
name|DSPR2
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
if|if
condition|(
name|procCpuinfoContains
argument_list|(
literal|"cpu model"
argument_list|,
literal|"MIPS 74Kc"
argument_list|)
operator|||
name|procCpuinfoContains
argument_list|(
literal|"cpu model"
argument_list|,
literal|"MIPS 74Kf"
argument_list|)
condition|)
name|flags
operator||=
name|DSPR2
expr_stmt|;
endif|#
directive|endif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
if|if
condition|(
name|procCpuinfoContains
argument_list|(
literal|"ASEs implemented"
argument_list|,
literal|"dsp"
argument_list|)
condition|)
block|{
name|flags
operator||=
name|DSP
expr_stmt|;
if|if
condition|(
name|procCpuinfoContains
argument_list|(
literal|"cpu model"
argument_list|,
literal|"MIPS 74Kc"
argument_list|)
operator|||
name|procCpuinfoContains
argument_list|(
literal|"cpu model"
argument_list|,
literal|"MIPS 74Kf"
argument_list|)
condition|)
name|flags
operator||=
name|DSPR2
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|flags
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
specifier|static
specifier|inline
name|uint
name|detectProcessorFeatures
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*  * Use kdesdk/scripts/generate_string_table.pl to update the table below.  * Here's the data (don't forget the ONE leading space):   neon  sse2  sse3  ssse3  sse4.1  sse4.2  avx  avx2  hle  rtm  dsp  dspr2   */
end_comment
begin_comment
comment|// begin generated
end_comment
begin_decl_stmt
DECL|variable|features_string
specifier|static
specifier|const
name|char
name|features_string
index|[]
init|=
literal|"\0"
literal|" neon\0"
literal|" sse2\0"
literal|" sse3\0"
literal|" ssse3\0"
literal|" sse4.1\0"
literal|" sse4.2\0"
literal|" avx\0"
literal|" avx2\0"
literal|" hle\0"
literal|" rtm\0"
literal|" dsp\0"
literal|" dspr2\0"
literal|"\0"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|features_indices
specifier|static
specifier|const
name|int
name|features_indices
index|[]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|7
block|,
literal|13
block|,
literal|19
block|,
literal|26
block|,
literal|34
block|,
literal|42
block|,
literal|47
block|,
literal|53
block|,
literal|58
block|,
literal|63
block|,
literal|68
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|// end generated
end_comment
begin_decl_stmt
DECL|variable|features_count
specifier|static
specifier|const
name|int
name|features_count
init|=
operator|(
sizeof|sizeof
name|features_indices
operator|-
literal|1
operator|)
operator|/
operator|(
sizeof|sizeof
name|features_indices
index|[
literal|0
index|]
operator|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|// record what CPU features were enabled by default in this Qt build
end_comment
begin_decl_stmt
DECL|variable|minFeature
specifier|static
specifier|const
name|uint
name|minFeature
init|=
name|qCompilerCpuFeatures
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_define
DECL|macro|ffs
define|#
directive|define
name|ffs
value|__builtin_ffs
end_define
begin_else
else|#
directive|else
end_else
begin_function
DECL|function|ffs
name|int
name|ffs
parameter_list|(
name|int
name|i
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|unsigned
name|long
name|result
decl_stmt|;
return|return
name|_BitScanForward
argument_list|(
operator|&
name|result
argument_list|,
name|i
argument_list|)
condition|?
name|result
else|:
literal|0
return|;
else|#
directive|else
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
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
end_elif
begin_define
DECL|macro|ffs
define|#
directive|define
name|ffs
value|__builtin_ffs
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|qt_cpu_features
name|QBasicAtomicInt
name|qt_cpu_features
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qDetectCpuFeatures
name|void
name|qDetectCpuFeatures
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_CLANG
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
if|#
directive|if
name|Q_CC_GNU
operator|<
literal|403
comment|// GCC 4.2 (at least the one that comes with Apple's XCode, on Mac) is
comment|// known to be broken beyond repair in dealing with the inline assembly
comment|// above. It will generate bad code that could corrupt important registers
comment|// like the PIC register. The behaviour of code after this function would
comment|// be totally unpredictable.
comment|//
comment|// For that reason, simply forego the CPUID check at all and return the set
comment|// of features that we found at compile time, through the #defines from the
comment|// compiler. This should at least allow code to execute, even if none of
comment|// the specialized code found in Qt GUI and elsewhere will ever be enabled
comment|// (it's the user's fault for using a broken compiler).
comment|//
comment|// This also disables the runtime checking that the processor actually
comment|// contains all the features that the code required. Qt 4 ran for years
comment|// like that, so it shouldn't be a problem.
name|qt_cpu_features
operator|.
name|store
argument_list|(
name|minFeature
operator||
name|QSimdInitialized
argument_list|)
expr_stmt|;
return|return;
endif|#
directive|endif
endif|#
directive|endif
name|uint
name|f
init|=
name|detectProcessorFeatures
argument_list|()
decl_stmt|;
name|QByteArray
name|disable
init|=
name|qgetenv
argument_list|(
literal|"QT_NO_CPU_FEATURE"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|disable
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|disable
operator|.
name|prepend
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|features_count
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|disable
operator|.
name|contains
argument_list|(
name|features_string
operator|+
name|features_indices
index|[
name|i
index|]
argument_list|)
condition|)
name|f
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|i
operator|)
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|RUNNING_ON_VALGRIND
name|bool
name|runningOnValgrind
init|=
name|RUNNING_ON_VALGRIND
decl_stmt|;
else|#
directive|else
name|bool
name|runningOnValgrind
init|=
literal|false
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|runningOnValgrind
operator|&&
operator|(
name|minFeature
operator|!=
literal|0
operator|&&
operator|(
name|f
operator|&
name|minFeature
operator|)
operator|!=
name|minFeature
operator|)
condition|)
block|{
name|uint
name|missing
init|=
name|minFeature
operator|&
operator|~
name|f
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Incompatible processor. This Qt build requires the following features:\n   "
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|features_count
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|missing
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s"
argument_list|,
name|features_string
operator|+
name|features_indices
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|qFatal
argument_list|(
literal|"Aborted. Incompatible processor: missing feature 0x%x -%s."
argument_list|,
name|missing
argument_list|,
name|features_string
operator|+
name|features_indices
index|[
name|ffs
argument_list|(
name|missing
argument_list|)
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
name|qt_cpu_features
operator|.
name|store
argument_list|(
name|f
operator||
name|QSimdInitialized
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|qDumpCPUFeatures
name|void
name|qDumpCPUFeatures
parameter_list|()
block|{
name|uint
name|features
init|=
name|qCpuFeatures
argument_list|()
decl_stmt|;
name|printf
argument_list|(
literal|"Processor features: "
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|features_count
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|features
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
name|printf
argument_list|(
literal|"%s%s"
argument_list|,
name|features_string
operator|+
name|features_indices
index|[
name|i
index|]
argument_list|,
name|minFeature
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|?
literal|"[required]"
else|:
literal|""
argument_list|)
expr_stmt|;
block|}
name|puts
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
