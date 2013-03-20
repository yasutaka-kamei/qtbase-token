begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qquaternion.h"
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
begin_include
include|#
directive|include
file|<cmath>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_QUATERNION
comment|/*!     \class QQuaternion     \brief The QQuaternion class represents a quaternion consisting of a vector and scalar.     \since 4.6     \ingroup painting-3D     \inmodule QtGui      Quaternions are used to represent rotations in 3D space, and     consist of a 3D rotation axis specified by the x, y, and z     coordinates, and a scalar representing the rotation angle. */
comment|/*!     \fn QQuaternion::QQuaternion()      Constructs an identity quaternion (1, 0, 0, 0), i.e. with the vector (0, 0, 0)     and scalar 1. */
comment|/*!     \fn QQuaternion::QQuaternion(float scalar, float xpos, float ypos, float zpos)      Constructs a quaternion with the vector (\a xpos, \a ypos, \a zpos)     and \a scalar. */
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
comment|/*!     \fn QQuaternion::QQuaternion(float scalar, const QVector3D& vector)      Constructs a quaternion vector from the specified \a vector and     \a scalar.      \sa vector(), scalar() */
comment|/*!     \fn QVector3D QQuaternion::vector() const      Returns the vector component of this quaternion.      \sa setVector(), scalar() */
comment|/*!     \fn void QQuaternion::setVector(const QVector3D& vector)      Sets the vector component of this quaternion to \a vector.      \sa vector(), setScalar() */
endif|#
directive|endif
comment|/*!     \fn void QQuaternion::setVector(float x, float y, float z)      Sets the vector component of this quaternion to (\a x, \a y, \a z).      \sa vector(), setScalar() */
ifndef|#
directive|ifndef
name|QT_NO_VECTOR4D
comment|/*!     \fn QQuaternion::QQuaternion(const QVector4D& vector)      Constructs a quaternion from the components of \a vector. */
comment|/*!     \fn QVector4D QQuaternion::toVector4D() const      Returns this quaternion as a 4D vector. */
endif|#
directive|endif
comment|/*!     \fn bool QQuaternion::isNull() const      Returns true if the x, y, z, and scalar components of this     quaternion are set to 0.0; otherwise returns false. */
comment|/*!     \fn bool QQuaternion::isIdentity() const      Returns true if the x, y, and z components of this     quaternion are set to 0.0, and the scalar component is set     to 1.0; otherwise returns false. */
comment|/*!     \fn float QQuaternion::x() const      Returns the x coordinate of this quaternion's vector.      \sa setX(), y(), z(), scalar() */
comment|/*!     \fn float QQuaternion::y() const      Returns the y coordinate of this quaternion's vector.      \sa setY(), x(), z(), scalar() */
comment|/*!     \fn float QQuaternion::z() const      Returns the z coordinate of this quaternion's vector.      \sa setZ(), x(), y(), scalar() */
comment|/*!     \fn float QQuaternion::scalar() const      Returns the scalar component of this quaternion.      \sa setScalar(), x(), y(), z() */
comment|/*!     \fn void QQuaternion::setX(float x)      Sets the x coordinate of this quaternion's vector to the given     \a x coordinate.      \sa x(), setY(), setZ(), setScalar() */
comment|/*!     \fn void QQuaternion::setY(float y)      Sets the y coordinate of this quaternion's vector to the given     \a y coordinate.      \sa y(), setX(), setZ(), setScalar() */
comment|/*!     \fn void QQuaternion::setZ(float z)      Sets the z coordinate of this quaternion's vector to the given     \a z coordinate.      \sa z(), setX(), setY(), setScalar() */
comment|/*!     \fn void QQuaternion::setScalar(float scalar)      Sets the scalar component of this quaternion to \a scalar.      \sa scalar(), setX(), setY(), setZ() */
comment|/*!     Returns the length of the quaternion.  This is also called the "norm".      \sa lengthSquared(), normalized() */
DECL|function|length
name|float
name|QQuaternion
operator|::
name|length
parameter_list|()
specifier|const
block|{
return|return
name|qSqrt
argument_list|(
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
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the squared length of the quaternion.      \sa length() */
end_comment
begin_function
DECL|function|lengthSquared
name|float
name|QQuaternion
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
comment|/*!     Returns the normalized unit form of this quaternion.      If this quaternion is null, then a null quaternion is returned.     If the length of the quaternion is very close to 1, then the quaternion     will be returned as-is.  Otherwise the normalized form of the     quaternion of length 1 will be returned.      \sa length(), normalize() */
end_comment
begin_function
DECL|function|normalized
name|QQuaternion
name|QQuaternion
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
return|return
operator|*
name|this
return|;
elseif|else
if|if
condition|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|len
argument_list|)
condition|)
return|return
operator|*
name|this
operator|/
name|qSqrt
argument_list|(
name|len
argument_list|)
return|;
else|else
return|return
name|QQuaternion
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Normalizes the current quaternion in place.  Nothing happens if this     is a null quaternion or the length of the quaternion is very close to 1.      \sa length(), normalized() */
end_comment
begin_function
DECL|function|normalize
name|void
name|QQuaternion
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
name|qSqrt
argument_list|(
name|len
argument_list|)
expr_stmt|;
name|xp
operator|/=
name|len
expr_stmt|;
name|yp
operator|/=
name|len
expr_stmt|;
name|zp
operator|/=
name|len
expr_stmt|;
name|wp
operator|/=
name|len
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn QQuaternion QQuaternion::conjugate() const      Returns the conjugate of this quaternion, which is     (-x, -y, -z, scalar). */
end_comment
begin_comment
comment|/*!     Rotates \a vector with this quaternion to produce a new vector     in 3D space.  The following code:      \code     QVector3D result = q.rotatedVector(vector);     \endcode      is equivalent to the following:      \code     QVector3D result = (q * QQuaternion(0, vector) * q.conjugate()).vector();     \endcode */
end_comment
begin_function
DECL|function|rotatedVector
name|QVector3D
name|QQuaternion
operator|::
name|rotatedVector
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|vector
parameter_list|)
specifier|const
block|{
return|return
operator|(
operator|*
name|this
operator|*
name|QQuaternion
argument_list|(
literal|0
argument_list|,
name|vector
argument_list|)
operator|*
name|conjugate
argument_list|()
operator|)
operator|.
name|vector
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QQuaternion&QQuaternion::operator+=(const QQuaternion&quaternion)      Adds the given \a quaternion to this quaternion and returns a reference to     this quaternion.      \sa operator-=() */
end_comment
begin_comment
comment|/*!     \fn QQuaternion&QQuaternion::operator-=(const QQuaternion&quaternion)      Subtracts the given \a quaternion from this quaternion and returns a     reference to this quaternion.      \sa operator+=() */
end_comment
begin_comment
comment|/*!     \fn QQuaternion&QQuaternion::operator*=(float factor)      Multiplies this quaternion's components by the given \a factor, and     returns a reference to this quaternion.      \sa operator/=() */
end_comment
begin_comment
comment|/*!     \fn QQuaternion&QQuaternion::operator*=(const QQuaternion&quaternion)      Multiplies this quaternion by \a quaternion and returns a reference     to this quaternion. */
end_comment
begin_comment
comment|/*!     \fn QQuaternion&QQuaternion::operator/=(float divisor)      Divides this quaternion's components by the given \a divisor, and     returns a reference to this quaternion.      \sa operator*=() */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
end_ifndef
begin_comment
comment|/*!     Creates a normalized quaternion that corresponds to rotating through     \a angle degrees about the specified 3D \a axis. */
end_comment
begin_function
DECL|function|fromAxisAndAngle
name|QQuaternion
name|QQuaternion
operator|::
name|fromAxisAndAngle
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|axis
parameter_list|,
name|float
name|angle
parameter_list|)
block|{
comment|// Algorithm from:
comment|// http://www.j3d.org/matrix_faq/matrfaq_latest.html#Q56
comment|// We normalize the result just in case the values are close
comment|// to zero, as suggested in the above FAQ.
name|float
name|a
init|=
operator|(
name|angle
operator|/
literal|2.0f
operator|)
operator|*
name|M_PI
operator|/
literal|180.0f
decl_stmt|;
name|float
name|s
init|=
name|sinf
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|float
name|c
init|=
name|cosf
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|QVector3D
name|ax
init|=
name|axis
operator|.
name|normalized
argument_list|()
decl_stmt|;
return|return
name|QQuaternion
argument_list|(
name|c
argument_list|,
name|ax
operator|.
name|x
argument_list|()
operator|*
name|s
argument_list|,
name|ax
operator|.
name|y
argument_list|()
operator|*
name|s
argument_list|,
name|ax
operator|.
name|z
argument_list|()
operator|*
name|s
argument_list|)
operator|.
name|normalized
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Creates a normalized quaternion that corresponds to rotating through     \a angle degrees about the 3D axis (\a x, \a y, \a z). */
end_comment
begin_function
DECL|function|fromAxisAndAngle
name|QQuaternion
name|QQuaternion
operator|::
name|fromAxisAndAngle
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|,
name|float
name|z
parameter_list|,
name|float
name|angle
parameter_list|)
block|{
name|float
name|length
init|=
name|qSqrt
argument_list|(
name|x
operator|*
name|x
operator|+
name|y
operator|*
name|y
operator|+
name|z
operator|*
name|z
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|qFuzzyIsNull
argument_list|(
name|length
operator|-
literal|1.0f
argument_list|)
operator|&&
operator|!
name|qFuzzyIsNull
argument_list|(
name|length
argument_list|)
condition|)
block|{
name|x
operator|/=
name|length
expr_stmt|;
name|y
operator|/=
name|length
expr_stmt|;
name|z
operator|/=
name|length
expr_stmt|;
block|}
name|float
name|a
init|=
operator|(
name|angle
operator|/
literal|2.0f
operator|)
operator|*
name|M_PI
operator|/
literal|180.0f
decl_stmt|;
name|float
name|s
init|=
name|sinf
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|float
name|c
init|=
name|cosf
argument_list|(
name|a
argument_list|)
decl_stmt|;
return|return
name|QQuaternion
argument_list|(
name|c
argument_list|,
name|x
operator|*
name|s
argument_list|,
name|y
operator|*
name|s
argument_list|,
name|z
operator|*
name|s
argument_list|)
operator|.
name|normalized
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \fn bool operator==(const QQuaternion&q1, const QQuaternion&q2)     \relates QQuaternion      Returns true if \a q1 is equal to \a q2; otherwise returns false.     This operator uses an exact floating-point comparison. */
end_comment
begin_comment
comment|/*!     \fn bool operator!=(const QQuaternion&q1, const QQuaternion&q2)     \relates QQuaternion      Returns true if \a q1 is not equal to \a q2; otherwise returns false.     This operator uses an exact floating-point comparison. */
end_comment
begin_comment
comment|/*!     \fn const QQuaternion operator+(const QQuaternion&q1, const QQuaternion&q2)     \relates QQuaternion      Returns a QQuaternion object that is the sum of the given quaternions,     \a q1 and \a q2; each component is added separately.      \sa QQuaternion::operator+=() */
end_comment
begin_comment
comment|/*!     \fn const QQuaternion operator-(const QQuaternion&q1, const QQuaternion&q2)     \relates QQuaternion      Returns a QQuaternion object that is formed by subtracting     \a q2 from \a q1; each component is subtracted separately.      \sa QQuaternion::operator-=() */
end_comment
begin_comment
comment|/*!     \fn const QQuaternion operator*(float factor, const QQuaternion&quaternion)     \relates QQuaternion      Returns a copy of the given \a quaternion,  multiplied by the     given \a factor.      \sa QQuaternion::operator*=() */
end_comment
begin_comment
comment|/*!     \fn const QQuaternion operator*(const QQuaternion&quaternion, float factor)     \relates QQuaternion      Returns a copy of the given \a quaternion,  multiplied by the     given \a factor.      \sa QQuaternion::operator*=() */
end_comment
begin_comment
comment|/*!     \fn const QQuaternion operator*(const QQuaternion&q1, const QQuaternion& q2)     \relates QQuaternion      Multiplies \a q1 and \a q2 using quaternion multiplication.     The result corresponds to applying both of the rotations specified     by \a q1 and \a q2.      \sa QQuaternion::operator*=() */
end_comment
begin_comment
comment|/*!     \fn const QQuaternion operator-(const QQuaternion&quaternion)     \relates QQuaternion     \overload      Returns a QQuaternion object that is formed by changing the sign of     all three components of the given \a quaternion.      Equivalent to \c {QQuaternion(0,0,0,0) - quaternion}. */
end_comment
begin_comment
comment|/*!     \fn const QQuaternion operator/(const QQuaternion&quaternion, float divisor)     \relates QQuaternion      Returns the QQuaternion object formed by dividing all components of     the given \a quaternion by the given \a divisor.      \sa QQuaternion::operator/=() */
end_comment
begin_comment
comment|/*!     \fn bool qFuzzyCompare(const QQuaternion& q1, const QQuaternion& q2)     \relates QQuaternion      Returns true if \a q1 and \a q2 are equal, allowing for a small     fuzziness factor for floating-point comparisons; false otherwise. */
end_comment
begin_comment
comment|/*!     Interpolates along the shortest spherical path between the     rotational positions \a q1 and \a q2.  The value \a t should     be between 0 and 1, indicating the spherical distance to travel     between \a q1 and \a q2.      If \a t is less than or equal to 0, then \a q1 will be returned.     If \a t is greater than or equal to 1, then \a q2 will be returned.      \sa nlerp() */
end_comment
begin_function
DECL|function|slerp
name|QQuaternion
name|QQuaternion
operator|::
name|slerp
parameter_list|(
specifier|const
name|QQuaternion
modifier|&
name|q1
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|q2
parameter_list|,
name|float
name|t
parameter_list|)
block|{
comment|// Handle the easy cases first.
if|if
condition|(
name|t
operator|<=
literal|0.0f
condition|)
return|return
name|q1
return|;
elseif|else
if|if
condition|(
name|t
operator|>=
literal|1.0f
condition|)
return|return
name|q2
return|;
comment|// Determine the angle between the two quaternions.
name|QQuaternion
name|q2b
decl_stmt|;
name|float
name|dot
decl_stmt|;
name|dot
operator|=
name|q1
operator|.
name|xp
operator|*
name|q2
operator|.
name|xp
operator|+
name|q1
operator|.
name|yp
operator|*
name|q2
operator|.
name|yp
operator|+
name|q1
operator|.
name|zp
operator|*
name|q2
operator|.
name|zp
operator|+
name|q1
operator|.
name|wp
operator|*
name|q2
operator|.
name|wp
expr_stmt|;
if|if
condition|(
name|dot
operator|>=
literal|0.0f
condition|)
block|{
name|q2b
operator|=
name|q2
expr_stmt|;
block|}
else|else
block|{
name|q2b
operator|=
operator|-
name|q2
expr_stmt|;
name|dot
operator|=
operator|-
name|dot
expr_stmt|;
block|}
comment|// Get the scale factors.  If they are too small,
comment|// then revert to simple linear interpolation.
name|float
name|factor1
init|=
literal|1.0f
operator|-
name|t
decl_stmt|;
name|float
name|factor2
init|=
name|t
decl_stmt|;
if|if
condition|(
operator|(
literal|1.0f
operator|-
name|dot
operator|)
operator|>
literal|0.0000001
condition|)
block|{
name|float
name|angle
init|=
name|acosf
argument_list|(
name|dot
argument_list|)
decl_stmt|;
name|float
name|sinOfAngle
init|=
name|sinf
argument_list|(
name|angle
argument_list|)
decl_stmt|;
if|if
condition|(
name|sinOfAngle
operator|>
literal|0.0000001
condition|)
block|{
name|factor1
operator|=
name|sinf
argument_list|(
operator|(
literal|1.0f
operator|-
name|t
operator|)
operator|*
name|angle
argument_list|)
operator|/
name|sinOfAngle
expr_stmt|;
name|factor2
operator|=
name|sinf
argument_list|(
name|t
operator|*
name|angle
argument_list|)
operator|/
name|sinOfAngle
expr_stmt|;
block|}
block|}
comment|// Construct the result quaternion.
return|return
name|q1
operator|*
name|factor1
operator|+
name|q2b
operator|*
name|factor2
return|;
block|}
end_function
begin_comment
comment|/*!     Interpolates along the shortest linear path between the rotational     positions \a q1 and \a q2.  The value \a t should be between 0 and 1,     indicating the distance to travel between \a q1 and \a q2.     The result will be normalized().      If \a t is less than or equal to 0, then \a q1 will be returned.     If \a t is greater than or equal to 1, then \a q2 will be returned.      The nlerp() function is typically faster than slerp() and will     give approximate results to spherical interpolation that are     good enough for some applications.      \sa slerp() */
end_comment
begin_function
DECL|function|nlerp
name|QQuaternion
name|QQuaternion
operator|::
name|nlerp
parameter_list|(
specifier|const
name|QQuaternion
modifier|&
name|q1
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|q2
parameter_list|,
name|float
name|t
parameter_list|)
block|{
comment|// Handle the easy cases first.
if|if
condition|(
name|t
operator|<=
literal|0.0f
condition|)
return|return
name|q1
return|;
elseif|else
if|if
condition|(
name|t
operator|>=
literal|1.0f
condition|)
return|return
name|q2
return|;
comment|// Determine the angle between the two quaternions.
name|QQuaternion
name|q2b
decl_stmt|;
name|float
name|dot
decl_stmt|;
name|dot
operator|=
name|q1
operator|.
name|xp
operator|*
name|q2
operator|.
name|xp
operator|+
name|q1
operator|.
name|yp
operator|*
name|q2
operator|.
name|yp
operator|+
name|q1
operator|.
name|zp
operator|*
name|q2
operator|.
name|zp
operator|+
name|q1
operator|.
name|wp
operator|*
name|q2
operator|.
name|wp
expr_stmt|;
if|if
condition|(
name|dot
operator|>=
literal|0.0f
condition|)
name|q2b
operator|=
name|q2
expr_stmt|;
else|else
name|q2b
operator|=
operator|-
name|q2
expr_stmt|;
comment|// Perform the linear interpolation.
return|return
operator|(
name|q1
operator|*
operator|(
literal|1.0f
operator|-
name|t
operator|)
operator|+
name|q2b
operator|*
name|t
operator|)
operator|.
name|normalized
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the quaternion as a QVariant. */
end_comment
begin_function
DECL|function|operator QVariant
name|QQuaternion
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
name|Quaternion
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
name|QQuaternion
modifier|&
name|q
parameter_list|)
block|{
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QQuaternion(scalar:"
operator|<<
name|q
operator|.
name|scalar
argument_list|()
operator|<<
literal|", vector:("
operator|<<
name|q
operator|.
name|x
argument_list|()
operator|<<
literal|", "
operator|<<
name|q
operator|.
name|y
argument_list|()
operator|<<
literal|", "
operator|<<
name|q
operator|.
name|z
argument_list|()
operator|<<
literal|"))"
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
comment|/*!     \fn QDataStream&operator<<(QDataStream&stream, const QQuaternion&quaternion)     \relates QQuaternion      Writes the given \a quaternion to the given \a stream and returns a     reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|QQuaternion
modifier|&
name|quaternion
parameter_list|)
block|{
name|stream
operator|<<
name|quaternion
operator|.
name|scalar
argument_list|()
operator|<<
name|quaternion
operator|.
name|x
argument_list|()
operator|<<
name|quaternion
operator|.
name|y
argument_list|()
operator|<<
name|quaternion
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
comment|/*!     \fn QDataStream&operator>>(QDataStream&stream, QQuaternion&quaternion)     \relates QQuaternion      Reads a quaternion from the given \a stream into the given \a quaternion     and returns a reference to the stream.      \sa {Serializing Qt Data Types} */
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
name|QQuaternion
modifier|&
name|quaternion
parameter_list|)
block|{
name|float
name|scalar
decl_stmt|,
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
name|stream
operator|>>
name|scalar
expr_stmt|;
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
name|quaternion
operator|.
name|setScalar
argument_list|(
name|scalar
argument_list|)
expr_stmt|;
name|quaternion
operator|.
name|setX
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|quaternion
operator|.
name|setY
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|quaternion
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
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
