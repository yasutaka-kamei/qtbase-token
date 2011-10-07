begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTANIMATION_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTANIMATION_P_H
define|#
directive|define
name|QABSTRACTANIMATION_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of QIODevice. This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtCore/qbasictimer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtimer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qelapsedtimer.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<qabstractanimation.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ANIMATION
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QAnimationGroup
name|class
name|QAnimationGroup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractAnimation
name|class
name|QAbstractAnimation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAbstractAnimationPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
name|QAbstractAnimationPrivate
argument_list|()
operator|:
name|state
argument_list|(
name|QAbstractAnimation
operator|::
name|Stopped
argument_list|)
block|,
name|direction
argument_list|(
name|QAbstractAnimation
operator|::
name|Forward
argument_list|)
block|,
name|totalCurrentTime
argument_list|(
literal|0
argument_list|)
block|,
name|currentTime
argument_list|(
literal|0
argument_list|)
block|,
name|loopCount
argument_list|(
literal|1
argument_list|)
block|,
name|currentLoop
argument_list|(
literal|0
argument_list|)
block|,
name|deleteWhenStopped
argument_list|(
name|false
argument_list|)
block|,
name|hasRegisteredTimer
argument_list|(
name|false
argument_list|)
block|,
name|isPause
argument_list|(
name|false
argument_list|)
block|,
name|isGroup
argument_list|(
name|false
argument_list|)
block|,
name|group
argument_list|(
literal|0
argument_list|)
block|{     }
name|virtual
operator|~
name|QAbstractAnimationPrivate
argument_list|()
block|{}
specifier|static
name|QAbstractAnimationPrivate
operator|*
name|get
argument_list|(
argument|QAbstractAnimation *q
argument_list|)
block|{
return|return
name|q
operator|->
name|d_func
argument_list|()
return|;
block|}
name|QAbstractAnimation
operator|::
name|State
name|state
block|;
name|QAbstractAnimation
operator|::
name|Direction
name|direction
block|;
name|void
name|setState
argument_list|(
argument|QAbstractAnimation::State state
argument_list|)
block|;
name|int
name|totalCurrentTime
block|;
name|int
name|currentTime
block|;
name|int
name|loopCount
block|;
name|int
name|currentLoop
block|;
name|bool
name|deleteWhenStopped
block|;
name|bool
name|hasRegisteredTimer
block|;
name|bool
name|isPause
block|;
name|bool
name|isGroup
block|;
name|QAnimationGroup
operator|*
name|group
block|;
name|private
operator|:
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractAnimation
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QUnifiedTimer
name|class
name|QUnifiedTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDefaultAnimationDriver
range|:
name|public
name|QAnimationDriver
block|{
name|Q_OBJECT
name|public
operator|:
name|QDefaultAnimationDriver
argument_list|(
name|QUnifiedTimer
operator|*
name|timer
argument_list|)
block|;
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
name|e
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|startTimer
argument_list|()
block|;
name|void
name|stopTimer
argument_list|()
block|;
name|private
operator|:
name|QBasicTimer
name|m_timer
block|;
name|QUnifiedTimer
operator|*
name|m_unified_timer
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QAnimationDriverPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
name|QAnimationDriverPrivate
argument_list|()
operator|:
name|running
argument_list|(
argument|false
argument_list|)
block|{}
name|bool
name|running
block|; }
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|ElapsedTimer
typedef|typedef
name|QElapsedTimer
name|ElapsedTimer
typedef|;
end_typedef
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QUnifiedTimer
range|:
name|public
name|QObject
block|{
name|private
operator|:
name|QUnifiedTimer
argument_list|()
block|;
name|public
operator|:
comment|//XXX this is needed by dui
specifier|static
name|QUnifiedTimer
operator|*
name|instance
argument_list|()
block|;
specifier|static
name|QUnifiedTimer
operator|*
name|instance
argument_list|(
argument|bool create
argument_list|)
block|;
specifier|static
name|void
name|registerAnimation
argument_list|(
argument|QAbstractAnimation *animation
argument_list|,
argument|bool isTopLevel
argument_list|)
block|;
specifier|static
name|void
name|unregisterAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
comment|//defines the timing interval. Default is DEFAULT_TIMER_INTERVAL
name|void
name|setTimingInterval
argument_list|(
argument|int interval
argument_list|)
block|;
comment|/*        this allows to have a consistent timer interval at each tick from the timer        not taking the real time that passed into account.     */
name|void
name|setConsistentTiming
argument_list|(
argument|bool consistent
argument_list|)
block|{
name|consistentTiming
operator|=
name|consistent
block|; }
comment|//these facilitate fine-tuning of complex animations
name|void
name|setSlowModeEnabled
argument_list|(
argument|bool enabled
argument_list|)
block|{
name|slowMode
operator|=
name|enabled
block|; }
name|void
name|setSlowdownFactor
argument_list|(
argument|qreal factor
argument_list|)
block|{
name|slowdownFactor
operator|=
name|factor
block|; }
comment|/*         this is used for updating the currentTime of all animations in case the pause         timer is active or, otherwise, only of the animation passed as parameter.     */
specifier|static
name|void
name|ensureTimerUpdate
argument_list|()
block|;
comment|/*         this will evaluate the need of restarting the pause timer in case there is still         some pause animations running.     */
specifier|static
name|void
name|updateAnimationTimer
argument_list|()
block|;
name|void
name|installAnimationDriver
argument_list|(
name|QAnimationDriver
operator|*
name|driver
argument_list|)
block|;
name|void
name|uninstallAnimationDriver
argument_list|(
name|QAnimationDriver
operator|*
name|driver
argument_list|)
block|;
name|bool
name|canUninstallAnimationDriver
argument_list|(
name|QAnimationDriver
operator|*
name|driver
argument_list|)
block|;
name|void
name|restartAnimationTimer
argument_list|()
block|;
name|void
name|updateAnimationsTime
argument_list|(
argument|qint64 timeStep
argument_list|)
block|;
comment|//useful for profiling/debugging
name|int
name|runningAnimationCount
argument_list|()
block|{
return|return
name|animations
operator|.
name|count
argument_list|()
return|;
block|}
name|void
name|registerProfilerCallback
argument_list|(
name|void
argument_list|(
operator|*
name|cb
argument_list|)
argument_list|(
name|qint64
argument_list|)
argument_list|)
block|;
name|protected
operator|:
name|void
name|timerEvent
argument_list|(
name|QTimerEvent
operator|*
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QDefaultAnimationDriver
block|;
name|friend
name|class
name|QAnimationDriver
block|;
name|QAnimationDriver
operator|*
name|driver
block|;
name|QDefaultAnimationDriver
name|defaultDriver
block|;
name|QBasicTimer
name|animationTimer
block|;
comment|// timer used to delay the check if we should start/stop the animation timer
name|QBasicTimer
name|startStopAnimationTimer
block|;
name|ElapsedTimer
name|time
block|;
name|qint64
name|lastTick
block|;
name|int
name|timingInterval
block|;
name|int
name|currentAnimationIdx
block|;
name|bool
name|insideTick
block|;
name|bool
name|consistentTiming
block|;
name|bool
name|slowMode
block|;
comment|// This factor will be used to divide the DEFAULT_TIMER_INTERVAL at each tick
comment|// when slowMode is enabled. Setting it to 0 or higher than DEFAULT_TIMER_INTERVAL (16)
comment|// stops all animations.
name|qreal
name|slowdownFactor
block|;
comment|// bool to indicate that only pause animations are active
name|bool
name|isPauseTimerActive
block|;
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|animations
block|,
name|animationsToStart
block|;
comment|// this is the count of running animations that are not a group neither a pause animation
name|int
name|runningLeafAnimations
block|;
name|QList
operator|<
name|QAbstractAnimation
operator|*
operator|>
name|runningPauseAnimations
block|;
name|void
name|registerRunningAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
name|void
name|unregisterRunningAnimation
argument_list|(
name|QAbstractAnimation
operator|*
name|animation
argument_list|)
block|;
name|int
name|closestPauseAnimationTimeToFinish
argument_list|()
block|;
name|void
argument_list|(
operator|*
name|profilerCallback
argument_list|)
argument_list|(
name|qint64
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ANIMATION
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QABSTRACTANIMATION_P_H
end_comment
end_unit
