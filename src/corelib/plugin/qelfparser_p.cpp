begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qelfparser_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LIBRARY
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OF_ELF
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qlibrary_p.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|// #define QELFPARSER_DEBUG 1
DECL|function|parseSectionHeader
specifier|const
name|char
modifier|*
name|QElfParser
operator|::
name|parseSectionHeader
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|ElfSectionHeader
modifier|*
name|sh
parameter_list|)
block|{
name|sh
operator|->
name|name
operator|=
name|read
argument_list|<
name|qelfword_t
argument_list|>
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|data
operator|+=
sizeof|sizeof
argument_list|(
name|qelfword_t
argument_list|)
expr_stmt|;
comment|// sh_name
name|sh
operator|->
name|type
operator|=
name|read
argument_list|<
name|qelfword_t
argument_list|>
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|data
operator|+=
sizeof|sizeof
argument_list|(
name|qelfword_t
argument_list|)
comment|// sh_type
operator|+
sizeof|sizeof
argument_list|(
name|qelfaddr_t
argument_list|)
comment|// sh_flags
operator|+
sizeof|sizeof
argument_list|(
name|qelfaddr_t
argument_list|)
expr_stmt|;
comment|// sh_addr
name|sh
operator|->
name|offset
operator|=
name|read
argument_list|<
name|qelfoff_t
argument_list|>
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|data
operator|+=
sizeof|sizeof
argument_list|(
name|qelfoff_t
argument_list|)
expr_stmt|;
comment|// sh_offset
name|sh
operator|->
name|size
operator|=
name|read
argument_list|<
name|qelfword_t
argument_list|>
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|data
operator|+=
sizeof|sizeof
argument_list|(
name|qelfword_t
argument_list|)
expr_stmt|;
comment|// sh_size
return|return
name|data
return|;
block|}
end_function
begin_function
DECL|function|parse
name|int
name|QElfParser
operator|::
name|parse
parameter_list|(
specifier|const
name|char
modifier|*
name|dataStart
parameter_list|,
name|ulong
name|fdlen
parameter_list|,
specifier|const
name|QString
modifier|&
name|library
parameter_list|,
name|QLibraryPrivate
modifier|*
name|lib
parameter_list|,
name|long
modifier|*
name|pos
parameter_list|,
name|ulong
modifier|*
name|sectionlen
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QELFPARSER_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"QElfParser::parse "
operator|<<
name|library
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|fdlen
operator|<
literal|64
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is not an ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"file too small"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|NotElf
return|;
block|}
specifier|const
name|char
modifier|*
name|data
init|=
name|dataStart
decl_stmt|;
if|if
condition|(
name|qstrncmp
argument_list|(
name|data
argument_list|,
literal|"\177ELF"
argument_list|,
literal|4
argument_list|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is not an ELF object"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
expr_stmt|;
return|return
name|NotElf
return|;
block|}
comment|// 32 or 64 bit
if|if
condition|(
name|data
index|[
literal|4
index|]
operator|!=
literal|1
operator|&&
name|data
index|[
literal|4
index|]
operator|!=
literal|2
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is an invalid ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"odd cpu architecture"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Corrupt
return|;
block|}
name|m_bits
operator|=
operator|(
name|data
index|[
literal|4
index|]
operator|<<
literal|5
operator|)
expr_stmt|;
comment|/*  If you remove this check, to read ELF objects of a different arch, please make sure you modify the typedefs         to match the _plugin_ architecture.     */
if|if
condition|(
operator|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|==
literal|4
operator|&&
name|m_bits
operator|!=
literal|32
operator|)
operator|||
operator|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|==
literal|8
operator|&&
name|m_bits
operator|!=
literal|64
operator|)
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is an invalid ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"wrong cpu architecture"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Corrupt
return|;
block|}
comment|// endian
if|if
condition|(
name|data
index|[
literal|5
index|]
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is an invalid ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"odd endianess"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Corrupt
return|;
block|}
name|m_endian
operator|=
operator|(
name|data
index|[
literal|5
index|]
operator|==
literal|1
condition|?
name|ElfLittleEndian
else|:
name|ElfBigEndian
operator|)
expr_stmt|;
name|data
operator|+=
literal|16
comment|// e_ident
operator|+
sizeof|sizeof
argument_list|(
name|qelfhalf_t
argument_list|)
comment|// e_type
operator|+
sizeof|sizeof
argument_list|(
name|qelfhalf_t
argument_list|)
comment|// e_machine
operator|+
sizeof|sizeof
argument_list|(
name|qelfword_t
argument_list|)
comment|// e_version
operator|+
sizeof|sizeof
argument_list|(
name|qelfaddr_t
argument_list|)
comment|// e_entry
operator|+
sizeof|sizeof
argument_list|(
name|qelfoff_t
argument_list|)
expr_stmt|;
comment|// e_phoff
name|qelfoff_t
name|e_shoff
init|=
name|read
argument_list|<
name|qelfoff_t
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|data
operator|+=
sizeof|sizeof
argument_list|(
name|qelfoff_t
argument_list|)
comment|// e_shoff
operator|+
sizeof|sizeof
argument_list|(
name|qelfword_t
argument_list|)
expr_stmt|;
comment|// e_flags
name|qelfhalf_t
name|e_shsize
init|=
name|read
argument_list|<
name|qelfhalf_t
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
name|e_shsize
operator|>
name|fdlen
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is an invalid ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"unexpected e_shsize"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Corrupt
return|;
block|}
name|data
operator|+=
sizeof|sizeof
argument_list|(
name|qelfhalf_t
argument_list|)
comment|// e_ehsize
operator|+
sizeof|sizeof
argument_list|(
name|qelfhalf_t
argument_list|)
comment|// e_phentsize
operator|+
sizeof|sizeof
argument_list|(
name|qelfhalf_t
argument_list|)
expr_stmt|;
comment|// e_phnum
name|qelfhalf_t
name|e_shentsize
init|=
name|read
argument_list|<
name|qelfhalf_t
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
if|if
condition|(
name|e_shentsize
operator|%
literal|4
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is an invalid ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"unexpected e_shentsize"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Corrupt
return|;
block|}
name|data
operator|+=
sizeof|sizeof
argument_list|(
name|qelfhalf_t
argument_list|)
expr_stmt|;
comment|// e_shentsize
name|qelfhalf_t
name|e_shnum
init|=
name|read
argument_list|<
name|qelfhalf_t
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|data
operator|+=
sizeof|sizeof
argument_list|(
name|qelfhalf_t
argument_list|)
expr_stmt|;
comment|// e_shnum
name|qelfhalf_t
name|e_shtrndx
init|=
name|read
argument_list|<
name|qelfhalf_t
argument_list|>
argument_list|(
name|data
argument_list|)
decl_stmt|;
name|data
operator|+=
sizeof|sizeof
argument_list|(
name|qelfhalf_t
argument_list|)
expr_stmt|;
comment|// e_shtrndx
if|if
condition|(
call|(
name|quint32
call|)
argument_list|(
name|e_shnum
operator|*
name|e_shentsize
argument_list|)
operator|>
name|fdlen
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is an invalid ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"announced %2 sections, each %3 bytes, exceed file size"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|e_shnum
argument_list|)
operator|.
name|arg
argument_list|(
name|e_shentsize
argument_list|)
expr_stmt|;
return|return
name|Corrupt
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|QELFPARSER_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
name|e_shnum
operator|<<
literal|"sections starting at "
operator|<<
operator|(
literal|"0x"
operator|+
name|QByteArray
operator|::
name|number
argument_list|(
name|e_shoff
argument_list|,
literal|16
argument_list|)
operator|)
operator|.
name|data
argument_list|()
operator|<<
literal|"each"
operator|<<
name|e_shentsize
operator|<<
literal|"bytes"
expr_stmt|;
endif|#
directive|endif
name|ElfSectionHeader
name|strtab
decl_stmt|;
name|qulonglong
name|soff
init|=
name|e_shoff
operator|+
name|e_shentsize
operator|*
operator|(
name|e_shtrndx
operator|)
decl_stmt|;
if|if
condition|(
operator|(
name|soff
operator|+
name|e_shentsize
operator|)
operator|>
name|fdlen
operator|||
name|soff
operator|%
literal|4
operator|||
name|soff
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is an invalid ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"shstrtab section header seems to be at %1"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|soff
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Corrupt
return|;
block|}
name|parseSectionHeader
argument_list|(
name|dataStart
operator|+
name|soff
argument_list|,
operator|&
name|strtab
argument_list|)
expr_stmt|;
name|m_stringTableFileOffset
operator|=
name|strtab
operator|.
name|offset
expr_stmt|;
if|if
condition|(
call|(
name|quint32
call|)
argument_list|(
name|m_stringTableFileOffset
operator|+
name|e_shentsize
argument_list|)
operator|>=
name|fdlen
operator|||
name|m_stringTableFileOffset
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is an invalid ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"string table seems to be at %1"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|soff
argument_list|,
literal|16
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Corrupt
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|QELFPARSER_DEBUG
argument_list|)
name|qDebug
argument_list|(
literal|".shstrtab at 0x%s"
argument_list|,
name|QByteArray
operator|::
name|number
argument_list|(
name|m_stringTableFileOffset
argument_list|,
literal|16
argument_list|)
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
specifier|const
name|char
modifier|*
name|s
init|=
name|dataStart
operator|+
name|e_shoff
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
name|e_shnum
condition|;
operator|++
name|i
control|)
block|{
name|ElfSectionHeader
name|sh
decl_stmt|;
name|parseSectionHeader
argument_list|(
name|s
argument_list|,
operator|&
name|sh
argument_list|)
expr_stmt|;
if|if
condition|(
name|sh
operator|.
name|name
operator|==
literal|0
condition|)
block|{
name|s
operator|+=
name|e_shentsize
expr_stmt|;
continue|continue;
block|}
specifier|const
name|char
modifier|*
name|shnam
init|=
name|dataStart
operator|+
name|m_stringTableFileOffset
operator|+
name|sh
operator|.
name|name
decl_stmt|;
if|if
condition|(
name|m_stringTableFileOffset
operator|+
name|sh
operator|.
name|name
operator|>
name|fdlen
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is an invalid ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"section name %2 of %3 behind end of file"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
operator|.
name|arg
argument_list|(
name|e_shnum
argument_list|)
expr_stmt|;
return|return
name|Corrupt
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|QELFPARSER_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"++++"
operator|<<
name|i
operator|<<
name|shnam
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|qstrcmp
argument_list|(
name|shnam
argument_list|,
literal|".qtplugin"
argument_list|)
operator|==
literal|0
operator|||
name|qstrcmp
argument_list|(
name|shnam
argument_list|,
literal|".rodata"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|sh
operator|.
name|type
operator|&
literal|0x1
operator|)
condition|)
block|{
if|if
condition|(
name|shnam
index|[
literal|1
index|]
operator|==
literal|'r'
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is an invalid ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"empty .rodata. not a library."
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Corrupt
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|QELFPARSER_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"section is not program data. skipped."
expr_stmt|;
endif|#
directive|endif
name|s
operator|+=
name|e_shentsize
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|sh
operator|.
name|offset
operator|==
literal|0
operator|||
operator|(
name|sh
operator|.
name|offset
operator|+
name|sh
operator|.
name|size
operator|)
operator|>
name|fdlen
condition|)
block|{
if|if
condition|(
name|lib
condition|)
name|lib
operator|->
name|errorString
operator|=
name|QLibrary
operator|::
name|tr
argument_list|(
literal|"'%1' is an invalid ELF object (%2)"
argument_list|)
operator|.
name|arg
argument_list|(
name|library
argument_list|)
operator|.
name|arg
argument_list|(
name|QLatin1String
argument_list|(
literal|"missing section data. This is not a library."
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Corrupt
return|;
block|}
operator|*
name|pos
operator|=
name|sh
operator|.
name|offset
expr_stmt|;
operator|*
name|sectionlen
operator|=
name|sh
operator|.
name|size
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|shnam
index|[
literal|1
index|]
operator|==
literal|'q'
condition|)
return|return
name|Ok
return|;
block|}
name|s
operator|+=
name|e_shentsize
expr_stmt|;
block|}
return|return
name|NoQtSection
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// defined(Q_OF_ELF)&& defined(Q_CC_GNU)
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_LIBRARY
end_comment
end_unit
