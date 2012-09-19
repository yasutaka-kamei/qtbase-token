begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|"qbrush.h"
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QBitmap>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_class
DECL|class|tst_QBrush
class|class
name|tst_QBrush
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QBrush
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|operator_eq_eq
parameter_list|()
function_decl|;
name|void
name|operator_eq_eq_data
parameter_list|()
function_decl|;
name|void
name|stream
parameter_list|()
function_decl|;
name|void
name|stream_data
parameter_list|()
function_decl|;
name|void
name|badStyles
parameter_list|()
function_decl|;
name|void
name|testQLinearGradientSetters
parameter_list|()
function_decl|;
name|void
name|testQRadialGradientSetters
parameter_list|()
function_decl|;
name|void
name|testQConicalGradientSetters
parameter_list|()
function_decl|;
name|void
name|testQGradientCopyConstructor
parameter_list|()
function_decl|;
name|void
name|gradientStops
parameter_list|()
function_decl|;
name|void
name|textures
parameter_list|()
function_decl|;
name|void
name|swap
parameter_list|()
function_decl|;
name|void
name|nullBrush
parameter_list|()
function_decl|;
name|void
name|isOpaque
parameter_list|()
function_decl|;
name|void
name|debug
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QBrush
argument_list|)
end_macro
begin_constructor
DECL|function|tst_QBrush
name|tst_QBrush
operator|::
name|tst_QBrush
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|operator_eq_eq_data
name|void
name|tst_QBrush
operator|::
name|operator_eq_eq_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QBrush
argument_list|>
argument_list|(
literal|"brush1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QBrush
argument_list|>
argument_list|(
literal|"brush2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"isEqual"
argument_list|)
expr_stmt|;
name|QLinearGradient
name|lg
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
name|lg
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|lg
operator|.
name|setColorAt
argument_list|(
literal|0.5
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|lg
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"black vs black"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"black vs blue"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"red vs no"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"no vs no"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lg vs same lg"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|lg
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|lg
argument_list|)
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lg vs diff lg"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|lg
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|QLinearGradient
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rad vs con"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|QRadialGradient
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|QConicalGradient
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|<<
literal|false
expr_stmt|;
name|QBrush
name|b1
argument_list|(
name|lg
argument_list|)
decl_stmt|;
name|QBrush
name|b2
argument_list|(
name|lg
argument_list|)
decl_stmt|;
name|b1
operator|.
name|setTransform
argument_list|(
name|QTransform
argument_list|()
operator|.
name|scale
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lg with transform vs same lg"
argument_list|)
operator|<<
name|b1
operator|<<
name|b2
operator|<<
literal|false
expr_stmt|;
name|b2
operator|.
name|setTransform
argument_list|(
name|QTransform
argument_list|()
operator|.
name|scale
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lg w/transform vs same lg w/same transform"
argument_list|)
operator|<<
name|b1
operator|<<
name|b2
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_eq_eq
name|void
name|tst_QBrush
operator|::
name|operator_eq_eq
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QBrush
argument_list|,
name|brush1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QBrush
argument_list|,
name|brush2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|isEqual
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|brush1
operator|==
name|brush2
argument_list|,
name|isEqual
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stream_data
name|void
name|tst_QBrush
operator|::
name|stream_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QBrush
argument_list|>
argument_list|(
literal|"brush"
argument_list|)
expr_stmt|;
name|QLinearGradient
name|lg
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
name|lg
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|lg
operator|.
name|setColorAt
argument_list|(
literal|0.5
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|lg
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"black"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"red"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"no"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lg"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|lg
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rad"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|QRadialGradient
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"con"
argument_list|)
operator|<<
name|QBrush
argument_list|(
name|QConicalGradient
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stream
name|void
name|tst_QBrush
operator|::
name|stream
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QBrush
argument_list|,
name|brush
argument_list|)
expr_stmt|;
name|QByteArray
name|data
decl_stmt|;
block|{
name|QDataStream
name|stream
argument_list|(
operator|&
name|data
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
decl_stmt|;
name|stream
operator|<<
name|brush
expr_stmt|;
block|}
name|QBrush
name|cmp
decl_stmt|;
block|{
name|QDataStream
name|stream
argument_list|(
operator|&
name|data
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
name|stream
operator|>>
name|cmp
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|brush
operator|.
name|style
argument_list|()
argument_list|,
name|cmp
operator|.
name|style
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|brush
operator|.
name|color
argument_list|()
argument_list|,
name|cmp
operator|.
name|color
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|brush
argument_list|,
name|cmp
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testQLinearGradientSetters
name|void
name|tst_QBrush
operator|::
name|testQLinearGradientSetters
parameter_list|()
block|{
name|QLinearGradient
name|lg
decl_stmt|;
name|QCOMPARE
argument_list|(
name|lg
operator|.
name|start
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|lg
operator|.
name|finalStop
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|lg
operator|.
name|setStart
argument_list|(
literal|101
argument_list|,
literal|102
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|lg
operator|.
name|start
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|101
argument_list|,
literal|102
argument_list|)
argument_list|)
expr_stmt|;
name|lg
operator|.
name|setStart
argument_list|(
name|QPointF
argument_list|(
literal|201
argument_list|,
literal|202
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|lg
operator|.
name|start
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|201
argument_list|,
literal|202
argument_list|)
argument_list|)
expr_stmt|;
name|lg
operator|.
name|setFinalStop
argument_list|(
literal|103
argument_list|,
literal|104
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|lg
operator|.
name|finalStop
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|103
argument_list|,
literal|104
argument_list|)
argument_list|)
expr_stmt|;
name|lg
operator|.
name|setFinalStop
argument_list|(
name|QPointF
argument_list|(
literal|203
argument_list|,
literal|204
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|lg
operator|.
name|finalStop
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|203
argument_list|,
literal|204
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testQRadialGradientSetters
name|void
name|tst_QBrush
operator|::
name|testQRadialGradientSetters
parameter_list|()
block|{
name|QRadialGradient
name|rg
decl_stmt|;
name|QCOMPARE
argument_list|(
name|rg
operator|.
name|radius
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|1.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rg
operator|.
name|center
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rg
operator|.
name|focalPoint
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|rg
operator|.
name|setRadius
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rg
operator|.
name|radius
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|100.0
argument_list|)
argument_list|)
expr_stmt|;
name|rg
operator|.
name|setCenter
argument_list|(
literal|101
argument_list|,
literal|102
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rg
operator|.
name|center
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|101
argument_list|,
literal|102
argument_list|)
argument_list|)
expr_stmt|;
name|rg
operator|.
name|setCenter
argument_list|(
name|QPointF
argument_list|(
literal|201
argument_list|,
literal|202
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rg
operator|.
name|center
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|201
argument_list|,
literal|202
argument_list|)
argument_list|)
expr_stmt|;
name|rg
operator|.
name|setFocalPoint
argument_list|(
literal|103
argument_list|,
literal|104
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rg
operator|.
name|focalPoint
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|103
argument_list|,
literal|104
argument_list|)
argument_list|)
expr_stmt|;
name|rg
operator|.
name|setFocalPoint
argument_list|(
name|QPointF
argument_list|(
literal|203
argument_list|,
literal|204
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rg
operator|.
name|focalPoint
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|203
argument_list|,
literal|204
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testQConicalGradientSetters
name|void
name|tst_QBrush
operator|::
name|testQConicalGradientSetters
parameter_list|()
block|{
name|QConicalGradient
name|cg
decl_stmt|;
name|QCOMPARE
argument_list|(
name|cg
operator|.
name|angle
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|0.0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cg
operator|.
name|center
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|cg
operator|.
name|setAngle
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cg
operator|.
name|angle
argument_list|()
argument_list|,
name|qreal
argument_list|(
literal|100.0
argument_list|)
argument_list|)
expr_stmt|;
name|cg
operator|.
name|setCenter
argument_list|(
literal|102
argument_list|,
literal|103
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cg
operator|.
name|center
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|102
argument_list|,
literal|103
argument_list|)
argument_list|)
expr_stmt|;
name|cg
operator|.
name|setCenter
argument_list|(
name|QPointF
argument_list|(
literal|202
argument_list|,
literal|203
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cg
operator|.
name|center
argument_list|()
argument_list|,
name|QPointF
argument_list|(
literal|202
argument_list|,
literal|203
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testQGradientCopyConstructor
name|void
name|tst_QBrush
operator|::
name|testQGradientCopyConstructor
parameter_list|()
block|{
block|{
name|QLinearGradient
name|lg1
argument_list|(
literal|101
argument_list|,
literal|102
argument_list|,
literal|103
argument_list|,
literal|104
argument_list|)
decl_stmt|;
name|QLinearGradient
name|lg2
init|=
name|lg1
decl_stmt|;
name|QCOMPARE
argument_list|(
name|lg1
operator|.
name|start
argument_list|()
argument_list|,
name|lg2
operator|.
name|start
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|lg1
operator|.
name|finalStop
argument_list|()
argument_list|,
name|lg2
operator|.
name|finalStop
argument_list|()
argument_list|)
expr_stmt|;
name|QGradient
name|g
init|=
name|lg1
decl_stmt|;
name|QCOMPARE
argument_list|(
operator|(
operator|(
name|QLinearGradient
operator|*
operator|)
operator|&
name|g
operator|)
operator|->
name|start
argument_list|()
argument_list|,
name|lg1
operator|.
name|start
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
operator|(
name|QLinearGradient
operator|*
operator|)
operator|&
name|g
operator|)
operator|->
name|finalStop
argument_list|()
argument_list|,
name|lg1
operator|.
name|finalStop
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|{
name|QRadialGradient
name|rg1
argument_list|(
literal|101
argument_list|,
literal|102
argument_list|,
literal|103
argument_list|,
literal|104
argument_list|,
literal|105
argument_list|)
decl_stmt|;
name|QRadialGradient
name|rg2
init|=
name|rg1
decl_stmt|;
name|QCOMPARE
argument_list|(
name|rg1
operator|.
name|center
argument_list|()
argument_list|,
name|rg2
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rg1
operator|.
name|focalPoint
argument_list|()
argument_list|,
name|rg2
operator|.
name|focalPoint
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|rg1
operator|.
name|radius
argument_list|()
argument_list|,
name|rg2
operator|.
name|radius
argument_list|()
argument_list|)
expr_stmt|;
name|QGradient
name|g
init|=
name|rg1
decl_stmt|;
name|QCOMPARE
argument_list|(
operator|(
operator|(
name|QRadialGradient
operator|*
operator|)
operator|&
name|g
operator|)
operator|->
name|center
argument_list|()
argument_list|,
name|rg1
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
operator|(
name|QRadialGradient
operator|*
operator|)
operator|&
name|g
operator|)
operator|->
name|focalPoint
argument_list|()
argument_list|,
name|rg1
operator|.
name|focalPoint
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
operator|(
name|QRadialGradient
operator|*
operator|)
operator|&
name|g
operator|)
operator|->
name|radius
argument_list|()
argument_list|,
name|rg1
operator|.
name|radius
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|{
name|QConicalGradient
name|cg1
argument_list|(
literal|101
argument_list|,
literal|102
argument_list|,
literal|103
argument_list|)
decl_stmt|;
name|QConicalGradient
name|cg2
init|=
name|cg1
decl_stmt|;
name|QCOMPARE
argument_list|(
name|cg1
operator|.
name|center
argument_list|()
argument_list|,
name|cg2
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|cg1
operator|.
name|angle
argument_list|()
argument_list|,
name|cg2
operator|.
name|angle
argument_list|()
argument_list|)
expr_stmt|;
name|QGradient
name|g
init|=
name|cg1
decl_stmt|;
name|QCOMPARE
argument_list|(
operator|(
operator|(
name|QConicalGradient
operator|*
operator|)
operator|&
name|g
operator|)
operator|->
name|center
argument_list|()
argument_list|,
name|cg1
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
operator|(
name|QConicalGradient
operator|*
operator|)
operator|&
name|g
operator|)
operator|->
name|angle
argument_list|()
argument_list|,
name|cg1
operator|.
name|angle
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|badStyles
name|void
name|tst_QBrush
operator|::
name|badStyles
parameter_list|()
block|{
comment|// QBrush(Qt::BrushStyle) constructor
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|Qt
operator|::
name|LinearGradientPattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|Qt
operator|::
name|RadialGradientPattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|Qt
operator|::
name|ConicalGradientPattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|Qt
operator|::
name|TexturePattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
comment|// QBrush(QColor, Qt::BrushStyle) constructor
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|Qt
operator|::
name|LinearGradientPattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|Qt
operator|::
name|RadialGradientPattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|Qt
operator|::
name|ConicalGradientPattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|QColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|Qt
operator|::
name|TexturePattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
comment|// QBrush(Qt::GlobalColor, Qt::BrushStyle) constructor
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
name|Qt
operator|::
name|LinearGradientPattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
name|Qt
operator|::
name|RadialGradientPattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
name|Qt
operator|::
name|ConicalGradientPattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|QBrush
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
name|Qt
operator|::
name|TexturePattern
argument_list|)
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
comment|// Set style...
name|QBrush
name|brush
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
decl_stmt|;
name|brush
operator|.
name|setStyle
argument_list|(
name|Qt
operator|::
name|LinearGradientPattern
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|brush
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|SolidPattern
argument_list|)
expr_stmt|;
name|brush
operator|.
name|setStyle
argument_list|(
name|Qt
operator|::
name|RadialGradientPattern
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|brush
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|SolidPattern
argument_list|)
expr_stmt|;
name|brush
operator|.
name|setStyle
argument_list|(
name|Qt
operator|::
name|ConicalGradientPattern
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|brush
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|SolidPattern
argument_list|)
expr_stmt|;
name|brush
operator|.
name|setStyle
argument_list|(
name|Qt
operator|::
name|TexturePattern
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|brush
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|SolidPattern
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|gradientStops
name|void
name|tst_QBrush
operator|::
name|gradientStops
parameter_list|()
block|{
name|QLinearGradient
name|gradient
decl_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QGradientStop
argument_list|(
literal|0
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|,
name|QGradientStop
argument_list|(
literal|1
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|1
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QGradientStop
argument_list|(
literal|0
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|,
name|QGradientStop
argument_list|(
literal|1
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|gradient
operator|.
name|setColorAt
argument_list|(
literal|0.5
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|,
name|QGradientStop
argument_list|(
literal|0.5
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|green
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// A hack in parseStopNode() in qsvghandler.cpp depends on inserting stops at NaN.
name|gradient
operator|.
name|setStops
argument_list|(
name|QGradientStops
argument_list|()
operator|<<
name|QGradientStop
argument_list|(
name|qQNaN
argument_list|()
argument_list|,
name|QColor
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|qIsNaN
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|first
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|gradient
operator|.
name|stops
argument_list|()
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|second
argument_list|,
name|QColor
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fill
name|void
name|fill
parameter_list|(
name|QPaintDevice
modifier|*
name|pd
parameter_list|)
block|{
name|QPainter
name|p
argument_list|(
name|pd
argument_list|)
decl_stmt|;
name|int
name|w
init|=
name|pd
operator|->
name|width
argument_list|()
decl_stmt|;
name|int
name|h
init|=
name|pd
operator|->
name|height
argument_list|()
decl_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|w
argument_list|,
name|h
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|.
name|fillRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|w
operator|/
literal|3
argument_list|,
name|h
operator|/
literal|3
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|textures
name|void
name|tst_QBrush
operator|::
name|textures
parameter_list|()
block|{
name|QPixmap
name|pixmap_source
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QImage
name|image_source
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|fill
argument_list|(
operator|&
name|pixmap_source
argument_list|)
expr_stmt|;
name|fill
argument_list|(
operator|&
name|image_source
argument_list|)
expr_stmt|;
comment|// Create a pixmap brush and compare its texture and textureImage
comment|// to the expected image
name|QBrush
name|pixmap_brush
decl_stmt|;
name|pixmap_brush
operator|.
name|setTexture
argument_list|(
name|pixmap_source
argument_list|)
expr_stmt|;
name|QImage
name|image
init|=
name|pixmap_brush
operator|.
name|texture
argument_list|()
operator|.
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|image
argument_list|,
name|image_source
argument_list|)
expr_stmt|;
name|image
operator|=
name|pixmap_brush
operator|.
name|textureImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
argument_list|,
name|image_source
argument_list|)
expr_stmt|;
name|pixmap_brush
operator|=
name|QBrush
argument_list|(
name|pixmap_source
argument_list|)
expr_stmt|;
name|image
operator|=
name|pixmap_brush
operator|.
name|texture
argument_list|()
operator|.
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
argument_list|,
name|image_source
argument_list|)
expr_stmt|;
name|image
operator|=
name|pixmap_brush
operator|.
name|textureImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
argument_list|,
name|image_source
argument_list|)
expr_stmt|;
comment|// Create a image brush and compare its texture and textureImage
comment|// to the expected image
name|QBrush
name|image_brush
decl_stmt|;
name|image_brush
operator|.
name|setTextureImage
argument_list|(
name|image_source
argument_list|)
expr_stmt|;
name|image
operator|=
name|image_brush
operator|.
name|texture
argument_list|()
operator|.
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
argument_list|,
name|image_source
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image_brush
operator|.
name|textureImage
argument_list|()
argument_list|,
name|image_source
argument_list|)
expr_stmt|;
name|image_brush
operator|=
name|QBrush
argument_list|(
name|image_source
argument_list|)
expr_stmt|;
name|image
operator|=
name|image_brush
operator|.
name|texture
argument_list|()
operator|.
name|toImage
argument_list|()
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image
argument_list|,
name|image_source
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|image_brush
operator|.
name|textureImage
argument_list|()
argument_list|,
name|image_source
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swap
name|void
name|tst_QBrush
operator|::
name|swap
parameter_list|()
block|{
name|QBrush
name|b1
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
decl_stmt|,
name|b2
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
decl_stmt|;
name|b1
operator|.
name|swap
argument_list|(
name|b2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|b1
operator|.
name|color
argument_list|()
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|b2
operator|.
name|color
argument_list|()
argument_list|,
name|QColor
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nullBrush
name|void
name|tst_QBrush
operator|::
name|nullBrush
parameter_list|()
block|{
name|QBrush
name|brush
argument_list|(
name|QColor
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|Qt
operator|::
name|NoBrush
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|brush
operator|.
name|color
argument_list|()
argument_list|,
name|QColor
argument_list|(
literal|100
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isOpaque
name|void
name|tst_QBrush
operator|::
name|isOpaque
parameter_list|()
block|{
name|QBitmap
name|bm
argument_list|(
literal|8
argument_list|,
literal|8
argument_list|)
decl_stmt|;
name|bm
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|QBrush
name|brush
argument_list|(
name|bm
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|brush
operator|.
name|isOpaque
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|debug
name|void
name|tst_QBrush
operator|::
name|debug
parameter_list|()
block|{
name|QPixmap
name|pixmap_source
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|fill
argument_list|(
operator|&
name|pixmap_source
argument_list|)
expr_stmt|;
name|QBrush
name|pixmap_brush
decl_stmt|;
name|pixmap_brush
operator|.
name|setTexture
argument_list|(
name|pixmap_source
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|pixmap_brush
operator|.
name|style
argument_list|()
argument_list|,
name|Qt
operator|::
name|TexturePattern
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
name|pixmap_brush
expr_stmt|;
comment|// don't crash
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QBrush
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qbrush.moc"
end_include
end_unit
