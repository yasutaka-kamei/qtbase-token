begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// This file contains benchmarks for QRect/QRectF functions.
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_class
DECL|class|tst_qrect
class|class
name|tst_qrect
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
comment|// QRect functions:
name|void
name|contains_point_data
parameter_list|()
function_decl|;
name|void
name|contains_point
parameter_list|()
function_decl|;
name|void
name|contains_rect_data
parameter_list|()
function_decl|;
name|void
name|contains_rect
parameter_list|()
function_decl|;
name|void
name|intersects_data
parameter_list|()
function_decl|;
name|void
name|intersects
parameter_list|()
function_decl|;
name|void
name|intersected_data
parameter_list|()
function_decl|;
name|void
name|intersected
parameter_list|()
function_decl|;
name|void
name|united_data
parameter_list|()
function_decl|;
name|void
name|united
parameter_list|()
function_decl|;
comment|// QRectF functions:
name|void
name|contains_point_f_data
parameter_list|()
function_decl|;
name|void
name|contains_point_f
parameter_list|()
function_decl|;
name|void
name|contains_rect_f_data
parameter_list|()
function_decl|;
name|void
name|contains_rect_f
parameter_list|()
function_decl|;
name|void
name|intersects_f_data
parameter_list|()
function_decl|;
name|void
name|intersects_f
parameter_list|()
function_decl|;
name|void
name|intersected_f_data
parameter_list|()
function_decl|;
name|void
name|intersected_f
parameter_list|()
function_decl|;
name|void
name|united_f_data
parameter_list|()
function_decl|;
name|void
name|united_f
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_struct
DECL|struct|RectRectCombination
struct|struct
name|RectRectCombination
block|{
DECL|member|tag
name|QString
name|tag
decl_stmt|;
DECL|member|x1
DECL|member|y1
DECL|member|w1
DECL|member|h1
DECL|member|x2
DECL|member|y2
DECL|member|w2
DECL|member|h2
name|qreal
name|x1
decl_stmt|,
name|y1
decl_stmt|,
name|w1
decl_stmt|,
name|h1
decl_stmt|,
name|x2
decl_stmt|,
name|y2
decl_stmt|,
name|w2
decl_stmt|,
name|h2
decl_stmt|;
DECL|function|RectRectCombination
name|RectRectCombination
parameter_list|(
specifier|const
name|QString
modifier|&
name|tag
parameter_list|,
specifier|const
name|qreal
name|x1
parameter_list|,
specifier|const
name|qreal
name|y1
parameter_list|,
specifier|const
name|qreal
name|w1
parameter_list|,
specifier|const
name|qreal
name|h1
parameter_list|,
specifier|const
name|qreal
name|x2
parameter_list|,
specifier|const
name|qreal
name|y2
parameter_list|,
specifier|const
name|qreal
name|w2
parameter_list|,
specifier|const
name|qreal
name|h2
parameter_list|)
member_init_list|:
name|tag
argument_list|(
name|tag
argument_list|)
member_init_list|,
name|x1
argument_list|(
name|x1
argument_list|)
member_init_list|,
name|y1
argument_list|(
name|y1
argument_list|)
member_init_list|,
name|w1
argument_list|(
name|w1
argument_list|)
member_init_list|,
name|h1
argument_list|(
name|h1
argument_list|)
member_init_list|,
name|x2
argument_list|(
name|x2
argument_list|)
member_init_list|,
name|y2
argument_list|(
name|y2
argument_list|)
member_init_list|,
name|w2
argument_list|(
name|w2
argument_list|)
member_init_list|,
name|h2
argument_list|(
name|h2
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_function
DECL|function|createRectRectCombinations
specifier|static
name|QList
argument_list|<
name|RectRectCombination
argument_list|>
name|createRectRectCombinations
parameter_list|()
block|{
name|QList
argument_list|<
name|RectRectCombination
argument_list|>
name|result
decl_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"null"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
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
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"null1"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"null2"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"miss"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|11
argument_list|,
literal|11
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"intersect"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"contain1"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"contain2"
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"miss_flip1"
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|11
argument_list|,
literal|11
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"intersect_flip1"
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"contain1_flip1"
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"contain2_flip1"
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
operator|-
literal|8
argument_list|,
operator|-
literal|8
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"miss_flip2"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|,
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"intersect_flip2"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|14
argument_list|,
literal|14
argument_list|,
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"contain1_flip2"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
operator|-
literal|8
argument_list|,
operator|-
literal|8
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectRectCombination
argument_list|(
literal|"contain2_flip2"
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|addRectRectData
specifier|static
name|void
name|addRectRectData
parameter_list|(
name|bool
name|includeProperArg
init|=
literal|false
parameter_list|)
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRectF
argument_list|>
argument_list|(
literal|"rf1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRectF
argument_list|>
argument_list|(
literal|"rf2"
argument_list|)
expr_stmt|;
if|if
condition|(
name|includeProperArg
condition|)
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"proper"
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
operator|(
name|includeProperArg
condition|?
literal|2
else|:
literal|1
operator|)
condition|;
operator|++
name|i
control|)
block|{
name|QList
argument_list|<
name|RectRectCombination
argument_list|>
name|combinations
init|=
name|createRectRectCombinations
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|RectRectCombination
name|c
decl|,
name|combinations
control|)
block|{
name|QTestData
modifier|&
name|testData
init|=
name|QTest
operator|::
name|newRow
argument_list|(
name|c
operator|.
name|tag
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|QRectF
name|r1
argument_list|(
name|c
operator|.
name|x1
argument_list|,
name|c
operator|.
name|y1
argument_list|,
name|c
operator|.
name|w1
argument_list|,
name|c
operator|.
name|h1
argument_list|)
decl_stmt|;
name|QRectF
name|r2
argument_list|(
name|c
operator|.
name|x2
argument_list|,
name|c
operator|.
name|y2
argument_list|,
name|c
operator|.
name|w2
argument_list|,
name|c
operator|.
name|h2
argument_list|)
decl_stmt|;
name|testData
operator|<<
name|r1
operator|<<
name|r2
expr_stmt|;
if|if
condition|(
name|includeProperArg
condition|)
name|testData
operator|<<
operator|(
name|i
operator|==
literal|0
operator|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_struct
DECL|struct|RectPointCombination
struct|struct
name|RectPointCombination
block|{
DECL|member|tag
name|QString
name|tag
decl_stmt|;
DECL|member|x
DECL|member|y
DECL|member|w
DECL|member|h
DECL|member|px
DECL|member|py
name|qreal
name|x
decl_stmt|,
name|y
decl_stmt|,
name|w
decl_stmt|,
name|h
decl_stmt|,
name|px
decl_stmt|,
name|py
decl_stmt|;
DECL|function|RectPointCombination
name|RectPointCombination
parameter_list|(
specifier|const
name|QString
modifier|&
name|tag
parameter_list|,
specifier|const
name|qreal
name|x
parameter_list|,
specifier|const
name|qreal
name|y
parameter_list|,
specifier|const
name|qreal
name|w
parameter_list|,
specifier|const
name|qreal
name|h
parameter_list|,
specifier|const
name|qreal
name|px
parameter_list|,
specifier|const
name|qreal
name|py
parameter_list|)
member_init_list|:
name|tag
argument_list|(
name|tag
argument_list|)
member_init_list|,
name|x
argument_list|(
name|x
argument_list|)
member_init_list|,
name|y
argument_list|(
name|y
argument_list|)
member_init_list|,
name|w
argument_list|(
name|w
argument_list|)
member_init_list|,
name|h
argument_list|(
name|h
argument_list|)
member_init_list|,
name|px
argument_list|(
name|px
argument_list|)
member_init_list|,
name|py
argument_list|(
name|py
argument_list|)
block|{}
block|}
struct|;
end_struct
begin_function
DECL|function|createRectPointCombinations
specifier|static
name|QList
argument_list|<
name|RectPointCombination
argument_list|>
name|createRectPointCombinations
parameter_list|()
block|{
name|QList
argument_list|<
name|RectPointCombination
argument_list|>
name|result
decl_stmt|;
name|result
operator|<<
name|RectPointCombination
argument_list|(
literal|"null"
argument_list|,
literal|0
argument_list|,
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
expr_stmt|;
name|result
operator|<<
name|RectPointCombination
argument_list|(
literal|"miss"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectPointCombination
argument_list|(
literal|"contain"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectPointCombination
argument_list|(
literal|"contain_proper"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectPointCombination
argument_list|(
literal|"miss_flip"
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectPointCombination
argument_list|(
literal|"contain_flip"
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|result
operator|<<
name|RectPointCombination
argument_list|(
literal|"contain_flip_proper"
argument_list|,
literal|9
argument_list|,
literal|9
argument_list|,
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|addRectPointData
specifier|static
name|void
name|addRectPointData
parameter_list|(
name|bool
name|includeProperArg
init|=
literal|false
parameter_list|)
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRectF
argument_list|>
argument_list|(
literal|"rf"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPointF
argument_list|>
argument_list|(
literal|"pf"
argument_list|)
expr_stmt|;
if|if
condition|(
name|includeProperArg
condition|)
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"proper"
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
operator|(
name|includeProperArg
condition|?
literal|2
else|:
literal|1
operator|)
condition|;
operator|++
name|i
control|)
block|{
name|QList
argument_list|<
name|RectPointCombination
argument_list|>
name|combinations
init|=
name|createRectPointCombinations
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|RectPointCombination
name|c
decl|,
name|combinations
control|)
block|{
name|QTestData
modifier|&
name|testData
init|=
name|QTest
operator|::
name|newRow
argument_list|(
name|c
operator|.
name|tag
operator|.
name|toLatin1
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|QRectF
name|r
argument_list|(
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
argument_list|,
name|c
operator|.
name|w
argument_list|,
name|c
operator|.
name|h
argument_list|)
decl_stmt|;
name|QPointF
name|p
argument_list|(
name|c
operator|.
name|px
argument_list|,
name|c
operator|.
name|py
argument_list|)
decl_stmt|;
name|testData
operator|<<
name|r
operator|<<
name|p
expr_stmt|;
if|if
condition|(
name|includeProperArg
condition|)
name|testData
operator|<<
operator|(
name|i
operator|==
literal|0
operator|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|contains_point_data
name|void
name|tst_qrect
operator|::
name|contains_point_data
parameter_list|()
block|{
name|addRectPointData
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|contains_point
name|void
name|tst_qrect
operator|::
name|contains_point
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPointF
argument_list|,
name|pf
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|proper
argument_list|)
expr_stmt|;
name|QRect
name|r
argument_list|(
name|rf
operator|.
name|toRect
argument_list|()
argument_list|)
decl_stmt|;
name|QPoint
name|p
argument_list|(
name|pf
operator|.
name|toPoint
argument_list|()
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|r
operator|.
name|contains
argument_list|(
name|p
argument_list|,
name|proper
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|contains_rect_data
name|void
name|tst_qrect
operator|::
name|contains_rect_data
parameter_list|()
block|{
name|addRectRectData
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|contains_rect
name|void
name|tst_qrect
operator|::
name|contains_rect
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|proper
argument_list|)
expr_stmt|;
name|QRect
name|r1
argument_list|(
name|rf1
operator|.
name|toRect
argument_list|()
argument_list|)
decl_stmt|;
name|QRect
name|r2
argument_list|(
name|rf2
operator|.
name|toRect
argument_list|()
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|r1
operator|.
name|contains
argument_list|(
name|r2
argument_list|,
name|proper
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|intersects_data
name|void
name|tst_qrect
operator|::
name|intersects_data
parameter_list|()
block|{
name|addRectRectData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|intersects
name|void
name|tst_qrect
operator|::
name|intersects
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf2
argument_list|)
expr_stmt|;
name|QRect
name|r1
argument_list|(
name|rf1
operator|.
name|toRect
argument_list|()
argument_list|)
decl_stmt|;
name|QRect
name|r2
argument_list|(
name|rf2
operator|.
name|toRect
argument_list|()
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|r1
operator|.
name|intersects
argument_list|(
name|r2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|intersected_data
name|void
name|tst_qrect
operator|::
name|intersected_data
parameter_list|()
block|{
name|addRectRectData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|intersected
name|void
name|tst_qrect
operator|::
name|intersected
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf2
argument_list|)
expr_stmt|;
name|QRect
name|r1
argument_list|(
name|rf1
operator|.
name|toRect
argument_list|()
argument_list|)
decl_stmt|;
name|QRect
name|r2
argument_list|(
name|rf2
operator|.
name|toRect
argument_list|()
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|r1
operator|.
name|intersected
argument_list|(
name|r2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|united_data
name|void
name|tst_qrect
operator|::
name|united_data
parameter_list|()
block|{
name|addRectRectData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|united
name|void
name|tst_qrect
operator|::
name|united
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf2
argument_list|)
expr_stmt|;
name|QRect
name|r1
argument_list|(
name|rf1
operator|.
name|toRect
argument_list|()
argument_list|)
decl_stmt|;
name|QRect
name|r2
argument_list|(
name|rf2
operator|.
name|toRect
argument_list|()
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|r1
operator|.
name|united
argument_list|(
name|r2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|contains_point_f_data
name|void
name|tst_qrect
operator|::
name|contains_point_f_data
parameter_list|()
block|{
name|addRectPointData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|contains_point_f
name|void
name|tst_qrect
operator|::
name|contains_point_f
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPointF
argument_list|,
name|pf
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|rf
operator|.
name|contains
argument_list|(
name|pf
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|contains_rect_f_data
name|void
name|tst_qrect
operator|::
name|contains_rect_f_data
parameter_list|()
block|{
name|addRectRectData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|contains_rect_f
name|void
name|tst_qrect
operator|::
name|contains_rect_f
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf2
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|rf1
operator|.
name|contains
argument_list|(
name|rf2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|intersects_f_data
name|void
name|tst_qrect
operator|::
name|intersects_f_data
parameter_list|()
block|{
name|addRectRectData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|intersects_f
name|void
name|tst_qrect
operator|::
name|intersects_f
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf2
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|rf1
operator|.
name|intersects
argument_list|(
name|rf2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|intersected_f_data
name|void
name|tst_qrect
operator|::
name|intersected_f_data
parameter_list|()
block|{
name|addRectRectData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|intersected_f
name|void
name|tst_qrect
operator|::
name|intersected_f
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf2
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|rf1
operator|.
name|intersected
argument_list|(
name|rf2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|united_f_data
name|void
name|tst_qrect
operator|::
name|united_f_data
parameter_list|()
block|{
name|addRectRectData
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|united_f
name|void
name|tst_qrect
operator|::
name|united_f
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRectF
argument_list|,
name|rf2
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|rf1
operator|.
name|united
argument_list|(
name|rf2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qrect
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
