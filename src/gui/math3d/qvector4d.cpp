begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qvector4d.h"
end_include
begin_include
include|#
directive|include
file|"qvector3d.h"
end_include
begin_include
include|#
directive|include
file|"qvector2d.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_VECTOR4D
comment|/*!     \class QVector4D     \brief The QVector4D class represents a vector or vertex in 4D space.     \since 4.6     \ingroup painting-3D     \inmodule QtGui      The QVector4D class can also be used to represent vertices in 4D space.     We therefore do not need to provide a separate vertex class.      \sa QQuaternion, QVector2D, QVector3D */
comment|/*!     \fn QVector4D::QVector4D()      Constructs a null vector, i.e. with coordinates (0, 0, 0, 0). */
comment|/*!     \fn QVector4D::QVector4D(float xpos, float ypos, float zpos, float wpos)      Constructs a vector with coordinates (\a xpos, \a ypos, \a zpos, \a wpos). */
comment|/*!     \fn QVector4D::QVector4D(const QPoint& point)      Constructs a vector with x and y coordinates from a 2D \a point, and     z and w coordinates of 0. */
comment|/*!     \fn QVector4D::QVector4D(const QPointF& point)      Constructs a vector with x and y coordinates from a 2D \a point, and     z and w coordinates of 0. */
ifndef|#
directive|ifndef
name|QT_NO_VECTOR2D
comment|/*!     Constructs a 4D vector from the specified 2D \a vector.  The z     and w coordinates are set to zero.      \sa toVector2D() */
DECL|function|QVector4D
name|QVector4D
operator|::
name|QVector4D
parameter_list|(
specifier|const
name|QVector2D
modifier|&
name|vector
parameter_list|)
block|{
name|xp
operator|=
name|vector
operator|.
name|xp
expr_stmt|;
name|yp
operator|=
name|vector
operator|.
name|yp
expr_stmt|;
name|zp
operator|=
literal|0.0f
expr_stmt|;
name|wp
operator|=
literal|0.0f
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Constructs a 4D vector from the specified 2D \a vector.  The z     and w coordinates are set to \a zpos and \a wpos respectively.      \sa toVector2D() */
end_comment
begin_constructor
DECL|function|QVector4D
name|QVector4D
operator|::
name|QVector4D
parameter_list|(
specifier|const
name|QVector2D
modifier|&
name|vector
parameter_list|,
name|float
name|zpos
parameter_list|,
name|float
name|wpos
parameter_list|)
block|{
name|xp
operator|=
name|vector
operator|.
name|xp
expr_stmt|;
name|yp
operator|=
name|vector
operator|.
name|yp
expr_stmt|;
name|zp
operator|=
name|zpos
expr_stmt|;
name|wp
operator|=
name|wpos
expr_stmt|;
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
end_ifndef
begin_comment
comment|/*!     Constructs a 4D vector from the specified 3D \a vector.  The w     coordinate is set to zero.      \sa toVector3D() */
end_comment
begin_constructor
DECL|function|QVector4D
name|QVector4D
operator|::
name|QVector4D
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|vector
parameter_list|)
block|{
name|xp
operator|=
name|vector
operator|.
name|xp
expr_stmt|;
name|yp
operator|=
name|vector
operator|.
name|yp
expr_stmt|;
name|zp
operator|=
name|vector
operator|.
name|zp
expr_stmt|;
name|wp
operator|=
literal|0.0f
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a 4D vector from the specified 3D \a vector.  The w     coordinate is set to \a wpos.      \sa toVector3D() */
end_comment
begin_constructor
DECL|function|QVector4D
name|QVector4D
operator|::
name|QVector4D
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|vector
parameter_list|,
name|float
name|wpos
parameter_list|)
block|{
name|xp
operator|=
name|vector
operator|.
name|xp
expr_stmt|;
name|yp
operator|=
name|vector
operator|.
name|yp
expr_stmt|;
name|zp
operator|=
name|vector
operator|.
name|zp
expr_stmt|;
name|wp
operator|=
name|wpos
expr_stmt|;
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \fn bool QVector4D::isNull() const      Returns true if the x, y, z, and w coordinates are set to 0.0,     otherwise returns false. */
end_comment
begin_comment
comment|/*!     \fn float QVector4D::x() const      Returns the x coordinate of this point.      \sa setX(), y(), z(), w() */
end_comment
begin_comment
comment|/*!     \fn float QVector4D::y() const      Returns the y coordinate of this point.      \sa setY(), x(), z(), w() */
end_comment
begin_comment
comment|/*!     \fn float QVector4D::z() const      Returns the z coordinate of this point.      \sa setZ(), x(), y(), w() */
end_comment
begin_comment
comment|/*!     \fn float QVector4D::w() const      Returns the w coordinate of this point.      \sa setW(), x(), y(), z() */
end_comment
begin_comment
comment|/*!     \fn void QVector4D::setX(float x)      Sets the x coordinate of this point to the given \a x coordinate.      \sa x(), setY(), setZ(), setW() */
end_comment
begin_comment
comment|/*!     \fn void QVector4D::setY(float y)      Sets the y coordinate of this point to the given \a y coordinate.      \sa y(), setX(), setZ(), setW() */
end_comment
begin_comment
comment|/*!     \fn void QVector4D::setZ(float z)      Sets the z coordinate of this point to the given \a z coordinate.      \sa z(), setX(), setY(), setW() */
end_comment
begin_comment
comment|/*!     \fn void QVector4D::setW(float w)      Sets the w coordinate of this point to the given \a w coordinate.      \sa w(), setX(), setY(), setZ() */
end_comment
begin_comment
comment|/*!     Returns the length of the vector from the origin.      \sa lengthSquared(), normalized() */
end_comment
begin_function
DECL|function|length
name|float
name|QVector4D
operator|::
name|length
parameter_list|()
specifier|const
block|{
comment|// Need some extra precision if the length is very small.
name|double
name|len
init|=
name|double
argument_list|(
name|xp
argument_list|)
operator|*
name|double
argument_list|(
name|xp
argument_list|)
operator|+
name|double
argument_list|(
name|yp
argument_list|)
operator|*
name|double
argument_list|(
name|yp
argument_list|)
operator|+
name|double
argument_list|(
name|zp
argument_list|)
operator|*
name|double
argument_list|(
name|zp
argument_list|)
operator|+
name|double
argument_list|(
name|wp
argument_list|)
operator|*
name|double
argument_list|(
name|wp
argument_list|)
decl_stmt|;
return|return
name|float
argument_list|(
name|sqrt
argument_list|(
name|len
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the squared length of the vector from the origin.     This is equivalent to the dot product of the vector with itself.      \sa length(), dotProduct() */
end_comment
begin_function
DECL|function|lengthSquared
name|float
name|QVector4D
operator|::
name|lengthSquared
parameter_list|()
specifier|const
block|{
return|return
name|xp
operator|*
name|xp
operator|+
name|yp
operator|*
name|yp
operator|+
name|zp
operator|*
name|zp
operator|+
name|wp
operator|*
name|wp
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the normalized unit vector form of this vector.      If this vector is null, then a null vector is returned.  If the length     of the vector is very close to 1, then the vector will be returned as-is.     Otherwise the normalized form of the vector of length 1 will be returned.      \sa length(), normalize() */
end_comment
begin_function
DECL|function|normalized
name|QVector4D
name|QVector4D
operator|::
name|normalized
parameter_list|()
specifier|const
block|{
comment|// Need some extra precision if the length is very small.
name|double
name|len
init|=
name|double
argument_list|(
name|xp
argument_list|)
operator|*
name|double
argument_list|(
name|xp
argument_list|)
operator|+
name|double
argument_list|(
name|yp
argument_list|)
operator|*
name|double
argument_list|(
name|yp
argument_list|)
operator|+
name|double
argument_list|(
name|zp
argument_list|)
operator|*
name|double
argument_list|(
name|zp
argument_list|)
operator|+
name|double
argument_list|(
name|wp
argument_list|)
operator|*
name|double
argument_list|(
name|wp
argument_list|)
decl_stmt|;
if|if
condition|(
name|qFuzzyIsNull
argument_list|(
name|len
operator|-
literal|1.0f
argument_list|)
condition|)
block|{
return|return
operator|*
name|this
return|;
block|}
elseif|else
if|if
condition|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|len
argument_list|)
condition|)
block|{
name|double
name|sqrtLen
init|=
name|sqrt
argument_list|(
name|len
argument_list|)
decl_stmt|;
return|return
name|QVector4D
argument_list|(
name|float
argument_list|(
name|double
argument_list|(
name|xp
argument_list|)
operator|/
name|sqrtLen
argument_list|)
argument_list|,
name|float
argument_list|(
name|double
argument_list|(
name|yp
argument_list|)
operator|/
name|sqrtLen
argument_list|)
argument_list|,
name|float
argument_list|(
name|double
argument_list|(
name|zp
argument_list|)
operator|/
name|sqrtLen
argument_list|)
argument_list|,
name|float
argument_list|(
name|double
argument_list|(
name|wp
argument_list|)
operator|/
name|sqrtLen
argument_list|)
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|QVector4D
argument_list|()
return|;
block|}
block|}
end_function
begin_comment
comment|/*!     Normalizes the currect vector in place.  Nothing happens if this     vector is a null vector or the length of the vector is very close to 1.      \sa length(), normalized() */
end_comment
begin_function
DECL|function|normalize
name|void
name|QVector4D
operator|::
name|normalize
parameter_list|()
block|{
comment|// Need some extra precision if the length is very small.
name|double
name|len
init|=
name|double
argument_list|(
name|xp
argument_list|)
operator|*
name|double
argument_list|(
name|xp
argument_list|)
operator|+
name|double
argument_list|(
name|yp
argument_list|)
operator|*
name|double
argument_list|(
name|yp
argument_list|)
operator|+
name|double
argument_list|(
name|zp
argument_list|)
operator|*
name|double
argument_list|(
name|zp
argument_list|)
operator|+
name|double
argument_list|(
name|wp
argument_list|)
operator|*
name|double
argument_list|(
name|wp
argument_list|)
decl_stmt|;
if|if
condition|(
name|qFuzzyIsNull
argument_list|(
name|len
operator|-
literal|1.0f
argument_list|)
operator|||
name|qFuzzyIsNull
argument_list|(
name|len
argument_list|)
condition|)
return|return;
name|len
operator|=
name|sqrt
argument_list|(
name|len
argument_list|)
expr_stmt|;
name|xp
operator|=
name|float
argument_list|(
name|double
argument_list|(
name|xp
argument_list|)
operator|/
name|len
argument_list|)
expr_stmt|;
name|yp
operator|=
name|float
argument_list|(
name|double
argument_list|(
name|yp
argument_list|)
operator|/
name|len
argument_list|)
expr_stmt|;
name|zp
operator|=
name|float
argument_list|(
name|double
argument_list|(
name|zp
argument_list|)
operator|/
name|len
argument_list|)
expr_stmt|;
name|wp
operator|=
name|float
argument_list|(
name|double
argument_list|(
name|wp
argument_list|)
operator|/
name|len
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn QVector4D&QVector4D::operator+=(const QVector4D&vector)      Adds the given \a vector to this vector and returns a reference to     this vector.      \sa operator-=() */
end_comment
begin_comment
comment|/*!     \fn QVector4D&QVector4D::operator-=(const QVector4D&vector)      Subtracts the given \a vector from this vector and returns a reference to     this vector.      \sa operator+=() */
end_comment
begin_comment
comment|/*!     \fn QVector4D&QVector4D::operator*=(float factor)      Multiplies this vector's coordinates by the given \a factor, and     returns a reference to this vector.      \sa operator/=() */
end_comment
begin_comment
comment|/*!     \fn QVector4D&QVector4D::operator*=(const QVector4D&vector)      Multiplies the components of this vector by the corresponding     components in \a vector. */
end_comment
begin_comment
comment|/*!     \fn QVector4D&QVector4D::operator/=(float divisor)      Divides this vector's coordinates by the given \a divisor, and     returns a reference to this vector.      \sa operator*=() */
end_comment
begin_comment
comment|/*!     Returns the dot product of \a v1 and \a v2. */
end_comment
begin_function
DECL|function|dotProduct
name|float
name|QVector4D
operator|::
name|dotProduct
parameter_list|(
specifier|const
name|QVector4D
modifier|&
name|v1
parameter_list|,
specifier|const
name|QVector4D
modifier|&
name|v2
parameter_list|)
block|{
return|return
name|v1
operator|.
name|xp
operator|*
name|v2
operator|.
name|xp
operator|+
name|v1
operator|.
name|yp
operator|*
name|v2
operator|.
name|yp
operator|+
name|v1
operator|.
name|zp
operator|*
name|v2
operator|.
name|zp
operator|+
name|v1
operator|.
name|wp
operator|*
name|v2
operator|.
name|wp
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool operator==(const QVector4D&v1, const QVector4D&v2)     \relates QVector4D      Returns true if \a v1 is equal to \a v2; otherwise returns false.     This operator uses an exact floating-point comparison. */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(const QVector4D&v1, const QVector4D&v2)     \relates QVector4D      Returns true if \a v1 is not equal to \a v2; otherwise returns false.     This operator uses an exact floating-point comparison. */
end_comment
begin_comment
comment|/*!     \fn const QVector4D operator+(const QVector4D&v1, const QVector4D&v2)     \relates QVector4D      Returns a QVector4D object that is the sum of the given vectors, \a v1     and \a v2; each component is added separately.      \sa QVector4D::operator+=() */
end_comment
begin_comment
comment|/*!     \fn const QVector4D operator-(const QVector4D&v1, const QVector4D&v2)     \relates QVector4D      Returns a QVector4D object that is formed by subtracting \a v2 from \a v1;     each component is subtracted separately.      \sa QVector4D::operator-=() */
end_comment
begin_comment
comment|/*!     \fn const QVector4D operator*(float factor, const QVector4D&vector)     \relates QVector4D      Returns a copy of the given \a vector,  multiplied by the given \a factor.      \sa QVector4D::operator*=() */
end_comment
begin_comment
comment|/*!     \fn const QVector4D operator*(const QVector4D&vector, float factor)     \relates QVector4D      Returns a copy of the given \a vector,  multiplied by the given \a factor.      \sa QVector4D::operator*=() */
end_comment
begin_comment
comment|/*!     \fn const QVector4D operator*(const QVector4D&v1, const QVector4D& v2)     \relates QVector4D      Returns the vector consisting of the multiplication of the     components from \a v1 and \a v2.      \sa QVector4D::operator*=() */
end_comment
begin_comment
comment|/*!     \fn const QVector4D operator-(const QVector4D&vector)     \relates QVector4D     \overload      Returns a QVector4D object that is formed by changing the sign of     all three components of the given \a vector.      Equivalent to \c {QVector4D(0,0,0,0) - vector}. */
end_comment
begin_comment
comment|/*!     \fn const QVector4D operator/(const QVector4D&vector, float divisor)     \relates QVector4D      Returns the QVector4D object formed by dividing all four components of     the given \a vector by the given \a divisor.      \sa QVector4D::operator/=() */
end_comment
begin_comment
comment|/*!     \fn bool qFuzzyCompare(const QVector4D& v1, const QVector4D& v2)     \relates QVector4D      Returns true if \a v1 and \a v2 are equal, allowing for a small     fuzziness factor for floating-point comparisons; false otherwise. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_VECTOR2D
end_ifndef
begin_comment
comment|/*!     Returns the 2D vector form of this 4D vector, dropping the z and w coordinates.      \sa toVector2DAffine(), toVector3D(), toPoint() */
end_comment
begin_function
DECL|function|toVector2D
name|QVector2D
name|QVector4D
operator|::
name|toVector2D
parameter_list|()
specifier|const
block|{
return|return
name|QVector2D
argument_list|(
name|xp
argument_list|,
name|yp
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the 2D vector form of this 4D vector, dividing the x and y     coordinates by the w coordinate and dropping the z coordinate.     Returns a null vector if w is zero.      \sa toVector2D(), toVector3DAffine(), toPoint() */
end_comment
begin_function
DECL|function|toVector2DAffine
name|QVector2D
name|QVector4D
operator|::
name|toVector2DAffine
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|qIsNull
argument_list|(
name|wp
argument_list|)
condition|)
return|return
name|QVector2D
argument_list|()
return|;
return|return
name|QVector2D
argument_list|(
name|xp
operator|/
name|wp
argument_list|,
name|yp
operator|/
name|wp
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
end_ifndef
begin_comment
comment|/*!     Returns the 3D vector form of this 4D vector, dropping the w coordinate.      \sa toVector3DAffine(), toVector2D(), toPoint() */
end_comment
begin_function
DECL|function|toVector3D
name|QVector3D
name|QVector4D
operator|::
name|toVector3D
parameter_list|()
specifier|const
block|{
return|return
name|QVector3D
argument_list|(
name|xp
argument_list|,
name|yp
argument_list|,
name|zp
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the 3D vector form of this 4D vector, dividing the x, y, and     z coordinates by the w coordinate.  Returns a null vector if w is zero.      \sa toVector3D(), toVector2DAffine(), toPoint() */
end_comment
begin_function
DECL|function|toVector3DAffine
name|QVector3D
name|QVector4D
operator|::
name|toVector3DAffine
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|qIsNull
argument_list|(
name|wp
argument_list|)
condition|)
return|return
name|QVector3D
argument_list|()
return|;
return|return
name|QVector3D
argument_list|(
name|xp
operator|/
name|wp
argument_list|,
name|yp
operator|/
name|wp
argument_list|,
name|zp
operator|/
name|wp
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \fn QPoint QVector4D::toPoint() const      Returns the QPoint form of this 4D vector. The z and w coordinates     are dropped.      \sa toPointF(), toVector2D() */
end_comment
begin_comment
comment|/*!     \fn QPointF QVector4D::toPointF() const      Returns the QPointF form of this 4D vector. The z and w coordinates     are dropped.      \sa toPoint(), toVector2D() */
end_comment
begin_comment
comment|/*!     Returns the 4D vector as a QVariant. */
end_comment
begin_function
DECL|function|operator QVariant
name|QVector4D
operator|::
name|operator
name|QVariant
parameter_list|()
specifier|const
block|{
return|return
name|QVariant
argument_list|(
name|QVariant
operator|::
name|Vector4D
argument_list|,
name|this
argument_list|)
return|;
block|}
end_function
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
name|QVector4D
modifier|&
name|vector
parameter_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QVector4D("
operator|<<
name|vector
operator|.
name|x
argument_list|()
operator|<<
literal|", "
operator|<<
name|vector
operator|.
name|y
argument_list|()
operator|<<
literal|", "
operator|<<
name|vector
operator|.
name|z
argument_list|()
operator|<<
literal|", "
operator|<<
name|vector
operator|.
name|w
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_comment
comment|/*!     \fn QDataStream&operator<<(QDataStream&stream, const QVector4D&vector)     \relates QVector4D      Writes the given \a vector to the given \a stream and returns a     reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|stream
parameter_list|,
specifier|const
name|QVector4D
modifier|&
name|vector
parameter_list|)
block|{
name|stream
operator|<<
name|vector
operator|.
name|x
argument_list|()
operator|<<
name|vector
operator|.
name|y
argument_list|()
operator|<<
name|vector
operator|.
name|z
argument_list|()
operator|<<
name|vector
operator|.
name|w
argument_list|()
expr_stmt|;
return|return
name|stream
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QDataStream&operator>>(QDataStream&stream, QVector4D&vector)     \relates QVector4D      Reads a 4D vector from the given \a stream into the given \a vector     and returns a reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|stream
parameter_list|,
name|QVector4D
modifier|&
name|vector
parameter_list|)
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|w
decl_stmt|;
name|stream
operator|>>
name|x
expr_stmt|;
name|stream
operator|>>
name|y
expr_stmt|;
name|stream
operator|>>
name|z
expr_stmt|;
name|stream
operator|>>
name|w
expr_stmt|;
name|vector
operator|.
name|setX
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|vector
operator|.
name|setY
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|vector
operator|.
name|setZ
argument_list|(
name|z
argument_list|)
expr_stmt|;
name|vector
operator|.
name|setW
argument_list|(
name|w
argument_list|)
expr_stmt|;
return|return
name|stream
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_VECTOR4D
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
