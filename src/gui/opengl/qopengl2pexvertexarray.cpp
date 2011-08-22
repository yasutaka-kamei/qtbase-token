begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopengl2pexvertexarray_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qbezier_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|clear
name|void
name|QOpenGL2PEXVertexArray
operator|::
name|clear
parameter_list|()
block|{
name|vertexArray
operator|.
name|reset
argument_list|()
expr_stmt|;
name|vertexArrayStops
operator|.
name|reset
argument_list|()
expr_stmt|;
name|boundingRectDirty
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundingRect
name|QOpenGLRect
name|QOpenGL2PEXVertexArray
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|boundingRectDirty
condition|)
return|return
name|QOpenGLRect
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|0.0
argument_list|,
literal|0.0
argument_list|)
return|;
else|else
return|return
name|QOpenGLRect
argument_list|(
name|minX
argument_list|,
name|minY
argument_list|,
name|maxX
argument_list|,
name|maxY
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|addClosingLine
name|void
name|QOpenGL2PEXVertexArray
operator|::
name|addClosingLine
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|QPointF
name|point
argument_list|(
name|vertexArray
operator|.
name|at
argument_list|(
name|index
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|point
operator|!=
name|QPointF
argument_list|(
name|vertexArray
operator|.
name|last
argument_list|()
argument_list|)
condition|)
name|vertexArray
operator|.
name|add
argument_list|(
name|point
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addCentroid
name|void
name|QOpenGL2PEXVertexArray
operator|::
name|addCentroid
parameter_list|(
specifier|const
name|QVectorPath
modifier|&
name|path
parameter_list|,
name|int
name|subPathIndex
parameter_list|)
block|{
specifier|const
name|QPointF
modifier|*
specifier|const
name|points
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|QPointF
operator|*
argument_list|>
argument_list|(
name|path
operator|.
name|points
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QPainterPath
operator|::
name|ElementType
modifier|*
specifier|const
name|elements
init|=
name|path
operator|.
name|elements
argument_list|()
decl_stmt|;
name|QPointF
name|sum
init|=
name|points
index|[
name|subPathIndex
index|]
decl_stmt|;
name|int
name|count
init|=
literal|1
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|subPathIndex
operator|+
literal|1
init|;
name|i
operator|<
name|path
operator|.
name|elementCount
argument_list|()
operator|&&
operator|(
operator|!
name|elements
operator|||
name|elements
index|[
name|i
index|]
operator|!=
name|QPainterPath
operator|::
name|MoveToElement
operator|)
condition|;
operator|++
name|i
control|)
block|{
name|sum
operator|+=
name|points
index|[
name|i
index|]
expr_stmt|;
operator|++
name|count
expr_stmt|;
block|}
specifier|const
name|QPointF
name|centroid
init|=
name|sum
operator|/
name|qreal
argument_list|(
name|count
argument_list|)
decl_stmt|;
name|vertexArray
operator|.
name|add
argument_list|(
name|centroid
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addPath
name|void
name|QOpenGL2PEXVertexArray
operator|::
name|addPath
parameter_list|(
specifier|const
name|QVectorPath
modifier|&
name|path
parameter_list|,
name|GLfloat
name|curveInverseScale
parameter_list|,
name|bool
name|outline
parameter_list|)
block|{
specifier|const
name|QPointF
modifier|*
specifier|const
name|points
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|QPointF
operator|*
argument_list|>
argument_list|(
name|path
operator|.
name|points
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QPainterPath
operator|::
name|ElementType
modifier|*
specifier|const
name|elements
init|=
name|path
operator|.
name|elements
argument_list|()
decl_stmt|;
if|if
condition|(
name|boundingRectDirty
condition|)
block|{
name|minX
operator|=
name|maxX
operator|=
name|points
index|[
literal|0
index|]
operator|.
name|x
argument_list|()
expr_stmt|;
name|minY
operator|=
name|maxY
operator|=
name|points
index|[
literal|0
index|]
operator|.
name|y
argument_list|()
expr_stmt|;
name|boundingRectDirty
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|outline
operator|&&
operator|!
name|path
operator|.
name|isConvex
argument_list|()
condition|)
name|addCentroid
argument_list|(
name|path
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|int
name|lastMoveTo
init|=
name|vertexArray
operator|.
name|size
argument_list|()
decl_stmt|;
name|vertexArray
operator|.
name|add
argument_list|(
name|points
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|// The first element is always a moveTo
do|do
block|{
if|if
condition|(
operator|!
name|elements
condition|)
block|{
comment|//             qDebug("QVectorPath has no elements");
comment|// If the path has a null elements pointer, the elements implicitly
comment|// start with a moveTo (already added) and continue with lineTos:
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|path
operator|.
name|elementCount
argument_list|()
condition|;
operator|++
name|i
control|)
name|lineToArray
argument_list|(
name|points
index|[
name|i
index|]
operator|.
name|x
argument_list|()
argument_list|,
name|points
index|[
name|i
index|]
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
break|break;
block|}
comment|//         qDebug("QVectorPath has element types");
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|path
operator|.
name|elementCount
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
switch|switch
condition|(
name|elements
index|[
name|i
index|]
condition|)
block|{
case|case
name|QPainterPath
operator|::
name|MoveToElement
case|:
if|if
condition|(
operator|!
name|outline
condition|)
name|addClosingLine
argument_list|(
name|lastMoveTo
argument_list|)
expr_stmt|;
comment|//                qDebug("element[%d] is a MoveToElement", i);
name|vertexArrayStops
operator|.
name|add
argument_list|(
name|vertexArray
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|outline
condition|)
block|{
if|if
condition|(
operator|!
name|path
operator|.
name|isConvex
argument_list|()
condition|)
name|addCentroid
argument_list|(
name|path
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|lastMoveTo
operator|=
name|vertexArray
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
name|lineToArray
argument_list|(
name|points
index|[
name|i
index|]
operator|.
name|x
argument_list|()
argument_list|,
name|points
index|[
name|i
index|]
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
comment|// Add the moveTo as a new vertex
break|break;
case|case
name|QPainterPath
operator|::
name|LineToElement
case|:
comment|//                qDebug("element[%d] is a LineToElement", i);
name|lineToArray
argument_list|(
name|points
index|[
name|i
index|]
operator|.
name|x
argument_list|()
argument_list|,
name|points
index|[
name|i
index|]
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QPainterPath
operator|::
name|CurveToElement
case|:
block|{
name|QBezier
name|b
init|=
name|QBezier
operator|::
name|fromPoints
argument_list|(
operator|*
operator|(
operator|(
operator|(
specifier|const
name|QPointF
operator|*
operator|)
name|points
operator|)
operator|+
name|i
operator|-
literal|1
operator|)
argument_list|,
name|points
index|[
name|i
index|]
argument_list|,
name|points
index|[
name|i
operator|+
literal|1
index|]
argument_list|,
name|points
index|[
name|i
operator|+
literal|2
index|]
argument_list|)
decl_stmt|;
name|QRectF
name|bounds
init|=
name|b
operator|.
name|bounds
argument_list|()
decl_stmt|;
comment|// threshold based on same algorithm as in qtriangulatingstroker.cpp
name|int
name|threshold
init|=
name|qMin
argument_list|<
name|float
argument_list|>
argument_list|(
literal|64
argument_list|,
name|qMax
argument_list|(
name|bounds
operator|.
name|width
argument_list|()
argument_list|,
name|bounds
operator|.
name|height
argument_list|()
argument_list|)
operator|*
literal|3.14f
operator|/
operator|(
name|curveInverseScale
operator|*
literal|6
operator|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|threshold
operator|<
literal|3
condition|)
name|threshold
operator|=
literal|3
expr_stmt|;
name|qreal
name|one_over_threshold_minus_1
init|=
name|qreal
argument_list|(
literal|1
argument_list|)
operator|/
operator|(
name|threshold
operator|-
literal|1
operator|)
decl_stmt|;
for|for
control|(
name|int
name|t
init|=
literal|0
init|;
name|t
operator|<
name|threshold
condition|;
operator|++
name|t
control|)
block|{
name|QPointF
name|pt
init|=
name|b
operator|.
name|pointAt
argument_list|(
name|t
operator|*
name|one_over_threshold_minus_1
argument_list|)
decl_stmt|;
name|lineToArray
argument_list|(
name|pt
operator|.
name|x
argument_list|()
argument_list|,
name|pt
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|i
operator|+=
literal|2
expr_stmt|;
break|break;
block|}
default|default:
break|break;
block|}
block|}
block|}
do|while
condition|(
literal|0
condition|)
do|;
if|if
condition|(
operator|!
name|outline
condition|)
name|addClosingLine
argument_list|(
name|lastMoveTo
argument_list|)
expr_stmt|;
name|vertexArrayStops
operator|.
name|add
argument_list|(
name|vertexArray
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lineToArray
name|void
name|QOpenGL2PEXVertexArray
operator|::
name|lineToArray
parameter_list|(
specifier|const
name|GLfloat
name|x
parameter_list|,
specifier|const
name|GLfloat
name|y
parameter_list|)
block|{
name|vertexArray
operator|.
name|add
argument_list|(
name|QOpenGLPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|>
name|maxX
condition|)
name|maxX
operator|=
name|x
expr_stmt|;
elseif|else
if|if
condition|(
name|x
operator|<
name|minX
condition|)
name|minX
operator|=
name|x
expr_stmt|;
if|if
condition|(
name|y
operator|>
name|maxY
condition|)
name|maxY
operator|=
name|y
expr_stmt|;
elseif|else
if|if
condition|(
name|y
operator|<
name|minY
condition|)
name|minY
operator|=
name|y
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
