begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
file|"qvector4d.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatastream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
comment|/*!     \class QVector3D     \brief The QVector3D class represents a vector or vertex in 3D space.     \since 4.6     \ingroup painting-3D     \inmodule QtGui      Vectors are one of the main building blocks of 3D representation and     drawing.  They consist of three coordinates, traditionally called     x, y, and z.      The QVector3D class can also be used to represent vertices in 3D space.     We therefore do not need to provide a separate vertex class.      \sa QVector2D, QVector4D, QQuaternion */
comment|/*!     \fn QVector3D::QVector3D()      Constructs a null vector, i.e. with coordinates (0, 0, 0). */
comment|/*!     \fn QVector3D::QVector3D(float xpos, float ypos, float zpos)      Constructs a vector with coordinates (\a xpos, \a ypos, \a zpos). */
comment|/*!     \fn QVector3D::QVector3D(const QPoint& point)      Constructs a vector with x and y coordinates from a 2D \a point, and a     z coordinate of 0. */
comment|/*!     \fn QVector3D::QVector3D(const QPointF& point)      Constructs a vector with x and y coordinates from a 2D \a point, and a     z coordinate of 0. */
ifndef|#
directive|ifndef
name|QT_NO_VECTOR2D
comment|/*!     Constructs a 3D vector from the specified 2D \a vector.  The z     coordinate is set to zero.      \sa toVector2D() */
DECL|function|QVector3D
name|QVector3D
operator|::
name|QVector3D
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
block|}
end_function
begin_comment
comment|/*!     Constructs a 3D vector from the specified 2D \a vector.  The z     coordinate is set to \a zpos.      \sa toVector2D() */
end_comment
begin_constructor
DECL|function|QVector3D
name|QVector3D
operator|::
name|QVector3D
parameter_list|(
specifier|const
name|QVector2D
modifier|&
name|vector
parameter_list|,
name|float
name|zpos
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
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_VECTOR4D
end_ifndef
begin_comment
comment|/*!     Constructs a 3D vector from the specified 4D \a vector.  The w     coordinate is dropped.      \sa toVector4D() */
end_comment
begin_constructor
DECL|function|QVector3D
name|QVector3D
operator|::
name|QVector3D
parameter_list|(
specifier|const
name|QVector4D
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
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \fn bool QVector3D::isNull() const      Returns true if the x, y, and z coordinates are set to 0.0,     otherwise returns false. */
end_comment
begin_comment
comment|/*!     \fn float QVector3D::x() const      Returns the x coordinate of this point.      \sa setX(), y(), z() */
end_comment
begin_comment
comment|/*!     \fn float QVector3D::y() const      Returns the y coordinate of this point.      \sa setY(), x(), z() */
end_comment
begin_comment
comment|/*!     \fn float QVector3D::z() const      Returns the z coordinate of this point.      \sa setZ(), x(), y() */
end_comment
begin_comment
comment|/*!     \fn void QVector3D::setX(float x)      Sets the x coordinate of this point to the given \a x coordinate.      \sa x(), setY(), setZ() */
end_comment
begin_comment
comment|/*!     \fn void QVector3D::setY(float y)      Sets the y coordinate of this point to the given \a y coordinate.      \sa y(), setX(), setZ() */
end_comment
begin_comment
comment|/*!     \fn void QVector3D::setZ(float z)      Sets the z coordinate of this point to the given \a z coordinate.      \sa z(), setX(), setY() */
end_comment
begin_comment
comment|/*! \fn float&QVector3D::operator[](int i)     \since 5.2      Returns the component of the vector at index position \a i     as a modifiable reference.      \a i must be a valid index position in the vector (i.e., 0<= \a i< 3). */
end_comment
begin_comment
comment|/*! \fn float QVector3D::operator[](int i) const     \since 5.2      Returns the component of the vector at index position \a i.      \a i must be a valid index position in the vector (i.e., 0<= \a i< 3). */
end_comment
begin_comment
comment|/*!     Returns the normalized unit vector form of this vector.      If this vector is null, then a null vector is returned.  If the length     of the vector is very close to 1, then the vector will be returned as-is.     Otherwise the normalized form of the vector of length 1 will be returned.      \sa length(), normalize() */
end_comment
begin_function
DECL|function|normalized
name|QVector3D
name|QVector3D
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
name|QVector3D
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
argument_list|)
return|;
block|}
else|else
block|{
return|return
name|QVector3D
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
name|QVector3D
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
block|}
end_function
begin_comment
comment|/*!     \fn QVector3D&QVector3D::operator+=(const QVector3D&vector)      Adds the given \a vector to this vector and returns a reference to     this vector.      \sa operator-=() */
end_comment
begin_comment
comment|/*!     \fn QVector3D&QVector3D::operator-=(const QVector3D&vector)      Subtracts the given \a vector from this vector and returns a reference to     this vector.      \sa operator+=() */
end_comment
begin_comment
comment|/*!     \fn QVector3D&QVector3D::operator*=(float factor)      Multiplies this vector's coordinates by the given \a factor, and     returns a reference to this vector.      \sa operator/=() */
end_comment
begin_comment
comment|/*!     \fn QVector3D&QVector3D::operator*=(const QVector3D& vector)     \overload      Multiplies the components of this vector by the corresponding     components in \a vector.      Note: this is not the same as the crossProduct() of this     vector and \a vector.      \sa crossProduct() */
end_comment
begin_comment
comment|/*!     \fn QVector3D&QVector3D::operator/=(float divisor)      Divides this vector's coordinates by the given \a divisor, and     returns a reference to this vector.      \sa operator*=() */
end_comment
begin_comment
comment|/*!     Returns the dot product of \a v1 and \a v2. */
end_comment
begin_function
DECL|function|dotProduct
name|float
name|QVector3D
operator|::
name|dotProduct
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|v1
parameter_list|,
specifier|const
name|QVector3D
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
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the cross-product of vectors \a v1 and \a v2, which corresponds     to the normal vector of a plane defined by \a v1 and \a v2.      \sa normal() */
end_comment
begin_function
DECL|function|crossProduct
name|QVector3D
name|QVector3D
operator|::
name|crossProduct
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|v1
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|v2
parameter_list|)
block|{
return|return
name|QVector3D
argument_list|(
name|v1
operator|.
name|yp
operator|*
name|v2
operator|.
name|zp
operator|-
name|v1
operator|.
name|zp
operator|*
name|v2
operator|.
name|yp
argument_list|,
name|v1
operator|.
name|zp
operator|*
name|v2
operator|.
name|xp
operator|-
name|v1
operator|.
name|xp
operator|*
name|v2
operator|.
name|zp
argument_list|,
name|v1
operator|.
name|xp
operator|*
name|v2
operator|.
name|yp
operator|-
name|v1
operator|.
name|yp
operator|*
name|v2
operator|.
name|xp
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the normal vector of a plane defined by vectors \a v1 and \a v2,     normalized to be a unit vector.      Use crossProduct() to compute the cross-product of \a v1 and \a v2 if you     do not need the result to be normalized to a unit vector.      \sa crossProduct(), distanceToPlane() */
end_comment
begin_function
DECL|function|normal
name|QVector3D
name|QVector3D
operator|::
name|normal
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|v1
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|v2
parameter_list|)
block|{
return|return
name|crossProduct
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
operator|.
name|normalized
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \overload      Returns the normal vector of a plane defined by vectors     \a v2 - \a v1 and \a v3 - \a v1, normalized to be a unit vector.      Use crossProduct() to compute the cross-product of \a v2 - \a v1 and     \a v3 - \a v1 if you do not need the result to be normalized to a     unit vector.      \sa crossProduct(), distanceToPlane() */
end_comment
begin_function
DECL|function|normal
name|QVector3D
name|QVector3D
operator|::
name|normal
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|v1
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|v2
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|v3
parameter_list|)
block|{
return|return
name|crossProduct
argument_list|(
operator|(
name|v2
operator|-
name|v1
operator|)
argument_list|,
operator|(
name|v3
operator|-
name|v1
operator|)
argument_list|)
operator|.
name|normalized
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.1      Returns the distance from this vertex to a point defined by     the vertex \a point.      \sa distanceToPlane(), distanceToLine() */
end_comment
begin_function
DECL|function|distanceToPoint
name|float
name|QVector3D
operator|::
name|distanceToPoint
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|point
parameter_list|)
specifier|const
block|{
return|return
operator|(
operator|*
name|this
operator|-
name|point
operator|)
operator|.
name|length
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the distance from this vertex to a plane defined by     the vertex \a plane and a \a normal unit vector.  The \a normal     parameter is assumed to have been normalized to a unit vector.      The return value will be negative if the vertex is below the plane,     or zero if it is on the plane.      \sa normal(), distanceToLine() */
end_comment
begin_function
DECL|function|distanceToPlane
name|float
name|QVector3D
operator|::
name|distanceToPlane
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|plane
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|normal
parameter_list|)
specifier|const
block|{
return|return
name|dotProduct
argument_list|(
operator|*
name|this
operator|-
name|plane
argument_list|,
name|normal
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \overload      Returns the distance from this vertex a plane defined by     the vertices \a plane1, \a plane2 and \a plane3.      The return value will be negative if the vertex is below the plane,     or zero if it is on the plane.      The two vectors that define the plane are \a plane2 - \a plane1     and \a plane3 - \a plane1.      \sa normal(), distanceToLine() */
end_comment
begin_function
DECL|function|distanceToPlane
name|float
name|QVector3D
operator|::
name|distanceToPlane
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|plane1
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|plane2
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|plane3
parameter_list|)
specifier|const
block|{
name|QVector3D
name|n
init|=
name|normal
argument_list|(
name|plane2
operator|-
name|plane1
argument_list|,
name|plane3
operator|-
name|plane1
argument_list|)
decl_stmt|;
return|return
name|dotProduct
argument_list|(
operator|*
name|this
operator|-
name|plane1
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the distance that this vertex is from a line defined     by \a point and the unit vector \a direction.      If \a direction is a null vector, then it does not define a line.     In that case, the distance from \a point to this vertex is returned.      \sa distanceToPlane() */
end_comment
begin_function
DECL|function|distanceToLine
name|float
name|QVector3D
operator|::
name|distanceToLine
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|point
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|direction
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|direction
operator|.
name|isNull
argument_list|()
condition|)
return|return
operator|(
operator|*
name|this
operator|-
name|point
operator|)
operator|.
name|length
argument_list|()
return|;
name|QVector3D
name|p
init|=
name|point
operator|+
name|dotProduct
argument_list|(
operator|*
name|this
operator|-
name|point
argument_list|,
name|direction
argument_list|)
operator|*
name|direction
decl_stmt|;
return|return
operator|(
operator|*
name|this
operator|-
name|p
operator|)
operator|.
name|length
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool operator==(const QVector3D&v1, const QVector3D&v2)     \relates QVector3D      Returns true if \a v1 is equal to \a v2; otherwise returns false.     This operator uses an exact floating-point comparison. */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(const QVector3D&v1, const QVector3D&v2)     \relates QVector3D      Returns true if \a v1 is not equal to \a v2; otherwise returns false.     This operator uses an exact floating-point comparison. */
end_comment
begin_comment
comment|/*!     \fn const QVector3D operator+(const QVector3D&v1, const QVector3D&v2)     \relates QVector3D      Returns a QVector3D object that is the sum of the given vectors, \a v1     and \a v2; each component is added separately.      \sa QVector3D::operator+=() */
end_comment
begin_comment
comment|/*!     \fn const QVector3D operator-(const QVector3D&v1, const QVector3D&v2)     \relates QVector3D      Returns a QVector3D object that is formed by subtracting \a v2 from \a v1;     each component is subtracted separately.      \sa QVector3D::operator-=() */
end_comment
begin_comment
comment|/*!     \fn const QVector3D operator*(float factor, const QVector3D&vector)     \relates QVector3D      Returns a copy of the given \a vector,  multiplied by the given \a factor.      \sa QVector3D::operator*=() */
end_comment
begin_comment
comment|/*!     \fn const QVector3D operator*(const QVector3D&vector, float factor)     \relates QVector3D      Returns a copy of the given \a vector,  multiplied by the given \a factor.      \sa QVector3D::operator*=() */
end_comment
begin_comment
comment|/*!     \fn const QVector3D operator*(const QVector3D&v1, const QVector3D& v2)     \relates QVector3D      Multiplies the components of \a v1 by the corresponding components in \a v2.      Note: this is not the same as the crossProduct() of \a v1 and \a v2.      \sa QVector3D::crossProduct() */
end_comment
begin_comment
comment|/*!     \fn const QVector3D operator-(const QVector3D&vector)     \relates QVector3D     \overload      Returns a QVector3D object that is formed by changing the sign of     all three components of the given \a vector.      Equivalent to \c {QVector3D(0,0,0) - vector}. */
end_comment
begin_comment
comment|/*!     \fn const QVector3D operator/(const QVector3D&vector, float divisor)     \relates QVector3D      Returns the QVector3D object formed by dividing all three components of     the given \a vector by the given \a divisor.      \sa QVector3D::operator/=() */
end_comment
begin_comment
comment|/*!     \fn bool qFuzzyCompare(const QVector3D& v1, const QVector3D& v2)     \relates QVector3D      Returns true if \a v1 and \a v2 are equal, allowing for a small     fuzziness factor for floating-point comparisons; false otherwise. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_VECTOR2D
end_ifndef
begin_comment
comment|/*!     Returns the 2D vector form of this 3D vector, dropping the z coordinate.      \sa toVector4D(), toPoint() */
end_comment
begin_function
DECL|function|toVector2D
name|QVector2D
name|QVector3D
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
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_VECTOR4D
end_ifndef
begin_comment
comment|/*!     Returns the 4D form of this 3D vector, with the w coordinate set to zero.      \sa toVector2D(), toPoint() */
end_comment
begin_function
DECL|function|toVector4D
name|QVector4D
name|QVector3D
operator|::
name|toVector4D
parameter_list|()
specifier|const
block|{
return|return
name|QVector4D
argument_list|(
name|xp
argument_list|,
name|yp
argument_list|,
name|zp
argument_list|,
literal|0.0f
argument_list|)
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \fn QPoint QVector3D::toPoint() const      Returns the QPoint form of this 3D vector. The z coordinate     is dropped.      \sa toPointF(), toVector2D() */
end_comment
begin_comment
comment|/*!     \fn QPointF QVector3D::toPointF() const      Returns the QPointF form of this 3D vector. The z coordinate     is dropped.      \sa toPoint(), toVector2D() */
end_comment
begin_comment
comment|/*!     Returns the 3D vector as a QVariant. */
end_comment
begin_function
DECL|function|operator QVariant
name|QVector3D
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
name|Vector3D
argument_list|,
name|this
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the length of the vector from the origin.      \sa lengthSquared(), normalized() */
end_comment
begin_function
DECL|function|length
name|float
name|QVector3D
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
name|QVector3D
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
name|QVector3D
modifier|&
name|vector
parameter_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QVector3D("
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
comment|/*!     \fn QDataStream&operator<<(QDataStream&stream, const QVector3D&vector)     \relates QVector3D      Writes the given \a vector to the given \a stream and returns a     reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|QVector3D
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
expr_stmt|;
return|return
name|stream
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QDataStream&operator>>(QDataStream&stream, QVector3D&vector)     \relates QVector3D      Reads a 3D vector from the given \a stream into the given \a vector     and returns a reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|QVector3D
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
comment|// QT_NO_VECTOR3D
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
