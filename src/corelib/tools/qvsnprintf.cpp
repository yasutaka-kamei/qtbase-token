begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qbytearray.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|"string.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_VSNPRINTF
comment|/*!     \relates QByteArray      A portable \c vsnprintf() function. Will call \c ::vsnprintf(), \c     ::_vsnprintf(), or \c ::vsnprintf_s depending on the system, or     fall back to an internal version.      \a fmt is the \c printf() format string. The result is put into     \a str, which is a buffer of at least \a n bytes.      The caller is responsible to call \c va_end() on \a ap.      \warning Since vsnprintf() shows different behavior on certain     platforms, you should not rely on the return value or on the fact     that you will always get a 0 terminated string back.      Ideally, you should never call this function but use QString::sprintf()     instead.      \sa qsnprintf(), QString::sprintf() */
DECL|function|qvsnprintf
name|int
name|qvsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
block|{
if|if
condition|(
operator|!
name|str
operator|||
operator|!
name|fmt
condition|)
return|return
operator|-
literal|1
return|;
name|QString
name|buf
decl_stmt|;
name|buf
operator|.
name|vsprintf
argument_list|(
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|QByteArray
name|ba
init|=
name|buf
operator|.
name|toLocal8Bit
argument_list|()
decl_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
block|{
name|size_t
name|blen
init|=
name|qMin
argument_list|(
name|size_t
argument_list|(
name|ba
operator|.
name|length
argument_list|()
argument_list|)
argument_list|,
name|size_t
argument_list|(
name|n
operator|-
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|str
argument_list|,
name|ba
operator|.
name|constData
argument_list|()
argument_list|,
name|blen
argument_list|)
expr_stmt|;
name|str
index|[
name|blen
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|// make sure str is always 0 terminated
block|}
return|return
name|ba
operator|.
name|length
argument_list|()
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|<stdio.h>
name|QT_END_INCLUDE_NAMESPACE
name|int
name|qvsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
block|{
return|return
name|QT_VSNPRINTF
argument_list|(
name|str
argument_list|,
name|n
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \relates QByteArray      A portable snprintf() function, calls qvsnprintf.      \a fmt is the \c printf() format string. The result is put into     \a str, which is a buffer of at least \a n bytes.      \warning Call this function only when you know what you are doing     since it shows different behavior on certain platforms.     Use QString::sprintf() to format a string instead.      \sa qvsnprintf(), QString::sprintf() */
end_comment
begin_function
DECL|function|qsnprintf
name|int
name|qsnprintf
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|int
name|ret
init|=
name|qvsnprintf
argument_list|(
name|str
argument_list|,
name|n
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
decl_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
