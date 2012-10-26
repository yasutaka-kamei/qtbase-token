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
file|<QtWidgets/qgraphicsscene.h>
end_include
begin_include
include|#
directive|include
file|<private/qgraphicsscenebsptreeindex_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qgraphicssceneindex_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qgraphicsscenelinearindex_p.h>
end_include
begin_class
DECL|class|tst_QGraphicsSceneIndex
class|class
name|tst_QGraphicsSceneIndex
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|scatteredItems_data
parameter_list|()
function_decl|;
name|void
name|scatteredItems
parameter_list|()
function_decl|;
name|void
name|overlappedItems_data
parameter_list|()
function_decl|;
name|void
name|overlappedItems
parameter_list|()
function_decl|;
name|void
name|movingItems_data
parameter_list|()
function_decl|;
name|void
name|movingItems
parameter_list|()
function_decl|;
name|void
name|connectedToSceneRectChanged
parameter_list|()
function_decl|;
name|void
name|items
parameter_list|()
function_decl|;
name|void
name|removeItems
parameter_list|()
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
private|private:
name|void
name|common_data
parameter_list|()
function_decl|;
name|QGraphicsSceneIndex
modifier|*
name|createIndex
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|common_data
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|common_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"indexMethod"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"BSP"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"bsp"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Linear"
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"linear"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createIndex
name|QGraphicsSceneIndex
modifier|*
name|tst_QGraphicsSceneIndex
operator|::
name|createIndex
parameter_list|(
specifier|const
name|QString
modifier|&
name|indexMethod
parameter_list|)
block|{
name|QGraphicsSceneIndex
modifier|*
name|index
init|=
literal|0
decl_stmt|;
name|QGraphicsScene
modifier|*
name|scene
init|=
operator|new
name|QGraphicsScene
argument_list|()
decl_stmt|;
if|if
condition|(
name|indexMethod
operator|==
literal|"bsp"
condition|)
name|index
operator|=
operator|new
name|QGraphicsSceneBspTreeIndex
argument_list|(
name|scene
argument_list|)
expr_stmt|;
if|if
condition|(
name|indexMethod
operator|==
literal|"linear"
condition|)
name|index
operator|=
operator|new
name|QGraphicsSceneLinearIndex
argument_list|(
name|scene
argument_list|)
expr_stmt|;
return|return
name|index
return|;
block|}
end_function
begin_function
DECL|function|scatteredItems_data
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|scatteredItems_data
parameter_list|()
block|{
name|common_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scatteredItems
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|scatteredItems
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|indexMethod
argument_list|)
expr_stmt|;
name|QGraphicsScene
name|scene
decl_stmt|;
name|scene
operator|.
name|setItemIndexMethod
argument_list|(
name|indexMethod
operator|==
literal|"linear"
condition|?
name|QGraphicsScene
operator|::
name|NoIndex
else|:
name|QGraphicsScene
operator|::
name|BspTreeIndex
argument_list|)
expr_stmt|;
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
name|scene
operator|.
name|addRect
argument_list|(
name|i
operator|*
literal|50
argument_list|,
name|i
operator|*
literal|50
argument_list|,
literal|40
argument_list|,
literal|35
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|55
argument_list|,
literal|55
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1000
argument_list|,
literal|1000
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|1000
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|overlappedItems_data
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|overlappedItems_data
parameter_list|()
block|{
name|common_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|overlappedItems
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|overlappedItems
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|indexMethod
argument_list|)
expr_stmt|;
name|QGraphicsScene
name|scene
decl_stmt|;
name|scene
operator|.
name|setItemIndexMethod
argument_list|(
name|indexMethod
operator|==
literal|"linear"
condition|?
name|QGraphicsScene
operator|::
name|NoIndex
else|:
name|QGraphicsScene
operator|::
name|BspTreeIndex
argument_list|)
expr_stmt|;
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
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
literal|10
condition|;
operator|++
name|j
control|)
name|scene
operator|.
name|addRect
argument_list|(
name|i
operator|*
literal|50
argument_list|,
name|j
operator|*
literal|50
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|55
argument_list|,
literal|55
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|105
argument_list|,
literal|105
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|9
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|100
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1000
argument_list|,
literal|1000
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
operator|-
literal|100
argument_list|,
operator|-
literal|1000
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
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
operator|.
name|count
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|100
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1000
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|10
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|movingItems_data
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|movingItems_data
parameter_list|()
block|{
name|common_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|movingItems
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|movingItems
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|indexMethod
argument_list|)
expr_stmt|;
name|QGraphicsScene
name|scene
decl_stmt|;
name|scene
operator|.
name|setItemIndexMethod
argument_list|(
name|indexMethod
operator|==
literal|"linear"
condition|?
name|QGraphicsScene
operator|::
name|NoIndex
else|:
name|QGraphicsScene
operator|::
name|BspTreeIndex
argument_list|)
expr_stmt|;
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
name|scene
operator|.
name|addRect
argument_list|(
name|i
operator|*
literal|50
argument_list|,
name|i
operator|*
literal|50
argument_list|,
literal|40
argument_list|,
literal|35
argument_list|)
expr_stmt|;
name|QGraphicsRectItem
modifier|*
name|box
init|=
name|scene
operator|.
name|addRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|box
operator|->
name|setPos
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|9
argument_list|,
literal|9
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
literal|15
argument_list|,
literal|15
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|box
operator|->
name|setPos
argument_list|(
operator|-
literal|5
argument_list|,
operator|-
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QPointF
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|(
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1000
argument_list|,
literal|1000
argument_list|)
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
literal|11
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|connectedToSceneRectChanged
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|connectedToSceneRectChanged
parameter_list|()
block|{
class|class
name|MyScene
super|:
specifier|public
name|QGraphicsScene
block|{
public|public:
using|using
name|QGraphicsScene
operator|::
name|receivers
using|;
block|}
class|;
name|MyScene
name|scene
decl_stmt|;
comment|// Uses QGraphicsSceneBspTreeIndex by default.
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|receivers
argument_list|(
name|SIGNAL
argument_list|(
name|sceneRectChanged
argument_list|(
name|QRectF
argument_list|)
argument_list|)
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|scene
operator|.
name|setItemIndexMethod
argument_list|(
name|QGraphicsScene
operator|::
name|NoIndex
argument_list|)
expr_stmt|;
comment|// QGraphicsSceneLinearIndex
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|receivers
argument_list|(
name|SIGNAL
argument_list|(
name|sceneRectChanged
argument_list|(
name|QRectF
argument_list|)
argument_list|)
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|items
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|items
parameter_list|()
block|{
name|QGraphicsScene
name|scene
decl_stmt|;
name|QGraphicsItem
modifier|*
name|item1
init|=
name|scene
operator|.
name|addRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QGraphicsItem
modifier|*
name|item2
init|=
name|scene
operator|.
name|addRect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// Move from unindexed items into bsp tree.
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// Add untransformable item.
name|QGraphicsItem
modifier|*
name|item3
init|=
operator|new
name|QGraphicsRectItem
argument_list|(
name|QRectF
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
decl_stmt|;
name|item3
operator|->
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIgnoresTransformations
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|item3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// Move from unindexed items into untransformable items.
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// Move from untransformable items into unindexed items.
name|item3
operator|->
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIgnoresTransformations
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// Make all items untransformable.
name|item1
operator|->
name|setFlag
argument_list|(
name|QGraphicsItem
operator|::
name|ItemIgnoresTransformations
argument_list|)
expr_stmt|;
name|item2
operator|->
name|setParentItem
argument_list|(
name|item1
argument_list|)
expr_stmt|;
name|item3
operator|->
name|setParentItem
argument_list|(
name|item2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// Move from unindexed items into untransformable items.
name|QTest
operator|::
name|qWait
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|scene
operator|.
name|items
argument_list|()
operator|.
name|size
argument_list|()
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|RectWidget
class|class
name|RectWidget
super|:
specifier|public
name|QGraphicsWidget
block|{
name|Q_OBJECT
public|public:
DECL|function|RectWidget
name|RectWidget
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QGraphicsWidget
argument_list|(
name|parent
argument_list|)
block|{     }
DECL|function|paint
name|void
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
comment|/* option */
parameter_list|,
name|QWidget
modifier|*
comment|/* widget */
parameter_list|)
block|{
name|painter
operator|->
name|setBrush
argument_list|(
name|brush
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRect
argument_list|(
name|boundingRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
public|public:
DECL|member|brush
name|QBrush
name|brush
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|removeItems
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|removeItems
parameter_list|()
block|{
name|QGraphicsScene
name|scene
decl_stmt|;
name|RectWidget
modifier|*
name|parent
init|=
operator|new
name|RectWidget
decl_stmt|;
name|parent
operator|->
name|brush
operator|=
name|QBrush
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|magenta
argument_list|)
argument_list|)
expr_stmt|;
name|parent
operator|->
name|setGeometry
argument_list|(
literal|250
argument_list|,
literal|250
argument_list|,
literal|400
argument_list|,
literal|400
argument_list|)
expr_stmt|;
name|RectWidget
modifier|*
name|widget
init|=
operator|new
name|RectWidget
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|widget
operator|->
name|brush
operator|=
name|QBrush
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setGeometry
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|200
argument_list|,
literal|200
argument_list|)
expr_stmt|;
name|RectWidget
modifier|*
name|widgetChild1
init|=
operator|new
name|RectWidget
argument_list|(
name|widget
argument_list|)
decl_stmt|;
name|widgetChild1
operator|->
name|brush
operator|=
name|QBrush
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|green
argument_list|)
argument_list|)
expr_stmt|;
name|widgetChild1
operator|->
name|setGeometry
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|RectWidget
modifier|*
name|widgetChild2
init|=
operator|new
name|RectWidget
argument_list|(
name|widgetChild1
argument_list|)
decl_stmt|;
name|widgetChild2
operator|->
name|brush
operator|=
name|QBrush
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|yellow
argument_list|)
argument_list|)
expr_stmt|;
name|widgetChild2
operator|->
name|setGeometry
argument_list|(
literal|25
argument_list|,
literal|25
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|QGraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
name|view
operator|.
name|resize
argument_list|(
literal|600
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
name|QApplication
operator|::
name|setActiveWindow
argument_list|(
operator|&
name|view
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowActive
argument_list|(
operator|&
name|view
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|.
name|removeItem
argument_list|(
name|widgetChild1
argument_list|)
expr_stmt|;
operator|delete
name|widgetChild1
expr_stmt|;
comment|//We move the parent
name|scene
operator|.
name|items
argument_list|(
literal|295
argument_list|,
literal|295
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
comment|//This should not crash
block|}
end_function
begin_function
DECL|function|clear
name|void
name|tst_QGraphicsSceneIndex
operator|::
name|clear
parameter_list|()
block|{
class|class
name|MyItem
super|:
specifier|public
name|QGraphicsItem
block|{
public|public:
name|MyItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QGraphicsItem
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|numPaints
argument_list|(
literal|0
argument_list|)
block|{}
name|int
name|numPaints
decl_stmt|;
protected|protected:
name|QRectF
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
return|;
block|}
name|void
name|paint
parameter_list|(
name|QPainter
modifier|*
comment|/* painter */
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
parameter_list|,
name|QWidget
modifier|*
parameter_list|)
block|{
operator|++
name|numPaints
expr_stmt|;
block|}
block|}
class|;
name|QGraphicsScene
name|scene
decl_stmt|;
name|scene
operator|.
name|setSceneRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
operator|new
name|MyItem
argument_list|)
expr_stmt|;
name|QGraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|QTest
operator|::
name|qWaitForWindowActive
argument_list|(
operator|&
name|view
argument_list|)
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|setActiveWindow
argument_list|(
operator|&
name|view
argument_list|)
expr_stmt|;
name|scene
operator|.
name|clear
argument_list|()
expr_stmt|;
comment|// Make sure the index is re-generated after QGraphicsScene::clear();
comment|// otherwise no items will be painted.
name|MyItem
modifier|*
name|item
init|=
operator|new
name|MyItem
decl_stmt|;
name|scene
operator|.
name|addItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QTRY_COMPARE
argument_list|(
name|item
operator|->
name|numPaints
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QGraphicsSceneIndex
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qgraphicssceneindex.moc"
end_include
end_unit
