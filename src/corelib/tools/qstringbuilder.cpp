begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstringbuilder.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextcodec.h>
end_include
begin_include
include|#
directive|include
file|<private/qutfcodec_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QStringBuilder     \inmodule QtCore     \internal     \reentrant     \since 4.6      \brief The QStringBuilder class is a template class that provides a facility to build up QStrings from smaller chunks.      \ingroup tools     \ingroup shared     \ingroup string-processing       To build a QString by multiple concatenations, QString::operator+()     is typically used. This causes \e{n - 1} reallocations when building     a string from \e{n} chunks.      QStringBuilder uses expression templates to collect the individual     chunks, compute the total size, allocate the required amount of     memory for the final QString object, and copy the chunks into the     allocated memory.      The QStringBuilder class is not to be used explicitly in user     code.  Instances of the class are created as return values of the     operator%() function, acting on objects of type QString,     QLatin1String, QStringRef, QChar, QCharRef,     QLatin1Char, and \c char.      Concatenating strings with operator%() generally yields better     performance then using \c QString::operator+() on the same chunks     if there are three or more of them, and performs equally well in other     cases.      \sa QLatin1String, QString */
comment|/*! \fn QStringBuilder::QStringBuilder(const A&a, const B&b)   Constructs a QStringBuilder from \a a and \a b.  */
comment|/* \fn QStringBuilder::operator%(const A&a, const B&b)      Returns a \c QStringBuilder object that is converted to a QString object     when assigned to a variable of QString type or passed to a function that     takes a QString parameter.      This function is usable with arguments of type \c QString,     \c QLatin1String, \c QStringRef,     \c QChar, \c QCharRef, \c QLatin1Char, and \c char. */
comment|/* \fn QByteArray QStringBuilder::toLatin1() const   Returns a Latin-1 representation of the string as a QByteArray.  The   returned byte array is undefined if the string contains non-Latin1   characters.  */
comment|/* \fn QByteArray QStringBuilder::toUtf8() const   Returns a UTF-8 representation of the string as a QByteArray.  */
comment|/*!     \internal  */
name|void
name|QAbstractConcatenable
operator|::
name|convertFromAscii
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
name|int
name|len
parameter_list|,
name|QChar
modifier|*
modifier|&
name|out
parameter_list|)
name|Q_DECL_NOTHROW
block|{
if|if
condition|(
name|len
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
operator|!
name|a
condition|)
return|return;
while|while
condition|(
operator|*
name|a
operator|&&
name|uchar
argument_list|(
operator|*
name|a
argument_list|)
operator|<
literal|0x80U
condition|)
operator|*
name|out
operator|++
operator|=
name|QLatin1Char
argument_list|(
operator|*
name|a
operator|++
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|a
condition|)
return|return;
name|len
operator|=
name|int
argument_list|(
name|strlen
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
operator|&&
name|uchar
argument_list|(
name|a
index|[
name|i
index|]
argument_list|)
operator|<
literal|0x80U
condition|;
operator|++
name|i
control|)
operator|*
name|out
operator|++
operator|=
name|QLatin1Char
argument_list|(
name|a
index|[
name|i
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
name|len
condition|)
return|return;
name|a
operator|+=
name|i
expr_stmt|;
name|len
operator|-=
name|i
expr_stmt|;
block|}
comment|// we need to complement with UTF-8 appending
name|out
operator|=
name|QUtf8
operator|::
name|convertToUnicode
argument_list|(
name|out
argument_list|,
name|a
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
