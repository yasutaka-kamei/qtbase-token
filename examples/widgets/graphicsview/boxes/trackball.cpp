begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the demonstration applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"trackball.h"
end_include
begin_include
include|#
directive|include
file|"scene.h"
end_include
begin_comment
comment|//============================================================================//
end_comment
begin_comment
comment|//                                  TrackBall                                 //
end_comment
begin_comment
comment|//============================================================================//
end_comment
begin_constructor
DECL|function|TrackBall
name|TrackBall
operator|::
name|TrackBall
parameter_list|(
name|TrackMode
name|mode
parameter_list|)
member_init_list|:
name|m_angularVelocity
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_paused
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_pressed
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_mode
argument_list|(
name|mode
argument_list|)
block|{
name|m_axis
operator|=
name|QVector3D
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_rotation
operator|=
name|QQuaternion
argument_list|()
expr_stmt|;
name|m_lastTime
operator|=
name|QTime
operator|::
name|currentTime
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_constructor
DECL|function|TrackBall
name|TrackBall
operator|::
name|TrackBall
parameter_list|(
name|float
name|angularVelocity
parameter_list|,
specifier|const
name|QVector3D
modifier|&
name|axis
parameter_list|,
name|TrackMode
name|mode
parameter_list|)
member_init_list|:
name|m_axis
argument_list|(
name|axis
argument_list|)
member_init_list|,
name|m_angularVelocity
argument_list|(
name|angularVelocity
argument_list|)
member_init_list|,
name|m_paused
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_pressed
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_mode
argument_list|(
name|mode
argument_list|)
block|{
name|m_rotation
operator|=
name|QQuaternion
argument_list|()
expr_stmt|;
name|m_lastTime
operator|=
name|QTime
operator|::
name|currentTime
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|push
name|void
name|TrackBall
operator|::
name|push
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
parameter_list|)
block|{
name|m_rotation
operator|=
name|rotation
argument_list|()
expr_stmt|;
name|m_pressed
operator|=
literal|true
expr_stmt|;
name|m_lastTime
operator|=
name|QTime
operator|::
name|currentTime
argument_list|()
expr_stmt|;
name|m_lastPos
operator|=
name|p
expr_stmt|;
name|m_angularVelocity
operator|=
literal|0.0f
expr_stmt|;
block|}
end_function
begin_function
DECL|function|move
name|void
name|TrackBall
operator|::
name|move
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|transformation
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_pressed
condition|)
return|return;
name|QTime
name|currentTime
init|=
name|QTime
operator|::
name|currentTime
argument_list|()
decl_stmt|;
name|int
name|msecs
init|=
name|m_lastTime
operator|.
name|msecsTo
argument_list|(
name|currentTime
argument_list|)
decl_stmt|;
if|if
condition|(
name|msecs
operator|<=
literal|20
condition|)
return|return;
switch|switch
condition|(
name|m_mode
condition|)
block|{
case|case
name|Plane
case|:
block|{
name|QLineF
name|delta
argument_list|(
name|m_lastPos
argument_list|,
name|p
argument_list|)
decl_stmt|;
name|m_angularVelocity
operator|=
literal|180
operator|*
name|delta
operator|.
name|length
argument_list|()
operator|/
operator|(
name|PI
operator|*
name|msecs
operator|)
expr_stmt|;
name|m_axis
operator|=
name|QVector3D
argument_list|(
operator|-
name|delta
operator|.
name|dy
argument_list|()
argument_list|,
name|delta
operator|.
name|dx
argument_list|()
argument_list|,
literal|0.0f
argument_list|)
operator|.
name|normalized
argument_list|()
expr_stmt|;
name|m_axis
operator|=
name|transformation
operator|.
name|rotatedVector
argument_list|(
name|m_axis
argument_list|)
expr_stmt|;
name|m_rotation
operator|=
name|QQuaternion
operator|::
name|fromAxisAndAngle
argument_list|(
name|m_axis
argument_list|,
literal|180
operator|/
name|PI
operator|*
name|delta
operator|.
name|length
argument_list|()
argument_list|)
operator|*
name|m_rotation
expr_stmt|;
block|}
break|break;
case|case
name|Sphere
case|:
block|{
name|QVector3D
name|lastPos3D
init|=
name|QVector3D
argument_list|(
name|m_lastPos
operator|.
name|x
argument_list|()
argument_list|,
name|m_lastPos
operator|.
name|y
argument_list|()
argument_list|,
literal|0.0f
argument_list|)
decl_stmt|;
name|float
name|sqrZ
init|=
literal|1
operator|-
name|QVector3D
operator|::
name|dotProduct
argument_list|(
name|lastPos3D
argument_list|,
name|lastPos3D
argument_list|)
decl_stmt|;
if|if
condition|(
name|sqrZ
operator|>
literal|0
condition|)
name|lastPos3D
operator|.
name|setZ
argument_list|(
name|sqrt
argument_list|(
name|sqrZ
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|lastPos3D
operator|.
name|normalize
argument_list|()
expr_stmt|;
name|QVector3D
name|currentPos3D
init|=
name|QVector3D
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|,
name|p
operator|.
name|y
argument_list|()
argument_list|,
literal|0.0f
argument_list|)
decl_stmt|;
name|sqrZ
operator|=
literal|1
operator|-
name|QVector3D
operator|::
name|dotProduct
argument_list|(
name|currentPos3D
argument_list|,
name|currentPos3D
argument_list|)
expr_stmt|;
if|if
condition|(
name|sqrZ
operator|>
literal|0
condition|)
name|currentPos3D
operator|.
name|setZ
argument_list|(
name|sqrt
argument_list|(
name|sqrZ
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|currentPos3D
operator|.
name|normalize
argument_list|()
expr_stmt|;
name|m_axis
operator|=
name|QVector3D
operator|::
name|crossProduct
argument_list|(
name|lastPos3D
argument_list|,
name|currentPos3D
argument_list|)
expr_stmt|;
name|float
name|angle
init|=
literal|180
operator|/
name|PI
operator|*
name|asin
argument_list|(
name|sqrt
argument_list|(
name|QVector3D
operator|::
name|dotProduct
argument_list|(
name|m_axis
argument_list|,
name|m_axis
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|m_angularVelocity
operator|=
name|angle
operator|/
name|msecs
expr_stmt|;
name|m_axis
operator|.
name|normalize
argument_list|()
expr_stmt|;
name|m_axis
operator|=
name|transformation
operator|.
name|rotatedVector
argument_list|(
name|m_axis
argument_list|)
expr_stmt|;
name|m_rotation
operator|=
name|QQuaternion
operator|::
name|fromAxisAndAngle
argument_list|(
name|m_axis
argument_list|,
name|angle
argument_list|)
operator|*
name|m_rotation
expr_stmt|;
block|}
break|break;
block|}
name|m_lastPos
operator|=
name|p
expr_stmt|;
name|m_lastTime
operator|=
name|currentTime
expr_stmt|;
block|}
end_function
begin_function
DECL|function|release
name|void
name|TrackBall
operator|::
name|release
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
specifier|const
name|QQuaternion
modifier|&
name|transformation
parameter_list|)
block|{
comment|// Calling move() caused the rotation to stop if the framerate was too low.
name|move
argument_list|(
name|p
argument_list|,
name|transformation
argument_list|)
expr_stmt|;
name|m_pressed
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|start
name|void
name|TrackBall
operator|::
name|start
parameter_list|()
block|{
name|m_lastTime
operator|=
name|QTime
operator|::
name|currentTime
argument_list|()
expr_stmt|;
name|m_paused
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|stop
name|void
name|TrackBall
operator|::
name|stop
parameter_list|()
block|{
name|m_rotation
operator|=
name|rotation
argument_list|()
expr_stmt|;
name|m_paused
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rotation
name|QQuaternion
name|TrackBall
operator|::
name|rotation
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|m_paused
operator|||
name|m_pressed
condition|)
return|return
name|m_rotation
return|;
name|QTime
name|currentTime
init|=
name|QTime
operator|::
name|currentTime
argument_list|()
decl_stmt|;
name|float
name|angle
init|=
name|m_angularVelocity
operator|*
name|m_lastTime
operator|.
name|msecsTo
argument_list|(
name|currentTime
argument_list|)
decl_stmt|;
return|return
name|QQuaternion
operator|::
name|fromAxisAndAngle
argument_list|(
name|m_axis
argument_list|,
name|angle
argument_list|)
operator|*
name|m_rotation
return|;
block|}
end_function
end_unit
