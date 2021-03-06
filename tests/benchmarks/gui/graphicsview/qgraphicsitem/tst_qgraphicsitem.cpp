begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QGraphicsItem>
end_include
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QGraphicsView>
end_include
begin_class
DECL|class|tst_QGraphicsItem
class|class
name|tst_QGraphicsItem
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QGraphicsItem
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QGraphicsItem
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|setParentItem
parameter_list|()
function_decl|;
name|void
name|setParentItem_deep
parameter_list|()
function_decl|;
name|void
name|setParentItem_deep_reversed
parameter_list|()
function_decl|;
name|void
name|deleteItemWithManyChildren
parameter_list|()
function_decl|;
name|void
name|setPos_data
parameter_list|()
function_decl|;
name|void
name|setPos
parameter_list|()
function_decl|;
name|void
name|setTransform_data
parameter_list|()
function_decl|;
name|void
name|setTransform
parameter_list|()
function_decl|;
name|void
name|rotate
parameter_list|()
function_decl|;
name|void
name|scale
parameter_list|()
function_decl|;
name|void
name|shear
parameter_list|()
function_decl|;
name|void
name|translate
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QGraphicsItem
name|tst_QGraphicsItem
operator|::
name|tst_QGraphicsItem
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QGraphicsItem
name|tst_QGraphicsItem
operator|::
name|~
name|tst_QGraphicsItem
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|processEvents
specifier|static
specifier|inline
name|void
name|processEvents
parameter_list|()
block|{
name|QApplication
operator|::
name|flush
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initTestCase
name|void
name|tst_QGraphicsItem
operator|::
name|initTestCase
parameter_list|()
block|{
name|QApplication
operator|::
name|flush
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|1500
argument_list|)
expr_stmt|;
name|processEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|tst_QGraphicsItem
operator|::
name|init
parameter_list|()
block|{
name|processEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QGraphicsItem
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|setParentItem
name|void
name|tst_QGraphicsItem
operator|::
name|setParentItem
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QGraphicsRectItem
name|rect
decl_stmt|;
name|QGraphicsRectItem
modifier|*
name|childRect
init|=
operator|new
name|QGraphicsRectItem
decl_stmt|;
name|childRect
operator|->
name|setParentItem
argument_list|(
operator|&
name|rect
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setParentItem_deep
name|void
name|tst_QGraphicsItem
operator|::
name|setParentItem_deep
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QGraphicsRectItem
name|rect
decl_stmt|;
name|QGraphicsRectItem
modifier|*
name|lastRect
init|=
operator|&
name|rect
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
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|QGraphicsRectItem
modifier|*
name|childRect
init|=
operator|new
name|QGraphicsRectItem
decl_stmt|;
name|childRect
operator|->
name|setParentItem
argument_list|(
name|lastRect
argument_list|)
expr_stmt|;
name|lastRect
operator|=
name|childRect
expr_stmt|;
block|}
name|QGraphicsItem
modifier|*
name|first
init|=
name|rect
operator|.
name|childItems
argument_list|()
operator|.
name|first
argument_list|()
decl_stmt|;
name|first
operator|->
name|setParentItem
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setParentItem_deep_reversed
name|void
name|tst_QGraphicsItem
operator|::
name|setParentItem_deep_reversed
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QGraphicsRectItem
modifier|*
name|lastRect
init|=
operator|new
name|QGraphicsRectItem
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
literal|100
condition|;
operator|++
name|i
control|)
block|{
name|QGraphicsRectItem
modifier|*
name|parentRect
init|=
operator|new
name|QGraphicsRectItem
decl_stmt|;
name|lastRect
operator|->
name|setParentItem
argument_list|(
name|parentRect
argument_list|)
expr_stmt|;
name|lastRect
operator|=
name|parentRect
expr_stmt|;
block|}
operator|delete
name|lastRect
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|deleteItemWithManyChildren
name|void
name|tst_QGraphicsItem
operator|::
name|deleteItemWithManyChildren
parameter_list|()
block|{
name|QBENCHMARK
block|{
name|QGraphicsRectItem
modifier|*
name|rect
init|=
operator|new
name|QGraphicsRectItem
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
literal|1000
condition|;
operator|++
name|i
control|)
operator|new
name|QGraphicsRectItem
argument_list|(
name|rect
argument_list|)
expr_stmt|;
operator|delete
name|rect
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setPos_data
name|void
name|tst_QGraphicsItem
operator|::
name|setPos_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPointF
argument_list|>
argument_list|(
literal|"pos"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"0, 0"
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"10, 10"
argument_list|)
operator|<<
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"-10, -10"
argument_list|)
operator|<<
name|QPointF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setPos
name|void
name|tst_QGraphicsItem
operator|::
name|setPos
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QPointF
argument_list|,
name|pos
argument_list|)
expr_stmt|;
name|QGraphicsScene
name|scene
decl_stmt|;
name|QGraphicsRectItem
modifier|*
name|rect
init|=
name|scene
operator|.
name|addRect
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
decl_stmt|;
name|processEvents
argument_list|()
expr_stmt|;
name|QBENCHMARK
block|{
name|rect
operator|->
name|setPos
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setTransform_data
name|void
name|tst_QGraphicsItem
operator|::
name|setTransform_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QTransform
argument_list|>
argument_list|(
literal|"transform"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rotate 45z"
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|45
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"scale 2x2"
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|scale
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"translate 100, 100"
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|translate
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rotate 45x 45y 45z"
argument_list|)
operator|<<
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|XAxis
argument_list|)
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|YAxis
argument_list|)
operator|.
name|rotate
argument_list|(
literal|45
argument_list|,
name|Qt
operator|::
name|ZAxis
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setTransform
name|void
name|tst_QGraphicsItem
operator|::
name|setTransform
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QTransform
argument_list|,
name|transform
argument_list|)
expr_stmt|;
name|QGraphicsScene
name|scene
decl_stmt|;
name|QGraphicsRectItem
modifier|*
name|item
init|=
name|scene
operator|.
name|addRect
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
decl_stmt|;
name|processEvents
argument_list|()
expr_stmt|;
name|QBENCHMARK
block|{
name|item
operator|->
name|setTransform
argument_list|(
name|transform
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|rotate
name|void
name|tst_QGraphicsItem
operator|::
name|rotate
parameter_list|()
block|{
name|QGraphicsScene
name|scene
decl_stmt|;
name|QGraphicsItem
modifier|*
name|item
init|=
name|scene
operator|.
name|addRect
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
decl_stmt|;
name|processEvents
argument_list|()
expr_stmt|;
specifier|const
name|QTransform
name|rotate
argument_list|(
name|QTransform
argument_list|()
operator|.
name|rotate
argument_list|(
literal|45
argument_list|)
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|item
operator|->
name|setTransform
argument_list|(
name|rotate
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|scale
name|void
name|tst_QGraphicsItem
operator|::
name|scale
parameter_list|()
block|{
name|QGraphicsScene
name|scene
decl_stmt|;
name|QGraphicsItem
modifier|*
name|item
init|=
name|scene
operator|.
name|addRect
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
decl_stmt|;
name|processEvents
argument_list|()
expr_stmt|;
specifier|const
name|QTransform
name|scale
argument_list|(
name|QTransform
operator|::
name|fromScale
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|item
operator|->
name|setTransform
argument_list|(
name|scale
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|shear
name|void
name|tst_QGraphicsItem
operator|::
name|shear
parameter_list|()
block|{
name|QGraphicsScene
name|scene
decl_stmt|;
name|QGraphicsItem
modifier|*
name|item
init|=
name|scene
operator|.
name|addRect
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
decl_stmt|;
name|processEvents
argument_list|()
expr_stmt|;
specifier|const
name|QTransform
name|shear
init|=
name|QTransform
argument_list|()
operator|.
name|shear
argument_list|(
literal|1.5
argument_list|,
literal|1.5
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|item
operator|->
name|setTransform
argument_list|(
name|shear
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|translate
name|void
name|tst_QGraphicsItem
operator|::
name|translate
parameter_list|()
block|{
name|QGraphicsScene
name|scene
decl_stmt|;
name|QGraphicsItem
modifier|*
name|item
init|=
name|scene
operator|.
name|addRect
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
decl_stmt|;
name|processEvents
argument_list|()
expr_stmt|;
specifier|const
name|QTransform
name|translate
init|=
name|QTransform
operator|::
name|fromTranslate
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|item
operator|->
name|setTransform
argument_list|(
name|translate
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGraphicsItem
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgraphicsitem.moc"
end_include
end_unit
