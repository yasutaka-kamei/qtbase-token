begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"rectanimation.h"
end_include
begin_include
include|#
directive|include
file|"dummyobject.h"
end_include
begin_function
DECL|function|interpolateInteger
specifier|static
specifier|inline
name|int
name|interpolateInteger
parameter_list|(
name|int
name|from
parameter_list|,
name|int
name|to
parameter_list|,
name|qreal
name|progress
parameter_list|)
block|{
return|return
name|from
operator|+
operator|(
name|to
operator|-
name|from
operator|)
operator|*
name|progress
return|;
block|}
end_function
begin_constructor
DECL|function|RectAnimation
name|RectAnimation
operator|::
name|RectAnimation
parameter_list|(
name|DummyObject
modifier|*
name|obj
parameter_list|)
member_init_list|:
name|m_object
argument_list|(
name|obj
argument_list|)
member_init_list|,
name|m_dura
argument_list|(
literal|250
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|setEndValue
name|void
name|RectAnimation
operator|::
name|setEndValue
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|m_end
operator|=
name|rect
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setStartValue
name|void
name|RectAnimation
operator|::
name|setStartValue
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|m_start
operator|=
name|rect
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setDuration
name|void
name|RectAnimation
operator|::
name|setDuration
parameter_list|(
name|int
name|d
parameter_list|)
block|{
name|m_dura
operator|=
name|d
expr_stmt|;
block|}
end_function
begin_function
DECL|function|duration
name|int
name|RectAnimation
operator|::
name|duration
parameter_list|()
specifier|const
block|{
return|return
name|m_dura
return|;
block|}
end_function
begin_function
DECL|function|updateCurrentTime
name|void
name|RectAnimation
operator|::
name|updateCurrentTime
parameter_list|(
name|int
name|currentTime
parameter_list|)
block|{
name|qreal
name|progress
init|=
name|m_easing
operator|.
name|valueForProgress
argument_list|(
name|currentTime
operator|/
name|qreal
argument_list|(
name|m_dura
argument_list|)
argument_list|)
decl_stmt|;
name|QRect
name|now
decl_stmt|;
name|now
operator|.
name|setCoords
argument_list|(
name|interpolateInteger
argument_list|(
name|m_start
operator|.
name|left
argument_list|()
argument_list|,
name|m_end
operator|.
name|left
argument_list|()
argument_list|,
name|progress
argument_list|)
argument_list|,
name|interpolateInteger
argument_list|(
name|m_start
operator|.
name|top
argument_list|()
argument_list|,
name|m_end
operator|.
name|top
argument_list|()
argument_list|,
name|progress
argument_list|)
argument_list|,
name|interpolateInteger
argument_list|(
name|m_start
operator|.
name|right
argument_list|()
argument_list|,
name|m_end
operator|.
name|right
argument_list|()
argument_list|,
name|progress
argument_list|)
argument_list|,
name|interpolateInteger
argument_list|(
name|m_start
operator|.
name|bottom
argument_list|()
argument_list|,
name|m_end
operator|.
name|bottom
argument_list|()
argument_list|,
name|progress
argument_list|)
argument_list|)
expr_stmt|;
name|bool
name|changed
init|=
operator|(
name|now
operator|!=
name|m_current
operator|)
decl_stmt|;
if|if
condition|(
name|changed
condition|)
name|m_current
operator|=
name|now
expr_stmt|;
if|if
condition|(
name|state
argument_list|()
operator|==
name|Stopped
condition|)
return|return;
if|if
condition|(
name|m_object
condition|)
name|m_object
operator|->
name|setRect
argument_list|(
name|m_current
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
