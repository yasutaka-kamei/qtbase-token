begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qsize.h"
end_include
begin_include
include|#
directive|include
file|"qdatastream.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QSize     \inmodule QtCore     \ingroup painting      \brief The QSize class defines the size of a two-dimensional     object using integer point precision.      A size is specified by a width() and a height().  It can be set in     the constructor and changed using the setWidth(), setHeight(), or     scale() functions, or using arithmetic operators. A size can also     be manipulated directly by retrieving references to the width and     height using the rwidth() and rheight() functions. Finally, the     width and height can be swapped using the transpose() function.      The isValid() function determines if a size is valid (a valid size     has both width and height greater than or equal to zero). The isEmpty()     function returns \c true if either of the width and height is less     than, or equal to, zero, while the isNull() function returns \c true     only if both the width and the height is zero.      Use the expandedTo() function to retrieve a size which holds the     maximum height and width of \e this size and a given     size. Similarly, the boundedTo() function returns a size which     holds the minimum height and width of \e this size and a given     size.      QSize objects can be streamed as well as compared.      \sa QSizeF, QPoint, QRect */
comment|/*****************************************************************************   QSize member functions  *****************************************************************************/
comment|/*!     \fn QSize::QSize()      Constructs a size with an invalid width and height (i.e., isValid()     returns \c false).      \sa isValid() */
comment|/*!     \fn QSize::QSize(int width, int height)      Constructs a size with the given \a width and \a height.      \sa setWidth(), setHeight() */
comment|/*!     \fn bool QSize::isNull() const      Returns \c true if both the width and height is 0; otherwise returns     false.      \sa isValid(), isEmpty() */
comment|/*!     \fn bool QSize::isEmpty() const      Returns \c true if either of the width and height is less than or     equal to 0; otherwise returns \c false.      \sa isNull(), isValid() */
comment|/*!     \fn bool QSize::isValid() const      Returns \c true if both the width and height is equal to or greater     than 0; otherwise returns \c false.      \sa isNull(), isEmpty() */
comment|/*!     \fn int QSize::width() const      Returns the width.      \sa height(), setWidth() */
comment|/*!     \fn int QSize::height() const      Returns the height.      \sa width(), setHeight() */
comment|/*!     \fn void QSize::setWidth(int width)      Sets the width to the given \a width.      \sa rwidth(), width(), setHeight() */
comment|/*!     \fn void QSize::setHeight(int height)      Sets the height to the given \a height.      \sa rheight(), height(), setWidth() */
comment|/*!     Swaps the width and height values.      \sa setWidth(), setHeight(), transposed() */
DECL|function|transpose
name|void
name|QSize
operator|::
name|transpose
parameter_list|()
block|{
name|int
name|tmp
init|=
name|wd
decl_stmt|;
name|wd
operator|=
name|ht
expr_stmt|;
name|ht
operator|=
name|tmp
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \fn QSize QSize::transposed() const   \since 5.0    Returns a QSize with width and height swapped.    \sa transpose() */
end_comment
begin_comment
comment|/*!   \fn void QSize::scale(int width, int height, Qt::AspectRatioMode mode)      Scales the size to a rectangle with the given \a width and \a     height, according to the specified \a mode:      \list     \li If \a mode is Qt::IgnoreAspectRatio, the size is set to (\a width, \a height).     \li If \a mode is Qt::KeepAspectRatio, the current size is scaled to a rectangle        as large as possible inside (\a width, \a height), preserving the aspect ratio.     \li If \a mode is Qt::KeepAspectRatioByExpanding, the current size is scaled to a rectangle        as small as possible outside (\a width, \a height), preserving the aspect ratio.     \endlist      Example:     \snippet code/src_corelib_tools_qsize.cpp 0      \sa setWidth(), setHeight(), scaled() */
end_comment
begin_comment
comment|/*!     \fn void QSize::scale(const QSize&size, Qt::AspectRatioMode mode)     \overload      Scales the size to a rectangle with the given \a size, according to     the specified \a mode. */
end_comment
begin_comment
comment|/*!     \fn QSize QSize::scaled(int width, int height, Qt::AspectRatioMode mode) const     \since 5.0      Return a size scaled to a rectangle with the given \a width and \a     height, according to the specified \a mode.      \sa scale() */
end_comment
begin_comment
comment|/*!     \overload     \since 5.0      Return a size scaled to a rectangle with the given size \a s,     according to the specified \a mode. */
end_comment
begin_function
DECL|function|scaled
name|QSize
name|QSize
operator|::
name|scaled
parameter_list|(
specifier|const
name|QSize
modifier|&
name|s
parameter_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|mode
operator|==
name|Qt
operator|::
name|IgnoreAspectRatio
operator|||
name|wd
operator|==
literal|0
operator|||
name|ht
operator|==
literal|0
condition|)
block|{
return|return
name|s
return|;
block|}
else|else
block|{
name|bool
name|useHeight
decl_stmt|;
name|qint64
name|rw
init|=
name|qint64
argument_list|(
name|s
operator|.
name|ht
argument_list|)
operator|*
name|qint64
argument_list|(
name|wd
argument_list|)
operator|/
name|qint64
argument_list|(
name|ht
argument_list|)
decl_stmt|;
if|if
condition|(
name|mode
operator|==
name|Qt
operator|::
name|KeepAspectRatio
condition|)
block|{
name|useHeight
operator|=
operator|(
name|rw
operator|<=
name|s
operator|.
name|wd
operator|)
expr_stmt|;
block|}
else|else
block|{
comment|// mode == Qt::KeepAspectRatioByExpanding
name|useHeight
operator|=
operator|(
name|rw
operator|>=
name|s
operator|.
name|wd
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|useHeight
condition|)
block|{
return|return
name|QSize
argument_list|(
name|rw
argument_list|,
name|s
operator|.
name|ht
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|QSize
argument_list|(
name|s
operator|.
name|wd
argument_list|,
name|qint32
argument_list|(
name|qint64
argument_list|(
name|s
operator|.
name|wd
argument_list|)
operator|*
name|qint64
argument_list|(
name|ht
argument_list|)
operator|/
name|qint64
argument_list|(
name|wd
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     \fn int&QSize::rwidth()      Returns a reference to the width.      Using a reference makes it possible to manipulate the width     directly. For example:      \snippet code/src_corelib_tools_qsize.cpp 1      \sa rheight(), setWidth() */
end_comment
begin_comment
comment|/*!     \fn int&QSize::rheight()      Returns a reference to the height.      Using a reference makes it possible to manipulate the height     directly. For example:      \snippet code/src_corelib_tools_qsize.cpp 2      \sa rwidth(), setHeight() */
end_comment
begin_comment
comment|/*!     \fn QSize&QSize::operator+=(const QSize&size)      Adds the given \a size to \e this size, and returns a reference to     this size. For example:      \snippet code/src_corelib_tools_qsize.cpp 3 */
end_comment
begin_comment
comment|/*!     \fn QSize&QSize::operator-=(const QSize&size)      Subtracts the given \a size from \e this size, and returns a     reference to this size. For example:      \snippet code/src_corelib_tools_qsize.cpp 4 */
end_comment
begin_comment
comment|/*!     \fn QSize&QSize::operator*=(qreal factor)     \overload      Multiplies both the width and height by the given \a factor, and     returns a reference to the size.      Note that the result is rounded to the nearest integer.      \sa scale() */
end_comment
begin_comment
comment|/*!     \fn bool operator==(const QSize&s1, const QSize&s2)     \relates QSize      Returns \c true if \a s1 and \a s2 are equal; otherwise returns \c false. */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(const QSize&s1, const QSize&s2)     \relates QSize      Returns \c true if \a s1 and \a s2 are different; otherwise returns \c false. */
end_comment
begin_comment
comment|/*!     \fn const QSize operator+(const QSize&s1, const QSize&s2)     \relates QSize      Returns the sum of \a s1 and \a s2; each component is added separately. */
end_comment
begin_comment
comment|/*!     \fn const QSize operator-(const QSize&s1, const QSize&s2)     \relates QSize      Returns \a s2 subtracted from \a s1; each component is subtracted     separately. */
end_comment
begin_comment
comment|/*!     \fn const QSize operator*(const QSize&size, qreal factor)     \relates QSize      Multiplies the given \a size by the given \a factor, and returns     the result rounded to the nearest integer.      \sa QSize::scale() */
end_comment
begin_comment
comment|/*!     \fn const QSize operator*(qreal factor, const QSize&size)     \overload     \relates QSize      Multiplies the given \a size by the given \a factor, and returns     the result rounded to the nearest integer. */
end_comment
begin_comment
comment|/*!     \fn QSize&QSize::operator/=(qreal divisor)     \overload      Divides both the width and height by the given \a divisor, and     returns a reference to the size.      Note that the result is rounded to the nearest integer.      \sa QSize::scale() */
end_comment
begin_comment
comment|/*!     \fn const QSize operator/(const QSize&size, qreal divisor)     \relates QSize     \overload      Divides the given \a size by the given \a divisor, and returns the     result rounded to the nearest integer.      \sa QSize::scale() */
end_comment
begin_comment
comment|/*!     \fn QSize QSize::expandedTo(const QSize& otherSize) const      Returns a size holding the maximum width and height of this size     and the given \a otherSize.      \sa boundedTo(), scale() */
end_comment
begin_comment
comment|/*!     \fn QSize QSize::boundedTo(const QSize& otherSize) const      Returns a size holding the minimum width and height of this size     and the given \a otherSize.      \sa expandedTo(), scale() */
end_comment
begin_comment
comment|/*****************************************************************************   QSize stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|/*!     \fn QDataStream&operator<<(QDataStream&stream, const QSize&size)     \relates QSize      Writes the given \a size to the given \a stream, and returns a     reference to the stream.      \sa {Serializing Qt Data Types} */
end_comment
begin_function
DECL|function|operator <<
name|QDataStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QDataStream
modifier|&
name|s
parameter_list|,
specifier|const
name|QSize
modifier|&
name|sz
parameter_list|)
block|{
if|if
condition|(
name|s
operator|.
name|version
argument_list|()
operator|==
literal|1
condition|)
name|s
operator|<<
operator|(
name|qint16
operator|)
name|sz
operator|.
name|width
argument_list|()
operator|<<
operator|(
name|qint16
operator|)
name|sz
operator|.
name|height
argument_list|()
expr_stmt|;
else|else
name|s
operator|<<
operator|(
name|qint32
operator|)
name|sz
operator|.
name|width
argument_list|()
operator|<<
operator|(
name|qint32
operator|)
name|sz
operator|.
name|height
argument_list|()
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QDataStream&operator>>(QDataStream&stream, QSize&size)     \relates QSize      Reads a size from the given \a stream into the given \a size, and     returns a reference to the stream.      \sa {Serializing Qt Data Types} */
end_comment
begin_function
DECL|function|operator >>
name|QDataStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QDataStream
modifier|&
name|s
parameter_list|,
name|QSize
modifier|&
name|sz
parameter_list|)
block|{
if|if
condition|(
name|s
operator|.
name|version
argument_list|()
operator|==
literal|1
condition|)
block|{
name|qint16
name|w
decl_stmt|,
name|h
decl_stmt|;
name|s
operator|>>
name|w
expr_stmt|;
name|sz
operator|.
name|rwidth
argument_list|()
operator|=
name|w
expr_stmt|;
name|s
operator|>>
name|h
expr_stmt|;
name|sz
operator|.
name|rheight
argument_list|()
operator|=
name|h
expr_stmt|;
block|}
else|else
block|{
name|qint32
name|w
decl_stmt|,
name|h
decl_stmt|;
name|s
operator|>>
name|w
expr_stmt|;
name|sz
operator|.
name|rwidth
argument_list|()
operator|=
name|w
expr_stmt|;
name|s
operator|>>
name|h
expr_stmt|;
name|sz
operator|.
name|rheight
argument_list|()
operator|=
name|h
expr_stmt|;
block|}
return|return
name|s
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QSize
modifier|&
name|s
parameter_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QSize("
operator|<<
name|s
operator|.
name|width
argument_list|()
operator|<<
literal|", "
operator|<<
name|s
operator|.
name|height
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
operator|.
name|space
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \class QSizeF     \inmodule QtCore     \brief The QSizeF class defines the size of a two-dimensional object     using floating point precision.      \ingroup painting      A size is specified by a width() and a height().  It can be set in     the constructor and changed using the setWidth(), setHeight(), or     scale() functions, or using arithmetic operators. A size can also     be manipulated directly by retrieving references to the width and     height using the rwidth() and rheight() functions. Finally, the     width and height can be swapped using the transpose() function.      The isValid() function determines if a size is valid. A valid size     has both width and height greater than or equal to zero. The     isEmpty() function returns \c true if either of the width and height     is \e less than (or equal to) zero, while the isNull() function     returns \c true only if both the width and the height is zero.      Use the expandedTo() function to retrieve a size which holds the     maximum height and width of this size and a given     size. Similarly, the boundedTo() function returns a size which     holds the minimum height and width of this size and a given size.      The QSizeF class also provides the toSize() function returning a     QSize copy of this size, constructed by rounding the width and     height to the nearest integers.      QSizeF objects can be streamed as well as compared.      \sa QSize, QPointF, QRectF */
end_comment
begin_comment
comment|/*****************************************************************************   QSizeF member functions  *****************************************************************************/
end_comment
begin_comment
comment|/*!     \fn QSizeF::QSizeF()      Constructs an invalid size.      \sa isValid() */
end_comment
begin_comment
comment|/*!     \fn QSizeF::QSizeF(const QSize&size)      Constructs a size with floating point accuracy from the given \a     size.      \sa toSize() */
end_comment
begin_comment
comment|/*!     \fn QSizeF::QSizeF(qreal width, qreal height)      Constructs a size with the given \a width and \a height. */
end_comment
begin_comment
comment|/*!     \fn bool QSizeF::isNull() const      Returns \c true if both the width and height are +0.0; otherwise returns     false.      \note Since this function treats +0.0 and -0.0 differently, sizes with     zero width and height where either or both values have a negative     sign are not defined to be null sizes.      \sa isValid(), isEmpty() */
end_comment
begin_comment
comment|/*!     \fn bool QSizeF::isEmpty() const      Returns \c true if either of the width and height is less than or     equal to 0; otherwise returns \c false.      \sa isNull(), isValid() */
end_comment
begin_comment
comment|/*!     \fn bool QSizeF::isValid() const      Returns \c true if both the width and height is equal to or greater     than 0; otherwise returns \c false.      \sa isNull(), isEmpty() */
end_comment
begin_comment
comment|/*!     \fn int QSizeF::width() const      Returns the width.      \sa height(), setWidth() */
end_comment
begin_comment
comment|/*!     \fn int QSizeF::height() const      Returns the height.      \sa width(), setHeight() */
end_comment
begin_comment
comment|/*!     \fn void QSizeF::setWidth(qreal width)      Sets the width to the given \a width.      \sa width(), rwidth(), setHeight() */
end_comment
begin_comment
comment|/*!     \fn void QSizeF::setHeight(qreal height)      Sets the height to the given \a height.      \sa height(), rheight(), setWidth() */
end_comment
begin_comment
comment|/*!     \fn QSize QSizeF::toSize() const      Returns an integer based copy of this size.      Note that the coordinates in the returned size will be rounded to     the nearest integer.      \sa QSizeF() */
end_comment
begin_comment
comment|/*!     Swaps the width and height values.      \sa setWidth(), setHeight(), transposed() */
end_comment
begin_function
DECL|function|transpose
name|void
name|QSizeF
operator|::
name|transpose
parameter_list|()
block|{
name|qreal
name|tmp
init|=
name|wd
decl_stmt|;
name|wd
operator|=
name|ht
expr_stmt|;
name|ht
operator|=
name|tmp
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn QSizeF QSizeF::transposed() const     \since 5.0      Returns the size with width and height values swapped.      \sa transpose() */
end_comment
begin_comment
comment|/*!   \fn void QSizeF::scale(qreal width, qreal height, Qt::AspectRatioMode mode)      Scales the size to a rectangle with the given \a width and \a     height, according to the specified \a mode.      \list     \li If \a mode is Qt::IgnoreAspectRatio, the size is set to (\a width, \a height).     \li If \a mode is Qt::KeepAspectRatio, the current size is scaled to a rectangle        as large as possible inside (\a width, \a height), preserving the aspect ratio.     \li If \a mode is Qt::KeepAspectRatioByExpanding, the current size is scaled to a rectangle        as small as possible outside (\a width, \a height), preserving the aspect ratio.     \endlist      Example:     \snippet code/src_corelib_tools_qsize.cpp 5      \sa setWidth(), setHeight(), scaled() */
end_comment
begin_comment
comment|/*!     \fn void QSizeF::scale(const QSizeF&size, Qt::AspectRatioMode mode)     \overload      Scales the size to a rectangle with the given \a size, according to     the specified \a mode. */
end_comment
begin_comment
comment|/*!     \fn QSizeF QSizeF::scaled(qreal width, qreal height, Qt::AspectRatioMode mode) const     \since 5.0      Returns a size scaled to a rectangle with the given \a width and     \a height, according to the specified \a mode.      \sa scale() */
end_comment
begin_comment
comment|/*!     \overload     \since 5.0      Returns a size scaled to a rectangle with the given size \a s,     according to the specified \a mode. */
end_comment
begin_function
DECL|function|scaled
name|QSizeF
name|QSizeF
operator|::
name|scaled
parameter_list|(
specifier|const
name|QSizeF
modifier|&
name|s
parameter_list|,
name|Qt
operator|::
name|AspectRatioMode
name|mode
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|mode
operator|==
name|Qt
operator|::
name|IgnoreAspectRatio
operator|||
name|qIsNull
argument_list|(
name|wd
argument_list|)
operator|||
name|qIsNull
argument_list|(
name|ht
argument_list|)
condition|)
block|{
return|return
name|s
return|;
block|}
else|else
block|{
name|bool
name|useHeight
decl_stmt|;
name|qreal
name|rw
init|=
name|s
operator|.
name|ht
operator|*
name|wd
operator|/
name|ht
decl_stmt|;
if|if
condition|(
name|mode
operator|==
name|Qt
operator|::
name|KeepAspectRatio
condition|)
block|{
name|useHeight
operator|=
operator|(
name|rw
operator|<=
name|s
operator|.
name|wd
operator|)
expr_stmt|;
block|}
else|else
block|{
comment|// mode == Qt::KeepAspectRatioByExpanding
name|useHeight
operator|=
operator|(
name|rw
operator|>=
name|s
operator|.
name|wd
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|useHeight
condition|)
block|{
return|return
name|QSizeF
argument_list|(
name|rw
argument_list|,
name|s
operator|.
name|ht
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|QSizeF
argument_list|(
name|s
operator|.
name|wd
argument_list|,
name|s
operator|.
name|wd
operator|*
name|ht
operator|/
name|wd
argument_list|)
return|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     \fn int&QSizeF::rwidth()      Returns a reference to the width.      Using a reference makes it possible to manipulate the width     directly. For example:      \snippet code/src_corelib_tools_qsize.cpp 6      \sa rheight(), setWidth() */
end_comment
begin_comment
comment|/*!     \fn int&QSizeF::rheight()      Returns a reference to the height.      Using a reference makes it possible to manipulate the height     directly. For example:      \snippet code/src_corelib_tools_qsize.cpp 7      \sa rwidth(), setHeight() */
end_comment
begin_comment
comment|/*!     \fn QSizeF&QSizeF::operator+=(const QSizeF&size)      Adds the given \a size to this size and returns a reference to     this size. For example:      \snippet code/src_corelib_tools_qsize.cpp 8 */
end_comment
begin_comment
comment|/*!     \fn QSizeF&QSizeF::operator-=(const QSizeF&size)      Subtracts the given \a size from this size and returns a reference     to this size. For example:      \snippet code/src_corelib_tools_qsize.cpp 9 */
end_comment
begin_comment
comment|/*!     \fn QSizeF&QSizeF::operator*=(qreal factor)     \overload      Multiplies both the width and height by the given \a factor and     returns a reference to the size.      \sa scale() */
end_comment
begin_comment
comment|/*!     \fn bool operator==(const QSizeF&s1, const QSizeF&s2)     \relates QSizeF      Returns \c true if \a s1 and \a s2 are equal; otherwise returns     false. */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(const QSizeF&s1, const QSizeF&s2)     \relates QSizeF      Returns \c true if \a s1 and \a s2 are different; otherwise returns \c false. */
end_comment
begin_comment
comment|/*!     \fn const QSizeF operator+(const QSizeF&s1, const QSizeF&s2)     \relates QSizeF      Returns the sum of \a s1 and \a s2; each component is added separately. */
end_comment
begin_comment
comment|/*!     \fn const QSizeF operator-(const QSizeF&s1, const QSizeF&s2)     \relates QSizeF      Returns \a s2 subtracted from \a s1; each component is subtracted     separately. */
end_comment
begin_comment
comment|/*!     \fn const QSizeF operator*(const QSizeF&size, qreal factor)      \overload     \relates QSizeF      Multiplies the given \a size by the given \a factor and returns     the result.      \sa QSizeF::scale() */
end_comment
begin_comment
comment|/*!     \fn const QSizeF operator*(qreal factor, const QSizeF&size)      \overload     \relates QSizeF      Multiplies the given \a size by the given \a factor and returns     the result. */
end_comment
begin_comment
comment|/*!     \fn QSizeF&QSizeF::operator/=(qreal divisor)      \overload      Divides both the width and height by the given \a divisor and     returns a reference to the size.      \sa scale() */
end_comment
begin_comment
comment|/*!     \fn const QSizeF operator/(const QSizeF&size, qreal divisor)      \relates QSizeF     \overload      Divides the given \a size by the given \a divisor and returns the     result.      \sa QSizeF::scale() */
end_comment
begin_comment
comment|/*!     \fn QSizeF QSizeF::expandedTo(const QSizeF& otherSize) const      Returns a size holding the maximum width and height of this size     and the given \a otherSize.      \sa boundedTo(), scale() */
end_comment
begin_comment
comment|/*!     \fn QSizeF QSizeF::boundedTo(const QSizeF& otherSize) const      Returns a size holding the minimum width and height of this size     and the given \a otherSize.      \sa expandedTo(), scale() */
end_comment
begin_comment
comment|/*****************************************************************************   QSizeF stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|/*!     \fn QDataStream&operator<<(QDataStream&stream, const QSizeF&size)     \relates QSizeF      Writes the given \a size to the given \a stream and returns a     reference to the stream.      \sa {Serializing Qt Data Types} */
end_comment
begin_function
DECL|function|operator <<
name|QDataStream
modifier|&
name|operator
name|<<
parameter_list|(
name|QDataStream
modifier|&
name|s
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|sz
parameter_list|)
block|{
name|s
operator|<<
name|double
argument_list|(
name|sz
operator|.
name|width
argument_list|()
argument_list|)
operator|<<
name|double
argument_list|(
name|sz
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QDataStream&operator>>(QDataStream&stream, QSizeF&size)     \relates QSizeF      Reads a size from the given \a stream into the given \a size and     returns a reference to the stream.      \sa {Serializing Qt Data Types} */
end_comment
begin_function
DECL|function|operator >>
name|QDataStream
modifier|&
name|operator
name|>>
parameter_list|(
name|QDataStream
modifier|&
name|s
parameter_list|,
name|QSizeF
modifier|&
name|sz
parameter_list|)
block|{
name|double
name|w
decl_stmt|,
name|h
decl_stmt|;
name|s
operator|>>
name|w
expr_stmt|;
name|s
operator|>>
name|h
expr_stmt|;
name|sz
operator|.
name|setWidth
argument_list|(
name|qreal
argument_list|(
name|w
argument_list|)
argument_list|)
expr_stmt|;
name|sz
operator|.
name|setHeight
argument_list|(
name|qreal
argument_list|(
name|h
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATASTREAM
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|s
parameter_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QSizeF("
operator|<<
name|s
operator|.
name|width
argument_list|()
operator|<<
literal|", "
operator|<<
name|s
operator|.
name|height
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
operator|.
name|space
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
