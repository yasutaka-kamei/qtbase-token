begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qgraphicsitem.h>
end_include
begin_include
include|#
directive|include
file|<qgraphicstransform.h>
end_include
begin_class
DECL|class|tst_QGraphicsTransform
class|class
name|tst_QGraphicsTransform
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|scale
parameter_list|()
function_decl|;
name|void
name|rotation
parameter_list|()
function_decl|;
name|void
name|rotation3d_data
parameter_list|()
function_decl|;
name|void
name|rotation3d
parameter_list|()
function_decl|;
name|void
name|rotation3dArbitraryAxis_data
parameter_list|()
function_decl|;
name|void
name|rotation3dArbitraryAxis
parameter_list|()
function_decl|;
private|private:
name|QString
name|toString
parameter_list|(
name|QTransform
specifier|const
modifier|&
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|transform2D
specifier|static
name|QTransform
name|transform2D
parameter_list|(
specifier|const
name|QGraphicsTransform
modifier|&
name|t
parameter_list|)
block|{
name|QMatrix4x4
name|m
decl_stmt|;
name|t
operator|.
name|applyTo
argument_list|(
operator|&
name|m
argument_list|)
expr_stmt|;
return|return
name|m
operator|.
name|toTransform
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|scale
name|void
name|tst_QGraphicsTransform
operator|::
name|scale
parameter_list|()
block|{
name|QGraphicsScale
name|scale
decl_stmt|;
comment|// check initial conditions
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|xScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|yScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|zScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|origin
argument_list|()
argument_list|,
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|scale
operator|.
name|setOrigin
argument_list|(
name|QVector3D
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|xScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|yScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|zScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|origin
argument_list|()
argument_list|,
name|QVector3D
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QMatrix4x4
name|t
decl_stmt|;
name|scale
operator|.
name|applyTo
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t
argument_list|,
name|QMatrix4x4
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|transform2D
argument_list|(
name|scale
argument_list|)
argument_list|,
name|QTransform
argument_list|()
argument_list|)
expr_stmt|;
name|scale
operator|.
name|setXScale
argument_list|(
literal|10
argument_list|)
expr_stmt|;
name|scale
operator|.
name|setOrigin
argument_list|(
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|xScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|yScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|zScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|origin
argument_list|()
argument_list|,
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTransform
name|res
decl_stmt|;
name|res
operator|.
name|scale
argument_list|(
literal|10
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|transform2D
argument_list|(
name|scale
argument_list|)
argument_list|,
name|res
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|transform2D
argument_list|(
name|scale
argument_list|)
operator|.
name|map
argument_list|(
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|100
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|scale
operator|.
name|setOrigin
argument_list|(
name|QVector3D
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|transform2D
argument_list|(
name|scale
argument_list|)
operator|.
name|map
argument_list|(
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|transform2D
argument_list|(
name|scale
argument_list|)
operator|.
name|map
argument_list|(
name|QPointF
argument_list|(
literal|11
argument_list|,
literal|10
argument_list|)
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|scale
operator|.
name|setYScale
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|scale
operator|.
name|setZScale
argument_list|(
literal|4.5
argument_list|)
expr_stmt|;
name|scale
operator|.
name|setOrigin
argument_list|(
name|QVector3D
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|xScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|yScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|zScale
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|4.5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scale
operator|.
name|origin
argument_list|()
argument_list|,
name|QVector3D
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|QMatrix4x4
name|t2
decl_stmt|;
name|scale
operator|.
name|applyTo
argument_list|(
operator|&
name|t2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t2
operator|.
name|map
argument_list|(
name|QVector3D
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|)
argument_list|)
argument_list|,
name|QVector3D
argument_list|(
literal|31
argument_list|,
literal|8
argument_list|,
literal|16.5
argument_list|)
argument_list|)
expr_stmt|;
comment|// Because the origin has a non-zero z, mapping (4, 5) in 2D
comment|// will introduce a projective component into the result.
name|QTransform
name|t3
init|=
name|t2
operator|.
name|toTransform
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|t3
operator|.
name|map
argument_list|(
name|QPointF
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|)
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|31
operator|/
name|t3
operator|.
name|m33
argument_list|()
argument_list|,
literal|8
operator|/
name|t3
operator|.
name|m33
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// fuzzyCompareNonZero is a very slightly looser version of qFuzzyCompare
end_comment
begin_comment
comment|// for use with values that are not very close to zero
end_comment
begin_function
DECL|function|fuzzyCompareNonZero
name|Q_DECL_CONSTEXPR
specifier|static
specifier|inline
name|bool
name|fuzzyCompareNonZero
parameter_list|(
name|float
name|p1
parameter_list|,
name|float
name|p2
parameter_list|)
block|{
return|return
operator|(
name|qAbs
argument_list|(
name|p1
operator|-
name|p2
argument_list|)
operator|<=
literal|0.00003f
operator|*
name|qMin
argument_list|(
name|qAbs
argument_list|(
name|p1
argument_list|)
argument_list|,
name|qAbs
argument_list|(
name|p2
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function
begin_comment
comment|// This is a more tolerant version of qFuzzyCompare that also handles the case
end_comment
begin_comment
comment|// where one or more of the values being compare are close to zero
end_comment
begin_function
DECL|function|fuzzyCompare
specifier|static
specifier|inline
name|bool
name|fuzzyCompare
parameter_list|(
name|float
name|p1
parameter_list|,
name|float
name|p2
parameter_list|)
block|{
if|if
condition|(
name|qFuzzyIsNull
argument_list|(
name|p1
argument_list|)
condition|)
return|return
name|qFuzzyIsNull
argument_list|(
name|p2
argument_list|)
return|;
elseif|else
if|if
condition|(
name|qFuzzyIsNull
argument_list|(
name|p2
argument_list|)
condition|)
return|return
literal|false
return|;
else|else
return|return
name|fuzzyCompareNonZero
argument_list|(
name|p1
argument_list|,
name|p2
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// This compares two QTransforms by casting the elements to float. This is
end_comment
begin_comment
comment|// necessary here because in this test one of the transforms is created from
end_comment
begin_comment
comment|// a QMatrix4x4 which uses float storage.
end_comment
begin_function
DECL|function|fuzzyCompareAsFloat
specifier|static
name|bool
name|fuzzyCompareAsFloat
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|t1
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|t2
parameter_list|)
block|{
return|return
name|fuzzyCompare
argument_list|(
name|float
argument_list|(
name|t1
operator|.
name|m11
argument_list|()
argument_list|)
argument_list|,
name|float
argument_list|(
name|t2
operator|.
name|m11
argument_list|()
argument_list|)
argument_list|)
operator|&&
name|fuzzyCompare
argument_list|(
name|float
argument_list|(
name|t1
operator|.
name|m12
argument_list|()
argument_list|)
argument_list|,
name|float
argument_list|(
name|t2
operator|.
name|m12
argument_list|()
argument_list|)
argument_list|)
operator|&&
name|fuzzyCompare
argument_list|(
name|float
argument_list|(
name|t1
operator|.
name|m13
argument_list|()
argument_list|)
argument_list|,
name|float
argument_list|(
name|t2
operator|.
name|m13
argument_list|()
argument_list|)
argument_list|)
operator|&&
name|fuzzyCompare
argument_list|(
name|float
argument_list|(
name|t1
operator|.
name|m21
argument_list|()
argument_list|)
argument_list|,
name|float
argument_list|(
name|t2
operator|.
name|m21
argument_list|()
argument_list|)
argument_list|)
operator|&&
name|fuzzyCompare
argument_list|(
name|float
argument_list|(
name|t1
operator|.
name|m22
argument_list|()
argument_list|)
argument_list|,
name|float
argument_list|(
name|t2
operator|.
name|m22
argument_list|()
argument_list|)
argument_list|)
operator|&&
name|fuzzyCompare
argument_list|(
name|float
argument_list|(
name|t1
operator|.
name|m23
argument_list|()
argument_list|)
argument_list|,
name|float
argument_list|(
name|t2
operator|.
name|m23
argument_list|()
argument_list|)
argument_list|)
operator|&&
name|fuzzyCompare
argument_list|(
name|float
argument_list|(
name|t1
operator|.
name|m31
argument_list|()
argument_list|)
argument_list|,
name|float
argument_list|(
name|t2
operator|.
name|m31
argument_list|()
argument_list|)
argument_list|)
operator|&&
name|fuzzyCompare
argument_list|(
name|float
argument_list|(
name|t1
operator|.
name|m32
argument_list|()
argument_list|)
argument_list|,
name|float
argument_list|(
name|t2
operator|.
name|m32
argument_list|()
argument_list|)
argument_list|)
operator|&&
name|fuzzyCompare
argument_list|(
name|float
argument_list|(
name|t1
operator|.
name|m33
argument_list|()
argument_list|)
argument_list|,
name|float
argument_list|(
name|t2
operator|.
name|m33
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fuzzyCompare
specifier|static
specifier|inline
name|bool
name|fuzzyCompare
parameter_list|(
specifier|const
name|QMatrix4x4
modifier|&
name|m1
parameter_list|,
specifier|const
name|QMatrix4x4
modifier|&
name|m2
parameter_list|)
block|{
name|bool
name|ok
init|=
literal|true
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
literal|4
condition|;
operator|++
name|y
control|)
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
literal|4
condition|;
operator|++
name|x
control|)
name|ok
operator|&=
name|fuzzyCompare
argument_list|(
name|m1
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
argument_list|,
name|m2
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ok
return|;
block|}
end_function
begin_function
DECL|function|rotation
name|void
name|tst_QGraphicsTransform
operator|::
name|rotation
parameter_list|()
block|{
name|QGraphicsRotation
name|rotation
decl_stmt|;
name|QCOMPARE
argument_list|(
name|rotation
operator|.
name|axis
argument_list|()
argument_list|,
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rotation
operator|.
name|origin
argument_list|()
argument_list|,
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rotation
operator|.
name|angle
argument_list|()
argument_list|,
operator|(
name|qreal
operator|)
literal|0
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setOrigin
argument_list|(
name|QVector3D
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rotation
operator|.
name|axis
argument_list|()
argument_list|,
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rotation
operator|.
name|origin
argument_list|()
argument_list|,
name|QVector3D
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rotation
operator|.
name|angle
argument_list|()
argument_list|,
operator|(
name|qreal
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QMatrix4x4
name|t
decl_stmt|;
name|rotation
operator|.
name|applyTo
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|t
argument_list|,
name|QMatrix4x4
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|transform2D
argument_list|(
name|rotation
argument_list|)
argument_list|,
name|QTransform
argument_list|()
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setAngle
argument_list|(
literal|40
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setOrigin
argument_list|(
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rotation
operator|.
name|axis
argument_list|()
argument_list|,
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rotation
operator|.
name|origin
argument_list|()
argument_list|,
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rotation
operator|.
name|angle
argument_list|()
argument_list|,
operator|(
name|qreal
operator|)
literal|40
argument_list|)
expr_stmt|;
name|QTransform
name|res
decl_stmt|;
name|res
operator|.
name|rotate
argument_list|(
literal|40
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fuzzyCompareAsFloat
argument_list|(
name|transform2D
argument_list|(
name|rotation
argument_list|)
argument_list|,
name|res
argument_list|)
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setOrigin
argument_list|(
name|QVector3D
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setAngle
argument_list|(
literal|90
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|transform2D
argument_list|(
name|rotation
argument_list|)
operator|.
name|map
argument_list|(
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|transform2D
argument_list|(
name|rotation
argument_list|)
operator|.
name|map
argument_list|(
name|QPointF
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|)
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setOrigin
argument_list|(
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setAngle
argument_list|(
name|qQNaN
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|transform2D
argument_list|(
name|rotation
argument_list|)
operator|.
name|map
argument_list|(
name|QPointF
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|)
argument_list|)
argument_list|,
name|QPointF
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
DECL|variable|Axis
name|Q_DECLARE_METATYPE
argument_list|(
name|Qt
operator|::
name|Axis
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|rotation3d_data
name|void
name|tst_QGraphicsTransform
operator|::
name|rotation3d_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|Axis
argument_list|>
argument_list|(
literal|"axis"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"angle"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|angle
init|=
literal|0
init|;
name|angle
operator|<=
literal|360
condition|;
name|angle
operator|++
control|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test rotation on X"
argument_list|)
operator|<<
name|Qt
operator|::
name|XAxis
operator|<<
name|qreal
argument_list|(
name|angle
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test rotation on Y"
argument_list|)
operator|<<
name|Qt
operator|::
name|YAxis
operator|<<
name|qreal
argument_list|(
name|angle
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"test rotation on Z"
argument_list|)
operator|<<
name|Qt
operator|::
name|ZAxis
operator|<<
name|qreal
argument_list|(
name|angle
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|rotation3d
name|void
name|tst_QGraphicsTransform
operator|::
name|rotation3d
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|Qt
operator|::
name|Axis
argument_list|,
name|axis
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|angle
argument_list|)
expr_stmt|;
name|QGraphicsRotation
name|rotation
decl_stmt|;
name|rotation
operator|.
name|setAxis
argument_list|(
name|axis
argument_list|)
expr_stmt|;
name|QMatrix4x4
name|t
decl_stmt|;
name|rotation
operator|.
name|applyTo
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t
operator|.
name|isIdentity
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|transform2D
argument_list|(
name|rotation
argument_list|)
operator|.
name|isIdentity
argument_list|()
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setAngle
argument_list|(
name|angle
argument_list|)
expr_stmt|;
comment|// QGraphicsRotation uses a correct mathematical rotation in 3D.
comment|// QTransform's Qt::YAxis rotation is inverted from the mathematical
comment|// version of rotation.  We correct for that here.
name|QTransform
name|expected
decl_stmt|;
if|if
condition|(
name|axis
operator|==
name|Qt
operator|::
name|YAxis
operator|&&
name|angle
operator|!=
literal|180.
condition|)
name|expected
operator|.
name|rotate
argument_list|(
operator|-
name|angle
argument_list|,
name|axis
argument_list|)
expr_stmt|;
else|else
name|expected
operator|.
name|rotate
argument_list|(
name|angle
argument_list|,
name|axis
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|fuzzyCompareAsFloat
argument_list|(
name|transform2D
argument_list|(
name|rotation
argument_list|)
argument_list|,
name|expected
argument_list|)
argument_list|)
expr_stmt|;
comment|// Check that "rotation" produces the 4x4 form of the 3x3 matrix.
comment|// i.e. third row and column are 0 0 1 0.
name|t
operator|.
name|setToIdentity
argument_list|()
expr_stmt|;
name|rotation
operator|.
name|applyTo
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|QMatrix4x4
name|r
argument_list|(
name|expected
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|fuzzyCompare
argument_list|(
name|t
argument_list|,
name|r
argument_list|)
argument_list|)
expr_stmt|;
comment|//now let's check that a null vector will not change the transform
name|rotation
operator|.
name|setAxis
argument_list|(
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setOrigin
argument_list|(
name|QVector3D
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|t
operator|.
name|setToIdentity
argument_list|()
expr_stmt|;
name|rotation
operator|.
name|applyTo
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t
operator|.
name|isIdentity
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|transform2D
argument_list|(
name|rotation
argument_list|)
operator|.
name|isIdentity
argument_list|()
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setAngle
argument_list|(
name|angle
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t
operator|.
name|isIdentity
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|transform2D
argument_list|(
name|rotation
argument_list|)
operator|.
name|isIdentity
argument_list|()
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setOrigin
argument_list|(
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t
operator|.
name|isIdentity
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|transform2D
argument_list|(
name|rotation
argument_list|)
operator|.
name|isIdentity
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|labelForTest
name|QByteArray
name|labelForTest
parameter_list|(
name|QVector3D
specifier|const
modifier|&
name|axis
parameter_list|,
name|int
name|angle
parameter_list|)
block|{
return|return
name|QString
argument_list|(
literal|"rotation of %1 on (%2, %3, %4)"
argument_list|)
operator|.
name|arg
argument_list|(
name|angle
argument_list|)
operator|.
name|arg
argument_list|(
name|axis
operator|.
name|x
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|axis
operator|.
name|y
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|axis
operator|.
name|z
argument_list|()
argument_list|)
operator|.
name|toLatin1
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|rotation3dArbitraryAxis_data
name|void
name|tst_QGraphicsTransform
operator|::
name|rotation3dArbitraryAxis_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVector3D
argument_list|>
argument_list|(
literal|"axis"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"angle"
argument_list|)
expr_stmt|;
name|QVector3D
name|axis1
init|=
name|QVector3D
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
decl_stmt|;
name|QVector3D
name|axis2
init|=
name|QVector3D
argument_list|(
literal|2.0f
argument_list|,
operator|-
literal|3.0f
argument_list|,
literal|0.5f
argument_list|)
decl_stmt|;
name|QVector3D
name|axis3
init|=
name|QVector3D
argument_list|(
operator|-
literal|2.0f
argument_list|,
literal|0.0f
argument_list|,
operator|-
literal|0.5f
argument_list|)
decl_stmt|;
name|QVector3D
name|axis4
init|=
name|QVector3D
argument_list|(
literal|0.0001f
argument_list|,
literal|0.0001f
argument_list|,
literal|0.0001f
argument_list|)
decl_stmt|;
name|QVector3D
name|axis5
init|=
name|QVector3D
argument_list|(
literal|0.01f
argument_list|,
literal|0.01f
argument_list|,
literal|0.01f
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|angle
init|=
literal|0
init|;
name|angle
operator|<=
literal|360
condition|;
name|angle
operator|++
control|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
name|labelForTest
argument_list|(
name|axis1
argument_list|,
name|angle
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
name|axis1
operator|<<
name|qreal
argument_list|(
name|angle
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|labelForTest
argument_list|(
name|axis2
argument_list|,
name|angle
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
name|axis2
operator|<<
name|qreal
argument_list|(
name|angle
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|labelForTest
argument_list|(
name|axis3
argument_list|,
name|angle
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
name|axis3
operator|<<
name|qreal
argument_list|(
name|angle
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|labelForTest
argument_list|(
name|axis4
argument_list|,
name|angle
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
name|axis4
operator|<<
name|qreal
argument_list|(
name|angle
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
name|labelForTest
argument_list|(
name|axis5
argument_list|,
name|angle
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
operator|<<
name|axis5
operator|<<
name|qreal
argument_list|(
name|angle
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|rotation3dArbitraryAxis
name|void
name|tst_QGraphicsTransform
operator|::
name|rotation3dArbitraryAxis
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QVector3D
argument_list|,
name|axis
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|angle
argument_list|)
expr_stmt|;
name|QGraphicsRotation
name|rotation
decl_stmt|;
name|rotation
operator|.
name|setAxis
argument_list|(
name|axis
argument_list|)
expr_stmt|;
name|QMatrix4x4
name|t
decl_stmt|;
name|rotation
operator|.
name|applyTo
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|t
operator|.
name|isIdentity
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|transform2D
argument_list|(
name|rotation
argument_list|)
operator|.
name|isIdentity
argument_list|()
argument_list|)
expr_stmt|;
name|rotation
operator|.
name|setAngle
argument_list|(
name|angle
argument_list|)
expr_stmt|;
comment|// Compute the expected answer using QMatrix4x4 and a projection.
comment|// These two steps are performed in one hit by QGraphicsRotation.
name|QMatrix4x4
name|exp
decl_stmt|;
name|exp
operator|.
name|rotate
argument_list|(
name|angle
argument_list|,
name|axis
argument_list|)
expr_stmt|;
name|QTransform
name|expected
init|=
name|exp
operator|.
name|toTransform
argument_list|(
literal|1024.0f
argument_list|)
decl_stmt|;
name|QTransform
name|actual
init|=
name|transform2D
argument_list|(
name|rotation
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
name|fuzzyCompareAsFloat
argument_list|(
name|actual
argument_list|,
name|expected
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|QString
argument_list|(
literal|"\nactual:   %1\n"
literal|"expected: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|toString
argument_list|(
name|actual
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|toString
argument_list|(
name|expected
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// Check that "rotation" produces the 4x4 form of the 3x3 matrix.
comment|// i.e. third row and column are 0 0 1 0.
name|t
operator|.
name|setToIdentity
argument_list|()
expr_stmt|;
name|rotation
operator|.
name|applyTo
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|QMatrix4x4
name|r
argument_list|(
name|expected
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
literal|4
condition|;
operator|++
name|row
control|)
block|{
for|for
control|(
name|int
name|col
init|=
literal|0
init|;
name|col
operator|<
literal|4
condition|;
operator|++
name|col
control|)
block|{
name|float
name|a
init|=
name|t
argument_list|(
name|row
argument_list|,
name|col
argument_list|)
decl_stmt|;
name|float
name|b
init|=
name|r
argument_list|(
name|row
argument_list|,
name|col
argument_list|)
decl_stmt|;
name|QVERIFY2
argument_list|(
name|fuzzyCompare
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"%1 is not equal to %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|a
argument_list|)
operator|.
name|arg
argument_list|(
name|b
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|toString
name|QString
name|tst_QGraphicsTransform
operator|::
name|toString
parameter_list|(
name|QTransform
specifier|const
modifier|&
name|t
parameter_list|)
block|{
return|return
name|QString
argument_list|(
literal|"[ [ %1  %2   %3 ]; [ %4  %5  %6 ]; [ %7  %8  %9 ] ]"
argument_list|)
operator|.
name|arg
argument_list|(
name|t
operator|.
name|m11
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|t
operator|.
name|m12
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|t
operator|.
name|m13
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|t
operator|.
name|m21
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|t
operator|.
name|m22
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|t
operator|.
name|m23
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|t
operator|.
name|m31
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|t
operator|.
name|m32
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|t
operator|.
name|m33
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGraphicsTransform
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgraphicstransform.moc"
end_include
end_unit
