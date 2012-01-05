begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_NATIVE_PLAYBACK
end_ifndef
begin_define
DECL|macro|Q_NATIVE_PLAYBACK
define|#
directive|define
name|Q_NATIVE_PLAYBACK
end_define
begin_include
include|#
directive|include
file|<QtCore>
end_include
begin_include
include|#
directive|include
file|"qnativeevents.h"
end_include
begin_decl_stmt
name|class
name|NativeEventList
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
block|;
name|public
operator|:
expr|enum
name|Playback
block|{
name|ReturnImmediately
block|,
name|WaitUntilFinished
block|}
block|;
name|NativeEventList
argument_list|(
argument|int defaultWaitMs =
literal|20
argument_list|)
block|;
operator|~
name|NativeEventList
argument_list|()
block|;
name|void
name|append
argument_list|(
name|QNativeEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|append
argument_list|(
argument|int waitMs
argument_list|,
argument|QNativeEvent *event =
literal|0
argument_list|)
block|;
name|void
name|play
argument_list|(
argument|Playback playback = WaitUntilFinished
argument_list|)
block|;
name|void
name|stop
argument_list|()
block|;
name|void
name|setTimeMultiplier
argument_list|(
argument|float multiplier
argument_list|)
block|;
name|signals
operator|:
name|void
name|done
argument_list|()
block|;
name|private
name|slots
operator|:
name|void
name|sendNextEvent
argument_list|()
block|;
name|private
operator|:
name|void
name|waitNextEvent
argument_list|()
block|;
name|QList
operator|<
name|QPair
operator|<
name|int
block|,
name|QNativeEvent
operator|*
operator|>
expr|>
name|eventList
block|;
name|float
name|playbackMultiplier
block|;
name|int
name|currIndex
block|;
name|bool
name|wait
block|;
name|int
name|defaultWaitMs
block|;
name|int
name|debug
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
